//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormPkgParamScrn.h"
#include "FormNumberKeyPadScrn.h"
//---------------------------------------------------------------------------
#include "BaseComm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma resource "*.dfm"
TFormPkgParam *FormPkgParam;
//---------------------------------------------------------------------------
__fastcall TFormPkgParam::TFormPkgParam(TComponent* Owner)
	: TForm(Owner)
{
    PkgParamGrid->Cells[0][0] = "NO";
    PkgParamGrid->Cells[1][0] = "NAME";
    PkgParamGrid->Cells[2][0] = "SET";
    PkgParamGrid->Cells[3][0] = "ACT";
}
//---------------------------------------------------------------------------
void TFormPkgParam::PkgParam_Initialize()
{
    PkgParamGrid->Options>>goEditing;
    PkgParamGrid->Options<<goRowSelect;

    BtnInputItem->Enabled = true;
    BtnSaveItem->Enabled = false;

	this->PkgDataIni_name_read();
    this->PkgDataSeq_Read();
}
//---------------------------------------------------------------------------
void __fastcall TFormPkgParam::BtnPkgPass1Click(TObject *Sender)
{
    int nSelectIndex = dynamic_cast<TSpeedButton*>(Sender)->Tag;

	for(int nIndex=0; nIndex<11; nIndex++)
	{
		TSpeedButton* ClonePassBtn = (TSpeedButton*)FindComponent("BtnPkgPass" + IntToStr(nIndex));

        if(nSelectIndex == (nIndex))
        {
			ClonePassBtn->Enabled = false;
        }
        else
        {
			ClonePassBtn->Enabled = true;
        }
	}

    if(nSelectIndex > 0)
    {
    	PkgParamGrid->TopRow  = nSelectIndex * 100;
    }
    else
    {
		PkgParamGrid->TopRow = 1;
    }
    PkgParamGrid->Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TFormPkgParam::BtnInputItemClick(TObject *Sender)
{
    BtnInputItem->Enabled = false;
    BtnSaveItem->Enabled = true;

    PkgParamGrid->Options<<goEditing;
    PkgParamGrid->Options>>goRowSelect;
}
//---------------------------------------------------------------------------
void __fastcall TFormPkgParam::BtnSaveItemClick(TObject *Sender)
{
    BtnInputItem->Enabled = true;
    BtnSaveItem->Enabled = false;

    PkgParamGrid->Options>>goEditing;
    PkgParamGrid->Options<<goRowSelect;

    PkgDataSeq_Write();
    PkgDataIni_name_save();
    PkgDataIni_name_read();
    PkgDataSeq_Read();

    FrmCdBox->QueryMsg("MOTOR SEQ READ OK", "PACKAGE DATA SAVE COMPLETE!", CD_OK );
}
//---------------------------------------------------------------------------
void __fastcall TFormPkgParam::BtnParamIndexMoveM10Click(TObject *Sender)
{
	if(PkgParamGrid->TopRow >= 12)
	{
		PkgParamGrid->TopRow = PkgParamGrid->TopRow - 12;
	}
	else
	{
		PkgParamGrid->TopRow = 1;
	}

    EditParamIndex->Text = IntToStr(PkgParamGrid->TopRow);
}
//---------------------------------------------------------------------------
void __fastcall TFormPkgParam::BtnParamIndexMoveP10Click(TObject *Sender)
{
	if(PkgParamGrid->TopRow <= 1000)
    {
    	PkgParamGrid->TopRow += 12;
    }
    else
    {
    	PkgParamGrid->TopRow = 999;
    }
    EditParamIndex->Text = IntToStr(PkgParamGrid->TopRow);
}

//---------------------------------------------------------------------------
bool    TFormPkgParam::PkgDataIni_name_read()
{
	int nGrpNo, nRcpNo;
    nGrpNo = nReadGroupNo();
    nRcpNo = nReadRecipeNo();

	TIniFile *PkgParmini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(nGrpNo)+"\\RCP"+IntToStr(nRcpNo)+"\\PkgParam.ini");
    TIniFile *PkgNameini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\PkgName.ini");

    for(int i=0; i<PkgParamGrid->RowCount;i++)
    {
        PkgParamGrid->Cells[0][i+1] =  IntToStr(i);
        PkgParamGrid->Cells[1][i+1] = PkgNameini->ReadString("PKGNAME","NAME"+IntToStr(i),"Name"+IntToStr(i));

        PkgParamGrid->Cells[2][i+1] = PkgParmini->ReadString("PKGPARM","VALUE"+IntToStr(i),IntToStr(i));
    }
    delete PkgParmini;
    delete PkgNameini;
    return true;
}
//------------------------------------------------------------------------
bool    TFormPkgParam::PkgDataIni_name_save()
{
	int nGrpNo, nRcpNo;

    nGrpNo = nReadGroupNo();
    nRcpNo = nReadRecipeNo();


	TIniFile *PkgParmini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(nGrpNo)+"\\RCP"+IntToStr(nRcpNo)+"\\PkgParam.ini");
    TIniFile *PkgNameini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\PkgName.ini");


    for(int i=0; i<PkgParamGrid->RowCount;i++)
    {
    	PkgNameini->WriteString("PKGNAME","NAME"+IntToStr(i),PkgParamGrid->Cells[1][i+1]);
    }

    for(int i=0; i<PkgParamGrid->RowCount;i++)
    {
        PkgParmini->WriteString("PKGPARM","VALUE"+IntToStr(i),PkgParamGrid->Cells[2][i+1]);
    }

	delete PkgParmini;
	delete PkgNameini;

    return true;

}
//------------------------------------------------------------------------
bool    TFormPkgParam::PkgDataSeq_Read()
{
    for(int i=0; i<PkgParamGrid->RowCount; i++)
    {
//        PkgParamGrid->Cells[3][i+1]= FloatToStr( g_pNvMem->GetPkg( i ) );
    }
}
//------------------------------------------------------------------------
bool    TFormPkgParam::PkgDataSeq_Write()
{
    g_MMIComm->m_mmiToSeq.buffer.pkg.nStart = 0;
    g_MMIComm->m_mmiToSeq.buffer.pkg.nEnd  = PkgParamGrid->RowCount;

    for(int i=0; i<PkgParamGrid->RowCount;i++)
    {
        if(PkgParamGrid->Cells[ 2 ][ i+1 ]  == "")
        {
            PkgParamGrid->Cells[ 2 ][ i+1 ]  = "0";
        }

        g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[i] = StrToFloat( PkgParamGrid->Cells[ 2 ][ i+1 ] );
    }

    g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_PKG;

    if(g_MMIComm->Send() && g_MMIComm->Recv())
    {
        return true;
    }
    else
    {
        return false;
    }

}
//------------------------------------------------------------------------

void __fastcall TFormPkgParam::BtnNdmKeyPadClick(TObject *Sender)
{
	FormNumberKeyPad->ShowModal();

    EditParamIndex->Text =  FormNumberKeyPad->GetKeyNumber();
    if(EditParamIndex->Text == "")
    {
        EditParamIndex->Text = "0";
    }
    PkgParamGrid->TopRow = EditParamIndex->Text.ToInt();

}
//---------------------------------------------------------------------------

void __fastcall TFormPkgParam::EditParamIndexKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)

{
	if(Key == vkReturn)
    {
        PkgParamGrid->TopRow = EditParamIndex->Text.ToInt();
    }
}
//---------------------------------------------------------------------------

