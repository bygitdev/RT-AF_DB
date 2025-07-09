#ifndef _INCLUDE_H_
#define _INCLUDE_H_

#include <ExtCtrls.hpp>

#include "logdll.h"

#ifdef _MAIN_CPP_
	#define EXTERN
#else
	#define EXTERN extern
#endif
                   
EXTERN CPiper	*g_pPiper;
EXTERN CTpBase	*g_pTpBase;

#endif /// _INCLUDE_H_
