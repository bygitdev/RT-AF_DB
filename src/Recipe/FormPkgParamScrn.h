//---------------------------------------------------------------------------

#ifndef FormPkgParamScrnH
#define FormPkgParamScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "CurvyControls.hpp"
#include <Vcl.Buttons.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TFormPkgParam : public TForm
{
__published:	// IDE-managed Components
	TCurvyPanel *CurvyPanel1;
	TSpeedButton *BtnParamIndexMoveM10;
	TSpeedButton *BtnParamIndexMoveP10;
	TSpeedButton *BtnSaveItem;
	TSpeedButton *BtnInputItem;
	TStringGrid *PkgParamGrid;
	TSpeedButton *BtnPkgPass1;
	TSpeedButton *BtnPkgPass2;
	TSpeedButton *BtnPkgPass3;
	TSpeedButton *BtnPkgPass4;
	TSpeedButton *BtnPkgPass5;
	TSpeedButton *BtnPkgPass6;
	TSpeedButton *BtnPkgPass7;
	TSpeedButton *BtnPkgPass8;
	TSpeedButton *BtnPkgPass9;
	TSpeedButton *BtnPkgPass10;
	TSpeedButton *BtnPkgPass0;
	TButton *BtnNdmKeyPad;
	TEdit *EditParamIndex;
	void __fastcall BtnPkgPass1Click(TObject *Sender);
	void __fastcall BtnInputItemClick(TObject *Sender);
	void __fastcall BtnSaveItemClick(TObject *Sender);
	void __fastcall BtnParamIndexMoveM10Click(TObject *Sender);
	void __fastcall BtnParamIndexMoveP10Click(TObject *Sender);
	void __fastcall BtnNdmKeyPadClick(TObject *Sender);
	void __fastcall EditParamIndexKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);

private:	// User declarations

   bool PkgDataSeq_Write();
   bool PkgDataIni_name_save();
   bool PkgDataIni_name_read();
   bool PkgDataSeq_Read();

public:		// User declarations
	void PkgParam_Initialize();

	__fastcall TFormPkgParam(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormPkgParam *FormPkgParam;
//---------------------------------------------------------------------------
#endif
