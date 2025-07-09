//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FrmCleanScreenScrn.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrmCleanScreen *FrmCleanScreen;
//---------------------------------------------------------------------------
__fastcall TFrmCleanScreen::TFrmCleanScreen(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFrmCleanScreen::FormShow(TObject *Sender)
{
	CleanTimer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TFrmCleanScreen::CleanTimerTimer(TObject *Sender)
{
	if(nEstTime >= 30)
    {
    	CleanTimer->Enabled = false;
        nEstTime = 0;
        Close();
    }
    else
    {
		nEstTime++;
        LabelRemainSec->Caption = IntToStr(30-nEstTime);
    }
}
//---------------------------------------------------------------------------
