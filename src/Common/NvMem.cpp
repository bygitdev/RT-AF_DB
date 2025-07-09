//---------------------------------------------------------------------------

#pragma hdrstop

#include "NvMem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace NVMEM
{
	//---------------------------------------------------------------
	CNvMem::CNvMem()
	{

	}

	CNvMem::~CNvMem()
	{

	}

	//---------------------------------------------------------------
	CNvMem* CNvMem::Singleton(void)
	{
		static CNvMem NvMemory;
		return (&NvMemory);
	}


	//---------------------------------------------------------------
	BOOL CNvMem::Open(void)
	{
		// PKG, DM
		int nNVSize = sizeof(NvData);
		m_pMMFData = new CMMF(L"nvFile", L"C:\\KOSES\\SEQ\\SSD_SORTER\\Nv.dat", nNVSize);

		if(!m_pMMFData->Open())
			return (FALSE);
		m_pData = (NvData*)m_pMMFData->GetAddr();

		// Motor Table
		int nMotTableSize = (((3 * 8) * 50) * 100); // pos,vel,acc table(50) * axis(100)
		m_pMMFMotTable = new CMMF(L"motTable", L"C:\\KOSES\\SEQ\\SSD_SORTER\\MotNv.dat", nMotTableSize);

		if(!m_pMMFMotTable->Open())
			return (FALSE);
		m_pMotTable = (NvMotTable*)m_pMMFMotTable->GetAddr();


		int robotTableSize = (4 * 30) * 10;
		m_pMMFRobotTable = new CMMF(L"robotTable", L"C:\\KOSES\\SEQ\\SSD_SORTER\\RobotNv.dat", robotTableSize);
		m_pRobotTable = (StaubliTable*)m_pMMFRobotTable->GetAddr();

		return (TRUE);
	}


	//---------------------------------------------------------------
	double& CNvMem::Pkg(int nNo)
	{
		return (m_pData->pkg[nNo]);
	}
	double& CNvMem::DDm(int nNo)
	{
		return (m_pData->ddm[nNo]);
	}
	INT32& CNvMem::NDm(int nNo)
	{
		return (m_pData->ndm[nNo]);
	}
	INT32& CNvMem::UseSkip(int nNo)
	{
		return (m_pData->useSkip[nNo]);
	}

};

