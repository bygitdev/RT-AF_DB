//---------------------------------------------------------------------------

#ifndef FrmTeachMainScrnH
#define FrmTeachMainScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include "CurvyControls.hpp"
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFrmTeachMain : public TForm
{
__published:	// IDE-managed Components
	TCurvyPanel *CurvyPanel1;
	TLabel *Label1;
	TBitBtn *BtnClose;
	TPanel *Panel1;
	TBitBtn *BtnTeachBtn1;
	TBitBtn *BtnTeachBtn2;
	TBitBtn *BtnTeachBtn4;
	TCurvyPanel *CurvyPanel2;
	TLabel *Label2;
	TBitBtn *BtnTeachBtn31;
	TBitBtn *BtnTeachBtn30;
	TBitBtn *BtnTeachBtn32;
	TPanel *Panel2;
	TBitBtn *BtnTeachBtn5;
	TBitBtn *BtnTeachBtn6;
	TBitBtn *BtnTeachBtn7;
	void __fastcall BtnTeachBtn1Click(TObject *Sender);
	void __fastcall BtnCloseClick(TObject *Sender);
	void __fastcall BtnTeachBtn2Click(TObject *Sender);
	void __fastcall BtnTeachBtn5Click(TObject *Sender);
	void __fastcall BtnTeachBtn7Click(TObject *Sender);
	void __fastcall BtnTeachBtn6Click(TObject *Sender);
	void __fastcall BtnTeachBtn4Click(TObject *Sender);
	void __fastcall BtnTeachBtn30Click(TObject *Sender);
	void __fastcall BtnTeachBtn31Click(TObject *Sender);
	void __fastcall BtnTeachBtn32Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFrmTeachMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmTeachMain *FrmTeachMain;
//---------------------------------------------------------------------------
#endif
