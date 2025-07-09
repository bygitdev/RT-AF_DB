//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormSecsGemSetScrn.h"
#include "MainFormScrn.h"
#include "PMSComm.h"
#include "FrmTerminalMsgScrn.h"
#include <stdio.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include "BaseComm.h"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma link "eXGemLib_OCX"
#pragma resource "*.dfm"
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

}
//---------------------------------------------------------------------------
void __fastcall TFormSecsGemSet::BtnCloseClick(TObject *Sender)
{
	this->Close();
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
		//SecsParamUpdate->Enabled = false;
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
void __fastcall TFormSecsGemSet::TMOnlineRemoteTimer(TObject *Sender)
{
	TMOnlineRemote->Enabled = false;
	this->Secs_OnlineRemoteProcess();
}
//---------------------------------------------------------------------------
void __fastcall TFormSecsGemSet::eXGemeGEMCommStateChanged(TObject *Sender, long nState)

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
		//FrmMain->FileSendTimer->Enabled = true;
		TMOnlineRemote->Enabled =true;
	}

	else if(nState == Comm_Enabled)
	{
		m_fStart = true;
		strcpy(szState, "Enabled");
    }
	EditCommState->Caption = szState;

    if(m_fStart ==  true && MainForm->MainPanelLed10->Color == clGreen)
	{
    	Status_Led(MainForm->MainPanelLed10 ,_STATUS_LED_GREEN_ , true , "ON");
    }
	else
    {
    	Status_Led(MainForm->MainPanelLed10 ,_STATUS_LED_GREEN_ , false , "OFF");
	}
	sprintf( szMsg, "Received %s, %s", "GEMCommStateChanged", szState );
    SECSHistoryData( szMsg );
}
//---------------------------------------------------------------------------

void __fastcall TFormSecsGemSet::eXGemeGEMControlStateChanged(TObject *Sender, long nState)

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
	EditCtrlState->Caption = szState;

	sprintf( szMsg, "Received %s, %s", "GEMControlStateChanged", szState );
	SECSHistoryData( szMsg );
}
//---------------------------------------------------------------------------

void __fastcall TFormSecsGemSet::eXGemeGEMErrorEvent(TObject *Sender, long nState)

{
	char    szMsg[256];

	sprintf( szMsg, "Received %s, Error Code = %d", "GEMErrorEvent", nState );
	SECSHistoryData( szMsg );
}
//---------------------------------------------------------------------------

