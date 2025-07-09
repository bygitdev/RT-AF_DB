//---------------------------------------------------------------------------

#ifndef fSeeLotH
#define fSeeLotH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "CurvyControls.hpp"
#include <System.Win.ScktComp.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ComCtrls.hpp>

#include "rfid.h"
//---------------------------------------------------------------------------
class TfrmSeeLot : public TForm
{
__published:	// IDE-managed Components
	TTimer *tmScrapInfo;
	TTimer *tmSeeLot;
	TTimer *Timer3;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TCurvyPanel *CurvyPanel1;
	TShape *Shape1;
	TShape *Shape2;
	TBitBtn *btnLotEnd;
	TCurvyEdit *ceMergeLotID;
	TBitBtn *btnSeeLot;
	TCurvyPanel *CurvyPanel2;
	TLabel *Label1;
	TLabel *Label3;
	TLabel *Label6;
	TLabel *Label14;
	TLabel *Label2;
	TCurvyEdit *lotState;
	TCurvyEdit *partNo;
	TCurvyEdit *qty;
	TCurvyEdit *result;
	TCurvyEdit *msg;
	TCurvyPanel *CurvyPanel3;
	TLabel *Label8;
	TCurvyEdit *scrapCount;
	TStringGrid *sgScrap;
	TCurvyPanel *CurvyPanel4;
	TLabel *Label9;
	TLabel *Label11;
	TLabel *Label16;
	TLabel *Label17;
	TCurvyEdit *eqInputCnt;
	TCurvyEdit *eqGoodCnt;
	TCurvyEdit *eqRejectCnt;
	TCurvyEdit *eqOutPutCnt;
	TCurvyEdit *ceEqpID;
	TCurvyPanel *CurvyPanel5;
	TLabel *Label18;
	TStringGrid *sgEqScrap;
	TCurvyEdit *eqScrapCnt;
	TBitBtn *btnDelete;
	TBitBtn *btnEdit;
	TCurvyEdit *CurvyEdit1;
	TCurvyEdit *CurvyEdit2;
	TBitBtn *btnLotEndManual;
	TBitBtn *btnSave;
	TBitBtn *btnOnlineEndAll;
	TBitBtn *btnManualClose;
	TTabSheet *TabSheet2;
	TCurvyPanel *CurvyPanel6;
	TShape *Shape4;
	TBitBtn *btnClose;
	TCurvyPanel *CurvyPanel7;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label7;
	TLabel *Label10;
	TCurvyEdit *rfidLotID;
	TCurvyEdit *rfidPartNo;
	TCurvyEdit *rfidQty;
	TCurvyEdit *rfidStep;
	TCurvyEdit *CurvyEdit8;
	TCurvyEdit *rfidCarrierID;
	TBitBtn *btnRfidRead;
	TCurvyMemo *CurvyMemo1;
	TBitBtn *btnRfidCycle;
	TLabel *Label12;
	TCurvyEdit *CurvyEditRfidState;
	TLabel *Label13;
	TCurvyEdit *CurvyEditRfidControl;
	TLabel *Label15;
	TBitBtn *BitBtn1;
	TPanel *PanelTitle;
	TSpeedButton *SpeedButton11;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall eqInputCntChange(TObject *Sender);
	void __fastcall btnLotEndClick(TObject *Sender);
	void __fastcall tmScrapInfoTimer(TObject *Sender);
	void __fastcall btnEditClick(TObject *Sender);
	void __fastcall btnDeleteClick(TObject *Sender);
	void __fastcall btnLotEndManualClick(TObject *Sender);
	void __fastcall tmSeeLotTimer(TObject *Sender);
	void __fastcall btnSeeLotClick(TObject *Sender);
	void __fastcall btnSaveClick(TObject *Sender);
	void __fastcall btnOnlineEndAllClick(TObject *Sender);
	void __fastcall btnManualCloseClick(TObject *Sender);
	void __fastcall btnRfidWriteClick(TObject *Sender);
	void __fastcall Timer3Timer(TObject *Sender);
	void __fastcall CurvyEditRfidControlDblClick(TObject *Sender);
	void __fastcall btnRfidReadClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall SpeedButton11Click(TObject *Sender);


private:	// User declarations
	AnsiString	_mergeLotID;
	int	_result, _retryCnt;
	int _mode;
	bool	_bWriteCycle;

	bool	rfidCycle();
	void	rfidState();

public:		// User declarations
	__fastcall TfrmSeeLot(TComponent* Owner);

	void	setCycle(bool bSet);
	void	setMode(int nMode=0);
	void	pageChg(int nIndex=0);
	void	readRfidData(RFID_DATA rfid);
	void	writeRfidData(String strLotID, String strPartNo);

	void __fastcall setMsg(String sText);

};
//---------------------------------------------------------------------------
extern PACKAGE TfrmSeeLot *frmSeeLot;
//---------------------------------------------------------------------------
#endif
