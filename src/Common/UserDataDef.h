#ifndef USERDEF_H
#define USERDEF_H


#include "kamelaslib.h"
#include "stdint.h"


#define	_MAX_TABLE_NO_      55
#define _MAX_MTARRAY_		50
#define _MAX_DATA_			1000
#define _MAX_ERR_			10
#define _MAX_ER_DATA		1000
#define _MAX_WR_DATA		1000

#define  _MAX_UNIT_ROW_			50
#define  _MAX_UNIT_COL_			50
#define  _MAX_UNIT_1LASERSHOT_   50
#define  _MAX_UNIT_CNT_			500
#define  _MAX_CAL_SIZE_			17



#define BUFFER_SIZE   (1024 * 320)


enum PAGE_INDEX
{
	page_seelot		=0,
	page_rfid		,
};

enum CALIBRATIONFORM
{
	FRM_PICKERSTATUS			= 1,
	FRM_OFFSET      			= 2,
	FRM_4POINT      			= 3,
	FRM_AUTOCAL      			= 4,
};


enum HISTORYFORM
{
	FRM_ALARMHISTORY		    	= 1,
	FRM_RUNHISTORY		    	    = 2,
	FRM_LOTHISTORY	     			= 3,
};

enum RECIPEFORM
{

	FRM_RECIPECHANGE			    = 1,
};


enum SETUPFORM
{
	FRM_MANUALRUN					= 1,
	FRM_MANUALCUT					= 2,
	FRM_UNITCONTROL					= 3,
	FRM_QCPOSITION					= 4,
	FRM_GERBER     					= 5,
    FRM_TRAYTEACH					= 6,
    FRM_SYSTEMTEACH					= 7,


};


enum SYSTEMFORM
{
	FRM_MOTOR					= 1,
	FRM_SENSOR					= 2,
	FRM_PARAM					= 3,
	FRM_LIFETIME    			= 4,
	FRM_TOWERLAMP               = 5,
	FRM_STAUBLI                 = 6,

};


enum enCommState
{
	STATE_IDLE	= 0,
	STATE_REQ	= 1,
	STATE_BUSY	= 2,
	STATE_COMP	= 3,
	STATE_ERR	= 4,
	STATE_ERR2	= 5,
    STATE_RETRY	= 5,
	STATE_RCPCHG= 6,

	STATE_BUSY2	= 99,

};


//=======================================================================================
//GEM 	ENUMERATIONS
//========================================================================================
// XGem state
enum _XGemState{
	XGemState_Unknown = -1,
	XGemState_Init = 0,
	XGemState_Idle,
	XGemState_Setup,
	XGemState_Ready,
	XGemState_Execute
};

//	Communication state
enum _eCommState
{
	Comm_None = -1,
	Comm_Disabled = 1,
	Comm_WaitCRFromHost,
	Comm_WaitDelay,
	Comm_WaitCRA,
	Comm_Communicating,
	Comm_Enabled
};

//	Control state
enum _eControlState
{
	Control_None = -1,
	Control_EqOffline = 1,
	Control_AttemptOnline,
	Control_HostOffline,
	Control_Local,
	Control_Remote
};


//   Processing state for sample(equipment dependent)
enum _eProcessingState
{
	Processing_Stop =0,
	Processing_Run  =1,
	Processing_Error=3,
	Processing_Idle =4,
	Processing_Manual =2
};



#endif

