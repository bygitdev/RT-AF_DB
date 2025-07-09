object FrmCommonSet: TFrmCommonSet
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'COMMON DATA SETTING'
  ClientHeight = 529
  ClientWidth = 709
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object StringGridAxis: TStringGrid
    Left = 24
    Top = 56
    Width = 241
    Height = 449
    ColCount = 2
    ScrollBars = ssHorizontal
    TabOrder = 0
    OnSelectCell = StringGridAxisSelectCell
    ColWidths = (
      64
      170)
  end
  object StringGridPosition: TStringGrid
    Left = 271
    Top = 56
    Width = 418
    Height = 449
    ColCount = 3
    ScrollBars = ssHorizontal
    TabOrder = 1
    OnDblClick = StringGridPositionDblClick
    OnDrawCell = StringGridPositionDrawCell
    ColWidths = (
      64
      241
      105)
  end
  object Panel1: TPanel
    Left = 24
    Top = 16
    Width = 241
    Height = 34
    BevelOuter = bvNone
    Caption = 'AXIS'
    Color = clGray
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -16
    Font.Name = 'Calibri'
    Font.Style = [fsBold]
    ParentBackground = False
    ParentFont = False
    TabOrder = 2
  end
  object Panel2: TPanel
    Left = 271
    Top = 16
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
    TabOrder = 3
  end
end
