// testcase.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include <stdio.h>
#include <kamelaslib.h>
#include <cassert>

#define BUFFER_SIZE	1024*20


int _tmain(int argc, _TCHAR* argv[])
{
	KamelasBase *pBase = CreateKamelas(FALSE, _T("MMI2SEQ"), BUFFER_SIZE);
	BOOL bSuccess = pBase->open();
	assert(TRUE == bSuccess);

	BYTE buffer[BUFFER_SIZE];

	while(1)
	{
		bSuccess = pBase->send(buffer, 150);
		if (TRUE == bSuccess)
		{
			//::OutputDebugString("seq->mmi data has received\n");
			bSuccess = pBase->recv(buffer, 50);

			if (FALSE == bSuccess)
			{
				::OutputDebugString( _T("mmi->seq send time out\n"));			
			}
		}
		::Sleep(1);
	}

	DestroyKamelas(pBase);
	return 0;
}


