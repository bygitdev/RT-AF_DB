//---------------------------------------------------------------------------

#ifndef NvMemH
#define NvMemH
//---------------------------------------------------------------------------
#include <windows.h>
#include <tchar.h>
#include "CSanSu.h"
#include "MMF.h"


#define pNvSingleTon NVMEM::CNvMem::Singleton() //추가 선언하지 않고 이것으로 사용함.
#define BUFFER_SIZE   (1024 * 320)

#define  _MAX_UNIT_ROW_			50
#define  _MAX_UNIT_COL_			50
#define  _MAX_UNIT_1LASERSHOT_   50
#define  _MAX_UNIT_CNT_			500
#define  _MAX_CAL_SIZE_			17

#define  MAX_MTARRAY			50



#define pNvSingleTon NVMEM::CNvMem::Singleton() //추가 선언하지 않고 이것으로 사용함..

namespace NVMEM
{
#pragma pack(push, 2)

	// NV memory
	typedef struct _NvData
	{
		double		pkg[1000];
		double		ddm[1000];
		INT32		ndm[1000];
		INT32		useSkip[500];
	}NvData;

	// Motor Table
	typedef struct _NvMotTable
	{
		double pos[50];
		double vel[50];
		double acc[50];
	}NvMotTable;

	// Staubli Table
	typedef struct _StaubliData
	{
		int posX[30];
		int posY[30];
		int posZ[30];
		int posRZ[30];
		int posZOffset[30];
		int speed[30];
		int acc[30];
		int dcc[30];
		int spare8[30];
		int spare9[30];
	}StaubliTable;




#pragma pack(pop)

	//////////////////////////////////////////////////////////////////////////

	class CNvMem
	{
	private:
		CMMF*			m_pMMFData;
		CMMF*			m_pMMFShared;
		CMMF*			m_pMMFMotTable;
		CMMF*			m_pMMFRobotTable;

	public:
		NvData*			m_pData;
		NvMotTable*		m_pMotTable;
		StaubliTable*	m_pRobotTable;

		double& Pkg(int nNo);
		double& DDm(int nNo);
		INT32&  NDm(int nNo);
		INT32& UseSkip(int nNo);

	public:
		explicit CNvMem();
		virtual ~CNvMem();

		BOOL  Open(void);
		static CNvMem* Singleton(void);
	};
};

using namespace NVMEM;

extern CNvMem *g_pNvMem;

#endif
