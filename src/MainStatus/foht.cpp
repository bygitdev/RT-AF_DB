//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "foht.h"

#include "BaseComm.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmOht *frmOht;
//---------------------------------------------------------------------------
__fastcall TfrmOht::TfrmOht(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TfrmOht::RefleshPioName()
{
	TIniFile *pSensorName  = new TIniFile(ExtractFilePath(Application->ExeName) + "\\Ini\\SensorName.ini");
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\SensorName.ini") == true)
	{
		for (int i=0; i < 8; i++)
		{
			TLabel *CloneInput  = (TLabel*)FindComponent("lblPioInput" + IntToStr(i));
			TLabel *CloneOutput = (TLabel*)FindComponent("lblPioOutput" + IntToStr(i));

			// IO가 8번 부터 시작함.
			CloneInput->Caption = pSensorName->ReadString("INPUT_CHANNEL_4", "NO_" + IntToStr(i+8), "");
			CloneOutput->Caption = pSensorName->ReadString("OUTPUT_CHANNEL_4", "NO_" + IntToStr(i+8), "");
		}
	}

	delete pSensorName;
	pSensorName = NULL;

}
//---------------------------------------------------------------------------
void TfrmOht::RefleshPioSensor()
{
	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_IO;

	bool bInIOChk;
	bool bOutIOChk;

	if(g_MMIComm->Send() && g_MMIComm->Recv())
	{
		for (int i=0; i < 8; i++)
		{
			// IO가 8번 부터 시작함.
			bInIOChk  = BIT(g_MMIComm->m_mmiToSeq.buffer.rdIO.inCH[4],i+8);
			bOutIOChk = BIT(g_MMIComm->m_mmiToSeq.buffer.rdIO.outCH[4],i+8);

			TLabel *pLabelInput = (TLabel*)FindComponent("lblPioInput" + IntToStr(i));
			TPanel *pPanelInput = (TPanel*)FindComponent("panPioInput" + IntToStr(i));
			if(bInIOChk == true)
			{
				pPanelInput->Color = clLime;
				pLabelInput->Font->Color = clBlack;
			}
			else
			{
				pPanelInput->Color = clGray;
				pLabelInput->Font->Color = clWhite;
			}

			TLabel *pLabelOutput = (TLabel*)FindComponent("lblPioOutput" + IntToStr(i));
			TPanel *pPanelOutput = (TPanel*)FindComponent("panPioOutput" + IntToStr(i));
			if(bOutIOChk == true)
			{
				pPanelOutput->Color = clLime;
				pLabelOutput->Font->Color = clBlack;
			}
			else
			{
				pPanelOutput->Color = clGray;
				pLabelOutput->Font->Color = clWhite;
			}
		}
	}
}
//---------------------------------------------------------------------------
void TfrmOht::RefleshUseSkip()
{
	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_USESKIP;
	g_MMIComm->m_mmiToSeq.buffer.useSkip.nStart  = 0;
	g_MMIComm->m_mmiToSeq.buffer.useSkip.nEnd  = 99;

	if(g_MMIComm->Send() && g_MMIComm->Recv())
	{
		for (int i=0; i < 3; i++)
		{
			TLabel *pLabel  = (TLabel*)FindComponent("lblUSESKIP" + IntToStr(i));
			TPanel *pPanel  = (TPanel*)FindComponent("panUSESKIP" + IntToStr(i));

			BOOL bUseSkip = g_MMIComm->m_mmiToSeq.buffer.useSkip.nVal[pLabel->Tag];

			if(NULL != pLabel && NULL != pPanel)
			{
				if (bUseSkip)
				{
					pPanel->Color = clLime;
					pLabel->Font->Color = clBlack;
				}
				else
				{
					pPanel->Color = clGray;
					pLabel->Font->Color = clWhite;
				}
			}
		}
	}
}
//---------------------------------------------------------------------------
void TfrmOht::RefleshDdm()
{
	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_DDM;
	g_MMIComm->m_mmiToSeq.buffer.ddm.nStart = 0;
	g_MMIComm->m_mmiToSeq.buffer.ddm.nEnd = 999;

	if (g_MMIComm->Send() && g_MMIComm->Recv())
	{
		for (int i = 0; i < 3; i++)
		{
			TPanel *pPanel = (TPanel*)FindComponent("panDDM" + IntToStr(i));

			if(NULL != pPanel)
			{
				double dData = g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[pPanel->Tag];
				pPanel->Caption = FloatToStrF(dData,ffFixed,10,1);
			}
		}
	}
}
//---------------------------------------------------------------------------
void TfrmOht::RefleshNdm()
{
	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_NDM;
	g_MMIComm->m_mmiToSeq.buffer.ndm.nStart = 0;
	g_MMIComm->m_mmiToSeq.buffer.ndm.nEnd = 999;

	if (g_MMIComm->Send() && g_MMIComm->Recv())
	{
		for (int i = 0; i < 2; i++)
		{
			TLabel *pLabel = (TLabel*)FindComponent("lblNDM" + IntToStr(i));
			TPanel *pPanel = (TPanel*)FindComponent("panNDM" + IntToStr(i));

			if (pLabel != NULL && pPanel != NULL)
			{
				int nData = g_MMIComm->m_mmiToSeq.buffer.ndm.nVal[pLabel->Tag];

				if (STATE_REQ == nData || STATE_BUSY == nData || STATE_COMP == nData)
				{
					pLabel->Font->Color = clBlack;
					pPanel->Color = clLime;
				}
				else
				{
					pLabel->Font->Color = clWhite;
					pPanel->Color = clGray;
				}
			}
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmOht::FormShow(TObject *Sender)
{
	//RefleshPioName();

	Timer1->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmOht::FormClose(TObject *Sender, TCloseAction &Action)
{
	Timer1->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmOht::Timer1Timer(TObject *Sender)
{
	if(!this->Showing) return;

	RefleshPioSensor();
	RefleshUseSkip();
	RefleshDdm();
	RefleshNdm();
}
//---------------------------------------------------------------------------
void __fastcall TfrmOht::lblPioOutput0DblClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;
	if(!CheckCanAccessLevel(PW_MAINTENANCE)) return;

	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_IO;

	if(g_MMIComm->Send() && g_MMIComm->Recv())
	{
		TLabel* pLabel = dynamic_cast<TLabel*>(Sender);
		int nTag = pLabel->Tag;

		Word wReadCh = (WORD) g_MMIComm->m_mmiToSeq.buffer.rdIO.outCH[4];
		BOOL bData = BIT(wReadCh, nTag);

		String szNum = StringSpaceMaker(4, 2) + StringSpaceMaker(nTag, 2);

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
void __fastcall TfrmOht::btnOutputResetClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;
	if(!CheckCanAccessLevel(PW_MAINTENANCE)) return;

	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_IO;

	if(g_MMIComm->Send() && g_MMIComm->Recv())
	{
		for (int i=0; i < 8; i++)
		{
			int nTag = i+8;

			Word wReadCh = (WORD) g_MMIComm->m_mmiToSeq.buffer.rdIO.outCH[4];
			BOOL bData = BIT(wReadCh, nTag);

			String szNum = StringSpaceMaker(4, 2) + StringSpaceMaker(nTag, 2);

			g_MMIComm->m_mmiToSeq.buffer.wrIO.nIONo = StrToInt(szNum);
			g_MMIComm->m_mmiToSeq.buffer.wrIO.bOn = false;
			g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_IO;
			if(g_MMIComm->Send() && g_MMIComm->Recv())
			{
				MainLog("Write IO : " + szNum + " ->" + BoolToStr(false,true));
			}
			else
			{
				ShowMessage("Communication Failure");
			}
		}
	}
	else
	{
		ShowMessage("Communication Failure");
	}
}
//---------------------------------------------------------------------------
