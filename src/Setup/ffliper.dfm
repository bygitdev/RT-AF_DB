object frmFlipper: TfrmFlipper
  Left = 0
  Top = 0
  BorderStyle = bsNone
  Caption = 'frmFlipper'
  ClientHeight = 382
  ClientWidth = 1054
  Color = clBackground
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object MatrixBasePanel: TPanel
    AlignWithMargins = True
    Left = 5
    Top = 5
    Width = 1044
    Height = 372
    Margins.Left = 5
    Margins.Top = 5
    Margins.Right = 5
    Margins.Bottom = 5
    Align = alClient
    ParentBackground = False
    TabOrder = 0
    DesignSize = (
      1044
      372)
    object Label1: TLabel
      Left = 33
      Top = 16
      Width = 34
      Height = 26
      Caption = 'TOP'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 933
      Top = 331
      Width = 77
      Height = 26
      Anchors = [akRight, akBottom]
      Caption = 'BOTTOM'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentFont = False
      ExplicitLeft = 976
      ExplicitTop = 350
    end
    object PanelTop: TPanel
      Tag = 2
      AlignWithMargins = True
      Left = 8
      Top = 16
      Width = 17
      Height = 28
      Margins.Left = 5
      Margins.Top = 5
      Margins.Right = 5
      Margins.Bottom = 5
      Caption = 'StatusPanel1'
      Color = clGreen
      ParentBackground = False
      ShowCaption = False
      TabOrder = 0
      OnDblClick = PanelTop3DblClick
    end
    object PanelBtm: TPanel
      Tag = 2
      AlignWithMargins = True
      Left = 1018
      Top = 328
      Width = 17
      Height = 28
      Margins.Left = 5
      Margins.Top = 5
      Margins.Right = 5
      Margins.Bottom = 5
      Anchors = [akRight, akBottom]
      Caption = 'StatusPanel1'
      Color = clGreen
      ParentBackground = False
      ShowCaption = False
      TabOrder = 1
      OnDblClick = PanelTop3DblClick
    end
    object GridPanel3: TGridPanel
      Left = 96
      Top = 13
      Width = 825
      Height = 346
      Anchors = [akLeft, akTop, akRight, akBottom]
      BevelOuter = bvNone
      Caption = 'GridPanel3'
      ColumnCollection = <
        item
          Value = 100.000000000000000000
        end>
      ControlCollection = <
        item
          Column = 0
          Control = GridPanel1
          Row = 0
        end
        item
          Column = 0
          Control = GridPanel2
          Row = 1
        end>
      ParentColor = True
      RowCollection = <
        item
          Value = 50.000000000000000000
        end
        item
          Value = 50.000000000000000000
        end>
      ShowCaption = False
      TabOrder = 2
      object GridPanel1: TGridPanel
        AlignWithMargins = True
        Left = 3
        Top = 3
        Width = 819
        Height = 167
        Align = alClient
        Caption = 'GridPanelTop'
        Color = clGrayText
        ColumnCollection = <
          item
            Value = 50.000000000000000000
          end
          item
            Value = 50.000000000000000000
          end>
        ControlCollection = <
          item
            Column = 0
            Control = PanelTop3
            Row = 0
          end
          item
            Column = 1
            Control = PanelTop4
            Row = 0
          end
          item
            Column = 0
            Control = PanelTop1
            Row = 1
          end
          item
            Column = 1
            Control = PanelTop2
            Row = 1
          end>
        ParentBackground = False
        RowCollection = <
          item
            Value = 50.000000000000000000
          end
          item
            Value = 50.000000000000000000
          end>
        ShowCaption = False
        TabOrder = 0
        object PanelTop3: TPanel
          Tag = 2
          AlignWithMargins = True
          Left = 6
          Top = 6
          Width = 398
          Height = 72
          Margins.Left = 5
          Margins.Top = 5
          Margins.Right = 5
          Margins.Bottom = 5
          Align = alClient
          Caption = 'INDEX : 04'
          Color = clGreen
          Font.Charset = ANSI_CHARSET
          Font.Color = clWhite
          Font.Height = -19
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 0
          OnDblClick = PanelTop3DblClick
        end
        object PanelTop4: TPanel
          Tag = 3
          AlignWithMargins = True
          Left = 414
          Top = 6
          Width = 399
          Height = 72
          Margins.Left = 5
          Margins.Top = 5
          Margins.Right = 5
          Margins.Bottom = 5
          Align = alClient
          Caption = 'INDEX : 03'
          Color = clGreen
          Font.Charset = ANSI_CHARSET
          Font.Color = clWhite
          Font.Height = -19
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 1
          OnDblClick = PanelTop3DblClick
        end
        object PanelTop1: TPanel
          AlignWithMargins = True
          Left = 6
          Top = 88
          Width = 398
          Height = 73
          Margins.Left = 5
          Margins.Top = 5
          Margins.Right = 5
          Margins.Bottom = 5
          Align = alClient
          Caption = 'INDEX : 02'
          Color = clGreen
          Font.Charset = ANSI_CHARSET
          Font.Color = clWhite
          Font.Height = -19
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 2
          OnDblClick = PanelTop3DblClick
        end
        object PanelTop2: TPanel
          Tag = 1
          AlignWithMargins = True
          Left = 414
          Top = 88
          Width = 399
          Height = 73
          Margins.Left = 5
          Margins.Top = 5
          Margins.Right = 5
          Margins.Bottom = 5
          Align = alClient
          Caption = 'INDEX : 01'
          Color = clGreen
          Font.Charset = ANSI_CHARSET
          Font.Color = clWhite
          Font.Height = -19
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 3
          OnDblClick = PanelTop3DblClick
        end
      end
      object GridPanel2: TGridPanel
        Tag = 1
        AlignWithMargins = True
        Left = 3
        Top = 176
        Width = 819
        Height = 167
        Align = alClient
        Caption = 'GridPanel1'
        Color = clGrayText
        ColumnCollection = <
          item
            Value = 50.000000000000000000
          end
          item
            Value = 50.000000000000000000
          end>
        ControlCollection = <
          item
            Column = 0
            Control = PanelBtm1
            Row = 0
          end
          item
            Column = 1
            Control = PanelBtm2
            Row = 0
          end
          item
            Column = 0
            Control = PanelBtm3
            Row = 1
          end
          item
            Column = 1
            Control = PanelBtm4
            Row = 1
          end>
        ParentBackground = False
        RowCollection = <
          item
            Value = 50.000000000000000000
          end
          item
            Value = 50.000000000000000000
          end>
        ShowCaption = False
        TabOrder = 1
        object PanelBtm1: TPanel
          AlignWithMargins = True
          Left = 6
          Top = 6
          Width = 398
          Height = 72
          Margins.Left = 5
          Margins.Top = 5
          Margins.Right = 5
          Margins.Bottom = 5
          Align = alClient
          Caption = 'INDEX : 02'
          Color = clGreen
          Font.Charset = ANSI_CHARSET
          Font.Color = clWhite
          Font.Height = -19
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 0
          OnDblClick = PanelTop3DblClick
        end
        object PanelBtm2: TPanel
          Tag = 1
          AlignWithMargins = True
          Left = 414
          Top = 6
          Width = 399
          Height = 72
          Margins.Left = 5
          Margins.Top = 5
          Margins.Right = 5
          Margins.Bottom = 5
          Align = alClient
          Caption = 'INDEX : 01'
          Color = clGreen
          Font.Charset = ANSI_CHARSET
          Font.Color = clWhite
          Font.Height = -19
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 1
          OnDblClick = PanelTop3DblClick
        end
        object PanelBtm3: TPanel
          Tag = 2
          AlignWithMargins = True
          Left = 6
          Top = 88
          Width = 398
          Height = 73
          Margins.Left = 5
          Margins.Top = 5
          Margins.Right = 5
          Margins.Bottom = 5
          Align = alClient
          Caption = 'INDEX : 04'
          Color = clGreen
          Font.Charset = ANSI_CHARSET
          Font.Color = clWhite
          Font.Height = -19
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 2
          OnDblClick = PanelTop3DblClick
        end
        object PanelBtm4: TPanel
          Tag = 3
          AlignWithMargins = True
          Left = 414
          Top = 88
          Width = 399
          Height = 73
          Margins.Left = 5
          Margins.Top = 5
          Margins.Right = 5
          Margins.Bottom = 5
          Align = alClient
          Caption = 'INDEX : 03'
          Color = clGreen
          Font.Charset = ANSI_CHARSET
          Font.Color = clWhite
          Font.Height = -19
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 3
          OnDblClick = PanelTop3DblClick
        end
      end
    end
  end
end
