//---------------------------------------------------------------------------

#ifndef fqcunitsetupH
#define fqcunitsetupH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "CurvyControls.hpp"
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Graphics.hpp>
#include <vector>
//---------------------------------------------------------------------------
class TfrmQcPositionSetup : public TForm
{
__published:	// IDE-managed Components
	TCurvyPanel *CurvySetUpPanel;
	TSpeedButton *BtnSaveData;
	TSpeedButton *BtnInputData;
	TLabel *Label1;
	TPanel *Panel5;
	TGridPanel *GridPanel1;
	TSpeedButton *SpeedButton1;
	TGroupBox *GroupBox1;
	TLabel *Label6;
	TEdit *Edit2;
	TEdit *Edit1;
	TLabel *Label5;
	TImage *Image1;
	TSpeedButton *BtnSaveUnitCnt;
	TSpeedButton *BtnInputUnitCnt;
	void __fastcall BtnInputDataClick(TObject *Sender);
	void __fastcall BtnSaveDataClick(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall BtnSaveUnitCntClick(TObject *Sender);
	void __fastcall BtnInputUnitCntClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
	std::vector<TForm*> 	_panels;
	void	resize_grid_panel();
	void	create_panel(int col, int row);
	void	readGerberData();
public:		// User declarations
	void Frm_UnitDisplay();
	__fastcall TfrmQcPositionSetup(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmQcPositionSetup *frmQcPositionSetup;
//---------------------------------------------------------------------------
#endif
