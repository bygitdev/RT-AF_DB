//---------------------------------------------------------------------------

#ifndef fpadsetupH
#define fpadsetupH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TfrmPadSetup : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TLabel *Label9;
	TGroupBox *GroupBox1;
	TGroupBox *GroupBox2;
	TButton *BtnSavePadOffset;
	TEdit *EditPadOffsetX;
	TEdit *EditPadOffsetY;
	TButton *BtnInputPadOffset;
	TLabel *Label1;
	TLabel *Label2;
	TGroupBox *GroupBox3;
	TLabel *Label3;
	TLabel *Label4;
	TButton *BtnSaveFlipOffset;
	TEdit *EditTopOffsetX;
	TEdit *EditTopOffsetY;
	TButton *BtnInputFlipOffset;
	TGroupBox *GroupBox4;
	TLabel *Label5;
	TButton *BtnSavePadTheta;
	TEdit *EditPadTheta;
	TButton *BtnInputPadTheta;
	TLabel *Label6;
	TEdit *EditBtmOffsetX;
	TLabel *Label7;
	TEdit *EditBtmOffsetY;
	TTimer *Timer1;
	TButton *BtnSavePadType;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TRadioButton *RadioButton3;
	TButton *BtnInputPadType;
	TGroupBox *GroupBox5;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TButton *btnFilpUnitOffsetSave;
	TEdit *EditFilpUnitOffset1;
	TButton *btnFilpUnitOffsetInput;
	TEdit *EditFilpUnitOffset2;
	TEdit *EditFilpUnitOffset3;
	TBitBtn *btnFilpUnit_1;
	TBitBtn *btnFilpUnit_2;
	TBitBtn *btnFilpUnit_3;
	TBitBtn *btnFilpUnit_4;
	TRadioButton *RadioButton4;
	TLabel *lbl1;
	TEdit *EditFlipCount;
	TLabel *lbl2333;
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall BtnInputPadTypeClick(TObject *Sender);
	void __fastcall BtnInputPadThetaClick(TObject *Sender);
	void __fastcall BtnInputPadOffsetClick(TObject *Sender);
	void __fastcall BtnInputFlipOffsetClick(TObject *Sender);
	void __fastcall BtnSavePadTypeClick(TObject *Sender);
	void __fastcall BtnSavePadThetaClick(TObject *Sender);
	void __fastcall BtnSavePadOffsetClick(TObject *Sender);
	void __fastcall BtnSaveFlipOffsetClick(TObject *Sender);
	void __fastcall btnFilpUnitOffsetInputClick(TObject *Sender);
	void __fastcall btnFilpUnitOffsetSaveClick(TObject *Sender);
	void __fastcall btnFilpUnit_1Click(TObject *Sender);
private:	// User declarations
	int _nFilpUnitIndex;

	void  FilpOffsetDataRead(int nIndex);
	void  FilpOffsetDataSave(int nIndex);
public:		// User declarations
	__fastcall TfrmPadSetup(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmPadSetup *frmPadSetup;
//---------------------------------------------------------------------------
#endif
