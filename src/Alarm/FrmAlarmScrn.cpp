//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FrmAlarmScrn.h"

//---------------------------------------------------------------------------
#include "BaseComm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma resource "*.dfm"

TFrmAlarm *FrmAlarm;

#define _MAXALARMCNT_      1001

#define _ALARM_PART_      1
#define _WARN_PART_       2
//---------------------------------------------------------------------------
__fastcall TFrmAlarm::TFrmAlarm(TComponent* Owner)
	: TForm(Owner)
{
    for(int i = 0; i < AlarmViewGrid->RowCount; i++)
    {
        AlarmViewGrid->Cells[0][i+1] ="          "+IntToStr(i);
    }

    AlarmViewGrid->Cells[0][0] ="No.";
    AlarmViewGrid->Cells[1][0] ="Name";
    AlarmViewGrid->Cells[2][0] ="Enable";

    AEWini= NULL;

}
//---------------------------------------------------------------------------
void __fastcall TFrmAlarm::BtnAlarm1Click(TObject *Sender)
{
    this->AlarmDataInitialize(dynamic_cast<TBitBtn *>(Sender)->Tag);
    AlarmViewGrid->Refresh();
}
//---------------------------------------------------------------------------

void TFrmAlarm::AlarmDataInitialize(int nErrWarn)
{
	_nErrWarnSelect_ = nErrWarn;

    BtnAlarm1->Enabled = true;
    BtnAlarm2->Enabled = true;

    TBitBtn* CloneChkBtn = (TBitBtn*)FindComponent("BtnAlarm" + IntToStr(_nErrWarnSelect_));
    CloneChkBtn->Enabled = false;

	if( nErrWarn == _ALARM_PART_ )
    {
		if(NULL != AEWini) delete AEWini;
		AEWini = new TIniFile(ExtractFilePath(Application->ExeName)+ "Ini\\Alarm.ini");
		CheckBoxAlarm->Visible = true;
		PanelAlarmBase->Visible = true;
	}
	else  if( nErrWarn == _WARN_PART_ )
	{
    	if(NULL != AEWini) delete AEWini;
    	AEWini = new TIniFile(ExtractFilePath(Application->ExeName)+ "Ini\\Warning.ini");
        CheckBoxAlarm->Visible = false;
        PanelAlarmBase->Visible = false;
    }

    for(int i=0; i<AlarmViewGrid->RowCount+1; i++)
    {
        AlarmViewGrid->Cells[1][i+1] = AEWini->ReadString("NAME","NAME"+IntToStr(i),"NAME"+IntToStr(i));
    }

    ReadAlarmDatas(0);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void  TFrmAlarm::ReadAlarmDatas(int nRecNo)
{
    String StrPartTemp , StrTemp;

    AlarmCodeText->Clear();
    MemoAlarmSolution->Clear();

    PanelAlarmNumber->Caption = IntToStr(nRecNo);
	LabelAlarmcnt->Caption = IntToStr(nRecNo) + "/1000";

    AlarmCodeText->Text = AEWini->ReadString("NAME","NAME"+IntToStr(nRecNo),"NAME"+IntToStr(nRecNo));

    String sol = AEWini->ReadString("SOLUTION","Sol"+IntToStr(nRecNo),"SOL"+IntToStr(nRecNo));
    MemoAlarmSolution->SelText = ReplaceTextW(sol,"\\r\\n","\r\n");

    if( _nErrWarnSelect_ == _ALARM_PART_ )
    {
		 CheckBoxAlarm->Checked =  AEWini->ReadBool("CHECK","CHECK"+IntToStr(nRecNo),true);
    }

    AlarmViewGrid->TopRow = PanelAlarmNumber->Caption.ToInt()+1;
}
//---------------------------------------------------------------------------
String  TFrmAlarm::ReadAlarmNames(int nRecNo)
{
    return AEWini->ReadString("NAME","NAME"+IntToStr(nRecNo),"NAME"+IntToStr(nRecNo));
}
//---------------------------------------------------------------------------
String  TFrmAlarm::ReadAlarmSol(int nRecNo)
{
    return AEWini->ReadString("SOLUTION","Sol"+IntToStr(nRecNo),"SOL"+IntToStr(nRecNo));
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TFrmAlarm::BtnSaveItemClick(TObject *Sender)
{
	String StrQuery;
	if( _nErrWarnSelect_ == _ALARM_PART_ )
    {
		StrQuery = "ALARM";
    }
    else  if( _nErrWarnSelect_ == _WARN_PART_ )
    {
		StrQuery = "WARNING";
    }

    FrmCdBox->setFlag(CD_YESNO);
    FrmCdBox->setTitle("SAVE " + StrQuery + " DATA");
    FrmCdBox->setText("Save the "+ StrQuery +" Data?");
    if( mrYes == FrmCdBox->ShowModal())
    {
        if(AEWini != NULL)
        {
            int nRecordNo = StrToInt(PanelAlarmNumber->Caption);
            AEWini->WriteString("NAME","NAME"+IntToStr(nRecordNo),AlarmCodeText->Text);

            String solStr = MemoAlarmSolution->Text;

            AEWini->WriteString("SOLUTION","Sol"+IntToStr(nRecordNo),ReplaceTextW(solStr,"\r\n","\\r\\n"));

            if( _nErrWarnSelect_ == _ALARM_PART_ )
            {
            	AEWini->WriteBool("CHECK","CHECK"+IntToStr(nRecordNo),CheckBoxAlarm->Checked);
            }
        }
        else
        {
            FrmCdBox->setFlag(CD_OK);
            FrmCdBox->setTitle("FILE ACCESS ERROR" );
            FrmCdBox->setText("Check the FILE ");
            FrmCdBox->ShowModal();
        }
    }

}
//---------------------------------------------------------------------------
void __fastcall TFrmAlarm::BtnDecrease1Click(TObject *Sender)
{
	int nPlusVal = dynamic_cast<TBitBtn *>(Sender)->Tag;

    if(PanelAlarmNumber->Caption.ToInt() >= nPlusVal)
    {
    	ReadAlarmDatas(PanelAlarmNumber->Caption.ToInt() -nPlusVal);
    }
    else
    {
    	ReadAlarmDatas(0);
    }
}
//---------------------------------------------------------------------------
void __fastcall TFrmAlarm::BtnIncrease1Click(TObject *Sender)
{
	int nPlusVal = dynamic_cast<TBitBtn *>(Sender)->Tag;

    if((PanelAlarmNumber->Caption.ToInt() + nPlusVal) >_MAXALARMCNT_)
    {
    	ReadAlarmDatas(999);
    }
    else
    {
    	ReadAlarmDatas(PanelAlarmNumber->Caption.ToInt() +nPlusVal);
    }
}
//---------------------------------------------------------------------------
void __fastcall TFrmAlarm::AlarmViewGridSelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect)
{
    MemoAlarmSolution->Clear();
    if(CanSelect == true && ARow > 0 && AlarmViewGrid->Cells[0][ARow] != "")
    {
        int nSelectCode = AlarmViewGrid->Cells[0][ARow].ToInt();
        AlarmCodeText->Text  = "("+ IntToStr(ARow-1) +")" + " : "+AlarmViewGrid->Cells[1][ARow];

        String sol = AEWini->ReadString("SOLUTION","Sol"+IntToStr(nSelectCode),"SOL"+IntToStr(nSelectCode));
        MemoAlarmSolution->SelText = ReplaceTextW(sol,"\\r\\n","\r\n");

        PanelAlarmNumber->Caption = IntToStr(nSelectCode);
        LabelAlarmcnt->Caption = IntToStr(nSelectCode) + "/1000";

        if( _nErrWarnSelect_ == _ALARM_PART_ )
        {
             CheckBoxAlarm->Checked =  AEWini->ReadBool("CHECK","CHECK"+IntToStr(nSelectCode),true);
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TFrmAlarm::FormDestroy(TObject *Sender)
{
    if(NULL != AEWini) delete AEWini;
    AEWini = NULL;
}
//---------------------------------------------------------------------------

