object frmRFID: TfrmRFID
  Left = 0
  Top = 0
  Caption = 'RFID Communication'
  ClientHeight = 474
  ClientWidth = 539
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Calibri'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 15
  object Label1: TLabel
    Left = 24
    Top = 21
    Width = 63
    Height = 18
    Caption = 'Carrier ID'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 24
    Top = 85
    Width = 31
    Height = 18
    Caption = 'QTY'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 24
    Top = 52
    Width = 41
    Height = 18
    Caption = 'Lot ID'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label5: TLabel
    Left = 24
    Top = 116
    Width = 29
    Height = 18
    Caption = 'Step'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label6: TLabel
    Left = 24
    Top = 149
    Width = 52
    Height = 18
    Caption = 'Part NO'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object EditStep: TEdit
    Left = 110
    Top = 113
    Width = 260
    Height = 26
    BevelInner = bvNone
    BevelOuter = bvNone
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = []
    ImeName = 'Microsoft IME 2010'
    ParentFont = False
    TabOrder = 5
  end
  object EditPartNO: TEdit
    Left = 110
    Top = 146
    Width = 260
    Height = 26
    BevelInner = bvNone
    BevelOuter = bvNone
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = []
    ImeName = 'Microsoft IME 2010'
    ParentFont = False
    TabOrder = 6
  end
  object MemoLog: TMemo
    Left = 0
    Top = 256
    Width = 539
    Height = 218
    Align = alBottom
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Courier New'
    Font.Style = []
    ImeName = 'Microsoft IME 2010'
    ParentFont = False
    ScrollBars = ssBoth
    TabOrder = 0
  end
  object EditCarrierID: TEdit
    Left = 110
    Top = 18
    Width = 260
    Height = 26
    BevelInner = bvNone
    BevelOuter = bvNone
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = []
    ImeName = 'Microsoft IME 2010'
    ParentFont = False
    ReadOnly = True
    TabOrder = 2
  end
  object EditQty: TEdit
    Left = 110
    Top = 82
    Width = 260
    Height = 26
    BevelInner = bvNone
    BevelOuter = bvNone
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = []
    ImeName = 'Microsoft IME 2010'
    ParentFont = False
    TabOrder = 3
  end
  object EditLotID: TEdit
    Left = 110
    Top = 49
    Width = 260
    Height = 26
    BevelInner = bvNone
    BevelOuter = bvNone
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = []
    ImeName = 'Microsoft IME 2010'
    ParentFont = False
    TabOrder = 4
  end
  object btnWrite: TButton
    Left = 257
    Top = 188
    Width = 113
    Height = 50
    Caption = 'Write'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Calibri'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 7
    OnClick = btnWriteClick
  end
  object btnRead: TButton
    Left = 110
    Top = 188
    Width = 113
    Height = 50
    Caption = 'Read'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Calibri'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    OnClick = btnReadClick
  end
  object rgChannel: TRadioGroup
    Left = 396
    Top = 69
    Width = 125
    Height = 55
    Caption = 'CHANNEL'
    Columns = 2
    ItemIndex = 0
    Items.Strings = (
      'CH.1'
      'CH.2')
    TabOrder = 8
  end
  object btnClear: TButton
    Left = 452
    Top = 220
    Width = 69
    Height = 30
    Caption = 'Clear'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Calibri'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 9
    OnClick = btnClearClick
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 200
    OnTimer = Timer1Timer
    Left = 392
    Top = 224
  end
  object Timer2: TTimer
    Enabled = False
    Interval = 200
    OnTimer = Timer2Timer
    Left = 440
    Top = 224
  end
end
