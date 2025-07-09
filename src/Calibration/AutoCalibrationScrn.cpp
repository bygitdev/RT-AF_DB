//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AutoCalibrationScrn.h"
//---------------------------------------------------------------------------
#include "BaseComm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma resource "*.dfm"
TAutoCalibration *AutoCalibration;
//---------------------------------------------------------------------------
__fastcall TAutoCalibration::TAutoCalibration(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TAutoCalibration::BtnAutoCal1Click(TObject *Sender)
{
	int nVal = dynamic_cast<TBitBtn *>(Sender)->Tag;
   //	WriteCommNDM(m2sLaserCalSize ,  nVal);
}
//---------------------------------------------------------------------------

