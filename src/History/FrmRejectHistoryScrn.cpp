//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FrmRejectHistoryScrn.h"
#include "SQLite\cppsqlite3.h"
#include "BaseComm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma link "AdvDateTimePicker"
#pragma resource "*.dfm"
TFrmRejectHistory *FrmRejectHistory;

//---------------------------------------------------------------------------
__fastcall TFrmRejectHistory::TFrmRejectHistory(TComponent* Owner)
	: TForm(Owner)
{
	StrGridList->Cells[0][0] ="No";
	StrGridList->Cells[1][0] ="DATE TIME";
	StrGridList->Cells[2][0] ="LOT ID";
	StrGridList->Cells[3][0] ="RECIPE ID";
	StrGridList->Cells[4][0] ="GROUP ID";

	for(int i = 1; i <=StrGridList->RowCount; i++)
	{
		StrGridList->Cells[0][i] ="";
		StrGridList->Cells[1][i] ="";
		StrGridList->Cells[2][i] ="";
		StrGridList->Cells[3][i] ="";
		StrGridList->Cells[4][i] ="";
	}

	DateTimeStart->Date = Now()-1;
	DateTimeEnd->Date = Now();
}
//---------------------------------------------------------------------------

//create table RejectData(kIndex integer primary key, EventTime char(20) ,RejectUnit char(100) ,LotCode char(20) , Recipe char(20));");

void __fastcall TFrmRejectHistory::BtnRejecttReadClick(TObject *Sender)
{
	for(int i = 1; i <=StrGridList->RowCount; i++)
	{
		StrGridList->Cells[0][i] ="";
		StrGridList->Cells[1][i] ="";
		StrGridList->Cells[2][i] ="";
		StrGridList->Cells[3][i] ="";
		StrGridList->Cells[4][i] ="";
	}

	StrGridList->RowCount = 2;

  	String strFileName = ExtractFilePath(Application->ExeName) + "\\Ini\\system\\DB\\RejectHistory.DB";

    String strStartDateTime = DateTimeStart->DateTime.FormatString("yyyy-mm-dd hh:mm:ss");
    String strEndDateTime = DateTimeEnd->DateTime.FormatString("yyyy-mm-dd hh:mm:ss");

    CHAR cFileName[100] = {0,};
	CHAR cStartTime[100] = {0,};
	CHAR cEndTime[100] = {0,};

	WideCharToMultiByte(0,0,strFileName.c_str(),-1,cFileName,strFileName.Length(),NULL,NULL);
	WideCharToMultiByte(0,0,strStartDateTime.c_str(),-1,cStartTime,strStartDateTime.Length(),NULL,NULL);
	WideCharToMultiByte(0,0,strEndDateTime.c_str(),-1,cEndTime,strEndDateTime.Length(),NULL,NULL);

	CppSQLite3DB SQLiteRejectDB;
	SQLiteRejectDB.open(cFileName);

	char Almtbuf[256] = {0,};

	sprintf(Almtbuf,"select * from RejectData where EventTime > ('%s') AND EventTime < ('%s');", cStartTime, cEndTime);
	CppSQLite3Table RejectLogtable = SQLiteRejectDB.getTable(Almtbuf);

    StrGridList->RowCount =  RejectLogtable.numRows();
	for (int row = 0; row < RejectLogtable.numRows(); row++)
	{
		RejectLogtable.setRow(row);

        StrGridList->Cells[0][row+1] = IntToStr(row);
        StrGridList->Cells[1][row+1] = (String)RejectLogtable.fieldValue(1);
				_StrLoadRejectdata = (String)RejectLogtable.fieldValue(2);
        StrGridList->Cells[2][row+1] = (String)RejectLogtable.fieldValue(3);

        String StrGrp = (String)RejectLogtable.fieldValue(4);
        String StrRcp = (String)RejectLogtable.fieldValue(5);

		StrGridList->Cells[3][row+1] = Get_ReadRecipeName(StrGrp.ToInt()  , StrRcp.ToInt());
	}

	SQLiteRejectDB.close();
}
//---------------------------------------------------------------------------
void  TFrmRejectHistory::LoadLotCode(String StrLotCode )
{
  	String strFileName = ExtractFilePath(Application->ExeName) + "\\Ini\\system\\DB\\RejectHistory.DB";

    String strStartDateTime = DateTimeStart->DateTime.FormatString("yyyy-mm-dd hh:mm:ss");
    String strEndDateTime = DateTimeEnd->DateTime.FormatString("yyyy-mm-dd hh:mm:ss");

    CHAR cFileName[100] = {0,};
	CHAR cStartTime[100] = {0,};
	CHAR cEndTime[100] = {0,};
	CHAR cLotCode[100] = {0,};


	WideCharToMultiByte(0,0,strFileName.c_str(),-1,cFileName,strFileName.Length(),NULL,NULL);
	WideCharToMultiByte(0,0,strStartDateTime.c_str(),-1,cStartTime,strStartDateTime.Length(),NULL,NULL);
	WideCharToMultiByte(0,0,strEndDateTime.c_str(),-1,cEndTime,strEndDateTime.Length(),NULL,NULL);
	WideCharToMultiByte(0,0,StrLotCode.c_str(),-1,cLotCode,StrLotCode.Length(),NULL,NULL);

    CppSQLite3DB SQLiteRejectDB;
	SQLiteRejectDB.open(cFileName);

	char Almtbuf[256] = {0,};

	sprintf(Almtbuf,"select * from RejectData where  LotCode like '%s' AND EventTime BETWEEN ('%s') AND ('%s');",cLotCode, cStartTime, cEndTime);
	CppSQLite3Table RejectLogtable = SQLiteRejectDB.getTable(Almtbuf);

	String StrTemp =   (String)RejectLogtable.fieldValue(2);

	String StrGrp = (String)RejectLogtable.fieldValue(4);
    String StrRcp = (String)RejectLogtable.fieldValue(5);

    SQLiteRejectDB.close();

//		nRowYCnt = dReadPkgData(trayYCnt);
//		nColXCnt = dReadPkgData(trayXCnt);

	double dbtempRow = ReadPkgDataRecipeInifile(StrGrp.ToInt() , StrRcp.ToInt()  , trayYCnt );
	double dbtempCol = ReadPkgDataRecipeInifile(StrGrp.ToInt() , StrRcp.ToInt()  , trayXCnt );

	if(dbtempCol > 0 || dbtempRow > 0)
	{
        StringGridSubstrate->RowCount = dbtempRow;
        StringGridSubstrate->ColCount = dbtempCol;

		StripMakeDraw(dbtempCol , dbtempRow, StrTemp);
    }

}
//---------------------------------------------------------------------------


