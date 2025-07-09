object frmRoute: TfrmRoute
  Left = 0
  Top = 0
  Align = alClient
  BorderStyle = bsNone
  Caption = 'frmRoute'
  ClientHeight = 848
  ClientWidth = 1278
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 1278
    Height = 848
    Align = alClient
    BevelOuter = bvNone
    Caption = 'Gerber Program Loading...'
    Color = 6965248
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clHighlightText
    Font.Height = -32
    Font.Name = 'Calibri'
    Font.Style = [fsBold]
    ParentBackground = False
    ParentFont = False
    TabOrder = 0
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 800
    OnTimer = Timer1Timer
    Left = 192
    Top = 184
  end
end
