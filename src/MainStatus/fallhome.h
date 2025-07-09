//---------------------------------------------------------------------------

#ifndef fallhomeH
#define fallhomeH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <vector>
//---------------------------------------------------------------------------
class TfrmAllhomeStatus : public TForm
{
__published:	// IDE-managed Components
	TGridPanel *GridPanel1;
	TTimer *Timer1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations
	std::vector<TPanel*>	_panels;
	std::vector<TLabel*>	_labels;

public:		// User declarations
	__fastcall TfrmAllhomeStatus(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmAllhomeStatus *frmAllhomeStatus;
//---------------------------------------------------------------------------
#endif
