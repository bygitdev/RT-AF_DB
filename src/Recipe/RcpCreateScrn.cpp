//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop


#include "RcpCreateScrn.h"
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

ToFrmRcpCreate *oFrmRcpCreate;

//---------------------------------------------------------------------------
__fastcall ToFrmRcpCreate::ToFrmRcpCreate(TComponent* Owner)
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


void __fastcall ToFrmRcpCreate::RecipeCreate_Initialize(int nGrpNo)
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

	RecipeChangeForm->RecipeName_Read(nGrpNo, OriginRCPGrid, false);
	RecipeChangeForm->RecipeCheck_Display(nGrpNo, OriginRCPGrid);

	RecipeChangeForm->RecipeName_Read(nGrpNo, TargetRCPGrid, false);
	RecipeChangeForm->RecipeCheck_Display(nGrpNo, TargetRCPGrid);
}
//---------------------------------------------------------------------------

void __fastcall ToFrmRcpCreate::BtnInputItemClick(TObject *Sender)
{
	BtnInputItem->Enabled = false;
    BtnSaveItem->Enabled = true;
	TargetRCPGrid->Options<<goEditing;
    TargetRCPGrid->Options>>goRowSelect;
}
//---------------------------------------------------------------------------

void __fastcall ToFrmRcpCreate::BtnSaveItemClick(TObject *Sender)
{
	BtnInputItem->Enabled = true;
    BtnSaveItem->Enabled = false;
    OriginRCPGrid->Options>>goEditing;
    OriginRCPGrid->Options<<goRowSelect;

	int nGrpIndex = GroupRCPComboBox->ItemIndex+1;
	int	nGrpTargetIndex = GroupTargetRCPComboBox->ItemIndex+1;
	RecipeChangeForm->RecipeName_Save(nGrpTargetIndex, TargetRCPGrid);
	RecipeChangeForm->RecipeName_Read(nGrpIndex, OriginRCPGrid, false);
	RecipeChangeForm->RecipeCheck_Display(nGrpIndex, OriginRCPGrid);


	RecipeChangeForm->RecipeName_Read(nGrpTargetIndex, TargetRCPGrid, false);
	RecipeChangeForm->RecipeCheck_Display(nGrpTargetIndex, TargetRCPGrid);
}
//---------------------------------------------------------------------------

