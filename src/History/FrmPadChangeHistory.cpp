//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "BaseComm.h"
#include "FrmPadChangeHistory.h"
#include "ReadDBThread.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvDateTimePicker"
#pragma resource "*.dfm"
TFormPadChangeHistory *FormPadChangeHistory;
//---------------------------------------------------------------------------
#include <iostream.h>
#include <fstream>
#include <string>
#include <vcl.h>
#include "SQLite\cppsqlite3.h"
#include <algorithm>
#include <cmath>
#include <SysUtils.hpp>
//---------------------------------------------------------------------------
__fastcall TFormPadChangeHistory::TFormPadChangeHistory(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void	TFormPadChangeHistory::dbInitialize()
{
	CppSQLite3DB SQLiteDB;

	AnsiString fileName = ExtractFilePath(Application->ExeName) + "Ini\\system\\DB\\PadChangeHistory.DB";

	try
	{
		cbSearchList->Items->Add("Lot ID");
		cbSearchList->Items->Add("Part ID");
		cbSearchList->Items->Add("Pad Type");
		cbSearchList->Items->Add("Pad Name");
		cbSearchList->Items->Add("Pad Alarm Code");
		cbSearchList->Items->Add("Pad Log Type");

		if(FileExists(fileName)== false)
		{
			ForceDirectories(ExtractFilePath(Application->ExeName) + "Ini\\system\\DB\\");

			try
			{
				SQLiteDB.open(fileName.c_str());
				SQLiteDB.execDML("create table PadChangeHistory("
				"kIndex integer primary key,"
				"dTime DATETIME,"
				"EqpID char(64),"
				"LotID char(64),"
				"PartNo char(64),"
				"PadType char(64),"
				"PadName char(64),"
				"PadLifeTimeCount char(64),"
				"PadVacData char(64),"
				"PadAlarmCode char(64),"
				"PadAlarmName char(64),"
				"PadLogType char(64)"
				");");

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
	}

	SQLiteDB.close();
}
//---------------------------------------------------------------------------
void __fastcall TFormPadChangeHistory::FormCreate(TObject *Sender)
{
	this->dbInitialize();

	PadChangeTimeGrid->ColCount = 12;

	String colLabel[] = {
			"NO.",
			"TIME",
			"EQP ID",
			"LOT ID",
			"PART NO",
			"PAD TYPE",
			"PAD NAME",
			"PAD LIFE COUNT",
			"PAD VAC",
			"PAD ALARM CODE",
			"PAD ALARM NAME",
			"PAD LOG TYPE",
	};

	for(int i=0 ; i < PadChangeTimeGrid->ColCount; i++)
	{
		PadChangeTimeGrid->Cells[i][0] = colLabel[i];
	}

	PadChangeTimeGrid->ColWidths[0] = 40;
	PadChangeTimeGrid->ColWidths[1] = 150;
	PadChangeTimeGrid->ColWidths[2] = 150;
	PadChangeTimeGrid->ColWidths[3] = 230;
	PadChangeTimeGrid->ColWidths[4] = 230;
	PadChangeTimeGrid->ColWidths[5] = 100;
	PadChangeTimeGrid->ColWidths[6] = 100;
	PadChangeTimeGrid->ColWidths[7] = 150;
	PadChangeTimeGrid->ColWidths[8] = 100;
	PadChangeTimeGrid->ColWidths[9] = 150;
	PadChangeTimeGrid->ColWidths[10] = 250;
	PadChangeTimeGrid->ColWidths[11] = 100;

	PadChangeResultGrid->ColCount = 5;

	String colLabel2[] = {
			"D",
			"MIN",
			"MAX",
			"AVERAGE",
			"DEVIATION",
	};

	for(int i2=0 ; i2 < PadChangeResultGrid->ColCount; i2++)
	{
		PadChangeResultGrid->Cells[i2][0] = colLabel2[i2];
	}

	PadChangeResultGrid->ColWidths[0] = 40;
	PadChangeResultGrid->ColWidths[1] = 100;
	PadChangeResultGrid->ColWidths[2] = 100;
	PadChangeResultGrid->ColWidths[3] = 100;
	PadChangeResultGrid->ColWidths[4] = 100;
}
//---------------------------------------------------------------------------

void __fastcall TFormPadChangeHistory::FormShow(TObject *Sender)
{
	DateTimePadChangeStart->DateTime = TDateTime(TDateTime(Now()-1).FormatString("yyyy-mm-dd") + " 22:00:00");
	DateTimePadChangeEnd->DateTime = TDateTime(Now().FormatString("yyyy-mm-dd") + " 22:00:00");

	this->Btn_DatabaseReadClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TFormPadChangeHistory::Btn_DatabaseReadClick(TObject *Sender)
{
	if(!_isInit) return;
	AnsiString strStartDateTime = DateTimePadChangeStart->DateTime.FormatString("yyyy-mm-dd hh:mm:ss");
	AnsiString strEndDateTime = DateTimePadChangeEnd->DateTime.FormatString("yyyy-mm-dd hh:mm:ss");
	AnsiString dbPath = ExtractFilePath(Application->ExeName) + "Ini\\system\\DB\\PadChangeHistory.DB";


	// 백그라운드 스레드로 실행
	TReadDBThread* thread = new TReadDBThread(dbPath, strStartDateTime, strEndDateTime, "PadChangeHistory", "dTime");
	thread->Start();

	/*
	AnsiString strStartDateTime = DateTimePadChangeStart->DateTime.FormatString("yyyy-mm-dd hh:mm:ss");
	AnsiString strEndDateTime = DateTimePadChangeEnd->DateTime.FormatString("yyyy-mm-dd hh:mm:ss");

	CppSQLite3DB SQLiteDB;

	AnsiString strAutoFeedBack = ExtractFilePath(Application->ExeName) + "Ini\\system\\DB\\PadChangeHistory.DB";
	SQLiteDB.open(strAutoFeedBack.c_str());

	char cBuf[512] = {0,};
	sprintf(cBuf,"select * from PadChangeHistory where dTime > ('%s') AND dTime < ('%s');", strStartDateTime.c_str(), strEndDateTime.c_str());
	CppSQLite3Table Logtable = SQLiteDB.getTable(cBuf);
	SQLiteDB.close();

	if(Logtable.numRows() < 1)
	{
		PadChangeTimeGrid->RowCount =  2;
		PadChangeTimeGrid->Cells[0][1] = "1";
		for(int col=1; col < PadChangeTimeGrid->ColCount; col++)
		{
			PadChangeTimeGrid->Cells[col][1] = "";
		}
	}
	else
	{
		PadChangeTimeGrid->RowCount =  Logtable.numRows() + 1;

		for (int row = 0; row < Logtable.numRows(); row++)
		{
			Logtable.setRow(row);
			PadChangeTimeGrid->Cells[0][row+1] = IntToStr(row+1);
			for(int col=1; col < PadChangeTimeGrid->ColCount; col++)
			{
				PadChangeTimeGrid->Cells[col][row+1] = (String)Logtable.fieldValue(col);
			}
		}
	}
	*/
}
//---------------------------------------------------------------------------

void __fastcall TFormPadChangeHistory::Btn_SaveCSVClick(TObject *Sender)
{
	String StrDateFilename = DateTimeToStr(DateTimePadChangeEnd->Date.FormatString("YYY-MM-DD")) + FormatDateTime(" hhmmss ", Now()); ;
	SaveCsvFileDialog->FileName = StrDateFilename;
	if(SaveCsvFileDialog->Execute())
	{
		SaveToCSVFile(PadChangeTimeGrid,SaveCsvFileDialog->FileName);
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormPadChangeHistory::Btn_SaveTXTClick(TObject *Sender)
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

		text += "[PAD CHANGE HISTORY]\r\n";

		for(int nIndex=0; nIndex<PadChangeTimeGrid->RowCount; nIndex++)
		{
			if(nIndex ==0)
			{
				for(int i=0; i< 204; i++)
				{
					text += "-";
				}
				text += "\r\n\r\n";
			}

			text += StringBlankMaker(PadChangeTimeGrid->Cells[0][nIndex],8);
			text += StringBlankMaker(PadChangeTimeGrid->Cells[1][nIndex],24);
			text += StringBlankMaker(PadChangeTimeGrid->Cells[2][nIndex],24);
			text += StringBlankMaker(PadChangeTimeGrid->Cells[3][nIndex],24);
			text += StringBlankMaker(PadChangeTimeGrid->Cells[4][nIndex],24);
			text += StringBlankMaker(PadChangeTimeGrid->Cells[5][nIndex],20);

			for (int iBridge = 6; iBridge < 207; iBridge++)
			{
				text += StringBlankMaker(PadChangeTimeGrid->Cells[iBridge][nIndex],20);
			}

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
void TFormPadChangeHistory::Record_PadChange(PADCHANGE_DATA data)
{
	if(!_isInit) return;

	CppSQLite3DB SQLiteDB;

	try
	{
		AnsiString strAutoFeedBack = ExtractFilePath(Application->ExeName) + "Ini\\system\\DB\\PadChangeHistory.DB";
		SQLiteDB.open(strAutoFeedBack.c_str());

		char Savebuf[1000000] = {0,};
		AnsiString strEvnetTime = Now().FormatString("yyyy-mm-dd hh:mm:ss");

		sprintf(Savebuf, "insert into PadChangeHistory ("
		"dTime, EqpID, LotID, PartNo, PadType, "
		"PadName, PadLifeTimeCount,  PadVacData,  PadAlarmCode,  PadAlarmName,  PadLogType"
		")"
		"values (DATETIME('%s'), '%s', '%s', '%s', '%s',"
		"'%s', '%s', '%s', '%s', '%s', '%s'"
		");;" ,\
		strEvnetTime.c_str(), data.EqpID, data.LotID, data.PartNo, data.PadType,
		data.PadName, data.PadLifeTimeCount, data.PadVacData, data.PadAlarmCode, data.PadAlarmName, data.PadLogType);

		SQLiteDB.execDML(Savebuf);
	}
	catch (CppSQLite3Exception& e)
	{
		MainForm->MachineHistoryData( "PadChangeHistory Error" );
	}

	SQLiteDB.close();
}
//---------------------------------------------------------------------------
void __fastcall TFormPadChangeHistory::Button1Click(TObject *Sender)
{
	try
	{

	}
	catch (...) {}
}
//---------------------------------------------------------------------------
void  TFormPadChangeHistory::PadChangeDataSave(int logType, int logNo, int logPicknPlace)
{
	try
	{
		AnsiString fileName = ExtractFilePath(Application->ExeName) + "Ini\\system\\DB\\PadChangeHistory.DB";

		if(FileExists(fileName) == true)
		{
			PADCHANGE_DATA data;
			int nStageNum = dReadPkgData(qpdvisionPickStage);
			g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_STG1_LOT_INFO+nStageNum;

			BOOL bRet = g_MMIComm->Send() &&  g_MMIComm->Recv();
			if (bRet)
			{
				LOT_INFO info = g_MMIComm->m_mmiToSeq.buffer.lotInfo;

				data.EqpID = String(info.eqpID);
				data.LotID = String(info.mergeLotID);
				data.PartNo = String(info.partID);
			}
			else
			{
				data.EqpID = "";
				data.LotID = "";
				data.PartNo = "";
			}

			int nJigtype = dReadPkgData(targetPad);
			String sJigName = "";
			int nJigNo = nReadCommunicationDM(flagPadNo);
			if (nJigNo == 0)
				sJigName = "A";
			else if (nJigNo == 1)
				sJigName = "B";
			else if (nJigNo == 2)
				sJigName = "C";
			else if (nJigNo == 3)
				sJigName = "D";
			else
				sJigName = "E";

			double dPadCount = 0;
			if(0 == nJigtype)
			{
				dPadCount = dReadCommunicationDM(curLifeTime00);
			}
			else if(1 == nJigtype)
			{
				dPadCount = dReadCommunicationDM(curLifeTime01);
			}

			double dPadAiValue = dReadCommunicationDM(aiChStaubli);
			AnsiString asPadAiValue = FormatFloat("0.000", dPadAiValue);

			data.PadType = IntToStr(nJigtype);
			data.PadName = sJigName;
			data.PadLifeTimeCount = FloatToStr(dPadCount);
			data.PadVacData = asPadAiValue;

			int errcodes = logNo;
			String seq_msg = "";
			TIniFile* DetailAlarmini = new TIniFile(ExtractFilePath(Application->ExeName)+ "Ini\\Alarm.ini");

			if(DetailAlarmini != NULL)
			{
				if(errcodes > 0)
				{
					seq_msg = "["+IntToStr(errcodes)+"]"+ DetailAlarmini->ReadString("NAME","NAME"+IntToStr(errcodes),"NAME"+IntToStr(errcodes));
					MainForm->MachineHistoryData("SEQ Error detected : " + seq_msg);

					data.PadAlarmCode = IntToStr(errcodes);
					data.PadAlarmName = seq_msg;
				}
				else
				{
					data.PadAlarmCode = "";
					data.PadAlarmName = "";
				}
			}
			delete DetailAlarmini;

			data.PadLogType = IntToStr(logType);

			int nPadPicknPlace = logPicknPlace;
			String sPadPicknPlace = "";
			if (nPadPicknPlace == 1)
				sPadPicknPlace = "PICKUP";
			else if (nPadPicknPlace == 2)
				sPadPicknPlace = "PLACE";
			else
				sPadPicknPlace = "ALARM";

			data.PadLogPicknPlace = sPadPicknPlace;

			Record_PadChange(data);
		}
		else
		{
			MessageDlg("PadChangeDataSave failed.", mtError, TMsgDlgButtons() << mbOK, 0);
		}
	}
	catch (...) {}
}
//---------------------------------------------------------------------------

void __fastcall TFormPadChangeHistory::Button2Click(TObject *Sender)
{
	try
	{
		if (PadChangeTimeGrid->RowCount >= 2)
		{
			double dData[100000] = {0, };
			for(int i=0 ; i < PadChangeTimeGrid->RowCount-1; i++)
			{
				dData[i] = StrToFloat(PadChangeTimeGrid->Cells[8][i+1]);
			}
			double dDataMin = dData[0];
			double dDataMax = dData[0];

			for(int i=0 ; i < PadChangeTimeGrid->RowCount-1; i++)
			{
				if (dData[i] < dDataMin)
					dDataMin = dData[i];
				if (dData[i] > dDataMax)
					dDataMax = dData[i];
			}

			int nRowCnt = PadChangeTimeGrid->RowCount-1;
			double dDataMedian = findMedianValue(dData, nRowCnt);
			double dDataAvg = findAverageValue(dData, nRowCnt);
			double dDataDeviation = calculateStandardDeviation(dData, nRowCnt);

			AnsiString asDataMin = FormatFloat("0.000", dDataMin);
			AnsiString asDataMax = FormatFloat("0.000", dDataMax);
			AnsiString asDataAvg = FormatFloat("0.000", dDataAvg);
			AnsiString asDataDeviation = FormatFloat("0.000", dDataDeviation);

			PadChangeResultGrid->Cells[1][1] = asDataMin;
			PadChangeResultGrid->Cells[2][1] = asDataMax;
			PadChangeResultGrid->Cells[3][1] = asDataAvg;
			PadChangeResultGrid->Cells[4][1] = asDataDeviation;
		}

	}
	catch (...) {}
}
//---------------------------------------------------------------------------
void TFormPadChangeHistory::sortArray(double arr[], int size)
{
	std::sort(arr, arr + size);
}
//---------------------------------------------------------------------------
double TFormPadChangeHistory::findAverageValue(double arr[], int size)
{
    if (size <= 0) return 0.0;

    double sum = 0.0;
    for (int i = 0; i < size; ++i)
    {
        sum += arr[i];
    }

    return sum / size;
}
//---------------------------------------------------------------------------
double TFormPadChangeHistory::findMedianValue(double arr[], int size)
{
	if (size == 0) return 0.0;

	sortArray(arr, size);

	if (size % 2 == 1)
	{
		return arr[size / 2];
	}
	else
	{
		int  mid1 = size / 2 - 1;
		int  mid2 = size / 2;
		return (arr[mid1] + arr[mid2]) / 2.0;
    }
}
//---------------------------------------------------------------------------
double TFormPadChangeHistory::calculateMean(double arr[], int size)
 {
	if (size == 0) return 0.0;

	double sum = 0.0;
	for (int i = 0; i < size; ++i)
	{
		sum += arr[i];
	}

	return sum / size;
}
//---------------------------------------------------------------------------
double TFormPadChangeHistory::calculateStandardDeviation(double arr[], int size)
{
	if (size == 0) return 0.0;

	double mean = calculateMean(arr, size);
	double sumOfSquares = 0.0;

	for (int i = 0; i < size; ++i)
	{
		double diff = arr[i] - mean;
		sumOfSquares += diff * diff;
    }

	double variance = sumOfSquares / size;
	return std::sqrt(variance);
}
//---------------------------------------------------------------------------
void __fastcall TFormPadChangeHistory::Btn_SearchClick(TObject *Sender)
{
	if(!_isInit) return;

	try
	{
		AnsiString sList = cbSearchList->Text;
		AnsiString sSelItem = cbSearchList->Text;

		if (sList == "Lot ID")
			sSelItem = "LotID";
		else if (sList == "Part ID")
			sSelItem = "PartNo";	
		else if (sList == "Pad Type")
			sSelItem = "PadType";	
		else if (sList == "Pad Name")
			sSelItem = "PadName";	
		else if (sList == "Pad Alarm Code")
			sSelItem = "PadAlarmCode";	
		else if (sList == "Pad Log Type")
			sSelItem = "PadLogType";

		AnsiString sSearchText = EditSearch->Text.Trim();

		if(sList != "")
		{
			AnsiString strStartDateTime = DateTimePadChangeStart->DateTime.FormatString("yyyy-mm-dd hh:mm:ss");
			AnsiString strEndDateTime = DateTimePadChangeEnd->DateTime.FormatString("yyyy-mm-dd hh:mm:ss");

			CppSQLite3DB SQLiteDB;

			AnsiString strALARM = ExtractFilePath(Application->ExeName) + "Ini\\system\\DB\\PadChangeHistory.DB";
			SQLiteDB.open(strALARM.c_str());

			char cBuf[512] = {0,};
			createQuery(strStartDateTime.c_str(), strEndDateTime.c_str(), sSelItem.c_str(), sSearchText.c_str(), cBuf, sizeof(cBuf));
			CppSQLite3Table Logtable = SQLiteDB.getTable(cBuf);

			if(Logtable.numRows() < 1)
			{
				PadChangeTimeGrid->RowCount =  2;
				PadChangeTimeGrid->Cells[0][1] = "1";
				for(int col=1; col < PadChangeTimeGrid->ColCount; col++)
				{
					PadChangeTimeGrid->Cells[col][1] = "";
				}
			}
			else
			{
				PadChangeTimeGrid->RowCount =  Logtable.numRows() + 1;

				for (int row = 0; row < Logtable.numRows(); row++)
				{
					Logtable.setRow(row);
					PadChangeTimeGrid->Cells[0][row+1] = IntToStr(row+1);
					for(int col=1; col < PadChangeTimeGrid->ColCount; col++)
					{
						PadChangeTimeGrid->Cells[col][row+1] = (String)Logtable.fieldValue(col);
					}
				}
			}
			SQLiteDB.close();
		}
	}
	catch (...) {}
}
//---------------------------------------------------------------------------
void TFormPadChangeHistory::createQuery(const std::string& sStartDateTime, const std::string& sEndDateTime, const std::string& sSelItem, const std::string& sSearchText, char* buffer, size_t bufferSize)
{
	snprintf(buffer, bufferSize, "SELECT * FROM PadChangeHistory WHERE dTime > ('%s') AND dTime < ('%s') AND %s = '%s';", sStartDateTime.c_str(), sEndDateTime.c_str(), sSelItem.c_str(), sSearchText.c_str());
}
//---------------------------------------------------------------------------


void __fastcall TFormPadChangeHistory::Btn_Search_PartIDClick(TObject *Sender)
{
	if(!_isInit) return;

	try
	{
		AnsiString sSelItem = "PartNo";

		AnsiString sSearchText = EditSearch_PartID->Text.Trim();

		AnsiString strStartDateTime = DateTimePadChangeStart->DateTime.FormatString("yyyy-mm-dd hh:mm:ss");
		AnsiString strEndDateTime = DateTimePadChangeEnd->DateTime.FormatString("yyyy-mm-dd hh:mm:ss");

		CppSQLite3DB SQLiteDB;

		AnsiString strALARM = ExtractFilePath(Application->ExeName) + "Ini\\system\\DB\\PadChangeHistory.DB";
		SQLiteDB.open(strALARM.c_str());

		char cBuf[512] = {0};
		sprintf(cBuf, "SELECT * FROM PadChangeHistory WHERE dTime > '%s' AND dTime < '%s' AND %s LIKE '%%%s%%';", strStartDateTime.c_str(), strEndDateTime.c_str(), sSelItem.c_str(), sSearchText.c_str());
		CppSQLite3Table Logtable = SQLiteDB.getTable(cBuf);

		if(Logtable.numRows() < 1)
		{
			PadChangeTimeGrid->RowCount =  2;
			PadChangeTimeGrid->Cells[0][1] = "1";
			for(int col=1; col < PadChangeTimeGrid->ColCount; col++)
			{
				PadChangeTimeGrid->Cells[col][1] = "";
			}
		}
		else
		{
			PadChangeTimeGrid->RowCount =  Logtable.numRows() + 1;

			for (int row = 0; row < Logtable.numRows(); row++)
			{
				Logtable.setRow(row);
				PadChangeTimeGrid->Cells[0][row+1] = IntToStr(row+1);
				for(int col=1; col < PadChangeTimeGrid->ColCount; col++)
				{
					PadChangeTimeGrid->Cells[col][row+1] = (String)Logtable.fieldValue(col);
				}
			}
		}
		SQLiteDB.close();
	}
	catch (...) {}
}
//---------------------------------------------------------------------------

