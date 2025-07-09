//---------------------------------------------------------------------------

#ifndef fECMRH
#define fECMRH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "AdvGlowButton.hpp"
//---------------------------------------------------------------------------
class TfrmECMR : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label3;
	TEdit *txtPartID;
	TEdit *txtStepNo;
	TAdvGlowButton *btnOk;
	TAdvGlowButton *btnCancel;
	void __fastcall btnCancelClick(TObject *Sender);
	void __fastcall btnOkClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmECMR(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmECMR *frmECMR;
//---------------------------------------------------------------------------
#endif
