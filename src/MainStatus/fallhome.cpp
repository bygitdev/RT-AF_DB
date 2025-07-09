//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fallhome.h"
#include "BaseComm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmAllhomeStatus *frmAllhomeStatus;

#define AXIS_MAX_COUNT	30
//---------------------------------------------------------------------------
__fastcall TfrmAllhomeStatus::TfrmAllhomeStatus(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmAllhomeStatus::FormCreate(TObject *Sender)
{
	TIniFile *nameIni = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\MotorName.ini");

	int	axisCnt = MAX_MT_NO;
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

		p->AlignWithMargins = true;
		p->Margins->SetBounds(3,3,3,3);

		p->Font->Name = "Calibri";
		p->Font->Size = 10;
		p->Font->Style << fsBold;
		p->Tag = i;
		//p->Caption = IntToStr(p->Tag+1)+ " : " + nameIni->ReadString("AXISNAME","AXIS"+IntToStr(p->Tag),"AXISNAME"+IntToStr(p->Tag));
		p->Caption = nameIni->ReadString("AXISNAME","AXIS"+IntToStr(p->Tag),"AXISNAME"+IntToStr(p->Tag));
//		p->OnClick = AxisBtnClick;
		_panels.push_back(p);

		TLabel* l = new TLabel(p);
		l->Parent = p;
		l->Align = alClient;
		l->AlignWithMargins = true;
		l->Margins->SetBounds(3,50,3,3);

		l->Font->Name = "Calibri";
		l->Font->Size = 10;
		l->Font->Style << fsBold;

		l->Alignment = taCenter;
		l->Layout = tlTop;

		_labels.push_back(l);

		p->Show();
	}

	delete nameIni;

}
//---------------------------------------------------------------------------
void __fastcall TfrmAllhomeStatus::Timer1Timer(TObject *Sender)
{
	if(!this->Showing) return;
	static bool tic = 0;
	for(int i=0; i<_panels.size() ; i++)
	{
		g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_MT_STATUS;
		g_MMIComm->m_mmiToSeq.buffer.motStatus.nMtNo = i;
		if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
		{
			if(g_MMIComm->m_mmiToSeq.buffer.motStatus.bHome)
			{
				_panels[i]->Color = clLime;
				_panels[i]->Font->Color = clBlack;
			}
			else if(g_MMIComm->m_mmiToSeq.buffer.motStatus.bHoming)
			{
				if(tic)
				{
					_panels[i]->Color = clLime;
					_panels[i]->Font->Color = clSilver;
					_panels[i]->Repaint();
				}
				else
				{
					_panels[i]->Color = clGrayText;
					_panels[i]->Font->Color = clSilver;
					_panels[i]->Repaint();
				}
			}
			else
			{
				_panels[i]->Color = clGrayText;
				_panels[i]->Font->Color = clSilver;
			}

			_labels[i]->Caption =  "( " + FloatToStr(g_MMIComm->m_mmiToSeq.buffer.motStatus.dRealCnt/1000) + " )" ;
		}
		else return;
	}
	tic = !tic;
}
//---------------------------------------------------------------------------
void __fastcall TfrmAllhomeStatus::FormDestroy(TObject *Sender)
{
	for(int i = 0; i < _labels.size() ; i++)
	{
		delete _labels.at(i);
	}

	_labels.clear();

	for(int i = 0; i < _panels.size() ; i++)
	{
		delete _panels.at(i);
	}

	_panels.clear();
}
//---------------------------------------------------------------------------

