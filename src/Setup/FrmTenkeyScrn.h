//---------------------------------------------------------------------------

#ifndef FrmTenkeyScrnH
#define FrmTenkeyScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "AdvPicture.hpp"
#include "CurvyControls.hpp"
#include "Shader.hpp"
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TFrmTenkey : public TForm
{
__published:	// IDE-managed Components
	TCurvyPanel *CurvyPanel3;
	TStringGrid *ChildGrid;
	TPanel *Panel1;
	TPanel *PanelSelectTenkeyNo;
	TPanel *PanelSelectTenkeyName;
	TSpeedButton *BtnTenkeyRun;
	TSpeedButton *BtnTenkeyStepRun;
	TCurvyPanel *CurvyPanel1;
	TStringGrid *ParentGrid;
	void __fastcall ParentGridSelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall ChildGridSelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall BtnTenkeyRunClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);


private:	// User declarations
	int g_nTenkeyPartNo;

	void __fastcall TenkeyScrnInitial();
    void __fastcall ParentTenkeyLoad();
    void __fastcall ChildTenkeyLoad(int nSelectNo);
    String	getTenKeyName(int nTenkeyNo);
public:		// User declarations
	__fastcall TFrmTenkey(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmTenkey *FrmTenkey;
//---------------------------------------------------------------------------
#endif
