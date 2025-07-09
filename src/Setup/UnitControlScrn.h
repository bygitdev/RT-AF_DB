//---------------------------------------------------------------------------

#ifndef UnitControlScrnH
#define UnitControlScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "CurvyControls.hpp"
#include <Vcl.ExtCtrls.hpp>
#include "cspin.h"
//---------------------------------------------------------------------------
class TFrmUnitControl : public TForm
{
__published:	// IDE-managed Components
	TCurvyPanel *CurvyPanel1;
	TLabel *Label1;
	TEdit *EditXSize;
	TLabel *Label2;
	TEdit *EditYSize;
	TPanel *PanelFlip;
	TLabel *LabelNotify;
	TEdit *EditTheta;
	TLabel *Label3;
	TCSpinEdit *CSpinEditBinNo;
	void __fastcall PanelFlipDblClick(TObject *Sender);
private:	// User declarations
	int _nLocateIndex , _nXnumber , _nYnumber , _FlipStatusnumber, _nTheta, _bBinNo;


	void UnitDataRead(int nIndex);
	void UnitDataSave(int nIndex);

public:		// User declarations

		void _UnitDataSave(int nIndex);
	void Form_Initialize(int nIndex);
	__fastcall TFrmUnitControl(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TFrmUnitControl *FrmUnitControl;
//---------------------------------------------------------------------------
#endif
