//---------------------------------------------------------------------------

#ifndef fdailyreportH
#define fdailyreportH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "AdvSmoothCalendar.hpp"
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include "iComponent.hpp"
#include "iCustomComponent.hpp"
#include "iPieChart.hpp"
#include "iVCLComponent.hpp"
#include "DBPlannerCal.hpp"
#include "PlannerCal.hpp"
#include <Vcl.Samples.Calendar.hpp>
#include <Vcl.ValEdit.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
typedef struct
{
	int runTimeMin;
	int stopTimeMin;
	int errTimeMin;
	int productCnt;
	int runDownTimeMin;
} RUNHISTORY_DATA;

typedef struct
{
	String 	Err1;
	String 	Err2;
	String 	Err3;
	int 	errCount;
} ALARMHISTRY_DATA;


class TFrmDailyReport : public TForm
{
__published:	// IDE-managed Components
	TGridPanel *GridPanel1;
	TiPieChart *iPieChart1;
	TAdvSmoothCalendar *Calendar;
	TValueListEditor *ValueListEditor1;
	TGridPanel *GridPanel2;
	TLabel *Label3;
	TValueListEditor *ValueListEditor2;
	TStringGrid *StringGridErrorList;
	TSaveDialog *SaveDialog1;
	TPanel *Panel1;
	TLabel *Label1;
	TBitBtn *BtnRunDataSaveCSV;
	TPanel *Panel2;
	TLabel *Label2;
	TBitBtn *BtnErrorListSaveCSV;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall CalendarMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall BtnRunDataSaveCSVClick(TObject *Sender);

private:	// User declarations
	void	regen(TDateTime startDate, TDateTime endDate);
	RUNHISTORY_DATA		get_run_data(TDateTime startTime, TDateTime endTime);
	ALARMHISTRY_DATA 	get_n_set_alarm_data(TDateTime startTime, TDateTime endTime);
	void	regen_product_cout(TDateTime startTime, TDateTime endTime);
public:		// User declarations
	__fastcall TFrmDailyReport(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmDailyReport *FrmDailyReport;
//---------------------------------------------------------------------------
#endif
