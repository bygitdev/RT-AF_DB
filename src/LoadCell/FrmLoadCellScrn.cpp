//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FrmLoadCellScrn.h"
#include "BaseComm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CPort"
#pragma link "CPort"
#pragma resource "*.dfm"
TFrmLoadCell *FrmLoadCell;

//---------------------------------------------------------------------------
__fastcall TFrmLoadCell::TFrmLoadCell(TComponent* Owner)
	: TForm(Owner)
{
	_bCmdType = _RevWeight_;
	_bLoadComp = true;
}
//---------------------------------------------------------------------------
void __fastcall TFrmLoadCell::BtnLoadCellConnectClick(TObject *Sender)
{
	FrmConnectInitialize();
}
//---------------------------------------------------------------------------
void  TFrmLoadCell::CommHistoryData(String StrTemp)
{
	MemoLoadCelllog->Lines->Add(DateTimeToStr(Now()) + " : MESSAGE : " + StrTemp);

	MemoLoadCelllog->Refresh();

	if(MemoLoadCelllog->Lines->Count >1000)
	{

		TDateTime dt = Now();
		String FolderName = dt.FormatString("yyyy-mm-dd");
		String FileName = dt.FormatString("yyyy-mm-dd hh-nn-ss");
		String FullPath  =  "C:\\KOSES\\History\\LoadCell\\"+ FolderName +"\\";
		ForceDirectories(FullPath);

		MemoLoadCelllog->Lines->SaveToFile(FullPath + FileName+".txt");

		MemoLoadCelllog->Clear();
	}
}
//---------------------------------------------------------------------------
bool TFrmLoadCell::ReadLoadCellCommand()
{
	bool bRet = false;
	_bCmdType = _RevWeight_;
	if(LoadCellPort->Connected  == true)
	{
		LoadCellPort->WriteStr("01RCWT");

		if(nReadCommunicationDM(reqReadLoadCell) == STATE_BUSY)
			CommHistoryData("READ SEND!");
		bRet = true;
	}
	return bRet;
}
//---------------------------------------------------------------------------
bool TFrmLoadCell::isConnected()
{
	return LoadCellPort->Connected;
}
//---------------------------------------------------------------------------
bool TFrmLoadCell::ZeroCellCommand()
{
	bool bRet = false;
	_bCmdType = _ZeroSet_;
	if(LoadCellPort->Connected  == true)
	{
		LoadCellPort->WriteStr("01WZER");
		CommHistoryData("ZERO CELL SEND!");
		bRet = true;
	}
	return bRet;
}
//---------------------------------------------------------------------------
void __fastcall TFrmLoadCell::BtnLoadCellReadClick(TObject *Sender)
{
	ReadLoadCellCommand();
}
//---------------------------------------------------------------------------
bool TFrmLoadCell::FrmConnectInitialize()
{
	TIniFile* configIni = new TIniFile(ExtractFilePath(Application->ExeName)+"Config.ini");

	int  nPort = configIni->ReadInteger("LOADCELL","COMPORT", 9);
	WideString wStrPort =   "COM" + IntToStr(nPort);

    /*******************************
     setPortW 링크 에러 발생시
     CPort.hpp 에 아래 내용 추가 필요.
	 #ifdef UNICODE
	 #define SetPortW SetPort
	 #else
	 #define SetPortA SetPort                                                               그
	 #endif
    *********************************/

	LoadCellPort->Port =   wStrPort;
	MainLog("LOADCELL PORT ("+wStrPort+") OPEN Start.");

    delete configIni;

    try
    {
    	LoadCellPort->Open();
    }
    catch(Exception &e)
    {
		MainLog("LOADCELL PORT ("+wStrPort+") OPEN fail.");
        return false;
    }

	CommHistoryData("PORT OPEN! PORT No: " + IntToStr(nPort) );
    return true;

}
//---------------------------------------------------------------------------
void TFrmLoadCell::LoadCellDataParse(String strData)
{
	bool bSign = true;
	int nStart = strData.Pos("T");

	int nEnd = strData.Pos("+");
	if(nEnd == 0)
	{
		nEnd = strData.Pos("-");
		if(nEnd > 0)
			bSign = false;
	}

	CommHistoryData("Data Check : Start : " + IntToStr(nStart) + " END : " +  IntToStr(nEnd));
	if(_bCmdType == _RevWeight_)
	{
		if(strData.Length() == 22 && nEnd > 0)
		{
			String StrTemp = strData.SubString((nEnd+1) , 7);
			String StrValue;
			if(bSign == false)
				StrValue = "-"+StrTemp + "kg";
			else
				StrValue = StrTemp + "kg";
			PanelDisplay->Caption = StrValue;
			MainForm->_loadcellData = StrValue;
			_bLoadComp = true;

			if(nReadCommunicationDM(reqReadLoadCell) == STATE_BUSY)
			{
				CommHistoryData("PARSE : " + StrTemp);
				dWriteCommunicationDM( StrToFloat(StrTemp) , 23);// send weight
				nWriteCommunicationDM( STATE_COMP , reqReadLoadCell);  //feedback
				CommHistoryData("Feedback Weight to SEQ");
			}
		}
	}
	else
	{
		if(nReadCommunicationDM(reqLoadCellZero) == STATE_BUSY)
		{
			nWriteCommunicationDM(STATE_COMP, reqLoadCellZero);
			CommHistoryData("Feedback ZeroSet to SEQ");
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmLoadCell::LoadCellPortRxChar(TObject *Sender, int Count)
{
	String StrTemp;
	LoadCellPort->ReadStr(StrTemp, Count);

	StrReceiveMessage += StrTemp;

	if(_bCmdType == _RevWeight_)
	{
		if(StrReceiveMessage.Length() == 22)   //sizefix
		{
			CommHistoryData(StrReceiveMessage);
			LoadCellDataParse(StrReceiveMessage);
			StrReceiveMessage = "";
		}
	}
	else
	{
		if(StrReceiveMessage.Length() == 9) 									// zero set
		{
			CommHistoryData(StrReceiveMessage);
			LoadCellDataParse(StrReceiveMessage);
			StrReceiveMessage = "";
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmLoadCell::PanelDisplayDblClick(TObject *Sender)
{
	StrReceiveMessage ="";
}
//---------------------------------------------------------------------------
void __fastcall TFrmLoadCell::btnZeroSetClick(TObject *Sender)
{
	ZeroCellCommand();
}
//---------------------------------------------------------------------------

