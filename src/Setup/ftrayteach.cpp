//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ftrayteach.h"
#include "..\common\basecomm.h"
#include "..\mainformscrn.h"
#include "FrmTrayUnitScrn.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmTrayTeach *frmTrayTeach;

#define		_3POINT_	0
#define		_TRAYJIG_	1
//---------------------------------------------------------------------------
__fastcall TfrmTrayTeach::TfrmTrayTeach(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfrmTrayTeach::BitBtn1Click(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	FrmCdBox->setFlag(CD_YESNO);
    FrmCdBox->setTitle("Overwrite package parameter");
    FrmCdBox->setText("Do you want to overwrite package parameter ?");
	FrmCdBox->BringToFront();
    if (mrYes != FrmCdBox->ShowModal())
    	return;	//


	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_PKG;
    g_MMIComm->m_mmiToSeq.buffer.pkg.nStart = 0;
    g_MMIComm->m_mmiToSeq.buffer.pkg.nEnd = 999;
	BOOL bRet = g_MMIComm->Send() && g_MMIComm->Recv();
    if (!bRet)
    	return;


	g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[trayXCnt] = EditTrayXCnt->Text.ToInt();
	g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[trayYCnt] = EditTrayYCnt->Text.ToInt();
	g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[trayPitchX] = EditTrayXPitch->Text.ToDouble();
	g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[trayPitchY] = EditTrayYPitch->Text.ToDouble();

	g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_PKG;
	bRet = g_MMIComm->Send() && g_MMIComm->Recv();
	if (!bRet)
		return;

	WriteFloatPkgParamInifile(EditTrayXCnt->Text.ToInt(), trayXCnt);
	WriteFloatPkgParamInifile(EditTrayYCnt->Text.ToInt(), trayYCnt);
	WriteFloatPkgParamInifile(EditTrayXPitch->Text.ToDouble(), trayPitchX);
	WriteFloatPkgParamInifile(EditTrayYPitch->Text.ToDouble(), trayPitchY);

	this->trayPKGDataRead();
}

void TfrmTrayTeach::TraySelectRead()
{

	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_PKG;
	if(true == g_MMIComm->Send() && true == g_MMIComm->Recv())
	{

        for(int i=0; i<6; i++)
        {
        	TEdit* CloneEdit = (TEdit*)FindComponent("TrayOffsetEdit" + IntToStr(i));
			CloneEdit->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[_pkg_START_NO1_ + i ] , ffFixed,10,3);
		}

		int Tray1Chk = dReadPkgData(trayXCnt);
		for(int i=0; i<12; i++)
		{
			TEdit* CloneEdit = (TEdit*)FindComponent("TrayShrinkOffsetEdit" + IntToStr(i));
			//CloneEdit->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[_pkg_START_NO2_ + i ] , ffFixed,10,3); // Origin

			if(Tray1Chk == 1) // 1Tray Check
			{
				if((i == 0) || (i == 1) || (i == 4) || (i == 5) || (i == 8) || (i == 9)) // 2rd Point X,Y
				{
                 	CloneEdit->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[_pkg_TRAY_NO1_ + i ] , ffFixed,10,3);
				}
				else
				{
					CloneEdit->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[_pkg_START_NO2_ + i ] , ffFixed,10,3);
                }
			}
			else // Origin
			{
				CloneEdit->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[_pkg_START_NO2_ + i ] , ffFixed,10,3);
			}
		}
	}

}
//---------------------------------------------------------------------------
void TfrmTrayTeach::TrayOffsetSelectSave()
{
    FrmCdBox->setFlag(CD_YESNO);
    FrmCdBox->setTitle("Overwrite package parameter");
    FrmCdBox->setText("save the Offset Parameter?");
    FrmCdBox->BringToFront();
    if (mrYes != FrmCdBox->ShowModal())
    	return;	//


	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_PKG;
    g_MMIComm->m_mmiToSeq.buffer.pkg.nStart = 0;
    g_MMIComm->m_mmiToSeq.buffer.pkg.nEnd = 999;
	BOOL bRet = g_MMIComm->Send() && g_MMIComm->Recv();
    if (!bRet)
    	return;


    // SEQ 저장
//	int nStartNo  =  _pkg_START_NO2_  + (4 * nSelect);
	int Tray1Chk = g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[trayXCnt];
	for(int i=0; i<12; i++)
    {
		TEdit* CloneEdit = (TEdit*)FindComponent("TrayShrinkOffsetEdit" + IntToStr(i));
		if(CloneEdit->Text == "")
		{
        	CloneEdit->Text = "0";
		}

		if(Tray1Chk == 1) // 1Tray Check
		{
			if((i == 0) || (i == 1) || (i == 4) || (i == 5) || (i == 8) || (i == 9)) // 2rd Point X,Y
			{
				g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[_pkg_TRAY_NO1_ + i] = StrToFloat(CloneEdit->Text.ToDouble());
			}
			else
			{
				g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[_pkg_START_NO2_ + i] = StrToFloat(CloneEdit->Text.ToDouble());
			}
		}
		else // Origin
		{
			g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[_pkg_START_NO2_ + i] = StrToFloat(CloneEdit->Text.ToDouble());
		}

		//g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[_pkg_START_NO2_ + i] = StrToFloat(CloneEdit->Text.ToDouble()); // Origin
		//WriteFloatPkgParamInifile(StrToFloat(CloneEdit->Text.Trim()) ,  nStartNo + i);
	}

//	nStartNo  =  _pkg_START_NO1_  + (2 * nSelect);
	for(int i=0; i<6; i++)
    {
		TEdit* CloneEdit = (TEdit*)FindComponent("TrayOffsetEdit" + IntToStr(i));
		if(CloneEdit->Text == "")
		{
        	CloneEdit->Text = "0";
		}

		g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[_pkg_START_NO1_ + i] = StrToFloat(CloneEdit->Text.ToDouble());
		//WriteFloatPkgParamInifile(StrToFloat(CloneEdit->Text.Trim()) ,  nStartNo + i);
	}

    g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_PKG;
	bRet = g_MMIComm->Send() && g_MMIComm->Recv();
	if (!bRet)
		return;

    // INI 파일 저장
//	nStartNo  =  _pkg_START_NO2_  + (4 * nSelect);
	for(int i=0; i<12; i++)
	{
		TEdit* CloneEdit = (TEdit*)FindComponent("TrayShrinkOffsetEdit" + IntToStr(i));
		if(CloneEdit->Text == "")
		{
			CloneEdit->Text = "0";
		}

		if(Tray1Chk == 1) // 1Tray Check
		{
			if((i == 0) || (i == 1) || (i == 4) || (i == 5) || (i == 8) || (i == 9)) // 2rd Point X,Y
			{
				WriteFloatPkgParamInifile(StrToFloat(CloneEdit->Text.Trim()) ,  _pkg_TRAY_NO1_ + i);
			}
			else
			{
				WriteFloatPkgParamInifile(StrToFloat(CloneEdit->Text.Trim()) ,  _pkg_START_NO2_ + i);
			}
		}
		else // Origin
		{
			WriteFloatPkgParamInifile(StrToFloat(CloneEdit->Text.Trim()) ,  _pkg_START_NO2_ + i);
		}

		//WriteFloatPkgParamInifile(StrToFloat(CloneEdit->Text.Trim()) ,  _pkg_START_NO2_ + i); // Origin
	}
//	nStartNo  =  _pkg_START_NO1_  + (2 * nSelect);
	for(int i=0; i<6; i++)
	{
		TEdit* CloneEdit = (TEdit*)FindComponent("TrayOffsetEdit" + IntToStr(i));
		if(CloneEdit->Text == "")
		{
			CloneEdit->Text = "0";
		}
		WriteFloatPkgParamInifile(StrToFloat(CloneEdit->Text.Trim()) ,  _pkg_START_NO1_ + i);
	}
}
//---------------------------------------------------------------------------

