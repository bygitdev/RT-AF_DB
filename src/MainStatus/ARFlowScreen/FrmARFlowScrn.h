//---------------------------------------------------------------------------

#ifndef FrmARFlowScrnH
#define FrmARFlowScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "iComponent.hpp"
#include "iCustomComponent.hpp"
#include "iGradient.hpp"
#include "iLedBar.hpp"
#include "iLedMatrix.hpp"
#include "iPipe.hpp"
#include "iPositionComponent.hpp"
#include "iProgressComponent.hpp"
#include "iVCLComponent.hpp"
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "CurvyControls.hpp"
#include <Vcl.Imaging.jpeg.hpp>
#include "W7Classes.hpp"
#include "W7Panels.hpp"
#include <Vcl.Grids.hpp>
#include <Vcl.Buttons.hpp>
#include "AdvProgr.hpp"
//---------------------------------------------------------------------------
class TFrmARFlow : public TForm
{
__published:	// IDE-managed Components
	TTimer *ProcessRefreshTimer;
	TTimer *TimerLotInfo;
	TPageControl *MainFlowPG;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TCurvyPanel *CurvyPanel2;
	TTabSheet *TabSheet3;
	TPanel *pnIndex1;
	TPanel *pnIndex2;
	TPanel *pnIndex3;
	TPanel *pnIndex4;
	TBitBtn *btnInput;
	TBitBtn *btnSave;
	TStringGrid *sgIndex4;
	TStringGrid *sgIndex3;
	TStringGrid *sgIndex2;
	TStringGrid *sgIndex1;
	TTabSheet *TabSheet4;
	TPanel *Panel27;
	TGridPanel *GridPanel1;
	TGridPanel *GridPanel2;
	TPanel *Panel1;
	TPanel *PanelData1;
	TGridPanel *GridPanel4;
	TPanel *Panel16;
	TPanel *PanelData16;
	TGridPanel *GridPanel5;
	TPanel *Panel17;
	TPanel *PanelData2;
	TGridPanel *GridPanel7;
	TPanel *Panel19;
	TPanel *PanelData17;
	TGridPanel *GridPanel8;
	TPanel *Panel20;
	TPanel *PanelData3;
	TGridPanel *GridPanel10;
	TPanel *Panel22;
	TPanel *PanelData18;
	TGridPanel *GridPanel11;
	TPanel *Panel23;
	TPanel *PanelData4;
	TGridPanel *GridPanel13;
	TPanel *Panel25;
	TPanel *PanelData19;
	TGridPanel *GridPanel14;
	TPanel *Panel26;
	TPanel *PanelData5;
	TGridPanel *GridPanel16;
	TPanel *Panel29;
	TPanel *PanelData20;
	TGridPanel *GridPanel19;
	TPanel *Panel35;
	TPanel *PanelData21;
	TGridPanel *GridPanel22;
	TPanel *Panel41;
	TPanel *PanelData22;
	TGridPanel *GridPanel25;
	TPanel *Panel47;
	TPanel *PanelData23;
	TGridPanel *GridPanel28;
	TPanel *Panel53;
	TPanel *PanelData24;
	TPanel *Panel15;
	TPanel *Panel18;
	TPanel *Panel24;
	TPanel *Panel28;
	TGridPanel *GridPanel3;
	TPanel *Panel30;
	TPanel *PanelData31;
	TGridPanel *GridPanel9;
	TPanel *Panel34;
	TPanel *PanelData36;
	TGridPanel *GridPanel12;
	TPanel *Panel38;
	TPanel *PanelData39;
	TGridPanel *GridPanel17;
	TPanel *Panel43;
	TPanel *PanelData44;
	TGridPanel *GridPanel21;
	TPanel *Panel45;
	TPanel *PanelData46;
	TPanel *Panel39;
	TPanel *Panel44;
	TPanel *Panel32;
	TPanel *Panel33;
	TPanel *Panel40;
	TPanel *Panel42;
	TPanel *Panel48;
	TPanel *Panel49;
	TPanel *Panel51;
	TPanel *Panel52;
	TPanel *Panel54;
	TPanel *Panel56;
	TGridPanel *GridPanel6;
	TPanel *Panel99;
	TPanel *PanelData57;
	TGridPanel *GridPanel15;
	TPanel *Panel21;
	TPanel *PanelData50;
	TTimer *ResetTimer;
	TBitBtn *BtnLotInfoClear;
	TCurvyPanel *CurvyPanel1;
	TCurvyPanel *CurvyPanel3;
	TStringGrid *sgProduct;
	TCurvyPanel *CurvyPanel4;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *LabelDisplayRunTime;
	TLabel *LabelDisplayStopTime;
	TLabel *LabelDisplayErrorTime;
	TLabel *Label4;
	TCurvyPanel *CurvyPanel5;
	TLabel *LabelLotID;
	TCurvyPanel *CurvyPanel6;
	TPanel *PanelGoodStackCnt;
	TCurvyPanel *CurvyPanel7;
	TPanel *PanelRejectStackCnt;
	TLabel *Label1;
	TPanel *Panel50;
	TLabel *Label10;
	TSpeedButton *SpeedButton1;
	TPanel *PanelTopMgz;
	TPanel *MainPanelRefresh21;
	TPanel *MainPanelRefresh24;
	TPanel *MainPanelRefresh25;
	TPanel *MainPanelRefresh26;
	TPanel *MainPanelRefresh27;
	TPanel *Panel57;
	TLabel *Label11;
	TSpeedButton *SpeedButton2;
	TPanel *PanelBtmMgz;
	TPanel *MainPanelRefresh22;
	TPanel *MainPanelRefresh36;
	TPanel *MainPanelRefresh35;
	TPanel *MainPanelRefresh34;
	TPanel *MainPanelRefresh33;
	TPanel *Panel58;
	TPanel *Panel59;
	TPanel *MainPanelRefresh8;
	TPanel *MainPanelRefresh18;
	TEdit *MainPanelRefreshText318;
	TPanel *MainPanelRefresh7;
	TPanel *MainPanelRefresh17;
	TEdit *MainPanelRefreshText317;
	TPanel *MainPanelRefresh6;
	TPanel *MainPanelRefresh16;
	TEdit *MainPanelRefreshText316;
	TPanel *MainPanelRefresh5;
	TPanel *MainPanelRefresh15;
	TEdit *MainPanelRefreshText315;
	TPanel *MainPanelRefresh9;
	TPanel *MainPanelRefresh14;
	TEdit *MainPanelRefreshText302;
	TPanel *MainPanelRefresh10;
	TPanel *MainPanelRefresh13;
	TEdit *MainPanelRefreshText301;
	TButton *BtnTimerRefresh;
	TButton *BtnTimerRefreshSave;
	TPanel *Panel60;
	TPanel *PanelTarget;
	TPanel *Panel62;
	TSpeedButton *btngTargetInput;
	TSpeedButton *btnTagetSave;
	TPanel *Panel61;
	TEdit *EditTargetJobtype;
	TPanel *Panel63;
	TPanel *MainPanelRefresh23;
	TPanel *MainPanelRefresh32;
	TPanel *MainPanelRefresh31;
	TPanel *MainPanelRefresh30;
	TPanel *MainPanelRefresh29;
	TPanel *MainPanelRefresh28;
	TPanel *MainPanelRefresh11;
	TGridPanel *GridPanel23;
	TPanel *Panel66;
	TPanel *PanelPadChangeCnt;
	TPanel *Panel2;
	TPanel *Panel3;
	TPanel *MainPanelRefresh78;
	TPanel *MainPanelRefresh77;
	TPanel *MainPanelRefresh76;
	TPanel *MainPanelRefresh75;
	TPanel *MainPanelRefresh74;
	TPanel *TargetPadType;
	TLabel *Label12;
	TLabel *Label13;
	TPanel *Panel4;
	TStringGrid *sgLotEndInfo;
	TShape *Shape1;
	TGridPanel *GridPanel20;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TPanel *Panel6;
	TPanel *MainFlowRefresh23;
	TPanel *Panel5;
	TPanel *MainFlowRefresh9;
	TLabel *Label6;
	TPanel *MainFlowRefresh10;
	TLabel *Label7;
	TPanel *MainFlowRefresh16;
	TLabel *Label5;
	TGridPanel *GridPanel18;
	TPanel *MainFlowRefresh1;
	TPanel *MainFlowRefresh4;
	TPanel *MainFlowRefresh3;
	TPanel *MainFlowRefresh2;
	TPanel *Panel9;
	TPanel *MainFlowRefresh12;
	TLabel *Label8;
	TPanel *Panel10;
	TPanel *MainFlowRefresh13;
	TLabel *Label9;
	TPanel *Panel12;
	TPanel *MainFlowRefresh14;
	TPanel *Panel11;
	TPanel *MainFlowRefresh11;
	TPanel *Panel13;
	TPanel *MainFlowRefresh19;
	TPanel *MainFlowRefresh20;
	TPanel *Panel8;
	TPanel *MainFlowRefresh21;
	TPanel *MainFlowRefresh22;
	TPanel *Panel14;
	TPanel *MainFlowRefresh15;
	TShape *ShapebarPadChangeCnt;
	TLabel *LabelPadChangeCnt;
	TCurvyPanel *CurvyPanel8;
	TLabel *Label14;
	TLabel *lbShift1;
	TLabel *lbShift2;
	TLabel *lbShift3;
	TLabel *Label19;
	TLabel *Label20;
	TLabel *Label21;
	TLabel *lbTodayTotal;
	TPanel *CurrentPadType;
	TPanel *Panel77;
	TPanel *MainPanelRefresh12;
	TBitBtn *btnLotEndInput;
	TBitBtn *btnLotEndSave;
	TButton *btnProductCntInput;
	TButton *btnProductCntSave;
	TCurvyPanel *CurvyPanel9;
	TPanel *PanelLoadCellWeight;
	TGridPanel *GridPanel36;
	TPanel *Panel79;
	TPanel *PanelData036;
	TPanel *Panel7;
	TLabel *Label15;
	TPanel *PanelUseSkip1;
	TBitBtn *BtnRMSInfoClear;
	TGridPanel *GridPanel83;
	TPanel *Panel83;
	TPanel *PanelData83;
	TGridPanel *GridPanel82;
	TPanel *Panel82;
	TPanel *PanelData82;
	TGridPanel *GridPanel81;
	TPanel *Panel81;
	TPanel *PanelData81;
	TGridPanel *GridPanel80;
	TPanel *Panel80;
	TPanel *PanelData80;
	TPanel *Panel46;
	TPanel *Panel65;
	TPanel *Panel64;
	TLabel *Label17;
	TLabel *Label18;
	TButton *btnPadDrop;
	TButton *btnPadPickup;
	TPanel *Panel31;
	TButton *btnPadReset;
	TButton *btnPadDropCheck;
	TButton *btnPadPickupCheck;
	TPanel *Panel36;
	TPanel *pnDropReset;
	TPanel *Panel55;
	TPanel *pnPickupReset;
	TPanel *Panel68;
	TPanel *Panel69;
	TGridPanel *GridPanelDoorFront;
	TPanel *Panel37;
	TPanel *Panel67;
	TGridPanel *GridPanelDoorRear2;
	TGridPanel *GridPanelDoorRear1;
	TGridPanel *GridPanelDoorRight;
	TPanel *PanelDoor1;
	TPanel *PanelDoor2;
	TPanel *PanelDoor3;
	TPanel *PanelDoor4;
	TPanel *PanelDoor15;
	TPanel *PanelDoor16;
	TPanel *PanelDoor17;
	TPanel *PanelDoor18;
	TPanel *PanelDoor8;
	TPanel *PanelDoor7;
	TPanel *PanelDoor6;
	TPanel *PanelDoor5;
	TPanel *PanelDoor10;
	TPanel *PanelDoor9;
	TPanel *PanelDoor12;
	TPanel *PanelDoor11;
	TPanel *PanelDoor14;
	TPanel *PanelDoor13;
	TPanel *PanelDoor20;
	TPanel *PanelDoor19;
	void __fastcall MainFlowRefresh1DblClick(TObject *Sender);
	void __fastcall ProcessRefreshTimerTimer(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall BtnTimerRefreshSaveClick(TObject *Sender);
	void __fastcall BtnTimerRefreshClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall TimerLotInfoTimer(TObject *Sender);
	void __fastcall pnIndex4DblClick(TObject *Sender);
	void __fastcall btnInputClick(TObject *Sender);
	void __fastcall btnSaveClick(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall ResetTimerTimer(TObject *Sender);
	void __fastcall BtnLotInfoClearClick(TObject *Sender);
	void __fastcall Label5DblClick(TObject *Sender);
	void __fastcall Label6DblClick(TObject *Sender);
	void __fastcall Label7DblClick(TObject *Sender);
	void __fastcall Label8DblClick(TObject *Sender);
	void __fastcall Label9DblClick(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall btngTargetInputClick(TObject *Sender);
	void __fastcall btnTagetSaveClick(TObject *Sender);
	void __fastcall MainPanelRefresh78DblClick(TObject *Sender);
	void __fastcall TabSheet3Show(TObject *Sender);
	void __fastcall btnLotEndInputClick(TObject *Sender);
	void __fastcall btnLotEndSaveClick(TObject *Sender);
	void __fastcall btnProductCntInputClick(TObject *Sender);
	void __fastcall btnProductCntSaveClick(TObject *Sender);
	void __fastcall PanelUseSkip1DblClick(TObject *Sender);
	void __fastcall btnPadDropClick(TObject *Sender);
	void __fastcall btnPadResetClick(TObject *Sender);
	void __fastcall btnPadDropCheckClick(TObject *Sender);
	void __fastcall pnDropResetClick(TObject *Sender);
	void __fastcall pnPickupResetClick(TObject *Sender);

private:	// User declarations
	String StrNamePanel[40];
	String StrNameADCPanel[40];
	String strOhtStatusCaption[4];
	void  RefreshStatus();
	void  RefreshValues();

	String getStrJobType(int index);
	void process_unit_counting();

	void RefleshPioSensor();
	void RefleshUseSkip();
	void RefleshOhtStatus();
	void RefleshDdm();
	void RefleshNdm();
	void __fastcall RefreshDoor();


public:		// User declarations
	__fastcall TFrmARFlow(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmARFlow *FrmARFlow;
//---------------------------------------------------------------------------
#endif
