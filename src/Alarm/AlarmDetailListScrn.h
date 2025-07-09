//---------------------------------------------------------------------------

#ifndef AlarmDetailListScrnH
#define AlarmDetailListScrnH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <jpeg.hpp>
#include "CurvyControls.hpp"
#include <Vcl.Buttons.hpp>
#include "Shader.hpp"
#include <Vcl.ComCtrls.hpp>

//---------------------------------------------------------------------------
class TFrmAlarmDetailList : public TForm
{
__published:	// IDE-managed Components
	TCurvyPanel *CurvyPanel1;
	TTimer *Timer1;
	TShader *Shader1;
	TPageControl *DisplayPageControl;
	TTabSheet *TabSheet1;
	TCurvyEdit *DetailAlarmEdit;
	TStringGrid *AlarmDetailGrid;
	TCurvyEdit *CurvyEdit1;
	TMemo *MemoCause;
	TSpeedButton *BtnClose;
	TTabSheet *TabSheet2;
	TMemo *MemoWarnCause;
	TCurvyEdit *CurvyEdit2;
	TStringGrid *WarningDetailGrid;
	TCurvyEdit *DetailWarningEdit;
    void __fastcall BtnCloseClick(TObject *Sender);
    void __fastcall AlarmDetailGridSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
private:	// User declarations
        int  ErrorCode[10] , WarnCode[10];
		int  nDetailAlarmCode , nDetailWarningCode;

public:		// User declarations
    void __fastcall AlarmDetail_Initialize(bool bMode);
    __fastcall TFrmAlarmDetailList(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmAlarmDetailList *FrmAlarmDetailList;
//---------------------------------------------------------------------------
#endif
