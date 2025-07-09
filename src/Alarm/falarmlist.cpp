//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "falarmlist.h"
#include <System.StrUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmAlarmList *frmAlarmList;
//---------------------------------------------------------------------------
__fastcall TfrmAlarmList::TfrmAlarmList(TComponent* Owner)
	: TForm(Owner)
{
	_pCurIni = NULL;
	_IniAlarm = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Alarm.ini");
	_IniWarning = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Warning.ini");
}
//---------------------------------------------------------------------------
void __fastcall TfrmAlarmList::FormDestroy(TObject *Sender)
{
	delete _IniAlarm;
	delete _IniWarning;
}
//---------------------------------------------------------------------------
void __fastcall TfrmAlarmList::FormCreate(TObject *Sender)
{
	StringGridList->Cells[0][0] = "No.";
	StringGridList->Cells[1][0] = "Name";

	for(int i=0; i < StringGridList->RowCount-1;i++)
	{
		StringGridList->Cells[0][i+1] = IntToStr(i);
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmAlarmList::FormShow(TObject *Sender)
{
	this->regen();
	this->select(0);
}
//---------------------------------------------------------------------------
void TfrmAlarmList::regen()
{
	if(PanelCategory->Caption == "ALARM LIST")
	{
		_pCurIni = _IniAlarm;
	}
	else
	{
		_pCurIni = _IniWarning;
	}

	for(int i=0; i<StringGridList->RowCount+1; i++)
	{
		StringGridList->Cells[1][i+1] = _pCurIni->ReadString("NAME","NAME"+IntToStr(i),"");
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmAlarmList::ButtonSwitchClick(TObject *Sender)
{
	TBitBtn* btn = dynamic_cast<TBitBtn*>(Sender);
	if(NULL == btn) return;

	//
	if(btn->Caption == "ALARM LIST")
	{
		PanelCategory->Caption = "ALARM LIST";
		ButtonWarning->Enabled = true;
		ButtonAlarm->Enabled = false;
		CheckBoxAlarm->Visible = true;
	}

	if(btn->Caption == "WARNING LIST")
	{
		PanelCategory->Caption = "WARNING LIST";
		ButtonWarning->Enabled = false;
		ButtonAlarm->Enabled = true;
		CheckBoxAlarm->Visible = false;
	}

	this->regen();
	this->select(StringGridList->Row-1);
}
//---------------------------------------------------------------------------
void    TfrmAlarmList::select(int index)
{
	EditTitle->Text = _pCurIni->ReadString("NAME","NAME"+IntToStr(index),"NAME");
	PanelIndex->Caption = IntToStr(index);
	RichEditSolution->Clear();
	String sol = _pCurIni->ReadString("SOLUTION","Sol"+IntToStr(index),"SOLUTION");
	RichEditSolution->SelText = ReplaceTextW(sol,"\\r\\n","\r\n");

	if(PanelCategory->Caption == "ALARM LIST")
	{
		CheckBoxAlarm->Checked =  _pCurIni->ReadBool("CHECK","CHECK"+IntToStr(index),false);
	}
}
//---------------------------------------------------------------------------


void __fastcall TfrmAlarmList::ButtonEditClick(TObject *Sender)
{
	ButtonSave->Enabled = true;
	ButtonEdit->Enabled = false;
	EditTitle->ReadOnly = false;
	RichEditSolution->ReadOnly = false;
}
//---------------------------------------------------------------------------

void __fastcall TfrmAlarmList::ButtonSaveClick(TObject *Sender)
{
	ButtonSave->Enabled = false;
	ButtonEdit->Enabled = true;
	EditTitle->ReadOnly = true;
	RichEditSolution->ReadOnly = true;

	int index = PanelIndex->Caption.ToInt();
	_pCurIni->WriteString("NAME","NAME"+PanelIndex->Caption,EditTitle->Text);
	String solStr = RichEditSolution->Text;
	_pCurIni->WriteString("SOLUTION","Sol"+PanelIndex->Caption,ReplaceTextW(solStr,"\r\n","\\r\\n"));

	if(PanelCategory->Caption == "ALARM LIST")
	{
		_pCurIni->WriteBool("CHECK","CHECK"+IntToStr(index),CheckBoxAlarm->Checked);
	}

	this->regen();
}
//---------------------------------------------------------------------------


void __fastcall TfrmAlarmList::StringGridListSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect)
{
	if(ARow > 0)
	{
		this->select(ARow-1);
    }
}
//---------------------------------------------------------------------------



void __fastcall TfrmAlarmList::ButtonPagingClick(TObject *Sender)
{
	TBitBtn* btn = dynamic_cast<TBitBtn*>(Sender);
	if(NULL == btn) return;

	int newRow = -1;

	if(btn->Caption == "¡ã - 100")
	{
		newRow = StringGridList->TopRow - 100;
		if(newRow < 1) newRow = 1;
		StringGridList->TopRow = newRow;
	}
	if(btn->Caption == "¡â - 10")
	{
		newRow = StringGridList->TopRow - 10;
		if(newRow < 1) newRow = 1;
		StringGridList->TopRow = newRow;
	}
	if(btn->Caption == "¡ä + 10")
	{
		newRow = StringGridList->TopRow + 10;
		if(newRow > StringGridList->RowCount) newRow = StringGridList->RowCount-9;
		StringGridList->TopRow = newRow;
	}
	if(btn->Caption == "¡å + 100")
	{
		newRow = StringGridList->TopRow + 100;
		if(newRow > StringGridList->RowCount) newRow = StringGridList->RowCount-9;
		StringGridList->TopRow = newRow;
	}

}
//---------------------------------------------------------------------------

void __fastcall TfrmAlarmList::ButtonGoClick(TObject *Sender)
{
	int index = EditGoTarget->Text.ToInt();

	if(index < 0 || index > StringGridList->RowCount-1) return;

	StringGridList->Row = index+1;
	this->select(index);
}
//---------------------------------------------------------------------------

