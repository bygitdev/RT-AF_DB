object frmPopupNotice: TfrmPopupNotice
  Left = 0
  Top = 0
  BorderIcons = []
  BorderStyle = bsNone
  Caption = 'frmPopupNotice'
  ClientHeight = 379
  ClientWidth = 997
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Calibri'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poOwnerFormCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel3: TPanel
    Left = 0
    Top = 0
    Width = 997
    Height = 379
    Align = alClient
    BevelOuter = bvNone
    Caption = 'Panel3'
    Color = clGray
    ParentBackground = False
    TabOrder = 0
    object Panel2: TPanel
      Left = 0
      Top = 0
      Width = 997
      Height = 41
      Align = alTop
      BevelOuter = bvNone
      Caption = 'Panel2'
      TabOrder = 0
      object Panel1: TPanel
        AlignWithMargins = True
        Left = 3
        Top = 3
        Width = 950
        Height = 35
        Align = alClient
        BevelOuter = bvLowered
        Color = clPurple
        Font.Charset = ANSI_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentBackground = False
        ParentFont = False
        TabOrder = 0
        OnClick = Panel1Click
        object Label1: TLabel
          Left = 8
          Top = 6
          Width = 111
          Height = 23
          Caption = 'Title Message'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWhite
          Font.Height = -19
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentFont = False
        end
      end
      object btnButton: TButton
        Tag = 2
        AlignWithMargins = True
        Left = 959
        Top = 3
        Width = 35
        Height = 35
        Align = alRight
        Caption = 'X'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
        OnClick = btnButtonClick
      end
    end
    object GridPanel1: TGridPanel
      Left = 0
      Top = 320
      Width = 997
      Height = 59
      Align = alBottom
      BevelOuter = bvNone
      ColumnCollection = <
        item
          Value = 25.000000000000000000
        end
        item
          Value = 25.000000000000000000
        end
        item
          Value = 25.000000000000000000
        end
        item
          Value = 25.000000000000000000
        end>
      ControlCollection = <
        item
          Column = 0
          Control = Btn1
          Row = 0
        end
        item
          Column = 1
          Control = Btn2
          Row = 0
        end
        item
          Column = 2
          Control = Btn3
          Row = 0
        end
        item
          Column = 3
          Control = Btn4
          Row = 0
        end>
      RowCollection = <
        item
          Value = 100.000000000000000000
        end
        item
          SizeStyle = ssAuto
        end>
      ShowCaption = False
      TabOrder = 1
      object Btn1: TButton
        Tag = 2
        AlignWithMargins = True
        Left = 3
        Top = 3
        Width = 243
        Height = 53
        Align = alClient
        Caption = 'DONE'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -24
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        OnClick = Btn1Click
      end
      object Btn2: TButton
        Tag = 3
        AlignWithMargins = True
        Left = 252
        Top = 3
        Width = 243
        Height = 53
        Align = alClient
        Caption = 'DONE'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -24
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
        OnClick = Btn1Click
      end
      object Btn3: TButton
        Tag = 4
        AlignWithMargins = True
        Left = 501
        Top = 3
        Width = 243
        Height = 53
        Align = alClient
        Caption = 'DONE'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -24
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
        OnClick = Btn1Click
      end
      object Btn4: TButton
        Tag = 5
        AlignWithMargins = True
        Left = 750
        Top = 3
        Width = 244
        Height = 53
        Align = alClient
        Caption = 'DONE'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -24
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 3
        OnClick = Btn1Click
      end
    end
    object Panel4: TPanel
      AlignWithMargins = True
      Left = 3
      Top = 41
      Width = 991
      Height = 279
      Margins.Top = 0
      Margins.Bottom = 0
      Align = alClient
      Caption = 'Panel4'
      ParentBackground = False
      TabOrder = 2
      object lbText: TLabel
        AlignWithMargins = True
        Left = 4
        Top = 4
        Width = 983
        Height = 271
        Align = alClient
        Alignment = taCenter
        Caption = 'lbTest'#13#10'ABC'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -37
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = False
        Layout = tlCenter
        WordWrap = True
        ExplicitWidth = 91
        ExplicitHeight = 90
      end
    end
  end
  object tmrFlicker: TTimer
    Enabled = False
    OnTimer = tmrFlickerTimer
    Left = 960
    Top = 48
  end
end
