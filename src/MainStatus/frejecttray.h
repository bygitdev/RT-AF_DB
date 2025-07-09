//---------------------------------------------------------------------------

#ifndef frejecttrayH
#define frejecttrayH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
#include <vector>

class TfrmRejectTray : public TForm
{
__published:	// IDE-managed Components
	TGridPanel *GridPanel1;
	TPanel *PanelIndex;
	TBitBtn *BitBtnPrev;
	TBitBtn *BitBtnNext;
	TPanel *PanelPage;
	TBitBtn *BitBtn4;
	void __fastcall BitBtnPrevClick(TObject *Sender);
	void __fastcall BitBtnNextClick(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations
	std::vector<TPanel*> 	_panels;
	int 	_page;
	void	regen();
	String 	read_status(int page, int unitId);
public:		// User declarations
	__fastcall TfrmRejectTray(TComponent* Owner);

	void	SetTrayCount(int col, int row);
	void	SetDisplayIndex(bool enable);
	void	SetUnitStatus(int id, String caption);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmRejectTray *frmRejectTray;
//---------------------------------------------------------------------------
#endif
