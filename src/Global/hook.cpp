//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "hook.h"
#include "MainFormScrn.h"
#include "keyhook.h"	//dll
#include <cassert>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrmHook *FrmHook;


#pragma comment(lib, "keyhooklib.lib")

//---------------------------------------------------------------------------
__fastcall TFrmHook::TFrmHook(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFrmHook::FormCreate(TObject *Sender)
{
	LRESULT lRes = InstallKeyHook(); // Install the hook
    assert(lRes == KH_OK);

    this->registerPasswordWindow();

}
//---------------------------------------------------------------------------
void __fastcall TFrmHook::FormDestroy(TObject *Sender)
{
	UninstallKeyHook(); // Uninstall the hook to cleanup.
}
//---------------------------------------------------------------------------


BOOL TFrmHook::registerPasswordWindow()
{
    // Prepare the KEYENTRY struct
    KEYENTRY ke;

    ke.nMessage = WM_PASSWORD_WINDOW; // Our message ID
    ke.hCallWnd = MainForm->Handle; // Send message to this window
    ke.hHookWnd = 0; // Capture key-strokes occurred in any windows
    ke.iCombKeys = KH_ALT_PRESSED | KH_CTRL_PRESSED; // Combination key states
    ke.iIndicators = 0; // Caps-lock, Num-lock,
                       // Scroll-lock on/off states do not matter
    ke.iKeyEvent = 
      KH_KEY_DOWN | KH_KEY_REPEAT; // Capture key-down and key-repeat events
    ke.iMinVKCode = 'P'; // Capture all keys regardless of their virtual key codes
    ke.iMaxVKCode = 'P';

    // Add the entry to the hook
    LRESULT lRes = AddKeyEntry(&ke);
	assert(lRes == KH_OK);
	return true;
}
//---------------------------------------------------------------------------

