object FrmQcUnitControl: TFrmQcUnitControl
  Left = 0
  Top = 0
  BorderStyle = bsNone
  Caption = 'FrmQcUnitControl'
  ClientHeight = 95
  ClientWidth = 155
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object CurvyPanel1: TCurvyPanel
    AlignWithMargins = True
    Left = 3
    Top = 3
    Width = 149
    Height = 89
    Align = alClient
    TabOrder = 0
    object Label1: TLabel
      Left = 11
      Top = 27
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
      Top = 54
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
      Left = 62
      Top = 4
      Width = 32
      Height = 14
      Caption = 'UNIT1'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Calibri'
      Font.Style = []
      ParentFont = False
    end
    object EditXSize: TEdit
      Left = 49
      Top = 24
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
      Top = 51
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
  end
end
