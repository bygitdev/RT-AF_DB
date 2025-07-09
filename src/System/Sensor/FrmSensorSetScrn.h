//---------------------------------------------------------------------------

#ifndef FrmSensorSetScrnH
#define FrmSensorSetScrnH
#include "CurvyControls.hpp"
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <VCLTee.TeCanvas.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class TFrmSensorSet : public TForm
{
__published:	// IDE-managed Components
	TColorDialog *ColorDialog;
	TCurvyPanel *CurvyPanelSensorEdit;
	TStringGrid *SensorNameGrid;
	TCurvyPanel *CurvyPanelSensorSet;
	TCurvyPanel *CurvyPanel1;
	TLabel *LabelChNotify;
	TCurvyPanel *CurvyPanel3;
	TLabel *Label1;
	TCurvyPanel *CurvyPanel2;
	TLabel *IOChIndexLabel;
	TSpeedButton *LMDButtonClose;
	TBitBtn *BtnSensorNameView;
	TRadioButton *LMDRadioButtonInput;
	TRadioButton *LMDRadioButtonOutput;
	TComboBox *LMDComboBoxIndex;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall LMDRadioButtonOutputClick(TObject *Sender);
	void __fastcall LMDRadioButtonInputClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall LMDComboBoxIndexSelect(TObject *Sender);

private:	// User declarations
		int nSetPointIndex;

     TForm* m_pSensorForm;
	void __fastcall SensorNamefromDB4Edit(bool bIO , int nChannel);
public:		// User declarations

	void __fastcall FrmSensorSet_Initialize(int nPosID, TForm* pParent);
	__fastcall TFrmSensorSet(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmSensorSet *FrmSensorSet;
//---------------------------------------------------------------------------
#endif
