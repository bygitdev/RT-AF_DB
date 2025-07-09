object frmMain: TfrmMain
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'KAMELAS TESTCASE - KOSES'
  ClientHeight = 466
  ClientWidth = 286
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Arial'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 15
  object Button1: TButton
    Left = 16
    Top = 53
    Width = 75
    Height = 25
    Caption = 'Create'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 16
    Top = 24
    Width = 251
    Height = 23
    ImeName = 'Microsoft IME 2010'
    TabOrder = 1
    Text = 'MMI2SEQ'
  end
  object Button2: TButton
    Left = 192
    Top = 53
    Width = 75
    Height = 25
    Caption = 'Delete'
    TabOrder = 2
    OnClick = Button2Click
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 95
    Width = 273
    Height = 362
    TabOrder = 3
    object Button3: TButton
      Left = 152
      Top = 320
      Width = 107
      Height = 25
      Caption = 'Communicate'
      TabOrder = 0
      OnClick = Button3Click
    end
    object Button5: TButton
      Left = 184
      Top = 20
      Width = 75
      Height = 25
      Caption = 'Close'
      TabOrder = 1
      OnClick = Button5Click
    end
    object Button4: TButton
      Left = 8
      Top = 20
      Width = 75
      Height = 25
      Caption = 'Open'
      TabOrder = 2
      OnClick = Button4Click
    end
    object Memo1: TMemo
      Left = 8
      Top = 59
      Width = 251
      Height = 222
      ImeName = 'Microsoft IME 2010'
      ScrollBars = ssBoth
      TabOrder = 3
    end
    object Edit2: TEdit
      Left = 8
      Top = 287
      Width = 251
      Height = 23
      ImeName = 'Microsoft IME 2010'
      TabOrder = 4
      Text = 'TEST MESSAGE HELLO WORLD'
    end
  end
end
