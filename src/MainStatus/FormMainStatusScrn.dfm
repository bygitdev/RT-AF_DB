object FormMainStatus: TFormMainStatus
  Left = 0
  Top = 0
  BorderStyle = bsNone
  ClientHeight = 618
  ClientWidth = 1271
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -19
  Font.Name = 'Segoe UI Light'
  Font.Style = []
  OldCreateOrder = False
  WindowState = wsMaximized
  PixelsPerInch = 96
  TextHeight = 25
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 1271
    Height = 618
    ActivePage = TabSheet4
    Align = alClient
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Calibri'
    Font.Style = [fsBold]
    ParentFont = False
    TabHeight = 45
    TabOrder = 0
    TabWidth = 200
    object TabSheet1: TTabSheet
      Caption = 'MACHINE STATUS'
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object PanelMainARFlow: TPanel
        Left = 0
        Top = 0
        Width = 1263
        Height = 563
        Align = alClient
        BevelOuter = bvNone
        TabOrder = 0
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'PRODUCTION STATUS'
      ImageIndex = 1
      TabVisible = False
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object PanelDailyReport: TPanel
        Left = 0
        Top = 0
        Width = 1263
        Height = 563
        Align = alClient
        BevelOuter = bvNone
        TabOrder = 0
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'MANUAL SELECT'
      ImageIndex = 2
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object PanelManualSelect: TPanel
        Left = 0
        Top = 0
        Width = 1263
        Height = 563
        Align = alClient
        BevelOuter = bvNone
        Caption = 'PanelManualSelect'
        ShowCaption = False
        TabOrder = 0
      end
    end
    object ALLHOME: TTabSheet
      Caption = 'ALL HOME'
      ImageIndex = 3
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object PanelAllhome: TPanel
        Left = 0
        Top = 0
        Width = 1263
        Height = 563
        Align = alClient
        BevelOuter = bvNone
        Caption = 'PanelAllhome'
        ShowCaption = False
        TabOrder = 0
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'MULTI SERVO'
      ImageIndex = 4
      object PanelMultiServo: TPanel
        Left = 0
        Top = 0
        Width = 1263
        Height = 563
        TabOrder = 0
      end
    end
  end
  object LotColorDialog: TColorDialog
    Left = 1072
    Top = 8
  end
  object MainRefreshTimer: TTimer
    Interval = 500
    OnTimer = MainRefreshTimerTimer
    Left = 1204
    Top = 11
  end
end
