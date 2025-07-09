//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FrmPackageParameterScrn.h"
#include "BaseComm.h"
#include "MainFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TFrmPackageParameter *FrmPackageParameter;

//---------------------------------------------------------------------------
__fastcall TFrmPackageParameter::TFrmPackageParameter(TComponent* Owner)
	: TForm(Owner)
{

	PackageParamGrid->Cells[0][0] = "ID";
    PackageParamGrid->Cells[1][0] = "PARAMETER NAME";
	PackageParamGrid->Cells[2][0] = "SET VALUE";
	PackageParamGrid->Cells[3][0] = "ACT VALUE";
}
//---------------------------------------------------------------------------
void    TFrmPackageParameter::Pacakageparam_Initialize(int nLeftStage)
{
	_nLeftRight_ =  nLeftStage;

	Pacakageparam_Data_read(_nLeftRight_);
	Pacakageparam_SEQ_read(_nLeftRight_);

	PackageParamGrid->Options>>goEditing;
	PackageParamGrid->Options<<goRowSelect;

}
//------------------------------------------------------------------------
bool    TFrmPackageParameter::Pacakageparam_Data_read(int nLeftStage)
{
	int nGrpNo, nRcpNo;
	if(nLeftStage ==  _LEFT_STAGE_) // LeftStage
	{
		nGrpNo = nReadLeftGroupNo();
		nRcpNo = nReadLeftRecipeNo();
    }
    else
	{
		nGrpNo = nReadRightGroupNo();
		nRcpNo = nReadRightRecipeNo();
    }

	TIniFile *PkgParmini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(nGrpNo)+"\\RCP"+IntToStr(nRcpNo)+"\\PkgParam.ini");
    TIniFile *PkgNameini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\PkgName.ini");

    for(int i=0; i<PackageParamGrid->RowCount;i++)
    {
        PackageParamGrid->Cells[0][i+1] = IntToStr(i);
        PackageParamGrid->Cells[1][i+1] = PkgNameini->ReadString("PKGNAME","NAME"+IntToStr(i),"Name"+IntToStr(i));
    }


    if(PkgParmini != NULL)
    {
        for(int i=0; i<PackageParamGrid->RowCount;i++)
        {
            PackageParamGrid->Cells[2][i+1] = PkgParmini->ReadString("PKGPARM","VALUE"+IntToStr(i),IntToStr(i));
		}
		delete 	PkgParmini;
		delete  PkgNameini;
		return true;

	}

	delete 	PkgParmini;
	delete  PkgNameini;
	return false;
}
//------------------------------------------------------------------------
bool    TFrmPackageParameter::Packageparam_Data_save(int nLeftRight)
{
	int nGrpNo, nRcpNo;

	if(nLeftRight ==  _LEFT_STAGE_) // LeftStage
	{
		nGrpNo = nReadLeftGroupNo();
		nRcpNo = nReadLeftRecipeNo();
	}
	else
	{
		nGrpNo = nReadRightGroupNo();
		nRcpNo = nReadRightRecipeNo();
    }

	TIniFile *PkgParmini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(nGrpNo)+"\\RCP"+IntToStr(nRcpNo)+"\\PkgParam.ini");
    TIniFile *PkgNameini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\PkgName.ini");


    for(int i=0; i<PackageParamGrid->RowCount;i++)
    {
    	PkgNameini->WriteString("PKGNAME","NAME"+IntToStr(i),PackageParamGrid->Cells[1][i+1]);
    }


    if(PkgParmini != NULL)
    {
        for(int i=0; i<PackageParamGrid->RowCount;i++)
        {
            PkgParmini->WriteString("PKGPARM","VALUE"+IntToStr(i),PackageParamGrid->Cells[2][i+1]);
		}
		delete PkgParmini;
		delete PkgNameini;
		return true;

    }

	delete PkgParmini;
	delete PkgNameini;
	return false;
}
//------------------------------------------------------------------------
bool    TFrmPackageParameter::Pacakageparam_SEQ_read(int nLeftRight)
{
	if(nLeftRight == _LEFT_STAGE_) //left
    {
        for(int i=0; i<PackageParamGrid->RowCount;i++)
        {
            PackageParamGrid->Cells[ 3 ][ i+1 ] = FloatToStr( g_pNvMem->GetPkgL( i ));
        }
    }
    else
    {
        for(int i=0; i<PackageParamGrid->RowCount;i++)
        {
            PackageParamGrid->Cells[ 3 ][ i+1 ] = FloatToStr( g_pNvMem->GetPkgR( i ) );
        }
    }
}
//------------------------------------------------------------------------
bool    TFrmPackageParameter::Pacakageparam_SEQ_save(int nLeftRight)
{
	if(nLeftRight == _LEFT_STAGE_) //left
    {
        for(int i=0; i<PackageParamGrid->RowCount;i++)
        {
            DOUBLE dData = StrToFloat( PackageParamGrid->Cells[ 2 ][ i+1 ] );
            g_pNvMem->SetPkgL(i, dData);
        }
    }
    else
    {
        for(int i=0; i<PackageParamGrid->RowCount;i++)
        {
            DOUBLE dData = StrToFloat( PackageParamGrid->Cells[ 2 ][ i+1 ] );
            g_pNvMem->SetPkgR(i, dData);
        }
    }

}
//------------------------------------------------------------------------

