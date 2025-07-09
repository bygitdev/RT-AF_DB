//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TeachingPointFormScrn.h"
#include "BaseComm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma resource "*.dfm"
TTeachingPointForm *TeachingPointForm;

#define   _STAGE_PALLET1_START_INDEX1_         900
#define   _STAGE_PALLET1_START_INDEX2_         910
#define   _PALLET_CONTROL_UNIT_                  8

#define   _STAGE_TRAY_START_INDEX1_             940
#define   _STAGE_TRAY_START_INDEX2_             950
#define   _TRAY_CONTROL_UNIT_                    8
//---------------------------------------------------------------------------
__fastcall TTeachingPointForm::TTeachingPointForm(TComponent* Owner)
	: TForm(Owner)
{

	PalletTeachGrid->Cells[0][0] = "NO";
	PalletTeachGrid->Cells[1][0] = "ITEM NAME";
	PalletTeachGrid->Cells[2][0] = "SET";
	PalletTeachGrid->Cells[3][0] = "ACT";

	TrayTeachGrid->Cells[0][0] = "NO";
	TrayTeachGrid->Cells[1][0] = "ITEM NAME";
	TrayTeachGrid->Cells[2][0] = "SET";
	TrayTeachGrid->Cells[3][0] = "ACT";

}
//---------------------------------------------------------------------------
void TTeachingPointForm::PalletData_Initialize(int nIndex)
{
    BtnPallet1->Enabled = true;
    BtnPallet2->Enabled = true;

    TBitBtn *SubCloneBtn = (TBitBtn *)FindComponent("BtnPallet"+IntToStr(nIndex+1));
    SubCloneBtn->Enabled = false;
	_nPalletStage_   =  nIndex;
	PalletData_Read(_nPalletStage_);
}
//---------------------------------------------------------------------------
void TTeachingPointForm::TrayData_Initialize(int nIndex)
{
    BtnTraySet1->Enabled = true;
    BtnTraySet2->Enabled = true;
    BtnTraySet3->Enabled = true;

    TBitBtn *SubCloneBtn = (TBitBtn *)FindComponent("BtnTraySet"+IntToStr(nIndex+1));
    SubCloneBtn->Enabled = false;
	_nTrayStage_ = nIndex;
	TrayData_Read(_nTrayStage_);
}
//---------------------------------------------------------------------------

void TTeachingPointForm::PalletData_Read(int nStage)
{
	int nGrpNo, nRcpNo;
    nGrpNo = nReadGroupNo();
    nRcpNo = nReadRecipeNo();

    TIniFile *PkgParmini = new TIniFile(ExtractFilePath(Application->ExeName)+ "Ini\\system\\GRP"+IntToStr(nGrpNo)+"\\RCP"+IntToStr(nRcpNo)+"\\PkgParam.ini");
    TIniFile *PkgNameini = new TIniFile(ExtractFilePath(Application->ExeName)+ "Ini\\PkgName.ini");

    int nNumber ;
	for(int i=0; i<_PALLET_CONTROL_UNIT_*2; i++)
	{
    	if(i >= _PALLET_CONTROL_UNIT_)
        {
         	nNumber = (_STAGE_PALLET1_START_INDEX2_+ (i -_PALLET_CONTROL_UNIT_))  + (nStage * 20);
        }
        else
        {
            nNumber = (_STAGE_PALLET1_START_INDEX1_ + i) + (nStage * 20);
		}

        PalletTeachGrid->Cells[0][i+1] =  IntToStr(i);
        PalletTeachGrid->Cells[1][i+1] = PkgNameini->ReadString("PKGNAME","NAME"+IntToStr(nNumber),"Name"+IntToStr(nNumber));
        PalletTeachGrid->Cells[2][i+1] = PkgParmini->ReadString("PKGPARM","VALUE"+IntToStr(nNumber),IntToStr(nNumber));
      //  PalletTeachGrid->Cells[3][i+1]= FloatToStr( g_pNvMem->GetPkg(nNumber));

    }
    PalletTeachGrid->Refresh();
    delete PkgParmini;
    delete PkgNameini;

}
//---------------------------------------------------------------------------
void    TTeachingPointForm::PalletData_Save(int nStage)
{
	int nGrpNo, nRcpNo;
    nGrpNo = nReadGroupNo();
    nRcpNo = nReadRecipeNo();

    TIniFile *PkgParmini = new TIniFile(ExtractFilePath(Application->ExeName)+ "Ini\\system\\GRP"+IntToStr(nGrpNo)+"\\RCP"+IntToStr(nRcpNo)+"\\PkgParam.ini");
    TIniFile *PkgNameini = new TIniFile(ExtractFilePath(Application->ExeName)+ "Ini\\PkgName.ini");

	for(int i=0; i<_PALLET_CONTROL_UNIT_*2; i++)
	{
        if(PalletTeachGrid->Cells[ 2 ][ i+1 ]  == "")
        {
            PalletTeachGrid->Cells[ 2 ][ i+1 ]  = "0";
        }

        int nNumber;
    	if(i >= _PALLET_CONTROL_UNIT_)
        {
         	nNumber = (_STAGE_PALLET1_START_INDEX2_+ (i -_PALLET_CONTROL_UNIT_))  + (nStage * 20);

        }
        else
        {
            nNumber = (_STAGE_PALLET1_START_INDEX1_ + i) + (nStage * 20);
		}

        PkgNameini->WriteString("PKGNAME","NAME"+IntToStr(nNumber), PalletTeachGrid->Cells[1][i+1]);
        PkgParmini->WriteString("PKGPARM","VALUE"+IntToStr(nNumber), PalletTeachGrid->Cells[2][i+1]);

        DOUBLE dData = StrToFloat( PalletTeachGrid->Cells[ 2 ][ i+1 ] );
        WriteCommPKG(nNumber, dData);
	}

    delete PkgParmini;
    delete PkgNameini;
}
//------------------------------------------------------------------------

