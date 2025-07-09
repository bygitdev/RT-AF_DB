//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fmultiservo.h"
#include "BaseComm.h"
#include "Include.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrmMultiServo *FrmMultiServo;

#define AXIS_MAX_COUNT	30
//---------------------------------------------------------------------------
__fastcall TFrmMultiServo::TFrmMultiServo(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFrmMultiServo::FormCreate(TObject *Sender)
{
	TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\MotorScrnSetup.ini");
	TIniFile *nameIni = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\MotorName.ini");

	int	axisCnt = ini->ReadInteger("MOTER_SELECT_SCREEN","TOTAL_AXIS_COUNT",0);
	if(axisCnt > AXIS_MAX_COUNT) axisCnt = AXIS_MAX_COUNT;

	for(int i=0; i <axisCnt; i++)
	{
		TPanel* p = new TPanel(this);
		p->Parent = GridPanel1;
		p->Align = alClient;
		p->ParentColor = false;
		p->ParentBackground = false;
		p->BevelOuter = bvNone;
		p->Color = clGrayText;
		p->Width = 140;
		p->Height = 90;

		p->AlignWithMargins = true;
		p->Margins->SetBounds(2,2,2,2);

		p->Font->Name = "Calibri";
		p->Font->Size = 10;
		p->Font->Style << fsBold;
		p->Tag = i;
		p->Caption = nameIni->ReadString("AXISNAME","AXIS"+IntToStr(p->Tag),"AXISNAME"+IntToStr(p->Tag));
		p->OnClick = AxisPanelClick;
		_panels.push_back(p);

		p->Show();

		TPanel* of = new TPanel(this);
		of->Parent = p;
		of->ParentColor = false;
		of->ParentBackground = false;
		of->BevelOuter = bvNone;
		of->Color = clGreen;
		//of->Color = clLime;
		of->Width = 10;
		of->Height = 30;

		of->Left = 5;
		of->Top = 27;

		of->Tag = i;
		_panelsOnOff.push_back(of);
	}

	delete ini;
	delete nameIni;
	strngrd->RowCount = axisCnt + 1;
	strngrd ->Cells[0][0] = "MOTOR NAME";
	this->Timer1->Enabled = true;

}
//---------------------------------------------------------------------------
void __fastcall TFrmMultiServo::FormDestroy(TObject *Sender)
{
	for(int i = 0; i < _panels.size() ; i++)
	{
		delete _panelsOnOff.at(i);
		delete _panels.at(i);
	}

	_panelsOnOff.clear();
	_panels.clear();
}
//---------------------------------------------------------------------------
void __fastcall TFrmMultiServo::AxisPanelClick(TObject *Sender)
{
	TPanel* panel = dynamic_cast<TPanel*>(Sender);
	if(NULL != panel)
	{
		int id = panel->Tag;
		String name = panel->Caption;
		AddAxisRow(id, name);
		if(panel->Color == clGrayText)
		{
			panel->Color = clYellow;
		}
		else if(panel->Color == clYellow)
		{
			panel->Color = clGrayText;
        }
	}
}
//---------------------------------------------------------------------------
void TFrmMultiServo::AddAxisRow(int tag, String name)
{
	bool exist = true;
	for(int sgrid = 1; sgrid < strngrd->RowCount; sgrid++)
	{
		String rowName = strngrd->Cells[0][sgrid];
		if(rowName == name)
		{
			strngrd->Cells[0][sgrid] = "";
			exist = false;
		}
	}

	if(exist)
	{
		for(int sgrid = 1; sgrid < strngrd->RowCount; sgrid++)
		{
			String rowName = strngrd->Cells[0][sgrid];
			if(rowName == "")
			{
				strngrd->Cells[0][sgrid] = name;
				break;
			}
		}
    }
}
//---------------------------------------------------------------------------
void TFrmMultiServo::ClearAxisRow()
{
	for(int i = 1; i < strngrd->RowCount; i++)
	{
		strngrd->Cells[0][i] = "";
	}
	for(int pi=0; pi<_panels.size(); pi++)
	{
		_panels[pi]->Color = clGrayText;
	}
	for(int i=0; i<_panels.size() ; i++)
	{
		g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_MT_STATUS;
		g_MMIComm->m_mmiToSeq.buffer.motStatus.nMtNo = i;
		if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
		{
			if(g_MMIComm->m_mmiToSeq.buffer.motStatus.bServoOn)
			{
				_panelsOnOff[i]->Color = clLime;
			}
			else
			{
				_panelsOnOff[i]->Color = clGreen;
			}
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmMultiServo::BtnClearClick(TObject *Sender)
{
/*
	for(int i = 1; i < strngrd->RowCount; i++)
	{
		strngrd->Cells[0][i] = "";
	}
	for(int pi=0; pi<_panels.size(); pi++)
	{
		_panels[pi]->Color = clGrayText;
	}
	for(int i=0; i<_panels.size() ; i++)
	{
		g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_MT_STATUS;
		g_MMIComm->m_mmiToSeq.buffer.motStatus.nMtNo = i;
		if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
		{
			if(g_MMIComm->m_mmiToSeq.buffer.motStatus.bServoOn)
			{
				_panelsOnOff[i]->Color = clLime;
			}
			else
			{
				_panelsOnOff[i]->Color = clGreen;
			}
		}
		else return;
	}
	*/
	this->ClearAxisRow();
}
//---------------------------------------------------------------------------
void __fastcall TFrmMultiServo::BtnAllClick(TObject *Sender)
{
	this->ClearAxisRow();

	for(int pi=0; pi<_panels.size(); pi++)
	{
		AddAxisRow(pi+1, _panels[pi]->Caption);
		_panels[pi]->Color = clYellow;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmMultiServo::BtnServoOnClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;
	for(int i = 1; i < strngrd->RowCount; i++)
	{
		if(strngrd->Cells[0][i] != "")
		{
			for(int pi=0; pi<_panels.size(); pi++)
			{
				if(_panels[pi]->Caption == strngrd->Cells[0][i])
				{
					g_MMIComm->m_mmiToSeq.buffer.motControl.nMtNo = _panels[pi]->Tag;
					g_MMIComm->m_mmiToSeq.buffer.motControl.nCmd = MTCMD_SERVO_ON;
					g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_MT_CMD;
					g_MMIComm->Send() && g_MMIComm->Recv();
					MainForm->MachineHistoryData("SERVO ON : " + _panels[pi]->Caption);
				}
			}

		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmMultiServo::BtnServoOffClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;
	for(int i = 1; i < strngrd->RowCount; i++)
	{
		if(strngrd->Cells[0][i] != "")
		{
			for(int pi=0; pi<_panels.size(); pi++)
			{
				if(_panels[pi]->Caption == strngrd->Cells[0][i])
				{
					g_MMIComm->m_mmiToSeq.buffer.motControl.nMtNo = _panels[pi]->Tag;
					g_MMIComm->m_mmiToSeq.buffer.motControl.nCmd = MTCMD_SERVO_OFF;
					g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_MT_CMD;
					g_MMIComm->Send() && g_MMIComm->Recv();
					MainForm->MachineHistoryData("SERVO OFF : " + _panels[pi]->Caption);
				}
			}

		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmMultiServo::Timer1Timer(TObject *Sender)
{
	static bool tic = 0;
	for(int i=0; i<_panels.size() ; i++)
	{
		g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_MT_STATUS;
		g_MMIComm->m_mmiToSeq.buffer.motStatus.nMtNo = i;
		if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
		{
			if(g_MMIComm->m_mmiToSeq.buffer.motStatus.bServoOn)
			{
				_panelsOnOff[i]->Color = clLime;
			}
			else
			{
				_panelsOnOff[i]->Color = clGreen;
            }
		}
		else return;
	}
	tic = !tic;
}
