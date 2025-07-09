program DelphiTestcase;

uses
  Forms,
  fmain in 'fmain.pas' {frmMain},
  kamelaslib in '..\src\kamelaslib.pas';

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TfrmMain, frmMain);
  Application.Run;
end.
