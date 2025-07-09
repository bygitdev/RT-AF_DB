//---------------------------------------------------------------------------
#pragma hdrstop


#include "barcode.h"
#include "fbarcode.h"
//#include "cserial.h"
#include "CSerialWnd.h"
#include "MainFormScrn.h"
#include "FrmLotCommScrn.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#include <process.h>


// enum BARCODE_TYPE { BCD_TOP, BCD_BTM, BCD_ADC };

class BarcodePimpl
{
public:
	BARCODE_TYPE id;
	BARCODE_COMMTYPE commType;
	CRITICAL_SECTION cs;
	//Serial::CSerial* pSerial;
	Serial::CSerialEx* pSerial;
	TClientSocket* pSocket;
	TCustomWinSocket* pConnectedSocket;
	HANDLE	hThread;
	BOOL	terminated;
	BOOL	received;
	AnsiString	recvData;
	BOOL	cmdSet;
	AnsiString	m_Parameter;	// 바코드만의 특정 기능을 사용하고자 할때 이용
	String	ip;
	int		port;
};

class BarcodeSerialEx: public Serial::CSerialEx
{
private:
	Barcode *m_bacode;

	String m_recvBuf;
	String m_recvStartPacket;
	String m_recvEndPacket;

protected:
	void OnEvent (EEvent eEvent, EError eError);

public:
	BarcodeSerialEx(Barcode* pForm)
	{
		m_bacode = pForm;
    }
};

//---------------------------------------------------------------------------
void BarcodeSerialEx::OnEvent(EEvent eEvent, EError eError)
{
	char readdata[256] = {0};

	DWORD dwReadBytes = 0;
	LONG lResult = 0;

	// start, end packet설정 나중에 설정하도록 하자
	m_recvEndPacket = "\r";

	if (eEvent & EEvent::EEventRecv)
	{

		lResult = this->Read(static_cast<void*>(readdata), sizeof(readdata), &dwReadBytes, NULL, 1000);
		if(lResult == ERROR_SUCCESS)
		{
			String sData = String(readdata).Trim();
			if(sData.Length() != 0)
				m_bacode->RecvData(sData);
		}
		else
		{
			MainForm->MachineHistoryData("Barcode Read failed : Errorcode : "  + IntToStr((int)lResult));
		}
	}
}
//---------------------------------------------------------------------------
Barcode::Barcode(int ID, int CommType)
{
	_pPimpl = new BarcodePimpl();
	_pPimpl->id = ID;
	_pPimpl->commType = CommType;
	_pPimpl->pSerial = NULL;
	_pPimpl->pSocket = NULL;

	_pPimpl->hThread = NULL;
    _pPimpl->terminated = false;
    _pPimpl->received = false;
    _pPimpl->recvData = "";
    _pPimpl->cmdSet = false;

	if(_pPimpl->commType == BCD_RSCOM || _pPimpl->commType == BCD_USBCOM)
	{
		//_pPimpl->pSerial = new Serial::CSerial();
		_pPimpl->pSerial = new BarcodeSerialEx(this);
	}
	else
		_pPimpl->pSocket = new TClientSocket(MainForm);

	::InitializeCriticalSection(&_pPimpl->cs);
}
//---------------------------------------------------------------------------
Barcode::~Barcode()
{
	if(_pPimpl->commType == BCD_RSCOM || _pPimpl->commType == BCD_USBCOM)
	{
//		if (_pPimpl->hThread)
//		{
//			_pPimpl->terminated = TRUE;
//			::WaitForSingleObject(_pPimpl->hThread, 1000);
//			::CloseHandle(_pPimpl->hThread);
//			_pPimpl->hThread = NULL;
//		}

		_pPimpl->pSerial->Purge();

		_pPimpl->pSerial->Close();
		_pPimpl->pSerial->StopListener(INFINITE);
		delete _pPimpl->pSerial;
		_pPimpl->pSerial = NULL;
	}
	else
	{
		_pPimpl->pSocket->OnRead = NULL;
		_pPimpl->pSocket->OnConnect  = NULL;
		_pPimpl->pSocket->OnDisconnect = NULL;
		_pPimpl->pSocket->OnError = NULL;
		_pPimpl->pSocket->Active = false;
		_pPimpl->pSocket->Close();
		delete _pPimpl->pSocket;
		_pPimpl->pSocket = NULL;
	}

	::DeleteCriticalSection(&_pPimpl->cs);
	delete _pPimpl;
    _pPimpl = NULL;
}

