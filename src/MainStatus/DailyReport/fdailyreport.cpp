//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fdailyreport.h"
#include "BaseComm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothCalendar"
#pragma link "iComponent"
#pragma link "iCustomComponent"
#pragma link "iPieChart"
#pragma link "iVCLComponent"
#pragma link "DBPlannerCal"
#pragma link "PlannerCal"
#pragma resource "*.dfm"
TFrmDailyReport *FrmDailyReport;

#include "SQLite\CppSQLite3.h"
//---------------------------------------------------------------------------
__fastcall TFrmDailyReport::TFrmDailyReport(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void	TFrmDailyReport::regen(TDateTime startDate, TDateTime endDate)
{

	TDateTime startTime = TDateTime(TDateTime(startDate-1).FormatString("yyyy-mm-dd 22:00:00"));
	TDateTime endTime = TDateTime(endDate.FormatString("yyyy-mm-dd 22:00:00"));

	if(startDate.FormatString("yyyy-mm-dd") == endDate.FormatString("yyyy-mm-dd"))
	{
		Label1->Caption = " RUN DATA REPORT (" + startDate.FormatString("yyyy-mm-dd") + ")";
	}
	else
	{
		Label1->Caption = " RUN DATA REPORT (" + startDate.FormatString("yyyy-mm-dd") + " ~ " + endDate.FormatString("yyyy-mm-dd") + ")";
	}

	ALARMHISTRY_DATA aData = this->get_n_set_alarm_data(startTime, endTime);

	RUNHISTORY_DATA rData =  this->get_run_data(startTime, endTime);

	ValueListEditor1->Values["RUN TIME (min)"] = rData.runTimeMin;
	ValueListEditor1->Values["STOP TIME (min)"] = rData.stopTimeMin;
	ValueListEditor1->Values["ERROR TIME (min)"] = rData.errTimeMin;
	ValueListEditor1->Values["RUNDOWN TIME (min)"] = rData.runDownTimeMin;
	double total  =  rData.runTimeMin + rData.stopTimeMin + rData.errTimeMin + rData.runDownTimeMin;
	if( total == 0)
	{
		ValueListEditor1->Values["RUN TIME RATE"] = "0.0 %";
    }
	else
	{
		ValueListEditor1->Values["RUN TIME RATE"] = FloatToStrF(double(rData.runTimeMin)/ total * 100, ffFixed, 10, 1) + " %";
	}
	ValueListEditor1->Values["PRODUCT COUNT"] = rData.productCnt;

	ValueListEditor1->Values["ERROR1"] = aData.Err1;
	ValueListEditor1->Values["ERROR2"] = aData.Err2;
	ValueListEditor1->Values["ERROR3"] = aData.Err3;

	ValueListEditor1->Values["ERROR COUNT"] = aData.errCount;

	int errCount = aData.errCount;
	if(errCount == 0) errCount = 1;

	ValueListEditor1->Values["MTBF (min)"] = rData.runTimeMin / errCount;
	ValueListEditor1->Values["UPH"] = (rData.productCnt/rData.runTimeMin)*60.0f;

	//

	iPieChart1->ItemValue[0] = rData.errTimeMin;
	iPieChart1->ItemValue[1] = rData.runTimeMin;
	iPieChart1->ItemValue[2] = rData.stopTimeMin;
	iPieChart1->ItemValue[3] = rData.runDownTimeMin;
	iPieChart1->TitleText = "";

	this->regen_product_cout(startTime, endTime);
}
//---------------------------------------------------------------------------
RUNHISTORY_DATA		TFrmDailyReport::get_run_data(TDateTime startTime, TDateTime endTime)
{
	RUNHISTORY_DATA data;
	::ZeroMemory(&data, sizeof(data));

	if(endTime.DateString() == Today().DateString() && Now() < endTime)
	{
		data.runTimeMin = MainForm->_dbRuntime/60;
		data.stopTimeMin = MainForm->_dbStoptime/60;
		data.errTimeMin = MainForm->_dbErrtime/60;
		data.runDownTimeMin = MainForm->_dbRunDowntime/60;

		data.productCnt = nReadCommunicationDM(dailyXoutCnt) + nReadCommunicationDM(dailyGoodCnt) + nReadCommunicationDM(dailyRejectCnt) ;
	}

	if(startTime.DateString() != Today().DateString())
	{
		CppSQLite3DB SQLiteReadTimeDB;
		SQLiteReadTimeDB.open(AnsiString(ExtractFilePath(Application->ExeName) + "\\Ini\\system\\DB\\RunHistory.DB").c_str());

		AnsiString strStartDateTime = TDateTime(startTime-1).FormatString("yyyy-mm-dd hh:nn:ss");
		AnsiString strEndDateTime = TDateTime(endTime-1).FormatString("yyyy-mm-dd hh:nn:ss");

		AnsiString buf = "";
		buf.sprintf("select * from RunHistory where EventTime BETWEEN ('%s') AND ('%s');"
				,strStartDateTime.c_str()
				,strEndDateTime.c_str()
				);


		CppSQLite3Table Logtable = SQLiteReadTimeDB.getTable(buf.c_str());

		SQLiteReadTimeDB.close();


		for( int i = 0; i < Logtable.numRows(); i++ )
		{
			Logtable.setRow(i);

			int runTime = 0;
			if(String(Logtable.fieldValue("RunTime")) != "") runTime = String(Logtable.fieldValue("RunTime")).ToInt()/60;
			data.runTimeMin 	+= runTime;

			int stopTime = 0;
			if(String(Logtable.fieldValue("StopTime")) != "") stopTime = String(Logtable.fieldValue("StopTime")).ToInt()/60;
			data.stopTimeMin 	+= stopTime;

			int errTime = 0;
			if(String(Logtable.fieldValue("AlarmTime")) != "") errTime = String(Logtable.fieldValue("AlarmTime")).ToInt()/60;
			data.errTimeMin 	+= errTime;

			int rundownTime = 0;
			if(String(Logtable.fieldValue("RundownTime")) != "") rundownTime = String(Logtable.fieldValue("RundownTime")).ToInt()/60;
			data.runDownTimeMin 	+= rundownTime;

			int prCnt = 0;
			if(String(Logtable.fieldValue("Count1")) != "") prCnt = String(Logtable.fieldValue("Count1")).ToInt();
			data.productCnt 	+= prCnt;
		}
	}
	return data;
}
//---------------------------------------------------------------------------
ALARMHISTRY_DATA 	TFrmDailyReport::get_n_set_alarm_data(TDateTime startTime, TDateTime endTime)
{
	ALARMHISTRY_DATA data;
	::ZeroMemory(&data, sizeof(data));

	CppSQLite3DB SQLiteAlarmDB;
	SQLiteAlarmDB.open(AnsiString(ExtractFilePath(Application->ExeName) + "\\Ini\\system\\DB\\AlarmHistory.DB").c_str());

	AnsiString strStartDateTime = startTime.FormatString("yyyy-mm-dd hh:nn:ss");
	AnsiString strEndDateTime = endTime.FormatString("yyyy-mm-dd hh:nn:ss");

	AnsiString buf = "";
	buf.sprintf("select *, count(AlarmCode) AS Frequency from MandatoryAlarm where AlarmWarning like '2' AND EventTime BETWEEN ('%s') AND ('%s') AND AlarmCode group by AlarmCode order by Frequency DESC;"
				,strStartDateTime.c_str()
				,strEndDateTime.c_str()
				);

	CppSQLite3Table AlarmLogtable = SQLiteAlarmDB.getTable(buf.c_str());

	SQLiteAlarmDB.close();

	String err[3] = {"-","-","-"};

	if(AlarmLogtable.numRows() == 0)
	{
		StringGridErrorList->RowCount = 2;
		for(int c=0; c < StringGridErrorList->ColCount; c++)
		{
			StringGridErrorList->Cells[c][1] = "";
		}
	}
	else
	{
		StringGridErrorList->RowCount = AlarmLogtable.numRows() + 1;

		for(int r = 0; r < AlarmLogtable.numRows(); r++)
		{
			StringGridErrorList->Cells[0][r+1] = IntToStr(r+1);
			AlarmLogtable.setRow(r);

			StringGridErrorList->Cells[1][r+1] = (String)AlarmLogtable.fieldValue("AlarmCode");
			StringGridErrorList->Cells[2][r+1] = ReadStringFromRootInifile("Alarm.ini", "NAME", "NAME" + StringGridErrorList->Cells[1][r+1]);
			if(r <3) err[r] = StringGridErrorList->Cells[2][r+1];

			StringGridErrorList->Cells[3][r+1] = (String)AlarmLogtable.fieldValue("Frequency");

			data.errCount += String(AlarmLogtable.fieldValue("Frequency")).ToInt();
		}
	}

	data.Err1 = err[0];
	data.Err2 = err[1];
	data.Err3 = err[2];

	return data;
}
//---------------------------------------------------------------------------
void __fastcall TFrmDailyReport::FormCreate(TObject *Sender)
{
	StringGridErrorList->Cells[0][0] ="NO";
	StringGridErrorList->Cells[1][0] ="CODE";
	StringGridErrorList->Cells[2][0] ="NAME";
	StringGridErrorList->Cells[3][0] ="COUNT";
}
//---------------------------------------------------------------------------
void __fastcall TFrmDailyReport::FormResize(TObject *Sender)
{
	int w = StringGridErrorList->Width - 35;

	StringGridErrorList->ColWidths[0] = 50;
	StringGridErrorList->ColWidths[1] = 75;
	StringGridErrorList->ColWidths[2] = w - 200;
	StringGridErrorList->ColWidths[3] = 75;
}
//---------------------------------------------------------------------------
void __fastcall TFrmDailyReport::CalendarMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	this->regen(Calendar->GetStartDate(),Calendar->GetEndDate());
}
//---------------------------------------------------------------------------
void __fastcall TFrmDailyReport::FormShow(TObject *Sender)
{
	Calendar->SelectedDate = Today();
	this->regen(Today(),Today());
}
//---------------------------------------------------------------------------
void	TFrmDailyReport::regen_product_cout(TDateTime startTime, TDateTime endTime)
{
	AnsiString strStartDateTime = startTime.FormatString("yyyy-mm-dd hh:nn:ss");
	AnsiString strEndDateTime = endTime.FormatString("yyyy-mm-dd hh:nn:ss");

	CppSQLite3DB SQLiteDB;

	AnsiString strALARM = ExtractFilePath(Application->ExeName) + "Ini\\system\\DB\\LotEventHistory.DB";
	SQLiteDB.open(strALARM.c_str());

	AnsiString buf = "";
	buf.sprintf("SELECT JobName, SUM(OutputCount) FROM LotEventHistory where LotendTime BETWEEN ('%s') AND ('%s') GROUP BY JobName ORDER BY SUM(OutputCount) DESC;", strStartDateTime.c_str(), strEndDateTime.c_str());
	CppSQLite3Table AlarmLogtable = SQLiteDB.getTable(buf.c_str());
	SQLiteDB.close();

	ValueListEditor2->Strings->Clear();

	bool curJob = false;
	if(endTime.DateString() == Today().DateString() && Now() < endTime)  curJob = true;

	int total = 0;

	for(int r = 0; r < AlarmLogtable.numRows(); r++)
	{
		AlarmLogtable.setRow(r);

		String jobName = (String)AlarmLogtable.fieldValue("JobName");
		int count  = String(AlarmLogtable.fieldValue("SUM(OutputCount)")).ToInt();

		if(curJob)
		{
			if(jobName == Get_RecipeName())
			{
				count += nReadCommunicationDM(lotOutPutCnt);
				curJob = false;
			}
		}
		ValueListEditor2->Values[jobName] = count;

		total += count;
	}

	if(curJob)
	{
		int count = nReadCommunicationDM(lotOutPutCnt);
		ValueListEditor2->Values[Get_RecipeName()] = count;

		total += count;
	}

	int gap = ValueListEditor1->Values["PRODUCT COUNT"].ToInt() - total;
	if(gap > 0)
	{
		ValueListEditor2->Values["UNKOWN JOB"] = gap;
    }


}

void __fastcall TFrmDailyReport::BtnRunDataSaveCSVClick(TObject *Sender)
{
	int nTag = dynamic_cast<TBitBtn*>(Sender)->Tag;

	if(SaveDialog1->Execute())
	{
		if(nTag == 0)
			ValueListEditor1->Strings->SaveToFile(SaveDialog1->FileName);
		else
			SaveToCSVFile(StringGridErrorList,SaveDialog1->FileName);

		FrmCdBox->setFlag(CD_OK);
		FrmCdBox->setTitle("Data Save ");
		FrmCdBox->setText("Complete to save the data to file : " + SaveDialog1->FileName);
		FrmCdBox->BringToFront();
		FrmCdBox->ShowModal();
	}
}
//---------------------------------------------------------------------------


