//---------------------------------------------------------------------------

#pragma hdrstop

#include "rfid.h"
#include "frfid.h"
#include <stdio.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)

#include "cserial.h"
#include <process.h>
#include "MainFormScrn.h"

class RFIDPimpl
{
public:
	BARCODE_TYPE id;
	BARCODE_COMMTYPE commType;
	RFID_MAKER maker;
	CRITICAL_SECTION cs;
	Serial::CSerial* pSerial;
	TClientSocket* pSocket;
	TCustomWinSocket* pConnectedSocket;
	HANDLE	hThread;
	BOOL	terminated;
	bool	isInitalized;
	bool	isWriteCmd;
	int		ch;

    String 	stepNo;
    String 	lotNo;
    String 	partNo;
	String 	qty;

	RFID_DATA	data;
	bool	isReadSuccess;
	bool	isWriteSuccess;
};



//---------------------------------------------------------------------------
RFID::RFID(int ID, int CommType, int Maker)
{
	_pPimpl = new RFIDPimpl();
	_pPimpl->id = ID;
	_pPimpl->commType = CommType;
	_pPimpl->maker = Maker;
	_pPimpl->pSerial = NULL;
	_pPimpl->pSocket = NULL;

	_pPimpl->hThread = NULL;
	_pPimpl->terminated = FALSE;
	_pPimpl->isInitalized = false;
	_pPimpl->isWriteCmd = false;
	_pPimpl->ch = 0;
    _pPimpl->stepNo = "";
	_pPimpl->lotNo = "";
    _pPimpl->partNo = "";
    _pPimpl->qty = "";

	if(_pPimpl->commType == BCD_RSCOM || _pPimpl->commType == BCD_USBCOM)
		_pPimpl->pSerial = new Serial::CSerial();
	else
		_pPimpl->pSocket = new TClientSocket(MainForm);

	::InitializeCriticalSection(&_pPimpl->cs);
}
//---------------------------------------------------------------------------
RFID::~RFID()
{
	if(_pPimpl->commType == BCD_RSCOM || _pPimpl->commType == BCD_USBCOM)
	{
		if (_pPimpl->hThread)
		{
			_pPimpl->terminated = TRUE;
			::WaitForSingleObject(_pPimpl->hThread, 1000);
			::CloseHandle(_pPimpl->hThread);
			_pPimpl->hThread = NULL;
		}

		_pPimpl->pSerial->Close();
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
//---------------------------------------------------------------------------
void __fastcall RFID::OnRecv(System::TObject* Sender, TCustomWinSocket* Socket)
{

	::EnterCriticalSection(&_pPimpl->cs);
	AnsiString recvData = Socket->ReceiveText();
	recvData = recvData.Trim();
	frmRFID->AddCommLog( getRfidInfo()+"RX:"+recvData,1);

	CHAR resp[1024] = {0, };
	strcpy(resp, recvData.c_str());

	int iLen = recvData.Length();	//226, 199+27 로 끊어져 들어오기도 함
	if (iLen <= 3)	//if (iLen <= 5)
		return;

	if (iLen == 4 && (recvData == "0190" || recvData == "0191"))	//Write ACK
	{
		// 쓰기에 대한 응답
		_pPimpl->isWriteSuccess = true;
		frmRFID->AddCommLog( getRfidInfo()+"RFID ACK !" );
	}
	else if (iLen == 6 && (recvData.SubString(1,4) == "0180" || recvData.SubString(1,4) == "0181"))	//Read NAK. CH0,1
	{
		// ERROR Fix 6. Read:018016  Write:01900D, 0190A1
		String sErr = recvData.SubString(5,2);
		frmRFID->AddCommLog( getRfidInfo()+"RFID(READ) NAK ! ERR_CODE:" + sErr );
		frmRFID->AddCommLog( getRfidInfo()+"ERR_NAME:" + getRfidErr(sErr) );
		frmRFID->CommClear();
	}
	else if (iLen == 6 && (recvData.SubString(1,4) == "0190" || recvData.SubString(1,4) == "0191"))	//Write NAK. CH0,1
	{
		// ERROR Fix 6. Read:018016  Write:01900D, 0190A1
		String sErr = recvData.SubString(5,2);
		frmRFID->AddCommLog( getRfidInfo()+"RFID(WRITE) NAK ! ERR_CODE:" + sErr );
		frmRFID->AddCommLog( getRfidInfo()+"ERR_NAME:" + getRfidErr(sErr) );
		frmRFID->CommClear();

	}
	else if (recvData.SubString(1,4) == "0180" || recvData.SubString(1,4) == "0181")	//CH0,1
	{
		// 읽기에 대한 응답
		//resp[iLen-1] = 0x00;	//ETX -> NULL 변경
		CHAR buf[1024]={0,};
		strcpy(buf, &resp[4]);	//&resp[5]

		CHAR buf2[1024]={0,};
		int index=0;
		for (int i=0; i< strlen(buf); i+=2)
		{
			CHAR buf3[3]={0,};
			buf3[0] = buf[i];
			buf3[1] = buf[i+1];
			char *stopstring;
			unsigned long ul = strtoul(buf3, &stopstring,  16);
			buf2[index++] = ul;
		}

		for (int i=0; i<  sizeof(buf2); i++)
		{
			if (buf2[i] == 0x20)
				buf2[i] = NULL;
		}

		RFID_PACKET* packet = (RFID_PACKET*)buf2;

		_pPimpl->data = parsing(packet);

		::Sleep(10);
		_pPimpl->isReadSuccess = true;

	}
	else
	{
		//frmRFID->AddCommLog( "RFID Unknown response ! so reject" );
	}

	::LeaveCriticalSection(&_pPimpl->cs);

}

void __fastcall RFID::OnConnect(System::TObject* Sender, TCustomWinSocket* Socket)
{
	_pPimpl->pConnectedSocket = Socket;
	frmRFID->AddCommLog( getRfidInfo()+"Connected to rfid server : ID : " + IntToStr(_pPimpl->id));
}

void __fastcall RFID::OnDisconnect(System::TObject* Sender, TCustomWinSocket* Socket)
{
	_pPimpl->pConnectedSocket = NULL;
	frmRFID->AddCommLog( getRfidInfo()+"Disconnected to rfid server : ID : " + IntToStr(_pPimpl->id));
}

void __fastcall RFID::OnError(System::TObject* Sender, TCustomWinSocket* Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
	_pPimpl->pConnectedSocket = NULL;
	frmRFID->AddCommLog( getRfidInfo()+"Socket error code : " + IntToStr(ErrorCode)+ " : ID : " + IntToStr(_pPimpl->id));
	ErrorCode = 0;
}

bool	RFID::initialize(String ipAddress, int nPort)
{
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
		frmRFID->AddCommLog(getRfidInfo()+"IP RFID initialzing failed : " + e.Message);
		return false;
    }

	frmRFID->AddCommLog(getRfidInfo()+"IP RFID initialzed : ID : " + IntToStr(_pPimpl->id));
    return true;

}

bool	RFID::initialize(int nPort)
{
	if (_pPimpl->hThread)
	{
		_pPimpl->terminated = TRUE;
		::WaitForSingleObject(_pPimpl->hThread, -1);
		::CloseHandle(_pPimpl->hThread);
		_pPimpl->hThread = NULL;
	}

	if (TRUE == _pPimpl->pSerial->IsOpen()) {
		_pPimpl->pSerial->Close();
	}
    bool bSuccess = false;

	WCHAR strPortNumber[16];
	memset(&strPortNumber, 0, sizeof(strPortNumber));
	wsprintf(strPortNumber, L"COM%d", nPort );

	LONG lLastError = _pPimpl->pSerial->Open(strPortNumber, 1024, 1024, TRUE);
	if (ERROR_SUCCESS == lLastError)
	{
		lLastError = _pPimpl->pSerial->Setup( 	Serial::CSerial::EBaud9600,
												Serial::CSerial::EData8,
												Serial::CSerial::EParNone,
												Serial::CSerial::EStop1);
		if (ERROR_SUCCESS == lLastError)
		{
			lLastError = _pPimpl->pSerial->SetupHandshaking(Serial::CSerial::EHandshakeOff);
			if (ERROR_SUCCESS == lLastError)
			{
				lLastError = _pPimpl->pSerial->SetupReadTimeouts(Serial::CSerial::EReadTimeoutBlocking);
				if (ERROR_SUCCESS == lLastError)
				{
					_pPimpl->pSerial->Purge();
                    _pPimpl->terminated = false;
                    _pPimpl->hThread = (HANDLE)_beginthreadex(NULL, 0, fnCommThread, this, 0, NULL);
					_pPimpl->isInitalized = true;
					bSuccess = true;
				}
			}
		}
	}

	if (bSuccess)
		frmRFID->AddCommLog(getRfidInfo()+"RFID initialzed.");
    else
		frmRFID->AddCommLog(getRfidInfo()+"RFID initialzing failed.");

	return bSuccess;
}
//---------------------------------------------------------------------------
AnsiString MakeRFIDCheckSum(AnsiString szCmd)
{
	short temp =0;
    for (int j = 1 ; j<= szCmd.Length(); j++)
    {
		temp = temp + szCmd[j];
  	}
    return IntToHex(temp,2);
}

AnsiString MakeASCIIToHex(AnsiString szCmd)
{
    AnsiString temp;

    for (int j = 1 ; j<= szCmd.Length(); j++)
    {
        temp = temp + IntToHex(szCmd[j],2);
  	}
    return temp;
}

bool	RFID::isInitialized()
{
	return _pPimpl->isInitalized;
}

bool  RFID::read(int ch)
{
	if(_pPimpl->commType == BCD_RSCOM || _pPimpl->commType == BCD_USBCOM)
	{
		if (_pPimpl->isWriteCmd)
		{
			frmRFID->AddCommLog( getRfidInfo()+"Trying to read but writing is not finished yet !" );
			return false;
		}
	}

	bool result = false;
	AnsiString szCmd;
	AnsiString szTemp;
	AnsiString szCheckSum;
	AnsiString szData;

	_pPimpl->isReadSuccess = false;
	switch(ch)
    {
    case 0:
		szCmd = "0180006F";
        szTemp = MakeRFIDCheckSum(""+szCmd);
        szCheckSum = szTemp.SubString(szTemp.Length() -1 , 2);
        szData = "" + szCmd + szCheckSum + "";
    	break;
	case 1:
		szCmd = "0181006F";
		szTemp = MakeRFIDCheckSum(""+szCmd);
		szCheckSum = szTemp.SubString(szTemp.Length() -1 , 2);
		szData = "" + szCmd + szCheckSum + "";
		break;
	default:
		return false;
		break;
	}

	if(_pPimpl->commType == BCD_RSCOM || _pPimpl->commType == BCD_USBCOM)
	{
		_pPimpl->pSerial->Purge();
		_pPimpl->ch = ch;
		LONG lResult = _pPimpl->pSerial->Write(szData.c_str(), szData.Length(), NULL, NULL);
		result = (lResult == ERROR_SUCCESS);

		if(result == false)	frmRFID->AddCommLog(getRfidInfo()+"RFID Serial->Write(READ) Fail!");

	}
	else
	{
		try
		{
			if (_pPimpl->pConnectedSocket)
			{
				_pPimpl->ch = ch;
				_pPimpl->pConnectedSocket->SendText(szData);
				result = true;
			}
			else
			{
				_pPimpl->pSocket->Active = true;
				frmRFID->AddCommLog(getRfidInfo()+"RFID Tcp disconnected... -> Active");
			}
		}
		catch(Exception &e)
		{
			frmRFID->AddCommLog(getRfidInfo()+"RFID Tcp->Write(READ) Fail! :" + e.Message);
			result = false;
		}
	}

	return result;
}

AnsiString MakeSpace(AnsiString s, int target_len)
{
	AnsiString szTemp="";
	int org_len = s.Length();
	for (int i= org_len; i <= target_len ; i++)
	{
    	szTemp = szTemp + " ";
	}

	return s + szTemp;
}

bool RFID::write(int ch, AnsiString stepNo, AnsiString lotNo, AnsiString partNo, AnsiString qty, bool bAuto)
{
	if(_pPimpl->commType == BCD_RSCOM || _pPimpl->commType == BCD_USBCOM)
	{
		if (_pPimpl->isWriteCmd)
		{
			frmRFID->AddCommLog( getRfidInfo()+"Another writing operation under working ! so rejected" );
			return false;
		}
	}
	else
	{
		if (_pPimpl->pConnectedSocket==NULL)
		{
			_pPimpl->pSocket->Active = true;
			frmRFID->AddCommLog(getRfidInfo()+"RFID Tcp disconnected... -> Active");
			return false;
		}
	}

	_pPimpl->ch = ch;
	_pPimpl->lotNo = lotNo;
	//if(bAuto==false)
   //	{
		_pPimpl->stepNo = stepNo;
		_pPimpl->partNo = partNo;
		_pPimpl->qty = qty;
   //	}

	_pPimpl->isWriteSuccess = false;
	if(_pPimpl->commType == BCD_RSCOM || _pPimpl->commType == BCD_USBCOM)
	{
		_pPimpl->isWriteCmd = true;
	}
	else
	{
		bool result = true;
		AnsiString szLotIdCheckSum;
		AnsiString szLotIdData;
		AnsiString szTotalLotId;
		AnsiString szTotalLotId2;
		AnsiString szStepNoCheckSum;
		AnsiString szStepNoData;
		AnsiString szTotalStepNo;
		AnsiString szTotalStepNo2;
		AnsiString szPartNoCheckSum;
		AnsiString szPartNoData;
		AnsiString szTotalPartNo;
		AnsiString szTotalPartNo2;
		AnsiString szqtyCheckSum;
		AnsiString szqtyData;
		AnsiString szTotalqty;
		AnsiString szTotalqty2;

		AnsiString szLotId;
		AnsiString szAddressLotId;
		AnsiString szStepNo;
		AnsiString szAddressStepNo;
		AnsiString szPartNo;
		AnsiString szAddressPartNo;
		AnsiString szqty;
		AnsiString szAddressqty;

		switch(_pPimpl->ch)
		{
		case 0:
			szLotId = _pPimpl->lotNo;
			szLotId = MakeSpace(szLotId,11);
			szLotId = MakeASCIIToHex(szLotId);
			szAddressLotId = "01901C0C";
			szTotalLotId = szAddressLotId + szLotId;
			szTotalLotId2 = MakeRFIDCheckSum(""+szTotalLotId);
			szLotIdCheckSum = szTotalLotId2.SubString(szTotalLotId2.Length() -1 , 2);
			szLotIdData = "" + szTotalLotId + szLotIdCheckSum + "";

			_pPimpl->pConnectedSocket->SendText(szLotIdData);
			frmRFID->AddCommLog(getRfidInfo()+"RFID Write Lot No.");
			::Sleep(500);

			szStepNo = _pPimpl->stepNo;
			szStepNo = MakeSpace(szStepNo,7);
			szStepNo = MakeASCIIToHex(szStepNo);
			szAddressStepNo = "01902808";
			szTotalStepNo = szAddressStepNo + szStepNo;
			szTotalStepNo2 = MakeRFIDCheckSum(""+szTotalStepNo);
			szStepNoCheckSum = szTotalStepNo2.SubString(szTotalStepNo2.Length() -1 , 2);
			szStepNoData = "" + szTotalStepNo + szStepNoCheckSum + "";

			_pPimpl->pConnectedSocket->SendText(szStepNoData);
			frmRFID->AddCommLog(getRfidInfo()+"RFID Write Step No.");
			::Sleep(500);

			szPartNo = _pPimpl->partNo;
			szPartNo = MakeSpace(szPartNo,62);
			szPartNo = MakeASCIIToHex(szPartNo);
			szAddressPartNo = "0190303F";
			szTotalPartNo = szAddressPartNo + szPartNo;
			szTotalPartNo2 = MakeRFIDCheckSum(""+szTotalPartNo);
			szPartNoCheckSum = szTotalPartNo2.SubString(szTotalPartNo2.Length() -1 , 2);
			szPartNoData = "" + szTotalPartNo + szPartNoCheckSum + "";

			_pPimpl->pConnectedSocket->SendText(szPartNoData);
			frmRFID->AddCommLog(getRfidInfo()+"RFID Write Part No.");
			::Sleep(500);

			szqty = _pPimpl->qty;
			szqty = MakeSpace(szqty,11);
			szqty = MakeASCIIToHex(szqty);
			szAddressqty = "0190100C";
			szTotalqty = szAddressqty + szqty;
			szTotalqty2 = MakeRFIDCheckSum(""+szTotalqty);
			szqtyCheckSum = szTotalqty2.SubString(szTotalqty2.Length() -1 , 2);
			szqtyData = "" + szTotalqty + szqtyCheckSum + "";

			_pPimpl->pConnectedSocket->SendText(szqtyData);
			frmRFID->AddCommLog(getRfidInfo()+"RFID Write Qty.");
			::Sleep(500);

			break;
		case 1:
			szLotId = _pPimpl->lotNo;
			szLotId = MakeSpace(szLotId,11);
			szLotId = MakeASCIIToHex(szLotId);
			szAddressLotId = "01911C0C";
			szTotalLotId = szAddressLotId + szLotId;
			szTotalLotId2 = MakeRFIDCheckSum(""+szTotalLotId);
			szLotIdCheckSum = szTotalLotId2.SubString(szTotalLotId2.Length() -1 , 2);
			szLotIdData = "" + szTotalLotId + szLotIdCheckSum + "";

			_pPimpl->pConnectedSocket->SendText(szLotIdData);
			frmRFID->AddCommLog(getRfidInfo()+"RFID Write Lot No.");
			::Sleep(500);

			szStepNo = _pPimpl->stepNo;
			szStepNo = MakeSpace(szStepNo,7);
			szStepNo = MakeASCIIToHex(szStepNo);
			szAddressStepNo = "01912808";
			szTotalStepNo = szAddressStepNo + szStepNo;
			szTotalStepNo2 = MakeRFIDCheckSum(""+szTotalStepNo);
			szStepNoCheckSum = szTotalStepNo2.SubString(szTotalStepNo2.Length() -1 , 2);
			szStepNoData = "" + szTotalStepNo + szStepNoCheckSum + "";

			_pPimpl->pConnectedSocket->SendText(szStepNoData);
			frmRFID->AddCommLog(getRfidInfo()+"RFID Write Step No.");
			::Sleep(500);

			szPartNo = _pPimpl->partNo;
			szPartNo = MakeSpace(szPartNo,62);
			szPartNo = MakeASCIIToHex(szPartNo);
			szAddressPartNo = "0191303F";
			szTotalPartNo = szAddressPartNo + szPartNo;
			szTotalPartNo2 = MakeRFIDCheckSum(""+szTotalPartNo);
			szPartNoCheckSum = szTotalPartNo2.SubString(szTotalPartNo2.Length() -1 , 2);
			szPartNoData = "" + szTotalPartNo + szPartNoCheckSum + "";

			_pPimpl->pConnectedSocket->SendText(szPartNoData);
			frmRFID->AddCommLog(getRfidInfo()+"RFID Write Part No.");
			::Sleep(500);

			szqty = _pPimpl->qty;
			szqty = MakeSpace(szqty,11);
			szqty = MakeASCIIToHex(szqty);
			szAddressqty = "0191100C";
			szTotalqty = szAddressqty + szqty;
			szTotalqty2 = MakeRFIDCheckSum(""+szTotalqty);
			szqtyCheckSum = szTotalqty2.SubString(szTotalqty2.Length() -1 , 2);
			szqtyData = "" + szTotalqty + szqtyCheckSum + "";

			_pPimpl->pConnectedSocket->SendText(szqtyData);
			frmRFID->AddCommLog(getRfidInfo()+"RFID Write Qty.");
			::Sleep(500);

			break;
		default:
			result = false;
			break;
		}
		//pPimpl->isWriteSuccess = true;
	}
	return true;
}
RFID_DATA	RFID::get_data()
{

	return _pPimpl->data;
}

bool RFID::isRecv()
{
	return	_pPimpl->isReadSuccess;
}

bool RFID::isWrite()
{
	return	_pPimpl->isWriteSuccess;
}

RFID_DATA	RFID::parsing(RFID_PACKET* packet)
{
	RFID_DATA	data;

	data.carrierID 	= packet->carrierID;
	data.qty 		= packet->qty;
	data.lotID  	= packet->lotID;
	data.step 		= packet->step;
	data.partNo  	= packet->partNo;

	if(data.carrierID.Length() > 8)
	{
		String strBuffer = data.carrierID.SubString(0,8);
		data.carrierID = strBuffer;
	}
	if(data.qty.Length() > 6)
	{
		String strBuffer = data.qty.SubString(0,6);
		data.qty = strBuffer;
	}
	if(data.lotID.Length() > 12)
	{
		String strBuffer = data.lotID.SubString(0,12);
		data.lotID = strBuffer;
	}
	if(data.step.Length() > 6)
	{
		String strBuffer = data.step.SubString(0,6);
		data.step = strBuffer;
	}
	if(data.partNo.Length() > 28)
	{
		String strBuffer = data.partNo.SubString(0,28);
		data.partNo = strBuffer;
	}

	return data;
}
//---------------------------------------------------------------------------
unsigned int __stdcall	RFID::fnCommThread(void* lpArg)
{
	RFID* p = static_cast<RFID*>(lpArg);
	RFIDPimpl* pPimpl = p->_pPimpl;

	while (!pPimpl->terminated)
	{
		if (pPimpl->isWriteCmd)
		{
			bool result = true;
			AnsiString szLotIdCheckSum;
			AnsiString szLotIdData;
			AnsiString szTotalLotId;
			AnsiString szTotalLotId2;
			AnsiString szStepNoCheckSum;
			AnsiString szStepNoData;
			AnsiString szTotalStepNo;
			AnsiString szTotalStepNo2;
			AnsiString szPartNoCheckSum;
			AnsiString szPartNoData;
			AnsiString szTotalPartNo;
			AnsiString szTotalPartNo2;
			AnsiString szqtyCheckSum;
			AnsiString szqtyData;
			AnsiString szTotalqty;
			AnsiString szTotalqty2;

			AnsiString szLotId;
			AnsiString szAddressLotId;
			AnsiString szStepNo;
			AnsiString szAddressStepNo;
			AnsiString szPartNo;
			AnsiString szAddressPartNo;
			AnsiString szqty;
			AnsiString szAddressqty;
			LONG lResult;

			int len = 0;

			switch(pPimpl->ch)
			{
			case 0:
				szLotId = pPimpl->lotNo;
				szLotId = MakeSpace(szLotId,11);
				szLotId = MakeASCIIToHex(szLotId);
				szAddressLotId = "01901C0C";
				szTotalLotId = szAddressLotId + szLotId;
				szTotalLotId2 = MakeRFIDCheckSum(""+szTotalLotId);
				szLotIdCheckSum = szTotalLotId2.SubString(szTotalLotId2.Length() -1 , 2);
				szLotIdData = "" + szTotalLotId + szLotIdCheckSum + "";

				lResult = pPimpl->pSerial->Write(szLotIdData.c_str(), szLotIdData.Length(), NULL, NULL);
				result &= (lResult == ERROR_SUCCESS);
				frmRFID->AddCommLog(p->getRfidInfo()+"RFID Write Lot No.");
				::Sleep(500);

				szStepNo = pPimpl->stepNo;
				szStepNo = MakeSpace(szStepNo,7);
				szStepNo = MakeASCIIToHex(szStepNo);
				szAddressStepNo = "01902808";
				szTotalStepNo = szAddressStepNo + szStepNo;
				szTotalStepNo2 = MakeRFIDCheckSum(""+szTotalStepNo);
				szStepNoCheckSum = szTotalStepNo2.SubString(szTotalStepNo2.Length() -1 , 2);
				szStepNoData = "" + szTotalStepNo + szStepNoCheckSum + "";

				lResult = pPimpl->pSerial->Write(szStepNoData.c_str(), szStepNoData.Length(), NULL, NULL);
				result &= (lResult == ERROR_SUCCESS);
				frmRFID->AddCommLog(p->getRfidInfo()+"RFID Write Step No.");
				::Sleep(500);

				szPartNo = pPimpl->partNo;
				szPartNo = MakeSpace(szPartNo,62);
				szPartNo = MakeASCIIToHex(szPartNo);
				szAddressPartNo = "0190303F";
				szTotalPartNo = szAddressPartNo + szPartNo;
				szTotalPartNo2 = MakeRFIDCheckSum(""+szTotalPartNo);
				szPartNoCheckSum = szTotalPartNo2.SubString(szTotalPartNo2.Length() -1 , 2);
				szPartNoData = "" + szTotalPartNo + szPartNoCheckSum + "";

				lResult = pPimpl->pSerial->Write(szPartNoData.c_str(), szPartNoData.Length(), NULL, NULL);
				result &= (lResult == ERROR_SUCCESS);
				frmRFID->AddCommLog(p->getRfidInfo()+"RFID Write Part No.");
				::Sleep(500);

				szqty = pPimpl->qty;
				szqty = MakeSpace(szqty,11);
				szqty = MakeASCIIToHex(szqty);
				szAddressqty = "0190100C";
				szTotalqty = szAddressqty + szqty;
				szTotalqty2 = MakeRFIDCheckSum(""+szTotalqty);
				szqtyCheckSum = szTotalqty2.SubString(szTotalqty2.Length() -1 , 2);
				szqtyData = "" + szTotalqty + szqtyCheckSum + "";

				lResult = pPimpl->pSerial->Write(szqtyData.c_str(), szqtyData.Length(), NULL, NULL);
				result &= (lResult == ERROR_SUCCESS);
				frmRFID->AddCommLog(p->getRfidInfo()+"RFID Write Qty.");
				::Sleep(500);

				break;
			case 1:
				szLotId = pPimpl->lotNo;
				szLotId = MakeSpace(szLotId,11);
				szLotId = MakeASCIIToHex(szLotId);
				szAddressLotId = "01911C0C";
				szTotalLotId = szAddressLotId + szLotId;
				szTotalLotId2 = MakeRFIDCheckSum(""+szTotalLotId);
				szLotIdCheckSum = szTotalLotId2.SubString(szTotalLotId2.Length() -1 , 2);
				szLotIdData = "" + szTotalLotId + szLotIdCheckSum + "";

				lResult = pPimpl->pSerial->Write(szLotIdData.c_str(), szLotIdData.Length(), NULL, NULL);
				result &= (lResult == ERROR_SUCCESS);
				frmRFID->AddCommLog(p->getRfidInfo()+"RFID Write Lot No.");
				::Sleep(500);

				szStepNo = pPimpl->stepNo;
				szStepNo = MakeSpace(szStepNo,7);
				szStepNo = MakeASCIIToHex(szStepNo);
				szAddressStepNo = "01912808";
				szTotalStepNo = szAddressStepNo + szStepNo;
				szTotalStepNo2 = MakeRFIDCheckSum(""+szTotalStepNo);
				szStepNoCheckSum = szTotalStepNo2.SubString(szTotalStepNo2.Length() -1 , 2);
				szStepNoData = "" + szTotalStepNo + szStepNoCheckSum + "";

				lResult = pPimpl->pSerial->Write(szStepNoData.c_str(), szStepNoData.Length(), NULL, NULL);
				result &= (lResult == ERROR_SUCCESS);
				frmRFID->AddCommLog(p->getRfidInfo()+"RFID Write Step No.");
				::Sleep(500);

				szPartNo = pPimpl->partNo;
				szPartNo = MakeSpace(szPartNo,62);
				szPartNo = MakeASCIIToHex(szPartNo);
				szAddressPartNo = "0191303F";
				szTotalPartNo = szAddressPartNo + szPartNo;
				szTotalPartNo2 = MakeRFIDCheckSum(""+szTotalPartNo);
				szPartNoCheckSum = szTotalPartNo2.SubString(szTotalPartNo2.Length() -1 , 2);
				szPartNoData = "" + szTotalPartNo + szPartNoCheckSum + "";

				lResult = pPimpl->pSerial->Write(szPartNoData.c_str(), szPartNoData.Length(), NULL, NULL);
				result &= (lResult == ERROR_SUCCESS);
				frmRFID->AddCommLog(p->getRfidInfo()+"RFID Write Part No.");
				::Sleep(500);

				szqty = pPimpl->qty;
				szqty = MakeSpace(szqty,11);
				szqty = MakeASCIIToHex(szqty);
				szAddressqty = "0191100C";
				szTotalqty = szAddressqty + szqty;
				szTotalqty2 = MakeRFIDCheckSum(""+szTotalqty);
				szqtyCheckSum = szTotalqty2.SubString(szTotalqty2.Length() -1 , 2);
				szqtyData = "" + szTotalqty + szqtyCheckSum + "";

				lResult = pPimpl->pSerial->Write(szqtyData.c_str(), szqtyData.Length(), NULL, NULL);
				result &= (lResult == ERROR_SUCCESS);
				frmRFID->AddCommLog(p->getRfidInfo()+"RFID Write Qty.");
				::Sleep(500);

				break;
			default:
				result = false;
				break;
			}

			pPimpl->isWriteSuccess = true;
            pPimpl->isWriteCmd = false;
		}
		else
        {
			::Sleep(500);
            if (pPimpl->isWriteCmd)
                continue;

            DWORD dwIndexBytes = 0;
            DWORD dwReadBytes = 0;
            LONG lResult = 0;
            CHAR resp[1024] = {0, };
            do
            {
                lResult = pPimpl->pSerial->Read((void*)&resp[dwIndexBytes], 1, &dwReadBytes, NULL, 200);
                if (lResult != ERROR_SUCCESS)
                    break;

				if (0x03 == resp[dwIndexBytes])	//ETX
					break;
				++dwIndexBytes;
			} while (lResult == ERROR_SUCCESS);

			if ( lResult == ERROR_SUCCESS)
			{
				if (dwIndexBytes <= 5)
					continue;

				if (resp[0] == 0x02)	//STX
				{
					// 읽기에 대한 응답
					resp[dwIndexBytes] = 0x00;	//ETX -> NULL 변경
					CHAR buf[1024]={0,};
					strcpy(buf, &resp[5]);

					CHAR buf2[1024]={0,};
					int index=0;
					for (int i=0; i< strlen(buf); i+=2)
					{
						CHAR buf3[3]={0,};
						buf3[0] = buf[i];
						buf3[1] = buf[i+1];
						char *stopstring;
						unsigned long ul = strtoul(buf3, &stopstring,  16);
						buf2[index++] = ul;
					}

					for (int i=0; i<  sizeof(buf2); i++)
					{
						if (buf2[i] == 0x20)
							buf2[i] = NULL;
					}

					RFID_PACKET* packet = (RFID_PACKET*)buf2;

					pPimpl->data = p->parsing(packet);

					::Sleep(50);
					pPimpl->isReadSuccess = true;

					//RFID_PACKET* packet = (RFID_PACKET*)resp;
					//frmRFID->AddCommLog( Now().TimeString() + " : RESPONSE : "  +  String((char*)packet,sizeof(packet)));

					//pPimpl->data = p->parsing(packet);
					//pPimpl->isReadSuccess = true;

					/*
					resp[dwIndexBytes] = 0x00;	//ETX -> NULL 변경
					CHAR buf[1024]={0,};
                    strcpy(buf, &resp[5]);

                    CHAR buf2[1024]={0,};
					int index=0;
					for (int i=0; i< strlen(buf); i+=2)
                    {
                        CHAR buf3[3]={0,};
                        buf3[0] = buf[i];
                        buf3[1] = buf[i+1];
                        char *stopstring;
                        unsigned long ul = strtoul(buf3, &stopstring,  16);
						buf2[index++] = ul;
					}

					//    15050009MS-A1X13U1S0714

					char magid[40]={0,};
					memcpy(magid, buf2, 28);
					char lotno[40]={0,};
					memcpy(lotno, buf2+28, 12);
					char stepno[40]={0,};
					memcpy(stepno, buf2+40, 8);
					char partno[40]={0,};
					memcpy(partno, buf2+48, 28);
					char pkgcode[40]={0,};
					memcpy(pkgcode, buf2+76, 4);
					char qty[40]={0,};
					memcpy(qty, buf2+108, 4);

					frmRFID->AddCommLog( Now().TimeString() + " : Magazine ID  : "  +  magid );
					frmRFID->AddCommLog( Now().TimeString() + " : Lot No       : "  +  lotno );
					frmRFID->AddCommLog( Now().TimeString() + " : Step No      : "  +  stepno );
					frmRFID->AddCommLog( Now().TimeString() + " : Part No      : "  +  partno );
					frmRFID->AddCommLog( Now().TimeString() + " : Package Code : "  +  pkgcode );
					frmRFID->AddCommLog( Now().TimeString() + " : Frame Count  : "  +  qty );
					*/
                }
                else if (resp[0] == 0x06)	//ACK
                {
                    // 쓰기에 대한 응답
					//frmRFID->AddCommLog( Now().TimeString() + " : ACK !" );
                }
				else if (resp[0] == 0x15)	//NAK
				{
					// 실패/오류
					//frmRFID->AddCommLog( Now().TimeString() + " : NAK ! Please check the tag position" );
				}
				else 	//
				{
					//frmRFID->AddCommLog( Now().TimeString() + " : Unknown response ! so reject" );
				}
			}
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
String RFID::getRfidInfo()
{
	return String().sprintf(L"[ID:%d,CH:%d] ",_pPimpl->id,_pPimpl->ch);
}
//---------------------------------------------------------------------------
String RFID::getRfidErr(String sErr)
{
	String sDefineError = "";
	if(sErr=="01")
		sDefineError = "Unknown Command ID";
	else if(sErr=="02")
		sDefineError = "Not Yet Implemented Command ID";
	else if(sErr=="03")
		sDefineError = "Invalid Destination Address(Device ID)";
	else if(sErr=="04")
		sDefineError = "Invalid System Register Address";
	else if(sErr=="05")
		sDefineError = "Timeout Error";
	else if(sErr=="06")
		sDefineError = "Invalid SLRC Register Address";
	else if(sErr=="07")
		sDefineError = "Out of System Register Address Range";
	else if(sErr=="08")
		sDefineError = "Out of SLRC Register Address Range";
	else if(sErr=="09")
		sDefineError = "Out of RF Channel Number";
	else if(sErr=="0A")
		sDefineError = "Out of Bit Range";
	else if(sErr=="0B")
		sDefineError = "Invalid Bit Value";
	else if(sErr=="0C")
		sDefineError = "Check Sum Error";
	else if(sErr=="0D")
		sDefineError = "Write Command Fail";
	else if(sErr=="0E")
		sDefineError = "Read Command Fail";
	else if(sErr=="0F")
		sDefineError = "Long Data Length (max 32 bytes)";
	else if(sErr=="10")
		sDefineError = "RF Channel Disabled";
	else if(sErr=="11")
		sDefineError = "SLRC Reset Error";
	else if(sErr=="12")
		sDefineError = "SLRC Parallel Bus Error";
	else if(sErr=="13")
		sDefineError = "Max Timeslot Error(max 255)";
	else if(sErr=="14")
		sDefineError = "Not Supported RF Protocol";
	else if(sErr=="15")
		sDefineError = "ICODE Wrong Command Parameter";
	else if(sErr=="16")
		sDefineError = "ICODE Timeout";
	else if(sErr=="17")
		sDefineError = "ICODE No Tag";
	else if(sErr=="18")
		sDefineError = "ICODE CRC Error";
	else if(sErr=="19")
		sDefineError = "ICODE Collision Error";
	else if(sErr=="1A")
		sDefineError = "ICODE SNR Error";
	else if(sErr=="1B")
		sDefineError = "ICODE Count Error";
	else if(sErr=="1C" || sErr=="22" || sErr=="23" || sErr=="24" || sErr=="25" || sErr=="26")
		sDefineError = "RFU";
	else if(sErr=="1D")
		sDefineError = "ICODE Invalid Quit Value";
	else if(sErr=="1E")
		sDefineError = "ICODE Weak Collision Error";
	else if(sErr=="1F")
		sDefineError = "ICODE Write Fail";
	else if(sErr=="20")
		sDefineError = "ICODE Halt Fail";
	else if(sErr=="21")
		sDefineError = "ICODE Not implemented Error";
	else if(sErr=="27")
		sDefineError = "Family Code Mismatch";
	else if(sErr=="28")
		sDefineError = "Application Code Mismatch";
	else if(sErr=="29")
		sDefineError = "ICODE Framing Error";
	else if(sErr=="2A")
		sDefineError = "Carrier Disabled";
	else if(sErr=="A1")
		sDefineError = "Write 동작 중 Write or Read 명령 수신 시";
	else if(sErr=="A2")
		sDefineError = "Write 동작 중 Write or Read 명령 수신 시";
	else if(sErr=="A3")
		sDefineError = "Write Data의 개수가 112 Byte를 초과하는 경우";
	else if(sErr=="A4")
		sDefineError = "Length와 Data의 개수가 틀린 경우";

	return sDefineError;
}
//---------------------------------------------------------------------------
