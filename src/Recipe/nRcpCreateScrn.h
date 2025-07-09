//---------------------------------------------------------------------------

#ifndef nRcpCreateScrnH
#define nRcpCreateScrnH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <Grids.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
#include <Vcl.Buttons.hpp>
#include "Shader.hpp"
#include "CurvyControls.hpp"
//---------------------------------------------------------------------------
class TFrmRcpCreate : public TForm
{
__published:	// IDE-managed Components
	TCurvyPanel *CurvyPanel1;
	TGridPanel *GridPanel1;
	TCurvyPanel *CurvyPanel2;
	TLabel *Label1;
	TLabel *Label2;
	TSpeedButton *BtnRCPCopy;
	TPanel *PanelOriginName;
	TPanel *PanelNewName;
	TCurvyPanel *CurvyPanel3;
	TSpeedButton *DownRCPGridCtrl;
	TLabel *Label3;
	TLabel *Label5;
	TSpeedButton *UpRCPGridCtrl;
	TComboBox *GroupRCPComboBox;
	TStringGrid *OriginRCPGrid;
	TPanel *PanelGrpNo;
	TCurvyPanel *CurvyPanel4;
	TSpeedButton *DownRCPGridCtrl2;
	TLabel *Label4;
	TSpeedButton *UpRCPGridCtrl2;
	TComboBox *GroupTargetRCPComboBox;
	TPanel *PanelTargetGrpNo;
	TStringGrid *TargetRCPGrid;
	TPanel *Panel2;
	TCheckBox *SameGrpCheckBox;
	TPanel *Panel3;
	TSpeedButton *SpeedButton1;
	TPanel *Panel1;
	TSpeedButton *BtnInputItem;
	TSpeedButton *BtnSaveItem;
	TCheckBox *CheckRcpMotorfile;
	TCheckBox *CheckRcpfile;
	TSpeedButton *BtnDeleteItem;
    void __fastcall OriginRCPGridSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
    void __fastcall TargetRCPGridSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
    void __fastcall UpRCPGridCtrlClick(TObject *Sender);
    void __fastcall DownRCPGridCtrlClick(TObject *Sender);
    void __fastcall DownRCPGridCtrl2Click(TObject *Sender);
    void __fastcall UpRCPGridCtrl2Click(TObject *Sender);
	void __fastcall BtnRCPCopyClick(TObject *Sender);
	void __fastcall BtnInputItemClick(TObject *Sender);
	void __fastcall BtnSaveItemClick(TObject *Sender);
	void __fastcall OriginRCPGridDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall TargetRCPGridDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall GroupRCPComboBoxChange(TObject *Sender);
	void __fastcall GroupTargetRCPComboBoxChange(TObject *Sender);
	void __fastcall SameGrpCheckBoxClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall BtnDeleteItemClick(TObject *Sender);
private:	// User declarations
	int m_setGroupIndex;
	int m_setRecipeIndex;
	int m_IntendGrpCopyIndex;
    int m_IntendCopyIndex;

    bool 		 MtrFileCopy();
    bool  		 PKGParamFileCopy();
	bool  		 StaubliFileCopy();
    bool   		 GerberParamFileCopy();


public:		// User declarations
	void __fastcall RecipeCreate_Initialize(int nGrpNo);

    __fastcall TFrmRcpCreate(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmRcpCreate *FrmRcpCreate;
//---------------------------------------------------------------------------
#endif                FrmDevSetUp
