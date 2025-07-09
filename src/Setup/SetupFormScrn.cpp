//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SetupFormScrn.h"

#include "UnitSetupScrn.h"
#include "fqcunitsetup.h"
#include "fsystemteach.h"
#include "ftrayteach.h"
#include "FormLifeTimeSetScrn.h"
#include "FormTowerLampScrn.h"
#include "fmotorsetup.h"
#include "fpadsetup.h"

#include "fgerber.h"

#include "BaseComm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSetupForm *SetupForm;


//---------------------------------------------------------------------------
__fastcall TSetupForm::TSetupForm(TComponent* Owner)
	: TForm(Owner)
{
	_pCurrentForm = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TSetupForm::SetupFrmSub1Click(TObject *Sender)
{
	this->ScreenChange(dynamic_cast<TBitBtn *>(Sender)->Caption);
}
//---------------------------------------------------------------------------



void __fastcall TSetupForm::FormShow(TObject *Sender)
{
	if(_pCurrentForm == NULL) this->ScreenChange("UNIT POSITION");
}
//---------------------------------------------------------------------------

void	TSetupForm::ScreenChange(String menu)
{
    TForm* target = NULL;

    if(menu == "UNIT POSITION")
    {
		target = FrmUnitSetup;
        FrmUnitSetup->Frm_UnitDisplay();
    }
    if(menu == "QC POSITION")
    {
    	target = frmQcPositionSetup;
        frmQcPositionSetup->Frm_UnitDisplay();
    }
    if(menu == "TRAY TEACH")
    {
    	target = frmTrayTeach;
    }
    if(menu == "SYSTEM TEACH")
    {
    	if(!CheckCanAccessLevel(PW_MAINTENANCE)) return;
    	target = frmSystemTeach;
    }
    if(menu == "GERBER TOOL")
    {
    	target = frmRoute;
    }
    if(menu == "LIFETIME")
    {
    	target = FormLifeTimeSet;
        FormLifeTimeSet->LifeTimeScreen_Initialize();
    }
    if(menu == "MOTOR SETUP")
    {
    	target = frmMorterSetup;
	}
	if(menu == "PAD SETUP")
	{
		target = frmPadSetup;
	}
    if(menu == "TOWER LAMP")
    {
    	target = FormTowerLamp;
        FormTowerLamp->TowerLamp_Initialize();
    }

    if(NULL != target && _pCurrentForm != target)
	{
		if(NULL != _pCurrentForm)
		{
			_pCurrentForm->Hide();
			_pCurrentForm = NULL;
		}

		_pCurrentForm = target;
		//
		if(NULL != _pCurrentForm)
		{
			_pCurrentForm->Parent = SetupBasePanel;
			_pCurrentForm->Align = alClient;
			_pCurrentForm->Show();
		}
	}
}

