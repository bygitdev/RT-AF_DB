// ************************************************************************ //
// WARNING                                                                    
// -------                                                                    
// The types declared in this file were generated from data read from a       
// Type Library. If this type library is explicitly or indirectly (via        
// another type library referring to this type library) re-imported, or the   
// 'Refresh' command of the Type Library Editor activated while editing the   
// Type Library, the contents of this file will be regenerated and all        
// manual modifications will be lost.                                         
// ************************************************************************ //

// $Rev: 52393 $
// File generated on 2017-11-02 오전 9:26:33 from Type Library described below.

// ************************************************************************  //
// Type Lib: C:\PROGRA~2\LINKGE~1\XGEMV3~1.X\SE\Bin\eXGem.ocx (1)
// LIBID: {B1594C47-316E-46A0-BED1-58A864F882B1}
// LCID: 0
// Helpfile: 
// HelpString: 
// DepndLst: 
//   (1) v2.0 stdole, (C:\Windows\SysWOW64\stdole2.tlb)
// SYS_KIND: SYS_WIN32
// ************************************************************************ //

#include <vcl.h>
#pragma hdrstop

#include <olectrls.hpp>
#include <oleserver.hpp>
#if defined(USING_ATL)
#include <atl\atlvcl.h>
#endif

#pragma option -w-8122
#include "eXGemLib_OCX.h"

#if !defined(__PRAGMA_PACKAGE_SMART_INIT)
#define      __PRAGMA_PACKAGE_SMART_INIT
#pragma package(smart_init)
#endif

