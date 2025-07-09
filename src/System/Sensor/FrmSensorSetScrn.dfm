object FrmSensorSet: TFrmSensorSet
  Left = 0
  Top = 0
  BorderStyle = bsSizeToolWin
  Caption = 'SENSOR PART CONFIGURE'
  ClientHeight = 659
  ClientWidth = 372
  Color = clWindow
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object CurvyPanelSensorEdit: TCurvyPanel
    Left = 2
    Top = 4
    Width = 368
    Height = 654
    Rounding = 12
    TabOrder = 0
    object LMDButtonClose: TSpeedButton
      Left = 59
      Top = 598
      Width = 230
      Height = 43
      Caption = 'SAVE && CLOSE'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
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
    object SensorNameGrid: TStringGrid
      Left = 4
      Top = 62
      Width = 358
      Height = 530
      ColCount = 2
      DefaultRowHeight = 30
      RowCount = 17
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = #47569#51008' '#44256#46357
      Font.Style = [fsBold]
      Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
      ParentFont = False
      TabOrder = 0
      ColWidths = (
        64
        286)
    end
    object CurvyPanel2: TCurvyPanel
      Left = 4
      Top = 6
      Width = 358
      Height = 50
      Rounding = 12
      TabOrder = 1
      object IOChIndexLabel: TLabel
        Left = 20
        Top = 16
        Width = 93
        Height = 17
        Alignment = taCenter
        Caption = 'Input Channel '
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #47569#51008' '#44256#46357
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LMDComboBoxIndex: TComboBox
        Left = 119
        Top = 15
        Width = 228
        Height = 25
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #47569#51008' '#44256#46357
        Font.Style = [fsBold]
        ImeName = 'Microsoft IME 2010'
        ParentFont = False
        TabOrder = 0
        OnSelect = LMDComboBoxIndexSelect
      end
    end
  end
  object CurvyPanelSensorSet: TCurvyPanel
    Left = 477
    Top = 8
    Width = 369
    Height = 217
    Rounding = 12
    TabOrder = 1
    object BtnSensorNameView: TBitBtn
      Left = 23
      Top = 165
      Width = 146
      Height = 49
      Caption = 'BtnSensorNameView'
      TabOrder = 0
    end
  end
  object CurvyPanel1: TCurvyPanel
    Left = 422
    Top = 432
    Width = 358
    Height = 66
    Rounding = 12
    TabOrder = 2
    Visible = False
    object LabelChNotify: TLabel
      Left = 16
      Top = 3
      Width = 111
      Height = 17
      Alignment = taCenter
      Caption = 'Channel Selection'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = #47569#51008' '#44256#46357
      Font.Style = [fsBold]
      ParentFont = False
    end
  end
  object CurvyPanel3: TCurvyPanel
    Left = 416
    Top = 360
    Width = 358
    Height = 66
    Rounding = 12
    TabOrder = 3
    object Label1: TLabel
      Left = 18
      Top = 4
      Width = 122
      Height = 17
      Alignment = taCenter
      Caption = 'Sensor Active Color'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = #47569#51008' '#44256#46357
      Font.Style = [fsBold]
      ParentFont = False
    end
  end
  object LMDRadioButtonInput: TRadioButton
    Left = 403
    Top = 528
    Width = 113
    Height = 17
    Caption = 'INPUT'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = #47569#51008' '#44256#46357
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 4
    OnClick = LMDRadioButtonInputClick
  end
  object LMDRadioButtonOutput: TRadioButton
    Left = 598
    Top = 528
    Width = 113
    Height = 17
    Caption = 'OUTPUT'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = #47569#51008' '#44256#46357
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 5
  end
  object ColorDialog: TColorDialog
    CustomColors.Strings = (
      'ColorA=FFFFFFFF'
      'ColorB=FFFFFFFF'
      'ColorC=FFFFFFFF'
      'ColorD=FFFFFFFF'
      'ColorE=FFFFFFFF'
      'ColorF=FFFFFFFF'
      'ColorG=FFFFFFFF'
      'ColorH=FFFFFFFF'
      'ColorI=FFFFFFFF'
      'ColorJ=FFFFFFFF'
      'ColorK=FFFFFFFF'
      'ColorL=FFFFFFFF'
      'ColorM=FFFFFFFF'
      'ColorN=FFFFFFFF'
      'ColorO=FFFFFFFF'
      'ColorP=FFFFFFFF')
    Left = 480
    Top = 312
  end
end
