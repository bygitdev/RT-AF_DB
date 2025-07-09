//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop


#include "nRcpCreateScrn.h"
#include "MainFormScrn.h"
#include "RecipeChangeFormScrn.h"
#include "cdbox.h"

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include "BaseComm.h"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Shader"
#pragma link "CurvyControls"
#pragma resource "*.dfm"

TFrmRcpCreate *FrmRcpCreate;

//---------------------------------------------------------------------------
__fastcall TFrmRcpCreate::TFrmRcpCreate(TComponent* Owner)
    : TForm(Owner)
{
    PanelOriginName->Caption = "";
    PanelNewName->Caption = "";

    OriginRCPGrid->Cells[0][0] = "No.";
    OriginRCPGrid->Cells[1][0] = "Name";
    OriginRCPGrid->Cells[2][0] = "Check";

    TargetRCPGrid->Cells[0][0] = "No.";
    TargetRCPGrid->Cells[1][0] = "Name";
    TargetRCPGrid->Cells[2][0] = "Check";

    BtnRCPCopy->Enabled = false;

	for(int i=0; i<OriginRCPGrid->RowCount;i++)
    {
		OriginRCPGrid->Cells[0][i+1] =  IntToStr(i+1);
        TargetRCPGrid->Cells[0][i+1] =  IntToStr(i+1);
    }
    SameGrpCheckBox->Checked = true;
}
//---------------------------------------------------------------------------


void __fastcall TFrmRcpCreate::RecipeCreate_Initialize(int nGrpNo)
{
	m_setGroupIndex = nGrpNo;
	GroupRCPComboBox->Clear();
	GroupTargetRCPComboBox->Clear();

	TIniFile *groupIni = new TIniFile(ExtractFilePath(Application->ExeName) + "ini\\GroupName.ini");
	String strName;
	for(int i=0; i<100; i++)
	{
		strName = groupIni->ReadString("GROUP", "NAME"+IntToStr(i+1), " ");
		GroupRCPComboBox->Items->Add(strName);
		GroupTargetRCPComboBox->Items->Add(strName);
	}
	delete groupIni;

	GroupRCPComboBox->ItemIndex = nGrpNo-1;
	GroupTargetRCPComboBox->ItemIndex = nGrpNo-1;

	PanelGrpNo->Caption = IntToStr(nGrpNo);
	PanelTargetGrpNo->Caption = IntToStr(nGrpNo);

	RecipeChangeForm->RecipeName_Read(nGrpNo, OriginRCPGrid);
	RecipeChangeForm->RecipeCheck_Display(nGrpNo, OriginRCPGrid);

	RecipeChangeForm->RecipeName_Read(nGrpNo, TargetRCPGrid);
	RecipeChangeForm->RecipeCheck_Display(nGrpNo, TargetRCPGrid);
}
//---------------------------------------------------------------------------

void __fastcall TFrmRcpCreate::BtnInputItemClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	BtnInputItem->Enabled = false;
    BtnSaveItem->Enabled = true;
	TargetRCPGrid->Options<<goEditing;
    TargetRCPGrid->Options>>goRowSelect;
}
//---------------------------------------------------------------------------

void __fastcall TFrmRcpCreate::BtnSaveItemClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	BtnInputItem->Enabled = true;
    BtnSaveItem->Enabled = false;
	TargetRCPGrid->Options>>goEditing;
	TargetRCPGrid->Options<<goRowSelect;

	int nGrpIndex = GroupRCPComboBox->ItemIndex+1;
	int nGrpTagetIndex = GroupTargetRCPComboBox->ItemIndex+1;
	RecipeChangeForm->RecipeName_Save(nGrpTagetIndex, TargetRCPGrid);
	RecipeChangeForm->RecipeName_Read(nGrpIndex, OriginRCPGrid);
	RecipeChangeForm->RecipeCheck_Display(nGrpIndex, OriginRCPGrid);

	RecipeChangeForm->RecipeName_Read(nGrpTagetIndex, TargetRCPGrid);
	RecipeChangeForm->RecipeCheck_Display(nGrpTagetIndex, TargetRCPGrid);
}
//---------------------------------------------------------------------------

