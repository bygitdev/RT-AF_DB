object frmAllhomeStatus: TfrmAllhomeStatus
  Left = 0
  Top = 0
  BorderStyle = bsNone
  Caption = 'frmAllhomeStatus'
  ClientHeight = 581
  ClientWidth = 1073
  Color = clInactiveCaptionText
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object GridPanel1: TGridPanel
    AlignWithMargins = True
    Left = 3
    Top = 3
    Width = 1067
    Height = 575
    Align = alClient
    BevelOuter = bvNone
    Caption = 'GridPanel1'
    Color = clInactiveCaptionText
    ColumnCollection = <
      item
        Value = 19.999999999999980000
      end
      item
        Value = 19.999999999999990000
      end
      item
        Value = 20.000000000000000000
      end
      item
        Value = 20.000000000000010000
      end
      item
        Value = 20.000000000000020000
      end>
    ControlCollection = <>
    ParentBackground = False
    RowCollection = <
      item
        Value = 16.666666666666660000
      end
      item
        Value = 16.666666666666660000
      end
      item
        Value = 16.666666666666660000
      end
      item
        Value = 16.666666666666660000
      end
      item
        Value = 16.666666666666680000
      end
      item
        Value = 16.666666666666680000
      end>
    ShowCaption = False
    TabOrder = 0
  end
  object Timer1: TTimer
    Interval = 667
    OnTimer = Timer1Timer
    Left = 520
    Top = 280
  end
end
