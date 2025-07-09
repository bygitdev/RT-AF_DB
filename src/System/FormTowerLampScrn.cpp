//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormTowerLampScrn.h"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include "BaseComm.h"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma resource "*.dfm"
TFormTowerLamp *FormTowerLamp;
//---------------------------------------------------------------------------
__fastcall TFormTowerLamp::TFormTowerLamp(TComponent* Owner)
	: TForm(Owner)
{
	TowerLampGrid->Cells[0][0] = "STATUS";
    TowerLampGrid->Cells[1][0] = "RED LAMP";
    TowerLampGrid->Cells[2][0] = "YELLOW LAMP";
    TowerLampGrid->Cells[3][0] = "GREEN LAMP";
    TowerLampGrid->Cells[4][0] = "BUZZER ON/OFF";

    TowerLampGrid->Cells[0][1] = "AUTO RUN";
    TowerLampGrid->Cells[0][2] = "ERROR";
    TowerLampGrid->Cells[0][3] = "ALARM";
    TowerLampGrid->Cells[0][4] = "EMPTY FULL";
    TowerLampGrid->Cells[0][5] = "STOP";
    TowerLampGrid->Cells[0][6] = "UTIL DOWN";
	TowerLampGrid->Cells[0][7] = "OHT&SAFY_AREA";
}
//---------------------------------------------------------------------------
void TFormTowerLamp::TowerLamp_Initialize()
{

	this->TowerLampRefreshStatus();
}

//---------------------------------------------------------------------------

void TFormTowerLamp::TowerLampRefreshStatus()
{
    g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_NDM;
    g_MMIComm->m_mmiToSeq.buffer.ndm.nStart = towerLampR1;
    g_MMIComm->m_mmiToSeq.buffer.ndm.nEnd = buzzerOffTime;
    BOOL bRet = g_MMIComm->Send() && g_MMIComm->Recv();
    if (!bRet)
    	return;

    if ( 1 == g_MMIComm->m_mmiToSeq.buffer.ndm.nVal[ buzzerSkip ])
    {
		PanelBuzzerLed->Color = clLime;
        PanelBuzzerLed->Caption = "ON";
    }
    else
    {
		PanelBuzzerLed->Color = clBtnFace;
        PanelBuzzerLed->Caption = "OFF";
    }

    EditBuzzerTime->Text = g_MMIComm->m_mmiToSeq.buffer.ndm.nVal[ buzzerOffTime ];

    for (int i=0; i< 7; i++)
    {
    	((TComboBox*)this->FindComponent("ComboBoxR"+ IntToStr(i+1)))->ItemIndex = \
        	g_MMIComm->m_mmiToSeq.buffer.ndm.nVal[ towerLampR1 + 4*i];
    	((TComboBox*)this->FindComponent("ComboBoxY"+ IntToStr(i+1)))->ItemIndex = \
        	g_MMIComm->m_mmiToSeq.buffer.ndm.nVal[ towerLampY1 + 4*i];
		((TComboBox*)this->FindComponent("ComboBoxG"+ IntToStr(i+1)))->ItemIndex = \
        	g_MMIComm->m_mmiToSeq.buffer.ndm.nVal[ towerLampG1 + 4*i];
		((TComboBox*)this->FindComponent("ComboBoxBuzzer"+ IntToStr(i+1)))->ItemIndex = \
        	g_MMIComm->m_mmiToSeq.buffer.ndm.nVal[ buzzer1 + 4*i];
    }

}
//---------------------------------------------------------------------------

void __fastcall TFormTowerLamp::BtnBuzzerSWClick(TObject *Sender)
{
    if ( 1 == nReadCommunicationDM( buzzerSkip))
        nWriteCommunicationDM( 0, buzzerSkip);
    else
    	nWriteCommunicationDM( 1, buzzerSkip);

}
//---------------------------------------------------------------------------
void __fastcall TFormTowerLamp::BtnBuzzerTimerClick(TObject *Sender)
{
	if(EditBuzzerTime->Text == "")
    {
        EditBuzzerTime->Text = "0";
    }
    nWriteCommunicationDM(EditBuzzerTime->Text.ToInt(), buzzerOffTime);
}
//---------------------------------------------------------------------------
void __fastcall TFormTowerLamp::FormShow(TObject *Sender)
{
//	this->TowerLamp_Initialize();	//
}
//---------------------------------------------------------------------------


void __fastcall TFormTowerLamp::ComboBoxR1Change(TObject *Sender)
{
    int ndm = ((TComboBox*)(Sender))->Tag;
    int value = ((TComboBox*)(Sender))->ItemIndex;
    nWriteCommunicationDM( value, ndm );
}
//---------------------------------------------------------------------------

