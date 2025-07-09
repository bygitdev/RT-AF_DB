object frmPadSetup: TfrmPadSetup
  Left = 0
  Top = 0
  BorderStyle = bsNone
  Caption = 'frmPadSetup'
  ClientHeight = 1096
  ClientWidth = 1280
  Color = clBtnFace
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
    Width = 1280
    Height = 1096
    Align = alClient
    BevelOuter = bvNone
    Caption = 'Panel1'
    ParentBackground = False
    ShowCaption = False
    TabOrder = 0
    object Label9: TLabel
      AlignWithMargins = True
      Left = 17
      Top = 14
      Width = 187
      Height = 33
      Margins.Top = 30
      Margins.Bottom = 20
      Alignment = taCenter
      Caption = 'PAD TOOL SETUP'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -27
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object GroupBox1: TGroupBox
      Left = 41
      Top = 94
      Width = 576
      Height = 130
      Caption = 'PAD TYPE SETUP'
      Color = clBtnFace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Calibri'
      Font.Style = []
      ParentBackground = False
      ParentColor = False
      ParentFont = False
      TabOrder = 0
      object BtnSavePadType: TButton
        Left = 455
        Top = 40
        Width = 100
        Height = 74
        Caption = 'SAVE'
        Enabled = False
        TabOrder = 0
        OnClick = BtnSavePadTypeClick
      end
      object RadioButton1: TRadioButton
        Left = 40
        Top = 40
        Width = 113
        Height = 17
        Caption = 'SINGLE TYPE'
        TabOrder = 1
      end
      object RadioButton2: TRadioButton
        Left = 184
        Top = 40
        Width = 113
        Height = 17
        Caption = 'DUAL TYPE'
        TabOrder = 2
      end
      object RadioButton3: TRadioButton
        Left = 40
        Top = 88
        Width = 145
        Height = 17
        Caption = 'RF-DUAL TYPE'
        TabOrder = 3
      end
      object BtnInputPadType: TButton
        Left = 349
        Top = 40
        Width = 100
        Height = 74
        Caption = 'CHANGE'
        TabOrder = 4
        OnClick = BtnInputPadTypeClick
      end
      object RadioButton4: TRadioButton
        Left = 184
        Top = 88
        Width = 145
        Height = 17
        Caption = 'NO-TYPE'
        TabOrder = 5
      end
    end
    object GroupBox2: TGroupBox
      Left = 41
      Top = 407
      Width = 576
      Height = 186
      Caption = 'PAD OFFSET'
      Color = clBtnFace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Calibri'
      Font.Style = []
      ParentBackground = False
      ParentColor = False
      ParentFont = False
      TabOrder = 1
      object Label1: TLabel
        Left = 40
        Top = 51
        Width = 94
        Height = 23
        Caption = 'Pad Offset X'
      end
      object Label2: TLabel
        Left = 40
        Top = 88
        Width = 93
        Height = 23
        Caption = 'Pad Offset Y'
      end
      object BtnSavePadOffset: TButton
        Left = 453
        Top = 134
        Width = 100
        Height = 35
        Caption = 'SAVE'
        Enabled = False
        TabOrder = 0
        OnClick = BtnSavePadOffsetClick
      end
      object EditPadOffsetX: TEdit
        Left = 184
        Top = 48
        Width = 369
        Height = 31
        ReadOnly = True
        TabOrder = 1
        Text = 'EditPadOffsetX'
      end
      object EditPadOffsetY: TEdit
        Left = 184
        Top = 85
        Width = 369
        Height = 31
        ReadOnly = True
        TabOrder = 2
        Text = 'Edit1'
      end
      object BtnInputPadOffset: TButton
        Left = 347
        Top = 134
        Width = 100
        Height = 35
        Caption = 'INPUT'
        TabOrder = 3
        OnClick = BtnInputPadOffsetClick
      end
    end
    object GroupBox3: TGroupBox
      Left = 665
      Top = 94
      Width = 576
      Height = 283
      Caption = 'FLIPPER OFFSET'
      Color = clBtnFace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Calibri'
      Font.Style = []
      ParentBackground = False
      ParentColor = False
      ParentFont = False
      TabOrder = 2
      object Label3: TLabel
        Left = 31
        Top = 79
        Width = 184
        Height = 23
        Caption = 'Flip Top On PCB Offset X'
      end
      object Label4: TLabel
        Left = 31
        Top = 118
        Width = 183
        Height = 23
        Caption = 'Flip Top On PCB Offset Y'
      end
      object Label6: TLabel
        Left = 31
        Top = 157
        Width = 153
        Height = 23
        Caption = 'Flip Bottom Offset X'
      end
      object Label7: TLabel
        Left = 31
        Top = 196
        Width = 152
        Height = 23
        Caption = 'Flip Bottom Offset Y'
      end
      object lbl1: TLabel
        Left = 31
        Top = 30
        Width = 77
        Height = 23
        Caption = 'Flip Count'
      end
      object lbl2333: TLabel
        Left = 31
        Top = 46
        Width = 522
        Height = 23
        Caption = '__________________________________________________________'
        Color = clBtnFace
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clSilver
        Font.Height = -19
        Font.Name = 'Calibri'
        Font.Style = []
        ParentColor = False
        ParentFont = False
      end
      object BtnSaveFlipOffset: TButton
        Left = 454
        Top = 230
        Width = 100
        Height = 35
        Caption = 'SAVE'
        Enabled = False
        TabOrder = 0
        OnClick = BtnSaveFlipOffsetClick
      end
      object EditTopOffsetX: TEdit
        Left = 232
        Top = 78
        Width = 321
        Height = 31
        ReadOnly = True
        TabOrder = 1
        Text = 'Edit1'
      end
      object EditTopOffsetY: TEdit
        Left = 232
        Top = 115
        Width = 321
        Height = 31
        ReadOnly = True
        TabOrder = 2
        Text = 'Edit1'
      end
      object BtnInputFlipOffset: TButton
        Left = 348
        Top = 230
        Width = 100
        Height = 35
        Caption = 'INPUT'
        TabOrder = 3
        OnClick = BtnInputFlipOffsetClick
      end
      object EditBtmOffsetX: TEdit
        Left = 232
        Top = 154
        Width = 321
        Height = 31
        ReadOnly = True
        TabOrder = 4
        Text = 'Edit1'
      end
      object EditBtmOffsetY: TEdit
        Left = 232
        Top = 193
        Width = 321
        Height = 31
        ReadOnly = True
        TabOrder = 5
        Text = 'Edit1'
      end
      object EditFlipCount: TEdit
        Left = 232
        Top = 28
        Width = 321
        Height = 31
        ReadOnly = True
        TabOrder = 6
        Text = 'Edit1'
      end
    end
    object GroupBox4: TGroupBox
      Left = 41
      Top = 245
      Width = 576
      Height = 132
      Caption = 'PAD THETA'
      Color = clBtnFace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Calibri'
      Font.Style = []
      ParentBackground = False
      ParentColor = False
      ParentFont = False
      TabOrder = 3
      object Label5: TLabel
        Left = 40
        Top = 39
        Width = 76
        Height = 23
        Caption = 'Pad Theta'
      end
      object BtnSavePadTheta: TButton
        Left = 455
        Top = 81
        Width = 100
        Height = 35
        Caption = 'SAVE'
        Enabled = False
        TabOrder = 0
        OnClick = BtnSavePadThetaClick
      end
      object EditPadTheta: TEdit
        Left = 184
        Top = 36
        Width = 369
        Height = 31
        ReadOnly = True
        TabOrder = 1
        Text = 'Edit1'
      end
      object BtnInputPadTheta: TButton
        Left = 349
        Top = 81
        Width = 100
        Height = 35
        Caption = 'INPUT'
        TabOrder = 2
        OnClick = BtnInputPadThetaClick
      end
    end
    object GroupBox5: TGroupBox
      Left = 665
      Top = 407
      Width = 576
      Height = 283
      Caption = 'FLIPPER UNIT OFFSET'
      Color = clBtnFace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Calibri'
      Font.Style = []
      ParentBackground = False
      ParentColor = False
      ParentFont = False
      TabOrder = 4
      object Label10: TLabel
        Left = 40
        Top = 115
        Width = 199
        Height = 23
        Caption = 'Top To Btm Vision Offset X'
      end
      object Label11: TLabel
        Left = 40
        Top = 154
        Width = 198
        Height = 23
        Caption = 'Top To Btm Vision Offset Y'
      end
      object Label12: TLabel
        Left = 40
        Top = 193
        Width = 198
        Height = 23
        Caption = 'Top To Btm Vision Offset T'
      end
      object btnFilpUnitOffsetSave: TButton
        Left = 454
        Top = 232
        Width = 100
        Height = 35
        Caption = 'SAVE'
        Enabled = False
        TabOrder = 0
        OnClick = btnFilpUnitOffsetSaveClick
      end
      object EditFilpUnitOffset1: TEdit
        Left = 296
        Top = 112
        Width = 257
        Height = 31
        ReadOnly = True
        TabOrder = 1
        Text = 'Edit1'
      end
      object btnFilpUnitOffsetInput: TButton
        Left = 348
        Top = 232
        Width = 100
        Height = 35
        Caption = 'INPUT'
        TabOrder = 2
        OnClick = btnFilpUnitOffsetInputClick
      end
      object EditFilpUnitOffset2: TEdit
        Left = 296
        Top = 151
        Width = 257
        Height = 31
        ReadOnly = True
        TabOrder = 3
        Text = 'Edit1'
      end
      object EditFilpUnitOffset3: TEdit
        Left = 296
        Top = 188
        Width = 257
        Height = 31
        ReadOnly = True
        TabOrder = 4
        Text = 'Edit1'
      end
      object btnFilpUnit_1: TBitBtn
        Left = 49
        Top = 29
        Width = 225
        Height = 33
        Caption = 'UNIT_1(LEFT_TOP)'
        Enabled = False
        TabOrder = 5
        OnClick = btnFilpUnit_1Click
      end
      object btnFilpUnit_2: TBitBtn
        Tag = 1
        Left = 297
        Top = 29
        Width = 225
        Height = 33
        Caption = 'UNIT_2(RIGHT_TOP)'
        TabOrder = 6
        OnClick = btnFilpUnit_1Click
      end
      object btnFilpUnit_3: TBitBtn
        Tag = 2
        Left = 49
        Top = 68
        Width = 225
        Height = 33
        Caption = 'UNIT_3(LEFT_BTM)'
        TabOrder = 7
        OnClick = btnFilpUnit_1Click
      end
      object btnFilpUnit_4: TBitBtn
        Tag = 3
        Left = 297
        Top = 68
        Width = 225
        Height = 33
        Caption = 'UNIT_4(RIGHT_BTM)'
        TabOrder = 8
        OnClick = btnFilpUnit_1Click
      end
    end
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 1184
    Top = 480
  end
end
