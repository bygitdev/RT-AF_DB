//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fProgramHistory.h"
#include "fLogin.h"
#include "Cdbox.h"
#include <stdio.h>
#include <tchar.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrmProgramHistory *FrmProgramHistory;
//---------------------------------------------------------------------------
__fastcall TFrmProgramHistory::TFrmProgramHistory(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFrmProgramHistory::FormShow(TObject *Sender)
{
	String strDirPath = ExtractFilePath(Application->ExeName)+"\\Ini\\ProgramHistory\\";
	String strFilePath = strDirPath + "MMIHistory.htr";

	if(false == DirectoryExists(strDirPath.c_str()))
	{
		//if (false == CreateDir(strDirPath.c_str()))
			return;
	}
	Memo1->Lines->Clear();
    try
    {
		Memo1->Lines->LoadFromFile(strFilePath);
    }
    catch(Exception& e)
    {
    	///...EFOpenError at first time
	}

	int nLevel = frmLogin->getLevel();

	if(nLevel == PW_SUPER)
	{
		Memo2->Enabled = true;
		Button2->Enabled = true;
	}
	else
	{
		Memo2->Enabled = false;
		Button2->Enabled = false;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmProgramHistory::Button1Click(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFrmProgramHistory::Button2Click(TObject *Sender)
{
	if (Edit1->Text == "")
	{
		FrmCdBox->setTitle( "Warning ! " );
		FrmCdBox->setText("Please input your name to write the logs");
		FrmCdBox->setFlag(CD_OK);
		FrmCdBox->ShowModal();
		return;
	}

	FrmCdBox->setTitle( "Write Logs" );
	FrmCdBox->setText("Do you want to log the message ?");
	FrmCdBox->setFlag(CD_YESNO);
	if ( mrYes == FrmCdBox->ShowModal())
    {
		String msg = "Date : " + DateTimePicker1->Time.DateString() + " " + \
			DateTimePicker1->Time.TimeString() + ", User Name : " + \
			Edit1->Text + "\r\n" + \
			Memo2->Text + "\r\n";

		Memo1->Lines->Add(msg);
		String strDirPath = ExtractFilePath(Application->ExeName)+"\\Ini\\ProgramHistory\\";
		String strFilePath = strDirPath + "MMIHistory.htr";
		Memo1->Lines->SaveToFile(strFilePath);
		Memo2->Clear();
	}
}
//---------------------------------------------------------------------------


