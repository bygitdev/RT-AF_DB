#include <vcl.h>
#pragma hdrstop

#include "WarningScrn.h"
#include <inifiles.hpp>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrmWarning *FrmWarning;
//---------------------------------------------------------------------------
__fastcall TFrmWarning::TFrmWarning(TComponent* Owner)
	: TForm(Owner)
{

    HWND hwnd = this->Handle; //다이얼로그의 핸들 얻음. 
    SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_EXSTYLE) | 524288);
    ::SetLayeredWindowAttributes(hwnd, 0, (255 * 60) / 100, 2);

}
//---------------------------------------------------------------------------
void __fastcall TFrmWarning::FormDblClick(TObject *Sender)
{
	this->Close();	
}
//---------------------------------------------------------------------------
void __fastcall TFrmWarning::FormShow(TObject *Sender)
{
    String strWarnFile = ExtractFilePath(Application->ExeName) + "ini\\warning.ini";
	if (FALSE == FileExists(strWarnFile))
		return;

	TIniFile* p = new TIniFile(strWarnFile);
    Memo1->Clear();
    Memo1->Lines->Add( p->ReadString("WARNING", "TEXT", NULL) );
    delete p;

}
//---------------------------------------------------------------------------


void __fastcall TFrmWarning::FormClose(TObject *Sender, TCloseAction &Action)
{
    String strWarnFile = ExtractFilePath(Application->ExeName) + "ini\\warning.ini";

	TIniFile* p = new TIniFile(strWarnFile);
    p->WriteString("WARNING", "TEXT", Memo1->Lines->Text);  
    delete p;

}
//---------------------------------------------------------------------------

