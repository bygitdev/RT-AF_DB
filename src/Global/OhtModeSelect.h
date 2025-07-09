//---------------------------------------------------------------------------

#ifndef OhtModeSelectH
#define OhtModeSelectH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
#include "AdvGlowButton.hpp"
//---------------------------------------------------------------------------

typedef enum
{
	CD_ALWAYS_WAIT	= 0x0001,
	CD_YIELD_CHECK	= 0x0010,
}CD_TYPE2;

class TFrmOhtModeSelect : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TLabel *LabelTitle;
    TRichEdit *MemoText;
    TAdvGlowButton *BtnMain1;
    TAdvGlowButton *BtnMain2;
	void __fastcall FormShow(TObject *Sender);
    void __fastcall BtnMain1Click(TObject *Sender);
    void __fastcall BtnMain2Click(TObject *Sender);
private:	// User declarations
	DWORD	_dwFlag;

public:
	void	setTitle(String strTitle);
    void	setText(String strText);
	void	setFlag(DWORD dwFlag);
	void    setFlagCaption(CD_TYPE2 dwFlag);

public:		// User declarations
	__fastcall TFrmOhtModeSelect(TComponent* Owner);


};
//---------------------------------------------------------------------------
extern PACKAGE TFrmOhtModeSelect *FrmOhtModeSelect;
//---------------------------------------------------------------------------
#endif
