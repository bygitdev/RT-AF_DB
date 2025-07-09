//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ConfigSetFormScrn.h"
#include "MainFormScrn.h"
#include "WarningScrn.h"
//---------------------------------------------------------------------------
#include "BaseComm.h"
//---------------------------------------------------------------------------
#include "VisionSetUpScrn.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma resource "*.dfm"
TConfigSetForm *ConfigSetForm;

#define   _SETMAX_CNT_   6
//---------------------------------------------------------------------------
__fastcall TConfigSetForm::TConfigSetForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TConfigSetForm::ReadIniSet_Shortcut()
{
    TIniFile *pConfigIni = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\ShortCutSet.ini");
	if( pConfigIni == NULL)
	{
        delete pConfigIni;
        return;
    }

    for( int i = 0; i < _SETMAX_CNT_; i++ )
    {
        TComboBox *SubCloneCombo = (TComboBox *)FindComponent("ComboSC"+IntToStr(i+1));
        if(SubCloneCombo != NULL)
        {
        	SubCloneCombo->ItemIndex =  pConfigIni->ReadInteger("ShortCut"+IntToStr(i+1),"SetID",0);
        }
    }

    delete pConfigIni;
}
//---------------------------------------------------------------------------

void __fastcall TConfigSetForm::FormShow(TObject *Sender)
{
	ReadIniSet_Shortcut();
}
//---------------------------------------------------------------------------

void __fastcall TConfigSetForm::BtnSaveConfigClick(TObject *Sender)
{
    TIniFile *pConfigIni = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\ShortCutSet.ini");
	if( pConfigIni == NULL)
	{
        delete pConfigIni;
        return;
    }

    for( int i = 0; i < _SETMAX_CNT_; i++ )
    {
        TComboBox *SubCloneCombo = (TComboBox *)FindComponent("ComboSC"+IntToStr(i+1));
        if(SubCloneCombo != NULL)
        {
        	int nSelectIndex;
        	pConfigIni->WriteInteger("ShortCut"+IntToStr(i+1),"SetID",(SubCloneCombo->ItemIndex));
    	}
    }

    delete pConfigIni;
}
//---------------------------------------------------------------------------

void __fastcall TConfigSetForm::BtnSystemCloseClick(TObject *Sender)
{
    FrmCdBox->setFlag(CD_YESNO);
    FrmCdBox->setTitle("SYSTEM CLOSE");
    FrmCdBox->setText("Do you want to exit MMI program ?");
    if( mrYes == FrmCdBox->ShowModal())
    {


	    MainForm->Savingrunningtime(true);
        FrmVisionSetUp->VisionClosingProcess();

        Application->Terminate();
        Close();
	}
}
//---------------------------------------------------------------------------

void __fastcall TConfigSetForm::BtnCloseClick(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------


void __fastcall TConfigSetForm::BtnScreenLockClick(TObject *Sender)
{
	FrmWarning->BringToFront();
	FrmWarning->ShowModal();
}
//---------------------------------------------------------------------------

