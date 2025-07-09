//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "VisionSetUpScrn.h"
#include "MainFormScrn.h"
#include "SECS\\FormSecsGemSetScrn.h"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include "BaseComm.h"
//---------------------------------------------------------------------------
#include <stdio.h>
#include <time.h>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma resource "*.dfm"



#define   _PRE_QC_VISION_        		0
#define   _ALIGN_VISION1_               1
#define   _ALIGN_VISION2_               2
#define   _TRAY_VISION_                 3
#define   _DVI_							4
#define   _QPD_QC_VISION_        		5
#define   _SORTER_JOB_CHANGE_VISION_    6

#define   _QC_VISION_DATACOUNT_    		4

TFrmVisionSetUp *FrmVisionSetUp;
//---------------------------------------------------------------------------
__fastcall TFrmVisionSetUp::TFrmVisionSetUp(TComponent* Owner)
	: TForm(Owner)
{
	m_AlignSocket1 = NULL;
	m_AlignSocket2 = NULL;

	m_SorterJobSocket = NULL;
	m_PreQCSocket = NULL;
	m_QpdSocket = NULL;

	bChkRCPchk =false;
	_fp = NULL;
	_fpl = NULL;

	vCutProcessStateChange("Init");
}
//---------------------------------------------------------------------------
void TFrmVisionSetUp::vCutProcessStateChange(String sType)
{
	TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\ini\\Setup.ini");

	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\ini\\Setup.ini"))
	{
		String sDate = Date();
		if(!ini->SectionExists("V-CUT_VISION"))
		{
			ini->WriteString("V-CUT_VISION","PATH","C:\\V-CUT_VISION");
			ini->WriteString("V-CUT_VISION","DATE",sDate);
			ini->WriteString("V-CUT_VISION","TYPE","NEVER");
			ini->WriteString("V-CUT_VISION","VALUE","0");
		}

		String sFilePath = "", sFileDate = "", sFileType = "", sFileValue = "";
		sFilePath = ini->ReadString("V-CUT_VISION", "PATH", "");
		sFileDate = ini->ReadString("V-CUT_VISION", "DATE", "");
		sFileType = ini->ReadString("V-CUT_VISION", "TYPE", "");
		sFileValue = ini->ReadString("V-CUT_VISION", "VALUE", "");

		if (false == DirectoryExists(sFilePath))
			return;
		if (sFileDate == "")
			return;
		if (sFileType == "")
			return;
		if (sFileValue == "")
			return;

		if (sType == "Init")
		{
			MemoLog->Clear();
			MemoLog->Lines->Add(sFilePath);

			//;TYPE -> NEVER = 0, YEAR = 1, MON = 2, DAY = 3
			//;VALUE -> NEVER = 0, 3DAY = 3, 1MONTH = 1, 3MONTH = 3, 6MONTH = 6
			if (sFileValue == "3" && sFileType == "DAY")
				Rdo_Del01->Checked = true;
			else if(sFileValue == "1"&& sFileType == "MON")
				Rdo_Del02->Checked = true;
			else if(sFileValue == "3"&& sFileType == "MON")
				Rdo_Del03->Checked = true;
			else if(sFileValue == "6"&& sFileType == "MON")
				Rdo_Del04->Checked = true;
			else if(sFileValue == "0")
				Rdo_Del05->Checked = true;
		}
		else if (sType == "Select")
		{
			ini->WriteString("V-CUT_VISION","DATE",sDate);

			if (Rdo_Del01->Checked)
			{
				ini->WriteString("V-CUT_VISION","TYPE","DAY");
				ini->WriteString("V-CUT_VISION","VALUE","3");
			}
			else if (Rdo_Del02->Checked)
			{
				ini->WriteString("V-CUT_VISION","TYPE","MON");
				ini->WriteString("V-CUT_VISION","VALUE","1");
			}
			else if (Rdo_Del03->Checked)
			{
				ini->WriteString("V-CUT_VISION","TYPE","MON");
				ini->WriteString("V-CUT_VISION","VALUE","3");
			}
			else if (Rdo_Del04->Checked)
			{
				ini->WriteString("V-CUT_VISION","TYPE","MON");
				ini->WriteString("V-CUT_VISION","VALUE","6");
			}
			else if (Rdo_Del05->Checked)
			{
				ini->WriteString("V-CUT_VISION","TYPE","NEVER");
				ini->WriteString("V-CUT_VISION","VALUE","0");
			}

		}
	}
	delete ini;
}
//---------------------------------------------------------------------------

void __fastcall TFrmVisionSetUp::BtnPreQCVisionClick(TObject *Sender)
{
	if(ChkPreQCVision->Checked == true)
	{
		ChkPreQCVision->Checked = false;
		BtnPreQCVision->Caption ="QC VISION OFF";
		PreQCSocket->Active = false;
//        Status_Led(MainForm->MainPanelLed1 ,_STATUS_LED_GREEN_ , false , "OFF");

    }
	else
    {
        ChkPreQCVision->Checked = true;
		BtnPreQCVision->Caption ="QC VISION ON";
		PreQCSocket->Active = true;
//        Status_Led(MainForm->MainPanelLed1 ,_STATUS_LED_GREEN_ , true , "ON");
	}

	TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini");
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini"))
	{
		ini->WriteBool("QCVISION","ONOFFChk",ChkPreQCVision->Checked);
	}
	delete ini;
}
//---------------------------------------------------------------------------
void __fastcall TFrmVisionSetUp::BtnAlignVision1Click(TObject *Sender)
{
	if(ChkAlignVision1->Checked == true)
	{

		ChkAlignVision1->Checked = false;
		BtnAlignVision1->Caption ="BOTTOM ALIGN OFF";
		BtmAlignVisionServer->Active = false;
//        Status_Led(MainForm->MainPanelLed2 ,_STATUS_LED_GREEN_ , false , "OFF");
	}
	else
	{
		ChkAlignVision1->Checked = true;
		BtnAlignVision1->Caption ="BOTTOM ALIGN ON";
		BtmAlignVisionServer->Active = true;
//        Status_Led(MainForm->MainPanelLed2 ,_STATUS_LED_GREEN_ , true , "ON");
	}

	TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini");
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini"))
	{
		ini->WriteBool("ALIGN_VISION1","ONOFFChk",ChkAlignVision1->Checked);
	}
	delete ini;
}
//---------------------------------------------------------------------------
void __fastcall TFrmVisionSetUp::BtnAlignVision2Click(TObject *Sender)
{
	if(ChkAlignVision2->Checked == true)
	{
		ChkAlignVision2->Checked = false;
		BtnAlignVision2->Caption ="FLIPPER VISION OFF";
		FlpAlignVisionServer->Active = false;
//        Status_Led(MainForm->MainPanelLed3 ,_STATUS_LED_GREEN_ , false , "OFF");
	}
	else
	{
		ChkAlignVision2->Checked = true;
		BtnAlignVision2->Caption ="FLIPPER VISION ON";
		FlpAlignVisionServer->Active = true;
//        Status_Led(MainForm->MainPanelLed3 ,_STATUS_LED_GREEN_ , true , "ON");
	}

	TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini");
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini"))
	{
		ini->WriteBool("ALIGN_VISION2","ONOFFChk",ChkAlignVision2->Checked);
	}
	delete ini;
}
//---------------------------------------------------------------------------

void __fastcall TFrmVisionSetUp::BtnTrayVisionClick(TObject *Sender)
{
	if(ChkTrayVision->Checked == true)
	{
		ChkTrayVision->Checked = false;
		BtnTrayVision->Caption ="TRAY VISION OFF";
		TraySocket->Active = false;
//        Status_Led(MainForm->MainPanelLed4,_STATUS_LED_GREEN_ , false , "OFF");
	}
	else
	{
		ChkTrayVision->Checked = true;
		BtnTrayVision->Caption ="TRAY VISION ON";
		TraySocket->Active = true;
//        Status_Led(MainForm->MainPanelLed4,_STATUS_LED_GREEN_ , true , "ON");
	}

	TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini");
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini"))
	{
		ini->WriteBool("TRAY_VISION","ONOFFChk",ChkTrayVision->Checked);
	}
	delete ini;
}
//---------------------------------------------------------------------------

void __fastcall TFrmVisionSetUp::BtnSorterJobChangeVisionClick(TObject *Sender)
{
	if(ChkSorterJobChangeVision->Checked == true)
	{
		ChkSorterJobChangeVision->Checked = false;
		BtnSorterJobChangeVision->Caption ="SORTER JOBCHANGE  OFF";
		SorterJobChangeVisionServer->Active = false;
//        Status_Led(MainForm->MainPanelLed5 ,_STATUS_LED_GREEN_ , false , "OFF");

    }
	else
    {
        ChkSorterJobChangeVision->Checked = true;
		BtnSorterJobChangeVision->Caption ="SORTER JOBCHANGE  ON";
		SorterJobChangeVisionServer->Active = true;
//        Status_Led(MainForm->MainPanelLed5 ,_STATUS_LED_GREEN_ , true , "ON");
	}

	TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini");
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini"))
	{
		ini->WriteBool("SORTERJOBCHANGE","ONOFFChk",ChkSorterJobChangeVision->Checked);
	}
	delete ini;
}
//---------------------------------------------------------------------------



