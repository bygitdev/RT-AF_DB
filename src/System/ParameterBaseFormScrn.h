//---------------------------------------------------------------------------

#ifndef ParameterBaseFormScrnH
#define ParameterBaseFormScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "CurvyControls.hpp"
#include <Vcl.Buttons.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TParameterBaseForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *PanelSystemBase;
	TCurvyPanel *CurvyPanel1;
	TCurvyPanel *CurvyPanel2;
	TCurvyPanel *CurvyPanel3;
	TStringGrid *nDMParamGrid;
	TSpeedButton *BtnParam1IndexMoveM10;
	TSpeedButton *BtnParam1IndexMoveP10;
	TSpeedButton *BtnSaveInt;
	TSpeedButton *BtnInputInt;
	TLabel *LabelfileSavefunction1;
	TLabel *Label2;
	TSpeedButton *BtnParam2IndexMoveM10;
	TStringGrid *dDMParamGrid;
	TSpeedButton *BtnParam2IndexMoveP10;
	TSpeedButton *BtnSaveDouble;
	TSpeedButton *BtnInputDouble;
	TLabel *Label3;
	TSpeedButton *BtnParam3IndexMoveM10;
	TStringGrid *pDMParamGrid;
	TSpeedButton *BtnParam3IndexMoveP10;
	TSpeedButton *BtnSavePkg;
	TSpeedButton *BtnInputPkg;
	TSpeedButton *BtnReverseSavePkg;
	TSpeedButton *BtnNDMRead;
	TSpeedButton *BtnDDMRead;
	TSpeedButton *BtnPDMRead;
	TEdit *EditNdmIndex;
	TButton *BtnNdmKeyPad;
	TButton *BtnDdmKeyPad;
	TEdit *EditDdmIndex;
	TButton *BtnPdmKeyPad;
	TEdit *EditPdmIndex;
	TOpenDialog *OpenDialog;
	TSaveDialog *SaveDialog;
	void __fastcall BtnInputIntClick(TObject *Sender);
	void __fastcall BtnSaveIntClick(TObject *Sender);
	void __fastcall BtnParam1IndexMoveM10Click(TObject *Sender);
	void __fastcall BtnParam1IndexMoveP10Click(TObject *Sender);
	void __fastcall BtnInputDoubleClick(TObject *Sender);
	void __fastcall BtnSaveDoubleClick(TObject *Sender);
	void __fastcall BtnParam2IndexMoveM10Click(TObject *Sender);
	void __fastcall BtnParam2IndexMoveP10Click(TObject *Sender);
	void __fastcall BtnInputPkgClick(TObject *Sender);
	void __fastcall BtnSavePkgClick(TObject *Sender);
	void __fastcall BtnParam3IndexMoveM10Click(TObject *Sender);
	void __fastcall BtnParam3IndexMoveP10Click(TObject *Sender);
	void __fastcall BtnNDMReadClick(TObject *Sender);
	void __fastcall BtnDDMReadClick(TObject *Sender);
	void __fastcall BtnPDMReadClick(TObject *Sender);
	void __fastcall BtnNdmKeyPadClick(TObject *Sender);
	void __fastcall EditNdmIndexClick(TObject *Sender);
	void __fastcall EditDdmIndexClick(TObject *Sender);
	void __fastcall EditPdmIndexClick(TObject *Sender);
	void __fastcall EditNdmIndexKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall EditDdmIndexKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall EditPdmIndexKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall FormShow(TObject *Sender);



private:	// User declarations

	bool    IntParam_name_read();
    bool    IntParam_name_save();
    bool    Int_value_read();
    bool    Int_value_write();

	bool    DoubleParam_name_read();
    bool    DoubleParam_name_save();
    bool    Double_value_read();
    bool    Double_value_write();


	bool    PkgParam_name_read();
    bool    PkgParam_name_save(bool bReverse);
	bool    Pkg_value_read();
    bool    Pkg_value_write();
	String 		_oldValue;
public:		// User declarations

	void __fastcall ParameterScreen_Initialize();
	__fastcall TParameterBaseForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TParameterBaseForm *ParameterBaseForm;
//---------------------------------------------------------------------------
#endif
