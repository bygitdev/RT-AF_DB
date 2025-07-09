#ifndef _AXISDEF_H_
#define _AXISDEF_H_

#include <windows.h>


enum AxisName
{
	// NODE #1
	mtSTAGE1				= (0),
	mtSTAGE2				= (1),
	mtSTAGE3				= (2),
	mtSTAGE4				= (3),
	mtBTM_BLOW1				= (4),
	mtBTM_BLOW2				= (5),
	mtBTM_BLOW3				= (6),
	mtBTM_BLOW4				= (7),
	mtFLIP_Y				= (8),
	mtFLIP_Z				= (9),
	mtFLIP_R				= (10),
	mtEMPTY_TRAY_STACK		= (11),
	mtGOOD_TRAY_STACK		= (12),
	mtREJECT_TRAY_STACK		= (13),
	mtCOVER_TRAY_STACK		= (14),
	mtTRAY_PICKER_X			= (15),

	// NODE #2
	mtTRAY_PICKER_Y			= (16),
	mtTRAY_PICKER_Z			= (17),
	mtCOVER_TRAY_PICKER_X	= (18),
	mtCOVER_TRAY_PICKER_Y	= (19),
	mtCOVER_TRAY_PICKER_Z	= (20),
	mtGOOD1_TRAY_TRANSFER	= (21),
	mtGOOD2_TRAY_TRANSFER	= (22),
	mtREJECT_TRAY_TRANSFER	= (23),
	mtADC_Z					= (24),
	mtQC_VISION_Y			= (25),
	mtQC_VISION_Z			= (26),
	MAX_MT_NO   			= (27),
};
#endif

