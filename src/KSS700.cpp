//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>


//---------------------------------------------------------------------------
USEFORM("Route\fgerber.cpp", frmRoute);
USEFORM("Setup\ffliper.cpp", frmFlipper);
USEFORM("RFID\fRFID.cpp", frmRFID);
USEFORM("Recipe\RcpCreateScrn.cpp", oFrmRcpCreate);
USEFORM("Recipe\RecipeChangeFormScrn.cpp", RecipeChangeForm);
USEFORM("Recipe\RecipeFormScrn.cpp", RecipeForm);
USEFORM("Setup\FormManualCuttingScrn.cpp", FormManualCutting);
USEFORM("Setup\fSystemTeach.cpp", frmSystemTeach);
USEFORM("Setup\ftrayteach.cpp", frmTrayTeach);
USEFORM("Setup\JobRunningScrn.cpp", FrmJobRunning);
USEFORM("Setup\FrmTenkeyScrn.cpp", FrmTenkey);
USEFORM("Setup\fpadsetup.cpp", frmPadSetup);
USEFORM("Setup\fqcunitsetup.cpp", frmQcPositionSetup);
USEFORM("Setup\fqcunitsetupcontrol.cpp", FrmQcUnitControl);
USEFORM("MainStatus\ARFlowScreen\fSeeLot.cpp", frmSeeLot);
USEFORM("MainStatus\DailyReport\fdailyreport.cpp", FrmDailyReport);
USEFORM("MainStatus\fallhome.cpp", frmAllhomeStatus);
USEFORM("MainStatus\ARFlowScreen\FrmARFlowScrn.cpp", FrmARFlow);
USEFORM("MainStatus\ARFlowScreen\fadctype.cpp", frmJobType);
USEFORM("MainStatus\ARFlowScreen\fQCResult.cpp", frmQCResult);
USEFORM("MainStatus\ARFlowScreen\frmADCBarcodeReg.cpp", frmADBBarcodeReg);
USEFORM("MainStatus\fmultiservo.cpp", FrmMultiServo);
USEFORM("Recipe\FormPkgParamScrn.cpp", FormPkgParam);
USEFORM("Recipe\nRcpCreateScrn.cpp", FrmRcpCreate);
USEFORM("PMS\FormPMSControlScrn.cpp", FrmPMSControl);
USEFORM("MainStatus\FormMainStatusScrn.cpp", FormMainStatus);
USEFORM("MainStatus\fpopmenu.cpp", FrmPopMenu);
USEFORM("MainStatus\frejecttray.cpp", frmRejectTray);
USEFORM("TCComm\ftccomm.cpp", frmTCComm);
USEFORM("Teaching\FlipperCenter\FrmFlipperCenterTeachScrn.cpp", FrmFlipperCenterTeach);
USEFORM("Teaching\FrmTeachMainScrn.cpp", FrmTeachMain);
USEFORM("System\SystemFormScrn.cpp", SystemForm);
USEFORM("System\Sensor\FrmSensorSetScrn.cpp", FrmSensorSet);
USEFORM("System\Staubli\FrmStaubliControlScrn.cpp", FrmStaubliControl);
USEFORM("System\Staubli\fSetCommonStaubli.cpp", frmSetCommonStaubli);
USEFORM("Teaching\RobotPadTeaching\FrmRobotPadTeachingScrn.cpp", FrmRobotPadTeaching);
USEFORM("Teaching\TrayTeaching\FrmRejectTrayTeachingScrn.cpp", FrmRejectTrayTeaching);
USEFORM("Teaching\TrayUnit\FrmTrayUnitScrn.cpp", FrmTrayUnit);
USEFORM("Teaching\VisionOffsetTeaching\FrmVisionOffsetTeachingScrn.cpp", FrmVisionOffsetTeaching);
USEFORM("Teaching\TrayTeaching\FrmRearGoodTrayScrn.cpp", FrmRearGoodTray);
USEFORM("Teaching\StageCenter\StageTeach1Scrn.cpp", FrmSystemCenterTeaching);
USEFORM("Teaching\StageUnit\FrmStageUnitScrn.cpp", FrmStageUnit);
USEFORM("Teaching\TrayTeaching\FrmFrontGoodTrayScrn.cpp", FrmFrontGoodTray);
USEFORM("System\FormLifeTimeSetScrn.cpp", FormLifeTimeSet);
USEFORM("System\FormTowerLampScrn.cpp", FormTowerLamp);
USEFORM("Setup\SetupFormScrn.cpp", SetupForm);
USEFORM("Setup\UnitControlScrn.cpp", FrmUnitControl);
USEFORM("Setup\UnitSetupScrn.cpp", FrmUnitSetup);
USEFORM("System\Motor\AxisConfigFormScrn.cpp", MotorAxisConfig);
USEFORM("System\ParameterBaseFormScrn.cpp", ParameterBaseForm);
USEFORM("System\SensorbaseFormScrn.cpp", SensorbaseForm);
USEFORM("System\Sensor\FrmSensorPartScrn.cpp", FrmSensorPart);
USEFORM("System\Motor\FrmMotorControlScrn.cpp", FrmMotorControl);
USEFORM("System\Motor\AxisSelectFormScrn.cpp", AxisSelectForm);
USEFORM("System\Motor\CommonDataSetting.cpp", FrmCommonSet);
USEFORM("System\Motor\faxisselect.cpp", frmSelectAxis);
USEFORM("Communication\FrmRouterCommScrn.cpp", FrmRouterComm);
USEFORM("Communication\SECS\FormSecsGemSetScrn.cpp", FormSecsGemSet);
USEFORM("Communication\SECS\FrmTerminalMsgScrn.cpp", FrmTerminalMsg);
USEFORM("Function\FormNumberKeyPadScrn.cpp", FormNumberKeyPad);
USEFORM("Function\FrmUserParameterScrn.cpp", FrmUserParameter);
USEFORM("Function\FrmUseSkipScrn.cpp", FrmUseSkip);
USEFORM("deviceSetup\fmotorsetupcontrol.cpp", frmMtrSetupControl);
USEFORM("Communication\VisionSetUpScrn.cpp", FrmVisionSetUp);
USEFORM("ConfigSetFormScrn.cpp", ConfigSetForm);
USEFORM("deviceSetup\fmotorsetup.cpp", frmMorterSetup);
USEFORM("Alarm\AlarmDetailListScrn.cpp", FrmAlarmDetailList);
USEFORM("Barcode\fbarcode.cpp", frmBarcode);
USEFORM("Alarm\falarmlist.cpp", frmAlarmList);
USEFORM("Alarm\FrmAlarmScrn.cpp", FrmAlarm);
USEFORM("History\FrmPadChangeHistory.cpp", FormPadChangeHistory);
USEFORM("History\FrmRejectHistoryScrn.cpp", FrmRejectHistory);
USEFORM("LoadCell\FrmLoadCellScrn.cpp", FrmLoadCell);
USEFORM("MainFormScrn.cpp", MainForm);
USEFORM("Global\flogin.cpp", frmLogin);
USEFORM("Global\fOperatorID.cpp", frmOperatorID);
USEFORM("Global\fPopupNotice.cpp", frmPopupNotice);
USEFORM("Global\falpha.cpp", FrmApha);
USEFORM("Function\WarningPopupScrn.cpp", FrmWarningPopup);
USEFORM("Function\WarningScrn.cpp", FrmWarning);
USEFORM("Global\Cdbox.cpp", FrmCdBox);
USEFORM("Global\fProgramHistory.cpp", FrmProgramHistory);
USEFORM("History\FormAlarmHistoryScrn.cpp", FormAlarmHistory);
USEFORM("History\FormHistoryScrn.cpp", FormHistory);
USEFORM("History\FrmAutoFBHistory.cpp", FormAutoFBHistory);
USEFORM("History\fLotEventHistory.cpp", frmLotDataHistory);
USEFORM("Global\GrayFormCDBoxScrn.cpp", GrayFrmCDBOX);
USEFORM("Global\hook.cpp", FrmHook);
USEFORM("Global\OhtModeSelect.cpp", FrmOhtModeSelect);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	HANDLE  hMutex = NULL;
	hMutex = CreateMutex(NULL, false,_T("KSS700"));
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		ShowMessage("It is already running.");
		return 0;
	}

	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TMainForm), &MainForm);
		Application->CreateForm(__classid(TFormMainStatus), &FormMainStatus);
		Application->CreateForm(__classid(TFormSecsGemSet), &FormSecsGemSet);
		Application->CreateForm(__classid(TGrayFrmCDBOX), &GrayFrmCDBOX);
		Application->CreateForm(__classid(TFrmHook), &FrmHook);
		Application->CreateForm(__classid(TfrmLogin), &frmLogin);
		Application->CreateForm(__classid(TFrmAlarmDetailList), &FrmAlarmDetailList);
		Application->CreateForm(__classid(TFrmUseSkip), &FrmUseSkip);
		Application->CreateForm(__classid(TFrmUserParameter), &FrmUserParameter);
		Application->CreateForm(__classid(TFrmVisionSetUp), &FrmVisionSetUp);
		Application->CreateForm(__classid(TFrmPMSControl), &FrmPMSControl);
		Application->CreateForm(__classid(TFrmWarning), &FrmWarning);
		Application->CreateForm(__classid(TFrmTerminalMsg), &FrmTerminalMsg);
		Application->CreateForm(__classid(ToFrmRcpCreate), &oFrmRcpCreate);
		Application->CreateForm(__classid(TFormNumberKeyPad), &FormNumberKeyPad);
		Application->CreateForm(__classid(TFrmStaubliControl), &FrmStaubliControl);
		Application->CreateForm(__classid(TFrmUnitSetup), &FrmUnitSetup);
		Application->CreateForm(__classid(TfrmRoute), &frmRoute);
		Application->CreateForm(__classid(TFrmRouterComm), &FrmRouterComm);
		Application->CreateForm(__classid(TfrmBarcode), &frmBarcode);
		Application->CreateForm(__classid(TfrmRFID), &frmRFID);
		Application->CreateForm(__classid(TfrmQcPositionSetup), &frmQcPositionSetup);
		Application->CreateForm(__classid(TfrmFlipper), &frmFlipper);
		Application->CreateForm(__classid(TfrmADBBarcodeReg), &frmADBBarcodeReg);
		Application->CreateForm(__classid(TfrmSeeLot), &frmSeeLot);
		Application->CreateForm(__classid(TfrmQCResult), &frmQCResult);
		Application->CreateForm(__classid(TfrmTrayTeach), &frmTrayTeach);
		Application->CreateForm(__classid(TfrmSystemTeach), &frmSystemTeach);
		Application->CreateForm(__classid(TSetupForm), &SetupForm);
		Application->CreateForm(__classid(TSystemForm), &SystemForm);
		Application->CreateForm(__classid(TRecipeForm), &RecipeForm);
		Application->CreateForm(__classid(TFormHistory), &FormHistory);
		Application->CreateForm(__classid(TFormAlarmHistory), &FormAlarmHistory);
		Application->CreateForm(__classid(TRecipeChangeForm), &RecipeChangeForm);
		Application->CreateForm(__classid(TFormTowerLamp), &FormTowerLamp);
		Application->CreateForm(__classid(TSensorbaseForm), &SensorbaseForm);
		Application->CreateForm(__classid(TParameterBaseForm), &ParameterBaseForm);
		Application->CreateForm(__classid(TFormLifeTimeSet), &FormLifeTimeSet);
		Application->CreateForm(__classid(TfrmMorterSetup), &frmMorterSetup);
		Application->CreateForm(__classid(TfrmMtrSetupControl), &frmMtrSetupControl);
		Application->CreateForm(__classid(TfrmAllhomeStatus), &frmAllhomeStatus);
		Application->CreateForm(__classid(TfrmAlarmList), &frmAlarmList);
		Application->CreateForm(__classid(TFrmPopMenu), &FrmPopMenu);
		Application->CreateForm(__classid(TFrmDailyReport), &FrmDailyReport);
		Application->CreateForm(__classid(TfrmLotDataHistory), &frmLotDataHistory);
		Application->CreateForm(__classid(TFrmMotorControl), &FrmMotorControl);
		Application->CreateForm(__classid(TFrmOhtModeSelect), &FrmOhtModeSelect);
		Application->CreateForm(__classid(TFrmRcpCreate), &FrmRcpCreate);
		Application->CreateForm(__classid(TfrmPadSetup), &frmPadSetup);
		Application->CreateForm(__classid(TFrmCdBox), &FrmCdBox);
		Application->CreateForm(__classid(TFrmTeachMain), &FrmTeachMain);
		Application->CreateForm(__classid(TFrmSystemCenterTeaching), &FrmSystemCenterTeaching);
		Application->CreateForm(__classid(TFrmFlipperCenterTeach), &FrmFlipperCenterTeach);
		Application->CreateForm(__classid(TFrmRearGoodTray), &FrmRearGoodTray);
		Application->CreateForm(__classid(TFrmFrontGoodTray), &FrmFrontGoodTray);
		Application->CreateForm(__classid(TFrmRobotPadTeaching), &FrmRobotPadTeaching);
		Application->CreateForm(__classid(TFrmRejectTrayTeaching), &FrmRejectTrayTeaching);
		Application->CreateForm(__classid(TFrmTrayUnit), &FrmTrayUnit);
		Application->CreateForm(__classid(TFrmVisionOffsetTeaching), &FrmVisionOffsetTeaching);
		Application->CreateForm(__classid(TFrmStageUnit), &FrmStageUnit);
		Application->CreateForm(__classid(TFrmLoadCell), &FrmLoadCell);
		Application->CreateForm(__classid(TFrmRejectHistory), &FrmRejectHistory);
		Application->CreateForm(__classid(TfrmOperatorID), &frmOperatorID);
		Application->CreateForm(__classid(TFrmProgramHistory), &FrmProgramHistory);
		Application->CreateForm(__classid(TFrmTenkey), &FrmTenkey);
		Application->CreateForm(__classid(TFrmCommonSet), &FrmCommonSet);
		Application->CreateForm(__classid(TFrmWarningPopup), &FrmWarningPopup);
		Application->CreateForm(__classid(TfrmSetCommonStaubli), &frmSetCommonStaubli);
		Application->CreateForm(__classid(TFrmAlarm), &FrmAlarm);
		Application->CreateForm(__classid(TFrmWarningPopup), &FrmWarningPopup);
		Application->CreateForm(__classid(TConfigSetForm), &ConfigSetForm);
		Application->CreateForm(__classid(TfrmSetCommonStaubli), &frmSetCommonStaubli);
		Application->CreateForm(__classid(TfrmTCComm), &frmTCComm);
		Application->CreateForm(__classid(TfrmPopupNotice), &frmPopupNotice);
		Application->CreateForm(__classid(TFrmMultiServo), &FrmMultiServo);
		Application->CreateForm(__classid(TFrmApha), &FrmApha);
		Application->CreateForm(__classid(TFormPadChangeHistory), &FormPadChangeHistory);
		Application->CreateForm(__classid(TFormAutoFBHistory), &FormAutoFBHistory);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
