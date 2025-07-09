//---------------------------------------------------------------------------

#ifndef FrmMotorControlScrnH
#define FrmMotorControlScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "CurvyControls.hpp"
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Graphics.hpp>
//---------------------------------------------------------------------------
#define   _MOTOR_IDNEX_COUNT_                           50

class TFrmMotorControl : public TForm
{
__published:	// IDE-managed Components
	TCurvyPanel *CurvyPanel1;
	TPanel *Panel1;
	TSpeedButton *BtnAxisSelect;
	TPanel *Panel2;
	TPanel *Panel3;
	TLabel *Label1;
	TPanel *MtrPanelLed2;
	TPanel *Panel4;
	TLabel *Label2;
	TPanel *MtrPanelLed1;
	TPanel *Panel5;
	TLabel *Label3;
	TPanel *MtrPanelLed3;
	TPanel *Panel6;
	TLabel *Label4;
	TPanel *MtrPanelLed6;
	TPanel *Panel8;
	TLabel *Label5;
	TPanel *MtrPanelLed4;
	TPanel *Panel9;
	TLabel *MtrPostionLabel;
	TPanel *Panel10;
	TLabel *Label6;
	TPanel *MtrPanelLed5;
	TStringGrid *MtrPosGrid;
	TCurvyPanel *CurvyPanel2;
	TCurvyPanel *CurvyPanel3;
	TBitBtn *BtnAxisMotorStop;
	TBitBtn *BtnAxisMotorReset;
	TBitBtn *BtnAxisMotorHome;
	TBitBtn *BtnServoControl;
	TPanel *PanelServoOnOff;
	TCurvyPanel *CurvyPanel4;
	TSpeedButton *BtnSaveMotionData;
	TSpeedButton *BtnIndexMove;
	TSpeedButton *BtnInputMotionData;
	TPanel *PanelMtrSelectIndex;
	TPanel *PanelTenkeyJog;
	TTimer *MtrRefreshTimer;
	TSpeedButton *BtnAxisMinusChange;
	TSpeedButton *BtnAxisPlusChange;
	TBitBtn *BtnSubSensor;
	TBitBtn *BtnTenkeyJog;
	TPanel *PanelVisibleSensor;
	TPanel *PanelSensorPart1;
	TPanel *PanelSensorPart2;
	TPanel *PanelSensorView;
	TBitBtn *BtnAxisMotorSet;
	TEdit *EditJogSpeed;
	TSpeedButton *BtnJogSpeedApply;
	TLabel *Label8;
	TBitBtn *BtnJogPositive;
	TBitBtn *BtnJogNegative;
	TEdit *EditJogPosition;
	TLabel *Label9;
	TButton *BtnRMove;
	TButton *BtnAMove;
	TCurvyEdit *JogControlEdit;
	TSpeedButton *BtnIndexWrite;
	TLabel *Label10;
	TSpeedButton *SpeedButton1;
	TSpeedButton *BtnCmnUnLock;
	TImage *ImageUnlock;
	TImage *ImageLock;
	TEdit *EditAMoveValue;
	TLabel *Label7;
	TSpeedButton *SpeedButtonAMove;
	void __fastcall MtrPosGridSelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall MtrPosGridDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall BtnAxisSelectClick(TObject *Sender);
	void __fastcall BtnInputMotionDataClick(TObject *Sender);
	void __fastcall BtnSaveMotionDataClick(TObject *Sender);
	void __fastcall BtnServoControlClick(TObject *Sender);
	void __fastcall PanelTenkeyJogClick(TObject *Sender);
	void __fastcall BtnAxisMotorHomeClick(TObject *Sender);
	void __fastcall BtnAxisMotorStopClick(TObject *Sender);
	void __fastcall BtnAxisMotorResetClick(TObject *Sender);
	void __fastcall BtnJogSpeedApplyClick(TObject *Sender);
	void __fastcall BtnIndexMoveClick(TObject *Sender);
	void __fastcall BtnAxisConfigClick(TObject *Sender);
	void __fastcall MtrRefreshTimerTimer(TObject *Sender);
	void __fastcall BtnTenkeyJogClick(TObject *Sender);
	void __fastcall BtnAxisMinusChangeClick(TObject *Sender);
	void __fastcall BtnAxisPlusChangeClick(TObject *Sender);
	void __fastcall PanelVisibleSensorMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall BtnSubSensorClick(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall PanelVisibleSensorDblClick(TObject *Sender);
	void __fastcall BtnAxisMotorSetClick(TObject *Sender);
	void __fastcall BtnJogPositiveClick(TObject *Sender);
	void __fastcall BtnJogNegativeClick(TObject *Sender);
	void __fastcall BtnRMoveClick(TObject *Sender);
	void __fastcall BtnJogPositiveMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall BtnJogPositiveMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall BtnJogNegativeMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall BtnJogNegativeMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall BtnIndexWriteClick(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall BtnCmnUnLockClick(TObject *Sender);
	void __fastcall SpeedButtonAMoveClick(TObject *Sender);


private:	// User declarations

	int  _nSelectIndex;
	int  _nAxis_no;
    int  _nJogControl;
    int  _nLeftDirect , _nRightDirect ;
    String  StrJogCaptionLeft  ,  StrJogCaptionRight , StrJogCheckCaption;

    bool bServoOnOff;

	TForm* pSensorFrm[2];
	void MtrAxis_SelectedProcess( int nSelectAxis );

    bool    MtrData_ReadDB();
    bool    MtrData_ReadSEQ();

    bool    MtrData_SaveDB();
    bool    MtrData_SaveSEQ();

	bool IndexDataSaveMotionDataToDB(int nIndex , String StrPos);
	bool IndexDataSaveMotionDataToMotion(int nIndex , String StrPos);

	bool	_flagCmn[_MOTOR_IDNEX_COUNT_];


public:		// User declarations

	void __fastcall Motorscreen_Initialize(int nAxisSelect);

	__fastcall TFrmMotorControl(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmMotorControl *FrmMotorControl;
//---------------------------------------------------------------------------
#endif
