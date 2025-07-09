//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CalibrationFormScrn.h"
#include "PickerStatusFormScrn.h"
#include "OffsetFormScrn.h"
#include "TeachingPointFormScrn.h"
#include "AutoCalibrationScrn.h"

#include "BaseComm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCalibrationForm *CalibrationForm;



//---------------------------------------------------------------------------
__fastcall TCalibrationForm::TCalibrationForm(TComponent* Owner)
	: TForm(Owner)
{
	::ZeroMemory(pCalibSubFrm, sizeof(pCalibSubFrm));
}
//---------------------------------------------------------------------------
void  TCalibrationForm::CalibrationButtonDisplay(int nBtnIndex)
{
	for(int i = 0; i < 4; i++)
    {
		TBitBtn *SubCloneBtn = (TBitBtn *)FindComponent("CalibrationFrmSub"+IntToStr(i+1));
        SubCloneBtn->Enabled  = true;
        if( nBtnIndex == i+1)
        {
			 SubCloneBtn->Enabled  = false;
		}
    }

    if(PickerStatusForm)
    {
        delete PickerStatusForm;
        PickerStatusForm = NULL;
    }

    if(OffsetForm)
    {
        delete OffsetForm;
        OffsetForm = NULL;
    }

    if(TeachingPointForm)
    {
        delete TeachingPointForm;
        TeachingPointForm = NULL;
    }

    if(AutoCalibration)
    {
        delete AutoCalibration;
        AutoCalibration = NULL;
    }

	switch(nBtnIndex)
	{
		case FRM_PICKERSTATUS :    //
		{
			pCalibSubFrm[nBtnIndex] = new TPickerStatusForm(CalibBasePanel);
        }
        break;

		case FRM_OFFSET :    //
		{
			pCalibSubFrm[nBtnIndex] = new TOffsetForm(CalibBasePanel);
        }
        break;

        case FRM_4POINT :    //
		{
			pCalibSubFrm[nBtnIndex] = new TTeachingPointForm(CalibBasePanel);
        }
        break;

        case FRM_AUTOCAL :    //
		{
			pCalibSubFrm[nBtnIndex] = new TAutoCalibration(CalibBasePanel);
        }
        break;

    	default :
        {

        }
		break;
	}


    if(pCalibSubFrm[nBtnIndex] != NULL)
    {
        pCalibSubFrm[nBtnIndex]->Parent = CalibBasePanel;
        pCalibSubFrm[nBtnIndex]->Align = alClient;
        pCalibSubFrm[nBtnIndex]->BringToFront();
        pCalibSubFrm[nBtnIndex]->Visible= true;

        switch(nBtnIndex)
        {

            case FRM_PICKERSTATUS :    //
            {
                ((TPickerStatusForm*)pCalibSubFrm[nBtnIndex])->PickerControl_Initialize(1);
            }
            break;

            case FRM_OFFSET :    //
            {
                ((TOffsetForm*)pCalibSubFrm[nBtnIndex])->OffsetData_Initialize(0);
            }
            break;

            case FRM_4POINT :    //
            {
                ((TTeachingPointForm*)pCalibSubFrm[nBtnIndex])->TrayData_Initialize(0);
                ((TTeachingPointForm*)pCalibSubFrm[nBtnIndex])->PalletData_Initialize(0);
            }
            break;

            case FRM_AUTOCAL :    //
            {

            }
            break;

            default :

                break;
        }
    }
    else
    {

    }
}
//---------------------------------------------------------------------------
void __fastcall TCalibrationForm::CalibrationFrmSub1Click(TObject *Sender)
{
	this->CalibrationButtonDisplay(dynamic_cast<TBitBtn *>(Sender)->Tag);
}
//---------------------------------------------------------------------------

