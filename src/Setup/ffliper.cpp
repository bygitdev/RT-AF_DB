//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ffliper.h"
#include "BaseComm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmFlipper *frmFlipper;

#define	NDM_EXIST_TOP	68
#define	NDM_EXIST_BTM	69


//---------------------------------------------------------------------------
__fastcall TfrmFlipper::TfrmFlipper(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void	TfrmFlipper::refresh_panel()
{
	TPanel* top[4] = { PanelTop1, PanelTop2, PanelTop3, PanelTop4 };
	TPanel* btm[4] = { PanelBtm1, PanelBtm2, PanelBtm3, PanelBtm4 };


	int top_exist = nReadCommunicationDM(NDM_EXIST_TOP);
	int btm_exist = nReadCommunicationDM(NDM_EXIST_BTM);

	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_FLIPPER;
	if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
	{
		if(top_exist != 1)
		{
			PanelTop->Color = clGray;
			for(int i=0; i <4 ;i++)
			{
				top[i]->Color = clGray;
			}
		}
		else
		{
			for(int i =0 ; i < 4; i++)
			{
				PanelTop->Color = clLime;
				UINT32 nVal = g_MMIComm->m_mmiToSeq.buffer.flipMap[i];
				if(nVal != 0)
				{
					// panel on
					top[i]->Color = clLime;
				}
				else
				{
					top[i]->Color = clGray;
				}
			}
		}

		if(btm_exist != 1)
		{
			PanelBtm->Color = clGray;
			for(int i=0; i <4 ;i++)
			{
				btm[i]->Color = clGray;
			}
		}
		else
		{
			for(int i =0 ; i < 4; i++)
			{
				PanelBtm->Color = clLime;
				UINT32 nVal = g_MMIComm->m_mmiToSeq.buffer.flipMap[i];
				if(nVal != 0)
				{
					// panel on
					btm[i]->Color = clLime;
				}
				else
				{
					btm[i]->Color = clGray;
				}
			}
		}
	}

}
void __fastcall TfrmFlipper::PanelTop3DblClick(TObject *Sender)
{
//
	TPanel* panel = dynamic_cast<TPanel*>(Sender);
	if(NULL != panel)
	{
		//if(panel->Color == clGray) return;
        int top_exist = nReadCommunicationDM(NDM_EXIST_TOP);
        if (top_exist)
        {
        	TPanel* top[4] = { PanelTop1, PanelTop2, PanelTop3, PanelTop4 };
        	bool valid = false;
        	for (int i=0; i< 4; i++)
            {
            	if (panel == top[i])
                	valid = true;
            }
            if (!valid)
            {
            	// top 을 더블클릭한게 아니므로 무시
                return;
            }
        }

        int btm_exist = nReadCommunicationDM(NDM_EXIST_BTM);
        if (btm_exist)
        {
        	TPanel* btm[4] = { PanelBtm1, PanelBtm2, PanelBtm3, PanelBtm4 };
        	bool valid = false;
        	for (int i=0; i< 4; i++)
            {
            	if (panel == btm[i])
                	valid = true;
            }
            if (!valid)
            {
            	// btm 을 더블클릭한게 아니므로 무시
                return;
            }
        }


		UINT32 flag = 0;
		if(panel->Color != clLime) flag = 1;
        g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_FLIPPER;
		if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
        {
           	g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_FLIPPER;
           	g_MMIComm->m_mmiToSeq.buffer.flipMap[panel->Tag] = flag;
            g_MMIComm->Send();
            g_MMIComm->Recv();
        }
	}

	this->refresh_panel();
}
//---------------------------------------------------------------------------
void __fastcall TfrmFlipper::FormShow(TObject *Sender)
{
	this->refresh_panel();
}
//---------------------------------------------------------------------------
