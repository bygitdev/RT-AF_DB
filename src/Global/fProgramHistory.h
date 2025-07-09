//---------------------------------------------------------------------------

#ifndef fProgramHistoryH
#define fProgramHistoryH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFrmProgramHistory : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TLabel *labelName;
	TButton *Button1;
	TMemo *Memo1;
	TButton *Button2;
	TEdit *Edit1;
	TMemo *Memo2;
	TDateTimePicker *DateTimePicker1;
	TLabel *Label1;
	TLabel *Label2;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFrmProgramHistory(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmProgramHistory *FrmProgramHistory;
//---------------------------------------------------------------------------
#endif
