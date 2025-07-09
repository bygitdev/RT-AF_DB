//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fSetCommonStaubli.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmSetCommonStaubli *frmSetCommonStaubli;

#define INDEX_COUNT 	30
//---------------------------------------------------------------------------
__fastcall TfrmSetCommonStaubli::TfrmSetCommonStaubli(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------//---------------------------------------------------------------------------//---------------------------------------------------------------------------
void __fastcall TfrmSetCommonStaubli::sgIndexDblClick(TObject *Sender)
{
	if(sgIndex->Cells[sgIndex->Col][sgIndex->Row] == "YES")
    {
    	_nameIni->WriteBool("INDEXNAME","COMMON"+IntToStr(sgIndex->Row-1),false);
    }
    else if(sgIndex->Cells[sgIndex->Col][sgIndex->Row] == "NO")
    {
    	_nameIni->WriteBool("INDEXNAME","COMMON"+IntToStr(sgIndex->Row-1),true);
    }

    this->regen();
}
//---------------------------------------------------------------------------
void __fastcall TfrmSetCommonStaubli::sgIndexDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State)
{
//
	if(ARow == 0)
	{
		sgIndex->Canvas->Brush->Color = clBtnFace;
		sgIndex->Canvas->Font->Color = clBlack;
	}
	else
	{
		if(ACol == 0)
		{
			sgIndex->Canvas->Brush->Color = clBtnFace;
			sgIndex->Canvas->Font->Color = clBlack;
		}
		else
		{
			sgIndex->Canvas->Brush->Color = clWhite;
			sgIndex->Canvas->Font->Color = clBlack;

			if(sgIndex->Cells[2][ARow] == "YES")
			{
				sgIndex->Canvas->Brush->Color = clMoneyGreen;
				sgIndex->Canvas->Font->Color = clGreen;
			}
		}

	}
	sgIndex->Canvas->FillRect(sgIndex->CellRect(ACol,ARow));
	DrawText(	sgIndex->Canvas->Handle,
				sgIndex->Cells[ACol][ARow].c_str(),
				sgIndex->Cells[ACol][ARow].Length(),
				&Rect,
				DT_CENTER | DT_SINGLELINE | DT_VCENTER);
}
//---------------------------------------------------------------------------
void TfrmSetCommonStaubli::regen()
{
    sgIndex->RowCount = INDEX_COUNT+1;

    sgIndex->Cells[0][0] = "Index";
    sgIndex->Cells[1][0] = "Position Name";
    sgIndex->Cells[2][0] = "Common";

    for(int i=0; i < INDEX_COUNT; i++)
    {
    	sgIndex->Cells[0][i+1] = IntToStr(i+1);
        sgIndex->Cells[1][i+1] = _nameIni->ReadString("INDEXNAME","INDEXNAME"+IntToStr(i),"");
        String strFlag = "NO";
        if( _nameIni->ReadBool("INDEXNAME","COMMON"+IntToStr(i),true) )
        {
        	strFlag = "YES";
        }
        sgIndex->Cells[2][i+1] = strFlag;
    }
}
void __fastcall TfrmSetCommonStaubli::FormShow(TObject *Sender)
{
    String fileName = ExtractFilePath(Application->ExeName)+ "\\ini\\StaubliIndexName.ini";
	_nameIni  = new TIniFile(fileName);

    this->regen();

}
//---------------------------------------------------------------------------

void __fastcall TfrmSetCommonStaubli::FormClose(TObject *Sender, TCloseAction &Action)
{
	delete _nameIni;
}
//---------------------------------------------------------------------------

