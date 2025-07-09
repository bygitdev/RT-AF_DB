//---------------------------------------------------------------------------

#ifndef fQCResultH
#define fQCResultH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "CurvyControls.hpp"
#include <System.Win.ScktComp.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TfrmQCResult : public TForm
{
__published:	// IDE-managed Components
	TCurvyPanel *CurvyPanel1;
	TBitBtn *btnOk;
	TCurvyEdit *ceLotID;
	TStringGrid *StringGridSubstrate;
	TLabel *Label1;
	TLabel *Label2;
	TCurvyEdit *CurvyEdit1;
	TCurvyEdit *CurvyEdit2;
	TBitBtn *btnRetry;
	TCurvyEdit *ceIndex;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall StringGridSubstrateDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
	void __fastcall StringGridSubstrateSelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect);
	void __fastcall btnOkClick(TObject *Sender);
	void __fastcall btnRetryClick(TObject *Sender);
private:	// User declarations
	int	_index;
    //int _status[20][20];
    int	_nRowYCnt;
	int _nColXCnt;
    int _qcResult[20]; 	//0 (good)
    void __fastcall SetGridPanels(int stageIndex);

public:		// User declarations
	__fastcall TfrmQCResult (TComponent* Owner);
    void	setStageIndex(int index);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmQCResult *frmQCResult ;
//---------------------------------------------------------------------------
#endif
