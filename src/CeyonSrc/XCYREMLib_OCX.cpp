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
// File generated on 2016-08-10 오전 8:34:56 from Type Library described below.

// ************************************************************************  //
// Type Lib: XCyRem.ocx (1)
// LIBID: {97E1D90C-0265-469F-B9D4-F030A9A642D3}
// LCID: 0
// Helpfile: E:\XCyRem.hlp 
// HelpString: XCyRem ActiveX Control module
// DepndLst: 
//   (1) v2.0 stdole, (C:\Windows\SysWOW64\stdole2.tlb)
// SYS_KIND: SYS_WIN32
// Cmdline:
//   tlibimp  -C XCyRem.ocx
// ************************************************************************ //

#include <vcl.h>
#pragma hdrstop

#include <olectrls.hpp>
#include <oleserver.hpp>
#if defined(USING_ATL)
#include <atl\atlvcl.h>
#endif

#pragma option -w-8122
#include "XCYREMLib_OCX.h"

#if !defined(__PRAGMA_PACKAGE_SMART_INIT)
#define      __PRAGMA_PACKAGE_SMART_INIT
#pragma package(smart_init)
#endif

namespace Xcyremlib_tlb
{



// *********************************************************************//
// OCX PROXY CLASS IMPLEMENTATION
// (The following variables/methods implement the class TXCyRem which
// allows "XCyRem Control" to be hosted in CBuilder IDE/apps).
// *********************************************************************//
int   TXCyRem::EventDispIDs[1] = {
    0x00000001};

Vcl::Olectrls::TControlData2 TXCyRem::CControlData =
{
  // GUID of CoClass and Event Interface of Control
  {0x9CDB6631, 0x6E9A, 0x4DD4,{ 0xB3, 0x20, 0x96,0x41, 0xE6, 0xD8,0xB8, 0x0E} }, // CoClass
  {0xDB4A336F, 0xFD06, 0x4FF4,{ 0xBA, 0x44, 0x50,0xDE, 0x61, 0x1B,0x54, 0xC2} }, // Events

  // Count of Events and array of their DISPIDs
  1, &EventDispIDs,

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

GUID     TXCyRem::DEF_CTL_INTF = {0xCF18A10A, 0x39E9, 0x4323,{ 0x96, 0x1E, 0xB1,0x53, 0xE1, 0xA5,0x75, 0xEC} };
TNoParam TXCyRem::OptParam;

static inline void ValidCtrCheck(TXCyRem *)
{
   delete new TXCyRem((System::Classes::TComponent*)(0));
};

void __fastcall TXCyRem::InitControlData()
{
  ControlData = (Vcl::Olectrls::TControlData*)&CControlData;
  CControlData.FirstEventOfs = System::PByte(&FOnContinuousEvent) - System::PByte(this);
};

void __fastcall TXCyRem::CreateControl()
{
  if (!m_OCXIntf)
  {
    _ASSERTE(DefaultDispatch);
    DefaultDispatch->QueryInterface(DEF_CTL_INTF, (LPVOID*)&m_OCXIntf);
  }
};

_DXCyRemDisp __fastcall TXCyRem::GetDefaultInterface()
{
  CreateControl();
  return m_OCXIntf;
};

long __fastcall TXCyRem::InitializePort(void)
{
  return  GetDefaultInterface()->InitializePort();
}

long __fastcall TXCyRem::ReadRegistry(short RegisterAddr)
{
  return  GetDefaultInterface()->ReadRegistry(RegisterAddr);
}

long __fastcall TXCyRem::WriteRegistry(short RegistryAddr, short RegistryValue)
{
  return  GetDefaultInterface()->WriteRegistry(RegistryAddr, RegistryValue);
}

long __fastcall TXCyRem::ReadTag(short ChannelNo, short TagAddr, short ByteToRead)
{
  return  GetDefaultInterface()->ReadTag(ChannelNo, TagAddr, ByteToRead);
}

long __fastcall TXCyRem::WriteTag(short ChannelNo, short TagAddr, BSTR TagData)
{
  return  GetDefaultInterface()->WriteTag(ChannelNo, TagAddr, TagData);
}

void __fastcall TXCyRem::ReleasePort(void)
{
  GetDefaultInterface()->ReleasePort();
}

void __fastcall TXCyRem::GetSerialNumber(void)
{
  GetDefaultInterface()->GetSerialNumber();
}

void __fastcall TXCyRem::AboutBox(void)
{
  GetDefaultInterface()->AboutBox();
}


};     // namespace Xcyremlib_tlb


// *********************************************************************//
// The Register function is invoked by the IDE when this module is 
// installed in a Package. It provides the list of Components (including
// OCXes) implemented by this module. The following implementation
// informs the IDE of the OCX proxy classes implemented here.
// *********************************************************************//
namespace Xcyremlib_ocx
{

void __fastcall PACKAGE Register()
{
  // [1]
  System::Classes::TComponentClass cls_ocx[] = {
                              __classid(Xcyremlib_tlb::TXCyRem)
                           };
  System::Classes::RegisterComponents("ActiveX", cls_ocx,
                     sizeof(cls_ocx)/sizeof(cls_ocx[0])-1);
}

};     // namespace Xcyremlib_ocx
