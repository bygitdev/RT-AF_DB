//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FrmTerminalMsgScrn.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma resource "*.dfm"
TFrmTerminalMsg *FrmTerminalMsg;
//---------------------------------------------------------------------------
__fastcall TFrmTerminalMsg::TFrmTerminalMsg(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFrmTerminalMsg::BtnCloseClick(TObject *Sender)
{
   this->Close();
}
//---------------------------------------------------------------------------
