object frmAlarmList: TfrmAlarmList
  Left = 0
  Top = 0
  BorderStyle = bsNone
  ClientHeight = 852
  ClientWidth = 1040
  Color = clGrayText
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object GridPanel1: TGridPanel
    AlignWithMargins = True
    Left = 7
    Top = 7
    Width = 1026
    Height = 781
    Margins.Left = 7
    Margins.Top = 7
    Margins.Right = 7
    Margins.Bottom = 7
    Align = alClient
    BevelOuter = bvNone
    Caption = 'GridPanel1'
    Color = clWhite
    ColumnCollection = <
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
        Column = 0
        Control = GridPanel2
        Row = 1
      end
      item
        Column = 0
        Control = Panel2
        Row = 2
      end>
    ParentBackground = False
    RowCollection = <
      item
        SizeStyle = ssAbsolute
        Value = 55.000000000000000000
      end
      item
        Value = 50.000000000000000000
      end
      item
        Value = 50.000000000000000000
      end
      item
        SizeStyle = ssAuto
      end>
    TabOrder = 0
    object Panel1: TPanel
      Left = 0
      Top = 0
      Width = 1026
      Height = 55
      Align = alClient
      BevelOuter = bvNone
      Caption = 'Panel1'
      ShowCaption = False
      TabOrder = 0
      object GridPanel5: TGridPanel
        AlignWithMargins = True
        Left = 3
        Top = 3
        Width = 1020
        Height = 49
        Align = alClient
        BevelOuter = bvNone
        Caption = 'GridPanel5'
        ColumnCollection = <
          item
            SizeStyle = ssAbsolute
            Value = 250.000000000000000000
          end
          item
            Value = 100.000000000000000000
          end
          item
            SizeStyle = ssAbsolute
            Value = 220.000000000000000000
          end
          item
            SizeStyle = ssAbsolute
            Value = 220.000000000000000000
          end>
        ControlCollection = <
          item
            Column = 0
            Control = PanelCategory
            Row = 0
          end
          item
            Column = 2
            Control = ButtonAlarm
            Row = 0
          end
          item
            Column = 3
            Control = ButtonWarning
            Row = 0
          end>
        RowCollection = <
          item
            Value = 100.000000000000000000
          end>
        ShowCaption = False
        TabOrder = 0
        object PanelCategory: TPanel
          AlignWithMargins = True
          Left = 3
          Top = 3
          Width = 244
          Height = 43
          Align = alClient
          BevelOuter = bvNone
          Caption = 'ALARM LIST'
          Color = clGrayText
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -21
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 0
        end
        object ButtonAlarm: TBitBtn
          AlignWithMargins = True
          Left = 583
          Top = 3
          Width = 214
          Height = 43
          Align = alClient
          Caption = 'ALARM LIST'
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -19
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          Glyph.Data = {
            F6060000424DF606000000000000360000002800000018000000180000000100
            180000000000C0060000C40E0000C40E00000000000000000000FFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC6C6C6E5E5E5
            FFFFFFFFFFFFFFFFFFFFFFFFE7E7E7C9C9C9FFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEF
            EFEF1515150505055A5A5AC8C8C8C9C9C95A5A5A060606181818EFEFEFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFF6E6E6E00000000000000000000000000000000000000000000
            00006E6E6EFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFF6F6F6B3B3B30404040000000000000000000000000000
            00000000000000000000040404B5B5B5F8F8F8FFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFF7E7E7E373737050505000000000000000000000000
            0000000000000000000000000000000000000000000000000707073A3A3A8181
            81FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF31313100000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            000000000000313131FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4747470000
            00000000000000000000000000000000000000FFFFFFFFFFFF00000000000000
            0000000000000000000000000000474747FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFF606060000000000000000000000000000000000000000000FFFFFFFFFF
            FF000000000000000000000000000000000000000000606060FFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFF5F5F5313131000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000000000003131
            31F5F5F5FFFFFFFFFFFFFFFFFFFCFCFC4E4E4E00000000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            0000000000000000004E4E4EFCFCFCFFFFFFFFFFFF6969690000000000000000
            00000000000000000000000000000000000000FFFFFFFFFFFF00000000000000
            0000000000000000000000000000000000000000696969FFFFFFFFFFFF696969
            000000000000000000000000000000000000000000000000000000FFFFFFFFFF
            FF000000000000000000000000000000000000000000000000000000696969FF
            FFFFFFFFFFFCFCFC4E4E4E000000000000000000000000000000000000000000
            000000FFFFFFFFFFFF0000000000000000000000000000000000000000000000
            004E4E4EFCFCFCFFFFFFFFFFFFFFFFFFF5F5F531313100000000000000000000
            0000000000000000000000FFFFFFFFFFFF000000000000000000000000000000
            000000000000313131F5F5F5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6060600000
            00000000000000000000000000000000000000FFFFFFFFFFFF00000000000000
            0000000000000000000000000000606060FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFF474747000000000000000000000000000000000000000000FFFFFFFFFF
            FF000000000000000000000000000000000000000000474747FFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFF313131000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000000000003131
            31FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF7E7E7E37373705050500000000
            0000000000000000000000000000000000000000000000000000000000000000
            0707073A3A3A818181FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFF6F6F6B4B4B404040400000000000000000000000000000000000000000000
            0000040404B5B5B5F8F8F8FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6E6E6E0000000000000000000000000000
            000000000000000000006E6E6EFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFEF181818060606
            5A5A5AC9C9C9C9C9C95A5A5A060606181818EFEFEFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFC9C9C9E7E7E7FFFFFFFFFFFFFFFFFFFFFFFFE7E7E7C9C9C9FFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
          ParentFont = False
          TabOrder = 1
          OnClick = ButtonSwitchClick
        end
        object ButtonWarning: TBitBtn
          AlignWithMargins = True
          Left = 803
          Top = 3
          Width = 214
          Height = 43
          Align = alClient
          Caption = 'WARNING LIST'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
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
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4B4B4B0000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            00000000000000000000000000000000000000004B4B4BFFFFFFFFFFFFD7D7D7
            0505050000000000000000000000000000000000000000000000000000000000
            00000000000000000000000000000000000000000000000000050505D7D7D7FF
            FFFFFFFFFFFFFFFF7373730000003D3D3DFEFEFEFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFE3D3D3D0000
            00737373FFFFFFFFFFFFFFFFFFFFFFFFF0F0F0151515000000AAAAAAFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            AAAAAA000000151515F0F0F0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9B9B9B0000
            001E1E1EF5F5F5FFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFFFF
            FFFFFFFFFFF5F5F51E1E1E0000009B9B9BFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFDFDFD313131000000818181FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFF818181000000313131FDFDFDFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFC2C2C20101010A0A0AE1E1E1FFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE1E1E10A0A0A010101C2C2C2FFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF57575700000058
            5858FFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFF585858000000
            575757FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFE1E1E10A0A0A010101C2C2C2FFFFFFFFFFFF000000000000FFFFFFFFFFFFC2
            C2C20101010A0A0AE1E1E1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFF808080000000323232FDFDFDFFFFFF0000000000
            00FFFFFFFDFDFD323232000000808080FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF5F5F51E1E1E0000009B9B9B
            FFFFFF000000000000FFFFFF9B9B9B0000001E1E1EF5F5F5FFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFA8
            A8A8000000151515F0F0F0FFFFFFFFFFFFF0F0F0151515000000A8A8A8FFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFEFEFE3D3D3D000000737373FFFFFFFFFFFF7373730000003D
            3D3DFEFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCECECE020202050505D7D7D7D7D7
            D7050505020202CECECEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF646464
            0000004B4B4B4B4B4B000000646464FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFEAEAEA0F0F0F0000000000000F0F0FEAEAEAFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF8C8C8C0000000000008C8C8CFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFAFA2828282828
            28FAFAFAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFB4B4B4B4B4B4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
          ParentFont = False
          TabOrder = 2
          OnClick = ButtonSwitchClick
        end
      end
    end
    object GridPanel2: TGridPanel
      Left = 0
      Top = 55
      Width = 1026
      Height = 363
      Align = alClient
      BevelOuter = bvNone
      Caption = 'GridPanel2'
      ColumnCollection = <
        item
          Value = 100.000000000000000000
        end
        item
          SizeStyle = ssAbsolute
          Value = 200.000000000000000000
        end>
      ControlCollection = <
        item
          Column = 0
          Control = StringGridList
          Row = 0
        end
        item
          Column = 1
          Control = GridPanel3
          Row = 0
        end>
      RowCollection = <
        item
          Value = 100.000000000000000000
        end>
      TabOrder = 1
      object StringGridList: TStringGrid
        AlignWithMargins = True
        Left = 6
        Top = 3
        Width = 814
        Height = 357
        Margins.Left = 6
        Margins.Right = 6
        Align = alClient
        BevelInner = bvNone
        BevelOuter = bvNone
        ColCount = 2
        DefaultColWidth = 120
        DefaultRowHeight = 35
        DrawingStyle = gdsGradient
        RowCount = 1002
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentFont = False
        ScrollBars = ssVertical
        TabOrder = 0
        OnSelectCell = StringGridListSelectCell
        ColWidths = (
          120
          658)
      end
      object GridPanel3: TGridPanel
        Left = 826
        Top = 0
        Width = 200
        Height = 363
        Align = alClient
        BevelOuter = bvNone
        Caption = 'GridPanel3'
        ColumnCollection = <
          item
            Value = 100.000000000000000000
          end>
        ControlCollection = <
          item
            Column = 0
            Control = BitBtn3
            Row = 0
          end
          item
            Column = 0
            Control = BitBtn4
            Row = 1
          end
          item
            Column = 0
            Control = BitBtn6
            Row = 3
          end
          item
            Column = 0
            Control = BitBtn7
            Row = 4
          end
          item
            Column = 0
            Control = GridPanel6
            Row = 2
          end>
        RowCollection = <
          item
            Value = 19.999999999999990000
          end
          item
            Value = 20.000000000000000000
          end
          item
            Value = 20.000000000000000000
          end
          item
            Value = 20.000000000000000000
          end
          item
            Value = 20.000000000000000000
          end>
        ShowCaption = False
        TabOrder = 1
        object BitBtn3: TBitBtn
          AlignWithMargins = True
          Left = 7
          Top = 7
          Width = 186
          Height = 58
          Margins.Left = 7
          Margins.Top = 7
          Margins.Right = 7
          Margins.Bottom = 7
          Align = alClient
          Caption = #9650' - 100'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 0
          OnClick = ButtonPagingClick
        end
        object BitBtn4: TBitBtn
          AlignWithMargins = True
          Left = 7
          Top = 79
          Width = 186
          Height = 58
          Margins.Left = 7
          Margins.Top = 7
          Margins.Right = 7
          Margins.Bottom = 7
          Align = alClient
          Caption = #9651' - 10'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 1
          OnClick = ButtonPagingClick
        end
        object BitBtn6: TBitBtn
          AlignWithMargins = True
          Left = 7
          Top = 223
          Width = 186
          Height = 58
          Margins.Left = 7
          Margins.Top = 7
          Margins.Right = 7
          Margins.Bottom = 7
          Align = alClient
          Caption = #9661' + 10'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 2
          OnClick = ButtonPagingClick
        end
        object BitBtn7: TBitBtn
          AlignWithMargins = True
          Left = 7
          Top = 295
          Width = 186
          Height = 61
          Margins.Left = 7
          Margins.Top = 7
          Margins.Right = 7
          Margins.Bottom = 7
          Align = alClient
          Caption = #9660' + 100'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 3
          OnClick = ButtonPagingClick
        end
        object GridPanel6: TGridPanel
          Left = 0
          Top = 144
          Width = 200
          Height = 72
          Align = alClient
          BevelOuter = bvNone
          Caption = 'GridPanel6'
          ColumnCollection = <
            item
              Value = 100.000000000000000000
            end
            item
              SizeStyle = ssAbsolute
              Value = 80.000000000000000000
            end>
          ControlCollection = <
            item
              Column = 1
              Control = ButtonGo
              Row = 0
            end
            item
              Column = 0
              Control = Panel4
              Row = 0
            end>
          RowCollection = <
            item
              Value = 100.000000000000000000
            end
            item
              SizeStyle = ssAuto
            end>
          ShowCaption = False
          TabOrder = 4
          object ButtonGo: TBitBtn
            AlignWithMargins = True
            Left = 123
            Top = 15
            Width = 70
            Height = 42
            Margins.Top = 15
            Margins.Right = 7
            Margins.Bottom = 15
            Align = alClient
            Caption = 'GO'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -19
            Font.Name = 'Calibri'
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 0
            OnClick = ButtonGoClick
          end
          object Panel4: TPanel
            AlignWithMargins = True
            Left = 7
            Top = 15
            Width = 110
            Height = 42
            Margins.Left = 7
            Margins.Top = 15
            Margins.Bottom = 15
            Align = alClient
            BevelKind = bkFlat
            BevelOuter = bvNone
            Caption = 'Panel4'
            TabOrder = 1
            object EditGoTarget: TEdit
              AlignWithMargins = True
              Left = 0
              Top = 7
              Width = 106
              Height = 24
              Margins.Left = 0
              Margins.Top = 7
              Margins.Right = 0
              Margins.Bottom = 7
              Align = alClient
              Alignment = taCenter
              BorderStyle = bsNone
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -19
              Font.Name = 'Calibri'
              Font.Style = [fsBold]
              ImeName = 'Microsoft IME 2010'
              ParentFont = False
              TabOrder = 0
              Text = '0'
            end
          end
        end
      end
    end
    object Panel2: TPanel
      AlignWithMargins = True
      Left = 3
      Top = 421
      Width = 1020
      Height = 357
      Align = alClient
      BevelOuter = bvNone
      Caption = 'Panel2'
      ShowCaption = False
      TabOrder = 2
      object Panel3: TPanel
        Left = 0
        Top = 0
        Width = 1020
        Height = 41
        Align = alTop
        BevelOuter = bvNone
        Caption = 'Panel3'
        ShowCaption = False
        TabOrder = 0
        object GridPanel4: TGridPanel
          Left = 0
          Top = 0
          Width = 1020
          Height = 41
          Align = alClient
          BevelOuter = bvNone
          Caption = 'GridPanel4'
          ColumnCollection = <
            item
              SizeStyle = ssAbsolute
              Value = 120.000000000000000000
            end
            item
              Value = 100.000000000000000000
            end
            item
              SizeStyle = ssAbsolute
              Value = 150.000000000000000000
            end
            item
              SizeStyle = ssAbsolute
              Value = 150.000000000000000000
            end
            item
              SizeStyle = ssAbsolute
              Value = 150.000000000000000000
            end>
          ControlCollection = <
            item
              Column = 0
              Control = PanelIndex
              Row = 0
            end
            item
              Column = 1
              Control = Panel5
              Row = 0
            end
            item
              Column = 3
              Control = ButtonEdit
              Row = 0
            end
            item
              Column = 4
              Control = ButtonSave
              Row = 0
            end
            item
              Column = 2
              Control = CheckBoxAlarm
              Row = 0
            end>
          RowCollection = <
            item
              Value = 100.000000000000000000
            end>
          ShowCaption = False
          TabOrder = 0
          object PanelIndex: TPanel
            AlignWithMargins = True
            Left = 3
            Top = 3
            Width = 114
            Height = 35
            Align = alClient
            BevelOuter = bvNone
            Caption = '000'
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
          object Panel5: TPanel
            AlignWithMargins = True
            Left = 123
            Top = 3
            Width = 444
            Height = 35
            Align = alClient
            BevelOuter = bvLowered
            Caption = 'Panel4'
            TabOrder = 1
            object EditTitle: TEdit
              AlignWithMargins = True
              Left = 4
              Top = 6
              Width = 436
              Height = 23
              Margins.Top = 5
              Margins.Bottom = 5
              Align = alClient
              BevelInner = bvNone
              BevelOuter = bvNone
              BorderStyle = bsNone
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -19
              Font.Name = 'Calibri'
              Font.Style = [fsBold]
              ImeName = 'Microsoft IME 2010'
              ParentFont = False
              ReadOnly = True
              TabOrder = 0
              Text = 'EditTitle'
            end
          end
          object ButtonEdit: TBitBtn
            AlignWithMargins = True
            Left = 723
            Top = 3
            Width = 144
            Height = 35
            Align = alClient
            Caption = 'EDIT'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -19
            Font.Name = 'Calibri'
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 2
            OnClick = ButtonEditClick
          end
          object ButtonSave: TBitBtn
            AlignWithMargins = True
            Left = 873
            Top = 3
            Width = 144
            Height = 35
            Align = alClient
            Caption = 'SAVE'
            Enabled = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -19
            Font.Name = 'Calibri'
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 3
            OnClick = ButtonSaveClick
          end
          object CheckBoxAlarm: TCheckBox
            AlignWithMargins = True
            Left = 573
            Top = 3
            Width = 144
            Height = 35
            Align = alClient
            BiDiMode = bdLeftToRight
            Caption = 'ALARM CHECK'
            Color = clWhite
            Ctl3D = True
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -19
            Font.Name = 'Calibri'
            Font.Style = [fsBold]
            ParentBiDiMode = False
            ParentColor = False
            ParentCtl3D = False
            ParentFont = False
            TabOrder = 4
          end
        end
      end
      object RichEditSolution: TRichEdit
        AlignWithMargins = True
        Left = 3
        Top = 44
        Width = 1014
        Height = 310
        Align = alClient
        Font.Charset = HANGEUL_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ImeName = 'Microsoft IME 2010'
        Lines.Strings = (
          'RichEdit1')
        ParentFont = False
        ReadOnly = True
        TabOrder = 1
      end
    end
  end
  object Panel6: TPanel
    Left = 0
    Top = 795
    Width = 1040
    Height = 57
    Margins.Left = 7
    Margins.Top = 8
    Margins.Right = 7
    Margins.Bottom = 0
    Align = alBottom
    Alignment = taLeftJustify
    BevelOuter = bvNone
    BiDiMode = bdLeftToRight
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -32
    Font.Name = 'Calibri'
    Font.Style = [fsBold]
    ParentBiDiMode = False
    ParentFont = False
    TabOrder = 1
    object BitBtn1: TBitBtn
      AlignWithMargins = True
      Left = 881
      Top = 3
      Width = 154
      Height = 46
      Margins.Right = 5
      Margins.Bottom = 8
      Align = alRight
      Caption = 'CLOSE'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      Glyph.Data = {
        F6060000424DF606000000000000360000002800000018000000180000000100
        180000000000C006000012170000121700000000000000000000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFA0A0A05252521212120202020202
        02020202020202323232727272E0E0E0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB1B1B1242424040404040404
        040404040404040404040404040404040404040404040404636363F0F0F0FFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF74747406060606
        0606060606060606060606060606060606060606060606060606060606060606
        060606262626D1D1D1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6565
        6508080808080808080808080808080808080808080808080808080808080808
        0808080808080808080808080808181818D1D1D1FFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFF9494940B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B
        0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B2A2A2AF0F0F0FF
        FFFFFFFFFFFFFFFFE1E1E10D0D0D0D0D0D0D0D0D0D0D0D0D0D0D1D1D1D959595
        1D1D1D0D0D0D0D0D0D0D0D0D0D0D0D6868685959590D0D0D0D0D0D0D0D0D0D0D
        0D0D0D0D696969FFFFFFFFFFFFFFFFFF6A6A6A0F0F0F0F0F0F0F0F0F0F0F0F1F
        1F1FD2D2D2FFFFFFD2D2D21F1F1F0F0F0F0F0F0F6A6A6AFFFFFFFFFFFF6A6A6A
        0F0F0F0F0F0F0F0F0F0F0F0F0F0F0FE2E2E2FFFFFFF1F1F11111111111111111
        11111111111111D3D3D3FFFFFFFFFFFFFFFFFFD3D3D32020206B6B6BFFFFFFFF
        FFFFFFFFFFFFFFFF5C5C5C1111111111111111111111117A7A7AFFFFFFB6B6B6
        141414141414141414141414232323D3D3D3FFFFFFFFFFFFFFFFFFFFFFFFE2E2
        E2FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6D6D6D14141414141414141414141441
        4141FFFFFF8B8B8B161616161616161616161616161616252525D4D4D4FFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6E6E6E1616161616161616
        16161616161616161616FFFFFF8C8C8C18181818181818181818181818181818
        1818272727D4D4D4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6F6F6F181818
        181818181818181818181818181818181818FFFFFF8D8D8D1A1A1A1A1A1A1A1A
        1A1A1A1A1A1A1A1A1A1A1A1A1A7F7F7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE3
        E3E32929291A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1AFFFFFF8E8E8E
        1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D727272FFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFD5D5D52B2B2B1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D
        1D1DFFFFFF9D9D9D1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F747474FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD5D5D52E2E2E1F1F1F1F1F
        1F1F1F1F1F1F1F2E2E2EFFFFFFD6D6D62121212121212121212121212F2F2FFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFF838383D6D6D6FFFFFFFFFFFFFFFFFFFFFFFF
        9E9E9E212121212121212121212121676767FFFFFFFFFFFF3F3F3F2424242424
        24242424242424777777FFFFFFFFFFFFFFFFFF777777242424323232D6D6D6FF
        FFFFFFFFFFD6D6D6323232242424242424242424242424ADADADFFFFFFFFFFFF
        AEAEAE262626262626262626262626262626787878FFFFFF7878782626262626
        26262626343434D7D7D7D7D7D7343434262626262626262626262626424242FF
        FFFFFFFFFFFFFFFFFFFFFF515151282828282828282828282828282828363636
        2828282828282828282828282828283636362828282828282828282828282828
        28282828BCBCBCFFFFFFFFFFFFFFFFFFFFFFFFD7D7D73838382A2A2A2A2A2A2A
        2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A
        2A2A2A2A2A2A2A2A2A7B7B7BFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD8D8
        D83A3A3A2D2D2D2D2D2D2D2D2D2D2D2D2D2D2D2D2D2D2D2D2D2D2D2D2D2D2D2D
        2D2D2D2D2D2D2D2D2D2D2D2D2D2D7C7C7CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFD8D8D85757572F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F
        2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2FA4A4A4FFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB2B2B24B4B4B313131
        3131313131313131313131313131313131313131317F7F7FE6E6E6FFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFD9D9D9A5A5A5999999999999999999999999BFBFBFF3F3F3FFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
      ModalResult = 8
      ParentFont = False
      Spacing = 12
      TabOrder = 0
      OnClick = ButtonEditClick
    end
  end
end
