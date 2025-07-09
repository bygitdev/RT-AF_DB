//---------------------------------------------------------------------------

#ifndef FrmRobotPadTeachingScrnH
#define FrmRobotPadTeachingScrnH
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
class TFrmRobotPadTeaching : public TForm
{
__published:	// IDE-managed Components
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
	TBitBtn *BtnTeachNext3;
	TCurvyPanel *CurvyPanel3;
	TImage *Image1;
	TLabel *LabelActiveCaption;
	TPanel *PanelEmg;
	TTimer *FeedbackTimer;
	void __fastcall BtnTeachStart1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall BtnStep1Click(TObject *Sender);
	void __fastcall BtnTeachNext2Click(TObject *Sender);
	void __fastcall FeedbackTimerTimer(TObject *Sender);
	void __fastcall PageCtrlTeachingChange(TObject *Sender);
	void __fastcall BtnTeachNext3Click(TObject *Sender);
private:	// User declarations
	int   _nStageSelectIndex;
	int   _nStepSelectIndex;
	int   _nEmgValue;

	void BtncheckStatus(bool bValue) ;
public:		// User declarations
	__fastcall TFrmRobotPadTeaching(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmRobotPadTeaching *FrmRobotPadTeaching;
//---------------------------------------------------------------------------
#endif
