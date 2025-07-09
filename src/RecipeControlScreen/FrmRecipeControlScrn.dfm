object FrmRecipeControl: TFrmRecipeControl
  Left = 0
  Top = 0
  BorderStyle = bsNone
  ClientHeight = 433
  ClientWidth = 942
  Color = clSilver
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  DesignSize = (
    942
    433)
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 1
    Top = 8
    Width = 941
    Height = 417
    Color = clWhite
    ParentBackground = False
    TabOrder = 0
    DesignSize = (
      941
      417)
    object BtnRecipeControlUp: TSpeedButton
      Left = 887
      Top = 35
      Width = 40
      Height = 81
      Caption = #9650
      OnClick = BtnRecipeControlUpClick
    end
    object BtnRecipeControlDown: TSpeedButton
      Left = 887
      Top = 178
      Width = 40
      Height = 81
      Anchors = [akLeft, akBottom]
      Caption = ' '#9660' '
      OnClick = BtnRecipeControlDownClick
    end
    object Label6: TLabel
      Left = 16
      Top = 0
      Width = 122
      Height = 30
      Caption = 'Group Select'
      Color = 11257291
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = #47569#51008' '#44256#46357
      Font.Style = []
      ParentColor = False
      ParentFont = False
      Transparent = True
    end
    object Label1: TLabel
      Left = 379
      Top = 0
      Width = 125
      Height = 30
      Caption = 'Recipe Select'
      Color = 11257291
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = #47569#51008' '#44256#46357
      Font.Style = []
      ParentColor = False
      ParentFont = False
      Transparent = True
    end
    object RecipeControlGrid: TStringGrid
      Left = 379
      Top = 36
      Width = 502
      Height = 222
      ColCount = 3
      DefaultRowHeight = 30
      RowCount = 500
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Calibri'
      Font.Style = []
      ParentFont = False
      ScrollBars = ssVertical
      TabOrder = 0
      OnDblClick = RecipeControlGridDblClick
      OnDrawCell = RecipeControlGridDrawCell
      OnSelectCell = RecipeControlGridSelectCell
      ColWidths = (
        64
        349
        64)
    end
    object Panel2: TPanel
      Left = 2
      Top = 289
      Width = 925
      Height = 121
      BevelOuter = bvNone
      ParentBackground = False
      TabOrder = 1
      DesignSize = (
        925
        121)
      object LabelHandlerRCPSelect: TLabel
        Left = 351
        Top = 86
        Width = 82
        Height = 14
        Anchors = []
        Caption = 'SELECT RECIPE : '
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
      end
      object LabellLeftRecipe: TLabel
        Left = 307
        Top = 34
        Width = 95
        Height = 14
        Anchors = []
        Caption = 'CURRENT RECIPE : '
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
      end
      object BtnRecipeChange: TSpeedButton
        Left = 737
        Top = 54
        Width = 179
        Height = 62
        Caption = 'RECIPE CHANGE'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'Calibri'
        Font.Style = []
        Glyph.Data = {
          360C0000424D360C000000000000360000002800000020000000200000000100
          180000000000000C000012170000121700000000000000000000FFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFF7171710101010101010101010101010101010101
          0101010101010101010101010101010101010101010101010101010101010101
          0101010101010101010101717171FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFF6262620303030303030303030303030303030303030303
          0303030303030303030303030303030303030303030303030303030303030303
          0303030303030303030303030303626262FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFF6363630404040404040404040404040404040404040404040404
          0404040404040404040404040404040404040404040404040404040404040404
          0404040404040404040404040404040404636363FFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFF6464640606060606060606060606060606060606060606060606060606
          0606060606060606060606060606060606060606060606060606060606060606
          0606060606060606060606060606060606060606646464FFFFFFFFFFFFFFFFFF
          757575080808080808080808080808080808656565FFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFF656565080808080808080808080808080808757575FFFFFFFFFFFF
          090909090909090909090909090909666666FFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFF666666090909090909090909090909090909FFFFFFFFFFFF
          0B0B0B0B0B0B0B0B0B0B0B0B676767FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFF6767670B0B0B0B0B0B0B0B0B0B0B0BFFFFFFFFFFFF
          8686860C0C0C0C0C0C777777FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFF7777770C0C0C0C0C0C868686FFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFF0F0F0696969696969F0F0F0FFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFF1F1F13D3D3D1010101010103D3D3DF1F1F1FFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFF1F1F13E3E3E1111111111111111111111113E3E3EF1F1F1FFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1F1
          F1404040131313131313131313131313131313131313404040F1F1F1FFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1F1F14141
          41141414141414141414141414141414141414141414141414414141F1F1F1FF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1F1F14242421616
          16161616161616161616161616161616161616161616161616161616424242F1
          F1F1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1F1F14444441818181818
          1818181818181818181818181818181818181818181818181818181818181844
          4444F1F1F1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1F1F14545451919191919191919
          1919191919191919191919191919191919191919191919191919191919191919
          1919454545F1F1F1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1F1F14646461B1B1B1B1B1B1B1B1B1B1B
          1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B1B
          1B1B1B1B1B464646F1F1F1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFF1F1F14747471C1C1C1C1C1C1C1C1C1C1C1C1C1C
          1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C
          1C1C1C1C1C1C1C1C474747F1F1F1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFF1F1F14949491E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E
          1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E
          1E1E1E1E1E1E1E1E1E1E1E494949F1F1F1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFF2F2F24A4A4A1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F
          1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F
          1F1F1F1F1F1F1F1F1F1F1F1F1F1F4A4A4AF2F2F2FFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFF4B4B4B2121212121212121212121212121212121212121212121
          2121212121212121212121212121212121212121212121212121212121212121
          21212121212121212121212121212121214B4B4BFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFF2323232323232323232323232323232323232323232323232323
          2323232323232323232323232323232323232323232323232323232323232323
          2323232323232323232323232323232323232323FFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE4E4E42424
          24242424242424242424242424242424242424242424242424242424E4E4E4FF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF2626
          26262626262626262626262626262626262626262626262626262626FFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF2727
          27272727272727272727272727272727272727272727272727272727FFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF2929
          29292929292929292929292929292929292929292929292929292929FFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF2B2B
          2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2BFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF2C2C
          2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2CFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF2E2E
          2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2EFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF2F2F
          2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2FFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF3F3F33131
          31313131313131313131313131313131313131313131313131313131FFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF3F3F33F3F
          3F3333333333333333333333333333333333333333333333333F3F3FFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
        Layout = blGlyphTop
        ParentFont = False
        OnClick = BtnRecipeChangeClick
      end
      object Label2: TLabel
        Left = 11
        Top = 34
        Width = 97
        Height = 14
        Anchors = []
        Caption = 'CURRENT GROUP : '
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
      end
      object Label3: TLabel
        Left = 59
        Top = 86
        Width = 84
        Height = 14
        Anchors = []
        Caption = 'SELECT GROUP : '
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
      end
      object Label4: TLabel
        Left = 22
        Top = 82
        Width = 19
        Height = 19
        Anchors = []
        Caption = 'TO'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
      end
      object PanelSetRCP: TPanel
        Left = 408
        Top = 24
        Width = 280
        Height = 34
        Anchors = []
        Caption = '1'
        Color = clGray
        Font.Charset = ANSI_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Calibri'
        Font.Style = []
        ParentBackground = False
        ParentFont = False
        TabOrder = 0
      end
      object PanelSelectRecipe: TPanel
        Left = 439
        Top = 72
        Width = 280
        Height = 32
        Anchors = []
        Color = clGray
        Font.Charset = ANSI_CHARSET
        Font.Color = clRed
        Font.Height = -15
        Font.Name = 'Calibri'
        Font.Style = []
        ParentBackground = False
        ParentFont = False
        TabOrder = 1
      end
      object CheckBoxVisionConversionCommand: TCheckBox
        Left = 748
        Top = 8
        Width = 141
        Height = 17
        Caption = 'VISION JOB CHANGE'
        Checked = True
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
        State = cbChecked
        TabOrder = 2
      end
      object CheckBoxLaserConversionCommand: TCheckBox
        Left = 750
        Top = 31
        Width = 123
        Height = 17
        Caption = 'LASER JOB CHANGE'
        Checked = True
        Enabled = False
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
        State = cbChecked
        TabOrder = 3
      end
      object PanelSetGRP: TPanel
        Left = 112
        Top = 24
        Width = 180
        Height = 34
        Anchors = []
        Caption = '1'
        Color = clGray
        Font.Charset = ANSI_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Calibri'
        Font.Style = []
        ParentBackground = False
        ParentFont = False
        TabOrder = 4
      end
      object PanelSelectGroup: TPanel
        Left = 149
        Top = 72
        Width = 180
        Height = 32
        Anchors = []
        Color = clGray
        Font.Charset = ANSI_CHARSET
        Font.Color = clRed
        Font.Height = -15
        Font.Name = 'Calibri'
        Font.Style = []
        ParentBackground = False
        ParentFont = False
        TabOrder = 5
      end
    end
    object GroupControlGrid: TStringGrid
      Left = 16
      Top = 36
      Width = 345
      Height = 222
      ColCount = 2
      DefaultRowHeight = 30
      RowCount = 100
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Calibri'
      Font.Style = []
      ParentFont = False
      ScrollBars = ssVertical
      TabOrder = 2
      OnDblClick = GroupControlGridDblClick
      OnDrawCell = GroupControlGridDrawCell
      OnSelectCell = GroupControlGridSelectCell
      ColWidths = (
        64
        254)
    end
  end
  object PanelProgress: TPanel
    Left = 199
    Top = 153
    Width = 569
    Height = 73
    Anchors = [akLeft, akTop, akRight]
    Color = 11257291
    TabOrder = 1
    Visible = False
    DesignSize = (
      569
      73)
    object LabelProgress: TLabel
      Left = 253
      Top = 41
      Width = 102
      Height = 20
      Alignment = taCenter
      Anchors = [akLeft, akTop, akRight, akBottom]
      Caption = '0% Processing'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #47569#51008' '#44256#46357
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ConversionProgress: TProgressBar
      Left = 14
      Top = 10
      Width = 539
      Height = 25
      Anchors = [akLeft, akTop, akRight]
      Smooth = True
      TabOrder = 0
    end
  end
  object ProgressTimer: TTimer
    Enabled = False
    Interval = 10
    OnTimer = ProgressTimerTimer
    Left = 232
    Top = 16
  end
end
