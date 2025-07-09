//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <stdio.h>
#include <vector>
#include "LaserSetUpScrn.h"
#include "Main.h"
//#include "AutoCalScrn.h"
#include "RecipeScrn.h"
#include "VisionSetUpScrn.h"
#include "SecsSetupScrn.h"
#include "cdbox.h"
#include "LotRcvShowScrn.h"
#include "ManualDrillingScrn.h"
//---------------------------------------------------------------------------
#include "Infovider.h"
#include "BaseProcess.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "LMDButton"
#pragma link "LMDCustomButton"

#pragma link "iThreadTimers"
#pragma resource "*.dfm"
TFrmLaserSetUp *FrmLaserSetUp;


#define   _LASER_CORRECTION_1_            21
#define   _LASER_CORRECTION_2_            22
#define   _LASER_CORRECTION_3_            23
#define   _LASER_CORRECTION_4_            24

#define   _LASER_Identifier_1_            32
#define   _LASER_Identifier_2_            33
#define   _LASER_Identifier_3_            34
#define   _LASER_Identifier_4_            35

#define   _LASER1_GetValue_RPT_           32
#define   _LASER2_GetValue_RPT_           33
#define   _LASER3_GetValue_RPT_           34
#define   _LASER4_GetValue_RPT_           35

#define   _LASER_JobChange_1_             36
#define   _LASER_JobChange_2_             37
#define   _LASER_JobChange_3_             38
#define   _LASER_JobChange_4_             39

#define   _LASER1_CYCLING_                 5  // 1: running
#define   _LASER2_CYCLING_                 6
#define   _LASER3_CYCLING_                 5  // 1: running
#define   _LASER4_CYCLING_                 6

