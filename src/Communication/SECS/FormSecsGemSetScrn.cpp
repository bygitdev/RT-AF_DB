//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormSecsGemSetScrn.h"
#include "MainFormScrn.h"
#include "SECS\\FrmTerminalMsgScrn.h"
#include "include.h"

#include <stdio.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include "BaseComm.h"
#include "RecipeChangeFormScrn.h"
#include "VisionSetUpScrn.h"
#include "fSeeLot.h"
#include "FrmAutoFBHistory.h"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma link "eXGemLib_OCX"
#pragma resource "*.dfm"
#define	LOT_END_STEP_GD_COVER_COMP 7
#define	LOT_END_STEP_RJ_COVER_COMP 8
#define FCMR_STEP_GD_COMP		   11
#define FCMR_STEP_RJ_COMP		   12
TFormSecsGemSet *FormSecsGemSet;
//---------------------------------------------------------------------------
__fastcall TFormSecsGemSet::TFormSecsGemSet(TComponent* Owner)
	: TForm(Owner)
{

	bCommChk = false;
	m_fStart = false;

	nSecsProcessState = 0;
	nSecsPrevProcessState = 0;
	nSecsCommState = 0;
	nSecsPrevControlState = 0;
	nSecsControlState = 0;


    _StrLoadType[0] = "LOAD";
    _StrLoadType[1] = "UNLOAD";

    _StrOrgLocation[0] = "UL";
    _StrOrgLocation[1] = "UR";
    _StrOrgLocation[2] = "LL";
	_StrOrgLocation[3] = "LR";

	nGemStatus = 0;
}
//---------------------------------------------------------------------------
void __fastcall TFormSecsGemSet::FormCreate(TObject *Sender)
{
	loadRecipeParamName();
}
//---------------------------------------------------------------------------
void __fastcall TFormSecsGemSet::BtnCloseClick(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormSecsGemSet::FormShow(TObject *Sender)
{
	for (int i=1; i< StringGrid1->RowCount; i++)
		StringGrid1->Cells[0][i] = IntToStr(i);

	StringGrid1->Cells[1][0] = "Params";

	TIniFile *tIni = new TIniFile(ExtractFilePath(Application->ExeName) + "\\ini\\GemData.ini");
	if(FileExists(ExtractFilePath(Application->ExeName) + "\\ini\\GemData.ini"))
	{
		EditPortID->Text = tIni->ReadString("PORTDATA" , "PORTID" , "0");
		EditOutPortID->Text = tIni->ReadString("PORTDATA" , "OUTPORTID" , "0");

		ComboBoxCarrierType->ItemIndex = tIni->ReadInteger("CARRIER","TYPE",0);
		EditOPid->Text = tIni->ReadString("OPERATOR" , "OPID" , "0");
		EditMapSENDBoatID->Text = tIni->ReadString("BOATID" , "SCREENBOATID" , "0");


		_StrOpid = EditOPid->Text ;
		_StrCarrierType =  ComboBoxCarrierType->Text;

		_StrPortID = EditPortID->Text;
		_StrOutPortID = EditOutPortID->Text;

	}
	delete tIni;

	TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName) + "ini\\Setup.ini");
	if(!ini->SectionExists("MARS"))
	{
		ini->WriteString("MARS","PATH","C:\\KOSES\\TPLOG\\MARS\\RECIPE");
	}
	sMarsLogPath = ini->ReadString("MARS","PATH","C:\\KOSES\\TPLOG\\MARS\\RECIPE");
	delete ini;

	GemOnlineTimer->Enabled = true;
}
//---------------------------------------------------------------------------


void __fastcall TFormSecsGemSet::BtnSaveLogClick(TObject *Sender)
{
    TDateTime dt = Now();
    String FolderName = dt.FormatString("yyyy-mm-dd");
	String FileName = dt.FormatString("yyyy-mm-dd hh-nn-ss");
	String FullPath  =  "C:\\KOSES\\History\\SECSHistory\\"+ FolderName +"\\";
    ForceDirectories(FullPath);

    SecsMemo->Lines->SaveToFile(FullPath + FileName+".txt");

    SecsMemo->Clear();

	SECSHistoryData("LOG Saved"+ FullPath + FileName+".txt");
}
//---------------------------------------------------------------------------

void __fastcall TFormSecsGemSet::SecsMemoChange(TObject *Sender)
{
	SendMessage(SecsMemo->Handle, WM_VSCROLL, SB_BOTTOM, 0);
}
//---------------------------------------------------------------------------

void __fastcall TFormSecsGemSet::BtnSecsCommStartClick(TObject *Sender)
{
	this->SecsStartProcess();
}
//---------------------------------------------------------------------------

