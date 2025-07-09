//---------------------------------------------------------------------------

#ifndef fshowdataH
#define fshowdataH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
#include <inifiles.hpp>

#include "BaseComm.h"
#include <Vcl.ValEdit.hpp>
#define 	MAX_PATHDATA_CNT	100

class TFrmShowData : public TForm
{
__published:	// IDE-managed Components
	TGridPanel *GridPanel1;
	TPanel *Panel1;
	TPanel *Panel2;
	TGridPanel *GridPanel2;
	TPanel *Panel3;
	TPanel *Panel4;
	TPanel *Panel5;
	TGridPanel *GridPanel3;
	TPanel *Panel7;
	TPanel *Panel8;
	TBitBtn *ButtonInput;
	TBitBtn *ButtonSave;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TTabSheet *TabSheet3;
	TTabSheet *TabSheet4;
	TTabSheet *TabSheet5;
	TStringGrid *StringGrid_offset4;
	TStringGrid *StringGrid_path;
	TStringGrid *StringGrid_offset3;
	TStringGrid *StringGrid_offset1;
	TStringGrid *StringGrid_offset2;
	TValueListEditor *ValueListEditorPkg;
	TGridPanel *GridPanel4;
	TPanel *Panel6;
	TPanel *Panel9;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	TEdit *EditIndex;
	TPanel *PanelPos;
	TBitBtn *ButtonReload;
	TPanel *Panel10;
	TPanel *Panel11;
	TGridPanel *GridPanelStageIndex;
	TPanel *PanelIndex1;
	TPanel *PanelIndex2;
	TPanel *PanelIndex3;
	TPanel *PanelIndex4;
	TStatusBar *StatusBar1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall StringGridSelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall ButtonInputClick(TObject *Sender);
	void __fastcall ButtonSaveClick(TObject *Sender);
	void __fastcall PanelIndexClick(TObject *Sender);
	void __fastcall ButtonIndexMoveClick(TObject *Sender);
	void __fastcall PageControl1Change(TObject *Sender);
	void __fastcall ButtonReloadClick(TObject *Sender);

private:	// User declarations
	void	read_pkg_data_ini();
	void	read_origin_path_data_ini();
	void	read_offset_data_ini();

	void	save_offset_data_ini();
	void	save_exportData_ini();

	void	read_from_seq();

	void	write_pkg_data_seq();
	void	write_offset_data_seq();
	void	write_origin_path_data_seq();

	void	select_index_for_move(int index);

	void	print_statusbar(String text);


public:		// User declarations
	__fastcall TFrmShowData(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmShowData *FrmShowData;
//---------------------------------------------------------------------------
#endif
