//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FrmMotorControlScrn.h"
#include "AxisConfigFormScrn.h"
#include "AxisSelectFormScrn.h"
#include "MainFormScrn.h"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include "BaseComm.h"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma resource "*.dfm"

TFrmMotorControl *FrmMotorControl;

#define   _MOTOR_IDNEX_COUNT_                           50

#define   _MOTOR_POSITIVE_DIRECTION_                    1
#define   _MOTOR_NEGATIVE_DIRECTION_                    0

#define   _JOGMODE_VALUE_ENABLE_                        1
#define   _JOGMODE_VALUE_DISABLE_                       0


//---------------------------------------------------------------------------
__fastcall TFrmMotorControl::TFrmMotorControl(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall TFrmMotorControl::Motorscreen_Initialize(int nAxisSelect)
{
	MtrPosGrid->Cells[0][0] = "ID";
    MtrPosGrid->Cells[1][0] = "INDEX NAME";
    MtrPosGrid->Cells[2][0] = "SET POS";
    MtrPosGrid->Cells[3][0] = "SET SPEED";
    MtrPosGrid->Cells[4][0] = "SET ACC";
    MtrPosGrid->Cells[5][0] = "ACT POS";
    MtrPosGrid->Cells[6][0] = "ACT SPEED";
    MtrPosGrid->Cells[7][0] = "SET ACC";


	this->MtrPosGrid->RowCount = _MOTOR_IDNEX_COUNT_ + 1;

	for( int i = 0; i < this->MtrPosGrid->RowCount; i++ )
	{
		this->MtrPosGrid->Cells[ 0 ][ i + 1 ] = IntToStr( i );
	}

	this->MtrAxis_SelectedProcess(nAxisSelect);

	this->MtrRefreshTimer->Enabled = true;
	this->BtnInputMotionData->Enabled = true;
	this->BtnSaveMotionData->Enabled = false;

	this->EditJogSpeed->Text= IntToStr( nReadCommunicationDM( jogSpeed ) );
    _nSelectIndex = 0;

}
//---------------------------------------------------------------------------

void TFrmMotorControl::MtrAxis_SelectedProcess( int nSelectAxis )
{
	_nAxis_no =  nSelectAxis;

	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\MotorName.ini"))
	{
		String strBitmapUnique	= ExtractFilePath(Application->ExeName)+ "resource\\unique.bmp";

        TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\MotorName.ini");

        _bUniqueMotorSet_ = true;

		String StrRet = ini->ReadString("AXISNAME","AXIS"+IntToStr(_nAxis_no),"AXISNAME"+IntToStr(_nAxis_no));
		BtnAxisSelect->Caption = IntToStr(_nAxis_no+1)+ " : " + StrRet;

        BtnAxisSelect->Glyph->LoadFromFile(strBitmapUnique);
		BtnAxisSelect->Refresh();
        delete ini;

    }

	this->MtrData_ReadDB();
	this->MtrData_ReadSEQ();

}
//---------------------------------------------------------------------------

void __fastcall TFrmMotorControl::MtrPosGridSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect)
{
	if(ARow > 0 && CanSelect == true)
	{
	   	_nSelectIndex = ARow -1 ;
        String StrSelectPosition = "POS: " +  MtrPosGrid->Cells[5][ARow];
        String StrSelectSpeed =  "  SPD: " +MtrPosGrid->Cells[6][ARow];
        String StrSelectAcccel = "  ACCEL: " + MtrPosGrid->Cells[7][ARow];

		PanelMtrSelectIndex->Caption = "SELECT : " + IntToStr(_nSelectIndex) + " : " + StrSelectPosition +  StrSelectSpeed + StrSelectAcccel;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmMotorControl::MtrRefreshTimerTimer(TObject *Sender)
{
    g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_MT_STATUS;

	g_MMIComm->m_mmiToSeq.buffer.motStatus.nMtNo = _nAxis_no;
    if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
    {
        MtrPostionLabel->Caption = FloatToStrF(g_MMIComm->m_mmiToSeq.buffer.motStatus.dRealCnt/1000.0, ffFixed, 10, 3 );

        int nValue =  g_MMIComm->m_mmiToSeq.buffer.motStatus.nCurIndex;

        if(g_MMIComm->m_mmiToSeq.buffer.motStatus.bCw == true)
        {
            Status_Led(MtrPanelLed1 ,_STATUS_LED_GREEN_ , true , "ON");
        }
        else
        {
            Status_Led(MtrPanelLed1 ,_STATUS_LED_GREEN_ , false , "OFF");
        }

        if(g_MMIComm->m_mmiToSeq.buffer.motStatus.bHome == true)
        {
            Status_Led(MtrPanelLed2 ,_STATUS_LED_GREEN_ , true , "ON");
        }
        else
        {
            Status_Led(MtrPanelLed2 ,_STATUS_LED_GREEN_ , false , "OFF");
        }

        if(g_MMIComm->m_mmiToSeq.buffer.motStatus.bDriving  == true)
        {
            Status_Led(MtrPanelLed3 ,_STATUS_LED_GREEN_ , true , "ON");
        }
        else
        {
            Status_Led(MtrPanelLed3 ,_STATUS_LED_GREEN_ , false , "OFF");
        }

        if(g_MMIComm->m_mmiToSeq.buffer.motStatus.bOrg == true)
        {
            Status_Led(MtrPanelLed4 ,_STATUS_LED_GREEN_ , true , "ON");
        }
        else
        {
            Status_Led(MtrPanelLed4 ,_STATUS_LED_GREEN_ , false , "OFF");
        }

        if(g_MMIComm->m_mmiToSeq.buffer.motStatus.bAlarm == true)
        {
            Status_Led(MtrPanelLed5 ,_STATUS_LED_GREEN_ , true , "ON");
        }
        else
        {
            Status_Led(MtrPanelLed5 ,_STATUS_LED_GREEN_ , false , "OFF");
        }

        if(g_MMIComm->m_mmiToSeq.buffer.motStatus.bCCw == true)
        {
            Status_Led(MtrPanelLed6 ,_STATUS_LED_GREEN_ , true , "ON");
        }
        else
        {
            Status_Led(MtrPanelLed6 ,_STATUS_LED_GREEN_ , false , "OFF");
        }

        if(g_MMIComm->m_mmiToSeq.buffer.motStatus.bServoOn == true)
        {
            Status_Led(PanelServoOnOff ,_STATUS_LED_GREEN_ , true , "SERVO ON");
            bServoOnOff = true;
        }
        else
        {
            Status_Led(PanelServoOnOff ,_STATUS_LED_GREEN_ , false , "SERVO OFF");
            bServoOnOff = false;
        }
    }

    int nTempVal  = nReadCommunicationDM (tenKeyJog);
    if(nTempVal == _JOGMODE_VALUE_DISABLE_)
    {
    	PanelTenkeyJog ->Color = clGray;
    }
    else
    {
    	PanelTenkeyJog ->Color = clLime;
    }


}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
bool    TFrmMotorControl::MtrData_ReadDB()
{
	int nGrpNo, nRcpNo;

    nGrpNo = nReadGroupNo();
    nRcpNo = nReadRecipeNo();

    String StrPath = ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(nGrpNo)+"\\RCP"+IntToStr(nRcpNo)+"\\Motor"+ IntToStr(_nAxis_no)+".ini";

    if(FileExists(StrPath))
    {
        TIniFile *ini = new TIniFile(StrPath);
        for( int nRow = 0; nRow <= MtrPosGrid->RowCount - 1; nRow++ )
        {
            MtrPosGrid->Cells[1][nRow+1] = ini->ReadString("INDEXNAME","INDEXNAME"+IntToStr(nRow),"INDEXNAME"+IntToStr(nRow));
            MtrPosGrid->Cells[2][nRow+1] = ini->ReadString("INDEXPOS","POSITION"+IntToStr(nRow),"0");
            MtrPosGrid->Cells[3][nRow+1] = ini->ReadString("INDEXSPD","SPEED"+IntToStr(nRow),"0");
            MtrPosGrid->Cells[4][nRow+1] = ini->ReadString("INDEXACC","ACC"+IntToStr(nRow),"0");
        }
        delete ini;
        return true;
    }
    else
    {
    	return false;
    }

}
//------------------------------------------------------------------------
bool    TFrmMotorControl::MtrData_ReadSEQ()
{
	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_MT_TABLE;
	g_MMIComm->m_mmiToSeq.buffer.motTable.nMtNo = _nAxis_no;

	if ( g_MMIComm->Send() &&  g_MMIComm->Recv() )
	{
		for( int nRow = 0; nRow <= MtrPosGrid->RowCount; nRow++ )
		{
			MtrPosGrid->Cells[5][nRow+1] =  FloatToStr(g_MMIComm->m_mmiToSeq.buffer.motTable.dPos[nRow]/1000);
			MtrPosGrid->Cells[6][nRow+1] =  FloatToStr(g_MMIComm->m_mmiToSeq.buffer.motTable.dVel[nRow]/1000);
			MtrPosGrid->Cells[7][nRow+1] =  FloatToStr(g_MMIComm->m_mmiToSeq.buffer.motTable.dAcc[nRow]/1000);
        }
        return true;
	}
    else
    {
        return false;
    }
}
//------------------------------------------------------------------------

bool    TFrmMotorControl::MtrData_SaveDB()
{
	int nGrpNo, nRcpNo;
    nGrpNo = nReadGroupNo();
    nRcpNo = nReadRecipeNo();

    String StrPath = ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(nGrpNo)+"\\RCP"+IntToStr(nRcpNo)+"\\Motor"+ IntToStr(_nAxis_no)+".ini";

//    if(_bUniqueMotorSet_ == false)
//    {
//		StrPath = ExtractFilePath(Application->ExeName)+ "\\Ini\\Common\\Motor"+ IntToStr(_nAxis_no)+".ini";
//    }

    if(FileExists(StrPath))
    {
        TIniFile *ini = new TIniFile(StrPath);
        for( int nRow = 0; nRow <= MtrPosGrid->RowCount - 1; nRow++ )
        {
			ini->WriteString("INDEXNAME","INDEXNAME"+IntToStr(nRow),MtrPosGrid->Cells[1][nRow+1]);
            ini->WriteString("INDEXPOS","POSITION"+IntToStr(nRow),MtrPosGrid->Cells[2][nRow+1]);
            ini->WriteString("INDEXSPD","SPEED"+IntToStr(nRow),MtrPosGrid->Cells[3][nRow+1]);
            ini->WriteString("INDEXACC","ACC"+IntToStr(nRow),MtrPosGrid->Cells[4][nRow+1]);
        }
        delete ini;
        return true;
    }
    else
    {
        return false;
    }

}
//------------------------------------------------------------------------

bool    TFrmMotorControl::MtrData_SaveSEQ()
{
    g_MMIComm->m_mmiToSeq.nCmd  = CMD_RD_MT_TABLE;
    g_MMIComm->m_mmiToSeq.buffer.motTable.nMtNo = _nAxis_no;

    if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
    {
        for(int i=0; i<_MOTOR_IDNEX_COUNT_; i++)
        {
            if(MtrPosGrid->Cells[2][i+1] != "")
            {
                g_MMIComm->m_mmiToSeq.buffer.motTable.dPos [i] = MtrPosGrid->Cells[2][i+1].ToDouble()*1000;
            }
            else
            {
                g_MMIComm->m_mmiToSeq.buffer.motTable.dPos [i] = 0.;

            }

            if(MtrPosGrid->Cells[3][i+1] !="")
            {
                g_MMIComm->m_mmiToSeq.buffer.motTable.dVel [i] = MtrPosGrid->Cells[3][i+1].ToDouble()*1000;
            }
            else
            {
                g_MMIComm->m_mmiToSeq.buffer.motTable.dVel [i] = 0.;

            }

            if(MtrPosGrid->Cells[4][i+1] !="")
            {
                g_MMIComm->m_mmiToSeq.buffer.motTable.dAcc [i] = MtrPosGrid->Cells[4][i+1].ToDouble()*1000;
            }
            else
            {
                g_MMIComm->m_mmiToSeq.buffer.motTable.dAcc [i] = 0.;

            }
        }

        g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_MT_TABLE;
        if(g_MMIComm->Send()  && g_MMIComm->Recv())
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}
//------------------------------------------------------------------------
void __fastcall TFrmMotorControl::BtnInputMotionDataClick(TObject *Sender)
{
	BtnInputMotionData->Enabled = false;
    BtnSaveMotionData->Enabled = true;
    MtrPosGrid->Options << goEditing;
    MtrPosGrid->Options >> goRowSelect;
    MtrRefreshTimer->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TFrmMotorControl::BtnSaveMotionDataClick(TObject *Sender)
{

    BtnInputMotionData->Enabled = true;
	BtnSaveMotionData->Enabled = false;

    MtrPosGrid->Options >> goEditing;
    MtrPosGrid->Options << goRowSelect;

	if(MtrData_SaveDB() == true)
    {
        if(MtrData_SaveSEQ() == true )
        {
            if(MtrData_ReadDB() == true)
            {
                if(MtrData_ReadSEQ() == true)
                {
                    FrmCdBox->QueryMsg("MOTOR SEQ READ OK", "MOTOR DATA SAVE SUCCESS!", CD_OK );
                }
                else
                {
                	FrmCdBox->QueryMsg("MOTOR SEQ READ FAIL", "MOTOR DATA SAVE FAIL! -> 4STEP", CD_OK );
                }
            }
            else
            {
                FrmCdBox->QueryMsg("MOTOR SEQ READ FAIL", "MOTOR DATA SAVE FAIL! -> 2STEP", CD_OK );
            }
        }
        else
        {
            FrmCdBox->QueryMsg("MOTOR SEQ READ FAIL", "MOTOR DATA SAVE FAIL! -> 2STEP", CD_OK );
        }
    }
    else
    {
    	FrmCdBox->QueryMsg("MOTOR SEQ READ FAIL", "MOTOR DATA SAVE FAIL! -> 1STEP", CD_OK );
    }

	MtrRefreshTimer->Enabled = true;
}
//---------------------------------------------------------------------------


void __fastcall TFrmMotorControl::BtnServoControlClick(TObject *Sender)
{
	if(bServoOnOff  == true)
	{
		FrmCdBox->setFlag(CD_YESNO);
		FrmCdBox->setTitle( "MOTION_CONTROL"  );
		FrmCdBox->setText( "SERVO_OFF"  );

		if( mrYes == FrmCdBox->ShowModal())
		{
			g_MMIComm->m_mmiToSeq.buffer.motControl.nMtNo = _nAxis_no;
			g_MMIComm->m_mmiToSeq.buffer.motControl.nCmd = MTCMD_SERVO_OFF;
			g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_MT_CMD;
            g_MMIComm->Send() && g_MMIComm->Recv();
        }
    }
    else
	{
        FrmCdBox->setFlag(CD_YESNO);
		FrmCdBox->setTitle( "MOTION_CONTROL"  );
		FrmCdBox->setText( "SERVO_ON"  );
		if( mrYes == FrmCdBox->ShowModal())
		{
			g_MMIComm->m_mmiToSeq.buffer.motControl.nMtNo = _nAxis_no;
			g_MMIComm->m_mmiToSeq.buffer.motControl.nCmd = MTCMD_SERVO_ON;
			g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_MT_CMD;
            g_MMIComm->Send() && g_MMIComm->Recv();
        }
    }
}
//---------------------------------------------------------------------------


void __fastcall TFrmMotorControl::PanelTenkeyJogClick(TObject *Sender)
{
	int nTemp = nReadCommunicationDM(tenKeyJog);
	if(nTemp == _JOGMODE_VALUE_DISABLE_)
	{
		FrmCdBox->setFlag(CD_YESNO);
		FrmCdBox->setTitle( "MOTION_CONTROL"  );
		FrmCdBox->setText( "TENKEY MODE ON"  );

		if( mrYes == FrmCdBox->ShowModal())
		{
			nWriteCommunicationDM( _JOGMODE_VALUE_ENABLE_ , tenKeyJog);
        }
    }
    else
	{
        FrmCdBox->setFlag(CD_YESNO);
		FrmCdBox->setTitle( "MOTION_CONTROL"  );
		FrmCdBox->setText( "TENKEY MODE OFF"  );
		if( mrYes == FrmCdBox->ShowModal())
		{
			nWriteCommunicationDM( _JOGMODE_VALUE_DISABLE_ , tenKeyJog);
        }
    }
	nWriteCommunicationDM( _nAxis_no , jogAxisNo);
}
//---------------------------------------------------------------------------


void __fastcall TFrmMotorControl::BtnAxisMotorHomeClick(TObject *Sender)
{
    FrmCdBox->setFlag(CD_YESNO);
	FrmCdBox->setTitle( "MOTION_CONTROL" );
	FrmCdBox->setText("HOME_MOVE_CONTROL" );
	if( mrYes == FrmCdBox->ShowModal())
	{
        g_MMIComm->m_mmiToSeq.buffer.motControl.nMtNo  = _nAxis_no;
        g_MMIComm->m_mmiToSeq.buffer.motControl.nCmd  = MTCMD_HOME;
        g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_MT_CMD;
        g_MMIComm->Send() && g_MMIComm->Recv();
    }
}
//---------------------------------------------------------------------------

void __fastcall TFrmMotorControl::BtnAxisMotorStopClick(TObject *Sender)
{
	FrmCdBox->setFlag(CD_YESNO);
	FrmCdBox->setTitle( "MOTION_CONTROL");
	FrmCdBox->setText("MOTOR_MOVING_STOP");
	if( mrYes == FrmCdBox->ShowModal())
    {
        g_MMIComm->m_mmiToSeq.buffer.motControl.nMtNo = _nAxis_no;
        g_MMIComm->m_mmiToSeq.buffer.motControl.nCmd = MTCMD_STOP;
        g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_MT_CMD;
		g_MMIComm->Send() && g_MMIComm->Recv();
    }
}
//---------------------------------------------------------------------------

void __fastcall TFrmMotorControl::BtnAxisMotorResetClick(TObject *Sender)
{

    FrmCdBox->setFlag(CD_YESNO);
	FrmCdBox->setTitle( "MOTION_CONTROL" );
	FrmCdBox->setText( "MOTOR_STATUS_RESET" );
    if( mrYes == FrmCdBox->ShowModal())
    {
        g_MMIComm->m_mmiToSeq.buffer.motControl.nMtNo =_nAxis_no;
        g_MMIComm->m_mmiToSeq.buffer.motControl.nCmd = MTCMD_RESET;
        g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_MT_CMD;
        g_MMIComm->Send() && g_MMIComm->Recv();
    }
}
//---------------------------------------------------------------------------

void __fastcall TFrmMotorControl::BtnJog4Click(TObject *Sender)
{
	if(RadioButtonRMove->Checked == true)
    {
        FrmCdBox->setFlag(CD_YESNO);
        FrmCdBox->setTitle( "MOTION_CONTROL" );
        FrmCdBox->setText( "POSITIVE_JOG_CONTROL" );
        if( mrYes == FrmCdBox->ShowModal())
        {
            g_MMIComm->m_mmiToSeq.buffer.motControl.nMtNo = _nAxis_no;

            if( RadioButtonRMove->Checked == false )
            {
                g_MMIComm->m_mmiToSeq.buffer.motControl.nCmd = MTCMD_A_MOVE;
            }
            else
            {
                g_MMIComm->m_mmiToSeq.buffer.motControl.nCmd = MTCMD_R_MOVE;
            }

            g_MMIComm->m_mmiToSeq.buffer.motControl.nDir = _MOTOR_NEGATIVE_DIRECTION_;
            g_MMIComm->m_mmiToSeq.buffer.motControl.dPulse =  EditJogPosition->Text.ToDouble() * 1000.0;
            g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_MT_CMD;
            g_MMIComm->Send() && g_MMIComm->Recv();
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TFrmMotorControl::BtnJog2Click(TObject *Sender)
{
	if(RadioButtonRMove->Checked == true)
    {
        FrmCdBox->setFlag(CD_YESNO);
        FrmCdBox->setTitle( "MOTION_CONTROL" );
        FrmCdBox->setText( "NEGATIVE_JOG_CONTROL" );
        if( mrYes == FrmCdBox->ShowModal())
        {
            g_MMIComm->m_mmiToSeq.buffer.motControl.nMtNo = _nAxis_no;

            if( RadioButtonRMove->Checked == false )
            {
                g_MMIComm->m_mmiToSeq.buffer.motControl.nCmd = MTCMD_A_MOVE;
            }
            else
            {
                g_MMIComm->m_mmiToSeq.buffer.motControl.nCmd = MTCMD_R_MOVE;
            }

            g_MMIComm->m_mmiToSeq.buffer.motControl.nDir = _MOTOR_POSITIVE_DIRECTION_;
            g_MMIComm->m_mmiToSeq.buffer.motControl.dPulse =  EditJogPosition->Text.ToDouble() * 1000.0;
            g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_MT_CMD;
            g_MMIComm->Send() && g_MMIComm->Recv();
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TFrmMotorControl::BtnJogSpeedApplyClick(TObject *Sender)
{
	if(EditJogSpeed->Text == "")
    {
    	EditJogSpeed->Text ="0";
    }

    double dData = StrToFloat(EditJogSpeed->Text);
    nWriteCommunicationDM(dData , jogSpeed);

    EditJogSpeed->Text= FloatToStr( nReadCommunicationDM( jogSpeed ) );
}
//---------------------------------------------------------------------------

void __fastcall TFrmMotorControl::BtnJog1MouseDown(TObject *Sender, TMouseButton Button,   //+
          TShiftState Shift, int X, int Y)
{
		if(RadioButtonJogMove->Checked == true)
		{
            g_MMIComm->m_mmiToSeq.buffer.motControl.nMtNo = _nAxis_no;
			g_MMIComm->m_mmiToSeq.buffer.motControl.nCmd  = MTCMD_JOG_MOVE;
			g_MMIComm->m_mmiToSeq.buffer.motControl.nDir =  _MOTOR_NEGATIVE_DIRECTION_;

			g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_MT_CMD;
			g_MMIComm->Send()   && g_MMIComm->Recv();
		}
}
//---------------------------------------------------------------------------

void __fastcall TFrmMotorControl::BtnJog1MouseUp(TObject *Sender, TMouseButton Button,  //+
          TShiftState Shift, int X, int Y)
{
		if(RadioButtonJogMove->Checked == true)
		{
            g_MMIComm->m_mmiToSeq.buffer.motControl.nMtNo = _nAxis_no;
			g_MMIComm->m_mmiToSeq.buffer.motControl.nCmd = MTCMD_JOG_STOP;
			g_MMIComm->m_mmiToSeq.buffer.motControl.nDir   =  _MOTOR_NEGATIVE_DIRECTION_;

			g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_MT_CMD;
			g_MMIComm->Send()   && g_MMIComm->Recv();
		}
}
//---------------------------------------------------------------------------

void __fastcall TFrmMotorControl::BtnIndexMoveClick(TObject *Sender)
{
    FrmCdBox->setFlag(CD_YESNO);
	FrmCdBox->setTitle( "WARNING" );
	FrmCdBox->setText( "INDEX_MOVE" );
	if( mrYes == FrmCdBox->ShowModal())
	{
        g_MMIComm->m_mmiToSeq.nCmd  = CMD_WR_MT_CMD;
		g_MMIComm->m_mmiToSeq.buffer.motControl.nMtNo =_nAxis_no;
        g_MMIComm->m_mmiToSeq.buffer.motControl.nCmd  = MTCMD_INDEX_MOVE;
		g_MMIComm->m_mmiToSeq.buffer.motControl.nCmdIndexNo = _nSelectIndex;
        g_MMIComm->Send();   g_MMIComm->Recv();
    }

}
//---------------------------------------------------------------------------

void __fastcall TFrmMotorControl::BtnJog2MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
    if(RadioButtonJogMove->Checked == true)
    {
        g_MMIComm->m_mmiToSeq.buffer.motControl.nMtNo = _nAxis_no;
        g_MMIComm->m_mmiToSeq.buffer.motControl.nCmd  = MTCMD_JOG_MOVE;
        g_MMIComm->m_mmiToSeq.buffer.motControl.nDir =  _MOTOR_POSITIVE_DIRECTION_;

        g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_MT_CMD;
        g_MMIComm->Send()   && g_MMIComm->Recv();
    }
}
//---------------------------------------------------------------------------

void __fastcall TFrmMotorControl::BtnJog2MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
    if(RadioButtonJogMove->Checked == true)
    {
        g_MMIComm->m_mmiToSeq.buffer.motControl.nMtNo = _nAxis_no;
        g_MMIComm->m_mmiToSeq.buffer.motControl.nCmd = MTCMD_JOG_STOP;
        g_MMIComm->m_mmiToSeq.buffer.motControl.nDir   =  _MOTOR_POSITIVE_DIRECTION_;

        g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_MT_CMD;
        g_MMIComm->Send()  && g_MMIComm->Recv();
    }
}
//---------------------------------------------------------------------------

void __fastcall TFrmMotorControl::BtnAxisConfigClick(TObject *Sender)
{
    FrmCdBox->setFlag(CD_YESNO);
	FrmCdBox->setTitle( "MOTION_CONTROL" );
	FrmCdBox->setText( "Do you attempt to change the motor information?");
    if( mrYes == FrmCdBox->ShowModal())
    {
		MotorAxisConfig->ShowModal();
    }
}
//---------------------------------------------------------------------------


void __fastcall TFrmMotorControl::MtrPosGridDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State)
{
	if(ARow > 0  && (ACol == 5 && (MtrPosGrid->Cells[2][ARow] != MtrPosGrid->Cells[5][ARow])))
	{
    	MtrPosGrid->Canvas->Brush->Color = clRed;
		MtrPosGrid->Canvas->Pen->Color = clBlack;
		MtrPosGrid->Canvas->FillRect( Rect );
		MtrPosGrid->Canvas->Font->Color = clBlack;
		MtrPosGrid->Canvas->FillRect(MtrPosGrid->CellRect(ACol,ARow));
		MtrPosGrid->Canvas->TextRect( Rect, (Rect.Right+Rect.Left)/2, Rect.Top+5, MtrPosGrid->Cells[ACol][ARow] );
	}

	if(ARow > 0  && (ACol == 6 && (MtrPosGrid->Cells[3][ARow] != MtrPosGrid->Cells[6][ARow])))
	{
    	MtrPosGrid->Canvas->Brush->Color = clRed;
		MtrPosGrid->Canvas->Pen->Color = clBlack;
		MtrPosGrid->Canvas->FillRect( Rect );
		MtrPosGrid->Canvas->Font->Color = clBlack;
		MtrPosGrid->Canvas->FillRect(MtrPosGrid->CellRect(ACol,ARow));
		MtrPosGrid->Canvas->TextRect( Rect, (Rect.Right+Rect.Left)/2, Rect.Top+5, MtrPosGrid->Cells[ACol][ARow] );
	}

	if(ARow > 0  && (ACol == 7 && (MtrPosGrid->Cells[4][ARow] != MtrPosGrid->Cells[7][ARow])))
	{
    	MtrPosGrid->Canvas->Brush->Color = clRed;
        MtrPosGrid->Canvas->Pen->Color = clBlack;
		MtrPosGrid->Canvas->FillRect( Rect );
		MtrPosGrid->Canvas->Font->Color = clBlack;
		MtrPosGrid->Canvas->FillRect(MtrPosGrid->CellRect(ACol,ARow));
		MtrPosGrid->Canvas->TextRect( Rect, (Rect.Right+Rect.Left)/2, Rect.Top+5, MtrPosGrid->Cells[ACol][ARow] );
	}
}

//---------------------------------------------------------------------------

void __fastcall TFrmMotorControl::BtnAxisSelectClick(TObject *Sender)
{
	AxisSelectForm->AxisSelect_Initialize(this);
}
//---------------------------------------------------------------------------

