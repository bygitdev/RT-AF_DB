//---------------------------------------------------------------------------

#ifndef FrmTerminalMsgScrnH
#define FrmTerminalMsgScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "CurvyControls.hpp"
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TFrmTerminalMsg : public TForm
{
__published:	// IDE-managed Components
	TCurvyPanel *CurvyPanel1;
	TLabel *Label1;
	TMemo *MemoFromHost;
	TBitBtn *BtnClose;
	void __fastcall BtnCloseClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFrmTerminalMsg(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmTerminalMsg *FrmTerminalMsg;
//---------------------------------------------------------------------------
#endif
