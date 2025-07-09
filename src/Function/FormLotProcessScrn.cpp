//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormLotProcessScrn.h"
//---------------------------------------------------------------------------
#include "BaseComm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma resource "*.dfm"
TFormLotProcess *FormLotProcess;
//---------------------------------------------------------------------------
__fastcall TFormLotProcess::TFormLotProcess(TComponent* Owner)
	: TForm(Owner)
{
	_pCeyon = NULL;

	RFIDStringGrid->Cells[0][0] = "ID";
    RFIDStringGrid->Cells[1][0] = "ITEM NAME";
    RFIDStringGrid->Cells[2][0] = "ITEM VALUE";
    RFIDStringGrid->Cells[3][0] = "CONTROL";

	for( int i = 0; i < this->RFIDStringGrid->RowCount; i++ )
	{
		this->RFIDStringGrid->Cells[ 0 ][ i + 1 ] = IntToStr( i + 1 );
	}

    RFIDStringGrid->Cells[1][1] = "MAGAZINE NUMBER";
    RFIDStringGrid->Cells[1][2] = "LOT ID";
    RFIDStringGrid->Cells[1][3] = "STEP NO";
    RFIDStringGrid->Cells[1][4] = "PKG NAME";
    RFIDStringGrid->Cells[1][5] = "FRMAE ID";
    RFIDStringGrid->Cells[1][6] = "PART NUMBER";

}
//---------------------------------------------------------------------------
void __fastcall TFormLotProcess::BtnCloseClick(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------
void TFormLotProcess::LotLogData(String StrTemp)
{
	LotMemo->Lines->Add(DateTimeToStr(Now()) + ": " + StrTemp);
	LotMemo->Refresh();

	if(LotMemo->Lines->Count > 1000)
	{
		TDateTime dt = Now();
		String FolderName = dt.FormatString("yyyy-mm-dd");
		String FileName = dt.FormatString("yyyy-mm-dd hh-nn-ss");
		String FullPath  =  "C:\\KOSES\\History\\LotHistory\\"+ FolderName +"\\";
		ForceDirectories(FullPath);

		LotMemo->Lines->SaveToFile(FullPath + FileName+".txt");

		LotMemo->Clear();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormLotProcess::LotMemoChange(TObject *Sender)
{
	SendMessage(LotMemo->Handle, WM_VSCROLL, SB_BOTTOM, 0);
}
//---------------------------------------------------------------------------

void __fastcall TFormLotProcess::BtnSaveLogClick(TObject *Sender)
{
    TDateTime dt = Now();
    String FolderName = dt.FormatString("yyyy-mm-dd");
    String FileName = dt.FormatString("yyyy-mm-dd hh-nn-ss");
    String FullPath  =  "C:\\KOSES\\History\\LotHistory\\"+ FolderName +"\\";
    ForceDirectories(FullPath);

    LotMemo->Lines->SaveToFile(FullPath + FileName+".txt");

    LotMemo->Clear();

	LotLogData("LOG Saved"+ FullPath + FileName+".txt");
}
//---------------------------------------------------------------------------

bool TFormLotProcess::RFIDConnect_Initialize()
{
	_pCeyon = new TXCyRem(this);
    _pCeyon->OnContinuousEvent = OnContinuousEvent;

	INT nComPort;
	TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini");

	nComPort = ini->ReadInteger("RFID","Port",5);
	INT nReadCh = ini->ReadInteger("RFID","ReadCh",1);
	INT nWriteCh = ini->ReadInteger("RFID","WriteCh",0);
	INT nRFIDWriteFailCnt = ini->ReadInteger("RFID","RetryWriteCnt",3);
	BOOL bTagwriteTest = ini->ReadBool("RFID","BoolWriteTest",false);
	delete ini;

	_pCeyon->Port = nComPort;

	try
	{
        _pCeyon->ReleasePort();
        _pCeyon->InitializePort();

        return true;
	}
	catch(Exception& e)
	{
		ShowMessage(e.Message);
    	return false;
	}

}
//---------------------------------------------------------------------------
bool TFormLotProcess::RFIDConnect_Close()
{
	if (_pCeyon)
    {
		_pCeyon->ReleasePort();

        delete _pCeyon;
        _pCeyon = NULL;
    }

    return true;
}
//---------------------------------------------------------------------------
void __fastcall TFormLotProcess::OnContinuousEvent(System::TObject * Sender,BSTR rcvPacket)
{
	WideString wStr =  rcvPacket;
	LotLogData(wStr);

    AnsiString Strbuffer;
	Strbuffer = String(wStr);

//	if(strcmp(Strbuffer.c_str(), "NAK") == 0)
//	{
//
//		if(nTrackOutInfo == 1)
//		{
//				nTrackOutInfo = -1;
//				FrmMain->MachineHistoryData("RFID UNLOADER M/Z ID Read Fail!!", _RED_);
//				WriteCommunicationDM(_RFID_RESPONSE_FAIL_, _ULD_RFID_READ_DM_);
//				return;
//
//		}
//
//		if(FrmMain->bRFReadfinish == true && nTrackOutInfo != 1)
//		{
//
//			FrmMain->bRFReadfinish = false;										// RFID Read Fail 후 지속적 Fail 을 해결하기 위해 추가함 - 111220 sjyoon
//			WriteCommunicationDM(_RFID_RESPONSE_FAIL_, _RFID_READ_DM_);
//
//		}
//
//		if(FrmMain->bRFWritefinish == true)
//		{
//			if(nRFIDWriteFailCnt > nRetryWritecnt)
//			{
//				nRetryWritecnt++;
//				nWriteSendIndex = _LOT_ID_;
//				WriteTagDataProcess();
//				FrmMain->MachineHistoryData("RFID COMM FAIL: RETRY"+ IntToStr(nRetryWritecnt) , _RED_);
//			}
//			else
//			{
//
//				WriteCommunicationDM(_RFID_RESPONSE_FAIL_, _RFID_WRITE_DM_);
//				nRetryWritecnt =0;
//				FrmMain->bRFWritefinish = false;
//				nWriteSendIndex = _LOT_ID_;
//				FrmMain->MachineHistoryData("RFID COMM FAIL: RETRY END ", _RED_);
//
//			}
//		}
//
//		if(FrmMain->bLDInitStep == true)
//		{
//			nLDInitIndex = 0;
//			FrmMain->bLDInitStep = false;
//			FrmMain->MachineHistoryData("RFID LOADER Tag Init Fail !", _RED_);
//		}
//
//		FrmMain->MachineHistoryData("RFID COMM RCV : NAK" , _RED_);
//		return;
//	}
//
//	if(strcmp(Strbuffer.c_str(),"ACK") == 0)
//	{
//		RFID_ResponseProcess_Step1();
//	}
//
//	int nChkEndIndex;
//	if ((nChkEndIndex = Strbuffer.Pos("TAG")) >0)
//	{
//		RFID_ResponseProcess_Step2(nChkEndIndex , Strbuffer);
//	}
}


//---------------------------------------------------------------------------

void __fastcall TFormLotProcess::OHTReadTimerTimer(TObject *Sender)
{
//	if(g_pNvMem->GetNDm(readRfidState) == 1)         		// WriteIndex DM(63) 감지 타이머. 0이 아닐시 OHT 관련 Tag Read
	{
		OHTReadTimer->Enabled = false;           	               	// WriteIndex DM(63) 감지 타이머 중지		`

//		nWriteIndex = ReadCommunicationDM(_OHT_WRITE_INDEX_DM_);
//
//		TIniFile *OHTInfoIni = new TIniFile(ExtractFilePath(Application->ExeName) + "\\ini\\OHTInfo.ini");	//OHTInfo.ini 에 실제로 쓰는 부분
//
//		if(FileExists(ExtractFilePath(Application->ExeName) + "\\ini\\OHTInfo.ini"))
//		{
//			// StrTROutMzNo, StrTROutLotID는 TrackOut 전 Unloader Magazine에서 RFID로 읽어들인 MZ_ID 와 LOT_ID 를 저장한 변수
//
//			OHTInfoIni->WriteString("SEND_INFO_"+IntToStr(nWriteIndex),"MAGAZINE_ID",StrTROutMzNo.Trim());
//			OHTInfoIni->WriteString("SEND_INFO_"+IntToStr(nWriteIndex),"LOT_ID",StrTROutLotID.Trim());
//
//			LotLogData("OHTInfo.ini MAGAZINE ID = "+ StrLastRFMzNo +" LOT ID = "+StrTROutLotID + " 저장 완료");
//		}
//		delete OHTInfoIni;
//
//		WriteCommunicationDM(0, _OHT_WRITE_INDEX_DM_);       		// WriteIndex DM(63) 초기화
	}
}
//---------------------------------------------------------------------------



void __fastcall TFormLotProcess::BtnConnectRFIDClick(TObject *Sender)
{
	if(this->RFIDConnect_Initialize() == true)
    {

    }
    else
    {

    }
}
//---------------------------------------------------------------------------

void __fastcall TFormLotProcess::BtnDisconnectRFIDClick(TObject *Sender)
{
	this->RFIDConnect_Close();
}
//---------------------------------------------------------------------------

