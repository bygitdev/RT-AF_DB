//---------------------------------------------------------------------------

#ifndef WarningScrnH
#define WarningScrnH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------

class TFrmWarning : public TForm
{
__published:	// IDE-managed Components
	TMemo *Memo1;
	TLabel *Label1;
	TLabel *Label2;
	void __fastcall FormDblClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TFrmWarning(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmWarning *FrmWarning;
//---------------------------------------------------------------------------
#endif
