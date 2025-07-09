//---------------------------------------------------------------------------

#ifndef fadctypeH
#define fadctypeH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TfrmJobType : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *StringGrid1;
	TPanel *PanelName;
	TPanel *PanelIndex;
	TSpeedButton *SpeedButtonInput;
	TSpeedButton *SpeedButtonSave;
	TSpeedButton *SpeedButton4;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall StringGrid1SelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall SpeedButton4Click(TObject *Sender);
	void __fastcall SpeedButtonInputClick(TObject *Sender);
	void __fastcall SpeedButtonSaveClick(TObject *Sender);

private:	// User declarations
	int 	_ndmIndex;
    String 	_iniFileName;
    String	getTypeName(int index);
public:		// User declarations
	__fastcall TfrmJobType(TComponent* Owner, int ndmIndex);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmJobType *frmJobType;
//---------------------------------------------------------------------------
#endif
