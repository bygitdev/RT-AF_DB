//---------------------------------------------------------------------------

#ifndef FrmCleanScreenScrnH
#define FrmCleanScreenScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFrmCleanScreen : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TTimer *CleanTimer;
	TLabel *Label1;
	TLabel *LabelRemainSec;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall CleanTimerTimer(TObject *Sender);
private:	// User declarations
	int 	nEstTime;
public:		// User declarations
	__fastcall TFrmCleanScreen(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmCleanScreen *FrmCleanScreen;
//---------------------------------------------------------------------------
#endif
