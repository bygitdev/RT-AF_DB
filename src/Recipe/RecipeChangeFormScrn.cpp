//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RecipeChangeFormScrn.h"
#include "nRcpCreateScrn.h"
#include "VisionSetUpScrn.h"
#include "MainFormScrn.h"
#include "FormSecsGemSetScrn.h"
//---------------------------------------------------------------------------
#include "BaseComm.h"
#include "GrayFormCDBoxScrn.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma resource "*.dfm"


#define _MAX_GRP_NO_	100
#define _MAX_RCP_NO_    500

TRecipeChangeForm *RecipeChangeForm;
//---------------------------------------------------------------------------
__fastcall TRecipeChangeForm::TRecipeChangeForm(TComponent* Owner)
	: TForm(Owner)
{
	GroupControlGrid->RowCount = _MAX_GRP_NO_+1;
	RecipeControlGrid->RowCount = _MAX_RCP_NO_+1;

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

void TRecipeChangeForm::RecipeControl_Initialize()
{

    m_groupNo 	= nReadGroupNo();
    m_recipeNo 	= nReadRecipeNo();

    if(m_groupNo == 0)
        m_groupNo = 1;

    if(m_recipeNo == 0)
    {
        m_recipeNo = 1;
    }


	GroupName_Read(GroupControlGrid);

    for(int i=0; i<RecipeControlGrid->RowCount;i++)
	{
		RecipeControlGrid->Cells[1][i+1] =  "";
		RecipeControlGrid->Cells[2][i+1] =  "";
	}

	String strRcp = Get_RecipeName();

	PanelSetGRP->Caption = IntToStr(m_groupNo) + " : " + GroupControlGrid->Cells[1][m_groupNo];
	PanelSetRCP->Caption = IntToStr(m_recipeNo) + " : " + strRcp;

    LabelNotifyName ->Caption = "GROUP SELECT  : " + PanelSetGRP->Caption;
    LabelNotifyRecipe ->Caption = "RECIPE SELECT  : " + PanelSetRCP->Caption ;
	m_IntendRecipeNo= 0;


	PanelSelectGroup->Caption = IntToStr(1) + " : " + GroupControlGrid->Cells[1][1];
	m_groupNo = 1;
	LabelNotifyName->Font->Color = clNavy;
	LabelNotifyName ->Caption = "GROUP SELECT : " + PanelSelectGroup->Caption ;
	RecipeName_Read(m_groupNo, RecipeControlGrid);
	RecipeCheck_Display(m_groupNo, RecipeControlGrid);

}
//---------------------------------------------------------------------------

void __fastcall TRecipeChangeForm::BtnInputGroupNameClick(TObject *Sender)
{
	m_LastGroupNo = _MAX_GRP_NO_;
	GroupControlGrid->RowCount = m_LastGroupNo+1;

    BtnInputGroupName->Enabled = false;
    BtnSaveGroupName->Enabled = true;

    GroupControlGrid->Options<<goEditing;
    GroupControlGrid->Options>>goRowSelect;
}
//---------------------------------------------------------------------------

void __fastcall TRecipeChangeForm::BtnSaveGroupNameClick(TObject *Sender)
{
    BtnInputGroupName->Enabled = true;
    BtnSaveGroupName->Enabled = false;

    GroupControlGrid->Options>>goEditing;
    GroupControlGrid->Options<<goRowSelect;

    this->GroupName_Save(GroupControlGrid);
    this->GroupName_Read(GroupControlGrid);

}
//---------------------------------------------------------------------------

bool TRecipeChangeForm::GroupName_Read(TStringGrid *pGrid)
{
	TIniFile *IniGroup = new TIniFile(ExtractFilePath(Application->ExeName) + "\\ini\\GroupName.ini");
	if(IniGroup != NULL)
	{
		m_LastGroupNo = IniGroup->ReadInteger("GROUP", "_LAST", 1);
		if(m_LastGroupNo <= 0)
		{
			m_LastGroupNo = 1;
		}
		pGrid->RowCount = m_LastGroupNo+1;

		String strGrpName;
		for(int i=0; i<pGrid->RowCount-1;i++)
		{
			strGrpName = IniGroup->ReadString("GROUP", "NAME"+IntToStr(i+1), "");
			pGrid->Cells[1][i+1] = strGrpName;
		}
		pGrid->Refresh();
        delete IniGroup;
        return true;
	}
    else
    {
		delete IniGroup;
        return false;
	}
}
//---------------------------------------------------------------------------
bool  TRecipeChangeForm::GroupName_Save(TStringGrid *pGrid)
{
	TIniFile *IniGroup = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\GroupName.ini");
	if(IniGroup != NULL)
	{
		m_LastGroupNo = 0;
		for(int i=0; i<pGrid->RowCount-1;i++)
		{
			IniGroup->WriteString("GROUP","NAME"+IntToStr(i+1),pGrid->Cells[1][i+1]);

			if(pGrid->Cells[1][i+1].IsEmpty()==false)	m_LastGroupNo = i+1;
		}

		if(m_LastGroupNo <= 0)
		{
			m_LastGroupNo = 1;
		}
		IniGroup->WriteInteger("GROUP", "_LAST", m_LastGroupNo);
		delete IniGroup;
		return true;

	}
	else
	{
		delete IniGroup;
		return false;
	}
}
//---------------------------------------------------------------------------
void __fastcall TRecipeChangeForm::BtnInputRecipeNameClick(TObject *Sender)
{
	for(int i=m_LastRecipeNo; i<_MAX_RCP_NO_;i++)
	{
		RecipeControlGrid->Cells[1][i+1] = "";
		RecipeControlGrid->Cells[1][i+1] = "";
	}
	m_LastRecipeNo = _MAX_RCP_NO_;
	RecipeControlGrid->RowCount = _MAX_RCP_NO_+1;

    BtnInputRecipeName->Enabled = false;
    BtnSaveRecipeName->Enabled = true;

    RecipeControlGrid->Options<<goEditing;
    RecipeControlGrid->Options>>goRowSelect;
}
//---------------------------------------------------------------------------

void __fastcall TRecipeChangeForm::BtnSaveRecipeNameClick(TObject *Sender)
{
    BtnInputRecipeName->Enabled = true;
    BtnSaveRecipeName->Enabled = false;

    RecipeControlGrid->Options>>goEditing;
    RecipeControlGrid->Options<<goRowSelect;

    this->RecipeName_Save(m_groupNo,RecipeControlGrid);
    this->RecipeName_Read(m_groupNo,RecipeControlGrid);
}
//---------------------------------------------------------------------------

bool   TRecipeChangeForm::RecipeName_Read(int nGrpNo, TStringGrid *pGrid, bool bChange)
{
	TIniFile *RecipeNameini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\RecipeName.ini");
	if(RecipeNameini != NULL)
	{
		if(bChange)
		{
			m_LastRecipeNo = RecipeNameini->ReadInteger("GROUP_"+IntToStr(m_groupNo), "_LAST", 1);
			if(m_LastRecipeNo <= 0)
			{
				m_LastRecipeNo = 1;
			}
			pGrid->RowCount = m_LastRecipeNo+1;
		}

		for(int i=0; i<pGrid->RowCount-1;i++)
		{
			pGrid->Cells[1][i+1] = RecipeNameini->ReadString("GROUP_"+IntToStr(nGrpNo),"RECIPENAME"+IntToStr(i+1),"");
		}
		pGrid->Refresh();
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
bool  TRecipeChangeForm::RecipeName_Save(int nGrpIndex, TStringGrid *pGrid)
{
	TIniFile *RecipeNameini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\RecipeName.ini");
	if(RecipeNameini != NULL)
	{
		m_LastRecipeNo = 0;
		for(int i=0; i<pGrid->RowCount-1;i++)
		{
			RecipeNameini->WriteString("GROUP_"+IntToStr(nGrpIndex),"RECIPENAME"+IntToStr(i+1),pGrid->Cells[1][i+1]);

			if(pGrid->Cells[1][i+1].IsEmpty()==false)	m_LastRecipeNo = i+1;
		}

		if(m_LastRecipeNo <= 0)
		{
			m_LastRecipeNo = 1;
		}
		RecipeNameini->WriteInteger("GROUP_"+IntToStr(nGrpIndex), "_LAST", m_LastRecipeNo);
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

String   TRecipeChangeForm::RecipeName_ReturnString(int nGroupIndex, int nRecipeIndex)
{
	TIniFile *RecipeNameini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\RecipeName.ini");

	if(RecipeNameini != NULL)
	{
		String RetStr = RecipeNameini->ReadString("GROUP_"+IntToStr(nGroupIndex),"RECIPENAME"+IntToStr(nRecipeIndex),"RECIPE Name"+IntToStr(nRecipeIndex));
		delete RecipeNameini;
		return RetStr;
	}
	delete RecipeNameini;
	return "";
}
//---------------------------------------------------------------------------

bool  TRecipeChangeForm::RecipePath_Check(int ngrpindex, int nrcpindex)
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

	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(ngrpindex)+"\\RCP"+IntToStr(nrcpindex)+"\\StaubliData.ini") == false)
	{
		return false;
	}

	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(ngrpindex)+"\\RCP"+IntToStr(nrcpindex)+"\\exportData.ini") == false)
	{
		return false;
	}
	return true;
}
//---------------------------------------------------------------------------
void   TRecipeChangeForm::RecipeCheck_Display(int nGrpNo, TStringGrid *pGrid)
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
bool   TRecipeChangeForm::MotionConvert()
{
//	for(int nLoopAxis=0; nLoopAxis<MAX_MT_NO; nLoopAxis++)
//	{
//		g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_MT_TABLE;
//		g_MMIComm->m_mmiToSeq.buffer.motTable.nMtNo = nLoopAxis;
//		if (g_MMIComm->Send()  && g_MMIComm->Recv())
//		{
//			String StrPath = ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(m_groupNo)+"\\RCP"+IntToStr(m_IntendRecipeNo)+"\\Motor"+ IntToStr(nLoopAxis)+".ini";
//			TIniFile *TempMotorchangeini = new TIniFile(StrPath);
//		}
//		else
//		{
//        	return false;
//		}
//
//		if(TempMotorchangeini != NULL)
//		{
//            for(int i=0; i<50; i++)
//			{
//				String bufpos = TempMotorchangeini->ReadString("INDEXPOS","POSITION"+IntToStr(i),"0");
//
//				if(bufpos == 0 || bufpos == "")
//				{
//                    g_MMIComm->m_mmiToSeq.buffer.motTable.dPos[i] = 0;
//
//                }
//                else
//                {
//					g_MMIComm->m_mmiToSeq.buffer.motTable.dPos [i] = StrToFloat(bufpos) * 1000.0;;
//                }
//
//                String bufspd = TempMotorchangeini->ReadString("INDEXSPD","SPEED"+IntToStr(i),"0");
//
//                if(bufspd == 0 || bufspd == "")
//				{
//                     g_MMIComm->m_mmiToSeq.buffer.motTable.dVel [i] = 0;
//                }
//                else
//                {
//                     g_MMIComm->m_mmiToSeq.buffer.motTable.dVel [i] = StrToFloat(bufspd) * 1000.0;;
//				}
//
//                String bufVel = TempMotorchangeini->ReadString("INDEXACC","ACC"+IntToStr(i),"0");
//
//                if(bufVel == 0 || bufVel == "")
//                {
//					 g_MMIComm->m_mmiToSeq.buffer.motTable.dAcc[i] = 0;
//                }
//                else
//                {
//                     g_MMIComm->m_mmiToSeq.buffer.motTable.dAcc[i] = StrToFloat(bufVel) * 1000.0;;
//                }
//			}
//
//			g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_MT_TABLE;
//        	g_MMIComm->m_mmiToSeq.buffer.motTable.nMtNo = nLoopAxis;
//            if(g_MMIComm->Send()  && g_MMIComm->Recv())
//			{
//            	delete TempMotorchangeini;
//			}
//            else
//            {
//				delete TempMotorchangeini;
//            	return false;
//			}
//        }
//		else
//        {
//			delete TempMotorchangeini;
//			return false;
//		}
//	}
//	return true;


	for(int nLoopAxis=0; nLoopAxis<MAX_MT_NO; nLoopAxis++)
	{
		g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_MT_TABLE;
		g_MMIComm->m_mmiToSeq.buffer.motTable.nMtNo = nLoopAxis;

		if(g_MMIComm->Send()  && g_MMIComm->Recv())
		{
			String strCmnPath = ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP0\\RCP0\\Motor"+ IntToStr(nLoopAxis)+".ini";
			String StrPath = ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(m_groupNo)+"\\RCP"+IntToStr(m_IntendRecipeNo)+"\\Motor"+ IntToStr(nLoopAxis)+".ini";
			String StrNamePath = ExtractFilePath(Application->ExeName)+ "\\Ini\\MotorIndexName.ini";

			TIniFile *cmnIni = new TIniFile(strCmnPath);
			TIniFile *TempMotorchangeini = new TIniFile(StrPath);
			TIniFile *iniName = new TIniFile(StrNamePath);

			TIniFile* iniFile;

			if(TempMotorchangeini != NULL)
			{
				for(int i=0; i<50; i++)
				{
					iniFile = TempMotorchangeini;
					if(iniName->ReadBool("INDEXNAME"+IntToStr(nLoopAxis),"COMMON"+IntToStr(i),true))
					{
						iniFile = cmnIni;
					}

					String bufpos = iniFile->ReadString("INDEXPOS","POSITION"+IntToStr(i),"0");

					if(bufpos == 0 || bufpos == "")
					{
						g_MMIComm->m_mmiToSeq.buffer.motTable.dPos[i] = 0;

					}
					else
					{
						g_MMIComm->m_mmiToSeq.buffer.motTable.dPos [i] = StrToFloat(bufpos) * 1000.0;;
					}

					String bufspd = iniFile->ReadString("INDEXSPD","SPEED"+IntToStr(i),"0");

					if(bufspd == 0 || bufspd == "")
					{
						 g_MMIComm->m_mmiToSeq.buffer.motTable.dVel [i] = 0;
					}
					else
					{
						 g_MMIComm->m_mmiToSeq.buffer.motTable.dVel [i] = StrToFloat(bufspd) * 1000.0;;
					}

					String bufVel = iniFile->ReadString("INDEXACC","ACC"+IntToStr(i),"0");

					if(bufVel == 0 || bufVel == "")
					{
						 g_MMIComm->m_mmiToSeq.buffer.motTable.dAcc[i] = 0;
					}
					else
					{
						 g_MMIComm->m_mmiToSeq.buffer.motTable.dAcc[i] = StrToFloat(bufVel) * 1000.0;;
					}
				}

				delete iniName;
				delete cmnIni;
				delete TempMotorchangeini;

				g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_MT_TABLE;
				if(g_MMIComm->Send()  && g_MMIComm->Recv())
				{

				}
				else
				{
					return false;
				}
			}
			else
			{
				delete iniName;
				delete cmnIni;
				delete TempMotorchangeini;
				return false;
			}
		}
		else return false;
	}

	return true;
}
//---------------------------------------------------------------------------
bool   TRecipeChangeForm::MotionConvert(int nGrpNo, int RcpNo)
{
	for(int nLoopAxis=0; nLoopAxis<MAX_MT_NO; nLoopAxis++)
	{
		g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_MT_TABLE;
		g_MMIComm->m_mmiToSeq.buffer.motTable.nMtNo = nLoopAxis;

		if(g_MMIComm->Send()  && g_MMIComm->Recv())
		{
			String strCmnPath = ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP0\\RCP0\\Motor"+ IntToStr(nLoopAxis)+".ini";
			String StrPath = ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(nGrpNo)+"\\RCP"+IntToStr(RcpNo)+"\\Motor"+ IntToStr(nLoopAxis)+".ini";
			String StrNamePath = ExtractFilePath(Application->ExeName)+ "\\Ini\\MotorIndexName.ini";

			TIniFile *cmnIni = new TIniFile(strCmnPath);
			TIniFile *TempMotorchangeini = new TIniFile(StrPath);
			TIniFile *iniName = new TIniFile(StrNamePath);

			TIniFile* iniFile;

			if(TempMotorchangeini != NULL)
			{
				for(int i=0; i<50; i++)
				{
					iniFile = TempMotorchangeini;
					if(iniName->ReadBool("INDEXNAME"+IntToStr(nLoopAxis),"COMMON"+IntToStr(i),true))
					{
						iniFile = cmnIni;
					}

					String bufpos = iniFile->ReadString("INDEXPOS","POSITION"+IntToStr(i),"0");

					if(bufpos == 0 || bufpos == "")
					{
						g_MMIComm->m_mmiToSeq.buffer.motTable.dPos[i] = 0;

					}
					else
					{
						g_MMIComm->m_mmiToSeq.buffer.motTable.dPos [i] = StrToFloat(bufpos) * 1000.0;;
					}

					String bufspd = iniFile->ReadString("INDEXSPD","SPEED"+IntToStr(i),"0");

					if(bufspd == 0 || bufspd == "")
					{
						 g_MMIComm->m_mmiToSeq.buffer.motTable.dVel [i] = 0;
					}
					else
					{
						 g_MMIComm->m_mmiToSeq.buffer.motTable.dVel [i] = StrToFloat(bufspd) * 1000.0;;
					}

					String bufVel = iniFile->ReadString("INDEXACC","ACC"+IntToStr(i),"0");

					if(bufVel == 0 || bufVel == "")
					{
						 g_MMIComm->m_mmiToSeq.buffer.motTable.dAcc[i] = 0;
					}
					else
					{
						 g_MMIComm->m_mmiToSeq.buffer.motTable.dAcc[i] = StrToFloat(bufVel) * 1000.0;;
					}
				}

				delete iniName;
				delete cmnIni;
				delete TempMotorchangeini;

				g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_MT_TABLE;
				if(g_MMIComm->Send()  && g_MMIComm->Recv())
				{

				}
				else
				{
					return false;
				}
			}
			else
			{
				delete iniName;
				delete cmnIni;
				delete TempMotorchangeini;
				return false;
			}
		}
		else return false;
	}

	return true;
}
//---------------------------------------------------------------------------
#define   _PKGDATA_COUNT_            1000
bool   TRecipeChangeForm::PKGDataConvert()
{
	TIniFile * TempPKGchangeini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(m_groupNo)+"\\RCP"+IntToStr(m_IntendRecipeNo)+"\\PkgParam.ini");

	if(TempPKGchangeini != NULL)
    {
		g_MMIComm->m_mmiToSeq.buffer.pkg.nStart = 0;
        g_MMIComm->m_mmiToSeq.buffer.pkg.nEnd  =_PKGDATA_COUNT_;

		for(int i=0; i<_PKGDATA_COUNT_; i++)
		{
			String StrTemp = TempPKGchangeini->ReadString("PKGPARM","VALUE"+IntToStr(i),IntToStr(i));

			if(StrTemp == "")
			{
                StrTemp = "0";
			}

			double dData = StrToFloat( StrTemp );
        	g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[i] = dData;
		}
		delete TempPKGchangeini;
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
	else
	{
		delete TempPKGchangeini;
		return false;
	}
}
//---------------------------------------------------------------------------
bool   TRecipeChangeForm::PKGDataConvert(int nGrpNo, int RcpNo)
{
	TIniFile * TempPKGchangeini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(nGrpNo)+"\\RCP"+IntToStr(RcpNo)+"\\PkgParam.ini");

    if(TempPKGchangeini != NULL)
    {
        g_MMIComm->m_mmiToSeq.buffer.pkg.nStart = 0;
        g_MMIComm->m_mmiToSeq.buffer.pkg.nEnd  =_PKGDATA_COUNT_;

        for(int i=0; i<_PKGDATA_COUNT_; i++)
        {
            String StrTemp = TempPKGchangeini->ReadString("PKGPARM","VALUE"+IntToStr(i),IntToStr(i));

            if(StrTemp == "")
            {
                StrTemp = "0";
            }

            double dData = StrToFloat( StrTemp );
        	g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[i] = dData;
        }
        delete TempPKGchangeini;
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
	else
    {
        delete TempPKGchangeini;
        return false;
    }
}
//---------------------------------------------------------------------------
bool   TRecipeChangeForm::StaubliDataConvert()
{
	TIniFile * TempPKGchangeini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(m_groupNo)+"\\RCP"+IntToStr(m_IntendRecipeNo)+"\\StaubliData.ini");

    if(TempPKGchangeini != NULL)
    {
        g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_STAUBLI_TABLE;
        if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
        {
            for(int i=0; i<30; i++)
            {
            	String StrTemp = TempPKGchangeini->ReadString("XPOS","VALUE"+IntToStr(i),IntToStr(i));

                if(StrTemp == "")
                {
                    StrTemp = "0";
                }

	            double dData = StrToFloat( StrTemp );
                g_MMIComm->m_mmiToSeq.buffer.staubliTable.posX[i] = dData;

                //
                StrTemp = TempPKGchangeini->ReadString("YPOS","VALUE"+IntToStr(i),IntToStr(i));

                if(StrTemp == "")
                {
                    StrTemp = "0";
                }

	            dData = StrToFloat( StrTemp );
                g_MMIComm->m_mmiToSeq.buffer.staubliTable.posY[i] = dData;

                  ///
                StrTemp = TempPKGchangeini->ReadString("ZPOS","VALUE"+IntToStr(i),IntToStr(i));

                if(StrTemp == "")
                {
                    StrTemp = "0";
                }

	            dData = StrToFloat( StrTemp );
                g_MMIComm->m_mmiToSeq.buffer.staubliTable.posZ[i] = dData;

                //
                StrTemp = TempPKGchangeini->ReadString("RZPOS","VALUE"+IntToStr(i),IntToStr(i));

                if(StrTemp == "")
                {
                    StrTemp = "0";
                }

	            dData = StrToFloat( StrTemp );
                g_MMIComm->m_mmiToSeq.buffer.staubliTable.posRZ[i] = dData;
                //
                StrTemp = TempPKGchangeini->ReadString("ZOFFSET","VALUE"+IntToStr(i),IntToStr(i));

                if(StrTemp == "")
                {
                    StrTemp = "0";
                }

	            dData = StrToFloat( StrTemp );
                g_MMIComm->m_mmiToSeq.buffer.staubliTable.posZOffset[i] = dData;

                 //
                StrTemp = TempPKGchangeini->ReadString("SPEED","VALUE"+IntToStr(i),IntToStr(i));

				if(StrTemp == "")
                {
                    StrTemp = "0";
                }

				dData = StrToFloat( StrTemp );
                g_MMIComm->m_mmiToSeq.buffer.staubliTable.speed[i] = dData;
            }

            delete TempPKGchangeini;
			g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_STAUBLI_TABLE;
			if(g_MMIComm->Send() && g_MMIComm->Recv())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			delete TempPKGchangeini;
			return false;
		}
	}
	else
	{
		delete TempPKGchangeini;
		return false;
	}

}
//---------------------------------------------------------------------------
bool   TRecipeChangeForm::StaubliDataConvert(int nGrpNo, int nRcpNo)
{
	TIniFile * TempPKGchangeini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(nGrpNo)+"\\RCP"+IntToStr(nRcpNo)+"\\StaubliData.ini");
    String StrCommonPath = ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP0\\RCP0\\StaubliData.ini";
    String StrNamePath = ExtractFilePath(Application->ExeName)+ "\\Ini\\StaubliIndexName.ini";

    TIniFile *iniCmn = new TIniFile(StrCommonPath);
    TIniFile *iniName = new TIniFile(StrNamePath);

    bool bResult;
    if(TempPKGchangeini != NULL)
    {
        g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_STAUBLI_TABLE;
		if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
        {
            for(int i=0; i<30; i++)
            {
             	bool bCommon = iniName->ReadBool("INDEXNAME","COMMON"+IntToStr(i), true);

            	String StrTemp;

                if ( bCommon == true )
                {
                	StrTemp= iniCmn->ReadString("XPOS","VALUE"+IntToStr(i),IntToStr(i));
                }
                else
                {
                   StrTemp= TempPKGchangeini->ReadString("XPOS","VALUE"+IntToStr(i),IntToStr(i));
                }

                if(StrTemp == "")
				{
                    StrTemp = "0";
                }

	            double dData = StrToFloat( StrTemp );
                g_MMIComm->m_mmiToSeq.buffer.staubliTable.posX[i] = dData;

                //
                if ( bCommon == true )
                {
                	StrTemp= iniCmn->ReadString("YPOS","VALUE"+IntToStr(i),IntToStr(i));
                }
                else
                {
                   StrTemp = TempPKGchangeini->ReadString("YPOS","VALUE"+IntToStr(i),IntToStr(i));
                }

                if(StrTemp == "")
                {
                    StrTemp = "0";
				}

	            dData = StrToFloat( StrTemp );
                g_MMIComm->m_mmiToSeq.buffer.staubliTable.posY[i] = dData;

				  ///
                if ( bCommon == true )
                {
                	StrTemp = iniCmn->ReadString("ZPOS","VALUE"+IntToStr(i),IntToStr(i));
                }
                else
                {
                	StrTemp = TempPKGchangeini->ReadString("ZPOS","VALUE"+IntToStr(i),IntToStr(i));
                }

                if(StrTemp == "")
                {
					StrTemp = "0";
                }

	            dData = StrToFloat( StrTemp );
                g_MMIComm->m_mmiToSeq.buffer.staubliTable.posZ[i] = dData;

                //
                if ( bCommon == true )
                {
                	StrTemp = iniCmn->ReadString("RZPOS","VALUE"+IntToStr(i),IntToStr(i));
                }
                else
                {
                	StrTemp = TempPKGchangeini->ReadString("RZPOS","VALUE"+IntToStr(i),IntToStr(i));
                }

                if(StrTemp == "")
				{
                    StrTemp = "0";
                }

	            dData = StrToFloat( StrTemp );
				g_MMIComm->m_mmiToSeq.buffer.staubliTable.posRZ[i] = dData;
                //

                if ( bCommon == true )
                {
					StrTemp = iniCmn->ReadString("ZOFFSET","VALUE"+IntToStr(i),IntToStr(i));
                }
                else
                {
					StrTemp = TempPKGchangeini->ReadString("ZOFFSET","VALUE"+IntToStr(i),IntToStr(i));
                }
				if(StrTemp == "")
				{
					StrTemp = "0";
				}

				dData = StrToFloat( StrTemp );
				g_MMIComm->m_mmiToSeq.buffer.staubliTable.posZOffset[i] = dData;

				 //
				StrTemp = TempPKGchangeini->ReadString("SPEED","VALUE"+IntToStr(i),IntToStr(i));

                if(StrTemp == "")
                {
                    StrTemp = "0";
                }

	            dData = StrToFloat( StrTemp );
                g_MMIComm->m_mmiToSeq.buffer.staubliTable.speed[i] = dData;
            }
            g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_STAUBLI_TABLE;
            if(g_MMIComm->Send() && g_MMIComm->Recv())
            {
                bResult = true;
            }
            else
            {
                bResult = false;
            }
        }
        else
        {
            bResult = false;
        }
    }
	else
    {
        bResult = false;
    }

    delete TempPKGchangeini;
    delete iniCmn;
    delete iniName;

    return bResult;

}
//---------------------------------------------------------------------------

