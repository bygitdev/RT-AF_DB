object frmSelectAxis: TfrmSelectAxis
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  ClientHeight = 735
  ClientWidth = 1029
  Color = 8404992
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object GridPanel1: TGridPanel
    AlignWithMargins = True
    Left = 5
    Top = 5
    Width = 1019
    Height = 725
    Margins.Left = 5
    Margins.Top = 5
    Margins.Right = 5
    Margins.Bottom = 5
    Align = alClient
    BevelOuter = bvNone
    Caption = 'GridPanel1'
    Color = clGrayText
    ColumnCollection = <
      item
        SizeStyle = ssAbsolute
        Value = 250.000000000000000000
      end
      item
        Value = 100.000000000000000000
      end>
    ControlCollection = <
      item
        Column = 1
        Control = GridPanelAxis
        Row = 0
      end
      item
        Column = 0
        Control = GridPanelCategory
        Row = 0
      end>
    ParentBackground = False
    RowCollection = <
      item
        Value = 100.000000000000000000
      end>
    ShowCaption = False
    TabOrder = 0
    ExplicitLeft = 336
    ExplicitTop = 288
    ExplicitWidth = 185
    ExplicitHeight = 41
    object GridPanelAxis: TGridPanel
      AlignWithMargins = True
      Left = 253
      Top = 3
      Width = 763
      Height = 719
      Align = alClient
      Caption = 'GridPanelAxis'
      ColumnCollection = <
        item
          Value = 25.000000000000000000
        end
        item
          Value = 25.000000000000000000
        end
        item
          Value = 25.000000000000000000
        end
        item
          Value = 25.000000000000000000
        end>
      ControlCollection = <>
      ExpandStyle = emAddColumns
      ParentBackground = False
      RowCollection = <
        item
          Value = 6.250000000000000000
        end
        item
          Value = 6.250000000000000000
        end
        item
          Value = 6.250000000000000000
        end
        item
          Value = 6.250000000000000000
        end
        item
          Value = 6.250000000000000000
        end
        item
          Value = 6.250000000000000000
        end
        item
          Value = 6.250000000000000000
        end
        item
          Value = 6.250000000000000000
        end
        item
          Value = 6.250000000000000000
        end
        item
          Value = 6.250000000000000000
        end
        item
          Value = 6.250000000000000000
        end
        item
          Value = 6.250000000000000000
        end
        item
          Value = 6.250000000000000000
        end
        item
          Value = 6.250000000000000000
        end
        item
          Value = 6.250000000000000000
        end
        item
          Value = 6.250000000000000000
        end>
      ShowCaption = False
      TabOrder = 0
      ExplicitLeft = 421
      ExplicitTop = 291
      ExplicitWidth = 185
      ExplicitHeight = 41
    end
    object GridPanelCategory: TGridPanel
      AlignWithMargins = True
      Left = 3
      Top = 3
      Width = 244
      Height = 719
      Align = alClient
      Caption = 'GridPanelCategory'
      ColumnCollection = <
        item
          Value = 100.000000000000000000
        end>
      ControlCollection = <
        item
          Column = 0
          Control = ButtonAll
          Row = 0
        end>
      ParentBackground = False
      RowCollection = <
        item
          Value = 6.250000000000000000
        end
        item
          Value = 6.250000000000000000
        end
        item
          Value = 6.250000000000000000
        end
        item
          Value = 6.250000000000000000
        end
        item
          Value = 6.250000000000000000
        end
        item
          Value = 6.250000000000000000
        end
        item
          Value = 6.250000000000000000
        end
        item
          Value = 6.250000000000000000
        end
        item
          Value = 6.250000000000000000
        end
        item
          Value = 6.250000000000000000
        end
        item
          Value = 6.250000000000000000
        end
        item
          Value = 6.250000000000000000
        end
        item
          Value = 6.250000000000000000
        end
        item
          Value = 6.250000000000000000
        end
        item
          Value = 6.250000000000000000
        end
        item
          Value = 6.250000000000000000
        end>
      ShowCaption = False
      TabOrder = 1
      ExplicitLeft = -6
      ExplicitTop = 0
      ExplicitWidth = 150
      ExplicitHeight = 576
      object ButtonAll: TBitBtn
        AlignWithMargins = True
        Left = 6
        Top = 6
        Width = 232
        Height = 34
        Margins.Left = 5
        Margins.Top = 5
        Margins.Right = 5
        Margins.Bottom = 5
        Align = alClient
        Caption = 'ALL'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        OnClick = ButtonAllClick
        ExplicitLeft = 30
        ExplicitWidth = 162
      end
    end
  end
end
