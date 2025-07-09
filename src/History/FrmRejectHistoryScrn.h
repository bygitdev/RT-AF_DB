//---------------------------------------------------------------------------

#ifndef FrmRejectHistoryScrnH
#define FrmRejectHistoryScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "CurvyControls.hpp"
#include "AdvDateTimePicker.hpp"
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TFrmRejectHistory : public TForm
{
__published:	// IDE-managed Components
	TCurvyPanel *CurvyPanel1;
	TLabel *LabelHistory;
	TPanel *Panel1;
	TBitBtn *BtnRejecttRead;
	TAdvDateTimePicker *DateTimeEnd;
	TAdvDateTimePicker *DateTimeStart;
	TStringGrid *StrGridList;
	TPanel *MatrixBasePanel;
	TStringGrid *StringGridSubstrate;
	void __fastcall BtnRejecttReadClick(TObject *Sender);
	void __fastcall StringGridSubstrateDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
	void __fastcall StrGridListSelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);


private:	// User declarations
	String   _StrLoadRejectdata;
	void  LoadLotCode(String StrLotCode );

	void StripMakeDraw(int nGroup , int nrecipe , String StrData);
public:		// User declarations
	__fastcall TFrmRejectHistory(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmRejectHistory *FrmRejectHistory;
//---------------------------------------------------------------------------
#endif
