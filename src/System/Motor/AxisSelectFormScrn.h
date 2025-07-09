//---------------------------------------------------------------------------

#ifndef AxisSelectFormScrnH
#define AxisSelectFormScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TAxisSelectForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TBitBtn *BtnAxis1;
	TBitBtn *BtnAxis0;
	TBitBtn *BtnAxis2;
	TBitBtn *BtnAxis3;
	TBitBtn *BtnAxis4;
	TBitBtn *BtnAxis5;
	TBitBtn *BtnAxis15;
	TBitBtn *BtnAxis6;
	TBitBtn *BtnAxis7;
	TBitBtn *BtnAxis8;
	TBitBtn *BtnAxis9;
	TBitBtn *BtnAxis10;
	TBitBtn *BtnAxis14;
	TBitBtn *BtnAxis13;
	TBitBtn *BtnAxis12;
	TBitBtn *BtnAxis11;
	TBitBtn *BtnAxis16;
	TBitBtn *BtnAxis31;
	TBitBtn *BtnAxis17;
	TBitBtn *BtnAxis18;
	TBitBtn *BtnAxis19;
	TBitBtn *BtnAxis20;
	TBitBtn *BtnAxis21;
	TBitBtn *BtnAxis22;
	TBitBtn *BtnAxis23;
	TBitBtn *BtnAxis24;
	TBitBtn *BtnAxis25;
	TBitBtn *BtnAxis26;
	TBitBtn *BtnAxis27;
	TBitBtn *BtnAxis28;
	TBitBtn *BtnAxis29;
	TBitBtn *BtnAxis30;
	TBitBtn *BtnAxis32;
	TBitBtn *BtnAxis47;
	TBitBtn *BtnAxis33;
	TBitBtn *BtnAxis34;
	TBitBtn *BtnAxis36;
	TBitBtn *BtnAxis37;
	TBitBtn *BtnAxis38;
	TBitBtn *BtnAxis39;
	TBitBtn *BtnAxis40;
	TBitBtn *BtnAxis41;
	TBitBtn *BtnAxis42;
	TBitBtn *BtnAxis43;
	TBitBtn *BtnAxis44;
	TBitBtn *BtnAxis45;
	TBitBtn *BtnAxis46;
	TBitBtn *BtnAxis48;
	TBitBtn *BtnAxis63;
	TBitBtn *BtnAxis49;
	TBitBtn *BtnAxis50;
	TBitBtn *BtnAxis51;
	TBitBtn *BtnAxis52;
	TBitBtn *BtnAxis53;
	TBitBtn *BtnAxis54;
	TBitBtn *BtnAxis55;
	TBitBtn *BtnAxis56;
	TBitBtn *BtnAxis57;
	TBitBtn *BtnAxis58;
	TBitBtn *BtnAxis59;
	TBitBtn *BtnAxis60;
	TBitBtn *BtnAxis61;
	TBitBtn *BtnAxis62;
	TBitBtn *BtnAxis35;
	TPanel *PanelSelectAxis;
	TBitBtn *AxisSelectClose;
	TCheckBox *CheckBoxSelectGo;
	void __fastcall AxisSelectCloseClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall BtnAxis0Click(TObject *Sender);

private:	// User declarations


	Graphics::TBitmap*		_pBitmapCommon;
	Graphics::TBitmap*		_pBitmapUnique;
    TForm* m_pMtrAxisForm;

    int _nAttemptAxis;
	void  MtrAxisName_ReadName(int nAxis);
public:		// User declarations

	void AxisSelect_Initialize( TForm* pParent);

	__fastcall TAxisSelectForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAxisSelectForm *AxisSelectForm;
//---------------------------------------------------------------------------
#endif