void TFrmVisionSetUp::VisionHistoryData(int VisionSeparator,String StrTemp)
{
	String strLog;
	if(VisionSeparator == _ALIGN_VISION1_)
	{
		strLog = "[BOTTOM ALIGN] " + StrTemp;
	}
	else if(VisionSeparator == _ALIGN_VISION2_)
	{
		strLog = "[FLIPPER VISION] " + StrTemp;
	}
	else if(VisionSeparator == _PRE_QC_VISION_)
	{
		strLog = "[QC VISION] " + StrTemp;
	}
	else if(VisionSeparator == _SORTER_JOB_CHANGE_VISION_)
	{
		strLog = "[SORTER JOB CHANGE] " + StrTemp;
	}
	else if(VisionSeparator == _TRAY_VISION_)
	{
		strLog = "[TRAY VISION] " + StrTemp;
	}
	else if(VisionSeparator == _DVI_)
	{
		strLog = "[DVI] " + StrTemp;
	}
	else if(VisionSeparator == _QPD_QC_VISION_)
	{
		strLog = "[QPD_QC_VISION_] " + StrTemp;
	}
	else
	{
		strLog = StrTemp;
	}


	String logMessage = Now().FormatString("yyyy-mm-dd hh:mm:ss")+ " : " + strLog;
    TDateTime dt = Now();
    String fileName = dt.FormatString("yyyy-mm-dd") + ".txt";

    if (_currentLogFileName != fileName)
    {
    	if (_fp)
        	fclose(_fp);
        String sDir = "C:\\KOSES\\History\\VisionHistory\\";
        ForceDirectories(sDir);
        String fullPathName = sDir + fileName;
        _fp = _wfopen( fullPathName.c_str(), L"at");
        assert(_fp);
        _currentLogFileName = fileName;
    }

    fputws(logMessage.c_str(), _fp);
    fputws(L"\r\n", _fp);
	VisionMemo->Lines->Add(logMessage);

	//if (CheckMemoRefresh->Checked)
    //	SendMessage(VisionMemo->Handle, WM_VSCROLL, SB_BOTTOM, 0);

    if(VisionMemo->Lines->Count > 1000)
    {
    	fflush(_fp);
    	VisionMemo->Lines->BeginUpdate();
		VisionMemo->SelStart = 0;
        VisionMemo->SelLength = VisionMemo->Perform(EM_LINEINDEX, 1000, 0);
        VisionMemo->SelText = "";
		VisionMemo->Lines->EndUpdate();
	}
}
//---------------------------------------------------------------------------


void __fastcall TFrmVisionSetUp::BtmAlignVisionServerClientConnect(TObject *Sender, TCustomWinSocket *Socket)
{
	VisionHistoryData(_ALIGN_VISION1_,"Connected.");
	StrRecvBTMBuffer = "";
	m_AlignSocket1 = Socket;
	nWriteCommunicationDM(1,flagVisionComm);
}
//---------------------------------------------------------------------------

void __fastcall TFrmVisionSetUp::BtmAlignVisionServerClientDisconnect(TObject *Sender,
		  TCustomWinSocket *Socket)
{
	VisionHistoryData(_ALIGN_VISION1_,"Disconnected.");
    StrRecvBTMBuffer = "";
	m_AlignSocket1 = NULL;
	nWriteCommunicationDM(0,flagVisionComm);
}
//---------------------------------------------------------------------------

