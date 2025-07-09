//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FrmSensorPartScrn.h"

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include "BaseComm.h"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma link "AdvPicture"
#pragma link "CurvyControls"


#pragma resource "*.dfm"

TFrmSensorPart *FrmSensorPart;

//TFrmSensorSet* pSensorTemp;

//---------------------------------------------------------------------------
__fastcall TFrmSensorPart::TFrmSensorPart(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFrmSensorPart::SensorScreenInitialize(int nPosID)
{

	TIniFile *pSensorIni = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini");
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini")== true)
	{
		nSensorPosID =  nPosID;
		_bSensorIO =  pSensorIni->ReadBool("ChannelSet"+IntToStr(nPosID),"IOSET",0);
		CheckBoxExt->Checked =  pSensorIni->ReadBool("ChannelSet"+IntToStr(nPosID),"Ext",0);

		if(_bSensorIO == true)
		{
            _nChannelIndex = pSensorIni->ReadInteger("ChannelSet"+IntToStr(nSensorPosID),"InputChannel",0);
            _clSensorColor = pSensorIni->ReadInteger("ChannelSet"+IntToStr(nSensorPosID),"InputColor",clGreen);
        }
        else
        {
            _nChannelIndex = pSensorIni->ReadInteger("ChannelSet"+IntToStr(nSensorPosID),"OutputChannel",0);
            _clSensorColor = pSensorIni->ReadInteger("ChannelSet"+IntToStr(nSensorPosID),"OutputColor",clRed);
        }

        SensorDataReadfromIni(_bSensorIO);
        SensorRefresh->Enabled = true;

        LabelSensorNotify->Refresh();

        //ImgSensorconfig->Tag = nPosID;
    }

    delete pSensorIni;
    pSensorIni = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TFrmSensorPart::SensorStatus_Config()
{
	TIniFile *pSensorIni = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini");

	pSensorIni->WriteBool("ChannelSet"+IntToStr(nSensorPosID),"IOSET",_bSensorIO);

	if(_bSensorIO == true)
	{
		pSensorIni->WriteInteger("ChannelSet"+IntToStr(nSensorPosID),"InputChannel",_nChannelIndex);
	}
	else
	{
		pSensorIni->WriteInteger("ChannelSet"+IntToStr(nSensorPosID),"OutputChannel",_nChannelIndex);
	}
	pSensorIni->WriteBool("ChannelSet"+IntToStr(nSensorPosID),"Ext",CheckBoxExt->Checked);

	delete pSensorIni;
	pSensorIni = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TFrmSensorPart::SensorDataReadfromIni(bool bIO)
{

	TIniFile *pSensorName  = new TIniFile(ExtractFilePath(Application->ExeName) + "\\Ini\\SensorName.ini");
	if(bIO == true)
    {
        for( int i = 0; i < StringGridSensor->RowCount; i++ )
        {
        	String strTemp = StringSpaceMaker(_nChannelIndex,2)+StringSpaceMaker(i,2);

            StringGridSensor->Cells[0][i]= strTemp;
            StringGridSensor->Cells[1][i]= pSensorName->ReadString("INPUT_CHANNEL_" + IntToStr(_nChannelIndex), "NO_" + IntToStr(i), "");
        }
        LabelSensorNotify->Caption = "Input Channel" + IntToStr(_nChannelIndex);
    }
    else
    {
        for( int i = 0; i < StringGridSensor->RowCount; i++ )
        {
        	String strTemp = StringSpaceMaker(_nChannelIndex,2)+StringSpaceMaker(i,2);

            StringGridSensor->Cells[0][i]= strTemp;
            StringGridSensor->Cells[1][i]= pSensorName->ReadString("OUTPUT_CHANNEL_" + IntToStr(_nChannelIndex), "NO_" + IntToStr(i), "");
        }
        LabelSensorNotify->Caption = "Output Channel" + IntToStr(_nChannelIndex);
    }

    delete pSensorName;
    pSensorName = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TFrmSensorPart::FormClose(TObject *Sender, TCloseAction &Action)
{
	SensorRefresh->Enabled = false;

	Action = caFree;
}
//---------------------------------------------------------------------------

void __fastcall TFrmSensorPart::SensorRefreshTimer(TObject *Sender)
{
    g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_IO;

   	bool bIOChk;
    if(true == g_MMIComm->Send() && true == g_MMIComm->Recv())
    {
        for(int i=0; i<=(StringGridSensor->RowCount-1); i++)
        {

            if(_bSensorIO == true)
            {
                bIOChk = BIT(g_MMIComm->m_mmiToSeq.buffer.rdIO.inCH[_nChannelIndex],i);
            }
            else
            {
                bIOChk = BIT(g_MMIComm->m_mmiToSeq.buffer.rdIO.outCH[_nChannelIndex],i);
            }

            if(bIOChk == true)
            {
                TPanel *CloneInput = (TPanel *)FindComponent("SensorPanel" + IntToStr(i+1));
                Status_Led( CloneInput, _bSensorIO ? _STATUS_LED_GREEN_ : _STATUS_LED_RED_, true, "ON" );
            }
            else
            {
                TPanel *CloneInput = (TPanel *)FindComponent("SensorPanel" + IntToStr(i+1));
                Status_Led( CloneInput, _clSensorColor, false, "OFF" );
            }
    	}
    }
}
//---------------------------------------------------------------------------


void __fastcall TFrmSensorPart::AdvPictureMoveNextClick(TObject *Sender)
{
	int nTag = dynamic_cast<TAdvPicture *>(Sender)->Tag;

    if(nTag == -1 &&  _nChannelIndex == 0)
    {
        return;
    }
    _nChannelIndex = _nChannelIndex + nTag;
	SensorDataReadfromIni(_bSensorIO);

    SensorStatus_Config();
}
//---------------------------------------------------------------------------

void __fastcall TFrmSensorPart::SensorPanel1DblClick(TObject *Sender)
{
	if(_bSensorIO == true) return;

	if(!CheckCanDataAccess()) return;
	if(!CheckCanAccessLevel(PW_MAINTENANCE)) return;

	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_IO;

	if(g_MMIComm->Send() && g_MMIComm->Recv())
	{
    	TPanel* pPanel = dynamic_cast<TPanel *>(Sender);
        int nTag = pPanel->Tag;

		Word wReadCh = (WORD) g_MMIComm->m_mmiToSeq.buffer.rdIO.outCH[_nChannelIndex];
		BOOL bData = BIT( wReadCh, nTag );

		String szNum = StringSpaceMaker( _nChannelIndex, 2 ) + StringSpaceMaker( nTag, 2 );

		g_MMIComm->m_mmiToSeq.buffer.wrIO.nIONo = StrToInt(szNum);
        g_MMIComm->m_mmiToSeq.buffer.wrIO.bOn = !bData;
		g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_IO;
		if(g_MMIComm->Send() && g_MMIComm->Recv())
		{
			MainLog("Write IO : " + szNum + " ->" + BoolToStr(!bData,true));
		}
		else
		{
			ShowMessage("Communication Failure");

		}
    }
	else
	{
		ShowMessage("Communication Failure");
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmSensorPart::CheckBoxExtClick(TObject *Sender)
{

    if(CheckBoxExt->Checked == true)
    {
    	if(_nChannelIndex < 15)
		{
			_nChannelIndex = _nChannelIndex+16;
    	}
    }
    else
    {
    	if(_nChannelIndex > 15)
        {
        	_nChannelIndex = _nChannelIndex-16;
        }
	}


	TIniFile *pSensorIni = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Setup.ini");

	pSensorIni->WriteBool("ChannelSet"+IntToStr(nSensorPosID),"Ext",CheckBoxExt->Checked);

	delete pSensorIni;
	pSensorIni = NULL;


	this->SensorDataReadfromIni(_bSensorIO);
}
//---------------------------------------------------------------------------


