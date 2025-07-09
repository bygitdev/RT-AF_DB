object frmQCResult: TfrmQCResult
  Left = 0
  Top = 0
  BorderStyle = bsNone
  Caption = 'QC Inspection Result'
  ClientHeight = 480
  ClientWidth = 443
  Color = clGray
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Calibri'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnResize = FormResize
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 15
  object CurvyPanel1: TCurvyPanel
    Left = 8
    Top = 8
    Width = 427
    Height = 465
    Color = clBtnFace
    TabOrder = 0
    object Label1: TLabel
      Left = 19
      Top = 97
      Width = 81
      Height = 18
      Caption = 'TEST RESULT :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Calibri'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 19
      Top = 128
      Width = 81
      Height = 18
      Caption = 'ARTS SCRAP :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Calibri'
      Font.Style = []
      ParentFont = False
    end
    object btnOk: TBitBtn
      Left = 271
      Top = 392
      Width = 146
      Height = 60
      Caption = 'OK'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      OnClick = btnOkClick
    end
    object ceLotID: TCurvyEdit
      Left = 10
      Top = 10
      Width = 407
      Height = 34
      TabOrder = 1
      TabStop = False
      Version = '1.1.1.8'
      Alignment = taCenter
      Controls = <>
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ImeName = 'Microsoft IME 2010'
      ParentFont = False
      Text = 'LOTID'
    end
    object StringGridSubstrate: TStringGrid
      Left = 10
      Top = 164
      Width = 407
      Height = 212
      ColCount = 4
      DefaultColWidth = 120
      DefaultRowHeight = 60
      FixedCols = 0
      RowCount = 3
      FixedRows = 0
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentFont = False
      ScrollBars = ssNone
      TabOrder = 2
      OnDrawCell = StringGridSubstrateDrawCell
      OnSelectCell = StringGridSubstrateSelectCell
    end
    object CurvyEdit1: TCurvyEdit
      Left = 109
      Top = 95
      Width = 308
      Height = 24
      TabOrder = 3
      TabStop = False
      Version = '1.1.1.8'
      Controls = <>
      ImeName = 'Microsoft IME 2010'
      ReadOnly = True
      Text = ''
    end
    object CurvyEdit2: TCurvyEdit
      Left = 109
      Top = 125
      Width = 308
      Height = 24
      TabOrder = 4
      TabStop = False
      Version = '1.1.1.8'
      Controls = <>
      ImeName = 'Microsoft IME 2010'
      ReadOnly = True
      Text = ''
    end
    object btnRetry: TBitBtn
      Left = 10
      Top = 392
      Width = 146
      Height = 60
      Caption = 'QC RETRY'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 5
      OnClick = btnRetryClick
    end
    object ceIndex: TCurvyEdit
      Left = 10
      Top = 50
      Width = 407
      Height = 34
      TabOrder = 6
      TabStop = False
      Version = '1.1.1.8'
      Alignment = taCenter
      Controls = <>
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ImeName = 'Microsoft IME 2010'
      ParentFont = False
      Text = 'INDEX 1'
    end
  end
end
