object FrmWarningPopup: TFrmWarningPopup
  Left = 0
  Top = 0
  BorderStyle = bsNone
  Caption = 'WarningPopup'
  ClientHeight = 500
  ClientWidth = 700
  Color = clBlack
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnClose = FormClose
  OnDblClick = FormDblClick
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 0
    Top = 0
    Width = 700
    Height = 400
    Align = alTop
    Alignment = taCenter
    AutoSize = False
    Caption = 'FULL!'
    Color = clWhite
    Font.Charset = ANSI_CHARSET
    Font.Color = clRed
    Font.Height = -267
    Font.Name = 'Calibri'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
    Transparent = True
  end
  object Memo1: TMemo
    Left = 0
    Top = 350
    Width = 700
    Height = 150
    Align = alBottom
    BevelInner = bvNone
    BevelOuter = bvNone
    BorderStyle = bsNone
    Color = clBlack
    Font.Charset = ANSI_CHARSET
    Font.Color = clWhite
    Font.Height = -40
    Font.Name = #47569#51008' '#44256#46357
    Font.Style = [fsBold]
    ImeName = 'Microsoft IME 2003'
    Lines.Strings = (
      '; EMPTY or FULL')
    ParentFont = False
    TabOrder = 0
    WantReturns = False
  end
  object btnManualClose: TBitBtn
    Left = 528
    Top = 8
    Width = 164
    Height = 48
    Caption = 'CLOSE'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Calibri'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    OnClick = FormDblClick
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 500
    OnTimer = Timer1Timer
    Left = 40
    Top = 32
  end
end
