//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fmotorsetup.h"
#include "fmotorsetupcontrol.h"
#include "BaseComm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMorterSetup *frmMorterSetup;
//---------------------------------------------------------------------------
__fastcall TfrmMorterSetup::TfrmMorterSetup(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmMorterSetup::SpeedButton1Click(TObject *Sender)
{
	//if(!CheckCanDataAccess()) return;
	if(!CheckCanAccessLevel(PW_MAINTENANCE)) return;

	int nTag = dynamic_cast<TSpeedButton*>(Sender)->Tag;
	TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\MotorScrnSetup.ini");
	int axis = ini->ReadInteger("MOTER_SETUPSCRN_AXIS_INDEX", "AXIS_INDEX_"+IntToStr(nTag), 0);
	delete ini;

    frmMtrSetupControl->SetAxisNumber(axis);
    frmMtrSetupControl->ShowModal();
//    FrmApha->AlphaShowModal(frmMtrSetupControl);
}
//---------------------------------------------------------------------------

