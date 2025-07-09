//---------------------------------------------------------------------------

#ifndef LaserSetUpScrnH
#define LaserSetUpScrnH
//---------------------------------------------------------------------------

#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdFTP.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include "LMDButton.hpp"
#include "LMDCustomButton.hpp"
#include <Sockets.hpp>
#include <ScktComp.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>
#include <IdFTPServer.hpp>
#include <IdTCPServer.hpp>
#include "iThreadTimers.hpp"
#include <IdCmdTCPServer.hpp>
#include <IdContext.hpp>
#include <IdCustomTCPServer.hpp>
#include <IdExplicitTLSClientServerBase.hpp>

//---------------------------------------------------------------------------
class TFrmLaserSetUp : public TForm
{
__published:	// IDE-managed Components
    TImage *Image1;
    TLabel *Label1;
    TClientSocket *TcpClientLaser1;
    TClientSocket *TcpClientLaser2;
    TiThreadTimers *LaserHeartBeatTimer;
	TClientSocket *LaserSECSClient;
	TTimer *LaserRCPResponseTimer;
	TOpenDialog *UploadOpenDialog;
	TIdFTPServer *FTPLaserServer;
	TOpenDialog *OpenDialog1;
	TTimer *LaserTransferTimer;
	TIdFTP *FTPLaserClient;
	TPageControl *LaserLogPage;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TTabSheet *TabSheet3;
	TTabSheet *TabSheet4;
	TTabSheet *TabSheet5;
	TMemo *Laser1Memo;
	TLMDButton *BtnLaser1SaveLog;
	TMemo *Laser2Memo;
	TLMDButton *BtnLaser2SaveLog;
	TLMDButton *BtnLaser3SaveLog;
	TMemo *Laser3Memo;
	TLMDButton *BtnLaser4SaveLog;
	TMemo *Laser4Memo;
	TRichEdit *SECSLaserMemo;
	TLMDButton *BtnSECSLaserSaveLog;
	TClientSocket *TcpClientLaser3;
	TClientSocket *TcpClientLaser4;
	TPanel *Panel1;
	TLMDButton *BtnLaser2Heartbeat;
	TLMDButton *BtnLaser3Heartbeat;
	TLMDButton *BtnLaser4Heartbeat;
	TLMDButton *BtnLaser1Heartbeat;
	TCheckBox *ChkLaser1Heartbeat;
	TCheckBox *ChkLaser4Heartbeat;
	TCheckBox *ChkLaser3Heartbeat;
	TCheckBox *ChkLaser2Heartbeat;
	TPanel *LaserSecsPanel2;
	TEdit *EditHostAddr;
	TEdit *EditRootDir;
	TLMDButton *BtnFTPLaserStop;
	TLMDButton *BtnFTPLaserRCPSend;
	TLMDButton *BtnFTPLaserStart;
	TLabel *Label3;
	TLabel *Label2;
	TLMDButton *BtnRecipeRootChange;
	TLMDButton *BtnRecipeAddressChange;
	TTimer *FTPTimer;
	TLMDButton *BtnRetryConnect;
	TTimer *TimerLaserRecipeNameCompare;
	TTimer *LaserMarkingTrigger;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
    void __fastcall Laser1MemoChange(TObject *Sender);
    void __fastcall Laser2MemoChange(TObject *Sender);
    void __fastcall BtnLaser1HeartbeatClick(TObject *Sender);
    void __fastcall BtnLaser2HeartbeatClick(TObject *Sender);
    void __fastcall TcpClientLaser1Read(TObject *Sender,
          TCustomWinSocket *Socket);
    void __fastcall TcpClientLaser2Read(TObject *Sender,
          TCustomWinSocket *Socket);
    void __fastcall TcpClientLaser1Connect(TObject *Sender,
          TCustomWinSocket *Socket);
    void __fastcall TcpClientLaser2Connect(TObject *Sender,
          TCustomWinSocket *Socket);
    void __fastcall TcpClientLaser1Error(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
    void __fastcall TcpClientLaser2Error(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
    void __fastcall TcpClientLaser1Disconnect(TObject *Sender,
          TCustomWinSocket *Socket);
    void __fastcall TcpClientLaser2Disconnect(TObject *Sender,
          TCustomWinSocket *Socket);
    void __fastcall LaserTransferTimerTimer(TObject *Sender);
    void __fastcall LaserHeartBeatTimerTimer1(TObject *Sender);
    void __fastcall LaserHeartBeatTimerTimer2(TObject *Sender);
    void __fastcall LaserHeartBeatTimerTimer3(TObject *Sender);
    void __fastcall LaserHeartBeatTimerTimer4(TObject *Sender);
    void __fastcall LaserHeartBeatTimerTimer5(TObject *Sender);
    void __fastcall BtnLaser1SaveLogClick(TObject *Sender);
    void __fastcall BtnLaser2SaveLogClick(TObject *Sender);

    void __fastcall SECSLaserMemoChange(TObject *Sender);
    void __fastcall BtnSECSLaserSaveLogClick(TObject *Sender);
    void __fastcall LaserSECSClientConnect(TObject *Sender,
          TCustomWinSocket *Socket);
    void __fastcall LaserSECSClientDisconnect(TObject *Sender,
          TCustomWinSocket *Socket);
    void __fastcall LaserSECSClientError(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
    void __fastcall LaserSECSClientRead(TObject *Sender,
          TCustomWinSocket *Socket);
	void __fastcall FTPLaserServerDisconnect(TIdPeerThread *AThread);
	void __fastcall FTPLaserServerUserLogin(TIdFTPServerThread *ASender,
          const AnsiString AUsername, const AnsiString APassword,
          bool &AAuthenticated);
	void __fastcall FTPLaserServerRetrieveFile(TIdFTPServerThread *ASender,
          const AnsiString AFileName, TStream *&VStream);
	void __fastcall FTPLaserServerListDirectory(TIdFTPServerThread *ASender,
          const AnsiString APath, TIdFTPListItems *ADirectoryListing);
	void __fastcall FTPLaserServerChangeDirectory(TIdFTPServerThread *ASender,
          AnsiString &VDirectory);
	void __fastcall FTPLaserServerGetFileSize(TIdFTPServerThread *ASender,
          const AnsiString AFilename, __int64 &VFileSize);
	void __fastcall FTPLaserServerStoreFile(TIdFTPServerThread *ASender,
          const AnsiString AFileName, bool AAppend, TStream *&VStream);
	void __fastcall FTPLaserServerDeleteFile(TIdFTPServerThread *ASender,
          const AnsiString APathName);
	void __fastcall BtnFTPLaserStartClick(TObject *Sender);
	void __fastcall BtnFTPLaserStopClick(TObject *Sender);
	void __fastcall BtnFTPLaserRCPSendClick(TObject *Sender);
	void __fastcall FTPLaserClientDisconnected(TObject *Sender);
	void __fastcall FTPLaserClientConnected(TObject *Sender);
	void __fastcall LaserRCPResponseTimerTimer(TObject *Sender);
	void __fastcall FTPLaserServerException(TIdPeerThread *AThread,
          Exception *AException);
	void __fastcall FTPLaserClientStatus(TObject *ASender, const TIdStatus AStatus,
          const AnsiString AStatusText);
	void __fastcall Laser4MemoChange(TObject *Sender);
	void __fastcall Laser3MemoChange(TObject *Sender);
	void __fastcall BtnLaser3SaveLogClick(TObject *Sender);
	void __fastcall BtnLaser4SaveLogClick(TObject *Sender);
	void __fastcall BtnLaser4HeartbeatClick(TObject *Sender);
	void __fastcall BtnLaser3HeartbeatClick(TObject *Sender);
	void __fastcall LaserHeartBeatTimerTimer6(TObject *Sender);
	void __fastcall LaserHeartBeatTimerTimer7(TObject *Sender);
	void __fastcall LaserHeartBeatTimerTimer8(TObject *Sender);
	void __fastcall TcpClientLaser3Connect(TObject *Sender,
          TCustomWinSocket *Socket);
	void __fastcall TcpClientLaser4Connect(TObject *Sender,
          TCustomWinSocket *Socket);
	void __fastcall TcpClientLaser3Disconnect(TObject *Sender,
          TCustomWinSocket *Socket);
	void __fastcall TcpClientLaser4Disconnect(TObject *Sender,
          TCustomWinSocket *Socket);
	void __fastcall TcpClientLaser3Error(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode);
	void __fastcall TcpClientLaser4Error(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode);
	void __fastcall TcpClientLaser3Read(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall TcpClientLaser4Read(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall LaserLogPageDrawTab(TCustomTabControl *Control, int TabIndex,
          const TRect &Rect, bool Active);
	void __fastcall BtnRetryConnectClick(TObject *Sender);
	void __fastcall FTPTimerTimer(TObject *Sender);
	void __fastcall TimerLaserRecipeNameCompareTimer(TObject *Sender);
	void __fastcall LaserMarkingTriggerTimer(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall LaserHeartBeatTimerTimer9(TObject *Sender);


private:	// User declarations
	String strLaserLotCodeChk[4];
	String strLaserMkModeChk[4];

	void __fastcall LaserHelloChk(int separator);

    void __fastcall LaserTransferComplete(int nIdentifier);

    void __fastcall PosArrayLaserSendProcess(int nIdentifier);
    void __fastcall PosArrayRowCol_RJCTLaserSendProcess(int nIdentifier);// 151014

    int __fastcall LaserDMGet_Val(int nIdentifier);

    void __fastcall RecvSVIDProcess(String StrTrgData);
    void __fastcall SVIDBuffering(String StrSVID , String StrTrgData);
	void __fastcall SVIDBuffering(String StrSVID , INT nCount,  WideString* wstr);

	bool __fastcall parse(String data);
	bool __fastcall svid(String data);

	bool __fastcall RecieveDetectPower(int nInOutIndex, String strLaserNo, String data);

	bool __fastcall m_MarkingSpecDataSend1(String StrWeekCode , String StrLDPMode,int MkNumber);
	bool __fastcall m_MarkingSpecDataSend2(String StrWeekCode , String StrLDPMode,int MkNumber);
	bool __fastcall m_MarkingSpecDataSend3(String StrWeekCode , String StrLDPMode,int MkNumber);
	bool __fastcall m_MarkingSpecDataSend4(String StrWeekCode , String StrLDPMode,int MkNumber);
	void __fastcall TFrmLaserSetUp::m_markingSpecDataTrigger();
    void __fastcall LaserMarkingSendFeedBack(bool bSuccess ,  int nseparator);


private:	// User declarations
	bool RefreshTagLaser1, RefreshTagLaser2 ,RefreshTagLaser3, RefreshTagLaser4;
	bool SystemTeach1, SystemTeach2 ,SystemTeach3, SystemTeach4;
	bool AutoCAL1, AutoCAL2 ,AutoCAL3, AutoCAL4;
	bool CorrectionCAL1, CorrectionCAL2,CorrectionCAL3, CorrectionCAL4;
	bool g_bLaserJobChk;		// 120911 JOB check 예외처리

	bool bMarkingSend1 , bMarkingSend2 , bMarkingSend3 , bMarkingSend4;
    bool bMarkingTime1 , bMarkingTime2 , bMarkingTime3 , bMarkingTime4;

	int  g_nRcpCmpIndex;

	TCustomWinSocket *m_Laser_Socket1;
	TCustomWinSocket *m_Laser_Socket2;
	TCustomWinSocket *m_Laser_Socket3;
	TCustomWinSocket *m_Laser_Socket4;

	TCustomWinSocket *m_SecsLaser_Socket;

	CHAR *pBuf;
	long lPPbodylength;
	String StrSVIDBuf , StrRrcpBuf , StrWrcpBuf;
	AnsiString _buf;
	String StrRcvLaserPartCode;
	String	_strRootDir;
	BOOL	_bServerConnected, _bClientConnected;
	String	_strLaserRecipeName[4];





public:		// User declarations
	void __fastcall SECSLaserConnection(bool bChkEnable);

public:
	int  g_nDataCnt;
	bool AckNakLaser1, AckNakLaser2 ,AckNakLaser3, AckNakLaser4;

	BOOL	start(String strRootDirectory, String strPeerHostName);	//"c:/"
	BOOL	stop();
	BOOL	sendToServer(String strFileName);
	BOOL	deleteToServer(String strFileName);
	bool __fastcall JobConversion(int nLaserDiv, String StrJobName);
	String __fastcall JobQuery_Process(int nLaserDiv);

	void __fastcall Laser1HistoryData(String StrTemp);
	void __fastcall Laser2HistoryData(String StrTemp);
	void __fastcall Laser3HistoryData(String StrTemp);
	void __fastcall Laser4HistoryData(String StrTemp);

	void __fastcall SECSLaserHistoryData(String StrTemp , int Emphasis);

	void __fastcall StartLaserChkSwitch();

	void __fastcall LaserJobChangeCompleteToSEQ(int separator);
	void __fastcall LaserJobChangeFailToSEQ(int separator);

	void __fastcall LaserJobChangeProcess(int nLaserNo ,String StrTemp);

	void __fastcall Laser1AutoCalPorcess(String StrTemp);
	void __fastcall Laser2AutoCalPorcess(String StrTemp);
	void __fastcall Laser3AutoCalPorcess(String StrTemp);
	void __fastcall Laser4AutoCalPorcess(String StrTemp);

	void __fastcall AutoCalDataReadFromSEQ(int Separator);
	void __fastcall LaserClosingProcess();
	bool __fastcall RecipeDownload(String SendPPID);
	bool __fastcall	RecipeUpload(String strPPID);

	void __fastcall RetrylaserRecipeCall();
	void __fastcall LaserRecipeNameCompare();
	void __fastcall LaserParamUpdateforTrackIn();

	void __fastcall SaveLaserLogProcess();
	void __fastcall AskLaserDetectPower(String strAsk);

	__fastcall TFrmLaserSetUp(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmLaserSetUp *FrmLaserSetUp;
//---------------------------------------------------------------------------
#endif
