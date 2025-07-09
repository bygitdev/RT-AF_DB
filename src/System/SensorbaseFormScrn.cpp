//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SensorbaseFormScrn.h"
#include "FrmSensorPartScrn.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSensorbaseForm *SensorbaseForm;
//---------------------------------------------------------------------------
__fastcall TSensorbaseForm::TSensorbaseForm(TComponent* Owner)
	: TForm(Owner)
{
    for(int i = 0; i < 8; i++)
    {
        TPanel *SubClonePanel = (TPanel *)FindComponent("PanelSensorPart"+IntToStr(i+1));

	   	pSensorFrm[i] = new TFrmSensorPart(SubClonePanel);
        pSensorFrm[i]->Parent = SubClonePanel;
        pSensorFrm[i]->Align = alClient;
        pSensorFrm[i]->Visible=true;
    	((TFrmSensorPart*)pSensorFrm[i])->SensorScreenInitialize(i);
    }
}
//---------------------------------------------------------------------------

void __fastcall TSensorbaseForm::FormDestroy(TObject *Sender)
{
    for(int i = 0; i < 8; i++)
    {
        if(pSensorFrm[i])
        {
            delete pSensorFrm[i];
            pSensorFrm[i] = NULL;
        }
    }
}
//---------------------------------------------------------------------------

