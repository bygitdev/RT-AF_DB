object FrmLotComm: TFrmLotComm
  Left = 0
  Top = 0
  BorderStyle = bsNone
  ClientHeight = 601
  ClientWidth = 1147
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
    Top = 10
    Width = 1129
    Height = 582
    Color = clBtnFace
    TabOrder = 0
    object Label1: TLabel
      Left = 18
      Top = 20
      Width = 478
      Height = 33
      Caption = '2D BARCODE && RFID COMMUNICATION SET'
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
      Top = 527
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
    end
    object LotMemo: TMemo
      Left = 575
      Top = 63
      Width = 538
      Height = 458
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
    end
    object BtnClose: TBitBtn
      Left = 967
      Top = 527
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
    object Panel1: TPanel
      Left = 18
      Top = 63
      Width = 538
      Height = 95
      TabOrder = 2
      object Label2: TLabel
        Left = 216
        Top = 8
        Width = 104
        Height = 23
        Caption = '2D BARCODE'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object BtnBcdOn: TButton
        Left = 10
        Top = 38
        Width = 223
        Height = 41
        Caption = 'ON'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        OnClick = BtnBcdOnClick
      end
      object BtnBcdOff: TButton
        Left = 306
        Top = 38
        Width = 223
        Height = 41
        Caption = 'OFF'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = BtnBcdOffClick
      end
    end
    object Panel2: TPanel
      Left = 18
      Top = 167
      Width = 538
      Height = 354
      TabOrder = 3
      object Label3: TLabel
        Left = 248
        Top = 8
        Width = 37
        Height = 23
        Caption = 'RFID'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label4: TLabel
        Left = 152
        Top = 128
        Width = 81
        Height = 19
        Caption = 'Magazine ID'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
      end
      object Label5: TLabel
        Left = 152
        Top = 161
        Width = 38
        Height = 19
        Caption = 'Lot ID'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
      end
      object Label6: TLabel
        Left = 152
        Top = 194
        Width = 46
        Height = 19
        Caption = 'Step ID'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
      end
      object Label7: TLabel
        Left = 152
        Top = 227
        Width = 72
        Height = 19
        Caption = 'Package ID'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
      end
      object Label8: TLabel
        Left = 152
        Top = 260
        Width = 82
        Height = 19
        Caption = 'Frame Count'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
      end
      object Label9: TLabel
        Left = 152
        Top = 293
        Width = 51
        Height = 19
        Caption = 'Part NO'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
      end
      object BtnRfidOn: TButton
        Left = 10
        Top = 46
        Width = 241
        Height = 41
        Caption = 'READ'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        OnClick = BtnRfidOnClick
      end
      object BtnRfidOff: TButton
        Left = 290
        Top = 46
        Width = 241
        Height = 41
        Caption = 'WRITE'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = BtnRfidOffClick
      end
      object edtMagazineID: TEdit
        Left = 262
        Top = 125
        Width = 200
        Height = 26
        Color = cl3DLight
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'Calibri'
        Font.Style = []
        ImeName = 'Microsoft IME 2010'
        ParentFont = False
        ReadOnly = True
        TabOrder = 2
      end
      object edtLotID: TEdit
        Left = 262
        Top = 158
        Width = 200
        Height = 26
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'Calibri'
        Font.Style = []
        ImeName = 'Microsoft IME 2010'
        ParentFont = False
        TabOrder = 3
      end
      object edtStepID: TEdit
        Left = 262
        Top = 191
        Width = 200
        Height = 26
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'Calibri'
        Font.Style = []
        ImeName = 'Microsoft IME 2010'
        ParentFont = False
        TabOrder = 4
      end
      object edtPackageID: TEdit
        Left = 262
        Top = 224
        Width = 200
        Height = 26
        Color = cl3DLight
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'Calibri'
        Font.Style = []
        ImeName = 'Microsoft IME 2010'
        ParentFont = False
        ReadOnly = True
        TabOrder = 5
      end
      object edtFrameCount: TEdit
        Left = 262
        Top = 257
        Width = 200
        Height = 26
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'Calibri'
        Font.Style = []
        ImeName = 'Microsoft IME 2010'
        ParentFont = False
        TabOrder = 6
      end
      object edtPartNo: TEdit
        Left = 262
        Top = 290
        Width = 200
        Height = 26
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'Calibri'
        Font.Style = []
        ImeName = 'Microsoft IME 2010'
        ParentFont = False
        TabOrder = 7
      end
    end
  end
end
