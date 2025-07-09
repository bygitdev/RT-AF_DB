//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "OhtModeSelect.h"
#include "BaseComm.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvGlowButton"
#pragma resource "*.dfm"
TFrmOhtModeSelect *FrmOhtModeSelect;

//---------------------------------------------------------------------------
__fastcall TFrmOhtModeSelect::TFrmOhtModeSelect(TComponent* Owner)
	: TForm(Owner)
{
    HWND hwnd = this->Handle; //다이얼로그의 핸들 얻음.
	SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_EXSTYLE) | 524288);
	::SetLayeredWindowAttributes(hwnd, 0, (255 * 95) / 100, 2);
	//::SetLayeredWindowAttributes(hwnd, RGB(255, 0, 0), 127, LWA_COLORKEY | LWA_ALPHA);
	MemoText->Lines->Clear();
 }
//---------------------------------------------------------------------------
void TFrmOhtModeSelect::setTitle(String strTitle)
{
	LabelTitle->Caption = strTitle;
}
//---------------------------------------------------------------------------
void TFrmOhtModeSelect::setText(String strText)
{
	MemoText->Text = MemoText->Text + strText + "\r\n";
}
//---------------------------------------------------------------------------
void TFrmOhtModeSelect::setFlag(DWORD dwFlag)
{
	_dwFlag = dwFlag;
}
//---------------------------------------------------------------------------
void __fastcall TFrmOhtModeSelect::FormShow(TObject *Sender)
{
	//this->BringToFront();
	BtnMain1->SetFocus();
}
//---------------------------------------------------------------------------
void TFrmOhtModeSelect::setFlagCaption(CD_TYPE2 dwFlag)
{
	_dwFlag = dwFlag;
}
//---------------------------------------------------------------------------
void __fastcall TFrmOhtModeSelect::BtnMain1Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TFrmOhtModeSelect::BtnMain2Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

