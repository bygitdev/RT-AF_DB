//---------------------------------------------------------------------------

#ifndef falarmlistH
#define falarmlistH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <inifiles.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TfrmAlarmList : public TForm
{
__published:	// IDE-managed Components
	TGridPanel *GridPanel1;
	TPanel *Panel1;
	TGridPanel *GridPanel2;
	TStringGrid *StringGridList;
	TGridPanel *GridPanel3;
	TBitBtn *BitBtn3;
	TBitBtn *BitBtn4;
	TBitBtn *BitBtn6;
	TBitBtn *BitBtn7;
	TPanel *Panel2;
	TPanel *Panel3;
	TRichEdit *RichEditSolution;
	TGridPanel *GridPanel4;
	TPanel *PanelIndex;
	TPanel *Panel5;
	TBitBtn *ButtonEdit;
	TBitBtn *ButtonSave;
	TEdit *EditTitle;
	TGridPanel *GridPanel5;
	TPanel *PanelCategory;
	TBitBtn *ButtonAlarm;
	TBitBtn *ButtonWarning;
	TGridPanel *GridPanel6;
	TBitBtn *ButtonGo;
	TPanel *Panel4;
	TEdit *EditGoTarget;
	TCheckBox *CheckBoxAlarm;
	TPanel *Panel6;
	TBitBtn *BitBtn1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ButtonSwitchClick(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall ButtonEditClick(TObject *Sender);
	void __fastcall ButtonSaveClick(TObject *Sender);
	void __fastcall StringGridListSelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ButtonPagingClick(TObject *Sender);
	void __fastcall ButtonGoClick(TObject *Sender);

private:	// User declarations
	void 	regen();
	void    select(int index);
	TIniFile*	_pCurIni;
	TIniFile*	_IniAlarm;
	TIniFile*	_IniWarning;
public:		// User declarations
	__fastcall TfrmAlarmList(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmAlarmList *frmAlarmList;
//---------------------------------------------------------------------------
#endif
