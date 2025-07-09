//---------------------------------------------------------------------------

#ifndef FrmAlarmScrnH
#define FrmAlarmScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Buttons.hpp>
#include "CurvyControls.hpp"
//---------------------------------------------------------------------------
class TFrmAlarm : public TForm
{
__published:	// IDE-managed Components
	TPanel *PanelSystemBase;
	TCurvyPanel *CurvyPanel1;
	TSpeedButton *BtnSaveItem;
	TStringGrid *AlarmViewGrid;
	TBitBtn *BtnIncrease100;
	TBitBtn *BtnIncrease1;
	TBitBtn *BtnIncrease10;
	TMemo *MemoAlarmSolution;
	TEdit *AlarmCodeText;
	TBitBtn *BtnDecrease1;
	TBitBtn *BtnDecrease10;
	TBitBtn *BtnDecrease100;
	TPanel *PanelAlarmNumber;
	TPanel *Panel1;
	TBitBtn *BtnAlarm1;
	TBitBtn *BtnAlarm2;
	TLabel *LabelAlarmcnt;
	TPanel *PanelAlarmBase;
	TCheckBox *CheckBoxAlarm;
	void __fastcall BtnSaveItemClick(TObject *Sender);
	void __fastcall BtnDecrease1Click(TObject *Sender);
	void __fastcall BtnIncrease1Click(TObject *Sender);
	void __fastcall AlarmViewGridSelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall BtnAlarm1Click(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);

private:	// User declarations

	int 	_nErrWarnSelect_;
    TIniFile  *AEWini;

	void  ReadAlarmDatas(int nRecNo);
	String  ReadAlarmNames(int nRecNo);
    String  ReadAlarmSol(int nRecNo);

public:		// User declarations

	void TFrmAlarm::AlarmDataInitialize(int nErrWarn);
	__fastcall TFrmAlarm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmAlarm *FrmAlarm;
//---------------------------------------------------------------------------
#endif
