//---------------------------------------------------------------------------

#ifndef FrmRecipeControlScrnH
#define FrmRecipeControlScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TFrmRecipeControl : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TStringGrid *RecipeControlGrid;
	TTimer *ProgressTimer;
	TPanel *PanelProgress;
	TLabel *LabelProgress;
	TProgressBar *ConversionProgress;
	TSpeedButton *BtnRecipeControlUp;
	TSpeedButton *BtnRecipeControlDown;
	TPanel *Panel2;
	TPanel *PanelSetRCP;
	TLabel *LabelHandlerRCPSelect;
	TLabel *LabellLeftRecipe;
	TPanel *PanelSelectRecipe;
	TCheckBox *CheckBoxVisionConversionCommand;
	TCheckBox *CheckBoxLaserConversionCommand;
	TSpeedButton *BtnRecipeChange;
	TLabel *Label6;
	TLabel *Label1;
	TStringGrid *GroupControlGrid;
	TLabel *Label2;
	TPanel *PanelSetGRP;
	TPanel *PanelSelectGroup;
	TLabel *Label3;
	TLabel *Label4;
	void __fastcall BtnRecipeControlUpClick(TObject *Sender);
	void __fastcall RecipeControlGridDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall RecipeControlGridDblClick(TObject *Sender);
	void __fastcall RecipeControlGridSelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect);
	void __fastcall BtnRecipeControlDownClick(TObject *Sender);
	void __fastcall ProgressTimerTimer(TObject *Sender);
	void __fastcall BtnRecipeChangeClick(TObject *Sender);
	void __fastcall GroupControlGridDblClick(TObject *Sender);
	void __fastcall GroupControlGridDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall GroupControlGridSelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect);
private:	// User declarations
	int		m_groupNo;
	int     m_recipeNo;
	int     m_IntendRecipeNo;
	int     nDisplayProgress;

    int      _nLeftRight_;

	bool   PKGDataConvert();
	bool   MotionConvert();

public:		// User declarations
	bool   RecipePath_Check(int ngrpindex, int nrcpindex);
	void   RecipeCheck_Display(int nGrpNo, TStringGrid *pGrid);

	void   GroupName_Read(TStringGrid *pGrid);
	bool   RecipeName_Read(int nGrpNo, TStringGrid *pGrid);
	bool  RecipeName_Save(int nGrpNo, TStringGrid *pGrid);

	void __fastcall RecipeControl_Initialize(int nLeftRight);
    String   RecipeName_ReturnString(int nRecipeIndex);

	__fastcall TFrmRecipeControl(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmRecipeControl *FrmRecipeControl;
//---------------------------------------------------------------------------
#endif
