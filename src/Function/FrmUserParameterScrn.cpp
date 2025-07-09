//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FrmUserParameterScrn.h"
#include "BaseComm.h"
#include "include.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma resource "*.dfm"
TFrmUserParameter *FrmUserParameter;

#define   _USER_PARAM_START_INDEX_DDM_     200
#define   _USER_PARAM_COUNT_DDM_           100

enum data_type
{
	pkg_data 	= 0,
	ddm_data    = 1,
	ndm_data	= 2,
};


//---------------------------------------------------------------------------
__fastcall TFrmUserParameter::TFrmUserParameter(TComponent* Owner)
	: TForm(Owner)
{
	UserParamGrid->Cells[0][0] = "NO";
    UserParamGrid->Cells[1][0] = "NAME";
	UserParamGrid->Cells[2][0] = "SET";

	ZeroMemory(m_dOldData,sizeof(m_dOldData));
}
//---------------------------------------------------------------------------
void __fastcall TFrmUserParameter::BitBtn1Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TFrmUserParameter::BtnInputItemClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	BtnInputItem->Enabled = false;
	BtnSaveItem->Enabled = true;

	UserParamGrid->Options<<goEditing;
	UserParamGrid->Options>>goRowSelect;
}
//---------------------------------------------------------------------------
void __fastcall TFrmUserParameter::BtnSaveItemClick(TObject *Sender)
{
	BtnInputItem->Enabled = true;
    BtnSaveItem->Enabled = false;

	UserParamGrid->Options>>goEditing;
    UserParamGrid->Options<<goRowSelect;

	Userparam_name_save(_nDataIndex);
	User_value_write(_nDataIndex);

	Userparam_name_read(_nDataIndex);
    User_value_read(_nDataIndex);

}
//---------------------------------------------------------------------------
void __fastcall TFrmUserParameter::FormShow(TObject *Sender)
{
	for(int i=0; i<UserParamGrid->RowCount-1;i++)
	{
		UserParamGrid->Cells[1][i+1] =  "";
		UserParamGrid->Cells[2][i+1] =  "";
	}

	_strSectionName = "PKG_PARAM";
	_nCmdType = CMD_RD_PKG;
	_nDataIndex = pkg_data;
	Userparam_name_read(pkg_data);
	User_value_read(pkg_data);

	UserParamGrid->Options>>goEditing;
	UserParamGrid->Options<<goRowSelect;

	BtnInputItem->Enabled = true;
	BtnSaveItem->Enabled = false;

	BtnPKGdata->Enabled = false;
	BtnDDMdata->Enabled = true;
	BtnNDMdata->Enabled = true;
}
//---------------------------------------------------------------------------

