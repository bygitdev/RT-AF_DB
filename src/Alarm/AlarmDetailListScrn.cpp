//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AlarmDetailListScrn.h"
#include "MainFormScrn.h"
#include "BaseComm.h"
//---------------------------------------------------------------------------

////---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma link "Shader"
#pragma resource "*.dfm"
TFrmAlarmDetailList *FrmAlarmDetailList;


TIniFile *DetailAlarmini;
TIniFile *DetailWarningini;
//---------------------------------------------------------------------------
__fastcall TFrmAlarmDetailList::TFrmAlarmDetailList(TComponent* Owner)
    : TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TFrmAlarmDetailList::FormShow(TObject *Sender)
{
    DetailAlarmini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Alarm.ini");
    DetailWarningini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Warning.ini");

    AlarmDetailGrid->Cells[0][0] = "No";
    AlarmDetailGrid->Cells[1][0] = "Code";
    AlarmDetailGrid->Cells[2][0] = "Name";
    AlarmDetailGrid->Cells[3][0] = "Enable";

    WarningDetailGrid->Cells[0][0] = "No";
    WarningDetailGrid->Cells[1][0] = "Code";
    WarningDetailGrid->Cells[2][0] = "Name";
    WarningDetailGrid->Cells[3][0] = "Enable";


    for(int i=0; i<AlarmDetailGrid->RowCount; i++)
    {
		AlarmDetailGrid->Cells[0][i+1] = IntToStr(i+1);
		AlarmDetailGrid->Cells[1][i+1] = "";
        AlarmDetailGrid->Cells[2][i+1] = "";

		WarningDetailGrid->Cells[0][i+1] = IntToStr(i+1);
		WarningDetailGrid->Cells[1][i+1] = "";
        WarningDetailGrid->Cells[2][i+1] = "";
	}
    MemoCause->Clear();
    MemoWarnCause->Clear();
    Timer1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TFrmAlarmDetailList::BtnCloseClick(TObject *Sender)
{
	delete DetailAlarmini;
    DetailAlarmini = NULL;
    delete DetailWarningini;
    DetailWarningini = NULL;

    Timer1->Enabled = false;

    Close();
}
//---------------------------------------------------------------------------

void __fastcall TFrmAlarmDetailList::AlarmDetailGridSelectCell(
      TObject *Sender, int ACol, int ARow, bool &CanSelect)
{
    if(CanSelect = true)
    {
        if(AlarmDetailGrid->Cells[1][ARow] != "")
        {
        	nDetailAlarmCode = AlarmDetailGrid->Cells[1][ARow].ToInt();
            MemoCause->Clear();

           String sol = DetailAlarmini->ReadString("SOLUTION","Sol"+IntToStr(nDetailAlarmCode),"SOL"+IntToStr(nDetailAlarmCode));
           MemoCause->Lines->Add(ReplaceTextW(sol,"\\r\\n","\r\n"));

            AlarmDetailGrid->Refresh();
            DetailAlarmEdit->Text = IntToStr(nDetailAlarmCode) +" : "+ AlarmDetailGrid->Cells[2][ARow];
        }

        if(WarningDetailGrid->Cells[1][ARow] != "")
        {
        	nDetailWarningCode = WarningDetailGrid->Cells[1][ARow].ToInt();
			MemoWarnCause->Clear();
            String sol = DetailWarningini->ReadString("SOLUTION","Sol"+IntToStr(nDetailWarningCode),"SOL"+IntToStr(nDetailWarningCode));
            MemoWarnCause->Lines->Add(ReplaceTextW(sol,"\\r\\n","\r\n"));

            WarningDetailGrid->Refresh();
            DetailWarningEdit->Text = IntToStr(nDetailWarningCode) +" : "+ WarningDetailGrid->Cells[2][ARow];
        }

    }
}
//---------------------------------------------------------------------------

void __fastcall TFrmAlarmDetailList::Timer1Timer(TObject *Sender)
{
	int ERRCNT , WRNCNT;
	for( INT i = 0; i < 10; i++ )
	{
		AlarmDetailGrid->Cells[ 1 ][ i + 1 ] = "";
		AlarmDetailGrid->Cells[ 2 ][ i + 1 ] = "";

		WarningDetailGrid->Cells[ 1 ][ i + 1 ] = "";
		WarningDetailGrid->Cells[ 2 ][ i + 1 ] = "";

	}
	ERRCNT = 0;
	WRNCNT = 0;
    g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_ERR_WR;
    if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
    {
        for( INT nIndex = 0; nIndex < 10; nIndex++ )
        {
        	INT nErrCode = g_MMIComm->m_mmiToSeq.buffer.errWr.err[ nIndex ] ;

            if( nErrCode > 0 )
            {
                AlarmDetailGrid->Cells[ 1 ][ ERRCNT + 1 ] = nErrCode;
                String szName = DetailAlarmini->ReadString("NAME","NAME"+IntToStr(nErrCode),"NAME"+IntToStr(nErrCode));
                AlarmDetailGrid->Cells[ 2 ][ ERRCNT + 1 ] = szName;
                ERRCNT++;
            }

        	INT nWrrCode = g_MMIComm->m_mmiToSeq.buffer.errWr.wr[ nIndex ] ;
            if( nWrrCode > 0 )
            {
                WarningDetailGrid->Cells[ 1 ][ WRNCNT + 1 ] = nWrrCode;
                String szName = DetailWarningini->ReadString("NAME","NAME"+IntToStr(nWrrCode),"NAME"+IntToStr(nWrrCode));
                WarningDetailGrid->Cells[ 2 ][ WRNCNT + 1 ] = szName;
                WRNCNT++;
            }

        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TFrmAlarmDetailList::AlarmDetail_Initialize(bool bMode)
{
	if(bMode == true)
    {
		DisplayPageControl->ActivePageIndex = 0;
    }
    else
    {
		DisplayPageControl->ActivePageIndex = 1;
    }
	FrmAlarmDetailList->Show();

	this->Timer1Timer(this);

	if(AlarmDetailGrid->Cells[1][1] != "")
	{
		nDetailAlarmCode = AlarmDetailGrid->Cells[1][1].ToInt();
		MemoCause->Clear();

		String sol = DetailAlarmini->ReadString("SOLUTION","Sol"+IntToStr(nDetailAlarmCode),"SOL"+IntToStr(nDetailAlarmCode));
		MemoCause->Lines->Add(ReplaceTextW(sol,"\\r\\n","\r\n"));

		AlarmDetailGrid->Refresh();
		DetailAlarmEdit->Text = IntToStr(nDetailAlarmCode) +" : "+ AlarmDetailGrid->Cells[2][1];
	}

	if(WarningDetailGrid->Cells[1][1] != "")
	{
		nDetailWarningCode = WarningDetailGrid->Cells[1][1].ToInt();
		MemoWarnCause->Clear();
		String sol = DetailWarningini->ReadString("SOLUTION","Sol"+IntToStr(nDetailWarningCode),"SOL"+IntToStr(nDetailWarningCode));
		MemoWarnCause->Lines->Add(ReplaceTextW(sol,"\\r\\n","\r\n"));

		WarningDetailGrid->Refresh();
		DetailWarningEdit->Text = IntToStr(nDetailWarningCode) +" : "+ WarningDetailGrid->Cells[2][1];
	}
}
//---------------------------------------------------------------------------


