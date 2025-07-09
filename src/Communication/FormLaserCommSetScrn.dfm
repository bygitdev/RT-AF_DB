object FormLaserCommSet: TFormLaserCommSet
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
    Width = 1262
    Height = 762
    BorderColor = clBtnFace
    Color = clBtnFace
    TabOrder = 0
    object Label1: TLabel
      Left = 17
      Top = 16
      Width = 319
      Height = 33
      Caption = 'LASER COMMUNICATION SET'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -27
      Font.Name = 'Calibri'
      Font.Style = []
      ParentFont = False
      Transparent = True
    end
    object BtnSaveLog: TSpeedButton
      Tag = 1
      Left = 18
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
    object LaserMemo: TMemo
      Left = 17
      Top = 117
      Width = 1232
      Height = 588
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
      OnChange = LaserMemoChange
    end
    object BtnLaserComm1: TButton
      Tag = 1
      Left = 18
      Top = 70
      Width = 241
      Height = 41
      Caption = 'LASER 1 OFF'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Calibri'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnClick = BtnLaserComm1Click
    end
    object BtnLaserComm3: TButton
      Tag = 3
      Left = 512
      Top = 70
      Width = 241
      Height = 41
      Caption = 'LASER 3  OFF'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Calibri'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnClick = BtnLaserComm1Click
    end
    object BtnLaserComm4: TButton
      Tag = 4
      Left = 759
      Top = 70
      Width = 241
      Height = 41
      Caption = 'LASER 4 OFF'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Calibri'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      OnClick = BtnLaserComm1Click
    end
    object BtnLaserComm2: TButton
      Tag = 2
      Left = 265
      Top = 70
      Width = 241
      Height = 41
      Caption = 'LASER 2 OFF'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Calibri'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
      OnClick = BtnLaserComm1Click
    end
    object ChkLaser2Heartbeat: TCheckBox
      Left = 285
      Top = 83
      Width = 14
      Height = 20
      TabOrder = 5
    end
    object ChkLaser4Heartbeat: TCheckBox
      Left = 779
      Top = 83
      Width = 14
      Height = 20
      TabOrder = 6
    end
    object ChkLaser3Heartbeat: TCheckBox
      Left = 532
      Top = 83
      Width = 14
      Height = 20
      TabOrder = 7
    end
    object ChkLaser1Heartbeat: TCheckBox
      Left = 38
      Top = 83
      Width = 14
      Height = 20
      TabOrder = 8
    end
    object BtnHeartBeatControl: TButton
      Tag = 4
      Left = 367
      Top = 17
      Width = 241
      Height = 41
      Caption = 'HEARTBEAT CONTROL'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Calibri'
      Font.Style = []
      ParentFont = False
      TabOrder = 9
      OnClick = BtnHeartBeatControlClick
    end
    object CheckHeartBeatControl: TCheckBox
      Left = 387
      Top = 29
      Width = 14
      Height = 20
      TabOrder = 10
    end
    object BtnClose: TBitBtn
      Left = 1103
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
      TabOrder = 11
      OnClick = BtnCloseClick
    end
    object BtnRetryConnectActive: TButton
      Tag = 4
      Left = 1152
      Top = 70
      Width = 97
      Height = 41
      Caption = 'RETRY CONNECT'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Calibri'
      Font.Style = []
      ParentFont = False
      TabOrder = 12
      OnClick = BtnRetryConnectActiveClick
    end
  end
  object TcpClientLaser1: TClientSocket
    Active = False
    ClientType = ctNonBlocking
    Host = '192.168.0.5'
    Port = 4885
    OnConnect = TcpClientLaser1Connect
    OnDisconnect = TcpClientLaser1Disconnect
    OnRead = TcpClientLaser1Read
    OnError = TcpClientLaser1Error
    Left = 56
    Top = 144
  end
  object TcpClientLaser2: TClientSocket
    Active = False
    ClientType = ctNonBlocking
    Host = '192.168.0.5'
    Port = 4886
    OnConnect = TcpClientLaser2Connect
    OnDisconnect = TcpClientLaser2Disconnect
    OnRead = TcpClientLaser2Read
    OnError = TcpClientLaser2Error
    Left = 104
    Top = 144
  end
  object TcpClientLaser3: TClientSocket
    Active = False
    ClientType = ctNonBlocking
    Host = '192.168.0.5'
    Port = 4887
    OnConnect = TcpClientLaser3Connect
    OnDisconnect = TcpClientLaser3Disconnect
    OnRead = TcpClientLaser3Read
    OnError = TcpClientLaser3Error
    Left = 152
    Top = 144
  end
  object TcpClientLaser4: TClientSocket
    Active = False
    ClientType = ctNonBlocking
    Host = '192.168.0.5'
    Port = 4888
    OnConnect = TcpClientLaser4Connect
    OnDisconnect = TcpClientLaser4Disconnect
    OnRead = TcpClientLaser4Read
    OnError = TcpClientLaser4Error
    Left = 200
    Top = 144
  end
  object HelloTimer: TTimer
    Enabled = False
    Interval = 5000
    OnTimer = HelloTimerTimer
    Left = 776
    Top = 16
  end
  object LaserRefreshTimer: TTimer
    Enabled = False
    Interval = 500
    OnTimer = LaserRefreshTimerTimer
    Left = 880
    Top = 16
  end
  object LaserCommCheck: TTimer
    Enabled = False
    Interval = 5000
    OnTimer = LaserCommCheckTimer
    Left = 976
    Top = 16
  end
  object FTPLaserServer: TIdFTPServer
    Active = True
    Bindings = <>
    DefaultPort = 21
    ReuseSocket = rsTrue
    TerminateWaitTime = 1000
    CommandHandlers = <>
    ExceptionReply.Code = '500'
    ExceptionReply.Text.Strings = (
      'Unknown Internal Error')
    Greeting.Code = '220'
    Greeting.Text.Strings = (
      'Indy FTP Server ready.')
    MaxConnectionReply.Code = '300'
    MaxConnectionReply.Text.Strings = (
      'Too many connections. Try again later.')
    ReplyTexts = <>
    ReplyUnknownCommand.Code = '500'
    ReplyUnknownCommand.Text.Strings = (
      'Syntax error, command unrecognized.')
    AnonymousAccounts.Strings = (
      'anonymous'
      'ftp'
      'guest')
    AnonymousPassStrictCheck = False
    SystemType = 'WIN32'
    SITECommands = <>
    MLSDFacts = []
    ReplyUnknownSITCommand.Code = '500'
    ReplyUnknownSITCommand.Text.Strings = (
      'Invalid SITE command.')
    Left = 1072
    Top = 251
  end
  object FTPLaserClient: TIdFTP
    IPVersion = Id_IPv4
    Host = '192.168.0.3'
    NATKeepAlive.UseKeepAlive = False
    NATKeepAlive.IdleTimeMS = 0
    NATKeepAlive.IntervalMS = 0
    ProxySettings.ProxyType = fpcmNone
    ProxySettings.Port = 0
    Left = 1072
    Top = 195
  end
  object LaserConnectWait: TTimer
    Enabled = False
    Interval = 2000
    OnTimer = LaserConnectWaitTimer
    Left = 1064
    Top = 16
  end
end
