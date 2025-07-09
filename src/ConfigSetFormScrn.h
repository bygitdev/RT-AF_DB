//---------------------------------------------------------------------------

#ifndef ConfigSetFormScrnH
#define ConfigSetFormScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "CurvyControls.hpp"
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TConfigSetForm : public TForm
{
__published:	// IDE-managed Components
	TCurvyPanel *CurvyPanel1;
	TBitBtn *BtnClose;
	TGroupBox *GroupBox1;
	TComboBox *ComboSC1;
	TComboBox *ComboSC2;
	TComboBox *ComboSC3;
	TComboBox *ComboSC4;
	TComboBox *ComboSC6;
	TGroupBox *GroupBox2;
	TBitBtn *BtnSystemClose;
	TSpeedButton *BtnSaveConfig;
	TComboBox *ComboSC5;
	TGroupBox *GroupBox3;
	TBitBtn *BtnScreenLock;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall BtnSaveConfigClick(TObject *Sender);
	void __fastcall BtnSystemCloseClick(TObject *Sender);
	void __fastcall BtnCloseClick(TObject *Sender);
	void __fastcall BtnScreenLockClick(TObject *Sender);
private:	// User declarations
	void ReadIniSet_Shortcut();
public:		// User declarations
	__fastcall TConfigSetForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TConfigSetForm *ConfigSetForm;
//---------------------------------------------------------------------------
#endif