bool Barcode::trigger(bool onOff)
{
//	if (_pPimpl->cmdSet)
//    {
//    	return false;
//    }

    if (onOff)
	{
        ::EnterCriticalSection(&_pPimpl->cs);
        _pPimpl->recvData = "";
		_pPimpl->received = false;
        ::LeaveCriticalSection(&_pPimpl->cs);
    }
	CHAR trigger[16] = {0,};
    if (onOff)
    	strcpy(trigger, "LON\r");
    else
    	strcpy(trigger, "LOFF\r");

	BOOL result = true;

	if(_pPimpl->commType == BCD_RSCOM || _pPimpl->commType == BCD_USBCOM)
	{
		LONG lResult = _pPimpl->pSerial->Write(trigger, strlen(trigger), NULL, NULL);
		result = (lResult == ERROR_SUCCESS);
		if (result)
			_pPimpl->cmdSet = true;
	}
	else
	{
		try
		{
			if (_pPimpl->pConnectedSocket)
				_pPimpl->pConnectedSocket->SendText(trigger);
			else
			{
				_pPimpl->pSocket->Address = _pPimpl->ip;
				_pPimpl->pSocket->Port = _pPimpl->port;
				_pPimpl->pSocket->Active = true;
			}
			_pPimpl->cmdSet = false;
		}
		catch(Exception &e)
		{
			//ShowMessage(e.Message);
			MainForm->MachineHistoryData("Barcode trigger error :" + e.Message);
			result = false;
		}
	}

    return result;
}

bool Barcode::isRecv()
{
    return _pPimpl->received;
}

AnsiString	Barcode::getRecvData()
{
	return _pPimpl->recvData;	//// hw failure : "ERROR" or "ERR20"
}

void Barcode::RecvData(String data)
{
	_pPimpl->recvData = data;
	_pPimpl->received = true;
}

void Barcode::clear()
{
	::EnterCriticalSection(&_pPimpl->cs);
	_pPimpl->received = false;
    _pPimpl->recvData = "";
    ::LeaveCriticalSection(&_pPimpl->cs);
}

void __fastcall Barcode::OnRecv(System::TObject* Sender, TCustomWinSocket* Socket)
{
	// tcp 로 바코드 읽은 데이타 수신됨 !!

    ::EnterCriticalSection(&_pPimpl->cs);
    AnsiString recvData = Socket->ReceiveText();
	recvData = recvData.Trim();

	if(recvData.Length() != 0)
	{
		_pPimpl->recvData = recvData;
		_pPimpl->received = true;
	}

    ::LeaveCriticalSection(&_pPimpl->cs);

	frmBarcode->Memo1->Lines->Add( Now().TimeString() +" : Received Data : " + _pPimpl->recvData );

}

void __fastcall Barcode::OnConnect(System::TObject* Sender, TCustomWinSocket* Socket)
{
	_pPimpl->pConnectedSocket = Socket;
	MainForm->MachineHistoryData( "Connected to barcode server : ID : " + IntToStr(_pPimpl->id));
    this->trigger(false);
}

void __fastcall Barcode::OnDisconnect(System::TObject* Sender, TCustomWinSocket* Socket)
{
	_pPimpl->pConnectedSocket = NULL;
	MainForm->MachineHistoryData( "Disconnected to barcode server : ID : " + IntToStr(_pPimpl->id));
    _pPimpl->pSocket->Active = false;
}

void __fastcall Barcode::OnError(System::TObject* Sender, TCustomWinSocket* Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
	_pPimpl->pConnectedSocket = NULL;
	MainForm->MachineHistoryData( "Socket error code : " + IntToStr(ErrorCode)+ " : ID : " + IntToStr(_pPimpl->id));
    ErrorCode = 0;
	_pPimpl->pSocket->Active = false;
}

bool	Barcode::initialize(String ipAddress, int nPort)
{
	_pPimpl->ip = ipAddress;
	_pPimpl->port = nPort;
	_pPimpl->pSocket->Address = ipAddress;
	_pPimpl->pSocket->Port = nPort;
    _pPimpl->pSocket->ClientType = ctNonBlocking;
    _pPimpl->pSocket->OnRead = this->OnRecv;
    _pPimpl->pSocket->OnConnect  = this->OnConnect;
    _pPimpl->pSocket->OnDisconnect = this->OnDisconnect;
    _pPimpl->pSocket->OnError = this->OnError;

    try
    {
    	_pPimpl->pSocket->Active = true;
    }
    catch(Exception &e)
    {
		MainForm->MachineHistoryData("IP Barcode initialzing failed : " + e.Message);
        return false;
    }

	MainForm->MachineHistoryData("IP Barcode initialzed : ID : " + IntToStr(_pPimpl->id));
    return true;

}

