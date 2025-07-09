//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SecsSetupScrn.h"
#include "TerminalMessage.h"
#include "Main.h"
#include <stdio.h>
#include "HostMessageScrn.h"
#include "Infovider.h"
#include "Communication.h"
#include "cdbox.h"
#include "LotInputScrn.h"
#include "JobProcessingScrn.h"
#include "LaserSetUpScrn.h"
#include "LotRcvShowScrn.h"
#include "RFIDProceeding.h"
#include "PMSScrn.h"
#include "FDCAlarmScrn.h"
#include "PKGParamScrn.h"
#include "SelectiveControlScrn.h"
#include "VisionSetUpScrn.h"
//---------------------------------------------------------------------------
#include "SQLite\cppsqlite3.h"
#include <ctime>
#include <iostream>
#include <DateUtils.hpp>

//---------------------------------------------------------------------------
#include "BaseProcess.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "LMDButton"
#pragma link "LMDCustomButton"
#pragma link "EXGEMLib_OCX"
#pragma resource "*.dfm"
TFrmSecsSetUp *FrmSecsSetUp;

using namespace std;
#define 	_unitXcnt_    4
#define 	_unitYcnt_    3
#define 	_blockCnt_    5
#define Process_RUN_STATE_                 1
#define Process_MANUAL_STATE_              2
#define Process_ERROR_STATE_               3
#define Process_STOP_STATE_                4


#define     _Laser1_Drill_Start_End_     70
#define     _Laser2_Drill_Start_End_     71
#define     _Laser3_Drill_Start_End_     72
#define     _Laser4_Drill_Start_End_     73

#define     _Laser_Drill_Start_               1
#define     _Laser_Drill_End_                 3
#define     _Laser_Drill_CommonResponse_      2
#define     _Laser_Drill_Idle                 0
#define     _MGZ_LOT_VAL_ 					170

//---------------------------------------------------------------------------
__fastcall TFrmSecsSetUp::TFrmSecsSetUp(TComponent* Owner)
	: TForm(Owner)
{
	bCommChk = false;
	m_fStart = false;
	m_bTrackoutException = false;
	nSecsProcessState = 0;
	nSecsPrevProcessState = 0;
	nSecsCommState = 0;
	nSecsPrevControlState = 0;
	nSecsControlState = 0;
	bOHTLoaderCall  = false;
	bOHTUnloaderCall = false;
    MarkingSpecRequest->Enabled = false;  // marking // 151015
}
//---------------------------------------------------------------------------

WideString TFrmSecsSetUp::GetWideString2AnsiString(AnsiString data)
{
	WideString wsData;
	wsData = data;
	return wsData;
}
//---------------------------------------------------------------------------
void __fastcall TFrmSecsSetUp::SecsMemoLogChange(TObject *Sender)
{
	SendMessage(SecsMemoLog->Handle, WM_VSCROLL, SB_BOTTOM, 0);
}
//---------------------------------------------------------------------------

