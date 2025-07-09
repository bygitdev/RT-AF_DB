//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fgerber.h"
#include <inifiles.hpp>
#include <Winuser.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmRoute *frmRoute;
//---------------------------------------------------------------------------
__fastcall TfrmRoute::TfrmRoute(TComponent* Owner)
	: TForm(Owner)
{
	_EMR_HWND = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TfrmRoute::FormCreate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
void __fastcall TfrmRoute::FormShow(TObject *Sender)
{
	TIniFile* ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "Config.ini");

	AnsiString file = ini->ReadString("GERBER","FILE","");
	AnsiString drectory = ini->ReadString("GERBER","DIRECTORY","");
	_caption = ini->ReadString("GERBER","CAPTION","ePM-R 1.0.0 - Namkang Hi-Tech Co.,Ltd. - Untitled");

	delete ini;

	if(file == "" || drectory == "")
	{
		ShowMessage("Please setting config.ini file");
		return;
	}

	static bool first = true;

	if(first)
	{
		first = false;

		Panel1->Visible = true;
		Panel1->Caption = "Gerber program loading now..";

		SHELLEXECUTEINFOA ExVal;
		ExVal.cbSize = sizeof(SHELLEXECUTEINFO);
		ExVal.fMask = NULL;
		ExVal.hwnd = NULL;
		ExVal.lpVerb = NULL;
		ExVal.lpFile = file.c_str();
		ExVal.lpParameters = NULL;
		ExVal.lpDirectory = drectory.c_str();
		ExVal.nShow = SW_HIDE; //SW_NORMAL;
		ExVal.hInstApp = NULL;

		ShellExecuteExA(&ExVal);

		Timer1->Enabled = true;
	}


}
//---------------------------------------------------------------------------
void __fastcall TfrmRoute::Timer1Timer(TObject *Sender)
{
	static bool tic = false;

	if(_EMR_HWND == NULL)
	{
		_EMR_HWND =  FindWindowA(NULL,_caption.c_str());

		if(!tic)
		{
			Panel1->Caption = "Gerber program loading now..";
		}
		else
		{
			Panel1->Caption = "Please wait..";
		}
		tic = !tic;
	}
	else
	{
		::SetParent(_EMR_HWND, this->Handle);

		LONG lStyle = GetWindowLong(_EMR_HWND, GWL_STYLE);
		lStyle &= ~(WS_CAPTION | WS_THICKFRAME | WS_MINIMIZE | WS_MAXIMIZE | WS_SYSMENU);
		SetWindowLong(_EMR_HWND, GWL_STYLE, lStyle);

		ShowWindow(_EMR_HWND, SW_SHOWMAXIMIZED);

		Panel1->Caption = "Gerber program was closed abnoramly. Please restart mmi program.";

		Timer1->Enabled = false;
	}

}
//---------------------------------------------------------------------------
void	TfrmRoute::change_file(String filename)
{
	AnsiString ansiFilename(filename);

	POINT point = {500,500};

	int cbBuffer = sizeof(DROPFILES) + strlen(ansiFilename.c_str()) + 2;

	if(HGLOBAL hGlobal = GlobalAlloc(GHND | GMEM_SHARE | GMEM_ZEROINIT, cbBuffer))
	{
		DROPFILES* df = (DROPFILES*)GlobalLock(hGlobal);
		df->pFiles = sizeof(DROPFILES);
		df->pt = point;
		df->fNC = FALSE;
		df->fWide = FALSE;

		strcpy(reinterpret_cast<char*>(df+1),ansiFilename.c_str());

		GlobalUnlock(hGlobal);

		int result = SendMessage(_EMR_HWND, 0x49,(WPARAM)cbBuffer,(LPARAM)hGlobal);
		SendMessageW(_EMR_HWND, WM_DROPFILES, (WPARAM)result, 0);

		GlobalFree(hGlobal);
	}
}
//---------------------------------------------------------------------------
void	TfrmRoute::RecipeChange()
{
	this->change_file("c:\\stencil_btm.nrpf");
}
//---------------------------------------------------------------------------
