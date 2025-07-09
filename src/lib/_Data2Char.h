#ifndef _DATA2CHAR_H_
#define _DATA2CHAR_H_

#include <Windows.h>

#define _charSize	20
#define _MAX_AXIS_	39
#define _MAX_INDEX_	20
#define _MAX_PNEUM_	100

enum _mtd2charDef
{
	_POS_		= 0,
	_SPD_		= 1,
	_ACC_		= 2,
	_POSIDX_	= 3,	/// position name
	_SPDIDX_	= 4,	/// speed name
	_ACCIDX_	= 5,
	_MAX_		= 6,
};

typedef struct _globalChk
{
	BOOL bTransfer[_MAX_AXIS_][_MAX_INDEX_];
	BOOL bFunction[_MAX_PNEUM_];
}LOG_CHK;


typedef struct _groupInpnp
{
	_char Y[_MAX_INDEX_][_MAX_][_charSize];
	_char Z[_MAX_INDEX_][_MAX_][_charSize];
	_char Clamp[_MAX_INDEX_][_MAX_][_charSize];
}cGroupInpnp;

typedef struct _groupStage
{
	_char Index[_MAX_INDEX_][_MAX_][_charSize];
	_char Clean[_MAX_INDEX_][_MAX_][_charSize];
	_char Theta[_MAX_INDEX_][_MAX_][_charSize];
	_char MaskPk[_MAX_INDEX_][_MAX_][_charSize];
}cGroupStage;

typedef struct _groupRouter
{
	_char Y[_MAX_INDEX_][_MAX_][_charSize];
	_char Z[2][_MAX_INDEX_][_MAX_][_charSize];
	_char Conv[_MAX_INDEX_][_MAX_][_charSize];
}cGroupRouter;

typedef struct _groupScrappnp
{
	_char Y[_MAX_INDEX_][_MAX_][_charSize];
	_char Z[_MAX_INDEX_][_MAX_][_charSize];
}cGroupScrappnp;

typedef struct _groupStanding
{
	_char X[_MAX_INDEX_][_MAX_][_charSize];
	_char Z[_MAX_INDEX_][_MAX_][_charSize];
}cGroupStanding;

typedef struct _groupReject
{
	_char PnpX[_MAX_INDEX_][_MAX_][_charSize];
}cGroupReject;

typedef struct _groupAdc
{
	_char GripperX[_MAX_INDEX_][_MAX_][_charSize];
	_char RailZ[_MAX_INDEX_][_MAX_][_charSize];
}cGroupAdc;

typedef struct _pmIO
{			// act // io
	_char In[3][2][_charSize];
	_char out[3][2][_charSize];
}cPmIO;

typedef struct _data2char
{
	_char			cPmName[_MAX_PNEUM_][_charSize];
	cPmIO			cPmIO[_MAX_PNEUM_];

	_char			cMtName[_MAX_AXIS_][_charSize];
	_char			cInRailStopper[_MAX_INDEX_][_MAX_][_charSize];	/// part data
	cGroupInpnp		cInPnp;
	cGroupStage		cStage[4];
	cGroupRouter	cRouter[2];
	cGroupScrappnp	cScrapPnp;
	cGroupStanding	cStanding[2];
	cGroupReject	cReject;
	cGroupAdc		cAdc;
	_char			cStaubliTilt[_MAX_INDEX_][_MAX_][_charSize];	///////////////////////
}DATA2C;

_char* w2c(char* msg);

void copyPmName(void);
void copyPmIoData(void);

void copyMtName(void);

void copyPosName(void);
void copySpeedName(void);
void copyAccelName(void);

void copyPosData(void);
void copySpeedData(void);
void copyAccelData(void);

void copy2Mtd(BOOL bInit = FALSE);

#endif	/// _DATA2CHAR_H_