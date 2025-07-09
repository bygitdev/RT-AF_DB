//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormManualCuttingScrn.h"
#include "MainFormScrn.h"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include "ffliper.h"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma link "iComponent"
#pragma link "iCustomComponent"
#pragma link "iEdit"
#pragma link "iEditCustom"
#pragma link "iLedMatrix"
#pragma link "iVCLComponent"
#pragma link "CurvyControls"
#pragma link "iLed"
#pragma link "iLedDiamond"
#pragma link "iLedRound"
#pragma resource "*.dfm"

#define	_MANUAL_CUTTING_LEFT 	113
#define   _MAX_STAGE_COUNT_      7


TFormManualCutting *FormManualCutting;
//---------------------------------------------------------------------------
__fastcall TFormManualCutting::TFormManualCutting(TComponent* Owner)
	: TForm(Owner)
{
	BtnSelect1->Enabled = false;
	BtnSelect2->Enabled = true;
	BtnSelect3->Enabled = true;
	BtnSelect4->Enabled = true;

	BtnSelect5->Enabled = true;
	BtnSelect6->Enabled = true;
	BtnSelect7->Enabled = true;
}
//---------------------------------------------------------------------------

void TFormManualCutting::FormManualCut_Initialize()
{

 	nStripIndex = 0;
	MatrixInfoRead(nStripIndex);
}
//---------------------------------------------------------------------------

void __fastcall TFormManualCutting::BtnSelect1Click(TObject *Sender)
{
	nStripIndex = dynamic_cast<TBitBtn*>(Sender)->Tag;

	if(formFlipper->Showing)
	{
		formFlipper->Hide();
		BtnFlipper->Enabled = true;
	}

	for(int nIndex=0; nIndex<_MAX_STAGE_COUNT_; nIndex++)
	{
		TBitBtn* CloneStripBtn = (TBitBtn*)FindComponent("BtnSelect" + IntToStr(nIndex+1));

        if(nStripIndex == (nIndex))
        {
			CloneStripBtn->Enabled = false;
        }
        else
        {
			CloneStripBtn->Enabled = true;
        }
	}
	nActivateRow = 0;
    nActivateCol = 0;

    this->MatrixInfoRead(nStripIndex);
}
//---------------------------------------------------------------------------