bool    TFrmUserParameter::Userparam_name_read(int dataType)
{
	TIniFile *UserParamini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\USERParam.ini");
	if(UserParamini != NULL)
	{
		for(int i=0; i<UserParamGrid->RowCount-1;i++)
		{
			UserParamGrid->Cells[0][i+1] =  IntToStr(i);
			int nIndex = UserParamini->ReadInteger(_strSectionName,"INDEX"+IntToStr(i), -1);
			if(nIndex >= 0 )
			{
				String strName;
				switch(dataType)
				{
					case pkg_data:
						strName = Get_PKGName(nIndex);
						break;
					case ddm_data:
						strName = Get_DDMName(nIndex);
						break;
					case ndm_data:
						strName = Get_NDMName(nIndex);
						break;
				}
				UserParamGrid->Cells[1][i+1] = strName;
			}
		}
		delete UserParamini;
		return true;
	}
	else
    {
        return false;
	}
  	delete UserParamini;
}
//------------------------------------------------------------------------
bool    TFrmUserParameter::Userparam_name_save(int dataType)
{
/*
	TIniFile *DParamini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\USERParam.ini");
    if(DParamini != NULL)
    {
		for(int i=0; i<UserParamGrid->RowCount-1;i++)
        {
            DParamini->WriteString("DPARM","NAME"+IntToStr(i),UserParamGrid->Cells[1][i+1]);
		}
        delete DParamini;
		return true;
    }
    else
    {
        return false;
	}
*/
	return true;
}
//------------------------------------------------------------------------
bool    TFrmUserParameter::User_value_read(int dataType)
{
	int nRtnVal = 0;
	double dRtnVal = 0.0f;
	TIniFile *UserParamini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\USERParam.ini");
	if(UserParamini != NULL)
	{
		g_MMIComm->m_mmiToSeq.nCmd = _nCmdType;
		g_MMIComm->m_mmiToSeq.buffer.ndm.nStart = 0;
		g_MMIComm->m_mmiToSeq.buffer.ndm.nEnd = 999;
		if(true == g_MMIComm->Send() &&  true == g_MMIComm->Recv())
		{
			for(int i=0; i<UserParamGrid->RowCount-1; i++)
			{
				int nIndex = UserParamini->ReadInteger(_strSectionName,"INDEX"+IntToStr(i), -1);

				if(nIndex < 0 )
					continue;

				switch(dataType)
				{
					case pkg_data:
						dRtnVal = g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[nIndex];
						UserParamGrid->Cells[2][i+1]= FloatToStr(dRtnVal);
						m_dOldData[i] = _wtof(UserParamGrid->Cells[2][i+1].w_str());
						break;
					case ddm_data:
						dRtnVal = g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[nIndex];
						UserParamGrid->Cells[2][i+1]= FloatToStr(dRtnVal);
						m_dOldData[i] = _wtof(UserParamGrid->Cells[2][i+1].w_str());
						break;
					case ndm_data:
						nRtnVal = g_MMIComm->m_mmiToSeq.buffer.ndm.nVal[nIndex];
						UserParamGrid->Cells[2][i+1]= IntToStr(nRtnVal);
						m_dOldData[i] = _wtoi(UserParamGrid->Cells[2][i+1].w_str());
						break;
				}
			}
			return true;
		}
		else
		{
			return false;
		}
	}
	delete UserParamini;
}
//------------------------------------------------------------------------
bool    TFrmUserParameter::User_value_write(int dataType)
{
	bool bRet = true;
	TIniFile *UserParamini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\USERParam.ini");
	if(UserParamini != NULL)
	{
		g_MMIComm->m_mmiToSeq.nCmd = _nCmdType;
		g_MMIComm->m_mmiToSeq.buffer.ndm.nStart = 0;
		g_MMIComm->m_mmiToSeq.buffer.ndm.nEnd = 999;
		if(true == g_MMIComm->Send() &&  true == g_MMIComm->Recv())
		{
			for(int i=0; i<UserParamGrid->RowCount-1; i++)
			{
				int nIndex = UserParamini->ReadInteger(_strSectionName,"INDEX"+IntToStr(i), -1);

                if(nIndex < 0 )
					continue;

				if(UserParamGrid->Cells[ 2 ][ i+1 ]  == "")
					continue;

				switch(dataType)
				{
					case pkg_data:
						g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[nIndex] = UserParamGrid->Cells[2][i+1].ToDouble();
						break;
					case ddm_data:
						g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[nIndex] = UserParamGrid->Cells[2][i+1].ToDouble();
						break;
					case ndm_data:
						g_MMIComm->m_mmiToSeq.buffer.ndm.nVal[nIndex] = UserParamGrid->Cells[2][i+1].ToInt();
						break;
				}
			}
			g_MMIComm->m_mmiToSeq.nCmd = _nCmdType+1;

			if(g_MMIComm->Send() && g_MMIComm->Recv())
			{
				bRet = true;
			}
			else
			{
				bRet = false;
			}
		}
		else
		{
			bRet = false;
		}

		if(true == bRet)
		{
			if(pkg_data == dataType)
			{
				int nGrpNo = nReadGroupNo();
				int nRcpNo = nReadRecipeNo();
				TIniFile *PkgParmini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(nGrpNo)+"\\RCP"+IntToStr(nRcpNo)+"\\PkgParam.ini");

				for(int i=0; i<UserParamGrid->RowCount-1; i++)
				{
					int nIndex = UserParamini->ReadInteger(_strSectionName,"INDEX"+IntToStr(i), -1);

					if(nIndex < 0 )
						continue;

					if(UserParamGrid->Cells[ 2 ][ i+1 ]  == "")
						continue;

					PkgParmini->WriteString("PKGPARM","VALUE"+IntToStr(nIndex),UserParamGrid->Cells[2][i+1]);

					if(MainForm->b_TpConnect)
					{
						String strData = "", strIndex = "";
						if(m_dOldData[i] != _wtof(UserParamGrid->Cells[ 2 ][ i+1 ].w_str()))
						{
							strIndex= "'"+UserParamGrid->Cells[ 1 ][ i+1 ]+"'";
							strData = "[2,"+FloatToStrF(m_dOldData[i],ffFixed,10,3)+","+UserParamGrid->Cells[ 2 ][ i+1 ]+"]";
							g_pTpBase->logConfigure(L"RECIPEDATA",L"CHANGE",strIndex.c_str(),strData.c_str());
						}
					}
				}
				delete PkgParmini;
			}
			else
			{
				for(int i=0; i<UserParamGrid->RowCount-1; i++)
				{
					int nIndex = UserParamini->ReadInteger(_strSectionName,"INDEX"+IntToStr(i), -1);
					if(nIndex < 0 )
						continue;

					if(UserParamGrid->Cells[ 2 ][ i+1 ]  == "")
						continue;

					if(MainForm->b_TpConnect)
					{
						String strData = "", strIndex = "";
						if(m_dOldData[i] != _wtof(UserParamGrid->Cells[ 2 ][ i+1 ].w_str()))
						{
							strIndex= "'"+UserParamGrid->Cells[ 1 ][ i+1 ]+"'";
							strData = "[2,"+FloatToStrF(m_dOldData[i],ffFixed,10,3)+","+UserParamGrid->Cells[ 2 ][ i+1 ]+"]";
							g_pTpBase->logConfigure(L"SYSTEMDATA",L"CHANGE",strIndex.c_str(),strData.c_str());
						}
					}
				}
			}
		}
	}
	delete UserParamini;
}
//------------------------------------------------------------------------

