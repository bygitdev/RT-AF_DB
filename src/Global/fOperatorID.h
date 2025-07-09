//---------------------------------------------------------------------------

#ifndef fOperatorIDH
#define fOperatorIDH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmOperatorID : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TLabel *labelName;
	TButton *Button1;
	TPanel *PanelOpID;
	TButton *Button2;
	TEdit *EditOpeartorID;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmOperatorID(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmOperatorID *frmOperatorID;
//---------------------------------------------------------------------------
#endif