#define   _PKG_MATCH_PICK_                100
#define   _PKG_MATCH_QC_                  300

bool   TRecipeChangeForm::GerberDataConvert()
{
	TIniFile * ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(m_groupNo)+"\\RCP"+IntToStr(m_IntendRecipeNo)+"\\exportData.ini");

	if(ini != NULL)
	{

	//100 번대
		int ncnt = ini->ReadInteger("PATH_ARRAY_INFO","PICK_COUNT",1);


		g_MMIComm->m_mmiToSeq.buffer.pkg.nStart = _PKG_MATCH_PICK_;
		g_MMIComm->m_mmiToSeq.buffer.pkg.nEnd  =_PKG_MATCH_PICK_ + (ncnt*2)-1;

		int index = _PKG_MATCH_PICK_;
		for(int i=_PKG_MATCH_PICK_; i<(_PKG_MATCH_PICK_ + ncnt); i++)
		{
			String StrTemp = ini->ReadString("PATH_ARRAY_INFO","PICK_POINT" + IntToStr(i)+"_X","0");

			if(StrTemp == "")
			{
				StrTemp = "0";
			}

			double dData = StrToFloat( StrTemp );
			g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[index++] = dData;

			StrTemp = ini->ReadString("PATH_ARRAY_INFO","PICK_POINT" + IntToStr(i)+"_Y","0");

			if(StrTemp == "")
			{
				StrTemp = "0";
			}

			dData = StrToFloat( StrTemp );
			g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[index++] = dData;

		}
		g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_PKG;

		if(g_MMIComm->Send() && g_MMIComm->Recv())
		{
			delete ini;
			return true;
		}
		else
		{
			delete ini;
			return false;
		}

		//300번대
		ncnt = ini->ReadInteger("PATH_ARRAY_INFO","QC_COUNT",1);


		g_MMIComm->m_mmiToSeq.buffer.pkg.nStart = _PKG_MATCH_QC_;
		g_MMIComm->m_mmiToSeq.buffer.pkg.nEnd  =_PKG_MATCH_QC_ + (ncnt*2)-1;

		index = _PKG_MATCH_QC_;
		for(int i=_PKG_MATCH_QC_; i<(_PKG_MATCH_QC_ + ncnt); i++)
		{
			String StrTemp = ini->ReadString("PATH_ARRAY_INFO","QC_POINT" + IntToStr(i)+"_X","0");

			if(StrTemp == "")
			{
				StrTemp = "0";
			}

			double dData = StrToFloat( StrTemp );
			g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[index++] = dData;

			StrTemp = ini->ReadString("PATH_ARRAY_INFO","QC_POINT" + IntToStr(i)+"_Y","0");

			if(StrTemp == "")
			{
				StrTemp = "0";
			}

			dData = StrToFloat( StrTemp );
			g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[index++] = dData;

		}
		delete ini;
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
	else
	{
		delete ini;
		return false;
	}
}
//---------------------------------------------------------------------------
bool   TRecipeChangeForm::GerberDataConvert(int nGrpNo, int nRcpNo)
{
	TIniFile * ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(nGrpNo)+"\\RCP"+IntToStr(nRcpNo)+"\\exportData.ini");

	if(ini != NULL)
	{

	//100 번대
		int ncnt = ini->ReadInteger("PATH_ARRAY_INFO","PICK_COUNT",1);


		g_MMIComm->m_mmiToSeq.buffer.pkg.nStart = _PKG_MATCH_PICK_;
		g_MMIComm->m_mmiToSeq.buffer.pkg.nEnd  =_PKG_MATCH_PICK_ + (ncnt*2)-1;

		int index = _PKG_MATCH_PICK_;
		for(int i=_PKG_MATCH_PICK_; i<(_PKG_MATCH_PICK_ + ncnt); i++)
		{
			String StrTemp = ini->ReadString("PATH_ARRAY_INFO","PICK_POINT" + IntToStr(i)+"_X","0");

			if(StrTemp == "")
			{
				StrTemp = "0";
			}

			double dData = StrToFloat( StrTemp );
			g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[index++] = dData;

			StrTemp = ini->ReadString("PATH_ARRAY_INFO","PICK_POINT" + IntToStr(i)+"_Y","0");

			if(StrTemp == "")
			{
				StrTemp = "0";
			}

			dData = StrToFloat( StrTemp );
			g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[index++] = dData;

		}
		g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_PKG;

		if(g_MMIComm->Send() && g_MMIComm->Recv())
		{
			delete ini;
			return true;
		}
		else
		{
			delete ini;
			return false;
		}

		//300번대
		ncnt = ini->ReadInteger("PATH_ARRAY_INFO","QC_COUNT",1);


		g_MMIComm->m_mmiToSeq.buffer.pkg.nStart = _PKG_MATCH_QC_;
		g_MMIComm->m_mmiToSeq.buffer.pkg.nEnd  =_PKG_MATCH_QC_ + (ncnt*2)-1;

		index = _PKG_MATCH_QC_;
		for(int i=_PKG_MATCH_QC_; i<(_PKG_MATCH_QC_ + ncnt); i++)
		{
			String StrTemp = ini->ReadString("PATH_ARRAY_INFO","QC_POINT" + IntToStr(i)+"_X","0");

			if(StrTemp == "")
			{
				StrTemp = "0";
			}

			double dData = StrToFloat( StrTemp );
			g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[index++] = dData;

			StrTemp = ini->ReadString("PATH_ARRAY_INFO","QC_POINT" + IntToStr(i)+"_Y","0");

			if(StrTemp == "")
			{
				StrTemp = "0";
			}

			dData = StrToFloat( StrTemp );
			g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[index++] = dData;

		}
		delete ini;
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
	else
	{
		delete ini;
		return false;
	}
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void __fastcall TRecipeChangeForm::BtnGroupRecipeGridMoveupClick(TObject *Sender)
{
	// 한 화면에 보여지는 Cell 수 13.
	if(GroupControlGrid->TopRow >= 13)
	{
		GroupControlGrid->TopRow = GroupControlGrid->TopRow - 12;
    }
    else
    {
        GroupControlGrid->TopRow = 1;
	}
}
//---------------------------------------------------------------------------
void __fastcall TRecipeChangeForm::BtnGroupRecipeGridMoveDownClick(TObject *Sender)
{
	if(m_LastGroupNo <= 12) return;
	if(GroupControlGrid->TopRow >= m_LastGroupNo-10) return;

	if(GroupControlGrid->TopRow <= _MAX_GRP_NO_-10)
    {
		GroupControlGrid->TopRow = GroupControlGrid->TopRow + 12;
	}
	else
	{
		GroupControlGrid->TopRow = _MAX_GRP_NO_-10;
	}
}
//---------------------------------------------------------------------------
void __fastcall TRecipeChangeForm::BtnRecipeGridMoveUpClick(TObject *Sender)
{
	// 한 화면에 보여지는 Cell 수 13.
	if(RecipeControlGrid->TopRow >= 13)
	{
		RecipeControlGrid->TopRow = RecipeControlGrid->TopRow - 12;
    }
	else
	{
        RecipeControlGrid->TopRow = 1;
	}
}
//---------------------------------------------------------------------------
void __fastcall TRecipeChangeForm::BtnRecipeGridMoveDownClick(TObject *Sender)
{
	if(m_LastRecipeNo <= 12) return;
	if(RecipeControlGrid->TopRow >= m_LastRecipeNo-10) return;

	if(RecipeControlGrid->TopRow <= _MAX_RCP_NO_-10)
    {
		RecipeControlGrid->TopRow = RecipeControlGrid->TopRow + 12;
    }
    else
    {
		RecipeControlGrid->TopRow = _MAX_RCP_NO_-10;
	}
}
//---------------------------------------------------------------------------
void __fastcall TRecipeChangeForm::RecipeControlGridDrawCell(TObject *Sender, int ACol,
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
        	pGrid->Canvas->Brush->Color = clSilver;
    		pGrid->Canvas->Font->Color = clBlack;
        }

        pGrid->Canvas->FillRect(pGrid->CellRect(ACol,ARow));
        DrawText(pGrid->Canvas->Handle,
        pGrid->Cells[ACol][ARow].c_str(), pGrid->Cells[ACol][ARow].Length(),
        &Rect, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
    }
}
//---------------------------------------------------------------------------
void __fastcall TRecipeChangeForm::RecipeControlGridSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect)
{
	if(RecipeControlGrid->Cells[1][ARow] != "" && RecipeControlGrid->Cells[2][ARow] != "NO")
	{
        PanelSelectRecipe->Caption = IntToStr(ARow) + " : " + RecipeControlGrid->Cells[1][ARow];
        BtnRecipeChange->Enabled = true;
        m_IntendRecipeNo = ARow;
        LabelNotifyRecipe->Font->Color = clNavy;
    	LabelNotifyRecipe ->Caption = "RECIPE SELECT  : " + PanelSelectRecipe->Caption;
	}
	else
	{
        LabelNotifyRecipe->Font->Color = clRed;
    	LabelNotifyRecipe ->Caption = "RECIPE SELECT  : ";
		BtnRecipeChange->Enabled = false;
    }
}
//---------------------------------------------------------------------------
void __fastcall TRecipeChangeForm::ProgressTimerTimer(TObject *Sender)
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
void __fastcall TRecipeChangeForm::BtnRecipeChangeClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;
	TIniFile *RecipeNameini;
	FrmCdBox->setFlag(CD_YESNO);
	FrmCdBox->setTitle("RECIPE DATA CHANGE");
	FrmCdBox->setText("Are sure CHANGE the RECIPE?");
	if( mrYes == FrmCdBox->ShowModal())
	{
		nDisplayProgress = 0;
		PanelProgress->Visible = true;
		PanelProgress->Top = 430;
		PanelProgress->Left = 350;

		ProgressTimer->Enabled = false;
		ProgressTimer->Enabled = true;

		if(m_IntendRecipeNo != 0)
		{
			nDisplayProgress = 10;
			if(MotionConvert() == true)
			{
				nDisplayProgress = 30;
				if(PKGDataConvert() == true)
				{
					nDisplayProgress = 50;
					if(StaubliDataConvert() == true)
                	{
//                    	if(GerberDataConvert()== true)
//						{
                        	nDisplayProgress = 70;
							if(CheckBoxVisionConversionCommand->Checked == true)
							{
								String StrRcpName = this->RecipeName_ReturnString(m_groupNo, m_IntendRecipeNo);

								if(StrRcpName != "")
								{
									if(FrmVisionSetUp->JobChangeVisionConversion(StrRcpName) == false)
									{
										nDisplayProgress = 100;
										FrmCdBox->setFlag(CD_OK);
										FrmCdBox->setTitle("VISION RECIPE CHANGE!");
										FrmCdBox->setText("CHECK the vision connect Status for recipe change!");
										FrmCdBox->ShowModal();
									}
									else
									{
										nDisplayProgress = 100;
										FrmCdBox->setFlag(CD_OK);
										FrmCdBox->setTitle("RECIPE CHANGE !");
                                        FrmCdBox->setText("Success to RECIPE Change!");
                                        FrmCdBox->ShowModal();

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

							nWriteCommunicationDM(0, qcCntStage1);
							nWriteCommunicationDM(0, qcCntStage2);
							nWriteCommunicationDM(0, qcCntStage3);
							nWriteCommunicationDM(0, qcCntStage4);
							nWriteCommunicationDM(0, stateQcDataSendR);

							nWriteCommunicationDM(0, VcutVisionSaveStatus);
							nWriteCommunicationDM(0, VcutVisionSaveTriggerCount);
							FrmVisionSetUp->JobChangeVCutVision("IMAGEOFF");
							MainForm->MachineHistoryData("V_Cut Recipe Change : VcutVisionSaveTriggerCount 0, VcutVisionSaveStatus 0 Complete Reset");

							// use
							UseSkipControl(usBtmVi, true);
							UseSkipControl(usTopVi, true);
							UseSkipControl(usTrayVi, true);
							UseSkipControl(usQcVi, true);

                            //Complete
							nWriteCommunicationDM(m_groupNo , groupNo);
							nWriteCommunicationDM(m_IntendRecipeNo , jobNo);

//                          MainForm->ShowRecipeInformation();
							RecipeControl_Initialize();
							FormSecsGemSet->GemRecipeChange();
//	  					  }
//                        else
//                        {
//                            nDisplayProgress = 100;
//                            FrmCdBox->setFlag(CD_OK);
//                            FrmCdBox->setTitle("GERBER DATA RECIPE!");
//                            FrmCdBox->setText("Fail to change GERBER RECIPE!");
//                            FrmCdBox->ShowModal();
//                            return;
//                        }
                    }
					else
                    {
                        nDisplayProgress = 100;
						FrmCdBox->setFlag(CD_OK);
                        FrmCdBox->setTitle("STAUBLI DATA RECIPE!");
                        FrmCdBox->setText("Fail to change STAUBLI RECIPE!");
                        FrmCdBox->ShowModal();
                        return;
					}
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
void __fastcall TRecipeChangeForm::GroupControlGridDrawCell(TObject *Sender, int ACol,
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
			pGrid->Canvas->Brush->Color = clSilver;
			pGrid->Canvas->Font->Color = clBlack;
		}

		pGrid->Canvas->FillRect(pGrid->CellRect(ACol,ARow));
		DrawText(pGrid->Canvas->Handle,
		pGrid->Cells[ACol][ARow].c_str(), pGrid->Cells[ACol][ARow].Length(),
		&Rect, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
	}
}
//---------------------------------------------------------------------------
void __fastcall TRecipeChangeForm::GroupControlGridSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect)
{
	if(GroupControlGrid->Cells[1][ARow] != "")
	{
		PanelSelectGroup->Caption = IntToStr(ARow) + " : " + GroupControlGrid->Cells[1][ARow];
		m_groupNo = ARow;
    	LabelNotifyName->Font->Color = clNavy;
        LabelNotifyName ->Caption = "GROUP SELECT : " + PanelSelectGroup->Caption ;
		RecipeName_Read(m_groupNo, RecipeControlGrid);
		RecipeCheck_Display(m_groupNo, RecipeControlGrid);
	}
    else
    {
		LabelNotifyName->Font->Color = clRed;
		LabelNotifyName ->Caption =  "GROUP SELECT : ";
    }
}
//---------------------------------------------------------------------------




void __fastcall TRecipeChangeForm::SpeedButton1Click(TObject *Sender)
{
    FrmRcpCreate->RecipeCreate_Initialize(1);
	FrmRcpCreate->ShowModal();
	this->RecipeControl_Initialize();
}
//---------------------------------------------------------------------------

void __fastcall TRecipeChangeForm::FormShow(TObject *Sender)
{
	this->RecipeControl_Initialize();
}
//---------------------------------------------------------------------------

bool   TRecipeChangeForm::autoDeviceChange()
{
	int nGrpNo = nReadCommunicationDM(autoDeviceChg_GroupNo);
	int nRcpNo = nReadCommunicationDM(autoDeviceChg_RecipeNo);

	if(MotionConvert(nGrpNo, nRcpNo) == true)
	{
		if(PKGDataConvert(nGrpNo, nRcpNo) == true)
		{
			if(StaubliDataConvert(nGrpNo, nRcpNo) == true)
			{
				if(CheckBoxVisionConversionCommand->Checked == true)
				{
					String StrRcpName = this->RecipeName_ReturnString(nGrpNo, nRcpNo);
					if(StrRcpName != "")
					{
						if(FrmVisionSetUp->JobChangeVisionConversion(StrRcpName) == false)
							return false;
					}
					else
						return false;
				}

				//Complete
				nWriteCommunicationDM(nGrpNo , groupNo);
				nWriteCommunicationDM(nRcpNo , jobNo);
				RecipeControl_Initialize();
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}
//---------------------------------------------------------------------------
void __fastcall TRecipeChangeForm::AutoDeviceChangeTimerTimer(TObject *Sender)
{
	AutoDeviceChangeTimer->Enabled = false;
	if(this->autoDeviceChange())
	{
		nWriteCommunicationDM(STATE_COMP, reqRecipeChange);
	}
	else
		nWriteCommunicationDM(STATE_ERR, reqRecipeChange);
}
//---------------------------------------------------------------------------
void __fastcall TRecipeChangeForm::DisplayRMS()
{

	{
		pnBackgroundRMS->Top	= pnMain->Top;
		pnBackgroundRMS->Left	= pnMain->Left;
		pnBackgroundRMS->Height	= pnMain->Height;
		pnBackgroundRMS->Width	= pnMain->Width;
		pnBackgroundRMS->Visible = true;

		cboxPpidList->Clear();
		TIniFile *RecipeNameini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\RecipeName.ini");
		if(RecipeNameini != NULL)
		{
			for(int _gNo=1; _gNo<=_MAX_GRP_NO_; _gNo++)
			{
				if( RecipeNameini->SectionExists("GROUP_"+IntToStr(_gNo)) )
				{
					int _last = RecipeNameini->ReadInteger("GROUP_"+IntToStr(_gNo), "_LAST", 0);
					for(int _rNo=1; _rNo<=_last; _rNo++)
					{
						String sPpid = RecipeNameini->ReadString("GROUP_"+IntToStr(_gNo),"RECIPENAME"+IntToStr(_rNo),"");
						if(sPpid.IsEmpty() == false)
						{
							cboxPpidList->Items->Add(sPpid);
						}
					}
				}
			}
			cboxPpidList->ItemIndex = 0;
		}

		PanelPPID->Caption = Get_RecipeName();
		PanelGroupNo->Caption = IntToStr(m_groupNo);
		PanelRecipeNo->Caption = IntToStr(m_recipeNo);
	}

	btnRename->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TRecipeChangeForm::btnRecipeDownloadClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;
	String strVal[5] = {"",};
	strVal[0] = edtLotId->Text.Trim();
	strVal[1] = edtPartId->Text.Trim();
	strVal[2] = cboxPpidList->Items->Strings[cboxPpidList->ItemIndex].Trim();
	strVal[3] = edtStepSeq->Text.Trim();
	strVal[4] = edtLotType->Text.Trim();

	FormSecsGemSet->manualRecipeDownload(strVal);
}
//---------------------------------------------------------------------------
void __fastcall TRecipeChangeForm::btnGetLotInfoClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;
	edtPartId->Text = "";
	edtStepSeq->Text = "";
	edtLotType->Text = "";
	pnHostRecipeId->Caption = "";

	FormSecsGemSet->GemLotInfo(2,edtLotId->Text.Trim());
}
//---------------------------------------------------------------------------
void __fastcall TRecipeChangeForm::btnExitClick(TObject *Sender)
{
	if(CheckCanAccessLevelMust(PW_ENGINEER))
	{
		pnBackgroundRMS->Visible = false;
	}
}
//---------------------------------------------------------------------------
void __fastcall TRecipeChangeForm::btnRecipeUploadClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;
	String strVal[5] = {"",};
	strVal[0] = edtLotId->Text.Trim();
	strVal[1] = edtPartId->Text.Trim();
	strVal[2] = cboxPpidList->Items->Strings[cboxPpidList->ItemIndex].Trim();
	strVal[3] = edtStepSeq->Text.Trim();
	strVal[4] = edtLotType->Text.Trim();

	FormSecsGemSet->manualRecipeUpload(strVal);
}
//---------------------------------------------------------------------------
String __fastcall strPPIDRename(String StrTempData) {
	StrTempData = StrTempData.Trim();

	String sRtn="";
	int nActualCnt = StrTempData.Length();
	if(nActualCnt <= 0) return "";

	for (int nCnt = 1; nCnt <= nActualCnt; nCnt++) {
		if(StrTempData[nCnt] == ' ')
		{
			//Nothing to do
		}
		else if(StrTempData[nCnt] == '(' || StrTempData[nCnt] == ')')
		{
			sRtn += "-";
		}
		else
			sRtn += StrTempData[nCnt];
	}
	return sRtn;
}
// ---------------------------------------------------------------------------
void __fastcall TRecipeChangeForm::btnRenameClick(TObject *Sender)
{
	TMemIniFile *RecipeNameini = new TMemIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\RecipeName.ini");
	if(RecipeNameini != NULL)
	{
		String sDelete[]={"GROUP_-1","GROUP_0"};
		for(int i=0; i<2; i++)
		{
			if(RecipeNameini->SectionExists(sDelete[i]))
				RecipeNameini->EraseSection(sDelete[i]);
		}

		for(int _gNo=1; _gNo<=_MAX_GRP_NO_; _gNo++)
		{
			if( RecipeNameini->SectionExists("GROUP_"+IntToStr(_gNo)) )
			{
				int _last = 0;
				for(int _rNo=1; _rNo<=_MAX_RCP_NO_; _rNo++)
				{
					String sPpid = RecipeNameini->ReadString("GROUP_"+IntToStr(_gNo),"RECIPENAME"+IntToStr(_rNo),"");
					if(sPpid.IsEmpty() == false)
					{
						_last = _rNo;	// Last One
						String sRename = strPPIDRename(sPpid);
						RecipeNameini->WriteString("GROUP_"+IntToStr(_gNo),"RECIPENAME"+IntToStr(_rNo),sRename);
					}
				}

				RecipeNameini->WriteInteger("GROUP_"+IntToStr(_gNo), "_LAST", _last);

			}
		}
		RecipeNameini->UpdateFile();
	}

	btnRename->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TRecipeChangeForm::lbVerRMSDblClick(TObject *Sender)
{
	btnRename->Visible = true;
}
//---------------------------------------------------------------------------
