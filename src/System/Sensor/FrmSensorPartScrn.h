//---------------------------------------------------------------------------

#ifndef FrmSensorPartScrnH
#define FrmSensorPartScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "AdvPicture.hpp"
#include "CurvyControls.hpp"
#include <Vcl.Grids.hpp>

//---------------------------------------------------------------------------
class TFrmSensorPart : public TForm
{
__published:	// IDE-managed Components
	TCurvyPanel *CurvyPanel1;
	TTimer *SensorRefresh;
	TLabel *LabelSensorNotify;
	TAdvPicture *AdvPictureMoveLast;
	TAdvPicture *AdvPictureMoveNext;
	TStringGrid *StringGridSensor;
	TPanel *SensorPanel2;
	TPanel *SensorPanel3;
	TPanel *SensorPanel4;
	TPanel *SensorPanel5;
	TPanel *SensorPanel6;
	TPanel *SensorPanel7;
	TPanel *SensorPanel8;
	TPanel *SensorPanel9;
	TPanel *SensorPanel10;
	TPanel *SensorPanel11;
	TPanel *SensorPanel12;
	TPanel *SensorPanel13;
	TPanel *SensorPanel14;
	TPanel *SensorPanel15;
	TPanel *SensorPanel16;
	TPanel *SensorPanel1;
	TCheckBox *CheckBoxExt;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall SensorRefreshTimer(TObject *Sender);
	void __fastcall AdvPictureMoveNextClick(TObject *Sender);
	void __fastcall SensorPanel1DblClick(TObject *Sender);
	void __fastcall CheckBoxExtClick(TObject *Sender);
private:	// User declarations
	bool _bSensorIO;
    int  _nChannelIndex;
	TColor 	_clSensorColor;

    void __fastcall SensorDataReadfromIni(bool bIO);
	void __fastcall SensorStatus_Config();
public:		// User declarations
    int  nSensorPosID;

    void __fastcall SensorScreenInitialize(int nPosID);

	__fastcall TFrmSensorPart(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmSensorPart *FrmSensorPart;
//---------------------------------------------------------------------------
#endif
