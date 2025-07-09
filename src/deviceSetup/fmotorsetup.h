//---------------------------------------------------------------------------

#ifndef fmotorsetupH
#define fmotorsetupH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TfrmMorterSetup : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel4;
	TPanel *Panel5;
	TImage *Image1;
	TSpeedButton *SpeedButton10;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton3;
	TSpeedButton *SpeedButton4;
	void __fastcall SpeedButton1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmMorterSetup(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMorterSetup *frmMorterSetup;
//---------------------------------------------------------------------------
#endif
