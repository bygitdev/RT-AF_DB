//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FrmVisionOffsetTeachingScrn.h"
#include "BaseComm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma resource "*.dfm"
TFrmVisionOffsetTeaching *FrmVisionOffsetTeaching;

#define  _TEACHING_COMMAND_VALUE_              400
#define  _EMG_COMMAND_VALUE_                   401
#define  _NEXT_COMMAND_VALUE_                  402
#define  _TEACHING_STEP_COUNT_                   12

//---------------------------------------------------------------------------
__fastcall TFrmVisionOffsetTeaching::TFrmVisionOffsetTeaching(TComponent* Owner)
	: TForm(Owner)
{
	_bDataSave = false;
}
//---------------------------------------------------------------------------
void __fastcall TFrmVisionOffsetTeaching::FormShow(TObject *Sender)
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

void __fastcall TFrmVisionOffsetTeaching::BtnTeachStart1Click(TObject *Sender)
{
	if(_nEmgValue != 1)
	{
        PageCtrlTeaching->ActivePageIndex = 1;
		PageCtrlTeaching->OnChange(this);
        _nStageSelectIndex = dynamic_cast<TBitBtn *>(Sender)->Tag;
	}
}
//---------------------------------------------------------------------------
void TFrmVisionOffsetTeaching::BtncheckStatus(bool bValue)
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

void __fastcall TFrmVisionOffsetTeaching::BtnStep1Click(TObject *Sender)
{
	_nStepSelectIndex =   (_nStageSelectIndex*10) +  dynamic_cast<TBitBtn *>(Sender)->Tag;
	nWriteCommunicationDM(_nStepSelectIndex ,  _TEACHING_COMMAND_VALUE_);

	if(dynamic_cast<TBitBtn *>(Sender)->Tag == 1008)
		_bDataSave = true;
}
//---------------------------------------------------------------------------

void __fastcall TFrmVisionOffsetTeaching::BtnTeachNext2Click(TObject *Sender)
{
	if(_nEmgValue != 1)
	{
        PageCtrlTeaching->ActivePageIndex = 2;
		PageCtrlTeaching->OnChange(this);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmVisionOffsetTeaching::BtnTeachNext3Click(TObject *Sender)
{
	if(_nEmgValue != 1)
	{
        PageCtrlTeaching->ActivePageIndex = 3;
		PageCtrlTeaching->OnChange(this);
	}
}
//---------------------------------------------------------------------------


void __fastcall TFrmVisionOffsetTeaching::FeedbackTimerTimer(TObject *Sender)
{
	_nEmgValue =  nReadCommunicationDM(_EMG_COMMAND_VALUE_);

	if( _nEmgValue == 1)
	{
        PanelEmg->Color = clRed;
        PanelEmg->Caption = "EMG STATUS!";
		if(PageCtrlTeaching->ActivePageIndex != 0)
		{
          //  MessageDlg("TEACHING 과정에서 잘못된 Process 가 수행되어 초기화 됩니다!\n처음부터 진행하여주십시요!", mtError, TMsgDlgButtons() << mbOK, 0);
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
	if(PanelNextStep9->Color == clLime || _bDataSave == true)
	{
		_bDataSave = false;
		this->VisionDataIniSave();
	}
}
//---------------------------------------------------------------------------



void __fastcall TFrmVisionOffsetTeaching::BtnTeachNext4Click(TObject *Sender)
{
	this->PkgDataIniSave();
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFrmVisionOffsetTeaching::PageCtrlTeachingChange(TObject *Sender)
{
	LabelActiveCaption->Caption = "VISION OFFSET  TEACHING :  " + IntToStr(PageCtrlTeaching->ActivePageIndex +1 ) + " / 4" ;
}
//---------------------------------------------------------------------------

void   TFrmVisionOffsetTeaching::PkgDataIniSave()
{
	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_PKG;
	g_MMIComm->m_mmiToSeq.buffer.pkg.nStart = 0;
	g_MMIComm->m_mmiToSeq.buffer.pkg.nEnd = 999;
	BOOL bRet = g_MMIComm->Send() && g_MMIComm->Recv();
	if (!bRet)
		return;

	double dPkgValue[12];
	for(int i=0; i<12; i++)
	{
		dPkgValue[i] = g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[500 + i];
	}

	for(int i=0; i<12; i++)
	{
		WriteFloatPkgParamInifile(dPkgValue[i],  500 + i);
	}
}
//---------------------------------------------------------------------------

void   TFrmVisionOffsetTeaching::VisionDataIniSave()
{
	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_PKG;
	g_MMIComm->m_mmiToSeq.buffer.pkg.nStart = 0;
	g_MMIComm->m_mmiToSeq.buffer.pkg.nEnd = 999;
	BOOL bRet = g_MMIComm->Send() && g_MMIComm->Recv();
	if (!bRet)
		return;

	double dPkgValue[12];
	for(int i=0; i<12; i++)
	{
		dPkgValue[i] = g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[520 + i];
	}

	for(int i=0; i<12; i++)
	{
		WriteFloatPkgParamInifile(dPkgValue[i],  520 + i);
	}
}
//---------------------------------------------------------------------------
