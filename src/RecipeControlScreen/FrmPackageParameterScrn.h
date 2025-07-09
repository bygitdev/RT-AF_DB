//---------------------------------------------------------------------------

#ifndef FrmPackageParameterScrnH
#define FrmPackageParameterScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TFrmPackageParameter : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TStringGrid *PackageParamGrid;
	TSpeedButton *BtnInputMotionData;
	TSpeedButton *BtnSaveMotionData;
	TSpeedButton *BtnParamIndexMoveM10;
	TSpeedButton *BtnParamIndexMoveP10;
	TSpeedButton *SpeedButton1;
	void __fastcall BtnParamIndexMoveP10Click(TObject *Sender);
	void __fastcall BtnParamIndexMoveM10Click(TObject *Sender);
	void __fastcall BtnInputMotionDataClick(TObject *Sender);
	void __fastcall BtnSaveMotionDataClick(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);

private:	// User declarations

	int 	_nLeftRight_;

	bool    Pacakageparam_Data_read(int nLeftRight);
    bool    Packageparam_Data_save(int nLeftRight);


    bool    Pacakageparam_SEQ_read(int nLeftRight);
    bool    Pacakageparam_SEQ_save(int nLeftRight);

public:		// User declarations

	void    Pacakageparam_Initialize(int  nLeftStage);
	__fastcall TFrmPackageParameter(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmPackageParameter *FrmPackageParameter;
//---------------------------------------------------------------------------
#endif
