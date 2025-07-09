//---------------------------------------------------------------------------

#ifndef FrmRouterCommScrnH
#define FrmRouterCommScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "CurvyControls.hpp"
#include <Vcl.Buttons.hpp>
#include <System.Win.ScktComp.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------

#include "BaseComm.h"
#include <stdio.h>

class TFrmRouterComm : public TForm
{
__published:	// IDE-managed Components
	TCurvyPanel *CurvyPanel1;
	TLabel *Label1;
	TMemo *MMIMemo;
	TButton *BtnRouterComm;
	TCheckBox *ChkRouterComm;
	TBitBtn *BtnClose;
	TServerSocket *SorterServer;
	TServerSocket *SorterDeviceInfoServer;
	TButton *Button1;
	TServerSocket *SorterQcSocket;
	void __fastcall BtnRouterCommClick(TObject *Sender);
	void __fastcall SorterServerClientConnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall SorterServerClientDisconnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall SorterServerClientError(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode);
	void __fastcall SorterServerClientRead(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall BtnCloseClick(TObject *Sender);
	void __fastcall Label1Click(TObject *Sender);
	void __fastcall SorterDeviceInfoServerClientConnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall SorterDeviceInfoServerClientDisconnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall SorterDeviceInfoServerClientError(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode);
	void __fastcall SorterDeviceInfoServerClientRead(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall SorterQcSocketClientConnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall SorterQcSocketClientDisconnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall SorterQcSocketClientError(TObject *Sender, TCustomWinSocket *Socket,
		  TErrorEvent ErrorEvent, int &ErrorCode);
	void __fastcall SorterQcSocketClientRead(TObject *Sender, TCustomWinSocket *Socket);






private:	// User declarations
	AnsiString strRecvBuffer;
	AnsiString strRecvDeviceInfo;
	AnsiString strRecvQcInfo;
	TCustomWinSocket *m_SorterSocket;
	TCustomWinSocket *m_SorterDeviceInfoSocket;
	TCustomWinSocket *m_SorterQcSocket;
	void MMILOGHistoryData(String StrTemp);

public:		// User declarations

	void StartRouterCommChkSwitch();
	__fastcall TFrmRouterComm(TComponent* Owner);
	BOOL qcInfoSend(AUTOFEEDBACK_INFO& qcInfo);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmRouterComm *FrmRouterComm;
//---------------------------------------------------------------------------
#endif