bool	Barcode::initialize(int nPort)
{
//	if (_pPimpl->hThread)
//	{
//		_pPimpl->terminated = TRUE;
//		::WaitForSingleObject(_pPimpl->hThread, -1);
//		::CloseHandle(_pPimpl->hThread);
//		_pPimpl->hThread = NULL;
//	}
 	if (TRUE == _pPimpl->pSerial->IsOpen()) {
		_pPimpl->pSerial->Close();
	}

	WCHAR strPortNumber[16];
	memset(&strPortNumber, 0, sizeof(strPortNumber));
	wsprintf(strPortNumber, L"COM%d", nPort );

	LONG lLastError = _pPimpl->pSerial->Open(strPortNumber, 1024, 1024, TRUE);
	if (ERROR_SUCCESS == lLastError)
	{
		lLastError = _pPimpl->pSerial->Setup(	Serial::CSerial::EBaud9600,
												Serial::CSerial::EData8,
												Serial::CSerial::EParNone,
												Serial::CSerial::EStop1);
        if (ERROR_SUCCESS == lLastError)
		{
			if(_pPimpl->commType == BCD_USBCOM)
				lLastError = _pPimpl->pSerial->SetupHandshaking(Serial::CSerial::EHandshakeHardware);
			else
				lLastError = _pPimpl->pSerial->SetupHandshaking(Serial::CSerial::EHandshakeOff);

			if (ERROR_SUCCESS == lLastError)
			{
//				lLastError = _pPimpl->pSerial->SetupReadTimeouts(Serial::CSerial::EReadTimeoutBlocking);
//				if (ERROR_SUCCESS == lLastError)
//				{
					_pPimpl->pSerial->Purge();
//					_pPimpl->terminated = false;
//					_pPimpl->hThread = (HANDLE)_beginthreadex(NULL, 0, fnCommThread, this, 0, NULL);
//
//				}
			}
		}
	}

	if (ERROR_SUCCESS == lLastError)
	{
		MainForm->MachineHistoryData("Barcode initialzed : ID : " + IntToStr(_pPimpl->id));
        return true;
	}
	else
	{
		MainForm->MachineHistoryData("Barcode initialzing failed : ID : "  + IntToStr(_pPimpl->id));
		return false;
	}
}

//---------------------------------------------------------------------------
int			Barcode::getCommType()
{
	return _pPimpl->commType;
}
//---------------------------------------------------------------------------


unsigned int __stdcall	Barcode::fnCommThread(void* lpArg)
{
	Barcode* p = static_cast<Barcode*>(lpArg);
	BarcodePimpl* pPimpl = p->_pPimpl;

	while (!pPimpl->terminated)
	{
		::Sleep(50);

		if (pPimpl->cmdSet)
		{
			::Sleep(500);	// 바코드 측정 딜레이.. 아래 pPimpl->pSerial->Read 와 연관. 개선 필요...
			//pPimpl->pSerial->Purge();

            DWORD dwIndexBytes = 0;
            DWORD dwReadBytes = 0;
            LONG lResult = 0;
            CHAR resp[1024] = { 0, };
            do
            {
                lResult = pPimpl->pSerial->Read((void*)&resp[dwIndexBytes], 1, &dwReadBytes, NULL, 100);
                if (lResult != ERROR_SUCCESS)
                    break;
                if ('\r' == resp[dwIndexBytes])
                    break;
                ++dwIndexBytes;
            } while (lResult == ERROR_SUCCESS);


            if ( dwIndexBytes >0)
            {
                ::EnterCriticalSection(&pPimpl->cs);

				AnsiString sBuf = AnsiString(resp).Trim();

				pPimpl->recvData += sBuf;
				pPimpl->received = true;
				::LeaveCriticalSection(&pPimpl->cs);

                // 쓰레드에서 UI접근 X
//
//                switch(pPimpl->id)
//                {
//                case BCD_TOP:
//                    break;
//					//frmBarcode->Memo1->Lines->Add( Now().TimeString() +" : Received Data : " + String(resp));
//                    break;
//                case BCD_BTM:
//                    frmBarcode->Memo2->Lines->Add( Now().TimeString() +" : Received Data : " + String(resp));
//                    break;
//                case BCD_ADC:
//                    frmBarcode->Memo3->Lines->Add( Now().TimeString() +" : Received Data : " + String(resp));
//                    break;
//                }
            }

            pPimpl->cmdSet = false;
        }
    }
    return 0;
}

