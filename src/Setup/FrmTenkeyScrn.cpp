//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FrmTenkeyScrn.h"
#include "BaseComm.h"
#include "cdbox.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvPicture"
#pragma link "CurvyControls"
#pragma link "Shader"
#pragma resource "*.dfm"
TFrmTenkey *FrmTenkey;

#define	_MAX_PARENT_TENKEYCOUNT_     30
#define _MAX_CHILD_TENKEYCOUNT_      50

#define _DM_TENKEY_RUNNING_            99

//---------------------------------------------------------------------------
__fastcall TFrmTenkey::TFrmTenkey(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFrmTenkey::FormShow(TObject *Sender)
{
    TenkeyScrnInitial();
    ParentTenkeyLoad();
    ChildTenkeyLoad(1);
	g_nTenkeyPartNo = 1;
}
//---------------------------------------------------------------------------


void __fastcall TFrmTenkey::TenkeyScrnInitial()
{
	ParentGrid->Cells[0][0] = "PART NAME";

    ChildGrid->Cells[0][0] = "NO";
    ChildGrid->Cells[1][0] = "NAME";
    ChildGrid->Cells[2][0] = "HOME";
    ChildGrid->Cells[3][0] = "STEP";
}
//---------------------------------------------------------------------------

String	TFrmTenkey::getTenKeyName(int nTenkeyNo)
{
 //	return _strTenkeyName[nTenkeyNo];
}

//---------------------------------------------------------------------------

void __fastcall TFrmTenkey::ParentTenkeyLoad()
{
    TIniFile *TenkeyIni = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\TenkeyNameInfo.ini");
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\TenkeyNameInfo.ini"))
    {
        for(int i = 1; i <= _MAX_PARENT_TENKEYCOUNT_; i++)
        {
        	String strTemp = TenkeyIni->ReadString("ParentTenkeyName","Part"+IntToStr(i),"");
            ParentGrid->Cells[0][i] = strTemp;
        }
    }
    delete  TenkeyIni;
}
//---------------------------------------------------------------------------
void __fastcall TFrmTenkey::ChildTenkeyLoad(int nSelectNo)
{
    TIniFile *TenkeyIni = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\TenkeyNameInfo.ini");
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\TenkeyNameInfo.ini"))
    {
        for(int i = 1; i <= _MAX_CHILD_TENKEYCOUNT_; i++)
        {
        	ChildGrid->Cells[0][i] = TenkeyIni->ReadString("ChildTenkeyName"+IntToStr(nSelectNo),"ChildTenkeyNumber"+IntToStr(i),"");
            ChildGrid->Cells[1][i] = TenkeyIni->ReadString("ChildTenkeyName"+IntToStr(nSelectNo),"ChildButtonName"+IntToStr(i),"");
            ChildGrid->Cells[2][i] = TenkeyIni->ReadString("ChildTenkeyName"+IntToStr(nSelectNo),"ChildHome"+IntToStr(i),"");
            ChildGrid->Cells[3][i] = TenkeyIni->ReadString("ChildTenkeyName"+IntToStr(nSelectNo),"ChildStep"+IntToStr(i),"");
        }
    }
    delete TenkeyIni;
}
//---------------------------------------------------------------------------

void __fastcall TFrmTenkey::ParentGridSelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect)
{
    PanelSelectTenkeyNo->Caption = "";
    PanelSelectTenkeyName->Caption = "";
    g_nTenkeyPartNo = ARow;
    ChildTenkeyLoad(g_nTenkeyPartNo);
}
//---------------------------------------------------------------------------

void __fastcall TFrmTenkey::ChildGridSelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect)
{
    int nTemp = ARow;

    TIniFile *TenkeyIni = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\TenkeyNameInfo.ini");
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\TenkeyNameInfo.ini"))
    {
        int nCmdTenekyNumber = TenkeyIni->ReadInteger("ChildTenkeyName"+IntToStr(g_nTenkeyPartNo),"ChildTenkeyNumber"+IntToStr(nTemp),0);
        String strTenkeyName = TenkeyIni->ReadString("ChildTenkeyName"+IntToStr(g_nTenkeyPartNo),"ChildButtonName"+IntToStr(nTemp),"");

        TSpeedButton *CloneTenkeyButton = (TSpeedButton *)FindComponent("TenkeyBtn"+IntToStr(nTemp));
        PanelSelectTenkeyNo->Caption = IntToStr(nCmdTenekyNumber);
        PanelSelectTenkeyName->Caption = strTenkeyName;
    }
    delete TenkeyIni;
}
//---------------------------------------------------------------------------

void __fastcall TFrmTenkey::BtnTenkeyRunClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

    if(PanelSelectTenkeyNo->Caption != "")
    {
        FrmCdBox->setFlag(CD_YESNO);
        FrmCdBox->setTitle("MANUAL OPERATION");
        FrmCdBox->setText("Are You sure?");
        if (mrYes == FrmCdBox->ShowModal())
        {
			int nTemp = dynamic_cast<TSpeedButton *>(Sender)->Tag;
			nWriteCommunicationDM( PanelSelectTenkeyNo->Caption.ToInt() + nTemp, _DM_TENKEY_RUNNING_);
		}
    }
    else
    {
        FrmCdBox->setFlag(CD_OK);
        FrmCdBox->setTitle("MANUAL OPERATION");
        FrmCdBox->setText("Press the tenkey what you want!");
        FrmCdBox->ShowModal();
    }
}
//---------------------------------------------------------------------------




