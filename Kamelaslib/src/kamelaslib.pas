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
//      �� ���̺귯�� (��Ī ����)�� MMI, SEQ �� ���� ���� �ٸ� ���μ������� ���(IPC)��
//      �����ϱ� ���� ������� ������, ���� ���� �̸��� ���� ����Ÿ ����ü�� �ܺ� ��� ���ϵ���
//      ���� �����ϰ�, MMI ���� SEQ���� ����� �����ϰ�, �ش� ����� ���������� ���޵Ǿ����� ���θ�
//      Ÿ�Ӿƿ����� ���� Ȯ�ΰ����ϰ�, SEQ ���� �� ����Ŭ ���� MMI �� ���� ����� ���ŵǾ����� ���θ�
//      ����Ͽ� ����� ���� ��� �̸� ������ �ð����� ó������ ������ �ֵ��� �Ѵ�.
//      ���������δ� ���� �޸𸮸� ����ϰ�, �̸� ���� ����Ÿ�� �ְ�, �޴� �뵵�� ����ϰ� �ִ�.
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
    function open(): Boolean; virtual; stdcall; abstract;   /// ��� ����
    function close(): Boolean; virtual; stdcall; abstract;  /// ��� �ݱ�
    function isOpen(): Boolean; virtual; stdcall; abstract; /// ��� ���� ����
    function name(): PAnsiChar; virtual; stdcall; abstract; /// ��� ä�� �ĺ��� �̸� ( �� ���μ����� ���� ������ �̸� ����ؾ� ��)
    function size(): Integer; virtual; stdcall; abstract;   /// ��� ä�� ũ�� (����Ʈ)
    function recv(APointer: Pointer; Milliseconds: Integer): Boolean; virtual; stdcall; abstract;     /// ����Ÿ ���Ź� Ÿ�Ӿƿ�(msec)
    function send(APointer: Pointer; Milliseconds: Integer): Boolean; virtual; stdcall;  abstract;    /// ����Ÿ �۽Ź� Ÿ�Ӿƿ�(msec)
  end;

function CreateKamelas(AServer: Boolean; ASharedName: PAnsiChar; ASizeBytes: Integer): TKamelasBase; stdcall; external DLL_NAME;  /// TKamelasBase ����
procedure DestroyKamelas(AKamelasBase: TKamelasBase); stdcall; external DLL_NAME; /// TKamelasBase ����

implementation


end.

