//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fbarcode.h"
#include "MainFormScrn.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmBarcode *frmBarcode;
//---------------------------------------------------------------------------
__fastcall TfrmBarcode::TfrmBarcode(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmBarcode::Button6Click(TObject *Sender)
{
	g_barcode[BCD_ADC]->trigger(true);
}
//---------------------------------------------------------------------------
void __fastcall TfrmBarcode::Button5Click(TObject *Sender)
{
	g_barcode[BCD_ADC]->trigger(false);
}
//---------------------------------------------------------------------------
