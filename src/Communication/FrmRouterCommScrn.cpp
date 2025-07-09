//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FrmRouterCommScrn.h"
#include "MainFormScrn.h"
#include "PACKET.h"
#include <stdio.h>

#include "..\..\common\communication.h"
#include "fLotEventHistory.h"

#include <vcl.h>
#include <sstream>
#include <string>
#include <iomanip>
#include <iostream>

#pragma hdrstop

using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma resource "*.dfm"
TFrmRouterComm *FrmRouterComm;
//---------------------------------------------------------------------------
__fastcall TFrmRouterComm::TFrmRouterComm(TComponent* Owner)
	: TForm(Owner)
{
	m_SorterSocket = NULL;
	m_SorterDeviceInfoSocket = NULL;

}
//---------------------------------------------------------------------------
void __fastcall TFrmRouterComm::BtnRouterCommClick(TObject *Sender)
{
	if(ChkRouterComm->Checked == true)
	{
		ChkRouterComm->Checked = false;
		BtnRouterComm->Caption ="COMMUNICATION OFF";
		SorterServer->Active = false;
		SorterDeviceInfoServer->Active = false;
		SorterQcSocket->Active = false;
		nWriteCommunicationDM(0,flagRouterComm);
	}
	else
	{
		ChkRouterComm->Checked = true;
		BtnRouterComm->Caption ="COMMUNICATION ON";
		SorterServer->Active = true;
		SorterDeviceInfoServer->Active = true;
		SorterQcSocket->Active = true;
		nWriteCommunicationDM(1,flagRouterComm);
	}

	TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini");
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini"))
	{
		ini->WriteBool("SORTERCOMM","ONOFFChk",ChkRouterComm->Checked);
	}
	delete ini;
}
//---------------------------------------------------------------------------
void TFrmRouterComm::StartRouterCommChkSwitch()
{
	TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini");
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini"))
    {
        if(ini->ReadBool("SORTERCOMM","ONOFFChk",true) == true)
        {
        	try
            {
				SorterServer->Active = true;
				SorterDeviceInfoServer->Active = true;
				SorterQcSocket->Active = true;
			}
			catch(Exception& e)
            {
            	MMILOGHistoryData("Exception : " + e.Message);
                delete ini;
                return ;
			}

            ChkRouterComm->Checked = true;
			BtnRouterComm->Caption ="COMMUNICATION ON";
		}
		else
		{
			ChkRouterComm->Checked = false;
			BtnRouterComm->Caption ="COMMUNICATION OFF";
		}
    }
    else
    {
		MessageDlg("Setup.ini File not found!", mtWarning, TMsgDlgButtons() << mbOK, 0);
    }

    delete ini;
}
//---------------------------------------------------------------------------

void TFrmRouterComm::MMILOGHistoryData(String StrTemp)
{
	MainForm->MachineHistoryData( "Router/Sorter Comm : " + StrTemp);
}
//---------------------------------------------------------------------------
void __fastcall TFrmRouterComm::SorterServerClientConnect(TObject *Sender, TCustomWinSocket *Socket)

{
	MMILOGHistoryData("Client Connected");
	strRecvBuffer = "";
	m_SorterSocket = Socket;
	nWriteCommunicationDM(1,flagRouterComm);
}
//---------------------------------------------------------------------------
void __fastcall TFrmRouterComm::SorterServerClientDisconnect(TObject *Sender, TCustomWinSocket *Socket)

