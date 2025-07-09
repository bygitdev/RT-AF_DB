//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "frmADCBarcodeReg.h"
#include <inifiles.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmADBBarcodeReg *frmADBBarcodeReg;
//---------------------------------------------------------------------------
__fastcall TfrmADBBarcodeReg::TfrmADBBarcodeReg(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmADBBarcodeReg::FormShow(TObject *Sender)
{
	//
    sgBarcode->Cells[0][0] = "No";
    sgBarcode->Cells[1][0] = "Name";
    sgBarcode->Cells[2][0] = "Barcode";

    TIniFile* ini = new TIniFile(ExtractFilePath(Application->ExeName)+"adc.ini");

    for (int i=0; i< 100; i++)
    {
    	sgBarcode->Cells[0][i+1] = IntToStr(i+1);
        sgBarcode->Cells[1][i+1] =  ini->ReadString("ADC", "NAME"+IntToStr(i+1), "");
        sgBarcode->Cells[2][i+1] =  ini->ReadString("ADC", "BARCODE"+IntToStr(i+1), "");
    }

    delete ini;
}
//---------------------------------------------------------------------------
void __fastcall TfrmADBBarcodeReg::sbInputClick(TObject *Sender)
{
    sbInput->Enabled = false;
    sbSave->Enabled = true;

    sgBarcode->Options<<goEditing;
    sgBarcode->Options>>goRowSelect;
}
//---------------------------------------------------------------------------
void __fastcall TfrmADBBarcodeReg::sbSaveClick(TObject *Sender)
{
    sbInput->Enabled = true;
    sbSave->Enabled = false;

    sgBarcode->Options>>goEditing;
    sgBarcode->Options<<goRowSelect;

    TIniFile* ini = new TIniFile(ExtractFilePath(Application->ExeName)+"adc.ini");

    for (int i=0; i< 100; i++)
    {
        ini->WriteString("ADC", "NAME"+IntToStr(i+1),sgBarcode->Cells[1][i+1] );
        ini->WriteString("ADC", "BARCODE"+IntToStr(i+1),sgBarcode->Cells[2][i+1] );
    }

    delete ini;
}
//---------------------------------------------------------------------------