#define	  _MAX_LASER_CNT_				   4
//---------------------------------------------------------------------------
__fastcall TFrmLaserSetUp::TFrmLaserSetUp(TComponent* Owner)
	: TForm(Owner)
{

	RefreshTagLaser1 = false;
	RefreshTagLaser2 = false;
	RefreshTagLaser3 = false;
	RefreshTagLaser4 = false;

	AckNakLaser1 = false;
	AckNakLaser2 = false;
	AckNakLaser3 = false;
	AckNakLaser4 = false;

	SystemTeach1 = false;
	SystemTeach2 = false;
	SystemTeach3 = false;
	SystemTeach4 = false;

	AutoCAL1 = false;
	AutoCAL2 = false;
	AutoCAL3 = false;
	AutoCAL4 = false;

    bMarkingTime1 = false;
    bMarkingTime2 = false;
    bMarkingTime3 = false;
    bMarkingTime4 = false;

	CorrectionCAL1 = false;
	CorrectionCAL2 = false;
	CorrectionCAL3 = false;
	CorrectionCAL4 = false;

    bMarkingSend1 = false;
    bMarkingSend2 = false;
    bMarkingSend3 = false;
    bMarkingSend4 = false;

	pBuf =NULL;

	_bServerConnected = TRUE;
	_bClientConnected = FALSE;

	g_nDataCnt = 0;

	LaserLogPage->OwnerDraw = true;
	LaserLogPage->Font->Style = TFontStyles() << fsBold;
}
//---------------------------------------------------------------------------
void __fastcall TFrmLaserSetUp::LaserLogPageDrawTab(TCustomTabControl *Control,
	  int TabIndex, const TRect &Rect, bool Active)
{
	TSize extent;
	String caption = LaserLogPage->Pages[TabIndex]->Caption;
	TRIVERTEX Vert[2];
	GRADIENT_RECT  gRect;
	Vert[0].x         = Rect.left;
	Vert[0].y         = Rect.top;
	Vert[0].Red     = 0xff00;
	Vert[0].Green = 0xff00;
	Vert[0].Blue    = 0xff00;
	Vert[0].Alpha   = 0;

	Vert[1].x          = Rect.right;
	Vert[1].y          = Rect.bottom;
	Vert[1].Red     = 0xA300;
	Vert[1].Green  = 0x9D00;
	Vert[1].Blue     = 0x8900;
	Vert[1].Alpha    = 0;

	gRect.UpperLeft = 0;
	gRect.LowerRight = 1;

	if(Active)
	{
		GradientFill(Control->Canvas->Handle,Vert, 2, &gRect, 1, GRADIENT_FILL_RECT_V);
		Control->Canvas->Brush->Style=bsClear;
		extent = Control->Canvas->TextExtent(caption);
	}
	else
	{
		Control->Canvas->Brush->Color = clBtnFace;
		Control->Canvas->Font->Color = clSilver;
		Control->Canvas->FillRect(Rect);
		Control->Canvas->Font->Style = TFontStyles() >> fsBold;
		extent = Control->Canvas->TextExtent(caption);
	}

	int dx = (Rect.Width() - extent.cx) / 2;
	int dy = (Rect.Height() - extent.cy) / 2;

	Control->Canvas->TextRect(Rect, Rect.Left + dx, Rect.Top + dy, caption);
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::Laser1HistoryData(String StrTemp)
{
	Laser1Memo->Lines->Add(DateTimeToStr(Now()) + ": " + StrTemp);
	Laser1Memo->Refresh();

	if(Laser1Memo->Lines->Count > 1000)
	{
		TDateTime dt = Now();
		String FolderName = dt.FormatString("yyyy-mm-dd");
		String FileName = dt.FormatString("yyyy-mm-dd hh-nn-ss");
		String FullPath  =  "C:\\KOSES\\History\\Laser1History\\"+ FolderName +"\\";
		ForceDirectories(FullPath);

		Laser1Memo->Lines->SaveToFile(FullPath + FileName+".txt");

		Laser1Memo->Clear();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmLaserSetUp::Laser2HistoryData(String StrTemp)
{
	Laser2Memo->Lines->Add(DateTimeToStr(Now()) + ": " + StrTemp);
	Laser2Memo->Refresh();

	if(Laser2Memo->Lines->Count > 1000)
	{
		TDateTime dt = Now();
		String FolderName = dt.FormatString("yyyy-mm-dd");
		String FileName = dt.FormatString("yyyy-mm-dd hh-nn-ss");
		String FullPath  =  "C:\\KOSES\\History\\Laser2History\\"+ FolderName +"\\";
		ForceDirectories(FullPath);

		Laser2Memo->Lines->SaveToFile(FullPath + FileName+".txt");

		Laser2Memo->Clear();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmLaserSetUp::Laser3HistoryData(String StrTemp)
{
	Laser3Memo->Lines->Add(DateTimeToStr(Now()) + ": " + StrTemp);
	Laser3Memo->Refresh();

	if(Laser3Memo->Lines->Count > 1000)
	{
		TDateTime dt = Now();
		String FolderName = dt.FormatString("yyyy-mm-dd");
		String FileName = dt.FormatString("yyyy-mm-dd hh-nn-ss");
		String FullPath  =  "C:\\KOSES\\History\\Laser3History\\"+ FolderName +"\\";
		ForceDirectories(FullPath);

		Laser3Memo->Lines->SaveToFile(FullPath + FileName+".txt");

		Laser3Memo->Clear();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmLaserSetUp::Laser4HistoryData(String StrTemp)
{
	Laser4Memo->Lines->Add(DateTimeToStr(Now()) + ": " + StrTemp);
	Laser4Memo->Refresh();

	if(Laser4Memo->Lines->Count > 1000)
	{
		TDateTime dt = Now();
		String FolderName = dt.FormatString("yyyy-mm-dd");
		String FileName = dt.FormatString("yyyy-mm-dd hh-nn-ss");
		String FullPath  =  "C:\\KOSES\\History\\Laser4History\\"+ FolderName +"\\";
		ForceDirectories(FullPath);

		Laser4Memo->Lines->SaveToFile(FullPath + FileName+".txt");

		Laser4Memo->Clear();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmLaserSetUp::SECSLaserHistoryData(String StrTemp , int Emphasis)
{

	if(Emphasis ==1)
	{
		SECSLaserMemo->SelAttributes->Color = clBlack;
		SECSLaserMemo->Lines->Add(DateTimeToStr(Now()) + ": " + StrTemp);

	}
	else if(Emphasis ==2)
	{
		SECSLaserMemo->SelAttributes->Color = clBlue;
		SECSLaserMemo->Lines->Add(DateTimeToStr(Now()) + ": " + StrTemp);
	}
	else if(Emphasis ==3)
	{
		SECSLaserMemo->SelAttributes->Color = clRed;
		SECSLaserMemo->Lines->Add(DateTimeToStr(Now()) + ": " + StrTemp);
	}
	SECSLaserMemo->Refresh();

	if(SECSLaserMemo->Lines->Count > 1000)
	{
		TDateTime dt = Now();
		String FolderName = dt.FormatString("yyyy-mm-dd");
		String FileName = dt.FormatString("yyyy-mm-dd hh-nn-ss");
		String FullPath  =  "C:\\KOSES\\History\\LASERSECSHistory\\"+ FolderName +"\\";
		ForceDirectories(FullPath);

		SECSLaserMemo->Lines->SaveToFile(FullPath + FileName+".txt");

		SECSLaserMemo->Clear();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmLaserSetUp::Laser1MemoChange(TObject *Sender)
{
	SendMessage(Laser1Memo->Handle, WM_VSCROLL, SB_BOTTOM, 0);
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::Laser2MemoChange(TObject *Sender)
{
	SendMessage(Laser2Memo->Handle, WM_VSCROLL, SB_BOTTOM, 0);
}
//---------------------------------------------------------------------------
void __fastcall TFrmLaserSetUp::Laser3MemoChange(TObject *Sender)
{
	SendMessage(Laser3Memo->Handle, WM_VSCROLL, SB_BOTTOM, 0);
}
//---------------------------------------------------------------------------
void __fastcall TFrmLaserSetUp::Laser4MemoChange(TObject *Sender)
{
	SendMessage(Laser4Memo->Handle, WM_VSCROLL, SB_BOTTOM, 0);
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::SECSLaserMemoChange(TObject *Sender)
{
	SendMessage(SECSLaserMemo->Handle, WM_VSCROLL, SB_BOTTOM, 0);
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::LaserHelloChk(int separator)
{
	try
	{
		AnsiString Hellobuf = "HELLO;";
		if(separator == 1)
		{
			if(TcpClientLaser1->Active == false)
			{
				TcpClientLaser1->Active = true;
			}

		 //	TcpClientLaser1->Socket->SendText(Hellobuf);
			//Laser1HistoryData("Laser1 : Hello Send");

		}
		else if(separator == 2)
		{
			if(TcpClientLaser2->Active == false)
			{
				TcpClientLaser2->Active = true;
			}

		  //	TcpClientLaser2->Socket->SendText(Hellobuf);
			//Laser2HistoryData("Laser2 : Hello Send");
		}
		else if(separator == 3)
		{
			if(TcpClientLaser3->Active == false)
			{
				TcpClientLaser3->Active = true;
			}

		 //	TcpClientLaser3->Socket->SendText(Hellobuf);
			//Laser3HistoryData("Laser3 : Hello Send");
		}
		else if(separator == 4)
		{
			if(TcpClientLaser4->Active == false)
			{
				TcpClientLaser4->Active = true;
			}

		 //	TcpClientLaser4->Socket->SendText(Hellobuf);
			//Laser4HistoryData("Laser4 : Hello Send");
		}
		if(LaserTransferTimer->Enabled == false)
		{
			LaserTransferTimer->Enabled = true;
		}

/*		if(LaserMarkingTrigger->Enabled == false)
		{
			LaserMarkingTrigger->Enabled = true;
		}
*/
	}
	catch (Exception &e)
	{
		Laser1HistoryData("LaserHelloChk" + e.Message );
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::BtnLaser1HeartbeatClick(TObject *Sender)
{
	if(ChkLaser1Heartbeat->Checked == true)
	{
		ChkLaser1Heartbeat->Checked = false;
		BtnLaser1Heartbeat->Caption ="LASER1 OFF";
		LaserHeartBeatTimer->Enabled1 = false;
		TcpClientLaser1->Active = false;
		TcpClientLaser1->Close();
		FrmMain->LEDLaser1Comm->Active = false;
		FrmMain->LEDLaser1Comm->CenterLabelText = "LASER1 OFF";
	}
	else
	{
		ChkLaser1Heartbeat->Checked = true;
		BtnLaser1Heartbeat->Caption ="LASER1 ON";
		TcpClientLaser1->Open();
		TcpClientLaser1->Active = true;
		FrmMain->LEDLaser1Comm->Active = true;
		FrmMain->LEDLaser1Comm->CenterLabelText = "LASER1 ON";
	}

	TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini");
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini"))
	{
		ini->WriteBool("LASER1","ONOFFChk",ChkLaser1Heartbeat->Checked);
	}
	delete ini;
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::BtnLaser2HeartbeatClick(TObject *Sender)
{
	if(ChkLaser2Heartbeat->Checked == true)
	{
		ChkLaser2Heartbeat->Checked = false;
		BtnLaser2Heartbeat->Caption ="LASER2 OFF";
		LaserHeartBeatTimer->Enabled2 = false;
		TcpClientLaser2->Active = false;
		TcpClientLaser2->Close();
		FrmMain->LEDLaser2Comm->Active = false;
		FrmMain->LEDLaser2Comm->CenterLabelText = "LASER2 OFF";
	}
	else
	{
		ChkLaser2Heartbeat->Checked = true;
		BtnLaser2Heartbeat->Caption ="LASER2 ON";
		TcpClientLaser2->Open();
		TcpClientLaser2->Active = true;
		FrmMain->LEDLaser2Comm->Active = true;
		FrmMain->LEDLaser2Comm->CenterLabelText = "LASER2 ON";
	}

	TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini");
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini"))
	{
		ini->WriteBool("LASER2","ONOFFChk",ChkLaser2Heartbeat->Checked);
	}
	delete ini;
}
//---------------------------------------------------------------------------
void __fastcall TFrmLaserSetUp::BtnLaser3HeartbeatClick(TObject *Sender)
{
	if(ChkLaser3Heartbeat->Checked == true)
	{
		ChkLaser3Heartbeat->Checked = false;
		BtnLaser3Heartbeat->Caption ="LASER3 OFF";
		LaserHeartBeatTimer->Enabled3 = false;
		TcpClientLaser3->Active = false;
		TcpClientLaser3->Close();
		FrmMain->LEDLaser3Comm->Active = false;
		FrmMain->LEDLaser3Comm->CenterLabelText = "LASER3 OFF";
	}
	else
	{
		ChkLaser3Heartbeat->Checked = true;
		BtnLaser3Heartbeat->Caption ="LASER3 ON";
		TcpClientLaser3->Open();
		TcpClientLaser3->Active = true;
		FrmMain->LEDLaser3Comm->Active = true;
		FrmMain->LEDLaser3Comm->CenterLabelText = "LASER3 ON";
	}

	TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini");
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini"))
	{
		ini->WriteBool("LASER3","ONOFFChk",ChkLaser3Heartbeat->Checked);
	}
	delete ini;
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::BtnLaser4HeartbeatClick(TObject *Sender)
{
	if(ChkLaser4Heartbeat->Checked == true)
	{
		ChkLaser4Heartbeat->Checked = false;
		BtnLaser4Heartbeat->Caption ="LASER4 OFF";
		LaserHeartBeatTimer->Enabled4 = false;
		TcpClientLaser4->Active = false;
		TcpClientLaser4->Close();
		FrmMain->LEDLaser4Comm->Active = false;
		FrmMain->LEDLaser4Comm->CenterLabelText = "LASER4 OFF";
	}
	else
	{
		ChkLaser4Heartbeat->Checked = true;
		BtnLaser4Heartbeat->Caption ="LASER4 ON";
		TcpClientLaser4->Open();
		TcpClientLaser4->Active = true;
		FrmMain->LEDLaser4Comm->Active = true;
		FrmMain->LEDLaser4Comm->CenterLabelText = "LASER4 ON";
	}

	TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini");
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini"))
	{
		ini->WriteBool("LASER4","ONOFFChk",ChkLaser4Heartbeat->Checked);
	}
	delete ini;
}
//---------------------------------------------------------------------------



void __fastcall TFrmLaserSetUp::StartLaserChkSwitch()
{
	TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini");
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini"))
	{
		if(ini->ReadBool("LASER1","ONOFFChk",true) == true)
		{
			ChkLaser1Heartbeat->Checked = true;
			BtnLaser1Heartbeat->Caption ="LASER1 ON";
			TcpClientLaser1->Active = true;
			FrmMain->LEDLaser1Comm->Active = true;
			FrmMain->LEDLaser1Comm->CenterLabelText = "LASER1 ON";
		}
		else
		{
			ChkLaser1Heartbeat->Checked = false;
			BtnLaser1Heartbeat->Caption ="LASER1 OFF";
			FrmMain->LEDLaser1Comm->Active = false;
			FrmMain->LEDLaser1Comm->CenterLabelText = "LASER1 OFF";

		}

		if(ini->ReadBool("LASER2","ONOFFChk",true) == true)
		{
			ChkLaser2Heartbeat->Checked = true;
			BtnLaser2Heartbeat->Caption ="LASER2 ON";
			TcpClientLaser2->Active = true;
			FrmMain->LEDLaser2Comm->Active = true;
			FrmMain->LEDLaser2Comm->CenterLabelText = "LASER2 ON";

		}
		else
		{
			ChkLaser2Heartbeat->Checked = false;
			BtnLaser2Heartbeat->Caption ="LASER2 OFF";
			FrmMain->LEDLaser2Comm->Active = false;
			FrmMain->LEDLaser2Comm->CenterLabelText = "LASER2 OFF";
		}

		if(ini->ReadBool("LASER3","ONOFFChk",true) == true)
		{
			ChkLaser3Heartbeat->Checked = true;
			BtnLaser3Heartbeat->Caption ="LASER3 ON";
			TcpClientLaser3->Active = true;
			FrmMain->LEDLaser3Comm->Active = true;
			FrmMain->LEDLaser3Comm->CenterLabelText = "LASER3 ON";

		}
		else
		{
			ChkLaser3Heartbeat->Checked = false;
			BtnLaser3Heartbeat->Caption ="LASER3 OFF";
			FrmMain->LEDLaser3Comm->Active = false;
			FrmMain->LEDLaser3Comm->CenterLabelText = "LASER3 OFF";
		}

		if(ini->ReadBool("LASER4","ONOFFChk",true) == true)
		{
			ChkLaser4Heartbeat->Checked = true;
			BtnLaser4Heartbeat->Caption ="LASER4 ON";
			TcpClientLaser4->Active = true;
			FrmMain->LEDLaser4Comm->Active = true;
			FrmMain->LEDLaser4Comm->CenterLabelText = "LASER4 ON";

		}
		else
		{
			ChkLaser4Heartbeat->Checked = false;
			BtnLaser4Heartbeat->Caption ="LASER4 OFF";
			FrmMain->LEDLaser4Comm->Active = false;
			FrmMain->LEDLaser4Comm->CenterLabelText = "LASER4 OFF";
		}
	}
	else
	{
		MessageDlg("Setup.ini 파일을 찾을 수 없습니다!", mtWarning, TMsgDlgButtons() << mbOK, 0);
	}
	delete ini;
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::LaserHeartBeatTimerTimer1(TObject *Sender)
{
	if(ChkLaser1Heartbeat->Checked == true)
	{
		if(TcpClientLaser1->Active == true)
		{
			LaserHelloChk(1);
		}
		else
		{
			TcpClientLaser1->Active = true;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::LaserHeartBeatTimerTimer2(TObject *Sender)
{
	if(ChkLaser2Heartbeat->Checked == true)
	{
		if(TcpClientLaser2->Active == true)
		{
			LaserHelloChk(2);
		}
		else
		{
			TcpClientLaser2->Active = true;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::LaserHeartBeatTimerTimer3(TObject *Sender)
{
	if(ChkLaser3Heartbeat->Checked == true)
	{
		if(TcpClientLaser3->Active == true)
		{
			LaserHelloChk(3);
		}
		else
		{
			TcpClientLaser3->Active = true;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::LaserHeartBeatTimerTimer4(TObject *Sender)
{
	if(ChkLaser4Heartbeat->Checked == true)
	{
		if(TcpClientLaser4->Active == true)
		{
			LaserHelloChk(4);
		}
		else
		{
			TcpClientLaser4->Active = true;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::LaserHeartBeatTimerTimer5(TObject *Sender)
{
	if(ChkLaser1Heartbeat->Checked ==true)
	{
		LaserHeartBeatTimer->Enabled5 = false;
		TcpClientLaser1->Close();
		TcpClientLaser1->Active = false;
		TcpClientLaser1->Active = true;
	}
	else
	{
		if(TcpClientLaser1->Active == true)
		{
			TcpClientLaser1->Active = false;
		}
	}

}
//---------------------------------------------------------------------------
void __fastcall TFrmLaserSetUp::LaserHeartBeatTimerTimer6(TObject *Sender)
{
	if(ChkLaser2Heartbeat->Checked ==true)
	{
		LaserHeartBeatTimer->Enabled6 = false;
		TcpClientLaser2->Close();
		TcpClientLaser2->Active = false;
		TcpClientLaser2->Active = true;
	}
	else
	{
		if(TcpClientLaser2->Active == true)
		{
			TcpClientLaser2->Active = false;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::LaserHeartBeatTimerTimer7(TObject *Sender)
{
	if(ChkLaser3Heartbeat->Checked ==true)
	{
		LaserHeartBeatTimer->Enabled7 = false;
		TcpClientLaser3->Close();
		TcpClientLaser3->Active = false;
		TcpClientLaser3->Active = true;
	}
	else
	{
		if(TcpClientLaser3->Active == true)
		{
			TcpClientLaser3->Active = false;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::LaserHeartBeatTimerTimer8(TObject *Sender)
{
	if(ChkLaser4Heartbeat->Checked ==true)
	{
		LaserHeartBeatTimer->Enabled8 = false;
		TcpClientLaser4->Close();
		TcpClientLaser4->Active = false;
		TcpClientLaser4->Active = true;
	}
	else
	{
		if(TcpClientLaser4->Active == true)
		{
			TcpClientLaser4->Active = false;
		}
	}
}
//---------------------------------------------------------------------------


void __fastcall TFrmLaserSetUp::TcpClientLaser1Read(TObject *Sender,
	  TCustomWinSocket *Socket)
{

	char *buf = NULL;
	if(FrmMain->LEDLaser1Comm->Active == false)
	{
		FrmMain->LEDLaser1Comm->Active = true;
	}

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
		Laser1HistoryData(e.Message );
		return;
	}

	if( AckNakLaser1 == true &&
		0 == strnicmp(buf, "AK;", 3))
	{
		AckNakLaser1 = false;
		RefreshTagLaser1 = false;
		LaserTransferComplete(_LASER_Identifier_1_);

	}
	else if( AckNakLaser1 == true &&
		0 == strnicmp(buf, "NK;", 3))
	{
		AckNakLaser1 = false;
		RefreshTagLaser1 = false;
		WriteCommunicationDM(2, _LASER_Identifier_1_);
		Laser1HistoryData("PosArray NK");
	}

	if(SystemTeach1 == true &&
		0 == strnicmp(buf, "AK;", 3))
	{
		SystemTeach1 = false;
		Laser1HistoryData("SystemTeach1 AK");
		LaserJobChangeCompleteToSEQ(1);
	}
	else if(SystemTeach1 == true &&
		0 == strnicmp(buf, "NK;", 3))
	{
		SystemTeach1 = false;
		Laser1HistoryData("SystemTeach1 NK");
		LaserJobChangeFailToSEQ(1);
	}


	if(AutoCAL1 == true &&
		0 == strnicmp(buf, "AK;", 3))
	{
		AutoCAL1 = false;
		Laser1HistoryData("AutoCAL1 AK");
		LaserJobChangeCompleteToSEQ(1);
	}
	else if(AutoCAL1 == true &&
		0 == strnicmp(buf, "NK;", 3))
	{
		AutoCAL1 = false;
		Laser1HistoryData("AutoCAL1 NK");
		LaserJobChangeFailToSEQ(1);
	}

	if(CorrectionCAL1 == true &&
		0 == strnicmp(buf, "AK;", 3))
	{
		CorrectionCAL1 = false;
		Laser1HistoryData("CorrectionCAL1 AK");
		LaserTransferComplete(_LASER_CORRECTION_1_);
	}
	else if(CorrectionCAL1 == true &&
		0 == strnicmp(buf, "NK;", 3))
	{
		Laser1HistoryData("CorrectionCAL1 NK!");
	}

	if(bMarkingSend1 == true &&         //151015
		0 == strnicmp(buf, "AK;", 3))
	{
		AnsiString strMkBuf = "STATUS,MKSPEC;"; //  160406 LJY확인
		m_Laser_Socket1->SendText(strMkBuf);
		Laser1HistoryData("Laser1 : Status;MkSpec;");
		Laser1HistoryData("MarkingSpec Send to Laser AK!");

	}
	else if(bMarkingSend1 == true &&
		0 == strnicmp(buf, "NK;", 3))
	{
		LaserMarkingSendFeedBack(false , 1);
		bMarkingSend1 = false;
		Laser1HistoryData("MarkingSpec Send to Laser NK!");
	}

	if (0 == strnicmp(buf, "FILENAME", 8 ))
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
	}
	if (0 == strnicmp(buf, "MKSPEC", 6 ))
	{
		//_strLaserRecipeName[0] = "";
		CHAR seps[]={",;\r\n"};

		CHAR buffer[MAX_PATH];
		strcpy(buffer, buf);
		CHAR* token = ::strtok(buffer, seps);
		String strToken[3];
		if (token != NULL)
		{
//			token = ::strtok(NULL, seps);
			strToken[0] = ::strtok(NULL, seps);
			strToken[1] = ::strtok(NULL, seps);
			strToken[2] = ::strtok(NULL, seps);

		}
		if(strLaserMkModeChk[0] == strToken[2])
		{
			if(strLaserLotCodeChk[0] == strToken[0])
			{
			LaserMarkingSendFeedBack(true , 1);
			bMarkingSend1 = false;
			Laser1HistoryData("Laser1 : Status;MkSpec; "+strToken[0] );
			}
			else
			{
				LaserMarkingSendFeedBack(false , 1);
				bMarkingSend1 = false;
				Laser1HistoryData("Laser1 : Status;MkSpec; Fail" );
			}
		}
		else
		{
			if(strLaserMkModeChk[0] == strToken[0])
			{
				if(strToken[0] == "DRILL")
				{
				LaserMarkingSendFeedBack(true , 1);
				bMarkingSend1 = false;
				Laser1HistoryData("Laser1 : Status;MkSpec; DRILL MODE");
				}
				else
				{
					LaserMarkingSendFeedBack(false , 1);
					bMarkingSend1= false;
					Laser1HistoryData("Laser1 : Status;MkSpec; Fail" );
				}

			}
			else
			{
			Laser1HistoryData("Laser1 : Status;MkSpec; Marking MODE fail" );
			}
		}
	}


	Laser1HistoryData(buf);


	delete [] buf;
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::TcpClientLaser2Read(TObject *Sender,
	  TCustomWinSocket *Socket)
{
	char *buf;
	if(FrmMain->LEDLaser2Comm->Active == false)
	{
		FrmMain->LEDLaser2Comm->Active = true;
	}

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
		Laser2HistoryData(e.Message );
		return;
	}

	if( AckNakLaser2 == true &&
		0 == strnicmp(buf, "AK;",3))
	{
		AckNakLaser2 = false;
		RefreshTagLaser2 = false;
		LaserTransferComplete(_LASER_Identifier_2_);
	}
	else if( AckNakLaser2 == true &&
		0 == strnicmp(buf, "NK;", 3))
	{
		AckNakLaser2 = false;
		RefreshTagLaser2 = false;
		WriteCommunicationDM(2, _LASER_Identifier_2_);
		Laser2HistoryData("PosArray NK");
	}


	if(SystemTeach2 == true &&
		0 == strnicmp(buf, "AK;", 3))
	{
		SystemTeach2 = false;
		Laser2HistoryData("SystemTeach2 AK");
		LaserJobChangeCompleteToSEQ(2);
	}
	else if(SystemTeach2 == true &&
		0 == strnicmp(buf, "NK;", 3))
	{
		SystemTeach2 = false;
		Laser2HistoryData("SystemTeach2 NK");
		LaserJobChangeFailToSEQ(2);
	}


	if(AutoCAL2 == true &&
		0 == strnicmp(buf, "AK;", 3))
	{
		AutoCAL2 = false;
		Laser2HistoryData("AutoCAL2 AK");
		LaserJobChangeCompleteToSEQ(2);
	}
	else if(AutoCAL2 == true &&
		0 == strnicmp(buf, "NK;", 3))
	{
		AutoCAL2 = false;
		Laser2HistoryData("AutoCAL2 NK");
		LaserJobChangeFailToSEQ(2);
	}

	if(CorrectionCAL2 == true &&
		0 == strnicmp(buf, "AK;", 3))
	{
		CorrectionCAL2 = false;
		Laser2HistoryData("CorrectionCAL2 AK");
		LaserTransferComplete(_LASER_CORRECTION_2_);
	}
	else if(CorrectionCAL2 == true &&
		0 == strnicmp(buf, "NK;", 3))
	{
		//CorrectionCAL2 = false;
		//LaserJobChangeFailToSEQ(1);
		Laser2HistoryData("CorrectionCAL2 NK!");
	}

	if(bMarkingSend2 == true &&         //151015
		0 == strnicmp(buf, "AK;", 3))
	{
		AnsiString strMkBuf = "STATUS,MKSPEC;"; //  160406 LJY확인
		m_Laser_Socket2->SendText(strMkBuf);
		Laser2HistoryData("Laser2 : Status;MkSpec;");


//		bMarkingSend2 = false;
		Laser2HistoryData("MarkingSpec Send to Laser AK!");
//		LaserMarkingSendFeedBack(true , 2);
	}
	else if(bMarkingSend2 == true &&
		0 == strnicmp(buf, "NK;", 3))
	{
		bMarkingSend2 = false;
		LaserMarkingSendFeedBack(false , 2);
		Laser2HistoryData("MarkingSpec Send to Laser NK!");
	}

	if (0 == strnicmp(buf, "FILENAME", 8 ))
	{
		_strLaserRecipeName[1] = "";
		CHAR seps[]={",;\r\n"};

		CHAR buffer[MAX_PATH];
		strcpy(buffer, buf);
		CHAR* token = ::strtok(buffer, seps);
		if (token != NULL)
		{
			token = ::strtok(NULL, seps);
			_strLaserRecipeName[1] = token;
		}
	}
	if (0 == strnicmp(buf, "MKSPEC", 6 ))
	{
		//_strLaserRecipeName[0] = "";
		CHAR seps[]={",;\r\n"};

		CHAR buffer[MAX_PATH];
		strcpy(buffer, buf);
		CHAR* token = ::strtok(buffer, seps);
		String strToken[3];
		if (token != NULL)
		{
//			token = ::strtok(NULL, seps);
			strToken[0] = ::strtok(NULL, seps);
			strToken[1] = ::strtok(NULL, seps);
			strToken[2] = ::strtok(NULL, seps);

		}
		if(strLaserMkModeChk[1] == strToken[2])
		{
			if(strLaserLotCodeChk[1] == strToken[0])
			{
			LaserMarkingSendFeedBack(true , 2);
			bMarkingSend2 = false;
			Laser2HistoryData("Laser2 : Status;MkSpec; "+strToken[0] );
			}
			else
			{
				LaserMarkingSendFeedBack(false , 2);
				bMarkingSend2= false;
				Laser2HistoryData("Laser2 : Status;MkSpec; Fail" );
			}
		}
		else
		{
			if(strLaserMkModeChk[1] == strToken[0])
			{
				if(strToken[0] == "DRILL")
				{
				LaserMarkingSendFeedBack(true , 2);
				bMarkingSend2 = false;
				Laser2HistoryData("Laser2 : Status;MkSpec; DRILL MODE");
				}
				else
				{
					LaserMarkingSendFeedBack(false , 2);
					bMarkingSend2= false;
					Laser2HistoryData("Laser2 : Status;MkSpec; Fail" );
				}

			}
			else
			{
			Laser2HistoryData("Laser2 : Status;MkSpec; Marking MODE fail" );
			}
		}
	}


	Laser2HistoryData(buf);
	delete [] buf;
}
//---------------------------------------------------------------------------
void __fastcall TFrmLaserSetUp::TcpClientLaser3Read(TObject *Sender,
	  TCustomWinSocket *Socket)
{
	char *buf;
	if(FrmMain->LEDLaser3Comm->Active == false)
	{
		FrmMain->LEDLaser3Comm->Active = true;
	}

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
		Laser3HistoryData(e.Message );
		return;
	}

	if( AckNakLaser3 == true &&
		0 == strnicmp(buf, "AK;",3))
	{
		AckNakLaser3 = false;
		RefreshTagLaser3 = false;
		LaserTransferComplete(_LASER_Identifier_3_);
	}
	else if( AckNakLaser3 == true &&
		0 == strnicmp(buf, "NK;", 3))
	{
		AckNakLaser3 = false;
		RefreshTagLaser3 = false;
		WriteCommunicationDM(2, _LASER_Identifier_3_);
		Laser3HistoryData("PosArray NK");
	}

	if(SystemTeach3 == true &&
		0 == strnicmp(buf, "AK;", 3))
	{
		SystemTeach3 = false;
		Laser3HistoryData("SystemTeach3 AK");
		LaserJobChangeCompleteToSEQ(3);
	}
	else if(SystemTeach3 == true &&
		0 == strnicmp(buf, "NK;", 3))
	{
		SystemTeach3 = false;
		Laser3HistoryData("SystemTeach3 NK");
		LaserJobChangeFailToSEQ(3);
	}


	if(AutoCAL3 == true &&
		0 == strnicmp(buf, "AK;", 3))
	{
		AutoCAL3 = false;
		Laser3HistoryData("AutoCAL3 AK");
		LaserJobChangeCompleteToSEQ(3);
	}
	else if(AutoCAL3 == true &&
		0 == strnicmp(buf, "NK;", 3))
	{
		AutoCAL3 = false;
		Laser3HistoryData("AutoCAL3 NK");
		LaserJobChangeFailToSEQ(3);
	}

	if(CorrectionCAL3 == true &&
		0 == strnicmp(buf, "AK;", 3))
	{
		CorrectionCAL3 = false;
		Laser3HistoryData("CorrectionCAL3 AK");
		LaserTransferComplete(_LASER_CORRECTION_3_);
	}
	else if(CorrectionCAL3 == true &&
		0 == strnicmp(buf, "NK;", 3))
	{
		//CorrectionCAL2 = false;
		//LaserJobChangeFailToSEQ(1);
		Laser3HistoryData("CorrectionCAL3 NK!");
	}

	if(bMarkingSend3 == true &&         //151015
		0 == strnicmp(buf, "AK;", 3))
	{
		AnsiString strMkBuf = "STATUS,MKSPEC;"; //  160406 LJY확인
		m_Laser_Socket3->SendText(strMkBuf);
		Laser3HistoryData("Laser3 : Status;MkSpec;");

//		bMarkingSend3 = false;
		Laser3HistoryData("MarkingSpec Send to Laser AK!");
//		LaserMarkingSendFeedBack(true , 3);
	}
	else if(bMarkingSend3 == true &&
		0 == strnicmp(buf, "NK;", 3))
	{
		bMarkingSend3 = false;
		LaserMarkingSendFeedBack(false , 3);
		Laser3HistoryData("MarkingSpec Send to Laser NK!");
	}

	if (0 == strnicmp(buf, "FILENAME", 8 ))
	{
		_strLaserRecipeName[2] = "";
		CHAR seps[]={",;\r\n"};
		CHAR buffer[MAX_PATH];
		strcpy(buffer, buf);

		CHAR* token = ::strtok(buffer, seps);
		if (token != NULL)
		{
			token = ::strtok(NULL, seps);
			_strLaserRecipeName[2] = token;
		}
	}
	if (0 == strnicmp(buf, "MKSPEC", 6 ))
	{
		//_strLaserRecipeName[0] = "";
		CHAR seps[]={",;\r\n"};

		CHAR buffer[MAX_PATH];
		strcpy(buffer, buf);
		CHAR* token = ::strtok(buffer, seps);
		String strToken[3];
		if (token != NULL)
		{
//			token = ::strtok(NULL, seps);
			strToken[0] = ::strtok(NULL, seps);
			strToken[1] = ::strtok(NULL, seps);
			strToken[2] = ::strtok(NULL, seps);

		}
		if(strLaserMkModeChk[2] == strToken[2])
		{
			if(strLaserLotCodeChk[2] == strToken[0])
			{
			LaserMarkingSendFeedBack(true , 3);
			bMarkingSend3 = false;
			Laser3HistoryData("Laser3 : Status;MkSpec; "+strToken[0] );
			}
			else
			{
				LaserMarkingSendFeedBack(false , 3);
				bMarkingSend3= false;
				Laser3HistoryData("Laser3 : Status;MkSpec; Fail" );
			}
		}
		else
		{
			if(strLaserMkModeChk[2] == strToken[0])
			{
				if(strToken[0] == "DRILL")
				{
				LaserMarkingSendFeedBack(true , 3);
				bMarkingSend3 = false;
				Laser3HistoryData("Laser3 : Status;MkSpec; DRILL MODE");
				}
				else
				{
					LaserMarkingSendFeedBack(false , 3);
					bMarkingSend3= false;
					Laser3HistoryData("Laser3 : Status;MkSpec; Fail" );
				}
			}
			else
			{
			Laser3HistoryData("Laser3 : Status;MkSpec; Marking MODE fail" );
			}
		}
	}

	Laser3HistoryData(buf);
	delete [] buf;
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::TcpClientLaser4Read(TObject *Sender,
	  TCustomWinSocket *Socket)
{
	char *buf;
	if(FrmMain->LEDLaser4Comm->Active == false)
	{
		FrmMain->LEDLaser4Comm->Active = true;
	}

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
		Laser4HistoryData(e.Message );
		return;
	}

	if( AckNakLaser4 == true &&
		0 == strnicmp(buf, "AK;",3))
	{
		AckNakLaser4 = false;
		RefreshTagLaser4 = false;
		LaserTransferComplete(_LASER_Identifier_4_);
	}
	else if( AckNakLaser4 == true &&
		0 == strnicmp(buf, "NK;", 3))
	{
		AckNakLaser4 = false;
		RefreshTagLaser4 = false;
		WriteCommunicationDM(2, _LASER_Identifier_4_);
		Laser4HistoryData("PosArray NK");
	}

	if(SystemTeach4 == true &&
		0 == strnicmp(buf, "AK;", 3))
	{
		SystemTeach4 = false;
		Laser4HistoryData("SystemTeach4 AK");
		LaserJobChangeCompleteToSEQ(4);
	}
	else if(SystemTeach4 == true &&
		0 == strnicmp(buf, "NK;", 3))
	{
		SystemTeach4 = false;
		Laser4HistoryData("SystemTeach4 NK");
		LaserJobChangeFailToSEQ(4);
	}


	if(AutoCAL4 == true &&
		0 == strnicmp(buf, "AK;", 3))
	{
		AutoCAL4 = false;
		Laser4HistoryData("AutoCAL4 AK");
		LaserJobChangeCompleteToSEQ(4);
	}
	else if(AutoCAL4 == true &&
		0 == strnicmp(buf, "NK;", 3))
	{
		AutoCAL4 = false;
		Laser4HistoryData("AutoCAL4 NK");
		LaserJobChangeFailToSEQ(4);
	}

	if(CorrectionCAL4 == true &&
		0 == strnicmp(buf, "AK;", 3))
	{
		CorrectionCAL4 = false;
		Laser4HistoryData("CorrectionCAL4 AK");
		LaserTransferComplete(_LASER_CORRECTION_4_);
	}
	else if(CorrectionCAL4 == true &&
		0 == strnicmp(buf, "NK;", 3))
	{
		//CorrectionCAL2 = false;
		//LaserJobChangeFailToSEQ(1);
		Laser4HistoryData("CorrectionCAL4 NK!");
	}

	if(bMarkingSend4 == true &&         //151015
		0 == strnicmp(buf, "AK;", 3))
	{
		AnsiString strMkBuf = "STATUS,MKSPEC;"; //  160406 LJY확인
		m_Laser_Socket4->SendText(strMkBuf);
		Laser4HistoryData("Laser4 : Status;MkSpec;");

//		bMarkingSend4 = false;
		Laser4HistoryData("MarkingSpec Send to Laser AK!");
//		LaserMarkingSendFeedBack(true , 4);
	}
	else if(bMarkingSend4 == true &&
		0 == strnicmp(buf, "NK;", 3))
	{
		bMarkingSend4 = false;
		LaserMarkingSendFeedBack(false , 4);
		Laser4HistoryData("MarkingSpec Send to Laser NK!");
	}


	if (0 == strnicmp(buf, "FILENAME", 8 ))
	{
		_strLaserRecipeName[3] = "";
		CHAR seps[]={",;\r\n"};
		CHAR buffer[MAX_PATH];
		strcpy(buffer, buf);

		CHAR* token = ::strtok(buffer, seps);
		if (token != NULL)
		{
			token = ::strtok(NULL, seps);
			_strLaserRecipeName[3] = token;
		}
	}
	if (0 == strnicmp(buf, "MKSPEC", 6 ))
	{
		//_strLaserRecipeName[0] = "";
		CHAR seps[]={",;\r\n"};

		CHAR buffer[MAX_PATH];
		strcpy(buffer, buf);
		CHAR* token = ::strtok(buffer, seps);
		String strToken[3];
		if (token != NULL)
		{
//			token = ::strtok(NULL, seps);
			strToken[0] = ::strtok(NULL, seps);
			strToken[1] = ::strtok(NULL, seps);
			strToken[2] = ::strtok(NULL, seps);

		}
		if(strLaserMkModeChk[3] == strToken[2])
		{
			if(strLaserLotCodeChk[3] == strToken[0])
			{
			LaserMarkingSendFeedBack(true , 4);
			bMarkingSend4 = false;
			Laser4HistoryData("Laser4 : Status;MkSpec; "+strToken[0] );
			}
			else
			{
				LaserMarkingSendFeedBack(false , 4);
				bMarkingSend4= false;
				Laser4HistoryData("Laser4 : Status;MkSpec; Fail" );
			}
		}
		else
		{
			if(strLaserMkModeChk[3] == strToken[0])
			{
				if(strToken[0] == "DRILL")
				{
				LaserMarkingSendFeedBack(true , 4);
				bMarkingSend4 = false;
				Laser4HistoryData("Laser4 : Status;MkSpec; DRILL MODE");
				}
				else
				{
					LaserMarkingSendFeedBack(false , 4);
					bMarkingSend4= false;
					Laser4HistoryData("Laser4 : Status;MkSpec; Fail" );
				}
			}
			else
			{
			Laser4HistoryData("Laser4 : Status;MkSpec; Marking MODE fail" );
			}
		}
	}

	Laser4HistoryData(buf);
	delete [] buf;
}
//---------------------------------------------------------------------------


void __fastcall TFrmLaserSetUp::TcpClientLaser1Connect(TObject *Sender,
	  TCustomWinSocket *Socket)
{
	m_Laser_Socket1 = Socket;
	Laser1HistoryData("LASER1 과 연결되었습니다!");
	if(LaserHeartBeatTimer->Enabled5 == true)
	{
		LaserHeartBeatTimer->Enabled5 = false;
	}
	LaserHeartBeatTimer->Enabled1 = true;
	if(FrmRecipe->CheckBoxLaserConversionCommand->Enabled == false)
	{
		FrmRecipe->CheckBoxLaserConversionCommand->Enabled = true;
		FrmRecipe->CheckBoxLaserConversionCommand->Checked = true;
	}
 //	FrmAutoCal->AutoCalibrationMakeProcess();

 //	this->start(EditRootDir->Text , EditHostAddr->Text);
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::TcpClientLaser2Connect(TObject *Sender,
	  TCustomWinSocket *Socket)
{
	m_Laser_Socket2 = Socket;
	Laser2HistoryData("LASER2와  연결되었습니다!");
	if(LaserHeartBeatTimer->Enabled6 == true)
	{
		LaserHeartBeatTimer->Enabled6 = false;
	}
	LaserHeartBeatTimer->Enabled2 = true;
	//LaserHeartBeatTimer->Enabled3 = true;
	if(FrmRecipe->CheckBoxLaserConversionCommand->Enabled == false)
	{
		FrmRecipe->CheckBoxLaserConversionCommand->Enabled = true;
		FrmRecipe->CheckBoxLaserConversionCommand->Checked = true;
	}
 //	FrmAutoCal->AutoCalibrationMakeProcess();

//	this->start(EditRootDir->Text , EditHostAddr->Text);
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::TcpClientLaser3Connect(TObject *Sender,
	  TCustomWinSocket *Socket)
{
	m_Laser_Socket3 = Socket;
	Laser3HistoryData("LASER3과  연결되었습니다!");
	if(LaserHeartBeatTimer->Enabled7 == true)
	{
		LaserHeartBeatTimer->Enabled7 = false;
	}
	LaserHeartBeatTimer->Enabled3 = true;
	//LaserHeartBeatTimer->Enabled3 = true;
	if(FrmRecipe->CheckBoxLaserConversionCommand->Enabled == false)
	{
		FrmRecipe->CheckBoxLaserConversionCommand->Enabled = true;
		FrmRecipe->CheckBoxLaserConversionCommand->Checked = true;
	}
 //	FrmAutoCal->AutoCalibrationMakeProcess();

//	this->start(EditRootDir->Text , EditHostAddr->Text);
}
//---------------------------------------------------------------------------
void __fastcall TFrmLaserSetUp::TcpClientLaser4Connect(TObject *Sender,
	  TCustomWinSocket *Socket)
{
	m_Laser_Socket4 = Socket;
	Laser4HistoryData("LASER4와  연결되었습니다!");
	if(LaserHeartBeatTimer->Enabled8 == true)
	{
		LaserHeartBeatTimer->Enabled8 = false;
	}
	LaserHeartBeatTimer->Enabled4 = true;
	//LaserHeartBeatTimer->Enabled3 = true;
	if(FrmRecipe->CheckBoxLaserConversionCommand->Enabled == false)
	{
		FrmRecipe->CheckBoxLaserConversionCommand->Enabled = true;
		FrmRecipe->CheckBoxLaserConversionCommand->Checked = true;
	}
 //	FrmAutoCal->AutoCalibrationMakeProcess();

	this->start(EditRootDir->Text , EditHostAddr->Text);
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::TcpClientLaser1Error(TObject *Sender,
	  TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
	try
	{
		TcpClientLaser1->Socket->Close();
		TcpClientLaser1->Active = false;
		Laser1HistoryData("exception :" + IntToStr(ErrorCode));
		ErrorCode = 0;
        m_Laser_Socket1 = NULL;
	}

	catch (Exception &exception)
	{
		Laser1HistoryData("exception :" + IntToStr(ErrorCode));
		//Application->ShowException(&exception);
	}
	LaserHeartBeatTimer->Enabled1 = false;
	if(FrmRecipe->CheckBoxLaserConversionCommand->Enabled == true)
	{
		FrmRecipe->CheckBoxLaserConversionCommand->Checked = false;
		FrmRecipe->CheckBoxLaserConversionCommand->Enabled = false;
	}
	if(LaserHeartBeatTimer->Enabled5 == false && ChkLaser1Heartbeat->Checked == true)
	{
		LaserHeartBeatTimer->Enabled5 = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::TcpClientLaser2Error(TObject *Sender,
	  TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
	try
	{
		TcpClientLaser2->Socket->Close();
		TcpClientLaser2->Active = false;
		Laser2HistoryData("exception :" + IntToStr(ErrorCode));
		ErrorCode = 0;
        m_Laser_Socket2 = NULL;
	}

	catch (Exception &exception)
	{
		Laser2HistoryData("exception :" + IntToStr(ErrorCode));
		//Application->ShowException(&exception);
	}
	LaserHeartBeatTimer->Enabled2 = false;
	if(FrmRecipe->CheckBoxLaserConversionCommand->Enabled == true)
	{
		FrmRecipe->CheckBoxLaserConversionCommand->Checked = false;
		FrmRecipe->CheckBoxLaserConversionCommand->Enabled = false;
	}
	if(LaserHeartBeatTimer->Enabled6 == false && ChkLaser2Heartbeat->Checked == true)
	{
		LaserHeartBeatTimer->Enabled6 = true;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmLaserSetUp::TcpClientLaser3Error(TObject *Sender,
	  TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
	try
	{
		TcpClientLaser3->Socket->Close();
		TcpClientLaser3->Active = false;
		Laser3HistoryData("exception :" + IntToStr(ErrorCode));
		ErrorCode = 0;
        m_Laser_Socket3 = NULL;
	}

	catch (Exception &exception)
	{
		Laser3HistoryData("exception :" + IntToStr(ErrorCode));
		//Application->ShowException(&exception);
	}
	LaserHeartBeatTimer->Enabled3 = false;
	if(FrmRecipe->CheckBoxLaserConversionCommand->Enabled == true)
	{
		FrmRecipe->CheckBoxLaserConversionCommand->Checked = false;
		FrmRecipe->CheckBoxLaserConversionCommand->Enabled = false;
	}
	if(LaserHeartBeatTimer->Enabled7 == false && ChkLaser3Heartbeat->Checked == true)
	{
		LaserHeartBeatTimer->Enabled7 = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::TcpClientLaser4Error(TObject *Sender,
	  TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
	try
	{
		TcpClientLaser4->Socket->Close();
		TcpClientLaser4->Active = false;
		Laser4HistoryData("exception :" + IntToStr(ErrorCode));
		ErrorCode = 0;
        m_Laser_Socket4 = NULL;
	}

	catch (Exception &exception)
	{
		Laser4HistoryData("exception :" + IntToStr(ErrorCode));
		//Application->ShowException(&exception);
	}
	LaserHeartBeatTimer->Enabled4 = false;
	if(FrmRecipe->CheckBoxLaserConversionCommand->Enabled == true)
	{
		FrmRecipe->CheckBoxLaserConversionCommand->Checked = false;
		FrmRecipe->CheckBoxLaserConversionCommand->Enabled = false;
	}
	if(LaserHeartBeatTimer->Enabled8 == false && ChkLaser4Heartbeat->Checked == true)
	{
		LaserHeartBeatTimer->Enabled8 = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::TcpClientLaser1Disconnect(TObject *Sender,
	  TCustomWinSocket *Socket)
{
	m_Laser_Socket1 = NULL;
	Laser1HistoryData("LASER1 과 연결이 끊어졌습니다!");
	if(LaserHeartBeatTimer->Enabled5 == false && ChkLaser1Heartbeat->Checked == true)
	{
		LaserHeartBeatTimer->Enabled5 = true;
	}
	LaserHeartBeatTimer->Enabled1 = false;
	//LaserHeartBeatTimer->Enabled3 = false;
	if(FrmRecipe->CheckBoxLaserConversionCommand->Enabled == true)
	{
		FrmRecipe->CheckBoxLaserConversionCommand->Checked = false;
		FrmRecipe->CheckBoxLaserConversionCommand->Enabled = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::TcpClientLaser2Disconnect(TObject *Sender,
	  TCustomWinSocket *Socket)
{
	m_Laser_Socket2 = NULL;
	Laser2HistoryData("LASER2 와 연결이 끊어졌습니다!");
	if(LaserHeartBeatTimer->Enabled6 == false && ChkLaser2Heartbeat->Checked == true)
	{
		LaserHeartBeatTimer->Enabled6 = true;
	}
	LaserHeartBeatTimer->Enabled2 = false;
	//LaserHeartBeatTimer->Enabled3 = false;
	if(FrmRecipe->CheckBoxLaserConversionCommand->Enabled == true)
	{
		FrmRecipe->CheckBoxLaserConversionCommand->Checked = false;
		FrmRecipe->CheckBoxLaserConversionCommand->Enabled = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::TcpClientLaser3Disconnect(TObject *Sender,
	  TCustomWinSocket *Socket)
{
	m_Laser_Socket3 = NULL;
	Laser3HistoryData("LASER3 과 연결이 끊어졌습니다!");
	if(LaserHeartBeatTimer->Enabled7 == false && ChkLaser3Heartbeat->Checked == true)
	{
		LaserHeartBeatTimer->Enabled7 = true;
	}
	LaserHeartBeatTimer->Enabled3 = false;
	//LaserHeartBeatTimer->Enabled3 = false;
	if(FrmRecipe->CheckBoxLaserConversionCommand->Enabled == true)
	{
		FrmRecipe->CheckBoxLaserConversionCommand->Checked = false;
		FrmRecipe->CheckBoxLaserConversionCommand->Enabled = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::TcpClientLaser4Disconnect(TObject *Sender,
	  TCustomWinSocket *Socket)
{
	m_Laser_Socket4 = NULL;
	Laser4HistoryData("LASER4 와 연결이 끊어졌습니다!");
	if(LaserHeartBeatTimer->Enabled8 == false && ChkLaser4Heartbeat->Checked == true)
	{
		LaserHeartBeatTimer->Enabled8 = true;
	}
	LaserHeartBeatTimer->Enabled4 = false;
   //	LaserHeartBeatTimer->Enabled3 = false;
	if(FrmRecipe->CheckBoxLaserConversionCommand->Enabled == true)
	{
		FrmRecipe->CheckBoxLaserConversionCommand->Checked = false;
		FrmRecipe->CheckBoxLaserConversionCommand->Enabled = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::LaserJobChangeProcess(int nLaserNo ,String StrTemp)
{
	if(StrTemp !="")
	{
		AnsiString JOBbuf = "JOB,";
		try
		{
			if(nLaserNo == 1)
			{
				SystemTeach1 = true;
				m_Laser_Socket1->SendText(JOBbuf+StrTemp+";");

			}
			else if(nLaserNo == 2)
			{
				SystemTeach2 = true;
				m_Laser_Socket2->SendText(JOBbuf+StrTemp+";");
			}
			else if(nLaserNo == 3)
			{
				SystemTeach3 = true;
				m_Laser_Socket3->SendText(JOBbuf+StrTemp+";");
			}
			else if(nLaserNo == 4)
			{
				SystemTeach4 = true;
				m_Laser_Socket4->SendText(JOBbuf+StrTemp+";");
			}
			Laser1HistoryData("Laser"+IntToStr(nLaserNo)+": Job변경 " +JOBbuf+StrTemp);
		}

		catch (Exception &e)
		{
			if(nLaserNo == 1)
			{
				Laser1HistoryData("Laser1JobChangeProcess" + e.Message );
			}
			else if(nLaserNo == 2)
			{
				Laser2HistoryData("Laser2JobChangeProcess" + e.Message );
			}
			else if(nLaserNo == 3)
			{
				Laser3HistoryData("Laser3JobChangeProcess" + e.Message );
			}
			else if(nLaserNo == 4)
			{
				Laser4HistoryData("Laser4JobChangeProcess" + e.Message );
			}
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::Laser1AutoCalPorcess(String StrTemp)
{
	if(StrTemp !="")
	{
		try
		{
			AutoCAL1 = true;

			//TcpClientLaser1->Socket->SendText(StrTemp.Trim()); // 130110 임시 사용(추후 주석처리 예정)

			Laser1HistoryData("Laser1 : AutoCAL. " +StrTemp);

		}

		catch (Exception &e)
		{
			Laser1HistoryData("Laser1AutoCalPorcess" + e.Message );
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmLaserSetUp::Laser2AutoCalPorcess(String StrTemp)
{
	if(StrTemp !="")
	{
		try
		{
			AutoCAL2 = true;
			//TcpClientLaser2->Socket->SendText(StrTemp.Trim()); // 130110 임시 사용(추후 주석처리 예정)
			Laser2HistoryData("Laser2 : AutoCAL. " +StrTemp);
		}

		catch (Exception &e)
		{
			Laser2HistoryData("Laser2AutoCalPorcess" + e.Message );
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmLaserSetUp::Laser3AutoCalPorcess(String StrTemp)
{
	if(StrTemp !="")
	{
		try
		{
			AutoCAL3 = true;
			//TcpClientLaser3->Socket->SendText(StrTemp.Trim());  // 130110 임시 사용(추후 주석처리 예정)
			Laser3HistoryData("Laser3 : AutoCAL. " +StrTemp);
		}

		catch (Exception &e)
		{
			Laser3HistoryData("Laser3AutoCalPorcess" + e.Message );
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmLaserSetUp::Laser4AutoCalPorcess(String StrTemp)
{
	if(StrTemp !="")
	{
		try
		{
			AutoCAL4 = true;
			//TcpClientLaser4->Socket->SendText(StrTemp.Trim());  // 130110 임시 사용(추후 주석처리 예정)
			Laser4HistoryData("Laser4 : AutoCAL. " +StrTemp);
		}

		catch (Exception &e)
		{
			Laser4HistoryData("Laser4AutoCalPorcess" + e.Message );
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmLaserSetUp::PosArrayRowCol_RJCTLaserSendProcess(int nIdentifier) // 151014 modified the PosArrayLaserSendProcess function
{
	try
	{
		if(nIdentifier == _LASER_Identifier_1_ && RefreshTagLaser1 == true)
		{
			MMIComm->m_mmiToSeq.cmdType = CMD_RD_DRILL_COORD_FL;
			if (MMIComm->Send() &&  MMIComm->Recv())
			{
				String SendDataCnt =  IntToStr(MMIComm->m_mmiToSeq.bufferData.drillCoord.cnt);
				String SendOffsets;
				String SendHeader;

				for(int i=0; i<MMIComm->m_mmiToSeq.bufferData.drillCoord.cnt; i++)
				{
                    SendOffsets+= String(",") + IntToStr( MMIComm->m_mmiToSeq.bufferData.drillCoord.unit[i].arrange.Row);
                    SendOffsets+= String(",") + IntToStr( MMIComm->m_mmiToSeq.bufferData.drillCoord.unit[i].arrange.Col);
					SendOffsets+= String(",") + FloatToStrF( MMIComm->m_mmiToSeq.bufferData.drillCoord.unit[i].x ,ffFixed,10,5);
					SendOffsets+= String(",") + FloatToStrF( MMIComm->m_mmiToSeq.bufferData.drillCoord.unit[i].y ,ffFixed,10,5);
					SendOffsets+= String(",") + FloatToStrF( MMIComm->m_mmiToSeq.bufferData.drillCoord.theta,ffFixed,10,5);
					SendOffsets+= String(",") + IntToStr( MMIComm->m_mmiToSeq.bufferData.drillCoord.unit[i].Reject);   //150318  PMS FUNCTION ADDED
				}

				SendOffsets+= ";";
				//SendHeader = "posarrays,0,"+SendDataCnt+SendOffsets;
				SendHeader = "posarrayrowcolreject,0,"+SendDataCnt+SendOffsets;  //150318  PMS FUNCTION ADDED
				m_Laser_Socket1->SendText(SendHeader);
				AckNakLaser1 = true;
				Laser1HistoryData(SendHeader);
			}
			else
			{
				RefreshTagLaser1 = false;
				Laser1HistoryData("PosArrayRowCol_Reject _ LaserSendProcess1 SEND & RECV Fail");
			}
		}
		if(nIdentifier == _LASER_Identifier_2_&& RefreshTagLaser2 == true)
		{
			MMIComm->m_mmiToSeq.cmdType = CMD_RD_DRILL_COORD_FR;
			if (MMIComm->Send() &&  MMIComm->Recv())
			{
				String SendDataCnt =  IntToStr(MMIComm->m_mmiToSeq.bufferData.drillCoord.cnt);
				String SendOffsets;
				String SendHeader;

				for(int i=0; i<MMIComm->m_mmiToSeq.bufferData.drillCoord.cnt; i++)
				{
                    SendOffsets+= String(",") + IntToStr( MMIComm->m_mmiToSeq.bufferData.drillCoord.unit[i].arrange.Row);
                    SendOffsets+= String(",") + IntToStr( MMIComm->m_mmiToSeq.bufferData.drillCoord.unit[i].arrange.Col);
					SendOffsets+= String(",") + FloatToStrF(MMIComm->m_mmiToSeq.bufferData.drillCoord.unit[i].x,ffFixed,10,5 );
					SendOffsets+= String(",") + FloatToStrF(MMIComm->m_mmiToSeq.bufferData.drillCoord.unit[i].y,ffFixed,10,5 );
					SendOffsets+= String(",") + FloatToStrF(MMIComm->m_mmiToSeq.bufferData.drillCoord.theta,ffFixed,10,5 );
					SendOffsets+= String(",") + IntToStr( MMIComm->m_mmiToSeq.bufferData.drillCoord.unit[i].Reject);   //150318  PMS FUNCTION ADDED

				}
				SendOffsets+= ";";
				SendHeader = "posarrayrowcolreject,0,"+SendDataCnt+SendOffsets;
				m_Laser_Socket2->SendText(SendHeader);
				AckNakLaser2 = true;
				Laser2HistoryData(SendHeader);
			}
			else
			{
				RefreshTagLaser2 = false;
				Laser2HistoryData("PosArrayRowCol_Reject _ LaserSendProcess2 SEND & RECV Fail");
			}
		}
		if(nIdentifier == _LASER_Identifier_3_&& RefreshTagLaser3 == true)
		{
			MMIComm->m_mmiToSeq.cmdType = CMD_RD_DRILL_COORD_RL;
			if (MMIComm->Send() &&  MMIComm->Recv())
			{
				String SendDataCnt =  IntToStr(MMIComm->m_mmiToSeq.bufferData.drillCoord.cnt);
				String SendOffsets;
				String SendHeader;

				for(int i=0; i<MMIComm->m_mmiToSeq.bufferData.drillCoord.cnt; i++)
				{
					SendOffsets+= String(",") + IntToStr( MMIComm->m_mmiToSeq.bufferData.drillCoord.unit[i].arrange.Row);
					SendOffsets+= String(",") + IntToStr( MMIComm->m_mmiToSeq.bufferData.drillCoord.unit[i].arrange.Col);
					SendOffsets+= String(",") + FloatToStrF(MMIComm->m_mmiToSeq.bufferData.drillCoord.unit[i].x,ffFixed,10,5 );
					SendOffsets+= String(",") + FloatToStrF(MMIComm->m_mmiToSeq.bufferData.drillCoord.unit[i].y,ffFixed,10,5 );
					SendOffsets+= String(",") + FloatToStrF(MMIComm->m_mmiToSeq.bufferData.drillCoord.theta,ffFixed,10,5 );
					SendOffsets+= String(",") + IntToStr( MMIComm->m_mmiToSeq.bufferData.drillCoord.unit[i].Reject);   //150318  PMS FUNCTION ADDED

				}

				SendOffsets+= ";";
				SendHeader = "posarrayrowcolreject,0,"+SendDataCnt+SendOffsets;
				m_Laser_Socket3->SendText(SendHeader);
				AckNakLaser3 = true;
				Laser3HistoryData(SendHeader);
			}
			else
			{
				RefreshTagLaser3 = false;
				Laser3HistoryData("PosArrayRowCol_Reject _ LaserSendProcess3 SEND & RECV Fail");
			}
		}
		if(nIdentifier == _LASER_Identifier_4_&& RefreshTagLaser4 == true)
		{
			MMIComm->m_mmiToSeq.cmdType = CMD_RD_DRILL_COORD_RR;
			if (MMIComm->Send() &&  MMIComm->Recv())
			{
				String SendDataCnt =  IntToStr(MMIComm->m_mmiToSeq.bufferData.drillCoord.cnt);
				String SendOffsets;
				String SendHeader;

				for(int i=0; i<MMIComm->m_mmiToSeq.bufferData.drillCoord.cnt; i++)
				{
                    SendOffsets+= String(",") + IntToStr( MMIComm->m_mmiToSeq.bufferData.drillCoord.unit[i].arrange.Row);
                    SendOffsets+= String(",") + IntToStr( MMIComm->m_mmiToSeq.bufferData.drillCoord.unit[i].arrange.Col);
					SendOffsets+= String(",") + FloatToStrF(MMIComm->m_mmiToSeq.bufferData.drillCoord.unit[i].x,ffFixed,10,5 );
					SendOffsets+= String(",") + FloatToStrF(MMIComm->m_mmiToSeq.bufferData.drillCoord.unit[i].y,ffFixed,10,5 );
					SendOffsets+= String(",") + FloatToStrF(MMIComm->m_mmiToSeq.bufferData.drillCoord.theta,ffFixed,10,5 );
					SendOffsets+= String(",") + IntToStr( MMIComm->m_mmiToSeq.bufferData.drillCoord.unit[i].Reject);   //150318  PMS FUNCTION ADDED

				}
				SendOffsets+= ";";
				SendHeader = "posarrayrowcolreject,0,"+SendDataCnt+SendOffsets;
				m_Laser_Socket4->SendText(SendHeader);
				AckNakLaser4 = true;
				Laser4HistoryData(SendHeader);
			}
			else
			{
				RefreshTagLaser4 = false;
				Laser4HistoryData("PosArrayRowCol_Reject _ LaserSendProcess4 SEND & RECV Fail");
			}
		}
	}

	catch (Exception &e)
	{
		Laser1HistoryData("PosArrayRowCol_Reject _ LaserSendProcess" + e.Message );
	}

}
//---------------------------------------------------------------------------
void __fastcall TFrmLaserSetUp::PosArrayLaserSendProcess(int nIdentifier)
{
 /*	try
	{
		if(nIdentifier == _LASER_Identifier_1_ && RefreshTagLaser1 == true)
		{
			MMIComm->m_mmiToSeq.cmdType = CMD_RD_DRILL_COORD_FL;
			if (MMIComm->Send() &&  MMIComm->Recv())
			{
				String SendDataCnt =  IntToStr(MMIComm->m_mmiToSeq.bufferData.drillCoord.cnt);
				String SendOffsets;
				String SendHeader;

				for(int i=0; i<MMIComm->m_mmiToSeq.bufferData.drillCoord.cnt; i++)
				{
					SendOffsets+= String(",") + FloatToStrF( MMIComm->m_mmiToSeq.bufferData.drillCoord.unit[i].x ,ffFixed,10,5);
					SendOffsets+= String(",") + FloatToStrF( MMIComm->m_mmiToSeq.bufferData.drillCoord.unit[i].y ,ffFixed,10,5);
					SendOffsets+= String(",") + FloatToStrF( MMIComm->m_mmiToSeq.bufferData.drillCoord.theta,ffFixed,10,5);
					SendOffsets+= String(",") + IntToStr( MMIComm->m_mmiToSeq.bufferData.drillCoord.unit[i].nLayer);   //150318  PMS FUNCTION ADDED
				}

				SendOffsets+= ";";
				//SendHeader = "posarrays,0,"+SendDataCnt+SendOffsets;
				SendHeader = "posarraylayer,0,"+SendDataCnt+SendOffsets;  //150318  PMS FUNCTION ADDED
				TcpClientLaser1->Socket->SendText(SendHeader);
				AckNakLaser1 = true;
				Laser1HistoryData(SendHeader);
			}
			else
			{
				RefreshTagLaser1 = false;
				Laser1HistoryData("PosArrayLayer _ LaserSendProcess1 SEND & RECV Fail");
			}
		}
		if(nIdentifier == _LASER_Identifier_2_&& RefreshTagLaser2 == true)
		{
			MMIComm->m_mmiToSeq.cmdType = CMD_RD_DRILL_COORD_FR;
			if (MMIComm->Send() &&  MMIComm->Recv())
			{
				String SendDataCnt =  IntToStr(MMIComm->m_mmiToSeq.bufferData.drillCoord.cnt);
				String SendOffsets;
				String SendHeader;
				for(int i=0; i<MMIComm->m_mmiToSeq.bufferData.drillCoord.cnt; i++)
				{
					SendOffsets+= String(",") + FloatToStrF(MMIComm->m_mmiToSeq.bufferData.drillCoord.unit[i].x,ffFixed,10,5 );
					SendOffsets+= String(",") + FloatToStrF(MMIComm->m_mmiToSeq.bufferData.drillCoord.unit[i].y,ffFixed,10,5 );
					SendOffsets+= String(",") + FloatToStrF(MMIComm->m_mmiToSeq.bufferData.drillCoord.theta,ffFixed,10,5 );
					SendOffsets+= String(",") + IntToStr( MMIComm->m_mmiToSeq.bufferData.drillCoord.unit[i].nLayer);   //150318  PMS FUNCTION ADDED

				}
				SendOffsets+= ";";
				SendHeader = "posarraylayer,0,"+SendDataCnt+SendOffsets;
				TcpClientLaser2->Socket->SendText(SendHeader);
				AckNakLaser2 = true;
				Laser2HistoryData(SendHeader);
			}
			else
			{
				RefreshTagLaser2 = false;
				Laser2HistoryData("PosArrayLayer _ LaserSendProcess2 SEND & RECV Fail");
			}
		}
		if(nIdentifier == _LASER_Identifier_3_&& RefreshTagLaser3 == true)
		{
			MMIComm->m_mmiToSeq.cmdType = CMD_RD_DRILL_COORD_RL;
			if (MMIComm->Send() &&  MMIComm->Recv())
			{
				String SendDataCnt =  IntToStr(MMIComm->m_mmiToSeq.bufferData.drillCoord.cnt);
				String SendOffsets;
				String SendHeader;
				for(int i=0; i<MMIComm->m_mmiToSeq.bufferData.drillCoord.cnt; i++)
				{
					SendOffsets+= String(",") + FloatToStrF(MMIComm->m_mmiToSeq.bufferData.drillCoord.unit[i].x,ffFixed,10,5 );
					SendOffsets+= String(",") + FloatToStrF(MMIComm->m_mmiToSeq.bufferData.drillCoord.unit[i].y,ffFixed,10,5 );
					SendOffsets+= String(",") + FloatToStrF(MMIComm->m_mmiToSeq.bufferData.drillCoord.theta,ffFixed,10,5 );
					SendOffsets+= String(",") + IntToStr( MMIComm->m_mmiToSeq.bufferData.drillCoord.unit[i].nLayer);   //150318  PMS FUNCTION ADDED

				}

				SendOffsets+= ";";
				SendHeader = "posarraylayer,0,"+SendDataCnt+SendOffsets;
				TcpClientLaser3->Socket->SendText(SendHeader);
				AckNakLaser3 = true;
				Laser3HistoryData(SendHeader);
			}
			else
			{
				RefreshTagLaser3 = false;
				Laser3HistoryData("PosArrayLayer _ LaserSendProcess3 SEND & RECV Fail");
			}
		}
		if(nIdentifier == _LASER_Identifier_4_&& RefreshTagLaser4 == true)
		{
			MMIComm->m_mmiToSeq.cmdType = CMD_RD_DRILL_COORD_RR;
			if (MMIComm->Send() &&  MMIComm->Recv())
			{
				String SendDataCnt =  IntToStr(MMIComm->m_mmiToSeq.bufferData.drillCoord.cnt);
				String SendOffsets;
				String SendHeader;
				for(int i=0; i<MMIComm->m_mmiToSeq.bufferData.drillCoord.cnt; i++)
				{
					SendOffsets+= String(",") + FloatToStrF(MMIComm->m_mmiToSeq.bufferData.drillCoord.unit[i].x,ffFixed,10,5 );
					SendOffsets+= String(",") + FloatToStrF(MMIComm->m_mmiToSeq.bufferData.drillCoord.unit[i].y,ffFixed,10,5 );
					SendOffsets+= String(",") + FloatToStrF(MMIComm->m_mmiToSeq.bufferData.drillCoord.theta,ffFixed,10,5 );
					SendOffsets+= String(",") + IntToStr( MMIComm->m_mmiToSeq.bufferData.drillCoord.unit[i].nLayer);   //150318  PMS FUNCTION ADDED

				}
				SendOffsets+= ";";
				SendHeader = "posarraylayer,0,"+SendDataCnt+SendOffsets;
				TcpClientLaser4->Socket->SendText(SendHeader);
				AckNakLaser4 = true;
				Laser4HistoryData(SendHeader);
			}
			else
			{
				RefreshTagLaser4 = false;
				Laser4HistoryData("PosArrayLayer _ LaserSendProcess4 SEND & RECV Fail");
			}
		}
	}

	catch (Exception &e)
	{
		Laser1HistoryData("PosArrayLayer _ LaserSendProcess" + e.Message );
	}
*/
}
//---------------------------------------------------------------------------
void __fastcall TFrmLaserSetUp::AutoCalDataReadFromSEQ(int Separator)
{
	if(Separator == 1)
	{
		CorrectionCAL1 = true;
		MMIComm->m_mmiToSeq.cmdType = CMD_RD_LSR_CAL_DATA_FL;
	}
	else if(Separator == 2)
	{
		CorrectionCAL2 = true;
		MMIComm->m_mmiToSeq.cmdType = CMD_RD_LSR_CAL_DATA_FR;
	}
	else if(Separator == 3)
	{
		CorrectionCAL3 = true;
		MMIComm->m_mmiToSeq.cmdType = CMD_RD_LSR_CAL_DATA_RL;
	}
	else if(Separator == 4)
	{
		CorrectionCAL4 = true;
		MMIComm->m_mmiToSeq.cmdType = CMD_RD_LSR_CAL_DATA_RR;
	}

	String    SendOffsets;
	String    SendHeader;
	String    SendLoadDatas;
	String    StrIndexValue;
	int nRowIndex = 1;

	if ( MMIComm->Send() &&  MMIComm->Recv())
	{
		for(int i = 0; i < FrmManualDrilling->nCalSize; i++)
		{
			for(int j = 0; j < FrmManualDrilling->nCalSize; j++)
			{
				StrIndexValue = NULL;
				try
				{
					//SendOffsets+= String(",") + FloatToStrF(MMIComm->m_mmiToSeq.bufferData.autoCal.data[i][j].xPos ,ffFixed,10,5);
					StrIndexValue =  FloatToStrF(MMIComm->m_mmiToSeq.bufferData.autoCal.data[i][j].x ,ffFixed,10,5);
				}
				catch (Exception &e)
				{
					//SendOffsets+= String(",0.0");

					Laser1HistoryData("AutoCalDataReadFromSEQ Xpos" + e.Message );
					StrIndexValue = "0.0";
				}

				SendOffsets+= String(",")+StrIndexValue;

				StrIndexValue = NULL;
				try
				{
					//SendOffsets+= String(",") + FloatToStrF(MMIComm->m_mmiToSeq.bufferData.autoCal.data[i][j].yPos ,ffFixed,10,5);
					StrIndexValue =  FloatToStrF(MMIComm->m_mmiToSeq.bufferData.autoCal.data[i][j].y ,ffFixed,10,5);
				}
				catch (Exception &e)
				{
					//SendOffsets+= String(",0.0");

					Laser1HistoryData("AutoCalDataReadFromSEQ Ypos" + e.Message );
					StrIndexValue = "0.0";
				}

				SendOffsets+= String(",")+StrIndexValue;

				nRowIndex++;
			}
		}
		SendOffsets+= ";";
		//FrmAutoCal->AutoCalMemo->Text = DateTimeT      oStr(Now()) + ": " + SendOffsets;

		SendLoadDatas = IntToStr(FrmManualDrilling->nCalSize)+","+IntToStr(FrmManualDrilling->nCalSize)+","+FloatToStr(FrmManualDrilling->dbInterSpace);
		SendHeader = "CORRECTION,"+ SendLoadDatas+ SendOffsets;
		if(Separator == 1)
		{
			m_Laser_Socket1->SendText(SendHeader);
			Laser1HistoryData(SendHeader);
		}
		else if(Separator == 2)
		{
			m_Laser_Socket2->SendText(SendHeader);
			Laser2HistoryData(SendHeader);
		}
		else if(Separator == 3)
		{
			m_Laser_Socket3->SendText(SendHeader);
			Laser3HistoryData(SendHeader);
		}
		else if(Separator == 4)
		{
			m_Laser_Socket4->SendText(SendHeader);
			Laser4HistoryData(SendHeader);
		}
	}
}
//----------------------------------------------------------------------------
void __fastcall TFrmLaserSetUp::LaserTransferComplete(int nIdentifier)
{
	MMIComm->m_mmiToSeq.cmdType = CMD_RD_DM;

	if (MMIComm->Send() &&  MMIComm->Recv())
	{
		MMIComm->m_mmiToSeq.bufferData.dm.nStartNo = nIdentifier;
		MMIComm->m_mmiToSeq.bufferData.dm.nEndNo  =nIdentifier;
		MMIComm->m_mmiToSeq.bufferData.dm.data[nIdentifier] = 0.0;

		MMIComm->m_mmiToSeq.cmdType = CMD_WR_DM;

		if(MMIComm->Send() && MMIComm->Recv())
		{
			if(nIdentifier == _LASER_Identifier_1_)
			{
				Laser1HistoryData("LaserTransferComplete DM : 0");
			}
			else if(nIdentifier == _LASER_Identifier_2_)
			{
				Laser2HistoryData("LaserTransferComplete DM : 0");
			}
			else if(nIdentifier == _LASER_Identifier_3_)
			{
				Laser3HistoryData("LaserTransferComplete DM : 0");
			}
			else if(nIdentifier == _LASER_Identifier_4_)
			{
				Laser4HistoryData("LaserTransferComplete DM : 0");
			}
		}
		else
		{
			if(nIdentifier == _LASER_Identifier_1_)
			{
				Laser1HistoryData("Communication Failure DM : 0");
			}
			else if(nIdentifier == _LASER_Identifier_2_)
			{
				Laser2HistoryData("Communication Failure DM : 0");
			}
			else if(nIdentifier == _LASER_Identifier_3_)
			{
				Laser3HistoryData("Communication Failure DM : 0");
			}
			else if(nIdentifier == _LASER_Identifier_4_)
			{
				Laser4HistoryData("Communication Failure DM : 0");
			}
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::LaserJobChangeCompleteToSEQ(int separator)
{
	MMIComm->m_mmiToSeq.cmdType = CMD_RD_DM;

	if (MMIComm->Send() &&  MMIComm->Recv())
	{
		if(separator == 1)
		{
			MMIComm->m_mmiToSeq.bufferData.dm.nStartNo = _LASER_JobChange_1_;
			MMIComm->m_mmiToSeq.bufferData.dm.nEndNo  =_LASER_JobChange_1_;
			MMIComm->m_mmiToSeq.bufferData.dm.data[_LASER_JobChange_1_] = 0.0;
		}
		else if(separator == 2)
		{
			MMIComm->m_mmiToSeq.bufferData.dm.nStartNo = _LASER_JobChange_2_;
			MMIComm->m_mmiToSeq.bufferData.dm.nEndNo  =_LASER_JobChange_2_;
			MMIComm->m_mmiToSeq.bufferData.dm.data[_LASER_JobChange_2_] = 0.0;
		}
		else if(separator == 3)
		{
			MMIComm->m_mmiToSeq.bufferData.dm.nStartNo = _LASER_JobChange_3_;
			MMIComm->m_mmiToSeq.bufferData.dm.nEndNo  =_LASER_JobChange_3_;
			MMIComm->m_mmiToSeq.bufferData.dm.data[_LASER_JobChange_3_] = 0.0;
		}
		else if(separator == 4)
		{
			MMIComm->m_mmiToSeq.bufferData.dm.nStartNo = _LASER_JobChange_4_;
			MMIComm->m_mmiToSeq.bufferData.dm.nEndNo  =_LASER_JobChange_4_;
			MMIComm->m_mmiToSeq.bufferData.dm.data[_LASER_JobChange_4_] = 0.0;
		}


		MMIComm->m_mmiToSeq.cmdType = CMD_WR_DM;

		if(MMIComm->Send() && MMIComm->Recv())
		{
			if(separator == 1)
			{
				Laser1HistoryData("LaserJobChangeCompleteToSEQ DM : 0");
			}
			else if(separator == 2)
			{
				Laser2HistoryData("LaserJobChangeCompleteToSEQ DM : 0");
			}

			else if(separator == 3)
			{
				Laser3HistoryData("LaserJobChangeCompleteToSEQ DM : 0");
			}

			else if(separator == 4)
			{
				Laser4HistoryData("LaserJobChangeCompleteToSEQ DM : 0");
			}
		}
		else
		{
			if(separator == 1)
			{
				Laser1HistoryData("LaserJobChangeCompleteToSEQ Failure DM : 0");
			}
			else if(separator == 2)
			{
				Laser2HistoryData("LaserJobChangeCompleteToSEQ Failure DM : 0");
			}
			else if(separator == 3)
			{
				Laser3HistoryData("LaserJobChangeCompleteToSEQ Failure DM : 0");
			}
			else if(separator == 4)
			{
				Laser4HistoryData("LaserJobChangeCompleteToSEQ Failure DM : 0");
			}
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmLaserSetUp::LaserJobChangeFailToSEQ(int separator)
{
	MMIComm->m_mmiToSeq.cmdType = CMD_RD_DM;

	if (MMIComm->Send() &&  MMIComm->Recv())
	{
		if(separator == 1)
		{
			MMIComm->m_mmiToSeq.bufferData.dm.nStartNo = _LASER_JobChange_1_;
			MMIComm->m_mmiToSeq.bufferData.dm.nEndNo  =_LASER_JobChange_1_;
			MMIComm->m_mmiToSeq.bufferData.dm.data[_LASER_JobChange_1_] = 10000.0;
		}
		else if(separator == 2)
		{
			MMIComm->m_mmiToSeq.bufferData.dm.nStartNo = _LASER_JobChange_2_;
			MMIComm->m_mmiToSeq.bufferData.dm.nEndNo  =_LASER_JobChange_2_;
			MMIComm->m_mmiToSeq.bufferData.dm.data[_LASER_JobChange_2_] = 10000.0;
		}
		else if(separator == 3)
		{
			MMIComm->m_mmiToSeq.bufferData.dm.nStartNo = _LASER_JobChange_3_;
			MMIComm->m_mmiToSeq.bufferData.dm.nEndNo  =_LASER_JobChange_3_;
			MMIComm->m_mmiToSeq.bufferData.dm.data[_LASER_JobChange_3_] = 10000.0;
		}
		else if(separator == 4)
		{
			MMIComm->m_mmiToSeq.bufferData.dm.nStartNo = _LASER_JobChange_4_;
			MMIComm->m_mmiToSeq.bufferData.dm.nEndNo  =_LASER_JobChange_4_;
			MMIComm->m_mmiToSeq.bufferData.dm.data[_LASER_JobChange_4_] = 10000.0;
		}


		MMIComm->m_mmiToSeq.cmdType = CMD_WR_DM;

		if(MMIComm->Send() && MMIComm->Recv())
		{
			if(separator == 1)
			{
				Laser1HistoryData("LaserJobChangeFailToSEQ DM : 0");
			}
			else if(separator == 2)
			{
				Laser2HistoryData("LaserJobChangeFailToSEQ DM : 0");
			}

			else if(separator == 3)
			{
				Laser3HistoryData("LaserJobChangeFailToSEQ DM : 0");
			}

			else if(separator == 4)
			{
				Laser4HistoryData("LaserJobChangeFailToSEQ DM : 0");
			}
		}
		else
		{
			if(separator == 1)
			{
				Laser1HistoryData("LaserJobChangeFailToSEQ Failure DM : 0");
			}
			else if(separator == 2)
			{
				Laser2HistoryData("LaserJobChangeFailToSEQ Failure DM : 0");
			}
			else if(separator == 3)
			{
				Laser3HistoryData("LaserJobChangeFailToSEQ Failure DM : 0");
			}
			else if(separator == 4)
			{
				Laser4HistoryData("LaserJobChangeFailToSEQ Failure DM : 0");
			}
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmLaserSetUp::LaserMarkingSendFeedBack(bool bSuccess , int nseparator)
{
	if(bSuccess == true)
	{
		if(nseparator == 1)
		{
			WriteCommunicationDM(10 , _DM_MKSPEC1_);
			Laser1HistoryData("LaserMarkingSpec_OK_ToSEQ DM : 10");
		}
		else if(nseparator == 2)
		{
			WriteCommunicationDM(10 , _DM_MKSPEC2_);
			Laser2HistoryData("LaserMarkingSpec_OK_ToSEQ DM : 10");
		}

		else if(nseparator == 3)
		{
			WriteCommunicationDM(10 , _DM_MKSPEC3_);
			Laser3HistoryData("LaserMarkingSpec_OK_ToSEQ DM : 10");
		}

		else if(nseparator == 4)
		{
			WriteCommunicationDM(10 , _DM_MKSPEC4_);
			Laser4HistoryData("LaserMarkingSpec_OK_ToSEQ DM : 10");
		}
	}
	else
	{
		if(nseparator == 1)
		{
			WriteCommunicationDM(11 , _DM_MKSPEC1_);
			Laser1HistoryData("LaserMarkingSpec_FAIL_ToSEQ DM : 11");
		}
		else if(nseparator == 2)
		{
			WriteCommunicationDM(11 , _DM_MKSPEC2_);
			Laser2HistoryData("LaserMarkingSpec_FAIL_ToSEQ DM : 11");
		}

		else if(nseparator == 3)
		{
			WriteCommunicationDM(11 , _DM_MKSPEC3_);
			Laser3HistoryData("LaserMarkingSpec_FAIL_ToSEQ DM : 11");
		}

		else if(nseparator == 4)
		{
			WriteCommunicationDM(11 , _DM_MKSPEC4_);
			Laser4HistoryData("LaserMarkingSpec_FAIL_ToSEQ DM : 11");
		}
	}
}
//---------------------------------------------------------------------------

int __fastcall TFrmLaserSetUp::LaserDMGet_Val(int nIdentifier)
{
	int nRetVal = 0;
	MMIComm->m_mmiToSeq.cmdType = CMD_RD_DM;

	if ( MMIComm->Send() &&  MMIComm->Recv())
	{
		nRetVal = MMIComm->m_mmiToSeq.bufferData.dm.data[nIdentifier];
		return  nRetVal;
	}
	else
	{
		return  0;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmLaserSetUp::LaserTransferTimerTimer(TObject *Sender)
{
	if(ChkLaser1Heartbeat->Checked == true)
	{
		if(LaserDMGet_Val(_LASER_Identifier_1_) ==1 && RefreshTagLaser1 == false && g_bLaserJobChk == false)
		{
			RefreshTagLaser1 = true;
			//PosArrayLaserSendProcess(_LASER_Identifier_1_);
            PosArrayRowCol_RJCTLaserSendProcess(_LASER_Identifier_1_);

		}

		if(LaserDMGet_Val(_LASER_JobChange_1_) == 3 && SystemTeach1 == false)
		{
			//LaserJobChangeProcess(1,"1Point.job");
		}

		if(LaserDMGet_Val(_LASER_JobChange_1_) == 2 && AutoCAL1 == false)
		{
			Laser1AutoCalPorcess(FrmManualDrilling->StrAutoCal1);
		}

		if(LaserDMGet_Val(_LASER_CORRECTION_1_) == 1 && CorrectionCAL1 == false)
		{
			AutoCalDataReadFromSEQ(1);
		}
	}

	if(ChkLaser2Heartbeat->Checked == true)
	{
		if(LaserDMGet_Val(_LASER_Identifier_2_) ==1 && RefreshTagLaser2 == false && g_bLaserJobChk == false)
		{
			RefreshTagLaser2 = true;
			//PosArrayLaserSendProcess(_LASER_Identifier_2_);
            PosArrayRowCol_RJCTLaserSendProcess(_LASER_Identifier_2_);
		}

		if(LaserDMGet_Val(_LASER_JobChange_2_) == 3 && SystemTeach2 == false)
		{
			//LaserJobChangeProcess(2,"1Point.job");
		}

		if(LaserDMGet_Val(_LASER_JobChange_2_) == 2 && AutoCAL2 == false)
		{
			Laser2AutoCalPorcess(FrmManualDrilling->StrAutoCal2);
		}

		if(LaserDMGet_Val(_LASER_CORRECTION_2_) == 1 && CorrectionCAL2 == false)
		{
			AutoCalDataReadFromSEQ(2);
		}
	}

	if(ChkLaser3Heartbeat->Checked == true)
	{
		if(LaserDMGet_Val(_LASER_Identifier_3_) ==1 && RefreshTagLaser3 == false && g_bLaserJobChk == false)
		{
			RefreshTagLaser3 = true;
			//PosArrayLaserSendProcess(_LASER_Identifier_3_);
            PosArrayRowCol_RJCTLaserSendProcess(_LASER_Identifier_3_);
		}

		if(LaserDMGet_Val(_LASER_JobChange_3_) == 3 && SystemTeach3 == false)
		{
			//LaserJobChangeProcess(3,"1Point.job");
		}

		if(LaserDMGet_Val(_LASER_JobChange_3_) == 2 && AutoCAL3 == false)
		{
			Laser3AutoCalPorcess(FrmManualDrilling->StrAutoCal3);
		}

		if(LaserDMGet_Val(_LASER_CORRECTION_3_) == 1 && CorrectionCAL3 == false)
		{
			AutoCalDataReadFromSEQ(3);
		}
	}

	if(ChkLaser4Heartbeat->Checked == true)
	{
		if(LaserDMGet_Val(_LASER_Identifier_4_) ==1 && RefreshTagLaser4 == false && g_bLaserJobChk == false)
		{
			RefreshTagLaser4 = true;
			//PosArrayLaserSendProcess(_LASER_Identifier_4_);
            PosArrayRowCol_RJCTLaserSendProcess(_LASER_Identifier_4_);
		}

		if(LaserDMGet_Val(_LASER_JobChange_4_) == 3 && SystemTeach4 == false)
		{
			//LaserJobChangeProcess(4,"1Point.job");
		}

		if(LaserDMGet_Val(_LASER_JobChange_4_) == 2 && AutoCAL4 == false)
		{
			Laser4AutoCalPorcess(FrmManualDrilling->StrAutoCal4);
		}

		if(LaserDMGet_Val(_LASER_CORRECTION_4_) == 1 && CorrectionCAL4 == false)
		{
			AutoCalDataReadFromSEQ(4);
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::LaserClosingProcess()
{
	FTPTimer->Enabled = false;
	LaserTransferTimer->Enabled = false;
	LaserMarkingTrigger->Enabled = false;
	LaserRCPResponseTimer->Enabled = false;
	LaserHeartBeatTimer->Enabled1 = false;
	LaserHeartBeatTimer->Enabled2 = false;
	LaserHeartBeatTimer->Enabled3 = false;
	LaserHeartBeatTimer->Enabled4 = false;
	LaserHeartBeatTimer->Enabled5 = false;
	LaserHeartBeatTimer->Enabled6 = false;
	LaserHeartBeatTimer->Enabled7 = false;
	LaserHeartBeatTimer->Enabled8 = false;
	this->stop();

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
	m_SecsLaser_Socket = NULL;
    m_Laser_Socket1 = NULL;
    m_Laser_Socket2 = NULL;
    m_Laser_Socket3 = NULL;
    m_Laser_Socket4 = NULL;

}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::SaveLaserLogProcess()
{
	String FolderName, FileName, FullPath;
	TDateTime dt = Now();

	FolderName = dt.FormatString("yyyy-mm-dd");
	FileName = dt.FormatString("yyyy-mm-dd hh-nn-ss");

	FullPath  =  "C:\\KOSES\\History\\Laser1History\\"+ FolderName +"\\";
	ForceDirectories(FullPath);
	Laser1Memo->Lines->SaveToFile(FullPath + FileName+".txt");

	FullPath  =  "C:\\KOSES\\History\\Laser2History\\"+ FolderName +"\\";
	ForceDirectories(FullPath);
	Laser2Memo->Lines->SaveToFile(FullPath + FileName+".txt");

	FullPath  =  "C:\\KOSES\\History\\Laser3History\\"+ FolderName +"\\";
	ForceDirectories(FullPath);
	Laser3Memo->Lines->SaveToFile(FullPath + FileName+".txt");

	FullPath  =  "C:\\KOSES\\History\\Laser4History\\"+ FolderName +"\\";
	ForceDirectories(FullPath);
	Laser4Memo->Lines->SaveToFile(FullPath + FileName+".txt");

	FullPath  =  "C:\\KOSES\\History\\LASERSECSHistory\\"+ FolderName +"\\";
	ForceDirectories(FullPath);
	SECSLaserMemo->Lines->SaveToFile(FullPath + FileName+".txt");
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::BtnLaser1SaveLogClick(TObject *Sender)
{
	TDateTime dt = Now();
	String FolderName = dt.FormatString("yyyy-mm-dd");
	String FileName = dt.FormatString("yyyy-mm-dd hh-nn-ss");
	String FullPath  =  "C:\\KOSES\\History\\Laser1History\\"+ FolderName +"\\";
	ForceDirectories(FullPath);

	Laser1Memo->Lines->SaveToFile(FullPath + FileName+".txt");

	Laser1Memo->Clear();

	Laser1HistoryData("LOG 저장"+ FullPath + FileName+".txt");
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::BtnLaser2SaveLogClick(TObject *Sender)
{
	TDateTime dt = Now();
	String FolderName = dt.FormatString("yyyy-mm-dd");
	String FileName = dt.FormatString("yyyy-mm-dd hh-nn-ss");
	String FullPath  =  "C:\\KOSES\\History\\Laser2History\\"+ FolderName +"\\";
	ForceDirectories(FullPath);

	Laser2Memo->Lines->SaveToFile(FullPath + FileName+".txt");

	Laser2Memo->Clear();

	Laser2HistoryData("LOG 저장"+ FullPath + FileName+".txt");
}
//---------------------------------------------------------------------------
void __fastcall TFrmLaserSetUp::BtnLaser3SaveLogClick(TObject *Sender)
{
	TDateTime dt = Now();
	String FolderName = dt.FormatString("yyyy-mm-dd");
	String FileName = dt.FormatString("yyyy-mm-dd hh-nn-ss");
	String FullPath  =  "C:\\KOSES\\History\\Laser3History\\"+ FolderName +"\\";
	ForceDirectories(FullPath);

	Laser3Memo->Lines->SaveToFile(FullPath + FileName+".txt");

	Laser3Memo->Clear();

	Laser3HistoryData("LOG 저장"+ FullPath + FileName+".txt");
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::BtnLaser4SaveLogClick(TObject *Sender)
{
	TDateTime dt = Now();
	String FolderName = dt.FormatString("yyyy-mm-dd");
	String FileName = dt.FormatString("yyyy-mm-dd hh-nn-ss");
	String FullPath  =  "C:\\KOSES\\History\\Laser4History\\"+ FolderName +"\\";
	ForceDirectories(FullPath);

	Laser4Memo->Lines->SaveToFile(FullPath + FileName+".txt");

	Laser4Memo->Clear();

	Laser4HistoryData("LOG 저장"+ FullPath + FileName+".txt");
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::BtnSECSLaserSaveLogClick(TObject *Sender)
{
	TDateTime dt = Now();
	String FolderName = dt.FormatString("yyyy-mm-dd");
	String FileName = dt.FormatString("yyyy-mm-dd hh-nn-ss");
	String FullPath  =  "C:\\KOSES\\History\\LASERSECSHistory\\"+ FolderName +"\\";
	ForceDirectories(FullPath);

	SECSLaserMemo->Lines->SaveToFile(FullPath + FileName+".txt");

	SECSLaserMemo->Clear();

	SECSLaserHistoryData("LOG 저장"+ FullPath + FileName+".txt",1);
}
//---------------------------------------------------------------------------
void __fastcall TFrmLaserSetUp::SECSLaserConnection(bool bChkEnable)
{
	if(bChkEnable == false)
	{
		LaserSECSClient->Active = false;
		FrmMain->LEDLaserSECSComm->Active = false;
        FrmMain->LEDLaserSECSComm->CenterLabelText = "LASER RCP OFF";
    }
    else
    {
		LaserSECSClient->Active = true;
        FrmMain->LEDLaserSECSComm->Active = true;
        FrmMain->LEDLaserSECSComm->CenterLabelText = "LASER RCP ON";

    }
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::LaserSECSClientConnect(TObject *Sender,
	  TCustomWinSocket *Socket)
{
	m_SecsLaser_Socket =  Socket;
	SECSLaserHistoryData("LASER RECIPE 시스템과 연결되었습니다!",1);

	FrmMain->LEDLaserSECSComm->Active = true;
    FrmMain->LEDLaserSECSComm->CenterLabelText = "LASER RCP ON";

	FTPTimer->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::LaserSECSClientDisconnect(TObject *Sender,
	  TCustomWinSocket *Socket)
{
	m_SecsLaser_Socket = NULL;
	SECSLaserHistoryData("LASER RECIPE 시스템과 연결이 끊어졌습니다!",1);

    FrmMain->LEDLaserSECSComm->Active = false;
    FrmMain->LEDLaserSECSComm->CenterLabelText = "LASER RCP OFF";

	FTPTimer->Enabled = true;
}
//---------------------------------------------------------------------------


void __fastcall TFrmLaserSetUp::LaserSECSClientError(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
    try
    {
		m_SecsLaser_Socket = NULL;
		LaserSECSClient->Socket->Close();
        LaserSECSClient->Active = false;
		SECSLaserHistoryData("exception :" + IntToStr(ErrorCode),1);
		ErrorCode = 0;

		FTPTimer->Enabled = true;
    }

	catch (Exception &exception)
	{
		SECSLaserHistoryData("exception :" + IntToStr(ErrorCode),1);
	}
}
//---------------------------------------------------------------------------

bool __fastcall	TFrmLaserSetUp::RecipeUpload(String strPPID)
{
	try
	{
		AnsiString StrRcpPath = ExtractFilePath(Application->ExeName)+ "SGConfig\\LDP\\XWork\\Recipe\\" + strPPID;
		if ( false == FileExists(StrRcpPath))
		{
			SECSLaserHistoryData("recipe file not found : " + StrRcpPath, 2);
			return false;
		}

		INT nRecipeFileSize = FileSizeByName( StrRcpPath);
		if (true == FrmSecsSetUp->PPLoadInquireS7F1Process(strPPID, nRecipeFileSize))
		{
			if (true == FrmSecsSetUp->PPSendS7F3Process(strPPID , nRecipeFileSize))
			{
				return true;
			}
		}
		return false;
	}

	catch (Exception &exception)
	{
		SECSLaserHistoryData("RecipeUpload exception :",1);
		return false;
	}
}
//---------------------------------------------------------------------------


bool __fastcall TFrmLaserSetUp::parse(String data)
{
	bool ret = false;
	if (NULL == m_SecsLaser_Socket)
	{
		 return false;
	}
	if(strcmp(data.c_str(),"AK") == 0)
	{
		if(FrmMain->bRcpDownloadWaitChk == true)
		{
			WriteCommunicationDM(_RFID_RESPONSE_SUCCESS_, _RFID_RCP_DOWN_DM_); //RFID
			FrmMain->bRcpDownloadWaitChk = false;
			FrmLotRcvShow->PopUpLotCodeProcess(1 , StrRcvLaserPartCode);
			SECSLaserHistoryData("RecipeDownload SUCCESS",3);
			ret = true;
		}
	}
	else if(strcmp(data.c_str(),"NK") == 0)
	{
		if(FrmMain->bRcpDownloadWaitChk == true)
		{
			WriteCommunicationDM(_RFID_RESPONSE_FAIL_, _RFID_RCP_DOWN_DM_);//RFID
			FrmMain->bRcpDownloadWaitChk = false;
			SECSLaserHistoryData("RecipeDownload FAIL",3);
			ret = false;
		}
	}
	else
	{
		INT nPos = data.Pos(",");
		String strparseBuffer = data.SubString(1, nPos-1);

		if ( 0 == strparseBuffer.AnsiCompareIC("RECIPE") )
		{
			SECSLaserHistoryData("secsgem try to upload the recipe",1);
			String data2 = data.SubString(
						String("RECIPE").Length() + 2,
						data.Length() - String("RECIPE").Length()-1);

			StrRcvLaserPartCode = data2;
			LaserRCPResponseTimer->Enabled = true;

		}
		else if ( 0 == strparseBuffer.AnsiCompareIC("SVID") )
		{
			String data2 = data.SubString(
						String("SVID").Length() + 2,
						data.Length() - String("SVID").Length()-1);

			ret = this->svid(data2);

			if (ret)
			{
				m_SecsLaser_Socket->SendText("AK;");
				SECSLaserHistoryData("SVID _  AK",1);
			}
			else
			{
				m_SecsLaser_Socket->SendText("NK;");
				SECSLaserHistoryData("SVID _  NK",1);
			}
		}
		else if ( 0 == strparseBuffer.AnsiCompareIC("CEID") )
		{
			String data2 = data.SubString(
						String("CEID").Length() + 2,
						data.Length() - String("CEID").Length()-1);

			int nCeid = StrToInt(data2.Trim());
			int nResult = -1;
			if(nCeid >= 1250 && nCeid <= 1253)		// CEID 1250~1253 번 : Laser 1~4 Power mapping 이벤트
				nResult = FrmSecsSetUp->EXGem->GEMSetEvent(nCeid);

			if(nResult == 0)
				ret = true;

			if (ret)
			{
				m_SecsLaser_Socket->SendText("AK;");
				SECSLaserHistoryData("CEID _  AK",1);
			}
			else
			{
				m_SecsLaser_Socket->SendText("NK;");
				SECSLaserHistoryData("CEID _  NK",1);
			}
		}
		else if( 0 == strparseBuffer.AnsiCompareIC("TKINPOWER"))
		{
		/*	141106 현재 사용하지 않아 주석처리!
			// 데이터 형식 -> TKINPOWER,1,0 0.3 10.0 0 0.27 10.0 ......;
			// 첫번째 세미콜론 전까지는 TK INOUT 구분자
			// 두번째 세미콜론 전까지는 Laser index 구분자
			// 이 후 데이터는 Layer | Diameter | Detected Power 차례대로 나열

			String strLaserNo = data.SubString(String("TKINPOWER").Length() + 2, 1);
			String data2 = data.SubString(
						String("TKINPOWER").Length() + 4,
						data.Length() - String("TKINPOWER").Length()-1);

			ret = RecieveDetectPower(1, strLaserNo, data2);
			if(ret)
			{
				g_nDataCnt++;
				if(g_nDataCnt >= 4)
				{
					g_nDataCnt = 0;
					WriteCommunicationDM(0, _DM_LASER_POWER_CHK_);
					FrmMain->g_bWaitLaserPwrData = false;
				}

				m_SecsLaser_Socket->SendText("AK;");
				SECSLaserHistoryData("DETECT TK IN POWER DATA _  AK",1);
			}
			else
			{
				g_nDataCnt = 0;
				m_SecsLaser_Socket->SendText("NK;");
				SECSLaserHistoryData("DETECT TK IN POWER DATA _  NK",1);
				FrmMain->g_bWaitLaserPwrData = false;
			}
		*/
		}
		else if( 0 == strparseBuffer.AnsiCompareIC("TKOUTPOWER"))
		{
		/*	141106 현재 사용하지 않아 주석처리!
			// 데이터 형식 -> TKOUTPOWER,1,0 0.3 10.0 0 0.27 10.0 ......;
			// 첫번째 세미콜론 전까지는 TK INOUT 구분자
			// 두번째 세미콜론 전까지는 Laser index 구분자
			// 이 후 데이터는 Layer | Diameter | Detected Power 차례대로 나열

			String strLaserNo = data.SubString(String("TKOUTPOWER").Length() + 2, 1);
			String data2 = data.SubString(
						String("TKOUTPOWER").Length() + 4,
						data.Length() - String("TKOUTPOWER").Length()-1);

			ret = RecieveDetectPower(2, strLaserNo, data2);
			if(ret)
			{
				g_nDataCnt++;
				if(g_nDataCnt >= 4)
				{
					g_nDataCnt = 0;
					WriteCommunicationDM(0, _DM_LASER_POWER_CHK_);
					FrmMain->g_bWaitLaserPwrData = false;
				}
				m_SecsLaser_Socket->SendText("AK;");
				SECSLaserHistoryData("DETECT TK OUT POWER DATA _  AK",1);
			}
			else
			{
				g_nDataCnt = 0;
				m_SecsLaser_Socket->SendText("NK;");
				SECSLaserHistoryData("DETECT TK OUT POWER DATA _  NK",1);
				FrmMain->g_bWaitLaserPwrData = false;
			}
		*/
		}
	}
	return ret;
}
//---------------------------------------------------------------------------
bool __fastcall TFrmLaserSetUp::RecieveDetectPower(int nInOutIndex, String strLaserNo, String data)
{
	bool bReturnVal = false;	
/*	141106 현재 사용하지 않아 주석처리!
	bool bReturnVal = true;
	int nLaserNo = StrToInt(strLaserNo);
	int nLotIndex = ReadCommunicationDM(_DM_LASER_POWER_CHK_) % 10;

	if(nLaserNo < 1 || nLaserNo > 4)
		return false;

	if(nInOutIndex == 1)
	{
		TIniFile *TKInIni = new TIniFile(ExtractFilePath(Application->ExeName) + "\\ini\\TKInDetectPower.ini");
		if(FileExists(ExtractFilePath(Application->ExeName) + "\\ini\\TKInDetectPower.ini"))
		{
			TKInIni->WriteString("LOT_" + IntToStr(nLotIndex),"LASER_" + IntToStr(nLaserNo),data);
		}
		delete TKInIni;
	}
	else if(nInOutIndex == 2)
	{
		TIniFile *TKOutIni = new TIniFile(ExtractFilePath(Application->ExeName) + "\\ini\\TKOutDetectPower.ini");
		if(FileExists(ExtractFilePath(Application->ExeName) + "\\ini\\TKOutDetectPower.ini"))
		{
			TKOutIni->WriteString("LOT_" + IntToStr(nLotIndex),"LASER_" + IntToStr(nLaserNo),data);
		}
		delete TKOutIni;
	}
	else
	{
		bReturnVal = false;
	}
*/
	return bReturnVal;
}
//---------------------------------------------------------------------------
bool __fastcall TFrmLaserSetUp::svid(String data)
{
	CHAR *token= NULL;
	CHAR seps[]={",;\r\n"};

	CHAR buf [1024*64];
	strcpy(buf, data.c_str());

	SECSLaserHistoryData(buf, 1);

	token = ::strtok(buf, seps);
	if (NULL == token)
	{
		return FALSE;
	}

	// ex) SVID,총 개수, 첫번째svid, 개수, 값,... , 두번째svid, 개수,값,...;

	INT nCount = atoi(token);
	for (int i=0; i< nCount;++i)
	{
		token = ::strtok(NULL, seps);

		//svid
		INT nSvid = atoi(token);

		//svid 개수

		token = ::strtok(NULL, seps);
		INT nSvidCount = atoi(token);

		WideString wstr[100];
		if (nSvidCount > 512)
			return FALSE;


		for (int j=0; j< nSvidCount; ++j)
		{
			token = ::strtok(NULL, seps);
			wstr[j] = token;
		}

		SVIDBuffering(nSvid ,nSvidCount, wstr);

	}
	return TRUE;
}

//---------------------------------------------------------------------------


void __fastcall TFrmLaserSetUp::LaserSECSClientRead(TObject *Sender,TCustomWinSocket *Socket)
{
	try
	{
		if(FrmMain->LEDLaserSECSComm->Active == false)
		{
			FrmMain->LEDLaserSECSComm->Active = true;
		}
		_buf +=Socket->ReceiveText();

        while (_buf.Pos(";"))
        {
			AnsiString recvdata = _buf.SubString( 1, _buf.Pos(";")-1);

            if ( recvdata.Length() == (_buf.Length()-1) )
            {
				_buf = "";	//clear
            }
            else
			{
                _buf = _buf.SubString( _buf.Pos(";")+1, _buf.Length() - recvdata.Length()-1);
			}


			this->parse(recvdata);
			//SECSLaserHistoryData(recvdata ,1);
		}
	}

	catch (Exception &e)
	{
		SECSLaserHistoryData(e.Message ,1);
	}
}
//---------------------------------------------------------------------------


void __fastcall TFrmLaserSetUp::RecvSVIDProcess(String StrTrgData)
{
	int nChkEndIndex;

	nChkEndIndex = StrTrgData.Pos(";");

    int nStartIndex = StrTrgData.Pos("SVID");
	if(nStartIndex == 0)
    {
		SECSLaserHistoryData("LASER SVID Data Matching 이 맞지 않습니다!",1);
		return;
    }
    else
    {
        String Strdatacnt = StrTrgData[nStartIndex + 5];
		String StrParseData;
        for(int i=8; i<nChkEndIndex; i++)
        {
            StrParseData += StrTrgData[i];
        }

        for(int i=0; i<Strdatacnt.ToInt(); i++)
		{
            int nCommaIndex = StrParseData.Pos(",");
            if(nCommaIndex > 0)
            {
                String StrSVID;
                for(int nId=1; nId<nCommaIndex; nId++)
                {
                    StrSVID += StrParseData[nId];
                }
                String StrDataBuf;
                for(int nData=nCommaIndex+1; nData<=StrParseData.Length(); nData++)
                {
                    StrDataBuf += StrParseData[nData];
                }
				strcpy(StrParseData.c_str() ,StrDataBuf.c_str());

                nCommaIndex = StrParseData.Pos(",");
                String StrSVVal;
                for(int nVal=1; nVal<nCommaIndex; nVal++)
                {
                    StrSVVal += StrParseData[nVal];
				}

                StrDataBuf = "";
                for(int nTrim=nCommaIndex+1; nTrim<=StrParseData.Length(); nTrim++)
                {
                    StrDataBuf += StrParseData[nTrim];
                }
                strcpy(StrParseData.c_str() ,StrDataBuf.c_str());

				SVIDBuffering(StrSVID , StrSVVal);

            }
		}
    }
}
//---------------------------------------------------------------------------
void __fastcall TFrmLaserSetUp::SVIDBuffering(String StrSVID , String StrTrgData)
{
    long nVid = 0;
    int nCount = 1;

	nVid = StrSVID.ToInt();
    FrmSecsSetUp->EXGem->GEMSetVariable(nCount, &nVid, &WideString(StrTrgData));
}

//---------------------------------------------------------------------------
void __fastcall TFrmLaserSetUp::SVIDBuffering(String StrSVID , INT nCount,  WideString* wstr)
{
    long nVid = 0;
    int nVidCount = nCount;

	nVid = StrSVID.ToInt();

    FrmSecsSetUp->EXGem->GEMSetVariable(nVidCount, &nVid, (wchar_t**)wstr);

}

//---------------------------------------------------------------------------
bool __fastcall TFrmLaserSetUp::RecipeDownload(String strPPID )
{
	if (NULL == m_SecsLaser_Socket)
    	return false;
        
	AnsiString StrRcpPath =  ExtractFilePath(Application->ExeName)+ "SGConfig\\LDP\\XWork\\Recipe\\" + strPPID;
	if ( false == FileExists(StrRcpPath))
    {
		SECSLaserHistoryData("recipe file not found : " + StrRcpPath, 2);
    	return false;
    }

    BOOL bRet = false;
	String StrBuffer = ";RECIPE," + strPPID + ";";
    try
    {
		bRet = m_SecsLaser_Socket->SendText(StrBuffer) > 0;
        SECSLaserHistoryData("Secs LaserDataSend 송신 :" + StrBuffer,1);
    }
    catch(...)
    {
        SECSLaserHistoryData("Secs LaserDataSend 송신 예외",1);
    }

    return bRet;
}
//---------------------------------------------------------------------------

 void BackSlashToSlash( String& str)
{
	String strResult;
	for (int i=0; i< str.Length(); ++i)
	{
		if ( str.c_str()[i] == char('\\') )
		{
			str.c_str()[i] = '/';
		}
	}
}

//---------------------------------------------------------------------------
BOOL TFrmLaserSetUp::start(String strRootDirectory, String strPeerHostName)
{
	try
	{
		_strRootDir = strRootDirectory;
		FTPLaserServer->Active = true;
		_bServerConnected = TRUE;

		return TRUE;
	}
	catch(Exception& e)
	{
		SECSLaserHistoryData("start"+e.Message ,1);
        return FALSE;
	}
}
//---------------------------------------------------------------------------
BOOL TFrmLaserSetUp::stop()
{
	try
	{
		FTPLaserServer->Active = false;
    }
    catch(Exception& e)
	{
		SECSLaserHistoryData("stop"+ e.Message ,1);
	}

	_bClientConnected = _bServerConnected = FALSE;
    return TRUE;
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::FTPLaserServerDisconnect(TIdPeerThread *AThread)
{
	_bClientConnected = FALSE;
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::FTPLaserServerUserLogin(
	  TIdFTPServerThread *ASender, const AnsiString AUsername,
	  const AnsiString APassword, bool &AAuthenticated)
{
	if (AUsername == "laser")
	{
		AAuthenticated = true;

		ASender->HomeDir = _strRootDir;
		ASender->CurrentDir = _strRootDir;

		_bClientConnected = TRUE;
	}
	else if(AUsername == "qc1")
	{
		AAuthenticated = true;
		AnsiString StrRcpPath =  ExtractFilePath(Application->ExeName)+ "SGConfig\\LDP\\XWork\\QC";
		ASender->HomeDir = StrRcpPath;//_strRootDir;
		ASender->CurrentDir = StrRcpPath;//_strRootDir;
//		_bClientConnected = TRUE;
	}
	else if(AUsername == "qc2")
	{
		AAuthenticated = true;
		AnsiString StrRcpPath =  ExtractFilePath(Application->ExeName)+ "SGConfig\\LDP\\XWork\\QC2";
		ASender->HomeDir = StrRcpPath;//_strRootDir;
		ASender->CurrentDir = StrRcpPath;//_strRootDir;
//		_bClientConnected = TRUE;
	}
	else
	{
		AAuthenticated = false;

    }
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::FTPLaserServerRetrieveFile(
	  TIdFTPServerThread *ASender, const AnsiString AFileName,
	  TStream *&VStream)
{
	String strFullPath = AFileName;
	VStream = new TFileStream( strFullPath , fmOpenRead | fmShareDenyWrite ) ;
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::FTPLaserServerListDirectory(
      TIdFTPServerThread *ASender, const AnsiString APath,
      TIdFTPListItems *ADirectoryListing)
{
    ADirectoryListing->DirectoryName = APath;

    TSearchRec f;
    INT a = FindFirst( APath + "*.*", faAnyFile, f ) ;
    while ( a == 0 )
    {
        if ( f.Attr & faDirectory )
        {
            TIdFTPListItem* Item = ADirectoryListing->Add();
			Item->ItemType =  ditDirectory;
            Item->FileName =  "/" + f.Name;
            Item->OwnerName = "anonymous";
            Item->GroupName = "all";
            Item->OwnerPermissions = "---";
            Item->GroupPermissions = "---";
            Item->UserPermissions = "---";
            Item->Size = f.Size;
            Item->ModifiedDate = FileDateToDateTime( f.Time ) ;
		}
        else
        {
            TIdFTPListItem* Item = ADirectoryListing->Add();
            Item->ItemType =  ditFile;
            Item->FileName =  f.Name;
            Item->OwnerName = "anonymous";
            Item->GroupName = "all";
            Item->OwnerPermissions = "---";
            Item->GroupPermissions = "---";
            Item->UserPermissions = "---";
            Item->Size = f.Size;
            Item->ModifiedDate = FileDateToDateTime( f.Time ) ;

        }
    	a = FindNext( f ) ;
    }

    FindClose( f ) ;

}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::FTPLaserServerChangeDirectory(
      TIdFTPServerThread *ASender, AnsiString &VDirectory)
{
	if ( FALSE == FileExists( VDirectory))
    {
		VDirectory = ASender->HomeDir;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::FTPLaserServerGetFileSize(
      TIdFTPServerThread *ASender, const AnsiString AFilename,
      __int64 &VFileSize)
{
	VFileSize = FileSizeByName( AFilename ) ;
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::FTPLaserServerStoreFile(
      TIdFTPServerThread *ASender, const AnsiString AFileName, bool AAppend,
      TStream *&VStream)
{
	String strFullPath = " ";
        String strAFileName , strAFilePath;
        for(int a = 0 ; a< AFileName.Length() ; a++)
        {
        	if(AFileName.c_str()[a] == '/')
                {
                	strAFileName = AFileName.SubString(a+2,AFileName.Length()-1);
                        strAFilePath = AFileName.SubString(1,a);
                        strFullPath = strAFilePath+ "\\" +strAFileName;
                        break;
                }

        }

	if (AFileName.c_str()[0] == '/')
	{
		strFullPath = _strRootDir + AFileName;
	}
	else
	{

                //strFullPath = strAFilePath+ "\\" +strAFileName;
                if(strFullPath == " ")
                {
		 strFullPath = AFileName;
                }
	}
        try
        {
//            ::Sleep(50);
			if (FileExists(strFullPath) && AAppend)
            {
                    VStream = new TFileStream( strFullPath , fmOpenWrite | fmShareExclusive ) ;
                    VStream->Seek(0, soFromEnd);
            }
            else
            {
                    if(strAFilePath == "C:\\KOSES\\MMI\\SGConfig\\LDP\\XWork\\QC")
                    {
                    	::Sleep(20);
                    }
                    if(strAFilePath == "C:\\KOSES\\MMI\\SGConfig\\LDP\\XWork\\QC2")
                    {
                    	::Sleep(10);
                    }

                    SECSLaserHistoryData("FULL PATH = "+strFullPath,1);
                    VStream = new TFileStream( strFullPath , fmCreate |fmShareExclusive );//fmCreate | fmOpenReadWrite);//| fmShareExclusive ) ;
            }
        }
        catch(Exception& e)
        {
        	SECSLaserHistoryData("FTP FILE CREATE FAIL!! Store Path Error!!",3);
        }
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::FTPLaserServerDeleteFile(
      TIdFTPServerThread *ASender, const AnsiString APathName)
{
	String strFullPath = ASender->CurrentDir +  + "//" + APathName;;
	DeleteFile( strFullPath );
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::BtnFTPLaserStartClick(TObject *Sender)
{
	this->start(EditRootDir->Text , EditHostAddr->Text);
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::BtnFTPLaserStopClick(TObject *Sender)
{
	this->stop();
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::BtnFTPLaserRCPSendClick(TObject *Sender)
{
	if (OpenDialog1->Execute())
	{
		String strRecipeFilePath = OpenDialog1->FileName;
		if (TRUE == this->sendToServer( strRecipeFilePath ))
		{
			this->RecipeDownload( ExtractFileName(strRecipeFilePath));
        }
	}
}
//---------------------------------------------------------------------------


void __fastcall TFrmLaserSetUp::FTPLaserClientDisconnected(TObject *Sender)
{
	_bClientConnected = FALSE;

}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::FTPLaserClientConnected(TObject *Sender)
{
	_bClientConnected = TRUE;
}
//---------------------------------------------------------------------------
BOOL TFrmLaserSetUp::sendToServer(String strFileName)
{
	if (FALSE == FTPLaserClient->Connected())
	{
        FTPLaserClient->Host = EditHostAddr->Text;
        FTPLaserClient->Username = "mmi";
		FTPLaserClient->Password = "";
        try
        {
            FTPLaserClient->Connect(TRUE, 1000);
        }
		catch(Exception& e)
        {
            //connection time out !!!
		    SECSLaserHistoryData("Exception on connection : " + e.Message, 1 );
        }
	}

    if (FALSE == FTPLaserClient->Connected())
    {
	    SECSLaserHistoryData("fail to connect to laser server", 1);
    	return FALSE;
    }

	FTPLaserClient->TransferType =  ftBinary;
	FTPLaserClient->Put(strFileName, ExtractFileName(strFileName), false );
    FTPLaserClient->Disconnect();

    SECSLaserHistoryData("Success to download the Laser Recipe : "+ strFileName ,1);
	return TRUE;
}
//---------------------------------------------------------------------------
BOOL TFrmLaserSetUp::deleteToServer(String strFileName)
{
	if (FALSE == FTPLaserClient->Connected())
	{
        FTPLaserClient->Host = EditHostAddr->Text;
        FTPLaserClient->Username = "mmi";
		FTPLaserClient->Password = "";
        try
        {
            FTPLaserClient->Connect(TRUE, 1000);
        }
        catch(Exception& e)
        {
            //connection time out !!!
        }

	}

    if (FALSE == FTPLaserClient->Connected())
    {
    	return FALSE;
	}

	FTPLaserClient->Delete( ExtractFileName(strFileName));
    FTPLaserClient->Disconnect();
    return TRUE;
}
//---------------------------------------------------------------------------
void __fastcall TFrmLaserSetUp::LaserRCPResponseTimerTimer(TObject *Sender)
{
    LaserRCPResponseTimer->Enabled = false;
    if (NULL == m_SecsLaser_Socket)
        return;

	if(FrmSecsSetUp->m_fStart == true)
	{
/*		121009 수정 - sjyoon
		=> Recipe upload 시 CEID 1017 이벤트를 삭제해도 무방하고
		  현재 1017 Event 발생 하면 SVID 2093 Part Code를 FDC 측에 전송하여 FDC interlock 이 걸림

		//s6f11 (1017)
//		FrmSecsSetUp->RecipeupLoadStepProcess(StrRcvLaserPartCode, 1);
*/
		FrmMain->TrackInMessageView("UPLOAD 시작");
		// s7f1 , s7f3
		bool ret = this->RecipeUpload(this->StrRcvLaserPartCode);
		SECSLaserHistoryData("RecipeupLoadStepProcess  -> "+StrRcvLaserPartCode,1);

		if (ret)
		{
			m_SecsLaser_Socket->SendText("AK;");
			SECSLaserHistoryData("RECIPE UPLOAD _  AK",1);

			FrmLotRcvShow->PopUpLotCodeProcess(2 , StrRcvLaserPartCode);
		}
		else
		{
			m_SecsLaser_Socket->SendText("NK;");
			SECSLaserHistoryData("RECIPE UPLOAD _  NK",1);
		}
	}
	else
	{
		FrmCdBox->setFlag(CD_OK);
		FrmCdBox->setTitle("RECIPE UPLOAD 실패!");
		FrmCdBox->setText("SECS/GEM 연결상태를 확인해주세요!");
		FrmCdBox->BringToFront();
		FrmCdBox->ShowModal();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::FTPLaserServerException(TIdPeerThread *AThread,
      Exception *AException)
{
	SECSLaserHistoryData("Exception on FTP server : "+ AException->Message ,2);
}
//---------------------------------------------------------------------------


void __fastcall TFrmLaserSetUp::FTPLaserClientStatus(TObject *ASender,
	  const TIdStatus AStatus, const AnsiString AStatusText)
{
	SECSLaserHistoryData("Exception on FTP CLIENT: "+ AStatusText ,2);
}
//---------------------------------------------------------------------------
void __fastcall TFrmLaserSetUp::RetrylaserRecipeCall()
{
	if (NULL == m_SecsLaser_Socket)
	return ;

	m_SecsLaser_Socket->SendText("svid,all;");
	SECSLaserHistoryData("SVID _  update from laser",1);
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::BtnRetryConnectClick(TObject *Sender)
{
	SECSLaserConnection(true);
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::FTPTimerTimer(TObject *Sender)
{
	SECSLaserConnection(true);
}
//---------------------------------------------------------------------------


void __fastcall TFrmLaserSetUp::LaserRecipeNameCompare()
{
	//
	try
	{
		_strLaserRecipeName[0] = "";
		_strLaserRecipeName[1] = "";
		_strLaserRecipeName[2] = "";
		_strLaserRecipeName[3] = "";

		TcpClientLaser1->Active = true;
		TcpClientLaser2->Active = true;
		TcpClientLaser3->Active = true;
		TcpClientLaser4->Active = true;

		AnsiString strBuf = "STATUS,FILENAME;";
 //		AnsiString strMkBuf = "STATUS,MKSPECS;";   160406 LJY확인

		m_Laser_Socket1->SendText(strBuf);
		Laser1HistoryData("Laser1 : Status;FileName;");

		m_Laser_Socket2->SendText(strBuf);
		Laser2HistoryData("Laser2 : Status;FileName;");

		m_Laser_Socket3->SendText(strBuf);
		Laser3HistoryData("Laser3 : Status;FileName;");

		m_Laser_Socket4->SendText(strBuf);
		Laser4HistoryData("Laser4 : Status;FileName;");

		g_bLaserJobChk = true;
		g_nRcpCmpIndex = 0;
		TimerLaserRecipeNameCompare->Enabled = true;
				LaserMarkingTrigger->Enabled = true;	/// 151123
	}
	catch(Exception& e)
	{
		SECSLaserHistoryData("Laser Recipe Name Compare Exception : " + e.Message, 1);
		TimerLaserRecipeNameCompare->Enabled = false;
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::TimerLaserRecipeNameCompareTimer(
	  TObject *Sender)
{
	//hcchoi
	//레이저 <-> 핸들러간 이름 비교하여 SEQ에게 알림
	BOOL bSame = TRUE;

	String strGrpName;
	String strRcpName;
	MMIComm->m_mmiToSeq.cmdType = CMD_RD_DM;
	if (MMIComm->Send() &&  MMIComm->Recv())
	{
		INT nGrpNo = (int)(MMIComm->m_mmiToSeq.bufferData.dm.data[_GROUP_NO_CONVERSION_]);
		INT nRcpNo = (int)(MMIComm->m_mmiToSeq.bufferData.dm.data[_RECIPE_NO_CONVERSION_]);

		try
		{
			InfoviderMod->SubRecipe->First();
			DataLocateIndex(InfoviderMod->SubRecipe, nRcpNo-1);
			strRcpName = InfoviderMod->SubRecipe->FieldByName("SubRcpName"+ IntToStr(nGrpNo))->AsString;
		}
		catch(Exception &e)
		{
			ShowMessage("SubRecipe DB File Error : " + e.Message);
		}

		for(int nIndex = 0; nIndex < _MAX_LASER_CNT_; nIndex++)
		{
			if(0 != strRcpName.AnsiCompareIC(_strLaserRecipeName[nIndex].Trim()))
			{
				bSame = FALSE;
				nIndex = _MAX_LASER_CNT_;

				g_nRcpCmpIndex++;
				SECSLaserHistoryData("레이저"+IntToStr(nIndex)+" 이름 비교 : " + _strLaserRecipeName[nIndex] + ", Count : " + IntToStr(g_nRcpCmpIndex), 1);

				if(g_nRcpCmpIndex > 5)
				{
					TimerLaserRecipeNameCompare->Enabled = false;
					WriteCommunicationDM(3, _DM_LASER_JOB_NAME_COMPARE_);
					g_bLaserJobChk = false;					
				}
				return;
			}
		}
		MMIComm->m_mmiToSeq.bufferData.dm.nStartNo = _DM_LASER_JOB_NAME_COMPARE_;
		MMIComm->m_mmiToSeq.bufferData.dm.nEndNo = _DM_LASER_JOB_NAME_COMPARE_;
		MMIComm->m_mmiToSeq.bufferData.dm.data[_DM_LASER_JOB_NAME_COMPARE_] = bSame ? 2 : 3;
		MMIComm->m_mmiToSeq.cmdType = CMD_WR_DM;

		g_bLaserJobChk = false;

		TimerLaserRecipeNameCompare->Enabled = false;

		if (MMIComm->Send() &&  MMIComm->Recv(500))
		{
			SECSLaserHistoryData("레이저 Recipe 이름 비교 결과 : " + strRcpName + " : " + bSame, 1);
		}

	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::LaserParamUpdateforTrackIn()
{
	long nVid;

	try
	{
		if (NULL == m_SecsLaser_Socket)
		{
			SECSLaserHistoryData("SecsLaser Socket is NULL!!",1);
			return ;
		}

		m_SecsLaser_Socket->SendText("svid, all;"); 				// 11.11.16 Laser Parameter SVID Update 수정 - sjyoon
		SECSLaserHistoryData("SVID _  update from laser before Track In",1);
	}
	catch (Exception &e)
	{
    	ShowMessage(e.Message);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::AskLaserDetectPower(AnsiString strAsk)
{
	try
	{
		if(NULL == m_SecsLaser_Socket)
		{
			SECSLaserHistoryData("SecsLaser Socket is NULL!!",1);
			return;
		}
		m_SecsLaser_Socket->SendText(strAsk);
		SECSLaserHistoryData("Send to Laser for Ask Detect Power! & DataCompare timer enabled true!" + strAsk,1);
		FrmMain->g_bWaitLaserPwrData = true;
	}
	catch (Exception &e)
	{
		FrmMain->g_bWaitLaserPwrData = false;
		ShowMessage("Ask Detect Power Socket Error! " + e.Message);
	}
}
//---------------------------------------------------------------------------

bool __fastcall TFrmLaserSetUp::m_MarkingSpecDataSend1(String StrWeekCode , String StrLDPMode,int MkNumber)
//151014 Add  the function : Send the marking spec data to laser
//those are  lotcode , week code and ldp mode data  that receive from the server in case of our trigger
{
	try
	{
		if(NULL == m_Laser_Socket1)
		{
			Laser1HistoryData("LASER1 Socket is NULL!!");
			return false;
		}
		String StrMarkCmd , StrLotCode,StrLotLdpMode;



		int nRFIDTRinval = MkNumber;//ReadCommunicationDM(_TRACK_IN_DM_INDEX);
		if(nRFIDTRinval == 0)
		{
			Laser1HistoryData("Marking Spec. Index Data Errror !");
			return false;
		}

		TIniFile *RFIDMemIni = new TIniFile(ExtractFilePath(Application->ExeName) + "\\ini\\RFIDMem" + IntToStr(nRFIDTRinval) + ".ini");
		if(FileExists(ExtractFilePath(Application->ExeName) + "\\ini\\RFIDMem" + IntToStr(nRFIDTRinval) + ".ini"))
		{
				StrLotCode = RFIDMemIni->ReadString("RFID READ","LOTID","0");
				StrLotLdpMode  = RFIDMemIni->ReadString("MarkingSpec","LDPMode","0");
				strLaserLotCodeChk[0] = StrLotCode;
				strLaserMkModeChk[0] = StrLotLdpMode;
		}
		else
		{
			Laser1HistoryData("IniFile Error for Marking spec!");
			return false;
		}
		delete RFIDMemIni;

/*        int nRetVal =(int) ReadCommunicationDM(_TRACK_IN_LOT_COLOR);
		if(nRetVal == 0)
		{
			Laser1HistoryData("Marking Spec. Index Data Errror !");
			return false;
		}

		TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini");
		if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini"))
		{
			StrLotCode = ini->ReadString("LotDataSet"+IntToStr(nRetVal),"LotCode","0");
		}
		else
		{
			Laser1HistoryData("IniFile Error for Marking spec!");
			return false;
		}
		delete ini;
*/
		StrMarkCmd = "mkspec," + Trim(StrLotCode) +","+  Trim(StrWeekCode) +","+ Trim(StrLotLdpMode)+";";
		m_Laser_Socket1->SendText(StrMarkCmd);

		Laser1HistoryData("Send to Laser Marking spec data!" + StrMarkCmd);

		return true;

	}
	catch (Exception &e)
	{
		Laser1HistoryData("Marking Spec Data Socket Error! " + e.Message);
		return false;
	}
}
//---------------------------------------------------------------------------
bool __fastcall TFrmLaserSetUp::m_MarkingSpecDataSend2(String StrWeekCode , String StrLDPMode,int MkNumber)
//151014 Add  the function : Send the marking spec data to laser
//those are  lotcode , week code and ldp mode data  that receive from the server in case of our trigger
{
	try
	{
		if(NULL == m_Laser_Socket2)
		{
			Laser2HistoryData("LASER2 Socket is NULL!!");
			return false;
		}
		String StrMarkCmd , StrLotCode,StrLotLdpMode;

		int nRFIDTRinval = MkNumber;//ReadCommunicationDM(_TRACK_IN_DM_INDEX);
		if(nRFIDTRinval == 0)
		{
			Laser2HistoryData("Marking Spec. Index Data Errror !");
			return false;
		}

		TIniFile *RFIDMemIni = new TIniFile(ExtractFilePath(Application->ExeName) + "\\ini\\RFIDMem" + IntToStr(nRFIDTRinval) + ".ini");
		if(FileExists(ExtractFilePath(Application->ExeName) + "\\ini\\RFIDMem" + IntToStr(nRFIDTRinval) + ".ini"))
		{
				StrLotCode = RFIDMemIni->ReadString("RFID READ","LOTID","0");
				StrLotLdpMode  = RFIDMemIni->ReadString("MarkingSpec","LDPMode","0");
				strLaserLotCodeChk[1] = StrLotCode;
				strLaserMkModeChk[1] = StrLotLdpMode;
		}
		else
		{
			Laser2HistoryData("IniFile Error for Marking spec!");
			return false;
		}
		delete RFIDMemIni;

/*        int nRetVal =(int) ReadCommunicationDM(_TRACK_IN_LOT_COLOR);
		if(nRetVal == 0)
		{
			Laser1HistoryData("Marking Spec. Index Data Errror !");
			return false;
		}

		TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini");
		if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini"))
		{
			StrLotCode = ini->ReadString("LotDataSet"+IntToStr(nRetVal),"LotCode","0");
		}
		else
		{
			Laser1HistoryData("IniFile Error for Marking spec!");
			return false;
		}
		delete ini;
*/
		StrMarkCmd = "mkspec," + Trim(StrLotCode) +","+  Trim(StrWeekCode) +","+ Trim(StrLotLdpMode)+";";
		m_Laser_Socket2->SendText(StrMarkCmd);

		Laser2HistoryData("Send to Laser Marking spec data!" + StrMarkCmd);

		return true;

	}
	catch (Exception &e)
	{
		Laser2HistoryData("Marking Spec Data Socket Error! " + e.Message);
		return false;
	}
}
//---------------------------------------------------------------------------
bool __fastcall TFrmLaserSetUp::m_MarkingSpecDataSend3(String StrWeekCode , String StrLDPMode,int MkNumber)
//151014 Add  the function : Send the marking spec data to laser
//those are  lotcode , week code and ldp mode data  that receive from the server in case of our trigger
{
	try
	{
		if(NULL == m_Laser_Socket3)
		{
			Laser3HistoryData("LASER3 Socket is NULL!!");
			return false;
		}
		String StrMarkCmd , StrLotCode,StrLotLdpMode;

		int nRFIDTRinval = MkNumber;//ReadCommunicationDM(_TRACK_IN_DM_INDEX);
		if(nRFIDTRinval == 0)
		{
			Laser3HistoryData("Marking Spec. Index Data Errror !");
			return false;
		}

		TIniFile *RFIDMemIni = new TIniFile(ExtractFilePath(Application->ExeName) + "\\ini\\RFIDMem" + IntToStr(nRFIDTRinval) + ".ini");
		if(FileExists(ExtractFilePath(Application->ExeName) + "\\ini\\RFIDMem" + IntToStr(nRFIDTRinval) + ".ini"))
		{
				StrLotCode = RFIDMemIni->ReadString("RFID READ","LOTID","0");
				StrLotLdpMode  = RFIDMemIni->ReadString("MarkingSpec","LDPMode","0");
				strLaserLotCodeChk[2] = StrLotCode;
				strLaserMkModeChk[2] = StrLotLdpMode;
		}
		else
		{
			Laser3HistoryData("IniFile Error for Marking spec!");
			return false;
		}
		delete RFIDMemIni;

/*        int nRetVal =(int) ReadCommunicationDM(_TRACK_IN_LOT_COLOR);
		if(nRetVal == 0)
		{
			Laser1HistoryData("Marking Spec. Index Data Errror !");
			return false;
		}

		TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini");
		if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini"))
		{
			StrLotCode = ini->ReadString("LotDataSet"+IntToStr(nRetVal),"LotCode","0");
		}
		else
		{
			Laser1HistoryData("IniFile Error for Marking spec!");
			return false;
		}
		delete ini;
*/
		StrMarkCmd = "mkspec," + Trim(StrLotCode) +","+  Trim(StrWeekCode) +","+ Trim(StrLotLdpMode)+";";
		m_Laser_Socket3->SendText(StrMarkCmd);

		Laser3HistoryData("Send to Laser Marking spec data!" + StrMarkCmd);

		return true;

	}
	catch (Exception &e)
	{
		Laser3HistoryData("Marking Spec Data Socket Error! " + e.Message);
		return false;
	}
}
//---------------------------------------------------------------------------
bool __fastcall TFrmLaserSetUp::m_MarkingSpecDataSend4(String StrWeekCode , String StrLDPMode,int MkNumber)
//151014 Add  the function : Send the marking spec data to laser
//those are  lotcode , week code and ldp mode data  that receive from the server in case of our trigger
{
	try
	{
		if(NULL == m_Laser_Socket4)
		{
			Laser4HistoryData("LASER4 Socket is NULL!!");
			return false;
		}
		String StrMarkCmd , StrLotCode,StrLotLdpMode;

		int nRFIDTRinval = MkNumber;//ReadCommunicationDM(_TRACK_IN_DM_INDEX);
		if(nRFIDTRinval == 0)
		{
			Laser4HistoryData("Marking Spec. Index Data Errror !");
			return false;
		}

		TIniFile *RFIDMemIni = new TIniFile(ExtractFilePath(Application->ExeName) + "\\ini\\RFIDMem" + IntToStr(nRFIDTRinval) + ".ini");
		if(FileExists(ExtractFilePath(Application->ExeName) + "\\ini\\RFIDMem" + IntToStr(nRFIDTRinval) + ".ini"))
		{
				StrLotCode = RFIDMemIni->ReadString("RFID READ","LOTID","0");
				StrLotLdpMode  = RFIDMemIni->ReadString("MarkingSpec","LDPMode","0");
				strLaserLotCodeChk[3] = StrLotCode;
				strLaserMkModeChk[3] = StrLotLdpMode;
		}
		else
		{
			Laser4HistoryData("IniFile Error for Marking spec!");
			return false;
		}
		delete RFIDMemIni;

/*        int nRetVal =(int) ReadCommunicationDM(_TRACK_IN_LOT_COLOR);
		if(nRetVal == 0)
		{
			Laser1HistoryData("Marking Spec. Index Data Errror !");
			return false;
		}

		TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini");
		if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini"))
		{
			StrLotCode = ini->ReadString("LotDataSet"+IntToStr(nRetVal),"LotCode","0");
		}
		else
		{
			Laser1HistoryData("IniFile Error for Marking spec!");
			return false;
		}
		delete ini;
*/
		StrMarkCmd = "mkspec," + Trim(StrLotCode) +","+  Trim(StrWeekCode) +","+ Trim(StrLotLdpMode)+";";
		m_Laser_Socket4->SendText(StrMarkCmd);

		Laser4HistoryData("Send to Laser Marking spec data!" + StrMarkCmd);

		return true;

	}
	catch (Exception &e)
	{
		Laser4HistoryData("Marking Spec Data Socket Error! " + e.Message);
		return false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::m_markingSpecDataTrigger()
{
	String StrWeekCode , StrLDPMODE;


	int nMkspec1 = ReadCommunicationDM(_DM_MKSPEC1_);
	int nMkspec2 = ReadCommunicationDM(_DM_MKSPEC2_);
	int nMkspec3 = ReadCommunicationDM(_DM_MKSPEC3_);
	int nMkspec4 = ReadCommunicationDM(_DM_MKSPEC4_);


 //   if(false == bMarkingSend1)
//    {
		if(nMkspec1 > 0 && nMkspec1 < 8)// TRIGGER FROM SEQ
		{
		TIniFile *Ini= new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\MarkingSpecData.ini");
		if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\MarkingSpecData.ini"))
		{
			StrWeekCode = Ini->ReadString("MarkingSpec","WeekCode","0");
			StrLDPMODE = Ini->ReadString("MarkingSpec","LDPMode","0");
		}
		else
		{
			StrWeekCode = "";
			StrLDPMODE = "";
			Laser1HistoryData("NOTHING MARKING SPECIFICATION DATA TO SEND!!");
		}
		delete Ini;

			int nMkLotNunber1 = nMkspec1;
			WriteCommunicationDM(-1,_DM_MKSPEC1_);
			bMarkingSend1 = true;
			bMarkingTime1 = true;

			if(m_MarkingSpecDataSend1( StrWeekCode , StrLDPMODE,nMkLotNunber1) == true)
			{
					Laser1HistoryData("LASER1 Marking Data Sending Process Finish!");
			}
			else
			{
					Laser1HistoryData("LASER1 Marking Data Sending Process FAIL");
			}
		}
 //   }

//    if(false == bMarkingSend2)
//    {
		if(nMkspec2 > 0 && nMkspec2 < 8)// TRIGGER FROM SEQ
		{
		TIniFile *Ini= new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\MarkingSpecData.ini");
		if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\MarkingSpecData.ini"))
		{
			StrWeekCode = Ini->ReadString("MarkingSpec","WeekCode","0");
			StrLDPMODE = Ini->ReadString("MarkingSpec","LDPMode","0");
		}
		else
		{
			StrWeekCode = "";
			StrLDPMODE = "";
			Laser1HistoryData("NOTHING MARKING SPECIFICATION DATA TO SEND!!");
		}
		delete Ini;

			int nMkLotNunber2 = nMkspec2;
			WriteCommunicationDM(-1,_DM_MKSPEC2_);
			bMarkingSend2 = true;
			bMarkingTime2 = true;

			if(m_MarkingSpecDataSend2( StrWeekCode , StrLDPMODE,nMkLotNunber2) == true)
			{
				Laser2HistoryData("LASER2 Marking Data Sending Process Finish!");
			}
			else
			{
				Laser2HistoryData("LASER3 Marking Data Sending Process FAIL");
			}
		}
  //	}

//	if(false == bMarkingSend3)
//	{
		if(nMkspec3 > 0 && nMkspec3 < 8)// TRIGGER FROM SEQ
		{
		TIniFile *Ini= new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\MarkingSpecData.ini");
		if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\MarkingSpecData.ini"))
		{
			StrWeekCode = Ini->ReadString("MarkingSpec","WeekCode","0");
			StrLDPMODE = Ini->ReadString("MarkingSpec","LDPMode","0");
		}
		else
		{
			StrWeekCode = "";
			StrLDPMODE = "";
			Laser1HistoryData("NOTHING MARKING SPECIFICATION DATA TO SEND!!");
		}
		delete Ini;

			int nMkLotNunber3 = nMkspec3;
			WriteCommunicationDM(-1,_DM_MKSPEC3_);
			bMarkingSend3 = true;
			bMarkingTime3 = true;

			if(m_MarkingSpecDataSend3( StrWeekCode , StrLDPMODE,nMkLotNunber3) == true)
			{
				Laser3HistoryData("LASER3 Marking Data Sending Process Finish!");
			}
			else
			{
				Laser3HistoryData("LASER3 Marking Data Sending Process FAIL");
			}
		}
 //	}

//	if(false == bMarkingSend4)
//	{
		if(nMkspec4 > 0 && nMkspec4 < 8)// TRIGGER FROM SEQ
		{
		TIniFile *Ini= new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\MarkingSpecData.ini");
		if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\MarkingSpecData.ini"))
		{
			StrWeekCode = Ini->ReadString("MarkingSpec","WeekCode","0");
			StrLDPMODE = Ini->ReadString("MarkingSpec","LDPMode","0");
		}
		else
		{
			StrWeekCode = "";
			StrLDPMODE = "";
			Laser1HistoryData("NOTHING MARKING SPECIFICATION DATA TO SEND!!");
		}
		delete Ini;

			int nMkLotNunber4 = nMkspec4;
			WriteCommunicationDM(-1,_DM_MKSPEC4_);
			bMarkingSend4 = true;
			bMarkingTime4 = true;

			if(m_MarkingSpecDataSend4( StrWeekCode , StrLDPMODE,nMkLotNunber4) == true)
			{
				Laser4HistoryData("LASER4 Marking Data Sending Process Finish!");
			}
			else
			{
				Laser4HistoryData("LASER4 Marking Data Sending Process FAIL");
			}
		}
//    }

/*	   if(bMarkingTime1 && bMarkingTime2 && bMarkingTime3 && bMarkingTime4)
	   {
				LaserMarkingTrigger->Enabled = false;
				bMarkingTime1 = false;
				bMarkingTime2 = false;
				bMarkingTime3 = false;
				bMarkingTime4 = false;
	   }
*/
}

//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::LaserMarkingTriggerTimer(TObject *Sender)
{
	m_markingSpecDataTrigger();
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::Button1Click(TObject *Sender)
{






		AnsiString strMkBuf = "STATUS,MKSPEC;"; //  160406 LJY확인
		m_Laser_Socket1->SendText(strMkBuf);
		Laser1HistoryData("Laser1 : Status;MkSpec;");
		m_Laser_Socket2->SendText(strMkBuf);
		Laser2HistoryData("Laser2 : Status;MkSpec;");
		m_Laser_Socket3->SendText(strMkBuf);
		Laser3HistoryData("Laser3 : Status;MkSpec;");
		m_Laser_Socket4->SendText(strMkBuf);
		Laser4HistoryData("Laser4 : Status;MkSpec;");
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::Button2Click(TObject *Sender)
{
		String MarkCmda = "MKSPEC,,,DRILL;";
 //		m_Laser_Socket1->SendText(MarkCmda);
 //		m_Laser_Socket2->SendText(MarkCmda);
 //		m_Laser_Socket3->SendText(MarkCmda);
 //		m_Laser_Socket4->SendText(MarkCmda);
	String asdf[3];
	char *buf = NULL;
	buf = MarkCmda.c_str();
	if(0 == strnicmp(buf, "MKSPEC", 6 ))
	{
		//_strLaserRecipeName[0] = "";
		CHAR seps[]={",;\r\n"};

		CHAR buffer[MAX_PATH];
		strcpy(buffer, buf);
		CHAR* token = ::strtok(buffer, seps);
		if (token != NULL)
		{
 //			token = ::strtok(NULL, seps);
			asdf[0] = ::strtok(NULL, seps);
			asdf[1] = ::strtok(NULL, seps);
			asdf[2] = ::strtok(NULL, seps);

		}
	}

}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::Button3Click(TObject *Sender)
{
LaserMarkingTrigger->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TFrmLaserSetUp::LaserHeartBeatTimerTimer9(TObject *Sender)
{

}
//---------------------------------------------------------------------------