void __fastcall TFrmRcpCreate::OriginRCPGridSelectCell(TObject *Sender,
      int ACol, int ARow, bool &CanSelect)
{

	if(OriginRCPGrid->Cells[2][ARow] != "NO")
	{
		m_setRecipeIndex = ARow;
		PanelOriginName->Caption = "NO :" +  IntToStr(ARow)+" Recipe : " + OriginRCPGrid->Cells[1][ARow];

        BtnRCPCopy->Enabled = true;

    }
    else
    {
    	PanelOriginName->Caption = "";
		BtnRCPCopy->Enabled = false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TFrmRcpCreate::TargetRCPGridSelectCell(TObject *Sender,
      int ACol, int ARow, bool &CanSelect)
{
    m_IntendCopyIndex = ARow;
	PanelNewName->Caption =  "NO :" +  IntToStr(ARow)+" Recipe";

    if(PanelOriginName->Caption != "" && PanelNewName->Caption != "")
	{
		PanelNewName->Caption = "NO :" +  IntToStr(ARow)+" Recipe : " + TargetRCPGrid->Cells[1][ARow];
        BtnRCPCopy->Enabled = true;
    }
    else
    {
    	BtnRCPCopy->Enabled = false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TFrmRcpCreate::BtnRCPCopyClick(TObject *Sender)
{
	if(CheckRcpMotorfile->Checked == false && CheckRcpfile->Checked == false)
    {
    	MessageDlg("Please Select Copy option!", mtError, TMsgDlgButtons() << mbOK, 0);
//        return;
    }


	m_IntendGrpCopyIndex = PanelTargetGrpNo->Caption.ToInt();


	if(!DirectoryExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\\GRP"+IntToStr(m_IntendGrpCopyIndex)+"\\RCP"+IntToStr(m_IntendCopyIndex)))
    {
		if (FALSE == ForceDirectories(ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(m_IntendGrpCopyIndex)+"\\RCP"+IntToStr(m_IntendCopyIndex)))
        {
            MessageDlg("Drectory create failed.", mtError, TMsgDlgButtons() << mbOK, 0);
//            return;
        }
    }

	if(CheckRcpMotorfile->Checked == true)
    {
        if(MtrFileCopy()!= true)
        {
			MessageDlg("Motor file copy failed.", mtError, TMsgDlgButtons() << mbOK, 0);
//            return;
		}
	}

	if(CheckRcpfile->Checked == true)
	{
		if(PKGParamFileCopy()!= true)
		{
			MessageDlg("Package parameter file copy failed.", mtError, TMsgDlgButtons() << mbOK, 0);
//			return;
		}
	}

	if(StaubliFileCopy() != true)
	{
		MessageDlg("STAUBLI file copy failed.", mtError, TMsgDlgButtons() << mbOK, 0);
//		return;
	}


	if(GerberParamFileCopy() != true)
	{
		MessageDlg("GERBER file copy failed.", mtError, TMsgDlgButtons() << mbOK, 0);
//		return;
	}

	//	if(LaserPenFileCopy() != true)
//    {
//		MessageDlg("Laser pen parameter file copy failed.", mtError, TMsgDlgButtons() << mbOK, 0);
//		return;
//	}

    PanelOriginName->Caption = "";
    PanelNewName->Caption = "";

	int nGrpIndex = GroupRCPComboBox->ItemIndex+1;
	RecipeChangeForm->RecipeCheck_Display(nGrpIndex, OriginRCPGrid);

	nGrpIndex = GroupTargetRCPComboBox->ItemIndex+1;
    RecipeChangeForm->RecipeCheck_Display(nGrpIndex, TargetRCPGrid);


    FrmCdBox->setFlag(CD_OK);
    FrmCdBox->setTitle("Recipe Copy");
    FrmCdBox->setText("Success to copy");
    FrmCdBox->BringToFront();
    FrmCdBox->ShowModal();

}
//---------------------------------------------------------------------------
bool  TFrmRcpCreate::MtrFileCopy()
{
	bool bChkRet = true;

	for(int i=0; i < MAX_MT_NO; i++)
	{
		String StrAddr = ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(m_setGroupIndex)+"\\RCP"+IntToStr(m_setRecipeIndex)+"\\Motor"+ IntToStr(i)+".ini";
		String TargetAddr = ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(m_IntendGrpCopyIndex)+"\\RCP"+IntToStr(m_IntendCopyIndex)+"\\Motor"+ IntToStr(i)+".ini";

		if(FileExists(TargetAddr))
		{
			DeleteFile(TargetAddr);
		}

		bChkRet= ::CopyFile(StrAddr.c_str(),TargetAddr.c_str(),false);

		if (bChkRet == false)
		{
			return bChkRet;
        }
	}
	return bChkRet;
}
//---------------------------------------------------------------------------
bool  TFrmRcpCreate::PKGParamFileCopy()
{
    bool bChkRet = true;

	String StrAddr = ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(m_setGroupIndex)+"\\RCP"+IntToStr(m_setRecipeIndex)+"\\PkgParam.ini";
	String TargetAddr = ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(m_IntendGrpCopyIndex)+"\\RCP"+IntToStr(m_IntendCopyIndex)+"\\PkgParam.ini";

    if(FileExists(TargetAddr))
    {
        DeleteFile(TargetAddr);
    }

    bChkRet= ::CopyFile(StrAddr.c_str(),TargetAddr.c_str(),false);

    return bChkRet;
}
//---------------------------------------------------------------------------


bool  TFrmRcpCreate::StaubliFileCopy()      //??
{
	bool bChkRet = true;

	String StrAddr = ExtractFilePath(Application->ExeName)+ "Ini\\system\\GRP"+IntToStr(m_setGroupIndex)+"\\RCP"+IntToStr(m_setRecipeIndex)+"\\StaubliData.ini";
	String TargetAddr = ExtractFilePath(Application->ExeName)+ "Ini\\system\\GRP"+IntToStr(m_IntendGrpCopyIndex)+"\\RCP"+IntToStr(m_IntendCopyIndex)+"\\StaubliData.ini";

	if(FileExists(TargetAddr))
	{
		DeleteFile(TargetAddr);
	}

	bChkRet= ::CopyFile(StrAddr.c_str(),TargetAddr.c_str(),false);

	return bChkRet;
}
//---------------------------------------------------------------------------
bool  TFrmRcpCreate::GerberParamFileCopy()
{
    bool bChkRet = true;

	String StrAddr = ExtractFilePath(Application->ExeName)+ "Ini\\system\\GRP"+IntToStr(m_setGroupIndex)+"\\RCP"+IntToStr(m_setRecipeIndex)+"\\exportData.ini";
	String TargetAddr = ExtractFilePath(Application->ExeName)+ "Ini\\system\\GRP"+IntToStr(m_IntendGrpCopyIndex)+"\\RCP"+IntToStr(m_IntendCopyIndex)+"\\exportData.ini";

    if(FileExists(TargetAddr))
    {
        DeleteFile(TargetAddr);
    }

    bChkRet= ::CopyFile(StrAddr.c_str(),TargetAddr.c_str(),false);


	StrAddr = ExtractFilePath(Application->ExeName)+ "Ini\\system\\GRP"+IntToStr(m_setGroupIndex)+"\\RCP"+IntToStr(m_setRecipeIndex)+"\\exportData.nrpf";
	TargetAddr = ExtractFilePath(Application->ExeName)+ "Ini\\system\\GRP"+IntToStr(m_IntendGrpCopyIndex)+"\\RCP"+IntToStr(m_IntendCopyIndex)+"\\exportData.nrpf";

    if(FileExists(TargetAddr))
    {
        DeleteFile(TargetAddr);
    }

	bChkRet= ::CopyFile(StrAddr.c_str(),TargetAddr.c_str(),false);

    return bChkRet;
}
//---------------------------------------------------------------------------

void __fastcall TFrmRcpCreate::UpRCPGridCtrlClick(TObject *Sender)
{
	if(OriginRCPGrid->TopRow >= 8)
    {
		OriginRCPGrid->TopRow = OriginRCPGrid->TopRow - 8;
    }
    else
    {
        OriginRCPGrid->TopRow = 1;
    }
}
//---------------------------------------------------------------------------

void __fastcall TFrmRcpCreate::DownRCPGridCtrlClick(TObject *Sender)
{
	if(OriginRCPGrid->TopRow <= 92)
    {
		OriginRCPGrid->TopRow = OriginRCPGrid->TopRow + 8;
	}
    else
    {
        OriginRCPGrid->TopRow = 99;
    }
}
//---------------------------------------------------------------------------

void __fastcall TFrmRcpCreate::DownRCPGridCtrl2Click(TObject *Sender)
{
	if(TargetRCPGrid->TopRow <= 92)
    {
		TargetRCPGrid->TopRow = TargetRCPGrid->TopRow + 8;
    }
    else
    {
        TargetRCPGrid->TopRow = 99;
    }
}
//---------------------------------------------------------------------------

void __fastcall TFrmRcpCreate::UpRCPGridCtrl2Click(TObject *Sender)
{
	if(TargetRCPGrid->TopRow >= 8)
    {
		TargetRCPGrid->TopRow = TargetRCPGrid->TopRow - 8;
    }
	else
    {
        TargetRCPGrid->TopRow = 1;
    }
}
//---------------------------------------------------------------------------



void __fastcall TFrmRcpCreate::OriginRCPGridDrawCell(TObject *Sender, int ACol, int ARow,
		  TRect &Rect, TGridDrawState State)
{
	TStringGrid* pGrid = (TStringGrid*)Sender;
    int id = pGrid->Tag*16 + ARow -1;

	if (ARow > 0)
	{
		if (pGrid->Cells[2][ARow] == "YES")
        {
        	pGrid->Canvas->Brush->Color = clWhite;
    		pGrid->Canvas->Font->Color = clBlack;
        }
		else
		{
        	pGrid->Canvas->Brush->Color = clBtnFace;
    		pGrid->Canvas->Font->Color = clBlack;
        }

		pGrid->Canvas->FillRect(pGrid->CellRect(ACol,ARow));
        DrawText(pGrid->Canvas->Handle,
        pGrid->Cells[ACol][ARow].c_str(), pGrid->Cells[ACol][ARow].Length(),
        &Rect, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
    }
}
//---------------------------------------------------------------------------

void __fastcall TFrmRcpCreate::TargetRCPGridDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State)
{
	TStringGrid* pGrid = (TStringGrid*)Sender;
    int id = pGrid->Tag*16 + ARow -1;

    if (ARow > 0)
    {
		if (pGrid->Cells[2][ARow] == "YES")
        {
        	pGrid->Canvas->Brush->Color = clWhite;
    		pGrid->Canvas->Font->Color = clBlack;
        }
        else
        {
        	pGrid->Canvas->Brush->Color = clBtnFace;
    		pGrid->Canvas->Font->Color = clBlack;
        }

        pGrid->Canvas->FillRect(pGrid->CellRect(ACol,ARow));
        DrawText(pGrid->Canvas->Handle,
        pGrid->Cells[ACol][ARow].c_str(), pGrid->Cells[ACol][ARow].Length(),
        &Rect, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
	}
}
//---------------------------------------------------------------------------


void __fastcall TFrmRcpCreate::GroupRCPComboBoxChange(TObject *Sender)
{
	int nComboBox =GroupRCPComboBox->ItemIndex+1 ;
	for(int i=0; i<OriginRCPGrid->RowCount+1; i++)
    {
        OriginRCPGrid->Cells[0][i+1] = IntToStr(nComboBox)+" - "+ IntToStr(i+1);
    }

	TIniFile *RcpIni = new TIniFile(ExtractFilePath(Application->ExeName) + "\\ini\\RecipeName.ini");
	for(int i=0; i<OriginRCPGrid->RowCount+1; i++)
	{
		OriginRCPGrid->Cells[1][i+1]= RcpIni->ReadString("GROUP_"+IntToStr(nComboBox), "RECIPENAME"+IntToStr(i+1), "");
	}
	delete RcpIni;

	m_setGroupIndex = nComboBox;

	RecipeChangeForm->RecipeName_Read(m_setGroupIndex, OriginRCPGrid);
	RecipeChangeForm->RecipeCheck_Display(m_setGroupIndex, OriginRCPGrid);

	if(SameGrpCheckBox->Checked ==true)
	{
		GroupTargetRCPComboBox->ItemIndex = GroupRCPComboBox->ItemIndex;
		GroupTargetRCPComboBox->OnChange(this);

		RecipeChangeForm->RecipeName_Read(m_setGroupIndex, TargetRCPGrid);
		RecipeChangeForm->RecipeCheck_Display(m_setGroupIndex, TargetRCPGrid);
	}

    PanelGrpNo->Caption = IntToStr(nComboBox);
}
//---------------------------------------------------------------------------

void __fastcall TFrmRcpCreate::GroupTargetRCPComboBoxChange(TObject *Sender)
{
	int nComboBox = GroupTargetRCPComboBox->ItemIndex+1;
	for(int i=0; i<TargetRCPGrid->RowCount+1; i++)
	{
		TargetRCPGrid->Cells[0][i+1] = IntToStr(nComboBox)+" - "+ IntToStr(i+1);
    }

	TIniFile *RcpIni = new TIniFile(ExtractFilePath(Application->ExeName) + "\\ini\\RecipeName.ini");
	for(int i=0; i<TargetRCPGrid->RowCount+1; i++)
	{
		TargetRCPGrid->Cells[1][i+1]= RcpIni->ReadString("GROUP_"+IntToStr(nComboBox), "RECIPENAME"+IntToStr(i+1), "");
	}
	delete RcpIni;

	m_IntendGrpCopyIndex = nComboBox;
	RecipeChangeForm->RecipeName_Read(m_IntendGrpCopyIndex, TargetRCPGrid);
	RecipeChangeForm->RecipeCheck_Display(m_IntendGrpCopyIndex, TargetRCPGrid);

    PanelTargetGrpNo->Caption = IntToStr(nComboBox);
}
//---------------------------------------------------------------------------

void __fastcall TFrmRcpCreate::SameGrpCheckBoxClick(TObject *Sender)
{
    if(SameGrpCheckBox->Checked ==true)
    {
        GroupTargetRCPComboBox->Enabled =false;
        GroupTargetRCPComboBox->ItemIndex = GroupRCPComboBox->ItemIndex;
        GroupTargetRCPComboBox->OnChange(this);
	}
    else
    {
        GroupTargetRCPComboBox->Enabled =true;
	}
}
//---------------------------------------------------------------------------


void __fastcall TFrmRcpCreate::FormShow(TObject *Sender)
{
	this->RecipeCreate_Initialize(1);
}
//---------------------------------------------------------------------------

void __fastcall TFrmRcpCreate::SpeedButton1Click(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TFrmRcpCreate::BtnDeleteItemClick(TObject *Sender)
{
	int nGrpNo = nReadGroupNo();
	int nRcpNo = nReadRecipeNo();
	int nTargetGrp = PanelTargetGrpNo->Caption.ToInt();
	int nTargetRcp = m_IntendCopyIndex;

	// 현재 작업 중인 Recipe 는 삭제 안되도록!
	if(nTargetRcp == nRcpNo && nTargetGrp == nGrpNo)
	{
		FrmCdBox->setTitle("FAIL TO DELETE RECIPE");
		FrmCdBox->setText("Can not delete current open recipe!");
		FrmCdBox->setFlag(CD_OK);
		FrmCdBox->ShowModal();
		return;
	}

	String strRcpName = GetStringRecipeName(nTargetGrp, nTargetRcp);

	FrmCdBox->setTitle("DELETE RECIPE");
	FrmCdBox->setText("Do you want delete recipe["+strRcpName+"]?");
	FrmCdBox->setFlag(CD_YESNO);
	if( mrYes != FrmCdBox->ShowModal())
		return;
	String TargetAddr = ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(nTargetGrp)+"\\RCP"+IntToStr(nTargetRcp)+"\\";
	//MotorData
	if(DirectoryExists(TargetAddr))
	{
		DeleteRecipeDirectory(TargetAddr, "*.*");
	}
	//
}
//---------------------------------------------------------------------------

