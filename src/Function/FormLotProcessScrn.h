//---------------------------------------------------------------------------

#ifndef FormLotProcessScrnH
#define FormLotProcessScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "CurvyControls.hpp"
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include "CeyonSrc\XCYREMLib_OCX.h"

using  namespace Xcyremlib_tlb;
//---------------------------------------------------------------------------
class TFormLotProcess : public TForm
{
__published:	// IDE-managed Components
	TCurvyPanel *CurvyPanel1;
	TMemo *LotMemo;
	TBitBtn *BtnClose;
	TSpeedButton *BtnSaveLog;
	TTimer *OHTReadTimer;
	TTimer *LDRFIDInitTimer;
	TStringGrid *RFIDStringGrid;
	TSpeedButton *BtnConnectRFID;
	TSpeedButton *BtnDisconnectRFID;

	void __fastcall BtnCloseClick(TObject *Sender);
	void __fastcall LotMemoChange(TObject *Sender);
	void __fastcall BtnSaveLogClick(TObject *Sender);
	void __fastcall OHTReadTimerTimer(TObject *Sender);
	void __fastcall BtnConnectRFIDClick(TObject *Sender);
	void __fastcall BtnDisconnectRFIDClick(TObject *Sender);
private:	// User declarations

  	TXCyRem*		_pCeyon;

	void LotLogData(String StrTemp);
	void __fastcall OnContinuousEvent(System::TObject * Sender,BSTR rcvPacket);

public:		// User declarations

	bool RFIDConnect_Initialize();
	bool RFIDConnect_Close();

	__fastcall TFormLotProcess(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormLotProcess *FormLotProcess;
//---------------------------------------------------------------------------
#endif