void __fastcall TFrmVisionSetUp::BtmAlignVisionServerClientError(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode)
{
    try
    {
		Socket->Close();
		VisionHistoryData(_ALIGN_VISION1_,"Connection have a problem.");
	}

	catch (Exception &exception)
	{
		VisionHistoryData(_ALIGN_VISION1_,"Exception" + IntToStr(ErrorCode));
	}

    ErrorCode= 0;
    StrRecvBTMBuffer = "";
	m_AlignSocket1 = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TFrmVisionSetUp::BtmAlignVisionServerClientRead(TObject *Sender, TCustomWinSocket *Socket)
{
    StrRecvBTMBuffer +=   Socket->ReceiveText();
    if ( StrRecvBTMBuffer.Pos(";") > 0)
    {
    	VisionHistoryData(_ALIGN_VISION1_, "RAW Recv:"+ StrRecvBTMBuffer);

        int nVal = VisionCommandJudgement(StrRecvBTMBuffer);

        if(1 == nVal)
        {
			this->MoveVisionControl(_ALIGN_VISION1_ , StrRecvBTMBuffer);
            StrRecvBTMBuffer = "";
        }
        else if(2 == nVal)
        {
			this->BottomVisionTransferControl();
        }
    }
    else
    {
		// 문자열 종결자(;)가 발견되지 않음
        // 다음번꺼에 도착할지 모름
	}
}
//---------------------------------------------------------------------------



void __fastcall TFrmVisionSetUp::FlpAlignVisionServerClientConnect(TObject *Sender,
          TCustomWinSocket *Socket)
{
	VisionHistoryData(_ALIGN_VISION2_,"Connected.");
	StrRecvTOPBuffer = "";
	m_AlignSocket2 = Socket;
	nWriteCommunicationDM(1,flagVisionComm);
}
//---------------------------------------------------------------------------

void __fastcall TFrmVisionSetUp::FlpAlignVisionServerClientDisconnect(TObject *Sender,
          TCustomWinSocket *Socket)
{
	VisionHistoryData(_ALIGN_VISION2_,"Disconnected.");
    StrRecvTOPBuffer = "";
	m_AlignSocket2 = NULL;
	nWriteCommunicationDM(0,flagVisionComm);
}
//---------------------------------------------------------------------------


void __fastcall TFrmVisionSetUp::FlpAlignVisionServerClientError(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode)
{
    try
    {
		Socket->Close();
		VisionHistoryData(_ALIGN_VISION2_,"Connection have a problem.");
	}

	catch (Exception &exception)
	{
		VisionHistoryData(_ALIGN_VISION2_,"Exception" + IntToStr(ErrorCode));
	}

    ErrorCode= 0;
    StrRecvTOPBuffer = "";
	m_AlignSocket2 = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TFrmVisionSetUp::FlpAlignVisionServerClientRead(TObject *Sender, TCustomWinSocket *Socket)

{
    StrRecvTOPBuffer +=   Socket->ReceiveText();
    if ( StrRecvTOPBuffer.Pos(";") > 0)
    {
    	VisionHistoryData(_ALIGN_VISION2_, "RAW Recv:"+ StrRecvTOPBuffer);

        int nVal = VisionCommandJudgement(StrRecvTOPBuffer);

        if(1 == nVal)
        {
			this->MoveVisionControl(_ALIGN_VISION2_ , StrRecvTOPBuffer);
            StrRecvTOPBuffer = "";
        }
        else if(2 == nVal)
        {
			this->TOPVisionTransferControl();
        }
    }
    else
    {
		// 문자열 종결자(;)가 발견되지 않음
        // 다음번꺼에 도착할지 모름
	}
}
//---------------------------------------------------------------------------



void __fastcall TFrmVisionSetUp::PreQCSocketClientConnect(TObject *Sender, TCustomWinSocket *Socket)
          
{
	m_PreQCSocket = Socket;
	VisionHistoryData(_PRE_QC_VISION_,"Connected.");
    StrQCRecvBuffer = "";
	nWriteCommunicationDM(1,flagVisionComm);
}
//---------------------------------------------------------------------------

void __fastcall TFrmVisionSetUp::PreQCSocketClientDisconnect(TObject *Sender, TCustomWinSocket *Socket)

{
	m_PreQCSocket = NULL;
	VisionHistoryData(_PRE_QC_VISION_,"Disconneted.");
    StrQCRecvBuffer = "";
	nWriteCommunicationDM(0,flagVisionComm);
}
//---------------------------------------------------------------------------

void __fastcall TFrmVisionSetUp::PreQCSocketClientRead(TObject *Sender, TCustomWinSocket *Socket)
          
{
    StrQCRecvBuffer +=   Socket->ReceiveText();
    if ( StrQCRecvBuffer.Pos(";") > 0)
    {
		VisionHistoryData(_PRE_QC_VISION_, "Recv:"+ StrQCRecvBuffer);

        int nVal = VisionCommandJudgement(StrQCRecvBuffer);

        if(1 == nVal)
        {
			this->MoveVisionControl(_PRE_QC_VISION_ , StrQCRecvBuffer);
            StrQCRecvBuffer = "";
        }
        else if(2 == nVal)
        {
			this->QCVisionRecvControl();
        }
    }
    else
    {
		// 문자열 종결자(;)가 발견되지 않음
        // 다음번꺼에 도착할지 모름
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmVisionSetUp::PreQCSocketClientError(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode)
{
	try
	{
		Socket->Close();
		VisionHistoryData(_PRE_QC_VISION_,"Connection have a problem.");
	}

	catch (Exception &exception)
	{
		VisionHistoryData(_PRE_QC_VISION_,"Exception" + IntToStr(ErrorCode));
	}

	m_PreQCSocket = NULL;
    StrQCRecvBuffer = "";
	ErrorCode= 0;
}
//---------------------------------------------------------------------------



void __fastcall TFrmVisionSetUp::SorterJobChangeVisionServerClientConnect(TObject *Sender,
          TCustomWinSocket *Socket)
{
	m_SorterJobSocket = Socket;
	VisionHistoryData(_SORTER_JOB_CHANGE_VISION_,"Connected.");
	nWriteCommunicationDM(1,flagVisionComm);
}
//---------------------------------------------------------------------------

void __fastcall TFrmVisionSetUp::SorterJobChangeVisionServerClientDisconnect(TObject *Sender,
          TCustomWinSocket *Socket)
{
	m_SorterJobSocket = NULL;
	VisionHistoryData(_SORTER_JOB_CHANGE_VISION_,"Disconneted.");
	nWriteCommunicationDM(0,flagVisionComm);
}
//---------------------------------------------------------------------------

void __fastcall TFrmVisionSetUp::SorterJobChangeVisionServerClientError(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)

{
	try
	{
		Socket->Close();
		VisionHistoryData(_SORTER_JOB_CHANGE_VISION_,"Connection have a problem.");
	}

	catch (Exception &exception)
	{
		VisionHistoryData(_SORTER_JOB_CHANGE_VISION_,"Exception" + IntToStr(ErrorCode));
	}

	m_SorterJobSocket = NULL;
	ErrorCode= 0;
}
//---------------------------------------------------------------------------

void __fastcall TFrmVisionSetUp::SorterJobChangeVisionServerClientRead(TObject *Sender,
          TCustomWinSocket *Socket)
{
	char *buf = NULL;
	try
	{
		int len = Socket->ReceiveLength();
		if (0 == len)
			return;

		buf = new char[len+1];
		ZeroMemory(buf, len+1);
		Socket->ReceiveBuf(buf, len);

		//if( bChkRCPchk == true)
		{
			//bChkRCPchk = false;
			if(0 == strnicmp(buf, "NK;", 3))
			{
				FrmCdBox->setFlag(CD_OK);
				FrmCdBox->setTitle("RECIPE CHANGE");
				FrmCdBox->setText("VISION RECIPE  IS NOT CHANGE!");
				FrmCdBox->ShowModal();
			}
			else if(0 == strnicmp(buf, "DVI;", 4))
			{
				//this->send_dvi();
//			}
//			else if(0 == strnicmp(buf, "INI", 5))
//			{
//				VisionHistoryData(_SORTER_JOB_CHANGE_VISION_,"VISION TO MMI TRACE DATA SENDING OK");
//				String strPPID("TRACE_DATA_VISION.dat");
//				FormSecsGemSet->FileUpload(strPPID);
			}
			else if(0 == strnicmp(buf, "JOB;", 4))
			{
				this->send_job();
			}
			else if(0 == strnicmp(buf, "TID;", 4))
			{
				// Tray Info data result OK !!
				// 시퀀스에 Ok에 던져주어야 Tray를 잡을 수 있음
				String StrTemp = buf;
				VisionHistoryData(_SORTER_JOB_CHANGE_VISION_,"Data Received (Tray Info Recive Ok !!) :" + StrTemp.Trim());
			}
			else
			{
				String StrTemp = buf;
				VisionHistoryData(_SORTER_JOB_CHANGE_VISION_,"Data Received :" + StrTemp.Trim());
			}
		}
	}
	catch (Exception &exception)
	{
	}
	delete [] buf;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TFrmVisionSetUp::TraySocketClientConnect(TObject *Sender, TCustomWinSocket *Socket)

{
	m_TraySocket = Socket;
	StrTrayRecvBuffer = "";
	VisionHistoryData(_TRAY_VISION_,"Connected.");
	nWriteCommunicationDM(1,flagVisionComm);
}
//---------------------------------------------------------------------------

void __fastcall TFrmVisionSetUp::TraySocketClientDisconnect(TObject *Sender, TCustomWinSocket *Socket)

{
	m_TraySocket = NULL;
	VisionHistoryData(_TRAY_VISION_,"Disconneted.");
	nWriteCommunicationDM(0,flagVisionComm);
}
//---------------------------------------------------------------------------

void __fastcall TFrmVisionSetUp::TraySocketClientError(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode)
{
	try
	{
		Socket->Close();
		VisionHistoryData(_TRAY_VISION_,"Connection have a problem.");
	}

	catch (Exception &exception)
	{
		VisionHistoryData(_TRAY_VISION_,"Exception" + IntToStr(ErrorCode));
	}

	m_TraySocket = NULL;
	StrTrayRecvBuffer = "";
	ErrorCode= 0;
}
//---------------------------------------------------------------------------

void __fastcall TFrmVisionSetUp::TraySocketClientRead(TObject *Sender, TCustomWinSocket *Socket)

{
	StrTrayRecvBuffer +=   Socket->ReceiveText();
	if ( StrTrayRecvBuffer.Pos(";") > 0)
	{
		VisionHistoryData(_TRAY_VISION_, "Recv : "+ StrTrayRecvBuffer);

		CHAR seps[]={",;"};
		CHAR buf [128];
		strcpy(buf, StrTrayRecvBuffer.c_str());
		StrTrayRecvBuffer = "";

		String StrTemp = ::strtok(buf, seps);

		VisionHistoryData(_TRAY_VISION_, "COUNT : " + StrTemp);

		if(StrTemp != "")
		{
			String Strdummy = ::strtok(NULL, seps);

			if(Strdummy == "0")
			{
				nWriteCommunicationDM(1 , trayViPass);
			}
			else
			{
				nWriteCommunicationDM(1 , trayViFail);
			}

			VisionHistoryData(_TRAY_VISION_, "RESPONSE : " + Strdummy);
		}
	}
	else
	{
		// 문자열 종결자(;)가 발견되지 않음
		// 다음번꺼에 도착할지 모름
	}
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void TFrmVisionSetUp::StartVisionChkSwitch()
{
    TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini");
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini"))
    {
        if(ini->ReadBool("QCVISION","ONOFFChk",true) == true)
        {
            ChkPreQCVision->Checked = true;
            BtnPreQCVision->Caption ="QC VISION ON";
			PreQCSocket->Active = true;
//			Status_Led(MainForm->MainPanelLed1 ,_STATUS_LED_GREEN_ , true , "ON");
		}
		else
		{
			ChkPreQCVision->Checked = false;
			BtnPreQCVision->Caption ="QC VISION OFF";
//			Status_Led(MainForm->MainPanelLed1 ,_STATUS_LED_GREEN_ , false , "OFF");
		}

        if(ini->ReadBool("ALIGN_VISION1","ONOFFChk",true) == true)
        {
			ChkAlignVision1->Checked = true;
			BtnAlignVision1->Caption ="BOTTOM ALIGN  ON";
			BtmAlignVisionServer->Active = true;
//        	Status_Led(MainForm->MainPanelLed2 ,_STATUS_LED_GREEN_ , true , "ON");

		}
		else
		{
			ChkAlignVision1->Checked = false;
			BtnAlignVision1->Caption ="BOTTOM ALIGN OFF";
//        	Status_Led(MainForm->MainPanelLed2 ,_STATUS_LED_GREEN_ , false , "OFF");
		}

        if(ini->ReadBool("ALIGN_VISION2","ONOFFChk",true) == true)
        {
			ChkAlignVision2->Checked = true;
			BtnAlignVision2->Caption ="TOP ALIGN ON";
			FlpAlignVisionServer->Active = true;
//        	Status_Led(MainForm->MainPanelLed3 ,_STATUS_LED_GREEN_ , true , "ON");

		}
		else
		{
			ChkAlignVision2->Checked = false;
			BtnAlignVision2->Caption ="TOP ALIGN OFF";
//        	Status_Led(MainForm->MainPanelLed3 ,_STATUS_LED_GREEN_ , false , "OFF");
		}

        if(ini->ReadBool("TRAY_VISION","ONOFFChk",true) == true)
        {
			ChkTrayVision->Checked = true;
			BtnTrayVision->Caption ="TRAY VISION ON";
			TraySocket->Active = true;
//        	Status_Led(MainForm->MainPanelLed5 ,_STATUS_LED_GREEN_ , true , "ON");

		}
		else
		{
			ChkTrayVision->Checked = false;
			BtnTrayVision->Caption ="TRAY VISION OFF";
//        	Status_Led(MainForm->MainPanelLed5 ,_STATUS_LED_GREEN_ , false , "OFF");
		}

		if(ini->ReadBool("QPDVISION","ONOFFChk",true) == true)
		{
			ChkPreQPDVision->Checked = true;
			BtnPreQPDVision->Caption ="QPD VISION ON";
			QpdSorket->Active = true;
//			Status_Led(MainForm->MainPanelLed1 ,_STATUS_LED_GREEN_ , true , "ON");
		}
		else
		{
			ChkPreQPDVision->Checked = false;
			BtnPreQPDVision->Caption ="QPD VISION OFF";
//			Status_Led(MainForm->MainPanelLed1 ,_STATUS_LED_GREEN_ , false , "OFF");
		}

		if(ini->ReadBool("SORTERJOBCHANGE","ONOFFChk",true) == true)
		{
            ChkSorterJobChangeVision->Checked = true;
            BtnSorterJobChangeVision->Caption ="SORTER JOBCHANGE ON";
			SorterJobChangeVisionServer->Active = true;
//			Status_Led(MainForm->MainPanelLed7 ,_STATUS_LED_GREEN_ , true , "ON");
		}
		else
		{
			ChkSorterJobChangeVision->Checked = false;
			BtnSorterJobChangeVision->Caption ="SORTER JOBCHANGE OFF";
//			Status_Led(MainForm->MainPanelLed7 ,_STATUS_LED_GREEN_ , false , "OFF");
		}

        DVIServerSocket->Active = true;

	}
	else
    {
		MessageDlg("Setup.ini File not found!", mtWarning, TMsgDlgButtons() << mbOK, 0);
    }

    delete ini;

    ReqRCClientSocket->Host = "192.168.0.3";

    try
    {
    	ReqRCClientSocket->Active = true;
        VisionHistoryData(-1, "REQ RECONNECT SOCKET ACTIVED.");
		//Status_Led(MainForm->MainPanelLed5 ,_STATUS_LED_GREEN_ , true , "ON");
	}
    catch(Exception& e)
	{
		// trying to connect but failed
		//this->MMILOGHistoryData("Exception : " + e.Message);
    	VisionHistoryData(-1, "REQ RECONNECT SOCKET ERROR : " + e.Message);
	}

	TIniFile* configIni = new TIniFile(ExtractFilePath(Application->ExeName)+"Config.ini");

	BtmSendClientSocket->Host = configIni->ReadString("TC","EQP_BTM_SEND_IP", "192.168.0.7");
	BtmSendClientSocket->Port = configIni->ReadInteger("TC","EQP_BTM_SEND_PORT", 8008);

	delete configIni;

	try
	{
		BtmSendClientSocket->Active = true;
		VisionHistoryData(-1, "BOTTOM VISION SEND - RECONNECT SOCKET ACTIVED.");
	}
	catch(Exception& e)
	{
		VisionHistoryData(-1, "BOTTOM VISION SEND - RECONNECT SOCKET ERROR : " + e.Message);
	}

	nWriteCommunicationDM(1,reqVisionReconnect);

}
//---------------------------------------------------------------------------

void TFrmVisionSetUp::TOPVisionTransferControl()
{
	String StrCount  , StrXoffset , StrYoffset ,Strthetaoffset;
	if (StrRecvTOPBuffer.Pos(";") >0)
	{
		CHAR seps[]={",;"};
		CHAR buf [256];
		strcpy(buf, StrRecvTOPBuffer.c_str());
        StrRecvTOPBuffer = "";

		StrCount = ::strtok(buf, seps);
        VisionHistoryData(_ALIGN_VISION2_, "COUNT : " + StrCount);
		if(StrCount != "")
		{
            for(int nVisionIndex=0; nVisionIndex<StrCount.ToInt(); nVisionIndex++)
            {
                StrXoffset = ::strtok(NULL, seps);
                StrYoffset = ::strtok(NULL, seps);
                Strthetaoffset = ::strtok(NULL, seps);

                VisionHistoryData(_ALIGN_VISION2_, "XVALUE  " + IntToStr(nVisionIndex) + " : " + StrXoffset);
                VisionHistoryData(_ALIGN_VISION2_, "YVALUE  " + IntToStr(nVisionIndex) + " : " + StrYoffset);
                VisionHistoryData(_ALIGN_VISION2_, "TVALUE  " + IntToStr(nVisionIndex) + " : " + Strthetaoffset);

                if(StrXoffset == "E")
                {
					//nWriteCommunicationDM(1 , topViErr);
					StrXoffset = StrYoffset = Strthetaoffset = "999";
                    VisionHistoryData(_ALIGN_VISION2_,"Data receives the Error DATA!");
					//return;
				}

                g_MMIComm->m_mmiToSeq.buffer.topPRsResult[nVisionIndex].x = StrToFloat(StrXoffset);
                g_MMIComm->m_mmiToSeq.buffer.topPRsResult[nVisionIndex].y = StrToFloat(StrYoffset);
                g_MMIComm->m_mmiToSeq.buffer.topPRsResult[nVisionIndex].t = StrToFloat(Strthetaoffset);
            }

            g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_TOP_VI_RESULT;
            if(g_MMIComm->Send()  && g_MMIComm->Recv())
            {

            }
            else
            {
                nWriteCommunicationDM(1 , topViErr);
                VisionHistoryData(_ALIGN_VISION2_,"Data Communication Fail!");
                return;
            }
        }
        else
        {
        	nWriteCommunicationDM(1 , topViErr);
    		VisionHistoryData(_ALIGN_VISION2_,"Data missing the data count!");
            return;
        }
	}
    else
    {
    	VisionHistoryData(_ALIGN_VISION2_,"Data missing the terminator!");
    }
}
//---------------------------------------------------------------------------

void TFrmVisionSetUp::BottomVisionTransferControl()
{
	String StrCount  , StrXoffset , StrYoffset ,Strthetaoffset;
	if (StrRecvBTMBuffer.Pos(";") >0)
	{
		CHAR seps[]={",;"};
		CHAR buf [256];
		strcpy(buf, StrRecvBTMBuffer.c_str());
        StrRecvBTMBuffer = "";

		StrCount = ::strtok(buf, seps);
        VisionHistoryData(_ALIGN_VISION1_, "COUNT : " + StrCount);

		if(StrCount != "")
		{
            StrXoffset = ::strtok(NULL, seps);
            StrYoffset = ::strtok(NULL, seps);
            Strthetaoffset = ::strtok(NULL, seps);

			VisionHistoryData(_ALIGN_VISION1_, "XVALUE : " + StrXoffset);
			VisionHistoryData(_ALIGN_VISION1_, "YVALUE : " + StrYoffset);
			VisionHistoryData(_ALIGN_VISION1_, "TVALUE : " + Strthetaoffset);

			String strLog = "";
			int cmd = nReadCommunicationDM(mapStageNum) - 1;

			// lot
			g_MMIComm->m_mmiToSeq.nCmd = cmd + CMD_RD_STG1_LOT_INFO;
			BOOL bRet = g_MMIComm->Send() &&  g_MMIComm->Recv();
			if (!bRet)
				return;

			LOT_INFO& info = g_MMIComm->m_mmiToSeq.buffer.lotInfo;
			if (cmd == CMD_RD_LOT_END_INFO)
			{
				info = g_MMIComm->m_mmiToSeq.buffer.lotInfoCopy;
			}

			String partID = info.partID;
			String lotID = info.lotID;

			strLog = partID + " " + lotID + " " + IntToStr(nReadCommunicationDM(mapStageNum)) + " " + IntToStr(nReadCommunicationDM(mapStagePickNum)) + " " + StrXoffset + " " +  StrYoffset + " " + Strthetaoffset;

			String logMessage = "";
			logMessage = Now().FormatString("yyyy-mm-dd hh:mm:ss")+ " " + strLog;
			TDateTime dt = Now();
			String fileName = dt.FormatString("yyyy-mm-dd") + ".txt";

			if (_currentLogFileNameBtm != fileName)
			{
				if (_fpl)
					fclose(_fpl);
				String sDir = "C:\\KOSES\\History\\VisionBtmHistory\\";
				ForceDirectories(sDir);
				String fullPathName = sDir + fileName;
				_fpl = _wfopen(fullPathName.c_str(), L"at");
				assert(_fpl);
				_currentLogFileNameBtm = fileName;
			}

			fputws(logMessage.c_str(), _fpl);
			fputws(L"\n", _fpl);

			fflush(_fpl);
			//////////////////////////////////////////////////////////////

            if(StrXoffset == "E")
            {
				//nWriteCommunicationDM(1 , btmViErr);
				VisionHistoryData(_ALIGN_VISION2_,"Data receives the Error DATA!");
				StrXoffset = StrYoffset = Strthetaoffset = "999";
				//return;
            }

            g_MMIComm->m_mmiToSeq.buffer.btmPRsResult.x = StrToFloat(StrXoffset);
			g_MMIComm->m_mmiToSeq.buffer.btmPRsResult.y = StrToFloat(StrYoffset);
            g_MMIComm->m_mmiToSeq.buffer.btmPRsResult.t = StrToFloat(Strthetaoffset);

            g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_BTM_VI_RESULT;
            if(g_MMIComm->Send()  && g_MMIComm->Recv())
            {

            }
            else
            {
                nWriteCommunicationDM(1 , btmViErr);
                VisionHistoryData(_ALIGN_VISION1_,"Data Communication Fail!");
                return;
            }
        }
        else
        {
        	nWriteCommunicationDM(1 , btmViErr);
    		VisionHistoryData(_ALIGN_VISION1_,"Data missing the data count!");
            return;
        }

	}
    else
    {
    	VisionHistoryData(_ALIGN_VISION1_,"Data missing the terminator!");
    }
}
//---------------------------------------------------------------------------

void TFrmVisionSetUp::QCVisionRecvControl()   // 0 : Pass     others  :  fail
{
	bool sign = false;
	String StrCount  , StrQCResult;
	if (StrQCRecvBuffer.Pos(";") >0)
	{
		CHAR seps[]={",;"};
		CHAR buf [256];
		strcpy(buf, StrQCRecvBuffer.c_str());
        StrQCRecvBuffer = "";

		StrCount = ::strtok(buf, seps);
        VisionHistoryData(_PRE_QC_VISION_, "COUNT : " + StrCount);
		if(StrCount != "")
		{
            for(int nVisionIndex=0; nVisionIndex<StrCount.ToInt(); nVisionIndex++)
            {
				StrQCResult = ::strtok(NULL, seps);
                if( StrQCResult == "E")
				{
					StrQCResult = "999";
					//nWriteCommunicationDM(1 , qcViErr);
					VisionHistoryData(_PRE_QC_VISION_,"Data receives the Error DATA!!");
					//return;
                }

				if(StrQCResult != "0")
					sign = true;

				VisionHistoryData(_PRE_QC_VISION_, "RESULT  " + IntToStr(nVisionIndex) + " : " + StrQCResult);
				g_MMIComm->m_mmiToSeq.buffer.qcViResult[nVisionIndex] = StrToInt(StrQCResult);
			}

            g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_QC_VI_RESULT;
            if(g_MMIComm->Send()  && g_MMIComm->Recv())
            {

			}
			else
			{
				nWriteCommunicationDM(1 , qcViErr);
				VisionHistoryData(_PRE_QC_VISION_,"Data Communication Fail!");
				return;
			}

			if(!sign)
				nWriteCommunicationDM(1, stageTraceFlag);
			else if(sign)
				nWriteCommunicationDM(0, stageTraceFlag);
		}
		else
		{
			nWriteCommunicationDM(1 , qcViErr);
			VisionHistoryData(_PRE_QC_VISION_,"Data missing the data count!");
			return;
		}
	}
    else
    {
		VisionHistoryData(_PRE_QC_VISION_,"Data missing the terminator!");
    }
}
//---------------------------------------------------------------------------
//ret val 999 : 정의도지 않은 command
int TFrmVisionSetUp::VisionCommandJudgement(AnsiString StrRecvBuffer)
{
	int nRet = 0;
	if (StrRecvBuffer.Pos(";") >0)
	{
		CHAR seps[]={",;"};
		CHAR buf [128];
		strcpy(buf, StrRecvBuffer.c_str());
        StrRecvBuffer = "";

		String StrTemp = ::strtok(buf, seps);

		if(StrTemp == "motion")
        {
			nRet = 1;
        }
        else
        {
            nRet = 2;
        }
	}
    else
    {
		nRet =99;
    }

    return nRet;
}
//---------------------------------------------------------------------------

void TFrmVisionSetUp::MoveVisionControl(int nCamIndex , AnsiString StrBuffer)
{
	String StrCmd , StrIndex , StrXoffset , StrYoffset;
	if (StrRecvBTMBuffer.Pos(";") >0)
	{
		CHAR seps[]={",;"};
		CHAR buf [64];
		strcpy(buf, StrBuffer.c_str());
        StrBuffer = "";

		StrCmd = ::strtok(buf, seps);
        VisionHistoryData(nCamIndex, "Command : " + StrCmd);

		if(StrCmd != "")
		{
            StrIndex = ::strtok(NULL, seps);
            StrXoffset = ::strtok(NULL, seps);
            StrYoffset = ::strtok(NULL, seps);

            VisionHistoryData(nCamIndex, "XVALUE : " + StrXoffset);
            VisionHistoryData(nCamIndex, "YVALUE : " + StrYoffset);
            VisionHistoryData(nCamIndex, "INDEX : " + StrIndex);

			this->ExecuteVisionMoveSend( StrToInt(StrIndex), StrXoffset  , StrYoffset);
        }
        else
        {
    		VisionHistoryData(nCamIndex,"MoveVisionControl data missing the data command!");
        }

	}
    else
	{
    	VisionHistoryData(nCamIndex,"MoveVisionControl data missing the terminator!");
    }
}
//---------------------------------------------------------------------------

bool TFrmVisionSetUp::JobChangeVisionConversion(AnsiString StrRecipename)
{
	if (NULL == m_SorterJobSocket)
	{
		VisionHistoryData(_SORTER_JOB_CHANGE_VISION_,"Job Change Data Send Fail : Job change soket is NULL.");
		return false;
	}

	try
	{
		String StrTemp;
		StrTemp = "JOB,"+StrRecipename+";";

		VisionHistoryData(_SORTER_JOB_CHANGE_VISION_,"Data Send :" + StrTemp.Trim());
		m_SorterJobSocket->SendText(StrTemp);
		return true;
	}
	catch(Exception& e)
	{
		VisionHistoryData(_SORTER_JOB_CHANGE_VISION_,"Data Recv Fail  : " + e.Message);
		return false;
	}

}
//---------------------------------------------------------------------------

void TFrmVisionSetUp::JobChangeVCutVision(AnsiString StrOF)
{
	if (NULL == m_SorterJobSocket)
	{
		VisionHistoryData(_SORTER_JOB_CHANGE_VISION_,"Job Change V Cut Data Send Fail : Job change soket is NULL.");
	}

	try
	{
		VisionHistoryData(_SORTER_JOB_CHANGE_VISION_,"Job Change V Cut Data Send :" + StrOF.Trim());
		m_SorterJobSocket->SendText(StrOF);
	}
	catch(Exception& e)
	{
		VisionHistoryData(_SORTER_JOB_CHANGE_VISION_,"Job Change V Cut Data Send Fail  : " + e.Message);
	}

}
//---------------------------------------------------------------------------

bool TFrmVisionSetUp::LotInfoSendToVision(AnsiString strLotID, AnsiString strBarcodeID, AnsiString strPARTID)
{
	if (NULL == m_SorterJobSocket)
	{
		VisionHistoryData(_SORTER_JOB_CHANGE_VISION_,"Lot Info Data Send Fail : Job change soket is NULL.");
		return false;
	}

	try
	{
		String StrTemp;
		// bar,barcodeid,lotid;
		StrTemp = "BAR,"+strBarcodeID+","+strLotID+","+strPARTID+";";

		VisionHistoryData(_SORTER_JOB_CHANGE_VISION_,"Data Send :" + StrTemp.Trim());

		m_SorterJobSocket->SendText(StrTemp);
		return true;
	}
	catch(Exception& e)
	{
		VisionHistoryData(_SORTER_JOB_CHANGE_VISION_,"Data Recv Fail  : " + e.Message);
		return false;
	}

}
//---------------------------------------------------------------------------

bool TFrmVisionSetUp::TrayVisiontTextSend(AnsiString StrID)
{
	if (NULL == m_TraySocket)
		return false;

	try
	{
		String StrTemp;
		StrTemp = "ID,"+StrID+";";

		VisionHistoryData(_TRAY_VISION_,"Data Send :" + StrTemp.Trim());
		m_TraySocket->SendText(StrTemp);
		return true;
	}
	catch(Exception& e)
	{
		VisionHistoryData(_TRAY_VISION_,"Data Recv Fail  : " + e.Message);
		return false;
	}

}
//---------------------------------------------------------------------------


bool TFrmVisionSetUp::TrayInfo(AnsiString partID, AnsiString trayMark)
{
	if (NULL == m_SorterJobSocket)
	{
		VisionHistoryData(_SORTER_JOB_CHANGE_VISION_,"Tray info send fail : Job change soket is NULL.");
		return false;
	}

	try
	{
		String StrTemp;
		StrTemp = "TID,"+partID+","+trayMark+";";

		VisionHistoryData(_SORTER_JOB_CHANGE_VISION_,"Data Send :" + StrTemp.Trim());
		m_SorterJobSocket->SendText(StrTemp);
		return true;
	}
	catch(Exception& e)
	{
		VisionHistoryData(_SORTER_JOB_CHANGE_VISION_,"Data Recv Fail  : " + e.Message);
		return false;
	}

}
//---------------------------------------------------------------------------


void TFrmVisionSetUp::VisionClosingProcess()
{
	if(BtmAlignVisionServer->Active == true)
	{
		BtmAlignVisionServer->Active = false;
	}

	if(FlpAlignVisionServer->Active == true)
	{
		FlpAlignVisionServer->Active = false;
	}

   	if(PreQCSocket->Active == true)
	{
		PreQCSocket->Active = false;
	}

	if(SorterJobChangeVisionServer->Active == true)
	{
		SorterJobChangeVisionServer->Active = false;
	}

   	if(TraySocket->Active == true)
	{
		TraySocket->Active = false;
	}
	nWriteCommunicationDM(0,flagVisionComm);
	nWriteCommunicationDM(0,stateQcDataSendR);
}
//---------------------------------------------------------------------------
void __fastcall TFrmVisionSetUp::FormDestroy(TObject *Sender)
{
    if(m_AlignSocket1 != NULL)
    {
       // delete m_AlignSocket;
        m_AlignSocket1 = NULL;
    }

    if(m_AlignSocket2 != NULL)
    {
       // delete m_AlignSocket;
        m_AlignSocket2 = NULL;
    }
    if(m_PreQCSocket != NULL)
    {
       // delete m_PreQCSocket;
        m_PreQCSocket = NULL;
    }

    if(m_SorterJobSocket != NULL)
    {
       // delete m_PreQCSocket;
        m_SorterJobSocket = NULL;
    }

	if(m_TraySocket != NULL)
	{
	   // delete m_PreQCSocket;
		m_TraySocket = NULL;
	}

	if(m_QpdSocket != NULL)
	{
	   // delete m_PreQCSocket;
		m_QpdSocket = NULL;
	}

	BtmSendClientSocket->OnDisconnect = NULL;
	BtmSendClientSocket->Active = false;

	if (_fp)
		fclose(_fp);
	if (_fpl)
		fclose(_fpl);

	_fp = NULL;
	_fpl = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TFrmVisionSetUp::BtnCloseClick(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------


void __fastcall TFrmVisionSetUp::VisionMemoChange(TObject *Sender)
{
	SendMessage(VisionMemo->Handle, WM_VSCROLL, SB_BOTTOM, 0);
}
//---------------------------------------------------------------------------

//int nVisionIndex , = 0 : QC  , 1 : BTM ,2 : TOP
bool TFrmVisionSetUp::ExecuteVisionMoveSend(int nVisionIndex , String StrX , String StrY)
{
	if(StrX != "" && StrY != "")
    {
    	g_MMIComm->m_mmiToSeq.buffer.viMoveCmd.viNo = nVisionIndex;
        g_MMIComm->m_mmiToSeq.buffer.viMoveCmd.posX =  StrToFloat(StrX);
        g_MMIComm->m_mmiToSeq.buffer.viMoveCmd.posY =  StrToFloat(StrY);

        g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_VI_MOVE;
        if(g_MMIComm->Send()  && g_MMIComm->Recv())
        {
        	VisionHistoryData(nVisionIndex ,"X: " + StrX  + "<>  Y: " +StrY + " MOVE!");
			return true;
        }
    }
    else
    {
        return false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TFrmVisionSetUp::BtnExecuteMoveClick(TObject *Sender)
{
    FrmCdBox->setFlag(CD_YESNO);
    FrmCdBox->setTitle( "MOVE CONTROL" );
    FrmCdBox->setText( "Do you want to MOVE as the X,Y Value?" );
	if( mrYes == FrmCdBox->ShowModal())
    {
        int nIndex ;

        for(int nVisionIndex=0; nVisionIndex<3; nVisionIndex++)
        {
            TRadioButton* CloneRadioBtn = (TRadioButton*)FindComponent("RadioBtn" + IntToStr(nVisionIndex+1));
            if(CloneRadioBtn->Checked == true)
            {
                nIndex = nVisionIndex;
            }
        }

        this->ExecuteVisionMoveSend( nIndex, EditXValue->Text , EditYValue->Text);
    }
}
//---------------------------------------------------------------------------
void  	TFrmVisionSetUp::send_dvi(TCustomWinSocket *Socket)
{
	int group = nReadGroupNo();
	int recipe = nReadRecipeNo();

    TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini");
    double drillSize = ini->ReadFloat("GERBER","DRILL_SIZE",1.6);
    delete ini;

    String msg = "DVI,";

	String file = ExtractFilePath(Application->ExeName)+ "\\ini\\system\\GRP"+IntToStr(group)+"\\RCP"+IntToStr(recipe)+"\\exportData.ini";
	if(FileExists(file))
	{
		TIniFile* orgData = new TIniFile(file);

		int pathCnt = orgData->ReadInteger("PATH_ARRAY_INFO","PATH_COUNT",0);
        msg += IntToStr(pathCnt) +",";

        for(int i=0; i < pathCnt; i++)
        {
            double sx = orgData->ReadFloat("PATH_DATA","PATH_"+IntToStr(i)+"_START_X",0);
            double sy = orgData->ReadFloat("PATH_DATA","PATH_"+IntToStr(i)+"_START_Y",0);
            double ex = orgData->ReadFloat("PATH_DATA","PATH_"+IntToStr(i)+"_END_X",0);
            double ey = orgData->ReadFloat("PATH_DATA","PATH_"+IntToStr(i)+"_END_Y",0);

			double dirY	= 1;
			if(sx < ex) dirY = -1;
			else if(sx == ex) dirY = 0;

			double dirX	= 1;
			if(sy > ey) dirX = -1;
			else if(sy == ey) dirX = 0;

			double rsX  = sx + dirX*drillSize/2;
			double rsY  = sy + dirY*drillSize/2;

			double reX  = ex + dirX*drillSize/2;
			double reY  = ey + dirY*drillSize/2;

            String SX = FloatToStrF(rsX,ffFixed,10,3);
            String SY = FloatToStrF(rsY,ffFixed,10,3);
            String EX = FloatToStrF(reX,ffFixed,10,3);
			String EY = FloatToStrF(reY,ffFixed,10,3);

            msg += SX + "_" + SY + "_" + EX + "_" + EY;
            if(i != pathCnt-1) msg += ",";
        }

        msg += ";";

		delete orgData;
	}
	else
	{
     	msg += "E;";
	}

    if(Socket)
    {
    	try
        {
            Socket->SendText(msg);
			//VisionHistoryData(_SORTER_JOB_CHANGE_VISION_,"Send :" + msg);
            return ;
        }
        catch(Exception& e)
        {
			//VisionHistoryData(_SORTER_JOB_CHANGE_VISION_,"Data Recv Fail  : " + e.Message);
            return ;
        }





    }
    else
    {
    	VisionHistoryData(_SORTER_JOB_CHANGE_VISION_,"Socket disconnected.");
    }
}

//--------------------------------------------------------------------------
void TFrmVisionSetUp::send_job()
{
	int nGroupIndex = nReadGroupNo();
	int nRecipeIndex = nReadRecipeNo();

	nGroupIndex = nRecipeIndex = 1;

	TIniFile *RecipeNameini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\RecipeName.ini");
	String RetStr = RecipeNameini->ReadString("GROUP_"+IntToStr(nGroupIndex),"RECIPENAME"+IntToStr(nRecipeIndex),"");
	delete RecipeNameini;

	this->JobChangeVisionConversion(AnsiString(RetStr));
}
//--------------------------------------------------------------------------


void TFrmVisionSetUp::send_trayinfo()
{
	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_LOT_END_INFO;

	if (g_MMIComm->Send() &&  g_MMIComm->Recv())
	{
		LOT_INFO& info = g_MMIComm->m_mmiToSeq.buffer.lotInfoCopy;

		this->TrayInfo(info.partID, info.tray1Mark);
	}
}
//--------------------------------------------------------------------------


void __fastcall TFrmVisionSetUp::Label1Click(TObject *Sender)
{
//	this->send_dvi();
	this->send_job();
}
//---------------------------------------------------------------------------

void __fastcall TFrmVisionSetUp::DVIServerSocketClientConnect(TObject *Sender, TCustomWinSocket *Socket)

{
	VisionHistoryData(_DVI_,"Connected.");//
}
//---------------------------------------------------------------------------

void __fastcall TFrmVisionSetUp::DVIServerSocketClientDisconnect(TObject *Sender,
          TCustomWinSocket *Socket)
{
	VisionHistoryData(_DVI_,"Disconneted.");
}
//---------------------------------------------------------------------------

void __fastcall TFrmVisionSetUp::DVIServerSocketClientError(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode)
{
	try
	{
		Socket->Close();
		VisionHistoryData(_DVI_,"Connection have a problem.");
	}

	catch (Exception &exception)
	{
		VisionHistoryData(_DVI_,"Exception" + IntToStr(ErrorCode));
	}
	ErrorCode= 0;
}
//---------------------------------------------------------------------------

void __fastcall TFrmVisionSetUp::DVIServerSocketClientRead(TObject *Sender, TCustomWinSocket *Socket)

{
	char *buf = NULL;
	try
	{
		int len = Socket->ReceiveLength();
		if (0 == len)
			return;

		buf = new char[len+1];
		ZeroMemory(buf, len+1);
		Socket->ReceiveBuf(buf, len);

        //if( bChkRCPchk == true)
        {
        	//bChkRCPchk = false;
            if(0 == strnicmp(buf, "DVI;", 4))
            {
                this->send_dvi(Socket);
            }
            else
            {
            	String StrTemp = buf;
	   			VisionHistoryData(_DVI_,"Data Received :" + StrTemp.Trim());
            }
        }
	}
	catch (Exception &exception)
	{
	}
	delete [] buf;
}
//---------------------------------------------------------------------------

void __fastcall TFrmVisionSetUp::ReqRCClientSocketConnect(TObject *Sender, TCustomWinSocket *Socket)
{
	VisionHistoryData(-1, "REQ RECONNECTED.");
    try
	{
        Socket->SendText("REQ;");
        VisionHistoryData(-1, "REQ RECONNECT SEND : REQ;");
    }
	catch (Exception &e)
	{
    	VisionHistoryData(-1, "Exception on Send : "  + e.Message);
	}

    ReqRCClientSocket->Active = false;
}
//---------------------------------------------------------------------------

void __fastcall TFrmVisionSetUp::ReqRCClientSocketError(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode)
{
    VisionHistoryData(-1, "REQ RECONNECT Socket Error : " + IntToStr(ErrorCode));
    ErrorCode= 0;

    ReqRCClientSocket->Active = false;
}
//---------------------------------------------------------------------------


void __fastcall TFrmVisionSetUp::btnTrayInfoSendClick(TObject *Sender)
{
	send_trayinfo();
}
//---------------------------------------------------------------------------

void __fastcall TFrmVisionSetUp::QpdSorketClientConnect(TObject *Sender, TCustomWinSocket *Socket)
{
	m_QpdSocket = Socket;
	VisionHistoryData(_QPD_QC_VISION_,"Connected.");
	StrQPDRecvBuffer = "";
}
//---------------------------------------------------------------------------


void __fastcall TFrmVisionSetUp::QpdSorketClientDisconnect(TObject *Sender, TCustomWinSocket *Socket)
{
	m_QpdSocket = NULL;
	VisionHistoryData(_QPD_QC_VISION_,"Disconneted.");
	StrQPDRecvBuffer = "";
}
//---------------------------------------------------------------------------

void __fastcall TFrmVisionSetUp::QpdSorketClientError(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode)
{
	try
	{
		Socket->Close();
		VisionHistoryData(_QPD_QC_VISION_,"Connection have a problem.");
	}

	catch (Exception &exception)
	{
		VisionHistoryData(_QPD_QC_VISION_,"Exception" + IntToStr(ErrorCode));
	}

	m_QpdSocket = NULL;
	StrQPDRecvBuffer = "";
	ErrorCode= 0;
}
//---------------------------------------------------------------------------

void __fastcall TFrmVisionSetUp::QpdSorketClientRead(TObject *Sender, TCustomWinSocket *Socket)
{
		StrQPDRecvBuffer +=   Socket->ReceiveText();

		int QPD_USE = dReadPkgData(usQpdVi);

		if (QPD_USE == 1)
		{
			if ( StrQPDRecvBuffer.Pos(";") > 0)
			{
				VisionHistoryData(_QPD_QC_VISION_, "Recv:"+ StrQPDRecvBuffer);

				int nVal = VisionCommandJudgement(StrQPDRecvBuffer);

				if(1 == nVal)
				{
					// this->MoveVisionControl(_QPD_QC_VISION_ , StrQPDRecvBuffer);
					StrQPDRecvBuffer = "";
				}
				else if(2 == nVal)
				{
					this->QPDVisionRecvControl();
				}
			}
			else
			{
				// 문자열 종결자(;)가 발견되지 않음
				// 다음번꺼에 도착할지 모름
			}
		}
}
//---------------------------------------------------------------------------
void TFrmVisionSetUp::QPDVisionRecvControl()   // 0 : Pass     others  :  fail
{
	int QPD_USE = dReadPkgData(usQpdVi);

	if (QPD_USE == 1)
	{
		String StrCount, StrXoffset , StrYoffset ,Strthetaoffset;

		if (StrQPDRecvBuffer.Pos(";") >0)
		{
			CHAR seps[]={",;"};
			CHAR buf [3000];
			strcpy(buf, StrQPDRecvBuffer.c_str());
			StrQPDRecvBuffer = "";
			StrCount = ::strtok(buf, seps);
			VisionHistoryData(_QPD_QC_VISION_, "COUNT : " + StrCount);
			if(StrCount != "")
			{
				int cnt = StrCount.ToInt();
				for(int nVisionIndex=0; nVisionIndex<cnt; nVisionIndex++)
				{
					StrXoffset = ::strtok(NULL, seps);
					StrYoffset = ::strtok(NULL, seps);
					Strthetaoffset = ::strtok(NULL, seps);

					VisionHistoryData(_QPD_QC_VISION_, "XVALUE  " + IntToStr(nVisionIndex) + " : " + StrXoffset);
					VisionHistoryData(_QPD_QC_VISION_, "YVALUE  " + IntToStr(nVisionIndex) + " : " + StrYoffset);
					VisionHistoryData(_QPD_QC_VISION_, "TVALUE  " + IntToStr(nVisionIndex) + " : " + Strthetaoffset);

					if(StrXoffset == "E")
					{
						//nWriteCommunicationDM(1 , topViErr);
						StrXoffset = StrYoffset = Strthetaoffset = "999";
						VisionHistoryData(_QPD_QC_VISION_,"Data receives the Error DATA!");
						//return;
					}

					g_MMIComm->m_mmiToSeq.buffer.qpdPRsResult[nVisionIndex].x = StrToFloat(StrXoffset);
					g_MMIComm->m_mmiToSeq.buffer.qpdPRsResult[nVisionIndex].y = StrToFloat(StrYoffset);
					g_MMIComm->m_mmiToSeq.buffer.qpdPRsResult[nVisionIndex].t = StrToFloat(Strthetaoffset);

					if(nVisionIndex == (cnt-1))
					{
						// 현재 최대 100개까지만
						for (int gc = cnt; gc < 100; gc++)
						{
							g_MMIComm->m_mmiToSeq.buffer.qpdPRsResult[gc].x = 0.0;
							g_MMIComm->m_mmiToSeq.buffer.qpdPRsResult[gc].y = 0.0;
							g_MMIComm->m_mmiToSeq.buffer.qpdPRsResult[gc].t = 0.0;
						}
					}
				}

				g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_QPD_VI_RESULT;
				if(g_MMIComm->Send()  && g_MMIComm->Recv())
				{
					}
				else
				{
					nWriteCommunicationDM(1 , qcViErr);
					VisionHistoryData(_QPD_QC_VISION_,"Data Communication Fail!");
					return;
				}
			}
			else
			{
				nWriteCommunicationDM(1 , qcViErr);
				VisionHistoryData(_QPD_QC_VISION_,"Data missing the data count!");
				return;
			}
		}
		else
		{
			VisionHistoryData(_PRE_QC_VISION_,"Data missing the terminator!");
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmVisionSetUp::BtnPreQPDVisionClick(TObject *Sender)
{
	if(ChkPreQPDVision->Checked == true)
	{
		ChkPreQPDVision->Checked = false;
		BtnPreQPDVision->Caption ="QPD VISION OFF";
		QpdSorket->Active = false;
//        Status_Led(MainForm->MainPanelLed1 ,_STATUS_LED_GREEN_ , false , "OFF");

	}
	else
	{
		ChkPreQPDVision->Checked = true;
		BtnPreQPDVision->Caption ="QPD VISION ON";
		QpdSorket->Active = true;
//        Status_Led(MainForm->MainPanelLed1 ,_STATUS_LED_GREEN_ , true , "ON");
	}

	TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini");
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini"))
	{
		ini->WriteBool("QPDVISION","ONOFFChk",ChkPreQCVision->Checked);
	}
	delete ini;
}
//---------------------------------------------------------------------------
void __fastcall TFrmVisionSetUp::Btn_QpdCmdClick(TObject *Sender)
{
   g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_QPDDATA;
   if(g_MMIComm->Send()  && g_MMIComm->Recv())
   {
   }
   else
   {
	 nWriteCommunicationDM(1 , qcViErr);
	 VisionHistoryData(_PRE_QC_VISION_,"CMD_RD_QPDDATA Communication Fail!");
	 return;
   }
}
//---------------------------------------------------------------------------
void __fastcall TFrmVisionSetUp::RemoveTree(String stDirectory)
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
			{
				RemoveTree(chFileName); // 디렉토리면 RemoveTree를 재귀 호출
				RemoveDir(chFileName) ; // delete directory
			}
			else
				DeleteFile(chFileName);

			}
		} while(FindNextFile(hdHandle, &fdFiles));

		FindClose(hdHandle);
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmVisionSetUp::Btn_OpenLogFolderClick(TObject *Sender)
{
	TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\ini\\Setup.ini");
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\ini\\Setup.ini"))
	{
		String sDate = Date();
		if(!ini->SectionExists("V-CUT_VISION"))
		{
			ini->WriteString("V-CUT_VISION","PATH","C:\\V-CUT_VISION");
			ini->WriteString("V-CUT_VISION","DATE",sDate);
			ini->WriteString("V-CUT_VISION","TYPE","NEVER");
			ini->WriteString("V-CUT_VISION","VALUE","0");
		}

		String sFilePath = "";
		sFilePath = ini->ReadString("V-CUT_VISION", "PATH", "");

		const wchar_t* widecstr = sFilePath.c_str();

		LPCWSTR pszPathToOpen = widecstr;
		PIDLIST_ABSOLUTE pidl;
		if (SUCCEEDED(SHParseDisplayName(pszPathToOpen, 0, &pidl, 0, 0)))
		{
			ITEMIDLIST idNull = { 0 };
			LPCITEMIDLIST pidlNull[1] = { &idNull };
			SHOpenFolderAndSelectItems(pidl, 1, pidlNull, 0);
			ILFree(pidl);
		}
	}
}
//---------------------------------------------------------------------------
void TFrmVisionSetUp::vCutFileDelete()
{
//	if (!bReadUseSkip(usVcutImageDelete))
		return;

	TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\ini\\Setup.ini");
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\ini\\Setup.ini"))
	{
		String sDate = Date();
		if(!ini->SectionExists("V-CUT_VISION"))
		{
			ini->WriteString("V-CUT_VISION","PATH","C:\\V-CUT_VISION");
			ini->WriteString("V-CUT_VISION","DATE",sDate);
			ini->WriteString("V-CUT_VISION","TYPE","NEVER");
			ini->WriteString("V-CUT_VISION","VALUE","0");
		}

		String sFilePath = "", sFileDate = "", sFileType = "", sFileValue = "";
		sFilePath = ini->ReadString("V-CUT_VISION", "PATH", "");
		sFileDate = ini->ReadString("V-CUT_VISION", "DATE", "");
		sFileType = ini->ReadString("V-CUT_VISION", "TYPE", "");
		sFileValue = ini->ReadString("V-CUT_VISION", "VALUE", "");

		if (false == DirectoryExists(sFilePath))
			return;
		if (sFileDate == "")
			return;
		if (sFileType == "" || sFileType == "NEVER" || sFileType == "YEAR")
			return;
		if (sFileValue == "" || sFileValue == "0")
			return;

		String sCompare = "";
		if (sFileType == "MON")
		{
			struct tm timeDate;
			memset(&timeDate,0,sizeof(struct tm));
			strptime(AnsiString(sFileDate).c_str(),"%Y-%m-%d", &timeDate);
			mktime(&timeDate);

			time_t tm_start = time(NULL), tm_end = time(NULL), tm_now = time(NULL);
			double d_diff;
			tm_start = mktime(&timeDate);
			time(&tm_end);
			d_diff = difftime(tm_end, tm_start);

			timeDate.tm_mon += StrToInt(sFileValue); // 값 계산 (월)

			struct tm* ptm = localtime(&tm_now);

			char cTimeDateBuf[256];
			strftime(cTimeDateBuf,sizeof(cTimeDateBuf),"%Y-%m-%d", &timeDate);
			String sLast(cTimeDateBuf);

			char cPtmBuf[256];
			strftime(cPtmBuf,sizeof(cPtmBuf),"%Y-%m-%d", ptm);
			String sCurrent(cPtmBuf);

			if (sLast.SubString(0, 7) <= sCurrent.SubString(0, 7))
			{
				if(true == DirectoryExists(sFilePath))
					RemoveTree(sFilePath);
			}
		}
		else if (sFileType == "DAY")
		{
			struct tm timeDate;
			memset(&timeDate,0,sizeof(struct tm));
			strptime(AnsiString(sFileDate).c_str(),"%Y-%m-%d", &timeDate);
			mktime(&timeDate);

			time_t tm_start = time(NULL), tm_end = time(NULL);
			int    itm_day;
			double d_diff;
			tm_start = mktime(&timeDate);
			time(&tm_end);
			d_diff = difftime(tm_end, tm_start);
			itm_day = d_diff / ( 60 * 60 * 24); // 차이 값 (일)

			if (itm_day >= sFileValue)
			{
				if(true == DirectoryExists(sFilePath))
					RemoveTree(sFilePath);
			}
		}
	}
	delete ini;
}
//---------------------------------------------------------------------------
void __fastcall TFrmVisionSetUp::Btn_vCutSaveClick(TObject *Sender)
{
	vCutProcessStateChange("Select");
}
//---------------------------------------------------------------------------

void __fastcall TFrmVisionSetUp::Btn_VisionImageOnClick(TObject *Sender)
{
	JobChangeVCutVision("IMAGEON");
}
//---------------------------------------------------------------------------

void __fastcall TFrmVisionSetUp::Btn_VisionImageOffClick(TObject *Sender)
{
	JobChangeVCutVision("IMAGEOFF");
}
//---------------------------------------------------------------------------

void __fastcall TFrmVisionSetUp::BtmSendClientSocketConnect(TObject *Sender, TCustomWinSocket *Socket)
{
	VisionHistoryData(-1, "BOTTOM VISION SEND - RECONNECTED.");
	try
	{
		//Socket->SendText("BOTTOM VISION SEND SOCKET REQ;");
		VisionHistoryData(-1, "BOTTOM VISION SEND - RECONNECT SEND : REQ;");
	}
	catch (Exception &e)
	{
		VisionHistoryData(-1, "Bottom Vision Send - Exception on Send : "  + e.Message);
	}

	// BtmSendClientSocket->Active = false;
}
//---------------------------------------------------------------------------

void __fastcall TFrmVisionSetUp::BtmSendClientSocketError(TObject *Sender, TCustomWinSocket *Socket,
		  TErrorEvent ErrorEvent, int &ErrorCode)
{
	VisionHistoryData(-1, "BOTTOM VISION SEND - RECONNECT Socket Error : " + IntToStr(ErrorCode));
	ErrorCode= 0;

	BtmSendClientSocket->Active = false;
}
//---------------------------------------------------------------------------

void __fastcall TFrmVisionSetUp::Button1Click(TObject *Sender)
{
	try
	{
		int useDL = dReadPkgData(BottomVisionSendUse);

		if (useDL == 1)
		{
				int nGroupIndex = nReadGroupNo();
				int nRecipeIndex = nReadRecipeNo();

				TIniFile *RecipeNameini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\RecipeName.ini");
				String RetStr = RecipeNameini->ReadString("GROUP_"+IntToStr(nGroupIndex),"RECIPENAME"+IntToStr(nRecipeIndex),"");
				delete RecipeNameini;

				AnsiString data;
				AnsiString params[7];

				AnsiString eqpVisionID = "";
				eqpVisionID = MainForm->_eqpVisionID.Trim();

				TIniFile *PkgParmini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(nGroupIndex)+"\\RCP"+IntToStr(nRecipeIndex)+"\\RcpInfo.ini");

				if (!PkgParmini->ReadString("RECIPE","EQP_VISION_ID","").Trim().IsEmpty())
				{
				   eqpVisionID = PkgParmini->ReadString("RECIPE","EQP_VISION_ID","");
				}

				int nStageNum = dReadPkgData(qpdvisionPickStage);
				g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_STG1_LOT_INFO+nStageNum;
				BOOL bRet = g_MMIComm->Send() &&  g_MMIComm->Recv();
				if (bRet)
				{
					LOT_INFO info = g_MMIComm->m_mmiToSeq.buffer.lotInfo;

					params[0] = eqpVisionID;
					params[1] = String(info.lotID);
					params[2] = String(info.partID);
					params[3] = RetStr;
					params[4] = IntToStr(info.lotQty);
					params[5] = "FALSE";
					params[6] = "Trigger";

					data.sprintf("VISION_ID=%s,LOT_NO=%s,PART_NO=%s,RECIPE_ID=%s,SERIALCOUNT=%s,TEST_MODE=%s,COMMAND=%s",\
					params[0].c_str(),
					params[1].c_str(),
					params[2].c_str(),
					params[3].c_str(),
					params[4].c_str(),
					params[5].c_str(),
					params[6].c_str());

					int nCheck = FrmVisionSetUp->send_btminfo(data);

					if(nCheck)
					{
						MainForm->MachineHistoryData("Send Data Vision : " + data);
					}
					else
					{
						MainForm->MachineHistoryData("onlineBtmVisionStep : Send Fail");
						nWriteCommunicationDM(STATE_ERR, onlineBtmVisionStep);
					}
				}
				else
				{
					MainForm->MachineHistoryData("onlineBtmVisionStep : Cmd Send Fail");
					nWriteCommunicationDM(STATE_ERR, onlineBtmVisionStep);
				}
		}
	}
	catch(Exception& e)
	{
		MainForm->MachineHistoryData("onlineBtmVisionStep : Send Exception");
		nWriteCommunicationDM(STATE_ERR, onlineBtmVisionStep);
		MainForm->MachineHistoryData("Exception : " + e.Message);
	}
}
//---------------------------------------------------------------------------
BOOL TFrmVisionSetUp::send_btminfo(WideString data)
{
	BOOL result = true;
	try
	{
		if (BtmSendClientSocket->Active && BtmSendClientSocket->Socket && BtmSendClientSocket->Socket->Connected)
		{
			BtmSendClientSocket->Socket->SendText(data);
			result = true;
		}
		else
		{
			MainForm->MachineHistoryData("Socket not connected - send_btminfo.");
			MainForm->MachineHistoryData("Socket not connected - send_btminfo Fail");
			nWriteCommunicationDM(STATE_ERR, onlineBtmVisionStep);
			result = false;
		}
	}
	catch(Exception& e)
	{
		BtmSendClientSocket->Active = false;
		MainForm->MachineHistoryData("Exception send_btminfo : " + e.Message  );
		result = false;
	}

	return result;
}
//---------------------------------------------------------------------------
void __fastcall TFrmVisionSetUp::BtmSendClientSocketRead(TObject *Sender, TCustomWinSocket *Socket)
{
	StrDLRecvBuffer = "";
	StrDLRecvBuffer += Socket->ReceiveText();

	int useDL = dReadPkgData(BottomVisionSendUse);

	String StrEqpVisionID, StrResult;

	if (useDL == 1)
	{
		if (StrDLRecvBuffer.Pos(",") > 0)
		{
			String StrEqpVisionID = "", StrResult = "";

			TStringList *list = new TStringList();
			list->Delimiter = ',';
			list->StrictDelimiter = true;
			list->DelimitedText = StrDLRecvBuffer;

			if (list->Count >= 2)
			{
				StrEqpVisionID = list->Strings[0].Trim();
				StrResult      = list->Strings[1].Trim();

				MainForm->MachineHistoryData("DL Recv Buffer : " + StrDLRecvBuffer  );
				MainForm->MachineHistoryData("DL Recv eqpVisionID : " + StrEqpVisionID  );
				MainForm->MachineHistoryData("DL Recv Result : " + StrResult  );

				if (StrResult.UpperCase() == "GOOD")
				{
					nWriteCommunicationDM(0, btmVisionResultStep);
					nWriteCommunicationDM(STATE_COMP, onlineBtmVisionStep);
				}
				else
				{
					nWriteCommunicationDM(1, btmVisionResultStep);
					nWriteCommunicationDM(STATE_COMP, onlineBtmVisionStep);
				}
			}
			else
			{
				nWriteCommunicationDM(STATE_ERR, onlineBtmVisionStep);
				MainForm->MachineHistoryData("DL Recv Fail (invalid item count)");
			}

			delete list;
		}
		else
		{
			nWriteCommunicationDM(STATE_ERR, onlineBtmVisionStep);
			MainForm->MachineHistoryData("DL Recv Fail");
		}
	}
	else
	{
		nWriteCommunicationDM(STATE_IDLE, onlineBtmVisionStep);
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmVisionSetUp::Set_btmVisionOptionClick(TObject *Sender)
{
	TMemIniFile *m_ini = NULL;
	bool bSaveSuccess = false;

	try
	{
		int nGroupIndex = nReadGroupNo();
		int nRecipeIndex = nReadRecipeNo();

		String sRcpFilePath = ExtractFilePath(Application->ExeName) +
							  "ini\\system\\GRP" + IntToStr(nGroupIndex) +
							  "\\RCP" + IntToStr(nRecipeIndex) + "\\";

		if (!set_VisionID->Text.Trim().IsEmpty())
		{
			m_ini = new TMemIniFile(sRcpFilePath + "RcpInfo.ini");
			m_ini->WriteString("RECIPE", "EQP_VISION_ID", set_VisionID->Text.Trim());
			m_ini->UpdateFile();

			bSaveSuccess = true;
		}
	}
	catch (...)
	{
		bSaveSuccess = false;
	}

	if (m_ini != NULL)
	{
		delete m_ini;
	}

	if (bSaveSuccess)
	{
		FrmCdBox->setFlag(CD_OK);
		FrmCdBox->setTitle("EQP_VISION_ID CHANGE!");
		FrmCdBox->setText("Save completed.");
		FrmCdBox->ShowModal();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmVisionSetUp::Read_btmVisionOptionClick(TObject *Sender)
{
	TMemIniFile *m_ini = NULL;

	try
	{
		int nGroupIndex = nReadGroupNo();
		int nRecipeIndex = nReadRecipeNo();

		String sRcpFilePath = ExtractFilePath(Application->ExeName) +
							  "ini\\system\\GRP" + IntToStr(nGroupIndex) +
							  "\\RCP" + IntToStr(nRecipeIndex) + "\\";

		m_ini = new TMemIniFile(sRcpFilePath + "RcpInfo.ini");

		if (!m_ini->ReadString("RECIPE","EQP_VISION_ID","").Trim().IsEmpty())
		{
			read_VisionID->Text = m_ini->ReadString("RECIPE","EQP_VISION_ID","");
		}
		else
		{
			read_VisionID->Text = "";
		}

		read_Use->Text = dReadPkgData(BottomVisionSendUse);
		read_Option->Text = dReadPkgData(BottomVisionSendOption);
	}
	catch (...)
	{
	}

	if (m_ini != NULL)
	{
		delete m_ini;
	}
}
//---------------------------------------------------------------------------

