//---------------------------------------------------------------------------

#ifndef fPopupNoticeH
#define fPopupNoticeH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <vector>
using namespace std;

//---------------------------------------------------------------------------

class TfrmPopupNotice : public TForm
{
__published:	// IDE-managed Components
	TTimer *tmrFlicker;
	TPanel *Panel3;
	TPanel *Panel2;
	TPanel *Panel1;
	TLabel *Label1;
	TButton *btnButton;
	TGridPanel *GridPanel1;
	TButton *Btn1;
	TButton *Btn2;
	TButton *Btn3;
	TButton *Btn4;
	TPanel *Panel4;
	TLabel *lbText;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Btn1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall btnButtonClick(TObject *Sender);
	void __fastcall tmrFlickerTimer(TObject *Sender);
	void __fastcall Panel1Click(TObject *Sender);
private:	// User declarations
	//twilight::hydra::HYDRA_CMD	_type;
	int			_comp_index;
	bool _btnClick;
	static bool	_showing_popup;
	int		m_eastEgg;

public:
	void	setTitle(String strTitle);
	void	setText(String strText);
	void 	setButton(String _Btn_Text1,String _Btn_Text2,String _Btn_Text3,String _Btn_Text4);
//	void 	setCompSignal(twilight::hydra::HYDRA_CMD type, int index);
	bool	isShowing();
public:		// User declarations
	__fastcall TfrmPopupNotice(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmPopupNotice *frmPopupNotice;
//---------------------------------------------------------------------------
#endif
