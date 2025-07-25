////---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "MainFormScrn.h"
#define _MAIN_CPP_
#include "include.h"

#include "fPopupNotice.h"
#include "SetupFormScrn.h"
#include "CalibrationFormScrn.h"
#include "SystemFormScrn.h"
#include "FrmAlarmScrn.h"
#include "FrmUseSkipScrn.h"
#include "FrmUserParameterScrn.h"
#include "RecipeFormScrn.h"
#include "RecipeChangeFormScrn.h"
#include "FormMainStatusScrn.h"
#include "FrmARFlowScrn.h"
#include "FormHistoryScrn.h"
#include "AlarmDetailListScrn.h"
#include "ConfigSetFormScrn.h"
#include "FormManualCuttingScrn.h"
#include "fOperatorID.h"
#include "fProgramHistory.h"
#include "ftrayteach.h"

//#include "FrmDailyReportScrn.h"
#include "fdailyreport.h"
#include "rfid\frfid.h"
#include "FrmLotCommScrn.h"
#include "tccomm\ftccomm.h"
#include "barcode\fbarcode.h"
//---------------------------------------------------------------------------
#include "FormSecsGemSetScrn.h"
#include "VisionSetUpScrn.h"
#include "FormPMSControlScrn.h"
#include "FrmStaubliControlScrn.h"
#include "FrmRouterCommScrn.h"
//---------------------------------------------------------------------------
#include "GrayFormCDBoxScrn.h"
#include "fLogin.h"
#include "falarmlist.h"

#include "FrmLoadCellScrn.h"
//---------------------------------------------------------------------------
#include "BaseComm.h"
#include "SQLite\CppSQLite3.h"
#include "mainstatus\arflowscreen\fqcresult.h"
#include "mainstatus\arflowscreen\fseelot.h"
#include "fpopmenu.h"
#include "WarningScrn.h"
#include "WarningPopupScrn.h"
#include "fLotEventHistory.h"
#include "OhtModeSelect.h"
#include "FrmPadChangeHistory.h"
#include "FrmAutoFBHistory.h"
//---------------------------------------------------------------------------
#include "FrmTeachMainScrn.h"
//---------------------------------------------------------------------------
#include <iostream.h>

#pragma package(smart_init)
#pragma link "iComponent"
#pragma link "iCustomComponent"
#pragma link "iLedMatrix"
#pragma link "iVCLComponent"
#pragma resource "*.dfm"

#define   _PRE_QC_VISION_        		0
#define   _ALIGN_VISION1_               1
#define   _ALIGN_VISION2_               2
#define   _TRAY_VISION_                 3
#define   _DVI_							4
#define   _QPD_QC_VISION_        		5
#define   _SORTER_JOB_CHANGE_VISION_    6

TMainForm *MainForm;

C_Communication *g_MMIComm;

CppSQLite3DB SQLiteRunDB;
CppSQLite3DB SQLiteRunHistoryDB;
CppSQLite3DB SQLiteLotInfoDB;
CppSQLite3DB SQLiteAlarmDB;
CppSQLite3DB SQLiteRejectDB;

Barcode		*g_barcode[1] = {NULL, };
RFID		*g_rfid = NULL;

enum MAINSUBFORM
{
	MSUB_SETUP					= 1,
	MSUB_CALIBRATION            = 2,
	MSUB_SYSTEM                 = 3,
	MSUB_RECIPE					= 4,
	MSUB_ALARM					= 5,
	MSUB_HISTORY    			= 6,

	MSUB_MAXCOUNT               = 7,
};

enum FUNCTIONBUTTON
{
	FUNCTION_BTN1				= 0,
	FUNCTION_BTN2				= 1,
	FUNCTION_BTN3				= 2,
	FUNCTION_BTN4				= 3,
	FUNCTION_BTN5               = 4,
	FUNCTION_BTN6				= 5,
	FUNCTION_BTN7				= 6,
	FUNCTION_BTN8				= 7,
	FUNCTION_BTN9				= 8,
	FUNCTION_BTN10              = 9,
	FUNCTION_BTN11				= 10,
	FUNCTION_BTN12				= 11,
	FUNCTION_BTN13				= 12,
};



enum RUNFACTOR
{
	FACTOR_TIME    		=0,
	FACTOR_RUNCODE    	=1,
	FACTOR_DURATION    	=2,
	FACTOR_RECIPE1    	=3,
	FACTOR_RECIPE2   	=4,
	FACTOR_ALARMCODE    =5,
	FACTOR_ALARMTYPE   	=6,
};

