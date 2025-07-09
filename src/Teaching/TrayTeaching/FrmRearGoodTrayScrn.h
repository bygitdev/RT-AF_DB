//---------------------------------------------------------------------------

#ifndef FrmRearGoodTrayScrnH
#define FrmRearGoodTrayScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "CurvyControls.hpp"
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
//---------------------------------------------------------------------------
class TFrmRearGoodTray : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageCtrlTeaching;
	TTabSheet *TabSheet1;
	TCurvyPanel *CurvyPanel1;
	TLabel *Label2;
	TBitBtn *BtnTeachStart1;
	TStaticText *StaticText1;
	TBitBtn *BtnTeachStart2;
	TBitBtn *BtnTeachStart3;
	TBitBtn *BtnTeachStart4;
	TTabSheet *TabSheet2;
	TBitBtn *BtnTeachNext2;
	TCurvyPanel *CurvyPanel2;
	TBitBtn *BtnStep1;
	TPanel *PanelNextStep1;
	TPanel *PanelNextStep2;
	TBitBtn *BtnStep2;
	TPanel *PanelNextStep3;
	TBitBtn *BtnStep3;
	TPanel *PanelNextStep4;
	TBitBtn *BtnStep4;
	TBitBtn *BtnStep5;
	TPanel *PanelNextStep5;
	TTabSheet *TabSheet3;
	TBitBtn *BtnTeachNext3;
	TCurvyPanel *CurvyPanel3;
	TImage *Image1;
	TLabel *Label1;
	TLabel *Label3;
	TLabel *Label4;
	TSpeedButton *BtnSaveItem;
	TEdit *EditXValue;
	TEdit *EditYValue;
	TLabel *LabelActiveCaption;
	TPanel *PanelEmg;
	TTimer *FeedbackTimer;
	TBitBtn *BtnTeachStart5;
	TPanel *Panel5;
	TPanel *Panel1;
	TPanel *Panel2;
	TPanel *Panel3;
	TPanel *Panel4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall BtnTeachStart1Click(TObject *Sender);
	void __fastcall BtnStep1Click(TObject *Sender);
	void __fastcall BtnTeachNext2Click(TObject *Sender);
	void __fastcall FeedbackTimerTimer(TObject *Sender);
	void __fastcall BtnTeachNext3Click(TObject *Sender);
	void __fastcall BtnSaveItemClick(TObject *Sender);
	void __fastcall TabSheet3Show(TObject *Sender);
	void __fastcall PageCtrlTeachingChange(TObject *Sender);
private:	// User declarations

	int   _nStageSelectIndex;
	int   _nStepSelectIndex;
	int   _nEmgValue;
	void BtncheckStatus(bool bValue);
public:		// User declarations
	__fastcall TFrmRearGoodTray(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmRearGoodTray *FrmRearGoodTray;
//---------------------------------------------------------------------------
#endif
