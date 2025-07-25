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
#ifndef   XCYREMLib_OCXH
#define   XCYREMLib_OCXH

#pragma option push -b -a4 -w-inl -w-8118

#include <olectrls.hpp>
#include <oleserver.hpp>
#if !defined(__UTILCLS_H)
#include <utilcls.h>
#endif
#if !defined(__UTILCLS_H_VERSION) || (__UTILCLS_H_VERSION < 0x0700)
//
// The code generated by the TLIBIMP utility or the Import|TypeLibrary 
// and Import|ActiveX feature of C++Builder rely on specific versions of
// the header file UTILCLS.H found in the INCLUDE\VCL directory. If an 
// older version of the file is detected, you probably need an update/patch.
//
#error "This file requires a newer version of the header UTILCLS.H" \
       "You need to apply an update/patch to your copy of C++Builder"
#endif
#include <olectl.h>
#include <ocidl.h>
#if !defined(_NO_VCL)
#include <System.Win.StdVCL.hpp>
#endif  //   _NO_VCL
#include <ocxproxy.h>

#include "XCYREMLib_TLB.h"
namespace Xcyremlib_tlb
{

// *********************************************************************//
// HelpString: XCyRem ActiveX Control module
// Version:    1.0
// *********************************************************************//


// *********************************************************************//
// COM Component Proxy Class Declaration
// Component Name   : TXCyRem
// Help String      : XCyRem Control
// Default Interface: _DXCyRem
// Def. Intf. Object: _DXCyRemDisp
// Def. Intf. DISP? : Yes
// Event   Interface: _DXCyRemEvents
// TypeFlags        : (34) CanCreate Control
// *********************************************************************//

// *********************************************************************//
// Definition of closures to allow VCL handlers to catch OCX events.      
// *********************************************************************//
typedef void __fastcall (__closure * TXCyRemOnContinuousEvent)(System::TObject * Sender, 
                                                               BSTR rcvPacket);
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
// Proxy class to host XCyRem Control in CBuilder IDE/Applications.
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
class PACKAGE TXCyRem : public Vcl::Olectrls::TOleControl
{
  OVERLOADED_PROP_METHODS;
  static TNoParam  OptParam;
  static GUID      DEF_CTL_INTF;

  // Instance of Closures to expose OCX Events as VCL ones
  //
  TXCyRemOnContinuousEvent       FOnContinuousEvent;

  // Default Interace of OCX
  //
  _DXCyRemDisp m_OCXIntf;

  // VCL Property Getters/Setters which delegate to OCX
  //

  // Static variables used by all instances of OCX proxy
  //
  static int          EventDispIDs[1];
  static Vcl::Olectrls::TControlData2 CControlData;
  static GUID          CTL_DEF_INTF;

  // Method providing access to interface as __property 
  //
  _DXCyRemDisp __fastcall GetDefaultInterface();
  _DXCyRemDisp __fastcall GetControlInterface()
  { return GetDefaultInterface(); }

protected:
  void     __fastcall CreateControl  ();
  void     __fastcall InitControlData();

public:
  virtual  __fastcall TXCyRem(System::Classes::TComponent* AOwner) : Vcl::Olectrls::TOleControl(AOwner)
  {};
  virtual  __fastcall TXCyRem(HWND        Parent) : Vcl::Olectrls::TOleControl(Parent)
  {};

  // OCX methods
  //
  long            __fastcall InitializePort(void);
  long            __fastcall ReadRegistry(short RegisterAddr);
  long            __fastcall WriteRegistry(short RegistryAddr, short RegistryValue);
  long            __fastcall ReadTag(short ChannelNo, short TagAddr, short ByteToRead);
  long            __fastcall WriteTag(short ChannelNo, short TagAddr, BSTR TagData);
  void            __fastcall ReleasePort(void);
  void            __fastcall GetSerialNumber(void);
  void            __fastcall AboutBox(void);

  // OCX properties
  //
  __property _DXCyRemDisp ControlInterface={ read=GetDefaultInterface };

  // Published properties
  //
__published:

  // Standard/Extended properties
  //
  __property TabStop;
  __property Align;
  __property DragCursor;
  __property DragMode;
  __property ParentShowHint;
  __property PopupMenu;
  __property ShowHint;
  __property TabOrder;
  __property Visible;
  __property OnDragDrop;
  __property OnDragOver;
  __property OnEndDrag;
  __property OnEnter;
  __property OnExit;
  __property OnStartDrag;

  // OCX properties
  //
  __property short Port={ read=GetSmallintProp, write=SetSmallintProp, stored=false, index=1 };
  __property int Speed={ read=GetIntegerProp, write=SetIntegerProp, stored=false, index=2 };

  // OCX Events
  //
  __property TXCyRemOnContinuousEvent OnContinuousEvent={ read=FOnContinuousEvent, write=FOnContinuousEvent };
};
typedef TXCyRem  TXCyRemProxy;

};     // namespace Xcyremlib_tlb

#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using  namespace Xcyremlib_tlb;
#endif

#pragma option pop

#endif // XCYREMLib_OCXH
