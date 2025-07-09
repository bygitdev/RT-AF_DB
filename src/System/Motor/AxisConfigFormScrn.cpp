//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AxisConfigFormScrn.h"
#include "BaseComm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma resource "*.dfm"
TMotorAxisConfig *MotorAxisConfig;
//---------------------------------------------------------------------------
__fastcall TMotorAxisConfig::TMotorAxisConfig(TComponent* Owner)
	: TForm(Owner)
{
    StringGridAxis->Cells[0][0] = "No.";
    StringGridAxis->Cells[1][0] = "Axis Name";
    StringGridAxis->Cells[2][0] = "Jog Name";
    StringGridAxis->Cells[3][0] = "Jog Direct";

    StringGridAxis->Options>>goEditing;
    StringGridAxis->Options<<goRowSelect;
}
//---------------------------------------------------------------------------
void __fastcall TMotorAxisConfig::BtnCloseClick(TObject *Sender)
{
	 this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TMotorAxisConfig::FormShow(TObject *Sender)
{
	StringGridAxis->RowCount = MAX_MT_NO;
	MotorRecipeSet_Read();
}
//---------------------------------------------------------------------------
void TMotorAxisConfig::MotorRecipeSet_Read()
{
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\MotorName.ini"))
	{
		TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\MotorName.ini");
        for( int nAxisIndex = 0; nAxisIndex < MAX_MT_NO; nAxisIndex++ )
        {
    		StringGridAxis->Cells[0][nAxisIndex+1] = IntToStr(nAxisIndex);
            StringGridAxis->Cells[1][nAxisIndex+1] = ini->ReadString("AXISNAME","AXIS"+IntToStr(nAxisIndex),"AXISNAME"+IntToStr(nAxisIndex));
            String StrCaption = ini->ReadString("AXISSET","JOGNAME"+IntToStr(nAxisIndex),"X");
            StringGridAxis->Cells[2][nAxisIndex+1] = StrCaption.UpperCase();
            StringGridAxis->Cells[3][nAxisIndex+1] = ini->ReadString("AXISSET","DIRECT"+IntToStr(nAxisIndex),"1");
        }
        delete ini;
    }
}
//---------------------------------------------------------------------------

void __fastcall TMotorAxisConfig::BtnInputItemClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;
	BtnInputItem->Enabled = false;
    BtnSaveItem->Enabled = true;

    StringGridAxis->Options<<goEditing;
    StringGridAxis->Options>>goRowSelect;
    StringGridAxis->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TMotorAxisConfig::BtnSaveItemClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;
	BtnInputItem->Enabled = true;
    BtnSaveItem->Enabled = false;

    TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\MotorName.ini");
    for( int nAxisIndex = 0; nAxisIndex < MAX_MT_NO; nAxisIndex++ )
    {

        ini->WriteString("AXISNAME","AXIS"+IntToStr(nAxisIndex),StringGridAxis->Cells[1][nAxisIndex+1]);

    	String strTemp = StringGridAxis->Cells[2][nAxisIndex+1].UpperCase().Trim();
//        if(strTemp != "X" && strTemp != "Y" && strTemp != "Z")
//        {
//			strTemp = "X";
//        }
        ini->WriteString("AXISSET","JOGNAME"+IntToStr(nAxisIndex),strTemp);

    	String strTemp1 = StringGridAxis->Cells[3][nAxisIndex+1].UpperCase().Trim();
//        if(strTemp1 != "0" && strTemp1 != "1")
//        {
//			strTemp1 = "1";
//        }
        ini->WriteString("AXISSET","DIRECT"+IntToStr(nAxisIndex),strTemp1);
    }
    delete ini;


	MotorRecipeSet_Read();
}
//---------------------------------------------------------------------------



void __fastcall TMotorAxisConfig::StringGridAxisKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift)
{
    String strTemp = StringGridAxis->Cells[2][StringGridAxis->Row].UpperCase().Trim();
    if(strTemp != "X" && strTemp != "Y" && strTemp != "Z")
    {
        StringGridAxis->Cells[2][StringGridAxis->Row] = "X";
    }
    else
    {
        StringGridAxis->Cells[2][StringGridAxis->Row] = strTemp.UpperCase().Trim();
    }

    String strTemp1 = StringGridAxis->Cells[3][StringGridAxis->Row].UpperCase().Trim();
    if(strTemp1 != "0" && strTemp1 != "1")
    {
        StringGridAxis->Cells[3][StringGridAxis->Row] = "0";
    }
    else
    {
        StringGridAxis->Cells[3][StringGridAxis->Row] = strTemp1.UpperCase().Trim();
    }
    StringGridAxis->Refresh();
}
//---------------------------------------------------------------------------

