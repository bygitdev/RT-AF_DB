object FrmRcpCreate: TFrmRcpCreate
  Left = 0
  Top = 0
  BorderIcons = []
  BorderStyle = bsNone
  Caption = 'FrmRcpCreate'
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
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object CurvyPanel1: TCurvyPanel
    AlignWithMargins = True
    Left = 5
    Top = 5
    Width = 1270
    Height = 770
    Margins.Left = 5
    Margins.Top = 5
    Margins.Right = 5
    Margins.Bottom = 5
    Align = alClient
    TabOrder = 0
    object GridPanel1: TGridPanel
      AlignWithMargins = True
      Left = 3
      Top = 3
      Width = 1264
      Height = 764
      Align = alClient
      BevelOuter = bvNone
      Caption = 'GridPanel1'
      Color = clWindow
      ColumnCollection = <
        item
          Value = 50.000000000000000000
        end
        item
          Value = 50.000000000000000000
        end>
      ControlCollection = <
        item
          Column = 0
          ColumnSpan = 2
          Control = CurvyPanel2
          Row = 1
        end
        item
          Column = 0
          Control = CurvyPanel3
          Row = 0
        end
        item
          Column = 1
          Control = CurvyPanel4
          Row = 0
        end>
      ParentBackground = False
      RowCollection = <
        item
          Value = 100.000000000000000000
        end
        item
          SizeStyle = ssAbsolute
          Value = 150.000000000000000000
        end>
      ShowCaption = False
      TabOrder = 0
      object CurvyPanel2: TCurvyPanel
        AlignWithMargins = True
        Left = 5
        Top = 619
        Width = 1254
        Height = 140
        Margins.Left = 5
        Margins.Top = 5
        Margins.Right = 5
        Margins.Bottom = 5
        Align = alClient
        Color = clSilver
        TabOrder = 0
        object Label1: TLabel
          Left = 33
          Top = 66
          Width = 54
          Height = 26
          Caption = 'FROM'
          Color = 11257291
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentColor = False
          ParentFont = False
          Transparent = True
        end
        object Label2: TLabel
          Left = 618
          Top = 66
          Width = 23
          Height = 26
          Caption = 'TO'
          Color = clBlue
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentColor = False
          ParentFont = False
          Transparent = True
        end
        object BtnRCPCopy: TSpeedButton
          Tag = 1
          Left = 1105
          Top = 63
          Width = 128
          Height = 42
          Caption = 'RECIPE COPY'
          Font.Charset = ANSI_CHARSET
          Font.Color = clNavy
          Font.Height = -16
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          Glyph.Data = {
            F6060000424DF606000000000000360000002800000018000000180000000100
            180000000000C006000012170000121700000000000000000000FFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFD0D0D0808080808080808080808080808080808080808080
            8080808080808080808080808080808080808080808080808080808080808080
            80D0D0D0FFFFFFFFFFFFFFFFFF72727203030303030303030303030303030303
            0303030303030303030303030303030303030303030303030303030303030303
            030303030303030303030303727272FFFFFF9292920505050505050505050505
            0505050505050505050505050505050505050505050505050505050505050505
            0505050505050505050505050505050505050505050505929292272727080808
            0808081818186565658383838383838383838383838383838383837474743636
            3608080808080808080808080808080808080808080808080808080808080827
            27270A0A0A0A0A0A0A0A0AB3B3B3FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFF3939390A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A
            0A0A0A0A0A0A0A0A0A0A0D0D0D0D0D0D0D0D0DFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF8686860D0D0D0D0D0D0D0D0D0D0D0D
            0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0F0F0F0F0F0F0F0F0FFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF8787870F0F0F0F
            0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F111111111111
            111111FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FF88888811111111111111111111111111111111111111111111111111111111
            1111141414141414141414FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFF8A8A8A1414141414141414141414141414141414141414
            14141414141414141414161616161616161616E2E2E2FFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF606060161616161616161616161616
            161616161616161616161616161616161616191919191919191919707070E3E3
            E3FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB8B8B828282819191919
            19191919191919191919191919191919191919191919191919191B1B1B1B1B1B
            1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B
            1B1B1B1B4646467171711B1B1B1B1B1B1B1B1B1B1B1B5555551B1B1B1B1B1B1B
            1B1B1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E
            1E1E1E1E1E1E1E1E1E2C2C2CF1F1F1FFFFFF7373731E1E1E1E1E1E1E1E1EB9B9
            B91E1E1E1E1E1E1E1E1E20202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020747474FFFFFFFFFFFF747474
            202020202020F1F1F12020202020202020202222222222222222222222222222
            2222222222222222222222222222222222222222222222222222222222222276
            7676FFFFFFFFFFFF7676764C4C4CFFFFFF222222222222222222252525252525
            2525252525252525252525252525252525252525252525252525252525252525
            25252525252525252525787878FFFFFFFFFFFFE4E4E4FFFFFF25252525252525
            2525272727272727272727272727272727272727272727272727272727272727
            272727272727272727272727272727272727272727868686FFFFFFFFFFFFFFFF
            FF2727272727272727272A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A
            2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A3838386D6D6DA2A2A2E5E5E5
            FFFFFFFFFFFFFFFFFF2A2A2A2A2A2A2A2A2A4747472C2C2C2C2C2C2C2C2C2C2C
            2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C96969696
            96969696969696969696969696966F6F6F2C2C2C2C2C2C474747A4A4A42F2F2F
            2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F
            2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2FA4
            A4A4FFFFFF8C8C8C313131313131313131313131313131313131313131313131
            3131313131313131313131313131313131313131313131313131313131313131
            313131318C8C8CFFFFFFFFFFFFFFFFFFD9D9D999999999999999999999999999
            9999999999999999999999999999999999999999999999999999999999999999
            999999999999999999D9D9D9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
          ParentFont = False
          OnClick = BtnRCPCopyClick
        end
        object SpeedButton1: TSpeedButton
          Left = 1105
          Top = 98
          Width = 146
          Height = 39
          Caption = 'CLOSE'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentFont = False
          Visible = False
          OnClick = SpeedButton1Click
        end
        object PanelOriginName: TPanel
          Left = 107
          Top = 64
          Width = 478
          Height = 36
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 0
        end
        object PanelNewName: TPanel
          Left = 652
          Top = 64
          Width = 438
          Height = 36
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 1
        end
        object Panel3: TPanel
          AlignWithMargins = True
          Left = 3
          Top = 3
          Width = 1248
          Height = 36
          Align = alTop
          BevelOuter = bvNone
          Color = clSilver
          ParentBackground = False
          TabOrder = 2
          object CheckRcpMotorfile: TCheckBox
            Left = 33
            Top = 17
            Width = 135
            Height = 17
            Caption = 'MOTOR FILE'
            Checked = True
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -16
            Font.Name = 'Calibri'
            Font.Style = []
            ParentFont = False
            State = cbChecked
            TabOrder = 0
          end
          object CheckRcpfile: TCheckBox
            Left = 240
            Top = 17
            Width = 185
            Height = 17
            Caption = 'PACKAGE PARAMETER'
            Checked = True
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -16
            Font.Name = 'Calibri'
            Font.Style = []
            ParentFont = False
            State = cbChecked
            TabOrder = 1
          end
        end
      end
      object CurvyPanel3: TCurvyPanel
        AlignWithMargins = True
        Left = 5
        Top = 5
        Width = 622
        Height = 604
        Margins.Left = 5
        Margins.Top = 5
        Margins.Right = 5
        Margins.Bottom = 5
        Align = alClient
        Color = clSilver
        TabOrder = 1
        DesignSize = (
          622
          604)
        object DownRCPGridCtrl: TSpeedButton
          Tag = 1
          Left = 558
          Top = 424
          Width = 50
          Height = 105
          Caption = #9660#13#10#9661
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -24
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = []
          ParentFont = False
          OnClick = DownRCPGridCtrlClick
        end
        object Label3: TLabel
          Left = 12
          Top = 97
          Width = 136
          Height = 23
          Caption = 'ORIGINAL RECIPE'
          Color = 11257291
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Calibri'
          Font.Style = []
          ParentColor = False
          ParentFont = False
          Transparent = True
        end
        object Label5: TLabel
          Left = 12
          Top = 7
          Width = 127
          Height = 26
          Caption = 'GROUP SELECT'
          Color = 11257291
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = 'Calibri'
          Font.Style = []
          ParentColor = False
          ParentFont = False
          Transparent = True
        end
        object UpRCPGridCtrl: TSpeedButton
          Tag = 1
          Left = 558
          Top = 126
          Width = 50
          Height = 105
          Caption = #9651#13#10#9650
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -24
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = []
          ParentFont = False
          OnClick = UpRCPGridCtrlClick
        end
        object GroupRCPComboBox: TComboBox
          Left = 112
          Top = 39
          Width = 496
          Height = 34
          Anchors = [akLeft, akTop, akRight]
          DropDownCount = 10
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = 'Calibri'
          Font.Style = []
          ImeName = 'Microsoft IME 2003'
          ParentFont = False
          TabOrder = 0
          OnChange = GroupRCPComboBoxChange
        end
        object OriginRCPGrid: TStringGrid
          Left = 12
          Top = 126
          Width = 540
          Height = 403
          BevelInner = bvNone
          BorderStyle = bsNone
          ColCount = 3
          Ctl3D = False
          DefaultColWidth = 50
          DefaultRowHeight = 32
          RowCount = 501
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Calibri'
          Font.Style = []
          Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goRowSelect]
          ParentCtl3D = False
          ParentFont = False
          ScrollBars = ssVertical
          TabOrder = 1
          OnDrawCell = OriginRCPGridDrawCell
          OnSelectCell = OriginRCPGridSelectCell
          ColWidths = (
            50
            392
            74)
        end
        object PanelGrpNo: TPanel
          Left = 12
          Top = 39
          Width = 86
          Height = 34
          Caption = '1'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = 'Calibri'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 2
        end
      end
      object CurvyPanel4: TCurvyPanel
        AlignWithMargins = True
        Left = 637
        Top = 5
        Width = 622
        Height = 604
        Margins.Left = 5
        Margins.Top = 5
        Margins.Right = 5
        Margins.Bottom = 5
        Align = alClient
        Color = clSilver
        TabOrder = 2
        DesignSize = (
          622
          604)
        object DownRCPGridCtrl2: TSpeedButton
          Tag = 1
          Left = 561
          Top = 424
          Width = 50
          Height = 105
          Caption = #9660#13#10#9661
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -24
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = []
          ParentFont = False
          OnClick = DownRCPGridCtrl2Click
        end
        object Label4: TLabel
          Left = 21
          Top = 97
          Width = 117
          Height = 23
          Caption = 'TARGET RECIPE'
          Color = 11257291
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Calibri'
          Font.Style = []
          ParentColor = False
          ParentFont = False
          Transparent = True
        end
        object UpRCPGridCtrl2: TSpeedButton
          Tag = 1
          Left = 560
          Top = 126
          Width = 50
          Height = 105
          Caption = #9651#13#10#9650
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -24
          Font.Name = #47569#51008' '#44256#46357
          Font.Style = []
          ParentFont = False
          OnClick = UpRCPGridCtrl2Click
        end
        object GroupTargetRCPComboBox: TComboBox
          Left = 105
          Top = 39
          Width = 505
          Height = 34
          Anchors = [akLeft, akTop, akRight]
          DropDownCount = 10
          Enabled = False
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = 'Calibri'
          Font.Style = []
          ImeName = 'Microsoft IME 2003'
          ParentFont = False
          TabOrder = 0
          OnChange = GroupTargetRCPComboBoxChange
        end
        object PanelTargetGrpNo: TPanel
          Left = 18
          Top = 39
          Width = 86
          Height = 34
          Caption = '1'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = 'Calibri'
          Font.Style = []
          ParentBackground = False
          ParentFont = False
          TabOrder = 1
        end
        object TargetRCPGrid: TStringGrid
          Left = 14
          Top = 126
          Width = 541
          Height = 402
          BevelInner = bvNone
          BorderStyle = bsNone
          ColCount = 3
          Ctl3D = False
          DefaultColWidth = 50
          DefaultRowHeight = 32
          RowCount = 501
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Calibri'
          Font.Style = []
          Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goRowSelect]
          ParentCtl3D = False
          ParentFont = False
          ScrollBars = ssVertical
          TabOrder = 2
          OnDrawCell = TargetRCPGridDrawCell
          OnSelectCell = TargetRCPGridSelectCell
          ColWidths = (
            50
            392
            74)
          RowHeights = (
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32
            32)
        end
        object Panel2: TPanel
          Left = 8
          Top = 3
          Width = 457
          Height = 30
          BevelOuter = bvNone
          Caption = 'Panel2'
          Color = clSilver
          ParentBackground = False
          ShowCaption = False
          TabOrder = 3
          object SameGrpCheckBox: TCheckBox
            Left = 11
            Top = 3
            Width = 238
            Height = 31
            Caption = 'Copy to same group '
            Checked = True
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -21
            Font.Name = 'Calibri'
            Font.Style = []
            ParentFont = False
            State = cbChecked
            TabOrder = 0
            OnClick = SameGrpCheckBoxClick
          end
        end
        object Panel1: TPanel
          Left = 14
          Top = 534
          Width = 571
          Height = 61
          BevelOuter = bvNone
          Color = clSilver
          ParentBackground = False
          TabOrder = 4
          DesignSize = (
            571
            61)
          object BtnInputItem: TSpeedButton
            Tag = 1
            Left = 15
            Top = 16
            Width = 162
            Height = 41
            Anchors = [akRight, akBottom]
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
            OnClick = BtnInputItemClick
          end
          object BtnSaveItem: TSpeedButton
            Tag = 1
            Left = 198
            Top = 16
            Width = 162
            Height = 41
            Anchors = [akRight, akBottom]
            Caption = 'SAVE DATA'
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
            OnClick = BtnSaveItemClick
          end
          object BtnDeleteItem: TSpeedButton
            Tag = 1
            Left = 379
            Top = 16
            Width = 162
            Height = 41
            Anchors = [akRight, akBottom]
            Caption = 'DELETE RECIPE'
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -12
            Font.Name = #47569#51008' '#44256#46357
            Font.Style = [fsBold]
            Glyph.Data = {
              E6040000424DE604000000000000360000002800000014000000140000000100
              180000000000B0040000C40E0000C40E00000000000000000000FFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDF
              DFDFB8B8B8B8B8B8E0E0E0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB8B8B82A2A2A0000
              000000002C2C2CBABABAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBA
              BABA7878786F6F6FD6D6D6FFFFFFFFFFFFDFDFDF2A2A2A0404049A9A9A989898
              0404042B2B2BE0E0E0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCACACA0707070000
              00020202CACACAFFFFFFFFFFFFB8B8B80000009A9A9AFFFFFFFFFFFF99999900
              0000B8B8B8FFFFFFFFFFFFFFFFFFFFFFFFCACACA111111000000080808B6B6B6
              FFFFFFFFFFFFFFFFFFB7B7B70000009B9B9BFFFFFFFFFFFF999999000000BEBE
              BEFFFFFFFFFFFFFFFFFFB6B6B6080808000000111111CACACAFFFFFFFFFFFFFF
              FFFFFFFFFFDEDEDE2828280606069B9B9B9A9A9A0D0D0D030303ABABABFFFFFF
              FFFFFFB5B5B5151515000000080808CACACAFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFB7B7B7282828000000000000010101000000181818C1C1C1C0C0C015
              1515000000151515B6B6B6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFDEDEDEB8B8B8BDBDBDA9A9A91616160000001717171717170000001515
              15B5B5B5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFC0C0C01616162323231B1B1B070707BBBBBBFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFC0C0C01616161F1F1F414141B1B1B1F0F0F0FFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDFDFDFB8B8B8BEBEBE
              AAAAAA171717000000070707B0B0B09494943D3D3DB0B0B0FFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB8B8B82A2A2A00000000000004040400
              0000171717BBBBBBF0F0F03E3E3E000000151515B6B6B6FFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFDFDFDF2A2A2A0404049898989797970B0B0B040404AAAA
              AAFFFFFFFFFFFFB0B0B0151515000000080808CACACAFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFB8B8B8000000999999FFFFFFFFFFFF979797000000BEBEBEFFFFFF
              FFFFFFFFFFFFB6B6B6080808000000111111CACACAFFFFFFFFFFFFFFFFFFFFFF
              FFB7B7B7000000999999FFFFFFFFFFFF999999000000B8B8B8FFFFFFFFFFFFFF
              FFFFFFFFFFCACACA111111000000080808B6B6B6FFFFFFFFFFFFFFFFFFDEDEDE
              2828280606069A9A9A9898980505052A2A2ADFDFDFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFCACACA070707000000020202CACACAFFFFFFFFFFFFFFFFFFB7B7B728
              2828000000000000292929B8B8B8FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFBABABA7878786F6F6FD6D6D6FFFFFFFFFFFFFFFFFFFFFFFFDEDEDEB7B7
              B7B8B8B8DFDFDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
              FFFFFFFFFFFFFFFFFFFF}
            ParentFont = False
            OnClick = BtnDeleteItemClick
          end
        end
      end
    end
  end
end
