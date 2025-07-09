//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitControlScrn.h"
#include "BaseComm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma link "cspin"
#pragma resource "*.dfm"
TFrmUnitControl *FrmUnitControl;
//---------------------------------------------------------------------------
__fastcall TFrmUnitControl::TFrmUnitControl(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TFrmUnitControl::Form_Initialize(int nIndex)
{
	_nLocateIndex =   nIndex;
	LabelNotify->Caption =  "UNIT " + IntToStr(_nLocateIndex+1);

    _nXnumber = pcb00PosX + (nIndex * 2);
	_nYnumber = pcb00PosY + (nIndex * 2);
	_nTheta	  = pcb00Theta + (nIndex);
    _bBinNo	  = bin00No + (nIndex);


    _FlipStatusnumber = pcb00isFlip + (nIndex);

	this->UnitDataRead(_nLocateIndex);
}
//---------------------------------------------------------------------------

void TFrmUnitControl::_UnitDataSave(int nIndex)
{
	int nGrpNo, nRcpNo;

    nGrpNo = nReadGroupNo();
    nRcpNo = nReadRecipeNo();


    if(EditXSize->Text == "")
    {
    	EditXSize->Text = "0";
    }
    if(EditYSize->Text == "")
    {
    	EditYSize->Text = "0";
	}
	if(EditTheta->Text == "")
    {
    	EditTheta->Text = "0";
	}
	if(CSpinEditBinNo->Text == "")
    {
    	CSpinEditBinNo->Text = "1";
	}



	TIniFile *PkgParmini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(nGrpNo)+"\\RCP"+IntToStr(nRcpNo)+"\\PkgParam.ini");

	PkgParmini->WriteString("PKGPARM","VALUE"+IntToStr(_nXnumber),EditXSize->Text);
	PkgParmini->WriteString("PKGPARM","VALUE"+IntToStr(_nYnumber),EditYSize->Text);
	PkgParmini->WriteString("PKGPARM","VALUE"+IntToStr(_nTheta),EditTheta->Text);
    PkgParmini->WriteString("PKGPARM","VALUE"+IntToStr(_bBinNo),CSpinEditBinNo->Text);



	bool flag = false;
	if(PanelFlip->Color == clLime) flag = true;
	PkgParmini->WriteInteger("PKGPARM","VALUE"+IntToStr(_FlipStatusnumber),flag);

	delete PkgParmini;


	dWritePkgData(StrToFloat(EditXSize->Text), _nXnumber);
	dWritePkgData(StrToFloat(EditYSize->Text), _nYnumber);
	dWritePkgData(StrToFloat(EditTheta->Text), _nTheta);
    dWritePkgData(CSpinEditBinNo->Value, _bBinNo);

	dWritePkgData(flag, _FlipStatusnumber);

	this->UnitDataRead(_nLocateIndex);
}
//---------------------------------------------------------------------------

void TFrmUnitControl::UnitDataRead(int nIndex)
{

	EditXSize->Text =  FloatToStr(dReadPkgData(_nXnumber));
	EditYSize->Text =  FloatToStr(dReadPkgData(_nYnumber));
	EditTheta->Text = 	FloatToStr(dReadPkgData(_nTheta));
    CSpinEditBinNo->Value = dReadPkgData(_bBinNo);

	bool dbFlipVal =  bool(dReadPkgData(_FlipStatusnumber));

	PanelFlip->Color =  dbFlipVal ? clLime : clGray;
	PanelFlip->Caption =   "";
	PanelFlip->Caption =   dbFlipVal ? "FLIP ON" : "FLIP OFF";

}
//---------------------------------------------------------------------------
void __fastcall TFrmUnitControl::PanelFlipDblClick(TObject *Sender)
{
	bool flag = true;
	if(PanelFlip->Color == clLime)
	{
		flag = false;
	}

	PanelFlip->Color =  flag ? clLime : clGray;
	PanelFlip->Caption =   "";
	PanelFlip->Caption =   flag ? "FLIP ON" : "FLIP OFF";

}
//---------------------------------------------------------------------------