void __fastcall TFormManualCutting::BtnResetClick(TObject *Sender)
{
	for(int nRow=0; nRow < StringGridSubstrate->RowCount; nRow++)
	{
		for(int nCol=0; nCol < StringGridSubstrate->ColCount; nCol++)
        {
			_status[nCol][nRow] = NONE;
		}
	}
	StringGridSubstrate->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TFormManualCutting::BtnInverseClick(TObject *Sender)
{
	for(int nRow = 0; nRow < StringGridSubstrate->RowCount; nRow++)
	{
		for(int nCol = 0; nCol < StringGridSubstrate->ColCount; nCol++)
		{
			if(_status[nCol][nRow] == NONE)
			{
				_status[nCol][nRow] = GOOD;
			}
			else
			{
				_status[nCol][nRow] = NONE;
			}
		}
	}
	StringGridSubstrate->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TFormManualCutting::BtnHorizontalClick(TObject *Sender)
{
	for(int nCol = 0; nCol <StringGridSubstrate->ColCount; nCol++)
	{
		_status[nCol][StringGridSubstrate->Row] = GOOD;
	}
	StringGridSubstrate->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TFormManualCutting::BtnVerticalClick(TObject *Sender)
{
	for(int nRow = 0; nRow <StringGridSubstrate->RowCount; nRow++)
	{
		_status[StringGridSubstrate->Col][nRow] = GOOD;
	}
	StringGridSubstrate->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TFormManualCutting::BtnAllUnitClick(TObject *Sender)
{
	for(int nRow=0; nRow < StringGridSubstrate->RowCount; nRow++)
	{
		for(int nCol=0; nCol < StringGridSubstrate->ColCount; nCol++)
        {
			_status[nCol][nRow] = GOOD;
		}
	}
	StringGridSubstrate->Repaint();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void __fastcall TFormManualCutting::BtnCuttingWriteClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	MatrixInfoWrite(nStripIndex);
	MatrixInfoRead(nStripIndex);
}
//---------------------------------------------------------------------------


void __fastcall TFormManualCutting::BtnCuttingReadClick(TObject *Sender)
{
	MatrixInfoRead(nStripIndex);
}
//---------------------------------------------------------------------------
void TFormManualCutting::MatrixInfoRead(int nStageNumber)
{
	this->SetGridPanels(nStageNumber);
}
//---------------------------------------------------------------------------


void TFormManualCutting::MatrixInfoWrite(int nStageNumber)
{
	int nRowYCnt , nColXCnt;

	nRowYCnt = dReadPkgData(pcbYCnt);
	nColXCnt = dReadPkgData(pcbXCnt);
	if( nStageNumber >=  10)
	{
		nRowYCnt = dReadPkgData(trayYCnt);
		nColXCnt = dReadPkgData(trayXCnt);
	}

	if(nColXCnt == 0|| nColXCnt > _MAX_COL_COUNT_)
	{
		nColXCnt =4;
	}
	if(nRowYCnt == 0|| nRowYCnt > _MAX_ROW_COUNT_)
    {
        nRowYCnt =4;
    }


    g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_MAP1 + nStageNumber;

    if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
    {
		for(int nRow=0; nRow<nRowYCnt; nRow++)
        {
            for(int nCol=0; nCol <nColXCnt;  nCol++)
			{
				g_MMIComm->m_mmiToSeq.buffer.selMap[nCol][nRow] = _status[nCol][nRow];
			}
        }


        if(nStageNumber >= 10)
        {
            nStageNumber = nStageNumber-1; 	// 트레이일 경우 WR커맨드가 1작음
        }

		g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_MAP1  + nStageNumber ;

        if(g_MMIComm->Send() && g_MMIComm->Recv())
		{
            FrmCdBox->setFlag(CD_OK);
            FrmCdBox->setTitle("MANUAL SELECT");
			FrmCdBox->setText("STAGE "+IntToStr(nStageNumber+1)+" Device Save Complete.");
            FrmCdBox->ShowModal();
		}
        else
		{
            MessageDlg("Fail", mtError, TMsgDlgButtons() << mbOK, 0);
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormManualCutting::BtnFlipperClick(TObject *Sender)
{
	for(int nIndex=0; nIndex<_MAX_STAGE_COUNT_; nIndex++)
	{
		TBitBtn* CloneStripBtn = (TBitBtn*)FindComponent("BtnSelect" + IntToStr(nIndex+1));
		CloneStripBtn->Enabled = true;
   	}

	formFlipper->Show();
	BtnFlipper->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TFormManualCutting::FormCreate(TObject *Sender)
{
	formFlipper = new TfrmFlipper(this);

	formFlipper->Parent = MatrixBasePanel;
	formFlipper->Align = alClient;
}
//---------------------------------------------------------------------------

void __fastcall TFormManualCutting::FormDestroy(TObject *Sender)
{
	if(NULL != formFlipper)
    {
        delete formFlipper;
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormManualCutting::FormResize(TObject *Sender)
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

void __fastcall TFormManualCutting::SetGridPanels(int stageIndex)
{
	int nRowYCnt , nColXCnt;

	nRowYCnt = dReadPkgData(pcbYCnt);
	nColXCnt = dReadPkgData(pcbXCnt);

	bool isRejectTray = false;

	if( stageIndex >=  10)		// tray
	{
		isRejectTray = true;
		nRowYCnt = dReadPkgData(trayYCnt);
		nColXCnt = dReadPkgData(trayXCnt);
	}

	if(nColXCnt == 0|| nColXCnt > _MAX_COL_COUNT_)
	{
		nColXCnt = _MAX_COL_COUNT_;
	}
	if(nRowYCnt == 0|| nRowYCnt > _MAX_ROW_COUNT_)
	{
		nRowYCnt = _MAX_ROW_COUNT_;
	}

	StringGridSubstrate->RowCount = nRowYCnt;
	StringGridSubstrate->ColCount = nColXCnt;

	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_MAP1 + stageIndex;

	if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
	{
		for(int nRow=0; nRow<nRowYCnt; nRow++)
		{
			for(int nCol=0; nCol <nColXCnt;  nCol++)
			{
				_status[nCol][nRow] = g_MMIComm->m_mmiToSeq.buffer.selMap[nCol][nRow];

				String caption = "";
				if(isRejectTray)
				{
					if(ReadIntegerFromRootInifile("RejectCode.ini","CAPTION_VISIBLE","VISIBLE"))
					{
						caption = ReadStringFromRootInifile("RejectCode.ini","CAPTION","CODE_"+IntToStr(_status[nCol][nRow]));
					}
				}

				StringGridSubstrate->Cells[nCol][nRow] = caption;
			}
		}
	}
	StringGridSubstrate->Repaint();
	this->FormResize(this);


}
//---------------------------------------------------------------------------
void __fastcall TFormManualCutting::StringGridSubstrateMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	if(_lmouse_down)
	{
		int end_x = StringGridSubstrate->MouseCoord(X,Y).X;
		int end_y = StringGridSubstrate->MouseCoord(X,Y).Y;

		int rsy = _drag_start.y;
		int rey = end_y;
		if(end_y < _drag_start.y)
		{
			rsy = end_y;
			rey = _drag_start.y;
		}

		int rsx = _drag_start.x;
		int rex = end_x;
		if(end_x < _drag_start.x)
		{
			rsx = end_x;
            rex = _drag_start.x;
		}

		for(int r = rsy; r <= rey ; r++)
		{
			for(int c= rsx; c<= rex; c++)
			{
                bool CanSelect;
				this->StringGridSubstrateSelectCell(Sender,c,r,CanSelect);
			}
		}
		StringGridSubstrate->Repaint();
		_lmouse_down = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormManualCutting::StringGridSubstrateMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y)
{
	_drag_start.x = StringGridSubstrate->MouseCoord(X,Y).X;
	_drag_start.y = StringGridSubstrate->MouseCoord(X,Y).Y;

	if(Button == mbLeft)  _lmouse_down= true;
}
//---------------------------------------------------------------------------

void __fastcall TFormManualCutting::StringGridSubstrateDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State)
{
	TColor brush, font;
	brush = clWhite;
	font = clBlack;


	if(nStripIndex == 12)
	{
		brush = clGray;
		if(_status[ACol][ARow]>0)
		{
			brush = clLime;
		}
	}
	else
	{
		switch(_status[ACol][ARow])
		{
			case NONE :
				brush = clGray;
				break;

			case GOOD:
				brush = clLime;
				break;

			default:
				brush = clGray;
				break;
		}
	}

	StringGridSubstrate->Canvas->Brush->Color = brush;
	StringGridSubstrate->Canvas->Font->Color = clBlack;

	StringGridSubstrate->Canvas->FillRect(StringGridSubstrate->CellRect(ACol,ARow));

	if(nStripIndex == 12) // rejectTray
	{
		DrawText(	StringGridSubstrate->Canvas->Handle,
					StringGridSubstrate->Cells[ACol][ARow].c_str(),
					StringGridSubstrate->Cells[ACol][ARow].Length(),
					&Rect,
					DT_CENTER | DT_SINGLELINE | DT_VCENTER);
    }

}
//---------------------------------------------------------------------------

void __fastcall TFormManualCutting::StringGridSubstrateSelectCell(TObject *Sender,
		  int ACol, int ARow, bool &CanSelect)
{
	if(_status[ACol][ARow] == NONE)
	{
		_status[ACol][ARow] = GOOD;
	}
	else
	{
		_status[ACol][ARow] = NONE;
	}
	StringGridSubstrate->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TFormManualCutting::FormShow(TObject *Sender)
{
	this->FormManualCut_Initialize();
}
//---------------------------------------------------------------------------

