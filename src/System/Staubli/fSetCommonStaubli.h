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
�����Ķ���� ���� ����
- ������ �� ������ ���������� ������ ������ ��� ����
- ������ �����, �����Ķ���ʹ� ���� �������� �о ����, ������ �Ķ���ʹ� ������ �������� ����.
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