namespace Exgemlib_tlb
{



// *********************************************************************//
// OCX PROXY CLASS IMPLEMENTATION
// (The following variables/methods implement the class TeXGem which
// allows "" to be hosted in CBuilder IDE/apps).
// *********************************************************************//
int   TeXGem::EventDispIDs[41] = {
    0x00000001, 0x00000002, 0x00000003, 0x00000004, 0x00000005, 0x00000006,
    0x00000007, 0x00000008, 0x00000009, 0x0000000A, 0x0000000B, 0x0000000C,
    0x0000000D, 0x0000000E, 0x0000000F, 0x00000010, 0x00000011, 0x00000012,
    0x00000013, 0x00000014, 0x00000015, 0x00000016, 0x00000017, 0x00000018,
    0x00000019, 0x0000001A, 0x0000001B, 0x0000001C, 0x0000001D, 0x0000001E,
    0x0000001F, 0x00000020, 0x00000021, 0x00000022, 0x00000023, 0x00000024,
    0x00000025, 0x00000026, 0x00000027, 0x00000028, 0x00000029};

Vcl::Olectrls::TControlData2 TeXGem::CControlData =
{
  // GUID of CoClass and Event Interface of Control
  {0x2220F20C, 0x2FA3, 0x461C,{ 0x84, 0xD4, 0x94,0x8B, 0x6D, 0x07,0xE7, 0x9B} }, // CoClass
  {0xF0B2A415, 0xB60D, 0x4F3D,{ 0xBD, 0xA6, 0xD8,0x25, 0x51, 0xC5,0x9C, 0xFA} }, // Events

  // Count of Events and array of their DISPIDs
  41, &EventDispIDs,

  // Pointer to Runtime License string
  NULL,  // HRESULT(0x80004005)

  // Flags for OnChanged PropertyNotification
  0x00000000,
  401,// (IDE Version)

  // Count of Font Prop and array of their DISPIDs
  0, Winapi::Activex::PDispIDList(NULL),

  // Count of Pict Prop and array of their DISPIDs
  0, Winapi::Activex::PDispIDList(NULL),
  0, // Reserved
  0, // Instance count (used internally)
  0, // List of Enum descriptions (internal)
};

GUID     TeXGem::DEF_CTL_INTF = {0x6F88E29E, 0x8982, 0x49D6,{ 0x9A, 0xCC, 0xCB,0xD4, 0x95, 0x2D,0x6D, 0x3B} };
TNoParam TeXGem::OptParam;

static inline void ValidCtrCheck(TeXGem *)
{
   delete new TeXGem((System::Classes::TComponent*)(0));
};

void __fastcall TeXGem::InitControlData()
{
  ControlData = (Vcl::Olectrls::TControlData*)&CControlData;
  CControlData.FirstEventOfs = System::PByte(&FOneSECSMessageReceived) - System::PByte(this);
};

void __fastcall TeXGem::CreateControl()
{
  if (!m_OCXIntf)
  {
    _ASSERTE(DefaultDispatch);
    DefaultDispatch->QueryInterface(DEF_CTL_INTF, (LPVOID*)&m_OCXIntf);
  }
};

_DeXGemDisp __fastcall TeXGem::GetDefaultInterface()
{
  CreateControl();
  return m_OCXIntf;
};

void __fastcall TeXGem::AboutBox(void)
{
  GetDefaultInterface()->AboutBox();
}

long __fastcall TeXGem::Initialize(BSTR sCfg)
{
  return  GetDefaultInterface()->Initialize(sCfg);
}

long __fastcall TeXGem::Start(void)
{
  return  GetDefaultInterface()->Start();
}

long __fastcall TeXGem::Stop(void)
{
  return  GetDefaultInterface()->Stop();
}

long __fastcall TeXGem::Close(void)
{
  return  GetDefaultInterface()->Close();
}

long __fastcall TeXGem::MakeObject(long* pnObjectID)
{
  return  GetDefaultInterface()->MakeObject(pnObjectID);
}

long __fastcall TeXGem::SetList(long nObjectID, long nItemCount)
{
  return  GetDefaultInterface()->SetList(nObjectID, nItemCount);
}

long __fastcall TeXGem::GetList(long nObjectID, long* pnItemCount)
{
  return  GetDefaultInterface()->GetList(nObjectID, pnItemCount);
}

long __fastcall TeXGem::GEMSetVariables(long nObjectID, long nVid)
{
  return  GetDefaultInterface()->GEMSetVariables(nObjectID, nVid);
}

long __fastcall TeXGem::SendSECSMessage(long nObjectID, long nStream, long nFunction, long nSysbyte)
{
  return  GetDefaultInterface()->SendSECSMessage(nObjectID, nStream, nFunction, nSysbyte);
}

long __fastcall TeXGem::GEMReqOffline(void)
{
  return  GetDefaultInterface()->GEMReqOffline();
}

long __fastcall TeXGem::GEMReqLocal(void)
{
  return  GetDefaultInterface()->GEMReqLocal();
}

long __fastcall TeXGem::GEMReqRemote(void)
{
  return  GetDefaultInterface()->GEMReqRemote();
}

long __fastcall TeXGem::GEMSetEstablish(long bState)
{
  return  GetDefaultInterface()->GEMSetEstablish(bState);
}

long __fastcall TeXGem::GEMSetParam(BSTR sParamName, BSTR sParamValue)
{
  return  GetDefaultInterface()->GEMSetParam(sParamName, sParamValue);
}

long __fastcall TeXGem::GEMGetParam(BSTR sParamName, BSTR* psParamValue)
{
  return  GetDefaultInterface()->GEMGetParam(sParamName, psParamValue);
}

long __fastcall TeXGem::GEMEQInitialized(long nInitType)
{
  return  GetDefaultInterface()->GEMEQInitialized(nInitType);
}

long __fastcall TeXGem::GEMReqGetDateTime(void)
{
  return  GetDefaultInterface()->GEMReqGetDateTime();
}

long __fastcall TeXGem::GEMRspGetDateTime(long nMsgId, BSTR sSystemTime)
{
  return  GetDefaultInterface()->GEMRspGetDateTime(nMsgId, sSystemTime);
}

long __fastcall TeXGem::GEMRspDateTime(long nMsgId, long nResult)
{
  return  GetDefaultInterface()->GEMRspDateTime(nMsgId, nResult);
}

long __fastcall TeXGem::GEMSetAlarm(long nID, long nState)
{
  return  GetDefaultInterface()->GEMSetAlarm(nID, nState);
}

long __fastcall TeXGem::GEMRspRemoteCommand(long nMsgId, BSTR sCmd, long nHCAck, long nCount, 
                                            long* pnResult)
{
  return  GetDefaultInterface()->GEMRspRemoteCommand(nMsgId, sCmd, nHCAck, nCount, pnResult);
}

long __fastcall TeXGem::GEMRspChangeECV(long nMsgId, long nResult)
{
  return  GetDefaultInterface()->GEMRspChangeECV(nMsgId, nResult);
}

long __fastcall TeXGem::GEMSetECVChanged(long nCount, long* pnEcIds, BSTR* psEcVals)
{
  return  GetDefaultInterface()->GEMSetECVChanged(nCount, pnEcIds, psEcVals);
}

long __fastcall TeXGem::GEMSetPPChanged(long nMode, BSTR sPpid, long nSize, BSTR sBody)
{
  return  GetDefaultInterface()->GEMSetPPChanged(nMode, sPpid, nSize, sBody);
}

long __fastcall TeXGem::GEMSetPPFmtChanged(long nMode, BSTR sPpid, BSTR sMdln, BSTR sSoftRev, 
                                           long nCount, BSTR* psCCode, long* pnParamCount, 
                                           BSTR* psParamNames)
{
  return  GetDefaultInterface()->GEMSetPPFmtChanged(nMode, sPpid, sMdln, sSoftRev, nCount, psCCode, 
                                                    pnParamCount, psParamNames);
}

long __fastcall TeXGem::GEMReqPPLoadInquire(BSTR sPpid, long nLength)
{
  return  GetDefaultInterface()->GEMReqPPLoadInquire(sPpid, nLength);
}

long __fastcall TeXGem::GEMRspPPLoadInquire(long nMsgId, BSTR sPpid, long nResult)
{
  return  GetDefaultInterface()->GEMRspPPLoadInquire(nMsgId, sPpid, nResult);
}

long __fastcall TeXGem::GEMReqPPSend(BSTR sPpid, BSTR sBody)
{
  return  GetDefaultInterface()->GEMReqPPSend(sPpid, sBody);
}

long __fastcall TeXGem::GEMRspPPSend(long nMsgId, BSTR sPpid, long nResult)
{
  return  GetDefaultInterface()->GEMRspPPSend(nMsgId, sPpid, nResult);
}

long __fastcall TeXGem::GEMReqPP(BSTR sPpid)
{
  return  GetDefaultInterface()->GEMReqPP(sPpid);
}

long __fastcall TeXGem::GEMRspPP(long nMsgId, BSTR sPpid, BSTR sBody)
{
  return  GetDefaultInterface()->GEMRspPP(nMsgId, sPpid, sBody);
}

long __fastcall TeXGem::GEMRspPPDelete(long nMsgId, long nCount, BSTR* psPpids, long nResult)
{
  return  GetDefaultInterface()->GEMRspPPDelete(nMsgId, nCount, psPpids, nResult);
}

long __fastcall TeXGem::GEMRspPPList(long nMsgId, long nCount, BSTR* psPpids)
{
  return  GetDefaultInterface()->GEMRspPPList(nMsgId, nCount, psPpids);
}

long __fastcall TeXGem::GEMReqPPFmtSend(BSTR sPpid, BSTR sMdln, BSTR sSoftRev, long nCount, 
                                        BSTR* psCCode, long* pnParamCount, BSTR* psParamNames)
{
  return  GetDefaultInterface()->GEMReqPPFmtSend(sPpid, sMdln, sSoftRev, nCount, psCCode, 
                                                 pnParamCount, psParamNames);
}

long __fastcall TeXGem::GEMRspPPFmtSend(long nMsgId, BSTR sPpid, long nResult)
{
  return  GetDefaultInterface()->GEMRspPPFmtSend(nMsgId, sPpid, nResult);
}

long __fastcall TeXGem::GEMReqPPFmt(BSTR sPpid)
{
  return  GetDefaultInterface()->GEMReqPPFmt(sPpid);
}

long __fastcall TeXGem::GEMRspPPFmt(long nMsgId, BSTR sPpid, BSTR sMdln, BSTR sSoftRev, long nCount, 
                                    BSTR* psCCode, long* pnParamCount, BSTR* psParamNames)
{
  return  GetDefaultInterface()->GEMRspPPFmt(nMsgId, sPpid, sMdln, sSoftRev, nCount, psCCode, 
                                             pnParamCount, psParamNames);
}

long __fastcall TeXGem::GEMReqPPFmtVerification(BSTR sPpid, long nCount, long* pnAck, 
                                                BSTR* psSeqNumber, BSTR* psError)
{
  return  GetDefaultInterface()->GEMReqPPFmtVerification(sPpid, nCount, pnAck, psSeqNumber, psError);
}

long __fastcall TeXGem::GEMSetTerminalMessage(long nTid, BSTR sMsg)
{
  return  GetDefaultInterface()->GEMSetTerminalMessage(nTid, sMsg);
}

long __fastcall TeXGem::GEMSetVariable(long nCount, long* pnVid, BSTR* psValue)
{
  return  GetDefaultInterface()->GEMSetVariable(nCount, pnVid, psValue);
}

long __fastcall TeXGem::GEMEnableLog(long bEnabled)
{
  return  GetDefaultInterface()->GEMEnableLog(bEnabled);
}

long __fastcall TeXGem::GEMSetLogOption(BSTR sDriectory, BSTR sPrefix, BSTR sExtension, 
                                        long nKeepDay, long bMakeDailyLog, long bMakeSubDirectory)
{
  return  GetDefaultInterface()->GEMSetLogOption(sDriectory, sPrefix, sExtension, nKeepDay, 
                                                 bMakeDailyLog, bMakeSubDirectory);
}

long __fastcall TeXGem::GEMSetEvent(long nEventID)
{
  return  GetDefaultInterface()->GEMSetEvent(nEventID);
}

long __fastcall TeXGem::GEMGetVariable(long nCount, long* pnVid, BSTR* psValue)
{
  return  GetDefaultInterface()->GEMGetVariable(nCount, pnVid, psValue);
}

long __fastcall TeXGem::GEMSetSpecificMessage(long nObjectID, BSTR sMsgName)
{
  return  GetDefaultInterface()->GEMSetSpecificMessage(nObjectID, sMsgName);
}

long __fastcall TeXGem::GEMGetSpecificMessage(long nObjectID, long* pnRObjectID, BSTR sMsgName)
{
  return  GetDefaultInterface()->GEMGetSpecificMessage(nObjectID, pnRObjectID, sMsgName);
}

long __fastcall TeXGem::GetAllStringItem(long nObjectID, BSTR* psValue)
{
  return  GetDefaultInterface()->GetAllStringItem(nObjectID, psValue);
}

long __fastcall TeXGem::SetAllStringItem(long nObjectID, BSTR sValue)
{
  return  GetDefaultInterface()->SetAllStringItem(nObjectID, sValue);
}

long __fastcall TeXGem::GEMSetVarName(long nCount, BSTR* psVidName, BSTR* psValue)
{
  return  GetDefaultInterface()->GEMSetVarName(nCount, psVidName, psValue);
}

long __fastcall TeXGem::GEMGetVarName(long nCount, BSTR* psVidName, BSTR* psValue)
{
  return  GetDefaultInterface()->GEMGetVarName(nCount, psVidName, psValue);
}

long __fastcall TeXGem::CloseObject(long nObjectID)
{
  return  GetDefaultInterface()->CloseObject(nObjectID);
}

long __fastcall TeXGem::GEMReqAllECInfo(void)
{
  return  GetDefaultInterface()->GEMReqAllECInfo();
}

long __fastcall TeXGem::SetBinary(long nObjectID, short* pnValue, long nItemCount)
{
  return  GetDefaultInterface()->SetBinary(nObjectID, pnValue, nItemCount);
}

long __fastcall TeXGem::SetBool(long nObjectID, short* pnValue, long nItemCount)
{
  return  GetDefaultInterface()->SetBool(nObjectID, pnValue, nItemCount);
}

long __fastcall TeXGem::SetU1(long nObjectID, short* pnValue, long nItemCount)
{
  return  GetDefaultInterface()->SetU1(nObjectID, pnValue, nItemCount);
}

long __fastcall TeXGem::SetU2(long nObjectID, long* pnValue, long nItemCount)
{
  return  GetDefaultInterface()->SetU2(nObjectID, pnValue, nItemCount);
}

long __fastcall TeXGem::SetU4(long nObjectID, double* prValue, long nItemCount)
{
  return  GetDefaultInterface()->SetU4(nObjectID, prValue, nItemCount);
}

long __fastcall TeXGem::SetU8(long nObjectID, double* prValue, long nItemCount)
{
  return  GetDefaultInterface()->SetU8(nObjectID, prValue, nItemCount);
}

long __fastcall TeXGem::SetI1(long nObjectID, short* pnValue, long nItemCount)
{
  return  GetDefaultInterface()->SetI1(nObjectID, pnValue, nItemCount);
}

long __fastcall TeXGem::SetI2(long nObjectID, short* pnValue, long nItemCount)
{
  return  GetDefaultInterface()->SetI2(nObjectID, pnValue, nItemCount);
}

long __fastcall TeXGem::SetI4(long nObjectID, long* plValue, long nItemCount)
{
  return  GetDefaultInterface()->SetI4(nObjectID, plValue, nItemCount);
}

long __fastcall TeXGem::SetI8(long nObjectID, long* plValue, long nItemCount)
{
  return  GetDefaultInterface()->SetI8(nObjectID, plValue, nItemCount);
}

long __fastcall TeXGem::SetF4(long nObjectID, float* prValue, long nItemCount)
{
  return  GetDefaultInterface()->SetF4(nObjectID, prValue, nItemCount);
}

long __fastcall TeXGem::SetF8(long nObjectID, double* prValue, long nItemCount)
{
  return  GetDefaultInterface()->SetF8(nObjectID, prValue, nItemCount);
}

long __fastcall TeXGem::SetAscii(long nObjectID, BSTR pszValue, long nItemCount)
{
  return  GetDefaultInterface()->SetAscii(nObjectID, pszValue, nItemCount);
}

long __fastcall TeXGem::GetBinary(long nObjectID, short* pnValue, long* pnItemCount, long nSize)
{
  return  GetDefaultInterface()->GetBinary(nObjectID, pnValue, pnItemCount, nSize);
}

long __fastcall TeXGem::GetBool(long nObjectID, short* pnValue, long* pnItemCount, long nSize)
{
  return  GetDefaultInterface()->GetBool(nObjectID, pnValue, pnItemCount, nSize);
}

long __fastcall TeXGem::GetU1(long nObjectID, short* pnValue, long* pnItemCount, long nSize)
{
  return  GetDefaultInterface()->GetU1(nObjectID, pnValue, pnItemCount, nSize);
}

long __fastcall TeXGem::GetU2(long nObjectID, long* pnValue, long* pnItemCount, long nSize)
{
  return  GetDefaultInterface()->GetU2(nObjectID, pnValue, pnItemCount, nSize);
}

long __fastcall TeXGem::GetU4(long nObjectID, double* prValue, long* pnItemCount, long nSize)
{
  return  GetDefaultInterface()->GetU4(nObjectID, prValue, pnItemCount, nSize);
}

long __fastcall TeXGem::GetU8(long nObjectID, double* prValue, long* pnItemCount, long nSize)
{
  return  GetDefaultInterface()->GetU8(nObjectID, prValue, pnItemCount, nSize);
}

long __fastcall TeXGem::GetI1(long nObjectID, short* pnValue, long* pnItemCount, long nSize)
{
  return  GetDefaultInterface()->GetI1(nObjectID, pnValue, pnItemCount, nSize);
}

long __fastcall TeXGem::GetI2(long nObjectID, short* pnValue, long* pnItemCount, long nSize)
{
  return  GetDefaultInterface()->GetI2(nObjectID, pnValue, pnItemCount, nSize);
}

long __fastcall TeXGem::GetI4(long nObjectID, long* pnValue, long* pnItemCount, long nSize)
{
  return  GetDefaultInterface()->GetI4(nObjectID, pnValue, pnItemCount, nSize);
}

long __fastcall TeXGem::GetI8(long nObjectID, long* pnValue, long* pnItemCount, long nSize)
{
  return  GetDefaultInterface()->GetI8(nObjectID, pnValue, pnItemCount, nSize);
}

long __fastcall TeXGem::GetF4(long nObjectID, float* prValue, long* pnItemCount, long nSize)
{
  return  GetDefaultInterface()->GetF4(nObjectID, prValue, pnItemCount, nSize);
}

long __fastcall TeXGem::GetF8(long nObjectID, double* prValue, long* pnItemCount, long nSize)
{
  return  GetDefaultInterface()->GetF8(nObjectID, prValue, pnItemCount, nSize);
}

long __fastcall TeXGem::GetAscii(long nObjectID, BSTR* psValue, long* pnItemCount)
{
  return  GetDefaultInterface()->GetAscii(nObjectID, psValue, pnItemCount);
}

long __fastcall TeXGem::GEMReqPPSendEx(BSTR sPpid, BSTR sRecipePath)
{
  return  GetDefaultInterface()->GEMReqPPSendEx(sPpid, sRecipePath);
}

long __fastcall TeXGem::GEMRspPPEx(long nMsgId, BSTR sPpid, BSTR sRecipePath)
{
  return  GetDefaultInterface()->GEMRspPPEx(nMsgId, sPpid, sRecipePath);
}

long __fastcall TeXGem::GEMRspPPSendEx(long nMsgId, BSTR sPpid, BSTR sRecipePath, long nResult)
{
  return  GetDefaultInterface()->GEMRspPPSendEx(nMsgId, sPpid, sRecipePath, nResult);
}

long __fastcall TeXGem::GEMReqPPEx(BSTR sPpid, BSTR sRecipePath)
{
  return  GetDefaultInterface()->GEMReqPPEx(sPpid, sRecipePath);
}

long __fastcall TeXGem::SetAsciiEx(long nObjectID, short* pnValue, long nItemCount)
{
  return  GetDefaultInterface()->SetAsciiEx(nObjectID, pnValue, nItemCount);
}

long __fastcall TeXGem::GetAsciiEx(long nObjectID, short* pnValue, long* pnItemCount, long nSize)
{
  return  GetDefaultInterface()->GetAsciiEx(nObjectID, pnValue, pnItemCount, nSize);
}

long __fastcall TeXGem::GEMSetVariableEx(long nObjectID, long nVid)
{
  return  GetDefaultInterface()->GEMSetVariableEx(nObjectID, nVid);
}

long __fastcall TeXGem::GEMReqLoopback(long nCount, long* pnAbs)
{
  return  GetDefaultInterface()->GEMReqLoopback(nCount, pnAbs);
}

long __fastcall TeXGem::GEMSetEventEnable(long nCount, long* pnCEIDs, long nEnable)
{
  return  GetDefaultInterface()->GEMSetEventEnable(nCount, pnCEIDs, nEnable);
}

long __fastcall TeXGem::GEMSetAlarmEnable(long nCount, long* pnALIDs, long nEnable)
{
  return  GetDefaultInterface()->GEMSetAlarmEnable(nCount, pnALIDs, nEnable);
}

long __fastcall TeXGem::GEMGetEventEnable(long nCount, long* pnCEIDs, long* pnEnable)
{
  return  GetDefaultInterface()->GEMGetEventEnable(nCount, pnCEIDs, pnEnable);
}

long __fastcall TeXGem::GEMGetAlarmEnable(long nCount, long* pnALIDs, long* pnEnable)
{
  return  GetDefaultInterface()->GEMGetAlarmEnable(nCount, pnALIDs, pnEnable);
}

long __fastcall TeXGem::GEMGetAlarmInfo(long nCount, long* pnALIDs, long* pnALCDs, BSTR* psALTXs)
{
  return  GetDefaultInterface()->GEMGetAlarmInfo(nCount, pnALIDs, pnALCDs, psALTXs);
}

long __fastcall TeXGem::GEMGetSVInfo(long nCount, long* pnSVIDs, BSTR* psMins, BSTR* psMaxs)
{
  return  GetDefaultInterface()->GEMGetSVInfo(nCount, pnSVIDs, psMins, psMaxs);
}

long __fastcall TeXGem::GEMGetECVInfo(long nCount, long* pnEcIds, BSTR* psNames, BSTR* psDefs, 
                                      BSTR* psMins, BSTR* psMaxs, BSTR* psUnits)
{
  return  GetDefaultInterface()->GEMGetECVInfo(nCount, pnEcIds, psNames, psDefs, psMins, psMaxs, 
                                               psUnits);
}

long __fastcall TeXGem::GEMRspOffline(long nMsgId, long nAck)
{
  return  GetDefaultInterface()->GEMRspOffline(nMsgId, nAck);
}

long __fastcall TeXGem::GEMRspOnline(long nMsgId, long nAck)
{
  return  GetDefaultInterface()->GEMRspOnline(nMsgId, nAck);
}

long __fastcall TeXGem::GEMReqHostOffline(void)
{
  return  GetDefaultInterface()->GEMReqHostOffline();
}

long __fastcall TeXGem::GEMReqStartPolling(BSTR sName, long nScanTime)
{
  return  GetDefaultInterface()->GEMReqStartPolling(sName, nScanTime);
}

long __fastcall TeXGem::GEMReqStopPolling(BSTR sName)
{
  return  GetDefaultInterface()->GEMReqStopPolling(sName);
}

long __fastcall TeXGem::GEMRspRemoteCommand2(long nMsgId, BSTR sCmd, long nHCAck, long nCount, 
                                             BSTR* psCpName, long* pnCpAck)
{
  return  GetDefaultInterface()->GEMRspRemoteCommand2(nMsgId, sCmd, nHCAck, nCount, psCpName, 
                                                      pnCpAck);
}

long __fastcall TeXGem::GEMReqPPFmtSend2(BSTR sPpid, BSTR sMdln, BSTR sSoftRev, long nCount, 
                                         BSTR* psCCode, long* pnParamCount, BSTR* psParamNames, 
                                         BSTR* psParamValues)
{
  return  GetDefaultInterface()->GEMReqPPFmtSend2(sPpid, sMdln, sSoftRev, nCount, psCCode, 
                                                  pnParamCount, psParamNames, psParamValues);
}

long __fastcall TeXGem::GEMRspPPFmt2(long nMsgId, BSTR sPpid, BSTR sMdln, BSTR sSoftRev, long nCount, 
                                     BSTR* psCCode, long* pnParamCount, BSTR* psParamNames, 
                                     BSTR* psParamValues)
{
  return  GetDefaultInterface()->GEMRspPPFmt2(nMsgId, sPpid, sMdln, sSoftRev, nCount, psCCode, 
                                              pnParamCount, psParamNames, psParamValues);
}


};     // namespace Exgemlib_tlb


// *********************************************************************//
// The Register function is invoked by the IDE when this module is 
// installed in a Package. It provides the list of Components (including
// OCXes) implemented by this module. The following implementation
// informs the IDE of the OCX proxy classes implemented here.
// *********************************************************************//
namespace Exgemlib_ocx
{

void __fastcall PACKAGE Register()
{
  // [1]
  System::Classes::TComponentClass cls_ocx[] = {
                              __classid(Exgemlib_tlb::TeXGem)
                           };
  System::Classes::RegisterComponents("ActiveX", cls_ocx,
                     sizeof(cls_ocx)/sizeof(cls_ocx[0])-1);
}

};     // namespace Exgemlib_ocx
