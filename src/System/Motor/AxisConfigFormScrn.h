//---------------------------------------------------------------------------

#ifndef AxisConfigFormScrnH
#define AxisConfigFormScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "CurvyControls.hpp"
#include <Vcl.Buttons.hpp>
#include <Vcl.Grids.hpp>
#include "AdvGrid.hpp"
#include "AdvObj.hpp"
#include "BaseGrid.hpp"
//---------------------------------------------------------------------------
class TMotorAxisConfig : public TForm
{
__published:	// IDE-managed Components
	TCurvyPanel *CurvyPanel1;
	TBitBtn *BtnClose;
	TSpeedButton *BtnSaveItem;
	TSpeedButton *BtnInputItem;
	TStringGrid *StringGridAxis;
	TLabel *Label1;
	void __fastcall BtnCloseClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall BtnInputItemClick(TObject *Sender);
	void __fastcall BtnSaveItemClick(TObject *Sender);
	void __fastcall StringGridAxisKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);


private:	// User declarations
	void MotorRecipeSet_Read();
public:		// User declarations
	__fastcall TMotorAxisConfig(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMotorAxisConfig *MotorAxisConfig;
//---------------------------------------------------------------------------
#endif
