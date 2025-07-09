object frmJobType: TfrmJobType
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Job Type Selection'
  ClientHeight = 409
  ClientWidth = 388
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
  object SpeedButtonInput: TSpeedButton
    Left = 7
    Top = 357
    Width = 90
    Height = 40
    Caption = 'LIST EDIT'
    OnClick = SpeedButtonInputClick
  end
  object SpeedButtonSave: TSpeedButton
    Left = 103
    Top = 357
    Width = 90
    Height = 40
    Caption = 'LIST SAVE'
    Enabled = False
    OnClick = SpeedButtonSaveClick
  end
  object SpeedButton4: TSpeedButton
    Left = 256
    Top = 357
    Width = 121
    Height = 40
    Caption = 'SELECT TYPE'
    OnClick = SpeedButton4Click
  end
  object StringGrid1: TStringGrid
    Left = 7
    Top = 8
    Width = 370
    Height = 291
    ColCount = 3
    ScrollBars = ssVertical
    TabOrder = 0
    OnSelectCell = StringGrid1SelectCell
    ColWidths = (
      64
      195
      82)
  end
  object PanelName: TPanel
    Left = 78
    Top = 305
    Width = 299
    Height = 30
    BevelOuter = bvLowered
    Caption = 'NAME'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Calibri'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
  end
  object PanelIndex: TPanel
    Left = 7
    Top = 305
    Width = 65
    Height = 30
    BevelOuter = bvLowered
    Caption = '1'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Calibri'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
  end
end
