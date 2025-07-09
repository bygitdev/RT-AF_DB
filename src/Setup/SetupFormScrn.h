//---------------------------------------------------------------------------

#ifndef SetupFormScrnH
#define SetupFormScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------

#define   _MAX_SUB_SETUP_FORM_ 	7

class TSetupForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TComboBox *ComboBoxAccessLevel;
	TPanel *Panel2;
	TBitBtn *BitBtn6;
	TPanel *SetupBasePanel;
	TBitBtn *SetupFrmSub3;
	TBitBtn *SetupFrmSub5;
	TBitBtn *SetupFrmSub4;
	TBitBtn *SetupFrmSub7;
	TBitBtn *SetupFrmSub6;
	TBitBtn *SystemFrmSubBtn4;
	TBitBtn *SystemFrmSubBtn5;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	void __fastcall SetupFrmSub1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
    TForm* _pCurrentForm;
public:		// User declarations
	__fastcall TSetupForm(TComponent* Owner);
    void 	ScreenChange(String menu);
};
//---------------------------------------------------------------------------
extern PACKAGE TSetupForm *SetupForm;
//---------------------------------------------------------------------------
#endif
