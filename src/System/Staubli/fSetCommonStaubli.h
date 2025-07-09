//---------------------------------------------------------------------------

#ifndef fSetCommonStaubliH
#define fSetCommonStaubliH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <inifiles.hpp>
//---------------------------------------------------------------------------

/*
공통파라메터 개념 정리
- 데이터 값 저장은 공통폴더와 레시피 폴더에 모두 저장
- 레시피 변경시, 공통파라메터는 공통 폴더에서 읽어서 써줌, 레시피 파라메터는 레시피 폴더에서 읽음.
*/

class TfrmSetCommonStaubli : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *sgIndex;
	TPanel *Panel2;
	void __fastcall sgIndexDblClick(TObject *Sender);
	void __fastcall sgIndexDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);

private:	// User declarations
    TIniFile* _nameIni;
	void regen();

public:		// User declarations
	__fastcall TfrmSetCommonStaubli(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TfrmSetCommonStaubli *frmSetCommonStaubli;
//---------------------------------------------------------------------------
#endif
