//---------------------------------------------------------------------------

#ifndef FormSecsGemSetScrnH
#define FormSecsGemSetScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "CurvyControls.hpp"
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.OleCtrls.hpp>
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
#include <System.Win.ScktComp.hpp>
#include "eXGemLib_OCX.h"
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Grids.hpp>

//---------------------------------------------------------------------------

class TFormSecsGemSet : public TForm
{
__published:	// IDE-managed Components
	TCurvyPanel *CurvyPanel1;
	TMemo *SecsMemo;
	TBitBtn *BtnClose;
	TSpeedButton *BtnSaveLog;
	TGroupBox *GroupBox1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TGroupBox *GroupboxSecsControl;
	TPanel *PanelGemState;
	TPanel *EditCommState;
	TPanel *EditCtrlState;
	TSpeedButton *BtnSecsCommStop;
	TSpeedButton *BtnSecsCommStart;
	TSpeedButton *BtnSecsAutoStart;
	TTimer *TMOnlineRemote;
	TGroupBox *GroupBox2;
	TGroupBox *GroupBox3;
	TEdit *EditOutPortID;
	TEdit *EditPortID;
	TButton *BtnGemPortID;
	TButton *BtnGemOutPortID;
	TTimer *GemOnlineTimer;
	TEdit *EditOPid;
	TComboBox *ComboBoxCarrierType;
	TButton *BtnGemCarrierType;
	TButton *BtnGemOPID;
	TButton *BtnBOATID;
	TEdit *EditMapSENDBoatID;
	TeXGem *eXGem;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TGroupBox *gbSecsgemOn;
	TSpeedButton *BtnCommEnable;
	TSpeedButton *BtnOnlineRemote;
	TSpeedButton *BtnOnlineLocal;
	TSpeedButton *BtnOffline;
	TTimer *SendVersionTimer;
	TTimer *tmRcpUpload;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TSpeedButton *SpeedButton1;
	TMemo *Memo1;
	TTabSheet *TabSheet2;
	TSpeedButton *SpeedButton2;
	TMemo *Memo2;
	TTabSheet *TabSheet3;
	TSpeedButton *SpeedButton3;
	TMemo *Memo3;
	TTabSheet *TabSheet4;
	TSpeedButton *SpeedButton4;
	TMemo *Memo4;
	TTabSheet *TabSheet5;
	TSpeedButton *SpeedButton5;
	TMemo *Memo5;
	TTabSheet *TabSheet6;
	TSpeedButton *SpeedButton6;
	TMemo *Memo6;
	TTabSheet *TabSheet7;
	TSpeedButton *SpeedButton7;
	TMemo *Memo7;
	TTabSheet *TabSheet8;
	TSpeedButton *SpeedButton8;
	TMemo *Memo8;
	TStringGrid *StringGrid1;
	TEdit *edtModuleID;
	TTabSheet *TabSheet9;
	TMemo *Memo9;
	TSpeedButton *SpeedButton9;
	TTabSheet *TabSheet10;
	TTabSheet *TabSheet11;
	TMemo *Memo10;
	TSpeedButton *SpeedButton10;
	TMemo *Memo11;
	TSpeedButton *SpeedButton11;
	TTabSheet *TabSheet12;
	TMemo *Memo12;
	TSpeedButton *SpeedButton12;
	TButton *Button5;
	TEdit *FEcmrTime;
	TButton *ReqTime;
	void __fastcall BtnCloseClick(TObject *Sender);
	void __fastcall BtnSaveLogClick(TObject *Sender);
	void __fastcall SecsMemoChange(TObject *Sender);
	void __fastcall BtnSecsCommStartClick(TObject *Sender);
	void __fastcall BtnSecsCommStopClick(TObject *Sender);
	void __fastcall BtnCommEnableClick(TObject *Sender);
	void __fastcall BtnOfflineClick(TObject *Sender);
	void __fastcall BtnOnlineLocalClick(TObject *Sender);
	void __fastcall BtnOnlineRemoteClick(TObject *Sender);
	void __fastcall TMOnlineRemoteTimer(TObject *Sender);
	void __fastcall BtnGemCarrierTypeClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall BtnGemOPIDClick(TObject *Sender);
	void __fastcall BtnGemPortIDClick(TObject *Sender);
	void __fastcall BtnGemOutPortIDClick(TObject *Sender);
	void __fastcall GemOnlineTimerTimer(TObject *Sender);
	void __fastcall BtnBOATIDClick(TObject *Sender);
	void __fastcall eXGemeGEMCommStateChanged(TObject *Sender, long nState);
	void __fastcall eXGemeGEMControlStateChanged(TObject *Sender, long nState);
	void __fastcall eXGemeGEMErrorEvent(TObject *Sender, long nState);
	void __fastcall eXGemeGEMReqPPLoadInquire(TObject *Sender, long nMsgId, BSTR sPpid,
          long nLength);
	void __fastcall eXGemeGEMReqPPSendEx(TObject *Sender, long nMsgId, BSTR sPpid, BSTR sBody);
	void __fastcall eXGemeGEMReqRemoteCommand(TObject *Sender, long nMsgId, BSTR sRcmd,
          long nCount, BSTR *psNames, BSTR *psVals);
	void __fastcall eXGemeGEMRspPPLoadInquire(TObject *Sender, BSTR sPpid, long nResult);
	void __fastcall eXGemeGEMTerminalMessage(TObject *Sender, long nMsgId, BSTR sSystemTime);
	void __fastcall eXGemeSECSMessageReceived(TObject *Sender, long nObjectID, long nStream,
          long nFunction, long nSysbyte);
	void __fastcall eXGemeXGEMStateEvent(TObject *Sender, long nState);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall eXGemeGEMReqOnline(TObject *Sender, long nMsgId, long nFromState,
          long nToState);
	void __fastcall eXGemeGEMReqPPEx(TObject *Sender, long nMsgId, BSTR sPpid, BSTR sBody);
	void __fastcall eXGemeGEMRspPPEx(TObject *Sender, BSTR sPpid, BSTR sBody);
	void __fastcall SendVersionTimerTimer(TObject *Sender);
	void __fastcall tmRcpUploadTimer(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall SpeedButton4Click(TObject *Sender);
	void __fastcall SpeedButton5Click(TObject *Sender);
	void __fastcall SpeedButton6Click(TObject *Sender);
	void __fastcall SpeedButton7Click(TObject *Sender);
	void __fastcall SpeedButton8Click(TObject *Sender);
	void __fastcall SpeedButton9Click(TObject *Sender);
	void __fastcall SpeedButton10Click(TObject *Sender);
	void __fastcall SpeedButton11Click(TObject *Sender);
	void __fastcall SpeedButton12Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall ReqTimeClick(TObject *Sender);

private:	// User declarations

	int nSecsProcessState ,nSecsPrevProcessState , nSecsCommState ,nSecsPrevControlState ,nSecsControlState;
	int nGemStatus;
	bool    bCommChk;
	int _nLotQty, _nMergeQty, _nMergeLotQty, _nXoutQty, m_nScrapCnt;
	String m_LotId, m_PartId, m_LotStatus, m_LotType, m_StepSeq, m_NextStepSeq, m_EqpType, m_Bypass, m_RecipeId, m_PcbSide;
	String m_PcbDut, m_MergeLotId, m_ProcessId, m_TestResult, m_ArtsScrap, m_R_Property, m_ScrapInfo, m_LotEndLotId, m_LotEndRejectLotId;
	String _StrOpid , _StrLoadType[2]  ,_StrCarrierType ,  _StrOrgLocation[4];

	String  _StrPortID , _StrOutPortID ;
	int  m_LotProcessStatus;	// NEW LOT, LOT END 시나리오 처리 상태용

	int _nPrevMCStatus, _nPrevGemState;
	String sMarsLogPath;
    String m_PkgName[1000];
	String m_DdmName[1000];
	const char* TerminalExclude;


	void SecsCloseProcess();
	void SecsStartProcess();
	void SECSHistoryData(String StrTemp);
	void SecsGemAutoStartProcess();
	void Secs_CommEnableProcess();
	void Secs_OnlineRemoteProcess();



	void GemRemoteCmdFeedBack(int nValue);
	int GemUpdateEvent(int nCategoryNo);
	int GemUpdateStatusVariable(int nCategoryNo);

	bool GemRecipeItemFileCreate(AnsiString sPPID="");
	bool GemTraceFileCreate(int nStageIndex);
	int __fastcall CombineFiles(String sDest, String sSource);
	void userMessageParsing(String strCmd, String* strObj, String* strVal, int nListCnt);

public:		// User declarations

	bool  m_fStart;
	String StrRecvMgzID;
	String recipePartName;
	BOOL _CompSeeLot;
	BOOL _CompScrapInfo;
	void SecsInitializeProcess();
	void S14F1Process(WideString strOBJID);
	void S14F4Process(WideString strOBJID, long nByte, String* strObj, String* strVal, int nListCnt);
	void g_GemAlarmProcess(int alarmid , bool bEnable);

	void GemDataValueStage_Refresh(int nDMFeedback);
	void GemDataValueTray_Refresh(int nDMFeedback);
	void GemDataTraceStage_Refresh(int nDMFeedback);
	void GemTRAYNumberUpdate(String strTrayNo);

	int __fastcall GetScrapCnt(){return m_nScrapCnt;}
	String __fastcall GetLotId(){return m_LotId;}
	String __fastcall GetPartId(){return m_PartId;}
    String __fastcall GetLotStatus(){return m_LotStatus;}
	String __fastcall GetLotType(){return m_LotType;}
	String __fastcall GetStepSeq(){return m_StepSeq;}
	String __fastcall GetEqpType(){return m_EqpType;}
    String __fastcall GetBypass(){return m_Bypass;}
	String __fastcall GetPcbSide(){return m_PcbSide;}
	String __fastcall GetProcessId(){return m_ProcessId;}
	String __fastcall GetScrapInfo(){return m_ScrapInfo;}
	String __fastcall GetNextStep(){return m_NextStepSeq;}


		//CEID Event
	void GemProcessStateChange();
	void GemOperatorECChange();
	void GemAlarmSet(int nAlarmNum);
	void GemAlarmClear(int nAlarmNum);
	void GemRecipeChange();
	void GemStopDescription();
	void GemOhtStateChange(int OhtIndex);
	void GemPortStateChangeLoad(int nGemState);
	bool GemVersionUpdate();
	void GemRFIDRead();
	bool TrackIn();
	bool TrackOut();

	void TrackIn_Cycle(int nDmNum);
	void SecsRunProcessingStatus(int nStatus);

	bool __fastcall ChangeMgzID(bool bEmptyMgz=false, int iPart=0, int iGdorRj=0);
	bool __fastcall FullCarrierMoveReq(bool bEmptyMgz=false,int iPart=0, int iGdorRj=0);
	bool __fastcall EmptyCarrierMoveReq(bool bEmptyMgz=false,int iPart=0);
	bool __fastcall ScrapInfo(int iPart=0);
	bool __fastcall AddScrap(int iPart=0, int iCnt=0, String sScrapId="");
	bool __fastcall DeleteScrap(int iPart=0, String sScrapId="");
	bool __fastcall GemPcbInfo();
	bool __fastcall GemLotInfo(int iStage, String sLotId="");	//0,1
	bool __fastcall eventRecipeUpload(int iPart=0);
	bool __fastcall eventRecipeDownload(int iPart=0);
	bool __fastcall manualRecipeDownload(String* strVal);
	bool __fastcall manualRecipeUpload(String* strVal);

    bool __fastcall	FileUpload(String strPPID);
	bool __fastcall	FileDownload(String strPPID);
	bool __fastcall PPLoadInquireS7F1Process(WideString StrPPID , long lLength);
	bool __fastcall PPSendS7F3Process(WideString StrPPID, int nLen);
	void __fastcall loadRecipeParamName();

    int __fastcall CompactZip(int iOption, String *sData);
	void	CompactResult(int nResult);
	void __fastcall DeleteTree(String stDirectory);
	void __fastcall doXCopy(String *sData);

	__fastcall TFormSecsGemSet(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormSecsGemSet *FormSecsGemSet;
//---------------------------------------------------------------------------
#endif
