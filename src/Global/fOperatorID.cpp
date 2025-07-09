//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fOperatorID.h"
#include "FormSecsGemSetScrn.h"
#include <inifiles.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmOperatorID *frmOperatorID;
//---------------------------------------------------------------------------
__fastcall TfrmOperatorID::TfrmOperatorID(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmOperatorID::FormShow(TObject *Sender)
{
	TIniFile *tIni = new TIniFile(ExtractFilePath(Application->ExeName) + "\\ini\\GemData.ini");
	if(FileExists(ExtractFilePath(Application->ExeName) + "\\ini\\GemData.ini"))
	{
		PanelOpID->Caption = tIni->ReadString("OPERATOR" , "OPID" , "0");
	}
	delete tIni;
}
//---------------------------------------------------------------------------
void __fastcall TfrmOperatorID::Button2Click(TObject *Sender)
{
	TIniFile *tIni = new TIniFile(ExtractFilePath(Application->ExeName) + "\\ini\\GemData.ini");
	if(FileExists(ExtractFilePath(Application->ExeName) + "\\ini\\GemData.ini"))
	{
		tIni->WriteString("OPERATOR" , "OPID" , EditOpeartorID->Text);
	}
	delete tIni;

	//FormSecsGemSet->GemOperatorECChange();
}
//---------------------------------------------------------------------------
void __fastcall TfrmOperatorID::Button1Click(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------
