unit Rfid;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, AssButton, StdCtrls, ExtCtrls, AssLEDBtn, Mask, AssEdit,
  AssInstEditor, AssLED, AssComm;

type
  TfrmRfid = class(TForm)
    Panel1: TPanel;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    lblMessage: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    btnRfidRead: TAssBitBtn;
    btnRfidWrite: TAssBitBtn;
    EditRfidStep: TAssInstEdit;
    EditRfidLotId: TAssInstEdit;
    EditRfidPartNo: TAssInstEdit;
    btnStepNo: TAssLEDBtn;
    btnLotNo: TAssLEDBtn;
    btnPratNo: TAssLEDBtn;
    btnMgzId: TAssLEDBtn;
    EditRfidMgzId: TAssInstEdit;
    btnFrameCount: TAssLEDBtn;
    EditRfidFrameCnt: TAssInstEdit;
    RadioSelectRfidType: TRadioGroup;
    BtnSkinnerXP: TAssBtnSkinner;
    RfidRead: TAssComm;
    btnConnect: TAssBitBtn;
    btnDisConnect: TAssBitBtn;
    ledReadOk: TAssLED;
    ledWrithOk: TAssLED;
    procedure btnRfidReadClick(Sender: TObject);
    procedure RFIDReaderData(Device,Channel,Address,Count : String);
    procedure btnConnectClick(Sender: TObject);
    procedure btnDisConnectClick(Sender: TObject);
    function  MakeRFIDCheckSum(szCmd : String) : String;
    procedure FormShow(Sender: TObject);
    procedure RfidReadEventCharReceived(Sender: TObject;
      const ACount: Integer);
    procedure RFIDOnLoaderReadAllData(ReadAll : String);  // 전체 Data를 Read 후에 쪼개어 저장한다...
    function  MakeHexToChr(szCmd : String) : String;
    procedure btnRfidWriteClick(Sender: TObject);
    procedure RFIDWriteData(Device,Channel,Address,Count,WData : String);  //WRITE
    function  MakeASCIIToHex(szCmd : String) : String;
    function  Space(Source: String; ch : integer): String;
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  frmRfid: TfrmRfid;

implementation

{$R *.dfm}

procedure TfrmRfid.btnRfidReadClick(Sender: TObject);
begin
  EditRfidStep.Clear;
  EditRfidLotId.Clear;
  EditRfidPartNo.Clear;
  EditRfidMgzId.Clear;
  EditRfidFrameCnt.Clear;

  btnStepNo.LED.Value := False;
  btnMgzId.LED.Value := False;
  btnLotNo.LED.Value := False;
  btnFrameCount.LED.Value := False;
  btnPratNo.LED.Value := False;

  Case RadioSelectRfidType.ItemIndex Of
    0 :
    begin
      RFIDReaderData('01','80','00', '111');
    end;
    1 :
    begin
      RFIDReaderData('01','81','00', '111');
    end;
  end;
end;

procedure TfrmRfid.RFIDReaderData(Device,Channel,Address,Count : String);
var
  szCheckSum, szTotal, szTemp, szData : String;
  szAddress, szCount : String;
begin
  If StrToIntDef(Address,0) >= 10 then
  begin
    szAddress := IntToHex(StrToIntDef(Address,0),2);
  end
  else
  begin
    szAddress := Address;
  end;

  If StrToIntDef(Count,0) >= 10 then
  begin
    szCount := IntToHex(StrToIntDef(Count,0),2);
  end
  else
  begin
    szCount := Count;
  end;

  szTotal := Device+Channel+szAddress+szCount;
  szTemp := MakeRFIDCheckSum(Chr(05)+szTotal);
  szCheckSum := Copy(szTemp,Length(szTemp)-1,Length(szTemp));

  szData := (chr(05)+szTotal+szCheckSum+chr(03));

  RFIDRead.WriteString(chr(05)+szTotal+szCheckSum+chr(03));
end;

procedure TfrmRfid.btnConnectClick(Sender: TObject);
begin
  RfidRead.OpenComm;
end;

