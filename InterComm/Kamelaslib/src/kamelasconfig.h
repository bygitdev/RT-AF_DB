#ifndef KAMELASCONFIGH
#define KAMELASCONFIGH

#include <windows.h>
#include <tchar.h>


namespace kamelaslib
{

/**
	*  KAMELAS ���ο��� ���Ǵ� �������� ����� ���� ����
	*	2009.6
	*	Hong Chan, Choi
	*	hccoi@koses.co.kr
	* 
	* 
	*  ���������� ���� ��� ����ü ����
	*  ���� ����� KAMELAS_VERSION ���� �����ϵ��� �Ѵ�.
	* 
	*
	*/


/// KAMELAS ���ο��� ���Ǵ� ����
typedef enum eConstant
{ 
	KAMELAS_VERSION		= 0x0001,	/// �������� ����
	KAMELAS_HEADER_SIZE	= 0x0040	/// ��� ũ��(64 bytes for cache-line size)
}KAMELAS_CONSTANTS;


/// KAMELAS ��� ����ü
#include <PshPack8.h>
typedef struct tagHEADER
{
	volatile UINT32	headerLength;			/// ���ũ�� = sizeof(HEADER)       	
	volatile UINT32	totalLength;			/// ��üũ��
	volatile UINT32	version;				/// ����
	volatile UINT32	lock;					/// 
	volatile UINT32	reserved[2];			/// �����
	BYTE			padding[KAMELAS_HEADER_SIZE - 6 * sizeof(UINT32)];	/// �����(�̷��� ���Ͽ�)

	struct tagHEADER()
	{
		::ZeroMemory(this, sizeof(*this));
		this->version		= KAMELAS_VERSION;
		this->headerLength	= KAMELAS_HEADER_SIZE;
	}
}HEADER, *PHEADER;
#include <PopPack.h>


}//namespace

#endif
