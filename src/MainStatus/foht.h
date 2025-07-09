//---------------------------------------------------------------------------

#ifndef fohtH
#define fohtH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TfrmOht : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TLabel *Label3;
	TGridPanel *GridPanel1;
	TPanel *PanelStatus1;
	TLabel *Label1;
	TPanel *Panel2;
	TLabel *Label2;
	TPanel *panPioInput0;
	TLabel *lblPioInput0;
	TPanel *panPioOutput0;
	TLabel *lblPioOutput0;
	TPanel *panPioInput1;
	TLabel *lblPioInput1;
	TPanel *panPioOutput1;
	TLabel *lblPioOutput1;
	TPanel *panPioInput2;
	TLabel *lblPioInput2;
	TPanel *panPioOutput2;
	TLabel *lblPioOutput2;
	TPanel *panPioInput3;
	TLabel *lblPioInput3;
	TPanel *panPioOutput3;
	TLabel *lblPioOutput3;
	TPanel *panPioInput4;
	TPanel *panPioOutput4;
	TLabel *lblPioOutput4;
	TPanel *panPioInput5;
	TLabel *lblPioInput5;
	TPanel *panPioOutput5;
	TLabel *lblPioOutput5;
	TPanel *panPioInput6;
	TLabel *lblPioInput6;
	TPanel *panPioOutput6;
	TLabel *lblPioOutput6;
	TPanel *panPioInput7;
	TLabel *lblPioInput7;
	TPanel *panPioOutput7;
	TLabel *lblPioOutput7;
	TTimer *Timer1;
	TLabel *lblPioInput4;
	TSpeedButton *btnOutputReset;
	TPanel *Panel5;
	TLabel *Label4;
	TGridPanel *GridPanel2;
	TPanel *panNDM0;
	TLabel *lblNDM0;
	TPanel *Panel3;
	TLabel *Label5;
	TGridPanel *GridPanel3;
	TPanel *panNDM1;
	TLabel *lblNDM1;
	TPanel *Panel7;
	TLabel *Label6;
	TGridPanel *GridPanel6;
	TPanel *panUSESKIP0;
	TLabel *lblUSESKIP0;
	TPanel *panUSESKIP1;
	TLabel *lblUSESKIP1;
	TPanel *panUSESKIP2;
	TLabel *lblUSESKIP2;
	TGridPanel *GridPanel7;
	TPanel *Panel8;
	TPanel *panDDM2;
	TGridPanel *GridPanel4;
	TPanel *Panel4;
	TPanel *panDDM0;
	TGridPanel *GridPanel5;
	TPanel *Panel6;
	TPanel *panDDM1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall lblPioOutput0DblClick(TObject *Sender);
	void __fastcall btnOutputResetClick(TObject *Sender);
private:	// User declarations
	void RefleshPioName();
	void RefleshPioSensor();
	void RefleshUseSkip();
	void RefleshDdm();
	void RefleshNdm();


public:		// User declarations
	__fastcall TfrmOht(TComponent* Owner);



};
//---------------------------------------------------------------------------
extern PACKAGE TfrmOht *frmOht;
//---------------------------------------------------------------------------
#endif
