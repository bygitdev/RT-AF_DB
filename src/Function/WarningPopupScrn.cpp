#include <vcl.h>
#pragma hdrstop

#include "MainFormScrn.h"
#include "WarningPopupScrn.h"
#include <inifiles.hpp>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrmWarningPopup *FrmWarningPopup;
//---------------------------------------------------------------------------
__fastcall TFrmWarningPopup::TFrmWarningPopup(TComponent* Owner)
	: TForm(Owner)
{
	_warningNum=0;
	_mode = true;
}
//---------------------------------------------------------------------------
void __fastcall TFrmWarningPopup::FormDblClick(TObject *Sender)
{
	MainForm->WarringRefreshTimer->Interval = 60000;
	Timer1->Enabled = false;
	this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TFrmWarningPopup::FormShow(TObject *Sender)
{
	String strWarnFile = ExtractFilePath(Application->ExeName) + "ini\\warning.ini";
	if (FALSE == FileExists(strWarnFile))
		return;

	Label1->Caption = _mode? "FULL!":"EMPTY!";
	Label1->Font->Color = _mode? clBlue:clRed;

	TIniFile* p = new TIniFile(strWarnFile);
	Memo1->Clear();
	Memo1->Lines->Add( p->ReadString("NAME", "NAME"+IntToStr(_warningNum), NULL) );
	delete p;

	Timer1->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TFrmWarningPopup::FormClose(TObject *Sender, TCloseAction &Action)

{
	Timer1->Enabled = false;
}
//---------------------------------------------------------------------------
void		TFrmWarningPopup::setWarningNum(int warningNum, bool mode)
{
	_warningNum = warningNum;
	_mode = mode;
}
//---------------------------------------------------------------------------
void __fastcall TFrmWarningPopup::Timer1Timer(TObject *Sender)
{
	TColor color = Label1->Font->Color;

	if(color != clWhite)
		Label1->Font->Color = clWhite;
	else
		Label1->Font->Color = _mode? clBlue:clRed;
}
//---------------------------------------------------------------------------

