//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormLaserCommSetScrn.h"
#include "MainFormScrn.h"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include "BaseComm.h"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma resource "*.dfm"
TFormLaserCommSet *FormLaserCommSet;


#define   _LASER1_                 1
#define   _LASER2_                 2
#define   _LASER3_                 3
#define   _LASER4_                 4

#define   _POSARRAY_               1
#define   _AUTOCAL_                2
#define   _JOBCHANGE_              3


#define   _RETRYCNT_               10

//---------------------------------------------------------------------------
__fastcall TFormLaserCommSet::TFormLaserCommSet(TComponent* Owner)
	: TForm(Owner)
{
    bAutoCalWaitFlag = false;

	bPosArrayWaitFlag1 = false;
    bPosArrayWaitFlag2 = false;
    bPosArrayWaitFlag3 = false;
    bPosArrayWaitFlag4 = false;

    bJobChangeWaitFlag1 = false;
    bJobChangeWaitFlag1 = false;
    bJobChangeWaitFlag1 = false;
    bJobChangeWaitFlag1 = false;
    _nCommTryCnt_ = 0;
}
//---------------------------------------------------------------------------
void TFormLaserCommSet::LaserHistoryData(String StrTemp)
{
	LaserMemo->Lines->Add(DateTimeToStr(Now()) + ": " + StrTemp);
	LaserMemo->Refresh();

	if(LaserMemo->Lines->Count > 1000)
	{
		TDateTime dt = Now();
		String FolderName = dt.FormatString("yyyy-mm-dd");
		String FileName = dt.FormatString("yyyy-mm-dd hh-nn-ss");
		String FullPath  =  "C:\\KOSES\\History\\LaserHistory\\"+ FolderName +"\\";
		ForceDirectories(FullPath);

		LaserMemo->Lines->SaveToFile(FullPath + FileName+".txt");

		LaserMemo->Clear();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormLaserCommSet::BtnSaveLogClick(TObject *Sender)
{
    TDateTime dt = Now();
    String FolderName = dt.FormatString("yyyy-mm-dd");
    String FileName = dt.FormatString("yyyy-mm-dd hh-nn-ss");
    String FullPath  =  "C:\\KOSES\\History\\LaserHistory\\"+ FolderName +"\\";
    ForceDirectories(FullPath);

    LaserMemo->Lines->SaveToFile(FullPath + FileName+".txt");

    LaserMemo->Clear();

	LaserHistoryData("LOG Saved"+ FullPath + FileName+".txt");
}
//---------------------------------------------------------------------------

void __fastcall TFormLaserCommSet::LaserMemoChange(TObject *Sender)
{
	SendMessage(LaserMemo->Handle, WM_VSCROLL, SB_BOTTOM, 0);
}
//---------------------------------------------------------------------------

void __fastcall TFormLaserCommSet::HelloTimerTimer(TObject *Sender)
{
	LaserHelloChk(_LASER1_);
	LaserHelloChk(_LASER2_);
	LaserHelloChk(_LASER3_);
	LaserHelloChk(_LASER4_);
}
//---------------------------------------------------------------------------

void TFormLaserCommSet::LaserHelloChk(int nLaserIndex)
{
	try
	{
		AnsiString Hellobuf = "HELLO;";
		if(nLaserIndex == _LASER1_)
		{
			if(TcpClientLaser1->Active == true)
			{
                TcpClientLaser1->Socket->SendText(Hellobuf);
                LaserHistoryData("Laser1 : Hello Send");
			}
		}
		else if(nLaserIndex == _LASER2_)
		{
			if(TcpClientLaser2->Active == true)
			{
                TcpClientLaser2->Socket->SendText(Hellobuf);
                LaserHistoryData("Laser2 : Hello Send");
			}

		}
		else if(nLaserIndex == _LASER3_)
		{
			if(TcpClientLaser3->Active == true)
			{
                TcpClientLaser3->Socket->SendText(Hellobuf);
                LaserHistoryData("Laser3 : Hello Send");
			}
		}
		else if(nLaserIndex == _LASER4_)
		{
			if(TcpClientLaser4->Active == true)
			{
                TcpClientLaser4->Socket->SendText(Hellobuf);
                LaserHistoryData("Laser4 : Hello Send");
			}
		}
	}
	catch (Exception &e)
	{
		LaserHistoryData("LaserHelloChk" + e.Message );
	}
}
//---------------------------------------------------------------------------
void TFormLaserCommSet::StartLaserChkSwitch()
{
	TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini");
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini"))
	{
		//_nLaserEnableCnt_  = ini->ReadInteger("LASERENABLE","COUNT",2);

		if(ini->ReadBool("LASER1","ONOFFChk",true) == true)
		{
			ChkLaser1Heartbeat->Checked = true;
			BtnLaserComm1->Caption ="LASER1 ON";
			TcpClientLaser1->Active = true;
            Status_Led(MainForm->MainPanelLed11 ,_STATUS_LED_GREEN_ , true , "ON");
		}
		else
		{
			ChkLaser1Heartbeat->Checked = false;
			BtnLaserComm1->Caption ="LASER1 OFF";
            Status_Led(MainForm->MainPanelLed11 ,_STATUS_LED_GREEN_ , false , "OFF");
		}

		if(ini->ReadBool("LASER2","ONOFFChk",true) == true)
		{
			ChkLaser2Heartbeat->Checked = true;
			BtnLaserComm2->Caption ="LASER2 ON";
			TcpClientLaser2->Active = true;
            Status_Led(MainForm->MainPanelLed12 ,_STATUS_LED_GREEN_ , true , "ON");

		}
		else
		{
			ChkLaser2Heartbeat->Checked = false;
			BtnLaserComm2->Caption ="LASER2 OFF";
            Status_Led(MainForm->MainPanelLed12 ,_STATUS_LED_GREEN_ , false , "OFF");
		}

		if(ini->ReadBool("LASER3","ONOFFChk",true) == true)
		{
			ChkLaser3Heartbeat->Checked = true;
			BtnLaserComm3->Caption ="LASER3 ON";
			TcpClientLaser3->Active = true;
            Status_Led(MainForm->MainPanelLed13 ,_STATUS_LED_GREEN_ , true , "ON");
		}
		else
		{
			ChkLaser3Heartbeat->Checked = false;
			BtnLaserComm3->Caption ="LASER3 OFF";
            Status_Led(MainForm->MainPanelLed13 ,_STATUS_LED_GREEN_ , false , "OFF");
		}

		if(ini->ReadBool("LASER4","ONOFFChk",true) == true)
		{
			ChkLaser4Heartbeat->Checked = true;
			BtnLaserComm4->Caption ="LASER4 ON";
			TcpClientLaser4->Active = true;
            Status_Led(MainForm->MainPanelLed14 ,_STATUS_LED_GREEN_ , true , "ON");

		}
		else
		{
			ChkLaser4Heartbeat->Checked = false;
			BtnLaserComm4->Caption ="LASER4 OFF";
            Status_Led(MainForm->MainPanelLed14 ,_STATUS_LED_GREEN_ , false , "OFF");
		}
	}
	else
	{
		MessageDlg("Setup.ini 파일을 찾을 수 없습니다!", mtWarning, TMsgDlgButtons() << mbOK, 0);
	}
	delete ini;
	LaserConnectWait->Enabled = true;

}
//---------------------------------------------------------------------------
void __fastcall TFormLaserCommSet::LaserConnectWaitTimer(TObject *Sender)
{
	LaserConnectWait->Enabled = false;
	LaserCommCheck->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TFormLaserCommSet::LaserCommCheckTimer(TObject *Sender)
{
	if(m_Laser_Socket1 != NULL && m_Laser_Socket2 != NULL )//&& m_Laser_Socket3 != NULL && m_Laser_Socket4 != NULL)
	{
		LaserCommCheck->Enabled = false;
    	if(LaserRefreshTimer->Enabled  == false)
        {
			LaserRefreshTimer->Enabled  = true;
        }

		LaserHistoryData("Laser : COMMUNICATION ACTIVATE !");
        _nCommTryCnt_ = 0;
        BtnRetryConnectActive->Enabled = false;
	}
    else
    {
    	if( _nCommTryCnt_<   _RETRYCNT_)
        {
            if(LaserRefreshTimer->Enabled  == true)
            {
                LaserRefreshTimer->Enabled  = false;
            }
            _nCommTryCnt_++;

            this->StartLaserChkSwitch();
            LaserHistoryData("Laser : COMMUNICATION DISABLE!!  -> SYSTEM COULD NOT DETECT THE ACTIVATE SOCKET!");
            BtnRetryConnectActive->Enabled = false;
        }
        else
        {
            LaserHistoryData("Laser :CONNECTION TRY COUNT OVER : " + IntToStr(_nCommTryCnt_));
            _nCommTryCnt_ = 0;
            LaserCommCheck->Enabled = false;
            BtnRetryConnectActive->Enabled = true;
        }
    }

}
//---------------------------------------------------------------------------

void TFormLaserCommSet::LaserClosingProcess()
{
	if(TcpClientLaser1->Active == true)
	{
		TcpClientLaser1->Active = false;
	}

	if(TcpClientLaser2->Active == true)
	{
		TcpClientLaser2->Active = false;
	}

	if(TcpClientLaser3->Active == true)
	{
		TcpClientLaser3->Active = false;
	}

	if(TcpClientLaser4->Active == true)
	{
		TcpClientLaser4->Active = false;
	}
    LaserRefreshTimer->Enabled  = false;
    HelloTimer->Enabled = false;
}
//---------------------------------------------------------------------------
void  TFormLaserCommSet::LaserJobChangeProcess(int nLaserNo ,String StrTemp)
{
	if(StrTemp !="")
	{
		AnsiString JOBbuf = "JOB,";
		try
		{
			if(nLaserNo == 1 && ChkLaser1Heartbeat->Checked == true && m_Laser_Socket1 != NULL)
			{
				bJobChangeWaitFlag1 = true;
				m_Laser_Socket1->SendText(JOBbuf+StrTemp+";");

			}
			else if(nLaserNo == 2 && ChkLaser2Heartbeat->Checked == true && m_Laser_Socket2 != NULL)
			{
				bJobChangeWaitFlag2 = true;
				m_Laser_Socket2->SendText(JOBbuf+StrTemp+";");
			}
			else if(nLaserNo == 3 && ChkLaser3Heartbeat->Checked == true && m_Laser_Socket3 != NULL)
			{
				bJobChangeWaitFlag3 = true;
				m_Laser_Socket3->SendText(JOBbuf+StrTemp+";");
			}
			else if(nLaserNo == 4 && ChkLaser4Heartbeat->Checked == true && m_Laser_Socket4 != NULL)
			{
				bJobChangeWaitFlag4 = true;
				m_Laser_Socket4->SendText(JOBbuf+StrTemp+";");
			}
			LaserHistoryData("Laser"+IntToStr(nLaserNo)+": Job변경 " +JOBbuf+StrTemp);
		}

		catch (Exception &e)
		{
			if(nLaserNo == 1)
			{
				LaserHistoryData("Laser1JobChangeProcess" + e.Message );
			}
			else if(nLaserNo == 2)
			{
				LaserHistoryData("Laser2JobChangeProcess" + e.Message );
			}
			else if(nLaserNo == 3)
			{
				LaserHistoryData("Laser3JobChangeProcess" + e.Message );
			}
			else if(nLaserNo == 4)
			{
				LaserHistoryData("Laser4JobChangeProcess" + e.Message );
			}
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormLaserCommSet::BtnHeartBeatControlClick(TObject *Sender)
{
	CheckHeartBeatControl->Checked = CheckHeartBeatControl->Checked ? 0:1;
	HelloTimer->Enabled = CheckHeartBeatControl->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TFormLaserCommSet::BtnLaserComm1Click(TObject *Sender)
{
     LaserCommEnableControl(dynamic_cast<TButton*>(Sender)->Tag);
}
//---------------------------------------------------------------------------
void TFormLaserCommSet::LaserCommEnableControl(int nLaserIndex)
{
    if(nLaserIndex == _LASER1_)
    {
        if(ChkLaser1Heartbeat->Checked == true)
        {
            ChkLaser1Heartbeat->Checked = false;
            BtnLaserComm1->Caption ="LASER"+ IntToStr(nLaserIndex) + "OFF";
			TcpClientLaser1->Active = false;
            Status_Led(MainForm->MainPanelLed11 ,_STATUS_LED_GREEN_ , true , "OFF");
        }
        else
        {
            ChkLaser1Heartbeat->Checked = true;
            BtnLaserComm1->Caption ="LASER"+ IntToStr(nLaserIndex) + "ON";
            TcpClientLaser1->Active = true;
            Status_Led(MainForm->MainPanelLed11 ,_STATUS_LED_GREEN_ , true , "ON");
        }
    }
    else if(nLaserIndex == _LASER2_)
    {
        if(ChkLaser2Heartbeat->Checked == true)
        {
            ChkLaser2Heartbeat->Checked = false;
            BtnLaserComm2->Caption ="LASER"+ IntToStr(nLaserIndex) + "OFF";
            TcpClientLaser2->Active = false;
            Status_Led(MainForm->MainPanelLed12 ,_STATUS_LED_GREEN_ , true , "OFF");
        }
        else
        {
            ChkLaser2Heartbeat->Checked = true;
            BtnLaserComm2->Caption ="LASER"+ IntToStr(nLaserIndex) + "ON";
            TcpClientLaser2->Active = true;
            Status_Led(MainForm->MainPanelLed12 ,_STATUS_LED_GREEN_ , true , "ON");
        }
    }
    else if(nLaserIndex == _LASER3_)
	{
        if(ChkLaser3Heartbeat->Checked == true)
        {
            ChkLaser3Heartbeat->Checked = false;
            BtnLaserComm3->Caption ="LASER"+ IntToStr(nLaserIndex) + "OFF";
            TcpClientLaser3->Active = false;
            Status_Led(MainForm->MainPanelLed13 ,_STATUS_LED_GREEN_ , true , "OFF");
        }
        else
        {
            ChkLaser3Heartbeat->Checked = true;
            BtnLaserComm3->Caption ="LASER"+ IntToStr(nLaserIndex) + "ON";
            TcpClientLaser3->Active = true;
            Status_Led(MainForm->MainPanelLed13 ,_STATUS_LED_GREEN_ , true , "ON");
        }
	}
    else if(nLaserIndex == _LASER4_)
    {
        if(ChkLaser4Heartbeat->Checked == true)
        {
            ChkLaser4Heartbeat->Checked = false;
            BtnLaserComm4->Caption ="LASER"+ IntToStr(nLaserIndex) + "OFF";
            TcpClientLaser4->Active = false;
            Status_Led(MainForm->MainPanelLed14 ,_STATUS_LED_GREEN_ , true , "OFF");
        }
        else
        {
            ChkLaser4Heartbeat->Checked = true;
            BtnLaserComm4->Caption ="LASER"+ IntToStr(nLaserIndex) + "ON";
            TcpClientLaser4->Active = true;
            Status_Led(MainForm->MainPanelLed14 ,_STATUS_LED_GREEN_ , true , "ON");
        }
    }

    TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini");
    if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini"))
    {
    	TCheckBox* CloneCheckBox = (TCheckBox*)FindComponent("ChkLaser" + IntToStr(nLaserIndex) + "Heartbeat");

        ini->WriteBool("LASER" + IntToStr(nLaserIndex),"ONOFFChk",CloneCheckBox->Checked);
    }
    delete ini;
}
//---------------------------------------------------------------------------
void TFormLaserCommSet::PosarrayEventTrigger()
{
	int nResponseVal = 0;
//	for(int nLaserIndex = 0; nLaserIndex < 4; nLaserIndex++)
//    {
//    	nResponseVal = g_pNvMem->GetNDm(s2mSendLaserCoord1 + nLaserIndex);
//
//        if( nResponseVal != 0)
//        {
//            this->PosArrayLaserSendProcess(nLaserIndex + 1);
//        }
//    }
}
//---------------------------------------------------------------------------
bool  TFormLaserCommSet::LaserTransferComplete(int nCommnadIndex , int nLaserIndex)
{
	bool bReturn = false;
//	if(nCommnadIndex == _POSARRAY_)
//    {
//		LaserHistoryData("PosArray Success Response : LASER : " + IntToStr(nLaserIndex));
//        bReturn = WriteCommNDM(s2mSendLaserCoord1 + (nLaserIndex -1) , 0);
//    }
//    else if(nCommnadIndex == _AUTOCAL_)
//    {
//		LaserHistoryData("AUTOCAL Success Response : LASER : " + IntToStr(nLaserIndex));
//        bReturn =  WriteCommNDM( s2mSendLaserCal , 0);
//    }
//	else if(_JOBCHANGE_)
//    {
//		LaserHistoryData("JOB CHANGE Success Response : LASER : " + IntToStr(nLaserIndex));
//    }
	return bReturn;
}
//---------------------------------------------------------------------------
bool  TFormLaserCommSet::LaserTransferFail(int nCommnadIndex , int nLaserIndex)
{
	bool bReturn = false;
//	if(nCommnadIndex == _POSARRAY_)
//    {
//		LaserHistoryData("PosArray Fail Response : LASER : " + IntToStr(nLaserIndex));
//        bReturn = WriteCommNDM(s2mSendLaserCoord1 + (nLaserIndex -1) , 100);
//    }
//    else if(nCommnadIndex == _AUTOCAL_)
//    {
//		LaserHistoryData("AUTOCAL Fail Response : LASER : " + IntToStr(nLaserIndex));
//        bReturn =  WriteCommNDM( s2mSendLaserCal , 0);
//    }
//	else if(_JOBCHANGE_)
//    {
//		LaserHistoryData("JOB CHANGE Fail Response : LASER : " + IntToStr(nLaserIndex));
//    }
	return bReturn;
}
//---------------------------------------------------------------------------
//
//	laserCoord1X				= 20,
//	laserCoord1Y				= 21,
//	laserCoord1T				= 22,

//	laserCoord2X				= 23,
//	laserCoord2Y				= 24,
//	laserCoord2T				= 25,

//	laserCoord3X				= 26,
//	laserCoord3Y				= 27,
//	laserCoord3T				= 28,

//	laserCoord4X				= 29,
//	laserCoord4Y				= 30,
//	laserCoord4T				= 31,


//	// mmi에 Cutting 좌표 전송 요청
//	// 0 : Comp,  1 : Request
//	s2mSendLaserCoord1			= 200,
//	s2mSendLaserCoord2			= 201,
//	s2mSendLaserCoord3			= 202,
//	s2mSendLaserCoord4			= 203,


void TFormLaserCommSet::PosArrayLaserSendProcess(int nLaserIndex)
{
 	try
	{
		if(nLaserIndex == _LASER1_ && bPosArrayWaitFlag1 == false)
		{
        	bPosArrayWaitFlag1 = true;
            String SendDataCnt =  IntToStr(1);  //이번컨섭에선한세트씩 전송
			String SendOffsets;
            String SendHeader;

            SendOffsets+= String(",") + FloatToStrF( g_pNvMem->GetDDm(laserCoord1X),ffFixed,10,5);
            SendOffsets+= String(",") + FloatToStrF( g_pNvMem->GetDDm(laserCoord1Y) ,ffFixed,10,5);
            SendOffsets+= String(",") + FloatToStrF( g_pNvMem->GetDDm(laserCoord1T),ffFixed,10,5);
            SendOffsets+= ";";
            //SendHeader = "posarrays,1,"+SendDataCnt+SendOffsets;

            SendHeader = "POSARRAY,1"+SendOffsets;

            m_Laser_Socket1->SendText(SendHeader);
            LaserHistoryData(SendHeader);

		}
		if(nLaserIndex == _LASER2_&& bPosArrayWaitFlag2 == false)
		{
        	bPosArrayWaitFlag2 = true;
            String SendDataCnt =  IntToStr(1);  //이번컨섭에선한세트씩 전송
            String SendOffsets;
            String SendHeader;

            SendOffsets+= String(",") + FloatToStrF( g_pNvMem->GetDDm(laserCoord2X),ffFixed,10,5);
            SendOffsets+= String(",") + FloatToStrF( g_pNvMem->GetDDm(laserCoord2Y) ,ffFixed,10,5);
            SendOffsets+= String(",") + FloatToStrF( g_pNvMem->GetDDm(laserCoord2T),ffFixed,10,5);
            SendOffsets+= ";";
            //SendHeader = "posarrays,1,"+SendDataCnt+SendOffsets;

            SendHeader = "POSARRAY,1"+SendOffsets;

            m_Laser_Socket2->SendText(SendHeader);
            LaserHistoryData(SendHeader);
		}
		if(nLaserIndex == _LASER3_&& bPosArrayWaitFlag3 == false)
		{
        	bPosArrayWaitFlag3 = true;
            String SendDataCnt =  IntToStr(1);  //이번컨섭에선한세트씩 전송
            String SendOffsets;
            String SendHeader;

            SendOffsets+= String(",") + FloatToStrF( g_pNvMem->GetDDm(laserCoord3X),ffFixed,10,5);
            SendOffsets+= String(",") + FloatToStrF( g_pNvMem->GetDDm(laserCoord3Y) ,ffFixed,10,5);
            SendOffsets+= String(",") + FloatToStrF( g_pNvMem->GetDDm(laserCoord3T),ffFixed,10,5);
            SendOffsets+= ";";
			//SendHeader = "posarrays,1,"+SendDataCnt+SendOffsets;

            SendHeader = "POSARRAY,1"+SendOffsets;

            m_Laser_Socket3->SendText(SendHeader);
            LaserHistoryData(SendHeader);
		}
		if(nLaserIndex == _LASER4_&& bPosArrayWaitFlag4 == false)
		{
        	bPosArrayWaitFlag4 = true;
            String SendDataCnt =  IntToStr(1);  //이번컨섭에선한세트씩 전송
            String SendOffsets;
            String SendHeader;

            SendOffsets+= String(",") + FloatToStrF( g_pNvMem->GetDDm(laserCoord4X),ffFixed,10,5);
			SendOffsets+= String(",") + FloatToStrF( g_pNvMem->GetDDm(laserCoord4Y) ,ffFixed,10,5);
            SendOffsets+= String(",") + FloatToStrF( g_pNvMem->GetDDm(laserCoord4T),ffFixed,10,5);
            SendOffsets+= ";";
            //SendHeader = "posarrays,1,"+SendDataCnt+SendOffsets;

            SendHeader = "POSARRAY,1"+SendOffsets;

            m_Laser_Socket4->SendText(SendHeader);
            LaserHistoryData(SendHeader);
		}
	}

	catch (Exception &e)
	{
		LaserHistoryData("PosArrayLayer _ LaserSendProcess" + e.Message );
	}

}
//---------------------------------------------------------------------------
void  TFormLaserCommSet::AutoCalEventTrigger()
{
	int nTemp = g_pNvMem->GetNDm (s2mSendLaserCal);
	if(nTemp > 0 && nTemp <= 4)
    {
		this->AutoCalDataReadFromSEQ(nTemp);
    }
}
//---------------------------------------------------------------------------
String  TFormLaserCommSet::AutoCalInterValueLoad(int nCalibSize)
{
	String StrRet;
	TIniFile *CalibIni = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini");
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini"))
	{
	   StrRet = CalibIni ->ReadString("CalibInfo","Calib"+ IntToStr(nCalibSize),"0");
	}
	delete CalibIni;

	return StrRet;
}
//---------------------------------------------------------------------------
void TFormLaserCommSet::AutoCalDataReadFromSEQ(int nLaserIndex)
{
	if(bAutoCalWaitFlag == true)
	{
		return;
	}

    bAutoCalWaitFlag = true;
	if(nLaserIndex == 1 )
	{
        g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_AUTO_CAL1;
	}
	else if(nLaserIndex == 2 )
	{
        g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_AUTO_CAL2;
	}
	else if(nLaserIndex == 3 )
	{
        g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_AUTO_CAL3;
	}
	else if(nLaserIndex == 4 )
	{
        g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_AUTO_CAL4;
	}

	String    SendOffsets , SendHeader , SendLoadDatas , StrIndexValue;

	if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
	{
        int nCalSize = g_MMIComm->m_mmiToSeq.buffer.rdAutoCal.nSize;

        for(int nIndex = 0; nIndex < (nCalSize *nCalSize) ; nIndex++)
		{
            StrIndexValue = NULL;
            try
            {
                StrIndexValue =  FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.rdAutoCal.ptVal[nIndex].dX ,ffFixed,10,5);
            }
            catch (Exception &e)
            {
                LaserHistoryData("AutoCalDataReadFromSEQ X" + e.Message );
                StrIndexValue = "0.0";
            }

            SendOffsets+= String(",")+StrIndexValue;

            StrIndexValue = NULL;
			try
            {
                StrIndexValue =  FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.rdAutoCal.ptVal[nIndex].dY,ffFixed,10,5);
            }
            catch (Exception &e)
            {
                LaserHistoryData("AutoCalDataReadFromSEQ Y" + e.Message );
                StrIndexValue = "0.0";
            }

            SendOffsets+= String(",")+StrIndexValue;

        }

		SendOffsets+= ";";

		SendLoadDatas = IntToStr(nCalSize)+","+IntToStr(nCalSize)+","+(AutoCalInterValueLoad(nCalSize));
		SendHeader = "CORRECTION,"+ SendLoadDatas+ SendOffsets;

		if(nLaserIndex == 1)
		{
			m_Laser_Socket1->SendText(SendHeader);
			LaserHistoryData(SendHeader);
		}
		else if(nLaserIndex == 2)
		{
			m_Laser_Socket2->SendText(SendHeader);
			LaserHistoryData(SendHeader);
		}
		else if(nLaserIndex == 3)
		{
			m_Laser_Socket3->SendText(SendHeader);
			LaserHistoryData(SendHeader);
		}
        else if(nLaserIndex == 4)
		{
			m_Laser_Socket4->SendText(SendHeader);
			LaserHistoryData(SendHeader);
		}
	}
    else
    {
    	LaserHistoryData("SEND && RECV FAIL ! ");
        bAutoCalWaitFlag = false;
	}
}
//----------------------------------------------------------------------------

void __fastcall TFormLaserCommSet::TcpClientLaser1Read(TObject *Sender, TCustomWinSocket *Socket)
{
	char *buf = NULL;
	int len = Socket->ReceiveLength();
	if (0 == len)
		return;
	buf = new char[len+1];
	if (NULL == buf)
		return;

	::ZeroMemory(buf, len+1);
	try
	{
		Socket->ReceiveBuf(buf, len);
	}
	catch (Exception &e)
	{
		delete [] buf;
		LaserHistoryData(e.Message );
		return;
	}

	if( bPosArrayWaitFlag1 == true &&
		0 == strnicmp(buf, "AK;", 3))
	{
		bPosArrayWaitFlag1 = false;
	  	LaserTransferComplete(_POSARRAY_ , _LASER1_);
	}
	else if( bPosArrayWaitFlag1 == true &&
		0 == strnicmp(buf, "NK;", 3))
	{
		bPosArrayWaitFlag1 = false;
		LaserHistoryData("PosArray NK");
	  	LaserTransferFail(_POSARRAY_ , _LASER1_);
    }

	if(bAutoCalWaitFlag == true &&
		0 == strnicmp(buf, "AK;", 3))
	{
		bAutoCalWaitFlag = false;
		LaserHistoryData("AutoCAL1 AK");
	  	LaserTransferComplete(_AUTOCAL_ , _LASER1_);
	}
	else if(bAutoCalWaitFlag == true &&
		0 == strnicmp(buf, "NK;", 3))
	{
		bAutoCalWaitFlag = false;
		LaserHistoryData("AutoCAL1 NK");
	}

	if(bJobChangeWaitFlag1 == true &&
		0 == strnicmp(buf, "AK;", 3))
	{
		bJobChangeWaitFlag1 = false;
		LaserHistoryData("LASER1 JOB CHANGE : AK");
	}
	else if(bJobChangeWaitFlag1 == true &&
		0 == strnicmp(buf, "NK;", 3))
	{
		bJobChangeWaitFlag1 = false;
		LaserHistoryData("LASER1 JOB CHANGE : NK");
	}

//	if(CorrectionCAL1 == true &&
//		0 == strnicmp(buf, "AK;", 3))
//	{
//		CorrectionCAL1 = false;
//		LaserHistoryData("CorrectionCAL1 AK");
//	 //	LaserTransferComplete(_LASER_CORRECTION_1_);
//	}
//	else if(CorrectionCAL1 == true &&
//		0 == strnicmp(buf, "NK;", 3))
//	{
//		LaserHistoryData("CorrectionCAL1 NK!");
//	}


  /*	if (0 == strnicmp(buf, "FILENAME", 8 ))
	{
		_strLaserRecipeName[0] = "";
		CHAR seps[]={",;\r\n"};

		CHAR buffer[MAX_PATH];
		strcpy(buffer, buf);
		CHAR* token = ::strtok(buffer, seps);
		if (token != NULL)
		{
			token = ::strtok(NULL, seps);
			_strLaserRecipeName[0] = token;
		}
	}  */

	LaserHistoryData(buf);


	delete [] buf;
}
//---------------------------------------------------------------------------

void __fastcall TFormLaserCommSet::TcpClientLaser1Connect(TObject *Sender, TCustomWinSocket *Socket)
{
	m_Laser_Socket1 = Socket;
	LaserHistoryData("LASER1 과 연결되었습니다!");
}
//---------------------------------------------------------------------------

void __fastcall TFormLaserCommSet::TcpClientLaser1Disconnect(TObject *Sender, TCustomWinSocket *Socket)

{
	m_Laser_Socket1 = NULL;
	LaserHistoryData("LASER1 과 연결이 끊어졌습니다!");

    LaserCommCheck->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TFormLaserCommSet::TcpClientLaser1Error(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode)
{
	try
	{
		TcpClientLaser1->Socket->Close();
		TcpClientLaser1->Active = false;
		LaserHistoryData("exception :" + IntToStr(ErrorCode));
		ErrorCode = 0;
        m_Laser_Socket1 = NULL;
        LaserCommCheck->Enabled = true;
	}

	catch (Exception &exception)
	{
		LaserHistoryData("exception :" + IntToStr(ErrorCode));
        LaserCommCheck->Enabled = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormLaserCommSet::TcpClientLaser2Connect(TObject *Sender, TCustomWinSocket *Socket)

{
	m_Laser_Socket2 = Socket;
	LaserHistoryData("LASER2 과 연결되었습니다!");
}
//---------------------------------------------------------------------------

void __fastcall TFormLaserCommSet::TcpClientLaser2Disconnect(TObject *Sender, TCustomWinSocket *Socket)

{
	m_Laser_Socket2 = NULL;
	LaserHistoryData("LASER2 과 연결이 끊어졌습니다!");
}
//---------------------------------------------------------------------------

void __fastcall TFormLaserCommSet::TcpClientLaser2Error(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode)
{
	try
	{
		TcpClientLaser2->Socket->Close();
		TcpClientLaser2->Active = false;
		LaserHistoryData("exception :" + IntToStr(ErrorCode));
		ErrorCode = 0;
        m_Laser_Socket2 = NULL;
	}

	catch (Exception &exception)
	{
		LaserHistoryData("exception :" + IntToStr(ErrorCode));
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormLaserCommSet::TcpClientLaser2Read(TObject *Sender, TCustomWinSocket *Socket)

{
	char *buf = NULL;
	int len = Socket->ReceiveLength();
	if (0 == len)
		return;
	buf = new char[len+1];
	if (NULL == buf)
		return;

	::ZeroMemory(buf, len+1);
	try
	{
		Socket->ReceiveBuf(buf, len);
	}
	catch (Exception &e)
	{
		delete [] buf;
		LaserHistoryData(e.Message );
		return;
	}


	if( bPosArrayWaitFlag2 == true &&
		0 == strnicmp(buf, "AK;", 3))
	{
		bPosArrayWaitFlag2 = false;
	  	LaserTransferComplete(_POSARRAY_ , _LASER2_);
	}
	else if( bPosArrayWaitFlag2 == true &&
		0 == strnicmp(buf, "NK;", 3))
	{
		bPosArrayWaitFlag2 = false;
		LaserHistoryData("PosArray NK");
	  	LaserTransferFail(_POSARRAY_ , _LASER2_);
    }

	if(bAutoCalWaitFlag == true &&
		0 == strnicmp(buf, "AK;", 3))
	{
		bAutoCalWaitFlag = false;
		LaserHistoryData("AutoCAL2 AK");
	  	LaserTransferComplete(_AUTOCAL_ , _LASER2_);
	}
	else if(bAutoCalWaitFlag == true &&
		0 == strnicmp(buf, "NK;", 3))
	{
		bAutoCalWaitFlag = false;
		LaserHistoryData("AutoCAL2 NK");
	}

	if(bJobChangeWaitFlag2 == true &&
		0 == strnicmp(buf, "AK;", 3))
	{
		bJobChangeWaitFlag2 = false;
		LaserHistoryData("LASER2 JOB CHANGE : AK");
	}
	else if(bJobChangeWaitFlag2 == true &&
		0 == strnicmp(buf, "NK;", 3))
	{
		bJobChangeWaitFlag2 = false;
		LaserHistoryData("LASER2 JOB CHANGE : NK");
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormLaserCommSet::TcpClientLaser3Connect(TObject *Sender, TCustomWinSocket *Socket)

{
	m_Laser_Socket3 = Socket;
	LaserHistoryData("LASER3 과 연결되었습니다!");
}
//---------------------------------------------------------------------------


void __fastcall TFormLaserCommSet::TcpClientLaser3Disconnect(TObject *Sender, TCustomWinSocket *Socket)

{
	m_Laser_Socket3 = NULL;
	LaserHistoryData("LASER3 과 연결이 끊어졌습니다!");
}
//---------------------------------------------------------------------------

void __fastcall TFormLaserCommSet::TcpClientLaser3Error(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode)
{
	try
	{
		TcpClientLaser3->Socket->Close();
		TcpClientLaser3->Active = false;
		LaserHistoryData("exception :" + IntToStr(ErrorCode));
		ErrorCode = 0;
        m_Laser_Socket3 = NULL;
	}

	catch (Exception &exception)
	{
		LaserHistoryData("exception :" + IntToStr(ErrorCode));
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormLaserCommSet::TcpClientLaser3Read(TObject *Sender, TCustomWinSocket *Socket)

{
	char *buf = NULL;
	int len = Socket->ReceiveLength();
	if (0 == len)
		return;
	buf = new char[len+1];
	if (NULL == buf)
		return;

	::ZeroMemory(buf, len+1);
	try
	{
		Socket->ReceiveBuf(buf, len);
	}
	catch (Exception &e)
	{
		delete [] buf;
		LaserHistoryData(e.Message );
		return;
	}

	if( bPosArrayWaitFlag3 == true &&
		0 == strnicmp(buf, "AK;", 3))
	{
		bPosArrayWaitFlag3 = false;
	  	LaserTransferComplete(_POSARRAY_ , _LASER3_);
	}
	else if( bPosArrayWaitFlag3 == true &&
		0 == strnicmp(buf, "NK;", 3))
	{
		bPosArrayWaitFlag3 = false;
		LaserHistoryData("PosArray NK");
	  	LaserTransferFail(_POSARRAY_ , _LASER3_);
    }

	if(bAutoCalWaitFlag == true &&
		0 == strnicmp(buf, "AK;", 3))
	{
		bAutoCalWaitFlag = false;
		LaserHistoryData("AutoCAL3 AK");
	  	LaserTransferComplete(_AUTOCAL_ , _LASER3_);
	}
	else if(bAutoCalWaitFlag == true &&
		0 == strnicmp(buf, "NK;", 3))
	{
		bAutoCalWaitFlag = false;
		LaserHistoryData("AutoCAL3 NK");
	}

	if(bJobChangeWaitFlag3 == true &&
		0 == strnicmp(buf, "AK;", 3))
	{
		bJobChangeWaitFlag3 = false;
		LaserHistoryData("LASER3 JOB CHANGE : AK");
	}
	else if(bJobChangeWaitFlag3 == true &&
		0 == strnicmp(buf, "NK;", 3))
	{
		bJobChangeWaitFlag3 = false;
		LaserHistoryData("LASER3 JOB CHANGE : NK");
	}

}
//---------------------------------------------------------------------------

void __fastcall TFormLaserCommSet::TcpClientLaser4Connect(TObject *Sender, TCustomWinSocket *Socket)

{
	m_Laser_Socket4 = Socket;
	LaserHistoryData("LASER4 과 연결되었습니다!");
}
//---------------------------------------------------------------------------

void __fastcall TFormLaserCommSet::TcpClientLaser4Disconnect(TObject *Sender, TCustomWinSocket *Socket)

{
	m_Laser_Socket4 = NULL;
	LaserHistoryData("LASER4 과 연결이 끊어졌습니다!");
}
//---------------------------------------------------------------------------

void __fastcall TFormLaserCommSet::TcpClientLaser4Error(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode)
{
	try
	{
		TcpClientLaser4->Socket->Close();
		TcpClientLaser4->Active = false;
		LaserHistoryData("exception :" + IntToStr(ErrorCode));
		ErrorCode = 0;
        m_Laser_Socket4 = NULL;
	}

	catch (Exception &exception)
	{
		LaserHistoryData("exception :" + IntToStr(ErrorCode));
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormLaserCommSet::TcpClientLaser4Read(TObject *Sender, TCustomWinSocket *Socket)

{
	char *buf = NULL;
	int len = Socket->ReceiveLength();
	if (0 == len)
		return;
	buf = new char[len+1];
	if (NULL == buf)
		return;

	::ZeroMemory(buf, len+1);
	try
	{
		Socket->ReceiveBuf(buf, len);
	}
	catch (Exception &e)
	{
		delete [] buf;
		LaserHistoryData(e.Message );
		return;
	}

	if( bPosArrayWaitFlag4 == true &&
		0 == strnicmp(buf, "AK;", 3))
	{
		bPosArrayWaitFlag4 = false;
	  	LaserTransferComplete(_POSARRAY_ , _LASER4_);
	}
	else if( bPosArrayWaitFlag4 == true &&
		0 == strnicmp(buf, "NK;", 3))
	{
		bPosArrayWaitFlag4 = false;
		LaserHistoryData("PosArray NK");
	  	LaserTransferFail(_POSARRAY_ , _LASER4_);
    }

	if(bAutoCalWaitFlag == true &&
		0 == strnicmp(buf, "AK;", 3))
	{
		bAutoCalWaitFlag = false;
		LaserHistoryData("AutoCAL3 AK");
	  	LaserTransferComplete(_AUTOCAL_ , _LASER4_);
	}
	else if(bAutoCalWaitFlag == true &&
		0 == strnicmp(buf, "NK;", 3))
	{
		bAutoCalWaitFlag = false;
		LaserHistoryData("AutoCAL4 NK");
	}

	if(bJobChangeWaitFlag4 == true &&
		0 == strnicmp(buf, "AK;", 3))
	{
		bJobChangeWaitFlag4 = false;
		LaserHistoryData("LASER4 JOB CHANGE : AK");
	}
	else if(bJobChangeWaitFlag4 == true &&
		0 == strnicmp(buf, "NK;", 3))
	{
		bJobChangeWaitFlag4 = false;
		LaserHistoryData("LASER4 JOB CHANGE : NK");
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormLaserCommSet::BtnCloseClick(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------


void __fastcall TFormLaserCommSet::LaserRefreshTimerTimer(TObject *Sender)
{
	this->PosarrayEventTrigger();
    this->AutoCalEventTrigger();
}
//---------------------------------------------------------------------------

void __fastcall TFormLaserCommSet::BtnRetryConnectActiveClick(TObject *Sender)
{
	this->StartLaserChkSwitch();
}
//---------------------------------------------------------------------------


