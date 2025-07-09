#ifndef _PACKET_H_
#define _PACKET_H_

/*
---------------------------
header		|	body ................
 4 bytes	|	n bytes ..........
---------------------------
*/

#include "..\..\common\communication.h"

#pragma pack(push, 1)


typedef struct _tagMsgData
{
	int		index;	// 0,1,2,3
   	LOT_INFO body;
}MSG_DATA;

#pragma pack(pop)




#endif
