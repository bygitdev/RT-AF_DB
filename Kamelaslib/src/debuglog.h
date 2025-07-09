#ifndef DEBUGLOGH
#define DEBUGLOGH

#include <windows.h>
#include <stdio.h>


namespace kamelaslib
{

/** Kamelas Debug Logger
	*
	*	2009.7
	*	Hong Chan, Choi
	*	hccoi@koses.co.kr
	* 
	* �����(DEBUG) ���� �����Ͻ� ���â(Output Window)���� ����� ���� ������ 
	* ������ִ� ��ƿ��Ƽ �Լ�
	* 
	*
	*/


void DebugLog(INT32 code, TCHAR* lpMessage, ...);


};

#endif
