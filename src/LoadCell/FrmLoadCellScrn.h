//---------------------------------------------------------------------------

#ifndef FrmLoadCellScrnH
#define FrmLoadCellScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "CPort.hpp"
#include <Vcl.ExtCtrls.hpp>
#include "CPort.hpp"
//---------------------------------------------------------------------------
class TFrmLoadCell : public TForm
{
__published:	// IDE-managed Components
	TMemo *MemoLoadCelllog;
	TComPort *LoadCellPort;
	TButton *BtnLoadCellRead;
	TButton *BtnLoadCellConnect;
	TPanel *PanelDisplay;
	TButton *btnZeroSet;
	void __fastcall BtnLoadCellConnectClick(TObject *Sender);
	void __fastcall BtnLoadCellReadClick(TObject *Sender);
	void __fastcall LoadCellPortRxChar(TObject *Sender, int Count);
	void __fastcall PanelDisplayDblClick(TObject *Sender);
	void __fastcall btnZeroSetClick(TObject *Sender);
private:	// User declarations
	String StrReceiveMessage;

	void  CommHistoryData(String StrTemp);
	void  LoadCellDataParse(String strData);
public:		// User declarations
	bool	_bCmdType, _bLoadComp;

	bool FrmConnectInitialize();
	bool ReadLoadCellCommand();
	bool ZeroCellCommand();
	bool isConnected();
	__fastcall TFrmLoadCell(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmLoadCell *FrmLoadCell;
//---------------------------------------------------------------------------
#endif
