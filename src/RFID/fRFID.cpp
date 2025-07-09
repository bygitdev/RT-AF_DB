//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fRFID.h"
#include "MainFormScrn.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmRFID *frmRFID;
//---------------------------------------------------------------------------

__fastcall TfrmRFID::TfrmRFID(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TfrmRFID::FormCreate(TObject *Sender)
{
	rgChannel->ItemIndex = 0;
}
//---------------------------------------------------------------------------
void __fastcall TfrmRFID::btnReadClick(TObject *Sender)
{
	int iCh = rgChannel->ItemIndex;

	{
		if (false == g_rfid->read(iCh))
		{
			AddCommLog("Fail to read !", 1);
		}
		else
		{
			if (!Timer1->Enabled)
			{
				Timer1->Tag = 0;
				Timer1->Enabled = true;
			}
		}
	}

}
//---------------------------------------------------------------------------

void __fastcall TfrmRFID::btnWriteClick(TObject *Sender)
{
	int iCh = rgChannel->ItemIndex;

	{
		if (FALSE == g_rfid->write(iCh,EditStep->Text,EditLotID->Text,EditPartNO->Text,EditQty->Text,false))
		{
			AddCommLog("Fail to write !", 1);
		}
		else
		{
			if (!Timer2->Enabled)
			{
				Timer2->Tag = 0;
				Timer2->Enabled = true;
			}
		}
	}

}
//---------------------------------------------------------------------------
void __fastcall TfrmRFID::CommClear()
{
	Timer1->Enabled = false;
	Timer2->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmRFID::Timer1Timer(TObject *Sender)
{
	Timer1->Tag =  Timer1->Tag +1;
	int ticCnt = Timer1->Tag;

	{
		if (!g_rfid->isRecv())
		{
			if(ticCnt > 4*5)//4sec
			{
				AddCommLog("RFID read timeover : "+ IntToStr(ticCnt*100) + "ms", 1);
				AddCommLog("Tying to read but timeout", 1);
				Timer1->Enabled = false;
				return;
			}
			return;
		}
	}

	Timer1->Enabled = false;

	RFID_DATA	data;

	{
		data = g_rfid->get_data();
	}


	EditCarrierID->Text = data.carrierID;
	EditQty->Text 		= data.qty;
	EditLotID->Text 	= data.lotID;
	EditStep->Text 		= data.step;
	EditPartNO->Text 	= data.partNo;

	AddCommLog("RFID Read Carrier ID : " + data.carrierID, 1);
	AddCommLog("RFID Read Qty        : " + data.qty, 1);
	AddCommLog("RFID Read Lot ID     : " + data.lotID, 1);
	AddCommLog("RFID Read Step       : " + data.step, 1);
	AddCommLog("RFID Read Part No    : " + data.partNo, 1);
}
//---------------------------------------------------------------------------
void __fastcall TfrmRFID::Timer2Timer(TObject *Sender)
{
	Timer2->Tag =  Timer2->Tag + 1;
	int ticCnt = Timer2->Tag;

	if (!g_rfid->isWrite())
	{
		if(ticCnt > 5*5)//4sec
		{
			AddCommLog("RFID write timeover : "+ IntToStr(ticCnt*100) + "ms", 1);
			AddCommLog("Tying to write but timeout", 1);
			Timer2->Enabled = false;
			return;
		}
		return;
	}

	Timer2->Enabled = false;

	AddCommLog("RFID Manual Write Qty	   : " + EditQty->Text);
	AddCommLog("RFID Manual Write Lot ID   : " + EditLotID->Text);
	AddCommLog("RFID Manual Write Step     : " + EditStep->Text);
	AddCommLog("RFID Manual Write Part No  : " + EditPartNO->Text);
}
//---------------------------------------------------------------------------
void __fastcall TfrmRFID::AddCommLog(String sLog, int iType)
{
	switch(iType)
	{
		case 0:
			MemoLog->Lines->Add(sLog);
			MainForm->MachineHistoryData(sLog);
			break;
		case 1:
			MemoLog->Lines->Add(sLog);
			break;

		default:
			MemoLog->Lines->Add(sLog);
			MainForm->MachineHistoryData(sLog);
			break;

	}

	if(MemoLog->Lines->Count > 100)
	{
		MemoLog->Clear();
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmRFID::btnClearClick(TObject *Sender)
{
	MemoLog->Clear();
}
//---------------------------------------------------------------------------
