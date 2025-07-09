//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fqcunitsetup.h"
#include "fqcunitsetupcontrol.h"
#include "BaseComm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma resource "*.dfm"
TfrmQcPositionSetup *frmQcPositionSetup;

#define PKG_QCUNIT_X_CNT  	6
#define PKG_QCUNIT_Y_CNT  	7

//---------------------------------------------------------------------------
__fastcall TfrmQcPositionSetup::TfrmQcPositionSetup(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TfrmQcPositionSetup::Frm_UnitDisplay()
{
	int col = dReadPkgData(PKG_QCUNIT_X_CNT);
	int row = dReadPkgData(PKG_QCUNIT_Y_CNT);

    Edit1->Text = IntToStr(col);
	Edit2->Text = IntToStr(row);

	this->create_panel(col,row);
// 	this->create_panel(3,4);
}
//---------------------------------------------------------------------------
void	TfrmQcPositionSetup::create_panel(int col, int row)
{
	if(col * row > 50)
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
			TFrmQcUnitControl* p = new TFrmQcUnitControl(this);
			p->Parent = GridPanel1;
			p->Align = alClient;
			p->Show();

			p->AlignWithMargins = true;
			p->Margins->Top = 5;
			p->Margins->Bottom = 5;
			p->Margins->Left = 5;
			p->Margins->Right = 5;

			_panels.push_back(p);

			p->Form_Initialize(r*col +c);
		}
	}

	this->resize_grid_panel();
}
//---------------------------------------------------------------------------
void	TfrmQcPositionSetup::resize_grid_panel()
{
	GridPanel1->Width = (160 + 2) * GridPanel1->ColumnCollection->Count;
	GridPanel1->Height = (100 + 2) * GridPanel1->RowCollection->Count;

	GridPanel1->Left = (Panel5->Width / 2) - (GridPanel1->Width / 2);
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
//---------------------------------------------------------------------------
void	TfrmQcPositionSetup::readGerberData()
{
	int group = nReadGroupNo();
	int recipe = nReadRecipeNo();

	String file = ExtractFilePath(Application->ExeName)+ "\\ini\\system\\GRP"+IntToStr(group)+"\\RCP"+IntToStr(recipe)+"\\exportData.ini";
	if(FileExists(file))
	{
		TIniFile* orgData = new TIniFile(file);

		int count = orgData->ReadInteger("PATH_ARRAY_INFO","QC COUNT",0);
		if(count == _panels.size())
		{
			for(int i=0; i < count; i++)
			{
				((TFrmQcUnitControl*)_panels.at(i))->EditXSize->Text = orgData->ReadString("PATH_ARRAY_INFO","QC_POINT"+IntToStr(i+1)+"_X",0);
				((TFrmQcUnitControl*)_panels.at(i))->EditYSize->Text = orgData->ReadString("PATH_ARRAY_INFO","QC_POINT"+IntToStr(i+1)+"_Y",0);

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
void __fastcall TfrmQcPositionSetup::BtnInputDataClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	BtnInputData->Enabled = false;
	BtnSaveData->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmQcPositionSetup::BtnSaveDataClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	for(int i = 0; i < _panels.size(); i++)
	{
		((TFrmQcUnitControl*)_panels[i])->DataSave(i);
    }

	BtnInputData->Enabled = true;
	BtnSaveData->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TfrmQcPositionSetup::SpeedButton1Click(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	//
    FrmCdBox->setFlag(CD_YESNO);
    FrmCdBox->setTitle("READ GERBER DATA");
    FrmCdBox->setText("Do you want to read the file from gerber?");
    if( mrYes == FrmCdBox->ShowModal())
    {
		this->readGerberData();
	}

}
//---------------------------------------------------------------------------

void __fastcall TfrmQcPositionSetup::BtnSaveUnitCntClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

    FrmCdBox->setFlag(CD_YESNO);
    FrmCdBox->setTitle("QC Position count save");
    FrmCdBox->setText("Are you sure about saving QC position count?");
    if( mrYes == FrmCdBox->ShowModal())
    {
        int x = Edit1->Text.ToInt();
        int y = Edit2->Text.ToInt();
     	dWritePkgData(x,PKG_QCUNIT_X_CNT);
        dWritePkgData(y,PKG_QCUNIT_Y_CNT);

        WriteIntegerToRecipeInifile("PkgParam.ini","PKGPARM","VALUE"+IntToStr(PKG_QCUNIT_X_CNT),x);
        WriteIntegerToRecipeInifile("PkgParam.ini","PKGPARM","VALUE"+IntToStr(PKG_QCUNIT_Y_CNT),y);
	}

	this->Frm_UnitDisplay();

	BtnSaveUnitCnt->Enabled = false;;
	BtnInputUnitCnt->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmQcPositionSetup::BtnInputUnitCntClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	BtnSaveUnitCnt->Enabled = true;
	BtnInputUnitCnt->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TfrmQcPositionSetup::FormShow(TObject *Sender)
{
	this->readGerberData();
}
//---------------------------------------------------------------------------

