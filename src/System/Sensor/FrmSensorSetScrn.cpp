//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FrmSensorSetScrn.h"
#include "FrmSensorPartScrn.h"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include "BaseComm.h"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma resource "*.dfm"
TFrmSensorSet *FrmSensorSet;
TIniFile *pSensorSetIni;
//--------------------------------------------------------------------------
//---------------------------------------------------------------------------
#define Input_Channel_Cnt    20
#define Output_Channel_Cnt   20
#define _IO_GRID_CNT_        16

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
__fastcall TFrmSensorSet::TFrmSensorSet(TComponent* Owner)
	: TForm(Owner)
{
	m_pSensorForm = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TFrmSensorSet::FrmSensorSet_Initialize(int nPosID, TForm* pParent)
{
	nSetPointIndex = nPosID;
    m_pSensorForm = pParent;
	bool bIOChk;
    pSensorSetIni = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini");
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini"))
	{
    	bIOChk = pSensorSetIni->ReadBool("ChannelSet"+IntToStr(nSetPointIndex),"IOSET",0);
		if(bIOChk == true)
        {

            for(int i=0; i<=Input_Channel_Cnt; i++)
            {
            	LMDComboBoxIndex->Items->Add("InputChannel : " + IntToStr(i));
            }

        	LMDRadioButtonInput->Checked = true;
			LMDRadioButtonOutput->Checked = false;
            IOChIndexLabel->Caption = "Input Channel";
            LMDComboBoxIndex->ItemIndex  = pSensorSetIni->ReadInteger("ChannelSet"+IntToStr(nSetPointIndex),"InputChannel",0);
           // SensorBtnColor->SymbolColor = pSensorSetIni->ReadFloat("ChannelSet"+IntToStr(nSetPointIndex),"InputColor",clGreen);

        }
        else
        {
        	for(int i=0; i<=Output_Channel_Cnt; i++)
    		{
				LMDComboBoxIndex->Items->Add("OutputChannel : " + IntToStr(i));
   	 		}
        	LMDRadioButtonInput->Checked = false;
			LMDRadioButtonOutput->Checked = true;
            IOChIndexLabel->Caption = "Output Channel";
            LMDComboBoxIndex->ItemIndex  = pSensorSetIni->ReadInteger("ChannelSet"+IntToStr(nSetPointIndex),"OutputChannel",1);
           // SensorBtnColor->SymbolColor = pSensorSetIni->ReadFloat("ChannelSet"+IntToStr(nSetPointIndex),"OutputColor",clRed);
        }

    }
    else
    {
    	pSensorSetIni->WriteBool("ChannelSet"+IntToStr(nSetPointIndex),"IOSET",false);
        pSensorSetIni->WriteInteger("ChannelSet"+IntToStr(nSetPointIndex),"InputChannel",0);
        pSensorSetIni->WriteInteger("ChannelSet"+IntToStr(nSetPointIndex),"OutputChannel",1);
        pSensorSetIni->WriteFloat("ChannelSet"+IntToStr(nSetPointIndex),"InputColor",clGreen);
        pSensorSetIni->WriteFloat("ChannelSet"+IntToStr(nSetPointIndex),"OutputColor",clRed);
    }

    this->SensorNamefromDB4Edit(LMDRadioButtonInput->Checked , LMDComboBoxIndex->ItemIndex);

    this->Show();
}
//---------------------------------------------------------------------------
void __fastcall TFrmSensorSet::LMDRadioButtonInputClick(TObject *Sender)
{
	LMDComboBoxIndex->Clear();
    for(int i=0; i<=Input_Channel_Cnt; i++)
    {
        LMDComboBoxIndex->Items->Add("InputChannel : " + IntToStr(i));
    }
    IOChIndexLabel->Caption = "Input Channel";
}
//---------------------------------------------------------------------------

void __fastcall TFrmSensorSet::LMDRadioButtonOutputClick(TObject *Sender)
{
	LMDComboBoxIndex->Clear();
    for(int i=0; i<=Output_Channel_Cnt; i++)
    {
        LMDComboBoxIndex->Items->Add("OutputChannel : " + IntToStr(i));
    }
     IOChIndexLabel->Caption = "Output Channel";
}
//---------------------------------------------------------------------------


void __fastcall TFrmSensorSet::FormClose(TObject *Sender, TCloseAction &Action)
{
	delete pSensorSetIni;
	pSensorSetIni = NULL;

	Action = caFree;
}
//---------------------------------------------------------------------------

void __fastcall TFrmSensorSet::FormShow(TObject *Sender)
{
    SensorNameGrid->Cells[0][0] =  "NO";
	SensorNameGrid->Cells[1][0] =  "NAME";
}
//---------------------------------------------------------------------------
void __fastcall TFrmSensorSet::SensorNamefromDB4Edit(bool bIO , int nChannel)
{

}
//---------------------------------------------------------------------------


void __fastcall TFrmSensorSet::LMDComboBoxIndexSelect(TObject *Sender)
{
	 this->SensorNamefromDB4Edit(LMDRadioButtonInput->Checked , LMDComboBoxIndex->ItemIndex);
}
//---------------------------------------------------------------------------









