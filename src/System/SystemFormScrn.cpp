//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SystemFormScrn.h"
#include "FrmMotorControlScrn.h"
#include "SensorbaseFormScrn.h"
#include "ParameterBaseFormScrn.h"
#include "JobRunningScrn.h"
#include "FormManualCuttingScrn.h"
#include "FrmStaubliControlScrn.h"
#include "FrmTenkeyScrn.h"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include "BaseComm.h"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSystemForm *SystemForm;


//---------------------------------------------------------------------------
__fastcall TSystemForm::TSystemForm(TComponent* Owner)
	: TForm(Owner)
{
	_pCurrentForm = NULL;
}

//---------------------------------------------------------------------------
void __fastcall TSystemForm::SystemFrmSubBtn1Click(TObject *Sender)
{
	this->ScreenChange(dynamic_cast<TBitBtn *>(Sender)->Caption);
}
//---------------------------------------------------------------------------
void __fastcall TSystemForm::FormShow(TObject *Sender)
{
	if(NULL == _pCurrentForm) this->ScreenChange("SENSOR");
}
//---------------------------------------------------------------------------

void	TSystemForm::ScreenChange(String menu)
{
    TForm* target = NULL;

    if(menu == "MANUAL RUN")
	{
		//if(!CheckCanDataAccess()) return;
		if(!CheckCanAccessLevel(PW_MAINTENANCE)) return;

//*        target = FrmJobRunning;
//*        FrmJobRunning->FormInitiaize();

        target = FrmTenkey;

    }
	//if(menu == "MANUAL SELECT")
	//{
	//	if(!CheckCanDataAccess()) return;
	//    target = FormManualCutting;
	//    FormManualCutting->FormManualCut_Initialize();
    //}
    if(menu == "SENSOR")
	{
		target = SensorbaseForm;
	}
	if(menu == "MOTOR DATA")
	{
		//if(!CheckCanDataAccess()) return;
		if(!CheckCanAccessLevel(PW_MAINTENANCE)) return;

    	target = FrmMotorControl;
        FrmMotorControl->Motorscreen_Initialize(0);
    }
    if(menu == "PARAMETER")
	{
		//if(!CheckCanDataAccess()) return;
    	if(!CheckCanAccessLevel(PW_SUPER)) return;

    	target = ParameterBaseForm;
        ParameterBaseForm->ParameterScreen_Initialize();
    }
    if(menu == "STAUBLI")
	{
		//if(!CheckCanDataAccess()) return;
    	if(!CheckCanAccessLevel(PW_SUPER)) return;

    	target = FrmStaubliControl;
        FrmStaubliControl->Staubli_Initilize();
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
			_pCurrentForm->Parent = SystemBasePanel;
			_pCurrentForm->Align = alClient;
			_pCurrentForm->Show();
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TSystemForm::SystemFrmSubBtn6Click(TObject *Sender)
{
    if(!CheckCanAccessLevel(PW_MAINTENANCE)) return;
	this->ScreenChange("STAUBLI");
}
//---------------------------------------------------------------------------

