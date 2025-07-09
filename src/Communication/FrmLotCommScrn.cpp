//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FrmLotCommScrn.h"
#include "MainFormScrn.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma resource "*.dfm"
TFrmLotComm *FrmLotComm;
//---------------------------------------------------------------------------
__fastcall TFrmLotComm::TFrmLotComm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFrmLotComm::BtnCloseClick(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFrmLotComm::BtnBcdOnClick(TObject *Sender)
{
	g_barcode[BCD_ADC]->trigger(true);
}
//---------------------------------------------------------------------------

void __fastcall TFrmLotComm::BtnBcdOffClick(TObject *Sender)
{
	g_barcode[BCD_ADC]->trigger(false);
}
//---------------------------------------------------------------------------

void __fastcall TFrmLotComm::BtnRfidOnClick(TObject *Sender)
{
	if (false == g_rfid->trigger(0))
    {
    	ShowMessage("Fail to write serial comm port !");
    }
}
//---------------------------------------------------------------------------

void __fastcall TFrmLotComm::BtnRfidOffClick(TObject *Sender)
{
    if (FALSE == g_rfid->write(0,edtStepID->Text,edtLotID->Text,edtPartNo->Text,edtFrameCount->Text))
    {
    	ShowMessage("Fail to write serial comm port !");
    }
}
//---------------------------------------------------------------------------

