//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CommonDataSetting.h"
#include <inifiles.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrmCommonSet *FrmCommonSet;

#define AXIS_COUNT 		50
#define INDEX_COUNT 	50
//---------------------------------------------------------------------------
__fastcall TFrmCommonSet::TFrmCommonSet(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFrmCommonSet::FormCreate(TObject *Sender)
{
    String fileName = ExtractFilePath(Application->ExeName)+ "\\ini\\MotorName.ini";
	TIniFile* nameIni  = new TIniFile(fileName);

    StringGridAxis->RowCount = AXIS_COUNT+1;

    StringGridAxis->Cells[0][0] = "No.";
    StringGridAxis->Cells[1][0] = "Axis Name";

    for(int i=0; i < AXIS_COUNT; i++)
    {
    	StringGridAxis->Cells[0][i+1] = IntToStr(i+1);
        StringGridAxis->Cells[1][i+1] = nameIni->ReadString("AXISNAME","AXIS"+IntToStr(i),"");
    }

    delete nameIni;

    this->select_axis(0);
}
//---------------------------------------------------------------------------
void	TFrmCommonSet::select_axis(int index)
{
	StringGridPosition->Tag = index;

    String fileName = ExtractFilePath(Application->ExeName)+ "\\ini\\MotorIndexName.ini";
	TIniFile* nameIni  = new TIniFile(fileName);

    StringGridPosition->RowCount = INDEX_COUNT+1;

    StringGridPosition->Cells[0][0] = "Index";
    StringGridPosition->Cells[1][0] = "Position Name";
    StringGridPosition->Cells[2][0] = "Common";

    for(int i=0; i < INDEX_COUNT; i++)
    {
    	StringGridPosition->Cells[0][i+1] = IntToStr(i+1);
        StringGridPosition->Cells[1][i+1] = nameIni->ReadString("INDEXNAME"+IntToStr(index),"INDEXNAME"+IntToStr(i),"");
        String strFlag = "NO";
        if(nameIni->ReadBool("INDEXNAME"+IntToStr(index),"COMMON"+IntToStr(i),true))
        {
        	strFlag = "YES";
        }
        StringGridPosition->Cells[2][i+1] = strFlag;
    }

    delete nameIni;
}
//---------------------------------------------------------------------------
void __fastcall TFrmCommonSet::StringGridAxisSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect)
{
	if(ARow>0 && ARow < AXIS_COUNT+1) this->select_axis(ARow-1);
}
//---------------------------------------------------------------------------
void __fastcall TFrmCommonSet::StringGridPositionDblClick(TObject *Sender)
{
    String fileName = ExtractFilePath(Application->ExeName)+ "\\ini\\MotorIndexName.ini";

	TIniFile* nameIni  = new TIniFile(fileName);

	if(StringGridPosition->Cells[StringGridPosition->Col][StringGridPosition->Row] == "YES")
    {
    	nameIni->WriteBool("INDEXNAME"+IntToStr(StringGridPosition->Tag),"COMMON"+IntToStr(StringGridPosition->Row-1),false);
    }
    else if(StringGridPosition->Cells[StringGridPosition->Col][StringGridPosition->Row] == "NO")
    {
    	nameIni->WriteBool("INDEXNAME"+IntToStr(StringGridPosition->Tag),"COMMON"+IntToStr(StringGridPosition->Row-1),true);
    }

    delete nameIni;
    select_axis(StringGridPosition->Tag);
}
//---------------------------------------------------------------------------
void __fastcall TFrmCommonSet::StringGridPositionDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State)
{
//
	if(ARow == 0)
	{
		StringGridPosition->Canvas->Brush->Color = clBtnFace;
		StringGridPosition->Canvas->Font->Color = clBlack;
	}
	else
	{
		if(ACol == 0)
		{
			StringGridPosition->Canvas->Brush->Color = clBtnFace;
			StringGridPosition->Canvas->Font->Color = clBlack;
		}
		else
		{
			StringGridPosition->Canvas->Brush->Color = clWhite;
			StringGridPosition->Canvas->Font->Color = clBlack;

			if(StringGridPosition->Cells[2][ARow] == "YES")
			{
				StringGridPosition->Canvas->Brush->Color = clMoneyGreen;
				StringGridPosition->Canvas->Font->Color = clGreen;
			}
		}

	}
	StringGridPosition->Canvas->FillRect(StringGridPosition->CellRect(ACol,ARow));
	DrawText(	StringGridPosition->Canvas->Handle,
				StringGridPosition->Cells[ACol][ARow].c_str(),
				StringGridPosition->Cells[ACol][ARow].Length(),
				&Rect,
				DT_CENTER | DT_SINGLELINE | DT_VCENTER);
}
//---------------------------------------------------------------------------
