//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FrmUserDataViewScrn.h"
//---------------------------------------------------------------------------
#include "BaseComm.h"
//---------------------------------------------------------------------------
#include "Infovider.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma link "AdvPicture"
#pragma link "Shader"
#pragma resource "*.dfm"
TFrmUserDataView *FrmUserDataView;

#define  _MAX_USERDATA_CNT_             50

//---------------------------------------------------------------------------
__fastcall TFrmUserDataView::TFrmUserDataView(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

	// 100~299 까지 User 노출 Data
	// 100~149 : Count
	// 150~199 : Time (단위 :sec)
	// 200~299 : Pitch & 기타 (단위 : mm)

void __fastcall TFrmUserDataView::BtnUserParameter1Click(TObject *Sender)
{
    int nIndex = dynamic_cast<TComponent *>(Sender)->Tag;

	for(int i=0; i<4; i++)
	{
    	TSpeedButton  *CloneUserBtn = (TSpeedButton *)FindComponent("BtnUserParameter"+IntToStr(i+1));
    	if((i+1) == nIndex)
        {
			CloneUserBtn->Enabled = false;
            nPKGCategoryStartNo = (50*i)+100;
            nDDMCategoryStartNo = (50*i)+100;
        }
        else
        {
            CloneUserBtn->Enabled = true;
        }
    }
    UserParamDataLoad();
    UserData_ReadFromDB();

    UserData_PKG_ReadFromDB();
    UserData_PKG_ReadFromSEQ();
}
//---------------------------------------------------------------------------
void __fastcall TFrmUserDataView::FormShow(TObject *Sender)
{
	UserParamGrid->Cells[0][0] = "No";
	UserParamGrid->Cells[1][0] = "Name";
	UserParamGrid->Cells[2][0] = "Value";

	PkgParamGrid->Cells[0][0] = "No";
	PkgParamGrid->Cells[1][0] = "Name";
	PkgParamGrid->Cells[2][0] = "SET";
	PkgParamGrid->Cells[3][0] = "Value";

    nPKGCategoryStartNo = 100;
    nDDMCategoryStartNo = 100;

	UserParamInitialize();

    UserData_PKG_ReadFromDB();
    UserData_PKG_ReadFromSEQ();
}
//---------------------------------------------------------------------------
void __fastcall TFrmUserDataView::UserDataTimerTimer(TObject *Sender)
{
	UserParamDataLoad();
}
//---------------------------------------------------------------------------

 void __fastcall TFrmUserDataView::UserParamInitialize()
{
	BtnInputUserData->Enabled = true;
	BtnSaveUserData->Enabled = false;

	UserDataTimer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TFrmUserDataView::UserParamDataLoad()
{
//	MMIComm->m_mmiToSeq.nCmd = CMD_RD_DDM;
//
//	if ( MMIComm->Send() &&  MMIComm->Recv())
//	{
//		for(int i=0; i<_MAX_USERDATA_CNT_; i++)
//		{
//			int ntemp =  i+nDDMCategoryStartNo;
//			UserParamGrid->Cells[2][i+1]= MMIComm->m_mmiToSeq.buffer.dDm.dData[ntemp];
//		}
//	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmUserDataView::UserData_PKG_ReadFromSEQ()
{
//	MMIComm->m_mmiToSeq.nCmd = CMD_RD_PKG_DATA;
//
//	if ( MMIComm->Send() &&  MMIComm->Recv())
//	{
//		for(int i=0; i<_MAX_USERDATA_CNT_; i++)
//		{
//        	int ntemp =  i+nPKGCategoryStartNo;
//			double dDumpdata  = MMIComm->m_mmiToSeq.buffer.pkgData.dData[ntemp];
//
//			if(dDumpdata == NULL)
//			{
//				dDumpdata = 0;
//			}
//			PkgParamGrid->Cells[3][i+1]= FloatToStr(dDumpdata);
//		}
//	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmUserDataView::UserData_ReadFromDB()
{
//	for(int i=0; i<_MAX_USERDATA_CNT_; i++)
//	{
//		int nIndex =  (i+nDDMCategoryStartNo);
//		PkgParamGrid->Cells[0][i+1] = StringSpaceMaker(nIndex,3);
//
//		InfoviderMod->SystemBit->First();
//		DataLocateIndex(InfoviderMod->SystemBit, nIndex);
//		PkgParamGrid->Cells[1][i+1] = InfoviderMod->SystemBit->FieldByName("NAME")->AsString;
//	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmUserDataView::UserData_PKG_ReadFromDB()
{
//	for(int i=0; i<_MAX_USERDATA_CNT_; i++)
//	{
//		int nIndex =  i +nPKGCategoryStartNo;
//		PkgParamGrid->Cells[0][i+1] = StringSpaceMaker(nIndex,3);
//		DataLocateIndex(InfoviderMod->PkgName, nIndex);
//		PkgParamGrid->Cells[1][i+1]= InfoviderMod->PkgName->FieldByName("NAME")->AsString;
//
//		DataLocateIndex(InfoviderMod->PkgParam, nIndex);
//		PkgParamGrid->Cells[2][i+1]= InfoviderMod->PkgParam->FieldByName("Set")->AsString;
//	}
}
//---------------------------------------------------------------------------


void __fastcall TFrmUserDataView::UserParamDataSave()
{
//	MMIComm->m_mmiToSeq.nCmd = CMD_RD_DDM;
//
//	if ( MMIComm->Send() &&  MMIComm->Recv())
//	{
//		for(int i=0; i<_MAX_USERDATA_CNT_; i++)
//		{
//			if(UserParamGrid->Cells[2][i+1] == "")
//			{
//				UserParamGrid->Cells[2][i+1] = "0";
//			}
//			int ntemp =  i+nDDMCategoryStartNo;
//
//			MMIComm->m_mmiToSeq.buffer.dDm.nStart = ntemp;
//			MMIComm->m_mmiToSeq.buffer.dDm.nEnd = ntemp;
//			MMIComm->m_mmiToSeq.buffer.dDm.dData[ntemp] = UserParamGrid->Cells[2][i+1].ToDouble();
//		}
//
//        MMIComm->m_mmiToSeq.nCmd = CMD_WR_DDM;
//        if(MMIComm->Send() && MMIComm->Recv())
//        {
//
//        }
//        else
//        {
//            MessageDlg(" 실패", mtError, TMsgDlgButtons() << mbOK, 0);
//        }
//
//	}
//
//	int nIndex;
//	for(int i=0; i<_MAX_USERDATA_CNT_; i++)
//	{
//		nIndex =(nDDMCategoryStartNo)+i ;
//
//		try
//		{
//			InfoviderMod->SystemMem->First();
//			DataLocateIndex(InfoviderMod->SystemMem , nIndex);
//			InfoviderMod->SystemMem->Edit();
//
//			if(UserParamGrid->Cells[1][i+1] != "")
//			{
//				InfoviderMod->SystemMem->FieldByName("Name")->AsString = UserParamGrid->Cells[1][i+1];
//			}
//			else
//			{
//				InfoviderMod->SystemMem->FieldByName("Name")->AsString = "";
//			}
//
//			InfoviderMod->SystemMem->Post();
//		}
//		catch(Exception &e)
//		{
//			ShowMessage("SystemMem DB File Error : " + e.Message);
//		}
//	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmUserDataView::UserData_PKG_SaveToSEQ()
{
//	MMIComm->m_mmiToSeq.nCmd = CMD_RD_PKG_DATA;
//
//	if ( MMIComm->Send() &&  MMIComm->Recv())
//	{
//		for(int i=0; i<_MAX_USERDATA_CNT_; i++)
//		{
//			if(PkgParamGrid->Cells[2][i+1] == "")
//			{
//				PkgParamGrid->Cells[2][i+1] = "0";
//			}
//
//			MMIComm->m_mmiToSeq.buffer.pkgData.nStart = nPKGCategoryStartNo;
//			MMIComm->m_mmiToSeq.buffer.pkgData.nEnd  = nPKGCategoryStartNo+(_MAX_USERDATA_CNT_-1);
//			MMIComm->m_mmiToSeq.buffer.pkgData.dData[i+nPKGCategoryStartNo] = PkgParamGrid->Cells[2][i+1].ToDouble();
//		}
//		MMIComm->m_mmiToSeq.nCmd = CMD_WR_PKG_DATA;
//
//		if(MMIComm->Send() && MMIComm->Recv())
//		{
//
//		}
//		else
//		{
//			MessageDlg("COMMUNICATION FAIL", mtError, TMsgDlgButtons() << mbOK, 0);
//		}
//	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmUserDataView::UserData_PKG_SaveToDB()
{
//	for(int i=0; i<_MAX_USERDATA_CNT_; i++)
//	{
//		InfoviderMod->PkgName->First();
//		DataLocateIndex(InfoviderMod->PkgName , i+nPKGCategoryStartNo);
//		InfoviderMod->PkgName->Edit();
//
//		if(PkgParamGrid->Cells[1][i+1] != "")
//		{
//			InfoviderMod->PkgName->FieldByName("Name")->AsString = PkgParamGrid->Cells[1][i+1];
//		}
//		else
//		{
//			InfoviderMod->PkgName->FieldByName("Name")->AsString = "";
//		}
//
//		InfoviderMod->PkgName->Post();
//	}
//
//	for(int i=0; i<_MAX_USERDATA_CNT_; i++)
//	{
//		int nIndex = i +nPKGCategoryStartNo;
//
//		InfoviderMod->PkgParam->First();
//		DataLocateIndex(InfoviderMod->PkgParam , nIndex);
//		InfoviderMod->PkgParam->Edit();
//
//		if(PkgParamGrid->Cells[2][i+1] != "")
//		{
//			InfoviderMod->PkgParam->FieldByName("Set")->AsString = PkgParamGrid->Cells[2][i+1];
//		}
//		else
//		{
//			InfoviderMod->PkgParam->FieldByName("Set")->AsString = "";
//		}
//
//		InfoviderMod->PkgParam->Post();
//	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmUserDataView::BtnUserDataGridUpClick(TObject *Sender)
{
	if(UserParamGrid->TopRow >= 19)
    {
		UserParamGrid->TopRow = UserParamGrid->TopRow - 19;
    }
    else
    {
		UserParamGrid->TopRow = 1;
    }
}
//---------------------------------------------------------------------------
void __fastcall TFrmUserDataView::BtnUserDataGridDownClick(TObject *Sender)
{
	if(UserParamGrid->TopRow <= 31)
	{
		UserParamGrid->TopRow = UserParamGrid->TopRow + 19;
    }
    else
    {
		 UserParamGrid->TopRow = 31;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmUserDataView::BtnInputUserDataClick(TObject *Sender)
{
	BtnInputUserData->Enabled = false;
	BtnSaveUserData->Enabled = true;
	UserDataTimer->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TFrmUserDataView::BtnSaveUserDataClick(TObject *Sender)
{
	BtnInputUserData->Enabled = true;
	BtnSaveUserData->Enabled = false;
	UserParamDataSave();
	UserDataTimer->Enabled = true;

		TFileStream *File;
		TDateTime dt = Now();
		String FolderName = dt.FormatString("yyyy-mm-dd");
		String FileName = dt.FormatString("yyyy-mm-dd hh-nn-ss");
		ForceDirectories("C:\\KOSES\\History\\UserParamLog\\"+ FolderName);
		String FullPath  =  "C:\\KOSES\\History\\UserParamLog\\"+ FolderName+"\\"+FileName+".txt";

		File = new TFileStream(FullPath, fmCreate | fmOpenReadWrite);

		File->Position = 0;
		String Strtemp = "UserParamLog \r\n";
		for(int i=0; i<UserParamGrid->RowCount; i++)
		{
			Strtemp += " No:"+IntToStr(i)+ ":"+ UserParamGrid->Cells[2][i+1] +"\r\n";
		}
		File->Write(Strtemp.c_str(),Strtemp.Length());
		delete File;
        File = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TFrmUserDataView::BtnPkgGridDownClick(TObject *Sender)
{
	if(PkgParamGrid->TopRow <= 31)
	{
		PkgParamGrid->TopRow = PkgParamGrid->TopRow + 19;
    }
    else
    {
		 PkgParamGrid->TopRow = 49;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmUserDataView::BtnPkgGridUpClick(TObject *Sender)
{
	if(PkgParamGrid->TopRow >= 31)
	{
		PkgParamGrid->TopRow = PkgParamGrid->TopRow - 19;
	}
	else
	{
		PkgParamGrid->TopRow = 1;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmUserDataView::BtnInputPKGDataClick(TObject *Sender)
{
	BtnSavePKGData->Enabled = true;
	BtnInputPKGData->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TFrmUserDataView::BtnSavePKGDataClick(TObject *Sender)
{
	BtnSavePKGData->Enabled = false;
	BtnInputPKGData->Enabled = true;

	UserData_PKG_SaveToSEQ();
	UserData_PKG_SaveToDB();

	UserData_PKG_ReadFromDB();
    UserData_PKG_ReadFromSEQ();

	TFileStream *File;
	TDateTime dt = Now();
	String FolderName = dt.FormatString("yyyy-mm-dd");
	String FileName = dt.FormatString("yyyy-mm-dd hh-nn-ss");
	ForceDirectories("C:\\KOSES\\History\\PKGParamLog\\"+ FolderName);

	String FullPath  =  "C:\\KOSES\\History\\PKGParamLog\\"+ FolderName+"\\"+FileName+".txt";

	File = new TFileStream(FullPath, fmCreate | fmOpenReadWrite);
	File->Position = 0;
	String Strtemp = "PKGParamLog \r\n";
	for(int i=0; i<PkgParamGrid->RowCount; i++)
	{
		Strtemp += " No:"+IntToStr(i)+ ":"+ PkgParamGrid->Cells[3][i+1] +"\r\n";
	}
	File->Write(Strtemp.c_str(),Strtemp.Length());
	delete File;
}
//---------------------------------------------------------------------------

void __fastcall TFrmUserDataView::ImgIDVCloseClick(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------




