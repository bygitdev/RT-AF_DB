unit kamelaslib;

/////////////////////////////////////////////////////////////////////////////
//
//  Project
//	    K.A.M.E.L.A.S
//
//
//  Introduction
//	    issue tracker : http://cpp.koses.co.kr/projects/kframework
//	    git repository : userid@cpp.koses.co.kr:/srv/repos/git/kframework.git
//
//
//  Copyrights
//  	hcchoi ( hcchoi@koses.co.kr )
//
//
//  Version History
//  	2009.?		first release
//	    2013.8.		ported for delphi environment
//
//
//  Comments
//      이 라이브러리 (가칭 까멜라스)는 MMI, SEQ 와 같이 서로 다른 프로세스간의 통신(IPC)를
//      지원하기 위해 만들어진 것으로, 서로 공유 이름과 공유 데이타 구조체를 외부 헤더 파일등을
//      통해 공유하고, MMI 측은 SEQ에게 명령을 전달하고, 해당 명령이 정상적으로 전달되었는지 여부를
//      타임아웃등을 통해 확인가능하고, SEQ 측은 매 싸이클 마다 MMI 로 부터 명령이 수신되었는지 여부를
//      대기하여 명령이 있을 경우 이를 조속한 시간내에 처리한후 응답을 주도록 한다.
//      내부적으로는 공유 메모리를 사용하고, 이를 통해 데이타를 주고, 받는 용도로 사용하고 있다.
//
//
/////////////////////////////////////////////////////////////////////////////
 
interface

uses
  Classes, SysUtils, Windows;

const
  DLL_NAME = 'kamelaslib.dll';

type
  TKamelasBase = class
  public
    function open(): Boolean; virtual; stdcall; abstract;   /// 통신 개방
    function close(): Boolean; virtual; stdcall; abstract;  /// 통신 닫기
    function isOpen(): Boolean; virtual; stdcall; abstract; /// 통신 개방 여부
    function name(): PAnsiChar; virtual; stdcall; abstract; /// 통신 채널 식별용 이름 ( 두 프로세스는 서로 동일한 이름 사용해야 함)
    function size(): Integer; virtual; stdcall; abstract;   /// 통신 채널 크기 (바이트)
    function recv(APointer: Pointer; Milliseconds: Integer): Boolean; virtual; stdcall; abstract;     /// 데이타 수신및 타임아웃(msec)
    function send(APointer: Pointer; Milliseconds: Integer): Boolean; virtual; stdcall;  abstract;    /// 데이타 송신및 타임아웃(msec)
  end;

function CreateKamelas(AServer: Boolean; ASharedName: PAnsiChar; ASizeBytes: Integer): TKamelasBase; stdcall; external DLL_NAME;  /// TKamelasBase 생성
procedure DestroyKamelas(AKamelasBase: TKamelasBase); stdcall; external DLL_NAME; /// TKamelasBase 삭제

implementation


end.

