//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormHistoryScrn.h"
#include "FormAlarmHistoryScrn.h"
#include "BaseComm.h"
#include "FrmRejectHistoryScrn.h"
#include "fdailyreport.h"
#include "fLotEventHistory.h"
#include "FrmPadChangeHistory.h"
#include "FrmAutoFBHistory.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormHistory *FormHistory;



//---------------------------------------------------------------------------
__fastcall TFormHistory::TFormHistory(TComponent* Owner)
	: TForm(Owner)
{
	_pCurrentForm = NULL;
}
//---------------------------------------------------------------------------
void	TFormHistory::ScreenChange(String menu)
{
    TForm* target = NULL;

    if(menu == "ALARM HISTORY")
    {
    	target = FormAlarmHistory;
    }

    if(menu == "RUN HISTORY")
    {
    	target = FrmDailyReport;
    }

	if(menu == "LOT HISTORY")
    {
		target = frmLotDataHistory;
	}

	if(menu == "REJECT HISTORY")
    {
		target = FrmRejectHistory;
	}

	if(menu == "PAD CHANGE")
	{
		target = FormPadChangeHistory;
	}

	if(menu == "AUTO FEEDBACK")
	{
		target = FormAutoFBHistory;
	}

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
			_pCurrentForm->Parent = HistoryBasePanel;
			_pCurrentForm->Align = alClient;
			_pCurrentForm->Show();
		}
	}
}

//---------------------------------------------------------------------------
void __fastcall TFormHistory::HistoryFrmSub1Click(TObject *Sender)
{
	this->ScreenChange(dynamic_cast<TBitBtn *>(Sender)->Caption);
}
//---------------------------------------------------------------------------

void __fastcall TFormHistory::FormShow(TObject *Sender)
{
    if(NULL == _pCurrentForm) this->ScreenChange("ALARM HISTORY");
}
//---------------------------------------------------------------------------

