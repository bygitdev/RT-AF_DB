//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fadctype.h"
#include "BaseComm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmJobType *frmJobType;

#define MAX_JOBTYPE_CNT	100

//---------------------------------------------------------------------------
__fastcall TfrmJobType::TfrmJobType(TComponent* Owner, int ndmIndex)
	: TForm(Owner)
{
	_ndmIndex = ndmIndex;
    _iniFileName = ExtractFilePath(Application->ExeName) + "\\adc.ini";
}
//---------------------------------------------------------------------------


void __fastcall TfrmJobType::FormCreate(TObject *Sender)
{
	StringGrid1->RowCount = MAX_JOBTYPE_CNT + 1;

	StringGrid1->Cells[0][0] = "INDEX";
	StringGrid1->Cells[1][0] = "NAME";
	StringGrid1->Cells[2][0] = "BARCODE";

	TIniFile* ini = new TIniFile(_iniFileName);

	for(int i=0; i< MAX_JOBTYPE_CNT; i++)
	{
		StringGrid1->Cells[0][i+1] = IntToStr(i+1);
		StringGrid1->Cells[1][i+1] = ini->ReadString("ADC","NAME"+IntToStr(i+1),"");
		StringGrid1->Cells[2][i+1] = ini->ReadString("ADC","BARCODE"+IntToStr(i+1),"");
	}
	delete ini;

    int jobTypeNum = nReadCommunicationDM(_ndmIndex);
    PanelIndex->Caption = IntToStr(jobTypeNum);
	PanelName->Caption = this->getTypeName(jobTypeNum);
}
//---------------------------------------------------------------------------
String	TfrmJobType::getTypeName(int index)
{
	TIniFile* ini = new TIniFile(_iniFileName);
	String name = ini->ReadString("ADC","NAME"+IntToStr(index),"");
	delete ini;

	return name;
}
//---------------------------------------------------------------------------


void __fastcall TfrmJobType::StringGrid1SelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect)
{
	if(ARow > 0)
    {
        PanelIndex->Caption = IntToStr(ARow);
        PanelName->Caption = this->getTypeName(ARow);
    }
}
//---------------------------------------------------------------------------


void __fastcall TfrmJobType::SpeedButton4Click(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

    nWriteCommunicationDM(PanelIndex->Caption.ToInt(),_ndmIndex);
    this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmJobType::SpeedButtonInputClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

    StringGrid1->Options << goEditing;
    SpeedButtonSave->Enabled = true;
    SpeedButtonInput->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TfrmJobType::SpeedButtonSaveClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	TIniFile* ini = new TIniFile(_iniFileName);

    for(int i=0; i< MAX_JOBTYPE_CNT; i++)
	{
		ini->WriteString("ADC", "NAME"+IntToStr(i+1),StringGrid1->Cells[1][i+1] );
		ini->WriteString("ADC", "BARCODE"+IntToStr(i+1),StringGrid1->Cells[2][i+1] );
    }
    delete ini;


    StringGrid1->Options >> goEditing;
    SpeedButtonSave->Enabled = false;
    SpeedButtonInput->Enabled = true;
}
//---------------------------------------------------------------------------

