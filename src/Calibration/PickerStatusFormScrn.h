//---------------------------------------------------------------------------

#ifndef PickerStatusFormScrnH
#define PickerStatusFormScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "CurvyControls.hpp"
#include <Vcl.Grids.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TPickerStatusForm : public TForm
{
__published:	// IDE-managed Components
	TCurvyPanel *CurvyPanel3;
	TBitBtn *BtnPickerPartRead;
	TBitBtn *BtnJigPartRead;
	TBitBtn *BtnPickerAnglePartRead;
	TCurvyPanel *CurvyPanel1;
	TLabel *LabelUnit1;
	TStringGrid *Picker1StatusGrid;
	TCurvyPanel *CurvyPanel2;
	TLabel *LabelUnit2;
	TStringGrid *Picker2StatusGrid;
	TTimer *PickerJigTimer;
	TPanel *Panel1;
	TLabel *Label1;
	TSpeedButton *BtnInputItem;
	TPanel *Panel2;
	TEdit *EditTolerance1;
	TLabel *Label2;
	TPanel *Panel3;
	TLabel *Label3;
	TEdit *EditTolerance2;
	TPanel *Panel4;
	TLabel *Label4;
	TEdit *EditTolerance3;
	TPanel *Panel5;
	TLabel *Label5;
	TEdit *EditTolerance4;
	TSpeedButton *BtnSaveItem;
	void __fastcall BtnPickerPartReadClick(TObject *Sender);
	void __fastcall PickerJigTimerTimer(TObject *Sender);
	void __fastcall BtnInputItemClick(TObject *Sender);
	void __fastcall BtnSaveItemClick(TObject *Sender);
private:	// User declarations
    int nStartIndex1 , nStartIndex2;

	void UniveralPickerUnitStatusRefresh(int nStartIndex , TStringGrid *pGrid);

public:		// User declarations

	void PickerControl_Initialize(int nVal);
	__fastcall TPickerStatusForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPickerStatusForm *PickerStatusForm;
//---------------------------------------------------------------------------
#endif
