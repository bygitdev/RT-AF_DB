//---------------------------------------------------------------------------

#ifndef CalibrationFormScrnH
#define CalibrationFormScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TCalibrationForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TComboBox *ComboBoxAccessLevel;
	TPanel *Panel2;
	TBitBtn *BitBtn6;
	TBitBtn *CalibrationFrmSub1;
	TPanel *CalibBasePanel;
	TBitBtn *CalibrationFrmSub2;
	TBitBtn *CalibrationFrmSub3;
	TBitBtn *CalibrationFrmSub4;
	void __fastcall CalibrationFrmSub1Click(TObject *Sender);
private:	// User declarations
	TForm* pCalibSubFrm[5];
public:		// User declarations

    void  CalibrationButtonDisplay(int nBtnIndex);

	__fastcall TCalibrationForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCalibrationForm *CalibrationForm;
//---------------------------------------------------------------------------
#endif
