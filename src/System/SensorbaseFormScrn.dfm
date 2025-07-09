object SensorbaseForm: TSensorbaseForm
  Left = 0
  Top = 0
  BorderStyle = bsNone
  ClientHeight = 780
  ClientWidth = 1280
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object PanelSystemBase: TPanel
    Left = 0
    Top = 0
    Width = 1280
    Height = 780
    Align = alClient
    Color = clGray
    ParentBackground = False
    TabOrder = 0
    object PanelSensorPart1: TPanel
      Tag = 1
      Left = 18
      Top = 8
      Width = 310
      Height = 380
      TabOrder = 0
    end
    object PanelSensorPart5: TPanel
      Tag = 5
      Left = 18
      Top = 393
      Width = 310
      Height = 380
      TabOrder = 1
    end
    object PanelSensorPart2: TPanel
      Tag = 2
      Left = 330
      Top = 8
      Width = 310
      Height = 380
      TabOrder = 2
    end
    object PanelSensorPart3: TPanel
      Tag = 3
      Left = 642
      Top = 8
      Width = 310
      Height = 380
      TabOrder = 3
    end
    object PanelSensorPart4: TPanel
      Tag = 4
      Left = 954
      Top = 8
      Width = 310
      Height = 380
      TabOrder = 4
    end
    object PanelSensorPart6: TPanel
      Tag = 6
      Left = 330
      Top = 393
      Width = 310
      Height = 380
      TabOrder = 5
    end
    object PanelSensorPart7: TPanel
      Tag = 7
      Left = 642
      Top = 393
      Width = 310
      Height = 380
      TabOrder = 6
    end
    object PanelSensorPart8: TPanel
      Tag = 8
      Left = 954
      Top = 393
      Width = 310
      Height = 380
      TabOrder = 7
    end
  end
end