void __fastcall TFrmPackageParameter::BtnParamIndexMoveP10Click(TObject *Sender)
{
	if(PackageParamGrid->TopRow <= 490)
    {
    	PackageParamGrid->TopRow += 9;
    }
    else
    {
    	PackageParamGrid->TopRow = 499;
    }
}
//---------------------------------------------------------------------------

void __fastcall TFrmPackageParameter::BtnParamIndexMoveM10Click(TObject *Sender)
{
	if(PackageParamGrid->TopRow >= 10)
	{
		PackageParamGrid->TopRow = PackageParamGrid->TopRow - 9;
	}
	else
	{
		PackageParamGrid->TopRow = 1;
	}
}
//---------------------------------------------------------------------------


void __fastcall TFrmPackageParameter::BtnInputMotionDataClick(TObject *Sender)
{
	PackageParamGrid->Options<<goEditing;
	PackageParamGrid->Options>>goRowSelect;

	BtnInputMotionData->Enabled = false;
    BtnSaveMotionData->Enabled = true;

}
//---------------------------------------------------------------------------

void __fastcall TFrmPackageParameter::BtnSaveMotionDataClick(TObject *Sender)
{
	PackageParamGrid->Options>>goEditing;
	PackageParamGrid->Options<<goRowSelect;

	BtnInputMotionData->Enabled = true;
    BtnSaveMotionData->Enabled = false;

//    Packageparam_Data_save(_nLeftRight_);
//    Pacakageparam_SEQ_save(_nLeftRight_);
//    Pacakageparam_Data_read(_nLeftRight_);
//    Pacakageparam_SEQ_read(_nLeftRight_);

    if(Recipe_dataBothsidecheck() == true)
    {
    	Packageparam_Data_save(_LEFT_STAGE_);
    	Packageparam_Data_save(_RIGHT_STAGE_);
    	Pacakageparam_SEQ_save(_LEFT_STAGE_);
    	Pacakageparam_SEQ_save(_RIGHT_STAGE_);

     	if(_nLeftRight_ == _LEFT_STAGE_)
		{
			if((TFrmPackageParameter*)MainFrmForm->pStage2SubFrm[1] != NULL)
			{
				((TFrmPackageParameter*)MainFrmForm->pStage2SubFrm[1])->Pacakageparam_Data_read(_RIGHT_STAGE_);
				((TFrmPackageParameter*)MainFrmForm->pStage2SubFrm[1])->Pacakageparam_SEQ_read(_RIGHT_STAGE_);
			}
		}
		else
		{
			if((TFrmPackageParameter*)MainFrmForm->pStage1SubFrm[1] != NULL)
			{
				((TFrmPackageParameter*)MainFrmForm->pStage1SubFrm[1])->Pacakageparam_Data_read(_LEFT_STAGE_);
				((TFrmPackageParameter*)MainFrmForm->pStage1SubFrm[1])->Pacakageparam_SEQ_read(_LEFT_STAGE_);
			}
        }

    }
    else
	{
		Packageparam_Data_save(_nLeftRight_);
		Pacakageparam_SEQ_save(_nLeftRight_);
    }

	Pacakageparam_Data_read(_nLeftRight_);
	Pacakageparam_SEQ_read(_nLeftRight_);
}
//---------------------------------------------------------------------------

void __fastcall TFrmPackageParameter::SpeedButton1Click(TObject *Sender)
{
    FrmHelp->PageControl1->ActivePage = FrmHelp->TabSheetNormal;
	FrmHelp->ShowModal();
}
//---------------------------------------------------------------------------

