//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormLifeTimeSetScrn.h"
#include "..\mainformscrn.h"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include "BaseComm.h"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma resource "*.dfm"
TFormLifeTimeSet *FormLifeTimeSet;


#define   _LIFETIME_SET_START_INDEX_         900
#define   _LIFETIME_ACT_START_INDEX_         930

//---------------------------------------------------------------------------
__fastcall TFormLifeTimeSet::TFormLifeTimeSet(TComponent* Owner)
	: TForm(Owner)
{

    LifeTimeParamGrid->Cells[0][0] = "NO";
    LifeTimeParamGrid->Cells[1][0] = "NAME";
    LifeTimeParamGrid->Cells[2][0] = "SET";
    LifeTimeParamGrid->Cells[3][0] = "ACT";
    LifeTimeParamGrid->Cells[4][0] = "PROGRESS";
}
//---------------------------------------------------------------------------
void __fastcall TFormLifeTimeSet::LifeTimeScreen_Initialize()
{
    LifeTimeParamGrid->Options>>goEditing;
    LifeTimeParamGrid->Options<<goRowSelect;

    BtnInputItem->Enabled = true;
    BtnSaveItem->Enabled = false;

	LifeTimeTimer->Enabled = true;
    this->LifeTime_read();
}
//---------------------------------------------------------------------------
void __fastcall TFormLifeTimeSet::BtnInputItemClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;
	BtnInputItem->Enabled = false;
    BtnSaveItem->Enabled = true;

    LifeTimeParamGrid->Options<<goEditing;
    LifeTimeParamGrid->Options>>goRowSelect;

	LifeTimeTimer->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TFormLifeTimeSet::BtnSaveItemClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;
	BtnInputItem->Enabled = true;
    BtnSaveItem->Enabled = false;

    LifeTimeParamGrid->Options>>goEditing;
    LifeTimeParamGrid->Options<<goRowSelect;

	this->LifeTime_save();
    this->LifeTimeSet();
    this->LifeTime_read();

  	LifeTimeTimer->Enabled = true;
}
//---------------------------------------------------------------------------
bool    TFormLifeTimeSet::LifeTime_read()
{
    TIniFile *DParamini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\DParam.ini");
    if(DParamini != NULL)
    {
        for(int i=0; i<LifeTimeParamGrid->RowCount-1;i++)
        {
            LifeTimeParamGrid->Cells[0][i+1] =  IntToStr(i);
            LifeTimeParamGrid->Cells[1][i+1] = DParamini->ReadString("DPARM","NAME"+IntToStr(i+_LIFETIME_SET_START_INDEX_),"Name"+IntToStr(i));
        }
        delete DParamini;
        return true;

    }
    else
    {
    	delete DParamini;
        return false;
    }
	delete DParamini;
}
//------------------------------------------------------------------------
bool    TFormLifeTimeSet::LifeTime_save()
{
    TIniFile *DParamini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\DParam.ini");
    if(DParamini != NULL)
    {
        for(int i=0; i<LifeTimeParamGrid->RowCount-1;i++)
        {
            DParamini->WriteString("DPARM","NAME"+IntToStr(i+_LIFETIME_SET_START_INDEX_),LifeTimeParamGrid->Cells[1][i+1]);
        }
        delete DParamini;
        return true;

    }
    else
    {
        delete DParamini;
        return false;
    }
}
//------------------------------------------------------------------------
void    TFormLifeTimeSet::LifeTimeRefresh()
{
	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_DDM;
    g_MMIComm->m_mmiToSeq.buffer.ddm.nStart =  _LIFETIME_SET_START_INDEX_;
    g_MMIComm->m_mmiToSeq.buffer.ddm.nEnd = _LIFETIME_ACT_START_INDEX_ + 20 -1;
	BOOL bRet = g_MMIComm->Send() && g_MMIComm->Recv();
    if (!bRet)
    	return;

    for(int i=0; i<LifeTimeParamGrid->RowCount-1; i++)
    {
        double dbSetval = g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ _LIFETIME_SET_START_INDEX_+ i];
        double dbActVal =  g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ _LIFETIME_ACT_START_INDEX_+ i];

        LifeTimeParamGrid->Cells[2][i+1]= FloatToStr( dbSetval);
        LifeTimeParamGrid->Cells[3][i+1]= FloatToStr( dbActVal);

		if(dbActVal == 0)
        {
            LifeTimeParamGrid->Cells[4][i+1]= "0";
        }
        else
        {
        	if(dbSetval == 0)
        	{
        		LifeTimeParamGrid->Cells[4][i+1]= FloatToStr( (dbActVal)*100);
            }
			else
            {
        		LifeTimeParamGrid->Cells[4][i+1]= FloatToStr( (dbActVal /dbSetval)*100);
    		}
        }
    }
}
//------------------------------------------------------------------------
void    TFormLifeTimeSet::LifeTimeSet()
{
	g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_DDM;
    g_MMIComm->m_mmiToSeq.buffer.ddm.nStart = _LIFETIME_SET_START_INDEX_;
    g_MMIComm->m_mmiToSeq.buffer.ddm.nEnd = _LIFETIME_ACT_START_INDEX_ + 20 -1;

    for(int i=0; i<LifeTimeParamGrid->RowCount-1;i++)
    {
        if(LifeTimeParamGrid->Cells[ 2 ][ i+1 ]  == "")
        {
            LifeTimeParamGrid->Cells[ 2 ][ i+1 ]  = "0";
        }
        g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[_LIFETIME_SET_START_INDEX_+i] = StrToFloat( LifeTimeParamGrid->Cells[ 2 ][ i+1 ] );
        if(LifeTimeParamGrid->Cells[ 3 ][ i+1 ]  == "")
        {
            LifeTimeParamGrid->Cells[ 3 ][ i+1 ]  = "0";
        }
        g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[_LIFETIME_ACT_START_INDEX_+i] = StrToFloat( LifeTimeParamGrid->Cells[ 3 ][ i+1 ] );
    }

	BOOL bRet = g_MMIComm->Send() && g_MMIComm->Recv();
    if (!bRet)
    	return;

}
//------------------------------------------------------------------------
void __fastcall TFormLifeTimeSet::LifeTimeTimerTimer(TObject *Sender)
{
	this->LifeTimeRefresh();
}
//---------------------------------------------------------------------------


