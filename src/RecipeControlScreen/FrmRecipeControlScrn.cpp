//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FrmRecipeControlScrn.h"
#include "BaseComm.h"

#include "MainFrm.h"
#include "RcpCreateScrn.h"
#include "VisionSetUpScrn.h"
#include "LaserCadScrn.h"
#include "CommonRCPSaveScrn.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrmRecipeControl *FrmRecipeControl;
//---------------------------------------------------------------------------
__fastcall TFrmRecipeControl::TFrmRecipeControl(TComponent* Owner)
	: TForm(Owner)
{
	GroupControlGrid->Cells[0][0] = "NO";
	GroupControlGrid->Cells[1][0] = "NAME";
    for(int i=0; i<GroupControlGrid->RowCount;i++)
    {
		GroupControlGrid->Cells[0][i+1] =  IntToStr(i+1);
	}

	RecipeControlGrid->Cells[0][0] = "NO";
    RecipeControlGrid->Cells[1][0] = "NAME";
    RecipeControlGrid->Cells[2][0] = "STATUS";

	for(int i=0; i<RecipeControlGrid->RowCount;i++)
	{
		RecipeControlGrid->Cells[0][i+1] =  IntToStr(i+1);
	}
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void __fastcall TFrmRecipeControl::RecipeControl_Initialize(int nLeftRight)
{

	_nLeftRight_ =  nLeftRight;
	if(nLeftRight == _LEFT_STAGE_)
	{
		m_groupNo 	= nReadLeftGroupNo();
		m_recipeNo 	= nReadLeftRecipeNo();

		if(m_groupNo == 0)
			m_groupNo = 1;

		if(m_recipeNo == 0)
		{
			m_recipeNo = 1;
		}
	}
	else
	{
		m_groupNo	= nReadRightGroupNo();
		m_recipeNo 	=  nReadRightRecipeNo();

		if(m_groupNo == 0)
			m_groupNo = 1;

		if(m_recipeNo == 0)
        {
			m_recipeNo = 1;
        }
	}
	GroupName_Read(GroupControlGrid);

    for(int i=0; i<RecipeControlGrid->RowCount;i++)
	{
		RecipeControlGrid->Cells[1][i+1] =  "";
		RecipeControlGrid->Cells[2][i+1] =  "";
	}

	String strRcp;

	if(_nLeftRight_ == 0)
		strRcp = Get_LeftRecipeName();
	else
		strRcp = Get_RightRecipeName();

	PanelSetGRP->Caption = IntToStr(m_groupNo) + " : " + GroupControlGrid->Cells[1][m_groupNo];
	PanelSetRCP->Caption = IntToStr(m_recipeNo) + " : " + strRcp;

	m_IntendRecipeNo= 0;
}
//---------------------------------------------------------------------------

void TFrmRecipeControl::GroupName_Read(TStringGrid *pGrid)
{
	TIniFile *IniGroup = new TIniFile(ExtractFilePath(Application->ExeName) + "\\ini\\GroupName.ini");
	if(FileExists(ExtractFilePath(Application->ExeName) + "\\ini\\GroupName.ini"))
	{
		String strGrpName;
		for(int i=0; i<100; i++)
		{
			strGrpName = IniGroup->ReadString("GROUP", "NAME"+IntToStr(i+1), "");
			pGrid->Cells[1][i+1] = strGrpName;
		}
	}
	delete IniGroup;
}
//---------------------------------------------------------------------------

bool   TFrmRecipeControl::RecipeName_Read(int nGrpNo, TStringGrid *pGrid)
{
	TIniFile *RecipeNameini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\RecipeName.ini");
	if(RecipeNameini != NULL)
    {
		for(int i=0; i<pGrid->RowCount;i++)
        {
			pGrid->Cells[1][i+1] = RecipeNameini->ReadString("GROUP_"+IntToStr(nGrpNo),"RECIPENAME"+IntToStr(i+1),"");
		}
		delete RecipeNameini;
		return true;

	}
	else
	{
		delete RecipeNameini;
		return false;
	}
}
//---------------------------------------------------------------------------
bool  TFrmRecipeControl::RecipeName_Save(int nGrpIndex, TStringGrid *pGrid)
{
	TIniFile *RecipeNameini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\RecipeName.ini");
	if(RecipeNameini != NULL)
	{
		for(int i=0; i<pGrid->RowCount;i++)
		{
			RecipeNameini->WriteString("GROUP_"+IntToStr(nGrpIndex),"RECIPENAME"+IntToStr(i+1),pGrid->Cells[1][i+1]);
		}
		delete RecipeNameini;
		return true;

	}
	else
	{
		delete RecipeNameini;
		return false;
	}
}
//---------------------------------------------------------------------------

String   TFrmRecipeControl::RecipeName_ReturnString(int nRecipeIndex)
{
	TIniFile *RecipeNameini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\RecipeName.ini");
    if(RecipeNameini != NULL)
    {
		String RetStr = RecipeNameini->ReadString("RECIPE","NAME"+IntToStr(nRecipeIndex),"RECIPE Name"+IntToStr(nRecipeIndex));
		delete RecipeNameini;
		return RetStr;
	}
	delete RecipeNameini;
}
//---------------------------------------------------------------------------

bool  TFrmRecipeControl::RecipePath_Check(int ngrpindex, int nrcpindex)
{
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(ngrpindex)+"\\RCP"+IntToStr(nrcpindex)+"\\PkgParam.ini") == false)
	{
		return false;
	}
	for(int i=0; i<MAX_MT_NO;i++)
	{
		if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(ngrpindex)+"\\RCP"+IntToStr(nrcpindex)+"\\Motor"+ IntToStr(i)+".ini") == false)
        {
			return false;
        }
	}

	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(ngrpindex)+"\\RCP"+IntToStr(nrcpindex)+"\\Pens.xml") == false)
	{
		return false;
	}
	return true;
}
//---------------------------------------------------------------------------
void   TFrmRecipeControl::RecipeCheck_Display(int nGrpNo, TStringGrid *pGrid)
{
	for(int i=0; i<pGrid->RowCount;i++)
	{
		if(RecipePath_Check(nGrpNo, i+1) == false || pGrid->Cells[1][i+1] == "" )
		{
			pGrid->Cells[2][i+1] = "NO";
		}
		else
        {
            pGrid->Cells[2][i+1] = "YES";
        }
    }
    pGrid->Refresh();
}
//---------------------------------------------------------------------------

