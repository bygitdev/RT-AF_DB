//---------------------------------------------------------------------------

#ifndef frouterH
#define frouterH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>

//---------------------------------------------------------------------------
class TFrmRouteScreen : public TForm
{
__published:	// IDE-managed Components
	TGridPanel *GridPanel1;
	TPanel *PanelMain;
	TGridPanel *GridPanel2;
	TBitBtn *BitBtn3;
	TBitBtn *BitBtn2;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall MenuButtonClick(TObject *Sender);
	void __fastcall GridPanel2Click(TObject *Sender);
private:	// User declarations
	TForm*	_pCurrentForm;
public:		// User declarations
	void __fastcall ScreenChange(String menu);
	__fastcall TFrmRouteScreen(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmRouteScreen *FrmRouteScreen;
//---------------------------------------------------------------------------
#endif
