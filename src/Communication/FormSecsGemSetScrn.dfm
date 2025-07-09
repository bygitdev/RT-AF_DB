object FormSecsGemSet: TFormSecsGemSet
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
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object CurvyPanel1: TCurvyPanel
    Left = 8
    Top = 8
    Width = 1266
    Height = 766
    Color = clBtnFace
    TabOrder = 0
    object BtnSaveLog: TSpeedButton
      Tag = 1
      Left = 17
      Top = 711
      Width = 146
      Height = 42
      Caption = 'SAVE LOG'
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
      OnClick = BtnSaveLogClick
    end
    object SecsMemo: TMemo
      Left = 17
      Top = 171
      Width = 1232
      Height = 535
      Color = clWhite
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = #47569#51008' '#44256#46357
      Font.Style = []
      ImeName = 'Microsoft IME 2003'
      ParentFont = False
      ReadOnly = True
      ScrollBars = ssVertical
      TabOrder = 0
      OnChange = SecsMemoChange
    end
    object BtnClose: TBitBtn
      Left = 1104
      Top = 711
      Width = 146
      Height = 42
      Caption = 'CLOSE'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Calibri'
      Font.Style = []
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
      ParentFont = False
      TabOrder = 1
      OnClick = BtnCloseClick
    end
    object GroupBox1: TGroupBox
      Left = 17
      Top = 17
      Width = 504
      Height = 133
      Caption = 'SECS/GEM STATUS'
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Calibri'
      Font.Style = []
      ParentBackground = False
      ParentColor = False
      ParentFont = False
      TabOrder = 2
      object Label1: TLabel
        Left = 24
        Top = 29
        Width = 93
        Height = 18
        Caption = 'PROCESS STATE'
      end
      object Label2: TLabel
        Left = 24
        Top = 61
        Width = 150
        Height = 18
        Caption = 'COMMUNICATION STATE'
      end
      object Label3: TLabel
        Left = 24
        Top = 93
        Width = 97
        Height = 18
        Caption = 'CONTROL STATE'
      end
      object PanelGemState: TPanel
        Left = 216
        Top = 18
        Width = 273
        Height = 38
        BevelInner = bvRaised
        BevelKind = bkSoft
        BevelOuter = bvLowered
        Caption = 'SETUP'
        Color = clWhite
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Calibri'
        Font.Style = []
        ParentBackground = False
        ParentFont = False
        TabOrder = 0
      end
      object EditCommState: TPanel
        Left = 216
        Top = 54
        Width = 273
        Height = 38
        BevelInner = bvRaised
        BevelKind = bkSoft
        BevelOuter = bvLowered
        Caption = 'SETUP'
        Color = clWhite
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Calibri'
        Font.Style = []
        ParentBackground = False
        ParentFont = False
        TabOrder = 1
      end
      object EditCtrlState: TPanel
        Left = 216
        Top = 91
        Width = 273
        Height = 38
        BevelInner = bvRaised
        BevelKind = bkSoft
        BevelOuter = bvLowered
        Caption = 'SETUP'
        Color = clWhite
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Calibri'
        Font.Style = []
        ParentBackground = False
        ParentFont = False
        TabOrder = 2
      end
    end
    object GroupboxSecsControl: TGroupBox
      Left = 527
      Top = 17
      Width = 714
      Height = 133
      Caption = 'SECS/GEM CONTROL'
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Calibri'
      Font.Style = []
      ParentBackground = False
      ParentColor = False
      ParentFont = False
      TabOrder = 3
      object BtnCommEnable: TSpeedButton
        Tag = 1
        Left = 349
        Top = 23
        Width = 171
        Height = 45
        Caption = 'COMMUNICATION'#13#10'ENABLE'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
        OnClick = BtnCommEnableClick
      end
      object BtnOffline: TSpeedButton
        Tag = 1
        Left = 349
        Top = 78
        Width = 171
        Height = 45
        Caption = #9632' OFFLINE'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
        OnClick = BtnOfflineClick
      end
      object BtnOnlineRemote: TSpeedButton
        Tag = 1
        Left = 531
        Top = 23
        Width = 171
        Height = 45
        Caption = #8594' ONLINE REMOTE'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
        OnClick = BtnOnlineRemoteClick
      end
      object BtnOnlineLocal: TSpeedButton
        Tag = 1
        Left = 531
        Top = 78
        Width = 171
        Height = 45
        Caption = #8592' ONLINE LOCAL'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
        OnClick = BtnOnlineLocalClick
      end
      object BtnSecsCommStop: TSpeedButton
        Tag = 1
        Left = 196
        Top = 78
        Width = 139
        Height = 45
        Caption = 'STOP'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
        OnClick = BtnSecsCommStopClick
      end
      object BtnSecsCommStart: TSpeedButton
        Tag = 1
        Left = 196
        Top = 23
        Width = 139
        Height = 45
        Caption = 'START'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
        OnClick = BtnSecsCommStartClick
      end
      object BtnSecsAutoStart: TSpeedButton
        Tag = 1
        Left = 12
        Top = 47
        Width = 157
        Height = 45
        Caption = 'AUTO START ON'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
        OnClick = BtnSecsCommStartClick
      end
    end
    object eXGem: TeXGem
      Left = 184
      Top = 224
      Width = 32
      Height = 32
      ControlData = {00000100560A00002B05000000000000}
    end
  end
  object TMOnlineRemote: TTimer
    Enabled = False
    OnTimer = TMOnlineRemoteTimer
    Left = 600
    Top = 144
  end
end
