object FormTowerLamp: TFormTowerLamp
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
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object CurvyPanel1: TCurvyPanel
    Left = 5
    Top = 5
    Width = 1270
    Height = 770
    Color = clBtnFace
    TabOrder = 0
    object Label1: TLabel
      Left = 24
      Top = 16
      Width = 155
      Height = 26
      Caption = 'TOWER LAMP SET'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object TowerLampGrid: TStringGrid
      Left = 24
      Top = 63
      Width = 1208
      Height = 409
      DefaultColWidth = 150
      DefaultRowHeight = 50
      FixedColor = clSilver
      RowCount = 8
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentFont = False
      ScrollBars = ssNone
      TabOrder = 0
      ColWidths = (
        150
        262
        252
        267
        278)
      RowHeights = (
        50
        50
        50
        50
        50
        50
        50
        50)
    end
    object Panel1: TPanel
      Left = 24
      Top = 488
      Width = 1208
      Height = 145
      Color = clSilver
      ParentBackground = False
      TabOrder = 1
      object BtnBuzzerSW: TSpeedButton
        Tag = 1
        Left = 24
        Top = 42
        Width = 353
        Height = 71
        Caption = 'BUZZER ON / OFF'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #47569#51008' '#44256#46357
        Font.Style = [fsBold]
        Glyph.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          1800000000000003000012170000121700000000000000000000FFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFF252525050505252525FFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD2D2D20E0E0E0E
          0E0E0E0E0ED2D2D2FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFF8B8B8B1616161616161616168B8B8BFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4A4A4A1F1F1F1F
          1F1F1F1F1F4A4A4AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFF272727272727272727272727272727FFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB1B1B130303030
          3030303030B1B1B1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE2E2E2F4F4F4
          FFFFFFFFFFFFFFFFFFFFFFFFF3F3F3CCCCCCF3F3F3FFFFFFFFFFFFFFFFFFFFFF
          FFF4F4F4E2E2E2FFFFFFB5B5B5FCFCFCFFFFFFD9D9D9FFFFFFFFFFFF3A3A3A0B
          0B0B3A3A3AFFFFFFFFFFFFD9D9D9FFFFFFF7F7F7B5B5B5FFFFFF8B8B8BFFFFFF
          F0F0F0A6A6A6FFFFFFE3E3E31C1C1C1C1C1C1C1C1CFFFFFFFFFFFFA6A6A6FFFF
          FFFFFFFF8B8B8BFFFFFF636363F5F5F5FFFFFF666666FFFFFFFFFFFF5353532D
          2D2D535353FFFFFFFFFFFF666666FFFFFFF5F5F5636363FFFFFF555555B5B5B5
          FFFFFF6A6A6AC9C9C9FFFFFFFFFFFFE6E6E6FFFFFFFFFFFFC9C9C96A6A6AFFFF
          FFB5B5B5555555FFFFFF8585855B5B5BFFFFFFE5E5E5464646CBCBCBFFFFFFFF
          FFFFFFFFFFCBCBCB464646E5E5E5FFFFFF5B5B5B858585FFFFFFF2F2F2353535
          A1A1A1FFFFFFE5E5E5717171585858666666585858717171E5E5E5FFFFFFA1A1
          A1353535F2F2F2FFFFFFFFFFFFB0B0B02B2B2BA3A3A3FFFFFFFFFFFFFFFFFFE6
          E6E6FFFFFFFFFFFFFFFFFFA3A3A32B2B2BBDBDBDFFFFFFFFFFFFFFFFFFFFFFFF
          BEBEBE3C3C3C646464B2B2B2F3F3F3FFFFFFF3F3F3B2B2B26464643C3C3CBEBE
          BEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF3F3F38C8C8C4B4B4B32323232
          32323232324B4B4B8C8C8CF3F3F3FFFFFFFFFFFFFFFFFFFFFFFF}
        ParentFont = False
        Visible = False
        OnClick = BtnBuzzerSWClick
      end
      object BtnBuzzerTimer: TSpeedButton
        Tag = 1
        Left = 728
        Top = 42
        Width = 433
        Height = 71
        Caption = 'SAVE BUZZER TIME'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #47569#51008' '#44256#46357
        Font.Style = [fsBold]
        Glyph.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          1800000000000003000012170000121700000000000000000000FFFFFFFFFFFF
          FFFFFFFFFFFFF0F0F0727272222222020202020202020202222222727272F0F0
          F0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB2B2B216161606060606060606
          0606454545060606060606060606161616B2B2B2FFFFFFFFFFFFFFFFFFFFFFFF
          B2B2B20909090909090909090909090909090909090909090909090909090909
          09090909B2B2B2FFFFFFFFFFFFF0F0F01D1D1D0D0D0D0D0D0D0D0D0D0D0D0D0D
          0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D1D1D1DF0F0F0FFFFFF797979
          1010101010101010101010101010101010101010101010101F1F1FA6A6A61010
          10101010101010797979FFFFFF31313113131313131313131313131313131313
          1313131313222222A7A7A7222222131313131313131313313131FFFFFF171717
          171717171717171717171717171717171717252525A8A8A82626261717171717
          17171717171717171717E3E3E31A1A1A5454541A1A1A1A1A1A1A1A1A1A1A1A1A
          1A1AD4D4D42929291A1A1A1A1A1A1A1A1A1A1A1A5454541A1A1AFFFFFF1E1E1E
          1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1EFFFFFF1E1E1E1E1E1E1E1E1E1E1E
          1E1E1E1E1E1E1E1E1E1EFFFFFF3C3C3C21212121212121212121212121212121
          2121FFFFFF2121212121212121212121212121212121213C3C3CFFFFFF858585
          242424242424242424242424242424242424FFFFFF2424242424242424242424
          24242424242424858585FFFFFFF2F2F235353528282828282828282828282828
          2828AFAFAF282828282828282828282828282828353535F2F2F2FFFFFFFFFFFF
          BDBDBD2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B
          2B2B2B2BBDBDBDFFFFFFFFFFFFFFFFFFFFFFFFBEBEBE3C3C3C2F2F2F2F2F2F2F
          2F2F6464642F2F2F2F2F2F2F2F2F3C3C3CBEBEBEFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFF3F3F38C8C8C4B4B4B3232323232323232324B4B4B8C8C8CF3F3
          F3FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
        ParentFont = False
        OnClick = BtnBuzzerTimerClick
      end
      object EditBuzzerTime: TEdit
        Left = 747
        Top = 60
        Width = 121
        Height = 34
        Alignment = taCenter
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -21
        Font.Name = 'Calibri'
        Font.Style = []
        ImeName = 'Microsoft IME 2010'
        NumbersOnly = True
        ParentFont = False
        TabOrder = 0
        Text = '0'
      end
      object PanelBuzzerLed: TPanel
        Left = 40
        Top = 62
        Width = 81
        Height = 33
        Caption = 'OFF'
        TabOrder = 1
        Visible = False
      end
    end
    object Panel2: TPanel
      Left = 25
      Top = 65
      Width = 151
      Height = 51
      BevelKind = bkSoft
      BevelOuter = bvNone
      Caption = 'STATUS'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentBackground = False
      ParentFont = False
      TabOrder = 2
    end
    object Panel3: TPanel
      Left = 176
      Top = 65
      Width = 264
      Height = 51
      BevelKind = bkSoft
      BevelOuter = bvNone
      Caption = 'RED LAMP'
      Color = clRed
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentBackground = False
      ParentFont = False
      TabOrder = 3
    end
    object Panel4: TPanel
      Left = 441
      Top = 65
      Width = 253
      Height = 51
      BevelKind = bkSoft
      BevelOuter = bvNone
      Caption = 'YELLLOW LAMP'
      Color = clYellow
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentBackground = False
      ParentFont = False
      TabOrder = 4
    end
    object Panel5: TPanel
      Left = 694
      Top = 65
      Width = 268
      Height = 52
      BevelKind = bkSoft
      BevelOuter = bvNone
      Caption = 'GREEN LAMP'
      Color = clGreen
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentBackground = False
      ParentFont = False
      TabOrder = 5
    end
    object Panel6: TPanel
      Left = 962
      Top = 65
      Width = 268
      Height = 51
      BevelKind = bkSoft
      BevelOuter = bvNone
      Caption = 'BUZZER ON / OFF'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentBackground = False
      ParentFont = False
      TabOrder = 6
    end
    object ComboBoxR1: TComboBox
      Tag = 950
      Left = 179
      Top = 117
      Width = 259
      Height = 47
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -32
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ImeName = 'Microsoft IME 2010'
      ItemIndex = 0
      ParentFont = False
      TabOrder = 7
      Text = 'OFF'
      OnChange = ComboBoxR1Change
      Items.Strings = (
        'OFF'
        'ON'
        'BLINK')
    end
    object ComboBoxBuzzer1: TComboBox
      Tag = 953
      Left = 964
      Top = 117
      Width = 264
      Height = 47
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -32
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ImeName = 'Microsoft IME 2010'
      ItemIndex = 0
      ParentFont = False
      TabOrder = 8
      Text = 'OFF'
      OnChange = ComboBoxR1Change
      Items.Strings = (
        'OFF'
        'BUZZER 1'
        'BUZZER 2'
        'BUZZER 3'
        'BUZZER 3')
    end
    object ComboBoxR2: TComboBox
      Tag = 954
      Left = 179
      Top = 169
      Width = 259
      Height = 47
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -32
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ImeName = 'Microsoft IME 2010'
      ItemIndex = 0
      ParentFont = False
      TabOrder = 9
      Text = 'OFF'
      OnChange = ComboBoxR1Change
      Items.Strings = (
        'OFF'
        'ON'
        'BLINK')
    end
    object ComboBoxR3: TComboBox
      Tag = 958
      Left = 179
      Top = 220
      Width = 259
      Height = 47
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -32
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ImeName = 'Microsoft IME 2010'
      ItemIndex = 0
      ParentFont = False
      TabOrder = 10
      Text = 'OFF'
      OnChange = ComboBoxR1Change
      Items.Strings = (
        'OFF'
        'ON'
        'BLINK')
    end
    object ComboBoxR4: TComboBox
      Tag = 962
      Left = 179
      Top = 271
      Width = 259
      Height = 47
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -32
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ImeName = 'Microsoft IME 2010'
      ItemIndex = 0
      ParentFont = False
      TabOrder = 11
      Text = 'OFF'
      OnChange = ComboBoxR1Change
      Items.Strings = (
        'OFF'
        'ON'
        'BLINK')
    end
    object ComboBoxR5: TComboBox
      Tag = 966
      Left = 179
      Top = 322
      Width = 259
      Height = 47
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -32
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ImeName = 'Microsoft IME 2010'
      ItemIndex = 0
      ParentFont = False
      TabOrder = 12
      Text = 'OFF'
      OnChange = ComboBoxR1Change
      Items.Strings = (
        'OFF'
        'ON'
        'BLINK')
    end
    object ComboBoxR6: TComboBox
      Tag = 970
      Left = 179
      Top = 372
      Width = 259
      Height = 47
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -32
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ImeName = 'Microsoft IME 2010'
      ItemIndex = 0
      ParentFont = False
      TabOrder = 13
      Text = 'OFF'
      OnChange = ComboBoxR1Change
      Items.Strings = (
        'OFF'
        'ON'
        'BLINK')
    end
    object ComboBoxR7: TComboBox
      Tag = 974
      Left = 179
      Top = 424
      Width = 259
      Height = 47
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -32
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ImeName = 'Microsoft IME 2010'
      ItemIndex = 0
      ParentFont = False
      TabOrder = 14
      Text = 'OFF'
      OnChange = ComboBoxR1Change
      Items.Strings = (
        'OFF'
        'ON'
        'BLINK')
    end
    object ComboBoxY7: TComboBox
      Tag = 975
      Left = 442
      Top = 424
      Width = 250
      Height = 47
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -32
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ImeName = 'Microsoft IME 2010'
      ItemIndex = 0
      ParentFont = False
      TabOrder = 15
      Text = 'OFF'
      OnChange = ComboBoxR1Change
      Items.Strings = (
        'OFF'
        'ON'
        'BLINK')
    end
    object ComboBoxY6: TComboBox
      Tag = 971
      Left = 442
      Top = 372
      Width = 250
      Height = 47
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -32
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ImeName = 'Microsoft IME 2010'
      ItemIndex = 0
      ParentFont = False
      TabOrder = 16
      Text = 'OFF'
      OnChange = ComboBoxR1Change
      Items.Strings = (
        'OFF'
        'ON'
        'BLINK')
    end
    object ComboBoxY5: TComboBox
      Tag = 967
      Left = 442
      Top = 322
      Width = 250
      Height = 47
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -32
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ImeName = 'Microsoft IME 2010'
      ItemIndex = 0
      ParentFont = False
      TabOrder = 17
      Text = 'OFF'
      OnChange = ComboBoxR1Change
      Items.Strings = (
        'OFF'
        'ON'
        'BLINK')
    end
    object ComboBoxY4: TComboBox
      Tag = 963
      Left = 442
      Top = 271
      Width = 250
      Height = 47
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -32
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ImeName = 'Microsoft IME 2010'
      ItemIndex = 0
      ParentFont = False
      TabOrder = 18
      Text = 'OFF'
      OnChange = ComboBoxR1Change
      Items.Strings = (
        'OFF'
        'ON'
        'BLINK')
    end
    object ComboBoxY3: TComboBox
      Tag = 959
      Left = 442
      Top = 220
      Width = 250
      Height = 47
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -32
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ImeName = 'Microsoft IME 2010'
      ItemIndex = 0
      ParentFont = False
      TabOrder = 19
      Text = 'OFF'
      OnChange = ComboBoxR1Change
      Items.Strings = (
        'OFF'
        'ON'
        'BLINK')
    end
    object ComboBoxY2: TComboBox
      Tag = 955
      Left = 442
      Top = 169
      Width = 250
      Height = 47
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -32
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ImeName = 'Microsoft IME 2010'
      ItemIndex = 0
      ParentFont = False
      TabOrder = 20
      Text = 'OFF'
      OnChange = ComboBoxR1Change
      Items.Strings = (
        'OFF'
        'ON'
        'BLINK')
    end
    object ComboBoxY1: TComboBox
      Tag = 951
      Left = 442
      Top = 117
      Width = 250
      Height = 47
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -32
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ImeName = 'Microsoft IME 2010'
      ItemIndex = 0
      ParentFont = False
      TabOrder = 21
      Text = 'OFF'
      OnChange = ComboBoxR1Change
      Items.Strings = (
        'OFF'
        'ON'
        'BLINK')
    end
    object ComboBoxG7: TComboBox
      Tag = 976
      Left = 697
      Top = 424
      Width = 264
      Height = 47
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -32
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ImeName = 'Microsoft IME 2010'
      ItemIndex = 0
      ParentFont = False
      TabOrder = 22
      Text = 'OFF'
      OnChange = ComboBoxR1Change
      Items.Strings = (
        'OFF'
        'ON'
        'BLINK')
    end
    object ComboBoxG6: TComboBox
      Tag = 972
      Left = 697
      Top = 372
      Width = 264
      Height = 47
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -32
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ImeName = 'Microsoft IME 2010'
      ItemIndex = 0
      ParentFont = False
      TabOrder = 23
      Text = 'OFF'
      OnChange = ComboBoxR1Change
      Items.Strings = (
        'OFF'
        'ON'
        'BLINK')
    end
    object ComboBoxG5: TComboBox
      Tag = 968
      Left = 697
      Top = 322
      Width = 264
      Height = 47
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -32
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ImeName = 'Microsoft IME 2010'
      ItemIndex = 0
      ParentFont = False
      TabOrder = 24
      Text = 'OFF'
      OnChange = ComboBoxR1Change
      Items.Strings = (
        'OFF'
        'ON'
        'BLINK')
    end
    object ComboBoxG4: TComboBox
      Tag = 964
      Left = 697
      Top = 271
      Width = 264
      Height = 47
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -32
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ImeName = 'Microsoft IME 2010'
      ItemIndex = 0
      ParentFont = False
      TabOrder = 25
      Text = 'OFF'
      OnChange = ComboBoxR1Change
      Items.Strings = (
        'OFF'
        'ON'
        'BLINK')
    end
    object ComboBoxG3: TComboBox
      Tag = 960
      Left = 697
      Top = 220
      Width = 264
      Height = 47
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -32
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ImeName = 'Microsoft IME 2010'
      ItemIndex = 0
      ParentFont = False
      TabOrder = 26
      Text = 'OFF'
      OnChange = ComboBoxR1Change
      Items.Strings = (
        'OFF'
        'ON'
        'BLINK')
    end
    object ComboBoxG2: TComboBox
      Tag = 956
      Left = 697
      Top = 169
      Width = 264
      Height = 47
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -32
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ImeName = 'Microsoft IME 2010'
      ItemIndex = 0
      ParentFont = False
      TabOrder = 27
      Text = 'OFF'
      OnChange = ComboBoxR1Change
      Items.Strings = (
        'OFF'
        'ON'
        'BLINK')
    end
    object ComboBoxG1: TComboBox
      Tag = 952
      Left = 697
      Top = 117
      Width = 264
      Height = 47
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -32
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ImeName = 'Microsoft IME 2010'
      ItemIndex = 0
      ParentFont = False
      TabOrder = 28
      Text = 'OFF'
      OnChange = ComboBoxR1Change
      Items.Strings = (
        'OFF'
        'ON'
        'BLINK')
    end
    object ComboBoxBuzzer2: TComboBox
      Tag = 957
      Left = 964
      Top = 169
      Width = 264
      Height = 47
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -32
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ImeName = 'Microsoft IME 2010'
      ItemIndex = 0
      ParentFont = False
      TabOrder = 29
      Text = 'OFF'
      OnChange = ComboBoxR1Change
      Items.Strings = (
        'OFF'
        'BUZZER 1'
        'BUZZER 2'
        'BUZZER 3'
        'BUZZER 3')
    end
    object ComboBoxBuzzer3: TComboBox
      Tag = 961
      Left = 964
      Top = 220
      Width = 264
      Height = 47
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -32
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ImeName = 'Microsoft IME 2010'
      ItemIndex = 0
      ParentFont = False
      TabOrder = 30
      Text = 'OFF'
      OnChange = ComboBoxR1Change
      Items.Strings = (
        'OFF'
        'BUZZER 1'
        'BUZZER 2'
        'BUZZER 3'
        'BUZZER 3')
    end
    object ComboBoxBuzzer4: TComboBox
      Tag = 965
      Left = 964
      Top = 271
      Width = 264
      Height = 47
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -32
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ImeName = 'Microsoft IME 2010'
      ItemIndex = 0
      ParentFont = False
      TabOrder = 31
      Text = 'OFF'
      OnChange = ComboBoxR1Change
      Items.Strings = (
        'OFF'
        'BUZZER 1'
        'BUZZER 2'
        'BUZZER 3'
        'BUZZER 3')
    end
    object ComboBoxBuzzer5: TComboBox
      Tag = 969
      Left = 964
      Top = 322
      Width = 264
      Height = 47
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -32
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ImeName = 'Microsoft IME 2010'
      ItemIndex = 0
      ParentFont = False
      TabOrder = 32
      Text = 'OFF'
      OnChange = ComboBoxR1Change
      Items.Strings = (
        'OFF'
        'BUZZER 1'
        'BUZZER 2'
        'BUZZER 3'
        'BUZZER 3')
    end
    object ComboBoxBuzzer6: TComboBox
      Tag = 973
      Left = 964
      Top = 372
      Width = 264
      Height = 47
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -32
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ImeName = 'Microsoft IME 2010'
      ItemIndex = 0
      ParentFont = False
      TabOrder = 33
      Text = 'OFF'
      OnChange = ComboBoxR1Change
      Items.Strings = (
        'OFF'
        'BUZZER 1'
        'BUZZER 2'
        'BUZZER 3'
        'BUZZER 3')
    end
    object ComboBoxBuzzer7: TComboBox
      Tag = 977
      Left = 967
      Top = 425
      Width = 264
      Height = 47
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -32
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ImeName = 'Microsoft IME 2010'
      ItemIndex = 0
      ParentFont = False
      TabOrder = 34
      Text = 'OFF'
      OnChange = ComboBoxR1Change
      Items.Strings = (
        'OFF'
        'BUZZER 1'
        'BUZZER 2'
        'BUZZER 3'
        'BUZZER 3')
    end
  end
end
