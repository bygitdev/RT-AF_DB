object frmSetCommonStaubli: TfrmSetCommonStaubli
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'STAUBLI COMMON DATA SETTING'
  ClientHeight = 621
  ClientWidth = 432
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object sgIndex: TStringGrid
    Left = 7
    Top = 48
    Width = 418
    Height = 561
    ColCount = 3
    ScrollBars = ssHorizontal
    TabOrder = 0
    OnDblClick = sgIndexDblClick
    OnDrawCell = sgIndexDrawCell
    ColWidths = (
      64
      241
      105)
  end
  object Panel2: TPanel
    Left = 7
    Top = 8
    Width = 418
    Height = 34
    BevelOuter = bvNone
    Caption = 'POSITION INDEX'
    Color = clGray
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -16
    Font.Name = 'Calibri'
    Font.Style = [fsBold]
    ParentBackground = False
    ParentFont = False
    TabOrder = 1
  end
end
