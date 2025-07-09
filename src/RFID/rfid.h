//---------------------------------------------------------------------------

#ifndef rfidH
#define rfidH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <System.Win.ScktComp.hpp>

#pragma pack(push,1)
typedef struct
{
	char	carrierID[16];		// ĳ���� ���� ID, RFID���鿡 ��ŷ��
	char	qty[12];
    char    lotID[12];
	char    step[8];
    char	partNo[63];
} RFID_PACKET;
#pragma pack(pop)

typedef struct
{
	String	carrierID;		// ĳ���� ���� ID, RFID���鿡 ��ŷ��
	//String	eqpID;			// �ش� Lot�� Dispatching���� �����ȣ
	String	qty;				// Tray ������ QTY
	String	lotID;			// LotID
	String	step;			// �ش�step ����
	String	partNo;			// Part NO �� �ִ� 28�ڸ����� �Ҵ��
	//String	cnt;				// �� Lot�� 2�� �̻��� �ǹ��� �̵��� ���,�̵��� ������ ������
	//String	trayQty;			// lot�ȿ� tray�� �ż�, �Ű��� ���� ���� ǥ�� 0104 -> 4���� �� 1��° ����
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
