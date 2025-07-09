//---------------------------------------------------------------------------

#ifndef falphaH
#define falphaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TFrmApha : public TForm
{
__published:	// IDE-managed Components
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFrmApha(TComponent* Owner);

	//void AlphaShowModal(TForm* form);
	TModalResult AlphaShowModal(TForm* form);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmApha *FrmApha;
//---------------------------------------------------------------------------
#endif
