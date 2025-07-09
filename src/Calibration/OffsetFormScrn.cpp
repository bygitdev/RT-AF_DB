//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "OffsetFormScrn.h"
#include "BaseComm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma resource "*.dfm"
TOffsetForm *OffsetForm;


#define   _STAGE_OFFSET_START_INDEX_         300
#define   _OFFSET_CONTROL_UNIT_               15
//---------------------------------------------------------------------------
__fastcall TOffsetForm::TOffsetForm(TComponent* Owner)
	: TForm(Owner)
{
	StageGridOffset->Cells[0][0] = "NO";
	StageGridOffset->Cells[1][0] = "ITEM NAME";
	StageGridOffset->Cells[2][0] = "SET";
	StageGridOffset->Cells[3][0] = "ACT";
}
//---------------------------------------------------------------------------
void TOffsetForm::OffsetData_Initialize(int nStage)
{
    BtnOffsetStage1->Enabled = true;
    BtnOffsetStage2->Enabled = true;
    BtnOffsetStage3->Enabled = true;
    BtnOffsetStage4->Enabled = true;

	LabelOffsetIndicator->Caption = "STAGE" + IntToStr(nStage+1) + "OFFSET";

    TBitBtn *SubCloneBtn = (TBitBtn *)FindComponent("BtnOffsetStage"+IntToStr(nStage+1));
    SubCloneBtn->Enabled = false;

	OffsetData_Read(nStage);
}
//---------------------------------------------------------------------------
void __fastcall TOffsetForm::BtnOffsetStage1Click(TObject *Sender)
{
	OffsetData_Initialize(dynamic_cast<TBitBtn *>(Sender)->Tag);
}
//---------------------------------------------------------------------------

void TOffsetForm::OffsetData_Read(int nStage)
{
	int nGrpNo, nRcpNo;
    nGrpNo = nReadGroupNo();
    nRcpNo = nReadRecipeNo();


	for(int i=0; i<_OFFSET_CONTROL_UNIT_; i++)
	{
//  	StageGridOffset->Cells[3][i+1]= FloatToStr( g_pNvMem->GetPkg(_STAGE_OFFSET_START_INDEX_ + i) + (nStage * 30));
	}

	TIniFile *PkgParmini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(nGrpNo)+"\\RCP"+IntToStr(nRcpNo)+"\\PkgParam.ini");
    TIniFile *PkgNameini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\PkgName.ini");

	for(int i=0; i<_OFFSET_CONTROL_UNIT_; i++)
	{
        StageGridOffset->Cells[0][i+1] =  IntToStr(i);
        StageGridOffset->Cells[1][i+1] = PkgNameini->ReadString("PKGNAME","NAME"+IntToStr(i),"Name"+IntToStr(i));

        StageGridOffset->Cells[2][i+1] = PkgParmini->ReadString("PKGPARM","VALUE"+IntToStr(i),IntToStr(i));
    }
    delete PkgParmini;
    delete PkgNameini;

}
//---------------------------------------------------------------------------
void    TOffsetForm::OffsetData_Save(int nStage)
{
    g_MMIComm->m_mmiToSeq.buffer.pkg.nStart = (_STAGE_OFFSET_START_INDEX_) + (nStage * 30);
    g_MMIComm->m_mmiToSeq.buffer.pkg.nEnd  = (_STAGE_OFFSET_START_INDEX_ + _OFFSET_CONTROL_UNIT_) + (nStage * 30);

	for(int i=0; i<_OFFSET_CONTROL_UNIT_; i++)
	{
        if(StageGridOffset->Cells[ 2 ][ i+1 ]  == "")
        {
            StageGridOffset->Cells[ 2 ][ i+1 ]  = "0";
        }

        g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[i] = StrToFloat( StageGridOffset->Cells[ 2 ][ i+1 ] );
    }

    g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_PKG;

    if(g_MMIComm->Send() && g_MMIComm->Recv())
    {

    }
    else
    {

    }
}
//------------------------------------------------------------------------


void __fastcall TOffsetForm::BtnInputItemClick(TObject *Sender)
{
    BtnInputItem->Enabled = false;
    BtnSaveItem->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TOffsetForm::BtnSaveItemClick(TObject *Sender)
{
    BtnInputItem->Enabled = true;
    BtnSaveItem->Enabled = false;

    StageGridOffset->Options>>goEditing;
    StageGridOffset->Options<<goRowSelect;
    this->OffsetData_Save(_nStageNumber_);

    this->OffsetData_Read(_nStageNumber_);

}
//---------------------------------------------------------------------------

