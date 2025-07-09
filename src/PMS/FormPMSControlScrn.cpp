//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormPMSControlScrn.h"
#include "BaseComm.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma resource "*.dfm"
TFrmPMSControl *FrmPMSControl;
//---------------------------------------------------------------------------
__fastcall TFrmPMSControl::TFrmPMSControl(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TFrmPMSControl::PMSCommSwitch(bool bOnOff)
{
	if(bOnOff == true)
	{
		TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini");
		bool bPMSOnOff = ini->ReadBool("PMS","OnOff",false);
		if(bPMSOnOff == true)
		{
			if (_pms.PMSisOpen())
			{
				_pms.PMSclose();
			}
			else
			{
				INT nComPort , nCommSpeed;
				nComPort = ini->ReadInteger("PMS","Port",7);
				nCommSpeed = ini->ReadInteger("PMS","Speed",115200);

				BOOL bSuccess = _pms.PMSopen(nComPort , nCommSpeed);

				if (!bSuccess)
				{
					ShowMessage("PMS 포트 열기에 실패하였습니다.");
					delete ini;
					return;
				}
			}
		}
		else
		{
			ShowMessage("PMS 연동기능을 사용하지 않습니다!");
		}
		delete ini;
	}
	else
	{
		if (_pms.PMSisOpen())
		{
			_pms.PMSclose();
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmPMSControl::PMSMemoChange(TObject *Sender)
{
	if(PMSMemo->Lines->Count > 100)
	{
		TDateTime dt = Now();
		String FolderName = dt.FormatString("yyyy-mm-dd");
		String FileName = dt.FormatString("yyyy-mm-dd hh-nn-ss");
		String FullPath  =  "C:\\KOSES\\History\\PMSHistory\\"+ FolderName +"\\";
		ForceDirectories(FullPath);

		PMSMemo->Lines->SaveToFile(FullPath + FileName+".txt");
		PMSMemo->Clear();
		PMSMemo->Lines->Add(FullPath + FileName+".txt");
	}
	SendMessage(PMSMemo->Handle, WM_VSCROLL, SB_BOTTOM, 0);
}
//---------------------------------------------------------------------------
void TFrmPMSControl::PMSIDDataProcess(String strStripID, String strBincodes)
{
//	MMIComm->m_mmiToSeq.cmdType  = CMD_WR_ID_VI_DATA ;
//	for (int i=0; i< strBincodes.Length(); ++i)
//	{
//		MMIComm->m_mmiToSeq.bufferData.idViData[i] = strBincodes[i+1] == '1' ? 1 : 0;
//	}
//
//	if(MMIComm->Send() && MMIComm->Recv(2000))
//	{
		PMSHistoryData("Write ID map data from PMS -> "+strBincodes);
//		FrmVisionSetUp->VisionHistoryData(11, "Strip ID : " + strStripID + ", Write ID map data From PMS-> " + strBincodes);
//		WriteCommunicationDM(0, _DM_ID_VISION_MAP_);
//		FrmVisionSetUp->VisionHistoryData(11, "ID VISION DM 0 COMPLETE FROM PMS!!");
//	}
//	else
//	{
		PMSHistoryData("Fail to write ID map data to SEQ.");
//		FrmVisionSetUp->VisionHistoryData(11, "Fail to Write " + strStripID + " ID map data to SEQ From PMS");
//	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmPMSControl::FormShow(TObject *Sender)
{
	if (_pms.PMSisOpen())
	{
		BtnPMSConnect->Enabled = false;
	}

	if(TimerPMSStatus->Enabled == false)
	{
		TimerPMSStatus->Enabled = true;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmPMSControl::TimerPMSStatusTimer(TObject *Sender)
{
	bool bOpen = _pms.PMSisOpen();
	Status_Led(PanelPMSConnect ,_STATUS_LED_GREEN_ , bOpen , bOpen ? "ON" : "OFF");
}
//---------------------------------------------------------------------------

void TFrmPMSControl::SavePMSLogProcess()
{
	TDateTime dt = Now();
	String FolderName = dt.FormatString("yyyy-mm-dd");
	String FileName = dt.FormatString("yyyy-mm-dd hh-nn-ss");
	String FullPath  =  "C:\\KOSES\\History\\PMSHistory\\"+ FolderName +"\\";
	ForceDirectories(FullPath);

	PMSMemo->Lines->SaveToFile(FullPath + FileName+".txt");
}
//---------------------------------------------------------------------------
void __fastcall TFrmPMSControl::BtnPMSConnectClick(TObject *Sender)
{
	if(!_pms.PMSisOpen())
	{
		TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini");

		if(FileExists(ExtractFilePath(Application->ExeName) + "\\ini\\setup.ini"))
		{
			INT nComPort , nCommSpeed;
			nComPort = ini->ReadInteger("PMS","Port",7);
			nCommSpeed = ini->ReadInteger("PMS","Speed",115200);

			BOOL bSuccess = _pms.PMSopen(nComPort , nCommSpeed);

			if (!bSuccess)
			{
				PMSHistoryData("PMS serial port open fail!");
			}
			else
			{
				PMSHistoryData("PMS serial port open!");
			}
		}
		delete ini;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmPMSControl::BtnPMSReadClick(TObject *Sender)
{
	if(_pms.PMSisOpen())
	{
		String value;
		this->_pms.PMSread(1, &value);
		PMSHistoryData("READ VALUE -> " + value);
	}
	else
	{
		ShowMessage("PMS port가 open되어 있지 않습니다.");
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmPMSControl::BtnPMSResetClick(TObject *Sender)
{
	if(_pms.PMSisOpen())
	{
		this->_pms.PMSResetTrigger();
		PMSHistoryData("SEND PMS RESET TRIGGER!");
	}
	else
	{
		ShowMessage("PMS port가 open되어 있지 않습니다.");
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmPMSControl::BtnPMSCloseClick(TObject *Sender)
{
	if(TimerPMSStatus->Enabled == true)
	{
		TimerPMSStatus->Enabled = false;
	}
	this->Close();
}
//---------------------------------------------------------------------------

void TFrmPMSControl::PMSHistoryData(String strTemp)
{
	PMSMemo->Lines->Add(DateTimeToStr(Now()) + " : " + strTemp);
}
//---------------------------------------------------------------------------
