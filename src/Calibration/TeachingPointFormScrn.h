//---------------------------------------------------------------------------

#ifndef TeachingPointFormScrnH
#define TeachingPointFormScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "CurvyControls.hpp"
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TTeachingPointForm : public TForm
{
__published:	// IDE-managed Components
	TCurvyPanel *CurvyPanel3;
	TPanel *Panel1;
	TStringGrid *PalletTeachGrid;
	TPanel *Panel2;
	TSpeedButton *BtnInputItem;
	TSpeedButton *BtnSaveItem;
	TBitBtn *BtnPallet1;
	TBitBtn *BtnPallet2;
	TBitBtn *BtnTraySet2;
	TBitBtn *BtnTraySet1;
	TPanel *Panel3;
	TStringGrid *TrayTeachGrid;
	TPanel *Panel4;
	TSpeedButton *BtnTrayInput;
	TSpeedButton *BtnTraySave;
	TBitBtn *BtnTraySet3;
	void __fastcall BtnInputItemClick(TObject *Sender);
	void __fastcall BtnSaveItemClick(TObject *Sender);
	void __fastcall BtnTrayInputClick(TObject *Sender);
	void __fastcall BtnTraySaveClick(TObject *Sender);
	void __fastcall BtnPallet1Click(TObject *Sender);
	void __fastcall BtnTraySet1Click(TObject *Sender);
private:	// User declarations

	int _nPalletStage_;
	int _nTrayStage_;

    void 	PalletData_Read(int nStage);
    void    PalletData_Save(int nStage);

    void 	TrayData_Read(int nStage);
    void    TrayData_Save(int nStage);

public:		// User declarations

    void PalletData_Initialize(int nIndex);
    void TrayData_Initialize(int nIndex);
	__fastcall TTeachingPointForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTeachingPointForm *TeachingPointForm;
//---------------------------------------------------------------------------
#endif
