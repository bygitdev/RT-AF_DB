//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fqcunitsetupcontrol.h"
#include "BaseComm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma resource "*.dfm"
TFrmQcUnitControl *FrmQcUnitControl;

#define INDEX_START 	300
//---------------------------------------------------------------------------
__fastcall TFrmQcUnitControl::TFrmQcUnitControl(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TFrmQcUnitControl::Form_Initialize(int nIndex)
{
	_nLocateIndex =   nIndex;
	LabelNotify->Caption =  "UNIT" + IntToStr(_nLocateIndex+1);

	_nXnumber = INDEX_START + (nIndex * 2);
	_nYnumber = INDEX_START + 1 + (nIndex * 2);

	this->UnitDataRead(_nLocateIndex);
}
//---------------------------------------------------------------------------

void TFrmQcUnitControl::DataSave(int nIndex)
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

	TIniFile *PkgParmini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(nGrpNo)+"\\RCP"+IntToStr(nRcpNo)+"\\PkgParam.ini");

	PkgParmini->WriteString("PKGPARM","VALUE"+IntToStr(_nXnumber),EditXSize->Text);
	PkgParmini->WriteString("PKGPARM","VALUE"+IntToStr(_nYnumber),EditYSize->Text);

	delete PkgParmini;


	dWritePkgData(StrToFloat(EditXSize->Text), _nXnumber);
	dWritePkgData(StrToFloat(EditYSize->Text), _nYnumber);

	this->UnitDataRead(_nLocateIndex);
}
//---------------------------------------------------------------------------

void TFrmQcUnitControl::UnitDataRead(int nIndex)
{
	EditXSize->Text =  FloatToStr(dReadPkgData(_nXnumber));
	EditYSize->Text =  FloatToStr(dReadPkgData(_nYnumber));
}
//---------------------------------------------------------------------------
void TFrmQcUnitControl::setPositionString(String x, String y)
{
	EditXSize->Text =  x;
	EditYSize->Text =  y;
}
