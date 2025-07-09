//---------------------------------------------------------------------------

#ifndef FrmUserDataViewScrnH
#define FrmUserDataViewScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "CurvyControls.hpp"
#include <Vcl.Grids.hpp>
#include "AdvPicture.hpp"
#include <Vcl.ExtCtrls.hpp>
#include "Shader.hpp"
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TFrmUserDataView : public TForm
{
__published:	// IDE-managed Components
	TTimer *UserDataTimer;
	TShader *Shader1;
	TLabel *Label1;
	TAdvPicture *ImgIDVClose;
	TCurvyPanel *CurvyPanel1;
	TSpeedButton *BtnSavePKGData;
	TSpeedButton *BtnPkgGridUp;
	TSpeedButton *BtnPkgGridDown;
	TStringGrid *PkgParamGrid;
	TCurvyEdit *CurvyEdit1;
	TSpeedButton *BtnInputPKGData;
	TSpeedButton *BtnUserParameter1;
	TSpeedButton *BtnUserParameter2;
	TSpeedButton *BtnUserParameter3;
	TSpeedButton *BtnUserParameter4;
	TCurvyPanel *CurvyPanel2;
	TSpeedButton *BtnSaveUserData;
	TSpeedButton *BtnInputUserData;
	TSpeedButton *BtnUserDataGridDown;
	TSpeedButton *BtnUserDataGridUp;
	TCurvyEdit *CurvyEdit2;
	TStringGrid *UserParamGrid;
	void __fastcall UserDataTimerTimer(TObject *Sender);
	void __fastcall BtnUserDataGridUpClick(TObject *Sender);
	void __fastcall BtnUserDataGridDownClick(TObject *Sender);
	void __fastcall BtnInputUserDataClick(TObject *Sender);
	void __fastcall BtnSaveUserDataClick(TObject *Sender);
	void __fastcall BtnPkgGridDownClick(TObject *Sender);
	void __fastcall BtnPkgGridUpClick(TObject *Sender);
	void __fastcall BtnInputPKGDataClick(TObject *Sender);
	void __fastcall BtnSavePKGDataClick(TObject *Sender);
	void __fastcall ImgIDVCloseClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall BtnUserParameter1Click(TObject *Sender);
private:	// User declarations

	int nDDMCategoryStartNo , nPKGCategoryStartNo;

     void __fastcall UserParamInitialize();
     void __fastcall UserParamDataLoad();
     void __fastcall UserData_ReadFromDB();
     void __fastcall UserParamDataSave();

	void __fastcall UserData_PKG_SaveToDB();
	void __fastcall UserData_PKG_SaveToSEQ();
	void __fastcall UserData_PKG_ReadFromDB();
    void __fastcall UserData_PKG_ReadFromSEQ();

public:		// User declarations



	__fastcall TFrmUserDataView(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmUserDataView *FrmUserDataView;
//---------------------------------------------------------------------------
#endif
