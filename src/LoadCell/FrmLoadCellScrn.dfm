object FrmLoadCell: TFrmLoadCell
  Left = 0
  Top = 0
  BorderStyle = bsToolWindow
  ClientHeight = 411
  ClientWidth = 575
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object MemoLoadCelllog: TMemo
    Left = 8
    Top = 160
    Width = 561
    Height = 241
    ImeName = 'Microsoft IME 2010'
    TabOrder = 0
  end
  object BtnLoadCellRead: TButton
    Left = 187
    Top = 8
    Width = 173
    Height = 52
    Caption = 'READ'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Calibri'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = BtnLoadCellReadClick
  end
  object BtnLoadCellConnect: TButton
    Left = 8
    Top = 8
    Width = 173
    Height = 52
    Caption = 'CONNECT'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Calibri'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = BtnLoadCellConnectClick
  end
  object PanelDisplay: TPanel
    Left = 8
    Top = 80
    Width = 561
    Height = 74
    BevelOuter = bvLowered
    Caption = '0.0'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Calibri'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 3
    OnDblClick = PanelDisplayDblClick
  end
  object btnZeroSet: TButton
    Left = 396
    Top = 8
    Width = 173
    Height = 52
    Caption = 'ZERO SET'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Calibri'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = btnZeroSetClick
  end
  object LoadCellPort: TComPort
    BaudRate = br9600
    Port = 'COM1'
    Parity.Bits = prNone
    StopBits = sbOneStopBit
    DataBits = dbEight
    Events = [evRxChar, evTxEmpty, evRxFlag, evRing, evBreak, evCTS, evDSR, evError, evRLSD, evRx80Full]
    FlowControl.OutCTSFlow = False
    FlowControl.OutDSRFlow = False
    FlowControl.ControlDTR = dtrDisable
    FlowControl.ControlRTS = rtsDisable
    FlowControl.XonXoffOut = False
    FlowControl.XonXoffIn = False
    StoredProps = [spBasic]
    TriggersOnRxChar = True
    OnRxChar = LoadCellPortRxChar
    Left = 280
    Top = 16
  end
end
