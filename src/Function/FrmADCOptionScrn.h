//---------------------------------------------------------------------------

#ifndef FrmADCOptionScrnH
#define FrmADCOptionScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "CurvyControls.hpp"
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFrmADCOption : public TForm
{
__published:	// IDE-managed Components
	TCurvyPanel *CurvyPanel1;
	TLabel *Label1;
	TBitBtn *BitBtn1;
	TPanel *PanelADC1;
	TPanel *PanelADC2;
	TPanel *PanelADC4;
	TPanel *PanelADC3;
	TPanel *PanelADC6;
	TPanel *PanelADC5;
	TPanel *PanelADC12;
	TPanel *PanelADC11;
	TPanel *PanelADC9;
	TPanel *PanelADC10;
	TPanel *PanelADC8;
	TPanel *PanelADC7;
	TPanel *PanelADC18;
	TPanel *PanelADC17;
	TPanel *PanelADC15;
	TPanel *PanelADC16;
	TPanel *PanelADC14;
	TPanel *PanelADC13;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall PanelADC1DblClick(TObject *Sender);
	void __fastcall BitBtn1Click(TObject *Sender);
private:	// User declarations

	int nADCSeqNumber[20];
	String nADCName[20];

    void ReadADCOption();
    bool WriteADCOption(int nIdx);
public:		// User declarations
	__fastcall TFrmADCOption(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmADCOption *FrmADCOption;
//---------------------------------------------------------------------------
#endif
