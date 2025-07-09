//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fpopmenu.h"
#include "cdbox.h"
#include "WarningScrn.h"
#include "MainFormScrn.h"
#include "VisionSetUpScrn.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma resource "*.dfm"
TFrmPopMenu *FrmPopMenu;
//---------------------------------------------------------------------------
__fastcall TFrmPopMenu::TFrmPopMenu(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFrmPopMenu::ButtonScreenLockClick(TObject *Sender)
{
	FrmWarning->BringToFront();
	FrmWarning->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TFrmPopMenu::ButtonMMICloseClick(TObject *Sender)
{
	FrmCdBox->setFlag(CD_YESNO);
    FrmCdBox->setTitle("CLOSE");
    FrmCdBox->setText("Do you want to exit MMI program ?");
    if( mrYes == FrmCdBox->ShowModal())
	{
		MainForm->Savingrunningtime(true);
		FrmVisionSetUp->VisionClosingProcess();

		Application->Terminate();
        Close();
	}
}
//---------------------------------------------------------------------------
