//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fpadsetup.h"
#include "BaseComm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmPadSetup *frmPadSetup;
//---------------------------------------------------------------------------
__fastcall TfrmPadSetup::TfrmPadSetup(TComponent* Owner)
	: TForm(Owner)
{
	_nFilpUnitIndex=0;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPadSetup::Timer1Timer(TObject *Sender)
{
	if(!this->Showing) return;

	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_PKG;
	g_MMIComm->m_mmiToSeq.buffer.pkg.nStart = 0;
    g_MMIComm->m_mmiToSeq.buffer.pkg.nEnd  = maxPKG;
	if(true == g_MMIComm->Send() && true == g_MMIComm->Recv())
	{
		// Pad Type
		if(this->BtnInputPadType->Enabled)
		{
			TRadioButton* btn[] = {RadioButton1, RadioButton2, RadioButton3, RadioButton4};

			int type = g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[targetPad];
			if(type >= 0 && type <=3)
			{
				btn[type]->Checked = true;
			}
		}

		// Pad Theta
		if(this->BtnInputPadTheta->Enabled)
		{
			EditPadTheta->Text = FloatToStr(g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[padTheta]);
		}

		// Pad offset
		if(this->BtnInputPadOffset->Enabled)
		{
			EditPadOffsetX->Text = FloatToStr(g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[padOffSetX]);
			EditPadOffsetY->Text = FloatToStr(g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[padOffSetY]);
		}

		// flip offset
		if(this->BtnInputFlipOffset->Enabled)
		{
			EditTopOffsetX->Text = FloatToStr(g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[flipTopOffsetX]);
			EditTopOffsetY->Text = FloatToStr(g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[flipTopOffsetY]);
			EditBtmOffsetX->Text = FloatToStr(g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[flipBtmOffsetX]);
			EditBtmOffsetY->Text = FloatToStr(g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[flipBtmOffsetY]);
			EditFlipCount->Text = FloatToStr(g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[flipPcbCount]);
		}

		// flip offset
		if(this->btnFilpUnitOffsetInput->Enabled)
		{
			FilpOffsetDataRead(_nFilpUnitIndex);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmPadSetup::BtnInputPadTypeClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	BtnInputPadType->Enabled = false;
	BtnSavePadType->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmPadSetup::BtnInputPadThetaClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	BtnInputPadTheta->Enabled = false;
	BtnSavePadTheta->Enabled = true;

	EditPadTheta->ReadOnly = false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPadSetup::BtnInputPadOffsetClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	BtnInputPadOffset->Enabled = false;
	BtnSavePadOffset->Enabled = true;

	EditPadOffsetX->ReadOnly = false;
	EditPadOffsetY->ReadOnly = false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPadSetup::BtnInputFlipOffsetClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	BtnInputFlipOffset->Enabled = false;
	BtnSaveFlipOffset->Enabled = true;

	EditTopOffsetX->ReadOnly = false;
	EditTopOffsetY->ReadOnly = false;

	EditBtmOffsetX->ReadOnly = false;
	EditBtmOffsetY->ReadOnly = false;

	EditFlipCount->ReadOnly = false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPadSetup::BtnSavePadTypeClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	int type = 0;

	if(RadioButton1->Checked) type = 0;
	else if(RadioButton2->Checked) type = 1;
	else if(RadioButton3->Checked) type = 2;
	else if(RadioButton4->Checked) type = 3;

	dWritePkgData(type,targetPad);
	WriteFloatPkgParamInifile(type,targetPad);

	BtnSavePadType->Enabled = false;
	BtnInputPadType->Enabled = true;

}
//---------------------------------------------------------------------------
void __fastcall TfrmPadSetup::BtnSavePadThetaClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	double value = EditPadTheta->Text.ToDouble();
	dWritePkgData(value,padTheta);
	WriteFloatPkgParamInifile(value,padTheta);

	EditPadTheta->ReadOnly = true;

	BtnSavePadTheta->Enabled = false;
	BtnInputPadTheta->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPadSetup::BtnSavePadOffsetClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	double value = EditPadOffsetX->Text.ToDouble();
	dWritePkgData(value,padOffSetX);
	WriteFloatPkgParamInifile(value,padOffSetX);

	value = EditPadOffsetY->Text.ToDouble();
	dWritePkgData(value,padOffSetY);
	WriteFloatPkgParamInifile(value,padOffSetY);

	EditPadOffsetX->ReadOnly = true;
	EditPadOffsetY->ReadOnly = true;

	BtnSavePadOffset->Enabled = false;
	BtnInputPadOffset->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPadSetup::BtnSaveFlipOffsetClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	if(EditFlipCount->Text.ToInt() > 4 || EditFlipCount->Text.ToInt() < 0)
	{
		FrmCdBox->setFlag(CD_YES);
		FrmCdBox->setTitle("플립 파라미터 셋팅");
		FrmCdBox->setText("플립의 최대개수는 4개이며 0보다 작은 수가 들어갈수 없습니다.");
		FrmCdBox->BringToFront();
		FrmCdBox->ShowModal();
		return;
	}

	double value = EditTopOffsetX->Text.ToDouble();
	dWritePkgData(value,flipTopOffsetX);
	WriteFloatPkgParamInifile(value,flipTopOffsetX);

	value = EditTopOffsetY->Text.ToDouble();
	dWritePkgData(value,flipTopOffsetY);
	WriteFloatPkgParamInifile(value,flipTopOffsetY);

	value = EditBtmOffsetX->Text.ToDouble();
	dWritePkgData(value,flipBtmOffsetX);
	WriteFloatPkgParamInifile(value,flipBtmOffsetX);

	value = EditBtmOffsetY->Text.ToDouble();
	dWritePkgData(value,flipBtmOffsetY);
	WriteFloatPkgParamInifile(value,flipBtmOffsetY);

	value = EditFlipCount->Text.ToDouble();
	dWritePkgData(value,flipPcbCount);
	WriteFloatPkgParamInifile(value,flipPcbCount);

	EditTopOffsetX->ReadOnly = true;
	EditTopOffsetY->ReadOnly = true;

	EditBtmOffsetX->ReadOnly = true;
	EditBtmOffsetY->ReadOnly = true;

	EditFlipCount->ReadOnly = true;

	BtnSaveFlipOffset->Enabled = false;
	BtnInputFlipOffset->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmPadSetup::btnFilpUnitOffsetInputClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	btnFilpUnitOffsetInput->Enabled = false;
	btnFilpUnitOffsetSave->Enabled = true;

	EditFilpUnitOffset1->ReadOnly = false;
	EditFilpUnitOffset2->ReadOnly = false;
	EditFilpUnitOffset3->ReadOnly = false;
}
//---------------------------------------------------------------------------

void __fastcall TfrmPadSetup::btnFilpUnitOffsetSaveClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	FilpOffsetDataSave(_nFilpUnitIndex);
	FilpOffsetDataRead(_nFilpUnitIndex);

	EditFilpUnitOffset1->ReadOnly = true;
	EditFilpUnitOffset2->ReadOnly = true;
	EditFilpUnitOffset3->ReadOnly = true;

	btnFilpUnitOffsetInput->Enabled = true;
	btnFilpUnitOffsetSave->Enabled = false;
}
//---------------------------------------------------------------------------

void  TfrmPadSetup::FilpOffsetDataSave(int nIndex)
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

	int nPKGIndex = FilpUnit_X_1 + (3*nIndex);

	for(int i=0; i<3; i++)
	{
		TEdit* CloneEdit = (TEdit*)FindComponent("EditFilpUnitOffset" + IntToStr(i+1));
		if(CloneEdit->Text == "")
		{
			CloneEdit->Text = "0.0";
		}

		g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[nPKGIndex + i] = StrToFloat(CloneEdit->Text.Trim());
		//WriteFloatPkgParamInifile(StrToFloat(CloneEdit->Text.Trim()) ,  94 + i);
	}

    g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_PKG;
	bRet = g_MMIComm->Send() && g_MMIComm->Recv();
	if (!bRet)
		return;

    for(int i=0; i<3; i++)
	{
		TEdit* CloneEdit = (TEdit*)FindComponent("EditFilpUnitOffset" + IntToStr(i+1));
		if(CloneEdit->Text == "")
		{
			CloneEdit->Text = "0.0";
		}
		WriteFloatPkgParamInifile(StrToFloat(CloneEdit->Text.Trim()) ,  nPKGIndex + i);
    }
}
//---------------------------------------------------------------------------
void  TfrmPadSetup::FilpOffsetDataRead(int nIndex)
{
	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_PKG;
	if(true == g_MMIComm->Send() && true == g_MMIComm->Recv())
	{
		int nPKGIndex = FilpUnit_X_1 + (3*nIndex);
		for(int i=0; i<3; i++)
		{
			TEdit* CloneEdit = (TEdit*)FindComponent("EditFilpUnitOffset" + IntToStr(i+1));
			CloneEdit->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[(nPKGIndex + i)]  , ffFixed,10,3);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmPadSetup::btnFilpUnit_1Click(TObject *Sender)
{
	_nFilpUnitIndex = dynamic_cast<TBitBtn*>(Sender)->Tag;

	switch(_nFilpUnitIndex)
	{
		case 0:
			btnFilpUnit_1->Enabled = false;
			btnFilpUnit_2->Enabled = true;
			btnFilpUnit_3->Enabled = true;
			btnFilpUnit_4->Enabled = true;
			break;
		case 1:
			btnFilpUnit_1->Enabled = true;
			btnFilpUnit_2->Enabled = false;
			btnFilpUnit_3->Enabled = true;
			btnFilpUnit_4->Enabled = true;
			break;
		case 2:
			btnFilpUnit_1->Enabled = true;
			btnFilpUnit_2->Enabled = true;
			btnFilpUnit_3->Enabled = false;
			btnFilpUnit_4->Enabled = true;
			break;
		case 3:
			btnFilpUnit_1->Enabled = true;
			btnFilpUnit_2->Enabled = true;
			btnFilpUnit_3->Enabled = true;
			btnFilpUnit_4->Enabled = false;
			break;
	}
}
//---------------------------------------------------------------------------

