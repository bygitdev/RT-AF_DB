object frmSeeLot: TfrmSeeLot
  Left = 0
  Top = 0
  BorderStyle = bsNone
  Caption = 'See Lot'
  ClientHeight = 639
  ClientWidth = 971
  Color = clGray
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Calibri'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 15
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 971
    Height = 639
    ActivePage = TabSheet1
    Align = alClient
    Style = tsButtons
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'SeeLot'
      TabVisible = False
      object CurvyPanel1: TCurvyPanel
        Left = 0
        Top = 46
        Width = 962
        Height = 580
        Color = clBtnFace
        TabOrder = 0
        object Shape1: TShape
          Left = 479
          Top = 9
          Width = 1
          Height = 491
          Pen.Style = psDot
        end
        object Shape2: TShape
          Left = 10
          Top = 510
          Width = 943
          Height = 1
          Pen.Style = psDot
        end
        object btnLotEnd: TBitBtn
          Left = 714
          Top = 522
          Width = 241
          Height = 48
          Caption = 'Lot End'
          Enabled = False
          Font.Charset = ANSI_CHARSET
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
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4ED3FF07C1FF07C1FF07C1
            FF07C1FF07C1FF07C1FF07C1FF07C1FF07C1FF07C1FF07C1FF07C1FF07C1FF07
            C1FF07C1FF07C1FF07C1FF07C1FF07C1FF07C1FF4FD3FFFFFFFFFFFFFFD9F6FF
            0CC2FF07C1FF07C1FF07C1FF07C1FF07C1FF07C1FF07C1FF07C1FF07C1FF07C1
            FF07C1FF07C1FF07C1FF07C1FF07C1FF07C1FF07C1FF07C1FF0CC2FFDAF6FFFF
            FFFFFFFFFFFFFFFF75DCFF07C1FF07C1FF07C1FF07C1FF07C1FF07C1FF07C1FF
            07C1FF07C1FF07C1FF07C1FF07C1FF07C1FF07C1FF07C1FF07C1FF07C1FF07C1
            FF76DDFFFFFFFFFFFFFFFFFFFFFFFFFFF0FBFF1BC6FF07C1FF07C1FF07C1FF07
            C1FF07C1FF07C1FF07C1FFFFFFFFFFFFFF07C1FF07C1FF07C1FF07C1FF07C1FF
            07C1FF07C1FF1CC6FFF0FBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9DE6FF07C1
            FF07C1FF07C1FF07C1FF07C1FF07C1FF07C1FFFFFFFFFFFFFF07C1FF07C1FF07
            C1FF07C1FF07C1FF07C1FF07C1FF9EE7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFDFFFF37CDFF07C1FF07C1FF07C1FF07C1FF07C1FF07C1FF07C1FF07C1
            FF07C1FF07C1FF07C1FF07C1FF07C1FF07C1FF38CDFFFDFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFC4F0FF07C1FF07C1FF07C1FF07C1FF07C1FF
            07C1FF07C1FF07C1FF07C1FF07C1FF07C1FF07C1FF07C1FF07C1FFC5F0FFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF5BD6FF07C1FF07
            C1FF07C1FF07C1FF07C1FFFFFFFFFFFFFF07C1FF07C1FF07C1FF07C1FF07C1FF
            5CD6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFE2F8FF10C3FF07C1FF07C1FF07C1FF07C1FFFFFFFFFFFFFF07C1FF07C1FF07
            C1FF07C1FF10C3FFE3F8FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFF83E0FF07C1FF07C1FF07C1FF07C1FFFFFFFFFFFF
            FF07C1FF07C1FF07C1FF07C1FF83E0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6FDFF23C8FF07C1FF07C1FF
            07C1FFFFFFFFFFFFFF07C1FF07C1FF07C1FF24C8FFF6FDFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFA9
            EAFF07C1FF07C1FF07C1FF07C1FF07C1FF07C1FF07C1FF07C1FFAAEAFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFF41D0FF07C1FF07C1FF07C1FF07C1FF07C1FF07C1FF42
            D0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCEF3FF09C1FF07C1FF07C1FF07C1
            FF07C1FF09C1FFCFF3FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF68D9FF
            07C1FF07C1FF07C1FF07C1FF69DAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFEAFAFF16C5FF07C1FF07C1FF16C5FFEBFAFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF8FE3FF07C1FF07C1FF90E3FFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFEFF2CCAFF2DCA
            FFFAFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFB7EDFFB7EDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
          ParentFont = False
          TabOrder = 0
          OnClick = btnLotEndClick
        end
        object ceMergeLotID: TCurvyEdit
          Left = 131
          Top = 9
          Width = 324
          Height = 36
          TabOrder = 1
          TabStop = False
          Version = '1.1.1.8'
          Alignment = taCenter
          Controls = <>
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ImeName = 'Microsoft IME 2010'
          ParentFont = False
          Text = 'LOTID'
        end
        object btnSeeLot: TBitBtn
          Left = 10
          Top = 452
          Width = 120
          Height = 48
          Caption = 'See Lot'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Calibri'
          Font.Style = []
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
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD0D0D06B6B6B2A2A2AFFFFFFFFFF
            FF2B2B2B6E6E6ED3D3D3FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF797979010101000000
            000000FFFFFFFFFFFF0000000000000202026B6B6BF8F8F8FFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD1
            D1D11919196B6B6BC6C6C6FFFFFFFFFFFFC8C8C86B6B6B060606000000414141
            F8F8F8FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FF7F7F7FD7D7D7FFFFFFF9F9F9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCF
            CFCF1A1A1A0000006A6A6AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFD1D1D1010101212121FDFDFDFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFD0D0D0060606020202D2D2D2FFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFF686868000000737373FFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6D6D6D0000006A6A6AFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF252525000000CFCFCFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCACACA
            000000292929FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFF7F7F7000000070707FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFF7F7F7000000070707FFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFF242424000000D0D0D0FFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCBCBCB000000282828FFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF686868000000757575FF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFF7C7C7CFFFFFFFFFFFFFFFFFFFFFFFF6F6F6F
            000000696969FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD0D0
            D00101011E1E1EFCFCFCFFFFFFFFFFFFFFFFFF767676000000FFFFFFFFFFFFFF
            FFFFD2D2D2070707010101D0D0D0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFF7C7C7CD4D4D4FFFFFFFFFFFFFFFFFF7070700000000000
            00FFFFFFFFFFFFD3D3D31C1C1C000000666666FFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFE6A6A6A
            000000000000000000CECECE7272720707070000003D3D3DF7F7F7FFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFB1B1B1000000000000000000000000000000000000010101656565F6F6F6
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFF7C7C7C000000000000000000262626676767CE
            CECEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF7C7C7C0000000000
            00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFF7C7C7C000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFF7C7C7CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
          ParentFont = False
          TabOrder = 2
          OnClick = btnSeeLotClick
        end
        object CurvyPanel2: TCurvyPanel
          Left = 10
          Top = 51
          Width = 445
          Height = 175
          TabOrder = 3
          object Label1: TLabel
            Left = 28
            Top = 22
            Width = 61
            Height = 18
            Caption = 'LOT STATE'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'Calibri'
            Font.Style = []
            ParentFont = False
          end
          object Label3: TLabel
            Left = 28
            Top = 60
            Width = 54
            Height = 18
            Caption = 'PART NO'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'Calibri'
            Font.Style = []
            ParentFont = False
          end
          object Label6: TLabel
            Left = 284
            Top = 22
            Width = 24
            Height = 18
            Caption = 'QTY'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'Calibri'
            Font.Style = []
            ParentFont = False
          end
          object Label14: TLabel
            Left = 28
            Top = 100
            Width = 43
            Height = 18
            Caption = 'RESULT'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'Calibri'
            Font.Style = []
            ParentFont = False
            Visible = False
          end
          object Label2: TLabel
            Left = 28
            Top = 140
            Width = 28
            Height = 18
            Caption = 'MSG'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'Calibri'
            Font.Style = []
            ParentFont = False
          end
          object lotState: TCurvyEdit
            Left = 101
            Top = 13
            Width = 100
            Height = 34
            TabOrder = 0
            TabStop = False
            Version = '1.1.1.8'
            Controls = <>
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -19
            Font.Name = 'Calibri'
            Font.Style = []
            ImeName = 'Microsoft IME 2010'
            ParentFont = False
            ReadOnly = True
            Text = 'RUN'
          end
          object partNo: TCurvyEdit
            Left = 101
            Top = 52
            Width = 334
            Height = 34
            TabOrder = 1
            TabStop = False
            Version = '1.1.1.8'
            Controls = <>
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -19
            Font.Name = 'Calibri'
            Font.Style = []
            ImeName = 'Microsoft IME 2010'
            ParentFont = False
            ReadOnly = True
            Text = 'MZ7LN250HCHP-2BW00-G1'
          end
          object qty: TCurvyEdit
            Left = 335
            Top = 13
            Width = 100
            Height = 34
            TabOrder = 2
            TabStop = False
            Version = '1.1.1.8'
            Controls = <>
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -19
            Font.Name = 'Calibri'
            Font.Style = [fsBold]
            ImeName = 'Microsoft IME 2010'
            ParentFont = False
            ReadOnly = True
            Text = '200'
            OnChange = eqInputCntChange
          end
          object result: TCurvyEdit
            Left = 101
            Top = 92
            Width = 334
            Height = 34
            TabOrder = 3
            TabStop = False
            Visible = False
            Version = '1.1.1.8'
            Controls = <>
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -19
            Font.Name = 'Calibri'
            Font.Style = [fsBold]
            ImeName = 'Microsoft IME 2010'
            ParentFont = False
            ReadOnly = True
            Text = ''
          end
          object msg: TCurvyEdit
            Left = 101
            Top = 132
            Width = 334
            Height = 34
            TabOrder = 4
            TabStop = False
            Version = '1.1.1.8'
            Controls = <>
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clRed
            Font.Height = -19
            Font.Name = 'Calibri'
            Font.Style = [fsBold]
            ImeName = 'Microsoft IME 2010'
            ParentFont = False
            ReadOnly = True
            Text = ''
          end
        end
        object CurvyPanel3: TCurvyPanel
          Left = 3
          Top = 232
          Width = 452
          Height = 211
          TabOrder = 4
          object Label8: TLabel
            Left = 24
            Top = 25
            Width = 87
            Height = 18
            Caption = 'SCRAP COUNT'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'Calibri'
            Font.Style = []
            ParentFont = False
          end
          object scrapCount: TCurvyEdit
            Left = 121
            Top = 15
            Width = 100
            Height = 33
            TabOrder = 0
            TabStop = False
            Version = '1.1.1.8'
            Controls = <>
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -19
            Font.Name = 'Calibri'
            Font.Style = [fsBold]
            ImeName = 'Microsoft IME 2010'
            ParentFont = False
            ReadOnly = True
            Text = '0'
            OnChange = eqInputCntChange
          end
          object sgScrap: TStringGrid
            Left = 0
            Top = 59
            Width = 452
            Height = 152
            Align = alBottom
            ColCount = 3
            DefaultColWidth = 30
            RowCount = 1001
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -12
            Font.Name = 'Arial'
            Font.Style = []
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing, goRowSelect, goFixedRowClick]
            ParentFont = False
            TabOrder = 1
            ColWidths = (
              30
              64
              329)
          end
        end
        object CurvyPanel4: TCurvyPanel
          Left = 504
          Top = 51
          Width = 449
          Height = 175
          TabOrder = 5
          object Label9: TLabel
            Left = 28
            Top = 22
            Width = 85
            Height = 18
            Caption = 'INPUT COUNT'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'Calibri'
            Font.Style = []
            ParentFont = False
          end
          object Label11: TLabel
            Left = 28
            Top = 60
            Width = 85
            Height = 18
            Caption = 'GOOD COUNT'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'Calibri'
            Font.Style = []
            ParentFont = False
          end
          object Label16: TLabel
            Left = 28
            Top = 100
            Width = 89
            Height = 18
            Caption = 'REJECT COUNT'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'Calibri'
            Font.Style = []
            ParentFont = False
          end
          object Label17: TLabel
            Left = 252
            Top = 22
            Width = 73
            Height = 18
            Caption = 'OUT COUNT'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'Calibri'
            Font.Style = []
            ParentFont = False
          end
          object eqInputCnt: TCurvyEdit
            Left = 125
            Top = 13
            Width = 100
            Height = 34
            TabOrder = 0
            TabStop = False
            Version = '1.1.1.8'
            Controls = <>
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -19
            Font.Name = 'Calibri'
            Font.Style = [fsBold]
            ImeName = 'Microsoft IME 2010'
            ParentFont = False
            ReadOnly = True
            Text = '0'
            OnChange = eqInputCntChange
          end
          object eqGoodCnt: TCurvyEdit
            Left = 125
            Top = 52
            Width = 100
            Height = 34
            TabOrder = 1
            TabStop = False
            Version = '1.1.1.8'
            Controls = <>
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -19
            Font.Name = 'Calibri'
            Font.Style = []
            ImeName = 'Microsoft IME 2010'
            ParentFont = False
            ReadOnly = True
            Text = '0'
          end
          object eqRejectCnt: TCurvyEdit
            Left = 125
            Top = 92
            Width = 100
            Height = 34
            TabOrder = 2
            TabStop = False
            Version = '1.1.1.8'
            Controls = <>
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clRed
            Font.Height = -19
            Font.Name = 'Calibri'
            Font.Style = []
            ImeName = 'Microsoft IME 2010'
            ParentFont = False
            ReadOnly = True
            Text = '0'
          end
          object eqOutPutCnt: TCurvyEdit
            Left = 341
            Top = 13
            Width = 100
            Height = 34
            TabOrder = 3
            TabStop = False
            Version = '1.1.1.8'
            Controls = <>
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -19
            Font.Name = 'Calibri'
            Font.Style = []
            ImeName = 'Microsoft IME 2010'
            ParentFont = False
            ReadOnly = True
            Text = '0'
          end
        end
        object ceEqpID: TCurvyEdit
          Left = 629
          Top = 9
          Width = 324
          Height = 36
          TabOrder = 6
          TabStop = False
          Version = '1.1.1.8'
          Alignment = taCenter
          Controls = <>
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ImeName = 'Microsoft IME 2010'
          ParentFont = False
          Text = 'EQPID'
        end
        object CurvyPanel5: TCurvyPanel
          Left = 504
          Top = 232
          Width = 449
          Height = 211
          TabOrder = 7
          object Label18: TLabel
            Left = 28
            Top = 25
            Width = 87
            Height = 18
            Caption = 'SCRAP COUNT'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'Calibri'
            Font.Style = []
            ParentFont = False
          end
          object sgEqScrap: TStringGrid
            Left = 0
            Top = 60
            Width = 449
            Height = 151
            Align = alBottom
            ColCount = 3
            DefaultColWidth = 30
            RowCount = 1001
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -12
            Font.Name = 'Arial'
            Font.Style = []
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing, goRowSelect]
            ParentFont = False
            TabOrder = 0
            ColWidths = (
              30
              67
              323)
            RowHeights = (
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24
              24)
          end
          object eqScrapCnt: TCurvyEdit
            Left = 125
            Top = 15
            Width = 100
            Height = 33
            TabOrder = 1
            TabStop = False
            Version = '1.1.1.8'
            Controls = <>
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -19
            Font.Name = 'Calibri'
            Font.Style = [fsBold]
            ImeName = 'Microsoft IME 2010'
            ParentFont = False
            ReadOnly = True
            Text = '0'
            OnChange = eqInputCntChange
          end
        end
        object btnDelete: TBitBtn
          Left = 298
          Top = 452
          Width = 157
          Height = 48
          Caption = 'Delete Scrap Info'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Calibri'
          Font.Style = []
          Glyph.Data = {
            F6060000424DF606000000000000360000002800000018000000180000000100
            180000000000C0060000C40E0000C40E00000000000000000000FFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD7D7D74E4E4E0C0C0C0C0C0C50
            5050D9D9D9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD7D7D70F0F0F0000
            00000000000000000000111111D9D9D9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFF7F7F7F000000000000000000FFFFFFFFFFFFFFFFFFFFFFFF
            4D4D4D000000505050E9E9E9E8E8E84E4E4E000000505050FFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFF7F7F7F0000000000000000007F7F7FFFFFFFFF
            FFFFFFFFFFFFFFFF0B0B0B000000EAEAEAFFFFFFFFFFFFE8E8E80000000C0C0C
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF7F7F7F0000000000000000007F7F
            7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0A0A0A000000EBEBEBFFFFFFFFFFFFE9
            E9E90000000C0C0CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF7F7F7F000000000000
            0000007F7F7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4B4B4B0000005353
            53EBEBEBEAEAEA5050500000003A3A3AFFFFFFFFFFFFFFFFFFFFFFFF7F7F7F00
            00000000000000007F7F7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            D5D5D50E0E0E000000000000000000000000000000000000828282FFFFFFFFFF
            FF7F7F7F0000000000000000007F7F7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFD5D5D54B4B4B0A0A0A0A0A0A353535000000000000
            0000008080807F7F7F0000000000000000007F7F7FFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFF7D7D7D0000000000000000000000000000000000007F7F7FFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFF7E7E7E0000003232323030300000007F7F7FFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF7F7F7F0000003333333232
            327F7F7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF7F7F7F000000
            0000000000007F7F7FFFFFFF7F7F7F7F7F7FFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD7D7D74E4E4E0C0C0C0D0D0D3A
            3A3A0000000000000000007F7F7FFFFFFF7F7F7F0000000000007F7F7FFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD7D7D70F0F0F0000
            000000000000000000000000000000007F7F7FFFFFFFFFFFFF7F7F7F00000000
            00000000007F7F7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            4D4D4D0000004F4F4FE7E7E7E7E7E74D4D4D0000003A3A3AFFFFFFFFFFFFFFFF
            FFFFFFFF7F7F7F0000000000000000007F7F7FFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFF0B0B0B000000E8E8E8FFFFFFFFFFFFE7E7E70000000D0D0D
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF7F7F7F0000000000000000007F7F7FFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0A0A0A000000E9E9E9FFFFFFFFFFFFE8
            E8E80000000C0C0CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF7F7F7F000000
            0000000000007F7F7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4B4B4B0000005151
            51E9E9E9E8E8E84F4F4F0000004E4E4EFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFF7F7F7F0000000000000000007F7F7FFFFFFFFFFFFFFFFFFFFFFFFF
            D5D5D50E0E0E0000000000000000000000000F0F0FD7D7D7FFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF7F7F7F000000000000000000FFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFD5D5D54B4B4B0A0A0A0B0B0B4D4D4DD7D7D7FFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
          ParentFont = False
          TabOrder = 8
          OnClick = btnDeleteClick
        end
        object btnEdit: TBitBtn
          Left = 504
          Top = 452
          Width = 90
          Height = 48
          Caption = 'Edit'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Calibri'
          Font.Style = []
          Glyph.Data = {
            F6060000424DF606000000000000360000002800000018000000180000000100
            180000000000C0060000C40E0000C40E00000000000000000000FFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000
            00000000080808B8B8B8FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFF000000000000000000000000080808B8B8B8FFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000080808B9B9B9
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF07070700000000000000000000
            0000000000080808B9B9B9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB7B7B70707
            07000000000000000000000000000000080808B9B9B9FFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFB7B7B7070707000000000000000000000000000000080808BABA
            BAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB6B6B6070707000000000000000000
            000000000000080808BABABAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB6B6B607
            0707000000000000000000000000000000080808BABABAFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFB6B6B6070707000000000000000000000000000000080808BA
            BABAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB6B6B60707070000000000000000
            00000000000000090909BABABAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB5B5B5
            070707000000000000000000000000000000090909BABABAFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFB5B5B5070707000000000000000000000000020202A2A2A2
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB5B5B507070700000000000002
            0202A1A1A1FFFFFF878787BABABAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB4B4
            B4070707020202A1A1A1FFFFFF838383000000090909BABABAFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFB4B4B4A2A2A2FFFFFF8383830000000000000000001212
            12FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF878787000000000000
            000000000000707070FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB4
            B4B40707070000000000006C6C6CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFB4B4B40B0B0B707070FFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
          ParentFont = False
          TabOrder = 9
          OnClick = btnEditClick
        end
        object CurvyEdit1: TCurvyEdit
          Left = 10
          Top = 9
          Width = 115
          Height = 36
          TabOrder = 10
          TabStop = False
          Version = '1.1.1.8'
          Alignment = taCenter
          Controls = <>
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = 'Calibri'
          Font.Style = []
          ImeName = 'Microsoft IME 2010'
          ParentFont = False
          Text = 'SERVER'
        end
        object CurvyEdit2: TCurvyEdit
          Left = 504
          Top = 9
          Width = 115
          Height = 36
          TabOrder = 11
          TabStop = False
          Version = '1.1.1.8'
          Alignment = taCenter
          Controls = <>
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = 'Calibri'
          Font.Style = []
          ImeName = 'Microsoft IME 2010'
          ParentFont = False
          Text = 'EQ'
        end
        object btnLotEndManual: TBitBtn
          Left = 10
          Top = 522
          Width = 200
          Height = 48
          Caption = 'Manual Lot Out'
          Font.Charset = ANSI_CHARSET
          Font.Color = clRed
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
            FFFFFFFFFFFF0000000000000000000000000000000000000000000000000000
            00000000000000000000000000000000000000000000FFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000
            000000000000000000000000000000000000000000000000000000000000FFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF18181800000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            000000191919FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFA5A5
            A502020200000000000000000000000000000000000000000000000000000000
            0000000000000000030303A7A7A7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFC2C2C23737370000000000000000000000000000000000
            00000000000000000000000000383838C4C4C4FFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCFCFCF818181454545
            1B1B1B0404040404041C1C1C464646828282D0D0D0FFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD7D7D74E4E4E0C0C0C0C0C
            0C505050D9D9D9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD7D7D70F0F0F
            000000000000000000000000111111D9D9D9FFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFF4D4D4D000000000000000000000000000000000000505050FFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFF0B0B0B0000000000000000000000000000000000000C
            0C0CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0A0A0A0000000000000000000000
            000000000000000C0C0CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4B4B4B000000
            0000000000000000000000000000004E4E4EFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFD5D5D50E0E0E0000000000000000000000000F0F0FD7D7D7FFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFD5D5D54B4B4B0A0A0A0B0B0B4D4D4DD7D7D7FF
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
          TabOrder = 12
          OnClick = btnLotEndManualClick
        end
        object btnSave: TBitBtn
          Left = 596
          Top = 452
          Width = 90
          Height = 48
          Caption = 'Save'
          Enabled = False
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Calibri'
          Font.Style = []
          Glyph.Data = {
            F6060000424DF606000000000000360000002800000018000000180000000100
            180000000000C0060000C40E0000C40E00000000000000000000FFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFAFAF1616
            1600000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000171717B2B2B2FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFF1515150000000000000000000000000000000000000000000000000000
            00000000000000000000000000000000000000000000171717FFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000070707
            939393F0F0F0EFEFEF9090900606060000000000000000000000000000000000
            00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000000
            0000000000949494FFFFFFFFFFFFFFFFFFFFFFFF909090000000000000000000
            000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000
            00000000000000000000000000F1F1F1FFFFFFFFFFFFFFFFFFFFFFFFEFEFEF00
            0000000000000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFF000000000000000000000000000000000000F2F2F2FFFFFFFFFFFFFFFF
            FFFFFFFFF0F0F0000000000000000000000000000000000000FFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000969696
            FFFFFFFFFFFFFFFFFFFFFFFF9393930000000000000000000000000000000000
            00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000000
            0000000000080808969696F2F2F2F1F1F1949494070707000000000000000000
            000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000
            0000000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFF0000000000000000000000000000000000000000000000000000000000
            00000000000000000000000000000000000000000000000000FFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000
            00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00
            0000000000000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFF000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFF000000000000000000000000000000000000FFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000000000000000000000007F7F
            7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000000000
            0000007F7F7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1616160000
            0000000000000000000000000000000000000000000000000000000000000000
            00000000000000007F7F7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFAEAEAE1616160000000000000000000000000000000000000000000000
            000000000000000000000000007F7F7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
          ParentFont = False
          TabOrder = 13
          OnClick = btnSaveClick
        end
        object btnOnlineEndAll: TBitBtn
          Left = 811
          Top = 452
          Width = 142
          Height = 48
          Caption = 'Online End'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Calibri'
          Font.Style = []
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
            F8F8F89090903434340909090000000000000000000000000000000000000000
            000000000000000000000000000000000000000A0A0A3F3F3FB2B2B2FFFFFFFF
            FFFFFFFFFFE4E4E42E2E2E000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            00000000787878FFFFFFF8F8F82D2D2D00000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            000000000000000000000000000000B2B2B28F8F8F0000000000000000000000
            00000000000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFF00000000
            00000000000000000000000000000000000000000000003F3F3F333333000000
            000000000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF
            FFFFFFFF0000000000000000000000000000000000000000000000000000000A
            0A0A070707000000000000000000000000000000000000000000000000000000
            FFFFFFFFFFFFFFFFFFFFFFFF0000000000000000000000000000000000000000
            000000000000000A0A0A07070700000000000000000000000000000000000000
            0000000000000000FFFFFFFFFFFFFFFFFFFFFFFF000000000000000000000000
            0000000000000000000000000000003F3F3F3131310000000000000000000000
            000000000000007F7F7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFF7F7F7F000000000000000000000000000000000000B2B2B28B8B8B000000
            0000000000000000000000000000000000007F7F7FFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFF7F7F7F000000000000000000000000000000000000797979FF
            FFFFF6F6F62929290000000000000000000000000000000000000000007F7F7F
            FFFFFFFFFFFFFFFFFFFFFFFF7F7F7F0000000000000000000000000C0C0C4343
            43B4B4B4FFFFFFFFFFFFFFFFFFE1E1E12A2A2A00000000000000000000000000
            00000000000000007F7F7FFFFFFFFFFFFF7F7F7F000000000000000000000000
            000000CBCBCBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF7F7F78B8B8B3030
            300404040000000000000000000000000000007F7F7F7F7F7F00000000000000
            0000000000000000272727FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFA7A7A70000000000000000000000000000000000000000
            00000000000000000000000000000000AEAEAEFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF686868000000000000000000
            000000000000000000000000000000000000000000707070FFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFE7F
            7F7F040404000000000000000000000000000000000000050505848484FFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFD8D8D86D6D6D2727270505050606062828286F6F6FDB
            DBDBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
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
          TabOrder = 14
          OnClick = btnOnlineEndAllClick
        end
        object btnManualClose: TBitBtn
          Left = 544
          Top = 522
          Width = 164
          Height = 48
          Caption = 'CLOSE'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 15
          OnClick = btnManualCloseClick
        end
        object BitBtn1: TBitBtn
          Left = 458
          Top = 362
          Width = 43
          Height = 31
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Calibri'
          Font.Style = []
          Glyph.Data = {
            360C0000424D360C000000000000360000002800000020000000200000000100
            180000000000000C000012170000121700000000000000000000FFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF010101313131F0F0F0FFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF030303030303333333F0F0F0FFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF050505050505050505353535F0F0F0FF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF070707070707070707070707363636F0
            F0F0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF09090909090909090909090909090938
            3838F0F0F0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B
            0B0B393939F0F0F0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D
            0D0D0D0D0D3B3B3BF0F0F0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFE2E2E20F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F
            0F0F0F0F0F0F0F0F3D3D3DF1F1F1FFFFFFFFFFFFFFFFFFFFFFFF202020111111
            1111111111111111111111111111111111111111111111111111111111111111
            1111111111111111111111111111111111111111111111111111111111111111
            11111111111111111111113E3E3EF1F1F1FFFFFFFFFFFFFFFFFF131313131313
            1313131313131313131313131313131313131313131313131313131313131313
            1313131313131313131313131313131313131313131313131313131313131313
            1313131313131313131313131313404040F1F1F1FFFFFFFFFFFF151515151515
            1515151515151515151515151515151515151515151515151515151515151515
            1515151515151515151515151515151515151515151515151515151515151515
            1515151515151515151515151515151515424242F1F1F1FFFFFF171717171717
            1717171717171717171717171717171717171717171717171717171717171717
            1717171717171717171717171717171717171717171717171717171717171717
            1717171717171717171717171717171717171717434343F1F1F1191919191919
            1919191919191919191919191919191919191919191919191919191919191919
            1919191919191919191919191919191919191919191919191919191919191919
            19191919191919191919191919191919191919191919197F7F7F1B1B1B1B1B1B
            1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B
            1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B
            1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B7171711D1D1D1D1D1D
            1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D
            1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D
            1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D1D474747F1F1F11F1F1F1F1F1F
            1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F
            1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F
            1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F494949F1F1F1FFFFFF212121212121
            2121212121212121212121212121212121212121212121212121212121212121
            2121212121212121212121212121212121212121212121212121212121212121
            21212121212121212121212121214A4A4AF2F2F2FFFFFFFFFFFF303030232323
            2323232323232323232323232323232323232323232323232323232323232323
            2323232323232323232323232323232323232323232323232323232323232323
            23232323232323232323234C4C4CF2F2F2FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFE4E4E425252525252525252525252525252525
            25252525252525254E4E4EF2F2F2FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF27272727272727272727272727272727
            27272727274F4F4FF2F2F2FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF29292929292929292929292929292929
            2929515151F2F2F2FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B53
            5353F2F2F2FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF2D2D2D2D2D2D2D2D2D2D2D2D545454F2
            F2F2FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF2F2F2F2F2F2F2F2F2F565656F2F2F2FF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF313131313131575757F3F3F3FFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF333333595959F3F3F3FFFFFFFFFFFFFF
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
          TabOrder = 16
          OnClick = BitBtn1Click
        end
      end
      object PanelTitle: TPanel
        AlignWithMargins = True
        Left = 2
        Top = 0
        Width = 960
        Height = 41
        Margins.Left = 8
        Margins.Top = 8
        Margins.Right = 8
        BevelOuter = bvNone
        Caption = 'LOT END'
        Color = clGrayText
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clHighlightText
        Font.Height = -21
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentBackground = False
        ParentFont = False
        TabOrder = 1
        object SpeedButton11: TSpeedButton
          Left = 886
          Top = 0
          Width = 74
          Height = 42
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          Glyph.Data = {
            7A010000424D7A010000000000008A000000280000000E0000000F0000000100
            080000000000F000000012170000121700001500000015000000000000000808
            080010101000202020003030300048484800686868007F7F7F00606060009F9F
            9F0087878700B7B7B700BFBFBF00C7C7C700CFCFCF00D7D7D700DFDFDF00EFEF
            EF00E7E7E700F7F7F700FFFFFF00141414131414141414141413141400001414
            0805141414141414070411140000130500000814141414070000041100001305
            0000000814140A00000003100000141104000000070900000003101400001414
            1104000000000000020F14140000141414120300000000020E14141400001414
            14140900000000071414141400001414140C0100000000000914141400001414
            0E02000001020000000914140000140E020000010B0E020000000B1400001102
            0000000B14140E020000010E00001409000009141414140D0100061400001414
            09091414141414140B0A1414000014141414141414141414141414140000}
          ParentFont = False
          OnClick = SpeedButton11Click
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Rfid'
      ImageIndex = 1
      TabVisible = False
      object CurvyPanel6: TCurvyPanel
        Left = 0
        Top = -4
        Width = 962
        Height = 580
        Color = clBtnFace
        TabOrder = 0
        object Shape4: TShape
          Left = 10
          Top = 510
          Width = 943
          Height = 1
          Pen.Style = psDot
        end
        object Label15: TLabel
          Left = 50
          Top = 28
          Width = 722
          Height = 33
          Caption = 'RFID WRITE CYCLE FAIL! PLEASE MANUAL CHECK RFID FUNCTION!'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clRed
          Font.Height = -27
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object btnClose: TBitBtn
          Left = 746
          Top = 522
          Width = 167
          Height = 48
          Caption = 'CLOSE'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 0
          OnClick = btnManualCloseClick
        end
        object CurvyPanel7: TCurvyPanel
          Left = 50
          Top = 107
          Width = 682
          Height = 168
          TabOrder = 1
          object Label4: TLabel
            Left = 212
            Top = 16
            Width = 39
            Height = 18
            Caption = 'LOT ID'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'Calibri'
            Font.Style = []
            ParentFont = False
          end
          object Label5: TLabel
            Left = 212
            Top = 55
            Width = 54
            Height = 18
            Caption = 'PART NO'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'Calibri'
            Font.Style = []
            ParentFont = False
          end
          object Label7: TLabel
            Left = 212
            Top = 96
            Width = 24
            Height = 18
            Caption = 'QTY'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'Calibri'
            Font.Style = []
            ParentFont = False
          end
          object Label10: TLabel
            Left = 212
            Top = 134
            Width = 29
            Height = 18
            Caption = 'STEP'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'Calibri'
            Font.Style = []
            ParentFont = False
          end
          object Label12: TLabel
            Left = 20
            Top = 93
            Width = 66
            Height = 18
            Caption = 'RFID STATE'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'Calibri'
            Font.Style = []
            ParentFont = False
          end
          object Label13: TLabel
            Left = 20
            Top = 22
            Width = 87
            Height = 18
            Caption = 'RFID USE/SKIP'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'Calibri'
            Font.Style = []
            ParentFont = False
          end
          object rfidLotID: TCurvyEdit
            Left = 305
            Top = 7
            Width = 314
            Height = 34
            TabOrder = 0
            TabStop = False
            Version = '1.1.1.8'
            Controls = <>
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -19
            Font.Name = 'Calibri'
            Font.Style = []
            ImeName = 'Microsoft IME 2010'
            ParentFont = False
            ReadOnly = True
            Text = 'RUN'
          end
          object rfidPartNo: TCurvyEdit
            Left = 305
            Top = 47
            Width = 314
            Height = 34
            TabOrder = 1
            TabStop = False
            Version = '1.1.1.8'
            Controls = <>
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -19
            Font.Name = 'Calibri'
            Font.Style = []
            ImeName = 'Microsoft IME 2010'
            ParentFont = False
            ReadOnly = True
            Text = 'MZ7LN250HCHP-2BW00-G1'
          end
          object rfidQty: TCurvyEdit
            Left = 305
            Top = 87
            Width = 100
            Height = 34
            TabOrder = 2
            TabStop = False
            Version = '1.1.1.8'
            Controls = <>
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -19
            Font.Name = 'Calibri'
            Font.Style = [fsBold]
            ImeName = 'Microsoft IME 2010'
            ParentFont = False
            ReadOnly = True
            Text = '200'
            OnChange = eqInputCntChange
          end
          object rfidStep: TCurvyEdit
            Left = 305
            Top = 127
            Width = 100
            Height = 34
            TabOrder = 3
            TabStop = False
            Version = '1.1.1.8'
            Controls = <>
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -19
            Font.Name = 'Calibri'
            Font.Style = [fsBold]
            ImeName = 'Microsoft IME 2010'
            ParentFont = False
            ReadOnly = True
            Text = ''
          end
          object CurvyEditRfidState: TCurvyEdit
            Left = 20
            Top = 117
            Width = 159
            Height = 36
            Color = clMedGray
            TabOrder = 4
            TabStop = False
            Version = '1.1.1.8'
            Alignment = taCenter
            Controls = <>
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -21
            Font.Name = 'Calibri'
            Font.Style = [fsBold]
            ImeName = 'Microsoft IME 2010'
            ParentFont = False
            ReadOnly = True
            Text = 'RFID READY'
          end
          object CurvyEditRfidControl: TCurvyEdit
            Left = 20
            Top = 46
            Width = 159
            Height = 36
            Color = clMedGray
            TabOrder = 5
            TabStop = False
            Version = '1.1.1.8'
            Alignment = taCenter
            Controls = <>
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -21
            Font.Name = 'Calibri'
            Font.Style = [fsBold]
            ImeName = 'Microsoft IME 2010'
            ParentFont = False
            ReadOnly = True
            Text = 'RFID SKIP'
            OnDblClick = CurvyEditRfidControlDblClick
          end
        end
        object CurvyEdit8: TCurvyEdit
          Left = 50
          Top = 67
          Width = 187
          Height = 36
          TabOrder = 2
          TabStop = False
          Version = '1.1.1.8'
          Alignment = taCenter
          Controls = <>
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = 'Calibri'
          Font.Style = []
          ImeName = 'Microsoft IME 2010'
          ParentFont = False
          Text = 'CARRIER ID'
        end
        object rfidCarrierID: TCurvyEdit
          Left = 243
          Top = 67
          Width = 489
          Height = 36
          TabOrder = 3
          TabStop = False
          Version = '1.1.1.8'
          Alignment = taCenter
          Controls = <>
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ImeName = 'Microsoft IME 2010'
          ParentFont = False
          Text = 'CARRIER ID'
        end
        object btnRfidRead: TBitBtn
          Left = 746
          Top = 173
          Width = 167
          Height = 48
          Caption = 'RFID READ'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 4
          OnClick = btnRfidReadClick
        end
        object CurvyMemo1: TCurvyMemo
          Left = 50
          Top = 279
          Width = 682
          Height = 225
          TabOrder = 5
          TabStop = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ImeName = ''
          ParentFont = False
          ReadOnly = True
          ScrollBars = ssVertical
        end
        object btnRfidCycle: TBitBtn
          Left = 746
          Top = 119
          Width = 167
          Height = 48
          Caption = 'RFID WRITE CYCLE'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 6
          OnClick = btnRfidWriteClick
        end
      end
    end
  end
  object tmScrapInfo: TTimer
    Enabled = False
    Interval = 500
    OnTimer = tmScrapInfoTimer
    Left = 848
    Top = 248
  end
  object tmSeeLot: TTimer
    Enabled = False
    Interval = 500
    OnTimer = tmSeeLotTimer
    Left = 376
    Top = 272
  end
  object Timer3: TTimer
    Enabled = False
    Interval = 500
    OnTimer = Timer3Timer
    Left = 408
    Top = 528
  end
end