procedure TfrmRfid.btnDisConnectClick(Sender: TObject);
begin
  RfidRead.CloseComm;
end;

function TfrmRfid.MakeRFIDCheckSum(szCmd: String): String;
var
  temp : Word;
  i, j : integer;
begin
  temp := 0;
  i := Length(szCmd);
  for j := 1 to i do
  begin
		//temp := temp xor ord(szCmd[j]);
    temp := temp + ord(szCmd[j]);
  end;
  result := IntToHex(temp,2);
end;


procedure TfrmRfid.FormShow(Sender: TObject);
begin
  RfidRead.OpenComm;
  RadioSelectRfidType.ItemIndex := 0;
  ledReadOk.LED.Value := False;
  ledWrithOk.LED.Value := False;
end;

procedure TfrmRfid.RfidReadEventCharReceived(Sender: TObject;
  const ACount: Integer);
var
  szData,szReaDdata,szTemp : String;
begin
  szData    := '';
  szReaDdata:= '';
  szTemp    := '';

  szData := RfidRead.ReadString;
  If Length(szData) > 5 then
  begin
    If Copy(szData,1,1) = Chr(02) then //Read명령 정상 응답...STX
    begin
      szTemp := Copy(szData,Pos(chr(02),szData)+5,LENGTH(szData)-1);
      szReadData := MakeHexToChr(Copy(szTemp,1,Pos(chr(03),szTemp)-1));

      // RFID Tag Data의 전체를 읽어들여 부분마다 쪼갠다...
      RFIDOnLoaderReadAllData(szReaDdata);
      ledReadOk.LED.Value := True;
    end
    else If Copy(szData,1,1) = Chr(06) then //WRITE명령 정상 응답...ACK
    begin
      ledWrithOk.LED.Value := True;
    end
    else If Copy(szData,1,1) = Chr(21) then //Read,Write..비정상 응답..NAK
    begin
      szTemp := Copy(szData,Pos(chr(21),szData)+5,LENGTH(szData)-1);
      szReadData := '$'+Copy(szTemp,1,2);
      ledReadOk.LED.Value := False;
      ledWrithOk.LED.Value := False;
    end;
  end;
end;

function TfrmRfid.MakeHexToChr(szCmd: String): String;
var
  szTemp,szHex,szChr : String;
  i,j,TmpLength    : integer;
begin
  //Hex는 무조건 2자리씩 끈으면 됨~~~~~
  szTemp   :=szCmd;
  TmpLength:= Trunc(Length(szCmd)/2);
  j:= 1;
  for i := 1 to TmpLength do // 2자리씩 끈으야 하니까~~~
  begin
    szHex  :=Copy(szTemp,j,2);
    If Length(szHex) <= 0 then Exit;
    szChr  := szChr + Chr(StrToInt('$'+szHex)); //Hex를-->문자로...
    j := j+2;
  end;
  result := szChr;
end;


procedure TfrmRfid.RFIDOnLoaderReadAllData(ReadAll : String);  // 전체 Data를 Read 후에 쪼개어 저장한다...

var
  szMgzId, szLotNo, szStepNo, szPartNo, szPGKCode, szFrameCount : String;
  szNextLotNo, szRfidPartNo, szEditPartNo : String;
begin
  szMgzId := Copy(ReadAll, 1, 8);
  szLotNo := Copy(ReadAll, 29, 12);
  szStepNo := Copy(ReadAll, 41, 8);
  szPartNo := Copy(ReadAll, 49, 28);
  szPGKCode := Copy(ReadAll, 77, 4);
  szFrameCount := Copy(ReadAll, 109, 4);

  // Manual Read 시에는 Data 저장 하지 않는다. 화면에 Display만 함...
  EditRfidStep.Text := szStepNo;
  EditRfidLotId.Text := szLotNo;
  EditRfidPartNo.Text := szPartNo;
  EditRfidMgzId.Text := szMgzId;
  EditRfidFrameCnt.Text := szFrameCount;


  If szStepNo <> '' then
    btnStepNo.LED.Value := True;
  If szLotNo <> '' then
    btnLotNo.LED.Value := True;
  If szPartNo <> '' then
    btnPratNo.LED.Value := True;
  If szMgzId <> '' then
    btnMgzId.LED.Value := True;
  If szFrameCount <> '' then
    btnFrameCount.LED.Value := True;

