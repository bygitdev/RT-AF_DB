//---------------------------------------------------------------------------

#ifndef FormLifeTimeSetScrnH
#define FormLifeTimeSetScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "CurvyControls.hpp"
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include "AdvGrid.hpp"
#include "AdvObj.hpp"
#include "BaseGrid.hpp"
//---------------------------------------------------------------------------
class TFormLifeTimeSet : public TForm
{
__published:	// IDE-managed Components
	TPanel *PanelSystemBase;
	TCurvyPanel *CurvyPanel1;
	TSpeedButton *BtnParamIndexMoveM10;
	TSpeedButton *BtnParamIndexMoveP10;
	TSpeedButton *BtnSaveItem;
	TSpeedButton *BtnInputItem;
	TLabel *Label1;
	TTimer *LifeTimeTimer;
	TStringGrid *LifeTimeParamGrid;
	TSpeedButton *SpeedButton1;
	void __fastcall BtnInputItemClick(TObject *Sender);
	void __fastcall BtnSaveItemClick(TObject *Sender);
	void __fastcall LifeTimeTimerTimer(TObject *Sender);
	void __fastcall LifeTimeParamGridDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall SpeedButton1Click(TObject *Sender);
private:	// User declarations

	bool    LifeTime_read();
    bool    LifeTime_save();
    void    LifeTimeRefresh();
    void    LifeTimeSet();

public:		// User declarations

	void __fastcall TFormLifeTimeSet::LifeTimeScreen_Initialize();
	__fastcall TFormLifeTimeSet(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormLifeTimeSet *FormLifeTimeSet;
//---------------------------------------------------------------------------
#endif
