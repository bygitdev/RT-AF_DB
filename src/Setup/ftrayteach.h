//---------------------------------------------------------------------------

#ifndef ftrayteachH
#define ftrayteachH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include "CurvyControls.hpp"
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmTrayTeach: public TForm
{
__published:	// IDE-managed Components
	TPageControl *TrayTeachPageCtrl;
	TTabSheet *TabSheet2;
	TCurvyPanel *CurvyPanel28;
	TCurvyPanel *CurvyPanel29;
	TPanel *Panel39;
	TEdit *TrayOffsetEdit0;
	TEdit *TrayOffsetEdit1;
	TLabel *LabelTrayShiftOffsetY;
	TLabel *LabelTrayShiftOffsetX;
	TEdit *TrayShrinkOffsetEdit1;
	TEdit *TrayShrinkOffsetEdit0;
	TLabel *LabelTrayXShrinkOffsetX;
	TLabel *LabelTrayXShrinkOffsetY;
	TEdit *TrayShrinkOffsetEdit3;
	TEdit *TrayShrinkOffsetEdit2;
	TLabel *LabelTrayYShrinkOffsetX;
	TLabel *LabelTrayYShrinkOffsetY;
	TCurvyPanel *CurvyPanel30;
	TCurvyPanel *CurvyPanel32;
	TLabel *Label28;
	TLabel *Label29;
	TEdit *EditPP2;
	TEdit *EditPP1;
	TBitBtn *BtnTCUnitSave;
	TEdit *EditTC2;
	TEdit *EditTC1;
	TLabel *Label31;
	TLabel *Label32;
	TBitBtn *BtnUCDistanceSave;
	TShape *Shape27;
	TCurvyPanel *CurvyPanel33;
	TBitBtn *BtnDataSave;
	TBitBtn *btnAllTrayDataSave;
	TShape *Shape28;
	TLabel *Label36;
	TLabel *Label37;
	TEdit *EditMaxTrayTotalWeight_1;
	TEdit *EditMaxTrayStackCount_1;
	TBitBtn *btnTrayInfoSave_Jig;
	TCurvyPanel *CurvyPanel31;
	TShape *Shape29;
	TLabel *Label24;
	TLabel *Label25;
	TLabel *Label26;
	TLabel *Label27;
	TLabel *Label33;
	TShape *Shape30;
	TShape *Shape31;
	TShape *Shape32;
	TShape *Shape33;
	TShape *Shape34;
	TShape *Shape35;
	TShape *Shape36;
	TShape *Shape37;
	TShape *Shape38;
	TShape *Shape39;
	TLabel *Label34;
	TShape *Shape40;
	TShape *Shape41;
	TLabel *Label35;
	TCurvyPanel *CurvyPanel35;
	TShape *Shape42;
	TShape *Shape43;
	TShape *Shape44;
	TLabel *Label38;
	TCurvyPanel *CurvyPanel36;
	TCurvyPanel *CurvyPanel37;
	TCurvyPanel *CurvyPanel38;
	TEdit *EditTrayXCnt;
	TCurvyPanel *CurvyPanel39;
	TCurvyPanel *CurvyPanel40;
	TCurvyPanel *CurvyPanel41;
	TCurvyPanel *CurvyPanel42;
	TCurvyPanel *CurvyPanel43;
	TCurvyPanel *CurvyPanel44;
	TCurvyPanel *CurvyPanel45;
	TCurvyPanel *CurvyPanel46;
	TCurvyPanel *CurvyPanel47;
	TCurvyPanel *CurvyPanel48;
	TCurvyPanel *CurvyPanel49;
	TEdit *EditTrayYCnt;
	TEdit *EditTrayXPitch;
	TEdit *EditTrayYPitch;
	TEdit *Edit5;
	TEdit *Edit6;
	TPanel *Panel40;
	TPanel *Panel41;
	TBitBtn *BitBtn3;
	TCurvyPanel *CurvyPanel50;
	TSpeedButton *SpeedButton12;
	TSpeedButton *SpeedButton13;
	TEdit *EditVisionThreshold;
	TSpeedButton *SpeedButton14;
	TShape *Shape45;
	TShape *Shape46;
	TImage *Image2;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TEdit *TrayOffsetEdit2;
	TEdit *TrayOffsetEdit3;
	TEdit *TrayShrinkOffsetEdit5;
	TEdit *TrayShrinkOffsetEdit4;
	TEdit *TrayShrinkOffsetEdit7;
	TEdit *TrayShrinkOffsetEdit6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TEdit *TrayOffsetEdit4;
	TEdit *TrayOffsetEdit5;
	TEdit *TrayShrinkOffsetEdit9;
	TEdit *TrayShrinkOffsetEdit8;
	TEdit *TrayShrinkOffsetEdit11;
	TEdit *TrayShrinkOffsetEdit10;
	TShape *Shape1;
	TShape *Shape2;
	TPanel *Panel1;
	TPanel *Panel2;
	TShape *Shape3;
	TPanel *Panel3;
	TPanel *Panel4;
	TShape *Shape4;
	TBitBtn *BitBtn5;
	TLabel *Label13;
	TBitBtn *BtnTeachBtn5;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	TShape *Shape5;
	TLabel *Label14;
	TEdit *EditGP1;
	TEdit *EditGP2;
	TLabel *Label15;
	TLabel *Label16;
	TLabel *Label17;
	TEdit *EditUC1;
	TEdit *EditUC2;
	TBitBtn *BtnUnitCenterInput;
	TBitBtn *BtnUnitCenterSave;
	TTimer *Timer1;
	TBitBtn *BtnDataInput;
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall BtnDataSaveClick(TObject *Sender);
	void __fastcall BtnTCUnitSaveClick(TObject *Sender);
	void __fastcall BtnUCDistanceSaveClick(TObject *Sender);
	void __fastcall FormPaint(TObject *Sender);
	void __fastcall btnAllTrayDataSaveClick(TObject *Sender);
	void __fastcall SpeedButton14Click(TObject *Sender);
	void __fastcall btnTrayInfoSave_JigClick(TObject *Sender);
	void __fastcall BitBtn5Click(TObject *Sender);
	void __fastcall BtnTeachBtn5Click(TObject *Sender);
	void __fastcall BtnUnitCenterInputClick(TObject *Sender);
	void __fastcall BtnUnitCenterSaveClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall BtnDataInputClick(TObject *Sender);

private:	// User declarations
	void	regen();

	void TraySelectRead();

	void trayInfoDataRead();
	void trayInfoDataSave();

	void trayPKGDataRead();

	void TrayOffsetSelectSave();
	void AllTrayOffsetSave();

public:		// User declarations
	void  GerberCenterDataRead();
	void  TrayPickupDataRead();
	void  TrayCenter1stDataSave();

	void  TrayCenter1stDataRead();

	__fastcall TfrmTrayTeach(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmTrayTeach* frmTrayTeach;
//---------------------------------------------------------------------------
#endif