void TfrmTrayTeach::AllTrayOffsetSave()
{
    FrmCdBox->setFlag(CD_YESNO);
    FrmCdBox->setTitle("Overwrite package parameter");
    FrmCdBox->setText("save the Offset Parameter?");
    FrmCdBox->BringToFront();
    if (mrYes != FrmCdBox->ShowModal())
    	return;	//


	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_PKG;
    g_MMIComm->m_mmiToSeq.buffer.pkg.nStart = 0;
    g_MMIComm->m_mmiToSeq.buffer.pkg.nEnd = 999;
	BOOL bRet = g_MMIComm->Send() && g_MMIComm->Recv();
    if (!bRet)
    	return;

	int nStartNo  =  _pkg_START_NO2_;
	int Tray1Chk = dReadPkgData(trayXCnt);
	for(int i=0; i<12; i++)
	{
		TEdit* CloneEdit = (TEdit*)FindComponent("TrayShrinkOffsetEdit" + IntToStr(i));
		if(CloneEdit->Text == "")
		{
        	CloneEdit->Text = "0";
		}

		if(Tray1Chk == 1) // 1Tray Check
		{
			if((i == 0) || (i == 1) || (i == 4) || (i == 5) || (i == 8) || (i == 9)) // 2rd Point X,Y
			{
				g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[_pkg_TRAY_NO1_ + i] = StrToFloat(CloneEdit->Text.ToDouble());
			}
			else
			{
				g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[_pkg_START_NO2_ + i] = StrToFloat(CloneEdit->Text.ToDouble());
			}
		}
		else // Origin
		{
			g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[_pkg_START_NO2_ + i] = StrToFloat(CloneEdit->Text.ToDouble());
		}

		//g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[_pkg_START_NO2_ + i] = StrToFloat(CloneEdit->Text.ToDouble());  // Origin
		//WriteFloatPkgParamInifile(StrToFloat(CloneEdit->Text.Trim()) ,  nStartNo + i);
	}

	for(int i=0; i<6; i++)
    {
		TEdit* CloneEdit = (TEdit*)FindComponent("TrayOffsetEdit" + IntToStr(i));
		if(CloneEdit->Text == "")
		{
			CloneEdit->Text = "0";
		}

		g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[_pkg_START_NO1_ + i] = StrToFloat(CloneEdit->Text.ToDouble());
		//WriteFloatPkgParamInifile(StrToFloat(CloneEdit->Text.Trim()) ,  nStartNo + i);
	}

    g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_PKG;
	bRet = g_MMIComm->Send() && g_MMIComm->Recv();
	if (!bRet)
		return;

	for(int i=0; i<12; i++)
	{
		TEdit* CloneEdit = (TEdit*)FindComponent("TrayShrinkOffsetEdit" + IntToStr(i));
		if(CloneEdit->Text == "")
		{
			CloneEdit->Text = "0";
		}

		if(Tray1Chk == 1) // 1Tray Check
		{
			if((i == 0) || (i == 1) || (i == 4) || (i == 5) || (i == 8) || (i == 9)) // 2rd Point X,Y
			{
				WriteFloatPkgParamInifile(StrToFloat(CloneEdit->Text.Trim()) ,  _pkg_TRAY_NO1_ + i);
			}
			else
			{
				WriteFloatPkgParamInifile(StrToFloat(CloneEdit->Text.Trim()) ,  _pkg_START_NO2_ + i);
			}
		}
		else // Origin
		{
			WriteFloatPkgParamInifile(StrToFloat(CloneEdit->Text.Trim()) ,  _pkg_START_NO2_ + i);
		}

		//WriteFloatPkgParamInifile(StrToFloat(CloneEdit->Text.Trim()) ,  _pkg_START_NO2_ + i);  //Origin
	}

	for(int i=0; i<6; i++)
	{
		TEdit* CloneEdit = (TEdit*)FindComponent("TrayOffsetEdit" + IntToStr(i));
		if(CloneEdit->Text == "")
		{
			CloneEdit->Text = "0";
		}
		WriteFloatPkgParamInifile(StrToFloat(CloneEdit->Text.Trim()) ,  _pkg_START_NO1_ + i);
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmTrayTeach::BtnDataSaveClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	this->TrayOffsetSelectSave();
	Timer1->Enabled = true;
}
//---------------------------------------------------------------------------

void  TfrmTrayTeach::TrayPickupDataRead()
{
	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_PKG;
	if(true == g_MMIComm->Send() && true == g_MMIComm->Recv())
	{
        for(int i=0; i<2; i++)
		{
        	TEdit* CloneEdit = (TEdit*)FindComponent("EditPP" + IntToStr(i+1));
			CloneEdit->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[(gerberUnitCenterToPickupX + i)]  , ffFixed,10,3);
		}
	}
}
//---------------------------------------------------------------------------
void  TfrmTrayTeach::TrayCenter1stDataRead()
{
	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_PKG;
	if(true == g_MMIComm->Send() && true == g_MMIComm->Recv())
	{
        for(int i=0; i<2; i++)
        {
        	TEdit* CloneEdit = (TEdit*)FindComponent("EditTC" + IntToStr(i+1));
			CloneEdit->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[(71 + i)]  , ffFixed,10,3);
		}
	}
}
//---------------------------------------------------------------------------

