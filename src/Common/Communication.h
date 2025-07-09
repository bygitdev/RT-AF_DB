//---------------------------------------------------------------------------

#ifndef CommunicationH
#define CommunicationH

#include "kamelaslib.h"
#include "UserDataDef.h"

#define	_CMD_SIZE_    	32          //int * 32 = 128byte
#define MAX_ERR			10


/********************************************************************
- Motor command define
********************************************************************/

enum MOTORCMD
{
    MTCMD_SERVO_ON      = 0,
    MTCMD_SERVO_OFF     = 1,
    MTCMD_INDEX_MOVE    = 2,
    MTCMD_JOG_MOVE      = 3,
    MTCMD_JOG_STOP      = 4,
    MTCMD_R_MOVE        = 5,
    MTCMD_A_MOVE        = 6, // 절대위치 이동
    MTCMD_ALL_HOME      = 7,
	MTCMD_HOME          = 8,
    MTCMD_RESET         = 9,
    MTCMD_STOP          = 10,
};

/********************************************************************
- Communication command type define
********************************************************************/
enum COMCMD
{
    CMD_NOTHING				= 0,
    CMD_RD_IO				= 1,
    CMD_WR_IO				= 2,
    CMD_RD_PKG				= 3,
    CMD_WR_PKG				= 4,
    CMD_RD_NDM				= 5,
    CMD_WR_NDM				= 6,
    CMD_RD_DDM				= 7,
	CMD_WR_DDM				= 8,
    CMD_RD_USESKIP			= 9,
    CMD_WR_USESKIP			= 10,

    CMD_RD_MT_STATUS		= 11,
    CMD_RD_MT_TABLE			= 12,
    CMD_WR_MT_TABLE			= 13,
    CMD_WR_MT_CMD			= 14,

    CMD_RD_ERR_WR			= 15,

    CMD_RD_STAUBLI_TABLE	= 20,
    CMD_WR_STAUBLI_TABLE	= 21,
    CMD_RD_MODBUS			= 22,
    CMD_WR_MODBUS			= 23,

    CMD_RD_MAP1				= 30,
    CMD_RD_MAP2				= 31,
    CMD_RD_MAP3				= 32,
    CMD_RD_MAP4				= 33,
    CMD_WR_MAP1				= 34,
    CMD_WR_MAP2				= 35,
    CMD_WR_MAP3				= 36,
	CMD_WR_MAP4				= 37,

    CMD_RD_GOOD_SORT1		= 40,
    CMD_RD_GOOD_SORT2		= 41,
    CMD_RD_REJECT_SORT		= 42,
    CMD_WR_GOOD_SORT1		= 43,
    CMD_WR_GOOD_SORT2		= 44,
    CMD_WR_REJECT_SORT		= 45,

	CMD_RD_QPDDATA			= 47,

    CMD_WR_QC_VI_RESULT		= 50,
    CMD_WR_TOP_VI_RESULT	= 51,
    CMD_WR_BTM_VI_RESULT	= 52,
	CMD_WR_VI_MOVE			= 53,
	CMD_WR_QPD_VI_RESULT	= 54,

	CMD_RD_FLIPPER			= 55,
	CMD_WR_FLIPPER			= 56,

