//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fmain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmRFIDTestcase *frmRFIDTestcase;
//---------------------------------------------------------------------------
__fastcall TfrmRFIDTestcase::TfrmRFIDTestcase(TComponent* Owner)
	: TForm(Owner)
{
	_pCeyon = NULL;
    //_pCeyonEvent = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TfrmRFIDTestcase::Button1Click(TObject *Sender)
{
    /// COM √ ±‚»≠
	::CoInitialize(NULL);
    HRESULT hr = CoCreateInstance(\
		CLSID_XCyRem,
        NULL,
        CLSCTX_INPROC_SERVER,
        DIID__DXCyRem,
        reinterpret_cast<void**>(&_pCeyon));

    if (S_OK != hr)
    {
		Memo1->Lines->Add("XCyrem ActiveX is not registered ! run regsvr32 xcyrem.ocx first !");
        return;
    }


//    HRESULT hr = CoCreateInstance(\
//        CLSID_XCyRem,
//        NULL,
//        CLSCTX_INPROC_SERVER,
//        DIID__DXCyRemEvents,
//        reinterpret_cast<void**>(&_pCeyonEvent));


	//for safety reason ?
    _pCeyon->ReleasePort();

	_pCeyon->set_Port(0);
    _pCeyon->set_Speed(9600);
    _pCeyon->InitializePort();


    //_pCeyon->WriteTag()
    //_pCeyon->ReadTag()


}
//---------------------------------------------------------------------------

void __fastcall TfrmRFIDTestcase::FormDestroy(TObject *Sender)
{
	if (_pCeyon)
    {
		_pCeyon->ReleasePort();

        _pCeyon->Release();
        _pCeyon = NULL;
    }


}
//---------------------------------------------------------------------------

