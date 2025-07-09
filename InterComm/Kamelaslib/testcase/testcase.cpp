//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "testcase.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------


__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormShow(TObject *Sender)
{
	_pCurrentBase = NULL;
    Timer1->Enabled = true;

    _recvCount = _sendCount=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{

	if (EditNameS->Text == "")
    	return;

	KamelasBase *pBase;
	KamelasFactory factory;

	FLAG flag;
	flag.type = RadioButtonSharedMemoryServer->Checked ? TYPE_SHAREDMEMORY_SERVER : TYPE_SHAREDMEMORY_CLIENT;
	_tcscpy(flag.name, EditNameS->Text.c_str());
	flag.size = EditSizeS->Text.ToInt();

	pBase = factory.create(flag);
	assert(NULL != pBase);
	_manager += pBase;

	BOOL bSuccess = _manager[EditNameS->Text.c_str()].open();
	assert(TRUE == bSuccess);

	ComboBoxManager->AddItem( EditNameS->Text, (TObject*)pBase);
	ComboBoxManager->ItemIndex = ComboBoxManager->Items->Count -1;
    ComboBoxManagerChange(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBoxManagerChange(TObject *Sender)
{
	_pCurrentBase = _manager.query(ComboBoxManager->Text.c_str());
    if (_pCurrentBase)
    {
		MemoRecv->Clear();
        MemoSend->Clear();

        _sendCount = _recvCount = 0;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	//
    CHAR buffer[1024];
    
    if (_pCurrentBase)
    {
		if (TRUE == _pCurrentBase->recv(buffer, TrackBarRecv->Position))
        {
			MemoRecv->Lines->Add(buffer);
            _recvCount++;
        }

        if (CheckBoxRepeat->Checked)
        {
            CHAR buffer[1024];
        	itoa(_index++, buffer, 10);
            strcat(buffer,"\n");            
    
            if (_pCurrentBase)
            {
                if (TRUE == _pCurrentBase->send(buffer, TrackBarSend->Position))
                {
					MemoSend->Lines->Add(buffer);
                    _sendCount++;
                }
                else
                {
                    _index = 0;
                }
            }
        }
        else
        {
			_index =0;
        }
    }

    StatusBarRecv->SimpleText = "Recv Count : " + String(_recvCount);
    StatusBarSend->SimpleText = "Send Count : " + String(_sendCount);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonSendClick(TObject *Sender)
{
    BYTE buffer[1024];
    
    if (_pCurrentBase)
    {
        _tcscpy((TCHAR*)buffer,	MemoSend->Lines->GetText() );
        if (TRUE == _pCurrentBase->send(buffer, TrackBarSend->Position))
        {
			_sendCount++;
        }
        else
        {
            ShowMessage("fail to send the data !!!");
        }
    }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::MemoSendKeyPress(TObject *Sender, char &Key)
{
	//
    if (Key == '\n' || Key == '\r')
    {
		ButtonSendClick(Sender);
    }

}
//---------------------------------------------------------------------------