void __fastcall TFormSecsGemSet::eXGemeGEMReqPPLoadInquire(TObject *Sender, long nMsgId,
		  BSTR sPpid, long nLength)
{
	long nReturn = 0;
	long nResult = 0;
	char szMsg[256];
	String strPPID(sPpid);
	sprintf(szMsg, "Received %s, MsgId = %d, Ppid = %s, Result = %d", "GEMReqPPLoadInquire", nMsgId, strPPID.c_str(), nLength );
	SECSHistoryData( szMsg );

 //	lDL_bodylen = nLength;

	nResult = 0;
	nReturn = eXGem->GEMRspPPLoadInquire(nMsgId, sPpid, nResult);
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

void __fastcall TFormSecsGemSet::eXGemeGEMReqPPSendEx(TObject *Sender, long nMsgId,
		  BSTR sPpid, BSTR sBody)
{
	//호스트로 부터 recipe 다운로드 완료후 호출됨

	// 해당 바이너리 파일 생성후
	// ftp client 를 사용해 레이저 측에 데이타 전송후
	// tcp 를 통해 recipe,ppid; 전송

	long nRet=0;

	String strPPID(sPpid);
	AnsiString StrRcpPath =  ExtractFilePath(Application->ExeName)+ "SGConfig\\LDP\\XWork\\Recipe\\" + strPPID;

	SECSHistoryData( "host download the recipe file : " +StrRcpPath);

  //	FrmMain->TrackInMessageView(StrRcpPath);

	// takes some time...
//	if(TRUE == FrmLaserSetUp->sendToServer(StrRcpPath))
//	{
//		FrmSecsSetUp->SECSHistoryData( "Success to Send Recipe file to Laser via FTP");
//
//		if (TRUE == FrmLaserSetUp->RecipeDownload(strPPID))
//		{
//			nRet = 0;
//			FrmMain->TrackInMessageView("Recipe Download 레이져로 전송 성공");
//			SECSHistoryData( "Success to download the recipe file To LASER part");
//		}
//		else
//		{
//			nRet = 1;
//			FrmMain->TrackInMessageView("Recipe Download 레이져;로 전송 실패!");
//			SECSHistoryData( "Fail to download the recipe file To LASER part");
//		}
//	}
//	else
//	{
//		nRet = 1;
//	}

//	// S7F4
//	eXGem->GEMRspPPSend(nMsgId, sPpid, nRet);
//
//	if(nRet == 0)
//	{
//		FrmLotRcvShow->PopUpLotCodeProcess(3 , strPPID);
//	}
//	else
//	{
//		FrmLotRcvShow->PopUpLotCodeProcess(4 , strPPID);
//	}
}
//---------------------------------------------------------------------------

void __fastcall TFormSecsGemSet::eXGemeGEMReqRemoteCommand(TObject *Sender, long nMsgId,
		  BSTR sRcmd, long nCount, BSTR *psNames, BSTR *psVals)
{
	int nRetVal;
   //	nRetVal = (int)ReadCommunicationDM(_TRACK_IN_DM_INDEX);  ///check161007

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
			//StartARSuccess();
			//StartArPartData(strValue1,strValue2);
			int nRecipeNumber;
		  //	nRecipeNumber = (int)ReadCommunicationDM(3);   161007

		 //	String strRecipeNumber = IntToStr((FrmMain->nGlobal_GrpNo*1000)+(nRecipeNumber));  161007

		}

		if(sRcmd2 == "PASS")
		{
//			for(int i = 0; i < nCount; i++)
//			{
//				sName = psNames[i];
//				sValue = psVals[i];
//				sprintf(szMsg,"    Name: %s, Value: %s", sName.c_str(), sValue.c_str());
//				SECSHistoryData( szMsg );
//
//				if(sName == "PMSRESULT") 				// PMS use/skip 을 S2F41 Message로 받음
//				{
//					if(sValue == "OK")
//					{
//						MMIComm->m_mmiToSeq.cmdType = CMD_RD_USESKIP;
//						if(MMIComm->Send() && MMIComm->Recv())
//						{
//							if(MMIComm->m_mmiToSeq.bufferData.useSkip.data[_USESKIP_PMS_ - 1] == false)
//							{
//								MMIComm->m_mmiToSeq.bufferData.useSkip.data[_USESKIP_PMS_ - 1] = true;
//								MMIComm->m_mmiToSeq.cmdType = CMD_WR_USESKIP;
//								if(MMIComm->Send() && MMIComm->Recv())
//								{
//									FrmSelectiveControl->UseSkipHistory("[PMS USE/SKIP] changed - SECS/GEM Received PMS Skip -> Use.");
//								}
//							}
//						}
//					}
//					else if(sValue == "NG")
//					{
//						MMIComm->m_mmiToSeq.cmdType = CMD_RD_USESKIP;
//						if(MMIComm->Send() && MMIComm->Recv())
//						{
//							if(MMIComm->m_mmiToSeq.bufferData.useSkip.data[_USESKIP_PMS_ - 1] == true)
//							{
//								MMIComm->m_mmiToSeq.bufferData.useSkip.data[_USESKIP_PMS_ - 1] = false;
//								MMIComm->m_mmiToSeq.cmdType = CMD_WR_USESKIP;
//								if(MMIComm->Send() && MMIComm->Recv())
//								{
//									FrmSelectiveControl->UseSkipHistory("[PMS USE/SKIP] changed - SECS/GEM Received PMS Use -> Skip.");
//								}
//							}
//						}
//					}
//				}
//			}
		}

		if(sRcmd2 == "TK_RESULT")
		{
//			for(int i = 0; i < nCount; i++)
//			{
//				sName = psNames[i];
//				sValue = psVals[i];
//				sprintf(szMsg,"    Name: %s, Value: %s", sName.c_str(), sValue.c_str());
//				SECSHistoryData( szMsg );
//
//				if(sName  == "TRACKIN")
//				{
//					if(sValue == "OK")
//					{
//						SECSHistoryData("SecsTrackInProcess: Trackin Success!");
//						FrmMain->TrackInMessageView("TRACK IN 성공");
//
//					}
//					else if(sValue == "NG")
//					{
//						WriteCommunicationDM(4, _TRACK_IN_DM_);
//						SECSHistoryData( "TK_RESULT _ TRACKIN _ NG");
//						FrmMain->TrackInMessageView("TRACK IN 실패");
//					}
//				}
//
//				else if(sName  == "TRACKOUT")
//				{
//					if(sValue == "OK")
//					{
//						FrmRFIDProceeding->TrackOutInfoManage();
//						FrmMain->TrackOutDBDataProcess();
//						SECSHistoryData("SecsTrackOutProcess:TrackOut Success!");
//					}
//					else if(sValue == "NG")
//					{
//
//						WriteCommunicationDM(3, _TRACK_OUT_DM_);
//						SECSHistoryData("SecsTrackOutProcess:TrackOut Failure!");
//					}
//				}
//			}
		}

		eXGem->GEMRspRemoteCommand(nMsgId, sRcmd, nHCAck, nCount, pnResult);

	}
	catch(Exception& e)
	{
		SECSHistoryData( e.Message);
	}
	delete [] pnResult;
}
//---------------------------------------------------------------------------

