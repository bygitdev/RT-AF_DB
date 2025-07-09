//---------------------------------------------------------------------------

#ifndef FormManualCuttingScrnH
#define FormManualCuttingScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "iComponent.hpp"
#include "iCustomComponent.hpp"
#include "iEdit.hpp"
#include "iEditCustom.hpp"
#include "iLedMatrix.hpp"
#include "iVCLComponent.hpp"
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Graphics.hpp>
#include "CurvyControls.hpp"
#include <Vcl.Buttons.hpp>
#include "iLed.hpp"
#include "iLedDiamond.hpp"
#include "iLedRound.hpp"
#include <Vcl.Grids.hpp>
#include "BaseComm.h"
//---------------------------------------------------------------------------

typedef enum
{
	NONE = 0,
	GOOD,
}PCB_STATUS;

class TFormManualCutting : public TForm
{
__published:	// IDE-managed Components
	TCurvyPanel *CurvyPanel1;
	TPanel *Panel2;
	TBitBtn *BtnAllUnit;
	TBitBtn *BtnReset;
	TBitBtn *BtnHorizontal;
	TBitBtn *BtnVertical;
	TBitBtn *BtnInverse;
	TBitBtn *BtnCuttingRead;
	TBitBtn *BtnCuttingWrite;
	TPanel *MatrixBasePanel;
	TPanel *Panel1;
	TBitBtn *BtnSelect1;
	TBitBtn *BtnSelect3;
	TBitBtn *BtnSelect4;
	TBitBtn *BtnSelect2;
	TLabel *Label2;
	TBitBtn *BtnSelect5;
	TBitBtn *BtnSelect6;
	TBitBtn *BtnSelect7;
	TBitBtn *BtnFlipper;
	TStringGrid *StringGridSubstrate;
	void __fastcall BtnSelect1Click(TObject *Sender);
	void __fastcall BtnResetClick(TObject *Sender);
	void __fastcall BtnInverseClick(TObject *Sender);
	void __fastcall BtnHorizontalClick(TObject *Sender);
	void __fastcall BtnVerticalClick(TObject *Sender);
	void __fastcall BtnAllUnitClick(TObject *Sender);
	void __fastcall BtnCuttingWriteClick(TObject *Sender);
	void __fastcall BtnCuttingReadClick(TObject *Sender);
	void __fastcall BtnFlipperClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall StringGridSubstrateMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall StringGridSubstrateMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall StringGridSubstrateDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
	void __fastcall StringGridSubstrateSelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect);
	void __fastcall FormShow(TObject *Sender);

private:	// User declarations
	POINT	_drag_start;
	bool	_lmouse_down;

	int nStripIndex;
	int nActivateRow , nActivateCol;

	bool bStageIndex;
	bool bKeepCutChkClick;
	bool bVacTenkeyCmd;

	TForm* formFlipper;

	int		_status[_MAX_COL_COUNT_][_MAX_ROW_COUNT_];

private:

	void __fastcall SetGridPanels(int stageIndex);

	void MatrixInfoRead(int nStageNumber);
	void MatrixInfoWrite(int nStageNumber);
    void  StripMatrixDataRead(TiLedMatrix* CloneLedMatrix , int nStageNumber);

public:		// User declarations

	void FormManualCut_Initialize();

	__fastcall TFormManualCutting(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TFormManualCutting *FormManualCutting;
//---------------------------------------------------------------------------
#endif
