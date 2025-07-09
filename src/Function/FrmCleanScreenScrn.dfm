object FrmCleanScreen: TFrmCleanScreen
  Left = 0
  Top = 0
  BorderStyle = bsNone
  ClientHeight = 371
  ClientWidth = 807
  Color = -1
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 80
    Top = 96
    Width = 657
    Height = 177
    Color = clSilver
    ParentBackground = False
    TabOrder = 0
    object Label1: TLabel
      Left = 134
      Top = 72
      Width = 485
      Height = 33
      Caption = ' '#52488' '#50504#50640' '#47784#45768#53552' '#49828#53356#47536#51012' '#45798#50500#51452#49901#49884#50836'.'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -27
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object LabelRemainSec: TLabel
      Left = 111
      Top = 71
      Width = 28
      Height = 33
      Alignment = taCenter
      Caption = '30'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -27
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentFont = False
    end
  end
  object CleanTimer: TTimer
    Enabled = False
    OnTimer = CleanTimerTimer
    Left = 680
    Top = 224
  end
end
