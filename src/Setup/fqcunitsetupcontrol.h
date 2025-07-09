//---------------------------------------------------------------------------

#ifndef fqcunitsetupcontrolH
#define fqcunitsetupcontrolH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "CurvyControls.hpp"
//---------------------------------------------------------------------------
class TFrmQcUnitControl : public TForm
{
__published:	// IDE-managed Components
	TCurvyPanel *CurvyPanel1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *LabelNotify;
	TEdit *EditXSize;
	TEdit *EditYSize;
private:	// User declarations
	int _nLocateIndex , _nXnumber , _nYnumber , _FlipStatusnumber, _nTheta;


	void UnitDataRead(int nIndex);
	void UnitDataSave(int nIndex);
public:		// User declarations
	void DataSave(int nIndex);
	void Form_Initialize(int nIndex);
	__fastcall TFrmQcUnitControl(TComponent* Owner);

	void setPositionString(String x, String y);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmQcUnitControl *FrmQcUnitControl;
//---------------------------------------------------------------------------
#endif
