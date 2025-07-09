//---------------------------------------------------------------------------

#ifndef hookH
#define hookH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>



//---------------------------------------------------------------------------
class TFrmHook : public TForm
{
__published:	// IDE-managed Components
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations

	BOOL	registerPasswordWindow();
  

public:		// User declarations
	__fastcall TFrmHook(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmHook *FrmHook;
//---------------------------------------------------------------------------
#endif
