//---------------------------------------------------------------------------

#ifndef FrmPadChangeHistoryH
#define FrmPadChangeHistoryH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "AdvDateTimePicker.hpp"
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <Vcl.Grids.hpp>
#include <cstdio>  // sprintf
#include <string>
//---------------------------------------------------------------------------
typedef struct
{
	AnsiString 		EqpID;
	AnsiString 		LotID;
	AnsiString 		PartNo;
	AnsiString 		PadType;
	AnsiString 		PadName;
	AnsiString 		PadLifeTimeCount;
	AnsiString 		PadVacData;
	AnsiString 		PadAlarmCode;
	AnsiString 		PadAlarmName;
	AnsiString 		PadLogType;
	AnsiString 		PadLogPicknPlace;
}PADCHANGE_DATA;

class TFormPadChangeHistory : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel2;
	TPanel *Panel3;
	TLabel *LabelHistory;
	TPanel *Panel4;
	TBitBtn *Btn_SaveCSV;
	TBitBtn *Btn_SaveTXT;
	TButton *Button2;
	TPanel *Panel5;
	TPanel *Panel6;
	TLabel *Label4;
	TShape *Shape1;
	TBitBtn *Btn_DatabaseRead;
	TBitBtn *Btn_Search;
	TAdvDateTimePicker *DateTimePadChangeEnd;
	TAdvDateTimePicker *DateTimePadChangeStart;
	TEdit *EditSearch;
	TStringGrid *PadChangeTimeGrid;
	TStringGrid *PadChangeResultGrid;
	TSaveTextFileDialog *SaveTextFileDialog;
	TSaveTextFileDialog *SaveCsvFileDialog;
	TComboBox *cbSearchList;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *EditSearch_PartID;
	TBitBtn *Btn_Search_PartID;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Btn_DatabaseReadClick(TObject *Sender);
	void __fastcall Btn_SaveCSVClick(TObject *Sender);
	void __fastcall Btn_SaveTXTClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Btn_SearchClick(TObject *Sender);
	void __fastcall Btn_Search_PartIDClick(TObject *Sender);
private:	// User declarations
	bool	_isInit;

	void	dbInitialize();
public:		// User declarations
	__fastcall TFormPadChangeHistory(TComponent* Owner);
	void Record_PadChange(PADCHANGE_DATA data);
	void PadChangeDataSave(int logType = 0, int logNo = 0, int logPicknPlace = 0);
	void sortArray(double arr[], int size);
	double findAverageValue(double arr[], int size);
	double findMedianValue(double arr[], int size);
	double calculateMean(double arr[], int size);
	double calculateStandardDeviation(double arr[], int size);
	void createQuery(const std::string& sStartDateTime, const std::string& sEndDateTime, const std::string& sSelItem, const std::string& sSearchText, char* buffer, size_t bufferSize);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormPadChangeHistory *FormPadChangeHistory;
//---------------------------------------------------------------------------
#endif
