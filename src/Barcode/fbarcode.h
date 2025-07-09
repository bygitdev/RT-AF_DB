//---------------------------------------------------------------------------

#ifndef fbarcodeH
#define fbarcodeH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmBarcode : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *TabSheet3;
	TButton *Button5;
	TButton *Button6;
	TMemo *Memo1;
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmBarcode(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmBarcode *frmBarcode;
//---------------------------------------------------------------------------
#endif
