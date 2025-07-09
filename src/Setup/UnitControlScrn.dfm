object FrmUnitControl: TFrmUnitControl
  Left = 0
  Top = 0
  BorderStyle = bsNone
  ClientHeight = 160
  ClientWidth = 230
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
  object CurvyPanel1: TCurvyPanel
    AlignWithMargins = True
    Left = 3
    Top = 3
    Width = 224
    Height = 154
    Align = alClient
    TabOrder = 0
    object Label1: TLabel
      Left = 11
      Top = 35
      Width = 31
      Height = 15
      Caption = 'X Size'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 11
      Top = 62
      Width = 31
      Height = 15
      Caption = 'Y Size'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object LabelNotify: TLabel
      Left = 94
      Top = 6
      Width = 45
      Height = 19
      Caption = 'UNIT 1'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label3: TLabel
      Left = 11
      Top = 89
      Width = 31
      Height = 15
      Caption = 'Theta'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object EditXSize: TEdit
      Left = 49
      Top = 32
      Width = 90
      Height = 23
      Alignment = taCenter
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ImeName = 'Microsoft IME 2010'
      ParentFont = False
      TabOrder = 0
      Text = '0.0'
    end
    object EditYSize: TEdit
      Left = 49
      Top = 59
      Width = 90
      Height = 23
      Alignment = taCenter
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ImeName = 'Microsoft IME 2010'
      ParentFont = False
      TabOrder = 1
      Text = '0.0'
    end
    object PanelFlip: TPanel
      Left = 49
      Top = 112
      Width = 160
      Height = 26
      Caption = 'FLIP OFF'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Calibri'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 2
      OnDblClick = PanelFlipDblClick
    end
    object EditTheta: TEdit
      Left = 49
      Top = 86
      Width = 90
      Height = 23
      Alignment = taCenter
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ImeName = 'Microsoft IME 2010'
      ParentFont = False
      TabOrder = 3
      Text = '0.0'
    end
    object CSpinEditBinNo: TCSpinEdit
      Left = 145
      Top = 32
      Width = 64
      Height = 74
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -53
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      MaxValue = 99
      MinValue = 1
      ParentFont = False
      TabOrder = 4
      Value = 1
    end
  end
end
