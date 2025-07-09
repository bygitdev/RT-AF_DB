object FrmStaubliControl: TFrmStaubliControl
  Left = 0
  Top = 0
  BorderStyle = bsNone
  ClientHeight = 780
  ClientWidth = 1280
  Color = clGray
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object CurvyPanel1: TCurvyPanel
    Left = 8
    Top = 8
    Width = 1267
    Height = 767
    TabOrder = 0
    object CurvyPanel4: TCurvyPanel
      Left = 10
      Top = 7
      Width = 1254
      Height = 54
      TabOrder = 0
      object BtnInputMotionData: TSpeedButton
        Tag = 1
        Left = 975
        Top = 6
        Width = 130
        Height = 42
        Caption = 'INPUT DATA'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #47569#51008' '#44256#46357
        Font.Style = [fsBold]
        Glyph.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          1800000000000003000012170000121700000000000000000000FFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFF02020202020202020202020202020202020202
          0202020202020202020202020202020202020202E0E0E0FFFFFFFFFFFF151515
          0606060606060606060606060606060606060606060606060606060606060606
          06060606A2A2A2FFFFFFFFFFFF57575709090909090909090909090909090909
          0909090909090909090909090909090909090909666666FFFFFFFFFFFF959595
          0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D
          0D0D0D0D2C2C2CFFFFFFFFFFFFE1E1E110101010101010101010101010101010
          1010101010101010101010101010101010101010101010D3D3D3FFFFFFFFFFFF
          3131311313131313131313131313131313131313131313131313131313131313
          13131313131313989898E3E3E3FFFFFF6E6E6E17171717171717171717171717
          17171717171717171717171717171717171717171717176060609B9B9BFFFFFF
          A9A9A91A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A
          1A1A1A1A1A1A1A292929656565FFFFFFE3E3E31E1E1E1E1E1E1E1E1E1E1E1E1E
          1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E2F2F2FFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFF242424BBBBBBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF282828282828
          2828282828282828282828282828282828282828282828282828282828282828
          285E5E5EFFFFFFFFFFFF3939392B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B
          2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B6E6E6EFFFFFFFFFFFF9797972F2F2F
          2F2F2F2F2F2F2F2F2F2F2F2F565656F2F2F2FFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFF5858583232323232323232323E3E3ED9D9D9FF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
        ParentFont = False
        OnClick = BtnInputMotionDataClick
      end
      object BtnSaveMotionData: TSpeedButton
        Tag = 1
        Left = 1111
        Top = 6
        Width = 130
        Height = 42
        Caption = 'SAVE DATA'
        Enabled = False
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #47569#51008' '#44256#46357
        Font.Style = [fsBold]
        Glyph.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          1800000000000003000012170000121700000000000000000000FFFFFFFFFFFF
          D0D0D01212120202020202020202020202020202020202020202020202020202
          02121212D0D0D0FFFFFFFFFFFFD1D1D115151505050505050505050505050505
          0505050505050505050505050505050505050505151515D1D1D1F0F0F0191919
          090909181818D1D1D1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD1D1
          D1181818090909191919F0F0F01B1B1B1B1B1BD1D1D1FFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD1D1D11B1B1B1B1B1BFFFFFFF0F0F0
          F0F0F0FFFFFFFFFFFFFFFFFFFFFFFFA5A5A54C4C4CA5A5A5FFFFFFFFFFFFFFFF
          FFFFFFFFF0F0F0F0F0F0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFA7A7A712
          1212121212121212A7A7A7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFA8A8A8151515151515151515151515151515A8A8A8FFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFA9A9A919191919191919
          1919191919191919191919191919A9A9A9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFAAAAAA1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C
          1CAAAAAAFFFFFFFFFFFFFFFFFFFFFFFFABABAB1F1F1F1F1F1F1F1F1F1F1F1F1F
          1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1FABABABFFFFFFFFFFFFFFFFFF
          2222222222222222222222222222222222222222222222222222222222222222
          22222222222222FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF2F2F225252525
          2525252525252525252525F2F2F2FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFF282828282828282828282828282828FFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF2C2C2C2C
          2C2C2C2C2C2C2C2C2C2C2CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFF2F2F2F2F2F2F2F2F2F2F2F2F2F2F2FFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE6E6E632323232
          3232323232323232323232FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
        ParentFont = False
        OnClick = BtnSaveMotionDataClick
      end
      object Label1: TLabel
        Left = 11
        Top = 6
        Width = 95
        Height = 19
        Caption = 'STAUBLI DATA'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object BtnModBusOpen: TSpeedButton
        Tag = 200
        Left = 359
        Top = 6
        Width = 130
        Height = 42
        Caption = 'MODBUS OPEN'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #47569#51008' '#44256#46357
        Font.Style = [fsBold]
        Glyph.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          1800000000000003000012170000121700000000000000000000FFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFF13131303030303030303030303030303030303030303
          0303030303030303030303030303030303030303030303131313070707070707
          0707070707070707070707070707070707070707070707070707070707070707
          070707070707070707070B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B
          0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0F0F0F0F0F0F
          696969C3C3C3C3C3C3C3C3C35A5A5A0F0F0F0F0F0FE1E1E18787870F0F0F0F0F
          0F878787F0F0F00F0F0F1313136C6C6CFFFFFF9898984F4F4F989898FFFFFF5D
          5D5D131313FFFFFF8989891313135D5D5DFFFFFFFFFFFF131313171717C5C5C5
          FFFFFF171717171717171717FFFFFFC5C5C5171717FFFFFF8B8B8B252525F1F1
          F1FFFFFFFFFFFF1717171A1A1AC6C6C6FFFFFF1A1A1A1A1A1A1A1A1AC6C6C6C6
          C6C61A1A1AFFFFFF8D8D8DC6C6C6C6C6C68D8D8DFFFFFF1A1A1A1E1E1EC7C7C7
          FFFFFF1E1E1E1E1E1E1E1E1EFFFFFFC7C7C71E1E1EFFFFFFFFFFFFF1F1F12D2D
          2D8F8F8FFFFFFF1E1E1E222222686868FFFFFF9E9E9E5959599E9E9EFFFFFF76
          7676222222FFFFFFFFFFFF686868222222919191FFFFFF222222262626262626
          6B6B6BC9C9C9C9C9C9C9C9C9787878262626262626F2F2F2A0A0A02626262626
          26868686F2F2F22626262A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A
          2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2E2E2E2E2E2E
          2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E
          2E2E2E2E2E2E2E2E2E2E3E3E3E32323232323232323232323232323232323232
          32323232323232323232323232323232323232323232323E3E3EFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
        ParentFont = False
        OnClick = BtnModBusOpenClick
      end
      object BtnModBusClose: TSpeedButton
        Tag = 201
        Left = 495
        Top = 6
        Width = 130
        Height = 42
        Caption = 'MODBUS CLOSE'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #47569#51008' '#44256#46357
        Font.Style = [fsBold]
        Glyph.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          1800000000000003000012170000121700000000000000000000FFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFF13131303030303030303030303030303030303030303
          0303030303030303030303030303030303030303030303131313070707D0D0D0
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFC1C1C10707070B0B0BFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0B0B0B0F0F0FFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFF0F0F0F131313FFFFFF6C6C6C1313131313137B7B7BFFFFFF13
          1313FFFFFFFFFFFFFFFFFF131313FFFFFFFFFFFFFFFFFF131313171717FFFFFF
          1717178B8B8B8B8B8B171717FFFFFF171717FFFFFFFFFFFFFFFFFF171717FFFF
          FFFFFFFFFFFFFF1717171A1A1AFFFFFF1A1A1AC6C6C6E3E3E31A1A1AFFFFFF1A
          1A1A1A1A1A545454FFFFFF1A1A1A1A1A1A545454FFFFFF1A1A1A1E1E1EFFFFFF
          1E1E1E8F8F8F8F8F8F1E1E1EFFFFFF1E1E1EC7C7C7C7C7C7FFFFFF1E1E1EFFFF
          FFFFFFFFFFFFFF1E1E1E222222FFFFFF838383222222222222757575FFFFFF22
          2222222222222222FFFFFF222222222222222222FFFFFF222222262626FFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFF2626262A2A2AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF2A2A2A2E2E2ED8D8D8
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFCBCBCB2E2E2E3E3E3E32323232323232323232323232323232323232
          32323232323232323232323232323232323232323232323E3E3EFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
        ParentFont = False
        OnClick = BtnModBusOpenClick
      end
      object SpeedButton1: TSpeedButton
        Tag = 1
        Left = 839
        Top = 6
        Width = 130
        Height = 42
        Caption = 'COMMON SET'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #47569#51008' '#44256#46357
        Font.Style = [fsBold]
        Glyph.Data = {
          F6060000424DF606000000000000360000002800000018000000180000000100
          180000000000C0060000C40E0000C40E00000000000000000000FFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB5
          B5B51C1C1C000000000000FFFFFFFFFFFF000000000000000000FFFFFFFFFFFF
          0000000000001C1C1CB5B5B5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFF1C1C1C000000000000000000FFFFFFFFFFFF00000000000000
          0000FFFFFFFFFFFF0000000000000000001C1C1CFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000
          00000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC5C5C5
          272727000000000000FFFFFFFFFFFF0000000000000000000000000000000000
          00000000272727C5C5C5FFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFF
          FFFFFFFFFF272727000000000000000000FFFFFFFFFFFF000000000000000000
          000000000000000000000000000000272727FFFFFFFFFFFFFFFFFFFFFFFF0000
          00000000FFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFFFFFFFF00
          0000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFF
          FFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFF
          FFFFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000
          0000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFF000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFFFFFFFF0000
          00000000FFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFFFFFFFF00
          0000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFF
          FFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFF
          FFFFFFFFFFFFFF1C1C1C00000000000000000000000000000000000000000000
          0000FFFFFFFFFFFF0000000000000000001C1C1CFFFFFFFFFFFFFFFFFF000000
          000000FFFFFFFFFFFFFFFFFFFFFFFFB5B5B51C1C1C0000000000000000000000
          00000000000000000000FFFFFFFFFFFF0000000000001C1C1CB5B5B5FFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000
          0000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000
          000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFF000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFF272727000000000000000000FFFFFFFFFFFF000000000000000000
          FFFFFFFFFFFF000000000000000000272727FFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFC5C5C5272727000000000000FFFFFFFFFFFF00
          0000000000000000FFFFFFFFFFFF000000000000272727C5C5C5FFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
        ParentFont = False
        OnClick = SpeedButton1Click
      end
      object PanelModBusOpen: TPanel
        Tag = 202
        Left = 118
        Top = 7
        Width = 162
        Height = 39
        BevelOuter = bvLowered
        Caption = 'MODBUS CLOSE'
        Font.Charset = ANSI_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentBackground = False
        ParentFont = False
        TabOrder = 0
      end
    end
    object Panel1: TPanel
      Left = 7
      Top = 325
      Width = 1254
      Height = 433
      TabOrder = 1
      object ModBusGrid: TStringGrid
        Left = 12
        Top = 21
        Width = 594
        Height = 403
        Ctl3D = False
        DefaultColWidth = 40
        DrawingStyle = gdsGradient
        RowCount = 46
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #47569#51008' '#44256#46357
        Font.Style = []
        ParentCtl3D = False
        ParentFont = False
        ScrollBars = ssVertical
        TabOrder = 0
        OnDrawCell = ModBusGridDrawCell
        ColWidths = (
          40
          193
          67
          191
          69)
      end
      object CurvyPanel3: TCurvyPanel
        Left = 612
        Top = 356
        Width = 637
        Height = 68
        TabOrder = 1
        object BtnModbusSave: TSpeedButton
          Tag = 1
          Left = 310
          Top = 12
          Width = 130
          Height = 47
          Caption = 'SAVE DATA'
          Enabled = False
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = [fsBold]
          Glyph.Data = {
            36030000424D3603000000000000360000002800000010000000100000000100
            1800000000000003000012170000121700000000000000000000FFFFFFFFFFFF
            D0D0D01212120202020202020202020202020202020202020202020202020202
            02121212D0D0D0FFFFFFFFFFFFD1D1D115151505050505050505050505050505
            0505050505050505050505050505050505050505151515D1D1D1F0F0F0191919
            090909181818D1D1D1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD1D1
            D1181818090909191919F0F0F01B1B1B1B1B1BD1D1D1FFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD1D1D11B1B1B1B1B1BFFFFFFF0F0F0
            F0F0F0FFFFFFFFFFFFFFFFFFFFFFFFA5A5A54C4C4CA5A5A5FFFFFFFFFFFFFFFF
            FFFFFFFFF0F0F0F0F0F0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFA7A7A712
            1212121212121212A7A7A7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFA8A8A8151515151515151515151515151515A8A8A8FFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFA9A9A919191919191919
            1919191919191919191919191919A9A9A9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFAAAAAA1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C
            1CAAAAAAFFFFFFFFFFFFFFFFFFFFFFFFABABAB1F1F1F1F1F1F1F1F1F1F1F1F1F
            1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1FABABABFFFFFFFFFFFFFFFFFF
            2222222222222222222222222222222222222222222222222222222222222222
            22222222222222FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF2F2F225252525
            2525252525252525252525F2F2F2FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFF282828282828282828282828282828FFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF2C2C2C2C
            2C2C2C2C2C2C2C2C2C2C2CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFF2F2F2F2F2F2F2F2F2F2F2F2F2F2F2FFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE6E6E632323232
            3232323232323232323232FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
          ParentFont = False
          OnClick = BtnModbusSaveClick
        end
        object BtnModbusInput: TSpeedButton
          Tag = 1
          Left = 174
          Top = 12
          Width = 130
          Height = 47
          Caption = 'INPUT DATA'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = [fsBold]
          Glyph.Data = {
            36030000424D3603000000000000360000002800000010000000100000000100
            1800000000000003000012170000121700000000000000000000FFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFF02020202020202020202020202020202020202
            0202020202020202020202020202020202020202E0E0E0FFFFFFFFFFFF151515
            0606060606060606060606060606060606060606060606060606060606060606
            06060606A2A2A2FFFFFFFFFFFF57575709090909090909090909090909090909
            0909090909090909090909090909090909090909666666FFFFFFFFFFFF959595
            0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D
            0D0D0D0D2C2C2CFFFFFFFFFFFFE1E1E110101010101010101010101010101010
            1010101010101010101010101010101010101010101010D3D3D3FFFFFFFFFFFF
            3131311313131313131313131313131313131313131313131313131313131313
            13131313131313989898E3E3E3FFFFFF6E6E6E17171717171717171717171717
            17171717171717171717171717171717171717171717176060609B9B9BFFFFFF
            A9A9A91A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A
            1A1A1A1A1A1A1A292929656565FFFFFFE3E3E31E1E1E1E1E1E1E1E1E1E1E1E1E
            1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E2F2F2FFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFF242424BBBBBBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF282828282828
            2828282828282828282828282828282828282828282828282828282828282828
            285E5E5EFFFFFFFFFFFF3939392B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B
            2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B6E6E6EFFFFFFFFFFFF9797972F2F2F
            2F2F2F2F2F2F2F2F2F2F2F2F565656F2F2F2FFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFF5858583232323232323232323E3E3ED9D9D9FF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
          ParentFont = False
          OnClick = BtnModbusInputClick
        end
        object Label2: TLabel
          Left = 15
          Top = 11
          Width = 102
          Height = 19
          Caption = 'MODBUS DATA'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentFont = False
        end
      end
      object CurvyPanel2: TCurvyPanel
        Left = 611
        Top = 21
        Width = 638
        Height = 164
        TabOrder = 2
        object Label3: TLabel
          Left = 7
          Top = 6
          Width = 104
          Height = 19
          Caption = 'MODBUS COILS'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object ModbusCoil1: TPanel
          Left = 7
          Top = 29
          Width = 150
          Height = 41
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 0
          OnDblClick = ModbusCoil1DblClick
        end
        object ModbusCoil2: TPanel
          Tag = 1
          Left = 163
          Top = 29
          Width = 150
          Height = 41
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 1
          OnDblClick = ModbusCoil1DblClick
        end
        object ModbusCoil4: TPanel
          Tag = 3
          Left = 475
          Top = 29
          Width = 150
          Height = 41
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 2
          OnDblClick = ModbusCoil1DblClick
        end
        object ModbusCoil3: TPanel
          Tag = 2
          Left = 319
          Top = 29
          Width = 150
          Height = 41
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 3
          OnDblClick = ModbusCoil1DblClick
        end
        object ModbusCoil7: TPanel
          Tag = 6
          Left = 319
          Top = 76
          Width = 150
          Height = 41
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 4
          OnDblClick = ModbusCoil1DblClick
        end
        object ModbusCoil8: TPanel
          Tag = 7
          Left = 475
          Top = 76
          Width = 150
          Height = 41
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 5
          OnDblClick = ModbusCoil1DblClick
        end
        object ModbusCoil5: TPanel
          Tag = 4
          Left = 7
          Top = 76
          Width = 150
          Height = 41
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 6
          OnDblClick = ModbusCoil1DblClick
        end
        object ModbusCoil6: TPanel
          Tag = 5
          Left = 163
          Top = 76
          Width = 150
          Height = 41
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 7
          OnDblClick = ModbusCoil1DblClick
        end
      end
      object CurvyPanel5: TCurvyPanel
        Left = 611
        Top = 188
        Width = 638
        Height = 164
        TabOrder = 3
        object Label4: TLabel
          Left = 7
          Top = 11
          Width = 175
          Height = 19
          Caption = 'MODBUS DISCRETE INPUT'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object LabelModBusErrCode: TLabel
          Left = 24
          Top = 136
          Width = 107
          Height = 15
          Caption = 'ERROR CODE : 0000'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object ModbusInput1: TPanel
          Left = 23
          Top = 30
          Width = 111
          Height = 41
          BevelOuter = bvNone
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 0
        end
        object ModbusInput2: TPanel
          Left = 140
          Top = 29
          Width = 111
          Height = 41
          BevelOuter = bvNone
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 1
        end
        object ModbusInput4: TPanel
          Left = 372
          Top = 29
          Width = 111
          Height = 41
          BevelOuter = bvNone
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 2
        end
        object ModbusInput3: TPanel
          Left = 255
          Top = 29
          Width = 111
          Height = 41
          BevelOuter = bvNone
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 3
        end
        object ModbusInput5: TPanel
          Left = 489
          Top = 29
          Width = 111
          Height = 41
          BevelOuter = bvNone
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 4
        end
        object ModbusInput6: TPanel
          Left = 23
          Top = 77
          Width = 111
          Height = 41
          BevelOuter = bvNone
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 5
        end
        object ModbusInput7: TPanel
          Left = 140
          Top = 76
          Width = 111
          Height = 41
          BevelOuter = bvNone
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 6
        end
        object ModbusInput8: TPanel
          Left = 255
          Top = 76
          Width = 111
          Height = 41
          BevelOuter = bvNone
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 7
        end
        object ModbusInput9: TPanel
          Left = 372
          Top = 76
          Width = 111
          Height = 41
          BevelOuter = bvNone
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 8
        end
        object ModbusInput10: TPanel
          Left = 489
          Top = 76
          Width = 111
          Height = 41
          BevelOuter = bvNone
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 9
        end
      end
    end
    object PageControl1: TPageControl
      Left = 10
      Top = 67
      Width = 1254
      Height = 252
      ActivePage = TabSheet1
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = #47569#51008' '#44256#46357
      Font.Style = [fsBold]
      ParentFont = False
      TabHeight = 32
      TabOrder = 2
      TabWidth = 150
      object TabSheet1: TTabSheet
        Caption = 'Robot Position'
        ExplicitLeft = 0
        ExplicitTop = 0
        ExplicitWidth = 0
        ExplicitHeight = 0
        object StaubliGrid: TStringGrid
          Left = 0
          Top = 0
          Width = 1246
          Height = 210
          Align = alClient
          ColCount = 12
          Ctl3D = False
          DefaultColWidth = 90
          DrawingStyle = gdsGradient
          RowCount = 31
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = []
          Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goEditing, goTabs, goRowSelect]
          ParentCtl3D = False
          ParentFont = False
          ScrollBars = ssVertical
          TabOrder = 0
          OnDrawCell = StaubliGridDrawCell
          OnSelectCell = StaubliGridSelectCell
          ColWidths = (
            90
            195
            90
            90
            90
            90
            90
            90
            90
            90
            90
            90)
        end
      end
      object TabSheet2: TTabSheet
        Caption = 'Robot Speed'
        ImageIndex = 1
        ExplicitLeft = 0
        ExplicitTop = 0
        ExplicitWidth = 0
        ExplicitHeight = 0
        object StaubliGridSpeed: TStringGrid
          Left = 0
          Top = 0
          Width = 1246
          Height = 210
          Align = alClient
          ColCount = 4
          Ctl3D = False
          DefaultColWidth = 90
          DrawingStyle = gdsGradient
          RowCount = 31
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = []
          Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goEditing, goTabs, goRowSelect]
          ParentCtl3D = False
          ParentFont = False
          ScrollBars = ssVertical
          TabOrder = 0
          OnDrawCell = StaubliGridSpeedDrawCell
          ColWidths = (
            90
            218
            90
            90)
        end
      end
    end
  end
  object ModbusTimer: TTimer
    Enabled = False
    Interval = 500
    OnTimer = ModbusTimerTimer
    Left = 886
    Top = 166
  end
end
