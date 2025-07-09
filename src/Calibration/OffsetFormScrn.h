//---------------------------------------------------------------------------

#ifndef OffsetFormScrnH
#define OffsetFormScrnH
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
class TOffsetForm : public TForm
{
__published:	// IDE-managed Components
	TCurvyPanel *CurvyPanel3;
	TPanel *Panel1;
	TStringGrid *StageGridOffset;
	TLabel *LabelOffsetIndicator;
	TBitBtn *BtnOffsetStage1;
	TBitBtn *BtnOffsetStage2;
	TBitBtn *BtnOffsetStage3;
	TBitBtn *BtnOffsetStage4;
	TPanel *Panel2;
	TSpeedButton *BtnInputItem;
	TSpeedButton *BtnSaveItem;
	void __fastcall BtnOffsetStage1Click(TObject *Sender);
	void __fastcall BtnInputItemClick(TObject *Sender);
	void __fastcall BtnSaveItemClick(TObject *Sender);
private:	// User declarations
    int _nStageNumber_;

    void  OffsetData_Read(int nStage);
    void  OffsetData_Save(int nStage);
public:		// User declarations

	void OffsetData_Initialize(int nStage);
	__fastcall TOffsetForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TOffsetForm *OffsetForm;
//---------------------------------------------------------------------------
#endif
