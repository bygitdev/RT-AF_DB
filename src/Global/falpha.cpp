//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "falpha.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrmApha *FrmApha;
//---------------------------------------------------------------------------
__fastcall TFrmApha::TFrmApha(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFrmApha::FormCreate(TObject *Sender)
{
	AlphaBlend = true;
	AlphaBlendValue = 220;
	BorderStyle = TFormBorderStyle::bsNone;

	Left=Application->MainForm->Left;
	Top=Application->MainForm->Top;
	Width=Application->MainForm->Width;
	Height=Application->MainForm->Height;
}
//---------------------------------------------------------------------------
//void TFrmApha::AlphaShowModal(TForm* form)
//{
//	this->Show();
//	this->ModalResult = form->ShowModal();
//	this->Close();
//}
//---------------------------------------------------------------------------
TModalResult TFrmApha::AlphaShowModal(TForm* form)
{
	TModalResult mr;
	this->Show();
	mr = form->ShowModal();
    this->ModalResult = mr;
	this->Close();
    return mr;
}
