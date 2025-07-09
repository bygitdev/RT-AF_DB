//---------------------------------------------------------------------------

#ifndef SensorbaseFormScrnH
#define SensorbaseFormScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TSensorbaseForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *PanelSystemBase;
	TPanel *PanelSensorPart1;
	TPanel *PanelSensorPart5;
	TPanel *PanelSensorPart2;
	TPanel *PanelSensorPart3;
	TPanel *PanelSensorPart4;
	TPanel *PanelSensorPart6;
	TPanel *PanelSensorPart7;
	TPanel *PanelSensorPart8;
	void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations
	TForm* pSensorFrm[8];
public:		// User declarations
	__fastcall TSensorbaseForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSensorbaseForm *SensorbaseForm;
//---------------------------------------------------------------------------
#endif
