#include "kamelasmanager.h"
#include "debuglog.h"
#include <set>
#include <string>
#include <cassert>

namespace kamelaslib
{

/// �����̳� Ÿ��
typedef std::set<const KamelasBase*> CONTAINER;
typedef CONTAINER::iterator CONTAINER_IT;

class KamelasManagerPimpl
{
public:
	CONTAINER container;
	CRITICAL_SECTION cs;

	KamelasManagerPimpl()
	{
		::InitializeCriticalSection(&cs);
	}
	virtual ~KamelasManagerPimpl()
	{
		::DeleteCriticalSection(&cs);
	}
};

/// ũ��Ƽ�� ���� ����ȭ ��ü 
/// ������, �Ҹ��ڸ� �̿��� ������ �ڿ����� ��� 
class Monitor
{
private:
	LPCRITICAL_SECTION	_pcs;
public:
	Monitor(LPCRITICAL_SECTION pcs)
		: _pcs(pcs)
	{
		assert(NULL != pcs);
		::EnterCriticalSection(_pcs);
	}
	~Monitor()
	{
		::LeaveCriticalSection(_pcs);
	}
};


KamelasManager::KamelasManager()
{
	_pPimpl = new KamelasManagerPimpl;
	assert(NULL != _pPimpl);

}

KamelasManager::~KamelasManager()
{
	this->clear();
	delete _pPimpl;
}

/// �ν��Ͻ� ����
UINT32 KamelasManager::size()
{
	return _pPimpl->container.size();
}

/// �ν��Ͻ� ��� ����
void KamelasManager::clear()
{
	Monitor m( &_pPimpl->cs);

	CONTAINER_IT it;

	while(false == _pPimpl->container.empty())
	{
		it = _pPimpl->container.begin();
		this->detach(*it);
	}
}

/// �ν��Ͻ� �߰�
bool KamelasManager::attach(const KamelasBase *pBase)
{	
	Monitor m( &_pPimpl->cs);
			
	if (NULL != this->query(pBase->name()))
	{
		DebugLog(-1, _TEXT("kamelas : manager detect duplicated instance attached. so abort : %s"), pBase->name() );
		return false;
	}

	_pPimpl->container.insert( pBase);
	DebugLog(0, _TEXT("kamelas : instance attached : %s"), pBase->name());

	return true;
}

/// �ν��Ͻ� ����
bool KamelasManager::detach(const KamelasBase *pBase)
{
	Monitor m( &_pPimpl->cs);
				
	CONTAINER_IT it = _pPimpl->container.find(pBase);
		
	if ( it == _pPimpl->container.end() )
	{
		DebugLog(-1, _TEXT("kamelas : fail to search the instance : %s"), pBase->name());			
		return false;
	}

	DebugLog(0, _TEXT("kamelas : detach the instance : %s"), pBase->name());
	const_cast<KamelasBase*>(*it)->close();
	delete (*it);
	_pPimpl->container.erase( it );

	return TRUE;
}

/// �ν��Ͻ� �̸����� ��ȸ
KamelasBase* KamelasManager::query(LPCTSTR lpName)
{
	Monitor m( &_pPimpl->cs);

	CONTAINER_IT it = _pPimpl->container.begin();
		
	for ( ; it != _pPimpl->container.end();  ++it)
	{
		if (!_tcscmp((*it)->name() , lpName))
		{
			return const_cast<KamelasBase*>(*it);
		}
	}		

	return NULL;
}

/// �ν��Ͻ� �ε����� ��ȸ
KamelasBase*	KamelasManager::at(UINT32 index)
{
	Monitor m( &_pPimpl->cs);
	CONTAINER_IT it;
	it = _pPimpl->container.begin();
		
	for (UINT i=0 ; i < index;  ++i, ++it)
		if (it == _pPimpl->container.end())
			return NULL;
			
	return const_cast<KamelasBase*>(*it);	
}

/// �ν��Ͻ� �߰�
bool KamelasManager::operator+=(const KamelasBase* pBase)
{
	return this->attach(pBase);
}

/// �ν��Ͻ� ����
bool KamelasManager::operator-=(const KamelasBase* pBase)
{
	return this->detach(pBase);
}

/// �ν��Ͻ� �̸����� ��ȸ
KamelasBase& KamelasManager::operator[] (LPCTSTR lpName)
{
	assert(NULL != lpName);
	return *(const_cast<KamelasBase*>(this->query(lpName)));
}

}//namespace

/// �Ŵ��� ��ü ���(�̱���)
void WINAPI GetManager(kamelaslib::KamelasManager** pManager)
{	
	static kamelaslib::KamelasManager manager;
	*pManager = &manager;
}