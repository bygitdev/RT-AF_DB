//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormMainStatusScrn.h"
#include "MainFormScrn.h"
#include "FormAlarmHistoryScrn.h"
#include "FrmARFlowScrn.h"
//#include "FrmDailyReportScrn.h"
#include "FormManualCuttingScrn.h"
#include "fallhome.h"
#include "fmultiservo.h"
//---------------------------------------------------------------------------
#include "BaseComm.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma link "iComponent"
#pragma link "iCustomComponent"
#pragma link "iLedMatrix"
#pragma link "iVCLComponent"
#pragma link "iPieChart"
#pragma link "iGradient"
#pragma link "iPipe"
#pragma link "iLedBar"
#pragma link "iPositionComponent"
#pragma link "iProgressComponent"
#pragma resource "*.dfm"
TFormMainStatus *FormMainStatus;

enum MAINSUBSCREEN
{
	MSUB_AUTOFLOW					= 0,
	MSUB_DAILYREPORT                = 1,
	MSUB_MANUALSELECT				= 2,
	MSUB_MULTYSERVO                 = 3
};


//---------------------------------------------------------------------------
__fastcall TFormMainStatus::TFormMainStatus(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void TFormMainStatus::Mainstatus_Initialize()
{
    pMainStatusFrm[MSUB_AUTOFLOW] = new TFrmARFlow(PanelMainARFlow);
    pMainStatusFrm[MSUB_AUTOFLOW]->Parent = PanelMainARFlow;
    pMainStatusFrm[MSUB_AUTOFLOW]->Left = 0;
    pMainStatusFrm[MSUB_AUTOFLOW]->Top = 0;
    pMainStatusFrm[MSUB_AUTOFLOW]->Visible = true;

//	pMainStatusFrm[MSUB_DAILYREPORT] = new TFrmDailyReport(PanelDailyReport);
//	pMainStatusFrm[MSUB_DAILYREPORT]->Parent = PanelDailyReport;
//	pMainStatusFrm[MSUB_DAILYREPORT]->Left = 0;
//	pMainStatusFrm[MSUB_DAILYREPORT]->Top = 0;
//	pMainStatusFrm[MSUB_DAILYREPORT]->Visible = true;


	pMainStatusFrm[MSUB_MANUALSELECT] = new TFormManualCutting(PanelManualSelect);
	pMainStatusFrm[MSUB_MANUALSELECT]->Parent = PanelManualSelect;
	pMainStatusFrm[MSUB_MANUALSELECT]->Left = 0;
	pMainStatusFrm[MSUB_MANUALSELECT]->Top = 0;
	pMainStatusFrm[MSUB_MANUALSELECT]->Align = alClient;
	pMainStatusFrm[MSUB_MANUALSELECT]->Visible = true;

	pMainStatusFrm[MSUB_MULTYSERVO] = new TFrmMultiServo(PanelMultiServo);
	pMainStatusFrm[MSUB_MULTYSERVO]->Parent = PanelMultiServo;
	pMainStatusFrm[MSUB_MULTYSERVO]->Left = 0;
	pMainStatusFrm[MSUB_MULTYSERVO]->Top = 0;
	pMainStatusFrm[MSUB_MULTYSERVO]->Align = alClient;
	pMainStatusFrm[MSUB_MULTYSERVO]->Visible = true;


    frmAllhomeStatus->Parent = PanelAllhome;
    frmAllhomeStatus->Align = alClient;
    frmAllhomeStatus->Visible = true;

    PageControl1->ActivePage = TabSheet1; // all home page
}
//---------------------------------------------------------------------------
void	TFormMainStatus::ShowAllhomeScrn()
{
	PageControl1->ActivePage = ALLHOME; // all home page
    frmAllhomeStatus->Show();
}
void TFormMainStatus::MainMotorStatus_Refresh()
{


}
//---------------------------------------------------------------------------

void __fastcall TFormMainStatus::MainRefreshTimerTimer(TObject *Sender)
{
    this->MainMotorStatus_Refresh();
}
//---------------------------------------------------------------------------




