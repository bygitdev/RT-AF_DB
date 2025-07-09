//---------------------------------------------------------------------------

#ifndef frmADCBarcodeRegH
#define frmADCBarcodeRegH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TfrmADBBarcodeReg : public TForm
{
__published:	// IDE-managed Components
	TSpeedButton *sbInput;
	TStringGrid *sgBarcode;
	TSpeedButton *sbSave;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall sbInputClick(TObject *Sender);
	void __fastcall sbSaveClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmADBBarcodeReg(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmADBBarcodeReg *frmADBBarcodeReg;
//---------------------------------------------------------------------------
#endif
