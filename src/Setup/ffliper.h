//---------------------------------------------------------------------------

#ifndef ffliperH
#define ffliperH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmFlipper : public TForm
{
__published:	// IDE-managed Components
	TPanel *MatrixBasePanel;
	TLabel *Label1;
	TLabel *Label2;
	TPanel *PanelTop;
	TPanel *PanelBtm;
	TGridPanel *GridPanel3;
	TGridPanel *GridPanel1;
	TPanel *PanelTop3;
	TPanel *PanelTop4;
	TPanel *PanelTop1;
	TPanel *PanelTop2;
	TGridPanel *GridPanel2;
	TPanel *PanelBtm1;
	TPanel *PanelBtm2;
	TPanel *PanelBtm3;
	TPanel *PanelBtm4;
	void __fastcall PanelTop3DblClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
	void	refresh_panel();
public:		// User declarations
	__fastcall TfrmFlipper(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmFlipper *frmFlipper;
//---------------------------------------------------------------------------
#endif
