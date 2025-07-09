//---------------------------------------------------------------------------

#ifndef FrmFlipperCenterTeachScrnH
#define FrmFlipperCenterTeachScrnH
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
class TFrmFlipperCenterTeach : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageCtrlTeaching;
	TTabSheet *TabSheet1;
	TCurvyPanel *CurvyPanel1;
	TLabel *Label2;
	TBitBtn *BtnTeachStart1;
	TStaticText *StaticText1;
	TBitBtn *BtnTeachStart2;
	TTabSheet *TabSheet2;
	TBitBtn *BtnTeachNext2;
	TCurvyPanel *CurvyPanel2;
	TBitBtn *BtnStep1;
	TPanel *PanelNextStep1;
	TPanel *PanelNextStep2;
	TBitBtn *BtnStep2;
	TPanel *PanelNextStep3;
	TBitBtn *BtnStep3;
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
	TPanel *PanelEmg;
	TLabel *LabelActiveCaption;
	TTimer *FeedbackTimer;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall BtnTeachStart1Click(TObject *Sender);
	void __fastcall PageCtrlTeachingChange(TObject *Sender);
	void __fastcall BtnStep1Click(TObject *Sender);
	void __fastcall BtnTeachNext2Click(TObject *Sender);
	void __fastcall FeedbackTimerTimer(TObject *Sender);
	void __fastcall BtnSaveItemClick(TObject *Sender);
	void __fastcall TabSheet3Show(TObject *Sender);
	void __fastcall TabSheet2Show(TObject *Sender);
	void __fastcall BtnTeachNext3Click(TObject *Sender);
private:	// User declarations

	int   _nStageSelectIndex;
	int   _nStepSelectIndex;
	int   _nEmgValue;

	void BtncheckStatus(bool bValue);

public:		// User declarations
	__fastcall TFrmFlipperCenterTeach(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmFlipperCenterTeach *FrmFlipperCenterTeach;
//---------------------------------------------------------------------------
#endif
