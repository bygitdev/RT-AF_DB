//---------------------------------------------------------------------------

#pragma hdrstop

#include "Communication.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


C_Communication::C_Communication()
{
	::InitializeCriticalSection(&comm_cs);
}
//---------------------------------------------------------------------------
C_Communication::~C_Communication()
{
	::DeleteCriticalSection(&comm_cs);
	kamelaslib::DestroyKamelas(this->m_pBase);
	this->m_pBase = NULL;
}
//---------------------------------------------------------------------------
BOOL C_Communication::Init()
{
	this->m_pBase = kamelaslib::CreateKamelas(false, L"MMI2SEQ", sizeof(COMM_BUFFER) );

	BOOL bSuccess;
	bSuccess = this->m_pBase->open();
	if(!bSuccess)
		return false;
                
	return true;
}
//---------------------------------------------------------------------------

BOOL C_Communication::Recv(DWORD dwMilliSeconds)
{
	return this->m_pBase->recv((PBYTE)&m_mmiToSeq, dwMilliSeconds);
}
//---------------------------------------------------------------------------

BOOL C_Communication::Send(DWORD dwMilliSeconds)
{
	return this->m_pBase->send((PBYTE)&m_mmiToSeq, dwMilliSeconds);
}
//---------------------------------------------------------------------------
