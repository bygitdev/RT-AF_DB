//---------------------------------------------------------------------------

#ifndef FormTowerLampScrnH
#define FormTowerLampScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "CurvyControls.hpp"
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TFormTowerLamp : public TForm
{
__published:	// IDE-managed Components
	TCurvyPanel *CurvyPanel1;
	TLabel *Label1;
	TStringGrid *TowerLampGrid;
	TPanel *Panel1;
	TSpeedButton *BtnBuzzerSW;
	TSpeedButton *BtnBuzzerTimer;
	TEdit *EditBuzzerTime;
	TPanel *PanelBuzzerLed;
	TPanel *Panel2;
	TPanel *Panel3;
	TPanel *Panel4;
	TPanel *Panel5;
	TPanel *Panel6;
	TComboBox *ComboBoxR1;
	TComboBox *ComboBoxBuzzer1;
	TComboBox *ComboBoxR2;
	TComboBox *ComboBoxR3;
	TComboBox *ComboBoxR4;
	TComboBox *ComboBoxR5;
	TComboBox *ComboBoxR6;
	TComboBox *ComboBoxR7;
	TComboBox *ComboBoxY7;
	TComboBox *ComboBoxY6;
	TComboBox *ComboBoxY5;
	TComboBox *ComboBoxY4;
	TComboBox *ComboBoxY3;
	TComboBox *ComboBoxY2;
	TComboBox *ComboBoxY1;
	TComboBox *ComboBoxG7;
	TComboBox *ComboBoxG6;
	TComboBox *ComboBoxG5;
	TComboBox *ComboBoxG4;
	TComboBox *ComboBoxG3;
	TComboBox *ComboBoxG2;
	TComboBox *ComboBoxG1;
	TComboBox *ComboBoxBuzzer2;
	TComboBox *ComboBoxBuzzer3;
	TComboBox *ComboBoxBuzzer4;
	TComboBox *ComboBoxBuzzer5;
	TComboBox *ComboBoxBuzzer6;
	TComboBox *ComboBoxBuzzer7;
	void __fastcall BtnBuzzerSWClick(TObject *Sender);
	void __fastcall BtnBuzzerTimerClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ComboBoxR1Change(TObject *Sender);

private:	// User declarations
	void TowerLampRefreshStatus();

public:		// User declarations
	void TowerLamp_Initialize();
	__fastcall TFormTowerLamp(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormTowerLamp *FormTowerLamp;
//---------------------------------------------------------------------------
#endif
