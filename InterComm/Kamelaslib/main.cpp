#include <windows.h>
#include <tchar.h>
#include "src\kamelasconfig.h"
#include "src\debuglog.h"

static HMODULE g_hModule = NULL;


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID 
					 )
{
	switch(ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		g_hModule = hModule;
		break;
	case DLL_PROCESS_DETACH:
		g_hModule = NULL;
		break;
	}
    return TRUE;
}