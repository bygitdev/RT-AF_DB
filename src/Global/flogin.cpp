//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fLogin.h"
#include "Cdbox.h"
#include <inifiles.hpp>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmLogin *frmLogin;

HHOOK g_hook = NULL;
BOOL g_mouseActive = FALSE;

String strLabel[] = {
    "OPERATOR",
    "MAINTENANCE",
    "ENGINEER",
    "SUPER"
};


#define LOG_OUT_TIME_MIN	(3)
//---------------------------------------------------------------------------

LRESULT CALLBACK MouseHookProc(INT nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode > 0)
    {
		MOUSEHOOKSTRUCT* p = (MOUSEHOOKSTRUCT*)lParam;
        switch (wParam)
        {
        case WM_LBUTTONDOWN:
            // 로그 아웃 시간 연장 !
            g_mouseActive = TRUE;
            break;
        }
    }
    return CallNextHookEx(0, nCode, wParam, lParam);
}


__fastcall TfrmLogin::TfrmLogin(TComponent* Owner)
	: TForm(Owner)
{
	_isEnable = true;
    _isExpired = false;
    _expiredMins = 0;
}
//---------------------------------------------------------------------------

void __fastcall TfrmLogin::FormShow(TObject *Sender)
{
	_count = 0;
    _user = "";
    mePassword->Text="";
    mePassword->Enabled = true;

    String path = ExtractFilePath(Application->ExeName)+ "password.ini";
    TIniFile* p = new TIniFile(path);
    _login[PW_OPERATOR] 	= p->ReadString("OPERATOR", "PASSWORD", "1").UpperCase();
    _login[PW_MAINTENANCE] 	= p->ReadString("MAINTENANCE", "PASSWORD", "2").UpperCase();
    _login[PW_ENGINEER] 	= p->ReadString("ENGINEER", "PASSWORD", "3").UpperCase();
    _login[PW_SUPER] 		= "DLSLRMAK!";
    delete p;

//    cbLevel->ItemIndex = _level;
    _leveltemp = cbLevel->ItemIndex;

    SetForegroundWindow(Application->Handle);
	mePassword->SetFocus();

    ChangePasswordForm(false);
}
//---------------------------------------------------------------------------

void TfrmLogin::changeLevel(_LEVEL_ level)
{
	if(_keepPwd)	return;

	_count =0;
    _level = level;
}
//---------------------------------------------------------------------------
_LEVEL_ TfrmLogin::getLevel()
{
	return _level;
}
//---------------------------------------------------------------------------
String				TfrmLogin::getStringLevel()
{
	return strLabel[_level];
}
//---------------------------------------------------------------------------
void TfrmLogin::enable(bool enable)
{
	_isEnable = enable;
    if (!enable)
    	_level = PW_OPERATOR;
}
//---------------------------------------------------------------------------
bool TfrmLogin::isEnable()
{
	return _isEnable;
}
//---------------------------------------------------------------------------

bool  TfrmLogin::isExpired()
{
	return _isExpired;
}

INT	TfrmLogin::getLogOutPercentage()
{
	INT percentage = 0;
	if (this->isEnable() && (this->getLevel() > PW_OPERATOR ))
    {
        if (g_mouseActive)
        	_loggedin = Now();

        g_mouseActive = FALSE;

        TDateTime diff = Now() - _loggedin;
        unsigned short h, m, s, ms;
        DecodeTime(diff, h, m, s, ms);
        FLOAT secs = 3600*h + 60*m + s;
        percentage = secs / (_expiredMins* 60.0f) * 100.0f;

        if (percentage >100)
        	percentage = 100;
    }

    return percentage;
}

bool TfrmLogin::tryLogIn()
{
	bool result = false;

	_user = mePassword->Text.UpperCase();
	switch(_leveltemp)
	{
    case PW_OPERATOR:
        if (_login[PW_OPERATOR] 	== _user ||
        	_login[PW_MAINTENANCE]  == _user ||
            _login[PW_ENGINEER]   	== _user ||
            _login[PW_SUPER] 		== _user)
        {
            _level = _leveltemp;
            _isExpired = true;
            _expiredMins = LOG_OUT_TIME_MIN;
            result = true;
        }
        break;

    case PW_MAINTENANCE:
        if (_login[PW_MAINTENANCE]  == _user ||
            _login[PW_ENGINEER]   	== _user ||
            _login[PW_SUPER] 		== _user)
        {
            _level = _leveltemp;
            _isExpired = true;
            _expiredMins = LOG_OUT_TIME_MIN;
            result = true;
        }
        break;
    case PW_ENGINEER:
        if (_login[PW_ENGINEER]   	== _user ||
            _login[PW_SUPER] 		== _user)
        {
            _level = _leveltemp;
            _isExpired = true;
            _expiredMins = LOG_OUT_TIME_MIN;
            result = true;
        }
        break;
    case PW_SUPER:
        if (_login[PW_SUPER] ==_user)
        {
            _level = _leveltemp;
            _isExpired = true;
            _expiredMins = LOG_OUT_TIME_MIN;
            result = true;
        }
        break;

    default:
    	result = false;
        break;
    }

    if (result)
		_loggedin = Now();

    return result;
}


