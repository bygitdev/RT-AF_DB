//---------------------------------------------------------------------------

#ifndef FrmMotorControlScrnH
#define FrmMotorControlScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "iComponent.hpp"
#include "iCustomComponent.hpp"
#include "iLed.hpp"
#include "iLedRectangle.hpp"
#include "iVCLComponent.hpp"
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TFrmMotorControl : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TBitBtn *BtnAxis0;
	TStringGrid *MtrPosGrid;
	TPanel *Panel3;
	TPanel *Panel4;
	TLabel *Label1;
	TPanel *Panel5;
	TLabel *Label2;
	TPanel *Panel6;
	TLabel *Label3;
	TPanel *Panel8;
	TLabel *Label4;
	TPanel *Panel9;
	TLabel *Label5;
	TPanel *Panel10;
	TLabel *MtrPostionLabel;
	TRadioButton *RadioButtonRMove;
	TRadioButton *RadioButtonJogMove;
	TButton *BtnJog3;
	TButton *BtnJog1;
	TButton *BtnJog4;
	TPanel *Panel11;
	TSpeedButton *BtnInputMotionData;
	TSpeedButton *BtnSaveMotionData;
	TPanel *PanelMtrSelectIndex;
	TButton *BtnJog6;
	TButton *BtnJog2;
	TButton *BtnJog5;
	TEdit *EditJogPosition;
	TLabel *Label6;
	TButton *BtnServoControl;
	TTimer *MtrRefreshTimer;
	TPanel *MtrPanelLed1;
	TPanel *MtrPanelLed2;
	TPanel *MtrPanelLed3;
	TPanel *MtrPanelLed4;
	TPanel *MtrPanelLed6;
	TPanel *Panel12;
	TLabel *Label7;
	TPanel *MtrPanelLed5;
	TPanel *PanelServoOnOff;
	TLabel *Label8;
	TEdit *EditJogSpeed;
	TButton *BtnJogSpeedApply;
	TBitBtn *BtnAxisMotorHome;
	TBitBtn *BtnAxisMotorStop;
	TBitBtn *BtnAxisMotorReset;
	TSpeedButton *BtnIndexMove;
	TBitBtn *BtnAxis1;
	TBitBtn *BtnAxis3;
	TBitBtn *BtnAxis2;
	TBitBtn *BtnAxis5;
	TBitBtn *BtnAxis4;
	void __fastcall MtrPosGridSelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall MtrRefreshTimerTimer(TObject *Sender);
	void __fastcall BtnAxis0Click(TObject *Sender);
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

private:	// User declarations
	int  _nSelectIndex;
    int  nMtrLeftRight;   //  0: LEFT    1 : RIGHT
    int  _nAxis_no;

    bool bServoOnOff;


	void MtrAxis_SelectedProcess( int nSelectAxis );

    bool    MtrData_ReadDB();
    bool    MtrData_ReadSEQ(int nLeftRight);

    bool    MtrData_SaveDB();
    bool    MtrData_SaveSEQ(int nLeftRight);

    String  MtrAxisName_ReadDB(int nAxis);
    void    MtrJogBtnDisplay(int nJogdirection);

public:		// User declarations

    bool    Mtr_dataBothsidecheck();

	void __fastcall Motorscreen_Initialize(int nLeft);


	__fastcall TFrmMotorControl(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmMotorControl *FrmMotorControl;
//---------------------------------------------------------------------------
#endif
