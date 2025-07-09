object FrmShowData: TFrmShowData
  Left = 0
  Top = 0
  BorderStyle = bsNone
  Caption = 'FrmShowData'
  ClientHeight = 719
  ClientWidth = 1301
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object GridPanel1: TGridPanel
    AlignWithMargins = True
    Left = 3
    Top = 3
    Width = 1295
    Height = 713
    Align = alClient
    BevelOuter = bvNone
    Caption = 'GridPanel1'
    ColumnCollection = <
      item
        SizeStyle = ssAbsolute
        Value = 310.000000000000000000
      end
      item
        Value = 100.000000000000000000
      end>
    ControlCollection = <
      item
        Column = 0
        Control = Panel1
        Row = 0
      end
      item
        Column = 1
        Control = Panel2
        Row = 0
      end>
    RowCollection = <
      item
        Value = 100.000000000000000000
      end>
    ShowCaption = False
    TabOrder = 0
    object Panel1: TPanel
      AlignWithMargins = True
      Left = 3
      Top = 3
      Width = 304
      Height = 707
      Align = alClient
      BevelOuter = bvNone
      Caption = 'Panel1'
      ShowCaption = False
      TabOrder = 0
      object GridPanel2: TGridPanel
        Left = 0
        Top = 0
        Width = 304
        Height = 707
        Align = alClient
        BevelOuter = bvNone
        Caption = 'GridPanel2'
        ColumnCollection = <
          item
            Value = 100.000000000000000000
          end>
        ControlCollection = <
          item
            Column = 0
            Control = Panel3
            Row = 0
          end
          item
            Column = 0
            Control = Panel4
            Row = 1
          end
          item
            Column = 0
            Control = Panel5
            Row = 2
          end>
        RowCollection = <
          item
            SizeStyle = ssAbsolute
            Value = 40.000000000000000000
          end
          item
            Value = 100.000000000000000000
          end
          item
            SizeStyle = ssAbsolute
            Value = 60.000000000000000000
          end>
        ShowCaption = False
        TabOrder = 0
        object Panel3: TPanel
          AlignWithMargins = True
          Left = 3
          Top = 3
          Width = 298
          Height = 34
          Align = alClient
          Alignment = taLeftJustify
          BevelOuter = bvNone
          BorderWidth = 9
          Caption = 'PACKAGE DATA'
          Color = clGrayText
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -19
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 0
        end
        object Panel4: TPanel
          AlignWithMargins = True
          Left = 3
          Top = 43
          Width = 298
          Height = 601
          Align = alClient
          BevelOuter = bvNone
          Caption = 'Panel3'
          TabOrder = 1
          object ValueListEditorPkg: TValueListEditor
            Left = 0
            Top = 0
            Width = 298
            Height = 601
            Align = alClient
            DefaultRowHeight = 24
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Calibri'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
            TitleCaptions.Strings = (
              'NAME'
              'VALUE'
              '')
            ColWidths = (
              107
              185)
          end
        end
        object Panel5: TPanel
          AlignWithMargins = True
          Left = 3
          Top = 650
          Width = 298
          Height = 54
          Align = alClient
          BevelOuter = bvNone
          Caption = 'Panel3'
          ShowCaption = False
          TabOrder = 2
        end
      end
    end
    object Panel2: TPanel
      AlignWithMargins = True
      Left = 313
      Top = 3
      Width = 979
      Height = 707
      Align = alClient
      BevelOuter = bvNone
      Caption = 'Panel1'
      ShowCaption = False
      TabOrder = 1
      object GridPanel3: TGridPanel
        Left = 0
        Top = 0
        Width = 979
        Height = 707
        Align = alClient
        BevelOuter = bvNone
        Caption = 'GridPanel2'
        ColumnCollection = <
          item
            Value = 100.000000000000000000
          end>
        ControlCollection = <
          item
            Column = 0
            Control = Panel7
            Row = 0
            RowSpan = 2
          end
          item
            Column = 0
            Control = Panel8
            Row = 2
          end>
        RowCollection = <
          item
            SizeStyle = ssAbsolute
            Value = 40.000000000000000000
          end
          item
            Value = 100.000000000000000000
          end
          item
            SizeStyle = ssAbsolute
            Value = 60.000000000000000000
          end
          item
            SizeStyle = ssAuto
          end>
        ShowCaption = False
        TabOrder = 0
        object Panel7: TPanel
          AlignWithMargins = True
          Left = 3
          Top = 3
          Width = 973
          Height = 641
          Align = alClient
          BevelOuter = bvNone
          Caption = 'Panel3'
          TabOrder = 0
          DesignSize = (
            973
            641)
          object PageControl1: TPageControl
            Left = 0
            Top = 0
            Width = 973
            Height = 641
            ActivePage = TabSheet1
            Align = alClient
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -19
            Font.Name = 'Calibri'
            Font.Style = [fsBold]
            ParentFont = False
            TabHeight = 35
            TabOrder = 0
            TabWidth = 150
            OnChange = PageControl1Change
            object TabSheet1: TTabSheet
              Caption = 'PATH DATA'
              ExplicitLeft = 0
              ExplicitTop = 0
              ExplicitWidth = 0
              ExplicitHeight = 0
              object StringGrid_path: TStringGrid
                Left = 0
                Top = 0
                Width = 965
                Height = 577
                Align = alClient
                BevelInner = bvNone
                BevelOuter = bvNone
                ColCount = 4
                DefaultColWidth = 70
                RowCount = 101
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -13
                Font.Name = 'Calibri'
                Font.Style = []
                ParentFont = False
                TabOrder = 0
                OnSelectCell = StringGridSelectCell
              end
              object StatusBar1: TStatusBar
                Left = 0
                Top = 577
                Width = 965
                Height = 19
                Anchors = []
                Panels = <
                  item
                    Width = 500
                  end>
              end
            end
            object TabSheet2: TTabSheet
              Caption = 'INDEX1 OFFSET'
              ImageIndex = 1
              ExplicitLeft = 0
              ExplicitTop = 0
              ExplicitWidth = 0
              ExplicitHeight = 0
              object StringGrid_offset1: TStringGrid
                Left = 0
                Top = 0
                Width = 965
                Height = 596
                Align = alClient
                BevelInner = bvNone
                BevelOuter = bvNone
                ColCount = 4
                DefaultColWidth = 70
                RowCount = 101
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -13
                Font.Name = 'Calibri'
                Font.Style = []
                ParentFont = False
                TabOrder = 0
                OnSelectCell = StringGridSelectCell
              end
            end
            object TabSheet3: TTabSheet
              Caption = 'INDEX2 OFFSET'
              ImageIndex = 2
              ExplicitLeft = 0
              ExplicitTop = 0
              ExplicitWidth = 0
              ExplicitHeight = 0
              object StringGrid_offset2: TStringGrid
                Left = 0
                Top = 0
                Width = 965
                Height = 596
                Align = alClient
                BevelInner = bvNone
                BevelOuter = bvNone
                ColCount = 4
                DefaultColWidth = 70
                RowCount = 101
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -13
                Font.Name = 'Calibri'
                Font.Style = []
                ParentFont = False
                TabOrder = 0
                OnSelectCell = StringGridSelectCell
              end
            end
            object TabSheet4: TTabSheet
              Caption = 'INDEX3 OFFSET'
              ImageIndex = 3
              ExplicitLeft = 0
              ExplicitTop = 0
              ExplicitWidth = 0
              ExplicitHeight = 0
              object StringGrid_offset3: TStringGrid
                Left = 0
                Top = 0
                Width = 965
                Height = 596
                Align = alClient
                BevelInner = bvNone
                BevelOuter = bvNone
                ColCount = 4
                DefaultColWidth = 70
                RowCount = 101
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -13
                Font.Name = 'Calibri'
                Font.Style = []
                ParentFont = False
                TabOrder = 0
                OnSelectCell = StringGridSelectCell
              end
            end
            object TabSheet5: TTabSheet
              Caption = 'INDEX4 OFFSET'
              ImageIndex = 4
              ExplicitLeft = 0
              ExplicitTop = 0
              ExplicitWidth = 0
              ExplicitHeight = 0
              object StringGrid_offset4: TStringGrid
                Left = 0
                Top = 0
                Width = 965
                Height = 596
                Align = alClient
                BevelInner = bvNone
                BevelOuter = bvNone
                ColCount = 4
                DefaultColWidth = 70
                RowCount = 101
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -13
                Font.Name = 'Calibri'
                Font.Style = []
                ParentFont = False
                TabOrder = 0
                OnSelectCell = StringGridSelectCell
              end
            end
          end
          object ButtonReload: TBitBtn
            Left = 868
            Top = 2
            Width = 104
            Height = 33
            Anchors = [akTop, akRight]
            Caption = 'READ SEQ'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Calibri'
            Font.Style = [fsBold]
            Glyph.Data = {
              F6060000424DF606000000000000360000002800000018000000180000000100
              180000000000C0060000C40E0000C40E00000000000000000000FFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFF7F7F7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFF0000007F7F7FFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000007F7F7FFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD4D4D46F6F6F2B2B2B0B0B0B0000
              000000000000007F7F7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9F9F96B6B6B020202000000
              000000000000000000000000000000808080FFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9F9F944444400
              00000606066E6E6EC7C7C7F4F4F4000000000000808080FFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FF6A6A6A0000001B1B1BCFCFCFFFFFFFFFFFFFFFFFFF000000808080FFFFFFFF
              FFFFFFFFFFFFFFFFF1F1F1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFD3D3D3030303070707D0D0D0FFFFFFFFFFFFFFFFFFFFFFFF8080
              80FFFFFFFFFFFFFFFFFFFFFFFFDFDFDF222222D3D3D3FFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFF7070700000006D6D6DFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF7272720000006C6C6CFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF2B2B2B000000C7C7C7FF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC6C6C6
              000000272727FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0D0D
              0D000000F2F2F2FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFF0F0F0000000090909FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFF090909000000F0F0F0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFF2F2F20000000D0D0DFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFF272727000000C6C6C6FFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC7C7C70000002B2B2BFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6C6C6C000000727272FF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6D6D6D
              000000707070FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD3D3
              D3222222DFDFDFFFFFFFFFFFFFFFFFFFFFFFFF7F7F7FFFFFFFFFFFFFFFFFFFFF
              FFFFD0D0D0070707030303D3D3D3FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFF1F1F1FFFFFFFFFFFFFFFFFFFFFFFF7F7F7F000000FFFF
              FFFFFFFFFFFFFFCFCFCF1B1B1B0000006A6A6AFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF7F7F7F
              000000000000F4F4F4C7C7C76E6E6E060606000000444444F9F9F9FFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFF7F7F7F0000000000000000000000000000000000000202026B6B6BF9F9F9
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFF8080800000000000000000000B0B0B2B2B2B6F6F6FD4
              D4D4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF808080000000000000FFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              808080000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFF808080FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
            ParentFont = False
            TabOrder = 1
            OnClick = ButtonReloadClick
          end
        end
        object Panel8: TPanel
          AlignWithMargins = True
          Left = 3
          Top = 650
          Width = 973
          Height = 54
          Align = alClient
          BevelOuter = bvNone
          Caption = 'Panel3'
          ShowCaption = False
          TabOrder = 1
          DesignSize = (
            973
            54)
          object ButtonInput: TBitBtn
            Left = 709
            Top = 8
            Width = 129
            Height = 41
            Anchors = [akTop, akRight]
            Caption = 'INPUT'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Calibri'
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 0
            OnClick = ButtonInputClick
          end
          object ButtonSave: TBitBtn
            Left = 844
            Top = 8
            Width = 129
            Height = 41
            Anchors = [akTop, akRight]
            Caption = 'SAVE'
            Enabled = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Calibri'
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 1
            OnClick = ButtonSaveClick
          end
          object GridPanel4: TGridPanel
            Left = 0
            Top = 0
            Width = 569
            Height = 54
            Align = alLeft
            BevelOuter = bvNone
            Caption = 'GridPanel4'
            Color = clSilver
            ColumnCollection = <
              item
                SizeStyle = ssAbsolute
                Value = 140.000000000000000000
              end
              item
                SizeStyle = ssAbsolute
                Value = 90.000000000000000000
              end
              item
                SizeStyle = ssAbsolute
                Value = 90.000000000000000000
              end
              item
                Value = 50.000000000000000000
              end
              item
                Value = 50.000000000000000000
              end>
            ControlCollection = <
              item
                Column = 0
                Control = Panel6
                Row = 0
              end
              item
                Column = 1
                Control = Panel9
                Row = 1
              end
              item
                Column = 3
                Control = BitBtn1
                Row = 0
                RowSpan = 2
              end
              item
                Column = 4
                Control = BitBtn2
                Row = 0
                RowSpan = 2
              end
              item
                Column = 2
                Control = PanelPos
                Row = 1
              end
              item
                Column = 1
                Control = Panel10
                Row = 0
              end
              item
                Column = 2
                Control = Panel11
                Row = 0
              end
              item
                Column = 0
                Control = GridPanelStageIndex
                Row = 1
              end>
            ParentBackground = False
            RowCollection = <
              item
                SizeStyle = ssAbsolute
                Value = 18.000000000000000000
              end
              item
                Value = 100.000000000000000000
              end>
            ShowCaption = False
            TabOrder = 2
            object Panel6: TPanel
              AlignWithMargins = True
              Left = 3
              Top = 3
              Width = 134
              Height = 12
              Align = alClient
              BevelOuter = bvNone
              Caption = 'INDEX'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Calibri'
              Font.Style = [fsBold]
              ParentFont = False
              TabOrder = 0
            end
            object Panel9: TPanel
              AlignWithMargins = True
              Left = 143
              Top = 22
              Width = 84
              Height = 28
              Margins.Top = 4
              Margins.Bottom = 4
              Align = alClient
              BevelOuter = bvLowered
              Caption = 'Panel6'
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -16
              Font.Name = 'Calibri'
              Font.Style = [fsBold]
              ParentBackground = False
              ParentFont = False
              TabOrder = 1
              object EditIndex: TEdit
                AlignWithMargins = True
                Left = 4
                Top = 4
                Width = 76
                Height = 20
                Align = alClient
                Alignment = taCenter
                BevelInner = bvNone
                BevelOuter = bvNone
                BorderStyle = bsNone
                NumbersOnly = True
                TabOrder = 0
                Text = '1'
              end
            end
            object BitBtn1: TBitBtn
              AlignWithMargins = True
              Left = 323
              Top = 3
              Width = 118
              Height = 48
              Align = alClient
              Caption = 'ROUTER'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -16
              Font.Name = 'Calibri'
              Font.Style = [fsBold]
              Glyph.Data = {
                F6060000424DF606000000000000360000002800000018000000180000000100
                180000000000C0060000C40E0000C40E00000000000000000000FFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFF000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFEFEFEBBBBBB5D5D5D2626260000000000002626265D5D5DBB
                BBBBFEFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFD6D6D63B3B3B0000000000000000000000000000
                000000000000000000003B3B3BD6D6D6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC0C0C00F0F0F000000141414838383
                CECECEF4F4F4F4F4F4CECECE8383831414140000000F0F0FC0C0C0FFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD5D5D50F0F0F00000053
                5353F1F1F1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1F1F1535353000000
                0F0F0FD5D5D5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFE3D3D
                3D000000535353FEFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFEFEFE5353530000003D3D3DFEFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFBABABA000000151515F1F1F1FFFFFFFFFFFFE2E2E25555550D0D0D0D0D
                0D555555E2E2E2FFFFFFFFFFFFF1F1F1151515000000BABABAFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFF5E5E5E000000828282FFFFFFFFFFFFE3E3E3121212
                000000000000000000000000121212E3E3E3FFFFFFFFFFFF8282820000005E5E
                5EFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF262626000000CFCFCFFFFFFFFF
                FFFF555555000000000000000000000000000000000000555555FFFFFFFFFFFF
                CFCFCF000000262626FFFFFFFFFFFFFFFFFFFFFFFF0000000000000000000000
                00F2F2F2FFFFFFFFFFFF0E0E0E0000000000000000000000000000000000000E
                0E0EFFFFFFFFFFFFF2F2F2000000000000000000000000FFFFFFFFFFFF000000
                000000000000000000F2F2F2FFFFFFFFFFFF0E0E0E0000000000000000000000
                000000000000000E0E0EFFFFFFFFFFFFF2F2F2000000000000000000000000FF
                FFFFFFFFFFFFFFFFFFFFFF262626000000CFCFCFFFFFFFFFFFFF555555000000
                000000000000000000000000000000555555FFFFFFFFFFFFCFCFCF0000002626
                26FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF5E5E5E000000828282FFFFFFFF
                FFFFE3E3E3121212000000000000000000000000121212E3E3E3FFFFFFFFFFFF
                8282820000005E5E5EFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBABABA0000
                00151515F1F1F1FFFFFFFFFFFFE2E2E25555550D0D0D0D0D0D555555E2E2E2FF
                FFFFFFFFFFF1F1F1151515000000BABABAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFEFEFE3D3D3D000000535353FEFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFEFEFE5353530000003D3D3DFEFEFEFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFD5D5D50F0F0F000000535353F1F1F1FFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1F1F15353530000000F0F0FD5D5D5FFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC0C0C00F0F0F00
                0000141414838383CECECEF4F4F4F4F4F4CECECE8383831414140000000F0F0F
                C0C0C0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFD6D6D63B3B3B00000000000000000000000000000000000000000000
                00003B3B3BD6D6D6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFEBBBBBB5D5D5D2626260000000000
                002626265D5D5DBBBBBBFEFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFF000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
              ParentFont = False
              TabOrder = 2
              OnClick = ButtonIndexMoveClick
            end
            object BitBtn2: TBitBtn
              AlignWithMargins = True
              Left = 447
              Top = 3
              Width = 119
              Height = 48
              Align = alClient
              Caption = 'VISION'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -16
              Font.Name = 'Calibri'
              Font.Style = [fsBold]
              Glyph.Data = {
                F6060000424DF606000000000000360000002800000018000000180000000100
                180000000000C0060000C40E0000C40E00000000000000000000FFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF3B3B3B00000000000000000000
                00000000000000000000000000000000000000000000000000003B3B3BFFFFFF
                FFFFFFFFFFFFDFDFDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000FFFFFFFFFFFFDFDFDF202020FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFF0000000000000000000000000000000000000000000000000000000000
                00000000000000000000000000FFFFFFDFDFDF202020000000FFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000000
                000000000000000000000000000000000000000000DFDFDF2020200000000000
                00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000202020
                000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFF0000000000000000000000000000000000000000000000000000000000
                00000000000000000000000000000000000000000000000000FFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000002020200000000000000000
                00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000DFDFDF
                202020000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000FFFFFFDFDFDF202020000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFF0000000000000000000000000000000000000000000000000000000000
                00000000000000000000000000FFFFFFFFFFFFDFDFDF202020FFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFF3B3B3B000000000000000000000000000000000000
                0000000000000000000000000000000000003B3B3BFFFFFFFFFFFFFFFFFFDFDF
                DFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
              ParentFont = False
              TabOrder = 3
              OnClick = ButtonIndexMoveClick
            end
            object PanelPos: TPanel
              AlignWithMargins = True
              Left = 233
              Top = 22
              Width = 84
              Height = 28
              Margins.Top = 4
              Margins.Bottom = 4
              Align = alClient
              BevelOuter = bvLowered
              Caption = 'START'
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -16
              Font.Name = 'Calibri'
              Font.Style = [fsBold]
              ParentBackground = False
              ParentFont = False
              TabOrder = 4
            end
            object Panel10: TPanel
              AlignWithMargins = True
              Left = 143
              Top = 3
              Width = 84
              Height = 12
              Align = alClient
              BevelOuter = bvNone
              Caption = 'PATH'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Calibri'
              Font.Style = [fsBold]
              ParentFont = False
              TabOrder = 5
            end
            object Panel11: TPanel
              AlignWithMargins = True
              Left = 233
              Top = 3
              Width = 84
              Height = 12
              Align = alClient
              BevelOuter = bvNone
              Caption = 'POSITION'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Calibri'
              Font.Style = [fsBold]
              ParentFont = False
              TabOrder = 6
              ExplicitLeft = 249
              ExplicitTop = 0
            end
            object GridPanelStageIndex: TGridPanel
              AlignWithMargins = True
              Left = 2
              Top = 18
              Width = 136
              Height = 36
              Margins.Left = 2
              Margins.Top = 0
              Margins.Right = 2
              Margins.Bottom = 0
              Align = alClient
              BevelOuter = bvNone
              Caption = 'GridPanelStageIndex'
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
              ControlCollection = <
                item
                  Column = 0
                  Control = PanelIndex1
                  Row = 0
                end
                item
                  Column = 1
                  Control = PanelIndex2
                  Row = 0
                end
                item
                  Column = 2
                  Control = PanelIndex3
                  Row = 0
                end
                item
                  Column = 3
                  Control = PanelIndex4
                  Row = 0
                end>
              RowCollection = <
                item
                  Value = 100.000000000000000000
                end>
              ShowCaption = False
              TabOrder = 7
              object PanelIndex1: TPanel
                AlignWithMargins = True
                Left = 1
                Top = 3
                Width = 32
                Height = 30
                Margins.Left = 1
                Margins.Right = 1
                Align = alClient
                BevelOuter = bvLowered
                Caption = '1'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -16
                Font.Name = 'Calibri'
                Font.Style = [fsBold]
                ParentBackground = False
                ParentFont = False
                TabOrder = 0
                OnClick = PanelIndexClick
              end
              object PanelIndex2: TPanel
                AlignWithMargins = True
                Left = 35
                Top = 3
                Width = 32
                Height = 30
                Margins.Left = 1
                Margins.Right = 1
                Align = alClient
                Caption = '2'
                Color = clSilver
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -16
                Font.Name = 'Calibri'
                Font.Style = [fsBold]
                ParentBackground = False
                ParentFont = False
                TabOrder = 1
                OnClick = PanelIndexClick
              end
              object PanelIndex3: TPanel
                AlignWithMargins = True
                Left = 69
                Top = 3
                Width = 32
                Height = 30
                Margins.Left = 1
                Margins.Right = 1
                Align = alClient
                Caption = '3'
                Color = clSilver
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -16
                Font.Name = 'Calibri'
                Font.Style = [fsBold]
                ParentBackground = False
                ParentFont = False
                TabOrder = 2
                OnClick = PanelIndexClick
              end
              object PanelIndex4: TPanel
                AlignWithMargins = True
                Left = 103
                Top = 3
                Width = 32
                Height = 30
                Margins.Left = 1
                Margins.Right = 1
                Align = alClient
                Caption = '4'
                Color = clSilver
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -16
                Font.Name = 'Calibri'
                Font.Style = [fsBold]
                ParentBackground = False
                ParentFont = False
                TabOrder = 3
                OnClick = PanelIndexClick
              end
            end
          end
        end
      end
    end
  end
end
