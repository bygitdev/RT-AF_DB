//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormNumberKeyPadScrn.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "iComponent"
#pragma link "iCustomComponent"
#pragma link "iPhonePad"
#pragma link "iVCLComponent"
#pragma link "iKeyBoard"
#pragma resource "*.dfm"
TFormNumberKeyPad *FormNumberKeyPad;

#define   _NUMBERDIGIT_                   3
//---------------------------------------------------------------------------
__fastcall TFormNumberKeyPad::TFormNumberKeyPad(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
String TFormNumberKeyPad::GetKeyNumber()
{
    return EditNumberData->Text.Trim();
}
//---------------------------------------------------------------------------
void __fastcall TFormNumberKeyPad::BtnNumberkeyPad1Click(TObject *Sender)
{
	int nNumber = dynamic_cast<TButton *>(Sender)->Tag;
    if( EditNumberData->Text.Length() < _NUMBERDIGIT_)
    {
    	EditNumberData->Text = EditNumberData->Text  + IntToStr(nNumber);
    }
    else
    {
    	EditNumberData->Text = EditNumberData->Text  + IntToStr(nNumber);
		EditNumberData->Text = EditNumberData->Text.SubString(2,_NUMBERDIGIT_);

    }
}
//---------------------------------------------------------------------------

void __fastcall TFormNumberKeyPad::BtnNumberkeyPadEnterClick(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormNumberKeyPad::BtnNumberkeyPadBKClick(TObject *Sender)
{
	EditNumberData->Text = EditNumberData->Text.SetLength(EditNumberData->Text.Length()-1);
}
//---------------------------------------------------------------------------

void __fastcall TFormNumberKeyPad::FormShow(TObject *Sender)
{
	EditNumberData->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TFormNumberKeyPad::EditNumberDataDblClick(TObject *Sender)
{
	EditNumberData->Text = "";
}
//---------------------------------------------------------------------------

