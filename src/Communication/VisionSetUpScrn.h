//---------------------------------------------------------------------------

#ifndef VisionSetUpScrnH
#define VisionSetUpScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <System.Win.ScktComp.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Graphics.hpp>
#include "CurvyControls.hpp"
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
#include <stdio.h>

class TFrmVisionSetUp : public TForm
{
__published:	// IDE-managed Components
	TCurvyPanel *CurvyPanel1;
	TLabel *Label1;
	TMemo *VisionMemo;
	TButton *BtnAlignVision1;
	TButton *BtnSaveLog;
	TCheckBox *ChkAlignVision1;
	TServerSocket *BtmAlignVisionServer;
	TServerSocket *SorterJobChangeVisionServer;
	TButton *BtnAlignVision2;
	TCheckBox *ChkAlignVision2;
	TButton *BtnPreQCVision;
	TCheckBox *ChkPreQCVision;
	TServerSocket *FlpAlignVisionServer;
	TServerSocket *PreQCSocket;
	TButton *BtnSorterJobChangeVision;
	TCheckBox *ChkSorterJobChangeVision;
	TBitBtn *BtnClose;
	TServerSocket *TraySocket;
	TButton *BtnTrayVision;
	TCheckBox *ChkTrayVision;
	TCurvyPanel *CurvyPanel2;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *EditXValue;
	TLabel *Label4;
	TEdit *EditYValue;
	TBitBtn *BtnExecuteMove;
	TPanel *Panel1;
	TRadioButton *RadioBtn1;
	TRadioButton *RadioBtn2;
	TRadioButton *RadioBtn3;
	TClientSocket *ReqRCClientSocket;
	TServerSocket *DVIServerSocket;
	TSpeedButton *btnTrayInfoSend;
	TServerSocket *QpdSorket;
	TButton *BtnPreQPDVision;
	TCheckBox *ChkPreQPDVision;
	TSpeedButton *Btn_QpdCmd;
	TCurvyPanel *CurvyPanel3;
	TLabel *Label5;
	TGroupBox *GroupBox1;
	TMemo *MemoLog;
	TGroupBox *GroupBox2;
	TRadioButton *Rdo_Del01;
	TRadioButton *Rdo_Del02;
	TRadioButton *Rdo_Del03;
	TRadioButton *Rdo_Del04;
	TRadioButton *Rdo_Del05;
	TBitBtn *Btn_OpenLogFolder;
	TClientSocket *BtmSendClientSocket;
	TBitBtn *Btn_vCutSave;
	TCurvyPanel *CurvyPanel4;
	TLabel *Label6;
	TGroupBox *GroupBox3;
	TLabel *Label7;
	TEdit *set_VisionID;
	TButton *Button1;
	TSpeedButton *Btn_VisionImageOn;
	TSpeedButton *Btn_VisionImageOff;
	TLabel *Label8;
	TEdit *read_VisionID;
	TSpeedButton *Read_btmVisionOption;
	TBitBtn *Set_btmVisionOption;
	TLabel *Label9;
	TEdit *read_Use;
	TEdit *read_Option;
	TLabel *Label10;
	TLabel *Label11;
	void __fastcall BtnAlignVision1Click(TObject *Sender);
	void __fastcall BtmAlignVisionServerClientConnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall BtmAlignVisionServerClientDisconnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall BtmAlignVisionServerClientError(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode);
	void __fastcall BtmAlignVisionServerClientRead(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall BtnAlignVision2Click(TObject *Sender);
	void __fastcall BtnPreQCVisionClick(TObject *Sender);
	void __fastcall FlpAlignVisionServerClientConnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall FlpAlignVisionServerClientDisconnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall FlpAlignVisionServerClientError(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode);
	void __fastcall FlpAlignVisionServerClientRead(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall PreQCSocketClientConnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall PreQCSocketClientDisconnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall PreQCSocketClientRead(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall PreQCSocketClientError(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode);
	void __fastcall BtnSorterJobChangeVisionClick(TObject *Sender);
	void __fastcall SorterJobChangeVisionServerClientConnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall SorterJobChangeVisionServerClientDisconnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall SorterJobChangeVisionServerClientError(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode);
	void __fastcall SorterJobChangeVisionServerClientRead(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall BtnCloseClick(TObject *Sender);
	void __fastcall VisionMemoChange(TObject *Sender);
	void __fastcall BtnTrayVisionClick(TObject *Sender);
	void __fastcall TraySocketClientConnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall TraySocketClientDisconnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall TraySocketClientError(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode);
	void __fastcall TraySocketClientRead(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall BtnExecuteMoveClick(TObject *Sender);
	void __fastcall Label1Click(TObject *Sender);
	void __fastcall DVIServerSocketClientConnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall DVIServerSocketClientDisconnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall DVIServerSocketClientError(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode);
	void __fastcall DVIServerSocketClientRead(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall ReqRCClientSocketConnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall ReqRCClientSocketError(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode);
	void __fastcall btnTrayInfoSendClick(TObject *Sender);
	void __fastcall QpdSorketClientConnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall QpdSorketClientDisconnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall QpdSorketClientError(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode);
	void __fastcall QpdSorketClientRead(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall BtnPreQPDVisionClick(TObject *Sender);
	void __fastcall Btn_OpenLogFolderClick(TObject *Sender);
	void __fastcall Btn_vCutSaveClick(TObject *Sender);
	void __fastcall Btn_QpdCmdClick(TObject *Sender);
	void __fastcall Btn_VisionImageOnClick(TObject *Sender);
	void __fastcall Btn_VisionImageOffClick(TObject *Sender);
	void __fastcall BtmSendClientSocketConnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall BtmSendClientSocketError(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall BtmSendClientSocketRead(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall Set_btmVisionOptionClick(TObject *Sender);
	void __fastcall Read_btmVisionOptionClick(TObject *Sender);









private:	// User declarations
	AnsiString StrRecvBTMBuffer;
    AnsiString StrRecvTOPBuffer;
    AnsiString StrQCRecvBuffer;
    AnsiString StrTrayRecvBuffer;

	AnsiString StrQPDRecvBuffer;
	AnsiString StrDLRecvBuffer;

	TCustomWinSocket *m_AlignSocket1;
	TCustomWinSocket *m_AlignSocket2;

    TCustomWinSocket *m_PreQCSocket;
	TCustomWinSocket *m_SorterJobSocket;
	TCustomWinSocket *m_TraySocket;

	TCustomWinSocket *m_QpdSocket;

	FILE*  _fp;
	FILE*  _fpl;
	String _currentLogFileName;
	String _currentLogFileNameBtm;

	void  TOPVisionTransferControl();
	void  BottomVisionTransferControl();

	void  QCVisionRecvControl();
	void  QPDVisionRecvControl();

	void  VisionHistoryData(int VisionSeparator,String StrTemp);
	void  VisionTransferComplete(int nIdentifier);

    bool  ExecuteVisionMoveSend(int nVisionIndex , String StrX , String StrY);
    int   VisionCommandJudgement(AnsiString StrRecvBuffer);
    void  MoveVisionControl(int nCamIndex , AnsiString StrBuffer);

    void  	send_dvi(TCustomWinSocket *Socket);
	void	send_job();
	void	send_trayinfo();

public:		// User declarations
	bool bChkRCPchk;

	bool  JobChangeVisionConversion(AnsiString RightSendtext);
	void  JobChangeVCutVision(AnsiString RightSendtext);
	bool  LotInfoSendToVision(AnsiString strLotID, AnsiString strBarcodeID, AnsiString strPARTID);
	bool  TrayVisiontTextSend(AnsiString StrID);
	void  VisionClosingProcess();
	void  StartVisionChkSwitch();
	bool  TrayInfo(AnsiString partID, AnsiString trayMark);
	void __fastcall RemoveTree(String stDirectory);
	void  vCutProcessStateChange(String sType);
	void  vCutFileDelete();

	BOOL send_btminfo(WideString data);

	__fastcall TFrmVisionSetUp(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmVisionSetUp *FrmVisionSetUp;
//---------------------------------------------------------------------------
#endif