void __fastcall TFormLifeTimeSet::LifeTimeParamGridDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State)
{
    TStringGrid* pGrid = (TStringGrid* )Sender;
    if (ACol == 4 && ARow > 0)
    {
        HDC hDC = pGrid->Canvas->Handle;
        Rect.left -=4; // resize rect area
        RECT rectPercentage = { Rect.left, Rect.top, Rect.right, Rect.bottom};
        RECT rectText = rectPercentage;

        int rectWidth = rectPercentage.right - rectPercentage.left;

        if(pGrid->Cells[4][ARow] == "")
        {
        	pGrid->Cells[4][ARow] = 0;
        }

		String StrVal = pGrid->Cells[4][ARow];
        float percentage = StrToFloat(StrVal);

        int rectWidthResized = rectWidth * percentage / 100.0;
        rectPercentage.right = rectPercentage.left +  rectWidthResized;

        StrVal.sprintf(L"%.1f %", percentage);

        HBRUSH hBrush = (HBRUSH)CreateSolidBrush(RGB( 255 - percentage*1.5 , 255- percentage*1.5, 255- percentage*1.5 ));
        HBRUSH oldBrush = (HBRUSH)::SelectObject(hDC, hBrush);

        //::FillRect(hDC, &rectPercentage, hBrush);
        ::RoundRect(hDC, rectPercentage.left, rectPercentage.top, rectPercentage.right, rectPercentage.bottom, 6, 6);
        ::SetBkMode(hDC, TRANSPARENT);
        ::SetTextColor(hDC, RGB(0, 0, 0));
        int oldPenMode = ::SetROP2(hDC,  R2_XORPEN);
        ::DrawText(hDC, StrVal.c_str(), StrVal.Length(), &rectText, DT_CENTER | DT_SINGLELINE | DT_VCENTER);

        ::SetROP2(hDC,  oldPenMode);

        ::SelectObject(hDC, oldBrush);
        ::DeleteObject(hBrush); //
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormLifeTimeSet::SpeedButton1Click(TObject *Sender)
{
    if(!CheckCanDataAccess()) return;
	int row = LifeTimeParamGrid->Row;
    if (row <1 )
    	return;

    String name = LifeTimeParamGrid->Cells[1][row];

    FrmCdBox->setFlag(CD_YESNO);
    FrmCdBox->setTitle( "LIFETIME" );
    FrmCdBox->setText("Do you want to reset lifetime to zero ? ["  +name + "]");
    if (mrYes == FrmCdBox->ShowModal())
    {
    	int ddm = _LIFETIME_ACT_START_INDEX_ + row - 1;
    	dWriteCommunicationDM( 0, ddm);	//reset to 0

        MainForm->MachineHistoryData( "lifetime reset to zero : " + name);
    }
}
//---------------------------------------------------------------------------

