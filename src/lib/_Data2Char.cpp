#include "..\SEQ\Def\Includes.h"

_char* w2c(char* msg)
{
	_char pStr[1024] = { 0, };

#ifdef UNICODE
	int strSize = 0;
	strSize = MultiByteToWideChar(CP_ACP, 0, msg, -1, NULL, NULL);
	MultiByteToWideChar(CP_ACP, 0, msg, 1024, pStr, strSize);
	return pStr;
#else
	return msg;
#endif
}

void copyPmName(void)
{
	for (int nPmCnt = 0; nPmCnt < pmMAX; nPmCnt)
	{
		if(solRouter1Spindle12_OF > nPmCnt)
			_sprintf(g_data2c.cPmName[nPmCnt], L"C%02d", nPmCnt);
		else
		{
			_sprintf(g_data2c.cPmName[nPmCnt], L"S%02d", nPmCnt - solRouter1Spindle12_OF);
		}
	}
}

void copyPmIoData(void)
{
	int nSolCnt = 0;
	for (int nPmCnt = 0; nPmCnt < pmMAX; nPmCnt)
	{
		_sprintf(g_data2c.cPmIO[nPmCnt].In[pmOFF][pmOFF], L"SEN_X%d", g_pm[nPmCnt].GetOffIO(pmOFF, 0));
		_sprintf(g_data2c.cPmIO[nPmCnt].In[pmOFF][pmON], L"SEN_X%d", g_pm[nPmCnt].GetOnIO(pmOFF, 0));
		_sprintf(g_data2c.cPmIO[nPmCnt].In[pmON][pmOFF], L"SEN_X%d", g_pm[nPmCnt].GetOffIO(pmON, 0));
		_sprintf(g_data2c.cPmIO[nPmCnt].In[pmON][pmON], L"SEN_X%d", g_pm[nPmCnt].GetOnIO(pmON, 0));
		_sprintf(g_data2c.cPmIO[nPmCnt].out[pmOFF][pmOFF], L"OUT_Y%d", g_pm[nPmCnt].GetOffIO(pmOFF, 1));
		_sprintf(g_data2c.cPmIO[nPmCnt].out[pmOFF][pmON], L"OUT_Y%d", g_pm[nPmCnt].GetOnIO(pmOFF, 1));
		_sprintf(g_data2c.cPmIO[nPmCnt].out[pmON][pmOFF], L"OUT_Y%d", g_pm[nPmCnt].GetOffIO(pmON, 1));
		_sprintf(g_data2c.cPmIO[nPmCnt].out[pmON][pmON], L"OUT_Y%d", g_pm[nPmCnt].GetOnIO(pmON, 1));
	}
}

void copyMtName(void)
{
	for (int nMtCnt = 0; nMtCnt < mtMAX; nMtCnt)
	{
		_sprintf(g_data2c.cMtName[nMtCnt], L"M%02d", nMtCnt);
	}

//	_sprintf(g_data2c.cMtName[mtStage1Index], L"mtStage1Index");
//	_sprintf(g_data2c.cMtName[mtStage2Index], L"mtStage2Index");
//	_sprintf(g_data2c.cMtName[mtStage3Index], L"mtStage3Index");
//	_sprintf(g_data2c.cMtName[mtStage4Index], L"mtStage4Index");
//	_sprintf(g_data2c.cMtName[mtStage1Cleaning], L"mtStage1Cleaning");
//	_sprintf(g_data2c.cMtName[mtStage2Cleaning], L"mtStage2Cleaning");
//	_sprintf(g_data2c.cMtName[mtStage3Cleaning], L"mtStage3Cleaning");
//	_sprintf(g_data2c.cMtName[mtStage4Cleaning], L"mtStage4Cleaning");
//	_sprintf(g_data2c.cMtName[mtStage1Theta], L"mtStage1Theta");
//	_sprintf(g_data2c.cMtName[mtStage2Theta], L"mtStage2Theta");
//	_sprintf(g_data2c.cMtName[mtStage3Theta], L"mtStage3Theta");
//	_sprintf(g_data2c.cMtName[mtStage4Theta], L"mtStage4Theta");
//	_sprintf(g_data2c.cMtName[mtRouter1Y], L"mtRouter1Y");
//	_sprintf(g_data2c.cMtName[mtRouter1Z1], L"mtRouter1Z1");
//	_sprintf(g_data2c.cMtName[mtRouter1Z2], L"mtRouter1Z2");
//	_sprintf(g_data2c.cMtName[mtRouter1Conv], L"mtRouter1Conv");
//	_sprintf(g_data2c.cMtName[mtRouter2Y], L"mtRouter2Y");
//	_sprintf(g_data2c.cMtName[mtRouter2Z1], L"mtRouter2Z1");
//	_sprintf(g_data2c.cMtName[mtRouter2Z2], L"mtRouter2Z2");
//	_sprintf(g_data2c.cMtName[mtRouter2Conv], L"mtRouter2Conv");
//	_sprintf(g_data2c.cMtName[mtInRailStopper], L"mtInRailStopper");
//	_sprintf(g_data2c.cMtName[mtInPnpY], L"mtInPnpY");
//	_sprintf(g_data2c.cMtName[mtInPnpZ], L"mtInPnpZ");
//	_sprintf(g_data2c.cMtName[mtInPnpClamp], L"mtInPnpClamp");
//	_sprintf(g_data2c.cMtName[mtMaskPicker1Z], L"mtMaskPicker1Z");
//	_sprintf(g_data2c.cMtName[mtMaskPicker2Z], L"mtMaskPicker2Z");
//	_sprintf(g_data2c.cMtName[mtMaskPicker3Z], L"mtMaskPicker3Z");
//	_sprintf(g_data2c.cMtName[mtMaskPicker4Z], L"mtMaskPicker4Z");
//	_sprintf(g_data2c.cMtName[mtScrapPnpY], L"mtScrapPnpY");
//	_sprintf(g_data2c.cMtName[mtScrapPnpZ], L"mtScrapPnpZ");
//	_sprintf(g_data2c.cMtName[mtStanding1X], L"mtStanding1X");
//	_sprintf(g_data2c.cMtName[mtStanding1Z], L"mtStanding1Z");
//	_sprintf(g_data2c.cMtName[mtStanding2X], L"mtStanding2X");
//	_sprintf(g_data2c.cMtName[mtStanding2Z], L"mtStanding2Z");
//	_sprintf(g_data2c.cMtName[mtRejectPnpX], L"mtRejectPnpX");
//	_sprintf(g_data2c.cMtName[mtAdcGripperX], L"mtAdcGripperX");
//	_sprintf(g_data2c.cMtName[mtAdcRailZ], L"mtAdcRailZ");
//	_sprintf(g_data2c.cMtName[mtStaubliTilt], L"mtStaubliTilt");
}

