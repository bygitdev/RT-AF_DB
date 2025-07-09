//---------------------------------------------------------------------------

#ifndef FrmVisionOffsetTeachingScrnH
#define FrmVisionOffsetTeachingScrnH
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
class TFrmVisionOffsetTeaching : public TForm
{
__published:	// IDE-managed Components
	TLabel *LabelActiveCaption;
	TPanel *PanelEmg;
	TTimer *FeedbackTimer;
	TPageControl *PageCtrlTeaching;
	TTabSheet *TabSheet1;
	TCurvyPanel *CurvyPanel1;
	TLabel *Label2;
	TBitBtn *BtnTeachStart1;
	TStaticText *StaticText1;
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
	TTabSheet *TabSheet3;
	TCurvyPanel *CurvyPanel3;
	TBitBtn *BtnStep8;
	TPanel *PanelNextStep8;
	TBitBtn *BtnStep9;
	TPanel *PanelNextStep9;
	TBitBtn *BtnStep10;
	TPanel *PanelNextStep10;
	TTabSheet *TabSheet4;
	TBitBtn *BtnTeachNext4;
	TBitBtn *BtnTeachNext3;
	TBitBtn *BtnStep5;
	TPanel *PanelNextStep5;
	TPanel *Panel1;
	TPanel *Panel2;
	TPanel *Panel3;
	TPanel *Panel4;
	TLabel *Label1;
	TPanel *Panel5;
	TPanel *Panel6;
	TPanel *Panel7;
	TPanel *panE4;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall BtnTeachStart1Click(TObject *Sender);
	void __fastcall BtnTeachNext2Click(TObject *Sender);
	void __fastcall FeedbackTimerTimer(TObject *Sender);
	void __fastcall BtnTeachNext4Click(TObject *Sender);
	void __fastcall PageCtrlTeachingChange(TObject *Sender);
	void __fastcall BtnTeachNext3Click(TObject *Sender);
	void __fastcall BtnStep1Click(TObject *Sender);

private:	// User declarations

	int   _nStageSelectIndex;
	int   _nStepSelectIndex;
	int   _nEmgValue;
	bool  _bDataSave;

	void BtncheckStatus(bool bValue);
	void PkgDataIniSave();
	void VisionDataIniSave();
public:		// User declarations
	__fastcall TFrmVisionOffsetTeaching(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmVisionOffsetTeaching *FrmVisionOffsetTeaching;
//---------------------------------------------------------------------------
#endif
