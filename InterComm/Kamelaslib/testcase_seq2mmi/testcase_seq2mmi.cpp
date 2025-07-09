// testcase.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include <stdio.h>
#include "..\src\kamelaslib.h"
#include <cassert>

#define BUFFER_SIZE	1024*20


int _tmain(int argc, _TCHAR* argv[])
{
	KamelasBase *pBase = CreateKamelas(TRUE, _T("MMI2SEQ"), BUFFER_SIZE);

	BOOL bSuccess = pBase->open();
	assert(TRUE == bSuccess);

	BYTE buffer[BUFFER_SIZE];

	while(1)
	{
		bSuccess = pBase->recv(buffer, 50);

		if (FALSE == bSuccess)
		{
			//::OutputDebugString("seq->mmi recv time out\n");
		}
		else
		{
			//::OutputDebugString("seq->mmi data has sent\n");
			bSuccess = pBase->send(buffer, 50);

			if (FALSE == bSuccess)
			{
				::OutputDebugString( _T("seq->mmi recv time out\n"));
			}
			else
			{
				::OutputDebugString( _T("\n"));
				::OutputDebugString( (TCHAR*)buffer);
			}
		}
		::Sleep(1);
	}

	return 0;
}