void TTeachingPointForm::TrayData_Read(int nStage)
{
	int nGrpNo, nRcpNo;
    nGrpNo = nReadGroupNo();
    nRcpNo = nReadRecipeNo();
	TIniFile *PkgParmini = new TIniFile(ExtractFilePath(Application->ExeName)+ "Ini\\system\\GRP"+IntToStr(nGrpNo)+"\\RCP"+IntToStr(nRcpNo)+"\\PkgParam.ini");
    TIniFile *PkgNameini = new TIniFile(ExtractFilePath(Application->ExeName)+ "Ini\\PkgName.ini");

    int nNumber ;
	for(int i=0; i<_TRAY_CONTROL_UNIT_*2; i++)
	{
    	if(i >= _TRAY_CONTROL_UNIT_)
        {
         	nNumber = (_STAGE_TRAY_START_INDEX2_+ (i -_TRAY_CONTROL_UNIT_))  + (nStage * 20);

        }
        else
        {
            nNumber = (_STAGE_TRAY_START_INDEX1_ + i) + (nStage * 20);
		}
        TrayTeachGrid->Cells[0][i+1] =  IntToStr(i);
        TrayTeachGrid->Cells[1][i+1] = PkgNameini->ReadString("PKGNAME","NAME"+IntToStr(nNumber),"Name"+IntToStr(nNumber));
        TrayTeachGrid->Cells[2][i+1] = PkgParmini->ReadString("PKGPARM","VALUE"+IntToStr(nNumber),IntToStr(nNumber));
      //	TrayTeachGrid->Cells[3][i+1]= FloatToStr( g_pNvMem->GetPkg(nNumber));
    }
    delete PkgParmini;
    delete PkgNameini;

}
//---------------------------------------------------------------------------

void    TTeachingPointForm::TrayData_Save(int nStage)
{
	int nGrpNo, nRcpNo;
    nGrpNo = nReadGroupNo();
    nRcpNo = nReadRecipeNo();
	TIniFile *PkgParmini = new TIniFile(ExtractFilePath(Application->ExeName)+ "Ini\\system\\GRP"+IntToStr(nGrpNo)+"\\RCP"+IntToStr(nRcpNo)+"\\PkgParam.ini");
    TIniFile *PkgNameini = new TIniFile(ExtractFilePath(Application->ExeName)+ "Ini\\PkgName.ini");

    int nNumber ;
	for(int i=0; i<_TRAY_CONTROL_UNIT_*2; i++)
	{
    	if(i >= _TRAY_CONTROL_UNIT_)
        {
         	nNumber = (_STAGE_TRAY_START_INDEX2_+ (i -_TRAY_CONTROL_UNIT_))  + (nStage * 20);

        }
        else
        {
            nNumber = (_STAGE_TRAY_START_INDEX1_ + i) + (nStage * 20);
		}

        PkgNameini->WriteString("PKGNAME","NAME"+IntToStr(nNumber), TrayTeachGrid->Cells[1][i+1]);
        PkgParmini->WriteString("PKGPARM","VALUE"+IntToStr(nNumber), TrayTeachGrid->Cells[2][i+1]);

        DOUBLE dData = StrToFloat( TrayTeachGrid->Cells[ 2 ][ i+1 ] );
        WriteCommPKG(nNumber, dData);

    }
    delete PkgParmini;
    delete PkgNameini;
}
//------------------------------------------------------------------------
void __fastcall TTeachingPointForm::BtnInputItemClick(TObject *Sender)
{
    BtnInputItem->Enabled = false;
    BtnSaveItem->Enabled = true;

    PalletTeachGrid->Options<<goEditing;
    PalletTeachGrid->Options>>goRowSelect;
}
//---------------------------------------------------------------------------

void __fastcall TTeachingPointForm::BtnSaveItemClick(TObject *Sender)
{
    BtnInputItem->Enabled = true;
    BtnSaveItem->Enabled = false;

    PalletTeachGrid->Options>>goEditing;
    PalletTeachGrid->Options<<goRowSelect;

    this->PalletData_Save(_nPalletStage_);
    this->PalletData_Read(_nPalletStage_);
}
//---------------------------------------------------------------------------

void __fastcall TTeachingPointForm::BtnTrayInputClick(TObject *Sender)
{
    BtnTrayInput->Enabled = false;
    BtnTraySave->Enabled = true;

    TrayTeachGrid->Options<<goEditing;
    TrayTeachGrid->Options>>goRowSelect;
}
//---------------------------------------------------------------------------

void __fastcall TTeachingPointForm::BtnTraySaveClick(TObject *Sender)
{
    BtnTrayInput->Enabled = true;
    BtnTraySave->Enabled = false;

    TrayTeachGrid->Options>>goEditing;
    TrayTeachGrid->Options<<goRowSelect;

    this->TrayData_Save(_nTrayStage_);
    this->TrayData_Read(_nTrayStage_);
}
//---------------------------------------------------------------------------

void __fastcall TTeachingPointForm::BtnPallet1Click(TObject *Sender)
{
	this->PalletData_Initialize(dynamic_cast<TBitBtn *>(Sender)->Tag);
}
//---------------------------------------------------------------------------

void __fastcall TTeachingPointForm::BtnTraySet1Click(TObject *Sender)
{
	this->TrayData_Initialize(dynamic_cast<TBitBtn *>(Sender)->Tag);
}
//---------------------------------------------------------------------------

