//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormAlarmHistoryScrn.h"
#include "SQLite\cppsqlite3.h"
#include "BaseComm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma link "iComponent"
#pragma link "iCustomComponent"
#pragma link "iEdit"
#pragma link "iEditCustom"
#pragma link "iVCLComponent"
#pragma link "AdvSmoothTimeLine"
#pragma link "AdvDateTimePicker"
#pragma resource "*.dfm"
TFormAlarmHistory *FormAlarmHistory;

//---------------------------------------------------------------------------
__fastcall TFormAlarmHistory::TFormAlarmHistory(TComponent* Owner)
	: TForm(Owner)
{
	AlarmDateTimeGrid->Cells[0][0] ="No";
	AlarmDateTimeGrid->Cells[1][0] ="DateTime";
	AlarmDateTimeGrid->Cells[2][0] ="CODE";
	AlarmDateTimeGrid->Cells[3][0] ="FLAG";
	AlarmDateTimeGrid->Cells[4][0] ="ALARM NAME";

	for(int i = 1; i <=AlarmDateTimeGrid->RowCount; i++)
	{
		AlarmDateTimeGrid->Cells[0][i] ="";
		AlarmDateTimeGrid->Cells[1][i] ="";
		AlarmDateTimeGrid->Cells[2][i] ="";
		AlarmDateTimeGrid->Cells[3][i] ="";
		AlarmDateTimeGrid->Cells[4][i] ="";
	}


	DateTimeAlarmStart->Date = Now()-1;
	DateTimeAlarmEnd->Date = Now();

    EditAlarmCodeSearch->Text = "";

	RadioBtnAlarm->Checked == true;
    LabelHistory->Caption = "ALARM HISTORY";
    BtnAlarmHistorySave->Caption = "ALARM DATA SAVE";
}
//---------------------------------------------------------------------------
void TFormAlarmHistory::SaveToCSVFile(TStringGrid *sGrid,String sCSVFile)
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
void __fastcall TFormAlarmHistory::BtnAlarmRead1Click(TObject *Sender)
{
	for(int i = 1; i <=AlarmDateTimeGrid->RowCount; i++)
	{
		AlarmDateTimeGrid->Cells[0][i] ="";
		AlarmDateTimeGrid->Cells[1][i] ="";
		AlarmDateTimeGrid->Cells[2][i] ="";
		AlarmDateTimeGrid->Cells[3][i] ="";
		AlarmDateTimeGrid->Cells[4][i] ="";
	}

	AlarmDateTimeGrid->RowCount = 2;


  	String strFileName = ExtractFilePath(Application->ExeName) + "\\Ini\\system\\DB\\AlarmHistory.DB";

    String strStartDateTime = DateTimeAlarmStart->DateTime.FormatString("yyyy-mm-dd hh:mm:ss");

    String strEndDateTime = DateTimeAlarmEnd->DateTime.FormatString("yyyy-mm-dd hh:mm:ss");

    CHAR cFileName[100] = {0,};
	CHAR cStartTime[100] = {0,};
	CHAR cEndTime[100] = {0,};

	WideCharToMultiByte(0,0,strFileName.c_str(),-1,cFileName,strFileName.Length(),NULL,NULL);
	WideCharToMultiByte(0,0,strStartDateTime.c_str(),-1,cStartTime,strStartDateTime.Length(),NULL,NULL);
	WideCharToMultiByte(0,0,strEndDateTime.c_str(),-1,cEndTime,strEndDateTime.Length(),NULL,NULL);

	CppSQLite3DB SQLiteAlarmDB;
	SQLiteAlarmDB.open(cFileName);

	char Almtbuf[512] = {0,};
	sprintf(Almtbuf,"select * from MandatoryAlarm where EventTime > ('%s') AND EventTime < ('%s');", cStartTime, cEndTime);
	CppSQLite3Table AlarmLogtable = SQLiteAlarmDB.getTable(Almtbuf);

    int nRowIndex = 0;
    AlarmDateTimeGrid->RowCount =  AlarmLogtable.numRows();
	for (int row = 0; row < AlarmLogtable.numRows(); row++)
	{
		AlarmLogtable.setRow(row);

        if(RadioBtnAlarm->Checked == true)
        {
            if((String)AlarmLogtable.fieldValue(4) == "1")
            {
                AlarmDateTimeGrid->Cells[0][nRowIndex+1] = IntToStr(nRowIndex+1);
                AlarmDateTimeGrid->Cells[1][nRowIndex+1] = (String)AlarmLogtable.fieldValue(1);
                AlarmDateTimeGrid->Cells[2][nRowIndex+1] = (String)AlarmLogtable.fieldValue(3);
                AlarmDateTimeGrid->Cells[4][nRowIndex+1] = (String)AlarmLogtable.fieldValue(2);
				AlarmDateTimeGrid->Cells[3][nRowIndex+1] = "ALARM";
                nRowIndex++;
            }
        }
        if(RadioBtnWarning->Checked == true)
        {
            if((String)AlarmLogtable.fieldValue(4) == "0")
            {
                AlarmDateTimeGrid->Cells[0][nRowIndex+1] = IntToStr(nRowIndex+1);
                AlarmDateTimeGrid->Cells[1][nRowIndex+1] = (String)AlarmLogtable.fieldValue(1);
                AlarmDateTimeGrid->Cells[2][nRowIndex+1] = (String)AlarmLogtable.fieldValue(3);
                AlarmDateTimeGrid->Cells[4][nRowIndex+1] = (String)AlarmLogtable.fieldValue(2);
                AlarmDateTimeGrid->Cells[3][nRowIndex+1] = "WARNING";
                nRowIndex++;
            }
        }

        if(RadioBtnError->Checked == true)
        {
            if((String)AlarmLogtable.fieldValue(4) == "2")
            {
                AlarmDateTimeGrid->Cells[0][nRowIndex+1] = IntToStr(nRowIndex+1);
                AlarmDateTimeGrid->Cells[1][nRowIndex+1] = (String)AlarmLogtable.fieldValue(1);
                AlarmDateTimeGrid->Cells[2][nRowIndex+1] = (String)AlarmLogtable.fieldValue(3);
                AlarmDateTimeGrid->Cells[4][nRowIndex+1] = (String)AlarmLogtable.fieldValue(2);
                AlarmDateTimeGrid->Cells[3][nRowIndex+1] = "ERROR";
                nRowIndex++;
            }
        }

	}
    SQLiteAlarmDB.close();
}
//---------------------------------------------------------------------------

