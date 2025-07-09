//---------------------------------------------------------------------------

#ifndef testcaseH
#define testcaseH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------


#include <kamelasimpl.h>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>


class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TGroupBox *GroupBox1;
	TEdit *EditNameS;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *EditSizeS;
	TButton *Button1;
	TComboBox *ComboBoxManager;
	TTimer *Timer1;
	TTabSheet *TabSheet3;
	TGroupBox *GroupBox2;
	TTrackBar *TrackBarSend;
	TLabel *Label3;
	TLabel *Label7;
	TTrackBar *TrackBarRecv;
	TPanel *Panel1;
	TPanel *Panel2;
	TSplitter *Splitter1;
	TMemo *MemoRecv;
	TPanel *Panel3;
	TMemo *MemoSend;
	TStatusBar *StatusBarRecv;
	TStatusBar *StatusBarSend;
	TCheckBox *CheckBoxRepeat;
	TButton *ButtonSend;
	TRadioButton *RadioButtonSharedMemoryServer;
	TRadioButton *RadioButtonSharedMemoryClient;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall ComboBoxManagerChange(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall ButtonSendClick(TObject *Sender);
	void __fastcall MemoSendKeyPress(TObject *Sender, char &Key);
private:	// User declarations

	KamelasManager 	_manager;
	KamelasBase*	_pCurrentBase;
    INT				_index;
    INT				_recvCount;
    INT				_sendCount;


public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
