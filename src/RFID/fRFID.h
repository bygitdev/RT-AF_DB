//---------------------------------------------------------------------------

#ifndef fRFIDH
#define fRFIDH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>

//---------------------------------------------------------------------------
class TfrmRFID : public TForm
{
__published:	// IDE-managed Components
	TMemo *MemoLog;
	TButton *btnRead;
	TEdit *EditCarrierID;
	TLabel *Label1;
	TLabel *Label3;
	TEdit *EditQty;
	TEdit *EditLotID;
	TLabel *Label4;
	TLabel *Label5;
	TEdit *EditStep;
	TEdit *EditPartNO;
	TLabel *Label6;
	TButton *btnWrite;
	TTimer *Timer1;
	TTimer *Timer2;
	TRadioGroup *rgChannel;
	TButton *btnClear;
	void __fastcall btnReadClick(TObject *Sender);
	void __fastcall btnWriteClick(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall btnClearClick(TObject *Sender);
private:	// User declarations


public:		// User declarations

	__fastcall TfrmRFID(TComponent* Owner);
	void __fastcall AddCommLog(String sLog, int iType=0);
	void __fastcall CommClear();
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmRFID *frmRFID;
//---------------------------------------------------------------------------
#endif
