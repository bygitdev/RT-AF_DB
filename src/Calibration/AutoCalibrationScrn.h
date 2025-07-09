//---------------------------------------------------------------------------

#ifndef AutoCalibrationScrnH
#define AutoCalibrationScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "CurvyControls.hpp"
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TAutoCalibration : public TForm
{
__published:	// IDE-managed Components
	TCurvyPanel *CurvyPanel1;
	TBitBtn *BtnAutoCal1;
	TLabel *Label1;
	TBitBtn *BtnAutoCal2;
	TBitBtn *BtnAutoCal3;
	TBitBtn *BtnAutoCal5;
	TBitBtn *BtnAutoCal6;
	TBitBtn *BtnAutoCal4;
	TBitBtn *BtnAutoCal8;
	TBitBtn *BtnAutoCal7;
	void __fastcall BtnAutoCal1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TAutoCalibration(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAutoCalibration *AutoCalibration;
//---------------------------------------------------------------------------
#endif
