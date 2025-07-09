//---------------------------------------------------------------------------

#ifndef FrmLotCommScrnH
#define FrmLotCommScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "CurvyControls.hpp"
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFrmLotComm : public TForm
{
__published:	// IDE-managed Components
	TCurvyPanel *CurvyPanel1;
	TLabel *Label1;
	TSpeedButton *BtnSaveLog;
	TMemo *LotMemo;
	TBitBtn *BtnClose;
	TPanel *Panel1;
	TButton *BtnBcdOn;
	TPanel *Panel2;
	TButton *BtnRfidOn;
	TLabel *Label2;
	TButton *BtnBcdOff;
	TLabel *Label3;
	TButton *BtnRfidOff;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TEdit *edtMagazineID;
	TEdit *edtLotID;
	TEdit *edtStepID;
	TEdit *edtPackageID;
	TEdit *edtFrameCount;
	TEdit *edtPartNo;
	void __fastcall BtnCloseClick(TObject *Sender);
	void __fastcall BtnBcdOnClick(TObject *Sender);
	void __fastcall BtnBcdOffClick(TObject *Sender);
	void __fastcall BtnRfidOnClick(TObject *Sender);
	void __fastcall BtnRfidOffClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFrmLotComm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmLotComm *FrmLotComm;
//---------------------------------------------------------------------------
#endif
