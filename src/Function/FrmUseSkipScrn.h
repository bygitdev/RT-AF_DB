//---------------------------------------------------------------------------

#ifndef FrmUseSkipScrnH
#define FrmUseSkipScrnH
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
class TFrmUseSkip : public TForm
{
__published:	// IDE-managed Components
	TCurvyPanel *CurvyPanel1;
	TBitBtn *BtnClose;
	TTimer *UseSkipTimer;
	TStringGrid *UseSkipGrid;
	void __fastcall BtnCloseClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall UseSkipTimerTimer(TObject *Sender);
	void __fastcall UseSkipGridDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall UseSkipGridDblClick(TObject *Sender);
private:	// User declarations
	bool bFailIni;
	int nUseSkipNumber[50];
    bool bUseSkipStatus[50];


	void UseSkipRead();
	void LotModeControl(int nModeIndex);
public:		// User declarations
	__fastcall TFrmUseSkip(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmUseSkip *FrmUseSkip;
//---------------------------------------------------------------------------
#endif