void __fastcall TFormSecsGemSet::BtnSecsCommStopClick(TObject *Sender)
{
	long	    nReturn = 0;
	char        szMsg[256];

	if( (nReturn = eXGem->Stop()) == 0 )
	{
		SECSHistoryData( "XGem stopped successfully" );
		BtnSecsCommStart->Enabled = true;
		BtnSecsCommStop->Enabled = false;
		gbSecsgemOn->Enabled = false;
		nWriteCommunicationDM(0,flagServerComm);
	}
	else
	{
		sprintf( szMsg, "Fail to stop XGem (%d)", nReturn );
		SECSHistoryData( szMsg );
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormSecsGemSet::BtnCommEnableClick(TObject *Sender)
{
	this->Secs_CommEnableProcess();
}
//---------------------------------------------------------------------------

void __fastcall TFormSecsGemSet::BtnOfflineClick(TObject *Sender)
{
	long	    nReturn = 0;
	char        szMsg[256];

	//Argument : None
	nReturn = eXGem->GEMReqOffline();
	if( nReturn == 0 )
	{
		SECSHistoryData( "Send GEMReqOffline successfully" );
	}
	else
	{
		sprintf( szMsg, "Fail to GEMReqOffline (%d)", nReturn );
		SECSHistoryData( szMsg );
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormSecsGemSet::BtnOnlineLocalClick(TObject *Sender)
{
	long	    nReturn = 0;
	char        szMsg[256];

	//Argument : None
	nReturn = eXGem->GEMReqLocal();
	if( nReturn == 0 )
	{
		SECSHistoryData( "Send GEMReqLocal successfully" );
	}
	else
	{
		sprintf( szMsg, "Fail to GEMReqLocal (%d)", nReturn );
		SECSHistoryData( szMsg );
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormSecsGemSet::BtnOnlineRemoteClick(TObject *Sender)
{
	this->Secs_OnlineRemoteProcess();
}
//---------------------------------------------------------------------------
void __fastcall TFormSecsGemSet::BtnGemPortIDClick(TObject *Sender)
{
	TIniFile *tIni = new TIniFile(ExtractFilePath(Application->ExeName) + "\\ini\\GemData.ini");
	if(FileExists(ExtractFilePath(Application->ExeName) + "\\ini\\GemData.ini"))
	{
		tIni->WriteString("PORTDATA","PORTID",EditPortID->Text.Trim());
		SECSHistoryData( "SET the PORT ID : " + EditPortID->Text.Trim());

		_StrPortID =  EditPortID->Text.Trim();
	}
	else
	{
		SECSHistoryData( "Check the port id GEMDATA.ini File ! ");
	}
	delete tIni;
}
//---------------------------------------------------------------------------

void __fastcall TFormSecsGemSet::BtnGemOutPortIDClick(TObject *Sender)
{
	TIniFile *tIni = new TIniFile(ExtractFilePath(Application->ExeName) + "\\ini\\GemData.ini");
	if(FileExists(ExtractFilePath(Application->ExeName) + "\\ini\\GemData.ini"))
	{
		tIni->WriteString("PORTDATA","OUTPORTID",EditOutPortID->Text.Trim());
		SECSHistoryData( "SET the OUTPORT ID : " + EditOutPortID->Text.Trim());

		_StrOutPortID =  EditOutPortID->Text.Trim();
	}
	else
	{
		SECSHistoryData( "Check the outport id GEMDATA.ini File ! ");
	}
	delete tIni;
}
//---------------------------------------------------------------------------


void __fastcall TFormSecsGemSet::BtnGemCarrierTypeClick(TObject *Sender)
{
	TIniFile *tIni = new TIniFile(ExtractFilePath(Application->ExeName) + "\\ini\\GemData.ini");
	if(FileExists(ExtractFilePath(Application->ExeName) + "\\ini\\GemData.ini"))
	{
		tIni->WriteString("CARRIER","TYPE",IntToStr(ComboBoxCarrierType->ItemIndex));
		SECSHistoryData( "SET the Carrier TYPE : " + ComboBoxCarrierType->Text.Trim());

		_StrCarrierType = ComboBoxCarrierType->Text;
	}
	else
	{
		SECSHistoryData( "Check the Carrier type GEMDATA.ini File ! ");
	}
	delete tIni;
}
//---------------------------------------------------------------------------
void __fastcall TFormSecsGemSet::BtnGemOPIDClick(TObject *Sender)
{
	TIniFile *tIni = new TIniFile(ExtractFilePath(Application->ExeName) + "\\ini\\GemData.ini");
	if(FileExists(ExtractFilePath(Application->ExeName) + "\\ini\\GemData.ini"))
	{
		tIni->WriteString("OPERATOR","OPID",EditOPid->Text.Trim());
		SECSHistoryData( "SET the operator ID : " + EditOPid->Text.Trim());

		_StrOpid =  EditOPid->Text.Trim();
	}
	else
	{
		SECSHistoryData( "Check the op id GEMDATA.ini File ! ");
	}
	delete tIni;
}
//---------------------------------------------------------------------------
void __fastcall TFormSecsGemSet::BtnBOATIDClick(TObject *Sender)
{
	TIniFile *tIni = new TIniFile(ExtractFilePath(Application->ExeName) + "\\ini\\GemData.ini");
	if(FileExists(ExtractFilePath(Application->ExeName) + "\\ini\\GemData.ini"))
	{
		tIni->WriteString("BOATID","SCREENBOATID",EditMapSENDBoatID->Text.Trim());
		SECSHistoryData( "SET the TEST BOAT ID : " + EditMapSENDBoatID->Text.Trim());
	}
	else
	{
		SECSHistoryData( "Check the boat id GEMDATA.ini File ! ");
	}
	delete tIni;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TFormSecsGemSet::GemOnlineTimerTimer(TObject *Sender)
{
//  int nVal = nReadCommunicationDM(GemConnectState);
//	if(nGemStatus != nVal)
//	{
//		nGemStatus = nVal;
//		if(m_fStart == false)
//		{
//			nWriteCommunicationDM(3, GemConnectState);
//			SECSHistoryData( "ONLINE STATE CHANGE OFF");
//		}
//		else
//		{
//			nWriteCommunicationDM(2, GemConnectState);
//			SECSHistoryData( "ONLINE STATE CHANGE ON");
//		}
//	}
//
//    MainForm->PanelGemConnect->Color = m_fStart ? clLime : clBtnFace;
}
//---------------------------------------------------------------------------
void __fastcall TFormSecsGemSet::TMOnlineRemoteTimer(TObject *Sender)
{
	TMOnlineRemote->Enabled = false;
	this->Secs_OnlineRemoteProcess();

	SendVersionTimer->Interval = 5000;
	SendVersionTimer->Enabled = true;
}
//---------------------------------------------------------------------------

void TFormSecsGemSet::S14F1Process(WideString strOBJID)
{
	long nReturn = 0;
	char szMsg[256];
	AnsiString szTemp;
	short nIndex = 0;
	short   nI1, nI2, nU1, nBinary, nBool;
    long    lI4, lI8, lU2;
    float   rF4;
    double  rU4, rU8, rF8;
    WideString sAscii;

	long nObjId = 0;
	long nS = 0;
	long nF = 0;
	long nSysbyte = 0;

	wchar_t* wstr = NULL;
	eXGem->MakeObject(&nObjId);
	// Setting values

	eXGem->SetList( nObjId, 5 );
	WideString  wStrP = "";
    wstr = wStrP.c_bstr();
    eXGem->SetAscii(nObjId, wstr, 1);
    wstr = NULL;
	wStrP = NULL;

	wStrP = "BoatMap";
    wstr = wStrP.c_bstr();
	eXGem->SetAscii(nObjId, wstr, 1);
    wstr = NULL;
	wStrP = NULL;

    eXGem->SetList( nObjId, 1 );    //  L 4
	wstr = strOBJID.c_bstr();
	eXGem->SetAscii( nObjId, wstr, 1 );

	eXGem->SetList( nObjId, 1 );    //  L 4

	eXGem->SetList( nObjId, 3 );   //  L 10
    wStrP = "2DCodeOriginLocation";
	wstr = wStrP.c_bstr();
	eXGem->SetAscii(nObjId, wstr, 1);		//
    wstr = NULL;
    wStrP = NULL;

	wStrP = "UPPERLEFT";
	wstr = wStrP.c_bstr();
	eXGem->SetAscii(nObjId, wstr, 1);		//
	wstr = NULL;
	wStrP = NULL;

	nU1 = 2;
	//wstr = wStrP.c_bstr();
	eXGem->SetU1( nObjId, &nU1, 1 );

    eXGem->SetList( nObjId, 6 );   //  L 10
    wStrP = "OriginLocation";
    wstr = wStrP.c_bstr();
	eXGem->SetAscii(nObjId, wstr, 1);		//
    wstr = NULL;
    wStrP = NULL;

    wStrP = "Rows";
    wstr = wStrP.c_bstr();
	eXGem->SetAscii(nObjId, wstr, 1);		//
    wstr = NULL;
    wStrP = NULL;

    wStrP = "Columns";
    wstr = wStrP.c_bstr();
	eXGem->SetAscii(nObjId, wstr, 1);		//
    wstr = NULL;
    wStrP = NULL;

	wStrP = "CellStatus";
	wstr = wStrP.c_bstr();
	eXGem->SetAscii(nObjId, wstr, 1);		//
	wstr = NULL;
	wStrP = NULL;

	wStrP = "LotID";
	wstr = wStrP.c_bstr();
	eXGem->SetAscii(nObjId, wstr, 1);		//
	wstr = NULL;
	wStrP = NULL;

	wStrP = "DeviceID";
	wstr = wStrP.c_bstr();
	eXGem->SetAscii(nObjId, wstr, 1);		//
	wstr = NULL;
	wStrP = NULL;

	nS = 14; nF = 1; nSysbyte = 0;
	nReturn = eXGem->SendSECSMessage(nObjId, nS, nF, nSysbyte);
	if( nReturn == 0 )
	{
		SECSHistoryData( "MESSAGE SEND S14 F1" );
	}
	else
	{
	}

	if(MainForm->b_TpConnect)
	{
		g_pTpBase->logComm(L"SYSTEM",L"SEND",L"'TYPE'",L"'SEC/GEMS'",L"'SEC/GEMS'",L"'S14F1'",L"'DURATION'",L"'NO'");
	}
}
//---------------------------------------------------------------------------

void TFormSecsGemSet::SecsInitializeProcess()
{
	long		nReturn = 0;
	char        szMsg[256];
	String	sCfg;

	WideString wStrPath = ExtractFilePath(Application->ExeName)+ "Ini\\XGEM.cfg";
	WCHAR* pPath = wStrPath.c_bstr();
	int nRetcode =  eXGem->Initialize(pPath);

	if(nRetcode == 0 )
	{
		SECSHistoryData("XGem initialized successfully");
		BtnSecsCommStart->Enabled = true;
		SecsGemAutoStartProcess();
	}
    else
    {
		sprintf( szMsg, "Fail to initialize XGem (%d)", nRetcode );
		SECSHistoryData(szMsg);
	}
}
//---------------------------------------------------------------------------

void TFormSecsGemSet::SecsStartProcess()
{
	long		nReturn = 0;
	char        szMsg[256];

    if( (nReturn = eXGem->Start()) == 0 )
    {
        SECSHistoryData( "XGem started successfully" );

	   // SecsParamUpdate->Enabled = true;
		BtnSecsCommStart->Enabled = false;
		BtnSecsCommStop->Enabled = true;
		gbSecsgemOn->Enabled = true;

	}
	else
	{
        sprintf( szMsg, "Fail to start XGem (%d)", nReturn );
        SECSHistoryData( szMsg );
	}
}
//---------------------------------------------------------------------------

void  TFormSecsGemSet::SecsGemAutoStartProcess()
{
	bool b_SECSautoStart;
	TIniFile *SecsIni = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\SECSConfig.ini");
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\SECSConfig.ini"))
	{
	   b_SECSautoStart = SecsIni->ReadBool("SECSSwitch","ONOFF",b_SECSautoStart);
	}
	delete SecsIni;

	if(b_SECSautoStart ==false)
	{
		BtnSecsAutoStart->Caption = "AUTO START OFF";
	}
	else
	{
		BtnSecsAutoStart->Caption = "AUTO START ON";
		SecsStartProcess();
	}
}
//---------------------------------------------------------------------------
void TFormSecsGemSet::Secs_OnlineRemoteProcess()
{
	long	    nReturn = 0;
	char        szMsg[256];

	//Argument : None
	nReturn = eXGem->GEMReqRemote();
	if( nReturn == 0 )
	{
		SECSHistoryData( "Send GEMReqRemote successfully" );
	}
	else
	{
		sprintf( szMsg, "Fail to GEMReqRemote (%d)", nReturn );
		SECSHistoryData( szMsg );
	}
}
//---------------------------------------------------------------------------

void TFormSecsGemSet::SecsCloseProcess()
{
	long	    nReturn = 0;
	char        szMsg[256];

    if( (nReturn = eXGem->Close()) == 0 )
	{
        SECSHistoryData( "XGem closed successfully" );
    }
	else
    {
        sprintf( szMsg, "Fail to close XGem (%d)", nReturn );
        SECSHistoryData( szMsg );
    }
}
//---------------------------------------------------------------------------
void TFormSecsGemSet::SECSHistoryData(String StrTemp)
{
	SecsMemo->Lines->Add(DateTimeToStr(Now()) + ": " + StrTemp);
	SecsMemo->Refresh();

	if(SecsMemo->Lines->Count > 1000)
	{
		TDateTime dt = Now();
		String FolderName = dt.FormatString("yyyy-mm-dd");
		String FileName = dt.FormatString("yyyy-mm-dd hh-nn-ss");
		String FullPath  =  "C:\\KOSES\\History\\SECSHistory\\"+ FolderName +"\\";
		ForceDirectories(FullPath);

		SecsMemo->Lines->SaveToFile(FullPath + FileName+".txt");

		SecsMemo->Clear();
	}
}
//---------------------------------------------------------------------------

void TFormSecsGemSet::SecsRunProcessingStatus(int nStatus)
{
	if(m_fStart != true)
		return;

	long  nVid = 0;

	String StrPrevStatus = PanelGemState->Caption;

	if(nStatus == Processing_Stop)
	{
		PanelGemState->Caption =  "Machine Stop";
		nSecsProcessState = Processing_Stop ;
	}
	else if(nStatus == Processing_Run)
	{
		PanelGemState->Caption =  "Machine Run";
		nSecsProcessState = Processing_Run ;
	}
	else if(nStatus == Processing_Error)
	{
		PanelGemState->Caption =  "Machine Error";
		nSecsProcessState = Processing_Error ;
	}
	else if(nStatus == Processing_Idle)
	{
		PanelGemState->Caption =  "Machine Idle";
		nSecsProcessState = Processing_Idle ;
	}
	else
	{
		PanelGemState->Caption =  "Machine Stop";
		nSecsProcessState = Processing_Stop ;
	}

	nVid = 2001;  // EQP ID
	eXGem->GEMSetVariable(1, &nVid, &WideString(MainForm->_eqpID));

	nVid = 1001;  // Process State SVID
	eXGem->GEMSetVariable(1, &nVid, &WideString(nSecsProcessState));

	nVid = 1004;  // Process State SVID
	eXGem->GEMSetVariable(1, &nVid, &WideString(nSecsProcessState));

	nVid = 1005;  // Previous Process State SVID
	eXGem->GEMSetVariable(1, &nVid, &WideString(nSecsPrevProcessState));

	SECSHistoryData("Process State Change : " +IntToStr(nSecsPrevProcessState)+ " -> " + IntToStr(nSecsProcessState));

	int nReturn = eXGem->GEMSetEvent(1001);
	if( nReturn == 0 )
	{
		SECSHistoryData( "Processing Status Change" + StrPrevStatus + "->"+  PanelGemState->Caption);

		if(MainForm->b_TpConnect)
		{
			g_pTpBase->logComm(L"SYSTEM",L"SEND", L"'TYPE'",L"'SECS/GEM'", L"'SECS/GEM'",L"'S6F11'", L"'CEID'",L"1001", L"'DURATION'",L"'NO'");
		}

		/*if(nSecsProcessState == Processing_Run)
			GemRecipeChange();*/ // 비활성화
	}
	else
	{
		char szMsg[256];
		sprintf(szMsg, "[EQ ==> XGEM] GEMSetEvent (1001) Error Code => %d", nReturn );
		SECSHistoryData( szMsg );
	}
	nSecsPrevProcessState = nSecsProcessState;
}
//---------------------------------------------------------------------------

void TFormSecsGemSet::Secs_CommEnableProcess()
{
	long	    nReturn = 0;
	char        szMsg[256];

	if(bCommChk ==false)
	{
		//Argument : bState value(0: disable, 1: enable)
		nReturn = eXGem->GEMSetEstablish(1);
	}
	else
	{
		//Argument : bState value(0: disable, 1: enable)
		nReturn = eXGem->GEMSetEstablish(0);
	}

	if( nReturn == 0 )
	{
		SECSHistoryData( "Send GEMSetEstablish successfully" );
		if(bCommChk ==false)
		{
			BtnCommEnable->Caption = "COMMUNICATION \n  DISABLE";
			bCommChk = true;
		}
		else
		{
			BtnCommEnable->Caption  ="COMMUNICATION   \n ENABLE";
			bCommChk = false;
		}
	}
	else
	{
		sprintf( szMsg, "Fail to GEMSetEstablish (%d)", nReturn );
		SECSHistoryData( szMsg );
	}
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void TFormSecsGemSet::GemRemoteCmdFeedBack(int nValue)
{
	SECSHistoryData( "NEXT WORK CMD RECEIVE -> " + IntToStr(nValue));

	switch(nValue)
	{
		case 1200:
		{

		}
		break;

		default :
		{
			SECSHistoryData( "EXCEPTION NEXT WORK CMD RECEVE -> " + IntToStr(nValue));
		}
		break;
	}
}
//---------------------------------------------------------------------------
void TFormSecsGemSet::g_GemAlarmProcess(int nAlarmid , bool bEnable)
{
	if(m_fStart == true)
	{
	//state (0 : clear, 1: detect)
		int nRet = eXGem->GEMSetAlarm(nAlarmid, bEnable);

		String strtemp =  bEnable ? "DETECT" : "CLEAR";
		if(nRet == 0)
		{
			SECSHistoryData(strtemp +  " ALARM EVENT SEND : " + IntToStr(nAlarmid) +" : " +_AlarmNameReturn(1 ,nAlarmid));
		}
		else
		{
			SECSHistoryData(strtemp +  " !ALARM EVENT SEND FAIL! : " + IntToStr(nAlarmid)+" : " +_AlarmNameReturn(1 ,nAlarmid));
		}
	}
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TFormSecsGemSet::eXGemeGEMCommStateChanged(TObject *Sender, long nState)

{
	char        szMsg[256];
	char	    szState[64];

	if (nState == Comm_None)
	{
		m_fStart = false;
		nWriteCommunicationDM(0,flagServerComm);
		strcpy(szState, "None");
	}
	else if (nState == Comm_Disabled)
	{
		m_fStart = false;
		nWriteCommunicationDM(0,flagServerComm);
        strcpy(szState, "Disabled");
	}

	else if(nState == Comm_WaitCRFromHost)
	{
		m_fStart = false;
		nWriteCommunicationDM(0,flagServerComm);
		strcpy(szState, "Wait CR From Host");
	}

	else if(nState == Comm_WaitDelay)
	{
        m_fStart = false;
		nWriteCommunicationDM(0,flagServerComm);
        strcpy(szState, "Wait Delay");
	}

	else if(nState == Comm_WaitCRA)
	{
		m_fStart = false;
		nWriteCommunicationDM(0,flagServerComm);
        strcpy(szState, "Wait CRA");
	}

	else if(nState == Comm_Communicating)
	{
		m_fStart = true;
		nWriteCommunicationDM(1,flagServerComm);
		strcpy(szState, "Communicating");
		TMOnlineRemote->Enabled =true;
	}

	else if(nState == Comm_Enabled)
	{
		nWriteCommunicationDM(1,flagServerComm);
		strcpy(szState, "Enabled");
    }
	EditCommState->Caption = szState;

//    if(m_fStart ==  true && FormMainStatus->MainPanelLed10->Color == clGreen)
//	{
//    	Status_Led(FormMainStatus->MainPanelLed10 ,_STATUS_LED_GREEN_ , true , "ON");
//    }
//	else
//    {
//    	Status_Led(FormMainStatus->MainPanelLed10 ,_STATUS_LED_GREEN_ , false , "OFF");
//	}

	sprintf( szMsg, "Received %s, %s", "GEMCommStateChanged", szState );
    SECSHistoryData( szMsg );
}
//---------------------------------------------------------------------------

void __fastcall TFormSecsGemSet::eXGemeGEMControlStateChanged(TObject *Sender, long nState)

{
	char        szMsg[256];
	char	    szState[64];
	int 		nXGemState=0;

	if (nState == Control_EqOffline)
	{
		nXGemState = 1;
		strcpy(szState, "OffLine");
	}
	else if(nState == Control_AttemptOnline)
	{
		nXGemState = 2;
		strcpy(szState, "Attempt OnLine");
	}
	else if(nState == Control_HostOffline)
	{
		nXGemState = 3;
		strcpy(szState, "Host OffLine");
	}
	else if(nState == Control_Local)
	{
		nXGemState = 4;
		strcpy(szState, "Online-Local");
	}
	else if(nState == Control_Remote)
	{
		nXGemState = 5;
		strcpy(szState, "Online-Remote");
	}
	else
	{
		nXGemState = 0;
		strcpy(szState, "Control_None");
	}
	EditCtrlState->Caption = szState;
	//this->GemPortStateChangeLoad(nXGemState);

	sprintf( szMsg, "Received %s, %s", "GEMControlStateChanged", szState );
	SECSHistoryData( szMsg );
}
//---------------------------------------------------------------------------

void __fastcall TFormSecsGemSet::eXGemeGEMErrorEvent(TObject *Sender, long nState)

{
	char    szMsg[256];
	AnsiString sDefineError = "";
	switch(nState)
	{
		case -30010:
			sDefineError = "Control state is offline";
			break;
		case -30011:
			sDefineError = "Control state is not changed";
			break;
		case -30012:
			sDefineError = "File is not created";
			break;
		case -30013:
			sDefineError = "Failed to open database";
			break;
		case -30014:
			sDefineError = "Failed to execute sql";
			break;
		case -30015:
			sDefineError = "Failed to open sql";
			break;
		case -30016:
			sDefineError = "Enabled attribute of CEID is false";
			break;
		case -30017:
			sDefineError = "Report buffer is full";
			break;
		case -30018:
			sDefineError = "This system does not use spooling now";
			break;
		case -30021:
			sDefineError = "Spool is not active, so message can not spooling";
			break;

		case -30251:
			sDefineError = "Invalid VID";
			break;
		case -30252:
			sDefineError = "Invalid ALID";
			break;
		case -30253:
			sDefineError = "Invalid CEID";
			break;
		case -30254:
			sDefineError = "Invalid RPTID";
			break;
		case -30258:
			sDefineError = "Invalid RCmd";
			break;
		case -30259:
			sDefineError = "Invalid Stream";
			break;
		case -30260:
			sDefineError = "Invalid Function";
			break;
		case -30262:
			sDefineError = "Invalid Error Code(id)";
			break;
		case -30264:
			sDefineError = "Invalid Data Format";
			break;
		case -30266:
			sDefineError = "Invalid Structure";
			break;
		case -30269:
			sDefineError = "Invalid Data Type";
			break;
		case -30270:
			sDefineError = "PPID Invalid Check";
			break;
		case -30271:
			sDefineError = "Invalid State changed";
			break;
		case -30272:
			sDefineError = "Invalid trace id";
			break;
		case -30273:
			sDefineError = "Not found buffer";
			break;
		case -30274:
			sDefineError = "Value is out of range";
			break;
		case -30275:
			sDefineError = "SVID does not exist";
			break;
	}
	sprintf( szMsg, "Received %s, Error Code = [%d]%s", "GEMErrorEvent", nState, sDefineError );
	SECSHistoryData( szMsg );
}
//---------------------------------------------------------------------------

void __fastcall TFormSecsGemSet::eXGemeGEMReqPPLoadInquire(TObject *Sender, long nMsgId,
          BSTR sPpid, long nLength)
{
	// [H->E] S7F1 : recipe load inquire.
	long nReturn = 0;
	char szMsg[256];
	AnsiString strPPID(sPpid);
	sprintf(szMsg, "[H->E] S7F1 : Received %s, MsgId = %d, Ppid = %s, Length = %d", "GEMReqPPLoadInquire", nMsgId, strPPID, nLength );
	SECSHistoryData( szMsg );
	//logForm->logHistorySave(1,"[H->E],S7F1,"+strPPID+","+String(nLength)+",");

	long nResult = 0;
	nReturn = eXGem->GEMRspPPLoadInquire(nMsgId, sPpid, nResult);
	if( nReturn == 0 )
	{
		SECSHistoryData( "[E->H] S7F2 : GEMRspPPLoadInquire successfully : " +strPPID );
	}
	else
	{
		SECSHistoryData( "[E->H] S7F2 : Fail to GEMRspPPLoadInquire : " + String(nReturn) );
	}
	//logForm->logHistorySave(1,"[E->H],S7F2,RESULT:"+String(nReturn)+",");
}
//---------------------------------------------------------------------------

void __fastcall TFormSecsGemSet::eXGemeGEMReqPPSendEx(TObject *Sender, long nMsgId,
		  BSTR sPpid, BSTR sBody)
{
	// [H->E] S7F3 : recipe download req.
	AnsiString strPPID(sPpid);
	AnsiString StrRcpPath =  ExtractFilePath(Application->ExeName)+ "Gem\\SSD\\XWork\\Recipe\\" + strPPID;

	SECSHistoryData("[H->E] S7F3 : Host download the recipe file : " +StrRcpPath);
	//logForm->logHistorySave(1,"[H->E],S7F3,"+strPPID+",");

	// S7F4
	long nRet = 0;
	eXGem->GEMRspPPSend(nMsgId, sPpid, nRet);
	if(nRet == 0)
	{
		SECSHistoryData( "[E->H] S7F4 : GEMRspPPSend successfully");

		// To do SEQ ask to change recipe(device)
		FileDownload(strPPID);

	}
	else
	{
		SECSHistoryData( "[E->H] S7F4 : Fail to GEMRspPPSend : " + String(nRet) );
	}
	//logForm->logHistorySave(1,"[E->H],S7F4,RESULT:"+String(nRet)+",");
}
//---------------------------------------------------------------------------

void __fastcall TFormSecsGemSet::eXGemeGEMReqRemoteCommand(TObject *Sender, long nMsgId,
          BSTR sRcmd, long nCount, BSTR *psNames, BSTR *psVals)
{
	char szMsg[256];
	AnsiString sName;
	String sValue;
	int nResult=0, nNdmNum=0, nCeidNum=0;
	long nHCAck = 0;
	long *pnResult = NULL;

	int iResultCnt = 1;
	if(nCount != 0)
	{
		iResultCnt = nCount;
	}

	pnResult = new long[iResultCnt];
	for(int i = 0; i < iResultCnt; i++)
	{
		pnResult[i] = 0;
	}

	try
	{
		String m_Rcmd = AnsiString(sRcmd);
		String logCmd = "'"+m_Rcmd+"'";
		if(nCount != 0)
		{
			sName = AnsiString(psNames[0]);
			sValue = String(psVals[0]);
		}
		SECSHistoryData( "Received GEMReqRemoteCommand : " + m_Rcmd  + " COUNT : " +String(nCount));

		if(m_Rcmd == "STOP")
		{
			// 장비 Stop cmd
			nWriteCommunicationDM(STATE_REQ, fdcCmdStop);

			if(MainForm->b_TpConnect)
			{
				g_pTpBase->logComm(L"SYSTEM",L"RECV", L"'TYPE'",L"'SECS/GEM'", L"'SECS/GEM'",L"'S2F41'", L"'RCMD'",logCmd.c_str(), L"'DURATION'",L"'NO'");
			}
		}
		if(m_Rcmd == "START")
		{
			// 장비 Start cmd
			//nWriteCommunicationDM(STATE_REQ, fdcCmdStop);
		}

		if(m_Rcmd == "NEXT_WORK_REQ")
		{
			nResult = STATE_COMP;	//101
			if(sName == "CUR_STEP_CEID")
			{
				String strVal = psVals[0];
				nCeidNum = _wtoi(strVal.w_str());
			}

			if(MainForm->b_TpConnect)
			{
				g_pTpBase->logComm(L"SYSTEM",L"RECV", L"'TYPE'",L"'SECS/GEM'", L"'SECS/GEM'",L"'S2F41'", L"'RCMD'",logCmd.c_str(), L"'DURATION'",L"'NO'");
			}
		}
		else if(m_Rcmd == "STOP_WORK_REQ")
		{
			nResult = STATE_ERR;
			if(sName == "CUR_STEP_CEID")
			{
				String strVal = psVals[0];
				nCeidNum = _wtoi(strVal.w_str());
			}

			if(MainForm->b_TpConnect)
			{
			   g_pTpBase->logComm(L"SYSTEM",L"RECV", L"'TYPE'",L"'SECS/GEM'", L"'SECS/GEM'",L"'S2F41'", L"'RCMD'",logCmd.c_str(), L"'DURATION'",L"'NO'");

			}
		}
		else if(m_Rcmd == "STOP_STEP_REQ")	// NOT USE
		{
			nResult = STATE_COMP;
			if(sName == "FDC FAIL")
			{
				String strVal = psVals[0];
				nCeidNum = _wtoi(strVal.w_str());
			}

			if(MainForm->b_TpConnect)
			{
				g_pTpBase->logComm(L"SYSTEM",L"RECV", L"'TYPE'",L"'SECS/GEM'", L"'SECS/GEM'",L"'S2F41'", L"'RCMD'",logCmd.c_str(), L"'DURATION'",L"'NO'");
			}
		}
		else
			nHCAck	= 1;

		switch(nCeidNum)
		{
			case 1001:	//EQP STATUS
				if(nResult == STATE_ERR)
				{
					nNdmNum = fdcCmdStop;
					nResult = 1; // SEQ 요청 값 1.

					MainForm->MachineHistoryData("[H->E],1001(EQP_STATUS),"+m_Rcmd);
				}
				break;

			case 1201:	//Recipe Upload Req.
				if(nResult == STATE_ERR)
				{
					nNdmNum = fdcCmdStop;
					nResult = 1;

					MainForm->MachineHistoryData("[H->E],1201(RECIPE_UPLOAD),"+m_Rcmd);
				}
				break;

			case 1202:	//Recipe Download Req.
				if(nResult == STATE_ERR)
				{
					nNdmNum = fdcCmdStop;
					nResult = 1;

					MainForm->MachineHistoryData("[H->E],1202(RECIPE_DOWNLOAD),"+m_Rcmd);
				}
				break;

			case 2004:	//Lot Display
				MainForm->MachineHistoryData("[H->E],2004(LOT_DISPLAY),"+m_Rcmd+","+m_RecipeId);
				if(m_LotProcessStatus==0)
				{
					nNdmNum = seeLotStep;
					//RMS Compare
					if(nResult == STATE_COMP)
					{
						LOT_INFO	info;
						if(ReadLotInfoData(CMD_RD_BUFFER_LOTINFO,info))
						{
							//String oldRcpId = String(info.recipeID);	//.ZIP
							String oldRcpId = Get_RecipeName() + ".ZIP";
							if(oldRcpId.UpperCase().Trim() != m_RecipeId.UpperCase().Trim())
								nResult = STATE_RCPCHG;

							MainForm->MachineHistoryData(String().sprintf(L"xgem Lot Display Finish Rcp o: %s, n: %s",oldRcpId,m_RecipeId));

							strcpy(info.recipeID, AnsiString(m_RecipeId).c_str());
							strcpy(info.step, AnsiString(m_StepSeq).c_str());
							strcpy(info.lotType, AnsiString(m_LotType).c_str());

							if (WriteLotInfoData(CMD_WR_BUFFER_LOTINFO,info))
							{

							}
							else
							{
								SECSHistoryData( "eGEMReqRemoteCommand() Fail to WriteLotInfoData() : " + m_RecipeId);
							}
						}
						else
						{
							SECSHistoryData( "eGEMReqRemoteCommand() Fail to ReadLotInfoData() : 2004(LOT_DISPLAY)");
						}
					}
				}
				else if(m_LotProcessStatus==1)
				{
					//Manual Btn..
					if(nResult == STATE_COMP)
					{
						_CompSeeLot = true;
						frmSeeLot->lotState->Text = m_LotStatus;
						frmSeeLot->partNo->Text = m_PartId;
						frmSeeLot->qty->Text = IntToStr(_nLotQty);

						nWriteCommunicationDM(_nLotQty, serverPcbQty);

						frmSeeLot->msg->Text = "";
					}
					else
					{
						frmSeeLot->lotState->Text = "";
						frmSeeLot->partNo->Text = "";
						frmSeeLot->qty->Text = "";
						frmSeeLot->msg->Text = "Fail to Lot Display (STOP_WORK_REQ)";
					}
					// AutoLotEnd 껏을 경우 Scrap Timer Enable
					if(!bReadUseSkip(usAutoLotEnd))
					frmSeeLot->tmScrapInfo->Enabled = true;
				}
				else if(m_LotProcessStatus==2)
				{
					//Manual Btn..
					if(nResult == STATE_COMP)
					{
						RecipeChangeForm->edtPartId->Text = m_PartId;
						RecipeChangeForm->edtStepSeq->Text = m_StepSeq;
						RecipeChangeForm->edtLotType->Text = m_LotType;
						RecipeChangeForm->pnHostRecipeId->Caption = m_RecipeId;
					}
					else
					{
						RecipeChangeForm->edtLotId->Text = "Fail to Lot Display (STOP_WORK_REQ) ...";
						RecipeChangeForm->edtPartId->Text = "";
						RecipeChangeForm->edtStepSeq->Text = "";
						RecipeChangeForm->edtLotType->Text = "";
						RecipeChangeForm->pnHostRecipeId->Caption = "";
					}
				}
				break;

			case 2005:	//CHANGE MAZID
			{
				int GdorRjComp = nReadCommunicationDM(lotEndStep);

				if(GdorRjComp == LOT_END_STEP_GD_COVER_COMP)
				{
					nNdmNum = reqMgzInfoChgGood;
					MainForm->MachineHistoryData("[H->E],2005(GOOD CHANGE_MAZID),"+m_Rcmd+","+m_RecipeId);

					if(nResult == STATE_COMP)
					{
						nWriteCommunicationDM(STATE_COMP, reqMgzInfoChgGood);
						MainForm->MachineHistoryData("Event 2005 (GOOD CHANGE MAZID) STATE_COMP");
					}
				}

				if(GdorRjComp == LOT_END_STEP_RJ_COVER_COMP)
				{
					nNdmNum = reqMgzInfoChgReject;
					MainForm->MachineHistoryData("[H->E],2005(REJECT CHANGE_MAZID),"+m_Rcmd+","+m_RecipeId);

					if(nResult == STATE_COMP)
					{
						nWriteCommunicationDM(STATE_COMP, reqMgzInfoChgReject);
						MainForm->MachineHistoryData("Event 2005 (REJECT CHANGE MAZID) STATE_COMP");
					}
				}
			}
				break;

			case 2007:              // ECMR
			{
				MainForm->MachineHistoryData("[H->E],2007(EMPTY_CARRIER_MOVE_REQUEST),"+m_Rcmd+","+m_RecipeId);

				if(nResult == STATE_COMP)
				{
					nWriteCommunicationDM(STATE_COMP, reqTrayEcmr);
					MainForm->MachineHistoryData("Event 2007 (EMPTY_CARRIER_MOVE_REQUEST) STATE_COMP");
				}
			}
				break;


			case 2008:         		// FCMR
			{

				int FcmrComp = nReadCommunicationDM(lotEndStep);

				if(FcmrComp == FCMR_STEP_GD_COMP)
				{
					MainForm->MachineHistoryData("[H->E],2008(GOOD FULL_CARRIER_MOVE_REQUEST),"+m_Rcmd+","+m_RecipeId);

					if(nResult == STATE_COMP)
					{
						nWriteCommunicationDM(STATE_COMP, reqMgzGdFcmr);
						MainForm->MachineHistoryData("Event 2008 (FULL_CARRIER_MOVE_REQUEST) STATE_COMP");
					}
				}

				if(FcmrComp == FCMR_STEP_RJ_COMP)
				{
					MainForm->MachineHistoryData("[H->E],2008(REJECT FULL_CARRIER_MOVE_REQUEST),"+m_Rcmd+","+m_RecipeId);

					if(nResult == STATE_COMP)
					{
						nWriteCommunicationDM(STATE_COMP, reqMgzRjFcmr);
						MainForm->MachineHistoryData("Event 2008 (REJECT FULL_CARRIER_MOVE_REQUEST) STATE_COMP");
					}
				}

			}
				break;

			case 2101: //Lot End Other
				nNdmNum = lotEndStep;
				if(nResult == STATE_COMP)
				{
					String model = Get_RecipeName();
					LOT_INFO	info;
					if(ReadLotInfoData(CMD_RD_LOT_END_INFO,info)==false)
						MainForm->MachineHistoryData("eGEMReqRemoteCommand() Fail to ReadLotInfoData() : 2101(LOT_END)");

					strcpy(info.rejectLotID, AnsiString(m_LotEndRejectLotId).c_str());
					MainForm->MachineHistoryData("LotEnd RejectID : " + AnsiString(info.rejectLotID));
					MainForm->SaveToCSVFile(String(info.mergeLotID));
					frmSeeLot->setCycle(true);

					if (WriteLotInfoData(CMD_WR_OHT_LOT_INFO, info))
					{

					}
					else
					{
						SECSHistoryData( "eGEMReqRemoteCommand() Fail to WriteLotInfoData() : " + m_RecipeId);
					}
				}
				else if(nResult == STATE_ERR)
				{
					if(bReadUseSkip(usAutoLotEnd))
					{
						if (!frmSeeLot->Showing)
						{
							if(FormSecsGemSet->m_fStart)
							{
								MainForm->MachineHistoryData("Auto Lot End Fail, Lot End Popup");

								frmSeeLot->setMode();
								frmSeeLot->ShowModal();
							}
						}
                    }

					if(strstr(TerminalExclude, "TKOUT FAIL :: Invalid Lot Status!"))
					{
						TerminalExclude = "";
					}
					else
					{
						nResult = STATE_ERR2;
					}
				}

				MainForm->MachineHistoryData("[H->E],2101(LOT_END),"+m_Rcmd);
				break;

			case 2114:	//ADD SCRAP
				if(MainForm->_onlineEndIndex = 99)	//manual
				{
					MainForm->MachineHistoryData("[H->E],2114(ADD_SCRAP) manual,"+m_Rcmd+","+m_RecipeId);

					//결과에 상관없이 호출
					frmSeeLot->tmSeeLot->Enabled = true;
				}
				else
				{
					MainForm->MachineHistoryData("[H->E],2114(ADD_SCRAP),"+m_Rcmd+","+m_RecipeId);

					nNdmNum = onlineEndStep1 + MainForm->_onlineEndIndex;
					if(nResult == STATE_ERR)
					{
						frmSeeLot->setMsg("Fail to Add Scrap (STOP_WORK_REQ)");
					}

				}
				break;

			case 2115:	//SCRAP INFO
				MainForm->MachineHistoryData("[H->E],2115(SCRAP_INFO),"+m_Rcmd+","+m_RecipeId);
				if(nResult == STATE_COMP)
				{
					int iScrapCnt = FormSecsGemSet->GetScrapCnt();
					AnsiString sScrapInfo = FormSecsGemSet->GetScrapInfo();
					nWriteCommunicationDM(iScrapCnt, serverScrapCnt );

					char body[100000]={0,};
					strcpy(body, sScrapInfo.c_str());
					char scrapSeps[]={"=() "};
					char *tok = NULL;
					AnsiString scrapCode[10000], scrapArraySN[10000];
					//SCRAP_INFO001=(SCRAP_CODE=3305 ARRAYSN=1M393A4K40BB2CTD7YXXXA054FXXX001_1 SERIAL=  EQPMODEL=KSS700) SCRAP_INFO002=(SCRAP_CODE=3404 ARRAYSN=1M393A4K40BB2CTD7YXXXA054FXXX001_2 SERIAL= ...
					for(int i=0; i< iScrapCnt; i++)
					{
						if(i==0)
							tok = strtok(body, scrapSeps);	// SCRAP_INF001
						 else
							tok = strtok(NULL, scrapSeps);	// SCRAP_INF001

						 tok = strtok(NULL, scrapSeps);	// SCRAP_CODE
						 tok = strtok(NULL, scrapSeps);	// CODE NUM
						 scrapCode[i] = (char*)(tok+0);
						 tok = strtok(NULL, scrapSeps);	// ARRAYSN
						 tok = strtok(NULL, scrapSeps);	// ARRAY NUM
						 scrapArraySN[i] = (char*)(tok+0);
						 tok = strtok(NULL, scrapSeps);	// SERIAL
						 tok = strtok(NULL, scrapSeps);	// EQPMODEL
						 tok = strtok(NULL, scrapSeps);	// KSS700
					}

					g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_SCRAP_INFO_CUR_COPY;
					g_MMIComm->m_mmiToSeq.buffer.onlineEndHistoryCopy.scrapCnt = iScrapCnt;

					for(int i=0; i<iScrapCnt; i++)
					{
						strcpy( g_MMIComm->m_mmiToSeq.buffer.onlineEndHistory.scrapCode[i], scrapCode[i].c_str() );
						strcpy( g_MMIComm->m_mmiToSeq.buffer.onlineEndHistory.scrapArraySN[i], scrapArraySN[i].c_str() );
					}

					bool bRet = g_MMIComm->Send() &&  g_MMIComm->Recv();

					if(bRet)
					{
						_CompScrapInfo = true;
						MainForm->MachineHistoryData("_CompScrapInfo -> " + IntToStr(_CompScrapInfo));
						MainForm->MachineHistoryData("[H->E],2115(SCRAP_INFO) --- bRet true ,"+m_Rcmd+","+m_RecipeId);
						for(int i=0; i<iScrapCnt; i++)
						{
							frmSeeLot->scrapCount->Text = IntToStr(iScrapCnt);
							frmSeeLot->sgScrap->Cells[0][i+1] = i+1;
							frmSeeLot->sgScrap->Cells[1][i+1] = scrapCode[i];
							frmSeeLot->sgScrap->Cells[2][i+1] = scrapArraySN[i];
						}
					}
				}
				else
				{
					MainForm->MachineHistoryData("[H->E],2115(SCRAP_INFO) ###FAIL### ,"+m_Rcmd+","+m_RecipeId);
					frmSeeLot->setMsg("Fail to Scrap Info (STOP_WORK_REQ)");
				}
				break;

			case 2116:	//DELETE SCRAP
				MainForm->MachineHistoryData("[H->E],2116(DELETE_SCRAP),"+m_Rcmd+","+m_RecipeId);
				if(nResult == STATE_ERR)
				{
					frmSeeLot->setMsg("Resp. Delete Scrap (NEXT_WORK_REQ)");
				}
				else
				{
					frmSeeLot->setMsg("Fail to Delete Scrap (STOP_WORK_REQ)");
				}
				//결과에 상관없이 호출
				frmSeeLot->tmSeeLot->Enabled = true;
				break;

			case 2021:	//Version Update
				nNdmNum = 0;
				break;


		}
		//장비 cmd
		if(nNdmNum != 0)
			nWriteCommunicationDM(nResult, nNdmNum);

		eXGem->GEMRspRemoteCommand(nMsgId, sRcmd, nHCAck, nCount, pnResult);

	}
	catch(Exception& e)
	{
		SECSHistoryData( e.Message);
	}
	delete [] pnResult; pnResult = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TFormSecsGemSet::eXGemeGEMRspPPLoadInquire(TObject *Sender, BSTR sPpid,
		  long nResult)
{
	// [H->E] S7F2 : recipe inquire rsp.
	char szMsg[256];

	String strPPID(sPpid);
	sprintf(szMsg, "Received %s, Ppid = %s, Result = %d", "GEMRspPPLoadInquire", strPPID, nResult );
	SECSHistoryData( szMsg );

	if(nResult == 0)	//Host ok
	{
		String StrRcpPath = ExtractFilePath(Application->ExeName)+ "Gem\\SSD\\XWork\\Recipe\\" + strPPID;
		if ( false == FileExists(StrRcpPath))
		{
			SECSHistoryData("recipe file not found : " + StrRcpPath);
			return;
		}

		INT nRecipeFileSize = FileSizeByName( StrRcpPath);
		if (true == PPSendS7F3Process(strPPID , nRecipeFileSize))
		{
			return;
		}
	}
	else
	{
		//report to seq.
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormSecsGemSet::eXGemeGEMTerminalMessage(TObject *Sender, long nMsgId,
		  BSTR sSystemTime)
{
	SECSHistoryData( "Received GEMTerminalMessage " +  String(sSystemTime));

	if(String(sSystemTime) == "Secs/Gem I/F Error")
		return;

	TerminalExclude = AnsiString(sSystemTime).c_str();

	if(!strstr(TerminalExclude, "TKOUT FAIL :: Invalid Lot Status!"))
	{
		FrmTerminalMsg->MemoFromHost->Lines->Add(sSystemTime);
		if(FrmTerminalMsg->Showing == false)
		{
			TerminalExclude = "";
			FrmTerminalMsg->BringToFront();

			// TerminalMessage 오른쪽 상단
			FrmTerminalMsg->Position = poDesigned; // 위치를 직접 설정할 수 있게 함
			FrmTerminalMsg->Left = Screen->Width - FrmTerminalMsg->Width; // 오른쪽 끝
			FrmTerminalMsg->Top = 0; // 상단
			FrmTerminalMsg->ShowModal();
			FrmTerminalMsg->Hide();
		}
	}

  /*	FrmTerminalMsg->MemoFromHost->Lines->Add(sSystemTime);
	if(FrmTerminalMsg->Showing == false)
	{
		FrmTerminalMsg->BringToFront();
		FrmTerminalMsg->ShowModal();
	}
	*/
}
//---------------------------------------------------------------------------

void __fastcall TFormSecsGemSet::eXGemeSECSMessageReceived(TObject *Sender, long nObjectID,
		  long nStream, long nFunction, long nSysbyte)
{
	long nReturn = 0;
	int  i;
	char szMsg[512];//, szTemp[32];
	ZeroMemory(szMsg, sizeof(szMsg));

	short   nI1, nI2, nU1, nBinary, nBool;
	long    nItems, lI4, lI8, lU2, lCnt;
	float   rF4;
	double  rU4, rU8, rF8;
	//WideString sAscii="";// ,sAscii1;
	wchar_t* wstr = NULL;
	long lSize;
	String strLotID, strType, strCmd, strBoatid , strBoatCell;

	// TODO: Add your control notification handler code here
	if( (nStream == 14) && (nFunction == 3) )
	{
		try
		{
			eXGem->GetList( nObjectID, &nItems );
			sprintf( szMsg, "L %d", nItems );	//4

			eXGem->GetAscii( nObjectID, &wstr, &lSize );
			strType = wstr;
			SECSHistoryData("TYPE : " + strType);
			wstr = NULL;

			eXGem->GetAscii( nObjectID, &wstr, &lSize );
			strCmd = wstr;
			SECSHistoryData("CMD : " + strCmd);
			wstr = NULL;

			eXGem->GetList( nObjectID, &nItems );
			//sprintf( szMsg, "L %d", nItems );	//1

			eXGem->GetAscii( nObjectID, &wstr, &lSize );
			strLotID = wstr;
			m_LotId = wstr;
			SECSHistoryData("LOTID : " + strLotID);
			wstr = NULL;

			eXGem->GetList( nObjectID, &nItems );
			int nListCnt = nItems;
			//sprintf( szMsg, "L %d", nItems ); 	//n

			String strObj[50], strVal[50];
			for(int nIndex=0; nIndex<nListCnt; nIndex++)
			{
				eXGem->GetList( nObjectID, &nItems );	//2

				eXGem->GetAscii( nObjectID, &wstr, &lSize );
				strObj[nIndex] = wstr;
				wstr = NULL;

				eXGem->GetAscii( nObjectID, &wstr, &lSize );
				strVal[nIndex] = wstr;
				wstr = NULL;
			}

			this->userMessageParsing(strCmd, strObj, strVal, nListCnt);
			// return user message
			this->S14F4Process(strLotID, nSysbyte, strObj, strVal, nListCnt);
			eXGem->CloseObject( nObjectID );

			if(MainForm->b_TpConnect)
			{
				g_pTpBase->logComm(L"SYSTEM",L"'TYPE'",L"'SEC/GEMS'",L"'RECV'",L"'SEC/GEMS'",L"'S14F3'",L"'DURATION'",L"'NO'");
			}
		}
		catch(Exception& e)
		{
			sprintf( szMsg, "Catch error message received (S%dF%d)", nStream, nFunction);
			SECSHistoryData(szMsg );
		}
	}
	else
	{
		sprintf( szMsg, "Undefined message received (S%dF%d)", nStream, nFunction);
		SECSHistoryData(szMsg );
		eXGem->CloseObject( nObjectID );
	}

	sprintf( szMsg, "message received (S%dF%d) & Object ID %d", nStream, nFunction, nObjectID);
	SECSHistoryData( szMsg );
}
//---------------------------------------------------------------------------
void  TFormSecsGemSet::userMessageParsing(String strCmd, String* strObj, String* strVal, int nListCnt)
{
	if(strCmd == "LOT_INFO" || strCmd == "LOT_DISPLAY" || strCmd == "LOT DISPLAY" || strCmd == "LOTINFO")
	{
		if(m_LotProcessStatus==0 || m_LotProcessStatus==1 || m_LotProcessStatus==2)
		{
			for(int nIndex=0; nIndex<nListCnt; nIndex++)
			{
				if(strObj[nIndex] == "LOTSTATUS" || strObj[nIndex] == "LOTSTATE")
					m_LotStatus = AnsiString(strVal[nIndex]);
				else if(strObj[nIndex] == "LOTTYPE")
					m_LotType = AnsiString(strVal[nIndex]);
				else if(strObj[nIndex] == "PART_ID" || strObj[nIndex] == "PARTID")
					m_PartId = AnsiString(strVal[nIndex]);
				else if(strObj[nIndex] == "QTY")
				{
					_nLotQty = _wtoi(strVal[nIndex].w_str());
				}
				else if(strObj[nIndex] == "STEPSEQ")
					m_StepSeq = AnsiString(strVal[nIndex]);
				else if(strObj[nIndex] == "NEXTSTEPSEQ")
					m_NextStepSeq = AnsiString(strVal[nIndex]);
				else if(strObj[nIndex] == "EQPTYPE")
					m_EqpType = AnsiString(strVal[nIndex]);
				else if(strObj[nIndex] == "BYPASS")
					m_Bypass = AnsiString(strVal[nIndex]);
				else if(strObj[nIndex] == "PCB_SIDE")
					m_PcbSide = AnsiString(strVal[nIndex]);	//SINGLE
				else if(strObj[nIndex] == "RECIPEID")
					m_RecipeId = AnsiString(strVal[nIndex]);
			}
		}
	}
	else if(strCmd == "SCRAP_INFO")
	{
		//<L[2]
		//	<A[10/1] "SCRAP_LIST">
		//	<A[200/1] "SCRAP_INFO001=(SCRAP_CODE=3305 ARRAYSN=1M393A4K40BB2CTD7YXXXA054FXXX001_1 SERIAL=  EQPMODEL=KSS700) SCRAP_INFO002=(SCRAP_CODE=3404 ARRAYSN=1M393A4K40BB2CTD7YXXXA054FXXX001_2 SERIAL=  EQPMODEL=KSS700) ">

		// All Attr List 2
		for(int nIndex=0; nIndex<nListCnt; nIndex++)
		{
			if(strObj[nIndex] == "SCRAP_INFO" || strObj[nIndex] == "SCRAP_LIST")
			{
				m_ScrapInfo = AnsiString(strVal[nIndex]);
			}
			else if(strObj[nIndex] == "SCRAP_CNT")
			{
				m_nScrapCnt = _wtoi(strVal[nIndex].w_str());
			}
		}
	}
	else if(strCmd == "SCRAP_REJECT_LOTID")
	{
		for(int nIndex=0; nIndex<nListCnt; nIndex++)
		{
			if(strObj[nIndex] == "LOT_ID")
			{
				m_LotEndLotId = AnsiString(strVal[nIndex]);
			}
			else if(strObj[nIndex] == "REJECT_LOT_ID")
			{
				m_LotEndRejectLotId = AnsiString(strVal[nIndex]);
			}
		}
	}
	else
	{
		return;
	}
}
//---------------------------------------------------------------------------
void TFormSecsGemSet::S14F4Process(WideString strOBJID, long nByte, String* strObj, String* strVal, int nListCnt)
{
	long nReturn = 0;
	char szMsg[256];
	AnsiString szTemp;
	short nIndex = 0;
	short   nI1, nI2, nU1, nBinary, nBool;
	long    lI4, lI8, lU2;
	float   rF4;
    double  rU4, rU8, rF8;
	WideString sAscii;

	long nObjId = 0;
	long nS = 0;
	long nF = 0;
	long nSysbyte = 0;
	long nLeng = 0;

	wchar_t* wstr = NULL;
	eXGem->MakeObject(&nObjId);
	// Setting values

	eXGem->SetList( nObjId, 2 );

	eXGem->SetList( nObjId, 1 );

	eXGem->SetList( nObjId, 2 );

	WideString  wStrP = strOBJID;
	wstr = wStrP.c_bstr();
	nLeng = strOBJID.Length();
	BSTR bstrStatus = SysAllocString(wstr);
	if(bstrStatus != NULL)
	{
		eXGem->SetAscii(nObjId, bstrStatus, nLeng);
		SysFreeString(bstrStatus);
	}
	wstr = NULL;
	wStrP = NULL;

	eXGem->SetList( nObjId, nListCnt );

	for(int nIndex=0; nIndex<nListCnt; nIndex++)
	{
		eXGem->SetList( nObjId, 2 );

		if(strObj[nIndex] == "" || strObj[nIndex].IsEmpty())
			strObj[nIndex] = " ";

		wStrP = strObj[nIndex];
		wstr = wStrP.c_bstr();
		nLeng = strObj[nIndex].Length();
		BSTR bstrStatus = SysAllocString(wstr);
		if(bstrStatus != NULL)
		{
			eXGem->SetAscii(nObjId, bstrStatus, nLeng);
			SysFreeString(bstrStatus);
		}
		wstr = NULL;
		wStrP = NULL;

		if(strVal[nIndex] == "" || strVal[nIndex].IsEmpty())
			strVal[nIndex] = " ";

		wStrP = strVal[nIndex];
		wstr = wStrP.c_bstr();
		nLeng = strVal[nIndex].Length();
		BSTR bstrStatus2 = SysAllocString(wstr);
		if(bstrStatus != NULL)
		{
			eXGem->SetAscii(nObjId, bstrStatus2, nLeng);
			SysFreeString(bstrStatus2);
		}
		wstr = NULL;
		wStrP = NULL;
	}

	eXGem->SetList( nObjId, 2 );

	nU1 = 0;
	eXGem->SetU1( nObjId, &nU1, 1 );

	eXGem->SetList( nObjId, 0 );

	nS = 14; nF = 4; nSysbyte = nByte;
	nReturn = eXGem->SendSECSMessage(nObjId, nS, nF, nSysbyte);
	if( nReturn == 0 )
	{
		SECSHistoryData( "MESSAGE SEND S14 F4" );
	}
	else
	{
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormSecsGemSet::eXGemeXGEMStateEvent(TObject *Sender, long nState)

{
	if (nState == XGemState_Execute)
	{
		//bEnable : 0(Disabled), 1(Enabled)
		eXGem->GEMSetEstablish(1);
		eXGem->GEMEQInitialized(1);
	}
	else
	{
		//SECSHistoryData(IntToStr(nState));
	}
}
//---------------------------------------------------------------------------

//CEID Event
void TFormSecsGemSet::GemProcessStateChange()
{

}
//---------------------------------------------------------------------------
void TFormSecsGemSet::GemOperatorECChange()
{
	if(m_fStart != true)
		return;
/*
2005  Current Recipe Name
2010  Operator ID
2011  EQUIPMENT ID
*/
//	long nCount = 3;
//	long naVid[3];
//
//	WideString* pwsValue = new WideString[3];
//
//	naVid[0] = 2005; pwsValue[0] = Get_RecipeName();
//	naVid[1] = 2010; pwsValue[1] = _StrOpid;
//	naVid[2] = 2011; pwsValue[2] = MainForm->_eqpID;
//
//	// 1. Update variable
//	eXGem->GEMSetVariable(nCount, naVid, &pwsValue[0]);
//
//	// 2. Event notification.
//	eXGem->GEMSetEvent(1055);
//
//	SECSHistoryData( "Send Event  1055");
//	delete [] pwsValue; pwsValue = NULL;
}
//---------------------------------------------------------------------------
void TFormSecsGemSet::GemAlarmSet(int nAlarmNum)
{
	if(m_fStart != true)
		return;
/*
1006  CurrentPPID
1007  LatestAlarmSet
2011  EQUIPMENT ID
*/
//	long nCount = 3;
//	long naVid[3];
//
//	WideString* pwsValue = new WideString[3];
//
//	naVid[0] = 1006; pwsValue[0] = Get_RecipeName();
//	naVid[1] = 1007; pwsValue[1] = _AlarmNameReturn(1 ,nAlarmNum);
//	naVid[2] = 2011; pwsValue[2] = MainForm->_eqpID;
//
//	// 1. Update variable
//	eXGem->GEMSetVariable(nCount, naVid, &pwsValue[0]);
//
//	// 2. Event notification.
//	eXGem->GEMSetEvent(1070);
//
//	SECSHistoryData( "Send Event  1070");
//	delete [] pwsValue; pwsValue = NULL;
}
//---------------------------------------------------------------------------
void TFormSecsGemSet::GemAlarmClear(int nAlarmNum)
{
	if(m_fStart != true)
		return;
/*
1006  CurrentPPID
1008  LatestAlarmClear
2011  EQUIPMENT ID
*/
//	long nCount = 3;
//	long naVid[3];
//
//	WideString* pwsValue = new WideString[3];
//
//	naVid[0] = 1006; pwsValue[0] = Get_RecipeName();
//	naVid[1] = 1008; pwsValue[1] = _AlarmNameReturn(1 ,nAlarmNum);
//	naVid[2] = 2011; pwsValue[2] = MainForm->_eqpID;
//
//	// 1. Update variable
//	eXGem->GEMSetVariable(nCount, naVid, &pwsValue[0]);
//
//	// 2. Event notification.
//	eXGem->GEMSetEvent(1071);
//
//	SECSHistoryData( "Send Event  1071");
//	delete [] pwsValue; pwsValue = NULL;
}
//---------------------------------------------------------------------------
void TFormSecsGemSet::GemRecipeChange()
{
	if(m_fStart != true)
		return;

	if(true == g_MMIComm->Send() && true == g_MMIComm->Recv())
	{
		if(!bReadUseSkip(31))
		{
			SECSHistoryData("Recipe Not Upload");
			return;
		}
	}

	// Recipe Upload
	this->eventRecipeUpload(CMD_RD_LOTINFO_CUR);	//CMD_RD_LOTINFO_CUR		= 39 Current Lot 필요.

//	long nCount = 3;
//	long naVid[3];
//
//	WideString* pwsValue = new WideString[3];
//
//	naVid[0] = 2005; pwsValue[0] = Get_RecipeName();
//	naVid[1] = 2010; pwsValue[1] = _StrOpid;
//	naVid[2] = 2011; pwsValue[2] = MainForm->_eqpID;
//
//	// 1. Update variable
//	eXGem->GEMSetVariable(nCount, naVid, &pwsValue[0]);
//
//	// 2. Event notification.
//	eXGem->GEMSetEvent(1080);
//
//	SECSHistoryData( "Send Event  1080");
//	delete [] pwsValue; pwsValue = NULL;
}
//---------------------------------------------------------------------------
void TFormSecsGemSet::GemStopDescription()
{
	if(m_fStart != true)
		return;
/*
2011  EQUIPMENT ID
2001  STOP DESCRIPTION ID
2002  STOP DESCRIPTION INFO
*/
//	long nCount = 3;
//	long naVid[3];
//
//	WideString* pwsValue = new WideString[3];
//
//	naVid[0] = 2011; pwsValue[0] = MainForm->_eqpID;
//	//naVid[1] = 2001; pwsValue[1] = ;
//	//naVid[2] = 2002; pwsValue[2] = ;
//
//	// 1. Update variable
//	eXGem->GEMSetVariable(nCount, naVid, &pwsValue[0]);
//
//	// 2. Event notification.
//	eXGem->GEMSetEvent(1100);
//
//	SECSHistoryData( "Send Event  1100");
//	delete [] pwsValue; pwsValue = NULL;
}
//---------------------------------------------------------------------------
void TFormSecsGemSet::GemOhtStateChange(int OhtIndex)
{
	if(m_fStart != true)
		return;
/*
2011  EQUIPMENT ID
2012  PORT ID
*/
//	long nCount = 2;
//	long naVid[2];
//
//	WideString* pwsValue = new WideString[2];
//
//	naVid[0] = 2011; pwsValue[0] = MainForm->_eqpID;
//	if(OhtIndex == 0)
//	{
//		naVid[1] = 2012; pwsValue[1] = MainForm->_ohtInPortID_Empty;
//	}
//	else if(OhtIndex == 1)
//	{
//		naVid[1] = 2012; pwsValue[1] = MainForm->_ohtInPortID_Cover;
//	}
//	else if(OhtIndex == 2)
//	{
//		naVid[1] = 2012; pwsValue[1] = MainForm->_ohtOutPortID_Good;
//	}
//	else if(OhtIndex == 3)
//	{
//		naVid[1] = 2012; pwsValue[1] = MainForm->_ohtOutPortID_Reject;
//	}
//
//
//	// 1. Update variable
//	eXGem->GEMSetVariable(nCount, naVid, &pwsValue[0]);
//
//	// 2. Event notification.
//	eXGem->GEMSetEvent(1110);
//
//	SECSHistoryData( "Send Event  1110");
//	delete [] pwsValue; pwsValue = NULL;
}
//---------------------------------------------------------------------------
void TFormSecsGemSet::GemPortStateChangeLoad(int nGemState)
{
	if(m_fStart != true)
		return;
/*
2011  EQUIPMENT ID
2012  PORT ID
1002  Control State
1003  Prev Control State
*/
//	if(_nPrevGemState != nGemState)
//	{
//		long nCount = 4;
//		long naVid[4];
//
//		WideString* pwsValue = new WideString[4];
//
//		naVid[0] = 2011; pwsValue[0] = MainForm->_eqpID;
//		naVid[1] = 2012; pwsValue[1] = _StrPortID;
//		naVid[2] = 1002; pwsValue[1] = IntToStr(nGemState);
//		naVid[3] = 1003; pwsValue[1] = IntToStr(_nPrevGemState);
//
//		// 1. Update variable
//		eXGem->GEMSetVariable(nCount, naVid, &pwsValue[0]);
//
//		// 2. Event notification.
//		eXGem->GEMSetEvent(1200);
//
//		_nPrevGemState = nGemState;
//
//		SECSHistoryData( "Send Event  1200");
//		delete [] pwsValue; pwsValue = NULL;
//	}
}
//---------------------------------------------------------------------------
bool TFormSecsGemSet::GemVersionUpdate()
{
	if(m_fStart != true)
		return false;

	{
		long nCount = 3;
		long naVid[3];

		WideString* pwsValue = new WideString[3];

		naVid[0] = 2001; pwsValue[0] = MainForm->_eqpID;
		naVid[1] = 2034; pwsValue[1] = MainForm->_eqpModel;
		naVid[2] = 2035; pwsValue[2] = MainForm->_eqpVersion;

		// 1. Update variable
		eXGem->GEMSetVariable(nCount, naVid, &pwsValue[0]);

		// 2. Event notification.
		long nReturn = eXGem->GEMSetEvent(2021);

		if(nReturn != 0)
		{
			char    szMsg[256];
			sprintf( szMsg, "[EQ ==> XGEM] GEMSetEvent (2021) Error Code => %d", nReturn);
			SECSHistoryData( szMsg );
		}
		else
		{
			SECSHistoryData( "Send Event  2021 (VersionUpdate)");

			if(MainForm->b_TpConnect)
			{
				String sLog = "'"+MainForm->_eqpVersion+"'";
				g_pTpBase->logComm(L"SYSTEM",L"SEND", L"'TYPE'",L"'SECS/GEM'", L"'SECS/GEM'",L"'S6F11'", L"'CEID'",L"2021",/*L"'SW_VERSION'",sLog.c_str(),*/ L"'DURATION'",L"'NO'");
			}
		}
		delete [] pwsValue; pwsValue = NULL;
	}

	return true;
}
//---------------------------------------------------------------------------
void TFormSecsGemSet::GemRFIDRead()
{
	if(m_fStart != true)
		return;
/*
2011  EQUIPMENT ID
2100  CARRIER ID
*/
	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_LOT_END_INFO;
	BOOL bRet = g_MMIComm->Send() &&  g_MMIComm->Recv();
	if(bRet)
	{
		long nCount = 2;
		long naVid[2];

		WideString* pwsValue = new WideString[2];

		naVid[0] = 2011; pwsValue[0] = MainForm->_eqpID;
		naVid[1] = 2100; pwsValue[1] = String(g_MMIComm->m_mmiToSeq.buffer.lotInfoCopy.carrierID);
		// naVid[1] = 2100; pwsValue[1] = String(g_MMIComm->m_mmiToSeq.buffer.lotInfo.carrierID);

		// 1. Update variable
		eXGem->GEMSetVariable(nCount, naVid, &pwsValue[0]);

		// 2. Event notification.
		eXGem->GEMSetEvent(1201);

		SECSHistoryData( "Send Event  1201");
		delete [] pwsValue; pwsValue = NULL;
	}
}
//---------------------------------------------------------------------------
bool __fastcall TFormSecsGemSet::ChangeMgzID(bool bEmptyMgz, int iPart, int iGdorRj)
{
	if(m_fStart != true)
		return false;

	if(bReadUseSkip(usRfid) == false)
		return false;
	else if(bReadUseSkip(usRfid) == true)
	{
		g_MMIComm->m_mmiToSeq.nCmd = iPart;
		BOOL bRet = g_MMIComm->Send() &&  g_MMIComm->Recv();
		if(bRet)
		{
			LOT_INFO info = g_MMIComm->m_mmiToSeq.buffer.lotInfo;

			bool bRtn = false;
			long nCount = 4;
			long naVid[4];

			WideString* pwsValue = new WideString[4];

			naVid[0] = 2001; pwsValue[0] = MainForm->_eqpID;

			if(bEmptyMgz == true)
			{
				naVid[1] = 2006; pwsValue[1] = "MDRDIETRAY";
			}
			else
			{
				if (iGdorRj == LOT_END_STEP_GD_COVER_COMP)
				{
					naVid[1] = 2006; pwsValue[1] = String(info.mergeLotID);
				}
				else if (iGdorRj == LOT_END_STEP_RJ_COVER_COMP)
				{
					naVid[1] = 2006; pwsValue[1] = String(info.rejectLotID);
				}
			}

			String sCarrierID = String(info.carrierID);
			if(sCarrierID == "")
			{
				naVid[2] = 2012; pwsValue[2] = "SE";
			}
			else
			{
				if (iGdorRj == LOT_END_STEP_GD_COVER_COMP)
				{
					naVid[2] = 2012; pwsValue[2] = String(info.carrierID);
				}
				else if (iGdorRj == LOT_END_STEP_RJ_COVER_COMP)
				{
					naVid[2] = 2012; pwsValue[2] = String(info.rejectCarrierID);
				}
			}

			naVid[3] = 2004; pwsValue[3] = _StrOpid;

			// 1. Update variable
			eXGem->GEMSetVariable(nCount, naVid, &pwsValue[0]);

			// 2. Event notification.
			long nReturn = eXGem->GEMSetEvent(2005);

			if(nReturn != 0)
			{
				char    szMsg[256];
				sprintf( szMsg, "[EQ ==> XGEM] GEMSetEvent (2005) Error Code => %d", nReturn);
				SECSHistoryData( szMsg );
			}
			else
			{
				bRtn = true;
				SECSHistoryData( "Send Event  2005 (CHANGE MAZID)");

				if(MainForm->b_TpConnect)
				{
					g_pTpBase->logComm(L"SYSTEM",L"SEND", L"'TYPE'",L"'SECS/GEM'", L"'SECS/GEM'",L"'S6F11'", L"'CEID'",L"2005",L"'DURATION'",L"'NO'");
				}
			}
			delete [] pwsValue; pwsValue = NULL;

			return bRtn;
		}
	}
	else
		return false;
}

//---------------------------------------------------------------------------
bool __fastcall TFormSecsGemSet::EmptyCarrierMoveReq(bool bEmptyMgz,int iPart)
{
	if(m_fStart != true)
		return false;

	if(bReadUseSkip(usRfid) == false)
		return false;

	g_MMIComm->m_mmiToSeq.nCmd = iPart;
	BOOL bRet = g_MMIComm->Send() &&  g_MMIComm->Recv();
	if(bRet)
	{
		LOT_INFO info = g_MMIComm->m_mmiToSeq.buffer.lotInfo;

		bool bRtn = false;
		long nCount = 9;
		long naVid[9];

		WideString* pwsValue = new WideString[9];

		naVid[0] = 2001; pwsValue[0] = MainForm->_eqpID;
		//naVid[1] = 2006; pwsValue[1] = String(info.lotID);

		if(nReadCommunicationDM(reqTrayEcmr) == STATE_BUSY)
		{
			naVid[1] = 2006; pwsValue[1] = "SSD_ETRAY";
			naVid[2] = 2013; pwsValue[2] = MainForm->_eqpID + "_I2";  // EMPTY TRAY
		}
		if(nReadCommunicationDM(reqCoverEcmr) == STATE_BUSY)
		{
			naVid[1] = 2006; pwsValue[1] = "SSD_CTRAY";
			naVid[2] = 2013; pwsValue[2] = MainForm->_eqpID + "_I3";  // COVER TRAY
		}
		naVid[3] = 2016; pwsValue[3] = "";
		naVid[4] = 2017; pwsValue[4] = "";
		naVid[5] = 2018; pwsValue[5] = "";
		naVid[6] = 2019; pwsValue[6] = String(info.rproperty);
		naVid[7] = 2014; pwsValue[7] = "";
		naVid[8] = 2015; pwsValue[8] = "MOBILE";

		eXGem->GEMSetVariable(nCount, naVid, &pwsValue[0]);

		long nReturn = eXGem->GEMSetEvent(2007);

		if(nReturn != 0)
		{
			char szMsg[256];
			sprintf(szMsg, "[EQ ==> XGEM] GEMSetEvent (2007) Error Code => %d",nReturn);
			SECSHistoryData( szMsg );
		}
		else
		{
         	bRtn = true;
			SECSHistoryData( "Send Event  2007 (EMPTY CARRIER MOVE REQ)");

			if(MainForm->b_TpConnect)
			{
				g_pTpBase->logComm(L"SYSTEM",L"SEND", L"'TYPE'",L"'SECS/GEM'", L"'SECS/GEM'",L"'S6F11'", L"'CEID'",L"2007",L"'DURATION'",L"'NO'");
			}
		}

		delete [] pwsValue;  pwsValue = NULL;

		return bRet;

	}
	else
		return false;
}
//---------------------------------------------------------------------------
bool __fastcall TFormSecsGemSet::FullCarrierMoveReq(bool bEmptyMgz, int iPart, int iGdorRj) //RSM SOR SEND S6F11 CEID 2008
{

	if(m_fStart != true)
		return false;

	if(bReadUseSkip(usRfid) == false)
		return false;
	/*if(bReadUseSkip(usOhtMode) == false) //RSM SOR SEND OHT, AGV 중 사용 하게 될 것으로 수정
		return false;*/

	g_MMIComm->m_mmiToSeq.nCmd = iPart;
	BOOL bRet = g_MMIComm->Send() &&  g_MMIComm->Recv();
	if(bRet)
	{
		LOT_INFO info = g_MMIComm->m_mmiToSeq.buffer.lotInfo;

		bool bRtn = false;
		long nCount = 5;
		long naVid[5];

		WideString* pwsValue = new WideString[5];

		naVid[0] = 2001; pwsValue[0] = MainForm->_eqpID;

		if(bEmptyMgz == true)
		{
			naVid[1] = 2006; pwsValue[1] = "MDRDIETRAY";
		}
		else
		{
			// naVid[1] = 2006; pwsValue[1] = String(info.mergeLotID);
			if (iGdorRj == FCMR_STEP_GD_COMP)
			{
				naVid[1] = 2006; pwsValue[1] = String(info.mergeLotID);
			}
			else if (iGdorRj == FCMR_STEP_RJ_COMP)
			{
				naVid[1] = 2006; pwsValue[1] = String(info.rejectLotID);
			}
		}

		if (iGdorRj == FCMR_STEP_GD_COMP)
		{
			naVid[2] = 2013; pwsValue[2] = MainForm->_eqpID + "_O2";
		}
		else if (iGdorRj == FCMR_STEP_RJ_COMP)
		{
			naVid[2] = 2013; pwsValue[2] = MainForm->_eqpID + "_O3";
		}

		// naVid[2] = 2013; pwsValue[2] = MainForm->_eqpID + "_O2";

		String sCarrierID = String(info.carrierID);
		if(sCarrierID == "")
		{
			naVid[3] = 2014; pwsValue[3] = "SE";
		}
		else
		{
			// naVid[3] = 2014; pwsValue[3] = String(info.carrierID);
			if (iGdorRj == FCMR_STEP_GD_COMP)
			{
				naVid[3] = 2014; pwsValue[3] = String(info.carrierID);
			}
			else if (iGdorRj == FCMR_STEP_RJ_COMP)
			{
				naVid[3] = 2014; pwsValue[3] = String(info.rejectCarrierID);
			}
		}

		naVid[4] = 2015; pwsValue[4] = "MOBILE";


		eXGem->GEMSetVariable(nCount, naVid, &pwsValue[0]);

		long nReturn = eXGem->GEMSetEvent(2008);

		if(nReturn != 0)
		{
			char    szMsg[256];
			sprintf( szMsg, "[EQ ==> XGEM] GEMSetEvent (2008) Error Code => %d", nReturn);
			SECSHistoryData( szMsg );
		}
		else
		{
			bRtn = true;
			SECSHistoryData( "Send Event  2008 (FULL CARRIER MOVE REQUEST)");

			if(MainForm->b_TpConnect)
			{
				g_pTpBase->logComm(L"SYSTEM",L"SEND", L"'TYPE'",L"'SECS/GEM'", L"'SECS/GEM'",L"'S6F11'", L"'CEID'",L"2008",L"'DURATION'",L"'NO'");
			}
		}
		delete [] pwsValue; pwsValue = NULL;

		return bRtn;
	}
	else
		return false;
}
//---------------------------------------------------------------------------
bool __fastcall TFormSecsGemSet::ScrapInfo(int iPart)
{
	if(m_fStart != true)
		return false;

	g_MMIComm->m_mmiToSeq.nCmd = iPart;
	BOOL bRet = g_MMIComm->Send() &&  g_MMIComm->Recv();
	if(bRet)
	{
		SCRAP_INFO info = g_MMIComm->m_mmiToSeq.buffer.onlineEndHistory;

		bool bRtn = false;
		long nCount = 4;
		long naVid[4];

		WideString* pwsValue = new WideString[4];

		naVid[0] = 2001; pwsValue[0] = MainForm->_eqpID;
		naVid[1] = 2006; pwsValue[1] = String(info.mergeLotID);
		naVid[2] = 2004; pwsValue[2] = _StrOpid;
		naVid[3] = 2038; pwsValue[3] = "NO";	//AUTOLINE

		// 1. Update variable
		eXGem->GEMSetVariable(nCount, naVid, &pwsValue[0]);

		// 2. Event notification.
		long nReturn = eXGem->GEMSetEvent(2115);

		if(nReturn != 0)
		{
			char    szMsg[256];
			sprintf( szMsg, "[EQ ==> XGEM] GEMSetEvent (2115) Error Code => %d", nReturn);
			SECSHistoryData( szMsg );

			MainForm->MachineHistoryData("[E->H] Send Fail: Event 2115 (SCRAP INFO)");
		}
		else
		{
			bRtn = true;
			SECSHistoryData( "Send Event  2115 (SCRAP INFO)");
			MainForm->MachineHistoryData("[E->H] Event 2115 (SCRAP INFO)");

			if(MainForm->b_TpConnect)
			{
				g_pTpBase->logComm(L"SYSTEM",L"SEND", L"'TYPE'",L"'SECS/GEM'", L"'SECS/GEM'",L"'S6F11'", L"'CEID'",L"2115",L"'DURATION'",L"'NO'");
			}
		}
		delete [] pwsValue; pwsValue = NULL;

		return bRtn;
	}
	else
		return false;
}
//---------------------------------------------------------------------------
bool __fastcall TFormSecsGemSet::AddScrap(int iPart, int iCnt, String sScrapId)
{
	if(m_fStart != true)
		return false;

	g_MMIComm->m_mmiToSeq.nCmd = iPart;
	BOOL bRet = g_MMIComm->Send() &&  g_MMIComm->Recv();
	if(bRet)
	{
		LOT_INFO info = g_MMIComm->m_mmiToSeq.buffer.lotInfo;

		bool bRtn = false;
		long nCount = 7;
		long naVid[7];

		WideString* pwsValue = new WideString[7];

		naVid[0] = 2001; pwsValue[0] = MainForm->_eqpID;
		naVid[1] = 2006; pwsValue[1] = String(info.mergeLotID);
		naVid[2] = 2004; pwsValue[2] = _StrOpid;
		naVid[3] = 2038; pwsValue[3] = "NO";	//AUTOLINE
		naVid[4] = 2046; pwsValue[4] = IntToStr(iCnt);	//Scrap Count (2)
		naVid[5] = 2047; pwsValue[5] = sScrapId;	//Scrap Info (3305:1M393A4K40BB2CTD7YXXXA054FXXX001_1,3404:1M393A4K40BB2CTD7YXXXA054FXXX001_2)
		naVid[6] = 2024; pwsValue[6] = "M033"; //String(info.step);	//Step

		// 1. Update variable
		eXGem->GEMSetVariable(nCount, naVid, &pwsValue[0]);

		// 2. Event notification.
		long nReturn = eXGem->GEMSetEvent(2114);

		if(nReturn != 0)
		{
			char    szMsg[256];
			sprintf( szMsg, "[EQ ==> XGEM] GEMSetEvent (2114) Error Code => %d", nReturn);
			SECSHistoryData( szMsg );

			MainForm->MachineHistoryData("[E->H] Send Fail: Event 2114 (ADD SCRAP)");
		}
		else
		{
			bRtn = true;
			SECSHistoryData( "Send Event  2114 (ADD SCRAP)");
			MainForm->MachineHistoryData("[E->H] Event 2114 (ADD SCRAP)");

			if(MainForm->b_TpConnect)
			{
				g_pTpBase->logComm(L"SYSTEM",L"SEND", L"'TYPE'",L"'SECS/GEM'", L"'SECS/GEM'",L"'S6F11'", L"'CEID'",L"2114",L"'DURATION'",L"'NO'");
			}
		}
		delete [] pwsValue; pwsValue = NULL;

		return bRtn;
	}
	else
		return false;

}
//---------------------------------------------------------------------------
bool __fastcall TFormSecsGemSet::DeleteScrap(int iPart, String sScrapId)
{
	if(m_fStart != true)
		return false;

	g_MMIComm->m_mmiToSeq.nCmd = iPart;
	BOOL bRet = g_MMIComm->Send() &&  g_MMIComm->Recv();
	if(bRet)
	{
		SCRAP_INFO info = g_MMIComm->m_mmiToSeq.buffer.onlineEndHistory;

        bool bRtn = false;
		long nCount = 4;
		long naVid[4];

		WideString* pwsValue = new WideString[4];

		naVid[0] = 2001; pwsValue[0] = MainForm->_eqpID;
		naVid[1] = 2006; pwsValue[1] = String(info.mergeLotID);
		naVid[2] = 2067; pwsValue[2] = sScrapId;	//Delete Serial
		naVid[3] = 2038; pwsValue[3] = "NO";	//AUTOLINE

		// 1. Update variable
		eXGem->GEMSetVariable(nCount, naVid, &pwsValue[0]);

		// 2. Event notification.
		long nReturn = eXGem->GEMSetEvent(2116);

		if(nReturn != 0)
		{
			char    szMsg[256];
			sprintf( szMsg, "[EQ ==> XGEM] GEMSetEvent (2116) Error Code => %d", nReturn);
			SECSHistoryData( szMsg );

			MainForm->MachineHistoryData("[E->H] Send Fail: Event 2116 (DELETE SCRAP)");
		}
		else
		{
			bRtn = true;
			SECSHistoryData( "Send Event  2116 (DELETE SCRAP)");
			MainForm->MachineHistoryData("[E->H] Event 2116 (DELETE SCRAP)");

			if(MainForm->b_TpConnect)
			{
				g_pTpBase->logComm(L"SYSTEM",L"SEND", L"'TYPE'",L"'SECS/GEM'", L"'SECS/GEM'",L"'S6F11'", L"'CEID'",L"2116",L"'DURATION'",L"'NO'");
			}
		}
		delete [] pwsValue; pwsValue = NULL;

		return bRtn;
	}
	else
		return false;
}
//---------------------------------------------------------------------------
bool TFormSecsGemSet::TrackIn()
{
//	if(m_fStart != true)
//		return false;
///*
//2011  EQUIPMENT ID
//2102  LOT ID
//*/
//
//	int nStageNumber = nReadCommunicationDM(581);//need to check ndm for stage number
//
//	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_STG1_LOT_INFO + nStageNumber;
//	BOOL bRet = g_MMIComm->Send() &&  g_MMIComm->Recv();
//	if(bRet)
//	{
//		long nCount = 2;
//		long naVid[2];
//
//		WideString* pwsValue = new WideString[2];
//
//		naVid[0] = 2011; pwsValue[0] = MainForm->_eqpID;
//		naVid[1] = 2102; pwsValue[1] = String(g_MMIComm->m_mmiToSeq.buffer.lotInfo.lotID);
//
//		// 1. Update variable
//		eXGem->GEMSetVariable(nCount, naVid, &pwsValue[0]);
//
//		// 2. Event notification.
//		eXGem->GEMSetEvent(1300);
//
//		SECSHistoryData( "Send Event  1300");
//		delete [] pwsValue; pwsValue = NULL;
//	}
//	else
//		return false;
//
//	return true;
}
//---------------------------------------------------------------------------
bool TFormSecsGemSet::TrackOut()
{
	if(m_fStart != true)
		return false;
/*
2011  EQUIPMENT ID
2102  LOT ID
*/
	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_LOT_END_INFO;
	BOOL bRet = g_MMIComm->Send() &&  g_MMIComm->Recv();
	if(bRet)
	{
		LOT_INFO info = g_MMIComm->m_mmiToSeq.buffer.lotInfo;

		bool bRtn = false;
		long nCount = 7;
		long naVid[7];

		WideString* pwsValue = new WideString[7];

		naVid[0] = 2001; pwsValue[0] = MainForm->_eqpID;
		naVid[1] = 2006; pwsValue[1] = String(info.mergeLotID);
		naVid[2] = 2004; pwsValue[2] = _StrOpid;
		naVid[3] = 2039; pwsValue[3] = "";	//EWS LOT
		naVid[4] = 2066; pwsValue[4] = "";	//SBL CHECK RESULT
		naVid[5] = 2038; pwsValue[5] = "NO";	//AUTOLINE
		naVid[6] = 2013; pwsValue[6] = MainForm->_ohtOutPortID_Good;	//PORT_ID "_O2"

		// 1. Update variable
		eXGem->GEMSetVariable(nCount, naVid, &pwsValue[0]);

		// 2. Event notification.
		long nReturn = eXGem->GEMSetEvent(2101);

		if(nReturn != 0)
		{
			char    szMsg[256];
			sprintf( szMsg, "[EQ ==> XGEM] GEMSetEvent (2101) Error Code => %d", nReturn);
			SECSHistoryData( szMsg );

			MainForm->MachineHistoryData("[E->H] Send Fail: Event 2101 (LOT END OTHER)");
		}
		else
		{
			bRtn = true;
			SECSHistoryData( "Send Event 2101 (LOT END OTHER)");
			MainForm->MachineHistoryData("[E->H] Event 2101 (LOT END OTHER)");

			if(MainForm->b_TpConnect)
			{
				g_pTpBase->logComm(L"SYSTEM",L"SEND", L"'TYPE'",L"'SECS/GEM'", L"'SECS/GEM'",L"'S6F11'", L"'CEID'",L"2101",L"'DURATION'",L"'NO'");
			}
		}
		delete [] pwsValue; pwsValue = NULL;

		return bRtn;
	}
	else
		return false;
}
//------------------------    For RMS    -----------------------------------
bool __fastcall TFormSecsGemSet::GemPcbInfo()
{
//	if(m_fStart != true)
//		return false;
//
//	LOT_INFO	info;
//	if(ReadLotInfoData(CMD_RD_STG1_LOT_INFO,info))
//	{
//		bool bRtn = false;
//		long nCount = 3;
//		long naVid[3];
//
//		WideString* pwsValue = new WideString[3];
//
//		naVid[0] = 2001; pwsValue[0] = MainForm->_eqpID;
//		naVid[1] = 2002; pwsValue[1] = String(info.pcbBarcode);
//		naVid[2] = 2004; pwsValue[2] = _StrOpid;
//
//		// 1. Update variable
//		eXGem->GEMSetVariable(nCount, naVid, &pwsValue[0]);
//
//		// 2. Event notification.
//		long nReturn = eXGem->GEMSetEvent(2122);
//
//		if(nReturn != 0)
//		{
//			char    szMsg[256];
//			sprintf( szMsg, "[EQ ==> XGEM] GEMSetEvent (2122) Error Code => %d", nReturn);
//			SECSHistoryData( szMsg );
//
//			MainForm->MachineHistoryData("[E->H] Send Fail: Event 2122 (PCB INFO OTHER)");
//		}
//		else
//		{
//			bRtn = true;
//			SECSHistoryData( "Send Event  2122 (PCB INFO OTHER)");
//			MainForm->MachineHistoryData("[E->H] Event 2122 (PCB INFO OTHER)");
//
//			if(MainForm->b_TpConnect)
//			{
//				g_pTpBase->logComm(L"SYSTEM",L"SEND", L"'TYPE'",L"'SECS/GEM'", L"'SECS/GEM'",L"'S6F11'", L"'CEID'",L"2122", L"'DURATION'",L"'NO'");
//			}
//		}
//		delete [] pwsValue; pwsValue = NULL;
//
//		return bRtn;
//	}
//	else
//	{
//		MainForm->MachineHistoryData("[E->H] Read SEQ Fail: Event 2122 (PCB INFO OTHER)");
//		return false;
//	}
}
//---------------------------------------------------------------------------
bool __fastcall TFormSecsGemSet::GemLotInfo(int iStage, String sLotId)	//0,1
{
	if(m_fStart != true)
		return false;

	String sReqLotId = "";
	BOOL bRet = false;
	if(iStage==0)	//AUTO
	{
		g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_BUFFER_LOTINFO;
		bRet = g_MMIComm->Send() &&  g_MMIComm->Recv();
		sReqLotId = String(g_MMIComm->m_mmiToSeq.buffer.lotInfo.lotID);
	}
	else
	{
		bRet = true;
		sReqLotId = sLotId;
	}

	if(bRet)
	{
		bool bRtn = false;
		long nCount = 2;
		long naVid[2];

		WideString* pwsValue = new WideString[2];

		naVid[0] = 2001; pwsValue[0] = MainForm->_eqpID;
		naVid[1] = 2006; pwsValue[1] = sReqLotId;

		// 결과 처리 구분용
		m_LotProcessStatus = iStage;

		// 1. Update variable
		eXGem->GEMSetVariable(nCount, naVid, &pwsValue[0]);

		// 2. Event notification.
		long nReturn = eXGem->GEMSetEvent(2004);

		if(nReturn != 0)
		{
			char    szMsg[256];
			sprintf( szMsg, "[EQ ==> XGEM] GEMSetEvent (2004) Error Code => %d", nReturn);
			SECSHistoryData( szMsg );

			MainForm->MachineHistoryData("[E->H] Send Fail: Event 2004 (LOT DISPLAY)");
		}
		else
		{
			bRtn = true;
			SECSHistoryData( "Send Event 2004 (LOT DISPLAY)");
			MainForm->MachineHistoryData("[E->H] Event 2004 (LOT DISPLAY)");

			if(MainForm->b_TpConnect)
			{
				g_pTpBase->logComm(L"SYSTEM",L"SEND", L"'TYPE'",L"'SECS/GEM'", L"'SECS/GEM'",L"'S6F11'", L"'CEID'",L"2004", L"'DURATION'",L"'NO'");
			}
		}
		delete [] pwsValue; pwsValue = NULL;

		return bRtn;
	}
	else
	{
		MainForm->MachineHistoryData("[E->H] Read SEQ Fail: Event 2004 (LOT DISPLAY)");
		return false;
	}
}
//---------------------------------------------------------------------------
bool __fastcall TFormSecsGemSet::eventRecipeUpload(int iPart)
{
	if(m_fStart != true)
		return false;

	g_MMIComm->m_mmiToSeq.nCmd = iPart;
	BOOL bRet = g_MMIComm->Send() &&  g_MMIComm->Recv();
	if(bRet)
	{
		LOT_INFO info = g_MMIComm->m_mmiToSeq.buffer.lotInfo;

		long nCount = 6;
		long naVid[6];

		WideString* pwsValue = new WideString[6];

		String strRecipeId = Get_RecipeName()+".ZIP";

		naVid[0] = 2001; pwsValue[0] = MainForm->_eqpID;
		naVid[1] = 2006; pwsValue[1] = String(info.lotID);
		naVid[2] = 2025; pwsValue[2] = String(info.partID);
		naVid[3] = 2092; pwsValue[3] = strRecipeId;		//GEM DB 생성 필요
		naVid[4] = 2024; pwsValue[4] = String(info.step);//MainForm->_eqpStepSeq;
		naVid[5] = 2093; pwsValue[5] = String(info.lotType);//MainForm->_eqpLotType;

//		if(MainForm->IsDebugging())
//		{
//			pwsValue[1] = m_DebugData[4];
//			pwsValue[2] = m_DebugData[33];
//			pwsValue[3] = m_DebugData[36];
//			pwsValue[4] = m_DebugData[9];
//		}

		// 1. Update variable
		eXGem->GEMSetVariable(nCount, naVid, &pwsValue[0]);

		// 2. Event notification.
		long nReturn = eXGem->GEMSetEvent(1201);

		if(nReturn != 0)
		{
			char    szMsg[256];
			sprintf( szMsg, "[EQ ==> XGEM] GEMSetEvent (1201) Error Code => %d", nReturn);
			SECSHistoryData( szMsg );
		}
		else
		{
			SECSHistoryData( "Send Event 1201 (RECIPE UPLOAD)");
			//logForm->logHistorySave(1,"[E->H],RECIPE_UPLOAD,"+String(info.lot.lotID)+","+strRecipeId+",");
			if(MainForm->b_TpConnect)
			{
				g_pTpBase->logComm(L"SYSTEM",L"SEND", L"'TYPE'",L"'SECS/GEM'", L"'SECS/GEM'",L"'S6F11'", L"'CEID'",L"1201", L"'DURATION'",L"'NO'");
			}
		}
		delete [] pwsValue; pwsValue = NULL;
	}
	else
		return false;

	return true;
}
//---------------------------------------------------------------------------
bool __fastcall TFormSecsGemSet::eventRecipeDownload(int iPart)
{
	if(m_fStart != true)
		return false;

	if(true == g_MMIComm->Send() && true == g_MMIComm->Recv())
	{
		if(!bReadUseSkip(31))
		{
			SECSHistoryData("Recipe Not Download");
			return false;
		}
	}

	g_MMIComm->m_mmiToSeq.nCmd = iPart;
	BOOL bRet = g_MMIComm->Send() &&  g_MMIComm->Recv();
	if(bRet)
	{
		LOT_INFO info = g_MMIComm->m_mmiToSeq.buffer.lotInfo;

		long nCount = 6;
		long naVid[6];

		WideString* pwsValue = new WideString[6];

		String strRecipeId = String(info.recipeID);

		naVid[0] = 2001; pwsValue[0] = MainForm->_eqpID;
		naVid[1] = 2006; pwsValue[1] = String(info.lotID);
		naVid[2] = 2025; pwsValue[2] = String(info.partID);
		naVid[3] = 2092; pwsValue[3] = strRecipeId;
		naVid[4] = 2024; pwsValue[4] = String(info.step);
		naVid[5] = 2093; pwsValue[5] = String(info.lotType);

//		if(MainForm->IsDebugging())
//		{
//			pwsValue[1] = m_DebugData[4];
//			pwsValue[2] = m_DebugData[33];
//			pwsValue[3] = m_DebugData[36];
//			pwsValue[4] = m_DebugData[9];
//		}

		// 1. Update variable
		eXGem->GEMSetVariable(nCount, naVid, &pwsValue[0]);

		// 2. Event notification.
		long nReturn = eXGem->GEMSetEvent(1202);

		if(nReturn != 0)
		{
			char    szMsg[256];
			sprintf( szMsg, "[EQ ==> XGEM] GEMSetEvent (1202) Error Code => %d", nReturn);
			SECSHistoryData( szMsg );
		}
		else
		{
			SECSHistoryData( "Send Event 1202 (RECIPE DOWNLOAD)");
			//logForm->logHistorySave(1,"[E->H],RECIPE_DOWNLOAD,"+String(info.lot.lotID)+","+strRecipeId+",");
			if(MainForm->b_TpConnect)
			{
				g_pTpBase->logComm(L"SYSTEM",L"SEND", L"'TYPE'",L"'SECS/GEM'", L"'SECS/GEM'",L"'S6F11'", L"'CEID'",L"1202", L"'DURATION'",L"'NO'");
			}
		}
		delete [] pwsValue; pwsValue = NULL;
	}
	else
		return false;

	return true;
}
//---------------------------------------------------------------------------
bool __fastcall TFormSecsGemSet::manualRecipeDownload(String* strVal)
{
	if(m_fStart != true)
		return false;

	long nCount = 6;
	long naVid[6];

	WideString* pwsValue = new WideString[6];

	String strRecipeId = strVal[2]+".ZIP";

	naVid[0] = 2001; pwsValue[0] = MainForm->_eqpID;
	naVid[1] = 2006; pwsValue[1] = strVal[0];
	naVid[2] = 2025; pwsValue[2] = strVal[1];
	naVid[3] = 2092; pwsValue[3] = strRecipeId;
	naVid[4] = 2024; pwsValue[4] = strVal[3];
	naVid[5] = 2093; pwsValue[5] = strVal[4];

	// 1. Update variable
	eXGem->GEMSetVariable(nCount, naVid, &pwsValue[0]);

	// 2. Event notification.
	long nReturn = eXGem->GEMSetEvent(1202);

	if(nReturn != 0)
	{
		char    szMsg[256];
		sprintf( szMsg, "[EQ ==> XGEM] GEMSetEvent (1202) Error Code => %d", nReturn);
		SECSHistoryData( szMsg );
	}
	else
	{
		SECSHistoryData( "Send Event 1202 (RECIPE DOWNLOAD) Manual");
		//logForm->logHistorySave(1,"[E->H],RECIPE_DOWNLOAD,"+String(info.lot.lotID)+","+strRecipeId+",");
	}
	delete [] pwsValue; pwsValue = NULL;

	return true;
}
//---------------------------------------------------------------------------
bool __fastcall TFormSecsGemSet::manualRecipeUpload(String* strVal)
{
	if(m_fStart != true)
		return false;

	long nCount = 6;
	long naVid[6];

	WideString* pwsValue = new WideString[6];

	String strRecipeId = strVal[2]+".ZIP";

	naVid[0] = 2001; pwsValue[0] = MainForm->_eqpID;
	naVid[1] = 2006; pwsValue[1] = strVal[0];
	naVid[2] = 2025; pwsValue[2] = strVal[1];
	naVid[3] = 2092; pwsValue[3] = strRecipeId;
	naVid[4] = 2024; pwsValue[4] = strVal[3];
	naVid[5] = 2093; pwsValue[5] = strVal[4];

	// 1. Update variable
	eXGem->GEMSetVariable(nCount, naVid, &pwsValue[0]);

	// 2. Event notification.
	long nReturn = eXGem->GEMSetEvent(1201);

	if(nReturn != 0)
	{
		char    szMsg[256];
		sprintf( szMsg, "[EQ ==> XGEM] GEMSetEvent (1201) Error Code => %d", nReturn);
		SECSHistoryData( szMsg );
	}
	else
	{
		SECSHistoryData( "Send Event  1201 (RECIPE UPLOAD) Manual");
		//logForm->logHistorySave(1,"[E->H],RECIPE_UPLOAD,"+String(info.lot.lotID)+","+strRecipeId+",");
	}
	delete [] pwsValue; pwsValue = NULL;

	return true;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//Carrier ID
//MGZ Quantity
//LOT ID
//Step ID
//PartID
//MergeLot ID
//Lot Quantity
//Sub LotID
//MergeLot Quantity
//PCB BARCODE
//PCB MODE
//PCB ArrayBase Quantity
//PCB TEST Result
//PCB Arts Scrap
//PCB XOut Count

//분리..

//Scrap Count
//Scrap Code
//ScrapArray
//ScrapSerial
//Stage Number

#define    _MAX_BUCKET_STAGE_GEMDATA_         7 // 6->7

void TFormSecsGemSet::GemDataValueStage_Refresh(int nDMFeedback)
{
	if(m_fStart != true)
		return;

	if(1 != nReadCommunicationDM(nDMFeedback))
	{
		return;
	}

	nWriteCommunicationDM(2,nDMFeedback);   //busy
	SECSHistoryData( "GemDataValueStage_Refresh START! ->" + IntToStr(nDMFeedback));

	long nSTCount = _MAX_BUCKET_STAGE_GEMDATA_;

	long naSTVid[_MAX_BUCKET_STAGE_GEMDATA_];
	WideString* pwsSTValue = new WideString[_MAX_BUCKET_STAGE_GEMDATA_];

	/* RMS 하면서 정리. 나머진 안씀.
	_TRACK_IN_					564
	_TRACK_OUT_					565
	_GOOD_TRAY_STACK_END_		561
	_REJECT_TRAY_STACK_END_		563

	각 4 Stage
	_TB_CLEANING_END_          	512
	_QCVISION_END_				520
	_FLIP_PCB_END_			    532
	_TOP_PRS_END_			    540
	_BTM_PRS_END_			    548
	_TRAY_SORTING_START_		552
	_TRAY_SORTING_END_		    556
	_PCB_IN_					584
	*/

	int nStageNumber = (nDMFeedback-500)%4;//need to check ndm for stage number

	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_STG1_LOT_INFO + nStageNumber;
	BOOL bRet = g_MMIComm->Send() &&  g_MMIComm->Recv();
	if (bRet)
	{
		LOT_INFO info = g_MMIComm->m_mmiToSeq.buffer.lotInfo;

		naSTVid[0] = 2001; pwsSTValue[0] = MainForm->_eqpID;
		naSTVid[1] = 2006; pwsSTValue[1] = String(info.lotID);
		naSTVid[2] = 2025; pwsSTValue[2] = String(info.partID);
		naSTVid[3] = 2024; pwsSTValue[3] = String(info.step);
		naSTVid[4] = 2018; pwsSTValue[4] = IntToStr(info.lotQty);
		naSTVid[5] = 9000; pwsSTValue[5] = IntToStr(nStageNumber+1);

		if(info.mergeLotID == "")// 처음 Lot_In시 빈거는 LotID=MergeLotID라고 하여 수정
		{
			naSTVid[6] = 2020; pwsSTValue[6] = String(info.lotID);
		}
		else
		{
			naSTVid[6] = 2020; pwsSTValue[6] = String(info.mergeLotID);
        }
	}

	int nEvid = GemUpdateEvent(nDMFeedback);

	// 1. Update variable
	eXGem->GEMSetVariable(nSTCount, naSTVid, &pwsSTValue[0]);

	// 2. Event notification.
	eXGem->GEMSetEvent(nEvid);
	SECSHistoryData( "Send Event " + IntToStr(nEvid));

	String strEvid = IntToStr(nEvid);

	if(MainForm->b_TpConnect)
	{
		g_pTpBase->logComm(L"SYSTEM",L"SEND",L"'TYPE'",L"'SEC/GEMS'",L"'SEC/GEMS'",L"'S6F11'",L"'CEID'",strEvid.c_str(),L"'DURATION'",L"'NO'");
	}

	nWriteCommunicationDM(3,nDMFeedback);

	delete [] pwsSTValue; pwsSTValue = NULL;
}
//---------------------------------------------------------------------------

void TFormSecsGemSet::GemDataValueTray_Refresh(int nDMFeedback)
{
	if(m_fStart != true)
		return;

	if(1 != nReadCommunicationDM(nDMFeedback))
	{
		return;
	}

	nWriteCommunicationDM(2,nDMFeedback);
	SECSHistoryData( "GemDataValueTray_Refresh START! ->" + IntToStr(nDMFeedback));

	AnsiString	TkOutmergeLotID;
    g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_SCRAP_INFO_CUR_COPY;
	TkOutmergeLotID = g_MMIComm->m_mmiToSeq.buffer.onlineEndHistoryCopy.mergeLotID;

	String strCarrierID;
	long nSTCount = _MAX_BUCKET_STAGE_GEMDATA_;

	long naSTVid[_MAX_BUCKET_STAGE_GEMDATA_];
	WideString* pwsSTValue = new WideString[_MAX_BUCKET_STAGE_GEMDATA_];


	String StrValue[_MAX_BUCKET_STAGE_GEMDATA_];

	int cmdTrayIndex = CMD_RD_GOOD_SORT1;
	int nTrayNumber = nReadCommunicationDM(goodTrayNoForGem);//need to check ndm for stage number

	/* RMS 하면서 정리. 나머진 안씀.
	_TRACK_IN_					564
	_TRACK_OUT_					565
	_GOOD_TRAY_STACK_END_		561
	_REJECT_TRAY_STACK_END_		563

	각 4 Stage
	_TB_CLEANING_END_          	512
	_QCVISION_END_				520
	_FLIP_PCB_END_			    532
	_TOP_PRS_END_			    540
	_BTM_PRS_END_			    548
	_TRAY_SORTING_START_		552
	_TRAY_SORTING_END_		    556
	_PCB_IN_					584
	*/

	switch(nDMFeedback)
	{
		case 561:
			cmdTrayIndex = CMD_RD_GOOD_SORT1+nTrayNumber;
			break;
		case 563:
			cmdTrayIndex = CMD_RD_REJECT_SORT;
			break;
		case 564:
			cmdTrayIndex = CMD_RD_LOTINFO_CUR;
			if(dReadPkgData(VcutVisionSaveUse) == 1 && dReadPkgData(VcutVisionSaveCount) != 0)
			{
				nWriteCommunicationDM(2, VcutVisionSaveStatus);
				nWriteCommunicationDM(0, VcutVisionSaveTriggerCount);
				FrmVisionSetUp->JobChangeVCutVision("IMAGEON");
				MainForm->MachineHistoryData("V_Cut : LOT START VcutVisionSaveStatus 2 / VcutVisionSaveTriggerCount 0, IMAGE ON");
			}
			break;
		case 565:
			cmdTrayIndex = CMD_RD_LOTINFO_CUR;
			if(dReadPkgData(VcutVisionSaveUse) == 1 && dReadPkgData(VcutVisionSaveCount) != 0)
			{
				nWriteCommunicationDM(0, VcutVisionSaveStatus);
				nWriteCommunicationDM(0, VcutVisionSaveTriggerCount);
				FrmVisionSetUp->JobChangeVCutVision("IMAGEOFF");
				MainForm->MachineHistoryData("V_Cut : LOT END VcutVisionSaveStatus 0 / VcutVisionSaveTriggerCount 0, IMAGE OFF");
			}
			break;
	}

	g_MMIComm->m_mmiToSeq.nCmd = cmdTrayIndex;
	BOOL bRet = g_MMIComm->Send() &&  g_MMIComm->Recv();
	if (bRet)
	{
		LOT_INFO info = g_MMIComm->m_mmiToSeq.buffer.lotInfo;

		naSTVid[0] = 2001; pwsSTValue[0] = MainForm->_eqpID;
		naSTVid[1] = 2006; pwsSTValue[1] = String(info.lotID);
		naSTVid[2] = 2025; pwsSTValue[2] = String(info.partID);
		naSTVid[3] = 2024; pwsSTValue[3] = String(info.step);
		naSTVid[4] = 2018; pwsSTValue[4] = IntToStr(info.lotQty);

		if(nDMFeedback == 565)
		{

			naSTVid[6] = 2020; pwsSTValue[6] = TkOutmergeLotID;
		}
		else
		{
			naSTVid[6] = 2020; pwsSTValue[6] = String(info.mergeLotID);
		}
	}

	int nEvid = GemUpdateEvent(nDMFeedback);

	// 1. Update variable
	eXGem->GEMSetVariable(nSTCount, naSTVid, &pwsSTValue[0]);

	// 2. Event notification.
	eXGem->GEMSetEvent(nEvid);
	SECSHistoryData( "Send Event " + IntToStr(nEvid));

	String strEvid = IntToStr(nEvid);

	if(MainForm->b_TpConnect)
	{
		g_pTpBase->logComm(L"SYSTEM",L"SEND",L"'TYPE'",L"'SEC/GEMS'",L"'SEC/GEMS'",L"'S6F11'",L"'CEID'",strEvid.c_str(),L"'DURATION'",L"'NO'");
	}

	nWriteCommunicationDM(3,nDMFeedback);

	if(nDMFeedback == 564) // 2024.12.11 Track In Success Receip Upload
		this->GemRecipeChange();

	delete [] pwsSTValue; pwsSTValue = NULL;
}
//---------------------------------------------------------------------------

void TFormSecsGemSet::GemDataTraceStage_Refresh(int nDMFeedback)
{
	if(m_fStart != true)
		return;

	if(1 != nReadCommunicationDM(nDMFeedback))
	{
		return;
	}
	nWriteCommunicationDM(2,nDMFeedback);

	long nCount = 2;
	long naVid[2];
	int nIndex = nDMFeedback - 570;

if (nReadCommunicationDM(stageTraceFlag) == 1)
	{
		SECSHistoryData( "GemDataTraceStage_Refresh START! ->" + IntToStr(nDMFeedback));

		nWriteCommunicationDM(0, stageTraceFlag);

		if(GemTraceFileCreate(nIndex-1))
		{
			String strPPID("TRACE_DATA.dat");
			FileUpload(strPPID);
		}

		String strPPID("TRACE_DATA_VISION.dat");
		FileUpload(strPPID);

		if (bReadUseSkip(usAutoFeedBack))
		{
			FormAutoFBHistory->AutoFBDataSave();
		}
	}

	/*
	double dValue1, dValue2;
	WideString* pwsValue = new WideString[2];

	switch(nIndex)
	{
		case 0:
			dValue1 = dReadCommunicationDM(100);
			dValue2 = dReadCommunicationDM(101);
			break;
		case 1:
		case 2:
		case 3:
		case 4:
			dValue1 = dReadCommunicationDM(106);
			dValue2 = dReadCommunicationDM(107+(nIndex-1));
			break;
	}

	naVid[0] = 3100; pwsValue[1] = FloatToStr(dValue1);
	naVid[1] = 3102+nIndex; pwsValue[2] = FloatToStr(dValue2);

	// 1. Update variable
	eXGem->GEMSetVariable(nCount, naVid, &pwsValue[0]);

	// 2. Event notification.
	eXGem->GEMSetEvent(1465+nIndex);

	String strLog = "Send Event "+IntToStr(nIndex+1465);
	SECSHistoryData( strLog);

	nWriteCommunicationDM(3,nDMFeedback);   //success
	delete [] pwsValue; pwsValue = NULL;
	*/
	nWriteCommunicationDM(3,nDMFeedback);   //success
}
//---------------------------------------------------------------------------
void TFormSecsGemSet::GemTRAYNumberUpdate(String strTrayNo)
{
	long nCount = 1;
	long naVid[1];

	WideString* pwsValue = new WideString[1];

	naVid[0] = 2919; pwsValue[0] = strTrayNo;

	// 1. Update variable
	eXGem->GEMSetVariable(nCount, naVid, &pwsValue[0]);

	// 2. Event notification.
//	eXGem->GEMSetEvent(1300);
//	SECSHistoryData( "Send Event  1300");
	delete [] pwsValue; pwsValue = NULL;
}
//---------------------------------------------------------------------------
int TFormSecsGemSet::GemUpdateEvent(int nCategoryNo)
{
	int nRet;

	SECSHistoryData( "EVENT CMD RECEIVE -> " + IntToStr(nCategoryNo));

	/* RMS 하면서 정리. 나머진 안씀.
	_TRACK_IN_					564
	_TRACK_OUT_					565
	_GOOD_TRAY_STACK_END_		561
	_REJECT_TRAY_STACK_END_		563

	각 4 Stage
	_TB_CLEANING_END_          	512
	_QCVISION_END_				520
	_FLIP_PCB_END_			    532
	_TOP_PRS_END_			    540
	_BTM_PRS_END_			    548
	_TRAY_SORTING_START_		552
	_TRAY_SORTING_END_		    556
	_PCB_IN_					584
	*/

	switch(nCategoryNo)
	{
		case 564:
		{
			nRet =  9000;
		}
		break;
		case 565:
		{
			nRet =  9011;
		}
		break;

		case 561:
		{
			nRet =  9009;
		}
		break;
		case 563:
		{
			nRet =  9010;
		}
		break;

		case 584:
		case 585:
		case 586:
		case 587:
		{
			nRet =  9001;
		}
		break;

		case 512:
		case 513:
		case 514:
		case 515:
		{
			nRet =  9002;
		}
		break;

		case 520:
		case 521:
		case 522:
		case 523:
		{
			nRet =  9003;
		}
		break;

		case 532:
		case 533:
		case 534:
		case 535:
		{
			nRet =  9004;
		}
		break;

		case 536:
		case 537:
		case 538:
		case 539:
		{
			nRet =  1442;
		}
		break;

		case 540:
		case 541:
		case 542:
		case 543:
		{
			nRet =  9005;
		}
		break;

		case 548:
		case 549:
		case 550:
		case 551:
		{
			nRet =  9006;
		}
		break;

		case 552:
		case 553:
		case 554:
		case 555:
		{
			nRet =  9007;
		}
		break;

		case 556:
		case 557:
		case 558:
		case 559:
		{
			nRet =  9008;
		}
		break;

		default :
		{
			SECSHistoryData( "EXCEPTION CMD RECEVE -> " + IntToStr(nCategoryNo));
		}
		break;
	}

	return nRet;
}
//---------------------------------------------------------------------------
int TFormSecsGemSet::GemUpdateStatusVariable(int nCategoryNo)
{
	int nRet = 0;
	/*
	SECSHistoryData( "STATUS VAR START CMD RECEIVE -> " + IntToStr(nCategoryNo));

	switch(nCategoryNo)
	{
		case 500:
		case 501:
		case 502:
		case 503:
		case 504:
		case 505:
		case 506:
		case 507:
		{
			nRet =  2100;
		}
		break;

		case 508:
		case 509:
		case 510:
		case 511:
		case 512:
		case 513:
		case 514:
		case 515:
		{
			nRet =  2200;
		}
		break;

		case 516:
		case 517:
		case 518:
		case 519:
		case 520:
		case 521:
		case 522:
		case 523:
		{
			nRet =  2300;
		}
		break;

		case 524:
		case 525:
		case 526:
		case 527:
		{
			nRet =  2400;
		}
		break;

		case 528:
		case 529:
		case 530:
		case 531:
		case 532:
		case 533:
		case 534:
		case 535:
		{
			nRet =  2500;
		}
		break;

		case 536:
		case 537:
		case 538:
		case 539:
		case 540:
		case 541:
		case 542:
		case 543:
		{
			nRet =  2600;
		}
		break;

		case 544:
		case 545:
		case 546:
		case 547:
		case 548:
		case 549:
		case 550:
		case 551:
		{
			nRet =  2700;
		}
		break;

		case 552:
		case 553:
		case 554:
		case 555:
		case 556:
		case 557:
		case 558:
		case 559:
		{
			nRet =  2800;
		}
		break;

		case 560 :
		case 561 :
		{
			nRet =  2900;
		}
		break;

		case 562 :
		case 563 :
		{
			nRet =  3000;
		}
		break;

		default :
		{
			SECSHistoryData( "EXCEPTION CMD RECEVE -> " + IntToStr(nCategoryNo));
		}
		break;
	}
	*/
	return nRet;
}
//---------------------------------------------------------------------------

bool TFormSecsGemSet::GemRecipeItemFileCreate(AnsiString sPPID)
{
	FILE* fp;

	bool bRet = false;
	int nValue = 0;
	int nBitOneCutLength = 0;
	double dValue = 0.0;

	String strDirPath = ExtractFilePath(Application->ExeName)+"\\Gem\\SSD\\XWork\\Recipe\\";
	if(false == DirectoryExists(strDirPath.c_str()))
	{
		if (false == ForceDirectories(strDirPath.c_str()))
			return false;
	}

	int group=0, recipe=0;
	String strRcp = sPPID;	//.ZIP TYPE
	if( strRcp != "")
	{
		int iPos = strRcp.UpperCase().Pos(".ZIP");
		if(iPos != 0)	//Need to remove (.ZIP)
		{
			strRcp = strRcp.SubString(1,iPos-1);
		}

		if(GetRecipeIndexNO(group, recipe, strRcp)==false)
		{
			SECSHistoryData( "[Fail to File Create] Can NOT found the PPID : " + sPPID);
			return false;
		}
	}
	else	//NULL is current recipe
	{
		strRcp = Get_RecipeName();
		group = nReadGroupNo();
		recipe = nReadRecipeNo();
	}

	String sRcpFilePath		= ExtractFilePath(Application->ExeName)+ "ini\\system\\GRP"+IntToStr(group)+"\\RCP"+IntToStr(recipe)+"\\";

	TMemIniFile *m_ini;
	try
	{
		m_ini = new TMemIniFile(sRcpFilePath + "RcpInfo.ini");
		m_ini->Clear();

		m_ini->WriteInteger("RECIPE","GROUP_NO",group);
		m_ini->WriteInteger("RECIPE","RECIPE_NO",recipe);

		m_ini->UpdateFile();
	}
	 __finally
	{
		delete m_ini;
	}

	String strFilePath = sRcpFilePath + strRcp + ".TXT";
	String strCmd;

	if(true == FileExists(strFilePath))
		DeleteFile(strFilePath);

	SECSHistoryData( "Recipe File Create Start.......!");

	/// 레시피 파일 생성전 공용데이터 현재 레시피에 업데이트
	for(int i = 0; i < MAX_MT_NO; i++)
	{
		int _nAxis_no = i;
		String RC_strCmnPath = ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP0\\RCP0\\Motor"+ IntToStr(_nAxis_no)+".ini";
		String RC_StrPath = ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(group)+"\\RCP"+IntToStr(recipe)+"\\Motor"+ IntToStr(_nAxis_no)+".ini";
		String RC_StrNamePath = ExtractFilePath(Application->ExeName)+ "\\Ini\\MotorIndexName.ini";

		TIniFile *Origin_ini = new TIniFile(RC_strCmnPath);
		TIniFile *Now_ini = new TIniFile(RC_StrPath);
		TIniFile *MT_iniName = new TIniFile(RC_StrNamePath);

		for( int nRow = 0; nRow <= 50; nRow++ )
		{
			//String RC_EmptyStr = MT_iniName->ReadString("INDEXNAME"+IntToStr(_nAxis_no),"INDEXNAME"+IntToStr(nRow),"");
			//if(RC_EmptyStr != "") // 공백이 있으면 저장 안함 제외
			//{
				bool flag = MT_iniName->ReadBool("INDEXNAME"+IntToStr(_nAxis_no),"COMMON"+IntToStr(nRow),true);

				if(flag)
				{
					String POSITION = FloatToStr(Origin_ini->ReadFloat("INDEXPOS","POSITION"+IntToStr(nRow),0));
					String SPEED = FloatToStr(Origin_ini->ReadFloat("INDEXSPD","SPEED"+IntToStr(nRow),0));
					String ACC = FloatToStr(Origin_ini->ReadFloat("INDEXACC","ACC"+IntToStr(nRow),0));

					// 현재 레시피
					Now_ini->WriteString("INDEXPOS","POSITION"+IntToStr(nRow),POSITION);
					Now_ini->WriteString("INDEXSPD","SPEED"+IntToStr(nRow),SPEED);
					Now_ini->WriteString("INDEXACC","ACC"+IntToStr(nRow),ACC);

					// 0rigin 레시피 (오리진 제외)
//					Origin_ini->WriteString("INDEXPOS","POSITION"+IntToStr(nRow),POSITION);
//					Origin_ini->WriteString("INDEXSPD","SPEED"+IntToStr(nRow),SPEED);
//					Origin_ini->WriteString("INDEXACC","ACC"+IntToStr(nRow),ACC);
				}
			//}
		}
	   delete Origin_ini;
	   delete Now_ini;
	   delete MT_iniName;
	}

	TMemIniFile *m_iniPkg;
	try
	{
		m_iniPkg = new TMemIniFile(ExtractFilePath(Application->ExeName) + "\\tempPkgRcp.ini");
		m_iniPkg->Clear();

		g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_PKG;
		g_MMIComm->m_mmiToSeq.buffer.ddm.nStart = 0;
		g_MMIComm->m_mmiToSeq.buffer.ddm.nEnd  = 999;
		if(true == g_MMIComm->Send() && true == g_MMIComm->Recv())
		{
			CommDouble rtnVal = g_MMIComm->m_mmiToSeq.buffer.pkg;
			for(int i=0; i<1000; i++)
			{
				if(m_PkgName[i].SubString(1,4) != "Name" && m_PkgName[i].SubString(1,1) != "_")
					m_iniPkg->WriteString("PKGPARM",String().sprintf(L"%03d",i) +"_"+m_PkgName[i],FloatToStrF(rtnVal.dVal[i],ffFixed,10,3));
			}
			m_iniPkg->UpdateFile();
		}
	}
	 __finally
	{
		delete m_iniPkg;
	}

	TMemIniFile *m_iniDdm;
	try
	{
		m_iniDdm = new TMemIniFile(ExtractFilePath(Application->ExeName) + "\\tempRcp.ini");
		m_iniDdm->Clear();

		g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_DDM;
		g_MMIComm->m_mmiToSeq.buffer.ddm.nStart = 0;
		g_MMIComm->m_mmiToSeq.buffer.ddm.nEnd  = 999;
		if(true == g_MMIComm->Send() && true == g_MMIComm->Recv())
		{
			CommDouble rtnVal = g_MMIComm->m_mmiToSeq.buffer.ddm;
			for(int i=0; i<1000; i++)
			{
				if(m_DdmName[i].SubString(1,4) != "Name" && m_DdmName[i].SubString(1,1) != "_")
					m_iniDdm->WriteString("SYSPARM",String().sprintf(L"%03d",i) +"_"+m_DdmName[i],FloatToStrF(rtnVal.dVal[i],ffFixed,10,3));
			}
			m_iniDdm->UpdateFile();
		}
	}
	 __finally
	{
		delete m_iniDdm;
	}

	fp = _tfopen(strFilePath.c_str(), _T("w"));

	if (!fp)
		return FALSE;

	////////// Recipe file - info /////////////////////////////

	strCmd = "<<<KSS700 RECIPE>>>";
	_fputts(strCmd.c_str(), fp);
	_fputtc(_T('\n'), fp);

	strCmd = "[EQP_INFO]";
	_fputts(strCmd.c_str(), fp);
	_fputtc(_T('\n'), fp);

	strCmd ="EQP_ID=" + MainForm->_eqpID;
	_fputts(strCmd.c_str(), fp);
	_fputtc(_T('\n'), fp);

	strCmd ="RECIPE_ID=" + strRcp;
	_fputts(strCmd.c_str(), fp);
	_fputtc(_T('\n'), fp);
	_fputtc(_T('\n'), fp);

	//////////   setting pakage param /////////////////////////////

	strCmd = "[FDC]";
	_fputts(strCmd.c_str(), fp);
	_fputtc(_T('\n'), fp);

	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_PKG;
	g_MMIComm->m_mmiToSeq.buffer.pkg.nStart = 0;
	g_MMIComm->m_mmiToSeq.buffer.pkg.nEnd = 999;
	bRet = g_MMIComm->Send() &&  g_MMIComm->Recv();
	if(!bRet)
		return false;

	strCmd = "pcb X count="+IntToStr((int)g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[pcbXCnt]);
	_fputts(strCmd.c_str(), fp);
	_fputtc(_T('\n'), fp);
	strCmd = "pcb Y count="+IntToStr((int)g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[pcbYCnt]);
	_fputts(strCmd.c_str(), fp);
	_fputtc(_T('\n'), fp);
	strCmd = "tray X count="+IntToStr((int)g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[trayXCnt]);
	_fputts(strCmd.c_str(), fp);
	_fputtc(_T('\n'), fp);
	strCmd = "tray Y count="+IntToStr((int)g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[trayYCnt]);
	_fputts(strCmd.c_str(), fp);
	_fputtc(_T('\n'), fp);
	strCmd = "flip X pitch="+FloatToStr(g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[padOffSetX]);
	_fputts(strCmd.c_str(), fp);
	_fputtc(_T('\n'), fp);
	strCmd = "flip Y pitch="+FloatToStr(g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[padOffSetY]);
	_fputts(strCmd.c_str(), fp);
	_fputtc(_T('\n'), fp);

	strCmd = "jig to pcb X="+FloatToStr(g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[padOffSetY]);
	_fputts(strCmd.c_str(), fp);
	_fputtc(_T('\n'), fp);
	strCmd = "jig to pcb Y="+FloatToStr(g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[padOffSetY]);
	_fputts(strCmd.c_str(), fp);
	_fputtc(_T('\n'), fp);
	strCmd = "jig to pcb Z="+FloatToStr(g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[padOffSetY]);
	_fputts(strCmd.c_str(), fp);
	_fputtc(_T('\n'), fp);

	strCmd = "1st btm clean count="+FloatToStr(g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[btmCleanCnt1]);
	_fputts(strCmd.c_str(), fp);
	_fputtc(_T('\n'), fp);
	strCmd = "1st top clean count="+FloatToStr(g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[topCleanCnt1]);
	_fputts(strCmd.c_str(), fp);
	_fputtc(_T('\n'), fp);
	strCmd = "2nd btm clean count="+FloatToStr(g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[btmCleanCnt2]);
	_fputts(strCmd.c_str(), fp);
	_fputtc(_T('\n'), fp);
	strCmd = "2nd top clean count="+FloatToStr(g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[topCleanCnt2]);
	_fputts(strCmd.c_str(), fp);
	_fputtc(_T('\n'), fp);
	strCmd = "3rd btm clean count="+FloatToStr(g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[btmCleanCnt3]);
	_fputts(strCmd.c_str(), fp);
	_fputtc(_T('\n'), fp);
	strCmd = "3rd top clean count="+FloatToStr(g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[topCleanCnt3]);
	_fputts(strCmd.c_str(), fp);
	_fputtc(_T('\n'), fp);
	strCmd = "max tray stack count="+FloatToStr(g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[trayStackMaxCnt]);
	_fputts(strCmd.c_str(), fp);
	_fputtc(_T('\n'), fp);

	for(int cmdCnt=0; cmdCnt<4; cmdCnt++)
	{
		for(int index=0; index<20; index++)
		{
			switch(cmdCnt)
			{
				case 0:
					nValue = pcb00PosX+(index*2);
					strCmd.sprintf(_T("pcb coord x%02d=%f"),index, g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[nValue]);
					_fputts(strCmd.c_str(), fp);
					_fputtc(_T('\n'), fp);
					nValue++;
					strCmd.sprintf(_T("pcb coord y%02d=%f"),index, g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[nValue]);
					_fputts(strCmd.c_str(), fp);
					_fputtc(_T('\n'), fp);
					break;
				case 1:
					strCmd.sprintf(_T("pcb is flipped %02d=%f"),index, g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[pcb00isFlip+index]);
					_fputts(strCmd.c_str(), fp);
					_fputtc(_T('\n'), fp);
					break;
				case 2:
					strCmd.sprintf(_T("pcb theta %02d=%f"),index, g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[pcb00Theta+index]);
					_fputts(strCmd.c_str(), fp);
					_fputtc(_T('\n'), fp);
					break;
				case 3:
					nValue = pcbVi00PosX+(index*2);
					strCmd.sprintf(_T("qc vision coord x%02d=%f"),index, g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[nValue]);
					_fputts(strCmd.c_str(), fp);
					_fputtc(_T('\n'), fp);
					nValue++;
					strCmd.sprintf(_T("qc vision coord y%02d=%f"),index, g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[nValue]);
					_fputts(strCmd.c_str(), fp);
					_fputtc(_T('\n'), fp);
					break;
			}
		}
	}

	// Motor Data Position 누락되어있어서 추가
	int nGrpNo, nRcpNo;
	nGrpNo = nReadGroupNo();
	nRcpNo = nReadRecipeNo();
	AnsiString Ansi1;

	String StrNamePath = ExtractFilePath(Application->ExeName)+ "\\Ini\\MotorIndexName.ini";
	String MtrNamePath = ExtractFilePath(Application->ExeName)+ "\\Ini\\MotorName.ini";

	TIniFile *iniName = new TIniFile(StrNamePath);
	TIniFile *Mtrini  = new TIniFile(MtrNamePath);

	for(int i = 0; i < MAX_MT_NO; i++)
	{
		int _nAxis_no = i;
		String StrPath = ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(nGrpNo)+"\\RCP"+IntToStr(nRcpNo)+"\\Motor"+ IntToStr(_nAxis_no)+".ini";
		TIniFile *ini  = new TIniFile(StrPath);

		strCmd = "[MOTORDATA]"+ IntToStr(_nAxis_no+1) + " : " + Mtrini->ReadString("AXISNAME","AXIS"+IntToStr(_nAxis_no),"");
		_fputts(strCmd.c_str(), fp);
		_fputtc(_T('\n'), fp);

		for( int nRow = 0; nRow <= 50; nRow++ )
		{
			Ansi1 = iniName->ReadString("INDEXNAME"+IntToStr(_nAxis_no),"INDEXNAME"+IntToStr(nRow),"");
			if(Ansi1 != "")
			{
				strCmd = Mtrini->ReadString("AXISNAME","AXIS"+IntToStr(_nAxis_no),"") + " "+IntToStr(nRow) + " " + iniName->ReadString("INDEXNAME"+IntToStr(_nAxis_no),"INDEXNAME"+IntToStr(nRow),"") + " POS=" + ini->ReadString("INDEXPOS","POSITION"+IntToStr(nRow),"POSITION"+IntToStr(nRow));
				_fputts(strCmd.c_str(), fp); //POSITION
				_fputtc(_T('\n'), fp);
			   //	strCmd = Mtrini->ReadString("AXISNAME","AXIS"+IntToStr(_nAxis_no),"") + " "+IntToStr(nRow) + " " + iniName->ReadString("INDEXNAME"+IntToStr(_nAxis_no),"INDEXNAME"+IntToStr(nRow),"") + " SPD=" + ini->ReadString("INDEXSPD","SPEED"+IntToStr(nRow),"SPEED"+IntToStr(nRow));
			   //	_fputts(strCmd.c_str(), fp); //SPEED
				//_fputtc(_T('\n'), fp);
				//strCmd = Mtrini->ReadString("AXISNAME","AXIS"+IntToStr(_nAxis_no),"") + " "+IntToStr(nRow) + " " + iniName->ReadString("INDEXNAME"+IntToStr(_nAxis_no),"INDEXNAME"+IntToStr(nRow),"") + " ACC=" + ini->ReadString("INDEXACC","ACC"+IntToStr(nRow),"ACC"+IntToStr(nRow));
				//_fputts(strCmd.c_str(), fp); //ACC
				//_fputtc(_T('\n'), fp);
			}
		}
		delete ini;
	}
	delete Mtrini;
	delete iniName;

	static const String sStaubliData[]={	"STAUBLI_STAGE_1_Z=",
											"STAUBLI_STAGE_2_Z=",
											"STAUBLI_STAGE_3_Z=",
											"STAUBLI_STAGE_4_Z=",
											"STAUBLI_FLIPPER_TOP_Z=",
											"STAUBLI_FLIPPER_BTM_Z="};
	static const int iStaubliIndex[]={		1,2,3,4,6,7	};
	int iIdx = 0;
	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_STAUBLI_TABLE;
	if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
	{
		::StaubliTable staubli = g_MMIComm->m_mmiToSeq.buffer.staubliTable;
		for (int i = 0; i < 6; i++)
		{
			iIdx = iStaubliIndex[i];
			strCmd =sStaubliData[i]+FloatToStrF(staubli.posZ[iIdx], ffFixed, 10, 3);
			_fputts(strCmd.c_str(), fp);
			_fputtc(_T('\n'), fp);
		}
	}
	_fputtc(_T('\n'), fp);

	fflush(fp);
	fclose(fp);
	fp = NULL;

	SECSHistoryData( "Recipe File Creating (1) .......!");

	String sPkgFilePath		= ExtractFilePath(Application->ExeName)+ "\\tempPkgRcp.ini";
	int iRst = CombineFiles(strFilePath,sPkgFilePath);
	if(iRst==0)
	{
		String sFilePath	= ExtractFilePath(Application->ExeName) + "\\tempRcp.ini";
		iRst = CombineFiles(strFilePath,sFilePath);
		SECSHistoryData( "Recipe File Creating (2) .......!");

		String TargetAddr = sMarsLogPath + "\\" + Now().FormatString("yyyymmdd") + "\\";

		if(!DirectoryExists(TargetAddr))
			ForceDirectories(TargetAddr);

		String strPPID = Get_RecipeName()+"_"+Now().FormatString("yyyymmdd_hh-nn-ss")+".ini";
		TargetAddr += strPPID;

		if(CopyFile(strFilePath.c_str(),TargetAddr.c_str(),false))
		{
			if(MainForm->b_TpConnect)
			{
				String strData = "'"+TargetAddr+"'";
				g_pTpBase->logConfigure(L"PARAM",L"SAVE",L"'PATH'",strData.c_str());
			}
		}
	}

	if(iRst != 0)
	{
		SECSHistoryData( "Recipe File Create Fail Code - " + IntToStr(iRst));
		return false;
	}
	else
	{
		//압축
		String sData[2] = {0,};
		sData[0] = sRcpFilePath;
		sData[1] = strDirPath + strRcp;
		if(CompactZip(0, sData)==0)
		{
			SECSHistoryData( "Recipe File Create Archive Fail - CompactZip(0)");
			return false;
		}
		SECSHistoryData( "Recipe File Create End.......!");
	}

	return true;
}
//---------------------------------------------------------------------------

bool TFormSecsGemSet::GemTraceFileCreate(int nStageIndex)
{
	FILE* fp;

	bool bRet = false;
	int nValue = 0;
	int nBitOneCutLength = 0;
	double dValue = 0.0;

	String strDirPath = ExtractFilePath(Application->ExeName)+"\\Gem\\SSD\\XWork\\Recipe\\";
	String strFilePath = strDirPath + "TRACE_DATA.dat";
	String strCmd;

	if(false == DirectoryExists(strDirPath.c_str()))
	{
		if (false == CreateDir(strDirPath.c_str()))
			return false;
	}
	else
	{
		if (true == FileExists(strFilePath.c_str()))
			DeleteFile(strFilePath.c_str());
	}

	fp = _tfopen(strFilePath.c_str(), _T("w"));

	if (!fp)
		return FALSE;


	SECSHistoryData( "Trace File Create Start.......!");

	////////// Trace file - info /////////////////////////////

	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_DDM;
	g_MMIComm->m_mmiToSeq.buffer.pkg.nStart = 0;
	g_MMIComm->m_mmiToSeq.buffer.pkg.nEnd = 999;
	bRet = g_MMIComm->Send() &&  g_MMIComm->Recv();
	if(!bRet)
		return false;

	strCmd = "ROBOT_PICKUP_PAD_TYPE="+FloatToStr(dReadPkgData(targetPad));
	_fputts(strCmd.c_str(), fp);
	_fputtc(_T('\n'), fp);
	strCmd = "ROBOT_PICKUP_PAD_COUNT="+FloatToStr(dReadCommunicationDM(930));
	_fputts(strCmd.c_str(), fp);
	_fputtc(_T('\n'), fp);
	strCmd = "ROBOT_PICKUP_VACUUM="+FloatToStr(dReadCommunicationDM(106));
	_fputts(strCmd.c_str(), fp);
	_fputtc(_T('\n'), fp);
	strCmd = "IONIZER_TRACE="+FloatToStr(dReadCommunicationDM(100));
	_fputts(strCmd.c_str(), fp);
	_fputtc(_T('\n'), fp);
	strCmd = "MAIN_AIR="+FloatToStr(dReadCommunicationDM(101));
	_fputts(strCmd.c_str(), fp);
	_fputtc(_T('\n'), fp);
	strCmd = "INDEX_FLOW_OPEN="+FloatToStr(dReadCommunicationDM(107+nStageIndex));
	_fputts(strCmd.c_str(), fp);
	_fputtc(_T('\n'), fp);
	strCmd = "STAGE_NUMBER="+IntToStr(nStageIndex+1);
	_fputts(strCmd.c_str(), fp);
	_fputtc(_T('\n'), fp);


	SECSHistoryData( "Trace File Create End.......!");
	_fputtc(_T('\n'), fp);

	fflush(fp);
	fclose(fp);
	fp = NULL;

	return true;
}
//---------------------------------------------------------------------------

void __fastcall TFormSecsGemSet::Button1Click(TObject *Sender)
{
	int nTag = dynamic_cast<TButton*>(Sender)->Tag;

	if(nTag == 0)
		GemRecipeItemFileCreate(edtModuleID->Text);
	else
	{
		int nStageIndex = nReadCommunicationDM(581);
		GemTraceFileCreate(nStageIndex);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormSecsGemSet::Button2Click(TObject *Sender)
{
	int nTag = dynamic_cast<TButton*>(Sender)->Tag;

	String strPPID;
	if(nTag == 0)
		strPPID = recipePartName + ".rcp"; // strPPID = "recipeFile.rcp";
	else
		strPPID = "TRACE_DATA.dat";
	FileUpload(strPPID);
	SECSHistoryData( "Send To Host GEMReqPPSendEx successfully" );
}
//---------------------------------------------------------------------------
bool __fastcall	TFormSecsGemSet::FileUpload(String strPPID)
{
	try
	{
		String StrRcpPath = ExtractFilePath(Application->ExeName)+ "Gem\\SSD\\XWork\\Recipe\\" + strPPID;
		if ( false == FileExists(StrRcpPath))
		{
			SECSHistoryData("recipe file not found : " + StrRcpPath);
			return false;
		}

		INT nRecipeFileSize = FileSizeByName( StrRcpPath);
		if (true == PPLoadInquireS7F1Process(strPPID, nRecipeFileSize))
		{
			// eXGemeGEMRspPPLoadInquire 에서 처리
			return true;
		}
		return false;
	}
	catch (Exception &exception)
	{
		SECSHistoryData("RecipeUpload exception :" + exception.Message);
		return false;
	}
}
//---------------------------------------------------------------------------
bool __fastcall	TFormSecsGemSet::FileDownload(String strPPID)
{
	try
	{
		String StrRcpPath = ExtractFilePath(Application->ExeName)+ "Gem\\SSD\\XWork\\Recipe\\" + strPPID;
		if ( false == FileExists(StrRcpPath))
		{
			SECSHistoryData("recipe file(download) not found : " + StrRcpPath);
			return false;
		}

		//해제
		String sData[2] = {0,};
		sData[0] = StrRcpPath;
		sData[1] = ExtractFilePath(Application->ExeName)+ "Ini\\System\\temp";

		if(true == DirectoryExists(sData[1].c_str()))
		{
			DeleteTree(sData[1]);
			Sleep(100);
		}

		if(CompactZip(1, sData)==0)
		{
			SECSHistoryData( "Recipe File Download Extract Fail - CompactZip(1)");
			return false;
		}
		else
		{
			Sleep(1000);

			int iPos = UpperCase(strPPID).Pos(".ZIP");
			if(iPos>1)
			{
				String sPPID = strPPID.SubString(1,iPos-1);
				String sPpidPath = ExtractFilePath(Application->ExeName)+ "Ini\\System\\temp\\RcpInfo.ini";
				if(FileExists(sPpidPath))
				{
					int iGroupNo=0, iRecipeNo=0;
					TIniFile *ini;
					try
					{
						ini = new TIniFile(sPpidPath);
						iGroupNo = ini->ReadInteger("RECIPE","GROUP_NO",0);
						iRecipeNo = ini->ReadInteger("RECIPE","RECIPE_NO",0);
					}
					__finally
					{
						delete ini;
					}

					if(iGroupNo !=0 && iRecipeNo !=0)
					{
						sData[0] = ExtractFilePath(Application->ExeName)+ "Ini\\System\\temp";
						sData[1] = ExtractFilePath(Application->ExeName)+ "Ini\\System\\GRP"+ IntToStr(iGroupNo) +"\\RCP"+ IntToStr(iRecipeNo);
						doXCopy(sData);

						MainForm->MachineHistoryData(String().sprintf(L"Recipe Download - Changing G-D[%d-%d]",iGroupNo,iRecipeNo));

						Sleep(1000);

						// Device Change Req. to seq.
						nWriteCommunicationDM(iGroupNo,autoDeviceChg_GroupNo);
						nWriteCommunicationDM(iRecipeNo,autoDeviceChg_RecipeNo);
						//nWriteCommunicationDM(1,needToChange);

						RecipeChangeForm->AutoDeviceChangeTimer->Enabled = true;

						DeleteTree(sData[0]);
					}
					else
					{
						SECSHistoryData( "Recipe File Download Wrong Group:Recipe Fail - " + IntToStr(iGroupNo)+":"+IntToStr(iRecipeNo));
						return false;
					}
				}
				else
				{
					SECSHistoryData( "Recipe File Download NO File Fail - " + sPpidPath);
					return false;
				}
			}
			else
			{
				SECSHistoryData( "Recipe File Download Wrong PPID(.ZIP X) Fail - " + IntToStr(iPos));
				return false;
			}
		}

		return true;
	}
	catch (Exception &exception)
	{
		SECSHistoryData("RecipeDownload exception :" + exception.Message);
		return false;
	}
}
//---------------------------------------------------------------------------
bool __fastcall TFormSecsGemSet::PPLoadInquireS7F1Process(WideString StrPPID , long lLength)
{
	long nReturn  = 0;

	nReturn = eXGem->GEMReqPPLoadInquire(StrPPID.c_bstr(), lLength);
	if( nReturn == 0 )
	{
		SECSHistoryData("Send GEMReqPPLoadInquire successfully" );
		return true;
	}
	else
	{
		SECSHistoryData("Fail to GEMReqPPLoadInquire ");
		return false;
	}
}
//---------------------------------------------------------------------------

bool __fastcall TFormSecsGemSet::PPSendS7F3Process(WideString StrPPID, int nLen)
{

	long nReturn  = 0;
	WideString StrRcpPath =  "";

	nReturn = eXGem->GEMReqPPSendEx(StrPPID.c_bstr(),StrRcpPath.c_bstr());
	if( nReturn == 0 )
	{
		SECSHistoryData("Send GEMReqPPSend successfully" );
		return true;
	}

	SECSHistoryData("Fail to GEMReqPPSend ");
	return false;
}
//---------------------------------------------------------------------------

void   TFormSecsGemSet::TrackIn_Cycle(int nDmNum)
{
//	if(m_fStart != true)
//		return;
//
//	if(1 != nReadCommunicationDM(nDmNum))
//	{
//		return;
//	}
//
//	int nStatus = nReadCommunicationDM(nDmNum);
//	if(nStatus == STATE_REQ)
//	{
//		SECSHistoryData("Track_In_Cycle Start...." );
//		nWriteCommunicationDM(STATE_BUSY, nDmNum);
//
//		//1. TrackIn Ceid
//		if(TrackIn())
//		{
//			//2. Recipe File Create
//			SECSHistoryData("Recipe File Create Start...." );
//			if(GemRecipeItemFileCreate())
//			{
//				//3. Recipe File Upload
//				SECSHistoryData("Recipe File Upload Start...." );
//				String strPPID(recipePartName + ".rcp");
//				// String strPPID("recipeFile.rcp");
//				FileUpload(strPPID);
//				nWriteCommunicationDM(STATE_COMP, nDmNum);
//			}
//			else
//				nWriteCommunicationDM(STATE_ERR, nDmNum);
//		}
//		else
//			nWriteCommunicationDM(STATE_ERR, nDmNum);
//
//		SECSHistoryData("Track_In_Cycle End...." );
//	}
}
//---------------------------------------------------------------------------
void __fastcall TFormSecsGemSet::loadRecipeParamName()
{
	TIniFile *PkgNameini = new TIniFile(ExtractFilePath(Application->ExeName)+ "Ini\\PkgName.ini");

	for(int i=0; i<1000; i++)
		m_PkgName[i] = PkgNameini->ReadString("PKGNAME","NAME"+IntToStr(i),"Name"+IntToStr(i));

	delete PkgNameini;

	TIniFile *DParamini = new TIniFile(ExtractFilePath(Application->ExeName)+ "Ini\\DParam.ini");

	for(int i=0; i<1000; i++)
		m_DdmName[i] = DParamini->ReadString("DPARAM","NAME"+IntToStr(i),"Name"+IntToStr(i));

	delete DParamini;
}
//---------------------------------------------------------------------------
int __fastcall TFormSecsGemSet::CombineFiles(String sDest, String sSource)	// sDest + sSource
{
	if(!FileExists(sDest.c_str()))		return 1;
	if(!FileExists(sSource.c_str()))	return 2;

	TMemoryStream *ms = new TMemoryStream;
	try
	{
		ms->LoadFromFile(sSource.c_str());
		int iScrSize= ms->Size;
		TBytes sData;
		sData.Length = iScrSize;
		int iSize = ms->Read(sData,iScrSize);
		if(iSize == iScrSize)
		{
			ms->LoadFromFile(sDest.c_str());
			iSize= ms->Size;
			ms->Position=iSize;
			ms->Write(sData,iScrSize);
		}

		ms->SaveToFile(sDest.c_str());
	}
	__finally
	{
		delete ms;
	}
	return 0;
}

//---------------------------------------------------------------------------
void __fastcall TFormSecsGemSet::eXGemeGEMReqOnline(TObject *Sender, long nMsgId,
          long nFromState, long nToState)
{
	SECSHistoryData("Receive S1F17 Msg...." );
	eXGem->GEMRspOnline(nMsgId, 0);
	SECSHistoryData("Send S1F18 MsgID:"+IntToStr((int)nMsgId)+", ACK:0" );
}
//---------------------------------------------------------------------------

void __fastcall TFormSecsGemSet::eXGemeGEMReqPPEx(TObject *Sender, long nMsgId, BSTR sPpid,
          BSTR sBody)
{
	// [H->E] S7F5 : recipe upload req.
	char szMsg[256];
	AnsiString strPPID(sPpid);
	sprintf(szMsg, "[H->E] S7F5 : Received %s, MsgId = %d, Ppid = %s, PPBody = %s", "GEMReqPPEx", nMsgId, strPPID, AnsiString(sBody));
	this->SECSHistoryData( szMsg );
	//logForm->logHistorySave(1,"[H->E],S7F5,"+strPPID+",");

	//Create Recipe File (C:\KOSES\MMI\Gem\SSD\XWork\Recipe\)
	this->GemRecipeItemFileCreate(strPPID);	// 현재는 현재 Recipe 로만 만듬ㅜㅜ

	Sleep(tmRcpUpload->Interval);	//압축파일 생성 시간(1000ms)... test: 800ms 이상 필요.

	// [E->H] S7F6 : ppid, ppbody(C:\KOSES\MMI\Gem\SSD\XWork\Recipe\)
	long nReturn = 0;
	nReturn = eXGem->GEMRspPPEx(nMsgId, sPpid, sBody);
	if( nReturn == 0 )
	{
		SECSHistoryData( "[E->H] S7F6 : GEMRspPPEx successfully : " +strPPID );
		//ref.: delete file after success...
	}
	else
	{
		sprintf( szMsg, "[E->H] S7F6 : Fail to GEMRspPPEx (%d)", nReturn );
		SECSHistoryData( szMsg );
	}
	//logForm->logHistorySave(1,"[E->H],S7F6,RESULT:"+String(nReturn)+",");
}
//---------------------------------------------------------------------------
void __fastcall TFormSecsGemSet::eXGemeGEMRspPPEx(TObject *Sender, BSTR sPpid, BSTR sBody)

{
	// NO검증
	// eq -> recipe download
	char szMsg[256];
	AnsiString strPPID(sPpid);
	sprintf(szMsg, "Received %s, Ppid = %s, PPBody = %s", "GEMRspPPEx", strPPID, AnsiString(sBody));
	this->SECSHistoryData( szMsg );

	String filename = String(sPpid);
	String filepath = String(sBody);

	//recipe folder 에 ppid 파일 있어야함
	//this->deleteRecipeFile(filename, filepath);
}
//---------------------------------------------------------------------------
void __fastcall TFormSecsGemSet::SendVersionTimerTimer(TObject *Sender)
{
	SendVersionTimer->Enabled = false;
	GemVersionUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TFormSecsGemSet::tmRcpUploadTimer(TObject *Sender)
{
	tmRcpUpload->Enabled = false;
	SECSHistoryData("Recipe Upload Start...." );
	String strPPID = Get_RecipeName()+ ".ZIP";//strPPID("recipeFile.rcp");
	FileUpload(strPPID);
	SECSHistoryData("Recipe Upload End...." );
}
//---------------------------------------------------------------------------
int __fastcall TFormSecsGemSet::CompactZip(int iOption, String *sData)
{
	wchar_t cTargetDir[200],cOutputDir[200];
	ZeroMemory(cTargetDir,sizeof(cTargetDir));
	ZeroMemory(cOutputDir,sizeof(cOutputDir));
	wmemcpy(cTargetDir,sData[0].c_str(),sData[0].Length());
	wmemcpy(cOutputDir,sData[1].c_str(),sData[1].Length());

	//swprintf(cSaveDirpName, L"%s\\%s\\%s", cSaveDir, cSaveFolder, cSaveName2);
//	FILE* fExist = _wfopen(cSaveDirpName, L"rt");
//	if (NULL != fExist)
//	{
//		fclose(fExist);

		wchar_t	cPatchFile[100] = {0,};
		swprintf(cPatchFile, L"%s", cTargetDir);

		wchar_t	cBandiDir[100] = {0,};
		swprintf(cBandiDir, L"%s", L"C:\\Program Files\\Bandizip\\bz.exe");	//Bandizip32.exe

		wchar_t   cCommand[200] = {0,};

		if(iOption == 0)
			swprintf(cCommand, L" /archive %s.ZIP %s*.*", cOutputDir, cPatchFile);	//bz.exe /archive [dest Zip] [sorc Dir]
		else
			swprintf(cCommand, L" x -o:%s %s", cOutputDir, cPatchFile);
			//swprintf(cCommand, L" /extract %s %s", cOutputDir, cPatchFile);
			//swprintf(cCommand, L" x -o:%s %s", cOutputDir, cPatchFile);	//bz.exe x -o:[sorc Dir] [dest Zip]

		HINSTANCE nResult = ShellExecuteW(NULL, L"open", cBandiDir, cCommand, 0, SW_SHOWNORMAL);

		if((int)nResult > 32)
		{
			return TRUE;
		}
		else
		{
			CompactResult((int)nResult);
			return FALSE;
		}
//	}
//	else
//	{
//		fclose(fExist);
//		return FALSE;
//	}
}
//---------------------------------------------------------------------------
void TFormSecsGemSet::CompactResult(int nResult)
{
	wchar_t cCaption[50] = {0,};
	wcscpy(cCaption, L"compact result");

	switch(nResult)
	{
		case NULL:
		case SE_ERR_OOM:
			MessageBoxW(NULL, L"memory or resource is not enough", cCaption, NULL);
			break;

		case ERROR_FILE_NOT_FOUND:
			MessageBoxW(NULL, L"file not found", cCaption, NULL);
			break;

		case ERROR_PATH_NOT_FOUND:
			MessageBoxW(NULL, L"file path not foune", cCaption, NULL);
			break;

		case SE_ERR_ACCESSDENIED:
			MessageBoxW(NULL, L"require not accept", cCaption, NULL);
			break;

		case SE_ERR_ASSOCINCOMPLETE:
			MessageBoxW(NULL, L"file name is not sure", cCaption, NULL);
			break;

		case SE_ERR_DDEBUSY:
			MessageBoxW(NULL, L"another DDE is not complete", cCaption, NULL);
			break;

		case SE_ERR_DDEFAIL:
			MessageBoxW(NULL, L"DDE fail", cCaption, NULL);
			break;

		case SE_ERR_DDETIMEOUT:
			MessageBoxW(NULL, L"time over the DDE", cCaption, NULL);
			break;

		case SE_ERR_DLLNOTFOUND:
			MessageBoxW(NULL, L"DLL file is not found", cCaption, NULL);
			break;

		case SE_ERR_SHARE:
			MessageBoxW(NULL, L"violation of shared", cCaption, NULL);
			break;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormSecsGemSet::DeleteTree(String stDirectory)
{
	WIN32_FIND_DATA   fdFiles;
	HANDLE            hdHandle;
	wchar_t	          chFileName[256];


	hdHandle = FindFirstFile(((String)stDirectory + "\\*").c_str(), &fdFiles);

	if(hdHandle) {
		do {
			ZeroMemory(chFileName,sizeof(chFileName));
			wsprintf(chFileName, L"%s\\%s", stDirectory.c_str(), fdFiles.cFileName);

			if(wcscmp(fdFiles.cFileName, L".") && wcscmp(fdFiles.cFileName, L"..")) {

			if(fdFiles.dwFileAttributes & FILE_ATTRIBUTE_READONLY)  // Read-Only 파일 처리
				SetFileAttributes(chFileName, fdFiles.dwFileAttributes & ~FILE_ATTRIBUTE_READONLY);

			if(fdFiles.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				DeleteTree(chFileName); // 디렉토리면 DeleteTree를 재귀 호출
			else
				DeleteFile(chFileName);

			}
		} while(FindNextFile(hdHandle, &fdFiles));

		FindClose(hdHandle);
	}

	RemoveDirectory(stDirectory.c_str());

}
//---------------------------------------------------------------------------
void __fastcall TFormSecsGemSet::doXCopy(String *sData)
{
	String sSrcDir, sDstDir;
	sSrcDir = sData[0];
	sDstDir = sData[1];
	//sSrcDir.sprintf(L"%s\\%s\\%s",sData[0],sData[1],sData[2]);
	//sDstDir.sprintf(L"%s\\%s\\%s",sData[0],sData[1],sData[3]);

	wchar_t	          chFileName[256] = {0,};
	wsprintf(chFileName, L"%s", sSrcDir.c_str());

	wchar_t	          chFileTgName[256] = {0,};
	wsprintf(chFileTgName, L"%s", sDstDir.c_str());

	wchar_t   cCommand[200] = {0,};
	swprintf(cCommand, L" /Y /E /I %s %s", chFileName, chFileTgName);

	HINSTANCE nResult = ShellExecuteW(NULL, L"open", L"xcopy.exe", cCommand, 0, SW_HIDE );
	if((int)nResult > 32)
		return;
	else
	{
		CompactResult((int)nResult);
		return;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormSecsGemSet::SpeedButton1Click(TObject *Sender)
{
/*
2001   EQUIPMENT ID
1004   Process State
*/
	long nCount = 2;
	long naVid[2];

	WideString* pwsValue = new WideString[2];

	naVid[0] = 2011; pwsValue[0] = StringGrid1->Cells[1][1];
	naVid[1] = 1001; pwsValue[1] = StringGrid1->Cells[1][2];

	// 1. Update variable
	eXGem->GEMSetVariable(nCount, naVid, &pwsValue[0]);

	// 2. Event notification.
	eXGem->GEMSetEvent(1001);

	SECSHistoryData( "Manual Send Event  1001");
	delete [] pwsValue; pwsValue = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TFormSecsGemSet::SpeedButton2Click(TObject *Sender)
{
	int iTag = dynamic_cast<TSpeedButton *>(Sender)->Tag;

	long nCount = 6;
	long naVid[6];

	WideString* pwsValue = new WideString[6];

	naVid[0] = 2001; pwsValue[0] = StringGrid1->Cells[1][1];
	naVid[1] = 2006; pwsValue[1] = StringGrid1->Cells[1][2];
	naVid[2] = 2025; pwsValue[2] = StringGrid1->Cells[1][3];
	naVid[3] = 2092; pwsValue[3] = StringGrid1->Cells[1][4];
	naVid[4] = 2024; pwsValue[4] = StringGrid1->Cells[1][5];
	naVid[5] = 2093; pwsValue[5] = StringGrid1->Cells[1][6];

	// 1. Update variable
	eXGem->GEMSetVariable(nCount, naVid, &pwsValue[0]);

	// 2. Event notification.
	eXGem->GEMSetEvent(1201+iTag);

	SECSHistoryData( "Manual Send Event  "+IntToStr(1201+iTag));
	delete [] pwsValue; pwsValue = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TFormSecsGemSet::SpeedButton4Click(TObject *Sender)
{
	long nCount = 2;
	long naVid[2];

	WideString* pwsValue = new WideString[2];

	naVid[0] = 2001; pwsValue[0] = StringGrid1->Cells[1][1];
	naVid[1] = 2006; pwsValue[1] = StringGrid1->Cells[1][2];

	// 1. Update variable
	eXGem->GEMSetVariable(nCount, naVid, &pwsValue[0]);

	// 2. Event notification.
	eXGem->GEMSetEvent(2004);

	SECSHistoryData( "Manual Send Event  2004");
	delete [] pwsValue; pwsValue = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TFormSecsGemSet::SpeedButton5Click(TObject *Sender)
{
	long nCount = 3;
	long naVid[3];

	WideString* pwsValue = new WideString[3];

	naVid[0] = 2001; pwsValue[0] = StringGrid1->Cells[1][1];
	naVid[1] = 2034; pwsValue[1] = StringGrid1->Cells[1][2];
	naVid[2] = 2035; pwsValue[2] = StringGrid1->Cells[1][3];

	// 1. Update variable
	eXGem->GEMSetVariable(nCount, naVid, &pwsValue[0]);

	// 2. Event notification.
	eXGem->GEMSetEvent(2021);

	SECSHistoryData( "Manual Send Event  2021");
	delete [] pwsValue; pwsValue = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TFormSecsGemSet::SpeedButton6Click(TObject *Sender)
{
	long nCount = 7;
	long naVid[7];

	WideString* pwsValue = new WideString[7];

	naVid[0] = 2001; pwsValue[0] = StringGrid1->Cells[1][1];
	naVid[1] = 2006; pwsValue[1] = StringGrid1->Cells[1][2];
	naVid[2] = 2004; pwsValue[2] = StringGrid1->Cells[1][3];
	naVid[3] = 2039; pwsValue[3] = StringGrid1->Cells[1][4];
	naVid[4] = 2066; pwsValue[4] = StringGrid1->Cells[1][5];
	naVid[5] = 2038; pwsValue[5] = StringGrid1->Cells[1][6];
	naVid[6] = 2013; pwsValue[6] = StringGrid1->Cells[1][7];

	// 1. Update variable
	eXGem->GEMSetVariable(nCount, naVid, &pwsValue[0]);

	// 2. Event notification.
	eXGem->GEMSetEvent(2101);

	SECSHistoryData( "Manual Send Event  2101");
	delete [] pwsValue; pwsValue = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TFormSecsGemSet::SpeedButton7Click(TObject *Sender)
{
	long nCount = 7;
	long naVid[7];

	WideString* pwsValue = new WideString[7];

	naVid[0] = 2001; pwsValue[0] = StringGrid1->Cells[1][1];
	naVid[1] = 2006; pwsValue[1] = StringGrid1->Cells[1][2];
	naVid[2] = 2004; pwsValue[2] = StringGrid1->Cells[1][3];
	naVid[3] = 2038; pwsValue[3] = StringGrid1->Cells[1][4];
	naVid[4] = 2046; pwsValue[4] = StringGrid1->Cells[1][5];
	naVid[5] = 2047; pwsValue[5] = StringGrid1->Cells[1][6];
	naVid[6] = 2024; pwsValue[6] = StringGrid1->Cells[1][7];

	// 1. Update variable
	eXGem->GEMSetVariable(nCount, naVid, &pwsValue[0]);

	// 2. Event notification.
	eXGem->GEMSetEvent(2114);

	SECSHistoryData( "Manual Send Event  2114");
	delete [] pwsValue; pwsValue = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TFormSecsGemSet::SpeedButton8Click(TObject *Sender)
{
	long nCount = 6;
	long naVid[6];

	WideString* pwsValue = new WideString[6];

	int iCeid = _wtoi(StringGrid1->Cells[1][1].w_str());
	naVid[0] = 2001; pwsValue[0] = StringGrid1->Cells[1][2];
	naVid[1] = 2006; pwsValue[1] = StringGrid1->Cells[1][3];
	naVid[2] = 2025; pwsValue[2] = StringGrid1->Cells[1][4];
	naVid[3] = 2024; pwsValue[3] = StringGrid1->Cells[1][5];
	naVid[4] = 2018; pwsValue[4] = StringGrid1->Cells[1][6];
	naVid[5] = 9000; pwsValue[5] = StringGrid1->Cells[1][7];

	// 1. Update variable
	eXGem->GEMSetVariable(nCount, naVid, &pwsValue[0]);

	// 2. Event notification.
	eXGem->GEMSetEvent(iCeid);

	SECSHistoryData( "Manual Send Event  "+IntToStr(iCeid));
	delete [] pwsValue; pwsValue = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TFormSecsGemSet::SpeedButton9Click(TObject *Sender)
{
	long nCount = 7;
	long naVid[7];

	WideString* pwsValue = new WideString[7];

	int iCeid = _wtoi(StringGrid1->Cells[1][1].w_str());
	naVid[0] = StringGrid1->Cells[2][2].ToIntDef(1000); pwsValue[0] = StringGrid1->Cells[1][2];
	naVid[1] = StringGrid1->Cells[2][3].ToIntDef(1000); pwsValue[1] = StringGrid1->Cells[1][3];
	naVid[2] = StringGrid1->Cells[2][4].ToIntDef(1000); pwsValue[2] = StringGrid1->Cells[1][4];
	naVid[3] = StringGrid1->Cells[2][5].ToIntDef(1000); pwsValue[3] = StringGrid1->Cells[1][5];
	naVid[4] = StringGrid1->Cells[2][6].ToIntDef(1000); pwsValue[4] = StringGrid1->Cells[1][6];
	naVid[5] = StringGrid1->Cells[2][7].ToIntDef(1000); pwsValue[5] = StringGrid1->Cells[1][7];
	naVid[6] = StringGrid1->Cells[2][8].ToIntDef(1000); pwsValue[6] = StringGrid1->Cells[1][8];

	// 1. Update variable
	eXGem->GEMSetVariable(nCount, naVid, &pwsValue[0]);

	// 2. Event notification.
	eXGem->GEMSetEvent(iCeid);

	SECSHistoryData( "Manual Send Event  "+IntToStr(iCeid));
	delete [] pwsValue; pwsValue = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TFormSecsGemSet::SpeedButton10Click(TObject *Sender)
{
	long nCount = 4;
	long naVid[4];

	WideString* pwsValue = new WideString[4];

	naVid[0] = 2001; pwsValue[0] = StringGrid1->Cells[1][1];
	naVid[1] = 2006; pwsValue[1] = StringGrid1->Cells[1][2];
	naVid[2] = 2004; pwsValue[2] = StringGrid1->Cells[1][3];
	naVid[3] = 2038; pwsValue[3] = StringGrid1->Cells[1][4];

	// 1. Update variable
	eXGem->GEMSetVariable(nCount, naVid, &pwsValue[0]);

	// 2. Event notification.
	long nReturn = eXGem->GEMSetEvent(2115);

	SECSHistoryData( "Manual Send Event  2115");
	delete [] pwsValue; pwsValue = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TFormSecsGemSet::SpeedButton11Click(TObject *Sender)
{
	long nCount = 4;
	long naVid[4];

	WideString* pwsValue = new WideString[4];

	naVid[0] = 2001; pwsValue[0] = StringGrid1->Cells[1][1];
	naVid[1] = 2006; pwsValue[1] = StringGrid1->Cells[1][2];
	naVid[2] = 2067; pwsValue[2] = StringGrid1->Cells[1][3];
	naVid[3] = 2038; pwsValue[3] = StringGrid1->Cells[1][4];

	// 1. Update variable
	eXGem->GEMSetVariable(nCount, naVid, &pwsValue[0]);

	// 2. Event notification.
	long nReturn = eXGem->GEMSetEvent(2116);

	SECSHistoryData( "Manual Send Event  2116");
	delete [] pwsValue; pwsValue = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TFormSecsGemSet::SpeedButton12Click(TObject *Sender)
{
	long nCount = 4;
	long naVid[4];

	WideString* pwsValue = new WideString[4];

	naVid[0] = 2001; pwsValue[0] = StringGrid1->Cells[1][1];
	naVid[1] = 2006; pwsValue[1] = StringGrid1->Cells[1][2];
	naVid[2] = 2012; pwsValue[2] = StringGrid1->Cells[1][3];
	naVid[3] = 2004; pwsValue[3] = StringGrid1->Cells[1][4];

	// 1. Update variable
	eXGem->GEMSetVariable(nCount, naVid, &pwsValue[0]);

	// 2. Event notification.
	long nReturn = eXGem->GEMSetEvent(2005);

	SECSHistoryData( "Manual Send Event  2005");
	delete [] pwsValue; pwsValue = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TFormSecsGemSet::Button5Click(TObject *Sender)
{
	LOT_INFO info = g_MMIComm->m_mmiToSeq.buffer.lotInfo;

	bool bRtn = false;
	long nCount = 4;
	long naVid[4];

	WideString* pwsValue = new WideString[4];

	naVid[0] = 2001; pwsValue[0] = MainForm->_eqpID;
	naVid[1] = 2006; pwsValue[1] = String(info.mergeLotID);

	String sCarrierID = String(info.carrierID);
	naVid[2] = 2012; pwsValue[2] = String(info.carrierID);

	naVid[3] = 2004; pwsValue[3] = _StrOpid;

	// 1. Update variable
	eXGem->GEMSetVariable(nCount, naVid, &pwsValue[0]);

	// 2. Event notification.
	long nReturn = eXGem->GEMSetEvent(2005);

	SECSHistoryData( "Manual Send Event  2005 - button");

	int b = 0;
}
//---------------------------------------------------------------------------

void __fastcall TFormSecsGemSet::ReqTimeClick(TObject *Sender)
{
   int reqTime = FEcmrTime->Text.ToInt(); 	// 1 ~ 30분까지 입력
   int realTime = reqTime * 60000;

   if(reqTime > 0 && reqTime < 31)
   {
		nWriteCommunicationDM(realTime,stateReqTime);
		MainForm->MachineHistoryData("[ REQ TIME SET ] reqTime = " + IntToStr(reqTime) + " realTime = " + IntToStr(realTime));
   }
   else
   {
		realTime = 10 * 60000;			   // default 시간 : 10분
		nWriteCommunicationDM(realTime,stateReqTime);
		MainForm->MachineHistoryData("[ DEFAULT REQ TIME SET ] reqTime = " + IntToStr(reqTime) + " realTime = " + IntToStr(realTime));
   }
}
//---------------------------------------------------------------------------