void __fastcall TFrmUserParameter::BtnParamIndexMoveM10Click(TObject *Sender)
{
	if(UserParamGrid->TopRow >= 20)
	{
		UserParamGrid->TopRow = UserParamGrid->TopRow - 20;
	}
	else
	{
		UserParamGrid->TopRow = 1;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmUserParameter::BtnParamIndexMoveP10Click(TObject *Sender)
{
	if(UserParamGrid->TopRow <= 400)
    {
    	UserParamGrid->TopRow += 20;
    }
    else
    {
    	UserParamGrid->TopRow = 499;
    }
}
//---------------------------------------------------------------------------

void __fastcall TFrmUserParameter::BtnPKGdataClick(TObject *Sender)
{
	for(int i=0; i<UserParamGrid->RowCount-1;i++)
	{
		UserParamGrid->Cells[1][i+1] =  "";
		UserParamGrid->Cells[2][i+1] =  "";
	}

	int nTag = dynamic_cast<TSpeedButton*>(Sender)->Tag;

	switch(nTag)
	{
		case pkg_data:
			_strSectionName = "PKG_PARAM";
			_nCmdType = CMD_RD_PKG;

			BtnPKGdata->Enabled = false;
			BtnDDMdata->Enabled = true;
			BtnNDMdata->Enabled = true;
			break;
		case ddm_data:
			_strSectionName = "DDM_PARAM";
			_nCmdType = CMD_RD_DDM;

			BtnPKGdata->Enabled = true;
			BtnDDMdata->Enabled = false;
			BtnNDMdata->Enabled = true;
			break;
		case ndm_data:
			_strSectionName = "NDM_PARAM";
			_nCmdType = CMD_RD_NDM;

			BtnPKGdata->Enabled = true;
			BtnDDMdata->Enabled = true;
			BtnNDMdata->Enabled = false;
			break;
	}

	_nDataIndex = nTag;
	UserParamGrid->Options>>goEditing;
	UserParamGrid->Options<<goRowSelect;

	BtnInputItem->Enabled = true;
	BtnSaveItem->Enabled = false;
	Userparam_name_read(nTag);
	User_value_read(nTag);
}
//---------------------------------------------------------------------------

