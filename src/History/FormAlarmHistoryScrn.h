//---------------------------------------------------------------------------

#ifndef FormAlarmHistoryScrnH
#define FormAlarmHistoryScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "CurvyControls.hpp"
#include <Vcl.Buttons.hpp>
#include <Vcl.Grids.hpp>
#include "iComponent.hpp"
#include "iCustomComponent.hpp"
#include "iEdit.hpp"
#include "iEditCustom.hpp"
#include "iVCLComponent.hpp"
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
#include "AdvSmoothTimeLine.hpp"
#include "AdvDateTimePicker.hpp"
//---------------------------------------------------------------------------
class TFormAlarmHistory : public TForm
{
__published:	// IDE-managed Components
	TCurvyPanel *CurvyPanel1;
	TLabel *LabelHistory;
	TStringGrid *AlarmDateTimeGrid;
	TPanel *Panel1;
	TLabel *Label3;
	TLabel *Label2;
	TLabel *Label4;
	TBitBtn *BtnAlarmRead1;
	TShape *Shape1;
	TShape *Shape2;
	TBitBtn *BtnAlarmRead2;
	TBitBtn *BtnAlarmHistorySave;
	TEdit *EditAlarmCodeSearch;
	TSaveTextFileDialog *SaveTextFileDialog;
	TBitBtn *BtnAlarmHistoryCsvSave;
	TAdvDateTimePicker *DateTimeAlarmStart;
	TAdvDateTimePicker *DateTimeAlarmEnd;
	TSaveTextFileDialog *SaveCsvFileDialog;
	TPanel *Panel2;
	TRadioButton *RadioBtnAlarm;
	TRadioButton *RadioBtnWarning;
	TRadioButton *RadioBtnError;
	void __fastcall BtnAlarmRead1Click(TObject *Sender);
	void __fastcall BtnAlarmRead2Click(TObject *Sender);
	void __fastcall BtnAlarmHistorySaveClick(TObject *Sender);
	void __fastcall BtnAlarmHistoryCsvSaveClick(TObject *Sender);
	void __fastcall RadioBtnAlarmClick(TObject *Sender);
	void __fastcall RadioBtnWarningClick(TObject *Sender);
	void __fastcall RadioBtnErrorClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
	void SaveToCSVFile(TStringGrid *sGrid,String sCSVFile);
public:		// User declarations

	__fastcall TFormAlarmHistory(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormAlarmHistory *FormAlarmHistory;
//---------------------------------------------------------------------------
#endif