void  TfrmTrayTeach::TrayCenter1stDataSave()
{
	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_PKG;
    g_MMIComm->m_mmiToSeq.buffer.pkg.nStart = 0;
    g_MMIComm->m_mmiToSeq.buffer.pkg.nEnd = 999;
	BOOL bRet = g_MMIComm->Send() && g_MMIComm->Recv();
    if (!bRet)
		return;

	double dPkgValue[4];
	for(int i=0; i<4; i++)
	{
		dPkgValue[i] = g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[71 + i];
	}

	for(int i=0; i<4; i++)
	{
		WriteFloatPkgParamInifile(dPkgValue[i],  71 + i);
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmTrayTeach::BtnTCUnitSaveClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	FrmCdBox->setFlag(CD_YESNO);
    FrmCdBox->setTitle("Overwrite tray unit data");
    FrmCdBox->setText("Do you want to overwrite tray unit data ?");
	FrmCdBox->BringToFront();
    if (mrYes != FrmCdBox->ShowModal())
    	return;	//

	nWriteCommunicationDM(STATE_REQ, scrLoadTrayDefaultData);

	//this->TrayCenter1stDataRead();
}
//---------------------------------------------------------------------------

void __fastcall TfrmTrayTeach::BtnUCDistanceSaveClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	FrmCdBox->setFlag(CD_YESNO);
    FrmCdBox->setTitle("AUTO OPERATION");
    FrmCdBox->setText("Do you proceed the parameter calculation?");
    FrmCdBox->BringToFront();
    if (mrYes != FrmCdBox->ShowModal())
		return;	//

	double dbX = dReadPkgData(getberPcbCenterToUnitCenterX);
	double dbY = dReadPkgData(getberPcbCenterToUnitCenterY);

	double dbopX = dReadPkgData(pcb00PosX) - dbX;
	double dbopY = dReadPkgData(pcb00PosY) - dbY;

	dbopX = dbopX * (-1.0f);
	dbopY = dbopY * (-1.0f);

	dWritePkgData(dbopX,gerberUnitCenterToPickupX);
	dWritePkgData(dbopY,gerberUnitCenterToPickupY);

	WriteFloatPkgParamInifile(dbopX  ,  gerberUnitCenterToPickupX);
	WriteFloatPkgParamInifile(dbopY  ,  gerberUnitCenterToPickupY);

	TrayPickupDataRead();
}
//---------------------------------------------------------------------------
void __fastcall TfrmTrayTeach::FormPaint(TObject *Sender)
{
	this->TraySelectRead();
	this->GerberCenterDataRead();
	this->TrayPickupDataRead();
	this->TrayCenter1stDataRead();
	this->trayPKGDataRead();
	this->trayInfoDataRead();
}
//---------------------------------------------------------------------------
void	TfrmTrayTeach::trayPKGDataRead()
{
	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_PKG;
	g_MMIComm->m_mmiToSeq.buffer.pkg.nStart = 0;
	g_MMIComm->m_mmiToSeq.buffer.pkg.nEnd = 999;
	if (g_MMIComm->Send() && g_MMIComm->Recv())
	{
		EditTrayXCnt->Text = IntToStr((int)g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[trayXCnt]);
		EditTrayYCnt->Text = IntToStr((int)g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[trayYCnt]);
		EditTrayXPitch->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[trayPitchX] , ffFixed, 10, 3);
		EditTrayYPitch->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[trayPitchY] , ffFixed, 10, 3);
	}

	double threshold = dReadCommunicationDM(trayTeachTolerance);
    EditVisionThreshold->Text = FloatToStrF(threshold, ffFixed, 10, 3);
	//EditVisionThreshold->Text = "Tolarence : " + FloatToStrF(threshold, ffFixed, 10, 3);
}
//---------------------------------------------------------------------------

