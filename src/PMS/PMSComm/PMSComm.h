#ifndef PMSCommH
#define PMSCommH

#include <windows.h>

class PMS
{
	public:
		BOOL			PMSopen(INT nPort, DWORD dwBaudRate = CBR_115200);
		BOOL			PMSclose();
		BOOL			PMSisOpen();
		BOOL			PMSread(unsigned short address, String* pValue);
		BOOL			PMSwrite(unsigned short address, unsigned short value);
		BOOL 			PMSResetTrigger();

	private:
		BOOL			PMSsend(CHAR* pBuffer, DWORD dwLen);
		BOOL			PMSrecv(CHAR* pBuffer, DWORD dwLen, unsigned char chTerminator);


	private:
		HANDLE			_hFilePMS;
		unsigned short	_basePMS;

	public:
		PMS();
		virtual ~PMS();

};
#endif



