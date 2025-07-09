//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Cdbox.h"
#include "falpha.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvGlowButton"
#pragma resource "*.dfm"
TFrmCdBox *FrmCdBox;

//---------------------------------------------------------------------------
__fastcall TFrmCdBox::TFrmCdBox(TComponent* Owner)
	: TForm(Owner)
{
    HWND hwnd = this->Handle; //다이얼로그의 핸들 얻음.
	SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_EXSTYLE) | 524288);
	::SetLayeredWindowAttributes(hwnd, 0, (255 * 95) / 100, 2);
	//::SetLayeredWindowAttributes(hwnd, RGB(255, 0, 0), 127, LWA_COLORKEY | LWA_ALPHA);
    MemoText->Lines->Clear();
 }
 
//---------------------------------------------------------------------------

void TFrmCdBox::setTitle(String strTitle)
{
	LabelTitle->Caption = strTitle;
}

//---------------------------------------------------------------------------

void TFrmCdBox::setText(String strText)
{
	MemoText->Text = MemoText->Text + strText + "\r\n";
}

//---------------------------------------------------------------------------

void TFrmCdBox::setFlag(DWORD dwFlag)
{
	_dwFlag = dwFlag;

    if (_dwFlag & CD_YES)
    {
		BtnMain1->Visible = true;
		BtnMain1->Caption = "&Yes";
		BtnMain1-> ModalResult = mrYes;
		BtnMain2->Visible = false;
    }
    else
    if (_dwFlag & CD_YESNO)
    {
		BtnMain1->Visible = true;
		BtnMain1->Caption = "&Yes";
		BtnMain1->ModalResult = mrYes;

		BtnMain2->Visible = true;
		BtnMain2->Caption = "&No";
		BtnMain2->ModalResult = mrNo;
	}
    else
    if (_dwFlag & CD_OK)
    {
		BtnMain1->Visible = true;
		BtnMain1->Caption = "&Ok";
		BtnMain1->ModalResult = mrYes;

		BtnMain2->Visible = false;
	}
	else
	if (_dwFlag & CD_OKCANCEL)
	{
		BtnMain1->Visible = true;
		BtnMain1->Caption = "&Ok";
		BtnMain1->ModalResult = mrOk;

		BtnMain2->Visible = true;
		BtnMain2->Caption = "&Cancel";
		BtnMain2->ModalResult = mrCancel;
	}
}

//---------------------------------------------------------------------------

void __fastcall TFrmCdBox::FormShow(TObject *Sender)
{
	BtnMain1->SetFocus();
}

//---------------------------------------------------------------------------

bool TFrmCdBox::QueryMsg(String Title, String Msg, CD_FLAG dwFlag)
{    
	setTitle(Title);
	setText(Msg);
	setFlagCaption(dwFlag);

	this->BringToFront();
	if( this->Showing == FALSE ) //동시에 여러창이 생기면 에러 발생하기 떄문에..
	{
		TModalResult mr =  this->ShowModal();
		if ( mr == mrOk ||
			 mr == mrYes )
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

//---------------------------------------------------------------------------
bool TFrmCdBox::QueryMsg2(String Title, String Msg, CD_FLAG dwFlag,CD_TYPE type,bool isAlpha)
{
	setTitle(Title);
	setText(Msg);
	setFlag(dwFlag);
	setType(type);
	return QueryMsg(isAlpha);
}

//---------------------------------------------------------------------------
bool TFrmCdBox::QueryMsg(bool isAlpha)
{
	this->BringToFront();
	if( this->Showing == FALSE ) //동시에 여러창이 생기면 에러 발생하기 떄문에..
	{
		TModalResult mr;
		if(isAlpha)
		{
			mr = FrmApha->AlphaShowModal(this);
		}
		else
		{
			mr =  this->ShowModal();
		}
		if ( mr == mrOk ||
			 mr == mrYes )
		{
			return true;
		}
	}
	return false;
}

//---------------------------------------------------------------------------
void TFrmCdBox::setType(CD_TYPE iType)
{
	_cdType = iType;
}

//---------------------------------------------------------------------------

void TFrmCdBox::setFlagCaption(CD_FLAG dwFlag)
{

	CD_FLAG	_dwFlag = dwFlag;

	BtnMain1->ModalResult = mrOk;
	BtnMain2->ModalResult = mrCancel;

	if (_dwFlag & CD_YES)
	{
		BtnMain1->Visible = true;
		BtnMain1->Caption = "&Yes";

		BtnMain2->Visible = false;
	}
	else
	if (_dwFlag & CD_YESNO)
	{
		BtnMain1->Visible = true;
		BtnMain1->Caption = "&Yes";

		BtnMain2->Visible = true;
		BtnMain2->Caption = "&No";
	}
	else
	if (_dwFlag & CD_OK)
	{
		BtnMain1->Visible = true;
		BtnMain1->Caption = "&Ok";

		BtnMain2->Visible = false;
	}
	else
	if (_dwFlag & CD_OKCANCEL)
	{
		BtnMain1->Visible = true;
		BtnMain1->Caption = "&Ok";

		BtnMain2->Visible = true;
		BtnMain2->Caption = "&Cancel";
	}
}

void __fastcall TFrmCdBox::BtnMain1Click(TObject *Sender)
{
    MemoText->Lines->Clear();  
}

//---------------------------------------------------------------------------

void __fastcall TFrmCdBox::BtnMain2Click(TObject *Sender)
{
    MemoText->Lines->Clear(); 
}

//---------------------------------------------------------------------------

