//---------------------------------------------------------------------------

#ifndef WarningPopupScrnH
#define WarningPopupScrnH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------

class TFrmWarningPopup : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TTimer *Timer1;
	TMemo *Memo1;
	TBitBtn *btnManualClose;
	void __fastcall FormDblClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
	int _warningNum;
	bool _mode;
public:		// User declarations
	void	setWarningNum(int warningNum, bool mode);
	__fastcall TFrmWarningPopup(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmWarningPopup *FrmWarningPopup;
//---------------------------------------------------------------------------
#endif