bool   TFrmRecipeControl::MotionConvert()
{
	for(int nLoopAxis=0; nLoopAxis<MAX_MT_NO; nLoopAxis++)
	{
        g_MMIComm->m_mmiToSeq.cmd  = CMD_RD_MTTABLE;
        g_MMIComm->m_mmiToSeq.buffer.mtData._nLR  = _nLeftRight_;
        g_MMIComm->m_mmiToSeq.buffer.mtData._nMtNo = nLoopAxis;

		TIniFile *TempMotorchangeini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(m_groupNo)+"\\RCP"+IntToStr(m_IntendRecipeNo)+"\\Motor"+ IntToStr(nLoopAxis)+".ini");
        if(TempMotorchangeini != NULL)
        {
            for(int i=0; i<50; i++)
            {
                String bufpos = TempMotorchangeini->ReadString("INDEXPOS","POSITION"+IntToStr(i),IntToStr(i));

                if(bufpos == 0 || bufpos == "")
                {
                    g_MMIComm->m_mmiToSeq.buffer.mtData._table._dPos [i] = 0;

                }
                else
                {
                    g_MMIComm->m_mmiToSeq.buffer.mtData._table._dPos [i] = StrToFloat(bufpos) * 1000.0;;
                }

                String bufspd = TempMotorchangeini->ReadString("INDEXSPD","SPEED"+IntToStr(i),IntToStr(i));

                if(bufspd == 0 || bufspd == "")
                {
                     g_MMIComm->m_mmiToSeq.buffer.mtData._table._dVel [i] = 0;
                }
                else
                {
                     g_MMIComm->m_mmiToSeq.buffer.mtData._table._dVel [i] = StrToFloat(bufspd) * 1000.0;;
                }
            }

            g_MMIComm->m_mmiToSeq.cmd = CMD_WR_MTTABLE;
            if(g_MMIComm->Send()  && g_MMIComm->Recv())
            {
			}
        }
        else
        {
            delete TempMotorchangeini;
            return false;
		}

		delete TempMotorchangeini;
	}
	return true;
}
//---------------------------------------------------------------------------
#define   _PKGDATA_COUNT_            500
bool   TFrmRecipeControl::PKGDataConvert()
{
	TIniFile * TempPKGchangeini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(m_groupNo)+"\\RCP"+IntToStr(m_IntendRecipeNo)+"\\PkgParam.ini");

    if(TempPKGchangeini != NULL)
    {
        if(_nLeftRight_ == _LEFT_STAGE_)
        {
            for(int i=0; i<_PKGDATA_COUNT_; i++)
            {
                String StrTemp = TempPKGchangeini->ReadString("PKGPARM","VALUE"+IntToStr(i),IntToStr(i));

                if(StrTemp == "")
                {
                    StrTemp = "0";
                }

                double dData = StrToFloat( StrTemp );
                g_pNvMem->SetPkgL(i, dData);
            }
        }
        else
        {
            for(int i=0; i<_PKGDATA_COUNT_; i++)
            {
                String StrTemp = TempPKGchangeini->ReadString("PKGPARM","VALUE"+IntToStr(i),IntToStr(i));

                if(StrTemp == "")
                {
                    StrTemp = "0";
                }

                double dData = StrToFloat( StrTemp );
                g_pNvMem->SetPkgR(i, dData);
            }
        }
        delete TempPKGchangeini;
    	return true;
    }
	else
    {
        delete TempPKGchangeini;
        return false;
    }

}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void __fastcall TFrmRecipeControl::BtnRecipeControlUpClick(TObject *Sender)
{
	if(RecipeControlGrid->TopRow >= 6)
    {
		RecipeControlGrid->TopRow = RecipeControlGrid->TopRow - 6;
    }
    else
    {
        RecipeControlGrid->TopRow = 1;
    }
}
//---------------------------------------------------------------------------
void __fastcall TFrmRecipeControl::BtnRecipeControlDownClick(TObject *Sender)
{
	if(RecipeControlGrid->TopRow <= 490)
    {
		RecipeControlGrid->TopRow = RecipeControlGrid->TopRow + 6;
    }
    else
    {
        RecipeControlGrid->TopRow = 499;
    }
}
//---------------------------------------------------------------------------
void __fastcall TFrmRecipeControl::RecipeControlGridDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State)
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
        	pGrid->Canvas->Brush->Color = clGray;
    		pGrid->Canvas->Font->Color = clBlack;
        }

        pGrid->Canvas->FillRect(pGrid->CellRect(ACol,ARow));
        DrawText(pGrid->Canvas->Handle,
        pGrid->Cells[ACol][ARow].c_str(), pGrid->Cells[ACol][ARow].Length(),
        &Rect, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
    }
}
//---------------------------------------------------------------------------
void __fastcall TFrmRecipeControl::RecipeControlGridDblClick(TObject *Sender)
{
	if(FrmRcpCreate->Showing == false)
	{
		FrmRcpCreate->RecipeCreate_Initialize(m_groupNo);
		FrmRcpCreate->ShowModal();
    }

	this->RecipeName_Read(m_groupNo, RecipeControlGrid);
	this->RecipeCheck_Display(m_groupNo, RecipeControlGrid);
}
//---------------------------------------------------------------------------
void __fastcall TFrmRecipeControl::RecipeControlGridSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect)
{
	if(RecipeControlGrid->Cells[1][ARow] != "" && RecipeControlGrid->Cells[2][ARow] != "NO")
	{
        PanelSelectRecipe->Caption = IntToStr(ARow) + " : " + RecipeControlGrid->Cells[1][ARow];
        BtnRecipeChange->Enabled = true;
        m_IntendRecipeNo = ARow;
	}
	else
	{
		BtnRecipeChange->Enabled = false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TFrmRecipeControl::ProgressTimerTimer(TObject *Sender)
{
    if(nDisplayProgress < 100)
	{
        nDisplayProgress++;
		LabelProgress->Caption =  FloatToStr(nDisplayProgress) + " % Processing";
		ConversionProgress->Position =  nDisplayProgress;
	}
	else
	{
		nDisplayProgress = 0;
		ConversionProgress->Position = 0;
		LabelProgress->Caption = "Complete!";
		ProgressTimer->Enabled = false;
		PanelProgress->Visible = false;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmRecipeControl::BtnRecipeChangeClick(TObject *Sender)
{
	TIniFile *RecipeNameini;
    FrmCdBox->setFlag(CD_YESNO);
    FrmCdBox->setTitle("RECIPE DATA CHANGE");
    FrmCdBox->setText("Are sure CHANGE the RECIPE?");
	if( mrYes == FrmCdBox->ShowModal())
	{
		PanelProgress->Visible = true;
		PanelProgress->Top = 180;
		PanelProgress->Left = 200;

        ProgressTimer->Enabled = false;
        ProgressTimer->Enabled = true;

        if(m_IntendRecipeNo != 0)
        {
			if(MotionConvert() == true)
            {
                if(PKGDataConvert() == true)
                {
					if(CheckBoxVisionConversionCommand->Checked == true)
                    {
						String StrRcpName = this->RecipeName_ReturnString(m_IntendRecipeNo);
						if(StrRcpName != "")
                        {
                            if(FrmVisionSetUp->JobChangeVisionConversion(_nLeftRight_ , StrRcpName) == false) // _nLeftRight --> 0 :LEFT  1 : RIGHT
                            {
								nDisplayProgress = 100;
                                FrmCdBox->setFlag(CD_OK);
                                FrmCdBox->setTitle("VISION RECIPE CHANGE!");
                                FrmCdBox->setText("CHECK the vision connect Status for recipe change!");
                                FrmCdBox->ShowModal();
                                return;
                            }
                        }
                        else
                        {
                            nDisplayProgress = 100;
                            FrmCdBox->setFlag(CD_OK);
                            FrmCdBox->setTitle("RECIPE NAME!");
                            FrmCdBox->setText("Fail to SEND RECIPE NAME !");
                            FrmCdBox->ShowModal();
                            return ;
                        }
					}
					if(CheckBoxLaserConversionCommand->Checked == true)
					{
						TFrmLaserCad* pLaserCad = dynamic_cast<TFrmLaserCad*>(MainFrmForm->get_LaserScrn(!_nLeftRight_));
						if(NULL != pLaserCad)
						{
							if(!pLaserCad->recipe_open(m_groupNo, m_IntendRecipeNo))
							{
								nDisplayProgress = 100;
								FrmCdBox->setFlag(CD_OK);
								FrmCdBox->setTitle("LASER RECIPE OPEN FAILED!");
								FrmCdBox->setText("Can not open the laser recipe. check for recipe or save the laser job!");
								FrmCdBox->ShowModal();
							}
						}
					}

                    //Complete
					if(_nLeftRight_ == _LEFT_STAGE_)
					{
						g_pNvMem->SetDDm(groupNo_L, m_groupNo);
						g_pNvMem->SetDDm(jobNo_L , m_IntendRecipeNo);
					}
					else
					{
						g_pNvMem->SetDDm(groupNo_R, m_groupNo);
                    	g_pNvMem->SetDDm(jobNo_R , m_IntendRecipeNo);
                    }

					MainFrmForm->ShowRecipeInformation();
					RecipeControl_Initialize(_nLeftRight_);
                }
                else
                {
                	nDisplayProgress = 100;
                    FrmCdBox->setFlag(CD_OK);
                    FrmCdBox->setTitle("PKG DATA RECIPE!");
                    FrmCdBox->setText("Fail to change PKG RECIPE!");
                    FrmCdBox->ShowModal();
                    return;
                }
            }
            else
            {
                nDisplayProgress = 100;
                FrmCdBox->setFlag(CD_OK);
                FrmCdBox->setTitle("MOTOR RECIPE!");
                FrmCdBox->setText("Fail to change MOTOR RECIPE!");
                FrmCdBox->ShowModal();
                return;
            }

        }
	}

    m_IntendRecipeNo = 0;
}
//---------------------------------------------------------------------------


void __fastcall TFrmRecipeControl::GroupControlGridDblClick(TObject *Sender)
{
	if(FrmCommonRcpSave->Showing == false)
	{
		FrmCommonRcpSave->ShowModal();
	}

	this->GroupName_Read(GroupControlGrid);
}
//---------------------------------------------------------------------------

void __fastcall TFrmRecipeControl::GroupControlGridDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State)
{
	TStringGrid* pGrid = (TStringGrid*)Sender;
    int id = pGrid->Tag*16 + ARow -1;

    if (ARow > 0)
	{
		if (pGrid->Cells[1][ARow] != "")
        {
        	pGrid->Canvas->Brush->Color = clWhite;
    		pGrid->Canvas->Font->Color = clBlack;
        }
        else
        {
        	pGrid->Canvas->Brush->Color = clGray;
    		pGrid->Canvas->Font->Color = clBlack;
        }

        pGrid->Canvas->FillRect(pGrid->CellRect(ACol,ARow));
        DrawText(pGrid->Canvas->Handle,
        pGrid->Cells[ACol][ARow].c_str(), pGrid->Cells[ACol][ARow].Length(),
		&Rect, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmRecipeControl::GroupControlGridSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect)
{
	if(GroupControlGrid->Cells[1][ARow] != "")
	{
		PanelSelectGroup->Caption = IntToStr(ARow) + " : " + GroupControlGrid->Cells[1][ARow];
		m_groupNo = ARow;
		RecipeName_Read(m_groupNo, RecipeControlGrid);
		RecipeCheck_Display(m_groupNo, RecipeControlGrid);
	}
}
//---------------------------------------------------------------------------

