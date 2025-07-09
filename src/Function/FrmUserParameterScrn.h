//---------------------------------------------------------------------------

#ifndef FrmUserParameterScrnH
#define FrmUserParameterScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "CurvyControls.hpp"
#include <Vcl.Buttons.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TFrmUserParameter : public TForm
{
__published:	// IDE-managed Components
	TCurvyPanel *CurvyPanel1;
	TBitBtn *BitBtn1;
	TStringGrid *UserParamGrid;
	TSpeedButton *BtnParamIndexMoveP10;
	TSpeedButton *BtnParamIndexMoveM10;
	TSpeedButton *BtnSaveItem;
	TSpeedButton *BtnInputItem;
	TLabel *Label1;
	TSpeedButton *BtnPKGdata;
	TSpeedButton *BtnDDMdata;
	TSpeedButton *BtnNDMdata;
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall BtnInputItemClick(TObject *Sender);
	void __fastcall BtnSaveItemClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall BtnParamIndexMoveM10Click(TObject *Sender);
	void __fastcall BtnParamIndexMoveP10Click(TObject *Sender);
	void __fastcall BtnPKGdataClick(TObject *Sender);
private:	// User declarations
	String	_strSectionName;
	int		_nCmdType, _nDataIndex;
	double 	m_dOldData[500];

	bool    Userparam_name_read(int dataType);
	bool    Userparam_name_save(int dataType);
	bool    User_value_read(int dataType);
	bool    User_value_write(int dataType);

public:		// User declarations
	__fastcall TFrmUserParameter(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmUserParameter *FrmUserParameter;
//---------------------------------------------------------------------------
#endif
