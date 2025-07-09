//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fECMR.h"
#include "BaseComm.h"
#include "tccomm\ftccomm.h"
#include "MainFormScrn.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvGlowButton"
#pragma resource "*.dfm"
TfrmECMR *frmECMR;
//---------------------------------------------------------------------------
__fastcall TfrmECMR::TfrmECMR(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmECMR::btnCancelClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmECMR::btnOkClick(TObject *Sender)
{
	MainLog("Manual button click. ECMR Empty Tray request start ...");

	/*
		FUNCTION=EMPTY_CARRIER_MOVE_REQ
			EQPID=AROUT-X04
			LOTID=SSD_ETRAY
			PORTID=AROUT-X04_I2
			CARRIERID=
			FRRDERID=
			MATCODE=
			QTY=
			PART_ID=MZVLW128HEGR-000L1-G14 // 메뉴얼 버튼 클릭시 사용자가 입력
			STEP_SEQ=M033 // 메뉴얼 버튼 클릭시 사용자가 입력
			MODE=OHT
	*/
	AnsiString partID = AnsiString(txtPartID->Text).c_str();
	AnsiString stepNo = AnsiString(txtStepNo->Text).c_str();
	AnsiString params[] = {\
		MainForm->_eqpID,
		"SSD_ETRAY",
		MainForm->_ohtInPortID_Empty,
		"",
		"",
		"",
		"",
		partID,
		stepNo,
		"OHT"
	};

	frmTCComm->_manualCmd = true;
	if (!frmTCComm->ohtEmptyCarrierMoveReq(params))
	{
		MainLog("ECMR Empty Tray request fail ...");
		frmTCComm->_manualCmd = false;
	}

	Close();
}
//---------------------------------------------------------------------------
