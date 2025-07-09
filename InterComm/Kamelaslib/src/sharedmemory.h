#ifndef sharedmemoryH
#define sharedmemoryH


#include "kamelasbase.h"

#ifdef __cplusplus
extern "C"
{
#endif
	
namespace kamelaslib
{
	/** Win32 Memory Mapped File 
	* 
	*  
	*	2009.6
	*	Hong Chan, Choi
	*	hcchoi@koses.co.kr
	* 
	*  Win32 ���� �����ϴ� IPC������� �����޸�(MMF)�� ����� ����Ÿ ��������� ����ϸ�,
	*  1:1 ��ű���� �����ϱ� ���� �۽Ź� ���ſ� ä���� �и��Ͽ���.
	*  ��, �޸� ������ �ΰ��� ū �������� ������, 
	*  �۽Žÿ��� �����޸� ������ ����ϰ�,
	*  ���Žÿ��� �����޸� ������ ����ϰ� �ȴ�.
	*  �� ä�ΰ� Ÿ�Ӿƿ� ������ ���� �ۼ��� �̺�Ʈ�� �и��Ͽ� ������.
	* 
	*/

class SharedMemoryPimpl;
class SharedMemory
	: public KamelasBase
{
public:
	virtual BOOL	__stdcall	open();
	virtual	BOOL	__stdcall	close();
	virtual	BOOL	__stdcall	isOpen();  
	virtual	LPCTSTR __stdcall	name() const;
	virtual	UINT32	__stdcall	size() const;
	virtual	BOOL	__stdcall	recv(PVOID pBuffer, UINT32 milliSeconds);
	virtual	BOOL	__stdcall	send(PVOID pBuffer, UINT32 milliSeconds);

private:
	SharedMemoryPimpl*	_pPimpl;

public:
	explicit SharedMemory(LPCTSTR lpName, UINT32 size, BOOL bServer);
	virtual ~SharedMemory();
};
	
}//namespace

#ifdef __cplusplus
}
#endif  //__cplusplus


#endif
