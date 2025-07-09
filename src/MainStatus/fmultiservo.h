//---------------------------------------------------------------------------

#ifndef fmultiservoH
#define fmultiservoH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Grids.hpp>
#include <vector>
//---------------------------------------------------------------------------
class TFrmMultiServo : public TForm
{
__published:	// IDE-managed Components
	TGridPanel *GridPanel1;
	TPanel *Panel1;
	TPanel *Panel2;
	TPanel *Panel3;
	TBitBtn *BtnClear;
	TBitBtn *BtnServoOn;
	TBitBtn *BtnServoOff;
	TStringGrid *strngrd;
	TTimer *Timer1;
	TBitBtn *BtnAll;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall AxisPanelClick(TObject *Sender);
	void __fastcall BtnClearClick(TObject *Sender);
	void __fastcall BtnAllClick(TObject *Sender);
	void __fastcall BtnServoOnClick(TObject *Sender);
	void __fastcall BtnServoOffClick(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
	std::vector<TPanel*>	_panels;
	std::vector<TPanel*>	_panelsOnOff;

	void AddAxisRow(int tag, String name);
	void ClearAxisRow();
public:		// User declarations
	__fastcall TFrmMultiServo(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmMultiServo *FrmMultiServo;
//---------------------------------------------------------------------------
#endif
