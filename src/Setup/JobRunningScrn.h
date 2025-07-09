//---------------------------------------------------------------------------

#ifndef JobRunningScrnH
#define JobRunningScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Graphics.hpp>
#include "CurvyControls.hpp"
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TFrmJobRunning : public TForm
{
__published:	// IDE-managed Components
	TCurvyPanel *CurvyPanel1;
	TPanel *PanelSelectTenkeyName;
	TPanel *PanelSelectTenkeyNo;
	TCurvyPanel *CurvyPanel2;
	TBitBtn *BtnTenkeyLoad1;
	TBitBtn *BtnTenkeyLoad12;
	TBitBtn *BtnTenkeyLoad2;
	TBitBtn *BtnTenkeyLoad3;
	TBitBtn *BtnTenkeyLoad6;
	TBitBtn *BtnTenkeyLoad5;
	TBitBtn *BtnTenkeyLoad4;
	TBitBtn *BtnTenkeyLoad11;
	TBitBtn *BtnTenkeyLoad10;
	TBitBtn *BtnTenkeyLoad9;
	TBitBtn *BtnTenkeyLoad8;
	TBitBtn *TenkeyBtn1;
	TBitBtn *TenkeyBtn2;
	TBitBtn *TenkeyBtn3;
	TBitBtn *TenkeyBtn5;
	TBitBtn *TenkeyBtn4;
	TBitBtn *TenkeyBtn6;
	TBitBtn *TenkeyBtn8;
	TBitBtn *TenkeyBtn7;
	TBitBtn *TenkeyBtn9;
	TBitBtn *TenkeyBtn11;
	TBitBtn *TenkeyBtn10;
	TBitBtn *TenkeyBtn12;
	TBitBtn *TenkeyBtn14;
	TBitBtn *TenkeyBtn13;
	TBitBtn *TenkeyBtn15;
	TBitBtn *TenkeyBtn17;
	TBitBtn *TenkeyBtn16;
	TBitBtn *TenkeyBtn18;
	TBitBtn *TenkeyBtn20;
	TBitBtn *TenkeyBtn19;
	TBitBtn *TenkeyBtn21;
	TBitBtn *TenkeyBtn23;
	TBitBtn *TenkeyBtn22;
	TBitBtn *TenkeyBtn24;
	TBitBtn *TenkeyBtn26;
	TBitBtn *TenkeyBtn25;
	TBitBtn *TenkeyBtn27;
	TBitBtn *BtnTenkeyLoad7;
	TBitBtn *BtnStep;
	TBitBtn *BtnHome;
	TBitBtn *BtnTenkeyLoad13;
	TBitBtn *BtnTenkeyLoad14;
	void __fastcall BtnTenkeyLoad1Click(TObject *Sender);
	void __fastcall TenkeyBtn1Click(TObject *Sender);
	void __fastcall BtnHomeClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);

private:	// User declarations
	int nTenkeyPartNo;
	String	_strTenkeyName[200];

	void __fastcall ParentTenkeyLoad();
    void __fastcall BtnTenkeyLoad(int SelectNo);
	void __fastcall TenkeyEffectProcess(int selectBtn);

public:		// User declarations
	void __fastcall FormInitiaize();
	String	getTenKeyName(int nTenkeyNo);

	__fastcall TFrmJobRunning(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmJobRunning *FrmJobRunning;
//---------------------------------------------------------------------------
#endif
