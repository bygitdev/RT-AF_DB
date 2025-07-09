object frmBarcode: TfrmBarcode
  Left = 0
  Top = 0
  Caption = 'Barcode'
  ClientHeight = 436
  ClientWidth = 532
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 14
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 532
    Height = 436
    ActivePage = TabSheet3
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    TabWidth = 170
    object TabSheet3: TTabSheet
      Caption = '1D Barcode'
      ImageIndex = 2
      object Button5: TButton
        Left = 154
        Top = 24
        Width = 100
        Height = 60
        Caption = 'Off'
        TabOrder = 0
        OnClick = Button5Click
      end
      object Button6: TButton
        Left = 26
        Top = 24
        Width = 100
        Height = 60
        Caption = 'On'
        TabOrder = 1
        OnClick = Button6Click
      end
      object Memo1: TMemo
        Left = 0
        Top = 152
        Width = 524
        Height = 250
        Align = alBottom
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ImeName = 'Microsoft IME 2010'
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 2
      end
    end
  end
end