{
	MMILOGHistoryData("Client Disconnected");
    strRecvBuffer = "";
	m_SorterSocket = NULL;
	nWriteCommunicationDM(0,flagRouterComm);
}
//---------------------------------------------------------------------------
void __fastcall TFrmRouterComm::SorterServerClientError(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode)
{
	MMILOGHistoryData("Connection have a problem : " + IntToStr(ErrorCode));
    ErrorCode= 0;
    strRecvBuffer = "";
	m_SorterSocket = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TFrmRouterComm::SorterServerClientRead(TObject *Sender, TCustomWinSocket *Socket)
{
	BOOL bRet = true;
    LOT_INFO lotInfo ={0,};

    int lotInfoBytes = sizeof(LOT_INFO);
	int totalBytes = 0;

	try
	{
        DWORD tick = ::GetTickCount();
        do
        {
            if (  (::GetTickCount() - tick ) > 500)
            {
            	bRet = false;
                if (totalBytes > 0)
					MMILOGHistoryData("Fail to receive lot information from router. timed out !");
				break;
            }
			int bytes = Socket->ReceiveBuf( ((char*)&lotInfo) + totalBytes, sizeof(lotInfo) - totalBytes);
            if (bytes <= 0)
            {
				::Sleep(1);
            	continue;
            }

            totalBytes += bytes;
        }
        while(lotInfoBytes != totalBytes);
    }
	catch (Exception &e)
	{
		MMILOGHistoryData("Fail to received lot information from router :" + e.Message );
		bRet = false;
	}

	try
	{
		if (!bRet)
		{

		}
		else
		{

			//write lot info
			g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_RCV_LOT_INFO; // 69
			memcpy( (void*)&g_MMIComm->m_mmiToSeq.buffer.lotInfo, (void*)&lotInfo, sizeof(lotInfo));
			if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
			{
				MMILOGHistoryData("Lot information received");
				MMILOGHistoryData(" carrier id : " + String(g_MMIComm->m_mmiToSeq.buffer.lotInfo.carrierID ));
				MMILOGHistoryData(" lot id : " + String(g_MMIComm->m_mmiToSeq.buffer.lotInfo.lotID ));
				String mergeId = String(g_MMIComm->m_mmiToSeq.buffer.lotInfo.mergeLotID );
				MMILOGHistoryData(" merge lot id : " + mergeId);
				MMILOGHistoryData(" lot qty : " + IntToStr(g_MMIComm->m_mmiToSeq.buffer.lotInfo.lotQty ));
				MMILOGHistoryData(" test result : " + String(g_MMIComm->m_mmiToSeq.buffer.lotInfo.pcbTestResult ));
				MMILOGHistoryData(" pcb barcode : " + String(g_MMIComm->m_mmiToSeq.buffer.lotInfo.pcbBarcode));
				MMILOGHistoryData(" step seq : " + String(g_MMIComm->m_mmiToSeq.buffer.lotInfo.step));
				MMILOGHistoryData(" Tray 1 Mark: " + String(g_MMIComm->m_mmiToSeq.buffer.lotInfo.tray1Mark));
				//MMILOGHistoryData(" Tray 1 Oht Qty : " + String(g_MMIComm->m_mmiToSeq.buffer.lotInfo.tray1OhtQty));
				//MMILOGHistoryData(" Tray 1 Oht ProduQty : " + String(g_MMIComm->m_mmiToSeq.buffer.lotInfo.tray1ProdQty));
				MMILOGHistoryData(" Tray 1 ProdQty : " + String(g_MMIComm->m_mmiToSeq.buffer.lotInfo.tray1ProdQty));

				MMILOGHistoryData(" S_AOI_SCRAP_CODE_LIST : " + String(g_MMIComm->m_mmiToSeq.buffer.lotInfo.aoiScrapCodeList ));
				MMILOGHistoryData(" S_AOI_SCRAP_RESULT : " + String(g_MMIComm->m_mmiToSeq.buffer.lotInfo.aoiScrapResult));

				bRet = true;

				frmLotDataHistory->Record_LotIn(AnsiString(mergeId), AnsiString(Get_RecipeName()));
			}
			else
			{
				bRet = false;
			}

			if (bRet)
			{
				if (m_SorterSocket)
					m_SorterSocket->SendText("AK;");
			}
			else
			{
				if (m_SorterSocket)
					m_SorterSocket->SendText("NK;");

				MMILOGHistoryData("Fail to receive lot info. so nacked !");
			}
		}
	}
	catch (Exception &e)
	{
		MMILOGHistoryData("Lot information received Error-1 :" + e.Message );
	}


}
//---------------------------------------------------------------------------
void __fastcall TFrmRouterComm::BtnCloseClick(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------



void __fastcall TFrmRouterComm::Label1Click(TObject *Sender)
{
//	frmLotDataHistory->Record_LotIn("lotidtest","jobname");
}
//---------------------------------------------------------------------------

void __fastcall TFrmRouterComm::SorterDeviceInfoServerClientConnect(TObject *Sender,
		  TCustomWinSocket *Socket)
{
	MMILOGHistoryData("Client Deive Info Connected");
	strRecvDeviceInfo = "";
	m_SorterDeviceInfoSocket = Socket;
}
//---------------------------------------------------------------------------

void __fastcall TFrmRouterComm::SorterDeviceInfoServerClientDisconnect(TObject *Sender,
          TCustomWinSocket *Socket)
{
	MMILOGHistoryData("Client Deive Info Disconnected");
	strRecvDeviceInfo = "";
	m_SorterDeviceInfoSocket = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TFrmRouterComm::SorterDeviceInfoServerClientError(TObject *Sender,
		  TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
	MMILOGHistoryData("Connection Deive Info have a problem : " + IntToStr(ErrorCode));
	ErrorCode= 0;
	strRecvDeviceInfo = "";
	m_SorterDeviceInfoSocket = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TFrmRouterComm::SorterDeviceInfoServerClientRead(TObject *Sender,
          TCustomWinSocket *Socket)
{
	BOOL bRet = true;
    LOT_INFO lotInfo ={0,};

    int lotInfoBytes = sizeof(LOT_INFO);
    int totalBytes = 0;

	try
	{
        DWORD tick = ::GetTickCount();
        do
        {
            if (  (::GetTickCount() - tick ) > 500)
            {
            	bRet = false;
                if (totalBytes > 0)
					MMILOGHistoryData("Fail to receive lot information from router. timed out !");
            	break;
            }
			int bytes = Socket->ReceiveBuf( ((char*)&lotInfo) + totalBytes, sizeof(lotInfo) - totalBytes);
            if (bytes <= 0)
            {
            	::Sleep(1);
				continue;
			}

			totalBytes += bytes;
		}
		while(lotInfoBytes != totalBytes);
    }
	catch (Exception &e)
	{
		MMILOGHistoryData("Fail to received lot information from router :" + e.Message );
		bRet = false;
	}


	try
	{
		if (!bRet)
		{

		}
		else
		{

			//write lot info
			g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_BUFFER_LOTINFO; // 83
			memcpy( (void*)&g_MMIComm->m_mmiToSeq.buffer.lotInfo, (void*)&lotInfo, sizeof(lotInfo));
			if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
			{
				MMILOGHistoryData("[Mgz Lot information received]");
				MMILOGHistoryData(" carrier id : " + String(g_MMIComm->m_mmiToSeq.buffer.lotInfo.carrierID ));
				MMILOGHistoryData(" lot id : " + String(g_MMIComm->m_mmiToSeq.buffer.lotInfo.lotID ));
				String mergeId = String(g_MMIComm->m_mmiToSeq.buffer.lotInfo.mergeLotID );
				MMILOGHistoryData(" merge lot id : " + mergeId);
				MMILOGHistoryData(" lot qty : " + IntToStr(g_MMIComm->m_mmiToSeq.buffer.lotInfo.lotQty ));
				MMILOGHistoryData(" test result : " + String(g_MMIComm->m_mmiToSeq.buffer.lotInfo.pcbTestResult ));
				MMILOGHistoryData(" pcb barcode : " + String(g_MMIComm->m_mmiToSeq.buffer.lotInfo.pcbBarcode));
				MMILOGHistoryData(" Tray 1 Mark: " + String(g_MMIComm->m_mmiToSeq.buffer.lotInfo.tray1Mark));
				MMILOGHistoryData(" Tray 1 Oht Qty : " + String(g_MMIComm->m_mmiToSeq.buffer.lotInfo.tray1OhtQty));
				MMILOGHistoryData(" Tray 1 Oht ProduQty : " + String(g_MMIComm->m_mmiToSeq.buffer.lotInfo.tray1ProdQty));
				bRet = true;
			}
			else
			{
				bRet = false;
			}

			if (bRet)
			{
				if (m_SorterDeviceInfoSocket)
					m_SorterDeviceInfoSocket->SendText("AK;");
			}
			else
			{
				if (m_SorterDeviceInfoSocket)
					m_SorterDeviceInfoSocket->SendText("NK;");

				MMILOGHistoryData("Fail to receive Mgz lot info. so nacked !");
			}
		}
	}
	catch (Exception &e)
	{
		MMILOGHistoryData("Lot information received Error-2 :" + e.Message );
	}


	/*  RMS에선 미사용
	BOOL bRet = true;
	strRecvDeviceInfo += Socket->ReceiveText();

	if ( strRecvDeviceInfo.Pos(";") > 0)
	{
		MMILOGHistoryData("Device Info Recv:"+ strRecvDeviceInfo);

		int nGroupNo, nRecipeNo;

		CHAR seps[]={",;"};
		CHAR buf [128];
		strcpy(buf, strRecvDeviceInfo.c_str());
		strRecvDeviceInfo = "";

		String StrTemp = ::strtok(buf, seps);
		if(StrTemp == "GROUP")
		{
			StrTemp = ::strtok(buf, NULL);
			nGroupNo = StrTemp.ToInt();
			StrTemp = ::strtok(buf, NULL);
			if(StrTemp == "RECIPE")
			{
				StrTemp = ::strtok(buf, NULL);
				nRecipeNo = StrTemp.ToInt();

				// RMS 사용으로 미사용
				//nWriteCommunicationDM(nGroupNo, autoDeviceChg_GroupNo);
				//nWriteCommunicationDM(nRecipeNo, autoDeviceChg_RecipeNo);
			}
			else
				bRet = false;
		}
		else
			bRet = false;
	}
	else
	{
		// 문자열 종결자(;)가 발견되지 않음
		// 다음번꺼에 도착할지 모름
	}


	if (bRet)
	{
		//MMILOGHistoryData("Lot information received : " + String(lotInfo.lotID));
		if (m_SorterSocket)
			m_SorterSocket->SendText("AK;");
	}
	else
	{
		if (m_SorterSocket)
			m_SorterSocket->SendText("NK;");

		MMILOGHistoryData("Fail to receive Device info. so nacked !");
	}     */
}
//---------------------------------------------------------------------------

void __fastcall TFrmRouterComm::Button1Click(TObject *Sender)
{

	String bb = "13.3";
	double dbTempX = StrToFloat( "13.33" );
	double dbTempX111 = StrToFloatDef(bb,0);


}
//---------------------------------------------------------------------------

void __fastcall TFrmRouterComm::SorterQcSocketClientConnect(TObject *Sender, TCustomWinSocket *Socket)
{
	MMILOGHistoryData("Client QC Info Connected");
	m_SorterQcSocket = Socket;
}
//---------------------------------------------------------------------------

void __fastcall TFrmRouterComm::SorterQcSocketClientDisconnect(TObject *Sender, TCustomWinSocket *Socket)

{
	MMILOGHistoryData("Client QC Info Disconnected");
	strRecvQcInfo = "";
	m_SorterQcSocket = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TFrmRouterComm::SorterQcSocketClientError(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode)
{
	MMILOGHistoryData("Connection QC Info have a problem : " + IntToStr(ErrorCode));
	ErrorCode= 0;
	strRecvQcInfo = "";
	m_SorterQcSocket = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TFrmRouterComm::SorterQcSocketClientRead(TObject *Sender, TCustomWinSocket *Socket)

{
	String resp = Socket->ReceiveText();
	MMILOGHistoryData(String().sprintf(L"RX: QC Info( %s )",resp));

	if (0 == resp.Compare("AK;"))
	{
	}
	else
	{
	}
	/*
	if (bRet)
	{
		//MMILOGHistoryData("Lot information received : " + String(lotInfo.lotID));
		if (m_SorterDeviceInfoSocket)      
			m_SorterDeviceInfoSocket->SendText("AK;");
	}
	else
	{
		if (m_SorterDeviceInfoSocket)
			m_SorterDeviceInfoSocket->SendText("NK;");
	}
	*/
}
//---------------------------------------------------------------------------
BOOL TFrmRouterComm::qcInfoSend(AUTOFEEDBACK_INFO& qcInfo)
{
	BOOL bRet = true;
	try
	{
		int bytes = 0;
			bytes = m_SorterQcSocket->SendBuf( &qcInfo , sizeof(qcInfo));

		if (bytes != sizeof(qcInfo))
			bRet = false;

		ostringstream oss;
		oss << qcInfo.qcBridgeDataOffset[0][0];
		string sOffsetValue = oss.str();

		nWriteCommunicationDM(0, stateQcDataSendR);
		MMILOGHistoryData(String().sprintf(L"TX: Auto FeedBack Info To Router : qcStageNo( %s ) qcBridgeCnt( %s ) qcBridgeDataOffset( %s )",String(qcInfo.qcStageNo), String(qcInfo.qcBridgeCnt[0]), String(sOffsetValue.c_str()) ));
	}
	catch(Exception& e)
	{
		MMILOGHistoryData("Exception on Send Auto FeedBack Info To Router : "  + e.Message);
		bRet = false;
		return false;
	}
	if (!bRet)
		this->MMILOGHistoryData("Fail to Send Auto FeedBack Info To Router");

	return bRet;
}
//---------------------------------------------------------------------------

