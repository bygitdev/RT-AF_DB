//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "frouter.h"
#include "fgerber.h"
#include "fshowdata.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrmRouteScreen *FrmRouteScreen;
//---------------------------------------------------------------------------
__fastcall TFrmRouteScreen::TFrmRouteScreen(TComponent* Owner)
	: TForm(Owner)
{
	_pCurrentForm = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TFrmRouteScreen::FormShow(TObject *Sender)
{
	if(_pCurrentForm == NULL) _pCurrentForm = FrmShowData;
	_pCurrentForm->Parent = PanelMain;
	_pCurrentForm->Align = alClient;
	_pCurrentForm->Show();
}
//---------------------------------------------------------------------------
void __fastcall TFrmRouteScreen::MenuButtonClick(TObject *Sender)
{
	TBitBtn* btn = dynamic_cast<TBitBtn*>(Sender);
	if(NULL == btn) return;

	this->ScreenChange(btn->Caption);
}
//---------------------------------------------------------------------------
void __fastcall TFrmRouteScreen::ScreenChange(String menu)
{
	TForm* target = NULL;

	if(menu == "GERBER")
	{
		target = frmRoute;
	}
	if(menu == "SHOW DATA")
	{
		target = FrmShowData;
	}

	//
	if(NULL != target && _pCurrentForm != target)
	{
		if(NULL != _pCurrentForm)
		{
			_pCurrentForm->Hide();
			_pCurrentForm = NULL;
		}

		_pCurrentForm = target;
		//
		if(NULL != _pCurrentForm)
		{
			_pCurrentForm->Parent = PanelMain;
			_pCurrentForm->Align = alClient;
			_pCurrentForm->Show();
		}
	}
}
void __fastcall TFrmRouteScreen::GridPanel2Click(TObject *Sender)
{
// 	frmRoute->RecipeChange();
}
//---------------------------------------------------------------------------

