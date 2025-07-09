object FrmVisionOffsetTeaching: TFrmVisionOffsetTeaching
  Left = 0
  Top = 0
  BorderStyle = bsToolWindow
  ClientHeight = 601
  ClientWidth = 757
  Color = clGray
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object LabelActiveCaption: TLabel
    Left = 6
    Top = 2
    Width = 250
    Height = 23
    Caption = 'STAGE CENTER TEACHING :   1/3'
    Font.Charset = ANSI_CHARSET
    Font.Color = clBlack
    Font.Height = -19
    Font.Name = 'Calibri'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object PanelEmg: TPanel
    Left = 659
    Top = 5
    Width = 93
    Height = 19
    Caption = 'EMG STATUS OFF'
    Color = clGray
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Calibri'
    Font.Style = []
    ParentBackground = False
    ParentFont = False
    TabOrder = 0
  end
  object PageCtrlTeaching: TPageControl
    Left = 0
    Top = 24
    Width = 761
    Height = 577
    ActivePage = TabSheet2
    TabOrder = 1
    OnChange = PageCtrlTeachingChange
    object TabSheet1: TTabSheet
      Caption = 'TabSheet1'
      TabVisible = False
      object CurvyPanel1: TCurvyPanel
        Left = 15
        Top = 1
        Width = 722
        Height = 520
        TabOrder = 0
        object Label2: TLabel
          Left = 82
          Top = 31
          Width = 578
          Height = 39
          Caption = 'TOP TO BOTTOM VISION OFFSET TEACHING'
          Font.Charset = ANSI_CHARSET
          Font.Color = clGreen
          Font.Height = -32
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label1: TLabel
          Left = 18
          Top = 215
          Width = 632
          Height = 99
          Caption = 
            '"TOP TO BOTTOM VISION OFFSET TEACHING" calculates the offset bet' +
            'ween Top and Bottom Vision for accurate "Put Down" of the flippe' +
            'd product.'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clGray
          Font.Height = -27
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          WordWrap = True
        end
        object BtnTeachStart1: TBitBtn
          Left = 175
          Top = 392
          Width = 359
          Height = 52
          Caption = 'TOP TO BOTTOM VISION OFFSET TEACHING START'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Calibri'
          Font.Style = []
          Glyph.Data = {
            26040000424D2604000000000000360000002800000012000000120000000100
            180000000000F003000012170000121700000000000000000000FFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000FFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFF2F2F2AEAEAE888888888888AFAFAFF3F3F3FFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFF0000FFFFFFFFFFFFFFFFFFFFFFFFFAFAFA7E7E7E0C0C0C00
            00000000000000000000000C0C0C818181FBFBFBFFFFFFFFFFFFFFFFFFFFFFFF
            0000FFFFFFFFFFFFFFFFFFF7F7F7424242000000595959C3C3C3F6F6F6F5F5F5
            C2C2C2575757000000454545F8F8F8FFFFFFFFFFFFFFFFFF0000FFFFFFFFFFFF
            FFFFFF666666020202A2A2A2FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9F9F
            9F0101016B6B6BFFFFFFFFFFFFFFFFFF0000FFFFFFFFFFFFD6D6D60101017474
            74FFFFFFFFFFFFFFFFFF6F6F6F6F6F6FFFFFFFFFFFFFFFFFFF717171020202D9
            D9D9FFFFFFFFFFFF0000FFFFFFFFFFFF7C7C7C040404EBEBEBFFFFFFFFFFFFFF
            FFFF3F3F3F3F3F3FFFFFFFFFFFFFFFFFFFE9E9E90303037F7F7FFFFFFFFFFFFF
            0000FFFFFFFFFFFF4C4C4C303030FFFFFFFFFFFF7F7F7F7F7F7F1F1F1F1F1F1F
            7F7F7F7F7F7FFFFFFFFFFFFF2D2D2D4E4E4EFFFFFFFFFFFF0000FFFFFFFFFFFF
            4343433C3C3CFFFFFFFFFFFF000000000000000000000000000000000000FFFF
            FFFFFFFF3A3A3A444444FFFFFFFFFFFF0000FFFFFFFFFFFF5F5F5F181818FFFF
            FFFFFFFFFFFFFFFFFFFF3F3F3F3F3F3FFFFFFFFFFFFFFFFFFFFEFEFE16161661
            6161FFFFFFFFFFFF0000FFFFFFFFFFFFA3A3A3000000BCBCBCFFFFFFFFFFFFFF
            FFFF3F3F3F3F3F3FFFFFFFFFFFFFFFFFFFB9B9B9000000A6A6A6FFFFFFFFFFFF
            0000FFFFFFFFFFFFF8F8F81D1D1D2A2A2AF2F2F2FFFFFFFFFFFFCFCFCFCFCFCF
            FFFFFFFFFFFFF1F1F1282828202020F9F9F9FFFFFFFFFFFF0000FFFFFFFFFFFF
            D1D1D1BDBDBD050505333333D8D8D8FFFFFFFFFFFFFFFFFFFFFFFFD6D6D63131
            31060606C0C0C0CECECEFFFFFFFFFFFF0000FFFFFFC1C1C1010101757575B3B3
            B3111111030303464646777777777777454545030303121212B4B4B46D6D6D01
            0101C2C2C2FFFFFF0000FFFFFFFCFCFC6F6F6F0000004D4D4DDCDCDC7B7B7B2B
            2B2B0606060707072D2D2D7D7D7DDCDCDC484848000000717171FDFDFDFFFFFF
            0000FFFFFFFFFFFFFFFFFF989898040404585858FFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFF5353530505059B9B9BFFFFFFFFFFFFFFFFFF0000FFFFFFFFFFFF
            FFFFFFFFFFFFBEBEBEE0E0E0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDEDE
            DEC0C0C0FFFFFFFFFFFFFFFFFFFFFFFF0000FFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFF0000}
          ParentFont = False
          TabOrder = 0
          OnClick = BtnTeachStart1Click
        end
        object StaticText1: TStaticText
          Left = 26
          Top = 90
          Width = 685
          Height = 107
          AutoSize = False
          Caption = 
            ' TOP TO BOTTOM VISION OFFSET TEACHING'#51008' Flip'#46108' '#51228#54408#51032'  '#51221#54869#54620'  "Put Down' +
            ' "'#51012'  '#50948#54644#49436' Top '#48143' Bottom Vision'#44036#51032'  Offset'#51012' '#44396#54633#45768#45796'.'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 1
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'TabSheet2'
      ImageIndex = 1
      TabVisible = False
      object BtnTeachNext2: TBitBtn
        Left = 632
        Top = 529
        Width = 105
        Height = 35
        Caption = 'NEXT'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'Calibri'
        Font.Style = []
        Layout = blGlyphTop
        ParentFont = False
        TabOrder = 0
        OnClick = BtnTeachNext2Click
      end
      object CurvyPanel2: TCurvyPanel
        Left = 15
        Top = 3
        Width = 722
        Height = 520
        TabOrder = 1
        object BtnStep1: TBitBtn
          Tag = 1000
          Left = 14
          Top = 11
          Width = 697
          Height = 40
          Caption = 'STAGE1'#51032' '#50504#51204' '#51312#44148#51012' '#54869#51064' '#54980' SORTING '#50948#52824#47196' '#51060#46041' '#54633#45768#45796'.'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          Layout = blGlyphTop
          ParentFont = False
          TabOrder = 0
          OnClick = BtnStep1Click
        end
        object PanelNextStep1: TPanel
          Left = 262
          Top = 84
          Width = 161
          Height = 44
          Color = clGray
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 1
        end
        object PanelNextStep2: TPanel
          Left = 262
          Top = 213
          Width = 161
          Height = 44
          Color = clGray
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 2
        end
        object BtnStep2: TBitBtn
          Tag = 1001
          Left = 14
          Top = 141
          Width = 697
          Height = 40
          Caption = 'STAGE1'#50640' TRAY '#48143' UNIT'#51012' '#50504#52265' '#49884#53429#45768#45796'. '
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          Layout = blGlyphTop
          ParentFont = False
          TabOrder = 3
          OnClick = BtnStep1Click
        end
        object PanelNextStep3: TPanel
          Left = 262
          Top = 341
          Width = 161
          Height = 44
          Color = clGray
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 4
        end
        object BtnStep3: TBitBtn
          Tag = 1002
          Left = 14
          Top = 272
          Width = 697
          Height = 40
          Caption = 'TP80'#47196#48391#51032' PAD'#47484' '#51109#52265' '#54633#45768#45796'. ( PAD CHANGE TENKEY  : 37 + HOME)'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          Layout = blGlyphTop
          ParentFont = False
          TabOrder = 5
          OnClick = BtnStep1Click
        end
        object PanelNextStep4: TPanel
          Left = 262
          Top = 466
          Width = 161
          Height = 44
          Color = clGray
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 6
        end
        object BtnStep4: TBitBtn
          Tag = 1003
          Left = 14
          Top = 398
          Width = 697
          Height = 40
          Caption = #49324#50857#51088#44032' VISION'#51032' '#51456#48708#49345#53468#47484' '#54869#51064' '#54633#45768#45796'. ( VISION PROGRAM START BUTTON)'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          Layout = blGlyphTop
          ParentFont = False
          TabOrder = 7
          OnClick = BtnStep1Click
        end
        object Panel5: TPanel
          Left = 15
          Top = 49
          Width = 695
          Height = 25
          BevelKind = bkFlat
          BevelOuter = bvNone
          Caption = 'Check safety condition of STAGE1 and move to SORTING position.'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 8
        end
        object Panel6: TPanel
          Left = 15
          Top = 179
          Width = 695
          Height = 25
          BevelKind = bkFlat
          BevelOuter = bvNone
          Caption = 'Place TRAY and UNIT on STAGE1.'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 9
        end
        object Panel7: TPanel
          Left = 15
          Top = 310
          Width = 695
          Height = 25
          BevelKind = bkFlat
          BevelOuter = bvNone
          Caption = 'Install the TP80 robot'#39's PAD. (PAD CHANGE TENKEY: 37 + HOME)...'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 10
        end
        object panE4: TPanel
          Left = 15
          Top = 436
          Width = 695
          Height = 25
          BevelKind = bkFlat
          BevelOuter = bvNone
          Caption = 'Check the readiness of VISION. (VISION PROGRAM START BUTTON)'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 11
        end
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'TabSheet3'
      ImageIndex = 2
      TabVisible = False
      object CurvyPanel3: TCurvyPanel
        Left = 15
        Top = 3
        Width = 722
        Height = 520
        TabOrder = 0
        object BtnStep8: TBitBtn
          Tag = 1007
          Left = 14
          Top = 131
          Width = 697
          Height = 40
          Caption = 'FLIPPER'#44032' FLIP CYCLE'#51012' '#49688#54665' '#54633#45768#45796'.'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          Layout = blGlyphTop
          ParentFont = False
          TabOrder = 0
          OnClick = BtnStep1Click
        end
        object PanelNextStep8: TPanel
          Left = 262
          Top = 201
          Width = 161
          Height = 44
          Color = clGray
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 1
        end
        object BtnStep9: TBitBtn
          Tag = 1008
          Left = 14
          Top = 254
          Width = 697
          Height = 40
          Caption = 'FLIPPER'#44032' TOP VISION CYCLE'#51012' '#49688#54665' '#54633#45768#45796'.'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          Layout = blGlyphTop
          ParentFont = False
          TabOrder = 2
          OnClick = BtnStep1Click
        end
        object PanelNextStep9: TPanel
          Left = 262
          Top = 324
          Width = 161
          Height = 44
          Color = clGray
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 3
        end
        object BtnStep10: TBitBtn
          Tag = 1009
          Left = 14
          Top = 378
          Width = 697
          Height = 40
          Caption = 'FLIPPER BOTTOM'#50640#49436' UNIT'#51012' PICK UP '#54633#45768#45796'.'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          Layout = blGlyphTop
          ParentFont = False
          TabOrder = 4
          OnClick = BtnStep1Click
        end
        object PanelNextStep10: TPanel
          Left = 262
          Top = 449
          Width = 161
          Height = 44
          Color = clGray
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 5
        end
        object BtnStep5: TBitBtn
          Tag = 1004
          Left = 14
          Top = 10
          Width = 697
          Height = 40
          Caption = 'STAGE1'#50640#49436' UNIT'#51012' PICK UP '#54633#45768#45796'.'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          Layout = blGlyphTop
          ParentFont = False
          TabOrder = 6
          OnClick = BtnStep1Click
        end
        object PanelNextStep5: TPanel
          Left = 262
          Top = 81
          Width = 161
          Height = 44
          Color = clGray
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 7
        end
        object Panel1: TPanel
          Left = 15
          Top = 48
          Width = 695
          Height = 30
          BevelKind = bkFlat
          BevelOuter = bvNone
          Caption = 'PICK UP UNIT in STAGE1.'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 8
        end
        object Panel2: TPanel
          Left = 15
          Top = 169
          Width = 695
          Height = 30
          BevelKind = bkFlat
          BevelOuter = bvNone
          Caption = 'FLIPPER performs FLIP CYCLE.'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 9
        end
        object Panel3: TPanel
          Left = 15
          Top = 292
          Width = 695
          Height = 30
          BevelKind = bkFlat
          BevelOuter = bvNone
          Caption = 'FLIPPER performs TOP VISION CYCLE.'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 10
        end
        object Panel4: TPanel
          Left = 15
          Top = 416
          Width = 695
          Height = 30
          BevelKind = bkFlat
          BevelOuter = bvNone
          Caption = 'Pick up the UNIT at the FLIPPER BOTTOM.'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 11
        end
      end
      object BtnTeachNext3: TBitBtn
        Left = 632
        Top = 529
        Width = 105
        Height = 35
        Caption = 'NEXT'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'Calibri'
        Font.Style = []
        Layout = blGlyphTop
        ParentFont = False
        TabOrder = 1
        OnClick = BtnTeachNext3Click
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'TabSheet4'
      ImageIndex = 3
      TabVisible = False
      object BtnTeachNext4: TBitBtn
        Left = 114
        Top = 184
        Width = 527
        Height = 177
        Caption = 'COMPLETE'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'Calibri'
        Font.Style = []
        Glyph.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          1800000000000003000012170000121700000000000000000000FFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF62626213
          1313F0F0F0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFF646464060606060606454545FFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6767670A0A0A0A0A0A0A
          0A0A0A0A0A858585FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFF6969690E0E0E0E0E0E0E0E0E0E0E0E0E0E0E0E0E0EC3C3C3FFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6B6B6B11111111111111111111111111
          1111111111111111202020F1F1F1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6E6E6E
          151515151515151515151515151515151515151515151515151515505050FFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFF27272719191919191919191919191919191935
          35351919191919191919191919198C8C8CFFFFFFFFFFFFFFFFFFFFFFFFD4D4D4
          2A2A2A1C1C1C1C1C1C1C1C1CAAAAAAF1F1F14646461C1C1C1C1C1C1C1C1C1C1C
          1CC7C7C7FFFFFFFFFFFFFFFFFFFFFFFFD5D5D52E2E2E202020828282FFFFFFFF
          FFFFF1F1F14A4A4A2020202020202020202E2E2EF2F2F2FFFFFFFFFFFFFFFFFF
          FFFFFFD6D6D69E9E9EFFFFFFFFFFFFFFFFFFFFFFFFF2F2F24D4D4D2323232323
          232323235B5B5BFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFF2F2F24F4F4F272727272727272727939393FFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF2F2F25353
          532B2B2B2B2B2B2B2B2BFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFF2F2F25656562E2E2E3C3C3CFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFF3F3F35858587F7F7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
        ParentFont = False
        TabOrder = 0
        OnClick = BtnTeachNext4Click
      end
    end
  end
  object FeedbackTimer: TTimer
    Enabled = False
    Interval = 500
    OnTimer = FeedbackTimerTimer
    Left = 715
    Top = 86
  end
end
