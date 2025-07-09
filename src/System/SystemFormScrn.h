//---------------------------------------------------------------------------

#ifndef SystemFormScrnH
#define SystemFormScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
#define   _MAX_SUB_SYSTEM_FORM_ 	6

class TSystemForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TComboBox *ComboBoxAccessLevel;
	TPanel *Panel2;
	TBitBtn *BitBtn6;
	TBitBtn *SystemFrmSubBtn1;
	TBitBtn *SystemFrmSubBtn2;
	TBitBtn *SystemFrmSubBtn3;
	TPanel *SystemBasePanel;
	TBitBtn *SystemFrmSubBtn6;
	TBitBtn *SetupFrmSub1;
	TBitBtn *SetupFrmSub2;
	void __fastcall SystemFrmSubBtn1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall SystemFrmSubBtn6Click(TObject *Sender);
private:	// User declarations
    TForm* _pCurrentForm;
public:		// User declarations

    void	ScreenChange(String menu);
	__fastcall TSystemForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSystemForm *SystemForm;
//---------------------------------------------------------------------------
#endif
