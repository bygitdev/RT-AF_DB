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
#include "eXGemLib_OCX.h"
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
	TSpeedButton *BtnCommEnable;
	TSpeedButton *BtnOffline;
	TSpeedButton *BtnOnlineRemote;
	TSpeedButton *BtnOnlineLocal;
	TPanel *PanelGemState;
	TPanel *EditCommState;
	TPanel *EditCtrlState;
	TSpeedButton *BtnSecsCommStop;
	TSpeedButton *BtnSecsCommStart;
	TSpeedButton *BtnSecsAutoStart;
	TTimer *TMOnlineRemote;
	TeXGem *eXGem;
	void __fastcall BtnCloseClick(TObject *Sender);
	void __fastcall BtnSaveLogClick(TObject *Sender);
	void __fastcall SecsMemoChange(TObject *Sender);
	void __fastcall eXGemeGEMCommStateChanged(TObject *Sender, long nState);
	void __fastcall eXGemeGEMControlStateChanged(TObject *Sender, long nState);
	void __fastcall eXGemeGEMErrorEvent(TObject *Sender, long nState);
	void __fastcall eXGemeGEMReqPPLoadInquire(TObject *Sender, long nMsgId, BSTR sPpid,
          long nLength);
	void __fastcall eXGemeGEMReqPPSendEx(TObject *Sender, long nMsgId, BSTR sPpid, BSTR sBody);
	void __fastcall eXGemeGEMReqRemoteCommand(TObject *Sender, long nMsgId, BSTR sRcmd,
          long nCount, BSTR *psNames, BSTR *psVals);
	void __fastcall eXGemeSECSMessageReceived(TObject *Sender, long nObjectID, long nStream,
          long nFunction, long nSysbyte);
	void __fastcall eXGemeXGEMStateEvent(TObject *Sender, long nState);
	void __fastcall eXGemeGEMTerminalMessage(TObject *Sender, long nMsgId, BSTR sSystemTime);
	void __fastcall eXGemeGEMRspPPLoadInquire(TObject *Sender, BSTR sPpid, long nResult);
	void __fastcall BtnSecsCommStartClick(TObject *Sender);
	void __fastcall BtnSecsCommStopClick(TObject *Sender);
	void __fastcall BtnCommEnableClick(TObject *Sender);
	void __fastcall BtnOfflineClick(TObject *Sender);
	void __fastcall BtnOnlineLocalClick(TObject *Sender);
	void __fastcall BtnOnlineRemoteClick(TObject *Sender);
	void __fastcall TMOnlineRemoteTimer(TObject *Sender);



private:	// User declarations

	int nSecsProcessState ,nSecsPrevProcessState , nSecsCommState ,nSecsPrevControlState ,nSecsControlState;;
	long g_nRowCnt, g_nColCnt, g_nTotalCnt;

	bool    bCommChk;
	String  StrRecvLotQty;
	String	strMagazineID,strLotID;

   //	void StartArPartData(String strValue1,String strValue2);
   //	void StartARSuccess();

	void SecsCloseProcess();
	void SecsRunProcessingStatus(int nStatus);
	void SecsStartProcess();
	void SECSHistoryData(String StrTemp);
	void StripMapDataSend(String EqpId,String strMap,String strOperId,int nStageNo,int nPmsNumber,int nQCLot,String strGEMLotID,String strSTEP);
	void SecsGemAutoStartProcess();
	void SecsTrackOutProcess(int nSelectIndex);
	void Secs_CommEnableProcess();
    void Secs_OnlineRemoteProcess();

	String PMSMapDataParse(int nColCnt, int nRowCnt, String strMapData);
	bool PmsLotChkPopUp(String ServerLot,String RfidLot);


public:		// User declarations

	bool  m_fStart;
	void SecsInitializeProcess();

	__fastcall TFormSecsGemSet(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormSecsGemSet *FormSecsGemSet;
//---------------------------------------------------------------------------
#endif
