//---------------------------------------------------------------------------

#ifndef fLotEventHistoryH
#define fLotEventHistoryH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <Vcl.Grids.hpp>
#include "AdvDateTimePicker.hpp"
#include "CurvyControls.hpp"
//---------------------------------------------------------------------------

typedef struct
{
	AnsiString 		lotID;
	int 			inputCnt;
	int				scrapCnt;
	int 			goodCnt;
	int 			rejectCnt;
	int				outputCnt;

}LOT_EVENT_DATA;


class TfrmLotDataHistory : public TForm
{
__published:	// IDE-managed Components
	TSaveTextFileDialog *SaveTextFileDialog;
	TSaveTextFileDialog *SaveCsvFileDialog;
	TPanel *Panel2;
	TPanel *Panel3;
	TPanel *Panel4;
	TPanel *Panel5;
	TPanel *Panel6;
	TLabel *LabelHistory;
	TStringGrid *AlarmDateTimeGrid;
	TBitBtn *BtnAlarmRead1;
	TBitBtn *BtnAlarmRead2;
	TAdvDateTimePicker *DateTimeAlarmEnd;
	TAdvDateTimePicker *DateTimeAlarmStart;
	TEdit *EditAlarmCodeSearch;
	TLabel *Label4;
	TShape *Shape1;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	void __fastcall BtnAlarmRead1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall BtnAlarmRead2Click(TObject *Sender);
	void __fastcall BtnAlarmHistoryCsvSaveClick(TObject *Sender);
	void __fastcall BtnAlarmHistorySaveClick(TObject *Sender);

private:	// User declarations
    bool	_isInit;

	void	dbInitialize();

    void 	SaveToCSVFile(TStringGrid *sGrid,String sCSVFile);
    String  StringBlankMaker(String StrTempData, int nBlankCnt);

public:		// User declarations
	__fastcall TfrmLotDataHistory(TComponent* Owner);

	void	Record_LotIn(AnsiString LotID, AnsiString jobName);
	void	Record_LotEnd(LOT_EVENT_DATA data);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmLotDataHistory *frmLotDataHistory;
//---------------------------------------------------------------------------
#endif