void copyPosName(void)
{
	for (int nIndexCnt = 0; nIndexCnt < 20; nIndexCnt++)
	{
		_sprintf(g_data2c.cInRailStopper[nIndexCnt][_POSIDX_], L"POS_X");
		_sprintf(g_data2c.cInPnp.Y[nIndexCnt][_POSIDX_], L"POS_Y");
		_sprintf(g_data2c.cInPnp.Z[nIndexCnt][_POSIDX_], L"POS_Z");
		_sprintf(g_data2c.cInPnp.Clamp[nIndexCnt][_POSIDX_], L"POS_CLAMP");

		for (int nStgCnt = 0; nStgCnt < 4; nStgCnt++)
		{
			_sprintf(g_data2c.cStage[nStgCnt].Index[nIndexCnt][_POSIDX_], L"POS_X");
			_sprintf(g_data2c.cStage[nStgCnt].Theta[nIndexCnt][_POSIDX_], L"POS_T");
			_sprintf(g_data2c.cStage[nStgCnt].Clean[nIndexCnt][_POSIDX_], L"POS_CLEAN");
			_sprintf(g_data2c.cStage[nStgCnt].MaskPk[nIndexCnt][_POSIDX_], L"POS_Z");
		}

		for (int nRouterCnt = 0; nRouterCnt < 2; nRouterCnt++)
		{
			_sprintf(g_data2c.cRouter[nRouterCnt].Y[nIndexCnt][_POSIDX_], L"POS_Y");
			_sprintf(g_data2c.cRouter[nRouterCnt].Z[0][nIndexCnt][_POSIDX_], L"POS_Z");
			_sprintf(g_data2c.cRouter[nRouterCnt].Z[1][nIndexCnt][_POSIDX_], L"POS_Z");
			_sprintf(g_data2c.cRouter[nRouterCnt].Conv[nIndexCnt][_POSIDX_], L"POS_CONV");
		}

		_sprintf(g_data2c.cScrapPnp.Y[nIndexCnt][_POSIDX_], L"POS_Y");
		_sprintf(g_data2c.cScrapPnp.Z[nIndexCnt][_POSIDX_], L"POS_Z");
		_sprintf(g_data2c.cStanding[0].X[nIndexCnt][_POSIDX_], L"POS_X");
		_sprintf(g_data2c.cStanding[0].Z[nIndexCnt][_POSIDX_], L"POS_CLAMP");
		_sprintf(g_data2c.cStanding[1].X[nIndexCnt][_POSIDX_], L"POS_X");
		_sprintf(g_data2c.cStanding[1].Z[nIndexCnt][_POSIDX_], L"POS_CLAMP");
		_sprintf(g_data2c.cReject.PnpX[nIndexCnt][_POSIDX_], L"POS_X");
		_sprintf(g_data2c.cAdc.GripperX[nIndexCnt][_POSIDX_], L"POS_X");
		_sprintf(g_data2c.cAdc.RailZ[nIndexCnt][_POSIDX_], L"POS_Z");
		_sprintf(g_data2c.cStaubliTilt[nIndexCnt][_POSIDX_], L"POS_TILT");
	}

//	_sprintf(g_data2c.cInRailStopper[CInRail::PX_RCV][_POSIDX_], L"POS_RCV");
//	_sprintf(g_data2c.cInRailStopper[CInRail::PX_PCB_BARCODE][_POSIDX_], L"POS_RCV");
//	_sprintf(g_data2c.cInRailStopper[CInRail::PX_UNIT_BARCODE][_POSIDX_], L"POS_UNIT_BARCODE");
//	_sprintf(g_data2c.cInRailStopper[CInRail::PX_ALIGN][_POSIDX_], L"POS_ALIGN");
//	_sprintf(g_data2c.cInRailStopper[CInRail::PX_WAIT][_POSIDX_], L"POS_WAIT");
//
//	_sprintf(g_data2c.cInPnp.Y[CInPnp::PY_INRAIL][_POSIDX_], L"POS_INRAIL");
//	_sprintf(g_data2c.cInPnp.Y[CInPnp::PY_STAGE1_STATION][_POSIDX_], L"POS_STAGE1_STATION");
//	_sprintf(g_data2c.cInPnp.Y[CInPnp::PY_STAGE2_STATION][_POSIDX_], L"POS_STAGE2_STATION");
//	_sprintf(g_data2c.cInPnp.Y[CInPnp::PY_STAGE3_STATION][_POSIDX_], L"POS_STAGE3_STATION");
//	_sprintf(g_data2c.cInPnp.Y[CInPnp::PY_STAGE4_STATION][_POSIDX_], L"POS_STAGE4_STATION");
//	_sprintf(g_data2c.cInPnp.Y[CInPnp::PY_STAGE1_MASK][_POSIDX_], L"POS_STAGE1_MASK");
//	_sprintf(g_data2c.cInPnp.Y[CInPnp::PY_STAGE2_MASK][_POSIDX_], L"POS_STAGE2_MASK");
//	_sprintf(g_data2c.cInPnp.Y[CInPnp::PY_STAGE3_MASK][_POSIDX_], L"POS_STAGE3_MASK");
//	_sprintf(g_data2c.cInPnp.Y[CInPnp::PY_STAGE4_MASK][_POSIDX_], L"POS_STAGE4_MASK");
//	_sprintf(g_data2c.cInPnp.Y[CInPnp::PY_STAGE1_PCB][_POSIDX_], L"POS_STAGE1_PCB");
//	_sprintf(g_data2c.cInPnp.Y[CInPnp::PY_STAGE2_PCB][_POSIDX_], L"POS_STAGE2_PCB");
//	_sprintf(g_data2c.cInPnp.Y[CInPnp::PY_STAGE3_PCB][_POSIDX_], L"POS_STAGE3_PCB");
//	_sprintf(g_data2c.cInPnp.Y[CInPnp::PY_STAGE4_PCB][_POSIDX_], L"POS_STAGE4_PCB");
//	_sprintf(g_data2c.cInPnp.Y[CInPnp::PY_ADC][_POSIDX_], L"POS_ADC");
//
//	_sprintf(g_data2c.cInPnp.Z[CInPnp::PZ_RAIL][_POSIDX_], L"POS_RAIL");
//	_sprintf(g_data2c.cInPnp.Z[CInPnp::PZ_STAGE1_STATION][_POSIDX_], L"POS_STAGE1_STATION");
//	_sprintf(g_data2c.cInPnp.Z[CInPnp::PZ_STAGE2_STATION][_POSIDX_], L"POS_STAGE2_STATION");
//	_sprintf(g_data2c.cInPnp.Z[CInPnp::PZ_STAGE3_STATION][_POSIDX_], L"POS_STAGE3_STATION");
//	_sprintf(g_data2c.cInPnp.Z[CInPnp::PZ_STAGE4_STATION][_POSIDX_], L"POS_STAGE4_STATION");
//	_sprintf(g_data2c.cInPnp.Z[CInPnp::PZ_STAGE1_MASK][_POSIDX_], L"POS_STAGE1_MASK");
//	_sprintf(g_data2c.cInPnp.Z[CInPnp::PZ_STAGE2_MASK][_POSIDX_], L"POS_STAGE2_MASK");
//	_sprintf(g_data2c.cInPnp.Z[CInPnp::PZ_STAGE3_MASK][_POSIDX_], L"POS_STAGE3_MASK");
//	_sprintf(g_data2c.cInPnp.Z[CInPnp::PZ_STAGE4_MASK][_POSIDX_], L"POS_STAGE4_MASK");
//	_sprintf(g_data2c.cInPnp.Z[CInPnp::PZ_STAGE_PCB][_POSIDX_], L"POS_STAGE_PCB");
//	_sprintf(g_data2c.cInPnp.Z[CInPnp::PZ_ADC_KIT][_POSIDX_], L"POS_ADC_KIT");
//	_sprintf(g_data2c.cInPnp.Z[CInPnp::PZ_FAST_DOWN][_POSIDX_], L"POS_FAST_DOWN");
//	_sprintf(g_data2c.cInPnp.Z[CInPnp::PZ_SLOW_UP][_POSIDX_], L"POS_SLOW_UP");
//	_sprintf(g_data2c.cInPnp.Z[CInPnp::PZ_READY][_POSIDX_], L"POS_READY");
//
//	_sprintf(g_data2c.cInPnp.Clamp[CInPnp::PC_PCB_CLOSE][_POSIDX_], L"POS_PCB_CLOSE");
//	_sprintf(g_data2c.cInPnp.Clamp[CInPnp::PC_KIT_CLOSE][_POSIDX_], L"POS_KIT_CLOSE");
//	_sprintf(g_data2c.cInPnp.Clamp[CInPnp::PC_PCB_OPEN][_POSIDX_], L"POS_PCB_OPEN");
//	_sprintf(g_data2c.cInPnp.Clamp[CInPnp::PC_OPEN][_POSIDX_], L"POS_OPEN");
//
//	for (int nStgCnt = 0; nStgCnt < 4; nStgCnt++)
//	{
//		_sprintf(g_data2c.cStage[nStgCnt].Index[CStage::PX_LOADING_PCB][_POSIDX_], L"POS_LOADING_PCB");
//		_sprintf(g_data2c.cStage[nStgCnt].Index[CStage::PX_LOADING_STATION][_POSIDX_], L"POS_LOADING_STATION");
//		_sprintf(g_data2c.cStage[nStgCnt].Index[CStage::PX_LOADING_MASK][_POSIDX_], L"POS_LOADING_MASK");
//		_sprintf(g_data2c.cStage[nStgCnt].Index[CStage::PX_MASK_PNP][_POSIDX_], L"POS_MASK_PNP");
//		_sprintf(g_data2c.cStage[nStgCnt].Index[CStage::PX_PRS][_POSIDX_], L"POS_PRS");
//		_sprintf(g_data2c.cStage[nStgCnt].Index[CStage::PX_ROUTING][_POSIDX_], L"POS_ROUTING");
//		_sprintf(g_data2c.cStage[nStgCnt].Index[CStage::PX_BIT_EJECT_MAIN][_POSIDX_], L"POS_BIT_EJECT_MAIN");
//		_sprintf(g_data2c.cStage[nStgCnt].Index[CStage::PX_BIT_EJECT_SUB][_POSIDX_], L"POS_BIT_EJECT_SUB");
//		_sprintf(g_data2c.cStage[nStgCnt].Index[CStage::PX_BIT_CLAMP_MAIN][_POSIDX_], L"POS_BIT_CLAMP_MAIN");
//		_sprintf(g_data2c.cStage[nStgCnt].Index[CStage::PX_BIT_CLAMP_SUB][_POSIDX_], L"POS_BIT_CLAMP_SUB");
//		_sprintf(g_data2c.cStage[nStgCnt].Index[CStage::PX_BIT_ALIGN_MAIN][_POSIDX_], L"POS_BIT_ALIGN_MAIN");
//		_sprintf(g_data2c.cStage[nStgCnt].Index[CStage::PX_BIT_ALIGN_SUB][_POSIDX_], L"POS_BIT_ALIGN_SUB");
//		_sprintf(g_data2c.cStage[nStgCnt].Index[CStage::PX_BIT_CATCH_MAIN][_POSIDX_], L"POS_BIT_CATCH_MAIN");
//		_sprintf(g_data2c.cStage[nStgCnt].Index[CStage::PX_BIT_CATCH_SUB][_POSIDX_], L"POS_BIT_CATCH_SUB");
//		_sprintf(g_data2c.cStage[nStgCnt].Index[CStage::PX_SCRAP_PNP][_POSIDX_], L"POS_SCRAP_PNP");
//		_sprintf(g_data2c.cStage[nStgCnt].Index[CStage::PX_CLEAN][_POSIDX_], L"POS_CLEAN");
//		_sprintf(g_data2c.cStage[nStgCnt].Index[CStage::PX_SORTING][_POSIDX_], L"POS_SORTING");
//
//		_sprintf(g_data2c.cStage[nStgCnt].Theta[CStage::PT_LOADING_PCB][_POSIDX_], L"POS_LOADING_PCB");
//		_sprintf(g_data2c.cStage[nStgCnt].Theta[CStage::PT_LOADING_STATION][_POSIDX_], L"POS_LOADING_STATION");
//		_sprintf(g_data2c.cStage[nStgCnt].Theta[CStage::PT_LOADING_MASK][_POSIDX_], L"POS_LOADING_MASK");
//		_sprintf(g_data2c.cStage[nStgCnt].Theta[CStage::PT_MASK_PNP][_POSIDX_], L"POS_MASK_PNP");
//		_sprintf(g_data2c.cStage[nStgCnt].Theta[CStage::PT_PRS][_POSIDX_], L"POS_PRS");
//		_sprintf(g_data2c.cStage[nStgCnt].Theta[CStage::PT_ROUTING][_POSIDX_], L"POS_ROUTING");
//		_sprintf(g_data2c.cStage[nStgCnt].Theta[CStage::PT_BIT_EJECT_MAIN][_POSIDX_], L"POS_BIT_EJECT_MAIN");
//		_sprintf(g_data2c.cStage[nStgCnt].Theta[CStage::PT_BIT_EJECT_SUB][_POSIDX_], L"POS_BIT_EJECT_SUB");
//		_sprintf(g_data2c.cStage[nStgCnt].Theta[CStage::PT_BIT_CLAMP_MAIN][_POSIDX_], L"POS_BIT_CLAMP_MAIN");
//		_sprintf(g_data2c.cStage[nStgCnt].Theta[CStage::PT_BIT_CLAMP_SUB][_POSIDX_], L"POS_BIT_CLAMP_SUB");
//		_sprintf(g_data2c.cStage[nStgCnt].Theta[CStage::PT_BIT_ALIGN_MAIN][_POSIDX_], L"POS_BIT_ALIGN_MAIN");
//		_sprintf(g_data2c.cStage[nStgCnt].Theta[CStage::PT_BIT_ALIGN_SUB][_POSIDX_], L"POS_BIT_ALIGN_SUB");
//		_sprintf(g_data2c.cStage[nStgCnt].Theta[CStage::PT_BIT_CATCH_MAIN][_POSIDX_], L"POS_BIT_CATCH_MAIN");
//		_sprintf(g_data2c.cStage[nStgCnt].Theta[CStage::PT_BIT_CATCH_SUB][_POSIDX_], L"POS_BIT_CATCH_SUB");
//		_sprintf(g_data2c.cStage[nStgCnt].Theta[CStage::PT_SCRAP_PNP][_POSIDX_], L"POS_SCRAP_PNP");
//		_sprintf(g_data2c.cStage[nStgCnt].Theta[CStage::PT_CLEAN][_POSIDX_], L"POS_CLEAN");
//		_sprintf(g_data2c.cStage[nStgCnt].Theta[CStage::PT_SORTING][_POSIDX_], L"POS_SORTING");
//
//		_sprintf(g_data2c.cStage[nStgCnt].Clean[CStage::PB_STAGE_IN][_POSIDX_], L"POS_STAGE_IN");
//		_sprintf(g_data2c.cStage[nStgCnt].Clean[CStage::PB_STAGE_OUT][_POSIDX_], L"POS_STAGE_OUT");
//
//		_sprintf(g_data2c.cStage[nStgCnt].MaskPk[CStage::PZ_READY][_POSIDX_], L"POS_READY");
//		_sprintf(g_data2c.cStage[nStgCnt].MaskPk[CStage::PZ_FAST_READY][_POSIDX_], L"POS_FAST_READY");
//		_sprintf(g_data2c.cStage[nStgCnt].MaskPk[CStage::PZ_SLOW_READY][_POSIDX_], L"POS_SLOW_READY");
//		_sprintf(g_data2c.cStage[nStgCnt].MaskPk[CStage::PZ_DOWN][_POSIDX_], L"POS_DOWN");
//	}
//
//	for (int nRouterCnt = 0; nRouterCnt < 2; nRouterCnt++)
//	{
//		_sprintf(g_data2c.cRouter[nRouterCnt].Y[CRouter::PY_BIT_CHECK_MAIN][_POSIDX_], L"POS_BIT_CHECK_MAIN");
//		_sprintf(g_data2c.cRouter[nRouterCnt].Y[CRouter::PY_BIT_CHECK_SUB][_POSIDX_], L"POS_BIT_CHECK_SUB");
//		_sprintf(g_data2c.cRouter[nRouterCnt].Y[CRouter::PY_BIT_ESD_MAIN][_POSIDX_], L"POS_BIT_ESD_MAIN");
//		_sprintf(g_data2c.cRouter[nRouterCnt].Y[CRouter::PY_BIT_ESD_SUB][_POSIDX_], L"POS_BIT_ESD_SUB");
//		_sprintf(g_data2c.cRouter[nRouterCnt].Y[CRouter::PY_BIT_DIAMETER_MAIN][_POSIDX_], L"POS_BIT_DIAMETER_MAIN");
//		_sprintf(g_data2c.cRouter[nRouterCnt].Y[CRouter::PY_BIT_DIAMETER_SUB][_POSIDX_], L"POS_BIT_DIAMETER_SUB");
//		_sprintf(g_data2c.cRouter[nRouterCnt].Y[CRouter::PY_BIT_EJECT_MAIN][_POSIDX_], L"POS_BIT_EJECT_MAIN");
//		_sprintf(g_data2c.cRouter[nRouterCnt].Y[CRouter::PY_BIT_EJECT_SUB][_POSIDX_], L"POS_BIT_EJECT_SUB");
//		_sprintf(g_data2c.cRouter[nRouterCnt].Y[CRouter::PY_BIT_CLAMP_MAIN][_POSIDX_], L"POS_BIT_CLAMP_MAIN");
//		_sprintf(g_data2c.cRouter[nRouterCnt].Y[CRouter::PY_BIT_CLAMP_SUB][_POSIDX_], L"POS_BIT_CLAMP_SUB");
//		_sprintf(g_data2c.cRouter[nRouterCnt].Y[CRouter::PY_BIT_ALIGN_MAIN][_POSIDX_], L"POS_BIT_ALIGN_MAIN");
//		_sprintf(g_data2c.cRouter[nRouterCnt].Y[CRouter::PY_BIT_ALIGN_SUB][_POSIDX_], L"POS_BIT_ALIGN_SUB");
//		_sprintf(g_data2c.cRouter[nRouterCnt].Y[CRouter::PY_BIT_CATCH_MAIN][_POSIDX_], L"POS_BIT_CATCH_MAIN");
//		_sprintf(g_data2c.cRouter[nRouterCnt].Y[CRouter::PY_BIT_CATCH_SUB][_POSIDX_], L"POS_BIT_CATCH_SUB");
//		_sprintf(g_data2c.cRouter[nRouterCnt].Y[CRouter::PY_PRS][_POSIDX_], L"POS_PRS");
//		_sprintf(g_data2c.cRouter[nRouterCnt].Y[CRouter::PY_ROUTING][_POSIDX_], L"POS_ROUTING");
//		_sprintf(g_data2c.cRouter[nRouterCnt].Y[CRouter::PY_SAFETY][_POSIDX_], L"POS_SAFETY");
//
//		for (int nRouterZCnt = 0; nRouterZCnt < 2; nRouterZCnt++)
//		{
//			_sprintf(g_data2c.cRouter[nRouterCnt].Z[nRouterZCnt][CRouter::PZ_READY][_POSIDX_], L"POS_READY");
//			_sprintf(g_data2c.cRouter[nRouterCnt].Z[nRouterZCnt][CRouter::PZ_BIT_CHECK][_POSIDX_], L"POS_BIT_CHECK");
//			_sprintf(g_data2c.cRouter[nRouterCnt].Z[nRouterZCnt][CRouter::PZ_BIT_EJECT][_POSIDX_], L"POS_BIT_EJECT");
//			_sprintf(g_data2c.cRouter[nRouterCnt].Z[nRouterZCnt][CRouter::PZ_READY_CATCH][_POSIDX_], L"POS_READY_CATCH");
//			_sprintf(g_data2c.cRouter[nRouterCnt].Z[nRouterZCnt][CRouter::PZ_BIT_CATCH][_POSIDX_], L"POS_BIT_CATCH");
//			_sprintf(g_data2c.cRouter[nRouterCnt].Z[nRouterZCnt][CRouter::PZ_BIT_ESD][_POSIDX_], L"POS_BIT_ESD");
//			_sprintf(g_data2c.cRouter[nRouterCnt].Z[nRouterZCnt][CRouter::PZ_BIT_DIAMETER][_POSIDX_], L"POS_BIT_DIAMETER");
//			_sprintf(g_data2c.cRouter[nRouterCnt].Z[nRouterZCnt][CRouter::PZ_READY_ROUTING][_POSIDX_], L"POS_READY_ROUTING");
//			_sprintf(g_data2c.cRouter[nRouterCnt].Z[nRouterZCnt][CRouter::PZ_ROUTING][_POSIDX_], L"POS_ROUTING");
//			_sprintf(g_data2c.cRouter[nRouterCnt].Z[nRouterZCnt][CRouter::PZ_VI_PRS][_POSIDX_], L"POS_VI_PRS");
//		}
//
//		_sprintf(g_data2c.cRouter[nRouterCnt].Conv[CRouter::PC_ZERO][_POSIDX_], L"POS_ZERO");
//		_sprintf(g_data2c.cRouter[nRouterCnt].Conv[CRouter::PC_ROUTING][_POSIDX_], L"POS_ROUTING");
//		_sprintf(g_data2c.cRouter[nRouterCnt].Conv[CRouter::PC_MAX][_POSIDX_], L"POS_MAX");
//	}
//
//	_sprintf(g_data2c.cScrapPnp.Y[CScrapPnp::PY_STAGE1][_POSIDX_], L"POS_STAGE1");
//	_sprintf(g_data2c.cScrapPnp.Y[CScrapPnp::PY_STAGE2][_POSIDX_], L"POS_STAGE2");
//	_sprintf(g_data2c.cScrapPnp.Y[CScrapPnp::PY_STAGE3][_POSIDX_], L"POS_STAGE3");
//	_sprintf(g_data2c.cScrapPnp.Y[CScrapPnp::PY_STAGE4][_POSIDX_], L"POS_STAGE4");
//	_sprintf(g_data2c.cScrapPnp.Y[CScrapPnp::PY_REMOVE][_POSIDX_], L"POS_REMOVE");
//	_sprintf(g_data2c.cScrapPnp.Y[CScrapPnp::PY_WAIT][_POSIDX_], L"POS_WAIT");
//
//	_sprintf(g_data2c.cScrapPnp.Z[CScrapPnp::PZ_STAGE1_DOWN][_POSIDX_], L"POS_STAGE1_DOWN");
//	_sprintf(g_data2c.cScrapPnp.Z[CScrapPnp::PZ_STAGE2_DOWN][_POSIDX_], L"POS_STAGE2_DOWN");
//	_sprintf(g_data2c.cScrapPnp.Z[CScrapPnp::PZ_STAGE3_DOWN][_POSIDX_], L"POS_STAGE3_DOWN");
//	_sprintf(g_data2c.cScrapPnp.Z[CScrapPnp::PZ_STAGE4_DOWN][_POSIDX_], L"POS_STAGE4_DOWN");
//	_sprintf(g_data2c.cScrapPnp.Z[CScrapPnp::PZ_STAGE1_CLAMP][_POSIDX_], L"POS_STAGE1_CLAMP");
//	_sprintf(g_data2c.cScrapPnp.Z[CScrapPnp::PZ_STAGE2_CLAMP][_POSIDX_], L"POS_STAGE2_CLAMP");
//	_sprintf(g_data2c.cScrapPnp.Z[CScrapPnp::PZ_STAGE3_CLAMP][_POSIDX_], L"POS_STAGE3_CLAMP");
//	_sprintf(g_data2c.cScrapPnp.Z[CScrapPnp::PZ_STAGE4_CLAMP][_POSIDX_], L"POS_STAGE4_CLAMP");
//	_sprintf(g_data2c.cScrapPnp.Z[CScrapPnp::PZ_REMOVE][_POSIDX_], L"POS_REMOVE");
//	_sprintf(g_data2c.cScrapPnp.Z[CScrapPnp::PZ_FAST_READY][_POSIDX_], L"POS_FAST_READY");
//	_sprintf(g_data2c.cScrapPnp.Z[CScrapPnp::PZ_SLOW_READY][_POSIDX_], L"POS_SLOW_READY");
//	_sprintf(g_data2c.cScrapPnp.Z[CScrapPnp::PZ_READY][_POSIDX_], L"POS_READY");
//
//	for (int nStandingCnt = 0; nStandingCnt < 2; nStandingCnt++)
//	{
//		_sprintf(g_data2c.cStanding[nStandingCnt].X[CStanding::PX_SORTING][_POSIDX_], L"POS_SORTING");
//		_sprintf(g_data2c.cStanding[nStandingCnt].X[CStanding::PX_NEXT_MC][_POSIDX_], L"POS_NEXT_MC");
//
//		_sprintf(g_data2c.cStanding[nStandingCnt].Z[CStanding::PZ_UNCLAMP][_POSIDX_], L"POS_UNCLAMP");
//		_sprintf(g_data2c.cStanding[nStandingCnt].Z[CStanding::PZ_CLAMP][_POSIDX_], L"POS_CLAMP");
//	}
//
//	_sprintf(g_data2c.cReject.PnpX[CReject::PX_PICKUP][_POSIDX_], L"POS_PICKUP");
//	_sprintf(g_data2c.cReject.PnpX[CReject::PX_LEFT_BOX][_POSIDX_], L"POS_LEFT_BOX");
//	_sprintf(g_data2c.cReject.PnpX[CReject::PX_RIGHT_BOX][_POSIDX_], L"POS_RIGHT_BOX");
//
//	_sprintf(g_data2c.cAdc.GripperX[CAdc::PX_WAIT][_POSIDX_], L"POS_WAIT");
//	_sprintf(g_data2c.cAdc.GripperX[CAdc::PX_PICKER][_POSIDX_], L"POS_PICKER");
//	_sprintf(g_data2c.cAdc.GripperX[CAdc::PX_SLOT_CHK_WAIT][_POSIDX_], L"POS_SLOT_CHK_WAIT");
//	_sprintf(g_data2c.cAdc.GripperX[CAdc::PX_GRIP][_POSIDX_], L"POS_GRIP");
//	_sprintf(g_data2c.cAdc.GripperX[CAdc::PX_PUSH][_POSIDX_], L"POS_PUSH");
//
//	_sprintf(g_data2c.cAdc.RailZ[CAdc::PZ_PICKER][_POSIDX_], L"POS_PICKER");
//	_sprintf(g_data2c.cAdc.RailZ[CAdc::PZ_SLOT][_POSIDX_], L"POS_SLOT");
//	_sprintf(g_data2c.cAdc.RailZ[CAdc::PZ_TOP_STAGE1_PUSH][_POSIDX_], L"POS_TOP_STAGE1_PUSH");
//	_sprintf(g_data2c.cAdc.RailZ[CAdc::PZ_TOP_STAGE1_DOWN][_POSIDX_], L"POS_TOP_STAGE1_DOWN");
//	_sprintf(g_data2c.cAdc.RailZ[CAdc::PZ_TOP_STAGE1_GRIP][_POSIDX_], L"POS_TOP_STAGE1_GRIP");
//	_sprintf(g_data2c.cAdc.RailZ[CAdc::PZ_TOP_MASK1_PUSH][_POSIDX_], L"POS_TOP_MASK1_PUSH");
//	_sprintf(g_data2c.cAdc.RailZ[CAdc::PZ_TOP_MASK1_DOWN][_POSIDX_], L"POS_TOP_MASK1_DOWN");
//	_sprintf(g_data2c.cAdc.RailZ[CAdc::PZ_TOP_MASK1_GRIP][_POSIDX_], L"POS_TOP_MASK1_GRIP");
//	_sprintf(g_data2c.cAdc.RailZ[CAdc::PZ_BTM_STAGE1_PUSH][_POSIDX_], L"POS_BTM_STAGE1_PUSH");
//	_sprintf(g_data2c.cAdc.RailZ[CAdc::PZ_BTM_STAGE1_DOWN][_POSIDX_], L"POS_BTM_STAGE1_DOWN");
//	_sprintf(g_data2c.cAdc.RailZ[CAdc::PZ_BTM_STAGE1_GRIP][_POSIDX_], L"POS_BTM_STAGE1_GRIP");
//	_sprintf(g_data2c.cAdc.RailZ[CAdc::PZ_BTM_MASK1_PUSH][_POSIDX_], L"POS_BTM_MASK1_PUSH");
//	_sprintf(g_data2c.cAdc.RailZ[CAdc::PZ_BTM_MASK1_DOWN][_POSIDX_], L"POS_BTM_MASK1_DOWN");
//	_sprintf(g_data2c.cAdc.RailZ[CAdc::PZ_BTM_MASK1_GRIP][_POSIDX_], L"POS_BTM_MASK1_GRIP");
//
//	_sprintf(g_data2c.cStaubliTilt[CStaubli::PT_CENTER][_POSIDX_], L"POS_CENTER");
//	_sprintf(g_data2c.cStaubliTilt[CStaubli::PT_UPPER][_POSIDX_], L"POS_UPPER");
//	_sprintf(g_data2c.cStaubliTilt[CStaubli::PT_LOWER][_POSIDX_], L"POS_LOWER");
}
void copySpeedName(void)
{
	for (int nIndexCnt = 0; nIndexCnt < 20; nIndexCnt++)
	{
		_sprintf(g_data2c.cInRailStopper[nIndexCnt][_SPDIDX_], L"VEL_X");
		_sprintf(g_data2c.cInPnp.Y[nIndexCnt][_SPDIDX_], L"VEL_Y");
		_sprintf(g_data2c.cInPnp.Z[nIndexCnt][_SPDIDX_], L"VEL_Z");
		_sprintf(g_data2c.cInPnp.Clamp[nIndexCnt][_SPDIDX_], L"VEL_CLAMP");

		for (int nStgCnt = 0; nStgCnt < 4; nStgCnt++)
		{
			_sprintf(g_data2c.cStage[nStgCnt].Index[nIndexCnt][_SPDIDX_], L"VEL_X");
			_sprintf(g_data2c.cStage[nStgCnt].Theta[nIndexCnt][_SPDIDX_], L"VEL_T");
			_sprintf(g_data2c.cStage[nStgCnt].Clean[nIndexCnt][_SPDIDX_], L"VEL_CLEAN");
			_sprintf(g_data2c.cStage[nStgCnt].MaskPk[nIndexCnt][_SPDIDX_], L"VEL_Z");
		}

		for (int nRouterCnt = 0; nRouterCnt < 2; nRouterCnt++)
		{
			_sprintf(g_data2c.cRouter[nRouterCnt].Y[nIndexCnt][_SPDIDX_], L"VEL_Y");
			_sprintf(g_data2c.cRouter[nRouterCnt].Z[0][nIndexCnt][_SPDIDX_], L"VEL_Z");
			_sprintf(g_data2c.cRouter[nRouterCnt].Z[1][nIndexCnt][_SPDIDX_], L"VEL_Z");
			_sprintf(g_data2c.cRouter[nRouterCnt].Conv[nIndexCnt][_SPDIDX_], L"VEL_CONV");
		}

		_sprintf(g_data2c.cScrapPnp.Y[nIndexCnt][_SPDIDX_], L"VEL_Y");
		_sprintf(g_data2c.cScrapPnp.Z[nIndexCnt][_SPDIDX_], L"VEL_Z");
		_sprintf(g_data2c.cStanding[0].X[nIndexCnt][_SPDIDX_], L"VEL_X");
		_sprintf(g_data2c.cStanding[0].Z[nIndexCnt][_SPDIDX_], L"VEL_CLAMP");
		_sprintf(g_data2c.cStanding[1].X[nIndexCnt][_SPDIDX_], L"VEL_X");
		_sprintf(g_data2c.cStanding[1].Z[nIndexCnt][_SPDIDX_], L"VEL_CLAMP");
		_sprintf(g_data2c.cReject.PnpX[nIndexCnt][_SPDIDX_], L"VEL_X");
		_sprintf(g_data2c.cAdc.GripperX[nIndexCnt][_SPDIDX_], L"VEL_X");
		_sprintf(g_data2c.cAdc.RailZ[nIndexCnt][_SPDIDX_], L"VEL_Z");
		_sprintf(g_data2c.cStaubliTilt[nIndexCnt][_SPDIDX_], L"VEL_TILT");
	}

//	_sprintf(g_data2c.cInRailStopper[CInRail::PX_RCV][_SPDIDX_], L"SPEED_RCV");
//	_sprintf(g_data2c.cInRailStopper[CInRail::PX_PCB_BARCODE][_SPDIDX_], L"SPEED_RCV");
//	_sprintf(g_data2c.cInRailStopper[CInRail::PX_UNIT_BARCODE][_SPDIDX_], L"SPEED_UNIT_BARCODE");
//	_sprintf(g_data2c.cInRailStopper[CInRail::PX_ALIGN][_SPDIDX_], L"SPEED_ALIGN");
//	_sprintf(g_data2c.cInRailStopper[CInRail::PX_WAIT][_SPDIDX_], L"SPEED_WAIT");
//
//	_sprintf(g_data2c.cInPnp.Y[CInPnp::PY_INRAIL][_SPDIDX_], L"SPEED_INRAIL");
//	_sprintf(g_data2c.cInPnp.Y[CInPnp::PY_STAGE1_STATION][_SPDIDX_], L"SPEED_STAGE1_STATION");
//	_sprintf(g_data2c.cInPnp.Y[CInPnp::PY_STAGE2_STATION][_SPDIDX_], L"SPEED_STAGE2_STATION");
//	_sprintf(g_data2c.cInPnp.Y[CInPnp::PY_STAGE3_STATION][_SPDIDX_], L"SPEED_STAGE3_STATION");
//	_sprintf(g_data2c.cInPnp.Y[CInPnp::PY_STAGE4_STATION][_SPDIDX_], L"SPEED_STAGE4_STATION");
//	_sprintf(g_data2c.cInPnp.Y[CInPnp::PY_STAGE1_MASK][_SPDIDX_], L"SPEED_STAGE1_MASK");
//	_sprintf(g_data2c.cInPnp.Y[CInPnp::PY_STAGE2_MASK][_SPDIDX_], L"SPEED_STAGE2_MASK");
//	_sprintf(g_data2c.cInPnp.Y[CInPnp::PY_STAGE3_MASK][_SPDIDX_], L"SPEED_STAGE3_MASK");
//	_sprintf(g_data2c.cInPnp.Y[CInPnp::PY_STAGE4_MASK][_SPDIDX_], L"SPEED_STAGE4_MASK");
//	_sprintf(g_data2c.cInPnp.Y[CInPnp::PY_STAGE1_PCB][_SPDIDX_], L"SPEED_STAGE1_PCB");
//	_sprintf(g_data2c.cInPnp.Y[CInPnp::PY_STAGE2_PCB][_SPDIDX_], L"SPEED_STAGE2_PCB");
//	_sprintf(g_data2c.cInPnp.Y[CInPnp::PY_STAGE3_PCB][_SPDIDX_], L"SPEED_STAGE3_PCB");
//	_sprintf(g_data2c.cInPnp.Y[CInPnp::PY_STAGE4_PCB][_SPDIDX_], L"SPEED_STAGE4_PCB");
//	_sprintf(g_data2c.cInPnp.Y[CInPnp::PY_ADC][_SPDIDX_], L"SPEED_ADC");
//
//	_sprintf(g_data2c.cInPnp.Z[CInPnp::PZ_RAIL][_SPDIDX_], L"SPEED_RAIL");
//	_sprintf(g_data2c.cInPnp.Z[CInPnp::PZ_STAGE1_STATION][_SPDIDX_], L"SPEED_STAGE1_STATION");
//	_sprintf(g_data2c.cInPnp.Z[CInPnp::PZ_STAGE2_STATION][_SPDIDX_], L"SPEED_STAGE2_STATION");
//	_sprintf(g_data2c.cInPnp.Z[CInPnp::PZ_STAGE3_STATION][_SPDIDX_], L"SPEED_STAGE3_STATION");
//	_sprintf(g_data2c.cInPnp.Z[CInPnp::PZ_STAGE4_STATION][_SPDIDX_], L"SPEED_STAGE4_STATION");
//	_sprintf(g_data2c.cInPnp.Z[CInPnp::PZ_STAGE1_MASK][_SPDIDX_], L"SPEED_STAGE1_MASK");
//	_sprintf(g_data2c.cInPnp.Z[CInPnp::PZ_STAGE2_MASK][_SPDIDX_], L"SPEED_STAGE2_MASK");
//	_sprintf(g_data2c.cInPnp.Z[CInPnp::PZ_STAGE3_MASK][_SPDIDX_], L"SPEED_STAGE3_MASK");
//	_sprintf(g_data2c.cInPnp.Z[CInPnp::PZ_STAGE4_MASK][_SPDIDX_], L"SPEED_STAGE4_MASK");
//	_sprintf(g_data2c.cInPnp.Z[CInPnp::PZ_STAGE_PCB][_SPDIDX_], L"SPEED_STAGE_PCB");
//	_sprintf(g_data2c.cInPnp.Z[CInPnp::PZ_ADC_KIT][_SPDIDX_], L"SPEED_ADC_KIT");
//	_sprintf(g_data2c.cInPnp.Z[CInPnp::PZ_FAST_DOWN][_SPDIDX_], L"SPEED_FAST_DOWN");
//	_sprintf(g_data2c.cInPnp.Z[CInPnp::PZ_SLOW_UP][_SPDIDX_], L"SPEED_SLOW_UP");
//	_sprintf(g_data2c.cInPnp.Z[CInPnp::PZ_READY][_SPDIDX_], L"SPEED_READY");
//
//	_sprintf(g_data2c.cInPnp.Clamp[CInPnp::PC_PCB_CLOSE][_SPDIDX_], L"SPEED_PCB_CLOSE");
//	_sprintf(g_data2c.cInPnp.Clamp[CInPnp::PC_KIT_CLOSE][_SPDIDX_], L"SPEED_KIT_CLOSE");
//	_sprintf(g_data2c.cInPnp.Clamp[CInPnp::PC_PCB_OPEN][_SPDIDX_], L"SPEED_PCB_OPEN");
//	_sprintf(g_data2c.cInPnp.Clamp[CInPnp::PC_OPEN][_SPDIDX_], L"SPEED_OPEN");
//
//	for (int nStgCnt = 0; nStgCnt < 4; nStgCnt++)
//	{
//		_sprintf(g_data2c.cStage[nStgCnt].Index[CStage::PX_LOADING_PCB][_SPDIDX_], L"SPEED_LOADING_PCB");
//		_sprintf(g_data2c.cStage[nStgCnt].Index[CStage::PX_LOADING_STATION][_SPDIDX_], L"SPEED_LOADING_STATION");
//		_sprintf(g_data2c.cStage[nStgCnt].Index[CStage::PX_LOADING_MASK][_SPDIDX_], L"SPEED_LOADING_MASK");
//		_sprintf(g_data2c.cStage[nStgCnt].Index[CStage::PX_MASK_PNP][_SPDIDX_], L"SPEED_MASK_PNP");
//		_sprintf(g_data2c.cStage[nStgCnt].Index[CStage::PX_PRS][_SPDIDX_], L"SPEED_PRS");
//		_sprintf(g_data2c.cStage[nStgCnt].Index[CStage::PX_ROUTING][_SPDIDX_], L"SPEED_ROUTING");
//		_sprintf(g_data2c.cStage[nStgCnt].Index[CStage::PX_BIT_EJECT_MAIN][_SPDIDX_], L"SPEED_BIT_EJECT_MAIN");
//		_sprintf(g_data2c.cStage[nStgCnt].Index[CStage::PX_BIT_EJECT_SUB][_SPDIDX_], L"SPEED_BIT_EJECT_SUB");
//		_sprintf(g_data2c.cStage[nStgCnt].Index[CStage::PX_BIT_CLAMP_MAIN][_SPDIDX_], L"SPEED_BIT_CLAMP_MAIN");
//		_sprintf(g_data2c.cStage[nStgCnt].Index[CStage::PX_BIT_CLAMP_SUB][_SPDIDX_], L"SPEED_BIT_CLAMP_SUB");
//		_sprintf(g_data2c.cStage[nStgCnt].Index[CStage::PX_BIT_ALIGN_MAIN][_SPDIDX_], L"SPEED_BIT_ALIGN_MAIN");
//		_sprintf(g_data2c.cStage[nStgCnt].Index[CStage::PX_BIT_ALIGN_SUB][_SPDIDX_], L"SPEED_BIT_ALIGN_SUB");
//		_sprintf(g_data2c.cStage[nStgCnt].Index[CStage::PX_BIT_CATCH_MAIN][_SPDIDX_], L"SPEED_BIT_CATCH_MAIN");
//		_sprintf(g_data2c.cStage[nStgCnt].Index[CStage::PX_BIT_CATCH_SUB][_SPDIDX_], L"SPEED_BIT_CATCH_SUB");
//		_sprintf(g_data2c.cStage[nStgCnt].Index[CStage::PX_SCRAP_PNP][_SPDIDX_], L"SPEED_SCRAP_PNP");
//		_sprintf(g_data2c.cStage[nStgCnt].Index[CStage::PX_CLEAN][_SPDIDX_], L"SPEED_CLEAN");
//		_sprintf(g_data2c.cStage[nStgCnt].Index[CStage::PX_SORTING][_SPDIDX_], L"SPEED_SORTING");
//
//		_sprintf(g_data2c.cStage[nStgCnt].Theta[CStage::PT_LOADING_PCB][_SPDIDX_], L"SPEED_LOADING_PCB");
//		_sprintf(g_data2c.cStage[nStgCnt].Theta[CStage::PT_LOADING_STATION][_SPDIDX_], L"SPEED_LOADING_STATION");
//		_sprintf(g_data2c.cStage[nStgCnt].Theta[CStage::PT_LOADING_MASK][_SPDIDX_], L"SPEED_LOADING_MASK");
//		_sprintf(g_data2c.cStage[nStgCnt].Theta[CStage::PT_MASK_PNP][_SPDIDX_], L"SPEED_MASK_PNP");
//		_sprintf(g_data2c.cStage[nStgCnt].Theta[CStage::PT_PRS][_SPDIDX_], L"SPEED_PRS");
//		_sprintf(g_data2c.cStage[nStgCnt].Theta[CStage::PT_ROUTING][_SPDIDX_], L"SPEED_ROUTING");
//		_sprintf(g_data2c.cStage[nStgCnt].Theta[CStage::PT_BIT_EJECT_MAIN][_SPDIDX_], L"SPEED_BIT_EJECT_MAIN");
//		_sprintf(g_data2c.cStage[nStgCnt].Theta[CStage::PT_BIT_EJECT_SUB][_SPDIDX_], L"SPEED_BIT_EJECT_SUB");
//		_sprintf(g_data2c.cStage[nStgCnt].Theta[CStage::PT_BIT_CLAMP_MAIN][_SPDIDX_], L"SPEED_BIT_CLAMP_MAIN");
//		_sprintf(g_data2c.cStage[nStgCnt].Theta[CStage::PT_BIT_CLAMP_SUB][_SPDIDX_], L"SPEED_BIT_CLAMP_SUB");
//		_sprintf(g_data2c.cStage[nStgCnt].Theta[CStage::PT_BIT_ALIGN_MAIN][_SPDIDX_], L"SPEED_BIT_ALIGN_MAIN");
//		_sprintf(g_data2c.cStage[nStgCnt].Theta[CStage::PT_BIT_ALIGN_SUB][_SPDIDX_], L"SPEED_BIT_ALIGN_SUB");
//		_sprintf(g_data2c.cStage[nStgCnt].Theta[CStage::PT_BIT_CATCH_MAIN][_SPDIDX_], L"SPEED_BIT_CATCH_MAIN");
//		_sprintf(g_data2c.cStage[nStgCnt].Theta[CStage::PT_BIT_CATCH_SUB][_SPDIDX_], L"SPEED_BIT_CATCH_SUB");
//		_sprintf(g_data2c.cStage[nStgCnt].Theta[CStage::PT_SCRAP_PNP][_SPDIDX_], L"SPEED_SCRAP_PNP");
//		_sprintf(g_data2c.cStage[nStgCnt].Theta[CStage::PT_CLEAN][_SPDIDX_], L"SPEED_CLEAN");
//		_sprintf(g_data2c.cStage[nStgCnt].Theta[CStage::PT_SORTING][_SPDIDX_], L"SPEED_SORTING");
//
//		_sprintf(g_data2c.cStage[nStgCnt].Clean[CStage::PB_STAGE_IN][_SPDIDX_], L"SPEED_STAGE_IN");
//		_sprintf(g_data2c.cStage[nStgCnt].Clean[CStage::PB_STAGE_OUT][_SPDIDX_], L"SPEED_STAGE_OUT");
//
//		_sprintf(g_data2c.cStage[nStgCnt].MaskPk[CStage::PZ_READY][_SPDIDX_], L"SPEED_READY");
//		_sprintf(g_data2c.cStage[nStgCnt].MaskPk[CStage::PZ_FAST_READY][_SPDIDX_], L"SPEED_FAST_READY");
//		_sprintf(g_data2c.cStage[nStgCnt].MaskPk[CStage::PZ_SLOW_READY][_SPDIDX_], L"SPEED_SLOW_READY");
//		_sprintf(g_data2c.cStage[nStgCnt].MaskPk[CStage::PZ_DOWN][_SPDIDX_], L"SPEED_DOWN");
//	}
//
//	for (int nRouterCnt = 0; nRouterCnt < 2; nRouterCnt++)
//	{
//		_sprintf(g_data2c.cRouter[nRouterCnt].Y[CRouter::PY_BIT_CHECK_MAIN][_SPDIDX_], L"SPEED_BIT_CHECK_MAIN");
//		_sprintf(g_data2c.cRouter[nRouterCnt].Y[CRouter::PY_BIT_CHECK_SUB][_SPDIDX_], L"SPEED_BIT_CHECK_SUB");
//		_sprintf(g_data2c.cRouter[nRouterCnt].Y[CRouter::PY_BIT_ESD_MAIN][_SPDIDX_], L"SPEED_BIT_ESD_MAIN");
//		_sprintf(g_data2c.cRouter[nRouterCnt].Y[CRouter::PY_BIT_ESD_SUB][_SPDIDX_], L"SPEED_BIT_ESD_SUB");
//		_sprintf(g_data2c.cRouter[nRouterCnt].Y[CRouter::PY_BIT_DIAMETER_MAIN][_SPDIDX_], L"SPEED_BIT_DIAMETER_MAIN");
//		_sprintf(g_data2c.cRouter[nRouterCnt].Y[CRouter::PY_BIT_DIAMETER_SUB][_SPDIDX_], L"SPEED_BIT_DIAMETER_SUB");
//		_sprintf(g_data2c.cRouter[nRouterCnt].Y[CRouter::PY_BIT_EJECT_MAIN][_SPDIDX_], L"SPEED_BIT_EJECT_MAIN");
//		_sprintf(g_data2c.cRouter[nRouterCnt].Y[CRouter::PY_BIT_EJECT_SUB][_SPDIDX_], L"SPEED_BIT_EJECT_SUB");
//		_sprintf(g_data2c.cRouter[nRouterCnt].Y[CRouter::PY_BIT_CLAMP_MAIN][_SPDIDX_], L"SPEED_BIT_CLAMP_MAIN");
//		_sprintf(g_data2c.cRouter[nRouterCnt].Y[CRouter::PY_BIT_CLAMP_SUB][_SPDIDX_], L"SPEED_BIT_CLAMP_SUB");
//		_sprintf(g_data2c.cRouter[nRouterCnt].Y[CRouter::PY_BIT_ALIGN_MAIN][_SPDIDX_], L"SPEED_BIT_ALIGN_MAIN");
//		_sprintf(g_data2c.cRouter[nRouterCnt].Y[CRouter::PY_BIT_ALIGN_SUB][_SPDIDX_], L"SPEED_BIT_ALIGN_SUB");
//		_sprintf(g_data2c.cRouter[nRouterCnt].Y[CRouter::PY_BIT_CATCH_MAIN][_SPDIDX_], L"SPEED_BIT_CATCH_MAIN");
//		_sprintf(g_data2c.cRouter[nRouterCnt].Y[CRouter::PY_BIT_CATCH_SUB][_SPDIDX_], L"SPEED_BIT_CATCH_SUB");
//		_sprintf(g_data2c.cRouter[nRouterCnt].Y[CRouter::PY_PRS][_SPDIDX_], L"SPEED_PRS");
//		_sprintf(g_data2c.cRouter[nRouterCnt].Y[CRouter::PY_ROUTING][_SPDIDX_], L"SPEED_ROUTING");
//		_sprintf(g_data2c.cRouter[nRouterCnt].Y[CRouter::PY_SAFETY][_SPDIDX_], L"SPEED_SAFETY");
//
//		for (int nRouterZCnt = 0; nRouterZCnt < 2; nRouterZCnt++)
//		{
//			_sprintf(g_data2c.cRouter[nRouterCnt].Z[nRouterZCnt][CRouter::PZ_READY][_SPDIDX_], L"SPEED_READY");
//			_sprintf(g_data2c.cRouter[nRouterCnt].Z[nRouterZCnt][CRouter::PZ_BIT_CHECK][_SPDIDX_], L"SPEED_BIT_CHECK");
//			_sprintf(g_data2c.cRouter[nRouterCnt].Z[nRouterZCnt][CRouter::PZ_BIT_EJECT][_SPDIDX_], L"SPEED_BIT_EJECT");
//			_sprintf(g_data2c.cRouter[nRouterCnt].Z[nRouterZCnt][CRouter::PZ_READY_CATCH][_SPDIDX_], L"SPEED_READY_CATCH");
//			_sprintf(g_data2c.cRouter[nRouterCnt].Z[nRouterZCnt][CRouter::PZ_BIT_CATCH][_SPDIDX_], L"SPEED_BIT_CATCH");
//			_sprintf(g_data2c.cRouter[nRouterCnt].Z[nRouterZCnt][CRouter::PZ_BIT_ESD][_SPDIDX_], L"SPEED_BIT_ESD");
//			_sprintf(g_data2c.cRouter[nRouterCnt].Z[nRouterZCnt][CRouter::PZ_BIT_DIAMETER][_SPDIDX_], L"SPEED_BIT_DIAMETER");
//			_sprintf(g_data2c.cRouter[nRouterCnt].Z[nRouterZCnt][CRouter::PZ_READY_ROUTING][_SPDIDX_], L"SPEED_READY_ROUTING");
//			_sprintf(g_data2c.cRouter[nRouterCnt].Z[nRouterZCnt][CRouter::PZ_ROUTING][_SPDIDX_], L"SPEED_ROUTING");
//			_sprintf(g_data2c.cRouter[nRouterCnt].Z[nRouterZCnt][CRouter::PZ_VI_PRS][_SPDIDX_], L"SPEED_VI_PRS");
//		}
//
//		_sprintf(g_data2c.cRouter[nRouterCnt].Conv[CRouter::PC_ZERO][_SPDIDX_], L"SPEED_ZERO");
//		_sprintf(g_data2c.cRouter[nRouterCnt].Conv[CRouter::PC_ROUTING][_SPDIDX_], L"SPEED_ROUTING");
//		_sprintf(g_data2c.cRouter[nRouterCnt].Conv[CRouter::PC_MAX][_SPDIDX_], L"SPEED_MAX");
//	}
//
//	_sprintf(g_data2c.cScrapPnp.Y[CScrapPnp::PY_STAGE1][_SPDIDX_], L"SPEED_STAGE1");
//	_sprintf(g_data2c.cScrapPnp.Y[CScrapPnp::PY_STAGE2][_SPDIDX_], L"SPEED_STAGE2");
//	_sprintf(g_data2c.cScrapPnp.Y[CScrapPnp::PY_STAGE3][_SPDIDX_], L"SPEED_STAGE3");
//	_sprintf(g_data2c.cScrapPnp.Y[CScrapPnp::PY_STAGE4][_SPDIDX_], L"SPEED_STAGE4");
//	_sprintf(g_data2c.cScrapPnp.Y[CScrapPnp::PY_REMOVE][_SPDIDX_], L"SPEED_REMOVE");
//	_sprintf(g_data2c.cScrapPnp.Y[CScrapPnp::PY_WAIT][_SPDIDX_], L"SPEED_WAIT");
//
//	_sprintf(g_data2c.cScrapPnp.Z[CScrapPnp::PZ_STAGE1_DOWN][_SPDIDX_], L"SPEED_STAGE1_DOWN");
//	_sprintf(g_data2c.cScrapPnp.Z[CScrapPnp::PZ_STAGE2_DOWN][_SPDIDX_], L"SPEED_STAGE2_DOWN");
//	_sprintf(g_data2c.cScrapPnp.Z[CScrapPnp::PZ_STAGE3_DOWN][_SPDIDX_], L"SPEED_STAGE3_DOWN");
//	_sprintf(g_data2c.cScrapPnp.Z[CScrapPnp::PZ_STAGE4_DOWN][_SPDIDX_], L"SPEED_STAGE4_DOWN");
//	_sprintf(g_data2c.cScrapPnp.Z[CScrapPnp::PZ_STAGE1_CLAMP][_SPDIDX_], L"SPEED_STAGE1_CLAMP");
//	_sprintf(g_data2c.cScrapPnp.Z[CScrapPnp::PZ_STAGE2_CLAMP][_SPDIDX_], L"SPEED_STAGE2_CLAMP");
//	_sprintf(g_data2c.cScrapPnp.Z[CScrapPnp::PZ_STAGE3_CLAMP][_SPDIDX_], L"SPEED_STAGE3_CLAMP");
//	_sprintf(g_data2c.cScrapPnp.Z[CScrapPnp::PZ_STAGE4_CLAMP][_SPDIDX_], L"SPEED_STAGE4_CLAMP");
//	_sprintf(g_data2c.cScrapPnp.Z[CScrapPnp::PZ_REMOVE][_SPDIDX_], L"SPEED_REMOVE");
//	_sprintf(g_data2c.cScrapPnp.Z[CScrapPnp::PZ_FAST_READY][_SPDIDX_], L"SPEED_FAST_READY");
//	_sprintf(g_data2c.cScrapPnp.Z[CScrapPnp::PZ_SLOW_READY][_SPDIDX_], L"SPEED_SLOW_READY");
//	_sprintf(g_data2c.cScrapPnp.Z[CScrapPnp::PZ_READY][_SPDIDX_], L"SPEED_READY");
//
//	for (int nStandingCnt = 0; nStandingCnt < 2; nStandingCnt++)
//	{
//		_sprintf(g_data2c.cStanding[nStandingCnt].X[CStanding::PX_SORTING][_SPDIDX_], L"SPEED_SORTING");
//		_sprintf(g_data2c.cStanding[nStandingCnt].X[CStanding::PX_NEXT_MC][_SPDIDX_], L"SPEED_NEXT_MC");
//
//		_sprintf(g_data2c.cStanding[nStandingCnt].Z[CStanding::PZ_UNCLAMP][_SPDIDX_], L"SPEED_UNCLAMP");
//		_sprintf(g_data2c.cStanding[nStandingCnt].Z[CStanding::PZ_CLAMP][_SPDIDX_], L"SPEED_CLAMP");
//	}
//
//	_sprintf(g_data2c.cReject.PnpX[CReject::PX_PICKUP][_SPDIDX_], L"SPEED_PICKUP");
//	_sprintf(g_data2c.cReject.PnpX[CReject::PX_LEFT_BOX][_SPDIDX_], L"SPEED_LEFT_BOX");
//	_sprintf(g_data2c.cReject.PnpX[CReject::PX_RIGHT_BOX][_SPDIDX_], L"SPEED_RIGHT_BOX");
//
//	_sprintf(g_data2c.cAdc.GripperX[CAdc::PX_WAIT][_SPDIDX_], L"SPEED_WAIT");
//	_sprintf(g_data2c.cAdc.GripperX[CAdc::PX_PICKER][_SPDIDX_], L"SPEED_PICKER");
//	_sprintf(g_data2c.cAdc.GripperX[CAdc::PX_SLOT_CHK_WAIT][_SPDIDX_], L"SPEED_SLOT_CHK_WAIT");
//	_sprintf(g_data2c.cAdc.GripperX[CAdc::PX_GRIP][_SPDIDX_], L"SPEED_GRIP");
//	_sprintf(g_data2c.cAdc.GripperX[CAdc::PX_PUSH][_SPDIDX_], L"SPEED_PUSH");
//
//	_sprintf(g_data2c.cAdc.RailZ[CAdc::PZ_PICKER][_SPDIDX_], L"SPEED_PICKER");
//	_sprintf(g_data2c.cAdc.RailZ[CAdc::PZ_SLOT][_SPDIDX_], L"SPEED_SLOT");
//	_sprintf(g_data2c.cAdc.RailZ[CAdc::PZ_TOP_STAGE1_PUSH][_SPDIDX_], L"SPEED_TOP_STAGE1_PUSH");
//	_sprintf(g_data2c.cAdc.RailZ[CAdc::PZ_TOP_STAGE1_DOWN][_SPDIDX_], L"SPEED_TOP_STAGE1_DOWN");
//	_sprintf(g_data2c.cAdc.RailZ[CAdc::PZ_TOP_STAGE1_GRIP][_SPDIDX_], L"SPEED_TOP_STAGE1_GRIP");
//	_sprintf(g_data2c.cAdc.RailZ[CAdc::PZ_TOP_MASK1_PUSH][_SPDIDX_], L"SPEED_TOP_MASK1_PUSH");
//	_sprintf(g_data2c.cAdc.RailZ[CAdc::PZ_TOP_MASK1_DOWN][_SPDIDX_], L"SPEED_TOP_MASK1_DOWN");
//	_sprintf(g_data2c.cAdc.RailZ[CAdc::PZ_TOP_MASK1_GRIP][_SPDIDX_], L"SPEED_TOP_MASK1_GRIP");
//	_sprintf(g_data2c.cAdc.RailZ[CAdc::PZ_BTM_STAGE1_PUSH][_SPDIDX_], L"SPEED_BTM_STAGE1_PUSH");
//	_sprintf(g_data2c.cAdc.RailZ[CAdc::PZ_BTM_STAGE1_DOWN][_SPDIDX_], L"SPEED_BTM_STAGE1_DOWN");
//	_sprintf(g_data2c.cAdc.RailZ[CAdc::PZ_BTM_STAGE1_GRIP][_SPDIDX_], L"SPEED_BTM_STAGE1_GRIP");
//	_sprintf(g_data2c.cAdc.RailZ[CAdc::PZ_BTM_MASK1_PUSH][_SPDIDX_], L"SPEED_BTM_MASK1_PUSH");
//	_sprintf(g_data2c.cAdc.RailZ[CAdc::PZ_BTM_MASK1_DOWN][_SPDIDX_], L"SPEED_BTM_MASK1_DOWN");
//	_sprintf(g_data2c.cAdc.RailZ[CAdc::PZ_BTM_MASK1_GRIP][_SPDIDX_], L"SPEED_BTM_MASK1_GRIP");
//
//	_sprintf(g_data2c.cStaubliTilt[CStaubli::PT_CENTER][_SPDIDX_], L"SPEED_CENTER");
//	_sprintf(g_data2c.cStaubliTilt[CStaubli::PT_UPPER][_SPDIDX_], L"SPEED_UPPER");
//	_sprintf(g_data2c.cStaubliTilt[CStaubli::PT_LOWER][_SPDIDX_], L"SPEED_LOWER");
}

