#include <vcl.h>
#pragma hdrstop

#include <stdio.h>
#include "PMSComm.h"

#define READ_TIME_OUT_MS	(2000)
#define MAX_FRAME_LEN 		(256)
#define MY_PURGE_EVENT 		(PURGE_TXABORT | PURGE_RXABORT | PURGE_TXCLEAR | PURGE_RXCLEAR)


PMS::PMS()
	: _hFilePMS(NULL)
	, _basePMS(0x0000)
{

}
//---------------------------------------------------------------------------
PMS::~PMS()
{
	this->PMSclose();
}
//---------------------------------------------------------------------------

BOOL PMS::PMSisOpen()
{
	return NULL != this->_hFilePMS;
}
//---------------------------------------------------------------------------
BOOL PMS::PMSopen(INT nPort, DWORD dwBaudRate)
{
	CHAR cpName[8];
	::DCB CommPMS;
	BOOL fRet;
	String StrCom = IntToStr(nPort);

	//sprintf(cpName,"COM%d", nPort);
	this->_hFilePMS = ::CreateFile( StrCom.w_str(),
		GENERIC_READ|GENERIC_WRITE,
		0,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	if(INVALID_HANDLE_VALUE == this->_hFilePMS)
	{
		this->_hFilePMS = NULL;
		return FALSE;
	}

	fRet = ::SetupComm(this->_hFilePMS, MAX_FRAME_LEN, MAX_FRAME_LEN);
	if(!fRet)
	{
		this->PMSclose();
		return FALSE;
	}

	fRet = ::PurgeComm(this->_hFilePMS, MY_PURGE_EVENT);
	if(!fRet)
	{
		this->PMSclose();
		return FALSE;
	}

	// Comm timeout set
	COMMTIMEOUTS CommTimeOuts;
	CommTimeOuts.ReadIntervalTimeout 			= 1;
	CommTimeOuts.ReadTotalTimeoutMultiplier 	= 5;
	CommTimeOuts.ReadTotalTimeoutConstant 		= 100;
	CommTimeOuts.WriteTotalTimeoutMultiplier 	= 5;
	CommTimeOuts.WriteTotalTimeoutConstant 		= 100;
	fRet = ::SetCommTimeouts(this->_hFilePMS, &CommTimeOuts);
	if(!fRet)
	{
		this->PMSclose();
		return FALSE;
	}


	// DCB Block Set
	CommPMS.DCBlength = sizeof(DCB) ;
	fRet = ::GetCommState( this->_hFilePMS, &CommPMS) ;
	if(!fRet)
	{
		this->PMSclose();
		return FALSE;
	}

	CommPMS.BaudRate 	= dwBaudRate;
	CommPMS.Parity 		= EVENPARITY; 	// Parity Setting
	//-> Keyence PMS : EVENPARITY , Ace-tech PMS : NOPARITY
	
	CommPMS.ByteSize 	= 8; 			// Data Size Setting
	CommPMS.StopBits 	= ONESTOPBIT; 	// Stop Bit Setting
	fRet = ::SetCommState(this->_hFilePMS, &CommPMS);
	if(!fRet)
	{
		this->PMSclose();
		return FALSE;
	}

	CHAR strSendBuffer[5] = {0,};  	// Keyence PMS reset trigger! = 'LOFF\r'
	strSendBuffer[0] = 0x4C;
	strSendBuffer[1] = 0x4F;
	strSendBuffer[2] = 0x46;
	strSendBuffer[3] = 0x46;
	strSendBuffer[4] = 0x0D;

	if (false == this->PMSsend( strSendBuffer, sizeof(strSendBuffer)))
		return false;

	return TRUE;

}
//---------------------------------------------------------------------------

BOOL PMS::PMSclose()
{
	if (NULL == this->_hFilePMS)
		return FALSE;

	::CloseHandle(this->_hFilePMS);
	this->_hFilePMS = NULL;
	return TRUE;
}
//---------------------------------------------------------------------------

BOOL PMS::PMSsend(CHAR* pBuffer, DWORD dwLen)
{
	BOOL bRet;
	DWORD dwWritten, dwErr;
	::COMSTAT CommState;

	::ClearCommError(this->_hFilePMS, &dwErr, &CommState);
	bRet = ::PurgeComm( this->_hFilePMS, MY_PURGE_EVENT);
	if(!bRet)
		return FALSE;

	bRet = ::WriteFile( this->_hFilePMS,
		pBuffer,
		dwLen,
		&dwWritten,
		NULL );

	if(!bRet)
		return FALSE;

	return (dwWritten == dwLen);

}
//---------------------------------------------------------------------------
BOOL PMS::PMSrecv(CHAR* pBuffer, DWORD dwLen, unsigned char chTerminator)
{
	BOOL bRet;
	DWORD dwReaded=0, dwRdTotal=0, dwErr;
	::COMSTAT CommState;

	::ClearCommError( this->_hFilePMS, &dwErr, &CommState);

	DWORD dwStartTime = ::GetTickCount();

	while((dwStartTime + READ_TIME_OUT_MS) > ::GetTickCount())
	{
		bRet = ReadFile( this->_hFilePMS,
			(pBuffer+dwRdTotal),
			dwLen - dwRdTotal,
			&dwReaded,
			NULL );

		if(!bRet)
			return false;

		if(dwReaded !=0 )
		{
			dwRdTotal += dwReaded;

			if (pBuffer[dwRdTotal-1] == chTerminator)
				return true;

			if (dwRdTotal == dwLen)
				return true;
		}
	}
	return false;
}
//---------------------------------------------------------------------------

BOOL PMS::PMSread(unsigned short address,String *pValue)
{
	CHAR strSendBuffer[4] = {0,};
	CHAR strRecvBuffer[30]	= {0,};

	strSendBuffer[0] = 0x4C;   	// Keyence PMS read trigger! = 'LON\r'
	strSendBuffer[1] = 0x4F;
	strSendBuffer[2] = 0x4E;
	strSendBuffer[3] = 0x0D;    


	if (false == this->PMSsend( strSendBuffer, sizeof(strSendBuffer)))
		return false;
	Sleep(200);

	if (false == this->PMSrecv( strRecvBuffer, sizeof(strRecvBuffer), '\r'))	//0x0D
		return false;

	*pValue = String(strRecvBuffer);

	return TRUE;
}
//---------------------------------------------------------------------------

BOOL PMS::PMSResetTrigger()
{
	CHAR strSendBuffer[5] = {0,};  	// Keyence PMS reset trigger! = 'LOFF\r'
	strSendBuffer[0] = 0x4C;
	strSendBuffer[1] = 0x4F;
	strSendBuffer[2] = 0x46;
	strSendBuffer[3] = 0x46;
	strSendBuffer[4] = 0x0D;

	if (false == this->PMSsend( strSendBuffer, sizeof(strSendBuffer)))
		return false;

	return TRUE;
}
//---------------------------------------------------------------------------

