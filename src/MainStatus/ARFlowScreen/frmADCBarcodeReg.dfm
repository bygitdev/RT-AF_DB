object frmADBBarcodeReg: TfrmADBBarcodeReg
  Left = 0
  Top = 0
  Caption = 'ADC Barcode Registration'
  ClientHeight = 576
  ClientWidth = 482
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Calibri'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 15
  object sbInput: TSpeedButton
    Left = 0
    Top = 496
    Width = 482
    Height = 40
    Align = alBottom
    Caption = 'INPUT DATA'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Calibri'
    Font.Style = [fsBold]
    ParentFont = False
    OnClick = sbInputClick
    ExplicitTop = 490
    ExplicitWidth = 443
  end
  object sbSave: TSpeedButton
    Left = 0
    Top = 536
    Width = 482
    Height = 40
    Align = alBottom
    Caption = 'SAVE DATA'
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Calibri'
    Font.Style = [fsBold]
    ParentFont = False
    OnClick = sbSaveClick
    ExplicitWidth = 612
  end
  object sgBarcode: TStringGrid
    Left = 0
    Top = 0
    Width = 482
    Height = 496
    Align = alClient
    ColCount = 3
    DefaultRowHeight = 30
    RowCount = 101
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Calibri'
    Font.Style = []
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 0
    ExplicitLeft = -132
    ExplicitTop = 32
    ExplicitWidth = 562
    ExplicitHeight = 437
    ColWidths = (
      64
      254
      132)
  end
end
