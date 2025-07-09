//---------------------------------------------------------------------------

#ifndef RecipeChangeFormScrnH
#define RecipeChangeFormScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "CurvyControls.hpp"
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TRecipeChangeForm : public TForm
{
__published:	// IDE-managed Components
	TCurvyPanel *pnMain;
	TPanel *Panel1;
	TSpeedButton *BtnRecipeChange;
	TPanel *Panel2;
	TStringGrid *GroupControlGrid;
	TPanel *Panel3;
	TStringGrid *RecipeControlGrid;
	TSpeedButton *BtnGroupRecipeGridMoveup;
	TSpeedButton *BtnGroupRecipeGridMoveDown;
	TSpeedButton *BtnRecipeGridMoveUp;
	TSpeedButton *BtnRecipeGridMoveDown;
	TCurvyPanel *CurvyPanel3;
	TLabel *Label3;
	TPanel *PanelSelectGroup;
	TLabel *LabelHandlerRCPSelect;
	TPanel *PanelSelectRecipe;
	TCurvyPanel *CurvyPanel4;
	TCheckBox *CheckBoxVisionConversionCommand;
	TTimer *ProgressTimer;
	TPanel *PanelProgress;
	TLabel *LabelProgress;
	TProgressBar *ConversionProgress;
	TCurvyPanel *CurvyPanel2;
	TLabel *Label1;
	TLabel *LabellLeftRecipe;
	TPanel *PanelSetGRP;
	TPanel *PanelSetRCP;
	TSpeedButton *BtnInputGroupName;
	TSpeedButton *BtnSaveGroupName;
	TSpeedButton *BtnSaveRecipeName;
	TSpeedButton *BtnInputRecipeName;
	TLabel *LabelNotifyName;
	TLabel *LabelNotifyRecipe;
	TSpeedButton *SpeedButton1;
	TTimer *AutoDeviceChangeTimer;
	TPanel *pnBackgroundRMS;
	TGridPanel *GridPanelCurrentRecipe;
	TPanel *PanelRecipeStatus;
	TPanel *Panel21;
	TPanel *PanelGroupNo;
	TPanel *PanelPPID;
	TPanel *PanelRecipeNo;
	TPanel *pnFunction;
	TBitBtn *btnExit;
	TGridPanel *gpFunctionRcpDw;
	TPanel *Panel6;
	TPanel *Panel7;
	TComboBox *cboxPpidList;
	TButton *btnRecipeDownload;
	TPanel *Panel8;
	TPanel *Panel9;
	TPanel *Panel13;
	TPanel *Panel17;
	TButton *btnGetLotInfo;
	TPanel *Panel16;
	TGridPanel *GridPanel1;
	TPanel *Panel19;
	TEdit *edtLotType;
	TEdit *edtStepSeq;
	TEdit *edtLotId;
	TEdit *edtPartId;
	TPanel *Panel18;
	TPanel *pnHostRecipeId;
	TPanel *Panel10;
	TButton *btnRecipeUpload;
	TButton *btnRename;
	TLabel *lbVerRMS;
	void __fastcall BtnGroupRecipeGridMoveupClick(TObject *Sender);
	void __fastcall BtnGroupRecipeGridMoveDownClick(TObject *Sender);
	void __fastcall BtnRecipeGridMoveUpClick(TObject *Sender);
	void __fastcall BtnRecipeGridMoveDownClick(TObject *Sender);
	void __fastcall RecipeControlGridDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall RecipeControlGridSelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect);
	void __fastcall ProgressTimerTimer(TObject *Sender);
	void __fastcall BtnRecipeChangeClick(TObject *Sender);
	void __fastcall GroupControlGridDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall GroupControlGridSelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect);
	void __fastcall BtnInputGroupNameClick(TObject *Sender);
	void __fastcall BtnSaveGroupNameClick(TObject *Sender);
	void __fastcall BtnInputRecipeNameClick(TObject *Sender);
	void __fastcall BtnSaveRecipeNameClick(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall AutoDeviceChangeTimerTimer(TObject *Sender);
	void __fastcall btnRecipeDownloadClick(TObject *Sender);
	void __fastcall btnGetLotInfoClick(TObject *Sender);
	void __fastcall btnExitClick(TObject *Sender);
	void __fastcall btnRecipeUploadClick(TObject *Sender);
	void __fastcall btnRenameClick(TObject *Sender);
	void __fastcall lbVerRMSDblClick(TObject *Sender);
private:	// User declarations

	int		m_groupNo;
	int     m_recipeNo;
	int     m_IntendRecipeNo;
	int     nDisplayProgress;

	int     m_LastGroupNo, m_LastRecipeNo;

	bool   PKGDataConvert();
	bool   MotionConvert();
    bool   StaubliDataConvert();
    bool   GerberDataConvert();

	bool   PKGDataConvert(int nGrpNo, int nRcpNo);
	bool   MotionConvert(int nGrpNo, int nRcpNo);
	bool   StaubliDataConvert(int nGrpNo, int nRcpNo);
	bool   GerberDataConvert(int nGrpNo, int nRcpNo);

public:		// User declarations
 	bool   autoDeviceChange();
	bool   RecipePath_Check(int ngrpindex, int nrcpindex);
	void   RecipeCheck_Display(int nGrpNo, TStringGrid *pGrid);

	bool   GroupName_Read(TStringGrid *pGrid);
	bool   GroupName_Save(TStringGrid *pGrid);
	bool   RecipeName_Read(int nGrpNo, TStringGrid *pGrid, bool bChange=true);
	bool   RecipeName_Save(int nGrpNo, TStringGrid *pGrid);

	void  RecipeControl_Initialize();
	String   RecipeName_ReturnString(int nGroupIndex, int nRecipeIndex);
    void __fastcall DisplayRMS();

	__fastcall TRecipeChangeForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TRecipeChangeForm *RecipeChangeForm;
//---------------------------------------------------------------------------
#endif
