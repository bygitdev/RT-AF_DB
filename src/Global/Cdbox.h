//---------------------------------------------------------------------------

#ifndef CdboxH
#define CdboxH
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
	CD_YES		= 0x0001,
    CD_YESNO	= 0x0010,
    CD_OK		= 0x0100,
    CD_OKCANCEL	= 0x1000,

}CD_FLAG;

typedef enum
{
	CD_NOTICE	= 0,
	CD_WARNING	,
	CD_ERROR	,
	CD_SUCCESS	,
	CD_ASK		,
}CD_TYPE;

class TFrmCdBox : public TForm
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
	CD_TYPE	_cdType;

public:
	void	setTitle(String strTitle);
    void	setText(String strText);
	void	setFlag(DWORD dwFlag);
	void	setType(CD_TYPE iType = CD_NOTICE);
	bool 	QueryMsg(bool isAlpha = true);
	bool    QueryMsg(String Title, String Msg, CD_FLAG dwFlag);
	bool 	QueryMsg2(String Title, String Msg, CD_FLAG dwFlag,CD_TYPE type = CD_NOTICE,bool isAlpha = true);
	void    setFlagCaption(CD_FLAG dwFlag);

public:		// User declarations
	__fastcall TFrmCdBox(TComponent* Owner);


};
//---------------------------------------------------------------------------
extern PACKAGE TFrmCdBox *FrmCdBox;
//---------------------------------------------------------------------------
#endif
