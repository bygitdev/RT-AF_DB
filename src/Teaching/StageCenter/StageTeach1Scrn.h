//---------------------------------------------------------------------------

#ifndef StageTeach1ScrnH
#define StageTeach1ScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "CurvyControls.hpp"
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
//---------------------------------------------------------------------------
class TFrmSystemCenterTeaching : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageCtrlTeaching;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TBitBtn *BtnTeachNext2;
	TLabel *LabelActiveCaption;
	TCurvyPanel *CurvyPanel1;
	TCurvyPanel *CurvyPanel2;
	TBitBtn *BtnTeachStart1;
	TStaticText *StaticText1;
	TLabel *Label2;
	TTabSheet *TabSheet3;
	TBitBtn *BtnTeachNext3;
	TBitBtn *BtnTeachStart2;
	TBitBtn *BtnTeachStart3;
	TBitBtn *BtnTeachStart4;
	TCurvyPanel *CurvyPanel3;
	TImage *Image1;
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
	TTimer *FeedbackTimer;
	TPanel *PanelEmg;
	TLabel *Label1;
	TEdit *EditXValue;
	TEdit *EditYValue;
	TLabel *Label3;
	TLabel *Label4;
	TSpeedButton *BtnSaveItem;
	void __fastcall BtnTeachStart1Click(TObject *Sender);
	void __fastcall PageCtrlTeachingChange(TObject *Sender);
	void __fastcall BtnStep1Click(TObject *Sender);
	void __fastcall FeedbackTimerTimer(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall BtnTeachNext2Click(TObject *Sender);
	void __fastcall BtnTeachNext3Click(TObject *Sender);
	void __fastcall BtnSaveItemClick(TObject *Sender);
	void __fastcall TabSheet3Show(TObject *Sender);

private:	// User declarations

	int   _nStageSelectIndex;
	int   _nStepSelectIndex;
	int   _nEmgValue;

	void BtncheckStatus(bool bValue) ;


public:		// User declarations
	__fastcall TFrmSystemCenterTeaching(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmSystemCenterTeaching *FrmSystemCenterTeaching;
//---------------------------------------------------------------------------
#endif
