//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FrmMotorControlScrn.h"
#include "BaseComm.h"
#include "MainFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "iComponent"
#pragma link "iCustomComponent"
#pragma link "iLed"
#pragma link "iLedRectangle"
#pragma link "iVCLComponent"
#pragma resource "*.dfm"
TFrmMotorControl *FrmMotorControl;

#define   _MOTOR_IDNEX_COUNT_                    50

//---------------------------------------------------------------------------
__fastcall TFrmMotorControl::TFrmMotorControl(TComponent* Owner)
	: TForm(Owner)
{
	MtrPosGrid->Cells[0][0] = "ID";
    MtrPosGrid->Cells[1][0] = "INDEX NAME";
    MtrPosGrid->Cells[2][0] = "SET POS";
    MtrPosGrid->Cells[3][0] = "SET SPEED";
    MtrPosGrid->Cells[4][0] = "ACT POS";
    MtrPosGrid->Cells[5][0] = "ACT SPEED";
}

//---------------------------------------------------------------------------
void __fastcall TFrmMotorControl::Motorscreen_Initialize(int nLeft)  //left = true
{
	MtrPosGrid->RowCount = 51;

	for( int i = 0; i < MtrPosGrid->RowCount; i++ )
	{
		MtrPosGrid->Cells[ 0 ][ i + 1 ] = IntToStr( i );
	}

	MtrRefreshTimer->Enabled = true;

	BtnInputMotionData->Enabled = true;
	BtnSaveMotionData->Enabled = false;

    nMtrLeftRight = nLeft;

    for( int nAxisIndex = 0; nAxisIndex < MAX_MT_NO; nAxisIndex++ )
    {
    	TBitBtn* CloneAxisBtn = (TBitBtn*)FindComponent("BtnAxis" + IntToStr(nAxisIndex));
        CloneAxisBtn->Enabled = true;
        CloneAxisBtn->Caption = this->MtrAxisName_ReadDB(nAxisIndex);
    }

	MtrAxis_SelectedProcess(0);

    EditJogSpeed->Text= FloatToStr( g_pNvMem->GetNDm( jogSpeed ) );

    _nSelectIndex = 0;

}
//---------------------------------------------------------------------------


