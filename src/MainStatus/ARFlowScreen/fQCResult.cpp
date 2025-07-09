//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fQCResult.h"
#include "MainFormScrn.h"
#include "BaseComm.h"
#include "..\tccomm\ftccomm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma resource "*.dfm"
TfrmQCResult *frmQCResult;
//---------------------------------------------------------------------------
__fastcall TfrmQCResult::TfrmQCResult(TComponent* Owner)
	: TForm(Owner)
{
	_index = 0;
}
//---------------------------------------------------------------------------

void TfrmQCResult::setStageIndex(int index)
{
	_index = index;
    ceIndex->Text = "INDEX : " + IntToStr(index+1);
}

void __fastcall TfrmQCResult::FormShow(TObject *Sender)
{

	_nRowYCnt = dReadPkgData(pcbYCnt);
	_nColXCnt = dReadPkgData(pcbXCnt);

	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_STG1_LOT_INFO + _index;
	BOOL bRet = g_MMIComm->Send() &&  g_MMIComm->Recv();
    if (!bRet)
    	return;

    LOT_INFO& info = g_MMIComm->m_mmiToSeq.buffer.lotInfo;
    ceLotID->Text = info.lotID;

    CurvyEdit1->Text = g_MMIComm->m_mmiToSeq.buffer.lotInfo.pcbTestResult;
    CurvyEdit2->Text = g_MMIComm->m_mmiToSeq.buffer.lotInfo.pcbArtsScrap;

    this->SetGridPanels( _index);

}
//---------------------------------------------------------------------------

void __fastcall TfrmQCResult::SetGridPanels(int stageIndex)
{
	StringGridSubstrate->RowCount = _nRowYCnt;
	StringGridSubstrate->ColCount = _nColXCnt;

	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_NDM;
    g_MMIComm->m_mmiToSeq.buffer.ndm.nStart = stage1QcResult + _index*20;
    g_MMIComm->m_mmiToSeq.buffer.ndm.nEnd = g_MMIComm->m_mmiToSeq.buffer.ndm.nStart +19;
	BOOL bRet = g_MMIComm->Send() &&  g_MMIComm->Recv();
    if (!bRet)
    	return;

    memset(_qcResult, 0x00, sizeof(_qcResult));
    memcpy( _qcResult , &g_MMIComm->m_mmiToSeq.buffer.ndm.nVal[ stage1QcResult + _index*20], sizeof(_qcResult));

//	for(int nRow=0; nRow<20; nRow++)
//	{
//		for(int nCol=0; nCol <20;  nCol++)
//		{
//			_qcResult[nCol][nRow] = 0;
//		}
//	}
	for(int nRow=0; nRow<_nRowYCnt; nRow++)
	{
		for(int nCol=0; nCol <_nColXCnt;  nCol++)
		{
			int sortingIndex = (_nRowYCnt*_nColXCnt) - ((nRow+1) * _nColXCnt) + (1+nCol);
			StringGridSubstrate->Cells[nCol][nRow] = IntToStr(sortingIndex);
		}
	}


	this->FormResize(this);
	StringGridSubstrate->Repaint();
}

void __fastcall TfrmQCResult::FormResize(TObject *Sender)
{
   	// colunm
	int Count = StringGridSubstrate->ColCount;
	int Total = StringGridSubstrate->ClientWidth;
	int Margin = Total % Count;
	int Default = (Total-Margin)/Count -1;

	int rMargin = Margin + 1;

	for(int i = 0; i < Count; i++)
	{
		int size = Default;
		if(Margin != 0)
		{
			if(i%(Count/Margin) == 0 && rMargin > 0)
			{
				size++;
				rMargin--;
			}
		}
		StringGridSubstrate->ColWidths[i] = size;
	}

	// row
	Count = StringGridSubstrate->RowCount;
	Total = StringGridSubstrate->ClientHeight;
	Margin = Total % Count;
	Default = (Total-Margin)/Count -1;

	rMargin = Margin + 1;

	for(int i = 0; i < Count; i++)
	{
		int size = Default;
		if(Margin != 0)
		{
			if(i%(Count/Margin) == 0 && rMargin > 0)
			{
				size++;
				rMargin--;
			}
		}
		StringGridSubstrate->RowHeights[i] = size;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmQCResult::StringGridSubstrateDrawCell(TObject *Sender, int ACol,
		  int ARow, TRect &Rect, TGridDrawState State)
{
    TColor brush, font;
    brush = clWhite;
	font = clBlack;

	int result;
	int AColMax = _nColXCnt - 1;

	if(ARow%2 == 1)
	{
		int AColRev;
		AColRev = AColMax - ACol;

		int index = ARow * _nColXCnt + AColRev;
		result = _qcResult[index];
	}
	else
	{
		int index = ARow * _nColXCnt + ACol;
		result = _qcResult[index];
	}

	switch(result)
	{
		case 0 :   //good
			brush = clLime;
			break;

		case 1: //NG
			brush = clRed;
			break;

		default:
            brush = clBlue;
			break;
	}

	StringGridSubstrate->Canvas->Brush->Color = brush;
	StringGridSubstrate->Canvas->Font->Color = clBlack;
	StringGridSubstrate->Canvas->FillRect(StringGridSubstrate->CellRect(ACol,ARow));

	DrawText(	StringGridSubstrate->Canvas->Handle,
			StringGridSubstrate->Cells[ACol][ARow].c_str(),
			StringGridSubstrate->Cells[ACol][ARow].Length(),
			&Rect,
			DT_CENTER | DT_SINGLELINE | DT_VCENTER);
}
//---------------------------------------------------------------------------



void __fastcall TfrmQCResult::StringGridSubstrateSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect)
{
	CanSelect =  true;
	int result, index;
	int AColMax = _nColXCnt - 1;

	if(ARow%2 == 1)
	{
		int AColRev;
		AColRev = AColMax - ACol;

		index = ARow * _nColXCnt + AColRev;
		result = _qcResult[index];
	}
	else
	{
		index = ARow * _nColXCnt + ACol;
		result = _qcResult[index];
	}

    if (0 == _qcResult[index])
    	_qcResult[index] = 1;
    else
    	_qcResult[index] = 0;

	StringGridSubstrate->Repaint();

	g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_NDM;
    g_MMIComm->m_mmiToSeq.buffer.ndm.nStart = stage1QcResult + _index*20;
    g_MMIComm->m_mmiToSeq.buffer.ndm.nEnd = g_MMIComm->m_mmiToSeq.buffer.ndm.nStart +19;
    memcpy( &g_MMIComm->m_mmiToSeq.buffer.ndm.nVal[ stage1QcResult + _index*20], _qcResult, sizeof(_qcResult));
	BOOL bRet = g_MMIComm->Send() &&  g_MMIComm->Recv();
    if (!bRet)
    	return;
}
//---------------------------------------------------------------------------

void __fastcall TfrmQCResult::btnOkClick(TObject *Sender)
{
	FrmCdBox->setFlag(CD_YESNO);
	FrmCdBox->setTitle( "QC Result" );
	FrmCdBox->setText("Do you really want to apply the QC result ?");
	if (mrYes == FrmCdBox->ShowModal())
	{
		nWriteCommunicationDM(1, stageTraceFlag);
		this->Close();
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmQCResult::btnRetryClick(TObject *Sender)
{
	nWriteCommunicationDM(1, stage1QCRetry + _index);	//QC cycle retry
	this->Close();
}
//---------------------------------------------------------------------------

