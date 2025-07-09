//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fPopupNotice.h"
#include "BaseComm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmPopupNotice *frmPopupNotice;

bool	TfrmPopupNotice::_showing_popup = false;
//---------------------------------------------------------------------------
__fastcall TfrmPopupNotice::TfrmPopupNotice(TComponent* Owner)
	: TForm(Owner)
{

	_comp_index = -1;
	_btnClick = -1;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPopupNotice::FormShow(TObject *Sender)
{
	_showing_popup = true;
	tmrFlicker->Enabled = true;

	m_eastEgg = 0;
}
//---------------------------------------------------------------------------

void TfrmPopupNotice::setTitle(String strTitle)
{
	Panel1->Caption = strTitle;
}
//---------------------------------------------------------------------------

void TfrmPopupNotice::setText(String strText)
{
//	mmMessage->Clear();
//	mmMessage->Lines->Add(strText);
	lbText->Caption = "";
	lbText->Caption = strText;
}
//---------------------------------------------------------------------------
void TfrmPopupNotice::setButton(String _Btn_Text1,String _Btn_Text2,String _Btn_Text3,String _Btn_Text4)
{
	int cnt = 0;
//	if(!_Btn_Text1.IsEmpty())
//	{
//		Btn1->Visible = true;
//		Btn1->Caption = _Btn_Text1;
//        cnt++;
//	}
//	else
//	{
//		Btn1->Visible = false;
//		Btn1->Caption = "";
//	}
//	if(!_Btn_Text2.IsEmpty())
//	{
//		Btn2->Visible = true;
//		Btn2->Caption = _Btn_Text2;
//        cnt++;
//	}
//	else
//	{
//		Btn2->Visible = false;
//		Btn2->Caption = "";
//	}
//	if(!_Btn_Text3.IsEmpty())
//	{
//		Btn3->Visible = true;
//		Btn3->Caption = _Btn_Text3;
//        cnt++;
//	}
//	else
//	{
//		Btn3->Visible = false;
//		Btn3->Caption = "";
//	}
//	if(!_Btn_Text4.IsEmpty())
//	{
//		Btn4->Visible = true;
//		Btn4->Caption = _Btn_Text4;
//        cnt++;
//	}
//	else
//	{
//		Btn4->Visible = false;
//		Btn4->Caption = "";
//	}
    vector<String> v_btn;
	if(!_Btn_Text1.IsEmpty())
	{
        v_btn.push_back(_Btn_Text1);
	}
	if(!_Btn_Text2.IsEmpty())
	{
        v_btn.push_back(_Btn_Text2);
	}
	if(!_Btn_Text3.IsEmpty())
	{
        v_btn.push_back(_Btn_Text3);
	}
	if(!_Btn_Text4.IsEmpty())
	{
        v_btn.push_back(_Btn_Text4);
	}

    for(int i=0;i<4;i++)
    {


        TButton* btn = dynamic_cast<TButton*>(FindComponent("Btn" + IntToStr(i+1)));
        if(NULL != btn)
        {
            if(i<v_btn.size())
            {
                btn->Caption = v_btn[i];
                btn->Visible = true;
                GridPanel1->ColumnCollection->Items[i]->Value = 100.0/ v_btn.size();
            }
            else
            {
                btn->Caption = "";
                btn->Visible = false;
                GridPanel1->ColumnCollection->Items[i]->Value = 0;
            }
        }


    }

	_btnClick = false;
}
//void TfrmPopupNotice::setCompSignal(twilight::hydra::HYDRA_CMD type, int index)
//{
//	_type = type;
//	_comp_index = index;
//
//}
//---------------------------------------------------------------------------

bool TfrmPopupNotice::isShowing()
{
	return _showing_popup;
}


void __fastcall TfrmPopupNotice::Btn1Click(TObject *Sender)
{
	int iValue = dynamic_cast<TButton*>(Sender)->Tag;
	nWriteCommunicationDM(iValue,MSGNOTICE_MMI2SEQ);
//	CONFIG& c = twilight::sequence::g_config;
//	if (NULL == c.pHydra)
//		return;
//	String sCaption = dynamic_cast<TButton*>(Sender)->Caption;
//	if(c.pHydra->write(_type, &iValue, _comp_index))
//	{
//		LOG(_T("popup notice msg comp :%s : success to write. type=%d, index=%d, val=%d"),sCaption.c_str(), _type, _comp_index, iValue);
//	}
//	else
//	{
//		LOG(_T("popup notice comp : fail to write. type=%d, index=%d, val=%d"), _type, _comp_index, iValue);
//	}
	_btnClick = true;
//	tmrFlicker->Enabled = false;
}
//---------------------------------------------------------------------------


void __fastcall TfrmPopupNotice::FormClose(TObject *Sender, TCloseAction &Action)

{
	if(m_eastEgg>7)	//click title over 7
	{
		nWriteCommunicationDM(0,MSGNOTICE_SEQ2MMI);	//mmi clear
	}
	else if(!_btnClick)
	{
		int iValue = 11;
		nWriteCommunicationDM(iValue,MSGNOTICE_MMI2SEQ);
	}
	tmrFlicker->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TfrmPopupNotice::btnButtonClick(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmPopupNotice::tmrFlickerTimer(TObject *Sender)
{
	if(lbText->Color != clBlack)
	{
		lbText->Color = clBlack;
		lbText->Font->Color = clYellow;
	}
	else
	{
		lbText->Color = clYellow;
		lbText->Font->Color = clBlack;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmPopupNotice::Panel1Click(TObject *Sender)
{
	//east egg.
	++m_eastEgg;
}
//---------------------------------------------------------------------------
