	//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitSetupScrn.h"
#include "UnitControlScrn.h"
#include "BaseComm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma resource "*.dfm"


#define UnitXOffset				13
#define UnitYOffset				14
#define UnitTeachingTolenrance 	17
#define	_TOP_FILP_THETA_		6
#define	_BTM_FILP_THETA_		7

TFrmUnitSetup *FrmUnitSetup;
//---------------------------------------------------------------------------
__fastcall TFrmUnitSetup::TFrmUnitSetup(TComponent* Owner)
	: TForm(Owner)
{
	::ZeroMemory(pSubUnitCtrlFrm, sizeof(pSubUnitCtrlFrm));
}
//---------------------------------------------------------------------------
void TFrmUnitSetup::Frm_UnitDisplay()
{
	int col = dReadPkgData(pcbXCnt);
	int row = dReadPkgData(pcbYCnt);

	Edit1->Text = IntToStr(col);
	Edit2->Text = IntToStr(row);

	this->create_panel(col,row);

	EditXOffset->Text = FloatToStrF(dReadPkgData(UnitXOffset),ffFixed,10,3);
	EditYOffset->Text = FloatToStrF(dReadPkgData(UnitYOffset),ffFixed,10,3);
	EditTolerence->Text = FloatToStrF(dReadCommunicationDM(UnitTeachingTolenrance),ffFixed,10,3);

	BtnSaveUnitCnt->Enabled = false;
	BtnSaveOffset->Enabled = false;
	BtnSaveTolerence->Enabled = false;
	BtnSaveData->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TFrmUnitSetup::FormDestroy(TObject *Sender)
{
	if(!_panels.empty())
	{
		for(int i=0; i < _panels.size(); i++)
		{
			_panels.at(i)->FreeOnRelease();
			delete _panels.at(i);
		}
	}

	_panels.clear();
}
//---------------------------------------------------------------------------
void __fastcall TFrmUnitSetup::BtnSaveDataClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	for(int i = 0; i < _panels.size(); i++)
	{
		((TFrmUnitControl*)_panels[i])->_UnitDataSave(i);
    }

	BtnInputData->Enabled = true;
	BtnSaveData->Enabled = false;

	for(int i = 0; i < _panels.size(); i++)
    {
		((TFrmUnitControl*)_panels[i])->PanelFlip->Enabled = false;
	}

	Timer1->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TFrmUnitSetup::BtnInputDataClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	Timer1->Enabled = false;
	BtnInputData->Enabled = false;
	BtnSaveData->Enabled = true;

	for(int i = 0; i < _panels.size(); i++)
    {
		((TFrmUnitControl*)_panels[i])->PanelFlip->Enabled = true;
    }
}
//---------------------------------------------------------------------------
void	TFrmUnitSetup::create_panel(int col, int row)
{
	if(col * row > 25)
	{
		ShowMessage("Unit count is over then limit.");
		col = row = 5;
	}

	if(!_panels.empty())
	{
		for(int i=0; i < _panels.size(); i++)
		{
			_panels.at(i)->FreeOnRelease();
			delete _panels.at(i);
		}
	}

	_panels.clear();

	GridPanel1->ColumnCollection->Clear();
	GridPanel1->RowCollection->Clear();

	for(int r=0; r<row ; r++)
	{
		GridPanel1->RowCollection->Add();
	}
	for(int c=0; c<col ; c++)
	{
		GridPanel1->ColumnCollection->Add();
	}

	for(int r=0; r < row; r++)
	{
		for(int c=0; c <col; c++)
		{
			TFrmUnitControl* p = new TFrmUnitControl(this);
			p->Parent = GridPanel1;
			p->Align = alClient;
			p->Show();

			p->AlignWithMargins = true;
			p->Margins->Top = 2;
			p->Margins->Bottom = 2;
			p->Margins->Left = 2;
			p->Margins->Right = 2;

			_panels.push_back(p);


			p->Form_Initialize(r*col +c);
			p->PanelFlip->Enabled = false;
		}
	}

	this->resize_grid_panel();
}
//---------------------------------------------------------------------------
void	TFrmUnitSetup::resize_grid_panel()
{
	GridPanel1->Width = (230 + 2) * GridPanel1->ColumnCollection->Count;
	GridPanel1->Height = (160 + 2) * GridPanel1->RowCollection->Count;

	//GridPanel1->Left = (Panel5->Width / 2) - (GridPanel1->Width / 2);
	GridPanel1->Top = (Panel5->Height / 2) - (GridPanel1->Height / 2);

	for(int i=0;i<GridPanel1->RowCollection->Count;i++)
	{
		GridPanel1->RowCollection->Items[i]->SizeStyle = ssAbsolute;
		GridPanel1->RowCollection->Items[i]->Value = GridPanel1->ClientHeight / GridPanel1->RowCollection->Count;
	}

	for(int i=0;i<GridPanel1->ColumnCollection->Count;i++)
	{
		GridPanel1->ColumnCollection->Items[i]->SizeStyle = ssAbsolute;
		GridPanel1->ColumnCollection->Items[i]->Value = GridPanel1->ClientWidth / GridPanel1->ColumnCollection->Count;
	}
}
void __fastcall TFrmUnitSetup::SpeedButton1Click(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

    FrmCdBox->setFlag(CD_YESNO);
    FrmCdBox->setTitle("READ GERBER DATA");
    FrmCdBox->setText("Do you want to read the file from gerber?");
    if( mrYes == FrmCdBox->ShowModal())
    {
		this->readGerberData();
    }
}
//---------------------------------------------------------------------------

