//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ftccomm.h"
#include ".\MainFormScrn.h"
#include "..\common\basecomm.h"
#include "..\mainstatus\arflowscreen\fseelot.h"
#include "..\Communication\SECS\FormSecsGemSetScrn.h"
#include "include.h"
#include <stdio.h>
#include <vector>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmTCComm *frmTCComm;


//---------------------------------------------------------------------------
__fastcall TfrmTCComm::TfrmTCComm(TComponent* Owner)
	: TForm(Owner)
{
	_pOhtSocket = NULL;
	_ohtBuf = "";
	_Address = "";
	_Port = "";
	_fp = NULL;

	_bInitialize = FALSE;
	ForceDirectories("C:\\KOSES\\History\\TCCommHistory\\");
	_ndmConfirm = TRUE;
}
//---------------------------------------------------------------------------
void __fastcall TfrmTCComm::btnConnectClick(TObject *Sender)
{
	if (_pOhtSocket)
	{
		ClientSocket1->Active = false;
		return;
	}

	ClientSocket1->Address = _Address;
	ClientSocket1->Port = _Port.ToInt();

	try
	{
		ClientSocket1->Active = true;
	}
	catch(Exception& e)
	{
		MachineHistoryData("Fail to connect : " + e.Message);
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmTCComm::ClientSocket1Connect(TObject *Sender, TCustomWinSocket *Socket)

{
	_pOhtSocket = Socket;
	btnConnect->Caption = "Disconnect";
	Edit1->Enabled = false;
	Edit2->Enabled = false;
	_bInitialize = TRUE;
	Memo1->Lines->Add(Now().TimeString() + " : TC Server Connected !");
}
//---------------------------------------------------------------------------
void __fastcall TfrmTCComm::ClientSocket1Disconnect(TObject *Sender, TCustomWinSocket *Socket)

{
	_pOhtSocket = NULL;
	btnConnect->Caption = "Connect";
	Edit1->Enabled = true;
	Edit2->Enabled = true;
	Memo1->Lines->Add(Now().TimeString() + " : TC Server Disconnected !");
}
//---------------------------------------------------------------------------

void __fastcall TfrmTCComm::ClientSocket1Read(TObject *Sender, TCustomWinSocket *Socket)
{
	bool bRet = true;
	DWORD tick = ::GetTickCount();
	unsigned char header[16+1] ={0,};
	int headerBytes = 16;
	int totalBytes = 0;
	do
	{
		int bytes = 0;
		try
		{
			if ( (::GetTickCount() - tick) > 2000)   //
			{
				if (totalBytes >0)	// 받던중이면
					MachineHistoryData("Timeout to get header information" );

				bRet = false;
				break;
			}

			if (!Socket->Connected)
			{
				bRet  = false;
				break;
			}
			bytes = Socket->ReceiveBuf(header+totalBytes, headerBytes- totalBytes);
			if (bytes <= 0)
			{
				::Sleep(1);
				continue;
			}
		}
		catch(Exception &e)
		{
			bRet = false;
			Memo1->Lines->Add(Now().TimeString() + " : " + e.Message );
			break;

		}

		totalBytes += bytes;
		if ( totalBytes == headerBytes)
			break;


	}
	while(  totalBytes != headerBytes);


	if (!bRet)
	{

		if (Socket->Connected)
		{
			_pOhtSocket = NULL;
			Socket->Close();
		}
		return;
	}

	int bodyBytes = atoi( header);
	if (bodyBytes > 1024*1024)
	{
		MachineHistoryData("Invalid body bytes : " + IntToStr(bodyBytes) );
		return;
	}

	char* body = new char [ bodyBytes +1] ;
	memset(body, 0x00, bodyBytes+1);

	tick = ::GetTickCount();
	totalBytes = 0;
	do
	{
		int bytes =0;
		try
		{
			if ( (::GetTickCount() - tick) > 2000)   //
			{
				MachineHistoryData("Timeout to get body information" );
				bRet = false;
				break;
			}
			if (!Socket->Connected)
			{
				bRet  = false;
				break;
			}
			bytes = Socket->ReceiveBuf(body+totalBytes, bodyBytes - totalBytes);
			if (bytes <= 0)
			{
				::Sleep(1);
				continue;
			}
		}
		catch(Exception &e )
		{
			bRet = false;
			Memo1->Lines->Add(Now().TimeString() + " : " + e.Message );
			break;
		}

		totalBytes += bytes;
		if ( totalBytes == bodyBytes)
			break;
	}
	while( totalBytes != bodyBytes);

	if (!bRet)
	{
		delete [] body;
		if (Socket->Connected)
		{
			_pOhtSocket = NULL;
			Socket->Close();
		}
		return;
	}

	MachineHistoryData(body);
	this->parse(body);
	delete [] body;
	if (Socket->Connected)
	{
		_pOhtSocket = NULL;
		Socket->Close();
	}
}
//---------------------------------------------------------------------------
void TfrmTCComm::parse(AnsiString bodyData)
{
	char body[1024*16]={0,};
	char buf[1024*16]={0,};
	strcpy(body, bodyData.c_str());
	strcpy(buf, bodyData.c_str());

	char seps[]={"  "};

	AnsiString func;
	AnsiString params[20];
	int paramsCnt = 0;

	char* tok = strtok(buf, seps);
	func = tok;


	// ----------------------- router -------------------------
	if (0 == func.AnsiCompareIC("FUNCTION_RPY=PCB_INFO_ROUTER"))
	{
	}
	else if (0 == func.AnsiCompareIC("FUNCTION_RPY=LOT_START"))
	{
	}
	// ----------------------- sorter -------------------------
	else if (0 == func.AnsiCompareIC("FUNCTION_RPY=SEE_LOT"))
	{
		if(MainForm->b_TpConnect)
		{
			g_pTpBase->logComm(L"SYSTEM",L"RECV", L"'TYPE'",L"'TCP/IP'", L"'FUNCTION'",L"'SEE_LOT'");
		}

		//FUNCTION_RPY=SEE_LOT LOTNO=X007B00508 LOTSTATE=RUN LOTTYPE=PP PARTNO=MZ7LN250HCHP-2BW00-G11
		//MAINSTATE=ACTIVE PROCID=SMAC QTY=400 RECIPE=M033 STEPSEQ=M033 CYCLEID=- ASSYLINE=MS-A1 COMPLOT=CMF2N39TA3
		//CUSTOMER=00 EVALCODE=- FABSITE=C LINE=XMDL NCACODE=K00 NCECODE=- NCFCODE=- NCHCODE=- NCMCODE=- NCQCODE=N00 NCTCODE=-
		//OPTCODE=0 TIER=0 OTHER=DAE SALECODE=- WEEKCODE=1433 RESULT=PASS MSG=""

		tok = strtok(NULL, seps); //LOTNO
		AnsiString lotNo =  (char*)(tok + 6);
		if (lotNo == "")
			return;

		tok = strtok(NULL, seps); //LOTSTATE      or RESULT
		if (0 == strncmp(tok , "RESULT=", 7))
		{
			//fail result
			MainForm->MachineHistoryData(bodyData);
			return;
		}

		frmSeeLot->lotState->Text = (char*)(tok + 9);
		tok = strtok(NULL, seps); //LOTTYPE
		tok = strtok(NULL, seps); //PARTNO
		frmSeeLot->partNo->Text = (char*)(tok + 7);
		tok = strtok(NULL, seps); //MAINSTATE
		tok = strtok(NULL, seps); //PROCID
		tok = strtok(NULL, seps); //QTY
		frmSeeLot->qty->Text = (char*)(tok + 4);
		tok = strtok(NULL, seps); //RECIPE
		tok = strtok(NULL, seps); //STEPSEQ
		tok = strtok(NULL, seps); //CYCLEID
		tok = strtok(NULL, seps); //ASSYLINE
		tok = strtok(NULL, seps); //COMPLOT
		tok = strtok(NULL, seps); //CUSTOMER
		tok = strtok(NULL, seps); //EVALCODE
		tok = strtok(NULL, seps); //FABSITE
		tok = strtok(NULL, seps); //LINE
		tok = strtok(NULL, seps); //NCACODE
		tok = strtok(NULL, seps); //NCECODE
		tok = strtok(NULL, seps); //NCFCODE
		tok = strtok(NULL, seps); //NCHCODE
		tok = strtok(NULL, seps); //NCMCODE
		tok = strtok(NULL, seps); //NCQCODE
		tok = strtok(NULL, seps); //NCTCODE
		tok = strtok(NULL, seps); //OPTCODE
		tok = strtok(NULL, seps); //TIER
		tok = strtok(NULL, seps); //OTHER
		tok = strtok(NULL, seps); //SALECODE
		tok = strtok(NULL, seps); //WEEKCODE
		tok = strtok(NULL, seps); //RESULT
		frmSeeLot->result->Text = (char*)(tok + 7);
		tok = strtok(NULL, seps); //MSG

		int qty = frmSeeLot->qty->Text.ToInt();
		nWriteCommunicationDM(qty, serverPcbQty	);

		int msgPos = bodyData.Pos("MSG=");
		String msg = bodyData.SubString(msgPos, bodyData.Length() - msgPos);
		frmSeeLot->msg->Text = msg;

		MainForm->_LotEndRetryCnt = 0;
	}
	else if (0 == func.AnsiCompareIC("FUNCTION_RPY=ONLINE_END"))
	{
		if(MainForm->b_TpConnect)
		{
			g_pTpBase->logComm(L"SYSTEM",L"RECV", L"'TYPE'",L"'TCP/IP'", L"'FUNCTION'",L"'ONLINE_END'");
		}

		//FUNCTION_RPY=ONLINE_END EQPID=AROUT-X02 EQPMODEL=ROUTER_SORTER LOTID=X007B00508 RESULT=PASS MSG=""
		tok = strtok(NULL, seps); //eqpid
		tok = strtok(NULL, seps); //eqpmodel
		tok = strtok(NULL, seps); //lotid
		tok = strtok(NULL, seps); //result
		String result = tok;
		tok = strtok(NULL, seps); //msg

		BOOL bRet = false;
		int ndm = onlineEndStep1 + MainForm->_onlineEndIndex;
		if ( 0 == result.CompareIC("RESULT=PASS"))
		{
			bRet = true;
		}
		else
		{
			nWriteCommunicationDM(4, ndm );	//fail
			MainForm->MachineHistoryData(bodyData);

			TFrmCdBox* pForm = new TFrmCdBox(this);
			pForm->setFlag(CD_OK);
			pForm->setTitle(func);
			pForm->setText(bodyData);
			pForm->ShowModal();
			delete pForm;


//            FrmCdBox->setFlag(CD_OK);
//            FrmCdBox->setTitle(func);
//            FrmCdBox->setText(bodyData);
//            FrmCdBox->ShowModal();
		}

		if (_ndmConfirm)
		{
			ndm = onlineEndStep1 + MainForm->_onlineEndIndex;
			if (bRet)
			{
				nWriteCommunicationDM(3, ndm );	//success

			}
			else
			{
				nWriteCommunicationDM(4, ndm );	//fail
				MainForm->MachineHistoryData(bodyData);
			}
		}

	}
	else if (0 == func.AnsiCompareIC("FUNCTION_RPY=SCRAP_INFO"))
	{
		if(MainForm->b_TpConnect)
		{
			g_pTpBase->logComm(L"SYSTEM",L"RECV", L"'TYPE'",L"'TCP/IP'", L"'FUNCTION'",L"'SCRAP_INFO'");
		}

		//FUNCTION_RPY=SCRAP_INFO EQPID=AROUT-X02 LOTID=X007B00508 SCRAP_CNT=8
		// SCRAP_INF0000=(SCRAP_CODE=3417 ARRAYSN=2MX16D003301MZVLVXXXXA039IXXXXXX_1 SERIAL= EQPMODEL=ROUTER_SORTER)
		// SCRAP_INF0001=(SCRAP_CODE=3417 ARRAYSN=2MX16D003301MZVLVXXXXA039IXXXXXX_2 SERIAL= EQPMODEL=ROUTER_SORTER)
		// SCRAP_INF0002=(SCRAP_CODE=3417 ARRAYSN=2MX16D003301MZVLVXXXXA039IXXXXXX_3 SERIAL= EQPMODEL=ROUTER_SORTER)
		// SCRAP_INF0003=(SCRAP_CODE=3417 ARRAYSN=2MX16D003301MZVLVXXXXA039IXXXXXX_4 SERIAL= EQPMODEL=ROUTER_SORTER)
		// SCRAP_INF0004=(SCRAP_CODE=3417 ARRAYSN=2MX16D003301MZVLVXXXXA039IXXXXXX_5 SERIAL= EQPMODEL=ROUTER_SORTER)
		// SCRAP_INF0005=(SCRAP_CODE=3417 ARRAYSN=2MX16D003301MZVLVXXXXA039IXXXXXX_6 SERIAL= EQPMODEL=ROUTER_SORTER)
		// SCRAP_INF0006=(SCRAP_CODE=3417 ARRAYSN=2MX16D003301MZVLVXXXXA039IXXXXXX_7 SERIAL= EQPMODEL=ROUTER_SORTER)
		// SCRAP_INF0007=(SCRAP_CODE=3417 ARRAYSN=2MX16D003301MZVLVXXXXA039IXXXXXX_8 SERIAL= EQPMODEL=ROUTER_SORTER)
		// RESULT=PASS MSG=""
		tok = strtok(NULL, seps); //EQPID
		tok = strtok(NULL, seps); //LOTID
		tok = strtok(NULL, seps); //SCRAP_CNT
		int scrapCnt = atoi( (char*)(tok + 10));

		AnsiString scrapCode[MAX_PATH], scrapArraySN[MAX_PATH];
		for(int i=0; i< scrapCnt; i++)
		{
			 char scrapSeps[]={"=  "};
			 tok = strtok(NULL, scrapSeps);	// SCRAP_INF001
			 tok = strtok(NULL, scrapSeps);	// SCRAP_CODE
			 tok = strtok(NULL, scrapSeps);	// CODE NUM
			 scrapCode[i] = tok;
			 tok = strtok(NULL, scrapSeps);	// ARRAYSN
			 tok = strtok(NULL, scrapSeps);	// ARRAY NUM
			 scrapArraySN[i] = tok;
			 tok = strtok(NULL, scrapSeps);	// SERIAL
			 tok = strtok(NULL, scrapSeps);	// EQPMODEL
			 tok = strtok(NULL, scrapSeps);	// EMPTY
		}

		tok = strtok(NULL, seps); //result
		String result = tok;
		MainForm->MachineHistoryData(result);
		tok = strtok(NULL, seps); //msg

		if (0 == result.CompareIC("RESULT=PASS"))
		{
			nWriteCommunicationDM(scrapCnt, serverScrapCnt );

			// g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_SCRAP_INFO_CUR;
			g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_SCRAP_INFO_CUR_COPY;
			// g_MMIComm->m_mmiToSeq.buffer.onlineEndHistory.scrapCnt = scrapCnt;
			g_MMIComm->m_mmiToSeq.buffer.onlineEndHistoryCopy.scrapCnt = scrapCnt;

			for(int i=0; i<scrapCnt; i++)
			{
				// strcpy( g_MMIComm->m_mmiToSeq.buffer.onlineEndHistory.scrapCode[i], scrapCode[i].c_str() );
				// strcpy( g_MMIComm->m_mmiToSeq.buffer.onlineEndHistory.scrapArraySN[i], scrapArraySN[i].c_str() );
				strcpy( g_MMIComm->m_mmiToSeq.buffer.onlineEndHistoryCopy.scrapCode[i], scrapCode[i].c_str() );
				strcpy( g_MMIComm->m_mmiToSeq.buffer.onlineEndHistoryCopy.scrapArraySN[i], scrapArraySN[i].c_str() );
			}
			//strcpy( g_MMIComm->m_mmiToSeq.buffer.onlineEndHistory.mergeLotID, _mergeLotID.c_str() );

			bool bRet = g_MMIComm->Send() &&  g_MMIComm->Recv();

			if(bRet)
			{
				for(int i=0; i<scrapCnt; i++)
				{
					frmSeeLot->scrapCount->Text = IntToStr(scrapCnt);
					frmSeeLot->sgScrap->Cells[0][i+1] = i+1;
					frmSeeLot->sgScrap->Cells[1][i+1] = scrapCode[i];
					frmSeeLot->sgScrap->Cells[2][i+1] = scrapArraySN[i];
				}
			}

			MainForm->_LotEndRetryCnt = 0;
		}
        else
        {
            MainForm->MachineHistoryData(bodyData);
			/*
			TFrmCdBox* pForm = new TFrmCdBox(this);
			pForm->setFlag(CD_OK);
			pForm->setTitle(func);
			pForm->setText(bodyData);
			pForm->ShowModal();
			delete pForm;
			*/
//            FrmCdBox->setFlag(CD_OK);
//            FrmCdBox->setTitle(func);
//            FrmCdBox->setText(bodyData);
//            FrmCdBox->ShowModal();
		}
	}
	else if (0 == func.AnsiCompareIC("FUNCTION_RPY=DELETE_SCRAP"))
	{
		if(MainForm->b_TpConnect)
		{
			g_pTpBase->logComm(L"SYSTEM",L"RECV", L"'TYPE'",L"'TCP/IP'", L"'FUNCTION'",L"'DELETE_SCRAP'");
		}

    	//FUNCTION_RPY=DELETE_SCRAP RESULT=PASS MSG=""
        tok = strtok(NULL, seps); //result
        String result = tok;

        if (0 == result.CompareIC("RESULT=PASS"))
        {
        }
		else
        {
			MainForm->MachineHistoryData(bodyData);
            TFrmCdBox* pForm = new TFrmCdBox(this);
            pForm->setFlag(CD_OK);
            pForm->setTitle(func);
            pForm->setText(bodyData);
            pForm->ShowModal();
			delete pForm;
//            FrmCdBox->setFlag(CD_OK);
//            FrmCdBox->setTitle(func);
//            FrmCdBox->setText(bodyData);
//            FrmCdBox->ShowModal();
		}
	}
	else if (0 == func.AnsiCompareIC("FUNCTION_RPY=CHANGE_MAZID"))
	{
		if(MainForm->b_TpConnect)
		{
			g_pTpBase->logComm(L"SYSTEM",L"RECV", L"'TYPE'",L"'TCP/IP'", L"'FUNCTION'",L"'CHANGE_MAZID'");
		}

		/*
		FUNCTION_RPY=CHANGE_MAZID
			EQP_ID=AROUT-X04
			MAGAZINE_ID=17301450
			RESULT=PASS
			MSG="CHANGMEMAGAZINEID TRANSACTION OK!"
		*/
		tok = strtok(NULL, seps); //EQP_ID=AROUT-X04
		tok = strtok(NULL, seps); //MAGAZINE_ID=17301450
		tok = strtok(NULL, seps); //RESULT=PASS
		String result = tok;
		tok = strtok(NULL, seps); //MSG="CHANGMEMAGAZINEID TRANSACTION OK!"


		int GdorRjComp = nReadCommunicationDM(lotEndStep); 	
		int LOT_END_STEP_GD_COVER_COMP = 7;
		int LOT_END_STEP_RJ_COVER_COMP = 8;

		if(GdorRjComp == LOT_END_STEP_GD_COVER_COMP)
		{
			if (0 == result.CompareIC("RESULT=PASS"))
				nWriteCommunicationDM(STATE_COMP, reqMgzInfoChgGood);
			else
				nWriteCommunicationDM(STATE_ERR, reqMgzInfoChgGood);
		}

		if(GdorRjComp == LOT_END_STEP_RJ_COVER_COMP)
		{
			if (0 == result.CompareIC("RESULT=PASS"))
				nWriteCommunicationDM(STATE_COMP, reqMgzInfoChgReject);
			else
				nWriteCommunicationDM(STATE_ERR, reqMgzInfoChgReject);
		}

		MainLog(bodyData);
	}
	else if (0 == func.AnsiCompareIC("FUNCTION_RPY=SORTER_LOT_END"))
	{
		if(MainForm->b_TpConnect)
		{
			g_pTpBase->logComm(L"SYSTEM",L"RECV", L"'TYPE'",L"'TCP/IP'", L"'FUNCTION'",L"'SORTER_LOT_END'");
		}

		/*
			FUNCTION_RPY=LOT_END
			EQP_ID=AROUT-X04
			LOT_ID=X0N90H0735
			REJECT_LOT_ID=X0N9RH1735
			RESULT=PASS
			MSG="TrackOut Success!! EQPSTEP[M033] LOTSTEP[M130] LOT STATE[HELD]"
		*/
		tok = strtok(NULL, seps); //EQP_ID=AROUT-X04
		tok = strtok(NULL, seps); //LOT_ID=X0N90H0735
		AnsiString goodLotID = (tok + 7);
		tok = strtok(NULL, seps); //RESULT=PASS
		String result = tok;
		tok = strtok(NULL, seps); //MSG="TrackOut Success!! EQPSTEP[M033] LOTSTEP[M130] LOT STATE[HELD]"

		if (0 == result.CompareIC("RESULT=PASS"))
		{
			nWriteCommunicationDM(3, lotEndStep); 	//success
			MainForm->SaveToCSVFile(String(goodLotID));
			frmSeeLot->setCycle(true);
			//FormSecsGemSet->TrackOut(); ceid9011 LOTOUT 처리로 변경 필요. 제어가 이벤트 처리하는게 좋음.
		}
		else
		{
			//MainForm->_bSeeLotShow = true;
			nWriteCommunicationDM(5, lotEndStep);	//fail
		}

		MainLog(bodyData);
	}
	else
	{
		//unsupported func
		MachineHistoryData("Unsupported Function : " + func);
	}


}
//---------------------------------------------------------------------------
BOOL TfrmTCComm::send(WideString data)
{
	if ( NULL == _pOhtSocket || !_pOhtSocket->Connected )
	{
		try
		{
			ClientSocket1->Address = _Address;
			ClientSocket1->Port = _Port.ToInt();
			ClientSocket1->Active = true;
			if (Timer1->Enabled)
			{
				MachineHistoryData("Fail to send. Another operation is not completed ! ");
				return FALSE;
			}
			_ohtBuf = data;
			Timer1->Tag = 0;
			Timer1->Enabled = true;
			return TRUE;

		}
		catch(Exception& e)
		{
			_ohtBuf = "";
			Timer1->Enabled = false;
			Timer1->Tag = 0;
			MachineHistoryData("Fail to connect : " + e.Message);
			return false;
		}
	}

	WideString header;
	header.printf(L"%016d", data.Length() );
	BOOL result = true;
	try
	{
		_pOhtSocket->SendText(header);
		_pOhtSocket->SendText(data);
		 MachineHistoryData(data );
		 result = true;
	}
	catch(Exception& e)
	{
		//e.Message -> 로그
		MachineHistoryData("Exception : " + e.Message  );
		result = false;
	}

	return result;
}
//---------------------------------------------------------------------------
BOOL TfrmTCComm::ohtPcbInfoRouter(AnsiString params[])
{
	//4개
	//FUNCTION=PCB_INFO_ROUTER
	//BCODE=2000000000L2MZ7LN250150800000001 STEPID=M033 MODEL=2.5_850EVO_PRO_6A EQPID=AROUT-X04
	AnsiString data;
	data.sprintf("FUNCTION=PCB_INFO_ROUTER BCODE=%s STEPID=%s MODEL=%s EQPID=%s",\
		params[0].c_str(),
		params[1].c_str(),
		params[2].c_str(),
		params[3].c_str());

	this->send(data);
}
//---------------------------------------------------------------------------
BOOL TfrmTCComm::ohtLotStart(AnsiString params[])
{
	//10개
	//FUNCTION=LOT_START
	//LOTID=X007B00508 PARTID=MZ7LN250HCHP-2BW00-G11 OPERID=AUTO STEP=M033 MODEL=ROUTER EQPID=AROUT-X04 SIMAX=YES AUTOLINE=YES MERGELOT=X007B00508 LOTQTY=600
	AnsiString data;
	data.sprintf("FUNCTION=LOT_START LOTID=%s PARTID=%s OPERID=%s STEP=%s MODEL=%s EQPID=%s SIMAX=%s AUTOLINE=%s MERGELOT=%s LOTQTY=%s",\
		params[0].c_str(),
		params[1].c_str(),
		params[2].c_str(),
		params[3].c_str(),
		params[4].c_str(),
		params[5].c_str(),
		params[6].c_str(),
		params[7].c_str(),
		params[8].c_str(),
		params[9].c_str());

	this->send(data);
}
//---------------------------------------------------------------------------
BOOL TfrmTCComm::ohtSeeLot(AnsiString params[])
{
	//3개
	//FUNCTION=SEE_LOT
	//LOTNO=X007B00508 EQPID=AROUT-X02 OPERID=AUTO
	AnsiString data;
	data.sprintf("FUNCTION=SEE_LOT LOTNO=%s EQPID=%s OPERID=%s",\
		params[0].c_str(),
		params[1].c_str(),
		params[2].c_str());

	this->send(data);

	if(MainForm->b_TpConnect)
	{
		g_pTpBase->logComm(L"SYSTEM",L"SEND", L"'TYPE'",L"'TCP/IP'", L"'FUNCTION'",L"'SEE_LOT'");
	}
}
//---------------------------------------------------------------------------
BOOL TfrmTCComm::ohtOnlineEnd( AnsiString params[], BOOL ndmConfirm)
{
	// FUNCTION=ONLINE_END
	// EQPID=AROUT-X02
	// EQPMODEL=ROUTER_SORTER
	// AUTOLINE=NO
	// LOTID=X007B00508
	// OPERID=AUTO
	// SCRAP_CNT=8
	// SCRAP_INFO001=(SCRAP_CODE=3417 ARRAYSN=2MX16D003301MZVLVXXXXA039IXXXXXX_1 SERIAL=)
	// SCRAP_INFO002=(SCRAP_CODE=3417 ARRAYSN=2MX16D003301MZVLVXXXXA039IXXXXXX_2 SERIAL=)
	// SCRAP_INFO003=(SCRAP_CODE=3417 ARRAYSN=2MX16D003301MZVLVXXXXA039IXXXXXX_3 SERIAL=)
	// SCRAP_INFO004=(SCRAP_CODE=3417 ARRAYSN=2MX16D003301MZVLVXXXXA039IXXXXXX_4 SERIAL=)
	// SCRAP_INFO005=(SCRAP_CODE=3417 ARRAYSN=2MX16D003301MZVLVXXXXA039IXXXXXX_5 SERIAL=)
	// SCRAP_INFO006=(SCRAP_CODE=3417 ARRAYSN=2MX16D003301MZVLVXXXXA039IXXXXXX_6 SERIAL=)
	// SCRAP_INFO007=(SCRAP_CODE=3417 ARRAYSN=2MX16D003301MZVLVXXXXA039IXXXXXX_7 SERIAL=)
	// SCRAP_INFO008=(SCRAP_CODE=3417 ARRAYSN=2MX16D003301MZVLVXXXXA039IXXXXXX_8 SERIAL=)
	_ndmConfirm = ndmConfirm;
	AnsiString data;
	data.sprintf("FUNCTION=ONLINE_END EQPID=%s SCRAP_CNT=%s EQPMODEL=%s AUTOLINE=%s LOTID=%s OPERID=%s ",\
		params[0].c_str(),
        params[1].c_str(),
        params[2].c_str(),
        params[3].c_str(),
        params[4].c_str(),
		params[5].c_str());

	int cnt = params[1].ToIntDef(0);

	for (int i=0; i<cnt; i++)
	{
		AnsiString number;
		number.sprintf("SCRAP_INFO%03d=(",i+1);

		data += number;
		data += params[6+i];
		data += ") ";
	}

	this->send(data);

	if(MainForm->b_TpConnect)
	{
		g_pTpBase->logComm(L"SYSTEM",L"SEND", L"'TYPE'",L"'TCP/IP'", L"'FUNCTION'",L"'ONLINE_END'");
	}
}
//---------------------------------------------------------------------------
BOOL TfrmTCComm::ohtScrapInfo(AnsiString params[])
{
	//3개
	//FUNCTION=SCRAP_INFO
	//LOTID=X007B00508 EQPID=AROUT-X02 AUTOLINE=NO
	AnsiString data;
	data.sprintf("FUNCTION=SCRAP_INFO EQPID=%s LOTID=%s AUTOLINE=%s",\
		params[0].c_str(),
        params[1].c_str(),
        params[2].c_str());

	this->send(data);

	if(MainForm->b_TpConnect)
	{
		g_pTpBase->logComm(L"SYSTEM",L"SEND", L"'TYPE'",L"'TCP/IP'", L"'FUNCTION'",L"'SCRAP_INFO'");
	}
}
//---------------------------------------------------------------------------
BOOL TfrmTCComm::ohtDeleteScrap(AnsiString params[])
{
	//5개
	//FUNCTION=DELETE_SCRAP
    //EQPID=AROUT-X02 LOTID=X007B00508 SERIAL= ARRAYSN=2MX16D003303MZVLVXXXXA009JXXXXXX_8 AUTOLINE=NO
	AnsiString data;
	data.sprintf("FUNCTION=DELETE_SCRAP EQPID=%s LOTID=%s SERIAL=%s ARRAYSN=%s AUTOLINE=%s",\
		params[0].c_str(),
        params[1].c_str(),
		params[2].c_str(),
        params[3].c_str(),
        params[4].c_str());

	this->send(data);

	if(MainForm->b_TpConnect)
	{
		g_pTpBase->logComm(L"SYSTEM",L"SEND", L"'TYPE'",L"'TCP/IP'", L"'FUNCTION'",L"'DELETE_SCRAP'");
	}
}
//---------------------------------------------------------------------------
BOOL TfrmTCComm::ohtChangeMgzId(AnsiString params[])
{
	// 4개
	/*
	FUNCTION=CHANGE_MAZID
	EQP_ID=AROUT-X04
	MAGAZINE_ID=17301450
	LOT_ID=X0NM0W0735
	*/
	AnsiString data;
	data.sprintf("FUNCTION=CHANGE_MAZID EQP_ID=%s MAGAZINE_ID=%s LOT_ID=%s",\
		params[0].c_str(),
		params[1].c_str(),
		params[2].c_str());

	this->send(data);

	if(MainForm->b_TpConnect)
	{
		g_pTpBase->logComm(L"SYSTEM",L"SEND", L"'TYPE'",L"'TCP/IP'", L"'FUNCTION'",L"'CHANGE_MAZID'");
	}
}
//---------------------------------------------------------------------------
BOOL TfrmTCComm::ohtLotEnd(AnsiString params[])
{
	// 5개
	/*
	FUNCTION=LOT_END
		EQP_ID=AROUT-X04
		LOT_ID=X0NM0W0735
		PORT_ID=AROUT-X04_O2
		OPER_ID=AUTO
		AUTOLINE=NO
	*/
	AnsiString data;
	data.sprintf("FUNCTION=SORTER_LOT_END EQPID=%s LOTID=%s PORTID=%s OPERID=%s AUTOLINE=%s",\
		params[0].c_str(),
		params[1].c_str(),
		params[2].c_str(),
		params[3].c_str(),
		params[4].c_str());

	this->send(data);

	if(MainForm->b_TpConnect)
	{
		g_pTpBase->logComm(L"SYSTEM",L"SEND", L"'TYPE'",L"'TCP/IP'", L"'FUNCTION'",L"'SORTER_LOT_END'");
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmTCComm::FormDestroy(TObject *Sender)
{
	ClientSocket1->OnDisconnect = NULL;
	ClientSocket1->Active = false;

	if (_fp)
    	fclose(_fp);
	_fp = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TfrmTCComm::Clear2Click(TObject *Sender)
{
	for (int i=1; i< StringGrid1->RowCount; i++)
		StringGrid1->Cells[1][i] = "";

}
//---------------------------------------------------------------------------
void __fastcall TfrmTCComm::FormShow(TObject *Sender)
{
	for (int i=1; i< StringGrid1->RowCount; i++)
		StringGrid1->Cells[0][i] = IntToStr(i);

	StringGrid1->Cells[1][0] = "Params";

	TIniFile* configIni = new TIniFile(ExtractFilePath(Application->ExeName)+"Config.ini");
	Edit1->Text = configIni->ReadString("TC","IP", "");
	Edit2->Text = configIni->ReadString("TC","PORT", "");

	delete configIni;
}
//---------------------------------------------------------------------------
void __fastcall TfrmTCComm::SpeedButton5Click(TObject *Sender)
{
	AnsiString params[] ={ \
    	StringGrid1->Cells[1][1],
        StringGrid1->Cells[1][2],
        StringGrid1->Cells[1][3],
        StringGrid1->Cells[1][4]};
	this->ohtPcbInfoRouter(params);
}
//---------------------------------------------------------------------------
void __fastcall TfrmTCComm::SpeedButton6Click(TObject *Sender)
{
	AnsiString params[] ={ \
    	StringGrid1->Cells[1][1],
        StringGrid1->Cells[1][2],
        StringGrid1->Cells[1][3],
        StringGrid1->Cells[1][4],
        StringGrid1->Cells[1][5],
    	StringGrid1->Cells[1][6],
        StringGrid1->Cells[1][7],
        StringGrid1->Cells[1][8],
        StringGrid1->Cells[1][9],
    	StringGrid1->Cells[1][10]
        };
	this->ohtLotStart( params);
}
//---------------------------------------------------------------------------
void __fastcall TfrmTCComm::SpeedButton2Click(TObject *Sender)
{
	AnsiString params[] ={ \
    	StringGrid1->Cells[1][1],
        StringGrid1->Cells[1][2],
        StringGrid1->Cells[1][3]};
	this->ohtSeeLot( params);
}
//---------------------------------------------------------------------------
void __fastcall TfrmTCComm::SpeedButton8Click(TObject *Sender)
{
	INT count = StringGrid1->Cells[1][6].ToInt();

	AnsiString params[100] = { \
    	StringGrid1->Cells[1][1],
        StringGrid1->Cells[1][2],
		StringGrid1->Cells[1][3],
		StringGrid1->Cells[1][4],
		StringGrid1->Cells[1][5],
		StringGrid1->Cells[1][6]};

	for (int i=0; i< count; i++)
		params[i+6] = StringGrid1->Cells[1][i+7];

	this->ohtOnlineEnd( params);

}
//---------------------------------------------------------------------------
void __fastcall TfrmTCComm::SpeedButton9Click(TObject *Sender)
{
	AnsiString params[] ={ \
		StringGrid1->Cells[1][1],
		StringGrid1->Cells[1][2],
		StringGrid1->Cells[1][3]};
	this->ohtScrapInfo( params);
}
//---------------------------------------------------------------------------
void __fastcall TfrmTCComm::SpeedButton10Click(TObject *Sender)
{
	AnsiString params[] ={ \
		StringGrid1->Cells[1][1],
		StringGrid1->Cells[1][2],
		StringGrid1->Cells[1][3],
		StringGrid1->Cells[1][4],
		StringGrid1->Cells[1][5]};
	this->ohtDeleteScrap( params);
}
//---------------------------------------------------------------------------
void __fastcall TfrmTCComm::SpeedButton11Click(TObject *Sender)
{
	AnsiString params[] ={ \
		StringGrid1->Cells[1][1],
		StringGrid1->Cells[1][2],
		StringGrid1->Cells[1][3],
		StringGrid1->Cells[1][4],
		StringGrid1->Cells[1][5]};
	this->ohtLotEnd( params);
}
//---------------------------------------------------------------------------

void __fastcall TfrmTCComm::ClientSocket1Error(TObject *Sender, TCustomWinSocket *Socket,
		  TErrorEvent ErrorEvent, int &ErrorCode)
{
	_pOhtSocket = NULL;
	ErrorCode = 0;
	MachineHistoryData("Socket Error : " + IntToStr(ErrorCode));
}
//---------------------------------------------------------------------------
void __fastcall TfrmTCComm::Timer1Timer(TObject *Sender)
{
	if (_ohtBuf != "")
	{
		if (!_pOhtSocket || !_pOhtSocket->Connected)
		{
			if (Timer1->Tag > 100)
			{
				Timer1->Tag = 0;
				Timer1->Enabled = false;
				_pOhtSocket = NULL;
				ClientSocket1->Active = false;

				MachineHistoryData("Send to timed out  : " + _ohtBuf);
				return;
			}
			else
			{
				Timer1->Tag = Timer1->Tag+1;
				return;
			}
		}

		WideString data = _ohtBuf;
		WideString header;
		header.printf(L"%016d", data.Length() );
		BOOL result = true;
		try
		{
			_pOhtSocket->SendText(header);
			_pOhtSocket->SendText(data);
			MachineHistoryData(data );
			result = true;
		}
		catch(Exception& e)
		{
			//e.Message -> 로그
			MachineHistoryData("Exception : " + e.Message  );
			result = false;
		}

		_ohtBuf = "";
		Timer1->Enabled = false;
		Timer1->Tag = 0;
	}
}
//---------------------------------------------------------------------------
void  TfrmTCComm::MachineHistoryData(String StrTemp)
{
	String logMessage = Now().FormatString("yyyy-mm-dd hh:mm:ss") + " : " + StrTemp;
	TDateTime dt = Now();
	String fileName = dt.FormatString("yyyy-mm-dd") + ".txt";

	if (_currentLogFileName != fileName)
	{
		if (_fp)
			fclose(_fp);
		String fullPathName = "C:\\KOSES\\History\\TCCommHistory\\" + fileName;
		_fp = _wfopen( fullPathName.c_str(), L"at");
        assert(_fp);
        _currentLogFileName = fileName;
    }

    fputws(logMessage.c_str(), _fp);
    fputws(L"\r\n", _fp);
	Memo1->Lines->Add(logMessage);
    SendMessage(Memo1->Handle, WM_VSCROLL, SB_BOTTOM, 0);

    if(Memo1->Lines->Count > 1000)
    {
    	fflush(_fp);
    	Memo1->Lines->BeginUpdate();
        Memo1->SelStart = 0;
		Memo1->SelLength = Memo1->Perform(EM_LINEINDEX, 1000, 0);
        Memo1->SelText = "";
		Memo1->Lines->EndUpdate();
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmTCComm::sbManualClick(TObject *Sender)
{
	Panel1->Visible = !Panel1->Visible;
}
//---------------------------------------------------------------------------
void	TfrmTCComm::TccommInitializeProcess()
{
	if (_pOhtSocket)
	{
		ClientSocket1->Active = false;
		return;
	}

	TIniFile* configIni = new TIniFile(ExtractFilePath(Application->ExeName)+"Config.ini");
	_Address = configIni->ReadString("TC","IP", "");
	_Port = configIni->ReadString("TC","PORT", "0");

	delete configIni;

	ClientSocket1->Address = _Address;
	ClientSocket1->Port = _Port.ToInt();

	try
	{
		ClientSocket1->Active = true;
		MachineHistoryData("TCComm Initialize!");
	}
	catch(Exception& e)
	{
		MachineHistoryData("Fail to connect : " + e.Message);
	}

	return;
}
//---------------------------------------------------------------------------
