//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AxisSelectFormScrn.h"
#include "FrmMotorControlScrn.h"
#include "BaseComm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAxisSelectForm *AxisSelectForm;
//---------------------------------------------------------------------------
__fastcall TAxisSelectForm::TAxisSelectForm(TComponent* Owner)
	: TForm(Owner)

{

}
//---------------------------------------------------------------------------
void  TAxisSelectForm::MtrAxisName_ReadName(int nAxis)
{
	TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\MotorName.ini");
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\MotorName.ini"))
	{
    	String strBitmapUnique	= ExtractFilePath(Application->ExeName)+ "resource\\unique.bmp";
		TBitBtn* CloneAxisBtn = (TBitBtn*)FindComponent("BtnAxis" + IntToStr(nAxis));

        CloneAxisBtn->Glyph->LoadFromFile(strBitmapUnique);

		String StrRet = ini->ReadString("AXISNAME","AXIS"+IntToStr(nAxis),"AXISNAME"+IntToStr(nAxis));
		CloneAxisBtn->Caption = IntToStr(nAxis+1)+ " : " + StrRet;
	}
	delete ini;
}
//------------------------------------------------------------------------

void __fastcall TAxisSelectForm::AxisSelectCloseClick(TObject *Sender)
{
   ((TFrmMotorControl*)m_pMtrAxisForm)->Motorscreen_Initialize(_nAttemptAxis);
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TAxisSelectForm::FormShow(TObject *Sender)
{
	for( int nAxisIndex = 0; nAxisIndex < MAX_MT_NO; nAxisIndex++ )
	{
		MtrAxisName_ReadName(nAxisIndex);
	}
}
//---------------------------------------------------------------------------
void TAxisSelectForm::AxisSelect_Initialize( TForm* pParent)
{
	m_pMtrAxisForm = pParent;

	for( int nAxisIndex = 0; nAxisIndex < MAX_MT_NO; nAxisIndex++ )
	{
		MtrAxisName_ReadName(nAxisIndex);
	}

    AxisSelectForm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TAxisSelectForm::BtnAxis0Click(TObject *Sender)
{
	int nAxis = dynamic_cast<TBitBtn *>(Sender)->Tag;

	TBitBtn* CloneAxisBtn = (TBitBtn*)FindComponent("BtnAxis" + IntToStr(nAxis));

	PanelSelectAxis->Caption = CloneAxisBtn->Caption;

	_nAttemptAxis = nAxis;

    if(CheckBoxSelectGo->Checked == true)
    {
    	AxisSelectClose->OnClick(this);
    }
}
//---------------------------------------------------------------------------

