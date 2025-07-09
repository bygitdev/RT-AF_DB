//---------------------------------------------------------------------------

#ifndef ftccommH
#define ftccommH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <System.Win.ScktComp.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------

#include <stdio.h>
//	loader
//1	carrier id read
//2	ssd req merge info
//3	pcb info router
//4	lot start
//5	lot merge
//
//
//
//
//	sorter
//1	see lot
//2	online end
//3	scrap info
//4	delete scrap
//5	sorter lot end

class TfrmTCComm : public TForm
{
__published:	// IDE-managed Components
	TClientSocket *ClientSocket1;
	TPopupMenu *PopupMenu1;
	TMenuItem *Clear2;
	TPanel *Panel2;
	TSpeedButton *btnConnect;
	TLabel *Label1;
	TEdit *Edit1;
	TEdit *Edit2;
	TMemo *Memo1;
	TTimer *Timer1;
	TSpeedButton *sbManual;
	TPanel *Panel1;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TPageControl *PageControl3;
	TTabSheet *TabSheet8;
	TSpeedButton *SpeedButton5;
	TMemo *Memo5;
	TTabSheet *TabSheet9;
	TSpeedButton *SpeedButton6;
	TMemo *Memo6;
	TTabSheet *TabSheet4;
	TPageControl *PageControl2;
	TTabSheet *TabSheet5;
	TSpeedButton *SpeedButton2;
	TMemo *Memo2;
	TTabSheet *TabSheet6;
	TSpeedButton *SpeedButton8;
	TMemo *Memo8;
	TTabSheet *TabSheet7;
	TSpeedButton *SpeedButton9;
	TMemo *Memo9;
	TTabSheet *TabSheet11;
	TSpeedButton *SpeedButton10;
	TMemo *Memo10;
	TTabSheet *TabSheet12;
	TSpeedButton *SpeedButton11;
	TMemo *Memo11;
	TStringGrid *StringGrid1;
	void __fastcall btnConnectClick(TObject *Sender);
	void __fastcall ClientSocket1Connect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall ClientSocket1Disconnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall ClientSocket1Read(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall Clear2Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall SpeedButton5Click(TObject *Sender);
	void __fastcall SpeedButton6Click(TObject *Sender);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall SpeedButton8Click(TObject *Sender);
	void __fastcall SpeedButton9Click(TObject *Sender);
	void __fastcall SpeedButton10Click(TObject *Sender);
	void __fastcall SpeedButton11Click(TObject *Sender);
	void __fastcall ClientSocket1Error(TObject *Sender, TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall sbManualClick(TObject *Sender);


private:	// User declarations
    TCustomWinSocket*	_pOhtSocket;
	String	_ohtBuf, _Address, _Port;
	FILE*	_fp;
	String 	_currentLogFileName;
	BOOL	_ndmConfirm;

    BOOL	send(WideString data);
    void	parse(AnsiString body);


public:		// User declarations
	BOOL _bInitialize;
	//-------------------------------------------- router & sorter -------------



	//-------------------------------------------- router ----------------------
	BOOL	ohtPcbInfoRouter(AnsiString params[]);
	BOOL	ohtLotStart(AnsiString params[]);

	//-------------------------------------------- sorter ----------------------
	BOOL	ohtSeeLot(AnsiString params[]);
	BOOL	ohtOnlineEnd(AnsiString params[], BOOL ndmConfirm = TRUE);
	BOOL	ohtScrapInfo(AnsiString params[]);
	BOOL	ohtDeleteScrap(AnsiString params[]);
	BOOL	ohtChangeMgzId(AnsiString params[]);
	BOOL	ohtLotEnd(AnsiString params[]);


	void  MachineHistoryData(String StrTemp);
	void  TccommInitializeProcess();

	__fastcall TfrmTCComm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmTCComm *frmTCComm;
//---------------------------------------------------------------------------
#endif
