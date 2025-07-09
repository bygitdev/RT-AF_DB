//---------------------------------------------------------------------------

#ifndef fmotorsetupcontrolH
#define fmotorsetupcontrolH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TfrmMtrSetupControl : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *StringGrid1;
	TPanel *Panel1;
	TPanel *PanelHome;
	TPanel *PanelServo;
	TPanel *PanelDrive;
	TPanel *PanelRealPos;
	TPanel *PanelTitle;
	TPanel *Panel9;
	TLabel *Label1;
	TPanel *PanelAlarm;
	TPanel *PanelTenkey;
	TImage *Image1;
	TPanel *Panel2;
	TPanel *PanelRvalue;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton4;
	TSpeedButton *SpeedButton6;
	TSpeedButton *SpeedButton3;
	TSpeedButton *SpeedButton7;
	TPanel *PanelSelect;
	TSpeedButton *SpeedButton5;
	TLabel *Label3;
	TSpeedButton *SpeedButton18;
	TSpeedButton *SpeedButton17;
	TSpeedButton *SpeedButton12;
	TSpeedButton *SpeedButton11;
	TTimer *Timer1;
	TPanel *PanelOrgPos;
	TSpeedButton *SpeedButton8;
	TSpeedButton *SpeedButton9;
	TSpeedButton *SpeedButton10;
	TSpeedButton *SpeedButton13;
	void __fastcall SpeedButton11Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall StringGrid1SelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall SpeedButton7Click(TObject *Sender);
	void __fastcall SpeedButton18Click(TObject *Sender);
	void __fastcall SpeedButton17Click(TObject *Sender);
	void __fastcall SpeedButton5Click(TObject *Sender);
	void __fastcall PanelHomeClick(TObject *Sender);
	void __fastcall PanelServoClick(TObject *Sender);
	void __fastcall PanelTenkeyClick(TObject *Sender);
	void __fastcall SpeedButton12Click(TObject *Sender);

private:	// User declarations
	int 	_axisNum;
    void	regen();
    void 	panel_led(TPanel* panel, bool flag);
    String 	get_string_offset_value(int number);
    int 	_pkgID;
public:		// User declarations
	__fastcall TfrmMtrSetupControl(TComponent* Owner);
    void	SetAxisNumber(int num);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMtrSetupControl *frmMtrSetupControl;
//---------------------------------------------------------------------------
#endif
