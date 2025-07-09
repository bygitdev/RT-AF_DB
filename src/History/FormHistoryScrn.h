//---------------------------------------------------------------------------

#ifndef FormHistoryScrnH
#define FormHistoryScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormHistory : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TComboBox *ComboBoxAccessLevel;
	TPanel *Panel2;
	TBitBtn *BitBtn6;
	TBitBtn *HistoryFrmSub1;
	TBitBtn *HistoryFrmSub2;
	TBitBtn *HistoryFrmSub3;
	TPanel *HistoryBasePanel;
	TBitBtn *HistoryFrmSub4;
	TBitBtn *HistoryFrmSub5;
	TBitBtn *BitBtn1;
	void __fastcall HistoryFrmSub1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
   TForm* _pCurrentForm;
public:		// User declarations

	__fastcall TFormHistory(TComponent* Owner);

    void	ScreenChange(String menu);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormHistory *FormHistory;
//---------------------------------------------------------------------------
#endif
