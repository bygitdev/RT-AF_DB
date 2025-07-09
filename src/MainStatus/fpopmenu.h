//---------------------------------------------------------------------------

#ifndef fpopmenuH
#define fpopmenuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "CurvyControls.hpp"
//---------------------------------------------------------------------------
class TFrmPopMenu : public TForm
{
__published:	// IDE-managed Components
	TCurvyPanel *CurvyPanel1;
	TGridPanel *GridPanel1;
	TBitBtn *ButtonScreenLock;
	TBitBtn *ButtonMMIClose;
	void __fastcall ButtonScreenLockClick(TObject *Sender);
	void __fastcall ButtonMMICloseClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFrmPopMenu(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmPopMenu *FrmPopMenu;
//---------------------------------------------------------------------------
#endif