void __fastcall TFrmRejectHistory::StrGridListSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect)
{
	String StrChkData = StrGridList->Cells[2][ARow].Trim();
    if(CanSelect == true &&   StrChkData != "")
	{
    	LoadLotCode(StrChkData);
	}
}
//---------------------------------------------------------------------------


void TFrmRejectHistory::StripMakeDraw(int nLoadCol , int nLoadRow, String StrData)
{
	int Count = nLoadCol;
	int Total = StringGridSubstrate->ClientWidth;
	int Margin = Total % Count;
	int Default = (Total-Margin)/Count -1;

	int rMargin = Margin + 1;

	for(int i = 0; i < Count; i++)
	{
		int size = Default;
		if(Margin != 0)
		{
			if(i%(Count/Margin) == 0 && rMargin > 0)
			{
				size++;
				rMargin--;
			}
		}
		StringGridSubstrate->ColWidths[i] = size;
	}

	// row
	Count = nLoadRow;
	Total = StringGridSubstrate->ClientHeight;
	Margin = Total % Count;
	Default = (Total-Margin)/Count -1;

	rMargin = Margin + 1;

	for(int i = 0; i < Count; i++)
	{
		int size = Default;
		if(Margin != 0)
		{
			if(i%(Count/Margin) == 0 && rMargin > 0)
			{
				size++;
				rMargin--;
			}
		}
		StringGridSubstrate->RowHeights[i] = size;
	}
	int nindex = 0;
    for(int nRow=0; nRow<nLoadRow; nRow++)
    {
        for(int nCol=0; nCol <nLoadCol;  nCol++)
        {
//            if(ReadIntegerFromRootInifile("RejectCode.ini","CAPTION_VISIBLE","VISIBLE"))
//            {
//                caption = ReadStringFromRootInifile("RejectCode.ini","CAPTION","CODE_"+IntToStr(_status[nCol][nRow]));
//            }
			String StrTemp =   StrData.SubString(nindex , 1);
            StringGridSubstrate->Cells[nCol][nRow] = StrTemp;
			nindex++;
        }
    }



}
//---------------------------------------------------------------------------

void __fastcall TFrmRejectHistory::StringGridSubstrateDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State)
{
	TColor brush, font;
	brush = clWhite;
	font = clBlack;

    brush = clGray;

	StringGridSubstrate->Canvas->Brush->Color = brush;
	StringGridSubstrate->Canvas->Font->Color = clBlack;

	StringGridSubstrate->Canvas->FillRect(StringGridSubstrate->CellRect(ACol,ARow));

    DrawText(	StringGridSubstrate->Canvas->Handle,
                StringGridSubstrate->Cells[ACol][ARow].c_str(),
                StringGridSubstrate->Cells[ACol][ARow].Length(),
                &Rect,
                DT_CENTER | DT_SINGLELINE | DT_VCENTER);

}
//---------------------------------------------------------------------------


