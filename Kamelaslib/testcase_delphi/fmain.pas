unit fmain;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, kamelaslib;

type
  TfrmMain = class(TForm)
    Button1: TButton;
    Edit1: TEdit;
    Button2: TButton;
    GroupBox1: TGroupBox;
    Button3: TButton;
    Button5: TButton;
    Button4: TButton;
    Memo1: TMemo;
    Edit2: TEdit;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure Button5Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
  private
    AKalemasBase : TKamelasBase;
  public
    { Public declarations }
  end;

var
  frmMain: TfrmMain;

implementation



{$R *.dfm}

procedure TfrmMain.Button1Click(Sender: TObject);
begin
    Self.AKalemasBase := CreateSharedMemory(False, PAnsiChar(Edit1.Text), 1024*20);    //1Kbytes
    Assert(nil <> Self.AKalemasBase);
    Memo1.Lines.Add(Edit1.Text + ' Created' );
end;

procedure TfrmMain.Button2Click(Sender: TObject);
begin
    Assert(nil <> Self.AKalemasBase);
    DestroySharedMemory( Self.AKalemasBase);
    Self.AKalemasBase := nil;
    Memo1.Lines.Add(Edit1.Text + ' Destroyed' );    
end;

procedure TfrmMain.Button3Click(Sender: TObject);
var
    ch : array[0..(1024*20)] of Char;
    ASuccess : Boolean;    
begin
    StrLCopy( ch, PChar(Edit2.Text) , High(ch));
    ASuccess := False;

    // send 가 실패할경우 SEQ 가 동작되지 않는 상태임
    // recv 가 실패할경우 SEQ 가 send 에 대한 응답을 시간을 초과한 상태임
    
    if Self.AKalemasBase.send(Addr(ch), 50) then
        ASuccess := Self.AKalemasBase.recv( Addr(ch), 50);

    if ASuccess then
        Memo1.Lines.Add('Success to send/recv' )
    else
        Memo1.Lines.Add('Fail to send/recv' );
end;

procedure TfrmMain.Button4Click(Sender: TObject);
var
    ASuccess : Boolean;
begin
   ASuccess := Self.AKalemasBase.open();
   Assert(ASuccess = True);
    Memo1.Lines.Add(Edit1.Text + ' Opened' );
end;

procedure TfrmMain.Button5Click(Sender: TObject);
begin
    Self.AKalemasBase.close();
    Memo1.Lines.Add(Edit1.Text + ' Closed' );    
end;

end.