void __fastcall TFrmMotorControl::MtrPosGridSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect)
{
	if(ARow > 0)
	{
	   	_nSelectIndex = ARow -1 ;
		PanelMtrSelectIndex->Caption = "SELECT : " + IntToStr(_nSelectIndex) + " :::  POS: " +  MtrPosGrid->Cells[2][ARow] + "SPD: " +  MtrPosGrid->Cells[3][ARow];
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmMotorControl::MtrRefreshTimerTimer(TObject *Sender)
{

   	MtrPostionLabel->Caption = FloatToStrF(g_pNvMem->m_pSharedMem->mtMonitor[_nAxis_no].dRealCnt/1000.0, ffFixed, 10, 3 );

    int nValue =  g_pNvMem->m_pSharedMem->mtMonitor[_nAxis_no].nPosNo;

	if(g_pNvMem->m_pSharedMem->mtMonitor[_nAxis_no].bLimitCw == TRUE)
	{
		Status_Led(MtrPanelLed1 ,_STATUS_LED_GREEN_ , true , "ON");
	}
	else
	{
		Status_Led(MtrPanelLed1 ,_STATUS_LED_GREEN_ , false , "OFF");
	}

	if(g_pNvMem->m_pSharedMem->mtMonitor[_nAxis_no].bHome == TRUE)
	{
		Status_Led(MtrPanelLed2 ,_STATUS_LED_GREEN_ , true , "ON");
	}
	else
	{
		Status_Led(MtrPanelLed2 ,_STATUS_LED_GREEN_ , false , "OFF");
	}

	if(g_pNvMem->m_pSharedMem->mtMonitor[_nAxis_no].bDriving == TRUE)
	{
		Status_Led(MtrPanelLed3 ,_STATUS_LED_GREEN_ , true , "ON");
	}
	else
	{
		Status_Led(MtrPanelLed3 ,_STATUS_LED_GREEN_ , false , "OFF");
	}

	if(g_pNvMem->m_pSharedMem->mtMonitor[_nAxis_no].bOrg == TRUE)
	{
		Status_Led(MtrPanelLed4 ,_STATUS_LED_GREEN_ , true , "ON");
	}
	else
	{
		Status_Led(MtrPanelLed4 ,_STATUS_LED_GREEN_ , false , "OFF");
	}

	if(g_pNvMem->m_pSharedMem->mtMonitor[_nAxis_no].bAlarm == TRUE)
	{
		Status_Led(MtrPanelLed5 ,_STATUS_LED_GREEN_ , true , "ON");
	}
	else
	{
		Status_Led(MtrPanelLed5 ,_STATUS_LED_GREEN_ , false , "OFF");
	}

	if(g_pNvMem->m_pSharedMem->mtMonitor[_nAxis_no].bLimitCCw == TRUE)
	{
		Status_Led(MtrPanelLed6 ,_STATUS_LED_GREEN_ , true , "ON");
	}
	else
	{
		Status_Led(MtrPanelLed6 ,_STATUS_LED_GREEN_ , false , "OFF");
	}

	if(g_pNvMem->m_pSharedMem->mtMonitor[_nAxis_no].bServoOn == TRUE)
	{
		bServoOnOff = true;
		Status_Led(PanelServoOnOff ,_STATUS_LED_GREEN_ , true , "SERVO ON");
	}
	else
	{
		bServoOnOff = false;
		Status_Led(PanelServoOnOff ,_STATUS_LED_GREEN_ , false , "SERVO OFF");
	}
}
//---------------------------------------------------------------------------

void TFrmMotorControl::MtrAxis_SelectedProcess( int nSelectAxis )
{
	_nAxis_no =  nSelectAxis;
    for( int nAxisIndex = 0; nAxisIndex < MAX_MT_NO; nAxisIndex++ )
    {
    	TBitBtn* CloneAxisBtn = (TBitBtn*)FindComponent("BtnAxis" + IntToStr(nAxisIndex));
        CloneAxisBtn->Enabled = true;

        CloneAxisBtn->Enabled = true;
		if(nAxisIndex ==  nSelectAxis)
        {
			CloneAxisBtn->Enabled = false;
			MtrAxisName_ReadDB(nSelectAxis);
        }
    }

	this->MtrData_ReadDB();
	this->MtrData_ReadSEQ(nMtrLeftRight);

}
//---------------------------------------------------------------------------

void __fastcall TFrmMotorControl::BtnAxis0Click(TObject *Sender)
{
	int nTag = dynamic_cast<TBitBtn*>(Sender)->Tag;
	MtrAxis_SelectedProcess(nTag);
}
//---------------------------------------------------------------------------
String    TFrmMotorControl::MtrAxisName_ReadDB(int nAxis)
{
	TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\MotorName.ini");
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\MotorName.ini"))
	{
    	int  nXYZDirect =  ini->ReadInteger("AXISDir","DIR"+IntToStr(nAxis),1);

        MtrJogBtnDisplay(nXYZDirect);

		String StrRet = ini->ReadString("AXISNAME","AXIS"+IntToStr(nAxis),"AXISNAME"+IntToStr(nAxis));
        return StrRet;
    }
    else
    {
		return "MOTOR NAME";
    }
    delete ini;

}
//------------------------------------------------------------------------
//1: X  2: Y   3 : Z
void    TFrmMotorControl::MtrJogBtnDisplay(int nJogdirection)
{
	BtnJog1->Enabled = false;
	BtnJog2->Enabled = false;
	BtnJog3->Enabled = false;
	BtnJog4->Enabled = false;
	BtnJog5->Enabled = false;
	BtnJog6->Enabled = false;

	if(nJogdirection == 2)
    {
        BtnJog3->Enabled = true;
        BtnJog4->Enabled = true;
    }
    else if(nJogdirection == 3)
    {
        BtnJog5->Enabled = true;
        BtnJog6->Enabled = true;
    }
    else
    {
        BtnJog1->Enabled = true;
        BtnJog2->Enabled = true;
    }
}
//------------------------------------------------------------------------

bool    TFrmMotorControl::MtrData_ReadDB()
{
	int nGrpNo, nRcpNo;
	if(nMtrLeftRight ==  _LEFT_STAGE_) // LeftStage
	{
		nGrpNo = nReadLeftGroupNo();
		nRcpNo = nReadLeftRecipeNo();
	}
	else
	{
		nGrpNo = nReadRightGroupNo();
		nRcpNo = nReadRightRecipeNo();
	}

	TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(nGrpNo)+"\\RCP"+IntToStr(nRcpNo)+"\\Motor"+ IntToStr(_nAxis_no)+".ini");
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(nGrpNo)+"\\RCP"+IntToStr(nRcpNo)+"\\Motor"+ IntToStr(_nAxis_no)+".ini"))
	{
		for( int nRow = 0; nRow <= MtrPosGrid->RowCount - 1; nRow++ )
		{
        	MtrPosGrid->Cells[1][nRow+1] = ini->ReadString("INDEXNAME","INDEXNAME"+IntToStr(nRow),"INDEXNAME"+IntToStr(nRow));
            MtrPosGrid->Cells[2][nRow+1] = ini->ReadString("INDEXPOS","POSITION"+IntToStr(nRow),IntToStr(nRow));
            MtrPosGrid->Cells[3][nRow+1] = ini->ReadString("INDEXSPD","SPEED"+IntToStr(nRow),IntToStr(nRow));

        }
        return true;
    }
    else
    {
		return false;
    }
    delete ini;

}
//------------------------------------------------------------------------
bool    TFrmMotorControl::MtrData_ReadSEQ(int nLeftRight)
{
	g_MMIComm->m_mmiToSeq.cmd = CMD_RD_MTTABLE;
    g_MMIComm->m_mmiToSeq.buffer.mtData._nLR = nLeftRight;
	g_MMIComm->m_mmiToSeq.buffer.mtData._nMtNo = _nAxis_no;

	if ( g_MMIComm->Send() &&  g_MMIComm->Recv() )
	{
		for( int nRow = 0; nRow <= MtrPosGrid->RowCount; nRow++ )
		{
			MtrPosGrid->Cells[4][nRow+1] =  FloatToStr(g_MMIComm->m_mmiToSeq.buffer.mtData._table._dPos[nRow]/1000);
			MtrPosGrid->Cells[5][nRow+1] =  FloatToStr(g_MMIComm->m_mmiToSeq.buffer.mtData._table._dVel[nRow]/1000);

//            MtrPosGrid->Cells[4][nRow+1] =  FloatToStr(g_pNvMem->m_pNv->_mtTable2->dPos[nRow]);
//            MtrPosGrid->Cells[5][nRow+1] =  FloatToStr(g_pNvMem->m_pNv->_mtTable2->dVel[nRow]);
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
	if(nMtrLeftRight ==  _LEFT_STAGE_) // LeftStage
	{
		nGrpNo = nReadLeftGroupNo();
		nRcpNo = nReadLeftRecipeNo();
	}
	else
	{
		nGrpNo = nReadRightGroupNo();
		nRcpNo = nReadRightRecipeNo();
    }


	TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(nGrpNo)+"\\RCP"+IntToStr(nRcpNo)+"\\Motor"+ IntToStr(_nAxis_no)+".ini");
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(nGrpNo)+"\\RCP"+IntToStr(nRcpNo)+"\\Motor"+ IntToStr(_nAxis_no)+".ini"))
	{
    	for(int i=0; i<_MOTOR_IDNEX_COUNT_;i++)
		{
			ini->WriteString("INDEXNAME","INDEXNAME"+IntToStr(i),MtrPosGrid->Cells[1][i+1]);
            ini->WriteString("INDEXPOS","POSITION"+IntToStr(i),MtrPosGrid->Cells[2][i+1]);
            ini->WriteString("INDEXSPD","SPEED"+IntToStr(i),MtrPosGrid->Cells[3][i+1]);
        }
        return true;
    }
    else
    {
		return false;
    }
    delete ini;

}
//------------------------------------------------------------------------
bool    TFrmMotorControl::MtrData_SaveSEQ(int nLeftRight)
{
    g_MMIComm->m_mmiToSeq.cmd  = CMD_RD_MTTABLE;
    g_MMIComm->m_mmiToSeq.buffer.mtData._nLR  = nLeftRight;
    g_MMIComm->m_mmiToSeq.buffer.mtData._nMtNo = _nAxis_no;

    if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
    {
        for(int i=0; i<_MOTOR_IDNEX_COUNT_; i++)
        {
            if(MtrPosGrid->Cells[2][i+1] != "")
            {
                g_MMIComm->m_mmiToSeq.buffer.mtData._table._dPos [i] = MtrPosGrid->Cells[2][i+1].ToDouble()*1000;
            }
            else
            {
                g_MMIComm->m_mmiToSeq.buffer.mtData._table._dPos [i] = 0.;

            }

            if(MtrPosGrid->Cells[3][i+1] !="")
            {
                g_MMIComm->m_mmiToSeq.buffer.mtData._table._dVel [i] = MtrPosGrid->Cells[3][i+1].ToDouble()*1000;
            }
            else
            {
                g_MMIComm->m_mmiToSeq.buffer.mtData._table._dVel [i] = 0.;

            }

        }

        g_MMIComm->m_mmiToSeq.cmd = CMD_WR_MTTABLE;
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
	MtrRefreshTimer->Enabled = false;
    MtrPosGrid->Options << goEditing;
    MtrPosGrid->Options >> goRowSelect;

}
//---------------------------------------------------------------------------

void __fastcall TFrmMotorControl::BtnSaveMotionDataClick(TObject *Sender)
{
//    if( IsDebuggerPresent() == false && g_pNvMem->GetNDm( machineState ) != 0 )
//    {
//	//	FrmCdBox->QueryMsg(g_langs.dictionary( "MACHINE_WORKING" ),
////							g_langs.dictionary( "MACHINE_WORKING_DESC" ), CD_OK );
////        return;
//    }

    BtnInputMotionData->Enabled = true;
	BtnSaveMotionData->Enabled = false;

    MtrPosGrid->Options >> goEditing;
    MtrPosGrid->Options << goRowSelect;

	if(MtrData_SaveDB() == true)
    {
		if(Recipe_dataBothsidecheck() == true)
    	{
        	if(MtrData_SaveSEQ(_LEFT_STAGE_) == true && MtrData_SaveSEQ(_RIGHT_STAGE_) == true )
    		{
                if(MtrData_ReadDB() == false)
                {
                    FrmCdBox->QueryMsg( "MOTOR DB READ FAIL", "MOTOR Data Read Fail", CD_OK );
                }

                if(MtrData_ReadSEQ(_LEFT_STAGE_) == false)
                {
                    FrmCdBox->QueryMsg( "MOTOR SEQ READ FAIL", "MOTOR SEQ Read Fail", CD_OK );
                }

                if(nMtrLeftRight == _LEFT_STAGE_)
				{
					if(((TFrmMotorControl*)MainFrmForm->pStage2SubFrm[0] != NULL))
					{
						if(((TFrmMotorControl*)MainFrmForm->pStage2SubFrm[0])->_nAxis_no == _nAxis_no)
						{
							((TFrmMotorControl*)MainFrmForm->pStage2SubFrm[0])->MtrData_ReadSEQ(_RIGHT_STAGE_);
							((TFrmMotorControl*)MainFrmForm->pStage2SubFrm[0])->MtrData_ReadDB();
						}
					}
				}
				if(nMtrLeftRight == _RIGHT_STAGE_)
				{
					if(((TFrmMotorControl*)MainFrmForm->pStage1SubFrm[0] != NULL))
					{
						if(((TFrmMotorControl*)MainFrmForm->pStage1SubFrm[0])->_nAxis_no == _nAxis_no)
						{
							((TFrmMotorControl*)MainFrmForm->pStage1SubFrm[0])->MtrData_ReadSEQ(_LEFT_STAGE_);
							((TFrmMotorControl*)MainFrmForm->pStage1SubFrm[0])->MtrData_ReadDB();
						}
					}
                }
            }
            else
            {
    			FrmCdBox->QueryMsg( "MOTOR DATA SAVE FAIL TO SEQ ", "MOTOR DATA SAVE Fail", CD_OK );
            }
        }
        else
        {
        	if(MtrData_SaveSEQ(nMtrLeftRight) == true )
    		{
                if(MtrData_ReadDB() == false)
                {
                    FrmCdBox->QueryMsg( "MOTOR DB READ FAIL", "MOTOR Data Read Fail", CD_OK );
                }
                if(MtrData_ReadSEQ(nMtrLeftRight) == false)
                {
                    FrmCdBox->QueryMsg( "MOTOR SEQ READ FAIL", "MOTOR SEQ Read Fail", CD_OK );
                }
            }
            else
            {
    			FrmCdBox->QueryMsg( "MOTOR DATA SAVE FAIL TO SEQ ", "MOTOR DATA SAVE Fail", CD_OK );
            }
        }
    }
    else
    {
    	FrmCdBox->QueryMsg( "MOTOR DATA SAVE FAIL on  1STEP ", "MOTOR DATA SAVE Fail", CD_OK );
    }

	MtrRefreshTimer->Enabled = true;
}
//---------------------------------------------------------------------------




void __fastcall TFrmMotorControl::BtnServoControlClick(TObject *Sender)
{
//    if( IsDebuggerPresent() == false && g_pNvMem->GetNDm( machineState ) != 0 )
//    {
//		FrmCdBox->QueryMsg(g_langs.dictionary( "MACHINE_WORKING" ),
//							g_langs.dictionary( "MACHINE_WORKING_DESC" ), CD_OK );
//		return;
//    }

	if(bServoOnOff == true)
	{
		FrmCdBox->setFlag(CD_YESNO);
		FrmCdBox->setTitle( "MOTION_CONTROL"  );
		FrmCdBox->setText( "SERVO_OFF"  );

		if( mrYes == FrmCdBox->ShowModal())
		{
			g_MMIComm->m_mmiToSeq.buffer.mtData._nMtNo =_nAxis_no;
            g_MMIComm->m_mmiToSeq.buffer.mtData._nLR = nMtrLeftRight;
			g_MMIComm->m_mmiToSeq.buffer.mtData._control._nControlType = MTCMD_SERVO_OFF;
			g_MMIComm->m_mmiToSeq.cmd = CMD_WR_MT_CMD;
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
			g_MMIComm->m_mmiToSeq.buffer.mtData._nMtNo =_nAxis_no;
            g_MMIComm->m_mmiToSeq.buffer.mtData._nLR = nMtrLeftRight;
			g_MMIComm->m_mmiToSeq.buffer.mtData._control._nControlType = MTCMD_SERVO_ON;
            g_MMIComm->m_mmiToSeq.cmd = CMD_WR_MT_CMD;
            g_MMIComm->Send() && g_MMIComm->Recv();
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TFrmMotorControl::BtnAxisMotorHomeClick(TObject *Sender)
{
    FrmCdBox->setFlag(CD_YESNO);
	FrmCdBox->setTitle( "MOTION_CONTROL" );
	FrmCdBox->setText("HOME_MOVE_CONTROL" );
	if( mrYes == FrmCdBox->ShowModal())
	{
        g_MMIComm->m_mmiToSeq.buffer.mtData._nMtNo  = _nAxis_no;
        g_MMIComm->m_mmiToSeq.buffer.mtData._nLR  = nMtrLeftRight;
        g_MMIComm->m_mmiToSeq.buffer.mtData._control._nControlType = MTCMD_HOME;
        g_MMIComm->m_mmiToSeq.cmd = CMD_WR_MT_CMD;
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
        g_MMIComm->m_mmiToSeq.buffer.mtData._nMtNo = _nAxis_no;
        g_MMIComm->m_mmiToSeq.buffer.mtData._nLR  = nMtrLeftRight;
        g_MMIComm->m_mmiToSeq.buffer.mtData._control._nControlType = MTCMD_STOP;
        g_MMIComm->m_mmiToSeq.cmd = CMD_WR_MT_CMD;
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
        g_MMIComm->m_mmiToSeq.buffer.mtData._nMtNo =_nAxis_no;
        g_MMIComm->m_mmiToSeq.buffer.mtData._nLR  = nMtrLeftRight;
        g_MMIComm->m_mmiToSeq.buffer.mtData._control._nControlType = MTCMD_RESET;
        g_MMIComm->m_mmiToSeq.cmd = CMD_WR_MT_CMD;
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
            g_MMIComm->m_mmiToSeq.buffer.mtData._nMtNo = _nAxis_no;
            g_MMIComm->m_mmiToSeq.buffer.mtData._nLR  = nMtrLeftRight;

            if( RadioButtonRMove->Checked == false )
            {
                g_MMIComm->m_mmiToSeq.buffer.mtData._control._nControlType = MTCMD_A_MOVE;
            }
            else
            {
                g_MMIComm->m_mmiToSeq.buffer.mtData._control._nControlType = MTCMD_R_MOVE;
            }

            g_MMIComm->m_mmiToSeq.buffer.mtData._control._nDir = 1;
            g_MMIComm->m_mmiToSeq.buffer.mtData._control._dPulse =  EditJogPosition->Text.ToDouble() * 1000.0;
            g_MMIComm->m_mmiToSeq.cmd = CMD_WR_MT_CMD;
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
            g_MMIComm->m_mmiToSeq.buffer.mtData._nMtNo = _nAxis_no;
            g_MMIComm->m_mmiToSeq.buffer.mtData._nLR  = nMtrLeftRight;

            if( RadioButtonRMove->Checked == false )
            {
                g_MMIComm->m_mmiToSeq.buffer.mtData._control._nControlType = MTCMD_A_MOVE;
            }
            else
            {
                g_MMIComm->m_mmiToSeq.buffer.mtData._control._nControlType = MTCMD_R_MOVE;
            }

            g_MMIComm->m_mmiToSeq.buffer.mtData._control._nDir = 0;
            g_MMIComm->m_mmiToSeq.buffer.mtData._control._dPulse =  EditJogPosition->Text.ToDouble() * 1000.0;
            g_MMIComm->m_mmiToSeq.cmd = CMD_WR_MT_CMD;
            g_MMIComm->Send() && g_MMIComm->Recv();
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TFrmMotorControl::BtnJogSpeedApplyClick(TObject *Sender)   //DM81
{
	if(EditJogSpeed->Text == "")
    {
    	EditJogSpeed->Text ="0";
    }

    double dData = StrToFloat(EditJogSpeed->Text);
   	g_pNvMem->SetNDm(jogSpeed, dData);

    EditJogSpeed->Text= FloatToStr( g_pNvMem->GetNDm( jogSpeed ) );
}
//---------------------------------------------------------------------------


void __fastcall TFrmMotorControl::BtnJog1MouseDown(TObject *Sender, TMouseButton Button,   //+
          TShiftState Shift, int X, int Y)
{
		if(RadioButtonJogMove->Checked == true)
		{
            g_MMIComm->m_mmiToSeq.buffer.mtData._nMtNo = _nAxis_no;
            g_MMIComm->m_mmiToSeq.buffer.mtData._nLR  = nMtrLeftRight;
			g_MMIComm->m_mmiToSeq.buffer.mtData._control._nControlType  = MTCMD_JOG_MOVE;
			g_MMIComm->m_mmiToSeq.buffer.mtData._control._nDir =  1;

			g_MMIComm->m_mmiToSeq.cmd = CMD_WR_MT_CMD;
			g_MMIComm->Send()   && g_MMIComm->Recv();
		}
}
//---------------------------------------------------------------------------

void __fastcall TFrmMotorControl::BtnJog1MouseUp(TObject *Sender, TMouseButton Button,  //+
          TShiftState Shift, int X, int Y)
{
		if(RadioButtonJogMove->Checked == true)
		{
            g_MMIComm->m_mmiToSeq.buffer.mtData._nMtNo = _nAxis_no;
            g_MMIComm->m_mmiToSeq.buffer.mtData._nLR  = nMtrLeftRight;
			g_MMIComm->m_mmiToSeq.buffer.mtData._control._nControlType = MTCMD_JOG_STOP;
			g_MMIComm->m_mmiToSeq.buffer.mtData._control._nDir   =  1;

			g_MMIComm->m_mmiToSeq.cmd = CMD_WR_MT_CMD;
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
        g_MMIComm->m_mmiToSeq.cmd  = CMD_WR_MT_CMD;
		g_MMIComm->m_mmiToSeq.buffer.mtData._nMtNo =_nAxis_no;
        g_MMIComm->m_mmiToSeq.buffer.mtData._nLR  = nMtrLeftRight;
        g_MMIComm->m_mmiToSeq.buffer.mtData._control._nControlType  = MTCMD_INDEX_MOVE;
		g_MMIComm->m_mmiToSeq.buffer.mtData._control._nCmdIndexNo = _nSelectIndex;
        g_MMIComm->Send();   g_MMIComm->Recv();
    }

}
//---------------------------------------------------------------------------

void __fastcall TFrmMotorControl::BtnJog2MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
    if(RadioButtonJogMove->Checked == true)
    {
        g_MMIComm->m_mmiToSeq.buffer.mtData._nMtNo = _nAxis_no;
        g_MMIComm->m_mmiToSeq.buffer.mtData._nLR  = nMtrLeftRight;
        g_MMIComm->m_mmiToSeq.buffer.mtData._control._nControlType  = MTCMD_JOG_MOVE;
        g_MMIComm->m_mmiToSeq.buffer.mtData._control._nDir =  0;

        g_MMIComm->m_mmiToSeq.cmd = CMD_WR_MT_CMD;
        g_MMIComm->Send()   && g_MMIComm->Recv();
    }
}
//---------------------------------------------------------------------------

void __fastcall TFrmMotorControl::BtnJog2MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
    if(RadioButtonJogMove->Checked == true)
    {
        g_MMIComm->m_mmiToSeq.buffer.mtData._nMtNo = _nAxis_no;
        g_MMIComm->m_mmiToSeq.buffer.mtData._nLR  = nMtrLeftRight;
        g_MMIComm->m_mmiToSeq.buffer.mtData._control._nControlType = MTCMD_JOG_STOP;
        g_MMIComm->m_mmiToSeq.buffer.mtData._control._nDir   =  0;

        g_MMIComm->m_mmiToSeq.cmd = CMD_WR_MT_CMD;
        g_MMIComm->Send()   && g_MMIComm->Recv();
    }
}
//---------------------------------------------------------------------------

