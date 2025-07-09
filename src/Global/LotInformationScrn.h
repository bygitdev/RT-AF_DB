//---------------------------------------------------------------------------

#ifndef LotInformationScrnH
#define LotInformationScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "AdvPicture.hpp"
#include "CurvyControls.hpp"
#include <Vcl.ExtCtrls.hpp>
#include "Shader.hpp"
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TFrmLotInformation : public TForm
{
__published:	// IDE-managed Components
	TCurvyPanel *CurvyPanel1;
	TLabel *Label1;
	TLabel *Label2;
	TCurvyEdit *CurvyEditLotnumber;
	TCurvyEdit *CurvyEditOPid;
	TPanel *PanelCountStop;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TCurvyEdit *CurvyEdit2;
	TCurvyEdit *CurvyEdit3;
	TCurvyEdit *CurvyEdit1;
	TLabel *Label6;
	TCurvyPanel *CurvyPanel2;
	TShader *MainTopPanel;
	TLabel *Label7;
	TSpeedButton *BtnClose;
	TSpeedButton *BtnLotsuspend;
	TSpeedButton *BtnLotStart;
	TRadioButton *LMDRadioButtonOption2;
	TRadioButton *LMDRadioButtonOption1;
	TCheckBox *LMDCheckBoxCountStop;
	TSpeedButton *BtnSaveMotionData;
	void __fastcall BtnLotStartClick(TObject *Sender);
	void __fastcall LMDCheckBoxCountStopChange(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall BtnCloseClick(TObject *Sender);
private:	// User declarations

public:		// User declarations
		String __fastcall LotInfoReturnQuery(int nType);
	__fastcall TFrmLotInformation(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmLotInformation *FrmLotInformation;
//---------------------------------------------------------------------------
#endif