void copyAccelName(void)
{
	for (int nIndexCnt = 0; nIndexCnt < 20; nIndexCnt++)
	{
		_sprintf(g_data2c.cInRailStopper[nIndexCnt][_ACCIDX_], L"ACC_X");
		_sprintf(g_data2c.cInPnp.Y[nIndexCnt][_ACCIDX_], L"ACC_Y");
		_sprintf(g_data2c.cInPnp.Z[nIndexCnt][_ACCIDX_], L"ACC_Z");
		_sprintf(g_data2c.cInPnp.Clamp[nIndexCnt][_ACCIDX_], L"ACC_CLAMP");

		for (int nStgCnt = 0; nStgCnt < 4; nStgCnt++)
		{
			_sprintf(g_data2c.cStage[nStgCnt].Index[nIndexCnt][_ACCIDX_], L"ACC_X");
			_sprintf(g_data2c.cStage[nStgCnt].Theta[nIndexCnt][_ACCIDX_], L"ACC_T");
			_sprintf(g_data2c.cStage[nStgCnt].Clean[nIndexCnt][_ACCIDX_], L"ACC_CLEAN");
			_sprintf(g_data2c.cStage[nStgCnt].MaskPk[nIndexCnt][_ACCIDX_], L"ACC_Z");
		}

		for (int nRouterCnt = 0; nRouterCnt < 2; nRouterCnt++)
		{
			_sprintf(g_data2c.cRouter[nRouterCnt].Y[nIndexCnt][_ACCIDX_], L"ACC_Y");
			_sprintf(g_data2c.cRouter[nRouterCnt].Z[0][nIndexCnt][_ACCIDX_], L"ACC_Z");
			_sprintf(g_data2c.cRouter[nRouterCnt].Z[1][nIndexCnt][_ACCIDX_], L"ACC_Z");
			_sprintf(g_data2c.cRouter[nRouterCnt].Conv[nIndexCnt][_ACCIDX_], L"ACC_CONV");
		}

		_sprintf(g_data2c.cScrapPnp.Y[nIndexCnt][_ACCIDX_], L"ACC_Y");
		_sprintf(g_data2c.cScrapPnp.Z[nIndexCnt][_ACCIDX_], L"ACC_Z");
		_sprintf(g_data2c.cStanding[0].X[nIndexCnt][_ACCIDX_], L"ACC_X");
		_sprintf(g_data2c.cStanding[0].Z[nIndexCnt][_ACCIDX_], L"ACC_CLAMP");
		_sprintf(g_data2c.cStanding[1].X[nIndexCnt][_ACCIDX_], L"ACC_X");
		_sprintf(g_data2c.cStanding[1].Z[nIndexCnt][_ACCIDX_], L"ACC_CLAMP");
		_sprintf(g_data2c.cReject.PnpX[nIndexCnt][_ACCIDX_], L"ACC_X");
		_sprintf(g_data2c.cAdc.GripperX[nIndexCnt][_ACCIDX_], L"ACC_X");
		_sprintf(g_data2c.cAdc.RailZ[nIndexCnt][_ACCIDX_], L"ACC_Z");
		_sprintf(g_data2c.cStaubliTilt[nIndexCnt][_ACCIDX_], L"ACC_TILT");
	}
}