void  TfrmTrayTeach::trayInfoDataRead()
{
	TEdit* pEditTrayCount = (TEdit*)FindComponent("EditMaxTrayStackCount_1");
	TEdit* pEditTrayWeight = (TEdit*)FindComponent("EditMaxTrayTotalWeight_1");

	pEditTrayCount->Text = (int)dReadPkgData(trayStackMaxCnt);
	pEditTrayWeight->Text = dReadPkgData(trayLoadWeightLimit);
}
//---------------------------------------------------------------------------

void  TfrmTrayTeach::trayInfoDataSave()
{
	FrmCdBox->setFlag(CD_YESNO);
    FrmCdBox->setTitle("Overwrite tray data");
    FrmCdBox->setText("Do you want to overwrite tray data ?");
	FrmCdBox->BringToFront();
    if (mrYes != FrmCdBox->ShowModal())
    	return;	//

	TEdit* pEditTrayCount = (TEdit*)FindComponent("EditMaxTrayStackCount_1");
	TEdit* pEditTrayWeight = (TEdit*)FindComponent("EditMaxTrayTotalWeight_1");

	double dTrayCnt = pEditTrayCount->Text.ToDouble();
	double dTrayWeight = pEditTrayWeight->Text.ToDouble();

	dWritePkgData(dTrayCnt, trayStackMaxCnt);
	dWritePkgData(dTrayWeight, trayLoadWeightLimit);

	WriteFloatPkgParamInifile(dTrayCnt,  trayStackMaxCnt);
	WriteFloatPkgParamInifile(dTrayWeight,  trayLoadWeightLimit);
}
//---------------------------------------------------------------------------