void __fastcall TFormAlarmHistory::BtnAlarmRead2Click(TObject *Sender)
{
	for(int i = 1; i <=AlarmDateTimeGrid->RowCount; i++)
	{
		AlarmDateTimeGrid->Cells[0][i] ="";
		AlarmDateTimeGrid->Cells[1][i] ="";
		AlarmDateTimeGrid->Cells[2][i] ="";
		AlarmDateTimeGrid->Cells[3][i] ="";
	}

	if(EditAlarmCodeSearch->Text != "")
	{
		AnsiString CodeName = EditAlarmCodeSearch->Text.Trim();
		AnsiString strStartDateTime = DateTimeAlarmStart->DateTime.FormatString("yyyy-mm-dd hh:mm:ss");
		AnsiString strEndDateTime = DateTimeAlarmEnd->DateTime.FormatString("yyyy-mm-dd hh:mm:ss");

		AlarmDateTimeGrid->RowCount = 2;
		AnsiString strALARM =ExtractFilePath(Application->ExeName) + "Ini\\system\\DB\\AlarmHistory.DB";

		CppSQLite3DB SQLiteAlarmDB;
		SQLiteAlarmDB.open(strALARM.c_str());
		char Almtbuf[256];
		sprintf(Almtbuf,"select * from MandatoryAlarm where AlarmCode like '%s' AND EventTime BETWEEN ('%s') AND ('%s');", CodeName.c_str(), strStartDateTime.c_str(),strEndDateTime.c_str());
		CppSQLite3Table AlarmLogtable = SQLiteAlarmDB.getTable(Almtbuf);

		for (int row = 0; row < AlarmLogtable.numRows(); row++)
		{
			AlarmLogtable.setRow(row);

			AlarmDateTimeGrid->Cells[0][row+1] = IntToStr(row+1);
			AlarmDateTimeGrid->Cells[1][row+1] = (String)AlarmLogtable.fieldValue(1);
			AlarmDateTimeGrid->Cells[2][row+1] = (String)AlarmLogtable.fieldValue(3);
			AlarmDateTimeGrid->Cells[4][row+1] = (String)AlarmLogtable.fieldValue(2);

            String strType  = "UNDEFINE";
			if((String)AlarmLogtable.fieldValue(4) == "0") strType  = "WARNING";
			if((String)AlarmLogtable.fieldValue(4) == "1") strType  = "ALARM";
			if((String)AlarmLogtable.fieldValue(4) == "2") strType  = "ERROR";

			AlarmDateTimeGrid->Cells[3][row+1] = strType;

			AlarmDateTimeGrid->RowCount = row+2;
		}
		SQLiteAlarmDB.close();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormAlarmHistory::BtnAlarmHistorySaveClick(TObject *Sender)
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

		text += "[ALARM HISTORY]\r\n";
		text += "-----------------------------------------------------------------------------------------------------------------------------------------\r\n";
		text += "    NO    DATETIME                      CODE                 FLAG                 ALARMNAME                                              \r\n";
		text += "-----------------------------------------------------------------------------------------------------------------------------------------\r\n";

		for(int nIndex=1; nIndex<AlarmDateTimeGrid->RowCount; nIndex++)
		{
			text += StringBlankMaker("",4);
			text += StringBlankMaker(AlarmDateTimeGrid->Cells[0][nIndex],3);
			text += StringBlankMaker(AlarmDateTimeGrid->Cells[1][nIndex],34);
			text += StringBlankMaker(AlarmDateTimeGrid->Cells[2][nIndex],20);
			text += StringBlankMaker(AlarmDateTimeGrid->Cells[3][nIndex],21);
			text += StringBlankMaker(AlarmDateTimeGrid->Cells[4][nIndex],40);
			text += "\r\n\r\n";
		}
		text += "\r\n\r\n";

		File->Write(text.c_str(),text.Length());
		delete File;

		FrmCdBox->setFlag(CD_OK);
		FrmCdBox->setTitle("Data Save ");
		FrmCdBox->setText("Complete to save the data to file : " + FullPath);
		FrmCdBox->BringToFront();
		FrmCdBox->ShowModal();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormAlarmHistory::BtnAlarmHistoryCsvSaveClick(TObject *Sender)
{
    String StrDateFilename = DateTimeToStr(DateTimeAlarmEnd->Date.FormatString("YYYY-MM-DD")) + FormatDateTime(" hhmmss ", Now()); ;
	SaveCsvFileDialog->FileName = StrDateFilename;
	if(SaveCsvFileDialog->Execute())
	{
		SaveToCSVFile(AlarmDateTimeGrid,SaveCsvFileDialog->FileName);

		FrmCdBox->setFlag(CD_OK);
		FrmCdBox->setTitle("Data Save ");
		FrmCdBox->setText("Complete to save the data to file : " + SaveCsvFileDialog->FileName);
		FrmCdBox->BringToFront();
		FrmCdBox->ShowModal();
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormAlarmHistory::RadioBtnAlarmClick(TObject *Sender)
{
	if(RadioBtnAlarm->Checked == true)
    {
        LabelHistory->Caption = "ALARM HISTORY";
        BtnAlarmHistorySave->Caption = "ALARM DATA SAVE(.txt)";
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormAlarmHistory::RadioBtnWarningClick(TObject *Sender)
{
	if(RadioBtnWarning->Checked == true)
    {
        LabelHistory->Caption = "WARNING HISTORY";
        BtnAlarmHistorySave->Caption = "WARNING DATA SAVE(.txt)";
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormAlarmHistory::RadioBtnErrorClick(TObject *Sender)
{
	if(RadioBtnError->Checked == true)
    {
        LabelHistory->Caption = "ERROR HISTORY";
        BtnAlarmHistorySave->Caption = "ERROR DATA SAVE(.txt)";
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormAlarmHistory::FormShow(TObject *Sender)
{
	DateTimeAlarmStart->DateTime = TDateTime(TDateTime(Now()-1).FormatString("yyyy-mm-dd") + " 22:00:00");
    DateTimeAlarmEnd->DateTime = TDateTime(Now().FormatString("yyyy-mm-dd") + " 22:00:00");

    this->BtnAlarmRead1Click(Sender);
}
//---------------------------------------------------------------------------

