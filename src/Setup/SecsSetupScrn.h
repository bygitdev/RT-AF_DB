//---------------------------------------------------------------------------

#ifndef SecsSetupScrnH
#define SecsSetupScrnH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include "LMDButton.hpp"
#include "LMDCustomButton.hpp"
#include <OleCtrls.hpp>
#include "EXGEMLib_OCX.h"
#include "Global.h"
#include <DB.hpp>
#include <DBTables.hpp>
#include "Include.h"
#include "PMSComm.h"

#define MAX_ARRAY     7
//---------------------------------------------------------------------------
class TFrmSecsSetUp : public TForm
{
__published:	// IDE-managed Components
    TImage *Image1;
    TMemo *SecsMemoLog;
    TGroupBox *GroupBox1;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TEdit *EditGemState;
    TEdit *EditCommState;
    TEdit *EditCtrlState;
    TGroupBox *GroupboxSecsControl;
    TLMDButton *BtnSecsCommStop;
    TLMDButton *BtnSecsCommStart;
	TEXGem *EXGem;
    TLMDButton *BtnProcessingState;
    TComboBox *m_cmbProcessingState;
    TLMDButton *BtnCommEnable;
    TLMDButton *BtnOffline;
    TLMDButton *BtnOnlineLocal;
    TLMDButton *BtnOnlineRemote;
    TTimer *SecsParamUpdate;
    TTimer *TMOnlineRemote;
    TLMDButton *BtnSecsAutoStart;
	TTimer *TrackInOutTimer;
	TLabel *Label4;
	TEdit *EditSpoolState;
	TLMDButton *BtnReqMarkingSpec;
	TTimer *MarkingSpecRequest;
    void __fastcall SecsMemoLogChange(TObject *Sender);
    void __fastcall BtnSecsCommStartClick(TObject *Sender);
    void __fastcall BtnSecsCommStopClick(TObject *Sender);
    void __fastcall BtnCommEnableClick(TObject *Sender);
    void __fastcall BtnOfflineClick(TObject *Sender);
    void __fastcall BtnOnlineLocalClick(TObject *Sender);
    void __fastcall BtnOnlineRemoteClick(TObject *Sender);
    void __fastcall EXGemeGEMCommStateChanged(TObject *Sender,
          long nState);
    void __fastcall EXGemeGEMControlStateChanged(TObject *Sender,
          long nState);
    void __fastcall EXGemeGEMErrorEvent(TObject *Sender, long nState);
    void __fastcall EXGemeXGEMStateEvent(TObject *Sender, long nState);
    void __fastcall EXGemeSECSMessageReceived(TObject *Sender,
          long nObjectID, long nStream, long nFunction, long nSysbyte);
    void __fastcall EXGemeGEMReqRemoteCommand(TObject *Sender, long nMsgId,
          BSTR sRcmd, long nCount, PWideString1 psNames,
          PWideString1 psVals);
    void __fastcall BtnSecsAutoStartClick(TObject *Sender);
    void __fastcall SecsParamUpdateTimer(TObject *Sender);
    void __fastcall EXGemeGEMTerminalMessage(TObject *Sender, long nMsgId,
          BSTR sSystemTime);
    void __fastcall TMOnlineRemoteTimer(TObject *Sender);
    void __fastcall TrackInOutTimerTimer(TObject *Sender);
    void __fastcall EXGemeGEMRspPPLoadInquire(TObject *Sender, BSTR sPpid,
          long nResult);
    void __fastcall EXGemeGEMReqPPLoadInquire(TObject *Sender, long nMsgId,
          BSTR sPpid, long nLength);
	void __fastcall EXGemeGEMSpoolStateChanged(TObject *Sender, long nState,
          long nLoadState, long nUnloadState, BSTR sFullTime, long nMaxTransmit,
          long nMsgNum, long nTotalNum, long nTransmitFail);
	void __fastcall EXGemeGEMReqPPSendEx(TObject *Sender, long nMsgId, BSTR sPpid,
          BSTR sBody);
	void __fastcall BtnReqMarkingSpecClick(TObject *Sender);
	void __fastcall MarkingSpecRequestTimer(TObject *Sender);


private:	// User declarations
	PMS _pms;
	
	int nSecsProcessState , nSecsPrevProcessState , nSecsCommState ,nSecsPrevControlState ,nSecsControlState;
	int nPrevOHTMzIndex;
	long g_nRowCnt, g_nColCnt, g_nTotalCnt;

	bool    bCommChk , b_SECSautoStart;

	bool    bOHTLoaderCall , bOHTUnloaderCall, bOHTMode;
	String  StrRecvLotQty;
	String	strMagazineID,strLotID;
	String	StrOHTModeSet;

    String  m_strMK_WeekCode , m_strMK_LDPMode;   //151014

	WideString GetWideString2AnsiString(AnsiString data);
	WideString WS2WS(WideString sVal);
	void __fastcall SetProcessingState(_eProcessingState eState);
	void __fastcall SecsParamVariableUpdateFunction(long nVid , WideString StrValue);
	void __fastcall SecsParamVariableNameUpdateFunction(WideString StrVid , WideString StrValue);
	void __fastcall Secs_OnlineRemoteProcess();
	void __fastcall Secs_CommEnableProcess();
	void __fastcall LaserDrillStartEndEventResponse(int DMnumber);

	void __fastcall SecsGemAutoStartProcess();

	void __fastcall TrackInProcess();
	void __fastcall LotProcessRegistered(AnsiString StrPartCode ,AnsiString StrLotCode ,AnsiString StrOpID);


	void __fastcall TrackOutProcess();

	String __fastcall PMSMapDataParse(int nColCnt, int nRowCnt, String strMapData);
	int __fastcall GetAsciiFunc(long nObjectID, WideString& strGetData, long lSize);
	int __fastcall SetAsciiFunc(long nObjectID, WideString strSetData, long lSize);

    void __fastcall MarkingSpecDataSave(AnsiString StrWeekCode ,AnsiString StrLDPMode);
	bool __fastcall PmsLotChkPopUp(String ServerLot,String RfidLot);

public:		// User declarations
	bool    m_fStart , m_bTrackoutException;
	String  Str_FL_PartCode , StrProcUnitcnt , StrGoodcnt ,StrRejectcnt;
	long    lDL_bodylen;
	void __fastcall StartArPartData(String strValue1,String strValue2);
	void __fastcall StartARSuccess();
	void __fastcall SecsInitializeProcess();
	void __fastcall SecsCloseProcess();
	void __fastcall SecsRunProcessingStatus(int nStatus);
	void __fastcall SecsStartProcess();
	void __fastcall SECSHistoryData(String StrTemp);
	void __fastcall StripMapDataSend(String EqpId,String strMap,String strOperId,int nStageNo,int nPmsNumber,int nQCLot,String strGEMLotID,String strSTEP);

	void __fastcall SecsTrackOutProcess(int nSelectIndex);

	bool __fastcall PPLoadInquireS7F1Process(WideString StrPPID, long lLength);
	bool __fastcall PPSendS7F3Process(WideString StrPPID , int nLen);
	void __fastcall RecipeupLoadStepProcess(String StrPartcode , int nStep);
	void __fastcall RecipedownLoadStepProcess(int nStep);

	void __fastcall S14F1Process(WideString strOBJID);
	void __fastcall OHTMCDownCancelFunc();
	String	getQCDataRegen( String szQCData );

    __fastcall TFrmSecsSetUp(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmSecsSetUp *FrmSecsSetUp;
//---------------------------------------------------------------------------
#endif