//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{

	_dbStoptime  = 0.;
	_dbRuntime  = 0.;
	_dbErrtime = 0.;
	_dbDuraTime = 0.;
	_dbbufferTime = 0.;
	_dbRunDowntime = 0.;

	_bHistoryRun_ = false;
	_bDayResetchk_ = false;

	g_barcode[BCD_ADC] = NULL;
	g_rfid = NULL;
	_onlineEndIndex = 0;
	_fp = NULL;
	_err_fp = NULL;

	_nLoadCellRetryCnt = 0;
	_LotEndRetryCnt = 0;

	_pCurrentForm = NULL;
	_bSeeLotShow = false;

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::AppModalBegin(TObject *Sender)
{
//	GrayFrmCDBOX->Display();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::AppModalEnd(TObject *Sender)
{
//	GrayFrmCDBOX->Close();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Dispatch(void *Message)
{
 	TMessage* p = static_cast< TMessage* >( Message );

	switch( p->Msg )
	{
		case WM_PASSWORD_WINDOW:
			if (false == frmLogin->Visible)
			{
				if (true == frmLogin->isEnable())
				{
					frmLogin->changeLevel(PW_SUPER);
					if (mrOk == frmLogin->ShowModal())
					{
						frmLogin->enable(false);
						FrmCdBox->setFlag(CD_OK);
						FrmCdBox->setTitle( "INFORMATION" );
						FrmCdBox->setText( "PASSWORD_FUNCTION_DISABLED");
						FrmCdBox->BringToFront();
						FrmCdBox->ShowModal();
					}
				}
				else
				{
					FrmCdBox->setFlag(CD_YESNO);
					FrmCdBox->setTitle( "INFORMATION" );
					FrmCdBox->setText("PASSWORD_FUNCTION_ENABLED" );
					if (mrYes == FrmCdBox->ShowModal())
					{
						frmLogin->enable(true);
						frmLogin->changeLevel( PW_OPERATOR );
					}
				}
			}
			break;

		default:
			TForm::Dispatch(Message);
			break;
	}
}

//---------------------------------------------------------------------------

void __fastcall TMainForm::FormShow(TObject *Sender)
{

	for(int i=1; i<=ParamCount(); i++)
	{
		if(LowerCase(ParamStr(i))=="/dialog")
		{
			this->BorderStyle = bsDialog;
			this->Caption = "Debugging Mode";
			this->Height = 1024+29;
		}

		if(LowerCase(ParamStr(i))=="/super")
		{
			frmLogin->changeLevel(PW_SUPER);
			frmLogin->setKeepPwd(true);
		}
	}

	g_pPiper = ::CreatePiper();
	ConnectPiper->Enabled = true;
	this->Connect_Initialize();
	this->SqlLiteDB_Initialize();
    this->ShowRecipeInformation();

	FormMainStatus->Parent = PanelStageStatus;
	FormMainStatus->Align = alClient;
	FormMainStatus->Show();
//	FormMainStatus->BringToFront();
//	FormMainStatus->Visible= true;
//	this->ScreenChange("MAINSCREEN");

	PanelSecsGem->Color = clGreen;
	String strVer = "RMS Ver." + refreshVersion(); //RMS Version 표기
	PanelProgramVersion->Caption = strVer;
	for(int i = 0; i < 3; i++)
	{
		nWriteCommunicationDM(0,flagVisionComm + i);
	}

    FormMainStatus->Mainstatus_Initialize();

    FrmVisionSetUp->StartVisionChkSwitch();
	FormSecsGemSet->SecsInitializeProcess();
    FrmRouterComm->StartRouterCommChkSwitch();
//	ConnectPiper->Enabled = true;
    this->BringToFront();
    	//FrmPMSControl->PMSCommSwitch(false);
}
//---------------------------------------------------------------------------

String TMainForm::refreshVersion()
{
    WIN32_FILE_ATTRIBUTE_DATA attr;
    ZeroMemory(&attr, sizeof(attr));
   ::GetFileAttributesEx( Application->ExeName.c_str(), GetFileExInfoStandard,  (LPVOID) &attr);
	SYSTEMTIME stUTC, stLocal;
    ::FileTimeToSystemTime(&attr.ftLastWriteTime , &stUTC);
    ::SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);
    String version;
    version.sprintf( _T("%d.%02d.%02d"), stLocal.wYear, stLocal.wMonth, stLocal.wDay);
	return version;
}
//---------------------------------------------------------------------------

void   TMainForm::ShowRecipeInformation()
{
	int ngroupNo = nReadGroupNo();
	int nrecipeNo =  nReadRecipeNo();

	if(nrecipeNo == 0)
	{
		nrecipeNo = 1;
	}

	String StrGrp = Get_GroupName();
	String StrTemp = Get_RecipeName();
   	PanelGroupName->Caption = "[" + IntToStr(ngroupNo) + "] " + StrGrp ;
    PanelRecipeName->Caption = "["+ IntToStr(nrecipeNo) + "] " + StrTemp;
}
//---------------------------------------------------------------------------
void  TMainForm::MachineHistoryData(String StrTemp)
{
	String logMessage = Now().FormatString("yyyy-mm-dd hh:mm:ss") + " : " + StrTemp;
    TDateTime dt = Now();
    String fileName = dt.FormatString("yyyy-mm-dd") + ".txt";

    if (_currentLogFileName != fileName)
    {
		if (_fp)
			fclose(_fp);

		String sDir = "C:\\KOSES\\History\\MachineHistory\\";
		ForceDirectories(sDir);
        String fullPathName = sDir + fileName;
        _fp = _wfopen( fullPathName.c_str(), L"at");
		assert(_fp);
		_currentLogFileName = fileName;
	}

	fputws(logMessage.c_str(), _fp);
	fputws(L"\r\n", _fp);
	fflush(_fp);

	MemoLog->Lines->Add(logMessage);

    if (CheckMemoRefresh->Checked)
    	SendMessage(MemoLog->Handle, WM_VSCROLL, SB_BOTTOM, 0);

    if(MemoLog->Lines->Count > 1000)
    {
    	fflush(_fp);
    	MemoLog->Lines->BeginUpdate();
        MemoLog->SelStart = 0;
		MemoLog->SelLength = MemoLog->Perform(EM_LINEINDEX, 1000, 0);
        MemoLog->SelText = "";
		MemoLog->Lines->EndUpdate();
    }
}
//---------------------------------------------------------------------------
void  TMainForm::AlarmHistoryData(String StrTemp)
{
	String logMessage = Now().FormatString("yyyy-mm-dd hh:mm:ss") + " : " + StrTemp;
	TDateTime dt = Now();
	String fileName = dt.FormatString("yyyy-mm-dd") + ".txt";

	if (_currentAllErrorLogFile != fileName)
	{
		if (_err_fp)
			fclose(_err_fp);

		String sDir = "C:\\KOSES\\History\\AlarmHistory\\";
		ForceDirectories(sDir);

		String fullPathName = sDir + fileName;
		_err_fp = _wfopen( fullPathName.c_str(), L"at");
		assert(_err_fp);
		_currentAllErrorLogFile = fileName;
	}

	fputws(logMessage.c_str(), _err_fp);
	fputws(L"\r\n", _err_fp);
	fflush(_err_fp);

//	MemoLog->Lines->Add(logMessage);
//
//	if (CheckMemoRefresh->Checked)
//		SendMessage(MemoLog->Handle, WM_VSCROLL, SB_BOTTOM, 0);
//
//	if(MemoLog->Lines->Count > 1000)
//	{
//		fflush(_fp);
//		MemoLog->Lines->BeginUpdate();
//		MemoLog->SelStart = 0;
//		MemoLog->SelLength = MemoLog->Perform(EM_LINEINDEX, 1000, 0);
//		MemoLog->SelText = "";
//		MemoLog->Lines->EndUpdate();
//	}
}
//---------------------------------------------------------------------------

void TMainForm::Connect_Initialize()
{
	if(NULL == g_MMIComm)
	{
		g_MMIComm = new C_Communication();
	}

	if( g_MMIComm->Init() == true )
	{
    	MachineHistoryData("MMICOMM -> Initial Success!");
	}

	MachineHistoryData("Software Communication Event start!");

	TIniFile* configIni = new TIniFile(ExtractFilePath(Application->ExeName)+"Config.ini");


	if(NULL == g_barcode[BCD_ADC])
	{
		// 0: RS-232 , 1: LAN
		int nComType = configIni->ReadInteger("BARCODE","COMM_TYPE", 0);
		g_barcode[BCD_ADC] = new Barcode(BCD_ADC, nComType);
		if(nComType == BCD_RSCOM)
		{
			int nPort = configIni->ReadInteger("BARCODE","COMPORT", 0);
			if (0 != nPort)
				g_barcode[BCD_ADC]->initialize(nPort);
			this->MachineHistoryData("BARCODE -> Initial RS-232!");
		}
		else
		{
			String ipAddress = configIni->ReadString("BARCODE","IP", "");
			int nPort = configIni->ReadInteger("BARCODE","PORT", 9004);
			if (ipAddress != "" && nPort >0)
				g_barcode[BCD_ADC]->initialize(ipAddress, nPort);
			this->MachineHistoryData("BARCODE -> Initial TCP/IP!");
		}
	}

	if(NULL == g_rfid)
	{
		int nComType = configIni->ReadInteger("RFID_MGZ","COMM_TYPE", 0);
		g_rfid = new RFID(0, nComType, RFID_CEYON);
		if(nComType == BCD_RSCOM)
		{
			int nPort = configIni->ReadInteger("RFID_MGZ","COMPORT",0);	//세연
			if (0 != nPort)
				g_rfid->initialize(nPort);
			this->MachineHistoryData("RFID -> Initial RS-232!");
		}
		else
		{
			String ipAddress = configIni->ReadString("RFID_MGZ","IP", "");
			int nPort = configIni->ReadInteger("RFID_MGZ","PORT", 9005);
			if (ipAddress != "" && nPort >0)
				g_rfid->initialize(ipAddress, nPort);
			this->MachineHistoryData("RFID -> Initial TCP/IP!\n"
									+ ipAddress + ":" + IntToStr(nPort));
		}
	}

    FrmLoadCell->FrmConnectInitialize();


    _eqpID = configIni->ReadString("TC","EQP_ID", "");
	_eqpVisionID = configIni->ReadString("TC","EQP_VISION_ID", "");
	_ohtInPortID_Empty = configIni->ReadString("TC","OHT_IN_PORT_ID_EMPTY", "");
	_ohtInPortID_Cover = configIni->ReadString("TC","OHT_IN_PORT_ID_COVER", "");
	_ohtOutPortID_Good = configIni->ReadString("TC","OHT_OUT_PORT_ID_GOOD", "");
	_ohtOutPortID_Reject = configIni->ReadString("TC","OHT_OUT_PORT_ID_REJECT", "");

	if(!configIni->ValueExists("TC","EQP_MODEL"))
	{
		configIni->WriteString("TC","EQP_MODEL", "SORTER");
	}
	_eqpModel = configIni->ReadString("TC","EQP_MODEL", "SORTER");

	if(!configIni->ValueExists("TC","EQP_VERSION"))
	{
		configIni->WriteString("TC","EQP_VERSION", "1.0.0.1");
	}
	_eqpVersion = configIni->ReadString("TC","EQP_VERSION", "1.0.0.1");

	delete configIni;

	//frmTCComm->TccommInitializeProcess();
	this->Savingrunningtime(false);

	MainRefreshTimer->Enabled = true;
	RobotRefreshTimer->Enabled = true;
	WarringRefreshTimer->Enabled = true;
    MCrunSaveTimer->Enabled = true;

    HistoryResetTimer->Enabled = true;
}

//---------------------------------------------------------------------------
void TMainForm::SqlLiteDB_Initialize()
{
	try
	{
    	AnsiString strLOT =ExtractFilePath(Application->ExeName) + "Ini\\system\\DB\\LotHistory.DB";

		if(FileExists(strLOT)== false)
		{
		  	SQLiteLotInfoDB.open(strLOT.c_str());
			SQLiteLotInfoDB.execDML("create table LotInfo(kIndex integer primary key, EventTime char(20) ,RecipeName1 char(50) , RecipeName2 char(50) , STATUS char(10),"
            " DURATION char(10) ,  LotCode1 char(40) , LotCode2 char(40) , UserTag char(20) , LotType char(5));");
		}
		else
		{
			SQLiteLotInfoDB.open(strLOT.c_str());
        }
	}
	catch (Exception &e)
	{
		ShowMessage(e.Message);
	}


	try
	{
        //  EventTime  발생시간 , RunCode  : 가동 형태 ( Run STOP Error) , StatusDuration  가동형태에 따른 이전상태 지속시간
        //  RecipeName1"RecipeName2 : 레시피 이름 , AlarmCode 알람 코드 번호    AlarmType 알람 타입   ( A E W)

    	AnsiString strRundata =ExtractFilePath(Application->ExeName) + "Ini\\system\\DB\\RunData.DB";

		if(FileExists(strRundata)== false)
		{
		  	SQLiteRunDB.open(strRundata.c_str());
			SQLiteRunDB.execDML("create table Rundata(kIndex integer primary key, EventTime char(20) , RunCode char(5) , StatusDuration char(10) , RecipeName1 char(50),"
            					  "RecipeName2 char(50) , AlarmCode char(5)  ,   AlarmType char(5));");
		}
		else
		{
			SQLiteRunDB.open(strRundata.c_str());
        }
	}
	catch (Exception &e)
	{
		ShowMessage(e.Message);
	}


	try
	{
    	AnsiString strRunHistory =ExtractFilePath(Application->ExeName) + "Ini\\system\\DB\\RunHistory.DB";

		if(FileExists(strRunHistory)== false)
		{
		  	SQLiteRunHistoryDB.open(strRunHistory.c_str());
			SQLiteRunHistoryDB.execDML("create table RunHistory(kIndex integer primary key, EventTime char(20) , RunTime char(20) , StopTime char(20) ,"
										"AlarmTime char(20) , RundownTime char(20), Count1 char(5) , Count2 char(5) , Count3 char(5));");
		}
		else
		{
			SQLiteRunHistoryDB.open(strRunHistory.c_str());
        }
	}
	catch (Exception &e)
	{
		ShowMessage(e.Message);
	}

	try
	{
    	AnsiString strALARM =ExtractFilePath(Application->ExeName) + "Ini\\system\\DB\\AlarmHistory.DB";

		if(FileExists(strALARM)== false)
		{
		  	SQLiteAlarmDB.open(strALARM.c_str());
			SQLiteAlarmDB.execDML("create table MandatoryAlarm(kIndex integer primary key, EventTime char(20) ,Name char(60) ,AlarmCode char(10) , AlarmWarning char(2));");
		}
		else
		{
			SQLiteAlarmDB.open(strALARM.c_str());
        }
	}
	catch (Exception &e)
	{
		ShowMessage(e.Message);
	}


	try
	{
    	AnsiString strRejectPath =ExtractFilePath(Application->ExeName) + "Ini\\system\\DB\\RejectHistory.DB";

		if(FileExists(strRejectPath)== false)
		{
		  	SQLiteRejectDB.open(strRejectPath.c_str());
			SQLiteRejectDB.execDML("create table RejectData(kIndex integer primary key, EventTime char(20) ,RejectUnit char(100) ,LotCode char(20) ,  GroupIndex char(5) , RecipeIndex char(5));");
		}
		else
		{
			SQLiteRejectDB.open(strRejectPath.c_str());
        }
	}
	catch (Exception &e)
	{
		ShowMessage(e.Message);
	}

}
//---------------------------------------------------------------------------


void __fastcall TMainForm::MainBtn1Click(TObject *Sender)
{
	this->ScreenChange(dynamic_cast<TBitBtn *>(Sender)->Caption);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	MainRefreshTimer->Enabled = false;
	RobotRefreshTimer->Enabled = false;
	WarringRefreshTimer->Enabled = false;
	MCrunSaveTimer->Enabled = false;
	HistoryResetTimer->Enabled = false;
	ConnectPiper->Enabled = false;
	g_pTpBase->Close();
	g_pPiper->Close();

	delete g_MMIComm;
	g_MMIComm = NULL;

	if (_fp)
		fclose(_fp);
	_fp = NULL;

	if (_err_fp)
		fclose(_err_fp);
	_err_fp = NULL;

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PanelMainMenuClick(TObject *Sender)
{
	//ConfigSetForm->ShowModal();

	this->ScreenChange("MAINSCREEN");
	frmLogin->changeLevel(PW_OPERATOR);

	FrmPopMenu->ShowModal();
}
//---------------------------------------------------------------------------
void TMainForm::VisionHistoryData(int VisionSeparator,String StrTemp)
{
	String strLog;
	if(VisionSeparator == _ALIGN_VISION1_)
	{
		strLog = "[BOTTOM ALIGN] " + StrTemp;
	}
	else if(VisionSeparator == _ALIGN_VISION2_)
	{
		strLog = "[FLIPPER VISION] " + StrTemp;
	}
	else if(VisionSeparator == _PRE_QC_VISION_)
	{
		strLog = "[QC VISION] " + StrTemp;
	}
	else if(VisionSeparator == _SORTER_JOB_CHANGE_VISION_)
	{
		strLog = "[SORTER JOB CHANGE] " + StrTemp;
	}
	else if(VisionSeparator == _TRAY_VISION_)
	{
		strLog = "[TRAY VISION] " + StrTemp;
	}
	else if(VisionSeparator == _DVI_)
	{
		strLog = "[DVI] " + StrTemp;
	}
	else
	{
		strLog = StrTemp;
	}


	String logMessage = Now().FormatString("yyyy-mm-dd hh:mm:ss")+ " : " + strLog;
    TDateTime dt = Now();
    String fileName = dt.FormatString("yyyy-mm-dd") + ".txt";

	if (_currentLogFileName != fileName)
    {
		if (_fp)
			fclose(_fp);
        String sDir = "C:\\KOSES\\History\\VisionHistory\\";
		ForceDirectories(sDir);
		String fullPathName = sDir + fileName;
		_fp = _wfopen( fullPathName.c_str(), L"at");
		assert(_fp);
		_currentLogFileName = fileName;
	}

	fputws(logMessage.c_str(), _fp);
	fputws(L"\r\n", _fp);
	FrmVisionSetUp->VisionMemo->Lines->Add(logMessage);

//		if (CheckMemoRefresh->Checked)
//		SendMessage(VisionMemo->Handle, WM_VSCROLL, SB_BOTTOM, 0);

	if(FrmVisionSetUp->VisionMemo->Lines->Count > 1000)
	{
		fflush(_fp);
		FrmVisionSetUp->VisionMemo->Lines->BeginUpdate();
		FrmVisionSetUp->VisionMemo->SelStart = 0;
		FrmVisionSetUp->VisionMemo->SelLength = FrmVisionSetUp->VisionMemo->Perform(EM_LINEINDEX, 1000, 0);
		FrmVisionSetUp->VisionMemo->SelText = "";
		FrmVisionSetUp->VisionMemo->Lines->EndUpdate();
	}
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall TMainForm::MainRefreshTimerTimer(TObject *Sender)
{
	MainForm->ShowRecipeInformation();

	this->AlarmRefresh();
	this->WarningRefresh();
	this->MachineResponseForSEQ();
	this->MachineStatus_Refresh();
	this->staubliMode_Refresh();
	this->reqMsgNotice();
	this->VisionRefresh();
	this->AutoFeedBackRefresh();

	// FrmVisionSetUp->vCutFileDelete(); // 현재 미사용

	LabelNowTime->Caption = Now().CurrentDateTime().FormatString("YYYY-MM-DD HH:MM:SS");

	int curCommState = 0;
	for(int i = 0; i < 3; i++)
	{
		curCommState = nReadCommunicationDM(flagVisionComm + i);
		//curCommState = 1;
		TiLedMatrix *iLedMatrix = (TiLedMatrix*)FindComponent("iLedMatrix" + IntToStr(i+1));

		if(curCommState)
		{
			iLedMatrix->IndicatorActive[0][0] = true;
		}
		else
		{
			iLedMatrix->IndicatorActive[0][0] = false;
        }
	}
	////
	switch( frmLogin->getLevel())
	{
		case PW_OPERATOR:
			PanelLogin->Caption = "OPERATOR";
			PanelLogin->Color = clLime;
			PanelLogin->Font->Color = clBlack;
			break;

		case PW_MAINTENANCE:
			PanelLogin->Caption = "MAINTENANCE";
			PanelLogin->Color = clAqua;
			PanelLogin->Font->Color = clBlack;
			break;
		case PW_ENGINEER:
			PanelLogin->Caption = "ENGINEER";
			PanelLogin->Color = clGray;
			PanelLogin->Font->Color = clWhite;
			break;
		case PW_SUPER:
			PanelLogin->Caption = "SUPER";
			PanelLogin->Color = clRed;
			PanelLogin->Font->Color = clWhite;
			break;
	}

	bool flag = nReadCommunicationDM(300); // ADC MODE
	if(flag) PanelAdcMode->Color = clLime;
	else PanelAdcMode->Color = clGray;

	// RSM
	if(bReadUseSkip(usRunSplitMerge) == true && bReadUseSkip(usRfid) == true)
	{
		PanelRsmStatus->Color = clLime;
	}
	else
	{
		PanelRsmStatus->Color = clGreen;
	}

	if(bReadUseSkip(usAutoLotEnd))
	{
	   PanelAutoLotEnd->Color = clLime;
	}
	else
	{
	   PanelAutoLotEnd->Color = clGreen;
    }


	// SECSGEM
	if(FormSecsGemSet->m_fStart)
		PanelSecsGem->Color = clLime;
	else
		PanelSecsGem->Color = clGreen;

	static bool tic = false;


    	/// ALLHOME
//	if(nReadCommunicationDM(motorHomming))
//	{
//		this->process_homming();
//		nWriteCommunicationDM(0,motorHomming);
//	}

    int home = nReadCommunicationDM(91); // ALL HOME\

    static int before = home;


	if(home == 1)
    {
    	PanelAllhome->Color = clLime;
    }
    else if(home == 2)
    {
    	if(tic)
        {
        	PanelAllhome->Color = clLime;
        }
        else
        {
			PanelAllhome->Color = clGray;
        }

    	tic = !tic;

        if(before != home)
        {
         	// change screen
            FormMainStatus->ShowAllhomeScrn();
        }
    }
    else
    {
		PanelAllhome->Color = clGray;
	}

	before = home;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#define		_CLEAR_		0
#define		_DETECT_	1


void TMainForm::AlarmRefresh()
{
	TIniFile* DetailAlarmini = new TIniFile(ExtractFilePath(Application->ExeName)+ "Ini\\Alarm.ini");

	static int ErrorCode = 0;

	bool comm = false;

	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_ERR_WR;
	if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
	{
		comm = true;

		int errcode = g_MMIComm->m_mmiToSeq.buffer.errWr.err[ 0 ] ;

		if(errcode ==0)
		{
			PanelAlarm->Caption = "NO ALARM";
			PanelAlarm->Color = clWhite;
			PanelAlarm->Font->Color = clBlack;
		}

		if(ErrorCode!=errcode)
		{
			ErrorCode = errcode;
			static int lastErr = 0;
			String seq_msg="";
			String all_err_log="";

			if(errcode > 0)
			{
				FormSecsGemSet->g_GemAlarmProcess(lastErr, _CLEAR_);

				seq_msg = "'["+IntToStr(ErrorCode)+"]"+ DetailAlarmini->ReadString("NAME","NAME"+IntToStr(ErrorCode),"NAME"+IntToStr(ErrorCode))+"'";
				if(MainForm->b_TpConnect)
				{
					g_pTpBase->logAlarm(L"EQUIPMENT",L"ERROR",IntToStr(ErrorCode).c_str(),L"OCCURRED",L"'DESCRIPTION'",seq_msg.c_str(), L"'DURATION'", L"'NO'");
				}

				for(int i=0; i < 10; i++)
				{
					int err = g_MMIComm->m_mmiToSeq.buffer.errWr.err[i] ;

					if(err != 0)
					{
						all_err_log = "'["+IntToStr(err)+"]"+ DetailAlarmini->ReadString("NAME","NAME"+IntToStr(err),"NAME"+IntToStr(err))+"'";
						AlarmHistoryData("ALL Error detected : " + all_err_log);
					}
				}

				MachineHistoryData("SEQ Error detected : " + seq_msg);

				bool bTemp = DetailAlarmini->ReadBool("CHECK","CHECK"+IntToStr(ErrorCode),true);
				if(_checkRunTime > 30 || (lastErr != ErrorCode && _checkRunTime > 1))
				{
					FormSecsGemSet->g_GemAlarmProcess(ErrorCode, _DETECT_);
					this->Alarm_Recording(ErrorCode , bTemp ? 1 : 2);
					lastErr = ErrorCode;
				}
				_checkRunTime = 0;

				if(errcode == 288)
				{
					String strStageNum = IntToStr(nReadCommunicationDM(mapStageNum));
					String strStagePickNum = IntToStr(nReadCommunicationDM(mapStagePickNum));
					String strstaubliTorqueCurData = FloatToStr(dReadCommunicationDM(staubliTorqueCurData));
					String strstaubliTorqueLimit = FloatToStr(dReadPkgData(staubliTorqueLimit));

					AnsiString strLotID;
					AnsiString strBarcode;
					
					for (int i = 0; i < 4; i++)
					{
						if(strStageNum == IntToStr(i+1))
						{
							strLotID = MainForm->vLotiD[i];
							strBarcode = MainForm->vBarcode[i];
						}
					}

					//this->MachineHistoryData("Torque Limit Error Data = LotID: "+strLotID+", Index: R"+strStageNum+", PickNum: "+strStagePickNum+", Barcode: "+strBarcode+", TorqueValue: "+strstaubliTorqueCurData+", TorqueLimit: "+strstaubliTorqueLimit);
					this->MachineHistoryData("Torque Limit Error Data = LotID: "+strLotID+", Index: R"+strStageNum+", PickNum: "+strStagePickNum+", Barcode: "+strBarcode);

				}

				if(Application->ModalLevel < 1)	FrmAlarmDetailList->AlarmDetail_Initialize(true);
			}

			if(seq_msg == "" && lastErr != 0)
			{

				if(MainForm->b_TpConnect)
				{
					seq_msg = "'["+IntToStr(lastErr)+"]"+ DetailAlarmini->ReadString("NAME","NAME"+IntToStr(lastErr),"NAME"+IntToStr(lastErr))+"'";
					g_pTpBase->logAlarm(L"EQUIPMENT",L"ERROR",IntToStr(lastErr).c_str(),L"RELEASED",L"'DESCRIPTION'",seq_msg.c_str(), L"'DURATION'", L"'NO'");
				}

				FormSecsGemSet->g_GemAlarmProcess(lastErr, _CLEAR_);
				MachineHistoryData("SEQ Alarm Clear.");
			}

			PanelAlarm->Caption = seq_msg;
			PanelAlarm->Color = clRed;
			PanelAlarm->Font->Color = clWhite;
		}
	}

	int nErrorCnt =0 ;
	int nWarningCnt =0 ;

	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_ERR_WR;
	if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
	{
		for( INT nIndex = 0; nIndex < 10; nIndex++ )
		{
			int errcnt = g_MMIComm->m_mmiToSeq.buffer.errWr.err[ nIndex ] ;
			int wrncnt = g_MMIComm->m_mmiToSeq.buffer.errWr.wr[ nIndex ] ;

			if(errcnt > 0)
			{
				nErrorCnt++;
			}
			if(wrncnt > 0)
			{
				nWarningCnt++;
			}
		}
	}
	MainForm->PanelAlarmCnt->Caption  =  IntToStr(nErrorCnt);
	MainForm->PanelWarningCnt->Caption  =  IntToStr(nWarningCnt);
	delete DetailAlarmini;


	iLedSeqComm->IndicatorActive[0][0] = comm;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void TMainForm::WarningRefresh()
{
	String fileName = ExtractFilePath(Application->ExeName)+ "Ini\\Warning.ini";
	BOOL bExist = FileExists(fileName);
	TIniFile* DetailWarningini = new TIniFile(fileName);
	static int WarnCode = 0;
	static int lastwrn = 0;

	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_ERR_WR;
	if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
	{
		int wrncode = g_MMIComm->m_mmiToSeq.buffer.errWr.wr[ 0 ] ;
		if(wrncode ==0)
		{
			PanelWarning->Caption = "NO WARNING";
			PanelWarning->Color = clWhite;
			PanelWarning->Font->Color = clBlack;

			WarnCode = 0; // 서버 전송을 위한 사용자 RESET 버튼 필수
		}

		bool bWrn = false;
		for (int i = 0; i < 10; i++)
		{
			int wrnCheck = g_MMIComm->m_mmiToSeq.buffer.errWr.wr[i];
			if (wrnCheck >= 870 && wrnCheck <= 873)
			{
				wrncode = wrnCheck;
				bWrn = true;
				break;
			}
		}

		if(WarnCode!=wrncode)
		{
			WarnCode = wrncode;

			String seq_msg="";

			if(wrncode > 0)
			{
				if (WarnCode >= 870 && WarnCode <= 873)
				{
					FormSecsGemSet->g_GemAlarmProcess(870, _CLEAR_);
					FormSecsGemSet->g_GemAlarmProcess(871, _CLEAR_);
					FormSecsGemSet->g_GemAlarmProcess(872, _CLEAR_);
					FormSecsGemSet->g_GemAlarmProcess(873, _CLEAR_);
				}

				seq_msg = "'["+IntToStr(wrncode)+"]"+ DetailWarningini->ReadString("NAME","NAME"+IntToStr(wrncode),"NAME"+IntToStr(wrncode))+"'";
				MachineHistoryData("SEQ Warning detected : " + seq_msg);
				this->Alarm_Recording(WarnCode ,0);

				if (WarnCode >= 870 && WarnCode <= 873)
				{
					FormSecsGemSet->g_GemAlarmProcess(WarnCode, _DETECT_);

					lastwrn = WarnCode;
				}

				if(MainForm->b_TpConnect)
				{
					g_pTpBase->logAlarm(L"EQUIPMENT",L"WARNING",IntToStr(wrncode).c_str(),L"OCCURRED",L"'DESCRIPTION'",seq_msg.c_str(), L"'DURATION'", L"'NO'");
				}
			}

			if(seq_msg == "" && lastwrn != 0)
			{
				if(MainForm->b_TpConnect)
				{
					seq_msg = "'["+IntToStr(lastwrn)+"]"+ DetailWarningini->ReadString("NAME","NAME"+IntToStr(lastwrn),"NAME"+IntToStr(lastwrn))+"'";
					g_pTpBase->logAlarm(L"EQUIPMENT",L"WARNING",IntToStr(lastwrn).c_str(),L"RELEASED",L"'DESCRIPTION'",seq_msg.c_str(), L"'DURATION'", L"'NO'");
				}

				if (WarnCode >= 870 && WarnCode <= 873)
				{
					FormSecsGemSet->g_GemAlarmProcess(lastwrn, _CLEAR_);
				}

				MachineHistoryData("SEQ Warning Clear.");
			}

			PanelWarning->Caption = seq_msg;
			PanelWarning->Color = clLime;
			PanelWarning->Font->Color = clBlack;
		}
	}
	delete DetailWarningini;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void TMainForm::Alarm_Recording(int nErrCode , int nAlarmwarning)
{
	char cTime[50] = {0,};
	char cName[100] = {0,};
	char cCode[10] = {0,};
	char cFlag[2] = {0,};

	String strTime = Now().FormatString("yyyy-mm-dd hh:mm:ss");
	WideCharToMultiByte(0, 0, strTime.c_str(), -1, cTime, strTime.Length()+2, NULL, NULL);

	String strCode = IntToStr(nErrCode);
	WideCharToMultiByte(0, 0, strCode.c_str(), -1, cCode, strCode.Length(), NULL, NULL);

	String strFlag = IntToStr(nAlarmwarning);
	WideCharToMultiByte(0, 0, strFlag.c_str(), -1, cFlag, strFlag.Length(), NULL, NULL);

	String strErrInfo;
	if(nAlarmwarning >= 1)
	{
		TIniFile* Alarmini = new TIniFile(ExtractFilePath(Application->ExeName)+ "Ini\\Alarm.ini");
		strErrInfo = "["+IntToStr(nErrCode)+"]"+ Alarmini->ReadString("NAME","NAME"+IntToStr(nErrCode),"NAME"+IntToStr(nErrCode));
		delete Alarmini;
	}
	else if(nAlarmwarning == 0)
	{
		TIniFile* Warningini = new TIniFile(ExtractFilePath(Application->ExeName)+ "Ini\\Warning.ini");
		strErrInfo = "["+IntToStr(nErrCode)+"]"+ Warningini->ReadString("NAME","NAME"+IntToStr(nErrCode),"NAME"+IntToStr(nErrCode));
		delete Warningini;
	}

	WideCharToMultiByte(0, 0, strErrInfo.c_str(), -1, cName, strErrInfo.Length(), NULL, NULL);


	try
	{
		char Savebuf[512] = {0,};
		sprintf(Savebuf, "insert into MandatoryAlarm (EventTime , Name , AlarmCode ,AlarmWarning )  values ('%s','%s','%s' , '%s');" ,cTime, cName, cCode , cFlag);
		SQLiteAlarmDB.execDML(Savebuf);
	}
	catch (CppSQLite3Exception& e)
	{
		cerr << e.errorCode() << ":" << e.errorMessage() << endl;
	}
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void TMainForm::Savingrunningtime(bool bFlag)
{
	TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "Ini\\MCTime.ini");

	if(bFlag == true)
	{
		ini->WriteFloat("MachineTime" , "RUN"  , _dbRuntime);
		ini->WriteFloat("MachineTime" , "STOP"  , _dbStoptime);
		ini->WriteFloat("MachineTime" , "ERROR"  , _dbErrtime);
		ini->WriteFloat("MachineTime" , "RunDownTime"  , _dbRunDowntime);
	}
	else
	{
		_dbRuntime = ini->ReadFloat("MachineTime" , "RUN"  , 0);
		_dbStoptime = ini->ReadFloat("MachineTime" , "STOP"  , 0);
		_dbErrtime = ini->ReadFloat("MachineTime" , "ERROR"  , 0);
		_dbRunDowntime = ini->ReadFloat("MachineTime" , "RunDownTime"  , 0);
	}
	delete ini;
}
//---------------------------------------------------------------------------
void TMainForm::Resetrunningtime()
{
	TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "Ini\\MCTime.ini");
	ini->WriteFloat("MachineTime" , "RUN"  , 0);
	ini->WriteFloat("MachineTime" , "STOP"  , 0);
	ini->WriteFloat("MachineTime" , "ERROR"  , 0);
	ini->WriteFloat("MachineTime" , "RunDownTime"  , 0);

	_dbRuntime = ini->ReadFloat("MachineTime" , "RUN"  , 0);
	_dbStoptime = ini->ReadFloat("MachineTime" , "STOP"  , 0);
	_dbErrtime = ini->ReadFloat("MachineTime" , "ERROR"  , 0);
	_dbRunDowntime = ini->ReadFloat("MachineTime" , "RunDownTime"  , 0);

	delete ini;
}
//---------------------------------------------------------------------------


void TMainForm::MachineStatus_Refresh()
{
//	String label[] = { "STOP", "AUTO", "ERROR", "CYCLE RUN", "EMG", "RUN DOWN"};
//	TColor panelColor[] = { clGreen, clLime, clRed, clAqua, clBlack, clGreen};


	int nAlarmCode = 0;
	int nType  = -1;

	if( _nRunBuffer_ !=  nReadCommunicationDM( mcState ))
	{
		_nRunBuffer_ =  nReadCommunicationDM( mcState );


		_dbDuraTime = _dbbufferTime - _dbDuraTime;

		this->Savingrunningtime(true);

		switch(_nRunBuffer_)
		{
			case STATUS_STOP :
            {
                MachineHistoryData("Machine Status Change -> STOP");
				PanelMachineStatus->Caption = "STOP";
				PanelMachineStatus->Color = clGreen;
			}
			break;

			case STATUS_AUTO :
            {
				MachineHistoryData("Machine Status Change -> AUTO");
				PanelMachineStatus->Caption = "AUTO";
				PanelMachineStatus->Color = clLime;

				this->ScreenChange("MAINSCREEN");
				frmLogin->changeLevel(PW_OPERATOR);

				_checkRunTime = 0;
			}
			break;

            case STATUS_RUN :
            {
				MachineHistoryData("Machine Status Change -> CYCLE RUN");
				PanelMachineStatus->Caption = "CYCLE RUN";
				PanelMachineStatus->Color = clAqua;
            }
			break;

            case STATUS_ERROR :
            {
				MachineHistoryData("Machine Status Change -> ERROR");
				PanelMachineStatus->Caption = "ERROR";
				PanelMachineStatus->Color = clRed;

				nAlarmCode = _AlarmCoodeReturn(true);
				nType = _AlarmTypeRet(nAlarmCode);
            }
			break;

			case STATUS_RUNDOWN:
            {
				MachineHistoryData("Machine Status Change -> RUNDOWN");
				PanelMachineStatus->Caption = "RUN DOWN";
				PanelMachineStatus->Color = clGreen;

				this->ScreenChange("MAINSCREEN");
				frmLogin->changeLevel(PW_OPERATOR);

				_checkRunTime = 0;
			}
            break;

            case STATUS_EMG :
            {
				MachineHistoryData("Machine Status Change -> EMG!");
				PanelMachineStatus->Caption = "EMERGENCY";
				PanelMachineStatus->Color = clBlack;
            }
            break;

            default :
            {
            	MachineHistoryData("UNKNOWN Machine Status :: CHECK THE DATA STATUS!");
            }
            break;
		}

		if(_nRunBuffer_ > -1)
        {
            String sFactor[10];

			sFactor[FACTOR_TIME] = Now().FormatString("yyyy-mm-dd hh:mm:ss");
            sFactor[FACTOR_RUNCODE] = IntToStr(_nRunBuffer_);
            sFactor[FACTOR_DURATION] =  FloatToStr(_dbDuraTime);
            sFactor[FACTOR_RECIPE1] = PanelGroupName->Caption;
            sFactor[FACTOR_RECIPE2] = PanelRecipeName->Caption;
			sFactor[FACTOR_ALARMCODE] =  IntToStr(nAlarmCode);
            sFactor[FACTOR_ALARMTYPE] =  IntToStr(nType);

			this->Run_Recording(sFactor);
		}

		// 0: Stop  1: Auto  2: Error 3: Cycle-Run 4: Emg
		//SecsGem
		//FormSecsGemSet->GemProcessStateChange();
		int nGemProcessStatus;
		switch(_nRunBuffer_)
		{
			case 0:		//STOP
				nGemProcessStatus = Processing_Stop;
				break;
			case 1:		//AUTO
				nGemProcessStatus = Processing_Run;
				break;
			case 2:		//ERROR
				nGemProcessStatus = Processing_Error;
				break;
			case 3:		//CYCLE
				nGemProcessStatus = Processing_Manual;
				break;
			case 4:		//EMG
				nGemProcessStatus = Processing_Error;
				break;
			case 5:		//RUNDOWN
				nGemProcessStatus = Processing_Idle;
				break;
			default:
				nGemProcessStatus = Processing_Stop;
				break;
		}
		FormSecsGemSet->SecsRunProcessingStatus(nGemProcessStatus);
	}

	// oSwStart = 8
	// oSwStop = 9
	// oSwReset = 10
	static int bSwStatus[3] = {-1,-1,-1};
	CommReadIO io;
	if(bReadIO(&io))
	{
		if(bSwStatus[0] != BIT(io.outCH[0],8))
		{
			bSwStatus[0] = BIT(io.outCH[0],8);
			if(bSwStatus[0] == false)
			{
				ImageStart_On->Visible = false;
				ImageStart_Off->Visible = true;
				LabelStart->Font->Color = clBlack;
				pnStart->Color = clBtnFace;
			}
			else
			{
				ImageStart_On->Visible = true;
				ImageStart_Off->Visible = false;
				LabelStart->Font->Color = clWhite;
				pnStart->Color = clLime;
			}
		}
		if(bSwStatus[1] != BIT(io.outCH[0],9))
		{
			bSwStatus[1] = BIT(io.outCH[0],9);
			if(bSwStatus[1] == false)
			{
				ImageStop_On->Visible = false;
				ImageStop_Off->Visible = true;
				LabelStop->Font->Color = clBlack;
				pnStop->Color = clBtnFace;
			}
			else
			{
				ImageStop_On->Visible = true;
				ImageStop_Off->Visible = false;
				pnStop->Color = clRed;
				LabelStop->Font->Color = clWhite;
			}
		}
		if(bSwStatus[2] != BIT(io.outCH[0],10))
		{
			bSwStatus[2] = BIT(io.outCH[0],10);
			if(bSwStatus[2] == false)
			{
				ImageReset_On->Visible = false;
				ImageReset_Off->Visible = true;
				LabelReset->Font->Color = clBlack;
				pnReset->Color = clBtnFace;
			}
			else
			{
				ImageReset_On->Visible = true;
				ImageReset_Off->Visible = false;
				pnReset->Color = clBlue;
				LabelReset->Font->Color = clWhite;
			}
		}
	}

	if(_nRunBuffer_ == STATUS_AUTO) _checkRunTime++;
}
//---------------------------------------------------------------------------
void TMainForm::staubliMode_Refresh()
{
	bool bAutoMode;
	bool bComm = bool(nReadCommunicationDM(modbusIsOpen));

	if(!bComm)
		return;

	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_MODBUS;

	if ( g_MMIComm->Send() &&  g_MMIComm->Recv() )
	{
		bAutoMode =  bool(g_MMIComm->m_mmiToSeq.buffer.modbus.discreteInput[9]);

		if(!bAutoMode && !FrmWarning->Showing)
		{
			if(PW_SUPER == frmLogin->getLevel())
				return;

			FrmWarning->BringToFront();
			FrmWarning->ShowModal();
		}
	}
}
//---------------------------------------------------------------------------
#define	GOOD_TRAY    7
#define	EMPTY_WARN	14
#define	FULL_WARN	18
#define	WARN_END	19

void TMainForm::WarningPopupRefresh()
{
	int nWarningNum=0;

	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_ERR_WR;
	if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
	{
		for(int i=0; i<10; i++)
		{
			nWarningNum =  g_MMIComm->m_mmiToSeq.buffer.errWr.wr[i];
			if(nWarningNum == 0)
				break;
			if((nWarningNum >= EMPTY_WARN && nWarningNum <= WARN_END) || (nWarningNum == GOOD_TRAY))
				break;
		}
	}

	bool bMode = true;

	if(nWarningNum != 0)
	{
		if((nWarningNum >= EMPTY_WARN && nWarningNum <= WARN_END) || (nWarningNum == GOOD_TRAY))
		{
			if(nWarningNum < FULL_WARN)
				bMode = false;
			else
				bMode = true;
		}
		else
			return;

		if(!FrmWarningPopup->Showing)
		{
			FrmWarningPopup->setWarningNum(nWarningNum, bMode);
			FrmWarningPopup->ShowModal();
		}
	}
	else
	{
		WarringRefreshTimer->Interval = 500;

		if(FrmWarningPopup->Showing)
		{
			FrmWarningPopup->Close();
		}
	}
}
//---------------------------------------------------------------------------
void TMainForm::Run_Recording(String strFactor[10])
{
	char cTime[20] = {0,};
	char cCode[5] = {0,};
	char cDuration[10] = {0,};
	char cRecipe1[128] = {0,};
	char cRecipe2[50] = {0,};
	char cAlarmCode[5] = {0,};
	char cAlarmType[5] = {0,};

	WideCharToMultiByte(0, 0, strFactor[FACTOR_TIME].c_str(), -1, cTime, strFactor[FACTOR_TIME].Length(),NULL, NULL);
	WideCharToMultiByte(0, 0, strFactor[FACTOR_RUNCODE].c_str(), -1, cCode, strFactor[FACTOR_RUNCODE].Length(),NULL, NULL);
	WideCharToMultiByte(0, 0, strFactor[FACTOR_DURATION].c_str(), -1, cDuration, strFactor[FACTOR_DURATION].Length(),NULL, NULL);
	WideCharToMultiByte(0, 0, strFactor[FACTOR_RECIPE1].c_str(), -1, cRecipe1, strFactor[FACTOR_RECIPE1].Length(),NULL, NULL);
	WideCharToMultiByte(0, 0, strFactor[FACTOR_RECIPE2].c_str(), -1, cRecipe2, strFactor[FACTOR_RECIPE2].Length(),NULL, NULL);
	WideCharToMultiByte(0, 0, strFactor[FACTOR_ALARMCODE].c_str(), -1, cAlarmCode, strFactor[FACTOR_ALARMCODE].Length(),NULL, NULL);
	WideCharToMultiByte(0, 0, strFactor[FACTOR_ALARMTYPE].c_str(), -1, cAlarmType, strFactor[FACTOR_ALARMTYPE].Length(),NULL, NULL);

	try
	{
		char Savebuf[256] = {0,};
		sprintf(Savebuf, "insert into Rundata (EventTime , RunCode , StatusDuration , RecipeName1 , RecipeName2 , AlarmCode , AlarmType)  values ('%s','%s','%s','%s','%s','%s','%s');"
         ,cTime, cCode, cDuration , cRecipe1 , cRecipe2 , cAlarmCode ,  cAlarmType);
		SQLiteRunDB.execDML(Savebuf);
	}
	catch (CppSQLite3Exception& e)
	{
		cerr << e.errorCode() << ":" << e.errorMessage() << endl;
	}
}
//---------------------------------------------------------------------------

void TMainForm::DailyHistory_Recording()
{
	char cTime[20] = {0,};
	char cRun[20] = {0,};
	char cStop[20] = {0,};
	char cError[20] = {0,};
	char cRunDown[20] = {0,};

	String strTime = Yesterday().FormatString("yyyy-mm-dd");
	WideCharToMultiByte(0, 0, strTime.c_str(), -1, cTime, strTime.Length(), NULL, NULL);

	String strRun = FloatToStr(_dbRuntime);
	WideCharToMultiByte(0, 0, strRun.c_str(), -1, cRun, strRun.Length(), NULL, NULL);

	String strStop = FloatToStr(_dbStoptime);
	WideCharToMultiByte(0, 0, strStop.c_str(), -1, cStop, strStop.Length(), NULL, NULL);

	String strErr = FloatToStr(_dbErrtime);
	WideCharToMultiByte(0, 0, strErr.c_str(), -1, cError, strErr.Length(), NULL, NULL);

	String strRunDown = FloatToStr(_dbRunDowntime);
	WideCharToMultiByte(0, 0, strRunDown.c_str(), -1, cRunDown, strRunDown.Length(), NULL, NULL);

	AnsiString prCount = nReadCommunicationDM(dailyInputCnt);

	try
	{
		char Savebuf[256] = {0,};
		sprintf(Savebuf, "insert into RunHistory (EventTime , RunTime , StopTime , AlarmTime, RundownTime, Count1 )  values ('%s','%s','%s','%s','%s', '%s');"
					,cTime, cRun, cStop , cError, cRunDown, prCount.c_str());
		SQLiteRunHistoryDB.execDML(Savebuf);

	}
	catch (CppSQLite3Exception& e)
	{
		cerr << e.errorCode() << ":" << e.errorMessage() << endl;
	}

	this->Resetrunningtime();
}
//---------------------------------------------------------------------------

void TMainForm::RejectData_Recording()
{
	char cTime[20] = {0,};
	char cData[100] = {0,};
	char cCode[20] = {0,};
	char cGroup[5] = {0,};
	char cRecipe[5] = {0,};


	String  StrRecipeIndex = IntToStr(nReadRecipeNo());
	String  StrGroupIndex = IntToStr(nReadGroupNo());

	WideCharToMultiByte(0, 0, StrRecipeIndex.c_str(), -1, cRecipe, StrRecipeIndex.Length(), NULL, NULL);
	WideCharToMultiByte(0, 0, StrGroupIndex.c_str(), -1, cGroup, StrGroupIndex.Length(), NULL, NULL);

	String StrLog;

	String strTime = Now().FormatString("yyyy-mm-dd hh:mm:ss");
	WideCharToMultiByte(0, 0, strTime.c_str(), -1, cTime, strTime.Length()+2, NULL, NULL);


	int nRowYCnt = dReadPkgData(trayYCnt);
	int nColXCnt = dReadPkgData(trayXCnt);

	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_REJECT_SORT;

	if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
	{
		for(int r=0; r<nRowYCnt; r++)
		{
			for(int c=0; c <nColXCnt;  c++)
			{
				int status = g_MMIComm->m_mmiToSeq.buffer.selMap[c][r];
                StrLog += IntToStr(status);
			}
		}
	}

	WideCharToMultiByte(0, 0, StrLog.c_str(), -1, cData, StrLog.Length(), NULL, NULL);

	String StrLotID;
	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_LOT_END_INFO;
    BOOL bRet = g_MMIComm->Send() &&  g_MMIComm->Recv();
    if (bRet)
    {
		LOT_INFO& info = g_MMIComm->m_mmiToSeq.buffer.lotInfoCopy;
        StrLotID = String(info.mergeLotID);//TYKIM check!
        if(StrLotID =="")
		{
			StrLotID = "NONE";
        }

	}
    WideCharToMultiByte(0, 0, StrLotID.c_str(), -1, cCode, StrLotID.Length(), NULL, NULL);

	try
	{
		char Savebuf[256] = {0,};
		sprintf(Savebuf, "insert into RejectData (EventTime , RejectUnit ,LotCode ,GroupIndex ,RecipeIndex)  values ('%s','%s','%s','%s','%s');",cTime , cData , cCode , cGroup , cRecipe);
		SQLiteRejectDB.execDML(Savebuf);

        nWriteCommunicationDM(3,logRejetTray);   //complete

	}
	catch (CppSQLite3Exception& e)
	{
		cerr << e.errorCode() << ":" << e.errorMessage() << endl;
	}
}
//---------------------------------------------------------------------------

void TMainForm::MachineResponseForSEQ()
{
	this->BarcodeTriggerComm();
	this->RfidComm();
	try
	{
		this->TCComm();
	}
	catch (Exception &e){}
	this->QCResultComm();
	this->OhtComm();
	this->LoadCellComm();
	this->TrayDataRead();
	this->SortTimeSave();
	this->RejectLogProcess();
	this->GemFeedBackProcess();
	this->BtmVisionDLComm();
}
//---------------------------------------------------------------------------

void TMainForm::QCResultComm()
{
	for (int i=0; i< 4; i++)
    {
		int state = nReadCommunicationDM( stage1QCStep + i );
		if (STATE_REQ == state)
		{
			nWriteCommunicationDM(STATE_BUSY, stage1QCStep+ i );	//busy
			this->MachineHistoryData("QC result activating ...");
			if (!frmQCResult->Showing)
			{
				frmQCResult->setStageIndex(i);
				if (mrOk == frmQCResult->ShowModal())
				{

				}
				nWriteCommunicationDM(STATE_COMP, stage1QCStep + i);	//success
			}
		}
		else if(STATE_BUSY == state)
		{
			if (!frmQCResult->Showing)
			{
				frmQCResult->setStageIndex(i);
				if (mrOk == frmQCResult->ShowModal())
				{

				}
				nWriteCommunicationDM(STATE_COMP, stage1QCStep + i);	//success
			}
		}
	}

	// Send to barcode id
	int state = nReadCommunicationDM( viSendToBarcode );
	if (STATE_REQ == state)
	{
		nWriteCommunicationDM(STATE_BUSY, viSendToBarcode);	//busy
		this->MachineHistoryData("QC Barcode activating ...");
		int nStageNum = nReadCommunicationDM( stageNum );

		g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_STG1_LOT_INFO+nStageNum;
		BOOL bRet = g_MMIComm->Send() && g_MMIComm->Recv();
		if (bRet)
		{
			LOT_INFO& info = g_MMIComm->m_mmiToSeq.buffer.lotInfo;

			String strBarcode = info.pcbBarcode;
			String strLotID = info.mergeLotID;
			String strPartID = info.partID;
			this->MachineHistoryData("PCB Barcode Data: "+strBarcode+", LotID: "+strLotID+", PartID: "+strPartID);

			if(FrmVisionSetUp->LotInfoSendToVision(AnsiString(strBarcode), AnsiString(strLotID), AnsiString(strPartID)))
				nWriteCommunicationDM(STATE_COMP, viSendToBarcode);	//success
			else
				nWriteCommunicationDM(STATE_ERR, viSendToBarcode);	//busy
		}
		else
			nWriteCommunicationDM(STATE_ERR, viSendToBarcode);	//busy
	}
}

void TMainForm::OhtComm()
{
	int state = nReadCommunicationDM(reqRecipeChange);
	if(STATE_REQ == state)
	{
		this->MachineHistoryData("Oht Mode : Auto Device Change activating...");
		nWriteCommunicationDM(STATE_BUSY, reqRecipeChange);	//  busy

		FormSecsGemSet->eventRecipeDownload(CMD_RD_BUFFER_LOTINFO);

		if(true == RecipeChangeForm->autoDeviceChange())
			nWriteCommunicationDM(STATE_COMP, reqRecipeChange);	//fail
		else
			nWriteCommunicationDM(STATE_ERR, reqRecipeChange);	//fail
	}
	else if(STATE_BUSY == state)
	{
		// vision check
	}

	state = nReadCommunicationDM(reqMgzInfoChgGood);
	if (STATE_REQ == state)
	{

		nWriteCommunicationDM(STATE_BUSY, reqMgzInfoChgGood);
		this->MachineHistoryData("GOOD CHANGE_MGZID activating Good...");

		int LOT_END_STEP_GD_COVER_COMP = 7;

		if(FormSecsGemSet->ChangeMgzID(false, CMD_RD_OHT_LOT_INFO, LOT_END_STEP_GD_COVER_COMP)==false)
		{
			nWriteCommunicationDM(STATE_ERR, reqMgzInfoChgGood);
		}
	}

	state = nReadCommunicationDM(reqMgzInfoChgReject);
	if (STATE_REQ == state)
	{
		nWriteCommunicationDM(STATE_BUSY, reqMgzInfoChgReject);
		this->MachineHistoryData("REJECT CHANGE_MGZID activating Reject...");

		int LOT_END_STEP_RJ_COVER_COMP = 8;

		if(FormSecsGemSet->ChangeMgzID(false, CMD_RD_OHT_LOT_INFO, LOT_END_STEP_RJ_COVER_COMP)==false)
		{
			nWriteCommunicationDM(STATE_ERR, reqMgzInfoChgReject);
		}
	}

	state = nReadCommunicationDM(reqMgzGdFcmr); 		// GOOD FCMR
	if(STATE_REQ == state)
	{
		this->MachineHistoryData("GOOD FCMR activating...");

		int FCMR_STEP_GD_COMP = 11;

		if(FormSecsGemSet->FullCarrierMoveReq(false,CMD_RD_OHT_LOT_INFO,FCMR_STEP_GD_COMP) == true)
		{
			nWriteCommunicationDM(STATE_COMP, reqMgzGdFcmr);
			this->MachineHistoryData("GOOD FCMR STATE COMP");
		}
	}

	state = nReadCommunicationDM(reqMgzRjFcmr); 		// REJECT FCMR
	if(STATE_REQ == state)
	{
		this->MachineHistoryData("REJECT FCMR activating...");

		int FCMR_STEP_RJ_COMP = 12;

		if(FormSecsGemSet->FullCarrierMoveReq(false,CMD_RD_OHT_LOT_INFO,FCMR_STEP_RJ_COMP) == true)
		{
			nWriteCommunicationDM(STATE_COMP, reqMgzRjFcmr);
			this->MachineHistoryData("REJECT FCMR STATE COMP");
		}
	}

	state = nReadCommunicationDM(reqTrayEcmr);			// Tray Empty Carrier Move Req
	if(STATE_REQ == state)
	{
	   this->MachineHistoryData("TRAY ECMR activating...");
	   nWriteCommunicationDM(STATE_BUSY,reqTrayEcmr);

	   if(FormSecsGemSet->EmptyCarrierMoveReq(false,CMD_RD_BUFFER_LOTINFO) == true)
	   {
			nWriteCommunicationDM(STATE_COMP,reqTrayEcmr);
			this->MachineHistoryData("TRAY ECMR STATE COMP !!");
	   }
	}

	state = nReadCommunicationDM(reqCoverEcmr);			// COVER Empty Carrier Move Req
	if(STATE_REQ == state)
	{
	   this->MachineHistoryData("COVER ECMR activating...");
	   nWriteCommunicationDM(STATE_BUSY,reqCoverEcmr);

	   if(FormSecsGemSet->EmptyCarrierMoveReq(false,CMD_RD_BUFFER_LOTINFO) == true)
	   {
			nWriteCommunicationDM(STATE_COMP,reqCoverEcmr);
			this->MachineHistoryData("COVER ECMR STATE COMP !!");
	   }
	}

}

void TMainForm::TrayDataRead()
{
	int state = 0;

	state = nReadCommunicationDM( scrLoadTrayDefaultData );
	if(STATE_COMP == state)
	{
		this->MachineHistoryData("Tray Data Save activating...");
		nWriteCommunicationDM(STATE_IDLE, scrLoadTrayDefaultData);

		frmTrayTeach->TrayCenter1stDataSave();
		frmTrayTeach->TrayCenter1stDataRead();
		frmTrayTeach->TrayPickupDataRead();
	}

	state = nReadCommunicationDM( updateRobotData );
	if(STATE_REQ == state)
	{
		this->MachineHistoryData("Update Staubli & Tray Offset Data Save activating...");
		nWriteCommunicationDM(STATE_IDLE, updateRobotData);

		if (FrmStaubliControl)	/// 화면 전환시 해당 폼이 NULL 이 되는데 접근하여 수정함
			FrmStaubliControl->_Staubli_ReverseSave();

		this->MachineHistoryData("Tray Offset Data Save activating...");
		g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_PKG;
		g_MMIComm->m_mmiToSeq.buffer.pkg.nStart = 0;
		g_MMIComm->m_mmiToSeq.buffer.pkg.nEnd = 999;
		BOOL bRet = g_MMIComm->Send() && g_MMIComm->Recv();
		if (!bRet)
		{
			this->MachineHistoryData("Fail to Tray Offset Data Save : seq to mmi communication");
			return;
		}

		double dNo2Data[12]={0.0f,};
		double dNo1Data[6]={0.0f,};

		int nStartNo  =  _pkg_START_NO2_;
		int nStartNo2 =  _pkg_TRAY_NO1_;
		int Tray1Chk = g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[trayXCnt];
		for(int i=0; i<4; i++)
		{
			if(Tray1Chk == 1) // Tray X Count 1 일때,
			{
				if((i == 0) || (i == 1))
				{
					dNo2Data[i] = g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[nStartNo2 + i];
					dNo2Data[i+4] = g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[nStartNo2 + i+4];
					dNo2Data[i+8] = g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[nStartNo2 + i+8];
				}
				else
				{
					dNo2Data[i] = g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[nStartNo + i];
					dNo2Data[i+4] = g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[nStartNo + i+4];
					dNo2Data[i+8] = g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[nStartNo + i+8];
				}
			}
			else
			{
				dNo2Data[i] = g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[nStartNo + i];
				dNo2Data[i+4] = g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[nStartNo + i+4];
				dNo2Data[i+8] = g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[nStartNo + i+8];
			}

			// 기존소스
		/*	dNo2Data[i] = g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[nStartNo + i];
			dNo2Data[i+4] = g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[nStartNo + i+4];
			dNo2Data[i+8] = g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[nStartNo + i+8];   */
		}
		nStartNo  =  _pkg_START_NO1_;
		for(int i=0; i<2; i++)
		{
			dNo1Data[i] = g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[nStartNo + i];
			dNo1Data[i+2] = g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[nStartNo + i+2];
			dNo1Data[i+4] = g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[nStartNo + i+4];
		}
		nStartNo  =  _pkg_START_NO2_;
		for(int i=0; i<4; i++)
		{
			if(Tray1Chk == 1) // Tray X Count 1 일때,
			{
				if((i == 0) || (i == 1))
				{
					WriteFloatPkgParamInifile(dNo2Data[i]   ,  nStartNo2 + i);
					WriteFloatPkgParamInifile(dNo2Data[i+4] ,  nStartNo2 + i + 4);
					WriteFloatPkgParamInifile(dNo2Data[i+8] ,  nStartNo2 + i + 8);
				}
				else
				{
					WriteFloatPkgParamInifile(dNo2Data[i]   ,  nStartNo + i);
					WriteFloatPkgParamInifile(dNo2Data[i+4] ,  nStartNo + i + 4);
					WriteFloatPkgParamInifile(dNo2Data[i+8] ,  nStartNo + i + 8);
				}
			}
			else
			{
				WriteFloatPkgParamInifile(dNo2Data[i]   ,  nStartNo + i);
				WriteFloatPkgParamInifile(dNo2Data[i+4] ,  nStartNo + i + 4);
				WriteFloatPkgParamInifile(dNo2Data[i+8] ,  nStartNo + i + 8);
			}

			// 기존소스
	   /*	WriteFloatPkgParamInifile(dNo2Data[i]   ,  nStartNo + i);
			WriteFloatPkgParamInifile(dNo2Data[i+4] ,  nStartNo + i + 4);
			WriteFloatPkgParamInifile(dNo2Data[i+8] ,  nStartNo + i + 8);    */
		}
		nStartNo  =  _pkg_START_NO1_;
		for(int i=0; i<2; i++)
		{
			WriteFloatPkgParamInifile(dNo1Data[i]   ,  nStartNo + i);
			WriteFloatPkgParamInifile(dNo1Data[i+2] ,  nStartNo + i + 2);
			WriteFloatPkgParamInifile(dNo1Data[i+4] ,  nStartNo + i + 4);
		}
		this->MachineHistoryData("Tray Offset Data Save End...");
	}
}

void TMainForm::SortTimeSave()
{
	int state = 0;
	state = nReadCommunicationDM(sortingTimeChg);
	if(state == STATE_REQ)
	{
		nWriteCommunicationDM(STATE_BUSY, sortingTimeChg);

		int index = nReadCommunicationDM(stageIndex);
		double dSortTime = dReadCommunicationDM(stage1SortTime+index);
		// add line
		AddLineToCSVFile(FloatToStr(dSortTime), index);

		nWriteCommunicationDM(STATE_IDLE, sortingTimeChg);
	}
}

void TMainForm::TCComm()
{
	// 0 : IDLE
	// 1 : REQ
	// 2:  BUSY
	// 3 : COMP
	// 4 : ERROR

	int state = 0;
	state = nReadCommunicationDM( seeLotStep );
	if (STATE_REQ == state)
	{
		nWriteCommunicationDM(STATE_BUSY, seeLotStep);
		FormSecsGemSet->GemLotInfo(0);
	}

	state = nReadCommunicationDM( scrapInfoStep );
	if (STATE_REQ == state)
	{


	}

	BOOL bRet = false;
	BOOL bLotEndPopUpSkip = bReadUseSkip(usAutoLotEnd);
	BOOL bLotEndReportComp = nReadCommunicationDM(autoLotEndComp);
	state = nReadCommunicationDM( lotEndStep );
	if (STATE_REQ == state)
	{
		_bSeeLotShow = false;
		nWriteCommunicationDM(STATE_BUSY, lotEndStep);	//busy
		this->MachineHistoryData("lot end activating...");

		FormSecsGemSet->_CompSeeLot = false;
		FormSecsGemSet->_CompScrapInfo = false;

		if(false == bLotEndPopUpSkip)
		{
			this->MachineHistoryData("Lot End Show 11111");
			_bSeeLotShow = true;
		}
		else
		{
			_LotEndRetryCnt = 0;
			m_ResTimeOut4LotEnd = 10;
			nWriteCommunicationDM(0, autoLotEndComp);
			bLotEndReportComp = false;
		}
	}
	else if(STATE_BUSY == state)
	{
		bool bCycle = true;

		if(_LotEndRetryCnt != 0)
		{
			if(_LotEndRetryCnt % m_ResTimeOut4LotEnd != 0)
				bCycle = false;
			if((_LotEndRetryCnt > (m_ResTimeOut4LotEnd*2)) && bLotEndReportComp == false)
			{
				_bSeeLotShow = true;
			}
		}

		if(bLotEndPopUpSkip == true && bCycle == true && bLotEndReportComp == false)
		{
			this->MachineHistoryData("Auto Lot End Start");
			if(FormSecsGemSet->_CompSeeLot == false && FormSecsGemSet->_CompScrapInfo == false)
			{
				AnsiString mergeLotID;
				g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_LOT_END_INFO;
				bRet = g_MMIComm->Send() &&  g_MMIComm->Recv();
				if (bRet)
				{
					LOT_INFO info = g_MMIComm->m_mmiToSeq.buffer.lotInfoCopy;
					mergeLotID = info.mergeLotID;    // Lot end 는 merge LOT ID 로

					FormSecsGemSet->GemLotInfo(1, mergeLotID);
					this->MachineHistoryData("_CompSeeLot = false / _CompScrapInfo = false");

					if(_LotEndRetryCnt > 0)
					{
						this->MachineHistoryData("Lot End Show 3");
					}
				}
			}
			else if(FormSecsGemSet->_CompSeeLot == true && FormSecsGemSet->_CompScrapInfo == false)
			{
				if(FormSecsGemSet->ScrapInfo(CMD_RD_SCRAP_INFO_CUR_COPY) == true)
				FormSecsGemSet->_CompScrapInfo = true;

				this->MachineHistoryData("_CompSeeLot = true / _CompScrapInfo = false");
				if(_LotEndRetryCnt > 0)
				{
					this->MachineHistoryData("Lot End Show 4");
					_LotEndRetryCnt = 0;
				}
			}
			else if(FormSecsGemSet->_CompSeeLot == true && FormSecsGemSet->_CompScrapInfo == true)
			{
				AnsiString mergeLotID;
				g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_LOT_END_INFO;

				bRet = g_MMIComm->Send() &&  g_MMIComm->Recv();
				if (bRet)
				{
					LOT_INFO info = g_MMIComm->m_mmiToSeq.buffer.lotInfoCopy;
					mergeLotID = info.mergeLotID;
					int nInputCnt  = nReadCommunicationDM(lotInputCntCopy);
					int nGoodCnt   = nReadCommunicationDM(lotGoodCntCopy);
					int nRejectCnt = nReadCommunicationDM(lotRejectCntCopy);
					int nOutPutCnt = nReadCommunicationDM(lotOutPutCntCopy);
					int nQty  	   = nReadCommunicationDM(serverPcbQty);
					int nScrapCnt  = nReadCommunicationDM(serverScrapCnt);

					MachineHistoryData("lot ended ! merge lotid: "+ mergeLotID + \
							", input cnt: " + IntToStr(nInputCnt) + \
							", good cnt: " + IntToStr(nGoodCnt) + \
							", reject cnt: " + IntToStr(nRejectCnt) + \
							", out cnt: " + IntToStr(nOutPutCnt) +
							", scrap cnt: " + IntToStr(nScrapCnt) +
							", server cnt: " + IntToStr(nQty));


					if((nQty != nOutPutCnt) || (nRejectCnt != nScrapCnt))
					{
						this->MachineHistoryData("fail to lot end : not equal Qty["+ IntToStr(nQty) +"] != OutPutCount["+ IntToStr(nOutPutCnt) +"]");
						nWriteCommunicationDM(5, lotEndStep);
						nWriteCommunicationDM(1, autoLotEndComp);
						this->MachineHistoryData("Lot End Show 5");
					}
					else
					{
						MachineHistoryData("Auto Lot End SEQ Equip RejectCnt : "+ IntToStr(nRejectCnt));
						MachineHistoryData("Auto Lot End SEQ Sever RejectCnt : "+ IntToStr(nScrapCnt));

						if(nRejectCnt == 0 && nScrapCnt == 0)
						{
							LOT_EVENT_DATA	data;
							::ZeroMemory(&data, sizeof(data));

							data.lotID = mergeLotID;
							data.inputCnt = nInputCnt;
							data.scrapCnt = nScrapCnt;
							data.goodCnt = nGoodCnt;
							data.rejectCnt = nRejectCnt;
							data.outputCnt = nOutPutCnt;

							frmLotDataHistory->Record_LotEnd(data);

							this->MachineHistoryData("Auto Lot End Comp");

							if(FormSecsGemSet->TrackOut() == true) 	// TRACK OUT 성공 시 다시 구문 안타게끔
							{
							   nWriteCommunicationDM(1, autoLotEndComp);
							}
							else
							{
							   this->MachineHistoryData("TRACK OUT FAIL!");
							}
						}
						else
						{
							LOT_EVENT_DATA	data;
							::ZeroMemory(&data, sizeof(data));

							data.lotID = mergeLotID;
							data.inputCnt = nInputCnt;
							data.scrapCnt = nScrapCnt;
							data.goodCnt = nGoodCnt;
							data.rejectCnt = nRejectCnt;
							data.outputCnt = nOutPutCnt;

							frmLotDataHistory->Record_LotEnd(data);

							this->MachineHistoryData("SCRAP Auto Lot End Comp");
							FormSecsGemSet->TrackOut();
						}

					}
				}
				else
				{
					nWriteCommunicationDM(5, lotEndStep);
					this->MachineHistoryData("Auto Lot End Fail / 1");
				}
			}
		}
		_LotEndRetryCnt++;
	}

	if(_bSeeLotShow)
	{
		_bSeeLotShow = false;
		if (!frmSeeLot->Showing)
		{
			if(FormSecsGemSet->m_fStart)
			{
				MainForm->MachineHistoryData("lot showing :::::::::::::::::::::");

				MainForm->MachineHistoryData("lotEndStep : "+ IntToStr(state));

				frmSeeLot->setMode();
				frmSeeLot->ShowModal();
			}
			else
			{
				nWriteCommunicationDM(5, lotEndStep);

				FrmCdBox->setFlag(CD_OK);
				FrmCdBox->setTitle( "SEE LOT" );
				FrmCdBox->setText( "Fail to try SeeLot. GEM is not connected!" );
				FrmCdBox->ShowModal();
			}
		}
	}

	INT pkgRowYCnt = dReadPkgData(pcbYCnt);
	INT pkgColXCnt = dReadPkgData(pcbXCnt);

	for (int i=0; i< 4; i++)
	{
		state = nReadCommunicationDM( onlineEndStep1 + i );
		if (1 == state)
		{
			nWriteCommunicationDM(2, onlineEndStep1+i);	//busy
			this->MachineHistoryData("online end activating : index [" + IntToStr(i+1)+ "]");
			g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_STG1_LOT_INFO+i;
			BOOL bRet = g_MMIComm->Send() &&  g_MMIComm->Recv();
			if (!bRet)
			{
				nWriteCommunicationDM(4, onlineEndStep1+i);	//fail
				this->MachineHistoryData("Online End(activating) Fail = " + IntToStr(onlineEndStep1+i));
				continue;
			}
			LOT_INFO info = g_MMIComm->m_mmiToSeq.buffer.lotInfo;

			int scrapCnt = 0;
			for (int j=0; j<pkgRowYCnt * pkgColXCnt; j++)
			{
				switch (info.pcbTestResult[j] )
				{
				case '1':
				case 'X':
				case 'x':
				//case 'A':
					break;
				case NULL:
				{
					this->MachineHistoryData("Online End(activating) Fail(NULL) = " + IntToStr(onlineEndStep1+i));
					int errcodes = 231;
					String seq_msg="";
					TIniFile* DetailAlarmini = new TIniFile(ExtractFilePath(Application->ExeName)+ "Ini\\Alarm.ini");
					if(errcodes > 0)
					{
						seq_msg = "["+IntToStr(errcodes)+"]"+ DetailAlarmini->ReadString("NAME","NAME"+IntToStr(errcodes),"NAME"+IntToStr(errcodes));
						MachineHistoryData("SEQ Error detected : " + seq_msg);
						bool bTemp = DetailAlarmini->ReadBool("CHECK","CHECK"+IntToStr(errcodes),true);
						this->Alarm_Recording(errcodes , bTemp ? 1 : 2);

						if(Application->ModalLevel < 1)	FrmAlarmDetailList->AlarmDetail_Initialize(true);
					}
					delete DetailAlarmini;
					break;
				}
				default:    	// 그 이외것들
					scrapCnt++;
					break;
				}
			}

	   /*	if (scrapCnt == 0)
			{
				//this->MachineHistoryData("online end but all good so deactivated");
				nWriteCommunicationDM(3, onlineEndStep1+i);	//success
				continue;
			}          */

			nWriteCommunicationDM(3, onlineEndStep1+i);

			this->MachineHistoryData("online ending with scrap cnt = " + IntToStr(scrapCnt));

			// FUNCTION=ONLINE_END
			// EQPID=AROUT-X02 EQPMODEL=ROUTER_SORTER AUTOLINE=NO LOTID=X007B00508 OPERID=AUTO
			// SCRAP_CNT=8
			// SCRAP_INFO001=(SCRAP_CODE=3417 ARRAYSN=2MX16D003301MZVLVXXXXA039IXXXXXX_1 SERIAL=)
			// SCRAP_INFO002=(SCRAP_CODE=3417 ARRAYSN=2MX16D003301MZVLVXXXXA039IXXXXXX_2 SERIAL=)
			// SCRAP_INFO003=(SCRAP_CODE=3417 ARRAYSN=2MX16D003301MZVLVXXXXA039IXXXXXX_3 SERIAL=)
			// SCRAP_INFO004=(SCRAP_CODE=3417 ARRAYSN=2MX16D003301MZVLVXXXXA039IXXXXXX_4 SERIAL=)
			// SCRAP_INFO005=(SCRAP_CODE=3417 ARRAYSN=2MX16D003301MZVLVXXXXA039IXXXXXX_5 SERIAL=)
			// SCRAP_INFO006=(SCRAP_CODE=3417 ARRAYSN=2MX16D003301MZVLVXXXXA039IXXXXXX_6 SERIAL=)
			// SCRAP_INFO007=(SCRAP_CODE=3417 ARRAYSN=2MX16D003301MZVLVXXXXA039IXXXXXX_7 SERIAL=)
			// SCRAP_INFO008=(SCRAP_CODE=3417 ARRAYSN=2MX16D003301MZVLVXXXXA039IXXXXXX_8 SERIAL=)
//			AnsiString params[16];
//			params[0] = _eqpID;
//			params[1] = IntToStr(scrapCnt);
//			params[2] = "ROUTER_SORTER";//eqp model
//			params[3] = "NO";	//autoline
//			params[4] = g_MMIComm->m_mmiToSeq.buffer.lotInfo.mergeLotID;   //online end 는 lot id 로
//			params[5] = "AUTO";//operid
//
//			int paramIndex = 6;
//
//			for (int j=0; j<pkgRowYCnt * pkgColXCnt; j++)  	// 패키지 파라메터의 유닛 개수만큼실행
//			{
//				switch (g_MMIComm->m_mmiToSeq.buffer.lotInfo.pcbTestResult[j])
//				{
//				case '1':
//				case 'X':
//				case 'x':
//					break;
//				default:
//					{   // 그 이외것들
//						//SCRAP_CODE=3417 ARRAYSN=2MX16D003301MZVLVXXXXA039IXXXXXX_1 SERIAL=
//						int nScrapCode = StrToInt(g_MMIComm->m_mmiToSeq.buffer.lotInfo.scrapCode[j]);
//
//						 params[paramIndex++] =  \
//							AnsiString("SCRAP_CODE=") + \
//							IntToStr(nScrapCode) + \
//							AnsiString(" ARRAYSN=") + \
//							g_MMIComm->m_mmiToSeq.buffer.lotInfo.scrapArraySN[j] + \
//							AnsiString(" SERIAL=") + \
//							g_MMIComm->m_mmiToSeq.buffer.lotInfo.scrapSerial[j];
//						break;
//					}
//				}
//			}

			_onlineEndIndex = i;
			//bRet = frmTCComm->ohtOnlineEnd(params);

			String sScrap4Add = "";
			String scrapCode, scrapArraySN, scrapSerial;
			for (int j=0; j<pkgRowYCnt * pkgColXCnt; j++)  	// 패키지 파라메터의 유닛 개수만큼실행
			{
				switch (info.pcbTestResult[j])
				{
				case '1':
				case 'X':
				case 'x':
				//case 'A':
					break;
				default:
					{
						// AddScrap이 2개 이상일 경우, '콤마'가 없어서 서버에서 Parsing 불가현상 발생으로
						// 밑에 '콤마' 추가후 Parsing 확인 완료
						if(sScrap4Add != "") sScrap4Add += ",";

						// 그 이외것들
						//3305:1M393A4K40BB2CTD7YXXXA054FXXX001_1,3404:1M393A4K40BB2CTD7YXXXA054FXXX001_2

						scrapCode = info.scrapCode[j];
						scrapArraySN = info.scrapArraySN[j];
						scrapSerial = info.scrapSerial[j];
						sScrap4Add += String().sprintf(L"%s:%s",scrapCode,scrapArraySN);
						if(scrapSerial != "")
						{
							sScrap4Add += String().sprintf(L":%s",scrapSerial);
						}
					}
					break;
				}
			}
			MainForm->MachineHistoryData("AddScrap Scrap Count Check : " + IntToStr(scrapCnt));
			MainForm->MachineHistoryData("AddScrap Scrap List Check : " + sScrap4Add);
			bRet = FormSecsGemSet->AddScrap(CMD_RD_STG1_LOT_INFO+i, scrapCnt, sScrap4Add);

			if (!bRet)
				nWriteCommunicationDM(4, onlineEndStep1+i);	//fail

		} //online step end
	}
}

void __fastcall TMainForm::FunctionButtonControl(int nIndex)
{
	switch(nIndex)
	{
		case FUNCTION_BTN1 :        //HOME
		{
			if(!CheckCanDataAccess()) return;
			//if(!CheckCanAccessLevel(PW_MAINTENANCE)) return;

			FrmCdBox->setFlag(CD_YESNO);
			FrmCdBox->setTitle("Manual Operate");
			FrmCdBox->setText("Execute Running?");
			if (mrYes == FrmCdBox->ShowModal())
			{
				WriteCommNDM(screenTenkey, 99);
			}
		}
		break;

		case FUNCTION_BTN2 :    //   RFID
		{
			if(!CheckCanDataAccess()) return;
			//if(!CheckCanAccessLevel(PW_MAINTENANCE)) return;
			//FrmLotComm->ShowModal();
			frmBarcode->ShowModal();
		}
		break;

		case FUNCTION_BTN3 :    //    USESKIP
		{
			//if(!CheckCanDataAccess()) return;
			//if(!CheckCanAccessLevel(PW_MAINTENANCE)) return;

			FrmUseSkip->ShowModal();
		}
		break;

		case FUNCTION_BTN4 :    //  RECIPECHANGE
		{
			//if(!CheckCanDataAccess()) return;
			if(!CheckCanAccessLevel(PW_MAINTENANCE)) return;
			this->ScreenChange("RECIPE");
		}
			break;

		case FUNCTION_BTN5 :    //  USER PARAM
		{
			//if(!CheckCanDataAccess()) return;
			if(!CheckCanAccessLevel(PW_MAINTENANCE)) return;
			FrmUserParameter->ShowModal();
		}
		break;

		case FUNCTION_BTN6 :    //  DEFAULT
		{
			FrmLoadCell->ShowModal();
		}
			break;

		case FUNCTION_BTN7 :	// MANUAL RUN
		{
			//if(!CheckCanDataAccess()) return;
			if(!CheckCanAccessLevel(PW_MAINTENANCE)) return;

			this->ScreenChange("SYSTEM");
			SystemForm->ScreenChange("MANUAL RUN");
		}
			break;


		case FUNCTION_BTN8 :    //  DEFAULT
		{
			FrmRouterComm->ShowModal();
		}
			break;

		case FUNCTION_BTN9 :    //  RFID
		{
			//if(!CheckCanDataAccess()) return;
			frmRFID->ShowModal();
        }
			break;

		case FUNCTION_BTN10 :    // DEFAULT
		{
			FrmVisionSetUp->ShowModal();
			if(!FrmVisionSetUp->Showing)
				FrmVisionSetUp->vCutProcessStateChange("Init");
		}
			break;

		case FUNCTION_BTN11 :    //   DEFAULT

			break;

		case FUNCTION_BTN12 :    // DEFAULT
		{
			FormSecsGemSet->ShowModal();
		}
			break;

		default :

		break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FunctionButtonClick(TObject *Sender)
{
	FunctionButtonControl(dynamic_cast<TBitBtn *>(Sender)->Tag);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::LabelAlarmShowClick(TObject *Sender)
{
	FrmAlarmDetailList->AlarmDetail_Initialize(true);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::LabelWarningShowClick(TObject *Sender)
{
	FrmAlarmDetailList->AlarmDetail_Initialize(false);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::HistoryResetTimerTimer(TObject *Sender)
{
//    if(_bDayResetchk_ ==  false)
//	{
//		TTime CompareTime;
//		CompareTime = Time().FormatString("22:00:00");
//
//		double dbChkVal = HoursBetween(Time(), CompareTime);
//
//		if(dbChkVal == 0)
//		{
//			_bDayResetchk_ = true;
//			this->DailyHistory_Recording();
//			Resetrunningtime();
//		}
//	}
//	else
//	{
//		TTime CompareResetTime;
//		CompareResetTime = Now().FormatString("03:00:00");
//		double dbChkVal = HoursBetween( Time() , CompareResetTime);
//		if(dbChkVal == 0)
//		{
//			_bDayResetchk_ = false;
//		}
//	}

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MCrunSaveTimerTimer(TObject *Sender)
{
	switch( nReadCommunicationDM(mcState))
	{
		case STATUS_STOP :
        {
			_dbStoptime++;
        }
		break;

		case STATUS_AUTO :
		{
			_dbRuntime++;
		}
		break;

		case STATUS_RUN:
        {
			_dbStoptime++;
		}
        break;

		case STATUS_RUNDOWN:
        {
//			_dbStoptime++;
			_dbRunDowntime++;
		}
        break;

		case STATUS_ERROR :
        {
			_dbErrtime++;
        }
		break;

		case STATUS_EMG :
        {
			_dbErrtime++;
        }
        break;

        default :
        {

        }
        break;
    }

    _dbbufferTime++;
}
//---------------------------------------------------------------------------

void TMainForm::BarcodeTriggerComm()
{
	// test용 코드
    int static adcBcdTick = 0;

	int value = nReadCommunicationDM(readBarcodeStep);
    if(value == 1)
    {
		nWriteCommunicationDM(2, readBarcodeStep);
		g_barcode[BCD_ADC]->clear();
    	MachineHistoryData("ADC Barcode activating ...");
    	if (true != g_barcode[BCD_ADC]->trigger(true))
        {
        	nWriteCommunicationDM(4, readBarcodeStep);	//fail
            MachineHistoryData("ADC Barcode trigger fail");
            g_barcode[BCD_ADC]->trigger(false);
            adcBcdTick = 0;
        }
    }

    else if(value == 2)
    {
        if (g_barcode[BCD_ADC]->isRecv())
        {
        	// 이름 비교
            adcBcdTick = 0;
            String strData = g_barcode[BCD_ADC]->getRecvData();
//            g_barcode[BCD_ADC]->trigger(false);
            strData = strData.Trim();

            int targetADCIndex = nReadCommunicationDM( 301 );
            TIniFile* ini = new TIniFile(ExtractFilePath(Application->ExeName)+"adc.ini");
            String strBarcode = ini->ReadString("ADC", "BARCODE"+IntToStr(targetADCIndex), "" );
            strBarcode = strBarcode.Trim();
            delete ini;

			// 끝자리 한글자만 뺀다
			//if (strData.Length() >0)
			//	strData = strData.SubString( 0, strData.Length() - 1);
			//5자리만 비교
			strData = strData.SubString( 1, 5);

            if ( 0 == strData.CompareIC(strBarcode))
            {
        		nWriteCommunicationDM(3, readBarcodeStep);	//success
                MachineHistoryData("ADC Barcode : " + strData );
            }
            else
            {
             	nWriteCommunicationDM(4, readBarcodeStep);	//fail
                MachineHistoryData("Mismatched ADC Barcode : " + strBarcode + " / " + strData  );
            }
        }
        else
        {
            if (adcBcdTick > 8)	//4s
            {
                g_barcode[BCD_ADC]->trigger(false);
                nWriteCommunicationDM(4, readBarcodeStep);	//fail
                MachineHistoryData("ADC Barcode read timeover !");
                adcBcdTick = 0;
            }
            adcBcdTick++;
        }
     	nWriteCommunicationDM(3, readBarcodeStep);
    }
}
//---------------------------------------------------------------------------

void TMainForm::RfidComm()
{
	// Lot End 이후에 RFID read/Write 를 진행한다.
	// RFID Write Good Cover
	int nState = nReadCommunicationDM(reqWriteCoverGoodRfid);
	if(nState == STATE_REQ)
	{
		MainLog("[SEQ->MMI] RFID write good cover start ...");
		nWriteCommunicationDM(STATE_BUSY, reqWriteCoverGoodRfid);

		g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_OHT_LOT_INFO;
		if (g_MMIComm->Send() && g_MMIComm->Recv())
		{
			LOT_INFO& info = g_MMIComm->m_mmiToSeq.buffer.lotInfoCopy;
			if (false == g_rfid->write(0, AnsiString(FormSecsGemSet->GetNextStep()), info.mergeLotID, info.partID, info.lotQty,true))
				nWriteCommunicationDM(STATE_ERR, reqWriteCoverGoodRfid);

			frmSeeLot->writeRfidData(String(info.mergeLotID), String(info.partID));
		}
		else
		{
			MainLog("SEQ <-> MMI communication failure : RFID write good cover start");
			nWriteCommunicationDM(STATE_ERR, reqWriteCoverGoodRfid);
		}
	}
	else if (nState == STATE_BUSY)
	{
		static int rfidWriteGoodCoverTikcCnt = 0;
		if (!g_rfid->isWrite())
		{
			rfidWriteGoodCoverTikcCnt++;
			if(rfidWriteGoodCoverTikcCnt > 8) //4sec
			{
				rfidWriteGoodCoverTikcCnt = 0;
				nWriteCommunicationDM(STATE_ERR, reqWriteCoverGoodRfid);
				MainLog("RFID write good cover timeout !");
			}
		}
		else
		{
			rfidWriteGoodCoverTikcCnt = 0;

			nWriteCommunicationDM(STATE_COMP, reqWriteCoverGoodRfid);
			MainLog("RFID write good cover comp !");
		}
	}

	// RFID Read Good Cover
	nState = nReadCommunicationDM(reqReadCoverGoodRfid);
	if(nState == STATE_REQ)
	{
		MainLog("[SEQ->MMI] RFID read good cover start ...");
		nWriteCommunicationDM(STATE_BUSY, reqReadCoverGoodRfid);
		if (false == g_rfid->read(0))
			nWriteCommunicationDM(STATE_ERR, reqReadCoverGoodRfid);
	}
	else if (nState == STATE_BUSY)
	{
		static int rfidReadGoodCoverTikcCnt = 0;
		if (!g_rfid->isRecv())
		{
			rfidReadGoodCoverTikcCnt++;
			if(rfidReadGoodCoverTikcCnt > 8)//4sec
			{
				rfidReadGoodCoverTikcCnt = 0;
				nWriteCommunicationDM(STATE_ERR, reqReadCoverGoodRfid);
				MainLog("RFID read good cover timeout !");
			}
		}
		else
		{
			rfidReadGoodCoverTikcCnt = 0;
			RFID_DATA rfid = g_rfid->get_data();

			MainLog("RFID good cover Carrier ID : "  + rfid.carrierID);
			MainLog("RFID good cover Qty        : "  + rfid.qty);
			MainLog("RFID good cover Lot ID     : "  + rfid.lotID);
			MainLog("RFID good cover Step       : "  + rfid.step);
			MainLog("RFID good cover Part No    : "  + rfid.partNo);

			frmSeeLot->readRfidData(rfid);

			g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_OHT_LOT_INFO;
			if (g_MMIComm->Send() && g_MMIComm->Recv())
			{
				LOT_INFO& info = g_MMIComm->m_mmiToSeq.buffer.lotInfoCopy;

				bool bComp  = (0 == AnsiStrComp(info.mergeLotID, AnsiString(rfid.lotID).c_str()));
					 bComp &= (0 == AnsiStrComp(info.partID, AnsiString(rfid.partNo).c_str()));

				if (bComp)
				{
					g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_OHT_LOT_INFO;
					strcpy(info.carrierID, AnsiString(rfid.carrierID).c_str());

					if (g_MMIComm->Send() && g_MMIComm->Recv())
					{
						//FormSecsGemSet->GemRFIDRead();	// 비활성화
						MainLog("RFID read good cover comp !");
						nWriteCommunicationDM(STATE_COMP, reqReadCoverGoodRfid);
						MainLog("reqReadCoverGoodRfid State_COMP 3 !");
					}
					else
					{
						MainLog("RFID read good cover fail : write data is different");
						nWriteCommunicationDM(STATE_ERR, reqReadCoverGoodRfid);
					}
				}
				else
				{
					MainLog("RFID read good cover fail : write data is different");
					nWriteCommunicationDM(STATE_ERR, reqReadCoverGoodRfid);
				}
			}
			else
			{
				MainLog("SEQ <-> MMI communication failure : RFID read good cover start");
				nWriteCommunicationDM(STATE_ERR, reqReadCoverGoodRfid);
			}
		}
	}

	// RFID Write Reject Cover
	nState = nReadCommunicationDM(reqWriteCoverRejectRfid);
	if(nState == STATE_REQ)
	{
		MainLog("[SEQ->MMI] RFID write reject cover start ...");
		nWriteCommunicationDM(STATE_BUSY, reqWriteCoverRejectRfid);

		g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_OHT_LOT_INFO;
		if (g_MMIComm->Send() && g_MMIComm->Recv())
		{
			LOT_INFO& info = g_MMIComm->m_mmiToSeq.buffer.lotInfoCopy;
			int scrapCnt = nReadCommunicationDM(serverScrapCnt);
			if (false == g_rfid->write(0, AnsiString(FormSecsGemSet->GetNextStep()), info.rejectLotID, info.partID, AnsiString(IntToStr(scrapCnt)),true))
				nWriteCommunicationDM(STATE_ERR, reqWriteCoverRejectRfid);

			frmSeeLot->writeRfidData(String(info.rejectLotID), String(info.partID));
		}
		else
		{
			MainLog("SEQ <-> MMI communication failure : RFID write reject cover start");
			nWriteCommunicationDM(STATE_ERR, reqWriteCoverRejectRfid);
		}
	}
	else if (nState == STATE_BUSY)
	{
		static int rfidWriteRejectCoverTikcCnt = 0;
		if (!g_rfid->isWrite())
		{
			rfidWriteRejectCoverTikcCnt++;
			if(rfidWriteRejectCoverTikcCnt > 8) //4sec
			{
				rfidWriteRejectCoverTikcCnt = 0;
				nWriteCommunicationDM(STATE_ERR, reqWriteCoverRejectRfid);
				MainLog("RFID write reject cover timeout !");
			}
		}
		else
		{
			rfidWriteRejectCoverTikcCnt = 0;

			nWriteCommunicationDM(STATE_COMP, reqWriteCoverRejectRfid);
			MainLog("RFID write reject cover comp !");
		}
	}

	// RFID Read Reject Cover
	nState = nReadCommunicationDM(reqReadCoverRejectRfid);
	if(nState == STATE_REQ)
	{
		MainLog("[SEQ->MMI] RFID read reject cover start ...");
		nWriteCommunicationDM(STATE_BUSY, reqReadCoverRejectRfid);
		if (false == g_rfid->read(0))
			nWriteCommunicationDM(STATE_ERR, reqReadCoverRejectRfid);
	}
	else if (nState == STATE_BUSY)
	{
		static int rfidReadRejectCoverTikcCnt = 0;
		if (!g_rfid->isRecv())
		{
			rfidReadRejectCoverTikcCnt++;
			if(rfidReadRejectCoverTikcCnt > 8)//4sec
			{
				rfidReadRejectCoverTikcCnt = 0;
				nWriteCommunicationDM(STATE_ERR, reqReadCoverRejectRfid);
				MainLog("RFID read reject cover timeout !");
			}
		}
		else
		{
			rfidReadRejectCoverTikcCnt = 0;
			RFID_DATA rfid = g_rfid->get_data();

			MainLog("RFID reject cover Carrier ID : "  + rfid.carrierID);
			MainLog("RFID reject cover Qty        : "  + rfid.qty);
			MainLog("RFID reject cover Lot ID     : "  + rfid.lotID);
			MainLog("RFID reject cover Step       : "  + rfid.step);
			MainLog("RFID reject cover Part No    : "  + rfid.partNo);

			frmSeeLot->readRfidData(rfid);

			g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_OHT_LOT_INFO;
			if (g_MMIComm->Send() && g_MMIComm->Recv())
			{
				LOT_INFO& info = g_MMIComm->m_mmiToSeq.buffer.lotInfoCopy;

				bool bComp = (0 == AnsiStrComp(info.rejectLotID, AnsiString(rfid.lotID).c_str()));

				if (bComp)
				{
					g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_OHT_LOT_INFO;
					strcpy(info.rejectCarrierID, AnsiString(rfid.carrierID).c_str());
					strcpy(info.rejectLotID, AnsiString(rfid.lotID).c_str());

					if (g_MMIComm->Send() && g_MMIComm->Recv())
					{
						MainLog("RFID read reject cover comp !");
						nWriteCommunicationDM(STATE_COMP, reqReadCoverRejectRfid);
						MainLog("reqReadCoverRejectRfid State_COMP 3 !");
					}
					else
					{
						MainLog("RFID read reject cover fail : write data is different");
						nWriteCommunicationDM(STATE_ERR, reqReadCoverRejectRfid);
					}
				}
				else
				{
					MainLog("RFID read reject cover fail : write data is different");
					nWriteCommunicationDM(STATE_ERR, reqReadCoverRejectRfid);
				}
			}
			else
			{
				MainLog("SEQ <-> MMI communication failure : RFID read reject cover start");
				nWriteCommunicationDM(STATE_ERR, reqReadCoverRejectRfid);
			}
		}
	}
}
//---------------------------------------------------------------------------

void TMainForm::LoadCellComm()
{
	int nWeightState = 0, nZeroSetState =0;
	nWeightState = nReadCommunicationDM(reqReadLoadCell);
	nZeroSetState = nReadCommunicationDM(reqLoadCellZero);

	if(nWeightState == STATE_REQ)
	{
		_nLoadCellRetryCnt = 0;
		nWriteCommunicationDM(STATE_BUSY ,reqReadLoadCell);  //feedback   //
		FrmLoadCell->_bCmdType = _RevWeight_;
		FrmLoadCell->ReadLoadCellCommand() ;
		MainLog("LOAD CELL Send Command!");
	}
	if(nWeightState == STATE_BUSY)
	{
		_nLoadCellRetryCnt++;
		if(_nLoadCellRetryCnt > 6)
		{
			nWriteCommunicationDM(STATE_ERR, reqReadLoadCell);
		}
		else if(_nLoadCellRetryCnt%2 == 0)
		{

			FrmLoadCell->_bCmdType = _RevWeight_;
			FrmLoadCell->ReadLoadCellCommand() ;
			MainLog("LOAD CELL Send Command Retry:"+_nLoadCellRetryCnt%2);
		}
	}

	if(nZeroSetState == STATE_REQ)
	{
		nWriteCommunicationDM(STATE_BUSY ,reqLoadCellZero);  //feedback   //
		FrmLoadCell->_bCmdType = _ZeroSet_;
		FrmLoadCell->ZeroCellCommand() ;
		MainLog("LOAD CELL ZERO Command!");
	}
	// 항시 Data 읽어오도록 변경.
	if(nWeightState == STATE_IDLE && nZeroSetState == STATE_IDLE)
	{
		if(FrmLoadCell->isConnected()  == true)
		{
			if(FrmLoadCell->_bLoadComp == true)
			{
				FrmLoadCell->_bCmdType = _RevWeight_;
				FrmLoadCell->_bLoadComp = false;
				FrmLoadCell->ReadLoadCellCommand();
			}
		}
	}
}

//---------------------------------------------------------------------------
void TMainForm::RejectLogProcess()
{
 //리젝트레이 로그 남기는 부분
	if(1 == nReadCommunicationDM(logRejetTray))
	{
		nWriteCommunicationDM(2,logRejetTray);   //busy

		RejectData_Recording();

		MainLog("REJECT DATA Recording Command!");
	}
}
//---------------------------------------------------------------------------
void	TMainForm::reqMsgNotice()
{
	int notice_state = nReadCommunicationDM(MSGNOTICE_SEQ2MMI);

	//CMD NO
	if(notice_state>=10)
	{
		MsgNotice _msg;

		if(bReadMsgNotice(&_msg))
		{

			if(!frmPopupNotice->Showing)
			{
				//LOG(_T("popup notice msg Show by Seq"));
				//frmPopupNotice->setCompSignal(HYDRA_CMD_NDM,MSGNOTICE_MMI2SEQ);
				frmPopupNotice->setText(String(_msg.strMsgTtile).Trim());
				frmPopupNotice->setButton(String(_msg.strBtn[0]).Trim(),String(_msg.strBtn[1]).Trim(),String(_msg.strBtn[2]).Trim(),String(_msg.strBtn[3]).Trim());
				int nShowing = 1;
				//c.pHydra->write(HYDRA_CMD_NDM,&nShowing,MSGNOTICE_MMI2SEQ);
				nWriteCommunicationDM(nShowing,MSGNOTICE_MMI2SEQ);
				frmPopupNotice->ShowModal();
			}              //Notice 메세지 테스트시 잠시 막아두기
		}
	}
	else if(notice_state==1 || notice_state == 0)
	{
		if(frmPopupNotice->Showing)
		{
			//LOG(_T("popup notice msg close by Seq"));
			frmPopupNotice->Close();
		}
	}

}
//---------------------------------------------------------------------------
//// EXAMPLE
#define    _CLEANING_STAGE_IN_   	    500
#define    _CLEANING_STAGE_OUT_       	504
#define    _TB_CLEANING_START_        	508
#define    _TB_CLEANING_END_          	512
#define    _QCVISION_START_             516
#define    _QCVISION_END_    		    520
#define	   _DUMMY_PCB_REMOVE_		    524
#define	   _FLIP_PCB_START_			    528
#define	   _FLIP_PCB_END_			    532
#define	   _TOP_PRS_START_			    536
#define	   _TOP_PRS_END_			    540
#define	   _BTM_PRS_START_			    544
#define	   _BTM_PRS_END_			    548
#define	   _TRAY_SORTING_START_		    552
#define	   _TRAY_SORTING_END_		    556

#define	   _GOOD_TRAY_STACK_START_	    560
#define	   _GOOD_TRAY_STACK_END_	    561
#define	   _REJECT_TRAY_STACK_START_	562
#define	   _REJECT_TRAY_STACK_END_		563

#define    _TRACK_IN_					564
#define    _TRACK_OUT_					565

#define	   _TRACE_INFO_MC_STATUS_		570
#define	   _TRACE_INFO_STAGE_1_			571
#define	   _TRACE_INFO_STAGE_2_			572
#define	   _TRACE_INFO_STAGE_3_			573
#define	   _TRACE_INFO_STAGE_4_			574


#define	   _CMD_GOOD_TRAY_INDEX_		580
#define	   _CMD_STAGE_INDEX_			581

#define	   _PCB_IN_						584

#define	   _MAX_STAGE_COUNT_			4


void TMainForm::GemFeedBackProcess()  //'GEM
{
	if(FormSecsGemSet->m_fStart == false)
	{   // 500 ~ 565번까지
		for(int i=_CLEANING_STAGE_IN_; i<_TRACK_IN_+1; i++)
		{
			if(STATE_REQ == nReadCommunicationDM(i))
				nWriteCommunicationDM(STATE_IDLE, i);
		}
		for(int i=_TRACE_INFO_MC_STATUS_; i<_TRACE_INFO_STAGE_4_+1; i++)
		{
			if(STATE_REQ == nReadCommunicationDM(i))
				nWriteCommunicationDM(STATE_IDLE, i);
		}
	}
	else
	{
		/* RMS 하면서 정리. 나머진 안씀. mjk
		_TRACK_IN_					564
		_TRACK_OUT_					565
		_GOOD_TRAY_STACK_END_		561
		_REJECT_TRAY_STACK_END_		563

		각 4 Stage
		_TB_CLEANING_END_          	512
		_QCVISION_END_				520
		_FLIP_PCB_END_			    532
		_TOP_PRS_END_			    540
		_BTM_PRS_END_			    548
		_TRAY_SORTING_START_		552
		_TRAY_SORTING_END_		    556
		_PCB_IN_					584
		*/
		for(int Index=0; Index<_MAX_STAGE_COUNT_; Index++)
		{
			//FormSecsGemSet->GemDataValueStage_Refresh(_DUMMY_PCB_REMOVE_+Index);
			//FormSecsGemSet->GemDataValueStage_Refresh(_CLEANING_STAGE_IN_+Index);
			//FormSecsGemSet->GemDataValueStage_Refresh(_TB_CLEANING_START_+Index);
			//FormSecsGemSet->GemDataValueStage_Refresh(_QCVISION_START_+Index);
			//FormSecsGemSet->GemDataValueStage_Refresh(_FLIP_PCB_START_+Index);
			//FormSecsGemSet->GemDataValueStage_Refresh(_TOP_PRS_START_+Index);
			//FormSecsGemSet->GemDataValueStage_Refresh(_BTM_PRS_START_+Index);
			FormSecsGemSet->GemDataValueStage_Refresh(_TRAY_SORTING_START_+Index);	//9007

			FormSecsGemSet->GemDataValueStage_Refresh(_PCB_IN_+Index);	//9001
			//FormSecsGemSet->GemDataValueStage_Refresh(_CLEANING_STAGE_OUT_+Index);
			FormSecsGemSet->GemDataValueStage_Refresh(_TB_CLEANING_END_+Index);	//9002
			FormSecsGemSet->GemDataValueStage_Refresh(_QCVISION_END_+Index);	//9003
			FormSecsGemSet->GemDataValueStage_Refresh(_FLIP_PCB_END_+Index);	//9004
			FormSecsGemSet->GemDataValueStage_Refresh(_TOP_PRS_END_+Index);	//9005
			FormSecsGemSet->GemDataValueStage_Refresh(_BTM_PRS_END_+Index);	//9006
			FormSecsGemSet->GemDataValueStage_Refresh(_TRAY_SORTING_END_+Index);	//9008

			FormSecsGemSet->GemDataTraceStage_Refresh(_TRACE_INFO_STAGE_1_+Index);
		}

		//FormSecsGemSet->GemDataValueTray_Refresh(_GOOD_TRAY_STACK_START_);
		FormSecsGemSet->GemDataValueTray_Refresh(_GOOD_TRAY_STACK_END_);	//9009
		//FormSecsGemSet->GemDataValueTray_Refresh(_REJECT_TRAY_STACK_START_);
		FormSecsGemSet->GemDataValueTray_Refresh(_REJECT_TRAY_STACK_END_);	//9010
		FormSecsGemSet->GemDataValueTray_Refresh(_TRACK_IN_);	//9000
		FormSecsGemSet->GemDataValueTray_Refresh(_TRACK_OUT_);	//9011
		//FormSecsGemSet->TrackIn_Cycle(_TRACK_IN_);
		//FormSecsGemSet->GemDataTraceStage_Refresh(_TRACE_INFO_MC_STATUS_);
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormDestroy(TObject *Sender)
{
	delete g_barcode[BCD_ADC];
	g_barcode[BCD_ADC] = NULL;

    delete g_rfid;
    g_rfid = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FunctionBtn9Click(TObject *Sender)
{
	if(!CheckCanAccessLevel(PW_MAINTENANCE)) return;

	frmTCComm->ShowModal();
}
//---------------------------------------------------------------------------
//bool	TMainForm::CanDataAccess()
//{
//	RUNNINGSTATUS curStatus = nReadCommunicationDM( mcState );
//
//	if(curStatus == STATUS_RUN || curStatus == STATUS_AUTO)  return false;
//	else return true;
//}


//---------------------------------------------------------------------------
void __fastcall TMainForm::PanelLoginClick(TObject *Sender)
{
	if(PanelLogin->Caption != "OPERATOR")
	{
		frmLogin->setKeepPwd(false);
    	frmLogin->changeLevel(PW_OPERATOR);
        this->ScreenChange("MAINSCREEN");
        return;
    }
    frmLogin->ShowModal() ;
}

//---------------------------------------------------------------------------
void	TMainForm::ScreenChange(String menu)
{
    TForm* target = NULL;

	/*if(_pCurrentForm == SystemForm  || _pCurrentForm == RecipeForm )  // 비활성화
	{
		FormSecsGemSet->GemRecipeChange();
	}*/

    if(menu == "MAINSCREEN")
	{
        if(NULL != _pCurrentForm)
        {
            _pCurrentForm->Hide();
            _pCurrentForm = NULL;
        }
    }

    if(menu == "SYSTEM")
    {
	   //if(!CheckCanDataAccess()) return;
	   if(!CheckCanAccessLevel(PW_MAINTENANCE)) return;

		target = SystemForm;
		SystemForm->ScreenChange("SENSOR");
        MachineHistoryData("SYSTEM SCREEN Enter!");
    }

    if(menu == "SETUP")
    {
		//if(!CheckCanDataAccess()) return;
		if(!CheckCanAccessLevel(PW_MAINTENANCE)) return;

        target = SetupForm;
        MachineHistoryData("SETUP SCREEN Enter!");
    }

    if(menu == "RECIPE")
    {
		//if(!CheckCanDataAccess()) return;
		if(!CheckCanAccessLevel(PW_MAINTENANCE)) return;

		target = RecipeForm;
        MachineHistoryData("RECIPE SCREEN Enter!");
    }

    if(menu == "ALARM")
    {
        target = FrmAlarm;
        MachineHistoryData("ALARM SCREEN Enter!");
    }

     if(menu == "HISTORY")
    {
        target = FormHistory;
        MachineHistoryData("HISTORY SCREEN Enter!");
    }


    if(NULL != target && _pCurrentForm != target)
	{
		if(NULL != _pCurrentForm)
		{
			_pCurrentForm->Hide();
			_pCurrentForm = NULL;
		}

		_pCurrentForm = target;
		//
		if(NULL != _pCurrentForm)
		{
			_pCurrentForm->Parent = MainPanelBase;
			_pCurrentForm->Align = alClient;
			_pCurrentForm->Show();
		}
	}
}


//---------------------------------------------------------------------------

void __fastcall TMainForm::BitBtn1Click(TObject *Sender)
{
    if(!CheckCanDataAccess()) return;
	if(!CheckCanAccessLevel(PW_MAINTENANCE)) return;

    FrmCdBox->setFlag(CD_YESNO);
	FrmCdBox->setTitle("ADC Mode Change Operate");
    FrmCdBox->setText("Are you sure about the changing ADC mode?");
    if (mrYes == FrmCdBox->ShowModal())
    {
        bool flag = true;
		if(PanelAdcMode->Color == clLime) flag = false;

        nWriteCommunicationDM(flag, 300);
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ShortCutClick(TObject *Sender)
{
	TBitBtn* btn = dynamic_cast<TBitBtn*>(Sender);
	if(NULL == btn) return;

	if(btn->Caption == "ALARM LIST")
	{
		TfrmAlarmList* form = new TfrmAlarmList(this);
		form->ShowModal();
		delete form;
	}

	if(btn->Caption == "RUN HISTORY")
	{
		this->ScreenChange("HISTORY");
		FormHistory->ScreenChange("RUN HISTORY");
	}

	if(btn->Caption == "TEACHING PROCESS")
	{
		FrmTeachMain->ShowModal();
	}

	if(btn->Caption == "RFID")
	{
		frmRFID->ShowModal();
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FunctionBtn5Click(TObject *Sender)
{
	BOOL bRet = false;

	if (!frmSeeLot->Showing)
	{
		frmSeeLot->setMode(1);
		frmSeeLot->ShowModal();
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BitBtn3Click(TObject *Sender)
{
	frmOperatorID->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PanelProgramVersionDblClick(TObject *Sender)
{
	FrmProgramHistory->ShowModal();
}
//---------------------------------------------------------------------------

void 		TMainForm::AddLineToCSVFile(String strData, int nIndex)
{
	try
	{
		if(_sLst == NULL)
		{
			_sLst = new TStringList;
			_sLst->Add(" INDEX , SORTING_TIME ,");
		}
		String strText;
		strText.sprintf(L" STAGEINDEX_%02d ,", nIndex+1);

		strText += " "+strData+" ,";
		_sLst->Add( strText );
	}
	__finally
	{
	}
}
//---------------------------------------------------------------------------
void 		TMainForm::SaveToCSVFile(String strLotID)
{
	try
	{
		if(_sLst == NULL)
			return;

		if(strLotID == NULL || strLotID == "")
			strLotID = "EMPTYLOT";

		String strRcpName = Get_RecipeName()+"_"+strLotID+".csv";
		String strFileName = "C:\\KOSES\\History\\SortingTimeHistory\\"+strRcpName;
		//SaveFile
		_sLst->SaveToFile(strFileName);
		delete _sLst;
		_sLst = NULL;
	}
	__finally
	{
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ConnectPiperTimer(TObject *Sender)
{
	try
	{
		if(TRUE == g_pPiper->Init(1, L"MmiManager", L"MMI_QUEMAP"))
		{
			g_pTpBase = CreateTpBase();	//add on
			if(TRUE == g_pTpBase->Init(L"MMI_QUEMAP"))
				b_TpConnect = true;
			else
				MessageBox(0 , L" fail the TpBase Que connection " , 0, 0);
		}
		else
		{
			MessageBox(0 , L" fail the LogManager connection " , 0, 0);
		}
		ConnectPiper->Enabled = false;
	}
	catch (Exception &e)
	{
		b_TpConnect = false;
		ShowMessage(e.Message);
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::pnStartClick(TObject *Sender)
{
	int iTag  = dynamic_cast<TControl*>(Sender)->Tag;

	if(iTag == scrStart)
	{
		if(FrmCdBox->QueryMsg2("Start","Do you want to Start???",CD_YESNO,CD_ASK))
		{
			nWriteCommunicationDM(1,iTag);
		}
	}
	else
	{
		nWriteCommunicationDM(1,iTag);
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::pnStartMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	TPanel *pnl = 	dynamic_cast<TPanel*>(Sender);
	if(pnl !=NULL)
	{
		pnl->BevelOuter = bvLowered;
        pnl->BevelInner = bvLowered;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::pnStartMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	TPanel *pnl = 	dynamic_cast<TPanel*>(Sender);
	if(pnl !=NULL)
	{
		pnl->BevelOuter = bvRaised;
        pnl->BevelInner = bvRaised;
	}
}
//---------------------------------------------------------------------------
void TMainForm::VisionRefresh()
{
	if (dReadPkgData(VcutVisionSaveUse) == 1)
	{
		if (nReadCommunicationDM(VcutVisionSaveStatus) == 3)
		{
			FrmVisionSetUp->JobChangeVCutVision("IMAGEOFF");
			nWriteCommunicationDM(0, VcutVisionSaveStatus);
			nWriteCommunicationDM(0, VcutVisionSaveTriggerCount);
			MainForm->MachineHistoryData("V_Cut : VisionRefresh VcutVisionSaveStatus 0 / VcutVisionSaveTriggerCount 0, IMAGE OFF");
		}
	}
}
//---------------------------------------------------------------------------
void TMainForm::AutoFeedBackRefresh()
{
	if (bReadUseSkip(usAutoFeedBack))
	{
		int nAgvCnt = dReadPkgData(qcAgvCnt);
		int nBridgeCnt = dReadPkgData(qcBridgeCnt);

		for (int i = 0; i < 4; i++)
		{
			int nStageNo = qcCntStage1+i;
			int nStageCnt = nReadCommunicationDM(qcCntStage1+i);
			int nAGVStageNo = i+1;

			if (nStageNo <= 0)
				continue;

			if (nStageCnt >= nAgvCnt)
			{
				MainForm->MachineHistoryData("AutoFeedBack Refresh : Start avg");
				FormAutoFBHistory->AutoFBAgv(nBridgeCnt, nAGVStageNo);
				nWriteCommunicationDM(0, nStageNo);
			}
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::WarringRefreshTimerTimer(TObject *Sender)
{
	this->WarningPopupRefresh();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RobotRefreshTimerTimer(TObject *Sender)
{
	if(nReadCommunicationDM(flagPadPickupLog))
	{
		nWriteCommunicationDM(0, flagPadPickupLog);
		FormPadChangeHistory->PadChangeDataSave(3, 0, 1);
	}
	else if(nReadCommunicationDM(flagPadPlaceLog))
	{
		nWriteCommunicationDM(0, flagPadPlaceLog);
		FormPadChangeHistory->PadChangeDataSave(3, 0, 2);
	}
	else if(nReadCommunicationDM(flagPadChange))
	{
		nWriteCommunicationDM(0, flagPadChange);
		MainForm->MachineHistoryData("Pad Count Reset -> Auto");
	}
	else if(nReadCommunicationDM(flagPadAlarmLog))
	{
		nWriteCommunicationDM(0, flagPadAlarmLog);
		FormPadChangeHistory->PadChangeDataSave(4, nReadCommunicationDM(flagPadAlarmLog), 0);
	}
}
//---------------------------------------------------------------------------
void TMainForm::BtmVisionDLComm()
{
	try
	{
		int useDL = dReadPkgData(BottomVisionSendUse);

		if (useDL == 1)
		{
			int state = nReadCommunicationDM( onlineBtmVisionStep );
			if (STATE_REQ == state)
			{
				nWriteCommunicationDM(STATE_BUSY, onlineBtmVisionStep );
				this->MachineHistoryData("onlineBtmVisionStep : STATE_BUSY...");

				int nGroupIndex = nReadGroupNo();
				int nRecipeIndex = nReadRecipeNo();

				TIniFile *RecipeNameini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\RecipeName.ini");
				String RetStr = RecipeNameini->ReadString("GROUP_"+IntToStr(nGroupIndex),"RECIPENAME"+IntToStr(nRecipeIndex),"");
				delete RecipeNameini;

				AnsiString data;
				AnsiString params[7];

				AnsiString eqpVisionID = "";
				eqpVisionID = MainForm->_eqpVisionID.Trim();

				TIniFile *PkgParmini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(nGroupIndex)+"\\RCP"+IntToStr(nRecipeIndex)+"\\RcpInfo.ini");

				if (!PkgParmini->ReadString("RECIPE","EQP_VISION_ID","").Trim().IsEmpty())
				{
				   eqpVisionID = PkgParmini->ReadString("RECIPE","EQP_VISION_ID","");
				}

				int nStageNum = dReadPkgData(qpdvisionPickStage);
				g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_STG1_LOT_INFO+nStageNum;
				BOOL bRet = g_MMIComm->Send() &&  g_MMIComm->Recv();
				if (bRet)
				{
					LOT_INFO info = g_MMIComm->m_mmiToSeq.buffer.lotInfo;

					params[0] = eqpVisionID;
					params[1] = String(info.lotID);
					params[2] = String(info.partID);
					params[3] = RetStr;
					params[4] = IntToStr(info.lotQty);
					params[5] = "FALSE";
					params[6] = "Trigger";

					data.sprintf("VISION_ID=%s,LOT_NO=%s,PART_NO=%s,RECIPE_ID=%s,SERIALCOUNT=%s,TEST_MODE=%s,COMMAND=%s",\
					params[0].c_str(),
					params[1].c_str(),
					params[2].c_str(),
					params[3].c_str(),
					params[4].c_str(),
					params[5].c_str(),
					params[6].c_str());

					int nCheck = FrmVisionSetUp->send_btminfo(data);

					if(nCheck)
					{
						MainForm->MachineHistoryData("Send Data Vision : " + data);
					}
					else
					{
						MainForm->MachineHistoryData("onlineBtmVisionStep : Send Fail");
						nWriteCommunicationDM(STATE_ERR, onlineBtmVisionStep);
					}
				}
				else
				{
					MainForm->MachineHistoryData("onlineBtmVisionStep : Cmd Send Fail");
					nWriteCommunicationDM(STATE_ERR, onlineBtmVisionStep);
				}
			}
		}
	}
	catch(Exception& e)
	{
		MainForm->MachineHistoryData("onlineBtmVisionStep : Send Exception");
		nWriteCommunicationDM(STATE_ERR, onlineBtmVisionStep);
		MainForm->MachineHistoryData("Exception : " + e.Message);
	}
}
//---------------------------------------------------------------------------
