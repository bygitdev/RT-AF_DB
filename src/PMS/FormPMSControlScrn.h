//---------------------------------------------------------------------------

#ifndef FormPMSControlScrnH
#define FormPMSControlScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "CurvyControls.hpp"
#include <Vcl.Buttons.hpp>


#include "PMSComm.h"
//---------------------------------------------------------------------------
class TFrmPMSControl : public TForm
{
__published:	// IDE-managed Components
	TTimer *TimerPMSStatus;
	TCurvyPanel *CurvyPanel1;
	TMemo *PMSMemo;
	TBitBtn *BtnPMSRead;
	TBitBtn *BtnPMSReset;
	TBitBtn *BtnPMSClose;
	TBitBtn *BtnPMSConnect;
	TPanel *PanelPMSConnect;
	void __fastcall PMSMemoChange(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall TimerPMSStatusTimer(TObject *Sender);
	void __fastcall BtnPMSConnectClick(TObject *Sender);
	void __fastcall BtnPMSReadClick(TObject *Sender);
	void __fastcall BtnPMSResetClick(TObject *Sender);
	void __fastcall BtnPMSCloseClick(TObject *Sender);
private:	// User declarations

	PMS  _pms;

public:		// User declarations

	void  PMSCommSwitch(bool bOnOff);
	bool  PMSReadSignal();
	void  PMSIDDataProcess(String strStripID, String strBincodes);
	void  PMSHistoryData(String strTemp);
	void  SavePMSLogProcess();


	__fastcall TFrmPMSControl(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmPMSControl *FrmPMSControl;
//---------------------------------------------------------------------------
#endif
