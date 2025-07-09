//---------------------------------------------------------------------------

#ifndef FormNumberKeyPadScrnH
#define FormNumberKeyPadScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "iComponent.hpp"
#include "iCustomComponent.hpp"
#include "iPhonePad.hpp"
#include "iVCLComponent.hpp"
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Touch.Keyboard.hpp>
#include "iKeyBoard.hpp"
//---------------------------------------------------------------------------
class TFormNumberKeyPad : public TForm
{
__published:	// IDE-managed Components
	TEdit *EditNumberData;
	TButton *BtnNumberkeyPad1;
	TButton *BtnNumberkeyPad2;
	TButton *BtnNumberkeyPad3;
	TButton *BtnNumberkeyPad4;
	TButton *BtnNumberkeyPad5;
	TButton *BtnNumberkeyPad6;
	TButton *BtnNumberkeyPadEnter;
	TButton *BtnNumberkeyPadBK;
	TButton *BtnNumberkeyPad7;
	TButton *BtnNumberkeyPad8;
	TButton *BtnNumberkeyPad9;
	TButton *BtnNumberkeyPad0;
	void __fastcall BtnNumberkeyPad1Click(TObject *Sender);
	void __fastcall BtnNumberkeyPadEnterClick(TObject *Sender);
	void __fastcall BtnNumberkeyPadBKClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall EditNumberDataDblClick(TObject *Sender);


private:	// User declarations
public:		// User declarations
	String GetKeyNumber();
	__fastcall TFormNumberKeyPad(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormNumberKeyPad *FormNumberKeyPad;
//---------------------------------------------------------------------------
#endif