void __fastcall TFormSecsGemSet::eXGemeSECSMessageReceived(TObject *Sender, long nObjectID,
          long nStream, long nFunction, long nSysbyte)
{
	char szMsg[256] = {0, };

	short   nU1;
	long    nItems, lU2, lCnt;
	long lSize;
	BSTR bstr;

	if((nStream == 14) && (nFunction == 2))			// S14F2 - User Define Message
	{
		String strTempMapData, strMapData, strStripID,strLotId;
		short nBinaryArray[300] = {0, };

		g_nRowCnt = 0;
		g_nColCnt = 0;
		g_nTotalCnt = 0;

		eXGem->GetList(nObjectID, &nItems);			// L 2
		eXGem->GetList(nObjectID, &nItems);		// L 1
		eXGem->GetList(nObjectID, &nItems);	// L 2
		//					GetAsciiFunc(nObjectID, sAscii, lSize);
		eXGem->GetAscii(nObjectID, &bstr, &lSize); //OBJID
		//					strStripID = sAscii;
		strStripID = String(bstr);


		eXGem->GetList(nObjectID, &nItems);		// L 6
		eXGem->GetList(nObjectID, &nItems);	   	// L 2 OriginLocation List
		//							GetAsciiFunc(nObjectID, sAscii, lSize);
		eXGem->GetAscii(nObjectID, &bstr, &lSize);		// Attr ID
		eXGem->GetU1(nObjectID, &nU1, &lCnt, 1);		// Attr DATA
		eXGem->GetList(nObjectID, &nItems);     // L 2Rows List
		//							GetAsciiFunc(nObjectID, sAscii, lSize);
		eXGem->GetAscii(nObjectID, &bstr, &lSize);    	// Attr ID
		eXGem->GetU2(nObjectID, &lU2, &lCnt, 1);		// Attr DATA
		g_nColCnt = lU2;

		eXGem->GetList(nObjectID, &nItems);		// L 2 Columns List
		//							GetAsciiFunc(nObjectID, sAscii, lSize);
		eXGem->GetAscii(nObjectID, &bstr, &lSize);    // Attr ID
		eXGem->GetU2(nObjectID, &lU2, &lCnt, 1);	// Attr DATA
		g_nRowCnt = lU2;
		g_nTotalCnt = g_nColCnt * g_nRowCnt;

		eXGem->GetList(nObjectID, &nItems);   	// L 2 CellStatus List
		//							GetAsciiFunc(nObjectID, sAscii, lSize);
		eXGem->GetAscii(nObjectID, &bstr, &lSize);	// Atrr ID
		eXGem->GetBinary(nObjectID, &nBinaryArray[0], &lCnt, 300);	// Attr DATA

		int nGroupCnt = 4;//g_pNvMem->GetPkg(blockCnt);
		int nColCnt = 4;//g_pNvMem->GetPkg(unitY1cnt);
		int nRowCnt = 4;//g_pNvMem->GetPkg(unitXcnt);


		long UintChk =nGroupCnt*nColCnt*nRowCnt;


		if (  g_nTotalCnt !=  lCnt)
		{
			ShowMessage("UNIT Total Count가 올바르지 않습니다.");
			eXGem->CloseObject(nObjectID);
			return;
		}
		else if (  g_nTotalCnt !=  UintChk)
		{
			ShowMessage("UNIT Total Count가 올바르지 않습니다.");
			eXGem->CloseObject(nObjectID);
			return;
		}


		eXGem->GetList(nObjectID, &nItems);		// L 2 나머지 List
		//							GetAsciiFunc(nObjectID, sAscii, lSize);
		//							GetAsciiFunc(nObjectID, sAscii, lSize);
		eXGem->GetAscii(nObjectID, &bstr, &lSize);
		eXGem->GetAscii(nObjectID, &bstr, &lSize);
		strLotId = String(bstr);
		eXGem->GetList(nObjectID, &nItems);		// L 2 나머지 List
		//							GetAsciiFunc(nObjectID, sAscii, lSize);
		//							GetAsciiFunc(nObjectID, sAscii, lSize);
		eXGem->GetAscii(nObjectID, &bstr, &lSize);
		eXGem->GetAscii(nObjectID, &bstr, &lSize);

		eXGem->GetList(nObjectID, &nItems);  	// L 2
		eXGem->GetU1(nObjectID, &nU1, &lCnt, 1);
		eXGem->GetList(nObjectID, &nItems);	// L 0
		eXGem->CloseObject(nObjectID);

		int nRFIDTRinval = 0;//g_pNvMem->GetNDm(5);
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
			//WriteCommNDM(pmsState , 4 );
			bLotCodChk = false;
		}
		delete RFIDMemIni;


        for(int nTemp = 0; nTemp < g_nTotalCnt; nTemp++)
        {
            strTempMapData += IntToStr(nBinaryArray[nTemp]);
        }

        SECSHistoryData("Map ID : " + strStripID + ", Recieve PMS Map Data : " + strTempMapData);
   //		FrmPMSScrn->PMSHistoryData("Map ID : " + strStripID + ", Recieve PMS Map Data : " + strTempMapData);
		strMapData = PMSMapDataParse(g_nColCnt, g_nRowCnt, strTempMapData);

		if(strMapData != "")
		{
		//	FrmPMSScrn->PMSIDDataProcess(strStripID, strMapData);   //161007
		}
	}

	sprintf( szMsg, "message received (S%dF%d) & Object ID %d", nStream, nFunction, nObjectID);
	SECSHistoryData( szMsg );

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

