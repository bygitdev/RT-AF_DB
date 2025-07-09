//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GrayFormCDBoxScrn.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGrayFrmCDBOX *GrayFrmCDBOX;
//---------------------------------------------------------------------------
__fastcall TGrayFrmCDBOX::TGrayFrmCDBOX(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TGrayFrmCDBOX::FormCreate(TObject *Sender)
{
	AlphaBlend = true;
	AlphaBlendValue = 220;
	BorderStyle = TFormBorderStyle::bsNone;
}
//---------------------------------------------------------------------------
void __fastcall TGrayFrmCDBOX::Display()
{
	Left=Application->MainForm->Left;
	Top=Application->MainForm->Top;
	Width=Application->MainForm->Width;
	Height=Application->MainForm->Height;
	Show();
}
//---------------------------------------------------------------------------
