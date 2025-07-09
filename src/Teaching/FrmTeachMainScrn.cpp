//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FrmTeachMainScrn.h"
#include "StageTeach1Scrn.h"
#include "FrmFlipperCenterTeachScrn.h"
#include "FrmFrontGoodTrayScrn.h"
#include "FrmRearGoodTrayScrn.h"
#include "FrmRejectTrayTeachingScrn.h"
#include "FrmRobotPadTeachingScrn.h"
#include "FrmTrayUnitScrn.h"
#include "FrmVisionOffsetTeachingScrn.h"
#include "FrmStageUnitScrn.h"


#include "BaseComm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma resource "*.dfm"
TFrmTeachMain *FrmTeachMain;
//---------------------------------------------------------------------------
__fastcall TFrmTeachMain::TFrmTeachMain(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFrmTeachMain::BtnCloseClick(TObject *Sender)
{
	nWriteCommunicationDM(0 ,  400);
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFrmTeachMain::BtnTeachBtn1Click(TObject *Sender)
{
	FrmSystemCenterTeaching->ShowModal() ;
}
//---------------------------------------------------------------------------


void __fastcall TFrmTeachMain::BtnTeachBtn2Click(TObject *Sender)
{
	FrmFlipperCenterTeach->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TFrmTeachMain::BtnTeachBtn5Click(TObject *Sender)
{
	FrmTrayUnit->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TFrmTeachMain::BtnTeachBtn7Click(TObject *Sender)
{
	FrmVisionOffsetTeaching->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFrmTeachMain::BtnTeachBtn6Click(TObject *Sender)
{
	FrmStageUnit->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFrmTeachMain::BtnTeachBtn4Click(TObject *Sender)
{
	FrmRobotPadTeaching->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFrmTeachMain::BtnTeachBtn30Click(TObject *Sender)
{
	FrmFrontGoodTray->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFrmTeachMain::BtnTeachBtn31Click(TObject *Sender)
{
	FrmRearGoodTray->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFrmTeachMain::BtnTeachBtn32Click(TObject *Sender)
{
	FrmRejectTrayTeaching->ShowModal();
}
//---------------------------------------------------------------------------

