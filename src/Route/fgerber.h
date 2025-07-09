//---------------------------------------------------------------------------

#ifndef fgerberH
#define fgerberH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmRoute : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TTimer *Timer1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
	HWND _EMR_HWND;
	void	change_file(String filename);
	AnsiString	_caption;
public:		// User declarations
	__fastcall TfrmRoute(TComponent* Owner);

	void	RecipeChange();
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmRoute *frmRoute;
//---------------------------------------------------------------------------
#endif