void copyPosData(void)
{
	for (int nIndex = 0; nIndex < _MAX_INDEX_; nIndex++)
	{
		_sprintf(g_data2c.cInRailStopper[nIndex][_POS_], L"%06f", g_mt[mtInRailStopper].m_pIdxTable->pos[nIndex]);

		_sprintf(g_data2c.cInPnp.Y[nIndex][_POS_], L"%06f", g_mt[mtInPnpY].m_pIdxTable->pos[nIndex]);
		_sprintf(g_data2c.cInPnp.Z[nIndex][_POS_], L"%06f", g_mt[mtInPnpZ].m_pIdxTable->pos[nIndex]);
		_sprintf(g_data2c.cInPnp.Clamp[nIndex][_POS_], L"%06f", g_mt[mtInPnpClamp].m_pIdxTable->pos[nIndex]);

		_sprintf(g_data2c.cStage[0].Index[nIndex][_POS_], L"%06f", g_mt[mtStage1Index].m_pIdxTable->pos[nIndex]);
		_sprintf(g_data2c.cStage[0].Clean[nIndex][_POS_], L"%06f", g_mt[mtStage1Cleaning].m_pIdxTable->pos[nIndex]);
		_sprintf(g_data2c.cStage[0].Theta[nIndex][_POS_], L"%06f", g_mt[mtStage1Theta].m_pIdxTable->pos[nIndex]);
		_sprintf(g_data2c.cStage[0].MaskPk[nIndex][_POS_], L"%06f", g_mt[mtMaskPicker1Z].m_pIdxTable->pos[nIndex]);

		_sprintf(g_data2c.cStage[1].Index[nIndex][_POS_], L"%06f", g_mt[mtStage2Index].m_pIdxTable->pos[nIndex]);
		_sprintf(g_data2c.cStage[1].Clean[nIndex][_POS_], L"%06f", g_mt[mtStage2Cleaning].m_pIdxTable->pos[nIndex]);
		_sprintf(g_data2c.cStage[1].Theta[nIndex][_POS_], L"%06f", g_mt[mtStage2Theta].m_pIdxTable->pos[nIndex]);
		_sprintf(g_data2c.cStage[1].MaskPk[nIndex][_POS_], L"%06f", g_mt[mtMaskPicker2Z].m_pIdxTable->pos[nIndex]);

		_sprintf(g_data2c.cStage[2].Index[nIndex][_POS_], L"%06f", g_mt[mtStage3Index].m_pIdxTable->pos[nIndex]);
		_sprintf(g_data2c.cStage[2].Clean[nIndex][_POS_], L"%06f", g_mt[mtStage3Cleaning].m_pIdxTable->pos[nIndex]);
		_sprintf(g_data2c.cStage[2].Theta[nIndex][_POS_], L"%06f", g_mt[mtStage3Theta].m_pIdxTable->pos[nIndex]);
		_sprintf(g_data2c.cStage[2].MaskPk[nIndex][_POS_], L"%06f", g_mt[mtMaskPicker3Z].m_pIdxTable->pos[nIndex]);

		_sprintf(g_data2c.cStage[3].Index[nIndex][_POS_], L"%06f", g_mt[mtStage4Index].m_pIdxTable->pos[nIndex]);
		_sprintf(g_data2c.cStage[3].Clean[nIndex][_POS_], L"%06f", g_mt[mtStage4Cleaning].m_pIdxTable->pos[nIndex]);
		_sprintf(g_data2c.cStage[3].Theta[nIndex][_POS_], L"%06f", g_mt[mtStage4Theta].m_pIdxTable->pos[nIndex]);
		_sprintf(g_data2c.cStage[3].MaskPk[nIndex][_POS_], L"%06f", g_mt[mtMaskPicker4Z].m_pIdxTable->pos[nIndex]);

		_sprintf(g_data2c.cRouter[0].Y[nIndex][_POS_], L"%06f", g_mt[mtRouter1Y].m_pIdxTable->pos[nIndex]);
		_sprintf(g_data2c.cRouter[0].Z[0][nIndex][_POS_], L"%06f", g_mt[mtRouter1Z1].m_pIdxTable->pos[nIndex]);
		_sprintf(g_data2c.cRouter[0].Z[1][nIndex][_POS_], L"%06f", g_mt[mtRouter1Z2].m_pIdxTable->pos[nIndex]);
		_sprintf(g_data2c.cRouter[0].Conv[nIndex][_POS_], L"%06f", g_mt[mtRouter1Conv].m_pIdxTable->pos[nIndex]);

		_sprintf(g_data2c.cRouter[1].Y[nIndex][_POS_], L"%06f", g_mt[mtRouter2Y].m_pIdxTable->pos[nIndex]);
		_sprintf(g_data2c.cRouter[1].Z[0][nIndex][_POS_], L"%06f", g_mt[mtRouter2Z1].m_pIdxTable->pos[nIndex]);
		_sprintf(g_data2c.cRouter[1].Z[1][nIndex][_POS_], L"%06f", g_mt[mtRouter2Z2].m_pIdxTable->pos[nIndex]);
		_sprintf(g_data2c.cRouter[1].Conv[nIndex][_POS_], L"%06f", g_mt[mtRouter2Conv].m_pIdxTable->pos[nIndex]);

		_sprintf(g_data2c.cScrapPnp.Y[nIndex][_POS_], L"%06f", g_mt[mtScrapPnpY].m_pIdxTable->pos[nIndex]);
		_sprintf(g_data2c.cScrapPnp.Z[nIndex][_POS_], L"%06f", g_mt[mtScrapPnpZ].m_pIdxTable->pos[nIndex]);

		_sprintf(g_data2c.cStanding[0].X[nIndex][_POS_], L"%06f", g_mt[mtStanding1X].m_pIdxTable->pos[nIndex]);
		_sprintf(g_data2c.cStanding[0].Z[nIndex][_POS_], L"%06f", g_mt[mtStanding1Z].m_pIdxTable->pos[nIndex]);

		_sprintf(g_data2c.cStanding[1].X[nIndex][_POS_], L"%06f", g_mt[mtStanding2X].m_pIdxTable->pos[nIndex]);
		_sprintf(g_data2c.cStanding[1].Z[nIndex][_POS_], L"%06f", g_mt[mtStanding2Z].m_pIdxTable->pos[nIndex]);

		_sprintf(g_data2c.cReject.PnpX[nIndex][_POS_], L"%06f", g_mt[mtRejectPnpX].m_pIdxTable->pos[nIndex]);

		_sprintf(g_data2c.cAdc.GripperX[nIndex][_POS_], L"%06f", g_mt[mtAdcGripperX].m_pIdxTable->pos[nIndex]);
		_sprintf(g_data2c.cAdc.RailZ[nIndex][_POS_], L"%06f", g_mt[mtAdcRailZ].m_pIdxTable->pos[nIndex]);

		_sprintf(g_data2c.cStaubliTilt[nIndex][_POS_], L"%06f", g_mt[mtStaubliTilt].m_pIdxTable->pos[nIndex]);
	}
}
void copySpeedData(void)
{
	for (int nIndex = 0; nIndex < _MAX_INDEX_; nIndex++)
	{
		_sprintf(g_data2c.cInRailStopper[nIndex][_SPD_], L"%06f", g_mt[mtInRailStopper].m_pIdxTable->vel[nIndex]);

		_sprintf(g_data2c.cInPnp.Y[nIndex][_SPD_], L"%06f", g_mt[mtInPnpY].m_pIdxTable->vel[nIndex]);
		_sprintf(g_data2c.cInPnp.Z[nIndex][_SPD_], L"%06f", g_mt[mtInPnpZ].m_pIdxTable->vel[nIndex]);
		_sprintf(g_data2c.cInPnp.Clamp[nIndex][_SPD_], L"%06f", g_mt[mtInPnpClamp].m_pIdxTable->vel[nIndex]);

		_sprintf(g_data2c.cStage[0].Index[nIndex][_SPD_], L"%06f", g_mt[mtStage1Index].m_pIdxTable->vel[nIndex]);
		_sprintf(g_data2c.cStage[0].Clean[nIndex][_SPD_], L"%06f", g_mt[mtStage1Cleaning].m_pIdxTable->vel[nIndex]);
		_sprintf(g_data2c.cStage[0].Theta[nIndex][_SPD_], L"%06f", g_mt[mtStage1Theta].m_pIdxTable->vel[nIndex]);
		_sprintf(g_data2c.cStage[0].MaskPk[nIndex][_SPD_], L"%06f", g_mt[mtMaskPicker1Z].m_pIdxTable->vel[nIndex]);

		_sprintf(g_data2c.cStage[1].Index[nIndex][_SPD_], L"%06f", g_mt[mtStage2Index].m_pIdxTable->vel[nIndex]);
		_sprintf(g_data2c.cStage[1].Clean[nIndex][_SPD_], L"%06f", g_mt[mtStage2Cleaning].m_pIdxTable->vel[nIndex]);
		_sprintf(g_data2c.cStage[1].Theta[nIndex][_SPD_], L"%06f", g_mt[mtStage2Theta].m_pIdxTable->vel[nIndex]);
		_sprintf(g_data2c.cStage[1].MaskPk[nIndex][_SPD_], L"%06f", g_mt[mtMaskPicker2Z].m_pIdxTable->vel[nIndex]);

		_sprintf(g_data2c.cStage[2].Index[nIndex][_SPD_], L"%06f", g_mt[mtStage3Index].m_pIdxTable->vel[nIndex]);
		_sprintf(g_data2c.cStage[2].Clean[nIndex][_SPD_], L"%06f", g_mt[mtStage3Cleaning].m_pIdxTable->vel[nIndex]);
		_sprintf(g_data2c.cStage[2].Theta[nIndex][_SPD_], L"%06f", g_mt[mtStage3Theta].m_pIdxTable->vel[nIndex]);
		_sprintf(g_data2c.cStage[2].MaskPk[nIndex][_SPD_], L"%06f", g_mt[mtMaskPicker3Z].m_pIdxTable->vel[nIndex]);

		_sprintf(g_data2c.cStage[3].Index[nIndex][_SPD_], L"%06f", g_mt[mtStage4Index].m_pIdxTable->vel[nIndex]);
		_sprintf(g_data2c.cStage[3].Clean[nIndex][_SPD_], L"%06f", g_mt[mtStage4Cleaning].m_pIdxTable->vel[nIndex]);
		_sprintf(g_data2c.cStage[3].Theta[nIndex][_SPD_], L"%06f", g_mt[mtStage4Theta].m_pIdxTable->vel[nIndex]);
		_sprintf(g_data2c.cStage[3].MaskPk[nIndex][_SPD_], L"%06f", g_mt[mtMaskPicker4Z].m_pIdxTable->vel[nIndex]);

		_sprintf(g_data2c.cRouter[0].Y[nIndex][_SPD_], L"%06f", g_mt[mtRouter1Y].m_pIdxTable->vel[nIndex]);
		_sprintf(g_data2c.cRouter[0].Z[0][nIndex][_SPD_], L"%06f", g_mt[mtRouter1Z1].m_pIdxTable->vel[nIndex]);
		_sprintf(g_data2c.cRouter[0].Z[1][nIndex][_SPD_], L"%06f", g_mt[mtRouter1Z2].m_pIdxTable->vel[nIndex]);
		_sprintf(g_data2c.cRouter[0].Conv[nIndex][_SPD_], L"%06f", g_mt[mtRouter1Conv].m_pIdxTable->vel[nIndex]);

		_sprintf(g_data2c.cRouter[1].Y[nIndex][_SPD_], L"%06f", g_mt[mtRouter2Y].m_pIdxTable->vel[nIndex]);
		_sprintf(g_data2c.cRouter[1].Z[0][nIndex][_SPD_], L"%06f", g_mt[mtRouter2Z1].m_pIdxTable->vel[nIndex]);
		_sprintf(g_data2c.cRouter[1].Z[1][nIndex][_SPD_], L"%06f", g_mt[mtRouter2Z2].m_pIdxTable->vel[nIndex]);
		_sprintf(g_data2c.cRouter[1].Conv[nIndex][_SPD_], L"%06f", g_mt[mtRouter2Conv].m_pIdxTable->vel[nIndex]);

		_sprintf(g_data2c.cScrapPnp.Y[nIndex][_SPD_], L"%06f", g_mt[mtScrapPnpY].m_pIdxTable->vel[nIndex]);
		_sprintf(g_data2c.cScrapPnp.Z[nIndex][_SPD_], L"%06f", g_mt[mtScrapPnpZ].m_pIdxTable->vel[nIndex]);

		_sprintf(g_data2c.cStanding[0].X[nIndex][_SPD_], L"%06f", g_mt[mtStanding1X].m_pIdxTable->vel[nIndex]);
		_sprintf(g_data2c.cStanding[0].Z[nIndex][_SPD_], L"%06f", g_mt[mtStanding1Z].m_pIdxTable->vel[nIndex]);

		_sprintf(g_data2c.cStanding[1].X[nIndex][_SPD_], L"%06f", g_mt[mtStanding2X].m_pIdxTable->vel[nIndex]);
		_sprintf(g_data2c.cStanding[1].Z[nIndex][_SPD_], L"%06f", g_mt[mtStanding2Z].m_pIdxTable->vel[nIndex]);

		_sprintf(g_data2c.cReject.PnpX[nIndex][_SPD_], L"%06f", g_mt[mtRejectPnpX].m_pIdxTable->vel[nIndex]);

		_sprintf(g_data2c.cAdc.GripperX[nIndex][_SPD_], L"%06f", g_mt[mtAdcGripperX].m_pIdxTable->vel[nIndex]);
		_sprintf(g_data2c.cAdc.RailZ[nIndex][_SPD_], L"%06f", g_mt[mtAdcRailZ].m_pIdxTable->vel[nIndex]);

		_sprintf(g_data2c.cStaubliTilt[nIndex][_SPD_], L"%06f", g_mt[mtStaubliTilt].m_pIdxTable->vel[nIndex]);
	}
}
void copyAccelData(void)
{
	for (int nIndex = 0; nIndex < _MAX_INDEX_; nIndex++)
	{
		_sprintf(g_data2c.cInRailStopper[nIndex][_ACC_], L"%10f", g_mt[mtInRailStopper].m_pIdxTable->acc[nIndex]);

		_sprintf(g_data2c.cInPnp.Y[nIndex][_ACC_], L"%10f", g_mt[mtInPnpY].m_pIdxTable->acc[nIndex]);
		_sprintf(g_data2c.cInPnp.Z[nIndex][_ACC_], L"%10f", g_mt[mtInPnpZ].m_pIdxTable->acc[nIndex]);
		_sprintf(g_data2c.cInPnp.Clamp[nIndex][_ACC_], L"%10f", g_mt[mtInPnpClamp].m_pIdxTable->acc[nIndex]);

		_sprintf(g_data2c.cStage[0].Index[nIndex][_ACC_], L"%10f", g_mt[mtStage1Index].m_pIdxTable->acc[nIndex]);
		_sprintf(g_data2c.cStage[0].Clean[nIndex][_ACC_], L"%10f", g_mt[mtStage1Cleaning].m_pIdxTable->acc[nIndex]);
		_sprintf(g_data2c.cStage[0].Theta[nIndex][_ACC_], L"%10f", g_mt[mtStage1Theta].m_pIdxTable->acc[nIndex]);
		_sprintf(g_data2c.cStage[0].MaskPk[nIndex][_ACC_], L"%10f", g_mt[mtMaskPicker1Z].m_pIdxTable->acc[nIndex]);

		_sprintf(g_data2c.cStage[1].Index[nIndex][_ACC_], L"%10f", g_mt[mtStage2Index].m_pIdxTable->acc[nIndex]);
		_sprintf(g_data2c.cStage[1].Clean[nIndex][_ACC_], L"%10f", g_mt[mtStage2Cleaning].m_pIdxTable->acc[nIndex]);
		_sprintf(g_data2c.cStage[1].Theta[nIndex][_ACC_], L"%10f", g_mt[mtStage2Theta].m_pIdxTable->acc[nIndex]);
		_sprintf(g_data2c.cStage[1].MaskPk[nIndex][_ACC_], L"%10f", g_mt[mtMaskPicker2Z].m_pIdxTable->acc[nIndex]);

		_sprintf(g_data2c.cStage[2].Index[nIndex][_ACC_], L"%10f", g_mt[mtStage3Index].m_pIdxTable->acc[nIndex]);
		_sprintf(g_data2c.cStage[2].Clean[nIndex][_ACC_], L"%10f", g_mt[mtStage3Cleaning].m_pIdxTable->acc[nIndex]);
		_sprintf(g_data2c.cStage[2].Theta[nIndex][_ACC_], L"%10f", g_mt[mtStage3Theta].m_pIdxTable->acc[nIndex]);
		_sprintf(g_data2c.cStage[2].MaskPk[nIndex][_ACC_], L"%10f", g_mt[mtMaskPicker3Z].m_pIdxTable->acc[nIndex]);

		_sprintf(g_data2c.cStage[3].Index[nIndex][_ACC_], L"%10f", g_mt[mtStage4Index].m_pIdxTable->acc[nIndex]);
		_sprintf(g_data2c.cStage[3].Clean[nIndex][_ACC_], L"%10f", g_mt[mtStage4Cleaning].m_pIdxTable->acc[nIndex]);
		_sprintf(g_data2c.cStage[3].Theta[nIndex][_ACC_], L"%10f", g_mt[mtStage4Theta].m_pIdxTable->acc[nIndex]);
		_sprintf(g_data2c.cStage[3].MaskPk[nIndex][_ACC_], L"%10f", g_mt[mtMaskPicker4Z].m_pIdxTable->acc[nIndex]);

		_sprintf(g_data2c.cRouter[0].Y[nIndex][_ACC_], L"%10f", g_mt[mtRouter1Y].m_pIdxTable->acc[nIndex]);
		_sprintf(g_data2c.cRouter[0].Z[0][nIndex][_ACC_], L"%10f", g_mt[mtRouter1Z1].m_pIdxTable->acc[nIndex]);
		_sprintf(g_data2c.cRouter[0].Z[1][nIndex][_ACC_], L"%10f", g_mt[mtRouter1Z2].m_pIdxTable->acc[nIndex]);
		_sprintf(g_data2c.cRouter[0].Conv[nIndex][_ACC_], L"%10f", g_mt[mtRouter1Conv].m_pIdxTable->acc[nIndex]);

		_sprintf(g_data2c.cRouter[1].Y[nIndex][_ACC_], L"%10f", g_mt[mtRouter2Y].m_pIdxTable->acc[nIndex]);
		_sprintf(g_data2c.cRouter[1].Z[0][nIndex][_ACC_], L"%10f", g_mt[mtRouter2Z1].m_pIdxTable->acc[nIndex]);
		_sprintf(g_data2c.cRouter[1].Z[1][nIndex][_ACC_], L"%10f", g_mt[mtRouter2Z2].m_pIdxTable->acc[nIndex]);
		_sprintf(g_data2c.cRouter[1].Conv[nIndex][_ACC_], L"%10f", g_mt[mtRouter2Conv].m_pIdxTable->acc[nIndex]);

		_sprintf(g_data2c.cScrapPnp.Y[nIndex][_ACC_], L"%10f", g_mt[mtScrapPnpY].m_pIdxTable->acc[nIndex]);
		_sprintf(g_data2c.cScrapPnp.Z[nIndex][_ACC_], L"%10f", g_mt[mtScrapPnpZ].m_pIdxTable->acc[nIndex]);

		_sprintf(g_data2c.cStanding[0].X[nIndex][_ACC_], L"%10f", g_mt[mtStanding1X].m_pIdxTable->acc[nIndex]);
		_sprintf(g_data2c.cStanding[0].Z[nIndex][_ACC_], L"%10f", g_mt[mtStanding1Z].m_pIdxTable->acc[nIndex]);

		_sprintf(g_data2c.cStanding[1].X[nIndex][_ACC_], L"%10f", g_mt[mtStanding2X].m_pIdxTable->acc[nIndex]);
		_sprintf(g_data2c.cStanding[1].Z[nIndex][_ACC_], L"%10f", g_mt[mtStanding2Z].m_pIdxTable->acc[nIndex]);

		_sprintf(g_data2c.cReject.PnpX[nIndex][_ACC_], L"%10f", g_mt[mtRejectPnpX].m_pIdxTable->acc[nIndex]);

		_sprintf(g_data2c.cAdc.GripperX[nIndex][_ACC_], L"%10f", g_mt[mtAdcGripperX].m_pIdxTable->acc[nIndex]);
		_sprintf(g_data2c.cAdc.RailZ[nIndex][_ACC_], L"%10f", g_mt[mtAdcRailZ].m_pIdxTable->acc[nIndex]);

		_sprintf(g_data2c.cStaubliTilt[nIndex][_ACC_], L"%10f", g_mt[mtStaubliTilt].m_pIdxTable->acc[nIndex]);
	}
}
void copy2Mtd(BOOL bInit)
{
	int nIndex, nMt;

	if(bInit)
	{
		copyPmName();
		copyMtName();

		copyPosName();
		copySpeedName();
		copyAccelName();

		for(nMt = 0; nMt < _MAX_AXIS_; nMt++)
		{
			for(nIndex = 0; nIndex < _MAX_INDEX_; nIndex++)
				g_logChk.bTransfer[nMt][nIndex] = FALSE;
		}

		for(nIndex = 0; nIndex < _MAX_PNEUM_; nIndex++)
			g_logChk.bFunction[nIndex] = FALSE;
	}
	
	copyPosData();
	copySpeedData();
	copyAccelData();
}