void __fastcall ToFrmRcpCreate::OriginRCPGridSelectCell(TObject *Sender,
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

void __fastcall ToFrmRcpCreate::TargetRCPGridSelectCell(TObject *Sender,
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

void __fastcall ToFrmRcpCreate::BtnRCPCopyClick(TObject *Sender)
{
	if(CheckRcpMotorfile->Checked == false && CheckRcpfile->Checked == false)
    {
    	MessageDlg("Please Select Copy option!", mtError, TMsgDlgButtons() << mbOK, 0);
//        return;
	}

	if(SameGrpCheckBox->Checked == false)
	{
		m_IntendGrpCopyIndex = PanelTargetGrpNo->Caption.ToInt();
	}

	if(!DirectoryExists(ExtractFilePath(Application->ExeName)+ "Ini\\system\\\GRP"+IntToStr(m_IntendGrpCopyIndex)+"\\RCP"+IntToStr(m_IntendCopyIndex)))
	{
		if (FALSE == ForceDirectories(ExtractFilePath(Application->ExeName)+ "Ini\\system\\GRP"+IntToStr(m_IntendGrpCopyIndex)+"\\RCP"+IntToStr(m_IntendCopyIndex)))
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
//            return;
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


	PanelOriginName->Caption = "";
	PanelNewName->Caption = "";

	int nGrpIndex = GroupRCPComboBox->ItemIndex+1;
	RecipeChangeForm->RecipeCheck_Display(nGrpIndex, OriginRCPGrid);

	nGrpIndex = GroupTargetRCPComboBox->ItemIndex+1;
	RecipeChangeForm->RecipeCheck_Display(nGrpIndex, TargetRCPGrid);

	FrmCdBox->setFlag(CD_OK);
	FrmCdBox->setTitle( "RECIPE COPY" );
	FrmCdBox->setText( "Success to copy");
	FrmCdBox->BringToFront();
	FrmCdBox->ShowModal();

}
//---------------------------------------------------------------------------

bool  ToFrmRcpCreate::MtrFileCopy()
{
	bool bChkRet = true;

	for(int i=0; i < MAX_MT_NO; i++)
	{
		String StrAddr = ExtractFilePath(Application->ExeName)+ "Ini\\system\\GRP"+IntToStr(m_setGroupIndex)+"\\RCP"+IntToStr(m_setRecipeIndex)+"\\Motor"+ IntToStr(i)+".ini";
		String TargetAddr = ExtractFilePath(Application->ExeName)+ "Ini\\system\\GRP"+IntToStr(m_IntendGrpCopyIndex)+"\\RCP"+IntToStr(m_IntendCopyIndex)+"\\Motor"+ IntToStr(i)+".ini";

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
bool  ToFrmRcpCreate::PKGParamFileCopy()
{
    bool bChkRet = true;

	String StrAddr = ExtractFilePath(Application->ExeName)+ "Ini\\system\\GRP"+IntToStr(m_setGroupIndex)+"\\RCP"+IntToStr(m_setRecipeIndex)+"\\PkgParam.ini";
	String TargetAddr = ExtractFilePath(Application->ExeName)+ "Ini\\system\\GRP"+IntToStr(m_IntendGrpCopyIndex)+"\\RCP"+IntToStr(m_IntendCopyIndex)+"\\PkgParam.ini";

    if(FileExists(TargetAddr))
    {
        DeleteFile(TargetAddr);
    }

    bChkRet= ::CopyFile(StrAddr.c_str(),TargetAddr.c_str(),false);

    return bChkRet;
}
//---------------------------------------------------------------------------


bool  ToFrmRcpCreate::StaubliFileCopy()      //??
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
bool  ToFrmRcpCreate::GerberParamFileCopy()
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

void __fastcall ToFrmRcpCreate::UpRCPGridCtrlClick(TObject *Sender)
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

void __fastcall ToFrmRcpCreate::DownRCPGridCtrlClick(TObject *Sender)
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

void __fastcall ToFrmRcpCreate::DownRCPGridCtrl2Click(TObject *Sender)
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

void __fastcall ToFrmRcpCreate::UpRCPGridCtrl2Click(TObject *Sender)
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


void __fastcall ToFrmRcpCreate::BtnCloseClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall ToFrmRcpCreate::OriginRCPGridDrawCell(TObject *Sender, int ACol, int ARow,
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

void __fastcall ToFrmRcpCreate::TargetRCPGridDrawCell(TObject *Sender, int ACol, int ARow,
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


void __fastcall ToFrmRcpCreate::GroupRCPComboBoxChange(TObject *Sender)
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

	RecipeChangeForm->RecipeName_Read(m_setGroupIndex, OriginRCPGrid, false);
	RecipeChangeForm->RecipeCheck_Display(m_setGroupIndex, OriginRCPGrid);

	if(SameGrpCheckBox->Checked ==true)
	{
		GroupTargetRCPComboBox->ItemIndex = GroupRCPComboBox->ItemIndex;
		GroupTargetRCPComboBox->OnChange(this);

		RecipeChangeForm->RecipeName_Read(m_setGroupIndex, TargetRCPGrid, false);
		RecipeChangeForm->RecipeCheck_Display(m_setGroupIndex, TargetRCPGrid);
	}

    PanelGrpNo->Caption = IntToStr(nComboBox);
}
//---------------------------------------------------------------------------

void __fastcall ToFrmRcpCreate::GroupTargetRCPComboBoxChange(TObject *Sender)
{
	int nComboBox = GroupTargetRCPComboBox->ItemIndex+1;
	for(int i=0; i<TargetRCPGrid->RowCount+1; i++)
	{
		TargetRCPGrid->Cells[0][i+1] = IntToStr(nComboBox)+" - "+ IntToStr(i+1);
    }

	TIniFile *RcpIni = new TIniFile(ExtractFilePath(Application->ExeName) + "ini\\RecipeName.ini");
	for(int i=0; i<TargetRCPGrid->RowCount+1; i++)
	{
		TargetRCPGrid->Cells[1][i+1]= RcpIni->ReadString("GROUP_"+IntToStr(nComboBox), "RECIPENAME"+IntToStr(i+1), "");
	}
	delete RcpIni;

	m_IntendGrpCopyIndex = nComboBox;
	RecipeChangeForm->RecipeName_Read(m_IntendGrpCopyIndex, TargetRCPGrid, false);
	RecipeChangeForm->RecipeCheck_Display(m_IntendGrpCopyIndex, TargetRCPGrid);

    PanelTargetGrpNo->Caption = IntToStr(nComboBox);
}
//---------------------------------------------------------------------------

void __fastcall ToFrmRcpCreate::SameGrpCheckBoxClick(TObject *Sender)
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

void __fastcall ToFrmRcpCreate::FormShow(TObject *Sender)
{
	int nComboBox = GroupTargetRCPComboBox->ItemIndex+1;
	PanelGrpNo->Caption = IntToStr(nComboBox);
	PanelTargetGrpNo->Caption = IntToStr(nComboBox);
	m_IntendGrpCopyIndex = nComboBox;
}
//---------------------------------------------------------------------------

