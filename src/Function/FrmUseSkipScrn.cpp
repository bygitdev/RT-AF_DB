//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FrmUseSkipScrn.h"
#include "BaseComm.h"
#include "Include.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma resource "*.dfm"
TFrmUseSkip *FrmUseSkip;


#define _MAX_USESKIP_CNT_   20
//---------------------------------------------------------------------------
__fastcall TFrmUseSkip::TFrmUseSkip(TComponent* Owner)
	: TForm(Owner)
{
    UseSkipGrid->Cells[0][0] = "NO";
    UseSkipGrid->Cells[1][0] = "ITEM";
    UseSkipGrid->Cells[2][0] = "CHECK";
    UseSkipGrid->Cells[3][0] = "NO";
    UseSkipGrid->Cells[4][0] = "ITEM";
    UseSkipGrid->Cells[5][0] = "CHECK";
}
//---------------------------------------------------------------------------
void __fastcall TFrmUseSkip::BtnCloseClick(TObject *Sender)
{
	UseSkipTimer->Enabled = false;
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TFrmUseSkip::FormShow(TObject *Sender)
{

    for( int i = 0; i < _MAX_USESKIP_CNT_; i++ )
    {
    	UseSkipGrid->Cells[0][i+1] = IntToStr(i);
    	UseSkipGrid->Cells[3][i+1] = IntToStr(i + _MAX_USESKIP_CNT_);
    }

	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\UseSkip.ini"))
	{
        TIniFile *UseSkipIni = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\UseSkip.ini");


        for( int i = 0; i < _MAX_USESKIP_CNT_*2; i++ )
        {
        	nUseSkipNumber[i] =  UseSkipIni->ReadInteger("USESKIPINDEX","ENUM"+IntToStr(i), i);
            if(i <  _MAX_USESKIP_CNT_)
			{
				UseSkipGrid->Cells[1][i+1] = IntToStr(nUseSkipNumber[i]) + " : "+ UseSkipIni->ReadString("USESKIPNAME","Name"+IntToStr(i),"USESKIP"+IntToStr(i+1));
			}
            else
            {
            	UseSkipGrid->Cells[4][(i+1) - _MAX_USESKIP_CNT_] = IntToStr(nUseSkipNumber[i]) + " : "+ UseSkipIni->ReadString("USESKIPNAME","Name"+IntToStr(i),"USESKIP"+IntToStr(i+1));
            }
        }
        UseSkipTimer->Enabled = true;

        delete UseSkipIni;
        bFailIni = true;
	}
    else
    {
        for( int i = 0; i < _MAX_USESKIP_CNT_*2; i++ )
        {
    		 bUseSkipStatus[i] = false;
        }
        bFailIni = false;
    }
}
//---------------------------------------------------------------------------

void TFrmUseSkip::UseSkipRead()
{
	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_USESKIP;
    if(g_MMIComm->Send() && g_MMIComm->Recv())
    {
        for( int iLeft = 0; iLeft < _MAX_USESKIP_CNT_*2; iLeft++ )
        {
            bUseSkipStatus[iLeft] = g_MMIComm->m_mmiToSeq.buffer.useSkip.nVal[nUseSkipNumber[iLeft]];

            if(iLeft < _MAX_USESKIP_CNT_)
            {
            	UseSkipGrid->Cells[2][iLeft+1] =  bUseSkipStatus[iLeft] ? "USE" : "SKIP";
            }
            else
			{
            	UseSkipGrid->Cells[5][(iLeft+1) -_MAX_USESKIP_CNT_] =  bUseSkipStatus[iLeft] ? "USE" : "SKIP";
            }
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TFrmUseSkip::UseSkipTimerTimer(TObject *Sender)
{
	this->UseSkipRead();
}
//---------------------------------------------------------------------------

void __fastcall TFrmUseSkip::UseSkipGridDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State)
{
	if(bFailIni == true)
    {
        if(ARow > 0  && (ACol == 2))
        {
            UseSkipGrid->Canvas->Brush->Color = bUseSkipStatus[ARow-1] ? clLime : clGray;
            UseSkipGrid->Canvas->Pen->Color = clBlack;
            UseSkipGrid->Canvas->FillRect( Rect );
            UseSkipGrid->Canvas->Font->Color = clBlack;
            UseSkipGrid->Canvas->FillRect(UseSkipGrid->CellRect(2,ARow));
            UseSkipGrid->Canvas->TextRect( Rect, (Rect.Right+Rect.Left)/2, Rect.Top+5, UseSkipGrid->Cells[2][ARow] );
        }

        if(ARow > 0  && (ACol == 5))
        {
            UseSkipGrid->Canvas->Brush->Color = bUseSkipStatus[(ARow-1) + _MAX_USESKIP_CNT_] ? clLime : clGray;
            UseSkipGrid->Canvas->Pen->Color = clBlack;
            UseSkipGrid->Canvas->FillRect( Rect );
            UseSkipGrid->Canvas->Font->Color = clBlack;
            UseSkipGrid->Canvas->FillRect(UseSkipGrid->CellRect(5,ARow));
            UseSkipGrid->Canvas->TextRect( Rect, (Rect.Right+Rect.Left)/2, Rect.Top+5, UseSkipGrid->Cells[5][ARow] );
        }
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmUseSkip::UseSkipGridDblClick(TObject *Sender)
{

    if(!CheckCanDataAccess()) return;

	int nTag = 999;

    if(UseSkipGrid->Row > 0  && UseSkipGrid->Col == 2 )
    {
        nTag = nUseSkipNumber[UseSkipGrid->Row-1];
	}

    if(UseSkipGrid->Row > 0  && UseSkipGrid->Col == 5)
    {
		nTag = nUseSkipNumber[(UseSkipGrid->Row-1) +_MAX_USESKIP_CNT_];
	}


	int iRtn =UseSkipControl(nTag);
	// OhtMode and RfidMode
	if(nTag == usOhtMode || nTag == usRfid)
		LotModeControl(nTag);

	if(nTag == usRfid && bReadUseSkip(usRfid))
	{
	   UseSkipControl(usRunSplitMerge,TRUE);
	   UseSkipControl(usAutoLotEnd,TRUE);
	}

	if(nTag == usRfid && !bReadUseSkip(usRfid))
	{
	   UseSkipControl(usRunSplitMerge,FALSE);
	   UseSkipControl(usAutoLotEnd,FALSE);
    }

	if(iRtn)
	{
		if(MainForm->b_TpConnect)
		{
			String strData = "", strIndex = "";

			{
				strIndex= "'"+UseSkipGrid->Cells[UseSkipGrid->Col-1][UseSkipGrid->Row]+"'";

				String ubIndex = strIndex;
				ubIndex = StringReplace(ubIndex, " ", "", TReplaceFlags()<<rfReplaceAll );

				if(iRtn==1)
					strData = "'TRUE'";
				else
					strData = "'FALSE'";

				MainForm->MachineHistoryData(ubIndex + " : " + strData);
				g_pTpBase->logConfigure(L"USESKIP",L"CHANGE",L"'CHANGE_ITEM'",ubIndex.c_str(),L"'VALUE'",strData.c_str());
			}
		}
	}

}
//---------------------------------------------------------------------------

void TFrmUseSkip::LotModeControl(int nModeIndex)
{
	bool bReadUseSkip = false, bWriteUseSkip = false;


	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_USESKIP;
	if(g_MMIComm->Send() && g_MMIComm->Recv())
	{
		bReadUseSkip = g_MMIComm->m_mmiToSeq.buffer.useSkip.nVal[nModeIndex];

		if(nModeIndex == usRfid)
		{
			bWriteUseSkip = g_MMIComm->m_mmiToSeq.buffer.useSkip.nVal[usOhtMode];

			if(!bReadUseSkip && bWriteUseSkip)
			{
				g_MMIComm->m_mmiToSeq.buffer.useSkip.nStart 	= usOhtMode;
				g_MMIComm->m_mmiToSeq.buffer.useSkip.nEnd 		= usOhtMode;
				g_MMIComm->m_mmiToSeq.buffer.useSkip.nVal[usOhtMode] = false;

				g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_USESKIP;
				if(g_MMIComm->Send() && g_MMIComm->Recv())
				{
					return;
				}
			}
		}
		else
		{
			bWriteUseSkip = g_MMIComm->m_mmiToSeq.buffer.useSkip.nVal[usRfid];

			if(bReadUseSkip && !bWriteUseSkip)
			{
				g_MMIComm->m_mmiToSeq.buffer.useSkip.nStart 	= usRfid;
				g_MMIComm->m_mmiToSeq.buffer.useSkip.nEnd 		= usRfid;
				g_MMIComm->m_mmiToSeq.buffer.useSkip.nVal[usRfid] = true;

				g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_USESKIP;
				if(g_MMIComm->Send() && g_MMIComm->Recv())
				{
					return;
				}
			}
		}
	}
}
//---------------------------------------------------------------------------
