object frmRFIDTestcase: TfrmRFIDTestcase
  Left = 0
  Top = 0
  Caption = 'RFID Testcase - KOSES'
  ClientHeight = 351
  ClientWidth = 267
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Arial'
  Font.Style = []
  OldCreateOrder = False
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 15
  object Button1: TButton
    Left = 16
    Top = 16
    Width = 225
    Height = 25
    Caption = 'Initialize'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Memo1: TMemo
    Left = 16
    Top = 47
    Width = 225
    Height = 266
    ScrollBars = ssVertical
    TabOrder = 1
  end
end
