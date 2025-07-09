//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CommonRCPSaveScrn.h"
#include "BaseComm.h"
#include "FrmRecipeControlScrn.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrmCommonRcpSave *FrmCommonRcpSave;
//---------------------------------------------------------------------------
__fastcall TFrmCommonRcpSave::TFrmCommonRcpSave(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFrmCommonRcpSave::FormShow(TObject *Sender)
{
    CommonRCPGrid->Cells[0][0] = "No.";
    CommonRCPGrid->Cells[1][0] = "Name";

    for(int i=1; i<CommonRCPGrid->RowCount+1; i++)
    {
        CommonRCPGrid->Cells[0][i] = IntToStr(i);
	}
	FormInitialize();
}
//---------------------------------------------------------------------------

void __fastcall TFrmCommonRcpSave::FormInitialize()
{
	TIniFile *IniGroup = new TIniFile(ExtractFilePath(Application->ExeName) + "\\ini\\GroupName.ini");
	if(FileExists(ExtractFilePath(Application->ExeName) + "\\ini\\GroupName.ini"))
	{
		for(int i=0; i<CommonRCPGrid->RowCount+1; i++)
		{
			CommonRCPGrid->Cells[1][i+1]= IniGroup->ReadString("GROUP", "NAME"+IntToStr(i+1), "");
		}
	}
	delete IniGroup;
}
//---------------------------------------------------------------------------

void __fastcall TFrmCommonRcpSave::SavePKGDataRoutine()
{
	TIniFile *IniGroup = new TIniFile(ExtractFilePath(Application->ExeName) + "\\ini\\GroupName.ini");
	if(FileExists(ExtractFilePath(Application->ExeName) + "\\ini\\GroupName.ini"))
	{
		for(int i=0; i<CommonRCPGrid->RowCount+1; i++)
		{
			IniGroup->WriteString("GROUP", "NAME"+IntToStr(i+1), CommonRCPGrid->Cells[1][i+1]);
		}
	}
	delete IniGroup;
	MessageDlg("Success save to data!", mtInformation, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------

void __fastcall TFrmCommonRcpSave::BtnCommonRCPSaveClick(TObject *Sender)
{
	SavePKGDataRoutine();
}
//---------------------------------------------------------------------------

void __fastcall TFrmCommonRcpSave::BtnCommonRCPExitClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TFrmCommonRcpSave::CommonRCPCodeUpClick(TObject *Sender)
{
    if(CommonRCPGrid->TopRow >= 8)
    {
        CommonRCPGrid->TopRow = CommonRCPGrid->TopRow - 8;
    }
    else
    {
        CommonRCPGrid->TopRow = 1;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmCommonRcpSave::CommonRCPCodeDownClick(TObject *Sender)
{
    if(CommonRCPGrid->TopRow <= 92)
    {
        CommonRCPGrid->TopRow = CommonRCPGrid->TopRow + 8;
    }
    else
    {
        CommonRCPGrid->TopRow = 99;
	}
}
//---------------------------------------------------------------------------

