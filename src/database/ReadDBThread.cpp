#include <vcl.h>
#pragma hdrstop

#include "ReadDBThread.h"
#include "FrmAutoFBHistory.h"
#include "FrmPadChangeHistory.h"
#include "MainFormScrn.h"
#include "CppSQLite3.h"

__fastcall TReadDBThread::TReadDBThread(String dbPath, String start, String end, String tableName, String dateColumnName)
	: TThread(true), FDBPath(dbPath), FStartTime(start), FEndTime(end), FTableName(tableName), FDateColumnName(dateColumnName)
{
	FreeOnTerminate = true;
}

void __fastcall TReadDBThread::Execute()
{
	try
	{
		CppSQLite3DB db;
		db.open(AnsiString(FDBPath).c_str());

		char sql[512];
		sprintf(sql,
			"SELECT * FROM %s WHERE %s > ('%s') AND %s < ('%s');",
			AnsiString(FTableName).c_str(),
			AnsiString(FDateColumnName).c_str(),
			AnsiString(FStartTime).c_str(),
            AnsiString(FDateColumnName).c_str(),
			AnsiString(FEndTime).c_str());

		FTable = db.getTable(sql);
		db.close();

		Synchronize(UpdateUI);
	}
	catch (Exception& e)
	{
		MainForm->MachineHistoryData("SQLite error : " + e.Message);
	}
}

void __fastcall TReadDBThread::UpdateUI()
{
	if (FTableName == "AutoFeedBackHistory")
	{
		if(FTable.numRows() < 1)
		{
			FormAutoFBHistory->AutoFeedBackDateTimeGrid->RowCount = 2;
			FormAutoFBHistory->AutoFeedBackDateTimeGrid->Cells[0][1] = "1";
			for(int col = 1; col < FormAutoFBHistory->AutoFeedBackDateTimeGrid->ColCount; col++)
				FormAutoFBHistory->AutoFeedBackDateTimeGrid->Cells[col][1] = "";
		}
		else
		{
			FormAutoFBHistory->AutoFeedBackDateTimeGrid->RowCount = FTable.numRows() + 1;
			for (int row = 0; row < FTable.numRows(); row++)
			{
				FTable.setRow(row);
				FormAutoFBHistory->AutoFeedBackDateTimeGrid->Cells[0][row+1] = IntToStr(row+1);
				for(int col = 1; col < FormAutoFBHistory->AutoFeedBackDateTimeGrid->ColCount; col++)
					FormAutoFBHistory->AutoFeedBackDateTimeGrid->Cells[col][row+1] = FTable.fieldValue(col);
			}
		}
	}
	else if (FTableName == "PadChangeHistory")
	{
		if(FTable.numRows() < 1)
		{
			FormPadChangeHistory->PadChangeTimeGrid->RowCount = 2;
			FormPadChangeHistory->PadChangeTimeGrid->Cells[0][1] = "1";
			for(int col = 1; col < FormPadChangeHistory->PadChangeTimeGrid->ColCount; col++)
				FormPadChangeHistory->PadChangeTimeGrid->Cells[col][1] = "";
		}
		else
		{
			FormPadChangeHistory->PadChangeTimeGrid->RowCount = FTable.numRows() + 1;
			for (int row = 0; row < FTable.numRows(); row++)
			{
				FTable.setRow(row);
				FormPadChangeHistory->PadChangeTimeGrid->Cells[0][row+1] = IntToStr(row+1);
				for(int col = 1; col < FormPadChangeHistory->PadChangeTimeGrid->ColCount; col++)
					FormPadChangeHistory->PadChangeTimeGrid->Cells[col][row+1] = FTable.fieldValue(col);
			}
		}
	}
}
