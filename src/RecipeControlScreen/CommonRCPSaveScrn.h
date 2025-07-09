//---------------------------------------------------------------------------

#ifndef CommonRCPSaveScrnH
#define CommonRCPSaveScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TFrmCommonRcpSave : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TStringGrid *CommonRCPGrid;
	TPanel *PanelLotSelect;
	TLabel *LabelSeparator;
	TButton *CommonRCPCodeUp;
	TButton *CommonRCPCodeDown;
	TButton *BtnCommonRCPSave;
	TButton *BtnCommonRCPExit;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall BtnCommonRCPSaveClick(TObject *Sender);
	void __fastcall BtnCommonRCPExitClick(TObject *Sender);
	void __fastcall CommonRCPCodeUpClick(TObject *Sender);
	void __fastcall CommonRCPCodeDownClick(TObject *Sender);

private:	// User declarations
	void __fastcall SavePKGDataRoutine();

public:		// User declarations
	 void __fastcall FormInitialize();
	__fastcall TFrmCommonRcpSave(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmCommonRcpSave *FrmCommonRcpSave;
//---------------------------------------------------------------------------
#endif