void __fastcall TFormSecsGemSet::eXGemeGEMTerminalMessage(TObject *Sender, long nMsgId,
          BSTR sSystemTime)
{
	char szMsg[512];
	sprintf(szMsg, "Received %s, Tid = %d, Msg = %s", "GEMTerminalMessage", nMsgId, sSystemTime );
	SECSHistoryData( szMsg );
	
	if(String(sSystemTime) == "Secs/Gem I/F Error")
		return;

	FrmTerminalMsg->MemoFromHost->Lines->Add(sSystemTime);
	if(FrmTerminalMsg->Showing == false)
	{
		FrmTerminalMsg->BringToFront();
		FrmTerminalMsg->ShowModal();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormSecsGemSet::eXGemeGEMRspPPLoadInquire(TObject *Sender, BSTR sPpid,
		  long nResult)
{
	char szMsg[256];

	String strPPID(sPpid);
	sprintf(szMsg, "Received %s, Ppid = %s, Result = %d", "GEMRspPPLoadInquire", strPPID.c_str(), nResult );
	SECSHistoryData( szMsg );
}
//---------------------------------------------------------------------------

void TFormSecsGemSet::SecsInitializeProcess()
{
	long		nReturn = 0;
	char        szMsg[256];
	AnsiString	sCfg;

	WideString wStrPath = ExtractFilePath(Application->ExeName)+ "\\Ini\\XGEM.cfg";
	int nRetcode =  eXGem->Initialize(wStrPath.c_bstr());

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
        GroupboxSecsControl->Enabled = true;

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

   //	FrmLaserSetUp->RetrylaserRecipeCall();
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
	long  nVid = 0;
	int nReturn;
	char        szMsg[256];
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
	else
	{
		PanelGemState->Caption =  "Machine Idle";
		nSecsProcessState = Processing_Manual ;
	}

	nVid = 2004;  // Process State SVID
	eXGem->GEMSetVariable(1, &nVid, &WideString(nSecsProcessState));

	nVid = 2005;  // Previous Process State SVID
	eXGem->GEMSetVariable(1, &nVid, &WideString(nSecsPrevProcessState));

	SECSHistoryData("Process State Change : " +IntToStr(nSecsPrevProcessState)+ " -> " + IntToStr(nSecsProcessState));

	nReturn = eXGem->GEMSetEvent(1116);
	if( nReturn == 0 )
	{
		SECSHistoryData( "Processing Status Change" + StrPrevStatus + "->"+  PanelGemState->Caption);
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

bool TFormSecsGemSet::PmsLotChkPopUp(String ServerLot,String RfidLot)
{
		if(ServerLot != RfidLot )
		{
			//WriteCommNDM(pmsState ,4);
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
		   //	WriteCommNDM(pmsState ,3);
			SECSHistoryData("PMS SERVER LOT ID : " + ServerLot + ", MGZ LOT ID : " + RfidLot);
			return true;
		}
}
//----------------------------------------------------------------------------
String TFormSecsGemSet::PMSMapDataParse(int nColCnt, int nRowCnt, String strMapData)
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