void __fastcall TFrmSecsSetUp::SECSHistoryData(String StrTemp)
{
	SecsMemoLog->Lines->Add(DateTimeToStr(Now()) + ": " + StrTemp);
	SecsMemoLog->Refresh();

	if(SecsMemoLog->Lines->Count > 1000)
	{
		TDateTime dt = Now();
		String FolderName = dt.FormatString("yyyy-mm-dd");
		String FileName = dt.FormatString("yyyy-mm-dd hh-nn-ss");
		String FullPath  =  "C:\\KOSES\\History\\SECSHistory\\"+ FolderName +"\\";
		ForceDirectories(FullPath);

		SecsMemoLog->Lines->SaveToFile(FullPath + FileName+".txt");

		SecsMemoLog->Clear();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmSecsSetUp::SecsInitializeProcess()
{
	long		nReturn = 0;
	char        szMsg[256];
	AnsiString	sCfg;

	WideString wStrPath = ExtractFilePath(Application->ExeName)+ "\\Ini\\XGEM.cfg";
	int nRetcode =  EXGem->Initialize(wStrPath.c_bstr());

	if(nRetcode == 0 )
	{
		SECSHistoryData("XGem initialized successfully");
		BtnSecsCommStart->Enabled = true;
		SecsGemAutoStartProcess();
	}
    else
    {
		sprintf( szMsg, "Fail to initialize XGem (%d)", nReturn );
        SECSHistoryData(szMsg);
    }
}
//---------------------------------------------------------------------------
void __fastcall TFrmSecsSetUp::SecsStartProcess()
{
	long		nReturn = 0;
	char        szMsg[256];

    if( (nReturn = EXGem->Start()) == 0 )
    {
        SECSHistoryData( "XGem started successfully" );
        SecsParamUpdate->Enabled = true;
		BtnSecsCommStart->Enabled = false;
		BtnSecsCommStop->Enabled = true;
        GroupboxSecsControl->Enabled = true;
        MarkingSpecRequest->Enabled  = true;
    }
    else
    {
        sprintf( szMsg, "Fail to start XGem (%d)", nReturn );
        SECSHistoryData( szMsg );
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmSecsSetUp::BtnSecsCommStartClick(TObject *Sender)
{
    SecsStartProcess();
}
//---------------------------------------------------------------------------
void __fastcall TFrmSecsSetUp::SecsCloseProcess()
{
	long	    nReturn = 0;
	char        szMsg[256];

    if( (nReturn = EXGem->Close()) == 0 )
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
void __fastcall TFrmSecsSetUp::BtnSecsCommStopClick(TObject *Sender)
{
	long	    nReturn = 0;
	char        szMsg[256];

	if( (nReturn = EXGem->Stop()) == 0 )
	{
		SECSHistoryData( "XGem stopped successfully" );
        SecsParamUpdate->Enabled = false;
        BtnSecsCommStart->Enabled = true;
		BtnSecsCommStop->Enabled = false;
        GroupboxSecsControl->Enabled = false;
    }
    else
    {
        sprintf( szMsg, "Fail to stop XGem (%d)", nReturn );
        SECSHistoryData( szMsg );
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmSecsSetUp::BtnCommEnableClick(TObject *Sender)
{
	Secs_CommEnableProcess();
}
//---------------------------------------------------------------------------

void __fastcall TFrmSecsSetUp::Secs_CommEnableProcess()
{
	long	    nReturn = 0;
	char        szMsg[256];

	if(bCommChk ==false)
	{
		//Argument : bState value(0: disable, 1: enable)
		nReturn = EXGem->GEMSetEstablish(1);
	}
	else
	{
		//Argument : bState value(0: disable, 1: enable)
		nReturn = EXGem->GEMSetEstablish(0);
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

void __fastcall TFrmSecsSetUp::BtnOfflineClick(TObject *Sender)
{
	long	    nReturn = 0;
	char        szMsg[256];

	//Argument : None
	nReturn = EXGem->GEMReqOffline();
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

void __fastcall TFrmSecsSetUp::BtnOnlineLocalClick(TObject *Sender)
{
	long	    nReturn = 0;
	char        szMsg[256];

	//Argument : None
	nReturn = EXGem->GEMReqLocal();
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

void __fastcall TFrmSecsSetUp::BtnOnlineRemoteClick(TObject *Sender)
{
    Secs_OnlineRemoteProcess();
}
//---------------------------------------------------------------------------

void __fastcall TFrmSecsSetUp::Secs_OnlineRemoteProcess()
{
	long	    nReturn = 0;
	char        szMsg[256];

    //Argument : None
    nReturn = EXGem->GEMReqRemote();
	if( nReturn == 0 )
    {
        SECSHistoryData( "Send GEMReqRemote successfully" );
    }
    else
	{
		sprintf( szMsg, "Fail to GEMReqRemote (%d)", nReturn );
        SECSHistoryData( szMsg );
	}

	FrmLaserSetUp->RetrylaserRecipeCall();
}
//---------------------------------------------------------------------------

void __fastcall TFrmSecsSetUp::SecsRunProcessingStatus(int nStatus)
{
	long  nVid = 0;
	int nReturn;
	char        szMsg[256];
	String StrPrevStatus = EditGemState->Text;

	if(nStatus == Processing_Stop)
	{
		EditGemState->Text =  "Machine Stop";
		nSecsProcessState = Process_STOP_STATE_ ;
	}
	else if(nStatus == Processing_Run)
	{
		EditGemState->Text =  "Machine Run";
		nSecsProcessState = Process_RUN_STATE_ ;
	}
	else if(nStatus == Processing_Error)
	{
		EditGemState->Text =  "Machine Error";
		nSecsProcessState = Process_ERROR_STATE_ ;
	}
	else
	{
		EditGemState->Text =  "Machine Idle";
		nSecsProcessState = Process_MANUAL_STATE_ ;
	}
	nVid = 2004;  // Process State SVID
	EXGem->GEMSetVariable(1, &nVid, &WideString(nSecsProcessState));

	nVid = 2005;  // Previous Process State SVID
	EXGem->GEMSetVariable(1, &nVid, &WideString(nSecsPrevProcessState));

	SECSHistoryData("Process State Change : " +IntToStr(nSecsPrevProcessState)+ " -> " + IntToStr(nSecsProcessState));

	nReturn = EXGem->GEMSetEvent(1116);
	if( nReturn == 0 )
	{
		SECSHistoryData( "Processing Status Change" + StrPrevStatus + "->"+  EditGemState->Text);
		SECSHistoryData( "Send GEMSetEvent successfully" );
	}
	else
	{
		sprintf(szMsg, "Fail to GEMSetEvent (%d)", nReturn );
		SECSHistoryData( szMsg );
	}
	nSecsPrevProcessState = nSecsProcessState;
}
//---------------------------------------------------------------------------
void __fastcall TFrmSecsSetUp::EXGemeGEMCommStateChanged(TObject *Sender,
      long nState)
{
	char        szMsg[256];
	char	    szState[64];

	if (nState == Comm_None)
    {
		m_fStart = false;
        strcpy(szState, "None");
	}
	else if (nState == Comm_Disabled)
	{
		m_fStart = false;
        strcpy(szState, "Disabled");
    }

	else if(nState == Comm_WaitCRFromHost)
    {
		m_fStart = false;
        strcpy(szState, "Wait CR From Host");
	}

	else if(nState == Comm_WaitDelay)
	{
        m_fStart = false;
        strcpy(szState, "Wait Delay");
    }

	else if(nState == Comm_WaitCRA)
    {
		m_fStart = false;
        strcpy(szState, "Wait CRA");
    }

	else if(nState == Comm_Communicating)
	{
		m_fStart = true;
		strcpy(szState, "Communicating");
		FrmMain->FileSendTimer->Enabled = true;
		TMOnlineRemote->Enabled =true;
	}

	else if(nState == Comm_Enabled)
	{
		m_fStart = true;
		strcpy(szState, "Enabled");
    }
	EditCommState->Text = szState;
    if(m_fStart != FrmMain->LEDSECSComm->Active)
	{
        FrmMain->LEDSECSComm->Active =  m_fStart;
        if(m_fStart == true)
        {
            FrmMain->LEDSECSComm->CenterLabelText = "GEM COMMUNICATING";
		}
        else
        {
            FrmMain->LEDSECSComm->CenterLabelText = "GEM NOT COMMUNICATING";
        }
    }
	sprintf( szMsg, "Received %s, %s", "GEMCommStateChanged", szState );
    SECSHistoryData( szMsg );
}
//---------------------------------------------------------------------------
void __fastcall TFrmSecsSetUp::EXGemeGEMSpoolStateChanged(TObject *Sender,
      long nState, long nLoadState, long nUnloadState, BSTR sFullTime,
      long nMaxTransmit, long nMsgNum, long nTotalNum, long nTransmitFail)
{
	char        szMsg[256];
	char	    szState[64];

//
//    nState
//    long
//    	0:INACTIVE
//    	1:ACTIVE
//    nLoadState
//    long
//    	0:LD NOTFULL
//    	1:LD FULL
//    nUnloadState
//    long
//    	0:NO OUTPUT
//    	1:TRANSMIT
//    	2:PURGE

	if (nState == 0)
	{
		strcpy(szState, "InActive");
	}
	else if(nState == 1)
	{
		strcpy(szState, "Active");

		if(nLoadState == 0)
		{
			strcat(szState, "/Not Full");
		}
		else if(nLoadState == 1)
		{
			strcat(szState, "/Full");
		}

		if(nUnloadState == 0)
		{
			strcat(szState, "/No Output");
		}
		else if(nUnloadState == 1)
		{
			strcat(szState, "/Transmit");
		}
		else if(nUnloadState == 2)
		{
			strcat(szState, "/Purge");
		}

	}

	EditSpoolState->Text = szState;

	sprintf( szMsg, "Received %s, %s", "GEMSpoolStateChanged", szState );
	SECSHistoryData( szMsg );
}
//---------------------------------------------------------------------------
void __fastcall TFrmSecsSetUp::TMOnlineRemoteTimer(TObject *Sender)
{
	TMOnlineRemote->Enabled =false;
	Secs_OnlineRemoteProcess();
}
//---------------------------------------------------------------------------

	/*Control_None = -1,
	Control_EqOffline = 1,
	Control_AttemptOnline,
	Control_HostOffline,
	Control_Local,
	Control_Remote*/

void __fastcall TFrmSecsSetUp::EXGemeGEMControlStateChanged(
	  TObject *Sender, long nState)
{
	char        szMsg[256];
	char	    szState[64];

	if (nState == Control_EqOffline)
	{
		strcpy(szState, "OffLine");
	}
	else if(nState == Control_AttemptOnline)
	{
		strcpy(szState, "Attempt OnLine");
	}
	else if(nState == Control_HostOffline)
	{
		strcpy(szState, "Host OffLine");
	}
	else if(nState == Control_Local)
	{
		strcpy(szState, "Online-Local");
	}
	else if(nState == Control_Remote)
	{
		strcpy(szState, "Online-Remote");
	}
	else
	{
		strcpy(szState, "Control_None");
	}
	EditCtrlState->Text = szState;

	sprintf( szMsg, "Received %s, %s", "GEMControlStateChanged", szState );
	SECSHistoryData( szMsg );
}
//---------------------------------------------------------------------------

void __fastcall TFrmSecsSetUp::EXGemeGEMErrorEvent(TObject *Sender,
	  long nState)
{
	char    szMsg[256];

	sprintf( szMsg, "Received %s, Error Code = %d", "GEMErrorEvent", nState );
	SECSHistoryData( szMsg );
}
//---------------------------------------------------------------------------


void __fastcall TFrmSecsSetUp::EXGemeXGEMStateEvent(TObject *Sender,
	  long nState)
{
	if (nState == XGemState_Execute)
	{
		//bEnable : 0(Disabled), 1(Enabled)
		EXGem->GEMSetEstablish(1);
		EXGem->GEMEQInitialized(1);
	}
	else
	{
		//SECSHistoryData(IntToStr(nState));
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmSecsSetUp::EXGemeSECSMessageReceived(TObject *Sender,
	  long nObjectID, long nStream, long nFunction, long nSysbyte)
{
	char szMsg[256] = {0, };

	short   nU1;
	long    nItems, lU2, lCnt;
//	WideString sAscii;
	long lSize;
	BSTR bstr;

	if((nStream == 14) && (nFunction == 2))			// S14F2 - User Define Message
	{
		String strTempMapData, strMapData, strStripID,strLotId;
		short nBinaryArray[300] = {0, };

		g_nRowCnt = 0;
		g_nColCnt = 0;
		g_nTotalCnt = 0;

		EXGem->GetList(nObjectID, &nItems);			// L 2
			EXGem->GetList(nObjectID, &nItems);		// L 1
				EXGem->GetList(nObjectID, &nItems);	// L 2
//					GetAsciiFunc(nObjectID, sAscii, lSize);
					EXGem->GetAscii(nObjectID, &bstr, &lSize); //OBJID
//					strStripID = sAscii;
					strStripID = String(bstr);


					EXGem->GetList(nObjectID, &nItems);		// L 6
						EXGem->GetList(nObjectID, &nItems);	   	// L 2 OriginLocation List
//							GetAsciiFunc(nObjectID, sAscii, lSize);
							EXGem->GetAscii(nObjectID, &bstr, &lSize);		// Attr ID
							EXGem->GetU1(nObjectID, &nU1, &lCnt, 1);		// Attr DATA
						EXGem->GetList(nObjectID, &nItems);     // L 2Rows List
//							GetAsciiFunc(nObjectID, sAscii, lSize);
							EXGem->GetAscii(nObjectID, &bstr, &lSize);    	// Attr ID
							EXGem->GetU2(nObjectID, &lU2, &lCnt, 1);		// Attr DATA
							g_nColCnt = lU2;

						EXGem->GetList(nObjectID, &nItems);		// L 2 Columns List
//							GetAsciiFunc(nObjectID, sAscii, lSize);
							EXGem->GetAscii(nObjectID, &bstr, &lSize);    // Attr ID
							EXGem->GetU2(nObjectID, &lU2, &lCnt, 1);	// Attr DATA
							g_nRowCnt = lU2;
							g_nTotalCnt = g_nColCnt * g_nRowCnt;

						EXGem->GetList(nObjectID, &nItems);   	// L 2 CellStatus List
//							GetAsciiFunc(nObjectID, sAscii, lSize);
							EXGem->GetAscii(nObjectID, &bstr, &lSize);	// Atrr ID
							EXGem->GetBinary(nObjectID, &nBinaryArray[0], &lCnt, 300);	// Attr DATA

						int nGroupCnt = 0;
						int nColCnt = 0;
						int nRowCnt = 0;
						MMIComm->m_mmiToSeq.cmdType = CMD_RD_PKG_DATA;
						if ( MMIComm->Send() &&  MMIComm->Recv())
						{
							nGroupCnt = MMIComm->m_mmiToSeq.bufferData.pkgData.data[_blockCnt_];
							nColCnt = MMIComm->m_mmiToSeq.bufferData.pkgData.data[_unitYcnt_];
							nRowCnt = MMIComm->m_mmiToSeq.bufferData.pkgData.data[_unitXcnt_];
						}
						long UintChk =nGroupCnt*nColCnt*nRowCnt;


						if (  g_nTotalCnt !=  lCnt)
						{
							ShowMessage("UNIT Total Count가 올바르지 않습니다.");
							EXGem->CloseObject(nObjectID);
							return;
						}
						else if (  g_nTotalCnt !=  UintChk)
						{
							ShowMessage("UNIT Total Count가 올바르지 않습니다.");
							EXGem->CloseObject(nObjectID);
							return;
						}


						EXGem->GetList(nObjectID, &nItems);		// L 2 나머지 List
//							GetAsciiFunc(nObjectID, sAscii, lSize);
//							GetAsciiFunc(nObjectID, sAscii, lSize);
							EXGem->GetAscii(nObjectID, &bstr, &lSize);
							EXGem->GetAscii(nObjectID, &bstr, &lSize);
							strLotId = String(bstr);
						EXGem->GetList(nObjectID, &nItems);		// L 2 나머지 List
//							GetAsciiFunc(nObjectID, sAscii, lSize);
//							GetAsciiFunc(nObjectID, sAscii, lSize);
							EXGem->GetAscii(nObjectID, &bstr, &lSize);
							EXGem->GetAscii(nObjectID, &bstr, &lSize);

			EXGem->GetList(nObjectID, &nItems);  	// L 2
				EXGem->GetU1(nObjectID, &nU1, &lCnt, 1);
				EXGem->GetList(nObjectID, &nItems);	// L 0
			EXGem->CloseObject(nObjectID);

		int nRFIDTRinval = ReadCommunicationDM(50); // 171 //INRIAL STRIP
		bool bLotCodChk = true;
		String StrLotRfidMem;
		TIniFile *RFIDMemIni = new TIniFile(ExtractFilePath(Application->ExeName) + "\\ini\\RFIDMem" + IntToStr(nRFIDTRinval) + ".ini");
		if(FileExists(ExtractFilePath(Application->ExeName) + "\\ini\\RFIDMem" + IntToStr(nRFIDTRinval) + ".ini"))
		{
				StrLotRfidMem = RFIDMemIni->ReadString("RFID READ","LOTID","0");
				bLotCodChk = PmsLotChkPopUp(strLotId,StrLotRfidMem);
		}
		else
		{
			SECSHistoryData("LOT CODE 정보 없음!");
			WriteCommunicationDM(4, _DM_PMS_READ_SIGNAL_);
			bLotCodChk = false;
		}
		delete RFIDMemIni;


			for(int nTemp = 0; nTemp < g_nTotalCnt; nTemp++)
			{
				strTempMapData += IntToStr(nBinaryArray[nTemp]);
			}

			SECSHistoryData("Map ID : " + strStripID + ", Recieve PMS Map Data : " + strTempMapData);
			FrmPMSScrn->PMSHistoryData("Map ID : " + strStripID + ", Recieve PMS Map Data : " + strTempMapData);
			strMapData = PMSMapDataParse(g_nColCnt, g_nRowCnt, strTempMapData);

			if(strMapData != "")
			{
				FrmPMSScrn->PMSIDDataProcess(strStripID, strMapData);
			}
	}

	sprintf( szMsg, "message received (S%dF%d) & Object ID %d", nStream, nFunction, nObjectID);
	SECSHistoryData( szMsg );
}
//---------------------------------------------------------------------------

void __fastcall TFrmSecsSetUp::EXGemeGEMReqRemoteCommand(TObject *Sender,
	  long nMsgId, BSTR sRcmd, long nCount, PWideString1 psNames,
	  PWideString1 psVals)
{
	int nRetVal;
	nRetVal = (int)ReadCommunicationDM(_TRACK_IN_DM_INDEX);

	String strLotLogLotID,strLotLogPartCode;
	TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini");
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini"))
	{
		strLotLogPartCode= ini->ReadString("LotDataSet"+IntToStr(nRetVal),"PartCode"," ");
		strLotLogLotID= ini->ReadString("LotDataSet"+IntToStr(nRetVal),"LotCode"," ");
	}
	delete ini;

	String StrMZID;
	TIniFile *RFini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\RFIDMem"+IntToStr(nRetVal)+".ini");
	StrMZID = RFini->ReadString("RFID READ","MZNO","1");
	delete RFini;



	char szMsg[256];
	AnsiString sName, sValue;
	long nHCAck = 0;
	long *pnResult = new long[nCount];
	for(int i = 0; i < nCount; i++)
	{
		pnResult[i] = 0;
	}

	try
	{
		String sRcmd2 = WideString(sRcmd);

		sprintf(szMsg, "Received %s, MsgId = %d, Rcmd = %s, Count = %d", "GEMReqRemoteCommand", nMsgId, sRcmd2.c_str(), nCount );
		SECSHistoryData( szMsg );

		if(sRcmd2 == "START_AR")
		{
			//
			String strValue1;
			String strValue2;

			for(int i = 0; i < nCount; i++)
			{
				sName = psNames[i];
				sValue = psVals[i];
				sprintf(szMsg,"    Name: %s, Value: %s", sName.c_str(), sValue.c_str());
				SECSHistoryData( szMsg );
				StrRecvLotQty = psVals[0]; //전산 COUNNTT;
				strValue1 = psVals[1];
				strValue2 = psVals[2];
			}
			StartARSuccess();
			StartArPartData(strValue1,strValue2);
			int nRecipeNumber;
			nRecipeNumber = (int)ReadCommunicationDM(3);

			String strRecipeNumber = IntToStr((FrmMain->nGlobal_GrpNo*1000)+(nRecipeNumber));

			if(FrmMain->b_TpConnect)
			{
//				g_TpBase.logLot("LOT_Track_In","Start",strLotLogLotID.c_str(),FrmMain->g_strCurrentRecipeName.c_str(),StrMZID.c_str(),"","","","","","");
				g_TpBase.logLot("LOADER","TrackIn",strLotLogLotID.c_str(),FrmMain->g_strCurrentRecipeName.c_str(),StrMZID.c_str(),"'RECIPE NUMBER'",strRecipeNumber.c_str(),"'LOT NUMBER'",IntToStr(nRetVal).c_str(),"'MZ NUMBER'",IntToStr(nRetVal).c_str(),"MMI_SW_VERSION","KOSES HANDLER SYSTEM 2.1.3.0");
				//g_TpBase.logLot("LOADER","TrackIn","$","$","$","KOSES MMI Ver.",FrmMain->LabelAppInfo->Caption.c_str());

			}

		}

		if(sRcmd2 == "PASS")
		{
			for(int i = 0; i < nCount; i++)
			{
				sName = psNames[i];
				sValue = psVals[i];
				sprintf(szMsg,"    Name: %s, Value: %s", sName.c_str(), sValue.c_str());
				SECSHistoryData( szMsg );

				if(sName == "PMSRESULT") 				// PMS use/skip 을 S2F41 Message로 받음
				{
					if(sValue == "OK")
					{
						MMIComm->m_mmiToSeq.cmdType = CMD_RD_USESKIP;
						if(MMIComm->Send() && MMIComm->Recv())
						{
							if(MMIComm->m_mmiToSeq.bufferData.useSkip.data[_USESKIP_PMS_ - 1] == false)
							{
								MMIComm->m_mmiToSeq.bufferData.useSkip.data[_USESKIP_PMS_ - 1] = true;
								MMIComm->m_mmiToSeq.cmdType = CMD_WR_USESKIP;
								if(MMIComm->Send() && MMIComm->Recv())
								{
									FrmSelectiveControl->UseSkipHistory("[PMS USE/SKIP] changed - SECS/GEM Received PMS Skip -> Use.");
								}
							}
						}
					}
					else if(sValue == "NG")
					{
						MMIComm->m_mmiToSeq.cmdType = CMD_RD_USESKIP;
						if(MMIComm->Send() && MMIComm->Recv())
						{
							if(MMIComm->m_mmiToSeq.bufferData.useSkip.data[_USESKIP_PMS_ - 1] == true)
							{
								MMIComm->m_mmiToSeq.bufferData.useSkip.data[_USESKIP_PMS_ - 1] = false;
								MMIComm->m_mmiToSeq.cmdType = CMD_WR_USESKIP;
								if(MMIComm->Send() && MMIComm->Recv())
								{
									FrmSelectiveControl->UseSkipHistory("[PMS USE/SKIP] changed - SECS/GEM Received PMS Use -> Skip.");
								}
							}
						}
					}
				}
			}
		}

		if(sRcmd2 == "TK_RESULT")
		{
			for(int i = 0; i < nCount; i++)
			{
				sName = psNames[i];
				sValue = psVals[i];
				sprintf(szMsg,"    Name: %s, Value: %s", sName.c_str(), sValue.c_str());
				SECSHistoryData( szMsg );

				if(sName  == "TRACKIN")
				{
					if(sValue == "OK")
					{
						SECSHistoryData("SecsTrackInProcess: Trackin Success!");
						FrmMain->TrackInMessageView("TRACK IN 성공");

					}
					else if(sValue == "NG")
					{
						WriteCommunicationDM(4, _TRACK_IN_DM_);
						SECSHistoryData( "TK_RESULT _ TRACKIN _ NG");
						FrmMain->TrackInMessageView("TRACK IN 실패");
						if(FrmMain->b_TpConnect)
						{
//							g_TpBase.logLot("LOT_Track_In","Cancel",strLotLogLotID.c_str(),FrmMain->g_strCurrentRecipeName.c_str(),StrMZID.c_str(),"","","","","","");
							g_TpBase.logLot("LOADER","TrackIn_Cancel",strLotLogLotID.c_str(),FrmMain->g_strCurrentRecipeName.c_str(),StrMZID.c_str());
						}

					}
				}

				else if(sName  == "TRACKOUT")
				{
					if(sValue == "OK")
					{
						FrmRFIDProceeding->TrackOutInfoManage();
						FrmMain->TrackOutDBDataProcess();
						SECSHistoryData("SecsTrackOutProcess:TrackOut Success!");
/*						if(FrmMain->b_TpConnect)
						{
//							g_TpBase.logLot("LOT_Track_Out","End",strLotLogLotID.c_str(),FrmMain->g_strCurrentRecipeName.c_str(),StrMZID.c_str(),"","","","","","");
							g_TpBase.logLot("UNLOADER","TrackOut",strLotLogLotID.c_str(),FrmMain->g_strCurrentRecipeName.c_str(),StrMZID.c_str());
						}
*/					}
					else if(sValue == "NG")
					{

						WriteCommunicationDM(3, _TRACK_OUT_DM_);
						SECSHistoryData("SecsTrackOutProcess:TrackOut Failure!");
					}
				}

				if(sName == "OHT_CALL")
				{
					if(sValue == "OK")
					{
						SECSHistoryData("SecsManualOHTProcess: Manual OHT Call Success!");
						FrmMain->TrackInMessageView("Manual OHT 성공");

						FrmMain->OHTTitleLabel->Caption = "Manual OHT 에 성공하였습니다";
						FrmMain->ManualOHTConfirmPanel->Visible = true;
						FrmMain->ManualOHTConfirmPanel->Left = 460;
						FrmMain->ManualOHTConfirmMsgTimer->Enabled = true;
					}
					else if(sValue == "NG")
					{
						SECSHistoryData("SecsManunalOHTProcess: Manual OHT Call Fail!");
						FrmMain->TrackInMessageView("Manual OHT 실패");
					}
				}

				if(sName == "EQPSTOP")
				{
					if(sValue == "OK")
					{
						WriteCommunicationFlag(1, _FLAG_FDC_STOP_);

						if(FrmFDCAlarm->Showing == false)
						{
							FrmFDCAlarm->BringToFront();
							FrmFDCAlarm->ShowModal();
						}
					}
				}
			}
		}

		if(sRcmd2 == "MKSPEC_AR") //20151012 Add the RCMD for the  LASER Complex Machine
		{
						bool bMK_SpecDn = true;
			for(int i = 0; i < nCount; i++)
			{
				sName = psNames[i];
				sValue = psVals[i];

				sprintf(szMsg,"    Name: %s, Value: %s", sName.c_str(), sValue.c_str());
				SECSHistoryData( szMsg );

				//m_strMK_LotCode , m_strMK_WeekCode , m_strMK_LDPMode
				SECSHistoryData("MKSPEC_AR");

				if(sName == "WEEKCODE")
				{
					m_strMK_WeekCode =  sValue;
					SECSHistoryData("MKSPEC_AR -> : WEEKCODE -> " + sValue);
										if(m_strMK_WeekCode == "")
										{
										bMK_SpecDn = false;
										}
				}

				if(sName == "LDP_MODE")
				{
					//m_strMK_LDPMode = sValue;
					SECSHistoryData("MKSPEC_AR -> : LDP_MODE -> " + sValue);
										if(m_strMK_LDPMode == "")
										{
										bMK_SpecDn = false;
										}
				}
				if(sName == "RECIPEID")
				{
										String strValueMk;
					strValueMk =sValue.SubString(sValue.Length()-1,1);
					SECSHistoryData("MKSPEC_AR -> : RECIPEID -> " + sValue);
										/*if(strValueMk != "T" && strValueMk != "0" && strValueMk != "M")
										{
										bMK_SpecDn = false;
										} */
										if(strValueMk == "T")
										{
											m_strMK_LDPMode = "DRILL_MK";
										}
										else if(strValueMk == "0")
										{
											m_strMK_LDPMode ="DRILL";
										}
										else if(strValueMk == "M")
										{
											m_strMK_LDPMode ="MK";
										}
										else
										{
											bMK_SpecDn = false;
										}

				}


			}
						if(bMK_SpecDn == false)
						{
							WriteCommunicationDM(2 , _MARKING_SPEC_REQUEST_DM_);
								SECSHistoryData("MKSPEC_AR -> _MARKING_SPEC_REQUEST_DM_ -> FALSE");

						}
						else
						{
							 WriteCommunicationDM(0 , _MARKING_SPEC_REQUEST_DM_);
							SECSHistoryData("MKSPEC_AR -> _MARKING_SPEC_REQUEST_DM_ -> Success");

							MarkingSpecDataSave(m_strMK_WeekCode , m_strMK_LDPMode);
							FrmLaserSetUp->LaserMarkingTrigger->Enabled = true;
							FrmVisionSetUp->MarkingSpecVisTime->Enabled = true;

							int nLdMZ_No = ReadCommunicationDM(170);
							int nLDP_MODE = 0;
							int QRGEM_MODE = 0;
							if(m_strMK_LDPMode=="DRILL")
							{
									SECSHistoryData("MKSPEC_AR -> : RECIPEID(MK_MODE) -> DRILL");
									nLDP_MODE = 1;
									QRGEM_MODE =2;
							}
							else if(m_strMK_LDPMode=="MK")
							{
									SECSHistoryData("MKSPEC_AR -> : RECIPEID(MK_MODE) -> MARKING");
									nLDP_MODE = 2;
									QRGEM_MODE = 3;
							}
							else if(m_strMK_LDPMode=="DRILL_MK")
							{
									SECSHistoryData("MKSPEC_AR -> : RECIPEID(MK_MODE) -> DRILL_MARKING");
									nLDP_MODE = 3;
									QRGEM_MODE= 1;
							}
							long nVid = 2450;
							int nCount = 1;
							EXGem->GEMSetVariable(nCount, &nVid, &WideString(QRGEM_MODE));

							WriteCommunicationDM(nLDP_MODE,nLdMZ_No+489);
						}
		}

		EXGem->GEMRspRemoteCommand(nMsgId, sRcmd, nHCAck, nCount, pnResult);

	}
	catch(Exception& e)
	{
		SECSHistoryData( e.Message);
	}
	delete [] pnResult;

}
//---------------------------------------------------------------------------
void __fastcall TFrmSecsSetUp::MarkingSpecDataSave(AnsiString StrWeekCode ,AnsiString StrLDPMode)
{
	int nRetVal;
	nRetVal = (int)ReadCommunicationDM(170);

	SECSHistoryData("MarkingSpecDataSave -> LDPMODE : " + StrLDPMode + "[" +IntToStr(nRetVal)+"]" );

	TIniFile *RFIDMemIni = new TIniFile(ExtractFilePath(Application->ExeName) + "\\ini\\RFIDMem" + IntToStr(nRetVal) + ".ini");
	if(FileExists(ExtractFilePath(Application->ExeName) + "\\ini\\RFIDMem" + IntToStr(nRetVal) + ".ini"))
	{
		RFIDMemIni->WriteString("MarkingSpec","LDPMode",StrLDPMode.Trim());
	}
	delete RFIDMemIni;



	TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\MarkingSpecData.ini");
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\MarkingSpecData.ini"))
	{
		ini->WriteString("MarkingSpec","WeekCode",StrWeekCode.Trim());
		ini->WriteString("MarkingSpec","LDPMode",StrLDPMode.Trim());
		ini->WriteString("MarkingSpec","StartTime",Now().CurrentDateTime());

		SECSHistoryData("MarkingSpecDataSave -> WEEKCODE : " + StrWeekCode + "LDPMODE : " + StrLDPMode);
	}
	delete ini;
}
//---------------------------------------------------------------------------
void __fastcall TFrmSecsSetUp::LotProcessRegistered(AnsiString StrPartCode ,AnsiString StrLotCode ,AnsiString StrOpID)
{
	int nRetVal;

	long nVid = 0;
	int nCount = 1;

	nRetVal =(int) ReadCommunicationDM(_TRACK_IN_DM_INDEX);

	if(nRetVal == 0)
	{
		nRetVal =1;
	}

	TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini");
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini"))
	{
		ini->WriteString("LotDataSet"+IntToStr(nRetVal),"PartCode",StrPartCode.Trim());
		ini->WriteString("LotDataSet"+IntToStr(nRetVal),"LotCode",StrLotCode.Trim());
		ini->WriteString("LotDataSet"+IntToStr(nRetVal),"StartTime",Now().CurrentDateTime());
	}
	delete ini;

	String StrMZID;
	TIniFile *RFini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\RFIDMem"+IntToStr(nRetVal)+".ini");
	StrMZID = RFini->ReadString("RFID READ","MZNO","1");
	delete RFini;

	String strPower[4];
	TIniFile *TKInIni = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\TKInDetectPower.ini");
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\TKInDetectPower.ini"))
	{
		for(int nTemp = 0; nTemp < 4; nTemp++)
		{
			strPower[nTemp] = TKInIni->ReadString("LOT_" + IntToStr(nRetVal), "LASER_"+IntToStr(nTemp+1), "");
		}
	}
	delete TKInIni;

	nVid = 4010;	// Laser Power data Setting
	EXGem->GEMSetVariable(nCount, &nVid, &WideString(strPower[0]));

	nVid = 4011;
	EXGem->GEMSetVariable(nCount, &nVid, &WideString(strPower[1]));

	nVid = 4012;
	EXGem->GEMSetVariable(nCount, &nVid, &WideString(strPower[2]));

	nVid = 4013;
	EXGem->GEMSetVariable(nCount, &nVid, &WideString(strPower[3]));

	nVid = 2092;  // LotID
	EXGem->GEMSetVariable(nCount, &nVid, &WideString(StrLotCode));

	nVid = 2093;  // Part Code  - 120927 수정 sjyoon
	EXGem->GEMSetVariable(nCount, &nVid, &WideString(FrmRFIDProceeding->StrRFPartNo));

	nVid = 2011;  // PPNAME
	EXGem->GEMSetVariable(nCount, &nVid, &WideString(StrPartCode));

	nVid = 2090;  // OPID
	EXGem->GEMSetVariable(nCount, &nVid, &WideString(StrOpID));

	nVid = 2095;  // MZID
	EXGem->GEMSetVariable(nCount, &nVid, &WideString(StrMZID));

	EXGem->GEMSetEvent(1100);
	FrmMain->TrackInMessageView("TRACK IN LOT CODE : " + StrLotCode + " PART CODE : " + StrPartCode + " OPERATOR ID : " + StrOpID + " MZ ID : " + StrMZID);
	FrmMain->TrackInMessageView("TRACK IN 필요정보 전송 완료");
}
//---------------------------------------------------------------------------

void __fastcall TFrmSecsSetUp::StartARSuccess()
{
	int nRetVal;
	double dbVal = 0;
	if(StrRecvLotQty != "")
	{
	dbVal = StrToFloat(StrRecvLotQty);
	}
	WriteCommunicationDM(_TRACK_IN_CONFIRM_HOST_, _TRACK_IN_DM_);

	nRetVal = (int)ReadCommunicationDM(_TRACK_IN_DM_INDEX);
	if(nRetVal == 0)
	{
		nRetVal = 1;
	}
	int nReadDMNo = (_DM_MatchingNo_LotCount_+((nRetVal-1)*5));

	WriteCommunicationDM(dbVal, nReadDMNo);
	FrmJobProcess->LotTrackInWaitProceed();
	SECSHistoryData("START AR : DM INDEX = " + IntToStr(nRetVal));
	FrmMain->TrackInMessageView("TRACK IN 성공 가동시작" );
	FrmMain->LotDataGetFromFiles(nRetVal);



}
//---------------------------------------------------------------------------

void __fastcall TFrmSecsSetUp::SecsTrackOutProcess(int nSelectIndex)
{
	long nVid = 0;
	int nTROutNo;
	String StrTROutLotCode ,StrTROutPartCode ,StrTROutBeginTime , StrTROPID;
	String StrMZName;
	if(nSelectIndex == 0)
	{
		nTROutNo = ReadCommunicationDM(_TRACK_OUT_DM_INDEX);
	}
	else
	{
		nTROutNo = nSelectIndex;
	}

	if(nTROutNo == 0)
	{
		nTROutNo = 1;
	}

	TIniFile *TrackInfoIni = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini");

	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini"))
	{
		StrTROutPartCode = TrackInfoIni->ReadString("LotDataSet"+IntToStr(nTROutNo),"PartCode","0");
		StrTROutLotCode = TrackInfoIni->ReadString("LotDataSet"+IntToStr(nTROutNo),"LotCode","0");
		StrTROutBeginTime = TrackInfoIni->ReadString("LotDataSet"+IntToStr(nTROutNo),"StartTime","NONE");

		StrTROPID = TrackInfoIni->ReadString("LotData","OPID","NONE");
	}
	delete TrackInfoIni;

	TIniFile *OHTInfo = new TIniFile(ExtractFilePath(Application->ExeName) + "\\ini\\OHTInfo.ini");
	if(FileExists(ExtractFilePath(Application->ExeName) + "\\ini\\OHTInfo.ini"))
	{
		StrMZName = OHTInfo->ReadString("ULD_INFO", "MZ_ID", "");
	}
	delete OHTInfo;

	FrmMain->GetTrackOutOEEDATA(nTROutNo);

	String StrMZID;
	TIniFile *RFini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\RFIDMem"+IntToStr(nTROutNo)+".ini");
	StrMZID = RFini->ReadString("RFID READ","MZNO","1");
	delete RFini;

	String strPower[4];
	TIniFile *TKOutIni = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\TKOutDetectPower.ini");
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\TKOutDetectPower.ini"))
	{
		for(int nTemp = 0; nTemp < 4; nTemp++)
		{
			strPower[nTemp] = TKOutIni->ReadString("LOT_" + IntToStr(nTROutNo), "LASER_"+IntToStr(nTemp+1), "");
		}
	}
	delete TKOutIni;

	nVid = 4020;	// Laser Power data Setting
	EXGem->GEMSetVariable(1, &nVid, &WideString(strPower[0]));

	nVid = 4021;
	EXGem->GEMSetVariable(1, &nVid, &WideString(strPower[1]));

	nVid = 4022;
	EXGem->GEMSetVariable(1, &nVid, &WideString(strPower[2]));

	nVid = 4023;
	EXGem->GEMSetVariable(1, &nVid, &WideString(strPower[3]));


	int  nOutTemp = nTROutNo;
	nOutTemp = nOutTemp -1;
	nVid = 2042 + (nOutTemp*5);
	EXGem->GEMSetVariable(1, &nVid, &WideString(StrProcUnitcnt));

	nVid = 2043 + (nOutTemp*5);
	EXGem->GEMSetVariable(1, &nVid, &WideString(StrGoodcnt));

	nVid = 2044 + (nOutTemp*5);
	EXGem->GEMSetVariable(1, &nVid, &WideString(StrRejectcnt));

	nVid = 2040;
	String StrTotalCnt =   FrmMain->MCProduceInformationGrid2->Cells[1][0].Trim();
	if(StrTotalCnt == "")
	{
		StrTotalCnt = 0;
	}
	EXGem->GEMSetVariable(1, &nVid, &WideString(StrTotalCnt));

	nVid = 2090;  // OPID
	EXGem->GEMSetVariable(1, &nVid, &WideString(StrTROPID));

	nVid = 2092;  // LotID
	EXGem->GEMSetVariable(1, &nVid, &WideString(StrTROutLotCode));

	nVid = 2096;  // Unloader Magazine ID
	EXGem->GEMSetVariable(1, &nVid, &WideString(StrMZName));
//	EXGem->GEMSetVariable(1, &nVid, &WideString(FrmRFIDProceeding->StrTROutMzNo));
	if(FrmMain->b_TpConnect)
	{
//		g_TpBase.logLot("LOT_Track_Out","End",strLotLogLotID.c_str(),FrmMain->g_strCurrentRecipeName.c_str(),StrMZID.c_str(),"","","","","","");
		g_TpBase.logLot("UNLOADER","TrackOut",StrTROutLotCode.c_str(),FrmMain->g_strCurrentRecipeName.c_str(),StrMZName.c_str());
	}

	EXGem->GEMSetEvent(1101);
	SECSHistoryData("EXGem->GEMSetEvent(1101)");
}
//---------------------------------------------------------------------------

void __fastcall TFrmSecsSetUp::RecipeupLoadStepProcess(String StrPartcode , int nStep)
{
/*	121009 수정 - sjyoon
		=> Recipe upload 시 발생하던 1017 이벤트 삭제
	long  nVid;
	if(nStep == 1)
	{

		nVid = 2093;  // JOB NAME
		EXGem->GEMSetVariable(1, &nVid, &WideString(StrPartcode.Trim()));

		EXGem->GEMSetEvent(1017);
		SECSHistoryData("EXGem->GEMSetEvent(1017)");

		FrmMain->TrackInMessageView("UPLOAD 시작");
	}
*/
}
//---------------------------------------------------------------------------
void __fastcall TFrmSecsSetUp::RecipedownLoadStepProcess(int nStep)
{
	long  nVid;
	if(nStep == 1)
	{
		FrmMain->bRcpDownloadWaitChk = true;
		if(FrmJobProcess->LotWaitInfoGrid->Cells[1][1] != "")
		{
			Str_FL_PartCode = FrmJobProcess->LotWaitInfoGrid->Cells[1][1];

			nVid = 2093;  // JOB NAME
			EXGem->GEMSetVariable(1, &nVid, &WideString(Str_FL_PartCode.Trim()));

			nVid = 2092;  // LotID
			EXGem->GEMSetVariable(1, &nVid, &WideString(FrmJobProcess->LotWaitInfoGrid->Cells[2][1].Trim()));

			nVid = 2011;  // PART NO
			EXGem->GEMSetVariable(1, &nVid, &WideString(Str_FL_PartCode.Trim()));


			String StrLDTemp;
			TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini");
			if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini"))
			{
				StrLDTemp = ini->ReadString("LotData","OPID","1234");
			}
			delete ini;

			nVid = 2090;  // OPID
			EXGem->GEMSetVariable(1, &nVid, &WideString(StrLDTemp));

			EXGem->GEMSetEvent(1016);	//request recipe download event	//FrmLotRcvShow ... showing...
			SECSHistoryData("EXGem->GEMSetEvent(1016)");
			FrmMain->TrackInMessageView("RECIPE DOWNLOAD EVENT를 전송하였습니다!");
		}
		else
		{
			WriteCommunicationDM(_RFID_RESPONSE_FAIL_, _RFID_RCP_DOWN_DM_); //RFID
			FrmMain->bRcpDownloadWaitChk = false;
			FrmCdBox->setFlag(CD_OK);
			FrmCdBox->setTitle("RECIPE DOWNLOAD 실패");
			FrmCdBox->setText("DOWNLOAD 하려는 PP ID 가 존재하지 않습니다.");
			FrmCdBox->BringToFront();
			FrmCdBox->ShowModal();
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmSecsSetUp::TrackInOutTimerTimer(TObject *Sender)
{
	if(m_fStart == true)
	{
		TrackInProcess();
		TrackOutProcess();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmSecsSetUp::TrackInProcess()
{
	if(_TRACK_IN_READ_COMMAND_ == ReadCommunicationDM(_TRACK_IN_DM_))		//1 == 60
	{
		WriteCommunicationDM(_TRACK_IN_READ_CONFIRM_, _TRACK_IN_DM_);
		SECSHistoryData("WriteCommunicationDM(10, _TRACK_IN_DM_");

		if(FrmJobProcess->LotWaitInfoGrid->Cells[1][1] != "" && FrmJobProcess->LotWaitInfoGrid->Cells[2][1] != "")
		{
			LotProcessRegistered(FrmJobProcess->LotWaitInfoGrid->Cells[1][1] , FrmJobProcess->LotWaitInfoGrid->Cells[2][1] , FrmJobProcess->LotWaitInfoGrid->Cells[3][1]); //EVENT SEND
		}
		else
		{
			WriteCommunicationDM(_TRACK_IN_NONE_, _TRACK_IN_DM_);
			SECSHistoryData("SecsTrackInProcess: No more Waiting Lot and PartCode!");
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmSecsSetUp::TrackOutProcess()
{
	if(_TRACK_OUT_READ_COMMAND_ == ReadCommunicationDM(_TRACK_OUT_DM_))
	{
		WriteCommunicationDM(_TRACK_OUT_READ_CONFIRM_, _TRACK_OUT_DM_);
		SECSHistoryData("WriteCommunicationDM(10, _TRACK_OUT_DM_)");

		SecsTrackOutProcess(0); //event rise
	}

}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void __fastcall TFrmSecsSetUp::BtnSecsAutoStartClick(TObject *Sender)
{
	if(b_SECSautoStart ==true)
	{
		BtnSecsAutoStart->Caption = "AUTO START OFF";
		b_SECSautoStart = false;
	}
	else
	{
		BtnSecsAutoStart->Caption = "AUTO START ON";
		b_SECSautoStart = true;
	}

	TIniFile *SecsIni = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\SECSConfig.ini");
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\SECSConfig.ini"))
	{
		SecsIni->WriteBool("SECSSwitch","ONOFF",b_SECSautoStart);
	}
	delete SecsIni;
}
//---------------------------------------------------------------------------

void __fastcall TFrmSecsSetUp::SecsGemAutoStartProcess()
{
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

void __fastcall TFrmSecsSetUp::SecsParamVariableUpdateFunction(long lVid , WideString StrValue)
{
	int nReturn;
	nReturn = EXGem->GEMSetVariable(1, &lVid, &StrValue);
	if( nReturn == 0 )
	{
		SECSHistoryData( "Send GEMSetVariable successfully Vid : " +IntToStr(lVid) + ", StrValue: " + StrValue );
	}
	else
	{
		char szMsg[256];
		sprintf( szMsg, "Fail to GEMSetVariable (%d)", nReturn );
		SECSHistoryData( szMsg );
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmSecsSetUp::SecsParamVariableNameUpdateFunction(WideString StrVid ,WideString StrValue)
{
	int nReturn;
	nReturn = EXGem->GEMSetVarName(1, &StrVid, &StrValue);
	if( nReturn == 0 )
	{
		SECSHistoryData( "Send GEMSetVariable successfully  SVid : " +StrVid + ", StrValue: " + StrValue );
	}
	else
	{
		char szMsg[256];
		sprintf( szMsg, "Fail to GEMSetVariable (%d)", nReturn );
		SECSHistoryData( szMsg );
	}
}
//---------------------------------------------------------------------------

//1200 ~3 (CEID)

void __fastcall TFrmSecsSetUp::SecsParamUpdateTimer(TObject *Sender)
{
	long nVid = 0;
	int nCount = 1;

	if(NULL == MMIComm)
		return;

	if(m_fStart ==true )
	{
		MMIComm->m_mmiToSeq.cmdType = CMD_RD_DM;

		if ( MMIComm->Send() &&  MMIComm->Recv())
		{
		   for(int nLaserStatusLed = 0; nLaserStatusLed<4; nLaserStatusLed++)
		   {
				nVid = 2080 + nLaserStatusLed;  // LASER1 VAC
				EXGem->GEMSetVariable(nCount, &nVid, &WideString(FloatToStr(MMIComm->m_mmiToSeq.bufferData.dm.data[145+nLaserStatusLed])));
			}

		   //Event -> In case of communicating the host and Secs/gem is also Use Stauts

			if(FloatToStr(MMIComm->m_mmiToSeq.bufferData.dm.data[_Laser1_Drill_Start_End_]) ==_Laser_Drill_Start_)
			{
				LaserDrillStartEndEventResponse(_Laser1_Drill_Start_End_);
				EXGem->GEMSetEvent(1200);
				SECSHistoryData( "Laser1DrillStartEndEventResponse START");
			}
			else if(FloatToStr(MMIComm->m_mmiToSeq.bufferData.dm.data[_Laser1_Drill_Start_End_]) ==_Laser_Drill_End_)
			{
				LaserDrillStartEndEventResponse(_Laser1_Drill_Start_End_);
				EXGem->GEMSetEvent(1201);
				SECSHistoryData( "Laser1DrillStartEndEventResponse END");
			}

			if(FloatToStr(MMIComm->m_mmiToSeq.bufferData.dm.data[_Laser2_Drill_Start_End_]) ==_Laser_Drill_Start_)
			{
				LaserDrillStartEndEventResponse(_Laser2_Drill_Start_End_);
				EXGem->GEMSetEvent(1202);
				SECSHistoryData( "Laser2DrillStartEndEventResponse START");
			}
			else if(FloatToStr(MMIComm->m_mmiToSeq.bufferData.dm.data[_Laser2_Drill_Start_End_]) ==_Laser_Drill_End_)
			{
				LaserDrillStartEndEventResponse(_Laser2_Drill_Start_End_);
				EXGem->GEMSetEvent(1203);
				SECSHistoryData( "Laser2DrillStartEndEventResponse END");
			}

			if(FloatToStr(MMIComm->m_mmiToSeq.bufferData.dm.data[_Laser3_Drill_Start_End_]) ==_Laser_Drill_Start_)
			{
				LaserDrillStartEndEventResponse(_Laser3_Drill_Start_End_);
				EXGem->GEMSetEvent(1204);
				SECSHistoryData( "Laser3DrillStartEndEventResponse START");
			}
			else if(FloatToStr(MMIComm->m_mmiToSeq.bufferData.dm.data[_Laser3_Drill_Start_End_]) ==_Laser_Drill_End_)
			{
				LaserDrillStartEndEventResponse(_Laser3_Drill_Start_End_);
				EXGem->GEMSetEvent(1205);
				SECSHistoryData( "Laser3DrillStartEndEventResponse END");
			}

			if(FloatToStr(MMIComm->m_mmiToSeq.bufferData.dm.data[_Laser4_Drill_Start_End_]) ==_Laser_Drill_Start_)
			{
				LaserDrillStartEndEventResponse(_Laser4_Drill_Start_End_);
				EXGem->GEMSetEvent(1206);
				SECSHistoryData( "Laser4DrillStartEndEventResponse START");
			}
			else if(FloatToStr(MMIComm->m_mmiToSeq.bufferData.dm.data[_Laser4_Drill_Start_End_]) ==_Laser_Drill_End_)
			{
				LaserDrillStartEndEventResponse(_Laser4_Drill_Start_End_);
				EXGem->GEMSetEvent(1207);
				SECSHistoryData( "Laser4DrillStartEndEventResponse END");
			}
		}

		MMIComm->m_mmiToSeq.cmdType = CMD_RD_FLAG;
		if(true == MMIComm->Send() && true == MMIComm->Recv())
		{
			if(bOHTLoaderCall !=  MMIComm->m_mmiToSeq.bufferData.flag.data[_AVAILABLE_INSERT_LD_MGZ_])
			{
				//hcchoi

				bOHTLoaderCall =  MMIComm->m_mmiToSeq.bufferData.flag.data[_AVAILABLE_INSERT_LD_MGZ_];
				String StrRetLDSecs;

				if(bOHTLoaderCall == true)
				{
					// not full (request more magazine)
					StrRetLDSecs =  "1";
				}
				else
				{
					// full (request to stop)
					StrRetLDSecs =  "0";
				}
				nVid = 2300;
				EXGem->GEMSetVariable(1, &nVid, &WideString(StrRetLDSecs));

				if(MMIComm->m_mmiToSeq.bufferData.flag.data[_OHT_OPERATOR_USE_] == 1)
				{
					// Set OHT Mode
					StrOHTModeSet = "1";
				}
				else
				{
					// Set Operator Mode
					StrOHTModeSet = "0";
				}
				nVid = 2302;
				EXGem->GEMSetVariable(1, &nVid, &WideString(StrOHTModeSet));

				EXGem->GEMSetEvent(1290);
				SECSHistoryData("OHT LoaderStatus CallChange ->"+StrRetLDSecs);

				if (bOHTLoaderCall)
					FrmMain->TrackInMessageView("OHT Loader Not Full");
				else
					FrmMain->TrackInMessageView("OHT Loader Full");
			 }

			 if(bOHTUnloaderCall !=  MMIComm->m_mmiToSeq.bufferData.flag.data[_AVAILABLE_OUT_ULD_MGZ_])
			 {
				bOHTUnloaderCall =  MMIComm->m_mmiToSeq.bufferData.flag.data[_AVAILABLE_OUT_ULD_MGZ_];
				String StrRetUDSecs;

				if(bOHTUnloaderCall == true)
				{
					// exist
					StrRetUDSecs =  "1";
				}
				else
				{
					//empty
					StrRetUDSecs =  "0";
				}
				nVid = 2301;
				EXGem->GEMSetVariable(1, &nVid, &WideString(StrRetUDSecs));

				if(MMIComm->m_mmiToSeq.bufferData.flag.data[_OHT_OPERATOR_USE_] == 1)
				{
					//Set OHT Mode
					StrOHTModeSet = "1";
				}
				else
				{
					//Set Operator Mode
					StrOHTModeSet = "0";
				}
				nVid = 2302;
				EXGem->GEMSetVariable(1, &nVid, &WideString(StrOHTModeSet));


				//OHT를 Unloading 하기 위해 Host 에게 저장해 놓았던 unloader magazineid. lotid 를 이벤트로 전달
				int nOHTMzIndex;

				MMIComm->m_mmiToSeq.cmdType = CMD_RD_DM;

				if(MMIComm->Send() == true && MMIComm->Recv() == true)
				{                                                            // DM 65 = 첫번째 buffer 에 쓰여진 Index 업로드
					nOHTMzIndex = (int)(MMIComm->m_mmiToSeq.bufferData.dm.data[_OHT_ULD_FIRST_BUFFER_]);

					if(nOHTMzIndex != nPrevOHTMzIndex && nOHTMzIndex != 0)
					{
						TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName) + "\\ini\\OHTInfo.ini");
						if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\OHTInfo.ini"))
						{
							strMagazineID = ini->ReadString("SEND_INFO_"+IntToStr(nOHTMzIndex), "MAGAZINE_ID", "NO DATA");
							strLotID = ini->ReadString("SEND_INFO_"+IntToStr(nOHTMzIndex), "LOT_ID", "NO DATA");

							nVid = 2096;
							EXGem->GEMSetVariable(1, &nVid, &WideString(strMagazineID));

							nVid = 2097;
							EXGem->GEMSetVariable(1, &nVid, &WideString(strLotID));

							if(FrmMain->b_TpConnect)
							{
								g_TpBase.logLot("OHT_Transfer","Start","$","$",strMagazineID.c_str(),"","","","","","");
							}
							SECSHistoryData("Unloader OHT CALL! Unloader Magazine ID :" + strMagazineID + ", Lot ID :" + strLotID);
						}
						nPrevOHTMzIndex = nOHTMzIndex;
						delete ini;
					}
				}

				EXGem->GEMSetEvent(1291);
				SECSHistoryData("OHT UnloaderStatus CallChange!"+StrRetUDSecs);

				if (bOHTUnloaderCall)
					FrmMain->TrackInMessageView("OHT Unloader Exist");
				else
					FrmMain->TrackInMessageView("OHT Unloader Empty");
			}

			if(MMIComm->m_mmiToSeq.bufferData.flag.data[_OHT_MANUAL_OUT_ULD_MGZ_] != 0)
			{
				String strLotID, strMzID;
				TIniFile *ManualOHTIni = new TIniFile(ExtractFilePath(Application->ExeName) + "\\ini\\OHTInfo.ini");

				if(FileExists(ExtractFilePath(Application->ExeName) + "\\ini\\OHTInfo.ini"))
				{
					String strOHTMode;

					if(MMIComm->m_mmiToSeq.bufferData.flag.data[_OHT_OPERATOR_USE_] == 1)
					{
						strOHTMode = "1";
					}
					else
					{
						strOHTMode = "0";
					}

					nVid = 2302;
					EXGem->GEMSetVariable(1, &nVid, &WideString(strOHTMode));

					strLotID = ManualOHTIni->ReadString("SEND_INFO_4","LOT_ID","");
					strMzID = ManualOHTIni->ReadString("SEND_INFO_4","MAGAZINE_ID","");

					nVid = 2096;
					FrmSecsSetUp->EXGem->GEMSetVariable(1, &nVid, &WideString(strMzID));

					nVid = 2097;
					FrmSecsSetUp->EXGem->GEMSetVariable(1, &nVid, &WideString(strLotID));

					FrmSecsSetUp->EXGem->GEMSetEvent(1293);
					FrmSecsSetUp->SECSHistoryData("Send GEMSetEvent(1293) successfully");

					FrmMain->TrackInMessageView("Manual OHT Event 전송 완료");
					FrmMain->ManualOHTConfirmPanel->Visible = true;
					FrmMain->ManualOHTConfirmPanel->Left = 460;
					FrmMain->ManualOHTConfirmMsgTimer->Enabled = true;

					if(FrmMain->b_TpConnect)
					{
						g_TpBase.logLot("OHT_Transfer","END","$","$","$","","","","","","");
					}

					WriteCommunicationFlag(0, _OHT_MANUAL_OUT_ULD_MGZ_);
				}
				delete ManualOHTIni;
			}
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmSecsSetUp::LaserDrillStartEndEventResponse(int DMnumber)
{
	MMIComm->m_mmiToSeq.cmdType = CMD_RD_DM;

	if ( MMIComm->Send() &&  MMIComm->Recv())
	{
		MMIComm->m_mmiToSeq.bufferData.dm.nStartNo = DMnumber;
		MMIComm->m_mmiToSeq.bufferData.dm.nEndNo  =DMnumber;
		MMIComm->m_mmiToSeq.bufferData.dm.data[DMnumber] = _Laser_Drill_CommonResponse_;

		MMIComm->m_mmiToSeq.cmdType = CMD_WR_DM;

		if(MMIComm->Send() && MMIComm->Recv())
		{

		}
	}
}

//---------------------------------------------------------------------------
void __fastcall TFrmSecsSetUp::EXGemeGEMTerminalMessage(TObject *Sender, long nMsgId, BSTR sSystemTime)
{
	char szMsg[512];
	sprintf(szMsg, "Received %s, Tid = %d, Msg = %s", "GEMTerminalMessage", nMsgId, sSystemTime );
	SECSHistoryData( szMsg );

	FrmTerminalMsg->MemoFromHost->Lines->Add(sSystemTime);
	if(FrmTerminalMsg->Showing == false)
	{
		FrmTerminalMsg->BringToFront();
		FrmTerminalMsg->ShowModal();
	}
}
//---------------------------------------------------------------------------

bool __fastcall TFrmSecsSetUp::PPLoadInquireS7F1Process(WideString StrPPID , long lLength)
{
	long nReturn  = 0;
	char szMsg[256];

	nReturn = EXGem->GEMReqPPLoadInquire(StrPPID, lLength);
	if( nReturn == 0 )
	{
		SECSHistoryData( "Send GEMReqPPLoadInquire successfully" );
		return true;
	}
	else
	{
		sprintf( szMsg, "Fail to GEMReqPPLoadInquire (%d)", nReturn );
		SECSHistoryData( szMsg );
		return false;
	}
}
//---------------------------------------------------------------------------

bool __fastcall TFrmSecsSetUp::PPSendS7F3Process(WideString StrPPID, int nLen)
{

	long nReturn  = 0;
	char szMsg[256];

	WideString StrRcpPath =  "";//ExtractFilePath(Application->ExeName)+ "SGConfig\\LDP\\XWork\\Recipe\\";

	//nReturn = FrmSecsSetUp->EXGem->GEMReqPPSendEx(StrPPID.c_bstr(), L"");

	nReturn = FrmSecsSetUp->EXGem->GEMReqPPSendEx(StrPPID.c_bstr(),StrRcpPath);
	if( nReturn == 0 )
	{
		FrmSecsSetUp->SECSHistoryData( "Send GEMReqPPSend successfully" );

		return true;
	}

	sprintf( szMsg, "Fail to GEMReqPPSend (%d)", nReturn );
	FrmSecsSetUp->SECSHistoryData( szMsg );
	return false;

}
//---------------------------------------------------------------------------

void __fastcall TFrmSecsSetUp::EXGemeGEMRspPPLoadInquire(TObject *Sender,
	  BSTR sPpid, long nResult)
{
	char szMsg[256];

	String strPPID(sPpid);
	sprintf(szMsg, "Received %s, Ppid = %s, Result = %d", "GEMRspPPLoadInquire", strPPID.c_str(), nResult );
	SECSHistoryData( szMsg );
}
//---------------------------------------------------------------------------

void __fastcall TFrmSecsSetUp::EXGemeGEMReqPPLoadInquire(TObject *Sender,
	  long nMsgId, BSTR sPpid, long nLength)
{
	long nReturn = 0;
	long nResult = 0;
	char szMsg[256];
	String strPPID(sPpid);
	sprintf(szMsg, "Received %s, MsgId = %d, Ppid = %s, Result = %d", "GEMReqPPLoadInquire", nMsgId, strPPID.c_str(), nLength );
	SECSHistoryData( szMsg );

	lDL_bodylen = nLength;

	nResult = 0;
	nReturn = EXGem->GEMRspPPLoadInquire(nMsgId, sPpid, nResult);
	if( nReturn == 0 )
	{
		SECSHistoryData( "Send GEMRspPPLoadInquire successfully" );
	}
	else
	{
		sprintf( szMsg, "Fail to GEMRspPPLoadInquire (%d)", nReturn );
		SECSHistoryData( szMsg );
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmSecsSetUp::EXGemeGEMReqPPSendEx(TObject *Sender,
	  long nMsgId, BSTR sPpid, BSTR sRecipePath)
{
	//호스트로 부터 recipe 다운로드 완료후 호출됨

	// 해당 바이너리 파일 생성후
	// ftp client 를 사용해 레이저 측에 데이타 전송후
	// tcp 를 통해 recipe,ppid; 전송

	long nRet=0;

	String strPPID(sPpid);
	AnsiString StrRcpPath =  ExtractFilePath(Application->ExeName)+ "SGConfig\\LDP\\XWork\\Recipe\\" + strPPID;

	FrmSecsSetUp->SECSHistoryData( "host download the recipe file : " +StrRcpPath);

	FrmMain->TrackInMessageView(StrRcpPath);

	// takes some time...
	if(TRUE == FrmLaserSetUp->sendToServer(StrRcpPath))
	{
		FrmSecsSetUp->SECSHistoryData( "Success to Send Recipe file to Laser via FTP");

		if (TRUE == FrmLaserSetUp->RecipeDownload(strPPID))
		{
			nRet = 0;
			FrmMain->TrackInMessageView("Recipe Download 레이져로 전송 성공");
			SECSHistoryData( "Success to download the recipe file To LASER part");
		}
		else
		{
			nRet = 1;
			FrmMain->TrackInMessageView("Recipe Download 레이져로 전송 실패!");
			SECSHistoryData( "Fail to download the recipe file To LASER part");
		}
	}
	else
	{
		nRet = 1;
	}

	// S7F4
	EXGem->GEMRspPPSend(nMsgId, sPpid, nRet);

	if(nRet == 0)
	{
		FrmLotRcvShow->PopUpLotCodeProcess(3 , strPPID);
	}
	else
	{
		FrmLotRcvShow->PopUpLotCodeProcess(4 , strPPID);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmSecsSetUp::S14F1Process(WideString strOBJID)
{
	long nObjID 	= 0;
	long nStream 	= 14;
	long nFunction 	= 1;
	long nReturn 	= -1;
	short nObjOri 	= 1;

//	WideString strOBJSpec 	= "";
//	WideString strOBJType 	= "";
//	WideString strTemp 		= "";

	wchar_t* wstr = NULL;

	EXGem->MakeObject(&nObjID);

		EXGem->SetList(nObjID, 5);
//			SetAsciiFunc(nObjID, strOBJSpec, strOBJSpec.Length());
//			SetAsciiFunc(nObjID, strOBJType, strOBJType.Length());

			EXGem->SetAscii(nObjID, wstr, 1); 							// OBJECT SPEC
			EXGem->SetAscii(nObjID, wstr, 1);							// OBJECT TYPE

			wstr = strOBJID.c_bstr();
			EXGem->SetList(nObjID, 1);
//				SetAsciiFunc(nObjID, strOBJID, strOBJID.Length());
				EXGem->SetAscii(nObjID, wstr, 1);	// OBJECT ID (STRIP ID)

			wstr = NULL;
			EXGem->SetList(nObjID, 1);
				EXGem->SetList(nObjID, 3);
//					SetAsciiFunc(nObjID, strTemp, strTemp.Length());
//					SetAsciiFunc(nObjID, strTemp, strTemp.Length());
					EXGem->SetAscii(nObjID, wstr, 1);
					EXGem->SetAscii(nObjID, wstr, 1);
					EXGem->SetU1(nObjID, &nObjOri, 1);

			EXGem->SetList(nObjID, 6);
/*				SetAsciiFunc(nObjID, strTemp, strTemp.Length());
				SetAsciiFunc(nObjID, strTemp, strTemp.Length());
				SetAsciiFunc(nObjID, strTemp, strTemp.Length());
				SetAsciiFunc(nObjID, strTemp, strTemp.Length());
				SetAsciiFunc(nObjID, strTemp, strTemp.Length());
				SetAsciiFunc(nObjID, strTemp, strTemp.Length());
*/
				EXGem->SetAscii(nObjID, wstr, 1);		// OriginLocation
				EXGem->SetAscii(nObjID, wstr, 1);		// Rows
				EXGem->SetAscii(nObjID, wstr, 1);		// Columns
				EXGem->SetAscii(nObjID, wstr, 1);		// Cell Status
				EXGem->SetAscii(nObjID, wstr, 1);		// Lot ID
				EXGem->SetAscii(nObjID, wstr, 1);		// Device ID

	nReturn = EXGem->SendSECSMessage(nObjID, nStream, nFunction, 0);
	if(nReturn == 0)
	{
		SECSHistoryData( "Send S14F1 - GetAttr Request Event successfully!! STRIP ID = " + strOBJID + ", Object ID = "+IntToStr(nObjID));
//		WriteCommunicationDM(3, _DM_PMS_READ_SIGNAL_);
	}
	else
	{
		SECSHistoryData( "Fail to send S14F1 - GetAttr Request Event!!");
		_pms.PMSResetTrigger();
		WriteCommunicationDM(4, _DM_PMS_READ_SIGNAL_);
	}
}
//---------------------------------------------------------------------------

String __fastcall TFrmSecsSetUp::PMSMapDataParse(int nColCnt, int nRowCnt, String strMapData)
{
	String StrParseResult;
	String strReturnMap;
	int nTemp = 0;
	int nCount = 0;
	int nBaseID = 0;

	for(int nColIndex = nColCnt; nColIndex >= 1; nColIndex--)
	{
		nBaseID = nColCnt * (nRowCnt-1);
		nCount++;

		for(int nRowIndex = nRowCnt; nRowIndex >= 1; nRowIndex--)
		{
			nTemp = nBaseID + nCount;
			strReturnMap += strMapData[nTemp];
			nBaseID -= nColCnt;
		}
	}

	SECSHistoryData( "PMS MAP Second Parse Data -> " + strReturnMap);
	return strReturnMap;
}
//---------------------------------------------------------------------------

int __fastcall TFrmSecsSetUp::GetAsciiFunc(long nObjectID, WideString& strGetData, long lSize)
{
	//120906 추가 => WideString 으로 GetAscii 시도 시 메모리 누수로 인한 임의적 Access Violation 발생.
	//				 GetAscii의 인자값인 wchar_t* * 와 같은 BSTR* 을 선언하여 GetAscii Event 시도하도록 수정
	BSTR* bstr = new BSTR;
	int nRet = EXGem->GetAscii(nObjectID, bstr, &lSize);
	strGetData = WideString(*bstr);
	delete bstr;
	return nRet;
}
//---------------------------------------------------------------------------
int __fastcall TFrmSecsSetUp::SetAsciiFunc(long nObjectID, WideString strSetData, long lSize)
{
	wchar_t* wstr;
	wstr = strSetData.c_bstr();
	int nRet = EXGem->SetAscii(nObjectID, wstr, lSize);
	return nRet;
}
//---------------------------------------------------------------------------

void __fastcall TFrmSecsSetUp::OHTMCDownCancelFunc()
{
	long nVid = 2303;       	// 2빔은 2103, 4빔 8빔은 2303번
	String strTemp = "1";
	EXGem->GEMSetVariable(1, &nVid, &WideString(strTemp));

	EXGem->GEMSetEvent(1295);
	SECSHistoryData("OHT MACHINE DOWN CANCEL - CEID 1295 이벤트 발생!");
}

//---------------------------------------------------------------------------

String	TFrmSecsSetUp::getQCDataRegen( String szQCData )
{
	//qc data에서 9로 들어오는 값은 0으로 바꿔준다.
	for( UINT idx = 1; idx <= szQCData.Length(); idx++ )
	{
		String nine = "9";
		String zero = "0";
		String temp = szQCData.operator []( idx );
		if( temp == nine )
		{
			szQCData.operator []( idx ) = zero[1];
		}
	}

	return szQCData;
}

//---------------------------------------------------------------------------

void __fastcall TFrmSecsSetUp::StripMapDataSend(String EqpId,String strMap,String strOperId,int nStageNo,int nPmsNumber,int nQCLot,String strGEMLotID,String strSTEP)
{
	String strFrameID = "";
	if(nQCLot != 0 && nQCLot < 11 && nPmsNumber != 0 && nPmsNumber < 101)
    {
    	strFrameID = FrmMain->strSeqPmsData[nQCLot][nPmsNumber];
    }
	SECSHistoryData("["+ IntToStr(nQCLot)+ "]["+IntToStr(nPmsNumber) +"] FRAME ID 1310 EVENT");


	if(strFrameID != "")
	{
		long nVid;
		nVid = 2400;       	// FRAME ID
		EXGem->GEMSetVariable(1, &nVid, &WideString(strFrameID));

		nVid = 2401;       	// LOT ID
		EXGem->GEMSetVariable(1, &nVid, &WideString(strGEMLotID));

		nVid = 2402;       	// EQP ID
		EXGem->GEMSetVariable(1, &nVid, &WideString(EqpId));

		nVid = 2403;       	// STAGE NO
		EXGem->GEMSetVariable(1, &nVid, &WideString(IntToStr(nStageNo)));

		nVid = 2404;       	// LOSS MAP INFO
		EXGem->GEMSetVariable(1, &nVid, &WideString(
			this->getQCDataRegen( strMap ) ) );

	//	nVid = 2405;       	// SITE ID
	//	EXGem->GEMSetVariable(1, &nVid, &WideString(IntToStr(nQCstage)));      // jylee 사용 안함

		nVid = 2406;       	// OPERATOR ID
		EXGem->GEMSetVariable(1, &nVid, &WideString(strOperId));

		EXGem->GEMSetEvent(1310);

		SECSHistoryData("STRIP MAP 전송!!(1310)");
		SECSHistoryData("SVID : 2400 (FRAME ID) : " + String(strFrameID));
		SECSHistoryData("SVID : 2401 (LOT ID)   : " + String(strGEMLotID));
		SECSHistoryData("SVID : 2402 (EQP ID)   : " + String(EqpId));
		SECSHistoryData("SVID : 2403 (STAGE ID) : " + String(IntToStr(nStageNo)));
		SECSHistoryData("SVID : 2404 (MAP INFO) : " + String(strMap));
		SECSHistoryData("SVID : 2405 (POER ID)  : " + String(strOperId));
	}
	else
	{
		SECSHistoryData("PMS Frame ID 가 비어있어 PMS Data send 이벤트(CEID : 1310)를 발생시키지 않습니다.");
	}

	FrmMain->strSeqPmsData[nQCLot][nPmsNumber] = "";

}
/*void __fastcall TFrmSecsSetUp::StripMapDataSend(String EqpId,String strMap,String strOperId,int nStageNo,int nPmsNumber,int nQCstage)
{
	TDateTime dt = Now();
	String StrDataTimeNow = dt.FormatString("yymmddhhnnss");
//	String strFrameID = FrmMain->strSeqPmsData[nPmsNumber];
	long nVid;
	nVid = 2400;       	// FRAME ID
	EXGem->GEMSetVariable(1, &nVid, &WideString("S4770448011221291"));

	nVid = 2401;       	// LOT ID
	EXGem->GEMSetVariable(1, &nVid, &WideString("S2P52O1"));

	nVid = 2402;       	// EQP ID
	EXGem->GEMSetVariable(1, &nVid, &WideString(EqpId));

	nVid = 2403;       	// STAGE NO
	EXGem->GEMSetVariable(1, &nVid, &WideString(IntToStr(nStageNo)));

	nVid = 2404;       	// LOSS MAP INFO
	EXGem->GEMSetVariable(1, &nVid, &WideString(strMap));

	nVid = 2405;       	// SITE ID
	EXGem->GEMSetVariable(1, &nVid, &WideString(IntToStr(nQCstage)));

	nVid = 2406;       	// OPERATOR ID
	EXGem->GEMSetVariable(1, &nVid, &WideString(strOperId));

	nVid = 2407;       	// EVENT TIME
	EXGem->GEMSetVariable(1, &nVid, &WideString(StrDataTimeNow));

	EXGem->GEMSetEvent(1310);
	SECSHistoryData("STRIP MAP 전송!!");

}
*/
//--------------------------------------------------------------------------

void __fastcall TFrmSecsSetUp::BtnReqMarkingSpecClick(TObject *Sender)
{
	EXGem->GEMSetEvent(1018);  // 151013 request marking spec for test
}
//---------------------------------------------------------------------------

void __fastcall TFrmSecsSetUp::MarkingSpecRequestTimer(TObject *Sender)
{
	int nRetVal =(int) ReadCommunicationDM(_MARKING_SPEC_REQUEST_DM_);
	if(nRetVal == 1)
	{
		MarkingSpecRequest->Enabled = false;
		EXGem->GEMSetEvent(1018);
		SECSHistoryData("Marking Trigger TranSfer to HOST SERVER");
	}

}
//---------------------------------------------------------------------------
void __fastcall TFrmSecsSetUp::StartArPartData(String strValue1,String strValue2)
{
	int nRetVal = (int)MMIComm->m_mmiToSeq.bufferData.dm.data[_MGZ_LOT_VAL_];
	TIniFile *RFIDMemIni = new TIniFile(ExtractFilePath(Application->ExeName) + "\\ini\\RFIDMem" + IntToStr(nRetVal) + ".ini");
	if(FileExists(ExtractFilePath(Application->ExeName) + "\\ini\\RFIDMem" + IntToStr(nRetVal) + ".ini"))
	{
		RFIDMemIni->WriteString("RFID READ","PART_NUMBER",strValue1);
		RFIDMemIni->WriteString("RFID READ","LOT_TYPE",strValue2);
	}
	delete RFIDMemIni;
}
//---------------------------------------------------------------------------
bool __fastcall TFrmSecsSetUp::PmsLotChkPopUp(String ServerLot,String RfidLot)
{
		if(ServerLot != RfidLot )
		{
			WriteCommunicationDM(4, _DM_PMS_READ_SIGNAL_);
			FrmCdBox->setFlag(CD_YES);
			FrmCdBox->setTitle("STRIP PMS LOT CODE ERROR!!");
			FrmCdBox->setText("PMS STRIP LOT CODE = "+ServerLot+ " MGZ LOT CODE = "+RfidLot + "   LOT COD가 일치 하지 않으니 확인후 가동!");
			FrmCdBox->BringToFront();
            if(FrmCdBox->Showing == false)
            {
				if (mrYes == FrmCdBox->ShowModal())
                {
                }
          }
			return false;
		}
		else
		{
			WriteCommunicationDM(3, _DM_PMS_READ_SIGNAL_);
            SECSHistoryData("PMS SERVER LOT ID : " + ServerLot + ", MGZ LOT ID : " + RfidLot);
 			return true;
		}
}
//----------------------------------------------------------------------------
