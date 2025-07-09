//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fLotEventHistory.h"
#include "BaseComm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvDateTimePicker"
#pragma link "CurvyControls"
#pragma resource "*.dfm"
TfrmLotDataHistory *frmLotDataHistory;


#include <iostream.h>
#include "SQLite\cppsqlite3.h"

//---------------------------------------------------------------------------
__fastcall TfrmLotDataHistory::TfrmLotDataHistory(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void	TfrmLotDataHistory::dbInitialize()
{
	CppSQLite3DB SQLiteDB;

	AnsiString fileName = ExtractFilePath(Application->ExeName) + "Ini\\system\\DB\\LotEventHistory.DB";

    try
	{
		if(FileExists(fileName)== false)
		{
			ForceDirectories(ExtractFilePath(Application->ExeName) + "Ini\\system\\DB\\");

            try
			{
				SQLiteDB.open(fileName.c_str());
				SQLiteDB.execDML("create table LotEventHistory(kIndex integer primary key, LotID char(64), JobName char(64), LotinTime DATETIME, LotendTime DATETIME, InputCount char(64), ScrapCount char(64), GoodCount char(64), RejectCount char(64), OutputCount char(64));");
				_isInit = true;
			}
			catch (CppSQLite3Exception& e)
			{
				cerr << e.errorCode() << ":" << e.errorMessage() << endl;
				_isInit = false;
			}
		}
		else
		{
			SQLiteDB.open(fileName.c_str());
			_isInit = true;
		}

	}
	catch (Exception &e)
	{
		MainForm->MachineHistoryData( "dbInitialize Error" );
		//ShowMessage(e.Message);
	}

	SQLiteDB.close();
}
//---------------------------------------------------------------------------
void	TfrmLotDataHistory::Record_LotEnd(LOT_EVENT_DATA data)
{
	if(!_isInit) return;

	CppSQLite3DB SQLiteDB;

	AnsiString strEvnetTime = Now().FormatString("yyyy-mm-dd hh:mm:ss");
	//InputCount char(64), XoutCount char(64), GoodCount char(64), RejectCount char(64), OutputCount char(64)

	try
	{
		AnsiString strALARM = ExtractFilePath(Application->ExeName) + "Ini\\system\\DB\\LotEventHistory.DB";
		SQLiteDB.open(strALARM.c_str());

		char Savebuf[512] = {0,};
		sprintf(Savebuf, "UPDATE LotEventHistory SET LotendTime = DATETIME('%s') , InputCount = '%s' , ScrapCount = '%s' , GoodCount = '%s', RejectCount = '%s', OutputCount = '%s' WHERE LotID = '%s';" ,\
							strEvnetTime.c_str(),
							AnsiString(data.inputCnt).c_str(),
							AnsiString(data.scrapCnt).c_str(),
							AnsiString(data.goodCnt).c_str(),
							AnsiString(data.rejectCnt).c_str(),
							AnsiString(data.outputCnt).c_str(),
							data.lotID.c_str());
		SQLiteDB.execDML(Savebuf);
	}
	catch (CppSQLite3Exception& e)
	{
		MainForm->MachineHistoryData( "Record_LotEnd Error" );
		//cerr << e.errorCode() << ":" << e.errorMessage() << endl;
	}

	SQLiteDB.close();
}
//---------------------------------------------------------------------------
void	TfrmLotDataHistory::Record_LotIn(AnsiString LotID, AnsiString jobName)
{
	if(!_isInit) return;

	CppSQLite3DB SQLiteDB;

	AnsiString strEvnetTime = Now().FormatString("yyyy-mm-dd hh:mm:ss");

//	MainLog("Checking lot-in event log : " + LotID + "," + jobName);

	try
	{
		AnsiString strALARM = ExtractFilePath(Application->ExeName) + "Ini\\system\\DB\\LotEventHistory.DB";
		SQLiteDB.open(strALARM.c_str());

		char Savebuf[512] = {0,};
		//
		sprintf(Savebuf, "SELECT count(*) FROM LotEventHistory WHERE LotID = '%s';" ,\
				LotID.c_str());
		int result = SQLiteDB.execScalar(Savebuf);

		if(result == 0)
		{
//			MainLog("Lot-in event record : " + LotID + "," + jobName);
			sprintf(Savebuf, "insert into LotEventHistory (LotID , JobName, LotinTime)  values ('%s','%s',DATETIME('%s'));;" ,\
				LotID.c_str(), jobName.c_str(), strEvnetTime.c_str());
			SQLiteDB.execDML(Savebuf);
		}
	}
	catch (CppSQLite3Exception& e)
	{
		MainForm->MachineHistoryData( "Record_LotIn Error" );
		//cerr << e.errorCode() << ":" << e.errorMessage() << endl;
	}

	SQLiteDB.close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmLotDataHistory::BtnAlarmRead1Click(TObject *Sender)
{
	if(!_isInit) return;

	AnsiString strStartDateTime = DateTimeAlarmStart->DateTime.FormatString("yyyy-mm-dd hh:mm:ss");
	AnsiString strEndDateTime = DateTimeAlarmEnd->DateTime.FormatString("yyyy-mm-dd hh:mm:ss");

    CppSQLite3DB SQLiteDB;

	AnsiString strALARM = ExtractFilePath(Application->ExeName) + "Ini\\system\\DB\\LotEventHistory.DB";
	SQLiteDB.open(strALARM.c_str());

	char Almtbuf[512] = {0,};
	sprintf(Almtbuf,"select * from LotEventHistory where LotinTime > ('%s') AND LotinTime < ('%s');", strStartDateTime.c_str(), strEndDateTime.c_str());
	CppSQLite3Table AlarmLogtable = SQLiteDB.getTable(Almtbuf);
	SQLiteDB.close();

	if(AlarmLogtable.numRows() < 1)
	{
		AlarmDateTimeGrid->RowCount =  2;
		AlarmDateTimeGrid->Cells[0][1] = "1";
		for(int col=1; col < AlarmDateTimeGrid->ColCount; col++)
		{
			AlarmDateTimeGrid->Cells[col][1] = "";
		}
	}
	else
	{
		AlarmDateTimeGrid->RowCount =  AlarmLogtable.numRows() + 1;

		for (int row = 0; row < AlarmLogtable.numRows(); row++)
		{
			AlarmLogtable.setRow(row);
			AlarmDateTimeGrid->Cells[0][row+1] = IntToStr(row+1);
			for(int col=1; col < AlarmDateTimeGrid->ColCount; col++)
			{
				AlarmDateTimeGrid->Cells[col][row+1] = (String)AlarmLogtable.fieldValue(col);
			}
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmLotDataHistory::BtnAlarmRead2Click(TObject *Sender)
{
	if(!_isInit) return;

	if(EditAlarmCodeSearch->Text != "")
	{
        AnsiString strStartDateTime = DateTimeAlarmStart->DateTime.FormatString("yyyy-mm-dd hh:mm:ss");
        AnsiString strEndDateTime = DateTimeAlarmEnd->DateTime.FormatString("yyyy-mm-dd hh:mm:ss");

        CppSQLite3DB SQLiteDB;

        AnsiString strALARM = ExtractFilePath(Application->ExeName) + "Ini\\system\\DB\\LotEventHistory.DB";
        SQLiteDB.open(strALARM.c_str());

        char Almtbuf[512] = {0,};
		sprintf(Almtbuf,"select * from LotEventHistory where LotID like '%s' AND LotinTime > ('%s') AND LotinTime < ('%s');", AnsiString(EditAlarmCodeSearch->Text).c_str() ,strStartDateTime.c_str(), strEndDateTime.c_str());
        CppSQLite3Table AlarmLogtable = SQLiteDB.getTable(Almtbuf);
        SQLiteDB.close();

		if(AlarmLogtable.numRows() < 1)
		{
			AlarmDateTimeGrid->RowCount =  2;
			AlarmDateTimeGrid->Cells[0][1] = "1";
			for(int col=1; col < AlarmDateTimeGrid->ColCount; col++)
			{
				AlarmDateTimeGrid->Cells[col][1] = "";
			}
		}
		else
		{
			AlarmDateTimeGrid->RowCount =  AlarmLogtable.numRows() + 1;

			for (int row = 0; row < AlarmLogtable.numRows(); row++)
			{
				AlarmLogtable.setRow(row);
				AlarmDateTimeGrid->Cells[0][row+1] = IntToStr(row+1);
				for(int col=1; col < AlarmDateTimeGrid->ColCount; col++)
				{
					AlarmDateTimeGrid->Cells[col][row+1] = (String)AlarmLogtable.fieldValue(col);
				}
			}
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmLotDataHistory::FormCreate(TObject *Sender)
{
	this->dbInitialize();

	AlarmDateTimeGrid->ColCount = 10;

	String colLabel[] = {
			"NO.",
			"LOT ID",
			"JOB NAME",
			"LOT-IN TIME",
			"LOT_END TIME",
			"INPUT CNT",
			"SCRAP CNT",
			"GOOD CNT",
			"REJECT CNT",
			"OUTPUT CNT",
    };

	for(int i=0 ; i < AlarmDateTimeGrid->ColCount; i++)
	{
		AlarmDateTimeGrid->Cells[i][0] = colLabel[i];
	}

	AlarmDateTimeGrid->ColWidths[0] = 40;
	AlarmDateTimeGrid->ColWidths[1] = AlarmDateTimeGrid->Width - 40 - 1030;
	AlarmDateTimeGrid->ColWidths[2] = 180;
	AlarmDateTimeGrid->ColWidths[3] = 150;
	AlarmDateTimeGrid->ColWidths[4] = 150;
	AlarmDateTimeGrid->ColWidths[5] = 100;
	AlarmDateTimeGrid->ColWidths[6] = 100;
	AlarmDateTimeGrid->ColWidths[7] = 100;
	AlarmDateTimeGrid->ColWidths[8] = 100;
	AlarmDateTimeGrid->ColWidths[9] = 100;
}
//---------------------------------------------------------------------------
void __fastcall TfrmLotDataHistory::FormShow(TObject *Sender)
{
	DateTimeAlarmStart->DateTime = TDateTime(TDateTime(Now()-1).FormatString("yyyy-mm-dd") + " 22:00:00");
    DateTimeAlarmEnd->DateTime = TDateTime(Now().FormatString("yyyy-mm-dd") + " 22:00:00");

    this->BtnAlarmRead1Click(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TfrmLotDataHistory::BtnAlarmHistoryCsvSaveClick(TObject *Sender)
{
    String StrDateFilename = DateTimeToStr(DateTimeAlarmEnd->Date.FormatString("YYY-MM-DD")) + FormatDateTime(" hhmmss ", Now()); ;
	SaveCsvFileDialog->FileName = StrDateFilename;
	if(SaveCsvFileDialog->Execute())
	{
		SaveToCSVFile(AlarmDateTimeGrid,SaveCsvFileDialog->FileName);
    }
}
//---------------------------------------------------------------------------
void TfrmLotDataHistory::SaveToCSVFile(TStringGrid *sGrid,String sCSVFile)
{
    TStringList *sLst=new TStringList;
    try
    {
        for(int i=0;i< sGrid->RowCount ; i++)
        {
        	sLst->Add( sGrid->Rows[i]->CommaText );
        }
        sLst->SaveToFile(sCSVFile);
    }
    __finally
    {
    	delete sLst;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmLotDataHistory::BtnAlarmHistorySaveClick(TObject *Sender)
{
	if(SaveTextFileDialog->Execute())
	{
		TFileStream *File;
		String FileName =  SaveTextFileDialog->FileName;
		String FullPath  = SaveTextFileDialog->FileName;

		File = new TFileStream(FullPath, fmCreate | fmOpenReadWrite);
		File->Position = 0;

		AnsiString text = "\r\n\r\n";
		text += "Date : " + DateTimeToStr(Now());
		text += "\r\n\r\n";

		text += "[LOT EVENT HISTORY]\r\n";
//		text += "-----------------------------------------------------------------------------------------------------------------------------------------\r\n";
//		text += "NO\tLOTID\t\t\tJOB-NAME\t\t\tLOT-IN TIME\t\tLOT-END TIME\t\tINPUT\t\tSCRAP\t\tGOOD\t\tREJECT\t\tOUTPUT\r\n";
//		text += "-----------------------------------------------------------------------------------------------------------------------------------------\r\n";

		for(int nIndex=0; nIndex<AlarmDateTimeGrid->RowCount; nIndex++)
		{
			if(nIndex ==0)
			{
				for(int i=0; i< 204; i++)
				{
					text += "-";
				}
				text += "\r\n\r\n";
			}

			text += StringBlankMaker(AlarmDateTimeGrid->Cells[0][nIndex],8);
			text += StringBlankMaker(AlarmDateTimeGrid->Cells[1][nIndex],24);
			text += StringBlankMaker(AlarmDateTimeGrid->Cells[2][nIndex],24);
			text += StringBlankMaker(AlarmDateTimeGrid->Cells[3][nIndex],24);
			text += StringBlankMaker(AlarmDateTimeGrid->Cells[4][nIndex],24);
			text += StringBlankMaker(AlarmDateTimeGrid->Cells[5][nIndex],20);
			text += StringBlankMaker(AlarmDateTimeGrid->Cells[6][nIndex],20);
			text += StringBlankMaker(AlarmDateTimeGrid->Cells[7][nIndex],20);
			text += StringBlankMaker(AlarmDateTimeGrid->Cells[8][nIndex],20);
			text += StringBlankMaker(AlarmDateTimeGrid->Cells[9][nIndex],20);
			text += "\r\n\r\n";

			if(nIndex ==0)
			{
				for(int i=0; i< 204; i++)
				{
					text += "-";
				}
				text += "\r\n\r\n";
			}
		}
		text += "\r\n\r\n";

		File->Write(text.c_str(),text.Length());
		delete File;

		ShowMessage("파일 저장이 완료되었습니다.");
	}
}
//---------------------------------------------------------------------------
String TfrmLotDataHistory::StringBlankMaker(String StrTempData, int nBlankCnt)
{
	StrTempData = StrTempData.Trim();
	int nActualCnt = nBlankCnt - StrTempData.Length();

	if (nActualCnt < 0) {
		StrTempData = StrTempData.SubString(1, nBlankCnt);
	}
	else {
		for (int nCnt = 0; nCnt < nActualCnt; nCnt++) {
			StrTempData += " ";
		}
	}
	return StrTempData;
}


