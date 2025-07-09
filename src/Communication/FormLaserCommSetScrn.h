//---------------------------------------------------------------------------

#ifndef FormLaserCommSetScrnH
#define FormLaserCommSetScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "CurvyControls.hpp"
#include <System.Win.ScktComp.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <IdBaseComponent.hpp>
#include <IdCmdTCPServer.hpp>
#include <IdComponent.hpp>
#include <IdContext.hpp>
#include <IdCustomTCPServer.hpp>
#include <IdExplicitTLSClientServerBase.hpp>
#include <IdFTP.hpp>
#include <IdFTPServer.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <IdTCPServer.hpp>
//---------------------------------------------------------------------------
class TFormLaserCommSet : public TForm
{
__published:	// IDE-managed Components
	TCurvyPanel *CurvyPanel1;
	TMemo *LaserMemo;
	TLabel *Label1;
	TButton *BtnLaserComm1;
	TButton *BtnLaserComm3;
	TButton *BtnLaserComm4;
	TButton *BtnLaserComm2;
	TCheckBox *ChkLaser2Heartbeat;
	TCheckBox *ChkLaser4Heartbeat;
	TCheckBox *ChkLaser3Heartbeat;
	TCheckBox *ChkLaser1Heartbeat;
	TClientSocket *TcpClientLaser1;
	TClientSocket *TcpClientLaser2;
	TClientSocket *TcpClientLaser3;
	TClientSocket *TcpClientLaser4;
	TButton *BtnHeartBeatControl;
	TCheckBox *CheckHeartBeatControl;
	TBitBtn *BtnClose;
	TTimer *HelloTimer;
	TTimer *LaserRefreshTimer;
	TTimer *LaserCommCheck;
	TButton *BtnRetryConnectActive;
	TSpeedButton *BtnSaveLog;
	TIdFTPServer *FTPLaserServer;
	TIdFTP *FTPLaserClient;
	TTimer *LaserConnectWait;
	void __fastcall LaserMemoChange(TObject *Sender);
	void __fastcall BtnLaserComm1Click(TObject *Sender);
	void __fastcall TcpClientLaser1Read(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall TcpClientLaser1Connect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall TcpClientLaser1Disconnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall TcpClientLaser1Error(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode);
	void __fastcall TcpClientLaser2Connect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall TcpClientLaser2Disconnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall TcpClientLaser2Error(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode);
	void __fastcall TcpClientLaser2Read(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall TcpClientLaser3Connect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall TcpClientLaser3Disconnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall TcpClientLaser3Error(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode);
	void __fastcall TcpClientLaser3Read(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall TcpClientLaser4Connect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall TcpClientLaser4Disconnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall TcpClientLaser4Error(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode);
	void __fastcall TcpClientLaser4Read(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall BtnHeartBeatControlClick(TObject *Sender);
	void __fastcall BtnCloseClick(TObject *Sender);
	void __fastcall HelloTimerTimer(TObject *Sender);
	void __fastcall LaserRefreshTimerTimer(TObject *Sender);
	void __fastcall LaserCommCheckTimer(TObject *Sender);
	void __fastcall BtnSaveLogClick(TObject *Sender);
	void __fastcall BtnRetryConnectActiveClick(TObject *Sender);
	void __fastcall LaserConnectWaitTimer(TObject *Sender);

private:	// User declarations

	bool bPosArrayWaitFlag1 , bPosArrayWaitFlag2 , bPosArrayWaitFlag3 , bPosArrayWaitFlag4;
	bool bJobChangeWaitFlag1 , bJobChangeWaitFlag2 , bJobChangeWaitFlag3 , bJobChangeWaitFlag4;
    bool bAutoCalWaitFlag;
    int  _nLaserEnableCnt_;
    int  _nCommTryCnt_;


	TCustomWinSocket *m_Laser_Socket1;
	TCustomWinSocket *m_Laser_Socket2;
	TCustomWinSocket *m_Laser_Socket3;
	TCustomWinSocket *m_Laser_Socket4;

	void LaserHistoryData(String StrTemp);
	void LaserHelloChk(int nLaserIndex);
    void LaserCommEnableControl(int nLaserIndex);

    void PosArrayLaserSendProcess(int nLaserIndex);
    void PosarrayEventTrigger();
    bool LaserTransferComplete(int nCommnadIndex , int nLaserIndex);
    bool LaserTransferFail(int nCommnadIndex , int nLaserIndex);

    void AutoCalDataReadFromSEQ(int nLaserIndex);
    String  AutoCalInterValueLoad(int nCalibSize);
    void  AutoCalEventTrigger();

public:		// User declarations

    void StartLaserChkSwitch();
    void LaserClosingProcess();
    void LaserJobChangeProcess(int nLaserNo ,String StrTemp);

	__fastcall TFormLaserCommSet(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormLaserCommSet *FormLaserCommSet;
//---------------------------------------------------------------------------
#endif
