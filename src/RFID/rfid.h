//---------------------------------------------------------------------------

#ifndef rfidH
#define rfidH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <System.Win.ScktComp.hpp>

#pragma pack(push,1)
typedef struct
{
	char	carrierID[16];		// 캐리어 고유 ID, RFID전면에 마킹됨
	char	qty[12];
    char    lotID[12];
	char    step[8];
    char	partNo[63];
} RFID_PACKET;
#pragma pack(pop)

typedef struct
{
	String	carrierID;		// 캐리어 고유 ID, RFID전면에 마킹됨
	//String	eqpID;			// 해당 Lot이 Dispatching받은 설비번호
	String	qty;				// Tray 묶음별 QTY
	String	lotID;			// LotID
	String	step;			// 해당step 정보
	String	partNo;			// Part NO 로 최대 28자리까지 할당됨
	//String	cnt;				// 한 Lot이 2개 이상의 실물로 이동할 경우,이들의 순서를 기입함
	//String	trayQty;			// lot안에 tray총 매수, 매거진 묶음 수로 표현 0104 -> 4묶음 중 1번째 묶음
} RFID_DATA;



class RFIDPimpl;
class RFID
{
private:
	RFIDPimpl*	_pPimpl;
	RFID_DATA	parsing(RFID_PACKET* packet);

public:
	RFID(int ID, int CommType, int Maker);
	~RFID();

	bool	initialize(int nPort);
	bool	initialize(String ipAddress, int nPort);
	bool	isInitialized();
    bool	read(int ch);	//ch (0, 1)
	bool	write(int ch, AnsiString stepNo, AnsiString lotNo, AnsiString partNo, AnsiString qty, bool bAuto);

	bool		isRecv();
	bool		isWrite();
	RFID_DATA	get_data();
	String		getRfidInfo();
	String		getRfidErr(String sErr);

	static unsigned int __stdcall fnCommThread(void*);

	void __fastcall OnRecv(System::TObject* Sender, TCustomWinSocket* Socket);
	void __fastcall OnConnect(System::TObject* Sender, TCustomWinSocket* Socket);
    void __fastcall OnDisconnect(System::TObject* Sender, TCustomWinSocket* Socket);
    void __fastcall OnError(System::TObject* Sender, TCustomWinSocket* Socket, TErrorEvent ErrorEvent, int &ErrorCode);


};
#endif
