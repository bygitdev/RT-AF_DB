object FrmMotorControl: TFrmMotorControl
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
    Left = 7
    Top = 5
    Width = 1268
    Height = 770
    TabOrder = 0
    object Panel1: TPanel
      Left = 7
      Top = 8
      Width = 1255
      Height = 56
      ParentBackground = False
      TabOrder = 0
      object BtnAxisSelect: TSpeedButton
        Tag = 1
        Left = 6
        Top = 5
        Width = 1237
        Height = 47
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #47569#51008' '#44256#46357
        Font.Style = [fsBold]
        ParentFont = False
        OnClick = BtnAxisSelectClick
      end
    end
    object MtrPosGrid: TStringGrid
      Left = 7
      Top = 69
      Width = 1255
      Height = 399
      Align = alCustom
      BevelInner = bvNone
      BevelKind = bkSoft
      BevelOuter = bvRaised
      BorderStyle = bsNone
      ColCount = 8
      Ctl3D = False
      DefaultColWidth = 50
      DefaultRowHeight = 35
      RowCount = 51
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Calibri'
      Font.Style = []
      Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goEditing, goTabs, goRowSelect]
      ParentCtl3D = False
      ParentFont = False
      ScrollBars = ssVertical
      TabOrder = 1
      OnDrawCell = MtrPosGridDrawCell
      OnSelectCell = MtrPosGridSelectCell
      ColWidths = (
        50
        578
        102
        102
        102
        101
        101
        91)
    end
    object Panel11: TPanel
      Left = 7
      Top = 504
      Width = 706
      Height = 94
      ParentBackground = False
      TabOrder = 2
      object BtnInputMotionData: TSpeedButton
        Tag = 1
        Left = 5
        Top = 42
        Width = 130
        Height = 47
        Caption = 'Input Data'
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
        Left = 566
        Top = 42
        Width = 130
        Height = 47
        Caption = 'Save Data'
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
      object BtnIndexMove: TSpeedButton
        Tag = 1
        Left = 286
        Top = 42
        Width = 130
        Height = 47
        Caption = 'INDEX MOVE'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #47569#51008' '#44256#46357
        Font.Style = [fsBold]
        Glyph.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          1800000000000003000012170000121700000000000000000000FFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0F0F0424242F0F0F0FFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF83
          8383050505838383FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF282828090909282828FFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC3C3C30C
          0C0C0C0C0C0C0C0CC3C3C3FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0F0F0101010F0F0F0FFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC5C5C5FFFFFFFFFFFFFF
          FFFF131313FFFFFFFFFFFFFFFFFFC5C5C5FFFFFFFFFFFFFFFFFFFFFFFFF1F1F1
          8B8B8B353535171717F1F1F1FFFFFFFFFFFF171717FFFFFFFFFFFFF1F1F11717
          173535358B8B8BF1F1F1FFFFFF5454541A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A
          1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A545454FFFFFFF1F1F1
          8E8E8E3A3A3A1E1E1EF1F1F1FFFFFFFFFFFF1E1E1EFFFFFFFFFFFFF1F1F11E1E
          1E3A3A3A8E8E8EF1F1F1FFFFFFFFFFFFFFFFFFFFFFFFC8C8C8FFFFFFFFFFFFFF
          FFFF212121FFFFFFFFFFFFFFFFFFC8C8C8FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF2F2F2252525F2F2F2FFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCACACA28
          2828282828282828CACACAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4646462C2C2C464646FFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF97
          97972F2F2F979797FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF3F3F3666666F3F3F3FFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
        ParentFont = False
        OnClick = BtnIndexMoveClick
      end
      object PanelMtrSelectIndex: TPanel
        Left = 46
        Top = 11
        Width = 612
        Height = 25
        Caption = 'SELECT:'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #47569#51008' '#44256#46357
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
      end
    end
    object Panel3: TPanel
      Left = 7
      Top = 472
      Width = 706
      Height = 29
      ParentBackground = False
      TabOrder = 3
      object Panel4: TPanel
        Left = 512
        Top = 3
        Width = 90
        Height = 20
        Color = 9729387
        ParentBackground = False
        TabOrder = 0
        object Label1: TLabel
          Left = 6
          Top = 1
          Width = 38
          Height = 18
          Caption = 'HOME'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWhite
          Font.Height = -15
          Font.Name = 'Calibri'
          Font.Style = []
          ParentFont = False
        end
        object MtrPanelLed2: TPanel
          Left = 54
          Top = 3
          Width = 30
          Height = 14
          BevelOuter = bvNone
          Caption = 'ON'
          Color = clLime
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Calibri'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 0
        end
      end
      object Panel5: TPanel
        Left = 174
        Top = 3
        Width = 73
        Height = 20
        Color = 9729387
        ParentBackground = False
        TabOrder = 1
        object Label2: TLabel
          Left = 6
          Top = 1
          Width = 21
          Height = 18
          Caption = 'CW'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWhite
          Font.Height = -15
          Font.Name = 'Calibri'
          Font.Style = []
          ParentFont = False
        end
        object MtrPanelLed1: TPanel
          Left = 39
          Top = 4
          Width = 30
          Height = 14
          BevelOuter = bvNone
          Caption = 'ON'
          Color = clLime
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Calibri'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 0
        end
      end
      object Panel6: TPanel
        Left = 328
        Top = 3
        Width = 102
        Height = 20
        Color = 9729387
        ParentBackground = False
        TabOrder = 2
        object Label3: TLabel
          Left = 9
          Top = 1
          Width = 53
          Height = 18
          Caption = 'DRIVING'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWhite
          Font.Height = -15
          Font.Name = 'Calibri'
          Font.Style = []
          ParentFont = False
        end
        object MtrPanelLed3: TPanel
          Left = 68
          Top = 3
          Width = 30
          Height = 14
          BevelOuter = bvNone
          Caption = 'ON'
          Color = clLime
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Calibri'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 0
        end
      end
      object Panel8: TPanel
        Left = 251
        Top = 3
        Width = 73
        Height = 20
        Color = 9729387
        ParentBackground = False
        TabOrder = 3
        object Label4: TLabel
          Left = 4
          Top = 1
          Width = 29
          Height = 18
          Caption = 'CCW'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWhite
          Font.Height = -15
          Font.Name = 'Calibri'
          Font.Style = []
          ParentFont = False
        end
        object MtrPanelLed6: TPanel
          Left = 39
          Top = 3
          Width = 30
          Height = 14
          BevelOuter = bvNone
          Caption = 'ON'
          Color = clLime
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Calibri'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 0
        end
      end
      object Panel9: TPanel
        Left = 433
        Top = 3
        Width = 73
        Height = 20
        Color = 9729387
        ParentBackground = False
        TabOrder = 4
        object Label5: TLabel
          Left = 6
          Top = 1
          Width = 27
          Height = 18
          Caption = 'ORG'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWhite
          Font.Height = -15
          Font.Name = 'Calibri'
          Font.Style = []
          ParentFont = False
        end
        object MtrPanelLed4: TPanel
          Left = 39
          Top = 3
          Width = 30
          Height = 14
          BevelOuter = bvNone
          Caption = 'ON'
          Color = clLime
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Calibri'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 0
        end
      end
      object Panel10: TPanel
        Left = 6
        Top = 3
        Width = 163
        Height = 20
        Color = 9729387
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentBackground = False
        ParentFont = False
        TabOrder = 5
        object MtrPostionLabel: TLabel
          Left = 10
          Top = 1
          Width = 135
          Height = 19
          Caption = 'REAL POS  : 1264375'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWhite
          Font.Height = -16
          Font.Name = 'Calibri'
          Font.Style = []
          ParentFont = False
        end
      end
      object Panel12: TPanel
        Left = 607
        Top = 3
        Width = 92
        Height = 20
        Color = 9729387
        ParentBackground = False
        TabOrder = 6
        object Label7: TLabel
          Left = 6
          Top = 1
          Width = 44
          Height = 18
          Caption = 'ALARM'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWhite
          Font.Height = -15
          Font.Name = 'Calibri'
          Font.Style = []
          ParentFont = False
        end
        object MtrPanelLed5: TPanel
          Left = 53
          Top = 3
          Width = 30
          Height = 14
          BevelOuter = bvNone
          Caption = 'ON'
          Color = clLime
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Calibri'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 0
        end
      end
    end
    object Panel7: TPanel
      Left = 7
      Top = 604
      Width = 706
      Height = 160
      TabOrder = 4
      object PanelServoOnOff: TPanel
        Left = 16
        Top = 10
        Width = 150
        Height = 27
        BevelInner = bvRaised
        BevelOuter = bvNone
        BorderStyle = bsSingle
        Caption = 'SERVO ON'
        Color = clLime
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Calibri'
        Font.Style = []
        ParentBackground = False
        ParentFont = False
        TabOrder = 0
      end
      object BtnAxisMotorHome: TBitBtn
        Left = 191
        Top = 43
        Width = 150
        Height = 53
        Caption = ' HOME'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = []
        Glyph.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          1800000000000003000012170000121700000000000000000000FFFFFFFFFFFF
          030303030303030303030303FFFFFFFFFFFFFFFFFFFFFFFF0303030303030303
          03030303FFFFFFFFFFFFFFFFFFFFFFFF060606060606060606060606FFFFFFFF
          FFFFFFFFFFFFFFFF060606060606060606060606FFFFFFFFFFFFFFFFFFFFFFFF
          0A0A0A0A0A0A0A0A0A0A0A0AFFFFFFFFFFFFFFFFFFFFFFFF0A0A0A0A0A0A0A0A
          0A0A0A0AFFFFFFFFFFFFFFFFFFFFFFFF0D0D0D0D0D0D0D0D0D0D0D0DFFFFFFFF
          FFFFFFFFFFFFFFFF0D0D0D0D0D0D0D0D0D0D0D0DFFFFFFFFFFFFFFFFFFFFFFFF
          111111111111111111111111FFFFFFFFFFFFFFFFFFFFFFFF1111111111111111
          11111111FFFFFFFFFFFFFFFFFFD4D4D4151515151515151515151515FFFFFFFF
          FFFFFFFFFFFFFFFF151515151515151515151515D4D4D4FFFFFF7E7E7E181818
          181818181818181818181818C6C6C6C6C6C6C6C6C6C6C6C61818181818181818
          181818181818187E7E7E1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C
          1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1CC7C7C72E2E2E
          1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F
          1F1F1F1F2E2E2EB9B9B9FFFFFFD6D6D63E3E3E23232323232323232323232323
          2323232323232323232323232323232323303030D6D6D6FFFFFFFFFFFFFFFFFF
          F2F2F24F4F4F2626262626262626262626262626262626262626262626264242
          42F2F2F2FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF7A7A7A2A2A2A2A2A2A2A
          2A2A2A2A2A2A2A2A2A2A2A2A2A2A606060FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFA3A3A32E2E2E2E2E2E2E2E2E3B3B3B4848482E2E2E6363
          63FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBEBEBE3D
          3D3D3D3D3DD8D8D8656565313131656565FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE6E6E6E6E6E6FFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
        ParentFont = False
        TabOrder = 1
        OnClick = BtnAxisMotorHomeClick
      end
      object BtnAxisMotorStop: TBitBtn
        Left = 540
        Top = 43
        Width = 150
        Height = 53
        Caption = 'STOP'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = []
        Glyph.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          1800000000000003000012170000121700000000000000000000FFFFFFFFFFFF
          FFFFFFFFFFFFF0F0F0727272222222020202020202020202222222727272F0F0
          F0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB2B2B216161606060606060606
          0606060606060606060606060606161616B2B2B2FFFFFFFFFFFFFFFFFFFFFFFF
          B2B2B20909090909090909090909090909090909090909090909090909090909
          09090909B2B2B2FFFFFFFFFFFFF0F0F01D1D1D0D0D0D0D0D0D0D0D0D0D0D0D77
          7777FFFFFF7777770D0D0D0D0D0D0D0D0D0D0D0D1D1D1DF0F0F0FFFFFF797979
          101010101010101010101010101010888888FFFFFF8888881010101010101010
          10101010101010797979FFFFFF31313113131313131313131313131313131389
          8989FFFFFF898989131313131313131313131313131313313131FFFFFF171717
          1717171717171717171717171717178B8B8BFFFFFF8B8B8B1717171717171717
          17171717171717171717E3E3E31A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A8D
          8D8DFFFFFF8D8D8D1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1AFFFFFF1E1E1E
          1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E818181FFFFFF8181811E1E1E1E1E1E1E1E
          1E1E1E1E1E1E1E1E1E1EFFFFFF3C3C3C21212121212121212121212121212121
          21212121212121212121212121212121212121212121213C3C3CFFFFFF858585
          242424242424242424242424242424696969C8C8C86969692424242424242424
          24242424242424858585FFFFFFF2F2F23535352828282828282828282828286C
          6C6CCACACA6C6C6C282828282828282828282828353535F2F2F2FFFFFFFFFFFF
          BDBDBD2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B
          2B2B2B2BBDBDBDFFFFFFFFFFFFFFFFFFFFFFFFBEBEBE3C3C3C2F2F2F2F2F2F2F
          2F2F2F2F2F2F2F2F2F2F2F2F2F2F3C3C3CBEBEBEFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFF3F3F38C8C8C4B4B4B3232323232323232324B4B4B8C8C8CF3F3
          F3FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
        ParentFont = False
        TabOrder = 2
        OnClick = BtnAxisMotorStopClick
      end
      object BtnAxisMotorReset: TBitBtn
        Left = 367
        Top = 43
        Width = 150
        Height = 53
        Caption = 'RESET'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = []
        Glyph.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          1800000000000003000012170000121700000000000000000000FFFFFFD0D0D0
          FFFFFFFFFFFFC0C0C0525252020202020202020202020202525252C0C0C0FFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFF05050574747474747405050505050505050505
          0505050505050505050505050505747474FFFFFFFFFFFFFFFFFFFFFFFF090909
          090909090909090909272727A2A2A2C1C1C1C1C1C1A2A2A22727270909090909
          09767676FFFFFFFFFFFFFFFFFF0C0C0C0C0C0C0C0C0C0C0C0C777777FFFFFFFF
          FFFFFFFFFFFFFFFFF0F0F06767670C0C0C0C0C0CC3C3C3FFFFFFFFFFFF0F0F0F
          0F0F0F0F0F0F0F0F0F0F0F0F5B5B5BFFFFFFFFFFFFFFFFFFFFFFFFF0F0F02E2E
          2E0F0F0F5B5B5BFFFFFFFFFFFF121212121212121212303030898989E2E2E2FF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFA6A6A6121212121212FFFFFFFFFFFF242424
          6E6E6EC5C5C5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE2E2
          E2242424424242FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFF4A4A4A2E2E2EE4E4E4FFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFC8C8C87474742E2E2EFFFFFFFFFFFF222222
          222222ACACACFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE4E4E49191913E3E3E2222
          22222222222222FFFFFFFFFFFF6A6A6A252525414141F2F2F2FFFFFFFFFFFFFF
          FFFFFFFFFF6A6A6A252525252525252525252525252525FFFFFFFFFFFFCACACA
          2828282828287A7A7AF2F2F2FFFFFFFFFFFFFFFFFFFFFFFF8787872828282828
          28282828282828FFFFFFFFFFFFFFFFFF8989892C2C2C2C2C2C474747B0B0B0CB
          CBCBCBCBCBB0B0B04747472C2C2C2C2C2C2C2C2C2C2C2CFFFFFFFFFFFFFFFFFF
          FFFFFF8A8A8A2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F8A8A
          8A8A8A8A2F2F2FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCCCCCC72727232323232
          3232323232323232727272CCCCCCFFFFFFFFFFFFD9D9D9FFFFFF}
        ParentFont = False
        TabOrder = 3
        OnClick = BtnAxisMotorResetClick
      end
      object BtnServoControl: TBitBtn
        Left = 16
        Top = 43
        Width = 150
        Height = 53
        Caption = 'SERVO ON/OFF '
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = []
        Glyph.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          1800000000000003000012170000121700000000000000000000FFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF818181020202818181FFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD1D1D1E0E0E0FFFFFFFFFFFF35
          3535060606353535FFFFFFFFFFFFE0E0E0D1D1D1FFFFFFFFFFFFFFFFFFFFFFFF
          D1D1D1090909090909848484F0F0F0090909090909090909F0F0F08484840909
          09090909D1D1D1FFFFFFFFFFFFFFFFFFE1E1E10C0C0C0C0C0C0C0C0C1C1C1C0C
          0C0C0C0C0C0C0C0C1C1C1C0C0C0C0C0C0C0C0C0CE1E1E1FFFFFFFFFFFFFFFFFF
          FFFFFF8787871010101010101010101010101010101010101010101010101010
          10878787FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1F1F122222213131313131313
          1313131313131313131313131313222222F1F1F1FFFFFFFFFFFFFFFFFF8B8B8B
          4343431717171717171717171717171717171717171717171717171717171717
          171717174343438B8B8BE3E3E31A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A
          1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1AFFFFFF8E8E8E
          4848481D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D
          1D1D1D1D4848488E8E8EFFFFFFFFFFFFFFFFFFF1F1F12F2F2F21212121212121
          21212121212121212121212121212F2F2FF1F1F1FFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFF9292922424242424242424242424242424242424242424242424242424
          24929292FFFFFFFFFFFFFFFFFFFFFFFFE5E5E528282828282828282835353528
          2828282828282828353535282828282828282828E5E5E5FFFFFFFFFFFFFFFFFF
          D7D7D72B2B2B2B2B2B959595F2F2F22B2B2B2B2B2B2B2B2BF2F2F29595952B2B
          2B2B2B2BD7D7D7FFFFFFFFFFFFFFFFFFFFFFFFD8D8D8E5E5E5FFFFFFFFFFFF56
          56562F2F2F565656FFFFFFFFFFFFE5E5E5D8D8D8FFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF989898323232989898FFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
        ParentFont = False
        TabOrder = 4
        OnClick = BtnServoControlClick
      end
      object BtnAxisConfig: TBitBtn
        Left = 16
        Top = 102
        Width = 150
        Height = 53
        Caption = 'MOTOR SET'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = []
        Glyph.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          1800000000000003000012170000121700000000000000000000FFFFFFFFFFFF
          1212120202020202020202020202020202020202020202020202020202020202
          02121212FFFFFFFFFFFFFFFFFFFFFFFF05050505050505050505050505050505
          0505050505050505050505050505050505050505FFFFFFFFFFFFFFFFFFFFFFFF
          090909090909A3A3A3FFFFFFFFFFFFFFFFFF9393930909090909090909090909
          09090909FFFFFFFFFFFFFFFFFFFFFFFF0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C
          0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0CFFFFFFFFFFFFFFFFFFFFFFFF
          0F0F0F0F0F0FA5A5A5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9696960F0F
          0F0F0F0FFFFFFFFFFFFFFFFFFFFFFFFF12121212121212121212121212121212
          1212121212121212121212121212121212121212FFFFFFFFFFFFFFFFFFFFFFFF
          151515151515A7A7A7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9999991515
          15151515FFFFFFFFFFFFFFFFFFFFFFFF19191919191919191919191919191919
          1919191919191919191919191919191919191919FFFFFFFFFFFFFFFFFFFFFFFF
          1C1C1C1C1C1CAAAAAAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9B9B9B1C1C
          1C1C1C1CFFFFFFFFFFFFFFFFFFFFFFFF1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F
          1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1FFFFFFFFFFFFFFFFFFFFFFFFF
          222222222222ACACACFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9E9E9E2222
          22222222FFFFFFFFFFFFFFFFFFFFFFFF25252525252525252525252525252525
          2525252525252525252525252525252525252525FFFFFFFFFFFFFFFFFFFFFFFF
          282828282828AFAFAFAFAFAF282828AFAFAFFFFFFFFFFFFFFFFFFFA1A1A12828
          28282828FFFFFFFFFFFFFFFFFFFFFFFF2C2C2C2C2C2CB0B0B0B0B0B02C2C2C2C
          2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2CFFFFFFFFFFFFFFFFFFF3F3F3
          2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F
          2F2F2F2FFFFFFFFFFFFFFFFFFFF3F3F33F3F3F32323232323232323232323232
          32323232323232323232323232323232323F3F3FFFFFFFFFFFFF}
        ParentFont = False
        TabOrder = 5
        Visible = False
        OnClick = BtnAxisConfigClick
      end
      object PanelTenkeyJog: TPanel
        Left = 542
        Top = 102
        Width = 150
        Height = 53
        BevelInner = bvRaised
        BorderStyle = bsSingle
        Caption = 'TENKEY  JOG MODE'
        Color = clLime
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Calibri'
        Font.Style = []
        ParentBackground = False
        ParentFont = False
        TabOrder = 6
        OnClick = PanelTenkeyJogClick
      end
    end
    object Panel2: TPanel
      Left = 719
      Top = 472
      Width = 543
      Height = 292
      TabOrder = 5
      object Label6: TLabel
        Left = 132
        Top = 111
        Width = 61
        Height = 38
        Alignment = taCenter
        Caption = 'Jog Pos.(mm)'
        Font.Charset = ANSI_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
        WordWrap = True
      end
      object BtnJog4: TButton
        Tag = 21
        Left = 77
        Top = 233
        Width = 170
        Height = 55
        Caption = '   '#9660'Y[-]'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = #47569#51008' '#44256#46357
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        WordWrap = True
        OnClick = BtnJog4Click
        OnMouseDown = BtnJog1MouseDown
        OnMouseUp = BtnJog1MouseUp
      end
      object BtnJog2: TButton
        Tag = 10
        Left = 249
        Top = 68
        Width = 55
        Height = 170
        Caption = '  '#9654'    X[+]'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = #47569#51008' '#44256#46357
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
        WordWrap = True
        OnClick = BtnJog2Click
        OnMouseDown = BtnJog2MouseDown
        OnMouseUp = BtnJog2MouseUp
      end
      object EditJogPosition: TEdit
        Left = 133
        Top = 155
        Width = 67
        Height = 34
        Alignment = taCenter
        Color = clWhite
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -21
        Font.Name = 'Calibri'
        Font.Style = []
        ImeName = 'Microsoft IME 2010'
        ParentFont = False
        TabOrder = 2
        Text = '0'
      end
      object BtnJog3: TButton
        Tag = 20
        Left = 77
        Top = 13
        Width = 170
        Height = 55
        Caption = '   '#9650'Y[+]'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = #47569#51008' '#44256#46357
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 3
        WordWrap = True
        OnClick = BtnJog2Click
        OnMouseDown = BtnJog2MouseDown
        OnMouseUp = BtnJog2MouseUp
      end
      object BtnJog1: TButton
        Tag = 11
        Left = 16
        Top = 68
        Width = 55
        Height = 170
        Caption = ' '#9664'    X[-]'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = #47569#51008' '#44256#46357
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 4
        WordWrap = True
        OnClick = BtnJog4Click
        OnMouseDown = BtnJog1MouseDown
        OnMouseUp = BtnJog1MouseUp
      end
      object BtnJog5: TButton
        Left = 310
        Top = 54
        Width = 66
        Height = 93
        Caption = '  '#9651'     Z[-]'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = #47569#51008' '#44256#46357
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 5
        WordWrap = True
        OnClick = BtnJog4Click
        OnMouseDown = BtnJog1MouseDown
        OnMouseUp = BtnJog1MouseUp
      end
      object BtnJog6: TButton
        Tag = 1
        Left = 310
        Top = 165
        Width = 66
        Height = 92
        Caption = '  '#9661'     Z[+]'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = #47569#51008' '#44256#46357
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 6
        WordWrap = True
        OnClick = BtnJog2Click
        OnMouseDown = BtnJog2MouseDown
        OnMouseUp = BtnJog2MouseUp
      end
      object Panel13: TPanel
        Left = 382
        Top = 15
        Width = 157
        Height = 267
        ParentBackground = False
        TabOrder = 7
        object Label8: TLabel
          Left = 49
          Top = 123
          Width = 64
          Height = 19
          Alignment = taCenter
          Caption = 'Jog Speed'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Calibri'
          Font.Style = []
          ParentFont = False
        end
        object BtnJogSpeedApply: TSpeedButton
          Tag = 1
          Left = 19
          Top = 196
          Width = 130
          Height = 47
          Caption = 'Apply'
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
          OnClick = BtnJogSpeedApplyClick
        end
        object EditJogSpeed: TEdit
          Left = 34
          Top = 148
          Width = 107
          Height = 34
          Alignment = taCenter
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = 'Calibri'
          Font.Style = []
          ImeName = 'Microsoft IME 2010'
          ParentFont = False
          TabOrder = 0
          Text = '0'
        end
        object RadioButtonJogMove: TRadioButton
          Left = 34
          Top = 8
          Width = 103
          Height = 21
          Caption = 'JOG Move'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 1
        end
        object RadioButtonRMove: TRadioButton
          Left = 34
          Top = 44
          Width = 81
          Height = 17
          Caption = 'R-Move'
          Checked = True
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 2
          TabStop = True
        end
      end
    end
  end
  object MtrRefreshTimer: TTimer
    Enabled = False
    Interval = 200
    OnTimer = MtrRefreshTimerTimer
    Left = 65
    Top = 200
  end
end
