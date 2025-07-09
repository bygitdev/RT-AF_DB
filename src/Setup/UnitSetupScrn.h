//---------------------------------------------------------------------------

#ifndef UnitSetupScrnH
#define UnitSetupScrnH
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
class TFrmUnitSetup : public TForm
{
__published:	// IDE-managed Components
	TCurvyPanel *CurvySetUpPanel;
	TSpeedButton *BtnSaveData;
	TSpeedButton *BtnInputData;
	TPanel *Panel5;
	TSpeedButton *SpeedButton1;
	TGridPanel *GridPanel1;
	TLabel *Label9;
	TGroupBox *GroupBox1;
	TLabel *Label6;
	TLabel *Label5;
	TImage *Image1;
	TSpeedButton *BtnSaveUnitCnt;
	TEdit *Edit2;
	TEdit *Edit1;
	TGroupBox *GroupBox2;
	TLabel *Label2;
	TEdit *EditXOffset;
	TLabel *Label3;
	TEdit *EditYOffset;
	TLabel *Label4;
	TEdit *EditTolerence;
	TSpeedButton *BtnSaveTolerence;
	TLabel *Label7;
	TSpeedButton *SpeedButton2;
	TTimer *Timer1;
	TSpeedButton *BtnInputUnitCnt;
	TSpeedButton *BtnInputTolerence;
	TSpeedButton *BtnInputOffset;
	TSpeedButton *BtnSaveOffset;
	TGroupBox *GroupBox3;
	TLabel *Label1;
	TLabel *Label8;
	TSpeedButton *btnRobotThetaInput;
	TSpeedButton *btnRobotThetaSave;
	TEdit *EditTopThetaOffset;
	TEdit *EditBtmThetaOffset;
	TScrollBox *ScrollBox1;
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall BtnSaveDataClick(TObject *Sender);
	void __fastcall BtnInputDataClick(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall BtnSaveTolerenceClick(TObject *Sender);
	void __fastcall BtnSaveUnitCntClick(TObject *Sender);
	void __fastcall BtnInputUnitCntClick(TObject *Sender);
	void __fastcall BtnInputOffsetClick(TObject *Sender);
	void __fastcall BtnInputTolerenceClick(TObject *Sender);
	void __fastcall BtnSaveOffsetClick(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall btnRobotThetaInputClick(TObject *Sender);
	void __fastcall btnRobotThetaSaveClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations

		TForm* pSubUnitCtrlFrm[20];
		std::vector<TForm*> 	_panels;
		void	resize_grid_panel();
		void	create_panel(int col, int row);

		void	refresh_data();
		void	readGerberData();
public:		// User declarations

	void Frm_UnitDisplay();
	__fastcall TFrmUnitSetup(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmUnitSetup *FrmUnitSetup;
//---------------------------------------------------------------------------
#endif
