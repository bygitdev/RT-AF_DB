object frmOht: TfrmOht
  Left = 0
  Top = 0
  BorderStyle = bsNone
  Caption = 'frmOht'
  ClientHeight = 535
  ClientWidth = 1034
  Color = clGray
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
  object Panel1: TPanel
    Left = 8
    Top = 8
    Width = 281
    Height = 417
    BevelOuter = bvNone
    Caption = 'Panel1'
    ParentBackground = False
    ShowCaption = False
    TabOrder = 0
    DesignSize = (
      281
      417)
    object Label3: TLabel
      Left = 87
      Top = 13
      Width = 107
      Height = 15
      Caption = 'LOADER PIO STATUS'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object btnOutputReset: TSpeedButton
      Tag = 1
      Left = 142
      Top = 367
      Width = 123
      Height = 34
      Caption = 'Output Reset'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentFont = False
      OnClick = btnOutputResetClick
    end
    object GridPanel1: TGridPanel
      AlignWithMargins = True
      Left = 16
      Top = 34
      Width = 249
      Height = 316
      Anchors = [akLeft, akTop, akRight, akBottom]
      BevelOuter = bvNone
      Color = clMedGray
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
          Control = PanelStatus1
          Row = 0
        end
        item
          Column = 1
          Control = Panel2
          Row = 0
        end
        item
          Column = 0
          Control = panPioInput0
          Row = 1
        end
        item
          Column = 1
          Control = panPioOutput0
          Row = 1
        end
        item
          Column = 0
          Control = panPioInput1
          Row = 2
        end
        item
          Column = 1
          Control = panPioOutput1
          Row = 2
        end
        item
          Column = 0
          Control = panPioInput2
          Row = 3
        end
        item
          Column = 1
          Control = panPioOutput2
          Row = 3
        end
        item
          Column = 0
          Control = panPioInput3
          Row = 4
        end
        item
          Column = 1
          Control = panPioOutput3
          Row = 4
        end
        item
          Column = 0
          Control = panPioInput4
          Row = 5
        end
        item
          Column = 1
          Control = panPioOutput4
          Row = 5
        end
        item
          Column = 0
          Control = panPioInput5
          Row = 6
        end
        item
          Column = 1
          Control = panPioOutput5
          Row = 6
        end
        item
          Column = 0
          Control = panPioInput6
          Row = 7
        end
        item
          Column = 1
          Control = panPioOutput6
          Row = 7
        end
        item
          Column = 0
          Control = panPioInput7
          Row = 8
        end
        item
          Column = 1
          Control = panPioOutput7
          Row = 8
        end>
      ParentBackground = False
      RowCollection = <
        item
          SizeStyle = ssAbsolute
          Value = 35.000000000000000000
        end
        item
          SizeStyle = ssAbsolute
          Value = 35.000000000000000000
        end
        item
          SizeStyle = ssAbsolute
          Value = 35.000000000000000000
        end
        item
          SizeStyle = ssAbsolute
          Value = 35.000000000000000000
        end
        item
          SizeStyle = ssAbsolute
          Value = 35.000000000000000000
        end
        item
          SizeStyle = ssAbsolute
          Value = 35.000000000000000000
        end
        item
          SizeStyle = ssAbsolute
          Value = 35.000000000000000000
        end
        item
          SizeStyle = ssAbsolute
          Value = 35.000000000000000000
        end
        item
          SizeStyle = ssAbsolute
          Value = 35.000000000000000000
        end>
      ShowCaption = False
      TabOrder = 0
      object PanelStatus1: TPanel
        AlignWithMargins = True
        Left = 2
        Top = 3
        Width = 120
        Height = 29
        Margins.Left = 2
        Margins.Right = 2
        Align = alClient
        BevelOuter = bvNone
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentBackground = False
        ParentFont = False
        ShowCaption = False
        TabOrder = 0
        ExplicitHeight = 30
        object Label1: TLabel
          AlignWithMargins = True
          Left = 3
          Top = 3
          Width = 114
          Height = 23
          Align = alClient
          Alignment = taCenter
          Caption = 'IN PUT'
          Color = clSilver
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentColor = False
          ParentFont = False
          Layout = tlCenter
          WordWrap = True
          ExplicitWidth = 36
          ExplicitHeight = 15
        end
      end
      object Panel2: TPanel
        AlignWithMargins = True
        Left = 126
        Top = 3
        Width = 121
        Height = 29
        Margins.Left = 2
        Margins.Right = 2
        Align = alClient
        BevelOuter = bvNone
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentBackground = False
        ParentFont = False
        ShowCaption = False
        TabOrder = 1
        ExplicitHeight = 30
        object Label2: TLabel
          AlignWithMargins = True
          Left = 3
          Top = 3
          Width = 115
          Height = 23
          Align = alClient
          Alignment = taCenter
          Caption = 'OUT PUT'
          Color = clSilver
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentColor = False
          ParentFont = False
          Layout = tlCenter
          WordWrap = True
          ExplicitWidth = 47
          ExplicitHeight = 15
        end
      end
      object panPioInput0: TPanel
        AlignWithMargins = True
        Left = 2
        Top = 38
        Width = 120
        Height = 29
        Margins.Left = 2
        Margins.Right = 2
        Align = alClient
        BevelOuter = bvNone
        Color = clGray
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentBackground = False
        ParentFont = False
        ShowCaption = False
        TabOrder = 2
        ExplicitTop = 39
        ExplicitHeight = 30
        object lblPioInput0: TLabel
          Tag = 8
          AlignWithMargins = True
          Left = 3
          Top = 3
          Width = 114
          Height = 23
          Align = alClient
          Alignment = taCenter
          Caption = 'VAL ID'
          Color = clGray
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -13
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentColor = False
          ParentFont = False
          Layout = tlCenter
          WordWrap = True
          ExplicitWidth = 35
          ExplicitHeight = 15
        end
      end
      object panPioOutput0: TPanel
        AlignWithMargins = True
        Left = 126
        Top = 38
        Width = 121
        Height = 29
        Margins.Left = 2
        Margins.Right = 2
        Align = alClient
        BevelOuter = bvNone
        Color = clGray
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentBackground = False
        ParentFont = False
        ShowCaption = False
        TabOrder = 3
        ExplicitTop = 39
        ExplicitHeight = 30
        object lblPioOutput0: TLabel
          Tag = 8
          AlignWithMargins = True
          Left = 3
          Top = 3
          Width = 115
          Height = 23
          Align = alClient
          Alignment = taCenter
          Caption = 'L-REQ'
          Color = clSilver
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -13
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentColor = False
          ParentFont = False
          Layout = tlCenter
          WordWrap = True
          OnDblClick = lblPioOutput0DblClick
          ExplicitWidth = 32
          ExplicitHeight = 15
        end
      end
      object panPioInput1: TPanel
        AlignWithMargins = True
        Left = 2
        Top = 73
        Width = 120
        Height = 29
        Margins.Left = 2
        Margins.Right = 2
        Align = alClient
        BevelOuter = bvNone
        Color = clGray
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentBackground = False
        ParentFont = False
        ShowCaption = False
        TabOrder = 4
        ExplicitTop = 75
        ExplicitHeight = 30
        object lblPioInput1: TLabel
          Tag = 9
          AlignWithMargins = True
          Left = 3
          Top = 3
          Width = 114
          Height = 23
          Align = alClient
          Alignment = taCenter
          Caption = 'CS0'
          Color = clSilver
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -13
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentColor = False
          ParentFont = False
          Layout = tlCenter
          WordWrap = True
          ExplicitWidth = 20
          ExplicitHeight = 15
        end
      end
      object panPioOutput1: TPanel
        AlignWithMargins = True
        Left = 126
        Top = 73
        Width = 121
        Height = 29
        Margins.Left = 2
        Margins.Right = 2
        Align = alClient
        BevelOuter = bvNone
        Color = clGray
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentBackground = False
        ParentFont = False
        ShowCaption = False
        TabOrder = 5
        ExplicitTop = 75
        ExplicitHeight = 30
        object lblPioOutput1: TLabel
          Tag = 9
          AlignWithMargins = True
          Left = 3
          Top = 3
          Width = 115
          Height = 23
          Align = alClient
          Alignment = taCenter
          Caption = 'U-REQ'
          Color = clSilver
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -13
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentColor = False
          ParentFont = False
          Layout = tlCenter
          WordWrap = True
          OnDblClick = lblPioOutput0DblClick
          ExplicitWidth = 34
          ExplicitHeight = 15
        end
      end
      object panPioInput2: TPanel
        AlignWithMargins = True
        Left = 2
        Top = 108
        Width = 120
        Height = 29
        Margins.Left = 2
        Margins.Right = 2
        Align = alClient
        BevelOuter = bvNone
        Color = clGray
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentBackground = False
        ParentFont = False
        ShowCaption = False
        TabOrder = 6
        ExplicitTop = 111
        ExplicitHeight = 30
        object lblPioInput2: TLabel
          Tag = 10
          AlignWithMargins = True
          Left = 3
          Top = 3
          Width = 114
          Height = 23
          Align = alClient
          Alignment = taCenter
          Caption = 'CS1'
          Color = clSilver
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -13
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentColor = False
          ParentFont = False
          Layout = tlCenter
          WordWrap = True
          ExplicitWidth = 20
          ExplicitHeight = 15
        end
      end
      object panPioOutput2: TPanel
        AlignWithMargins = True
        Left = 126
        Top = 108
        Width = 121
        Height = 29
        Margins.Left = 2
        Margins.Right = 2
        Align = alClient
        BevelOuter = bvNone
        Color = clGray
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentBackground = False
        ParentFont = False
        ShowCaption = False
        TabOrder = 7
        ExplicitTop = 111
        ExplicitHeight = 30
        object lblPioOutput2: TLabel
          Tag = 10
          AlignWithMargins = True
          Left = 3
          Top = 3
          Width = 115
          Height = 23
          Align = alClient
          Alignment = taCenter
          Caption = 'ABORT'
          Color = clSilver
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -13
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentColor = False
          ParentFont = False
          Layout = tlCenter
          WordWrap = True
          OnDblClick = lblPioOutput0DblClick
          ExplicitWidth = 37
          ExplicitHeight = 15
        end
      end
      object panPioInput3: TPanel
        AlignWithMargins = True
        Left = 2
        Top = 143
        Width = 120
        Height = 29
        Margins.Left = 2
        Margins.Right = 2
        Align = alClient
        BevelOuter = bvNone
        Color = clGray
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentBackground = False
        ParentFont = False
        ShowCaption = False
        TabOrder = 8
        ExplicitTop = 147
        ExplicitHeight = 30
        object lblPioInput3: TLabel
          Tag = 11
          AlignWithMargins = True
          Left = 3
          Top = 3
          Width = 114
          Height = 23
          Align = alClient
          Alignment = taCenter
          Caption = 'CS2'
          Color = clSilver
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -13
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentColor = False
          ParentFont = False
          Layout = tlCenter
          WordWrap = True
          ExplicitWidth = 20
          ExplicitHeight = 15
        end
      end
      object panPioOutput3: TPanel
        AlignWithMargins = True
        Left = 126
        Top = 143
        Width = 121
        Height = 29
        Margins.Left = 2
        Margins.Right = 2
        Align = alClient
        BevelOuter = bvNone
        Color = clGray
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentBackground = False
        ParentFont = False
        ShowCaption = False
        TabOrder = 9
        ExplicitTop = 147
        ExplicitHeight = 30
        object lblPioOutput3: TLabel
          Tag = 11
          AlignWithMargins = True
          Left = 3
          Top = 3
          Width = 115
          Height = 23
          Align = alClient
          Alignment = taCenter
          Caption = 'READY'
          Color = clSilver
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -13
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentColor = False
          ParentFont = False
          Layout = tlCenter
          WordWrap = True
          OnDblClick = lblPioOutput0DblClick
          ExplicitWidth = 36
          ExplicitHeight = 15
        end
      end
      object panPioInput4: TPanel
        AlignWithMargins = True
        Left = 2
        Top = 178
        Width = 120
        Height = 29
        Margins.Left = 2
        Margins.Right = 2
        Align = alClient
        BevelOuter = bvNone
        Color = clGray
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentBackground = False
        ParentFont = False
        ShowCaption = False
        TabOrder = 10
        ExplicitTop = 183
        ExplicitHeight = 30
        object lblPioInput4: TLabel
          Tag = 12
          AlignWithMargins = True
          Left = 3
          Top = 3
          Width = 114
          Height = 23
          Align = alClient
          Alignment = taCenter
          Caption = 'CS3'
          Color = clSilver
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -13
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentColor = False
          ParentFont = False
          Layout = tlCenter
          WordWrap = True
          ExplicitWidth = 20
          ExplicitHeight = 15
        end
      end
      object panPioOutput4: TPanel
        AlignWithMargins = True
        Left = 126
        Top = 178
        Width = 121
        Height = 29
        Margins.Left = 2
        Margins.Right = 2
        Align = alClient
        BevelOuter = bvNone
        Color = clGray
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentBackground = False
        ParentFont = False
        ShowCaption = False
        TabOrder = 11
        ExplicitTop = 183
        ExplicitHeight = 30
        object lblPioOutput4: TLabel
          Tag = 12
          AlignWithMargins = True
          Left = 3
          Top = 3
          Width = 115
          Height = 23
          Align = alClient
          Alignment = taCenter
          Caption = 'N/C'
          Color = clSilver
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -13
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentColor = False
          ParentFont = False
          Layout = tlCenter
          WordWrap = True
          ExplicitWidth = 22
          ExplicitHeight = 15
        end
      end
      object panPioInput5: TPanel
        AlignWithMargins = True
        Left = 2
        Top = 213
        Width = 120
        Height = 29
        Margins.Left = 2
        Margins.Right = 2
        Align = alClient
        BevelOuter = bvNone
        Color = clGray
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentBackground = False
        ParentFont = False
        ShowCaption = False
        TabOrder = 12
        ExplicitTop = 219
        ExplicitHeight = 30
        object lblPioInput5: TLabel
          Tag = 13
          AlignWithMargins = True
          Left = 3
          Top = 3
          Width = 114
          Height = 23
          Align = alClient
          Alignment = taCenter
          Caption = 'TR-REQ'
          Color = clSilver
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -13
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentColor = False
          ParentFont = False
          Layout = tlCenter
          WordWrap = True
          ExplicitWidth = 39
          ExplicitHeight = 15
        end
      end
      object panPioOutput5: TPanel
        AlignWithMargins = True
        Left = 126
        Top = 213
        Width = 121
        Height = 29
        Margins.Left = 2
        Margins.Right = 2
        Align = alClient
        BevelOuter = bvNone
        Color = clGray
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentBackground = False
        ParentFont = False
        ShowCaption = False
        TabOrder = 13
        ExplicitTop = 219
        ExplicitHeight = 30
        object lblPioOutput5: TLabel
          Tag = 13
          AlignWithMargins = True
          Left = 3
          Top = 3
          Width = 115
          Height = 23
          Align = alClient
          Alignment = taCenter
          Caption = 'N/C'
          Color = clSilver
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -13
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentColor = False
          ParentFont = False
          Layout = tlCenter
          WordWrap = True
          ExplicitWidth = 22
          ExplicitHeight = 15
        end
      end
      object panPioInput6: TPanel
        AlignWithMargins = True
        Left = 2
        Top = 248
        Width = 120
        Height = 29
        Margins.Left = 2
        Margins.Right = 2
        Align = alClient
        BevelOuter = bvNone
        Color = clGray
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentBackground = False
        ParentFont = False
        ShowCaption = False
        TabOrder = 14
        ExplicitTop = 255
        ExplicitHeight = 30
        object lblPioInput6: TLabel
          Tag = 14
          AlignWithMargins = True
          Left = 3
          Top = 3
          Width = 114
          Height = 23
          Align = alClient
          Alignment = taCenter
          Caption = 'BUSY'
          Color = clSilver
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -13
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentColor = False
          ParentFont = False
          Layout = tlCenter
          WordWrap = True
          ExplicitWidth = 28
          ExplicitHeight = 15
        end
      end
      object panPioOutput6: TPanel
        AlignWithMargins = True
        Left = 126
        Top = 248
        Width = 121
        Height = 29
        Margins.Left = 2
        Margins.Right = 2
        Align = alClient
        BevelOuter = bvNone
        Color = clGray
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentBackground = False
        ParentFont = False
        ShowCaption = False
        TabOrder = 15
        ExplicitTop = 255
        ExplicitHeight = 30
        object lblPioOutput6: TLabel
          Tag = 14
          AlignWithMargins = True
          Left = 3
          Top = 3
          Width = 115
          Height = 23
          Align = alClient
          Alignment = taCenter
          Caption = 'N/C'
          Color = clSilver
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -13
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentColor = False
          ParentFont = False
          Layout = tlCenter
          WordWrap = True
          ExplicitWidth = 22
          ExplicitHeight = 15
        end
      end
      object panPioInput7: TPanel
        AlignWithMargins = True
        Left = 2
        Top = 283
        Width = 120
        Height = 29
        Margins.Left = 2
        Margins.Right = 2
        Align = alClient
        BevelOuter = bvNone
        Color = clGray
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentBackground = False
        ParentFont = False
        ShowCaption = False
        TabOrder = 16
        ExplicitTop = 291
        ExplicitHeight = 33
        object lblPioInput7: TLabel
          Tag = 15
          AlignWithMargins = True
          Left = 3
          Top = 3
          Width = 114
          Height = 23
          Align = alClient
          Alignment = taCenter
          Caption = 'COMP'
          Color = clSilver
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -13
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentColor = False
          ParentFont = False
          Layout = tlCenter
          WordWrap = True
          ExplicitWidth = 34
          ExplicitHeight = 15
        end
      end
      object panPioOutput7: TPanel
        AlignWithMargins = True
        Left = 126
        Top = 283
        Width = 121
        Height = 29
        Margins.Left = 2
        Margins.Right = 2
        Align = alClient
        BevelOuter = bvNone
        Color = clGray
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentBackground = False
        ParentFont = False
        ShowCaption = False
        TabOrder = 17
        ExplicitTop = 291
        ExplicitHeight = 33
        object lblPioOutput7: TLabel
          Tag = 15
          AlignWithMargins = True
          Left = 3
          Top = 3
          Width = 115
          Height = 23
          Align = alClient
          Alignment = taCenter
          Caption = 'N/C'
          Color = clSilver
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -13
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentColor = False
          ParentFont = False
          Layout = tlCenter
          WordWrap = True
          ExplicitWidth = 22
          ExplicitHeight = 15
        end
      end
    end
  end
  object Panel5: TPanel
    Left = 8
    Top = 431
    Width = 281
    Height = 98
    BevelOuter = bvNone
    Caption = 'Panel1'
    ParentBackground = False
    ShowCaption = False
    TabOrder = 1
    DesignSize = (
      281
      98)
    object Label4: TLabel
      Left = 108
      Top = 13
      Width = 65
      Height = 15
      Caption = 'RFID STATUS'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object GridPanel2: TGridPanel
      AlignWithMargins = True
      Left = 16
      Top = 34
      Width = 249
      Height = 39
      Anchors = [akLeft, akTop, akRight, akBottom]
      BevelOuter = bvNone
      Color = clMedGray
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
          Control = panNDM0
          Row = 0
        end
        item
          Column = 1
          Control = panNDM1
          Row = 0
        end>
      ParentBackground = False
      RowCollection = <
        item
          Value = 100.000000000000000000
        end>
      ShowCaption = False
      TabOrder = 0
      object panNDM0: TPanel
        AlignWithMargins = True
        Left = 2
        Top = 3
        Width = 120
        Height = 33
        Margins.Left = 2
        Margins.Right = 2
        Align = alClient
        BevelOuter = bvNone
        Color = clGray
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentBackground = False
        ParentFont = False
        ShowCaption = False
        TabOrder = 0
        ExplicitLeft = 4
        ExplicitTop = 0
        ExplicitHeight = 47
        object lblNDM0: TLabel
          Tag = 254
          AlignWithMargins = True
          Left = 3
          Top = 3
          Width = 114
          Height = 27
          Align = alClient
          Alignment = taCenter
          Caption = 'READ'
          Color = clGray
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -13
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentColor = False
          ParentFont = False
          Layout = tlCenter
          WordWrap = True
          ExplicitTop = 6
          ExplicitWidth = 88
          ExplicitHeight = 38
        end
      end
      object panNDM1: TPanel
        AlignWithMargins = True
        Left = 126
        Top = 3
        Width = 121
        Height = 33
        Margins.Left = 2
        Margins.Right = 2
        Align = alClient
        BevelOuter = bvNone
        Color = clGray
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentBackground = False
        ParentFont = False
        ShowCaption = False
        TabOrder = 1
        ExplicitLeft = 128
        ExplicitTop = 6
        ExplicitHeight = 47
        object lblNDM1: TLabel
          Tag = 255
          AlignWithMargins = True
          Left = 3
          Top = 3
          Width = 115
          Height = 27
          Align = alClient
          Alignment = taCenter
          Caption = 'WRITE'
          Color = clGray
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -13
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentColor = False
          ParentFont = False
          Layout = tlCenter
          WordWrap = True
          ExplicitWidth = 34
          ExplicitHeight = 15
        end
      end
    end
  end
  object Panel3: TPanel
    Left = 295
    Top = 8
    Width = 281
    Height = 147
    BevelOuter = bvNone
    Caption = 'Panel1'
    ParentBackground = False
    ShowCaption = False
    TabOrder = 2
    DesignSize = (
      281
      147)
    object Label5: TLabel
      Left = 87
      Top = 13
      Width = 99
      Height = 15
      Caption = 'OHT SETTING TIME'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object GridPanel3: TGridPanel
      AlignWithMargins = True
      Left = 16
      Top = 34
      Width = 249
      Height = 106
      Anchors = [akLeft, akTop, akRight, akBottom]
      BevelOuter = bvNone
      Color = clMedGray
      ColumnCollection = <
        item
          Value = 100.000000000000000000
        end>
      ControlCollection = <
        item
          Column = 0
          Control = GridPanel7
          Row = 2
        end
        item
          Column = 0
          Control = GridPanel4
          Row = 0
        end
        item
          Column = 0
          Control = GridPanel5
          Row = 1
        end>
      ParentBackground = False
      RowCollection = <
        item
          SizeStyle = ssAbsolute
          Value = 35.000000000000000000
        end
        item
          SizeStyle = ssAbsolute
          Value = 35.000000000000000000
        end
        item
          SizeStyle = ssAbsolute
          Value = 35.000000000000000000
        end>
      ShowCaption = False
      TabOrder = 0
      ExplicitHeight = 162
      object GridPanel7: TGridPanel
        AlignWithMargins = True
        Left = 3
        Top = 73
        Width = 243
        Height = 29
        Align = alClient
        BevelOuter = bvNone
        Caption = 'GridPanel2'
        Color = clInactiveCaptionText
        ColumnCollection = <
          item
            SizeStyle = ssAbsolute
            Value = 180.000000000000000000
          end
          item
            Value = 100.000000000000000000
          end>
        ControlCollection = <
          item
            Column = 0
            Control = Panel8
            Row = 0
          end
          item
            Column = 1
            Control = panDDM2
            Row = 0
          end>
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentBackground = False
        ParentFont = False
        RowCollection = <
          item
            Value = 100.000000000000000000
          end>
        ShowCaption = False
        TabOrder = 0
        ExplicitLeft = 6
        ExplicitTop = 11
        ExplicitWidth = 185
        ExplicitHeight = 0
        object Panel8: TPanel
          Left = 0
          Top = 0
          Width = 180
          Height = 29
          Align = alClient
          BevelOuter = bvNone
          Caption = 'PIO SAFETY WAIT TIME (sec)'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -13
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 0
        end
        object panDDM2: TPanel
          Tag = 152
          AlignWithMargins = True
          Left = 183
          Top = 3
          Width = 57
          Height = 23
          Align = alClient
          BevelOuter = bvNone
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 1
        end
      end
      object GridPanel4: TGridPanel
        AlignWithMargins = True
        Left = 3
        Top = 3
        Width = 243
        Height = 29
        Align = alClient
        BevelOuter = bvNone
        Caption = 'GridPanel2'
        Color = clInactiveCaptionText
        ColumnCollection = <
          item
            SizeStyle = ssAbsolute
            Value = 180.000000000000000000
          end
          item
            Value = 100.000000000000000000
          end>
        ControlCollection = <
          item
            Column = 0
            Control = Panel4
            Row = 0
          end
          item
            Column = 1
            Control = panDDM0
            Row = 0
          end>
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentBackground = False
        ParentFont = False
        RowCollection = <
          item
            Value = 100.000000000000000000
          end>
        ShowCaption = False
        TabOrder = 1
        ExplicitLeft = 6
        ExplicitTop = 11
        object Panel4: TPanel
          Left = 0
          Top = 0
          Width = 180
          Height = 29
          Align = alClient
          BevelOuter = bvNone
          Caption = 'EMPTY LOT END WAIT TIME (sec)'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -13
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 0
        end
        object panDDM0: TPanel
          Tag = 150
          AlignWithMargins = True
          Left = 183
          Top = 3
          Width = 57
          Height = 23
          Align = alClient
          BevelOuter = bvNone
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 1
        end
      end
      object GridPanel5: TGridPanel
        AlignWithMargins = True
        Left = 3
        Top = 38
        Width = 243
        Height = 29
        Align = alClient
        BevelOuter = bvNone
        Caption = 'GridPanel2'
        Color = clInactiveCaptionText
        ColumnCollection = <
          item
            SizeStyle = ssAbsolute
            Value = 180.000000000000000000
          end
          item
            Value = 100.000000000000000000
          end>
        ControlCollection = <
          item
            Column = 0
            Control = Panel6
            Row = 0
          end
          item
            Column = 1
            Control = panDDM1
            Row = 0
          end>
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentBackground = False
        ParentFont = False
        RowCollection = <
          item
            Value = 100.000000000000000000
          end>
        ShowCaption = False
        TabOrder = 2
        ExplicitLeft = 6
        ExplicitTop = 11
        ExplicitWidth = 185
        ExplicitHeight = 0
        object Panel6: TPanel
          Left = 0
          Top = 0
          Width = 180
          Height = 29
          Align = alClient
          BevelOuter = bvNone
          Caption = 'RETRY CALL WAIT TIME (sec)'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -13
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 0
          ExplicitHeight = 36
        end
        object panDDM1: TPanel
          Tag = 151
          AlignWithMargins = True
          Left = 183
          Top = 3
          Width = 57
          Height = 23
          Align = alClient
          BevelOuter = bvNone
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentBackground = False
          ParentFont = False
          TabOrder = 1
          ExplicitHeight = 30
        end
      end
    end
  end
  object Panel7: TPanel
    Left = 295
    Top = 161
    Width = 281
    Height = 147
    BevelOuter = bvNone
    Caption = 'Panel1'
    ParentBackground = False
    ShowCaption = False
    TabOrder = 3
    DesignSize = (
      281
      147)
    object Label6: TLabel
      Left = 103
      Top = 13
      Width = 75
      Height = 15
      Caption = 'OHT USE/SKIP'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object GridPanel6: TGridPanel
      AlignWithMargins = True
      Left = 16
      Top = 34
      Width = 249
      Height = 106
      Anchors = [akLeft, akTop, akRight, akBottom]
      BevelOuter = bvNone
      Color = clMedGray
      ColumnCollection = <
        item
          Value = 100.000000000000000000
        end>
      ControlCollection = <
        item
          Column = 0
          Control = panUSESKIP0
          Row = 0
        end
        item
          Column = 0
          Control = panUSESKIP1
          Row = 1
        end
        item
          Column = 0
          Control = panUSESKIP2
          Row = 2
        end>
      ParentBackground = False
      RowCollection = <
        item
          SizeStyle = ssAbsolute
          Value = 35.000000000000000000
        end
        item
          SizeStyle = ssAbsolute
          Value = 35.000000000000000000
        end
        item
          SizeStyle = ssAbsolute
          Value = 35.000000000000000000
        end>
      ShowCaption = False
      TabOrder = 0
      ExplicitHeight = 130
      object panUSESKIP0: TPanel
        AlignWithMargins = True
        Left = 2
        Top = 3
        Width = 245
        Height = 29
        Margins.Left = 2
        Margins.Right = 2
        Align = alClient
        BevelOuter = bvNone
        Color = clGray
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentBackground = False
        ParentFont = False
        ShowCaption = False
        TabOrder = 0
        ExplicitWidth = 120
        ExplicitHeight = 33
        object lblUSESKIP0: TLabel
          Tag = 3
          AlignWithMargins = True
          Left = 3
          Top = 3
          Width = 239
          Height = 23
          Align = alClient
          Alignment = taCenter
          Caption = 'OHT MODE'
          Color = clGray
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -13
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentColor = False
          ParentFont = False
          Layout = tlCenter
          WordWrap = True
          ExplicitTop = 6
        end
      end
      object panUSESKIP1: TPanel
        AlignWithMargins = True
        Left = 2
        Top = 38
        Width = 245
        Height = 29
        Margins.Left = 2
        Margins.Right = 2
        Align = alClient
        BevelOuter = bvNone
        Color = clGray
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentBackground = False
        ParentFont = False
        ShowCaption = False
        TabOrder = 1
        ExplicitLeft = 32
        ExplicitWidth = 120
        ExplicitHeight = 33
        object lblUSESKIP1: TLabel
          Tag = 4
          AlignWithMargins = True
          Left = 3
          Top = 3
          Width = 239
          Height = 23
          Align = alClient
          Alignment = taCenter
          Caption = 'OHT MGZ IN'
          Color = clGray
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -13
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentColor = False
          ParentFont = False
          Layout = tlCenter
          WordWrap = True
          ExplicitTop = 6
        end
      end
      object panUSESKIP2: TPanel
        AlignWithMargins = True
        Left = 2
        Top = 73
        Width = 245
        Height = 29
        Margins.Left = 2
        Margins.Right = 2
        Align = alClient
        BevelOuter = bvNone
        Color = clGray
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -13
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentBackground = False
        ParentFont = False
        ShowCaption = False
        TabOrder = 2
        ExplicitLeft = 32
        ExplicitWidth = 120
        ExplicitHeight = 33
        object lblUSESKIP2: TLabel
          Tag = 5
          AlignWithMargins = True
          Left = 3
          Top = 3
          Width = 239
          Height = 23
          Align = alClient
          Alignment = taCenter
          Caption = 'OHT MGZ OUT'
          Color = clGray
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -13
          Font.Name = 'Calibri'
          Font.Style = [fsBold]
          ParentColor = False
          ParentFont = False
          Layout = tlCenter
          WordWrap = True
          ExplicitTop = 0
        end
      end
    end
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 200
    OnTimer = Timer1Timer
    Left = 248
    Top = 8
  end
end