void __fastcall TfrmTrayTeach::btnAllTrayDataSaveClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	this->AllTrayOffsetSave();
}
//---------------------------------------------------------------------------

void __fastcall TfrmTrayTeach::SpeedButton14Click(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	FrmCdBox->setFlag(CD_YESNO);
	FrmCdBox->setTitle("Manual operation");
    FrmCdBox->setText("Do you want to operate the equipment by manually ?");
    FrmCdBox->BringToFront();
    if (mrYes != FrmCdBox->ShowModal())
    	return;	//

    TSpeedButton* pButton =  (TSpeedButton*)Sender;
    int value = pButton->Tag;
	nWriteCommunicationDM(value, 99);	//tenkey
}
//---------------------------------------------------------------------------

void __fastcall TfrmTrayTeach::btnTrayInfoSave_JigClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	this->trayInfoDataSave();
}
//---------------------------------------------------------------------------


void __fastcall TfrmTrayTeach::BitBtn5Click(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	FrmCdBox->setFlag(CD_YESNO);
    FrmCdBox->setTitle("Overwrite Tolarence parameter");
    FrmCdBox->setText("Do you want to overwrite Tolarence parameter ?");
	FrmCdBox->BringToFront();
    if (mrYes != FrmCdBox->ShowModal())
    	return;	//


    double dValue = EditVisionThreshold->Text.ToDouble();
    dWriteCommunicationDM(dValue, trayTeachTolerance);

	double threshold = dReadCommunicationDM(trayTeachTolerance);
    EditVisionThreshold->Text = FloatToStrF(threshold, ffFixed, 10, 3);

}
//---------------------------------------------------------------------------

void __fastcall TfrmTrayTeach::BtnTeachBtn5Click(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	FrmTrayUnit->FormInitiaize( ((TBitBtn*)Sender)->Tag );
}
//---------------------------------------------------------------------------

void __fastcall TfrmTrayTeach::BtnUnitCenterInputClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	EditUC1->Enabled = true;
	EditUC2->Enabled = true;
	BtnUnitCenterInput->Enabled = false;
	BtnUnitCenterSave->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmTrayTeach::BtnUnitCenterSaveClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	dWritePkgData(EditUC1->Text.ToDouble(), getberPcbCenterToUnitCenterX);
	dWritePkgData(EditUC2->Text.ToDouble(), getberPcbCenterToUnitCenterY);

	WriteFloatPkgParamInifile(EditUC1->Text.ToDouble(),  getberPcbCenterToUnitCenterX);
	WriteFloatPkgParamInifile(EditUC2->Text.ToDouble(),  getberPcbCenterToUnitCenterY);

	EditUC1->Enabled = false;
	EditUC2->Enabled = false;
	BtnUnitCenterInput->Enabled = true;
	BtnUnitCenterSave->Enabled = false;

	this->GerberCenterDataRead();
}
//---------------------------------------------------------------------------

void 	 TfrmTrayTeach::GerberCenterDataRead()
{
	for(int i=0; i<2; i++)
	{
		TEdit* pEditGP = (TEdit*)FindComponent("EditGP"+IntToStr(i+1));
		TEdit* pEditUC = (TEdit*)FindComponent("EditUC"+IntToStr(i+1));

		pEditGP->Text = FloatToStrF(dReadPkgData(pcb00PosX+i), ffFixed, 10, 3);
		pEditUC->Text = FloatToStrF(dReadPkgData(getberPcbCenterToUnitCenterX+i), ffFixed, 10, 3);
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmTrayTeach::FormShow(TObject *Sender)
{
	Timer1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmTrayTeach::FormClose(TObject *Sender, TCloseAction &Action)
{
	Timer1->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TfrmTrayTeach::Timer1Timer(TObject *Sender)
{
	this->TraySelectRead();
}
//---------------------------------------------------------------------------

void __fastcall TfrmTrayTeach::BtnDataInputClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	Timer1->Enabled = false;
}
//---------------------------------------------------------------------------

