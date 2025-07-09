object frmTCComm: TfrmTCComm
  Left = 0
  Top = 0
  Caption = 'TC Communication'
  ClientHeight = 389
  ClientWidth = 813
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Calibri'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnDestroy = FormDestroy
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 15
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 813
    Height = 50
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object btnConnect: TSpeedButton
      Left = 247
      Top = 10
      Width = 106
      Height = 28
      Caption = 'Connect'
      OnClick = btnConnectClick
    end
    object Label1: TLabel
      Left = 16
      Top = 15
      Width = 64
      Height = 15
      Caption = 'IP Address :'
    end
    object sbManual: TSpeedButton
      Left = 359
      Top = 10
      Width = 106
      Height = 28
      Caption = 'Manual Test'
      OnClick = sbManualClick
    end
    object Edit1: TEdit
      Left = 92
      Top = 12
      Width = 93
      Height = 23
      ImeName = 'Microsoft IME 2010'
      TabOrder = 0
      Text = '109.154.11.63'
    end
    object Edit2: TEdit
      Left = 191
      Top = 12
      Width = 50
      Height = 23
      ImeName = 'Microsoft IME 2010'
      TabOrder = 1
      Text = '15177'
    end
  end
  object Memo1: TMemo
    Left = 0
    Top = 240
    Width = 813
    Height = 149
    Align = alClient
    BorderStyle = bsNone
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Arial'
    Font.Style = []
    ImeName = 'Microsoft IME 2010'
    ParentFont = False
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 1
  end
  object Panel1: TPanel
    Left = 0
    Top = 50
    Width = 813
    Height = 190
    Align = alTop
    BevelOuter = bvNone
    Caption = 'Panel1'
    TabOrder = 2
    Visible = False
    object PageControl1: TPageControl
      Left = 0
      Top = 0
      Width = 543
      Height = 190
      ActivePage = TabSheet1
      Align = alClient
      TabHeight = 32
      TabOrder = 0
      TabWidth = 150
      object TabSheet1: TTabSheet
        Caption = 'Loader (Router)'
        ExplicitLeft = 0
        ExplicitTop = 0
        ExplicitWidth = 0
        ExplicitHeight = 0
        object PageControl3: TPageControl
          Left = 0
          Top = 0
          Width = 535
          Height = 148
          ActivePage = TabSheet8
          Align = alClient
          HotTrack = True
          MultiLine = True
          ParentShowHint = False
          ShowHint = False
          TabOrder = 0
          object TabSheet8: TTabSheet
            Caption = 'PCB Info Router'
            ImageIndex = 2
            ExplicitLeft = 0
            ExplicitTop = 0
            ExplicitWidth = 0
            ExplicitHeight = 0
            object SpeedButton5: TSpeedButton
              Left = 0
              Top = 90
              Width = 527
              Height = 28
              Align = alBottom
              Caption = 'Send'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Arial'
              Font.Style = []
              ParentFont = False
              OnClick = SpeedButton5Click
              ExplicitLeft = 2
              ExplicitTop = 316
              ExplicitWidth = 383
            end
            object Memo5: TMemo
              Left = 0
              Top = 0
              Width = 527
              Height = 90
              Align = alClient
              BorderStyle = bsNone
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Arial'
              Font.Style = []
              ImeName = 'Microsoft IME 2010'
              Lines.Strings = (
                'FUNCTION=PCB_INFO_ROUTER'
                '1. BCODE='
                '2. STEPID='
                '3. MODEL='
                '4. EQPID=')
              ParentFont = False
              ScrollBars = ssVertical
              TabOrder = 0
            end
          end
          object TabSheet9: TTabSheet
            Caption = 'Lot Start'
            ImageIndex = 3
            ExplicitLeft = 0
            ExplicitTop = 0
            ExplicitWidth = 0
            ExplicitHeight = 0
            object SpeedButton6: TSpeedButton
              Left = 0
              Top = 90
              Width = 527
              Height = 28
              Align = alBottom
              Caption = 'Send'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Arial'
              Font.Style = []
              ParentFont = False
              OnClick = SpeedButton6Click
              ExplicitLeft = 2
              ExplicitTop = 316
              ExplicitWidth = 383
            end
            object Memo6: TMemo
              Left = 0
              Top = 0
              Width = 527
              Height = 90
              Align = alClient
              BorderStyle = bsNone
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Arial'
              Font.Style = []
              ImeName = 'Microsoft IME 2010'
              Lines.Strings = (
                'FUNCTION=LOT_START'
                '1. LOTID='
                '2. PARTID='
                '3. OPERID='
                '4. STEP='
                '5. MODEL='
                '6. EQPID='
                '7. SIMAX='
                '8. AUTOLINE='
                '9. MERGELOT='
                '10. LOTQTY=')
              ParentFont = False
              ScrollBars = ssVertical
              TabOrder = 0
            end
          end
        end
      end
      object TabSheet4: TTabSheet
        Caption = 'Unloader (Sorter)'
        ImageIndex = 1
        ExplicitLeft = 0
        ExplicitTop = 0
        ExplicitWidth = 0
        ExplicitHeight = 0
        object PageControl2: TPageControl
          Left = 0
          Top = 0
          Width = 535
          Height = 148
          ActivePage = TabSheet5
          Align = alClient
          MultiLine = True
          ParentShowHint = False
          ShowHint = False
          TabOrder = 0
          object TabSheet5: TTabSheet
            Caption = 'See Lot'
            ImageIndex = 6
            ExplicitLeft = 0
            ExplicitTop = 0
            ExplicitWidth = 0
            ExplicitHeight = 0
            object SpeedButton2: TSpeedButton
              Left = 0
              Top = 90
              Width = 527
              Height = 28
              Align = alBottom
              Caption = 'Send'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Arial'
              Font.Style = []
              ParentFont = False
              OnClick = SpeedButton2Click
              ExplicitLeft = 277
              ExplicitTop = 163
              ExplicitWidth = 73
            end
            object Memo2: TMemo
              Left = 0
              Top = 0
              Width = 527
              Height = 90
              Align = alClient
              BorderStyle = bsNone
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Arial'
              Font.Style = []
              ImeName = 'Microsoft IME 2010'
              Lines.Strings = (
                'FUNCTION=SEE_LOT'
                '1. LOTNO='
                '2. EQPID='
                '3. OPERID=')
              ParentFont = False
              ScrollBars = ssVertical
              TabOrder = 0
            end
          end
          object TabSheet6: TTabSheet
            Caption = 'Online End'
            ImageIndex = 1
            ExplicitLeft = 0
            ExplicitTop = 0
            ExplicitWidth = 0
            ExplicitHeight = 0
            object SpeedButton8: TSpeedButton
              Left = 0
              Top = 90
              Width = 527
              Height = 28
              Align = alBottom
              Caption = 'Send'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Arial'
              Font.Style = []
              ParentFont = False
              OnClick = SpeedButton8Click
              ExplicitLeft = 277
              ExplicitTop = 163
              ExplicitWidth = 73
            end
            object Memo8: TMemo
              Left = 0
              Top = 0
              Width = 527
              Height = 90
              Align = alClient
              BorderStyle = bsNone
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Arial'
              Font.Style = []
              ImeName = 'Microsoft IME 2010'
              Lines.Strings = (
                'FUNCTION=ONLINE_END'
                '1. EQPID='
                '2. EQPMODEL='
                '3. LOTID='
                '4. OPERID='
                '5. AUTOLINE='
                '6. SCRAP_CNT='
                '7. SCRAP_INFO001= ( ... )'
                ' ...'
                '7+n. SCRAP_INFO00n= ( ... )')
              ParentFont = False
              ScrollBars = ssVertical
              TabOrder = 0
            end
          end
          object TabSheet7: TTabSheet
            Caption = 'Scrap Info'
            ImageIndex = 2
            ExplicitLeft = 0
            ExplicitTop = 0
            ExplicitWidth = 0
            ExplicitHeight = 0
            object SpeedButton9: TSpeedButton
              Left = 0
              Top = 90
              Width = 527
              Height = 28
              Align = alBottom
              Caption = 'Send'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Arial'
              Font.Style = []
              ParentFont = False
              OnClick = SpeedButton9Click
              ExplicitLeft = 277
              ExplicitTop = 163
              ExplicitWidth = 73
            end
            object Memo9: TMemo
              Left = 0
              Top = 0
              Width = 527
              Height = 90
              Align = alClient
              BorderStyle = bsNone
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Arial'
              Font.Style = []
              ImeName = 'Microsoft IME 2010'
              Lines.Strings = (
                'FUNCTION=SCRAP_INFO'
                '1. EQPID='
                '2. LOTID='
                '3. AUTOLINE=')
              ParentFont = False
              ScrollBars = ssVertical
              TabOrder = 0
            end
          end
          object TabSheet11: TTabSheet
            Caption = 'Delete Scrap'
            ImageIndex = 3
            ExplicitLeft = 0
            ExplicitTop = 0
            ExplicitWidth = 0
            ExplicitHeight = 0
            object SpeedButton10: TSpeedButton
              Left = 0
              Top = 90
              Width = 527
              Height = 28
              Align = alBottom
              Caption = 'Send'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Arial'
              Font.Style = []
              ParentFont = False
              OnClick = SpeedButton10Click
              ExplicitLeft = 277
              ExplicitTop = 163
              ExplicitWidth = 73
            end
            object Memo10: TMemo
              Left = 0
              Top = 0
              Width = 527
              Height = 90
              Align = alClient
              BorderStyle = bsNone
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Arial'
              Font.Style = []
              ImeName = 'Microsoft IME 2010'
              Lines.Strings = (
                'FUNCTION=DELETE_SCRAP'
                '1. EQPID='
                '2. LOTID='
                '3. SERIAL='
                '4. ARRAYSN='
                '5. AUTOLINE=')
              ParentFont = False
              ScrollBars = ssVertical
              TabOrder = 0
            end
          end
          object TabSheet12: TTabSheet
            Caption = 'Lot End'
            ImageIndex = 4
            ExplicitLeft = 0
            ExplicitTop = 0
            ExplicitWidth = 0
            ExplicitHeight = 0
            object SpeedButton11: TSpeedButton
              Left = 0
              Top = 90
              Width = 527
              Height = 28
              Align = alBottom
              Caption = 'Send'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Arial'
              Font.Style = []
              ParentFont = False
              OnClick = SpeedButton11Click
              ExplicitLeft = 277
              ExplicitTop = 163
              ExplicitWidth = 73
            end
            object Memo11: TMemo
              Left = 0
              Top = 0
              Width = 527
              Height = 90
              Align = alClient
              BorderStyle = bsNone
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Arial'
              Font.Style = []
              ImeName = 'Microsoft IME 2010'
              Lines.Strings = (
                'FUNCTION=SORTER_LOT_END'
                '1. EQPID='
                '2. LOTID='
                '3. PORTID='
                '4.OPERID='
                '5. AUTOLINE=')
              ParentFont = False
              ScrollBars = ssVertical
              TabOrder = 0
            end
          end
        end
      end
    end
    object StringGrid1: TStringGrid
      Left = 543
      Top = 0
      Width = 270
      Height = 190
      Align = alRight
      BorderStyle = bsNone
      ColCount = 2
      DefaultColWidth = 30
      RowCount = 40
      Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
      TabOrder = 1
      ColWidths = (
        30
        218)
    end
  end
  object ClientSocket1: TClientSocket
    Active = False
    ClientType = ctNonBlocking
    Port = 0
    OnConnect = ClientSocket1Connect
    OnDisconnect = ClientSocket1Disconnect
    OnRead = ClientSocket1Read
    OnError = ClientSocket1Error
    Left = 472
    Top = 8
  end
  object PopupMenu1: TPopupMenu
    Left = 536
    Top = 16
    object Clear2: TMenuItem
      Caption = 'Clear'
      OnClick = Clear2Click
    end
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 10
    OnTimer = Timer1Timer
    Left = 384
    Top = 360
  end
end
