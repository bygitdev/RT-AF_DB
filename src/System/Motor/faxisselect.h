//---------------------------------------------------------------------------

#ifndef faxisselectH
#define faxisselectH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
#include <vector>
class TfrmSelectAxis : public TForm
{
__published:	// IDE-managed Components
	TGridPanel *GridPanel1;
	TGridPanel *GridPanelAxis;
	TGridPanel *GridPanelCategory;
	TBitBtn *ButtonAll;
	void __fastcall ButtonAllClick(TObject *Sender);
	void __fastcall CategoryBtnClick(TObject *Sender);
	void __fastcall AxisBtnClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations
	std::vector<TBitBtn*>	_category;
	std::vector<TBitBtn*>	_axis;
	TForm* 	_target;

	void	set_axis(int index);


public:		// User declarations
	__fastcall TfrmSelectAxis(TComponent* Owner, TForm* target);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmSelectAxis *frmSelectAxis;
//---------------------------------------------------------------------------
#endif