end;



procedure TfrmRfid.btnRfidWriteClick(Sender: TObject);
var
  szStep,szLotId,szPartNo,szFrameCount, szDeviceName, szToolName :String;
begin
  Case RadioSelectRfidType.ItemIndex Of
    0 : // OnLoader
    begin
      if (EditRfidStep.Text <> '') and (EditRfidLotId.Text <> '') and (EditRfidPartNo.Text <> '')  then  //and (EditRfidMgzId.Text <> '')
      begin
        szStep   := Trim(EditRfidStep.Text);
        szLotId  := Trim(EditRfidLotId.Text);
        szPartNo := Trim(EditRfidPartNo.Text);
        szFrameCount :=Trim(EditRfidFrameCnt.Text);

        RFIDWriteData('01','90','40','08',szStep);
        RFIDWriteData('01','90','28','12',szLotId);
        RFIDWriteData('01','90','48','28',szPartNo);
        RFIDWriteData('01','90','108','04',szFrameCount);

        Sleep(2000);
        btnRfidReadClick(Self);
      end;
    end;
    1 :
    begin
      if (EditRfidStep.Text <> '') and (EditRfidLotId.Text <> '') and (EditRfidPartNo.Text <> '')  then  //and (EditRfidMgzId.Text <> '')
      begin
        szStep   := Trim(EditRfidStep.Text);
        szLotId  := Trim(EditRfidLotId.Text);
        szPartNo := Trim(EditRfidPartNo.Text);
        szFrameCount :=Trim(EditRfidFrameCnt.Text);

        RFIDWriteData('01','91','40','08',szStep);
        RFIDWriteData('01','91','28','12',szLotId);
        RFIDWriteData('01','91','48','28',szPartNo);
        RFIDWriteData('01','91','108','04',szFrameCount);

        Sleep(2000);
        btnRfidReadClick(Self);
      end;
    end;
  end;
end;

procedure TfrmRfid.RFIDWriteData(Device, Channel, Address, Count,WData: String);
var
  szTemp, szTotal : String;
  szCheckSum, szAddress, szCount : String;
  szWDataHex, szSpaceData : String;
begin
  If StrToIntDef(Address,0) >= 10 then
  begin
    szAddress := IntToHex(StrToIntDef(Address,0),2);
  end
  else
  begin
    szAddress := Address;
  end;

  If (StrToIntDef(Count,0)) >= 10 then
  begin
    szCount := IntToHex(StrToIntDef(Count,0),2);
  end
  else
  begin
    szCount := Count;
  end;
  szSpaceData := Space(WData,StrToIntDef(Count,0)-1);
  szWDataHex  := MakeASCIIToHex(szSpaceData);

  szTotal   := Device+Channel+szAddress+szCount+szWDataHex;
  szTemp    := MakeRFIDCheckSum(Chr(05)+szTotal);
  szCheckSum:= Copy(szTemp,Length(szTemp)-1,Length(szTemp));

  RFIDRead.WriteString(chr(05)+szTotal+szCheckSum+chr(03));
end;

function TfrmRfid.MakeASCIIToHex(szCmd: String): String;
var
  Temp : String;
  i    : integer;
begin
  //Temp := 0;
  for i := 1 to Length(szCmd) do
  begin
    Temp := Temp + IntToHex(ord(szCmd[i]),2);
  end;
  Result := Temp;
  //Result := IntToHex(Temp, 2);
end;

function TfrmRfid.Space(Source: String; ch : integer): String;
Var
  i,j : integer;
  szTmp : String;
Begin
  i := Length(Source);
  for j := i to ch  do
  Begin
    szTmp := szTmp + ' ';
  End;
  Result := source + szTmp;
End;





procedure TfrmRfid.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  RfidRead.CloseComm;
end;

end.
