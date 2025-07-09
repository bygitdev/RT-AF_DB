//---------------------------------------------------------------------------

#ifndef RcpCreateScrnH
#define RcpCreateScrnH
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
class ToFrmRcpCreate : public TForm
{
__published:	// IDE-managed Components
	TCurvyPanel *CurvyPanel1;
	TSpeedButton *BtnClose;
	TPanel *Panel2;
	TPanel *PanelGrpNo;
	TComboBox *GroupRCPComboBox;
	TLabel *Label5;
	TSpeedButton *DownRCPGridCtrl;
	TSpeedButton *UpRCPGridCtrl;
	TStringGrid *OriginRCPGrid;
	TLabel *Label3;
	TPanel *Panel3;
	TCheckBox *SameGrpCheckBox;
	TPanel *PanelTargetGrpNo;
	TComboBox *GroupTargetRCPComboBox;
	TLabel *Label4;
	TStringGrid *TargetRCPGrid;
	TSpeedButton *UpRCPGridCtrl2;
	TSpeedButton *DownRCPGridCtrl2;
	TCurvyPanel *CurvyPanel2;
	TLabel *Label1;
	TPanel *PanelOriginName;
	TLabel *Label2;
	TPanel *PanelNewName;
	TSpeedButton *BtnRCPCopy;
	TCheckBox *CheckRcpMotorfile;
	TCheckBox *CheckRcpfile;
	TPanel *Panel1;
	TSpeedButton *BtnInputItem;
	TSpeedButton *BtnSaveItem;
    void __fastcall OriginRCPGridSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
    void __fastcall TargetRCPGridSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
    void __fastcall UpRCPGridCtrlClick(TObject *Sender);
    void __fastcall DownRCPGridCtrlClick(TObject *Sender);
    void __fastcall DownRCPGridCtrl2Click(TObject *Sender);
    void __fastcall UpRCPGridCtrl2Click(TObject *Sender);
	void __fastcall BtnCloseClick(TObject *Sender);
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

    __fastcall ToFrmRcpCreate(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE ToFrmRcpCreate *oFrmRcpCreate;
//---------------------------------------------------------------------------
#endif                FrmDevSetUp
