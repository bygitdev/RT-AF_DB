#ifndef barcodeH
#define barcodeH

#include <vcl.h>
#include <System.Win.ScktComp.hpp>



class BarcodePimpl;
class Barcode
{
private:
	BarcodePimpl*	_pPimpl;

public:
	Barcode(int ID, int CommType);
	~Barcode();

	bool	initialize(int nPort);
	bool	initialize(String ipAddress, int nPort);
	bool	isInitialized();
	bool	trigger(bool onOff);
	bool	isRecv();
	AnsiString	getRecvData();
	void 	RecvData(String data);
	void	clear();
	int		getCommType();


	static unsigned int __stdcall fnCommThread(void*);

    void __fastcall OnRecv(System::TObject* Sender, TCustomWinSocket* Socket);
    void __fastcall OnConnect(System::TObject* Sender, TCustomWinSocket* Socket);
    void __fastcall OnDisconnect(System::TObject* Sender, TCustomWinSocket* Socket);
    void __fastcall OnError(System::TObject* Sender, TCustomWinSocket* Socket, TErrorEvent ErrorEvent, int &ErrorCode);


};
#endif
