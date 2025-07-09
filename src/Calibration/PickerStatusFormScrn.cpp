//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PickerStatusFormScrn.h"
//---------------------------------------------------------------------------
#include "BaseComm.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma resource "*.dfm"
TPickerStatusForm *PickerStatusForm;

#define   _PICKER_STATUS_READ_UNIT_         8
#define   _PICKER_STATUS_UNIT_COUNT_        10

#define   _PICKER1_STATUS_START_INDEX_      500
#define   _PICKER2_STATUS_START_INDEX_      540

#define   _JIG1_STATUS_START_INDEX_      580
#define   _JIG2_STATUS_START_INDEX_      620

#define   _PICKER_ANGLE1_STATUS_START_INDEX_      660
#define   _PICKER_ANGLE2_STATUS_START_INDEX_      700

//---------------------------------------------------------------------------
__fastcall TPickerStatusForm::TPickerStatusForm(TComponent* Owner)
	: TForm(Owner)
{
    Picker1StatusGrid->Cells[0][0] = "NAME";
    Picker1StatusGrid->Cells[1][0] = "VALUE";

    Picker2StatusGrid->Cells[0][0] = "NAME";
    Picker2StatusGrid->Cells[1][0] = "VALUE";

}
//---------------------------------------------------------------------------

void TPickerStatusForm::UniveralPickerUnitStatusRefresh(int nStartIndex , TStringGrid *pGrid)
{
    for(int nGridIndex=0; nGridIndex<pGrid->RowCount; nGridIndex++)
    {
        for(int i=0; i<_PICKER_STATUS_READ_UNIT_; i++)
        {
        //    pGrid->Cells[1][(i+1)+(_PICKER_STATUS_READ_UNIT_*nGridIndex)]= FloatToStr( g_pNvMem->GetDDm( (nStartIndex + i) + (_PICKER_STATUS_UNIT_COUNT_* nGridIndex) ) );
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TPickerStatusForm::BtnPickerPartReadClick(TObject *Sender)
{
	PickerControl_Initialize(dynamic_cast<TBitBtn *>(Sender)->Tag);
}
//---------------------------------------------------------------------------

void TPickerStatusForm::PickerControl_Initialize(int nVal)
{
    BtnPickerPartRead->Enabled = true;
    BtnJigPartRead->Enabled = true;
    BtnPickerAnglePartRead->Enabled = true;

	if(nVal == 1) ///Picker
    {
    	nStartIndex1=  _PICKER1_STATUS_START_INDEX_;
    	nStartIndex2=  _PICKER2_STATUS_START_INDEX_;

    	LabelUnit1->Caption = "PICKER1 STATUS ";
		LabelUnit2->Caption = "PICKER2 STATUS ";

        BtnPickerPartRead->Enabled = false;
    }
	else if(nVal == 2) //Jig
    {
    	nStartIndex1=  _JIG1_STATUS_START_INDEX_;
    	nStartIndex2=  _JIG2_STATUS_START_INDEX_;

        LabelUnit1->Caption = "JIG1 STATUS ";
		LabelUnit2->Caption = "JIG2 STATUS ";

        BtnJigPartRead->Enabled = false;
    }
    else //Pickerangle
    {
    	nStartIndex1=  _PICKER_ANGLE1_STATUS_START_INDEX_;
    	nStartIndex2=  _PICKER_ANGLE2_STATUS_START_INDEX_;

        LabelUnit1->Caption = "PICKER ANGLE 1 STATUS ";
		LabelUnit2->Caption = "PICKER ANGLE 2 STATUS ";

        BtnPickerAnglePartRead->Enabled = false;
    }


    TIniFile *DParamini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\DParam.ini");
    if(DParamini != NULL)
    {
        for(int nGridIndex=0; nGridIndex<Picker1StatusGrid->RowCount; nGridIndex++)
        {
            for(int i=0; i<_PICKER_STATUS_READ_UNIT_; i++)
            {
                int nNumber =  (nStartIndex1 + i) + (_PICKER_STATUS_UNIT_COUNT_* nGridIndex) ;
                Picker1StatusGrid->Cells[0][(i+1)+(_PICKER_STATUS_READ_UNIT_*nGridIndex)] =   DParamini->ReadString("DPARM","NAME"+IntToStr(nNumber),"Name"+IntToStr(nNumber));

                nNumber =  ((nStartIndex2 + i) + (_PICKER_STATUS_UNIT_COUNT_* nGridIndex) ) ;
                Picker2StatusGrid->Cells[0][(i+1)+(_PICKER_STATUS_READ_UNIT_*nGridIndex)] =   DParamini->ReadString("DPARM","NAME"+IntToStr(nNumber),"Name"+IntToStr(nNumber));
            }
        }
    }
	delete DParamini;

    PickerJigTimer->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TPickerStatusForm::PickerJigTimerTimer(TObject *Sender)
{
	UniveralPickerUnitStatusRefresh(nStartIndex1 , Picker1StatusGrid);
    UniveralPickerUnitStatusRefresh(nStartIndex2 , Picker2StatusGrid);

//    EditTolerance1->Text = FloatToStr( g_pNvMem->GetDDm(pkViCenTolerance ));
//    EditTolerance2->Text = FloatToStr( g_pNvMem->GetDDm(pkJigCenTolerance ));
//    EditTolerance3->Text = FloatToStr( g_pNvMem->GetDDm(trayTeachTolerance));
//    EditTolerance4->Text = FloatToStr( g_pNvMem->GetDDm(palletTeachTolerance ));

}
//---------------------------------------------------------------------------
void __fastcall TPickerStatusForm::BtnInputItemClick(TObject *Sender)
{
	EditTolerance1->Enabled = true;
    EditTolerance2->Enabled = true;
    EditTolerance3->Enabled = true;
    EditTolerance4->Enabled = true;

	BtnInputItem->Enabled = false;
    BtnSaveItem->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TPickerStatusForm::BtnSaveItemClick(TObject *Sender)
{
	BtnInputItem->Enabled = true;
    BtnSaveItem->Enabled = false;

	EditTolerance1->Enabled = false;
    EditTolerance2->Enabled = false;
    EditTolerance3->Enabled = false;
    EditTolerance4->Enabled = false;


	if(EditTolerance1->Text != "")
    {
    //	WriteCommDDM(pkViCenTolerance,  StrToFloat( EditTolerance1->Text));
    }

	if(EditTolerance2->Text != "")
    {
    //	WriteCommDDM(pkJigCenTolerance,  StrToFloat( EditTolerance2->Text));
    }

	if(EditTolerance3->Text != "")
    {
    //	WriteCommDDM(trayTeachTolerance,  StrToFloat( EditTolerance3->Text));
    }

	if(EditTolerance4->Text != "")
    {
    //	WriteCommDDM(palletTeachTolerance,  StrToFloat( EditTolerance4->Text));
    }
}
//---------------------------------------------------------------------------


