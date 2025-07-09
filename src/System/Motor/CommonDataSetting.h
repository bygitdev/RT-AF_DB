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
공통파라메터 개념 정리
- 데이터 값 저장은 공통폴더와 레시피 폴더에 모두 저장
- 레시피 변경시, 공통파라메터는 공통 폴더에서 읽어서 써줌, 레시피 파라메터는 레시피 폴더에서 읽음.
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
