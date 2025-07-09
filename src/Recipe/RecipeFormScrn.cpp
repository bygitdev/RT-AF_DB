//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RecipeFormScrn.h"
#include "FormPkgParamScrn.h"
#include "RecipeChangeFormScrn.h"
#include "nRcpCreateScrn.h"

#include "BaseComm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TRecipeForm *RecipeForm;



//---------------------------------------------------------------------------
__fastcall TRecipeForm::TRecipeForm(TComponent* Owner)
	: TForm(Owner)
{
	_pCurrentForm = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TRecipeForm::RecipeFrmSub1Click(TObject *Sender)
{
	this->ScreenChange(dynamic_cast<TBitBtn *>(Sender)->Caption);
}
//---------------------------------------------------------------------------
void	TRecipeForm::ScreenChange(String menu)
{
    TForm* target = NULL;

    if(menu == "RECIPE CHANGE")
    {
        target =  RecipeChangeForm;
		RecipeChangeForm->RecipeControl_Initialize();
		RecipeChangeForm->DisplayRMS();
    }

	if(menu == "RECIPE EDIT")
    {
		target = FrmRcpCreate;
		FrmRcpCreate->RecipeCreate_Initialize(nReadGroupNo());
	}
//    if(menu == "STAUBLI")
//    {
//    	target = FrmStaubliControl;
//        FrmStaubliControl->Staubli_Initilize();
//    }

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
			_pCurrentForm->Parent = RecipeBasePanel;
			_pCurrentForm->Align = alClient;
			_pCurrentForm->Show();
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TRecipeForm::FormShow(TObject *Sender)
{
	if(NULL == _pCurrentForm) this->ScreenChange("RECIPE CHANGE");
	else if(RecipeChangeForm == _pCurrentForm)	RecipeChangeForm->DisplayRMS();
}
//---------------------------------------------------------------------------

