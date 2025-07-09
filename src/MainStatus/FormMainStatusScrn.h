//---------------------------------------------------------------------------

#ifndef FormMainStatusScrnH
#define FormMainStatusScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Dialogs.hpp>
#include "iComponent.hpp"
#include "iCustomComponent.hpp"
#include "iLedMatrix.hpp"
#include "iVCLComponent.hpp"
#include <Vcl.Buttons.hpp>
#include "iPieChart.hpp"
#include "iGradient.hpp"
#include "iPipe.hpp"
#include "iLedBar.hpp"
#include "iPositionComponent.hpp"
#include "iProgressComponent.hpp"
//---------------------------------------------------------------------------
class TFormMainStatus : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TColorDialog *LotColorDialog;
	TTimer *MainRefreshTimer;
	TPanel *PanelMainARFlow;
	TPanel *PanelDailyReport;
	TTabSheet *TabSheet3;
	TPanel *PanelManualSelect;
	TTabSheet *ALLHOME;
	TPanel *PanelAllhome;
	TTabSheet *TabSheet4;
	TPanel *PanelMultiServo;
	void __fastcall MainRefreshTimerTimer(TObject *Sender);

private:	// User declarations

	TForm* pMainStatusFrm[5];

    int nUseSkipNumber[50];
	String  StrMotorName[100];

	void MainMotorStatus_Refresh();


public:		// User declarations

	void Mainstatus_Initialize();

    void	ShowAllhomeScrn();

	__fastcall TFormMainStatus(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMainStatus *FormMainStatus;
//---------------------------------------------------------------------------
#endif
