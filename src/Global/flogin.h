#ifndef fLoginH
#define fLoginH

#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <ImgList.hpp>
#include <Mask.hpp>
#include <StdCtrls.hpp>
#include <ToolWin.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Samples.Spin.hpp>
//---------------------------------------------------------------------------



/** TfrmLogin
 *
 *
 * description
 * �����ִ� ����ڰ� ���������� ���θ� �Ǻ��ϱ� ���� ���
 * Ư�� ������ �ʿ��� ��ɾտ��� ������ ��ȸ(getlevel)�Ͽ� ������
 * ��뿩�θ� �Ǵ��Ѵ�.
 *
 * usage
 *
 *
 * history
 * hcchoi@koses.co.kr
 * 2013.8.
 *
 */


typedef enum
{
	PW_OPERATOR		=0,
    PW_MAINTENANCE,
    PW_ENGINEER,
    PW_SUPER

}_LEVEL_;

class TfrmLogin : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TLabel *Label3;
	TLabel *Label1;
	TComboBox *cbLevel;
	TMaskEdit *mePassword;
	TButton *Button1;
	TShape *Shape1;
	TLabel *Label2;
	TLabel *Label4;
	TSplitter *Splitter1;
	TSpeedButton *SpeedButton1;
	TShape *Shape2;
	TBitBtn *btnChangePassword;
	TLabel *Label5;
	TLabel *Label6;
	TMaskEdit *meCurrentPassword;
	TMaskEdit *meNewPassword;
	TBitBtn *btnOk;
	TBitBtn *btnCancel;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall mePasswordKeyPress(TObject *Sender, char &Key);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall cbLevelChange(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall btnChangePasswordClick(TObject *Sender);
	void __fastcall btnCancelClick(TObject *Sender);
	void __fastcall btnOkClick(TObject *Sender);

private:	// User declarations

	INT					_count;
    _LEVEL_				_level;
    _LEVEL_				_leveltemp;
	String				_login[4];
    String				_user;
    bool				_isEnable;
    bool				_isExpired;
    INT					_expiredMins;
    TDateTime			_loggedin;
    bool				tryLogIn();
    void				ChangePasswordForm(bool enabled);

	bool				_keepPwd;

public:		// User declarations

	void	   			changeLevel(_LEVEL_ lv);
	void				setKeepPwd(bool nSet){_keepPwd=nSet;}
	bool				getKeepPwd(){return _keepPwd;}

	_LEVEL_    			getLevel();
    String				getStringLevel();
    void				enable(bool);
    bool				isEnable();
    bool				isExpired();
    INT					getLogOutPercentage();

    void				SetTryLevel(_LEVEL_ lv);
	__fastcall TfrmLogin(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmLogin *frmLogin;
//---------------------------------------------------------------------------
#endif
