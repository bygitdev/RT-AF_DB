//---------------------------------------------------------------------------

#ifndef CommonDataSettingH
#define CommonDataSettingH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------

/*
�����Ķ���� ���� ����
- ������ �� ������ ���������� ������ ������ ��� ����
- ������ �����, �����Ķ���ʹ� ���� �������� �о ����, ������ �Ķ���ʹ� ������ �������� ����.
*/

class TFrmCommonSet : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *StringGridAxis;
	TStringGrid *StringGridPosition;
	TPanel *Panel1;
	TPanel *Panel2;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall StringGridAxisSelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall StringGridPositionDblClick(TObject *Sender);
	void __fastcall StringGridPositionDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);

private:	// User declarations
	void	select_axis(int index);

public:		// User declarations
	__fastcall TFrmCommonSet(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TFrmCommonSet *FrmCommonSet;
//---------------------------------------------------------------------------
#endif
