object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Kamelas Testcase Suite'
  ClientHeight = 477
  ClientWidth = 500
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 0
    Top = 307
    Width = 500
    Height = 170
    ActivePage = TabSheet1
    Align = alBottom
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'Shared Memory Model'
      object GroupBox1: TGroupBox
        Left = 0
        Top = 0
        Width = 492
        Height = 142
        Align = alClient
        TabOrder = 0
        object Label1: TLabel
          Left = 38
          Top = 24
          Width = 27
          Height = 13
          Caption = 'Name'
        end
        object Label2: TLabel
          Left = 16
          Top = 51
          Width = 49
          Height = 13
          Caption = 'Bytes Size'
        end
        object EditNameS: TEdit
          Left = 81
          Top = 21
          Width = 169
          Height = 21
          ImeName = 'Microsoft IME 2003'
          TabOrder = 0
        end
        object EditSizeS: TEdit
          Left = 81
          Top = 48
          Width = 169
          Height = 21
          ImeName = 'Microsoft IME 2003'
          TabOrder = 1
          Text = '1024'
        end
        object Button1: TButton
          Left = 344
          Top = 21
          Width = 129
          Height = 25
          Caption = 'Open and Attach'
          TabOrder = 2
          OnClick = Button1Click
        end
        object RadioButtonSharedMemoryServer: TRadioButton
          Left = 81
          Top = 102
          Width = 56
          Height = 17
          Caption = 'Server'
          Checked = True
          TabOrder = 3
          TabStop = True
        end
        object RadioButtonSharedMemoryClient: TRadioButton
          Left = 169
          Top = 102
          Width = 56
          Height = 17
          Caption = 'Client'
          TabOrder = 4
        end
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Option'
      ImageIndex = 2
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object GroupBox2: TGroupBox
        Left = 0
        Top = 0
        Width = 492
        Height = 142
        Align = alClient
        Caption = 'Timeout'
        TabOrder = 0
        object Label3: TLabel
          Left = 16
          Top = 37
          Width = 24
          Height = 13
          Caption = 'Send'
        end
        object Label7: TLabel
          Left = 16
          Top = 95
          Width = 24
          Height = 13
          Caption = 'Recv'
        end
        object TrackBarSend: TTrackBar
          Left = 46
          Top = 32
          Width = 427
          Height = 41
          Max = 1000
          Min = 1
          PageSize = 10
          Frequency = 10
          Position = 50
          PositionToolTip = ptTop
          TabOrder = 0
        end
        object TrackBarRecv: TTrackBar
          Left = 46
          Top = 87
          Width = 427
          Height = 41
          Max = 1000
          Min = 1
          PageSize = 10
          Frequency = 10
          Position = 10
          PositionToolTip = ptTop
          TabOrder = 1
        end
      end
    end
  end
  object ComboBoxManager: TComboBox
    Left = 0
    Top = 0
    Width = 500
    Height = 24
    Align = alTop
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ImeName = 'Microsoft IME 2003'
    ParentFont = False
    TabOrder = 1
    OnChange = ComboBoxManagerChange
  end
  object Panel1: TPanel
    Left = 0
    Top = 24
    Width = 500
    Height = 283
    Align = alClient
    BevelOuter = bvLowered
    Caption = 'Panel1'
    TabOrder = 2
    object Splitter1: TSplitter
      Left = 246
      Top = 1
      Height = 281
      ExplicitLeft = 186
      ExplicitTop = -4
      ExplicitHeight = 167
    end
    object Panel2: TPanel
      Left = 1
      Top = 1
      Width = 245
      Height = 281
      Align = alLeft
      Caption = 'Panel2'
      TabOrder = 0
      object MemoRecv: TMemo
        Left = 1
        Top = 1
        Width = 243
        Height = 260
        Align = alClient
        Color = clWhite
        ImeName = 'Microsoft IME 2003'
        Lines.Strings = (
          '')
        ReadOnly = True
        ScrollBars = ssVertical
        TabOrder = 0
      end
      object StatusBarRecv: TStatusBar
        Left = 1
        Top = 261
        Width = 243
        Height = 19
        Panels = <>
      end
    end
    object Panel3: TPanel
      Left = 249
      Top = 1
      Width = 250
      Height = 281
      Align = alClient
      Caption = 'Panel3'
      TabOrder = 1
      object MemoSend: TMemo
        Left = 1
        Top = 1
        Width = 248
        Height = 218
        Align = alClient
        ImeName = 'Microsoft IME 2003'
        ScrollBars = ssVertical
        TabOrder = 0
        OnKeyPress = MemoSendKeyPress
      end
      object StatusBarSend: TStatusBar
        Left = 1
        Top = 261
        Width = 248
        Height = 19
        Panels = <>
      end
      object CheckBoxRepeat: TCheckBox
        Left = 1
        Top = 244
        Width = 248
        Height = 17
        Align = alBottom
        Caption = 'Repeat with Increase the number'
        TabOrder = 2
      end
      object ButtonSend: TButton
        Left = 1
        Top = 219
        Width = 248
        Height = 25
        Align = alBottom
        Caption = '&Send'
        TabOrder = 3
        OnClick = ButtonSendClick
      end
    end
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 5
    OnTimer = Timer1Timer
    Left = 241
    Top = 152
  end
end
