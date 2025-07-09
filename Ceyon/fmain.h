//---------------------------------------------------------------------------

#ifndef fmainH
#define fmainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "src\XCYREMLib_TLB.h"

//---------------------------------------------------------------------------
class TfrmRFIDTestcase : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TMemo *Memo1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations
	_DXCyRem*			_pCeyon;
    //_DXCyRemEvents*		_pCeyonEvent;

public:		// User declarations
	__fastcall TfrmRFIDTestcase(TComponent* Owner);



};
//---------------------------------------------------------------------------
extern PACKAGE TfrmRFIDTestcase *frmRFIDTestcase;
//---------------------------------------------------------------------------
#endif
