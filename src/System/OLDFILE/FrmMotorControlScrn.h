//---------------------------------------------------------------------------

#ifndef FrmMotorControlScrnH
#define FrmMotorControlScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include "CurvyControls.hpp"

//---------------------------------------------------------------------------
class TFrmMotorControl : public TForm
{
__published:	// IDE-managed Components
	TTimer *MtrRefreshTimer;
	TCurvyPanel *CurvyPanel1;
	TPanel *Panel1;
	TSpeedButton *BtnAxisSelect;
	TStringGrid *MtrPosGrid;
	TPanel *Panel11;
	TSpeedButton *BtnInputMotionData;
	TSpeedButton *BtnSaveMotionData;
	TSpeedButton *BtnIndexMove;
	TPanel *PanelMtrSelectIndex;
	TPanel *Panel3;
	TPanel *Panel4;
	TLabel *Label1;
	TPanel *MtrPanelLed2;
	TPanel *Panel5;
	TLabel *Label2;
	TPanel *MtrPanelLed1;
	TPanel *Panel6;
	TLabel *Label3;
	TPanel *MtrPanelLed3;
	TPanel *Panel8;
	TLabel *Label4;
	TPanel *MtrPanelLed6;
	TPanel *Panel9;
	TLabel *Label5;
	TPanel *MtrPanelLed4;
	TPanel *Panel10;
	TLabel *MtrPostionLabel;
	TPanel *Panel12;
	TLabel *Label7;
	TPanel *MtrPanelLed5;
	TPanel *Panel7;
	TPanel *PanelServoOnOff;
	TBitBtn *BtnAxisMotorHome;
	TBitBtn *BtnAxisMotorStop;
	TBitBtn *BtnAxisMotorReset;
	TBitBtn *BtnServoControl;
	TBitBtn *BtnAxisConfig;
	TPanel *PanelTenkeyJog;
	TPanel *Panel2;
	TLabel *Label6;
	TButton *BtnJog4;
	TButton *BtnJog2;
	TEdit *EditJogPosition;
	TButton *BtnJog3;
	TButton *BtnJog1;
	TButton *BtnJog5;
	TButton *BtnJog6;
	TPanel *Panel13;
	TLabel *Label8;
	TSpeedButton *BtnJogSpeedApply;
	TEdit *EditJogSpeed;
	TRadioButton *RadioButtonJogMove;
	TRadioButton *RadioButtonRMove;
	void __fastcall MtrPosGridSelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall MtrRefreshTimerTimer(TObject *Sender);
	void __fastcall BtnSaveMotionDataClick(TObject *Sender);
	void __fastcall BtnInputMotionDataClick(TObject *Sender);
	void __fastcall BtnServoControlClick(TObject *Sender);
	void __fastcall BtnAxisMotorHomeClick(TObject *Sender);
	void __fastcall BtnAxisMotorStopClick(TObject *Sender);
	void __fastcall BtnAxisMotorResetClick(TObject *Sender);
	void __fastcall BtnJog4Click(TObject *Sender);
	void __fastcall BtnJog2Click(TObject *Sender);
	void __fastcall BtnJogSpeedApplyClick(TObject *Sender);
	void __fastcall BtnJog1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall BtnJog1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall BtnIndexMoveClick(TObject *Sender);
	void __fastcall BtnJog2MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall BtnJog2MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y);
	void __fastcall BtnAxisConfigClick(TObject *Sender);
	void __fastcall MtrPosGridDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall PanelTenkeyJogClick(TObject *Sender);
	void __fastcall BtnAxisSelectClick(TObject *Sender);

private:	// User declarations
	int  _nSelectIndex;
	int  _nAxis_no;
    bool _bUniqueMotorSet_;

    bool bServoOnOff;


	void MtrAxis_SelectedProcess( int nSelectAxis );

    bool    MtrData_ReadDB();
    bool    MtrData_ReadSEQ();

    bool    MtrData_SaveDB();
    bool    MtrData_SaveSEQ();

public:		// User declarations

	void __fastcall Motorscreen_Initialize(int nAxisSelect);

	__fastcall TFrmMotorControl(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmMotorControl *FrmMotorControl;
//---------------------------------------------------------------------------
#endif