void __fastcall TfrmLogin::mePasswordKeyPress(TObject *Sender,
      char &Key)
{
	if (Key == VK_ESCAPE)
    {
        this->ModalResult = mrCancel;
        this->Close();
        return;
    }
	else
    if (Key =='\n' || Key == '\r')
    {
		if (FALSE == this->tryLogIn())
        {
            mePassword->Text ="";

            //if (++_count >2)
            {
                FrmCdBox->setFlag(CD_OK);
                FrmCdBox->setTitle("Password");
                FrmCdBox->setText("Incorrect password!. Please try again");
                FrmCdBox->ShowModal();

                _count =0;
                _level = PW_OPERATOR;
                this->Close();
                this->ModalResult = mrCancel;
            }
        }
        else
        {
            this->Close();
            this->ModalResult = mrOk;
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmLogin::Button1Click(TObject *Sender)
{
    if (FALSE == this->tryLogIn())
    {
        mePassword->Text ="";

        //if (++_count >2)
        {
            FrmCdBox->setFlag(CD_OK);
            FrmCdBox->setTitle("Password");
            FrmCdBox->setText("Incorrect password!. Please try again");
            FrmCdBox->ShowModal();

            _count =0;
            _level = PW_OPERATOR;
            this->Close();
            this->ModalResult = mrCancel;
        }
    }
    else
    {
        this->Close();
        this->ModalResult = mrOk;
    }
}
//---------------------------------------------------------------------------
void  TfrmLogin::SetTryLevel(_LEVEL_ lv)
{
 	cbLevel->ItemIndex = lv;
    _leveltemp = lv;

    if ( _leveltemp == PW_SUPER )
    {
        ChangePasswordForm(false);
        btnChangePassword->Enabled = false;
    }
    else
    {
        btnChangePassword->Enabled = true;
    }

}

void __fastcall TfrmLogin::cbLevelChange(TObject *Sender)
{
	_leveltemp = cbLevel->ItemIndex;

    if ( _leveltemp == PW_SUPER )
    {
        ChangePasswordForm(false);
        btnChangePassword->Enabled = false;
    }
    else
    {
        btnChangePassword->Enabled = true;
    }
    mePassword->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TfrmLogin::SpeedButton1Click(TObject *Sender)
{
    this->ModalResult = mrCancel;
    this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmLogin::FormCreate(TObject *Sender)
{
	// hcchoi
	// 마우스 후킹을통해 마우스 동작시 로그아웃시간 자동 연장
    // 키보드도 추가 가능
    g_hook = ::SetWindowsHookEx( WH_MOUSE, MouseHookProc, 0, ::GetCurrentThreadId() );
}
//---------------------------------------------------------------------------

void __fastcall TfrmLogin::FormDestroy(TObject *Sender)
{
    ::UnhookWindowsHookEx (g_hook);
    g_hook = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TfrmLogin::btnChangePasswordClick(TObject *Sender)
{
	ChangePasswordForm(true);
}
//---------------------------------------------------------------------------


void __fastcall TfrmLogin::btnCancelClick(TObject *Sender)
{
	ChangePasswordForm(false);
}
//---------------------------------------------------------------------------
void TfrmLogin::ChangePasswordForm(bool enabled)
{
	if (enabled == true)
    {
    	this->Height = 360;

        meCurrentPassword->Clear();
        meNewPassword->Clear();
    }
    else
    {
    	this->Height = 200;
    }
}



void __fastcall TfrmLogin::btnOkClick(TObject *Sender)
{
    String path = ExtractFilePath(Application->ExeName)+ "password.ini";
    TIniFile* p = new TIniFile(path);

	String slevel = strLabel[_leveltemp];
    String sPassword = meCurrentPassword->Text.UpperCase();
    if ( _login[_leveltemp] != sPassword )
    {
        FrmCdBox->setFlag(CD_OK);
        FrmCdBox->setTitle("Change Password");
        FrmCdBox->setText("Incorrect current password!. Please try again");
        FrmCdBox->ShowModal();
        meCurrentPassword->Clear();
        meNewPassword->Clear();
        meCurrentPassword->SetFocus();
        return;
    }

	FrmCdBox->setFlag(CD_YESNO);
    FrmCdBox->setTitle("Change password");
    FrmCdBox->setText("Do you want to chage password?");
	FrmCdBox->BringToFront();
    if (mrYes != FrmCdBox->ShowModal())
    	return;	//

    String sNewPassword = meNewPassword->Text.UpperCase();
    p->WriteString(slevel, "PASSWORD", sNewPassword);
    _login[_leveltemp] 	=  sNewPassword;
    delete p;

    ChangePasswordForm(false);
}
//---------------------------------------------------------------------------

