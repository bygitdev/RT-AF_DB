//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FrmTrayUnitScrn.h"
#include "BaseComm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma resource "*.dfm"
TFrmTrayUnit *FrmTrayUnit;

#define  _TEACHING_COMMAND_VALUE_              400
#define  _EMG_COMMAND_VALUE_                   401
#define  _NEXT_COMMAND_VALUE_                  402
#define  _TEACHING_STEP_COUNT_                   5
#define  _TRAY_BTN_COUNT_                        3

//---------------------------------------------------------------------------
__fastcall TFrmTrayUnit::TFrmTrayUnit(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFrmTrayUnit::FormShow(TObject *Sender)
{
	FeedbackTimer->Enabled = true;
    PageCtrlTeaching->ActivePageIndex = 0;
    PageCtrlTeaching->OnChange(this);

    for (int i= 0; i< _TEACHING_STEP_COUNT_; i++)
    {
        TPanel *ClonePanel = (TPanel *)FindComponent("PanelNextStep"+IntToStr(i +1 ));
        if(ClonePanel != NULL)
        {
            ClonePanel->Color = clGray;
            ClonePanel->Caption = "WAIT STEP!";

        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TFrmTrayUnit::BtnTeachStart1Click(TObject *Sender)
{
	if(_nEmgValue != 1)
	{
        PageCtrlTeaching->ActivePageIndex = 1;
		PageCtrlTeaching->OnChange(this);
        _nStageSelectIndex = dynamic_cast<TBitBtn *>(Sender)->Tag;
	}

	String  StrCaptionName[3];
	StrCaptionName[0] ="REAR GOOD";
	StrCaptionName[1] ="FRONT GOOD";
	StrCaptionName[2] ="REJECT";

	BtnStep1->Caption  = StrCaptionName[_nStageSelectIndex] + " TRANSFER의 안전 조건을 확인 후 SORTING 위치로 이동 합니다";
	BtnStep2->Caption  = StrCaptionName[_nStageSelectIndex] + " TRANSFER에 TRAY 및 UNIT을 안착 시킵니다. (CLAMP TENKEY  : 70 + HOME)";
	BtnStep5->Caption  = StrCaptionName[_nStageSelectIndex] + " TRANSFER의 TEACHING CYCLE을 수행 합니다";

    panE1->Caption = "Check the safety conditions of " + StrCaptionName[_nStageSelectIndex] + " TRANSFER and move to the SORTING position.";
    panE2->Caption = "Place TRAY and UNIT on " + StrCaptionName[_nStageSelectIndex] + " TRANSFER. (CLAMP TENKEY: 70 + HOME)";
    panE5->Caption = "Perform TEACHING CYCLE of " + StrCaptionName[_nStageSelectIndex] + " TRANSFER.";

}
//---------------------------------------------------------------------------
void TFrmTrayUnit::BtncheckStatus(bool bValue)
{
    for (int i= 0; i< _TEACHING_STEP_COUNT_; i++)
    {
        TPanel *ClonePanel = (TPanel *)FindComponent("PanelNextStep"+IntToStr(i +1 ));
        if(ClonePanel != NULL)
        {
            ClonePanel->Enabled = bValue;
        }
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmTrayUnit::BtnStep1Click(TObject *Sender)
{
    _nStepSelectIndex =   (_nStageSelectIndex*10) +  dynamic_cast<TBitBtn *>(Sender)->Tag;
	nWriteCommunicationDM(_nStepSelectIndex ,  _TEACHING_COMMAND_VALUE_);
}
//---------------------------------------------------------------------------

void __fastcall TFrmTrayUnit::BtnTeachNext2Click(TObject *Sender)
{
	if(_nEmgValue != 1)
	{
        PageCtrlTeaching->ActivePageIndex = 2;
		PageCtrlTeaching->OnChange(this);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmTrayUnit::FeedbackTimerTimer(TObject *Sender)
{
	_nEmgValue =  nReadCommunicationDM(_EMG_COMMAND_VALUE_);

	if( _nEmgValue == 1)
	{
        PanelEmg->Color = clRed;
        PanelEmg->Caption = "EMG STATUS!";
		if(PageCtrlTeaching->ActivePageIndex != 0)
		{
         //   MessageDlg("TEACHING 과정에서 잘못된 Process 가 수행되어 초기화 됩니다!\n처음부터 진행하여주십시요!", mtError, TMsgDlgButtons() << mbOK, 0);
            PageCtrlTeaching->ActivePageIndex = 0;
		    PageCtrlTeaching->OnChange(this);
		}
    }
    else
    {
		PanelEmg->Color = clGray;
    	PanelEmg->Caption = "EMG STATUS OFF";
    }


	int nChkValue =  nReadCommunicationDM(_TEACHING_COMMAND_VALUE_);
	int nNextStepValue =  nReadCommunicationDM(_NEXT_COMMAND_VALUE_);

	if( nChkValue == 0)
    {
		BtncheckStatus(true);
	}
	else
	{
		BtncheckStatus(false);
	}

	if(nNextStepValue != 0 )
	{
		int nVal =  nNextStepValue;
        if(nVal ==  _nStepSelectIndex)
        {
            String strChk = IntToStr(_nStepSelectIndex);

            strChk = strChk.SubString(strChk.Length() , strChk.Length());

            int nValue =   strChk.ToInt();

            for (int i= 0; i< _TEACHING_STEP_COUNT_; i++)
            {
                TPanel *ClonePanel = (TPanel *)FindComponent("PanelNextStep"+IntToStr(i +1 ));
                if(ClonePanel != NULL)
                {
                    if( (i) ==  nValue)
                    {
                        ClonePanel->Color = clLime;
                        ClonePanel->Caption = "NEXT STEP!";
                    }
                    else
                    {
                        ClonePanel->Color = clGray;
                        ClonePanel->Caption = "WAIT STEP!";
                    }
                }
            }
        }
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmTrayUnit::BtnTeachNext3Click(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFrmTrayUnit::PageCtrlTeachingChange(TObject *Sender)
{
	LabelActiveCaption->Caption = "TRAY UNIT TEACHING :  " + IntToStr(PageCtrlTeaching->ActivePageIndex +1) + " / 3" ;
}
//---------------------------------------------------------------------------
void TFrmTrayUnit::FormInitiaize(int nTag)
{
    for (int i= 0; i< _TRAY_BTN_COUNT_; i++)
    {
        TBitBtn *pbtn = (TBitBtn *)FindComponent("BtnTeachStart"+IntToStr(i +1 ));
        if(pbtn != NULL)
        {
        	if (nTag == pbtn->Tag )
            {
            	pbtn->Visible = true;
            }
            else
            {
            	pbtn->Visible = false;
            }
        }
    }

    FrmTrayUnit->ShowModal();


}


