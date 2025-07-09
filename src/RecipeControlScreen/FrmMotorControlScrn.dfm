object FrmMotorControl: TFrmMotorControl
  Left = 0
  Top = 0
  BorderStyle = bsNone
  ClientHeight = 433
  ClientWidth = 942
  Color = clGray
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 942
    Height = 433
    Color = clSilver
    ParentBackground = False
    TabOrder = 0
    object Panel2: TPanel
      Left = 1
      Top = 9
      Width = 941
      Height = 417
      Color = clWhite
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Calibri'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 0
      object Label6: TLabel
        Left = 638
        Top = 202
        Width = 71
        Height = 15
        Alignment = taCenter
        Caption = 'Jog Pos.(mm)'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
        WordWrap = True
      end
      object Label8: TLabel
        Left = 813
        Top = 77
        Width = 52
        Height = 15
        Alignment = taCenter
        Caption = 'Jog Speed'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
      end
      object BtnAxis0: TBitBtn
        Left = 7
        Top = 6
        Width = 150
        Height = 38
        Caption = ' MOTOR AXIS'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = []
        Glyph.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          1800000000000003000012170000121700000000000000000000FFFFFFFFFFFF
          FFFFFFF0F0F0424242020202818181FFFFFFFFFFFF818181020202424242F0F0
          F0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC1C1C1050505050505050505C1
          C1C1C1C1C1050505050505050505C1C1C1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFF090909090909090909090909090909090909090909090909FFFF
          FFFFFFFFFFFFFFFFFFFFF0F0F0C3C3C3FFFFFFD2D2D20C0C0C0C0C0C0C0C0C49
          49494949490C0C0C0C0C0C0C0C0CD2D2D2FFFFFFC3C3C3F0F0F04C4C4C0F0F0F
          0F0F0F0F0F0F0F0F0F787878F0F0F0FFFFFFFFFFFFF0F0F07878780F0F0F0F0F
          0F0F0F0F0F0F0F4C4C4C1212121212121212121212127B7B7BFFFFFFF1F1F198
          9898A7A7A7F1F1F1FFFFFF7B7B7B1212121212121212121212128A8A8A151515
          151515242424F1F1F1F1F1F1242424151515151515242424F1F1F1F1F1F12424
          241515151515158A8A8AFFFFFFC6C6C6191919535353FFFFFF9A9A9A191919D4
          D4D4D4D4D41919199A9A9AFFFFFF535353191919C6C6C6FFFFFFFFFFFFC7C7C7
          1C1C1C555555FFFFFF8E8E8E1C1C1CD5D5D5D5D5D51C1C1C8E8E8EFFFFFF5555
          551C1C1CC7C7C7FFFFFF8F8F8F1F1F1F1F1F1F3C3C3CFFFFFFE3E3E32D2D2D1F
          1F1F1F1F1F2D2D2DE3E3E3FFFFFF3C3C3C1F1F1F1F1F1F8F8F8F222222222222
          2222222222229E9E9EFFFFFFE4E4E4909090909090E4E4E4FFFFFF9E9E9E2222
          222222222222222222225C5C5C252525252525252525252525A0A0A0FFFFFFFF
          FFFFFFFFFFFFFFFFA0A0A02525252525252525252525255C5C5CF2F2F2C9C9C9
          FFFFFFD7D7D7282828282828434343878787878787434343282828282828D7D7
          D7FFFFFFC9C9C9F2F2F2FFFFFFFFFFFFFFFFFFFFFFFF2C2C2C2C2C2C2C2C2C2C
          2C2C2C2C2C2C2C2C2C2C2C2C2C2CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFCBCBCB2F2F2F2F2F2F2F2F2FCBCBCBCBCBCB2F2F2F2F2F2F2F2F2FCBCB
          CBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF3F3F3656565323232999999FF
          FFFFFFFFFF999999323232656565F3F3F3FFFFFFFFFFFFFFFFFF}
        ParentFont = False
        TabOrder = 0
        OnClick = BtnAxis0Click
      end
      object MtrPosGrid: TStringGrid
        Left = 7
        Top = 74
        Width = 541
        Height = 253
        Align = alCustom
        BevelInner = bvNone
        BevelKind = bkSoft
        BevelOuter = bvRaised
        BorderStyle = bsNone
        ColCount = 6
        Ctl3D = False
        DefaultColWidth = 25
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
        OnSelectCell = MtrPosGridSelectCell
        ColWidths = (
          25
          224
          65
          64
          66
          72)
      end
      object Panel3: TPanel
        Left = 7
        Top = 46
        Width = 929
        Height = 25
        ParentBackground = False
        TabOrder = 2
        object Panel4: TPanel
          Left = 273
          Top = 3
          Width = 102
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
        object Panel5: TPanel
          Left = 164
          Top = 3
          Width = 102
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
        object Panel6: TPanel
          Left = 381
          Top = 3
          Width = 102
          Height = 20
          Color = 9729387
          ParentBackground = False
          TabOrder = 2
          object Label3: TLabel
            Left = 6
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
          Left = 715
          Top = 3
          Width = 102
          Height = 20
          Color = 9729387
          ParentBackground = False
          TabOrder = 3
          object Label4: TLabel
            Left = 6
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
        object Panel9: TPanel
          Left = 491
          Top = 3
          Width = 102
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
        object Panel10: TPanel
          Left = 6
          Top = 3
          Width = 151
          Height = 20
          Color = 9729387
          ParentBackground = False
          TabOrder = 5
          object MtrPostionLabel: TLabel
            Left = 10
            Top = 1
            Width = 120
            Height = 18
            Caption = 'REAL POS  : 1264375'
            Font.Charset = ANSI_CHARSET
            Font.Color = clWhite
            Font.Height = -15
            Font.Name = 'Calibri'
            Font.Style = []
            ParentFont = False
          end
        end
        object Panel12: TPanel
          Left = 602
          Top = 3
          Width = 102
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
      end
      object RadioButtonRMove: TRadioButton
        Left = 648
        Top = 93
        Width = 81
        Height = 17
        Caption = 'R-Move'
        Checked = True
        TabOrder = 3
        TabStop = True
      end
      object RadioButtonJogMove: TRadioButton
        Left = 561
        Top = 91
        Width = 73
        Height = 21
        Caption = 'JOG Move'
        TabOrder = 4
      end
      object BtnJog3: TButton
        Tag = 20
        Left = 628
        Top = 124
        Width = 90
        Height = 60
        Caption = '   '#9650'      Y1[-]'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = #47569#51008' '#44256#46357
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 5
        WordWrap = True
        OnClick = BtnJog2Click
        OnMouseDown = BtnJog2MouseDown
        OnMouseUp = BtnJog2MouseUp
      end
      object BtnJog1: TButton
        Tag = 11
        Left = 724
        Top = 181
        Width = 55
        Height = 113
        Caption = ' '#9664'    X[+]'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = #47569#51008' '#44256#46357
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 6
        WordWrap = True
        OnClick = BtnJog4Click
        OnMouseDown = BtnJog1MouseDown
        OnMouseUp = BtnJog1MouseUp
      end
      object BtnJog4: TButton
        Tag = 21
        Left = 628
        Top = 273
        Width = 90
        Height = 59
        Caption = '   '#9660'      Y1[+]'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = #47569#51008' '#44256#46357
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 7
        WordWrap = True
        OnClick = BtnJog4Click
        OnMouseDown = BtnJog1MouseDown
        OnMouseUp = BtnJog1MouseUp
      end
      object Panel11: TPanel
        Left = 7
        Top = 329
        Width = 541
        Height = 83
        ParentBackground = False
        TabOrder = 8
        object BtnInputMotionData: TSpeedButton
          Tag = 1
          Left = 5
          Top = 39
          Width = 130
          Height = 40
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
          Left = 407
          Top = 39
          Width = 130
          Height = 40
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
          Left = 223
          Top = 39
          Width = 130
          Height = 40
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
          Left = 78
          Top = 8
          Width = 409
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
      object BtnJog6: TButton
        Tag = 1
        Left = 820
        Top = 245
        Width = 88
        Height = 59
        Caption = '  '#9661'     Z[+]'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = #47569#51008' '#44256#46357
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 9
        WordWrap = True
        OnClick = BtnJog4Click
        OnMouseDown = BtnJog1MouseDown
        OnMouseUp = BtnJog1MouseUp
      end
      object BtnJog2: TButton
        Tag = 10
        Left = 567
        Top = 181
        Width = 55
        Height = 113
        Caption = '  '#9654'    X[-]'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = #47569#51008' '#44256#46357
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 10
        WordWrap = True
        OnClick = BtnJog2Click
        OnMouseDown = BtnJog2MouseDown
        OnMouseUp = BtnJog2MouseUp
      end
      object BtnJog5: TButton
        Left = 820
        Top = 155
        Width = 88
        Height = 60
        Caption = '  '#9651'     Z[-]'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = #47569#51008' '#44256#46357
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 11
        WordWrap = True
        OnClick = BtnJog2Click
        OnMouseDown = BtnJog2MouseDown
        OnMouseUp = BtnJog2MouseUp
      end
      object EditJogPosition: TEdit
        Left = 640
        Top = 222
        Width = 67
        Height = 31
        Alignment = taCenter
        Color = clWhite
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Calibri'
        Font.Style = []
        ImeName = 'Microsoft IME 2010'
        ParentFont = False
        TabOrder = 12
        Text = '0'
      end
      object BtnServoControl: TButton
        Left = 566
        Top = 379
        Width = 74
        Height = 27
        Caption = 'ON / OFF'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
        TabOrder = 13
        WordWrap = True
        OnClick = BtnServoControlClick
      end
      object PanelServoOnOff: TPanel
        Left = 566
        Top = 353
        Width = 74
        Height = 23
        BevelOuter = bvNone
        Caption = 'SERVO ON'
        Color = clLime
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Calibri'
        Font.Style = []
        ParentBackground = False
        ParentFont = False
        TabOrder = 14
      end
      object EditJogSpeed: TEdit
        Left = 807
        Top = 97
        Width = 67
        Height = 27
        Alignment = taCenter
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Calibri'
        Font.Style = []
        ImeName = 'Microsoft IME 2010'
        ParentFont = False
        TabOrder = 15
        Text = '0'
      end
      object BtnJogSpeedApply: TButton
        Left = 880
        Top = 85
        Width = 52
        Height = 32
        Caption = 'Apply'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
        TabOrder = 16
        WordWrap = True
        OnClick = BtnJogSpeedApplyClick
      end
      object BtnAxisMotorHome: TBitBtn
        Left = 693
        Top = 353
        Width = 77
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
        TabOrder = 17
        OnClick = BtnAxisMotorHomeClick
      end
      object BtnAxisMotorStop: TBitBtn
        Left = 775
        Top = 353
        Width = 77
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
        TabOrder = 18
        OnClick = BtnAxisMotorStopClick
      end
      object BtnAxisMotorReset: TBitBtn
        Left = 856
        Top = 353
        Width = 77
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
        TabOrder = 19
        OnClick = BtnAxisMotorResetClick
      end
      object BtnAxis1: TBitBtn
        Tag = 1
        Left = 163
        Top = 6
        Width = 150
        Height = 38
        Caption = ' MOTOR AXIS'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = []
        Glyph.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          1800000000000003000012170000121700000000000000000000FFFFFFFFFFFF
          FFFFFFF0F0F0424242020202818181FFFFFFFFFFFF818181020202424242F0F0
          F0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC1C1C1050505050505050505C1
          C1C1C1C1C1050505050505050505C1C1C1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFF090909090909090909090909090909090909090909090909FFFF
          FFFFFFFFFFFFFFFFFFFFF0F0F0C3C3C3FFFFFFD2D2D20C0C0C0C0C0C0C0C0C49
          49494949490C0C0C0C0C0C0C0C0CD2D2D2FFFFFFC3C3C3F0F0F04C4C4C0F0F0F
          0F0F0F0F0F0F0F0F0F787878F0F0F0FFFFFFFFFFFFF0F0F07878780F0F0F0F0F
          0F0F0F0F0F0F0F4C4C4C1212121212121212121212127B7B7BFFFFFFF1F1F198
          9898A7A7A7F1F1F1FFFFFF7B7B7B1212121212121212121212128A8A8A151515
          151515242424F1F1F1F1F1F1242424151515151515242424F1F1F1F1F1F12424
          241515151515158A8A8AFFFFFFC6C6C6191919535353FFFFFF9A9A9A191919D4
          D4D4D4D4D41919199A9A9AFFFFFF535353191919C6C6C6FFFFFFFFFFFFC7C7C7
          1C1C1C555555FFFFFF8E8E8E1C1C1CD5D5D5D5D5D51C1C1C8E8E8EFFFFFF5555
          551C1C1CC7C7C7FFFFFF8F8F8F1F1F1F1F1F1F3C3C3CFFFFFFE3E3E32D2D2D1F
          1F1F1F1F1F2D2D2DE3E3E3FFFFFF3C3C3C1F1F1F1F1F1F8F8F8F222222222222
          2222222222229E9E9EFFFFFFE4E4E4909090909090E4E4E4FFFFFF9E9E9E2222
          222222222222222222225C5C5C252525252525252525252525A0A0A0FFFFFFFF
          FFFFFFFFFFFFFFFFA0A0A02525252525252525252525255C5C5CF2F2F2C9C9C9
          FFFFFFD7D7D7282828282828434343878787878787434343282828282828D7D7
          D7FFFFFFC9C9C9F2F2F2FFFFFFFFFFFFFFFFFFFFFFFF2C2C2C2C2C2C2C2C2C2C
          2C2C2C2C2C2C2C2C2C2C2C2C2C2CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFCBCBCB2F2F2F2F2F2F2F2F2FCBCBCBCBCBCB2F2F2F2F2F2F2F2F2FCBCB
          CBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF3F3F3656565323232999999FF
          FFFFFFFFFF999999323232656565F3F3F3FFFFFFFFFFFFFFFFFF}
        ParentFont = False
        TabOrder = 20
        OnClick = BtnAxis0Click
      end
      object BtnAxis3: TBitBtn
        Tag = 3
        Left = 475
        Top = 6
        Width = 150
        Height = 38
        Caption = ' MOTOR AXIS'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = []
        Glyph.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          1800000000000003000012170000121700000000000000000000FFFFFFFFFFFF
          FFFFFFF0F0F0424242020202818181FFFFFFFFFFFF818181020202424242F0F0
          F0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC1C1C1050505050505050505C1
          C1C1C1C1C1050505050505050505C1C1C1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFF090909090909090909090909090909090909090909090909FFFF
          FFFFFFFFFFFFFFFFFFFFF0F0F0C3C3C3FFFFFFD2D2D20C0C0C0C0C0C0C0C0C49
          49494949490C0C0C0C0C0C0C0C0CD2D2D2FFFFFFC3C3C3F0F0F04C4C4C0F0F0F
          0F0F0F0F0F0F0F0F0F787878F0F0F0FFFFFFFFFFFFF0F0F07878780F0F0F0F0F
          0F0F0F0F0F0F0F4C4C4C1212121212121212121212127B7B7BFFFFFFF1F1F198
          9898A7A7A7F1F1F1FFFFFF7B7B7B1212121212121212121212128A8A8A151515
          151515242424F1F1F1F1F1F1242424151515151515242424F1F1F1F1F1F12424
          241515151515158A8A8AFFFFFFC6C6C6191919535353FFFFFF9A9A9A191919D4
          D4D4D4D4D41919199A9A9AFFFFFF535353191919C6C6C6FFFFFFFFFFFFC7C7C7
          1C1C1C555555FFFFFF8E8E8E1C1C1CD5D5D5D5D5D51C1C1C8E8E8EFFFFFF5555
          551C1C1CC7C7C7FFFFFF8F8F8F1F1F1F1F1F1F3C3C3CFFFFFFE3E3E32D2D2D1F
          1F1F1F1F1F2D2D2DE3E3E3FFFFFF3C3C3C1F1F1F1F1F1F8F8F8F222222222222
          2222222222229E9E9EFFFFFFE4E4E4909090909090E4E4E4FFFFFF9E9E9E2222
          222222222222222222225C5C5C252525252525252525252525A0A0A0FFFFFFFF
          FFFFFFFFFFFFFFFFA0A0A02525252525252525252525255C5C5CF2F2F2C9C9C9
          FFFFFFD7D7D7282828282828434343878787878787434343282828282828D7D7
          D7FFFFFFC9C9C9F2F2F2FFFFFFFFFFFFFFFFFFFFFFFF2C2C2C2C2C2C2C2C2C2C
          2C2C2C2C2C2C2C2C2C2C2C2C2C2CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFCBCBCB2F2F2F2F2F2F2F2F2FCBCBCBCBCBCB2F2F2F2F2F2F2F2F2FCBCB
          CBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF3F3F3656565323232999999FF
          FFFFFFFFFF999999323232656565F3F3F3FFFFFFFFFFFFFFFFFF}
        ParentFont = False
        TabOrder = 21
        OnClick = BtnAxis0Click
      end
      object BtnAxis2: TBitBtn
        Tag = 2
        Left = 319
        Top = 6
        Width = 150
        Height = 38
        Caption = ' MOTOR AXIS'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = []
        Glyph.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          1800000000000003000012170000121700000000000000000000FFFFFFFFFFFF
          FFFFFFF0F0F0424242020202818181FFFFFFFFFFFF818181020202424242F0F0
          F0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC1C1C1050505050505050505C1
          C1C1C1C1C1050505050505050505C1C1C1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFF090909090909090909090909090909090909090909090909FFFF
          FFFFFFFFFFFFFFFFFFFFF0F0F0C3C3C3FFFFFFD2D2D20C0C0C0C0C0C0C0C0C49
          49494949490C0C0C0C0C0C0C0C0CD2D2D2FFFFFFC3C3C3F0F0F04C4C4C0F0F0F
          0F0F0F0F0F0F0F0F0F787878F0F0F0FFFFFFFFFFFFF0F0F07878780F0F0F0F0F
          0F0F0F0F0F0F0F4C4C4C1212121212121212121212127B7B7BFFFFFFF1F1F198
          9898A7A7A7F1F1F1FFFFFF7B7B7B1212121212121212121212128A8A8A151515
          151515242424F1F1F1F1F1F1242424151515151515242424F1F1F1F1F1F12424
          241515151515158A8A8AFFFFFFC6C6C6191919535353FFFFFF9A9A9A191919D4
          D4D4D4D4D41919199A9A9AFFFFFF535353191919C6C6C6FFFFFFFFFFFFC7C7C7
          1C1C1C555555FFFFFF8E8E8E1C1C1CD5D5D5D5D5D51C1C1C8E8E8EFFFFFF5555
          551C1C1CC7C7C7FFFFFF8F8F8F1F1F1F1F1F1F3C3C3CFFFFFFE3E3E32D2D2D1F
          1F1F1F1F1F2D2D2DE3E3E3FFFFFF3C3C3C1F1F1F1F1F1F8F8F8F222222222222
          2222222222229E9E9EFFFFFFE4E4E4909090909090E4E4E4FFFFFF9E9E9E2222
          222222222222222222225C5C5C252525252525252525252525A0A0A0FFFFFFFF
          FFFFFFFFFFFFFFFFA0A0A02525252525252525252525255C5C5CF2F2F2C9C9C9
          FFFFFFD7D7D7282828282828434343878787878787434343282828282828D7D7
          D7FFFFFFC9C9C9F2F2F2FFFFFFFFFFFFFFFFFFFFFFFF2C2C2C2C2C2C2C2C2C2C
          2C2C2C2C2C2C2C2C2C2C2C2C2C2CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFCBCBCB2F2F2F2F2F2F2F2F2FCBCBCBCBCBCB2F2F2F2F2F2F2F2F2FCBCB
          CBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF3F3F3656565323232999999FF
          FFFFFFFFFF999999323232656565F3F3F3FFFFFFFFFFFFFFFFFF}
        ParentFont = False
        TabOrder = 22
        OnClick = BtnAxis0Click
      end
      object BtnAxis5: TBitBtn
        Tag = 5
        Left = 787
        Top = 6
        Width = 150
        Height = 38
        Caption = ' MOTOR AXIS'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = []
        Glyph.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          1800000000000003000012170000121700000000000000000000FFFFFFFFFFFF
          FFFFFFF0F0F0424242020202818181FFFFFFFFFFFF818181020202424242F0F0
          F0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC1C1C1050505050505050505C1
          C1C1C1C1C1050505050505050505C1C1C1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFF090909090909090909090909090909090909090909090909FFFF
          FFFFFFFFFFFFFFFFFFFFF0F0F0C3C3C3FFFFFFD2D2D20C0C0C0C0C0C0C0C0C49
          49494949490C0C0C0C0C0C0C0C0CD2D2D2FFFFFFC3C3C3F0F0F04C4C4C0F0F0F
          0F0F0F0F0F0F0F0F0F787878F0F0F0FFFFFFFFFFFFF0F0F07878780F0F0F0F0F
          0F0F0F0F0F0F0F4C4C4C1212121212121212121212127B7B7BFFFFFFF1F1F198
          9898A7A7A7F1F1F1FFFFFF7B7B7B1212121212121212121212128A8A8A151515
          151515242424F1F1F1F1F1F1242424151515151515242424F1F1F1F1F1F12424
          241515151515158A8A8AFFFFFFC6C6C6191919535353FFFFFF9A9A9A191919D4
          D4D4D4D4D41919199A9A9AFFFFFF535353191919C6C6C6FFFFFFFFFFFFC7C7C7
          1C1C1C555555FFFFFF8E8E8E1C1C1CD5D5D5D5D5D51C1C1C8E8E8EFFFFFF5555
          551C1C1CC7C7C7FFFFFF8F8F8F1F1F1F1F1F1F3C3C3CFFFFFFE3E3E32D2D2D1F
          1F1F1F1F1F2D2D2DE3E3E3FFFFFF3C3C3C1F1F1F1F1F1F8F8F8F222222222222
          2222222222229E9E9EFFFFFFE4E4E4909090909090E4E4E4FFFFFF9E9E9E2222
          222222222222222222225C5C5C252525252525252525252525A0A0A0FFFFFFFF
          FFFFFFFFFFFFFFFFA0A0A02525252525252525252525255C5C5CF2F2F2C9C9C9
          FFFFFFD7D7D7282828282828434343878787878787434343282828282828D7D7
          D7FFFFFFC9C9C9F2F2F2FFFFFFFFFFFFFFFFFFFFFFFF2C2C2C2C2C2C2C2C2C2C
          2C2C2C2C2C2C2C2C2C2C2C2C2C2CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFCBCBCB2F2F2F2F2F2F2F2F2FCBCBCBCBCBCB2F2F2F2F2F2F2F2F2FCBCB
          CBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF3F3F3656565323232999999FF
          FFFFFFFFFF999999323232656565F3F3F3FFFFFFFFFFFFFFFFFF}
        ParentFont = False
        TabOrder = 23
        OnClick = BtnAxis0Click
      end
      object BtnAxis4: TBitBtn
        Tag = 4
        Left = 631
        Top = 6
        Width = 150
        Height = 38
        Caption = ' MOTOR AXIS'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = []
        Glyph.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          1800000000000003000012170000121700000000000000000000FFFFFFFFFFFF
          FFFFFFF0F0F0424242020202818181FFFFFFFFFFFF818181020202424242F0F0
          F0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC1C1C1050505050505050505C1
          C1C1C1C1C1050505050505050505C1C1C1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFF090909090909090909090909090909090909090909090909FFFF
          FFFFFFFFFFFFFFFFFFFFF0F0F0C3C3C3FFFFFFD2D2D20C0C0C0C0C0C0C0C0C49
          49494949490C0C0C0C0C0C0C0C0CD2D2D2FFFFFFC3C3C3F0F0F04C4C4C0F0F0F
          0F0F0F0F0F0F0F0F0F787878F0F0F0FFFFFFFFFFFFF0F0F07878780F0F0F0F0F
          0F0F0F0F0F0F0F4C4C4C1212121212121212121212127B7B7BFFFFFFF1F1F198
          9898A7A7A7F1F1F1FFFFFF7B7B7B1212121212121212121212128A8A8A151515
          151515242424F1F1F1F1F1F1242424151515151515242424F1F1F1F1F1F12424
          241515151515158A8A8AFFFFFFC6C6C6191919535353FFFFFF9A9A9A191919D4
          D4D4D4D4D41919199A9A9AFFFFFF535353191919C6C6C6FFFFFFFFFFFFC7C7C7
          1C1C1C555555FFFFFF8E8E8E1C1C1CD5D5D5D5D5D51C1C1C8E8E8EFFFFFF5555
          551C1C1CC7C7C7FFFFFF8F8F8F1F1F1F1F1F1F3C3C3CFFFFFFE3E3E32D2D2D1F
          1F1F1F1F1F2D2D2DE3E3E3FFFFFF3C3C3C1F1F1F1F1F1F8F8F8F222222222222
          2222222222229E9E9EFFFFFFE4E4E4909090909090E4E4E4FFFFFF9E9E9E2222
          222222222222222222225C5C5C252525252525252525252525A0A0A0FFFFFFFF
          FFFFFFFFFFFFFFFFA0A0A02525252525252525252525255C5C5CF2F2F2C9C9C9
          FFFFFFD7D7D7282828282828434343878787878787434343282828282828D7D7
          D7FFFFFFC9C9C9F2F2F2FFFFFFFFFFFFFFFFFFFFFFFF2C2C2C2C2C2C2C2C2C2C
          2C2C2C2C2C2C2C2C2C2C2C2C2C2CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFCBCBCB2F2F2F2F2F2F2F2F2FCBCBCBCBCBCB2F2F2F2F2F2F2F2F2FCBCB
          CBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF3F3F3656565323232999999FF
          FFFFFFFFFF999999323232656565F3F3F3FFFFFFFFFFFFFFFFFF}
        ParentFont = False
        TabOrder = 24
        OnClick = BtnAxis0Click
      end
    end
  end
  object MtrRefreshTimer: TTimer
    Enabled = False
    Interval = 500
    OnTimer = MtrRefreshTimerTimer
    Left = 65
    Top = 200
  end
end
