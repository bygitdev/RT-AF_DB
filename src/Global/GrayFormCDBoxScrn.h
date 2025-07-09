//---------------------------------------------------------------------------

#ifndef GrayFormCDBoxScrnH
#define GrayFormCDBoxScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TGrayFrmCDBOX : public TForm
{
__published:	// IDE-managed Components
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	void __fastcall Display();
	__fastcall TGrayFrmCDBOX(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TGrayFrmCDBOX *GrayFrmCDBOX;
//---------------------------------------------------------------------------
#endif