	CMD_RD_STG1_LOT_INFO	= 61,
	CMD_RD_STG2_LOT_INFO	= 62,	CMD_RD_STG3_LOT_INFO	= 63,	CMD_RD_STG4_LOT_INFO	= 64,	CMD_WR_STG1_LOT_INFO	= 65,	CMD_WR_STG2_LOT_INFO	= 66,	CMD_WR_STG3_LOT_INFO	= 67,	CMD_WR_STG4_LOT_INFO	= 68,	CMD_WR_RCV_LOT_INFO		= 69,	CMD_RD_LOT_END_INFO		= 70,	CMD_RD_SCRAP_INFO_OLD	= 71,  //not	CMD_RD_SCRAP_INFO_CUR	= 72,	CMD_WR_SCRAP_INFO_OLD	= 73,  //not	CMD_WR_SCRAP_INFO_CUR	= 74,	CMD_RD_OHT_LOT_INFO     = 75,	CMD_WR_LOT_END_INFO 	= 76, //
	CMD_WR_OHT_LOT_INFO     = 77,	CMD_RD_SCRAP_INFO_CUR_COPY		= 78,	CMD_WR_SCRAP_INFO_CUR_COPY 		= 79,	CMD_RD_LOT_END_LOT_INFO_COPY	= 80,	CMD_RD_LOTINFO_CUR		= 81,	CMD_RD_BUFFER_LOTINFO	= 82,	// RMS For Rcp Change	CMD_WR_BUFFER_LOTINFO	= 83,	// RMS For Rcp Change	CMD_RD_MSGNOTICE    	= 99,};


#define MAX_SELMAP_IDX	(20)

enum enLR
{
	L		= 0,
	R		= 1,
	LR		= 2,
};


enum enPcbState
{
	SELMAP_NOTHING	= 0,
	SELMAP_DUMMY	= 0x01,
	SELMAP_NORMAL	= 0x02,
	SELMAP_FLIP		= 0x04,
	SELMAP_EXIST	= 0x07,
};

typedef struct _MapBit
{
	WORD state			: 8;
	WORD isViGood		: 1;
	WORD spare			: 7;
}SelMapBit;



typedef struct _SelMap
{
	SelMapBit bit[MAX_SELMAP_IDX][MAX_SELMAP_IDX];
}SelMap;


typedef struct tagMCOperation
{
    BOOL isEmg;
    BOOL isStop;
    BOOL isAuto;
    BOOL isPausedStop;
    BOOL isDoorOpen;
	BOOL isDoorUnlock;
    BOOL isCycleRun;
	BOOL isAllHome;
	BOOL isDryRun;
}MCOPR;



/********************************************************************
- 공통으로 사용되는 구조체
********************************************************************/

#pragma pack(push, 1)


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//from now on the commmon structure
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct _CommMtControl
{
	int		nMtNo;
    int		nCmd;
    int		nCmdIndexNo;
    int		nDir;
    double	dPulse;
}CommMtControl;

typedef struct _CommMtTable
{
	int		nMtNo;
    double	dVel[50];
    double	dPos[50];
    double	dAcc[50];
}CommMtTable;

typedef struct _CommMtStatus
{
	int		nMtNo;
	BOOL	bServoOn;
	BOOL	bAlarm;
	BOOL	bDriving;
	BOOL	bPaused;
	BOOL	bHome;
	BOOL    bHoming;
	BOOL	bCw;
	BOOL	bCCw;
	BOOL	bOrg;
	int		nCurIndex;
	double	dRealCnt;
}CommMtStatus;

typedef struct _CommReadIO
{
	WORD inCH[50];
	WORD outCH[50];
}CommReadIO;

typedef struct _CommWriteIO
{
	int  nIONo;
	BOOL bOn;
}CommWriteIO;


typedef struct _CommInt
{
	int nStart;
	int nEnd;
	int nVal[1000];
}CommInt;

typedef struct _CommDouble
{
	int nStart;
	int nEnd;
	double dVal[1000];
}CommDouble;

typedef struct _CommStaubliTable
{
	float posX[30];
	float posY[30];
	float posZ[30];
	float posRZ[30];
	float posZOffset[30];
	float speed[30];
}StaubliTable;


typedef struct _CommModbus
{
//	uint8_t coils[16];
//	uint8_t discreteInput[16];
//	float holdingRegister[44];
//	float inputRegister[8];

	uint8_t coils[16];
	uint8_t discreteInput[16];
	float holdingRegister[45];
	float inputRegister[13];
}Modbus;

typedef struct _PRsResult
{
    double x;
    double y;
    double t;
}PRSResult;

typedef struct _VisionMove
{
    int viNo; // 0(Qc), 1(Btm),
    double posX;
    double posY;
    double velocity;
}VisionMove;

typedef struct _CommErrWar
{
	int err[10];
	int wr[10];
}CommErrWr;




#define SCRAP_MAX_CNT	(20)

typedef struct
{
	//rfid
	char carrierID[64];	// 캐리어 고유 ID, RFID전면에 마킹됨 15050032
	char eqpID[64];		// 설비번호 AROUT-X04
	int magQty;			// rfid 에서 읽은 수량
	char lotID[64];		// LotID X0SP050716
	char step[16];		// 해당step 정보 M033
	char partID[64];	// MZ7LN256HMJP-000H1-G11

	//
	char portID[64];	// 포트 ID,  AROUT-X07
	char mergeLotID[64];// X007B00508
	int lotQty;			// 600
	char subLotID[64];	//
	int mergeLotQty;    //

	//
	char pcbBarcode[64];	// 바코드 정보 2000000000L2MZ7LN250150800000001
	char pcbModel[64];		// 2.5_850EVO_PRO_6A
	int pcbArrayBaseQty;	// 8
	char pcbTestResult[SCRAP_MAX_CNT]; //11111111
	char pcbArtsScrap[64];	// 3369:2, *N (: 뒤 숫자는 testresult 에서의 불량위치 1 부터 배열 인덱스)

	int pcbXOutCnt;	//0
	int scrapCnt;	//8   (online end 에 의해 서버에서 받은 스크랩 개수)
	char scrapCode[SCRAP_MAX_CNT][64];	//SCRAP_INFO001=(SCRAP_CODE=3350 ARRAYSN=2000000000L1MZJPU512143300005772_3 SERIAL= EQPMODEL=ROUTER_SORTER)
	char scrapArraySN[SCRAP_MAX_CNT][64];
	char scrapSerial[SCRAP_MAX_CNT][64];

	char aoiScrapCodeList[64];
	char aoiScrapResult[SCRAP_MAX_CNT];
	char aoiScrapCode[SCRAP_MAX_CNT][64];

    int lotStatus;	// unused

	// OHT 사용시에 추가 -----------------------------
	char tray1Mark[64]; //Sorter에서 비교해야 할 Tray OCR Code	int tray1OhtQty;    // Oht사용시 이송해야 할 Tray Max 수량	int tray1ProdQty;   // Router에서 Merge 할 Unit Max 수량	char rejectLotID[64]; // RejectLotID X0SP050716
	char rejectCarrierID[64];  // reject tray cover

	char lotType[16];	//add 4 RMS (1024-16)
	char recipeID[64];	//add 4 RMS (1008-64)
	char reserved[944];
	char mergeLotIDData[64]; // Log표준화 Merger LotID Data
	char tier[16]; //RSM
	char weekcode[16];
	char option[16];
	char assyline[16];
	char rproperty[64]; //RSM
	char splitLotID[64]; //RSM
	int  mergeCnt;
	int  inputLotQty;
	int  splitMgzLotQty;
	int  mergeMgzLotQty;
	int  inputTray1Cnt;
	int  curQty;

}LOT_INFO;


typedef struct
{
	int 	scrapCnt;
	char	mergeLotID[64];
	char	scrapCode[1000][64];
	char	scrapArraySN[1000][64];
}SCRAP_INFO;

typedef struct _MsgNotice
{
	char    strMsgTtile[100];
	char    strBtn[4][10];
}MsgNotice;

typedef struct _AUTOFEEDBACK_INFO
{
	int qcStageNo;
	int qcBridgeCnt[4];
	double	qcBridgeDataOffset[4][200];
}AUTOFEEDBACK_INFO;

typedef union tagBufferData
{
    CHAR bufferSize[BUFFER_SIZE]; //#define  BUFFER_SIZE      (1024 * 320)

    CommMtControl	motControl;
    CommMtTable		motTable;
    CommMtStatus	motStatus;
    CommWriteIO 	wrIO;
    CommReadIO		rdIO;

    CommDouble		pkg;
    CommDouble		ddm;
    CommInt			ndm;
    CommInt			useSkip;

    StaubliTable	staubliTable;
    Modbus			modbus;

    CommErrWr			errWr;

    PRSResult		btmPRsResult;
    PRSResult		topPRsResult[20];
	PRSResult		qpdPRsResult[100];
    int				qcViResult[20];
    VisionMove		viMoveCmd;
    int				selMap[20][20]; // [x][y]
    UINT32			flipMap[4];

	LOT_INFO		lotInfo;
	LOT_INFO		lotInfoCopy;
	SCRAP_INFO		onlineEndHistory;	//lot end 시 확인용
	SCRAP_INFO		onlineEndHistoryCopy;

	MsgNotice		msg;

}BUFFER_DATA;


typedef struct tagCommBuffer
{
    BUFFER_DATA buffer;
    int         nCmd;
}COMM_BUFFER;

#pragma pack(pop)


class C_Communication
{
private :
	KamelasBase* 	m_pBase;
public :
	COMM_BUFFER		m_mmiToSeq;
	BOOL Init(void);
	BOOL Recv(DWORD dwMilliSeconds = 100);
	BOOL Send(DWORD dwMilliSeconds = 50);

    void MtControl(CommMtControl cmd);

	CRITICAL_SECTION comm_cs;
public:
	C_Communication();
	virtual ~C_Communication();
};
//---------------------------------------------------------------------------

extern C_Communication *g_MMIComm;

class Monitor
{
private:
	CRITICAL_SECTION*	_pcs;

public:
	explicit Monitor(CRITICAL_SECTION* pcs);
	~Monitor();
};

Monitor::Monitor(CRITICAL_SECTION* pcs)
	: _pcs(pcs)
{
	::EnterCriticalSection(_pcs);
}

Monitor::~Monitor()
{
	::LeaveCriticalSection(_pcs);
}
#endif
