object FrmMultiServo: TFrmMultiServo
  Left = 0
  Top = 0
  BorderStyle = bsNone
  Caption = 'FrmMultiServo'
  ClientHeight = 540
  ClientWidth = 1260
  Color = clInactiveCaptionText
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  DesignSize = (
    1260
    540)
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 1067
    Height = 540
    Anchors = []
    Caption = 'Panel1'
    TabOrder = 0
    DesignSize = (
      1067
      540)
    object Panel3: TPanel
      Left = 8
      Top = 5
      Width = 1051
      Height = 530
      Anchors = []
      Caption = 'Panel3'
      TabOrder = 0
      object GridPanel1: TGridPanel
        Left = 1
        Top = 1
        Width = 1049
        Height = 528
        Align = alClient
        BevelOuter = bvNone
        Caption = 'GridPanel1'
        Color = clInactiveCaptionText
        ColumnCollection = <
          item
            Value = 19.999999999999980000
          end
          item
            Value = 19.999999999999990000
          end
          item
            Value = 20.000000000000000000
          end
          item
            Value = 20.000000000000010000
          end
          item
            Value = 20.000000000000020000
          end>
        ControlCollection = <>
        UseDockManager = False
        ParentBackground = False
        RowCollection = <
          item
            Value = 16.666666666666660000
          end
          item
            Value = 16.666666666666660000
          end
          item
            Value = 16.666666666666660000
          end
          item
            Value = 16.666666666666660000
          end
          item
            Value = 16.666666666666680000
          end
          item
            Value = 16.666666666666680000
          end>
        ShowCaption = False
        TabOrder = 0
      end
    end
  end
  object Panel2: TPanel
    Left = 1065
    Top = -17
    Width = 195
    Height = 573
    Anchors = []
    Caption = 'Panel2'
    TabOrder = 1
    object BtnClear: TBitBtn
      Left = 8
      Top = 392
      Width = 177
      Height = 35
      Caption = 'CLEAR'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      Layout = blGlyphTop
      ParentFont = False
      TabOrder = 0
      WordWrap = True
      OnClick = BtnClearClick
    end
    object BtnServoOn: TBitBtn
      Left = 8
      Top = 474
      Width = 177
      Height = 35
      Caption = 'SERVO ON '
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      Layout = blGlyphTop
      ParentFont = False
      TabOrder = 1
      WordWrap = True
      OnClick = BtnServoOnClick
    end
    object BtnServoOff: TBitBtn
      Left = 8
      Top = 515
      Width = 177
      Height = 35
      Caption = 'SERVO OFF '
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      Layout = blGlyphTop
      ParentFont = False
      TabOrder = 2
      WordWrap = True
      OnClick = BtnServoOffClick
    end
    object strngrd: TStringGrid
      AlignWithMargins = True
      Left = 9
      Top = 22
      Width = 180
      Height = 364
      HelpContext = 180
      ColCount = 1
      DefaultColWidth = 155
      DefaultRowHeight = 20
      FixedCols = 0
      RowCount = 16
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Calibri'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
    end
    object BtnAll: TBitBtn
      Left = 8
      Top = 433
      Width = 177
      Height = 35
      Caption = 'ALL SELECT'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      Layout = blGlyphTop
      ParentFont = False
      TabOrder = 4
      WordWrap = True
      OnClick = BtnAllClick
    end
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 500
    OnTimer = Timer1Timer
    Left = 560
    Top = 256
  end
end
