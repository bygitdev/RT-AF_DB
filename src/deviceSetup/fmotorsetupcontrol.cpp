//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fmotorsetupcontrol.h"
#include "BaseComm.h"
//#include "RMoveScrn.h"
#include "MainFormScrn.h"
#include "Include.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMtrSetupControl *frmMtrSetupControl;

#define _TENKEY_MOTION_SPEED_DM_       98
//---------------------------------------------------------------------------
__fastcall TfrmMtrSetupControl::TfrmMtrSetupControl(TComponent* Owner)
	: TForm(Owner)
{
	_axisNum = 10;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMtrSetupControl::SpeedButton11Click(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMtrSetupControl::FormCreate(TObject *Sender)
{
	StringGrid1->Cells[0][0] = "REAL INDEX";
    StringGrid1->Cells[1][0] = "POSITION";
	StringGrid1->Cells[2][0] = "SET VALUE";
	StringGrid1->Cells[3][0] = "ACTUAL";
}
//---------------------------------------------------------------------------
void	TfrmMtrSetupControl::SetAxisNumber(int num)
{
 	_axisNum = num;
}
//---------------------------------------------------------------------------
void	TfrmMtrSetupControl::regen()
{
	PanelTitle->Caption = ReadStringFromRootInifile("MotorName.ini","AXISNAME","AXIS"+IntToStr(_axisNum));

	String imageFileName = ExtractFilePath(Application->ExeName)+"resource\\motor\\" + ReadStringFromRootInifile("DeviceSetup.ini","AXIS_"+IntToStr(_axisNum),"IMAGE");
	Image1->Picture->LoadFromFile(imageFileName);

	int count = ReadIntegerFromRootInifile("DeviceSetup.ini","AXIS_"+IntToStr(_axisNum),"POSITION_COUNT");
    StringGrid1->RowCount = count+1;

	String cmnIni = "system\\GRP0\\RCP0\\Motor"+ IntToStr(_axisNum)+".ini";

	TIniFile *rcpIni = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(nReadGroupNo())+"\\RCP"+IntToStr((int)nReadRecipeNo())+"\\Motor"+ IntToStr(_axisNum)+".ini");
	TIniFile *nameIni = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\MotorIndexName.ini");


	g_MMIComm->m_mmiToSeq.nCmd  = CMD_RD_MT_TABLE;
	g_MMIComm->m_mmiToSeq.buffer.motTable.nMtNo = _axisNum;

	bool comm = false;
	if ( g_MMIComm->Send() &&  g_MMIComm->Recv()) comm = true;

	for(int i=0; i < count; i++)
	{
    	int index = ReadIntegerFromRootInifile("DeviceSetup.ini","AXIS_"+IntToStr(_axisNum),"POSITION_INDEX"+IntToStr(i));
     	StringGrid1->Cells[0][i+1] = IntToStr(index);
		StringGrid1->Cells[1][i+1] = ReadStringFromRootInifile("MotorIndexName.ini","INDEXNAME"+IntToStr(_axisNum),"INDEXNAME"+IntToStr(index));
		if(nameIni->ReadBool("INDEXNAME"+IntToStr(_axisNum),"COMMON"+IntToStr(index),true))
		{
			StringGrid1->Cells[2][i+1] = ReadStringFromRootInifile(cmnIni,"INDEXPOS","POSITION"+IntToStr(index));
		}
		else
		{
			StringGrid1->Cells[2][i+1] = rcpIni->ReadString("INDEXPOS","POSITION"+IntToStr(index),"0");
		}

		StringGrid1->Cells[3][i+1] = "";

		if(comm)
		{
			StringGrid1->Cells[3][i+1]  =  FloatToStr(g_MMIComm->m_mmiToSeq.buffer.motTable.dPos[index]/1000);
		}

	}

	delete nameIni;
	delete rcpIni;

    PanelSelect->Caption = " [" + StringGrid1->Cells[0][1] + "] " + StringGrid1->Cells[1][1];
    PanelOrgPos->Caption =  StringGrid1->Cells[2][1];
    PanelSelect->Tag = StringGrid1->Cells[0][1].ToInt();
    _pkgID = ReadIntegerFromRootInifile("DeviceSetup.ini","AXIS_"+IntToStr(_axisNum),"POSITION_INDEX"+IntToStr(0));
}
//---------------------------------------------------------------------------
void __fastcall TfrmMtrSetupControl::FormShow(TObject *Sender)
{
	this->regen();
}
//---------------------------------------------------------------------------
String 	TfrmMtrSetupControl::get_string_offset_value(int number)
{
	int index = ReadIntegerFromRootInifile("DeviceSetup.ini","AXIS_"+IntToStr(_axisNum),"PKG_INDEX"+IntToStr(number));
    double value = dReadPkgData(index);
	return FloatToStrF(value,ffFixed,10,3);
}
//---------------------------------------------------------------------------
void __fastcall TfrmMtrSetupControl::SpeedButton12Click(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;


	int index = PanelSelect->Tag;
	double value = PanelRealPos->Caption.ToDouble();

	FrmCdBox->setFlag(CD_YESNO);
	FrmCdBox->setTitle( "PARAMETER SAVE" );
	FrmCdBox->setText( "Index " + PanelSelect->Caption + " paramer will be change " + FloatToStr(value));
	if( mrYes == FrmCdBox->ShowModal())
	{
		int nGrpNo, nRcpNo;
		nGrpNo = nReadGroupNo();
		nRcpNo = nReadRecipeNo();

		String strCmnPath = ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP0\\RCP0\\Motor"+ IntToStr(_axisNum)+".ini";
		String StrPath = ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(nGrpNo)+"\\RCP"+IntToStr(nRcpNo)+"\\Motor"+ IntToStr(_axisNum)+".ini";

		TIniFile *cmnIni = new TIniFile(strCmnPath);
		TIniFile *ini = new TIniFile(StrPath);

		if(NULL == ini || NULL == cmnIni)
		{
			MainForm->MachineHistoryData("User Motor Setup Screen : Can not access motor DB files (recipe " + IntToStr(nGrpNo) + "-" + IntToStr(nRcpNo) + ")");
			return;
		}

		ini->WriteString("INDEXPOS","POSITION"+IntToStr(index),FloatToStr(value));
		cmnIni->WriteString("INDEXPOS","POSITION"+IntToStr(index),FloatToStr(value));

		MainForm->MachineHistoryData("User Motor Setup Screen Parameter Saved : INDEX=" + IntToStr(index) + ", VALUE=" + FloatToStr(value));

		if(MainForm->b_TpConnect)
		{
			String sMotorName = ReadStringFromRootInifile("MotorName.ini","AXISNAME","AXIS"+IntToStr(_axisNum));
			String strData = "", strIndex = "";

			{
				strIndex= "'"+PanelSelect->Caption+"_POS'";
				strData = "[2,"+PanelOrgPos->Caption+","+PanelRealPos->Caption+"]";
				g_pTpBase->logConfigure(sMotorName.c_str(),L"CHANGE",L"'CHANGE_ITEM'",strIndex.c_str(),L"'VALUE'",strData.c_str());
			}
		}

		delete cmnIni;
		delete ini;

		g_MMIComm->m_mmiToSeq.nCmd  = CMD_RD_MT_TABLE;
		g_MMIComm->m_mmiToSeq.buffer.motTable.nMtNo = _axisNum;

		if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
		{
			g_MMIComm->m_mmiToSeq.buffer.motTable.dPos [index] = value*1000;
			g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_MT_TABLE;
			if(!g_MMIComm->Send() || !g_MMIComm->Recv())
			{
				MainForm->MachineHistoryData("User Motor Setup Screen error : DB parm saved, but can not save SEQ date");
			}
		}

	  this->regen();
	}
}
//---------------------------------------------------------------------------


void __fastcall TfrmMtrSetupControl::Timer1Timer(TObject *Sender)
{
    g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_MT_STATUS;

	g_MMIComm->m_mmiToSeq.buffer.motStatus.nMtNo = _axisNum;
    if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
    {
		PanelRealPos->Caption = FloatToStrF(g_MMIComm->m_mmiToSeq.buffer.motStatus.dRealCnt/1000.0, ffFixed, 10, 3 );

		this->panel_led(PanelHome, g_MMIComm->m_mmiToSeq.buffer.motStatus.bHome);
		this->panel_led(PanelDrive, g_MMIComm->m_mmiToSeq.buffer.motStatus.bDriving);
		this->panel_led(PanelAlarm, g_MMIComm->m_mmiToSeq.buffer.motStatus.bAlarm);
		this->panel_led(PanelServo, g_MMIComm->m_mmiToSeq.buffer.motStatus.bServoOn);
    }

    this->panel_led(PanelTenkey, nReadCommunicationDM(tenKeyJog));
}
//---------------------------------------------------------------------------
void	TfrmMtrSetupControl::panel_led(TPanel* panel, bool flag)
{
	if(flag)
	{
		panel->Color = clLime;
		panel->Font->Color = clBlack;
	}
	else
	{
		panel->Color = clGray;
		panel->Font->Color = clWhite;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMtrSetupControl::StringGrid1SelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect)
{
	if(ARow > 0)
    {
     	PanelSelect->Caption = " [" + StringGrid1->Cells[0][ARow] + "] " + StringGrid1->Cells[1][ARow];
        PanelOrgPos->Caption =  StringGrid1->Cells[2][ARow];
        PanelSelect->Tag = StringGrid1->Cells[0][ARow].ToInt();
        _pkgID = ReadIntegerFromRootInifile("DeviceSetup.ini","AXIS_"+IntToStr(_axisNum),"PKG_INDEX"+IntToStr(ARow-1));
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMtrSetupControl::SpeedButton1Click(TObject *Sender)
{
	PanelRvalue->Caption = dynamic_cast<TSpeedButton*>(Sender)->Caption;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMtrSetupControl::SpeedButton7Click(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	#define   _MOTOR_POSITIVE_DIRECTION_                    1
    #define   _MOTOR_NEGATIVE_DIRECTION_                    0

	int dir = dynamic_cast<TSpeedButton*>(Sender)->Tag;


    String strDir = "POSITIVE";
    if(dir == _MOTOR_NEGATIVE_DIRECTION_) strDir = "NEGATIVE";

    FrmCdBox->setFlag(CD_YESNO);
    FrmCdBox->setTitle( "MOTION_CONTROL" );
    FrmCdBox->setText( "Are you sure about the moving motor to " + strDir + " direction?" );
    if( mrYes == FrmCdBox->ShowModal())
    {
    	nResponseWriteCommunicationDM(1, _TENKEY_MOTION_SPEED_DM_);

        g_MMIComm->m_mmiToSeq.buffer.motControl.nMtNo = _axisNum;
        g_MMIComm->m_mmiToSeq.buffer.motControl.nCmd = MTCMD_R_MOVE;

        g_MMIComm->m_mmiToSeq.buffer.motControl.nDir = dir;
        g_MMIComm->m_mmiToSeq.buffer.motControl.dPulse =  PanelRvalue->Caption.ToDouble() * 1000.0;
        g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_MT_CMD;
        g_MMIComm->Send() && g_MMIComm->Recv();
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMtrSetupControl::SpeedButton18Click(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	g_MMIComm->m_mmiToSeq.buffer.motControl.nMtNo = _axisNum;
    g_MMIComm->m_mmiToSeq.buffer.motControl.nCmd = MTCMD_STOP;
    g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_MT_CMD;
    g_MMIComm->Send() && g_MMIComm->Recv();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMtrSetupControl::SpeedButton17Click(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	FrmCdBox->setFlag(CD_YESNO);
	FrmCdBox->setTitle( "MOTION_CONTROL" );
	FrmCdBox->setText( "MOTOR_STATUS_RESET" );
    if( mrYes == FrmCdBox->ShowModal())
    {
        g_MMIComm->m_mmiToSeq.buffer.motControl.nMtNo =_axisNum;
        g_MMIComm->m_mmiToSeq.buffer.motControl.nCmd = MTCMD_RESET;
        g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_MT_CMD;
        g_MMIComm->Send() && g_MMIComm->Recv();
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMtrSetupControl::SpeedButton5Click(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	FrmCdBox->setFlag(CD_YESNO);
	FrmCdBox->setTitle( "WARNING" );
	FrmCdBox->setText( "INDEX_MOVE" );
	if( mrYes == FrmCdBox->ShowModal())
	{
        g_MMIComm->m_mmiToSeq.nCmd  = CMD_WR_MT_CMD;
		g_MMIComm->m_mmiToSeq.buffer.motControl.nMtNo =_axisNum;
        g_MMIComm->m_mmiToSeq.buffer.motControl.nCmd  = MTCMD_INDEX_MOVE;
		g_MMIComm->m_mmiToSeq.buffer.motControl.nCmdIndexNo = PanelSelect->Tag;
        g_MMIComm->Send();   g_MMIComm->Recv();
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMtrSetupControl::PanelHomeClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

    FrmCdBox->setFlag(CD_YESNO);
	FrmCdBox->setTitle( "MOTION_CONTROL" );
	FrmCdBox->setText("HOME_MOVE_CONTROL" );
	if( mrYes == FrmCdBox->ShowModal())
	{
        g_MMIComm->m_mmiToSeq.buffer.motControl.nMtNo  = _axisNum;
        g_MMIComm->m_mmiToSeq.buffer.motControl.nCmd  = MTCMD_HOME;
        g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_MT_CMD;
        g_MMIComm->Send() && g_MMIComm->Recv();
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMtrSetupControl::PanelServoClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	if(PanelServo->Color == clLime)
	{
		FrmCdBox->setFlag(CD_YESNO);
		FrmCdBox->setTitle( "MOTION_CONTROL"  );
		FrmCdBox->setText( "SERVO_OFF"  );

		if( mrYes == FrmCdBox->ShowModal())
		{
			g_MMIComm->m_mmiToSeq.buffer.motControl.nMtNo = _axisNum;
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
			g_MMIComm->m_mmiToSeq.buffer.motControl.nMtNo = _axisNum;
			g_MMIComm->m_mmiToSeq.buffer.motControl.nCmd = MTCMD_SERVO_ON;
			g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_MT_CMD;
            g_MMIComm->Send() && g_MMIComm->Recv();
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMtrSetupControl::PanelTenkeyClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	int nTemp = nReadCommunicationDM(tenKeyJog);
	if(nTemp == 0)
	{
        nWriteCommunicationDM( 1 , tenKeyJog);
//        FrmRMove->JogMovefrm_Initialize(_axisNum ,this);
    }
	nWriteCommunicationDM( _axisNum , jogAxisNo);
}
//---------------------------------------------------------------------------