void __fastcall TFrmUnitSetup::SpeedButton2Click(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

//
  // tenkry 108
  	TSpeedButton* btn = dynamic_cast<TSpeedButton*>(Sender);
    if(NULL != btn)
    {

        if ( 0 != nReadCommunicationDM( mcState ))	//0 : stop
        {
            FrmCdBox->setFlag(CD_OK);
            FrmCdBox->setTitle("MACHINE STATUS");
            FrmCdBox->setText("Machine is not stopped !");
            FrmCdBox->ShowModal();
            return;
        }

        FrmCdBox->setFlag(CD_YESNO);
        FrmCdBox->setTitle(btn->Caption);
        FrmCdBox->setText("Do you want to "+ btn->Caption + "?");
        if( mrYes == FrmCdBox->ShowModal())
        {
			nWriteCommunicationDM(btn->Tag,screenTenkey);
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TFrmUnitSetup::BtnSaveTolerenceClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	if ( 0 != nReadCommunicationDM( mcState ))	//0 : stop
    {
        FrmCdBox->setFlag(CD_OK);
        FrmCdBox->setTitle("MACHINE STATUS");
        FrmCdBox->setText("Machine is not stopped !");
        FrmCdBox->ShowModal();
        return;
    }

	dWriteCommunicationDM(EditTolerence->Text.ToDouble(), UnitTeachingTolenrance);

	BtnInputTolerence->Enabled = true;
	BtnSaveTolerence->Enabled = false;

	Timer1->Enabled = true;
}
//---------------------------------------------------------------------------



void __fastcall TFrmUnitSetup::BtnSaveUnitCntClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

    FrmCdBox->setFlag(CD_YESNO);
    FrmCdBox->setTitle("Unit count save");
    FrmCdBox->setText("Are you sure about saving unit count?");
    if( mrYes == FrmCdBox->ShowModal())
    {
        int x = Edit1->Text.ToInt();
        int y = Edit2->Text.ToInt();
     	dWritePkgData(x,pcbXCnt);
        dWritePkgData(y,pcbYCnt);

        WriteIntegerToRecipeInifile("PkgParam.ini","PKGPARM","VALUE"+IntToStr(pcbXCnt),x);
        WriteIntegerToRecipeInifile("PkgParam.ini","PKGPARM","VALUE"+IntToStr(pcbYCnt),y);
	}

	BtnInputUnitCnt->Enabled = true;
	BtnSaveUnitCnt->Enabled = false;

	Timer1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TFrmUnitSetup::BtnInputUnitCntClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	Timer1->Enabled = false;

	BtnInputUnitCnt->Enabled = false;
	BtnSaveUnitCnt->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TFrmUnitSetup::BtnInputOffsetClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	Timer1->Enabled = false;

	BtnInputOffset->Enabled = false;
	BtnSaveOffset->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TFrmUnitSetup::BtnInputTolerenceClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	Timer1->Enabled = false;

	BtnInputTolerence->Enabled = false;
	BtnSaveTolerence->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TFrmUnitSetup::BtnSaveOffsetClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	dWritePkgData(EditXOffset->Text.ToDouble(),UnitXOffset);
	WriteFloatPkgParamInifile(EditXOffset->Text.ToDouble(),UnitXOffset);
	dWritePkgData(EditYOffset->Text.ToDouble(),UnitYOffset);
	WriteFloatPkgParamInifile(EditYOffset->Text.ToDouble(),UnitYOffset);

	BtnInputOffset->Enabled = true;
	BtnSaveOffset->Enabled = false;
	Timer1->Enabled = true;
}
//---------------------------------------------------------------------------
void	TFrmUnitSetup::refresh_data()
{
	int col = dReadPkgData(pcbXCnt);
	int row = dReadPkgData(pcbYCnt);

	Edit1->Text = IntToStr(col);
	Edit2->Text = IntToStr(row);

	EditXOffset->Text = FloatToStrF(dReadPkgData(UnitXOffset),ffFixed,10,3);
	EditYOffset->Text = FloatToStrF(dReadPkgData(UnitYOffset),ffFixed,10,3);
	EditTolerence->Text = FloatToStrF(dReadCommunicationDM(UnitTeachingTolenrance),ffFixed,10,3);

	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_STAUBLI_TABLE;
	BOOL bRet = g_MMIComm->Send() &&  g_MMIComm->Recv();
	if(bRet)
	{
		EditTopThetaOffset->Text = FloatToStrF(g_MMIComm->m_mmiToSeq.buffer.staubliTable.posRZ[_TOP_FILP_THETA_],ffFixed,10,3);
		EditBtmThetaOffset->Text = FloatToStrF(g_MMIComm->m_mmiToSeq.buffer.staubliTable.posRZ[_BTM_FILP_THETA_],ffFixed,10,3);
	}
}
//---------------------------------------------------------------------------
void    TFrmUnitSetup::readGerberData()
{
	int group = nReadGroupNo();
	int recipe = nReadRecipeNo();

	String file = ExtractFilePath(Application->ExeName)+ "\\ini\\system\\GRP"+IntToStr(group)+"\\RCP"+IntToStr(recipe)+"\\exportData.ini";
	if(FileExists(file))
	{
		TIniFile* orgData = new TIniFile(file);

		int count = orgData->ReadInteger("PATH_ARRAY_INFO","PICK COUNT",0);
		if(count == _panels.size())
		{
			for(int i=0; i < count; i++)
			{
				((TFrmUnitControl*)_panels.at(i))->EditXSize->Text = orgData->ReadString("PATH_ARRAY_INFO","PICK_POINT"+IntToStr(i+1)+"_X",0);
				((TFrmUnitControl*)_panels.at(i))->EditYSize->Text = orgData->ReadString("PATH_ARRAY_INFO","PICK_POINT"+IntToStr(i+1)+"_Y",0);
			}

			//ShowMessage("Gerber data read success.");
			//this->BtnInputDataClick(Sender);
		}
		else
		{
			ShowMessage("Do not matched unit count with gerber data.");
		}

		delete orgData;
	}
	else
	{
		ShowMessage("Can not find gerber data file(exportData.ini)");
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmUnitSetup::Timer1Timer(TObject *Sender)
{
	this->refresh_data();
}
//---------------------------------------------------------------------------


void __fastcall TFrmUnitSetup::btnRobotThetaInputClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	Timer1->Enabled = false;

	btnRobotThetaInput->Enabled = false;
	btnRobotThetaSave->Enabled = true;
}
//---------------------------------------------------------------------------


void __fastcall TFrmUnitSetup::btnRobotThetaSaveClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	if ( 0 != nReadCommunicationDM( mcState ))	//0 : stop
    {
        FrmCdBox->setFlag(CD_OK);
        FrmCdBox->setTitle("MACHINE STATUS");
        FrmCdBox->setText("Machine is not stopped !");
        FrmCdBox->ShowModal();
        return;
	}

	int nGrpNo, nRcpNo; // Theta Save

	nGrpNo = nReadGroupNo();
	nRcpNo = nReadRecipeNo();

	String StrPath = ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(nGrpNo)+"\\RCP"+IntToStr(nRcpNo)+"\\StaubliData.ini";

	if(FileExists(StrPath))
	{
		TIniFile *ini = new TIniFile(StrPath);

     	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_STAUBLI_TABLE;
		BOOL bRet = g_MMIComm->Send() &&  g_MMIComm->Recv();
		if(bRet)
		{

			g_MMIComm->m_mmiToSeq.buffer.staubliTable.posRZ[_TOP_FILP_THETA_] = EditTopThetaOffset->Text.ToDouble();
			g_MMIComm->m_mmiToSeq.buffer.staubliTable.posRZ[_BTM_FILP_THETA_] = EditBtmThetaOffset->Text.ToDouble();

			g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_STAUBLI_TABLE;
			if(g_MMIComm->Send() &&  g_MMIComm->Recv())
			{
			}
			else
			{
			}


			ini->WriteString("RZPOS","VALUE"+IntToStr(_TOP_FILP_THETA_),EditTopThetaOffset->Text);
			ini->WriteString("RZPOS","VALUE"+IntToStr(_BTM_FILP_THETA_),EditBtmThetaOffset->Text);

			delete ini;
		}
    }


    btnRobotThetaInput->Enabled = true;
	btnRobotThetaSave->Enabled = false;
	//BtnInputTolerence->Enabled = true;   // Theta Save
	//BtnSaveTolerence->Enabled = false;

	Timer1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TFrmUnitSetup::FormShow(TObject *Sender)
{
	this->readGerberData();
}
//---------------------------------------------------------------------------

