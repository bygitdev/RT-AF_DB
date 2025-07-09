object frmTrayTeach: TfrmTrayTeach
  Left = 0
  Top = 0
  BorderStyle = bsNone
  Caption = 'frmRecuoeTeach'
  ClientHeight = 782
  ClientWidth = 1280
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Calibri'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnPaint = FormPaint
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object TrayTeachPageCtrl: TPageControl
    Left = 0
    Top = 0
    Width = 1280
    Height = 780
    ActivePage = TabSheet2
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Calibri'
    Font.Style = [fsBold]
    ParentFont = False
    TabHeight = 30
    TabOrder = 0
    TabWidth = 250
    object TabSheet2: TTabSheet
      Caption = 'DEVICE TEACH'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Calibri'
      Font.Style = []
      ImageIndex = 1
      ParentFont = False
      object CurvyPanel28: TCurvyPanel
        Left = 3
        Top = 7
        Width = 1262
        Height = 730
        Color = clBtnFace
        TabOrder = 0
        object CurvyPanel29: TCurvyPanel
          Left = 16
          Top = 8
          Width = 1233
          Height = 393
          TabOrder = 0
          object Panel39: TPanel
            Left = 8
            Top = 8
            Width = 1218
            Height = 377
            BevelKind = bkFlat
            BevelOuter = bvNone
            TabOrder = 0
            object LabelTrayShiftOffsetY: TLabel
              Left = 149
              Top = 88
              Width = 99
              Height = 15
              Caption = 'LEFT TOP OFFSET Y'
            end
            object LabelTrayShiftOffsetX: TLabel
              Left = 149
              Top = 59
              Width = 100
              Height = 15
              Caption = 'LEFT TOP OFFSET X'
            end
            object LabelTrayXShrinkOffsetX: TLabel
              Left = 472
              Top = 59
              Width = 110
              Height = 15
              Caption = 'RIGHT TOP OFFSET X'
            end
            object LabelTrayXShrinkOffsetY: TLabel
              Left = 473
              Top = 87
              Width = 109
              Height = 15
              Caption = 'RIGHT TOP OFFSET Y'
            end
            object LabelTrayYShrinkOffsetX: TLabel
              Left = 824
              Top = 59
              Width = 102
              Height = 15
              Caption = 'LEFT BTM OFFSET X'
            end
            object LabelTrayYShrinkOffsetY: TLabel
              Left = 824
              Top = 88
              Width = 101
              Height = 15
              Caption = 'LEFT BTM OFFSET Y'
            end
            object Label1: TLabel
              Left = 149
              Top = 176
              Width = 99
              Height = 15
              Caption = 'LEFT TOP OFFSET Y'
            end
            object Label2: TLabel
              Left = 149
              Top = 147
              Width = 100
              Height = 15
              Caption = 'LEFT TOP OFFSET X'
            end
            object Label3: TLabel
              Left = 473
              Top = 150
              Width = 110
              Height = 15
              Caption = 'RIGHT TOP OFFSET X'
            end
            object Label4: TLabel
              Left = 473
              Top = 179
              Width = 109
              Height = 15
              Caption = 'RIGHT TOP OFFSET Y'
            end
            object Label5: TLabel
              Left = 824
              Top = 150
              Width = 102
              Height = 15
              Caption = 'LEFT BTM OFFSET X'
            end
            object Label6: TLabel
              Left = 824
              Top = 179
              Width = 101
              Height = 15
              Caption = 'LEFT BTM OFFSET Y'
            end
            object Label7: TLabel
              Left = 149
              Top = 267
              Width = 99
              Height = 15
              Caption = 'LEFT TOP OFFSET Y'
            end
            object Label8: TLabel
              Left = 149
              Top = 238
              Width = 100
              Height = 15
              Caption = 'LEFT TOP OFFSET X'
            end
            object Label9: TLabel
              Left = 473
              Top = 239
              Width = 110
              Height = 15
              Caption = 'RIGHT TOP OFFSET X'
            end
            object Label10: TLabel
              Left = 473
              Top = 270
              Width = 109
              Height = 15
              Caption = 'RIGHT TOP OFFSET Y'
            end
            object Label11: TLabel
              Left = 824
              Top = 241
              Width = 102
              Height = 15
              Caption = 'LEFT BTM OFFSET X'
            end
            object Label12: TLabel
              Left = 824
              Top = 270
              Width = 101
              Height = 15
              Caption = 'LEFT BTM OFFSET Y'
            end
            object Shape1: TShape
              Left = 20
              Top = 122
              Width = 1154
              Height = 1
            end
            object Shape2: TShape
              Left = 20
              Top = 213
              Width = 1154
              Height = 1
            end
            object Shape3: TShape
              Left = 20
              Top = 32
              Width = 1154
              Height = 1
            end
            object Shape4: TShape
              Left = 20
              Top = 304
              Width = 1154
              Height = 1
            end
            object TrayOffsetEdit0: TEdit
              Left = 279
              Top = 57
              Width = 86
              Height = 26
              Alignment = taCenter
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'Calibri'
              Font.Style = []
              ImeName = 'Microsoft Office IME 2007'
              ParentFont = False
              TabOrder = 0
              Text = '0.0'
            end
            object TrayOffsetEdit1: TEdit
              Left = 279
              Top = 86
              Width = 86
              Height = 26
              Alignment = taCenter
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'Calibri'
              Font.Style = []
              ImeName = 'Microsoft Office IME 2007'
              ParentFont = False
              TabOrder = 1
              Text = '0.0'
            end
            object TrayShrinkOffsetEdit1: TEdit
              Left = 615
              Top = 84
              Width = 86
              Height = 26
              Alignment = taCenter
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'Calibri'
              Font.Style = []
              ImeName = 'Microsoft Office IME 2007'
              ParentFont = False
              TabOrder = 2
              Text = '0.0'
            end
            object TrayShrinkOffsetEdit0: TEdit
              Left = 615
              Top = 55
              Width = 86
              Height = 26
              Alignment = taCenter
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'Calibri'
              Font.Style = []
              ImeName = 'Microsoft Office IME 2007'
              ParentFont = False
              TabOrder = 3
              Text = '0.0'
            end
            object TrayShrinkOffsetEdit3: TEdit
              Left = 952
              Top = 84
              Width = 86
              Height = 26
              Alignment = taCenter
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'Calibri'
              Font.Style = []
              ImeName = 'Microsoft Office IME 2007'
              ParentFont = False
              TabOrder = 4
              Text = '0.0'
            end
            object TrayShrinkOffsetEdit2: TEdit
              Left = 952
              Top = 55
              Width = 86
              Height = 26
              Alignment = taCenter
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'Calibri'
              Font.Style = []
              ImeName = 'Microsoft Office IME 2007'
              ParentFont = False
              TabOrder = 5
              Text = '0.0'
            end
            object BtnDataSave: TBitBtn
              AlignWithMargins = True
              Left = 1026
              Top = 312
              Width = 147
              Height = 53
              Margins.Left = 5
              Margins.Top = 10
              Margins.Right = 5
              Margins.Bottom = 10
              Caption = 'OFFSET DATA SAVE'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Calibri'
              Font.Style = []
              Glyph.Data = {
                F6060000424DF606000000000000360000002800000018000000180000000100
                180000000000C0060000C40E0000C40E00000000000000000000FFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB5B5B51D1D
                1D00000000000000000000000000000000000000000000000000000000000000
                00000000000000000000001D1D1DB5B5B5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFF1C1C1C0000000000000000000000000000000000000000000000000000
                000000000000000000000000000000000000000000001C1C1CFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000000
                0000000000000000000000FFFFFFFFFFFF000000000000000000000000000000
                000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000
                00000000000000000000000000000000000000FFFFFFFFFFFF00000000000000
                0000000000000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFF0000000000000000000000000000000000000000000000000000000000
                00000000000000000000000000000000000000000000000000FFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000000
                0000000000000000000000FFFFFFFFFFFF000000000000000000000000000000
                000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000
                00000000000000000000000000000000000000FFFFFFFFFFFF00000000000000
                0000000000000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFF000000000000000000000000000000000000000000000000FFFFFFFFFF
                FF000000000000000000000000000000000000000000000000FFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000000
                000000FFFFFFFFFFFF0000000000000000000000000000000000000000000000
                00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000000
                0000000000000000000000FFFFFFFFFFFF000000000000000000000000000000
                000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000
                00000000000000000000000000000000000000FFFFFFFFFFFF00000000000000
                0000000000000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFF0000000000000000000000000000000000000000000000000000000000
                00000000000000000000000000000000000000000000000000FFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1C1C1C0000
                00000000000000000000000000000000000000C4C4C4C4C4C400000000000000
                00000000000000000000000000001C1C1CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFB5B5B51D1D1D000000000000000000000000000000000000C4C4C4C4C4
                C40000000000000000000000000000000000001D1D1DB5B5B5FFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF757575
                000000000000000000000000757575FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFBFBFB747474141414141414747474FBFBFBFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
              ParentFont = False
              Style = bsWin31
              TabOrder = 6
              OnClick = BtnDataSaveClick
            end
            object btnAllTrayDataSave: TBitBtn
              AlignWithMargins = True
              Left = 730
              Top = 312
              Width = 137
              Height = 53
              Margins.Left = 5
              Margins.Top = 10
              Margins.Right = 5
              Margins.Bottom = 10
              Caption = 'ALL TRAY                OFFSET DATA APPLY'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Calibri'
              Font.Style = []
              Glyph.Data = {
                F6060000424DF606000000000000360000002800000018000000180000000100
                180000000000C0060000C40E0000C40E00000000000000000000FFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB5B5B51D1D
                1D00000000000000000000000000000000000000000000000000000000000000
                00000000000000000000001D1D1DB5B5B5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFF1C1C1C0000000000000000000000000000000000000000000000000000
                000000000000000000000000000000000000000000001C1C1CFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000000
                0000000000000000000000FFFFFFFFFFFF000000000000000000000000000000
                000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000
                00000000000000000000000000000000000000FFFFFFFFFFFF00000000000000
                0000000000000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFF0000000000000000000000000000000000000000000000000000000000
                00000000000000000000000000000000000000000000000000FFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000000
                0000000000000000000000FFFFFFFFFFFF000000000000000000000000000000
                000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000
                00000000000000000000000000000000000000FFFFFFFFFFFF00000000000000
                0000000000000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFF000000000000000000000000000000000000000000000000FFFFFFFFFF
                FF000000000000000000000000000000000000000000000000FFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000000
                000000FFFFFFFFFFFF0000000000000000000000000000000000000000000000
                00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000000
                0000000000000000000000FFFFFFFFFFFF000000000000000000000000000000
                000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000
                00000000000000000000000000000000000000FFFFFFFFFFFF00000000000000
                0000000000000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFF0000000000000000000000000000000000000000000000000000000000
                00000000000000000000000000000000000000000000000000FFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1C1C1C0000
                00000000000000000000000000000000000000C4C4C4C4C4C400000000000000
                00000000000000000000000000001C1C1CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFB5B5B51D1D1D000000000000000000000000000000000000C4C4C4C4C4
                C40000000000000000000000000000000000001D1D1DB5B5B5FFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF757575
                000000000000000000000000757575FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFBFBFB747474141414141414747474FBFBFBFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
              ParentFont = False
              Style = bsWin31
              TabOrder = 7
              Visible = False
              WordWrap = True
              OnClick = btnAllTrayDataSaveClick
            end
            object TrayOffsetEdit2: TEdit
              Left = 280
              Top = 145
              Width = 86
              Height = 26
              Alignment = taCenter
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'Calibri'
              Font.Style = []
              ImeName = 'Microsoft Office IME 2007'
              ParentFont = False
              TabOrder = 8
              Text = '0.0'
            end
            object TrayOffsetEdit3: TEdit
              Left = 280
              Top = 174
              Width = 86
              Height = 26
              Alignment = taCenter
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'Calibri'
              Font.Style = []
              ImeName = 'Microsoft Office IME 2007'
              ParentFont = False
              TabOrder = 9
              Text = '0.0'
            end
            object TrayShrinkOffsetEdit5: TEdit
              Left = 615
              Top = 174
              Width = 86
              Height = 26
              Alignment = taCenter
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'Calibri'
              Font.Style = []
              ImeName = 'Microsoft Office IME 2007'
              ParentFont = False
              TabOrder = 10
              Text = '0.0'
            end
            object TrayShrinkOffsetEdit4: TEdit
              Left = 615
              Top = 145
              Width = 86
              Height = 26
              Alignment = taCenter
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'Calibri'
              Font.Style = []
              ImeName = 'Microsoft Office IME 2007'
              ParentFont = False
              TabOrder = 11
              Text = '0.0'
            end
            object TrayShrinkOffsetEdit7: TEdit
              Left = 952
              Top = 174
              Width = 86
              Height = 26
              Alignment = taCenter
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'Calibri'
              Font.Style = []
              ImeName = 'Microsoft Office IME 2007'
              ParentFont = False
              TabOrder = 12
              Text = '0.0'
            end
            object TrayShrinkOffsetEdit6: TEdit
              Left = 952
              Top = 145
              Width = 86
              Height = 26
              Alignment = taCenter
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'Calibri'
              Font.Style = []
              ImeName = 'Microsoft Office IME 2007'
              ParentFont = False
              TabOrder = 13
              Text = '0.0'
            end
            object TrayOffsetEdit4: TEdit
              Left = 280
              Top = 236
              Width = 86
              Height = 26
              Alignment = taCenter
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'Calibri'
              Font.Style = []
              ImeName = 'Microsoft Office IME 2007'
              ParentFont = False
              TabOrder = 14
              Text = '0.0'
            end
            object TrayOffsetEdit5: TEdit
              Left = 280
              Top = 265
              Width = 86
              Height = 26
              Alignment = taCenter
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'Calibri'
              Font.Style = []
              ImeName = 'Microsoft Office IME 2007'
              ParentFont = False
              TabOrder = 15
              Text = '0.0'
            end
            object TrayShrinkOffsetEdit9: TEdit
              Left = 615
              Top = 267
              Width = 86
              Height = 26
              Alignment = taCenter
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'Calibri'
              Font.Style = []
              ImeName = 'Microsoft Office IME 2007'
              ParentFont = False
              TabOrder = 16
              Text = '0.0'
            end
            object TrayShrinkOffsetEdit8: TEdit
              Left = 615
              Top = 236
              Width = 86
              Height = 26
              Alignment = taCenter
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'Calibri'
              Font.Style = []
              ImeName = 'Microsoft Office IME 2007'
              ParentFont = False
              TabOrder = 17
              Text = '0.0'
            end
            object TrayShrinkOffsetEdit11: TEdit
              Left = 952
              Top = 267
              Width = 86
              Height = 26
              Alignment = taCenter
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'Calibri'
              Font.Style = []
              ImeName = 'Microsoft Office IME 2007'
              ParentFont = False
              TabOrder = 18
              Text = '0.0'
            end
            object TrayShrinkOffsetEdit10: TEdit
              Left = 952
              Top = 235
              Width = 86
              Height = 26
              Alignment = taCenter
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'Calibri'
              Font.Style = []
              ImeName = 'Microsoft Office IME 2007'
              ParentFont = False
              TabOrder = 19
              Text = '0.0'
            end
            object Panel1: TPanel
              Left = 477
              Top = 3
              Width = 301
              Height = 29
              Caption = 'TRAY OFFSET'
              Color = clSilver
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -16
              Font.Name = 'Calibri'
              Font.Style = [fsBold]
              ParentBackground = False
              ParentFont = False
              TabOrder = 20
            end
            object Panel2: TPanel
              Left = 20
              Top = 34
              Width = 94
              Height = 87
              BevelKind = bkFlat
              BevelOuter = bvNone
              Caption = 'REAR (GOOD)'
              Color = clSilver
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Calibri'
              Font.Style = [fsBold]
              ParentBackground = False
              ParentFont = False
              TabOrder = 21
            end
            object Panel3: TPanel
              Left = 20
              Top = 124
              Width = 94
              Height = 87
              BevelKind = bkFlat
              BevelOuter = bvNone
              Caption = 'FRONT (GOOD)'
              Color = clSilver
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Calibri'
              Font.Style = [fsBold]
              ParentBackground = False
              ParentFont = False
              TabOrder = 22
            end
            object Panel4: TPanel
              Left = 20
              Top = 216
              Width = 94
              Height = 87
              BevelKind = bkFlat
              BevelOuter = bvNone
              Caption = 'REJECT'
              Color = clSilver
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Calibri'
              Font.Style = [fsBold]
              ParentBackground = False
              ParentFont = False
              TabOrder = 23
            end
            object BtnTeachBtn5: TBitBtn
              Left = 1048
              Top = 52
              Width = 125
              Height = 54
              Caption = 'TRAY UNIT TEACHING'
              Font.Charset = ANSI_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Calibri'
              Font.Style = [fsBold]
              Layout = blGlyphTop
              ParentFont = False
              TabOrder = 24
              OnClick = BtnTeachBtn5Click
            end
            object BitBtn1: TBitBtn
              Tag = 1
              Left = 1048
              Top = 145
              Width = 125
              Height = 54
              Caption = 'TRAY UNIT TEACHING'
              Font.Charset = ANSI_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Calibri'
              Font.Style = [fsBold]
              Layout = blGlyphTop
              ParentFont = False
              TabOrder = 25
              OnClick = BtnTeachBtn5Click
            end
            object BitBtn2: TBitBtn
              Tag = 2
              Left = 1048
              Top = 236
              Width = 125
              Height = 54
              Caption = 'TRAY UNIT TEACHING'
              Font.Charset = ANSI_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Calibri'
              Font.Style = [fsBold]
              Layout = blGlyphTop
              ParentFont = False
              TabOrder = 26
              OnClick = BtnTeachBtn5Click
            end
            object BtnDataInput: TBitBtn
              AlignWithMargins = True
              Left = 873
              Top = 312
              Width = 147
              Height = 53
              Margins.Left = 5
              Margins.Top = 10
              Margins.Right = 5
              Margins.Bottom = 10
              Caption = 'OFFSET DATA INPUT'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Calibri'
              Font.Style = []
              Glyph.Data = {
                36030000424D3603000000000000360000002800000010000000100000000100
                1800000000000003000012170000121700000000000000000000FFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFF02020202020202020202020202020202020202
                0202020202020202020202020202020202020202E0E0E0FFFFFFFFFFFF151515
                0606060606060606060606060606060606060606060606060606060606060606
                06060606A2A2A2FFFFFFFFFFFF57575709090909090909090909090909090909
                0909090909090909090909090909090909090909666666FFFFFFFFFFFF959595
                0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D0D
                0D0D0D0D2C2C2CFFFFFFFFFFFFE1E1E110101010101010101010101010101010
                1010101010101010101010101010101010101010101010D3D3D3FFFFFFFFFFFF
                3131311313131313131313131313131313131313131313131313131313131313
                13131313131313989898E3E3E3FFFFFF6E6E6E17171717171717171717171717
                17171717171717171717171717171717171717171717176060609B9B9BFFFFFF
                A9A9A91A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A
                1A1A1A1A1A1A1A292929656565FFFFFFE3E3E31E1E1E1E1E1E1E1E1E1E1E1E1E
                1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E2F2F2FFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFF242424BBBBBBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF282828282828
                2828282828282828282828282828282828282828282828282828282828282828
                285E5E5EFFFFFFFFFFFF3939392B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B
                2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B2B6E6E6EFFFFFFFFFFFF9797972F2F2F
                2F2F2F2F2F2F2F2F2F2F2F2F565656F2F2F2FFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFF5858583232323232323232323E3E3ED9D9D9FF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
              ParentFont = False
              Style = bsWin31
              TabOrder = 27
              OnClick = BtnDataInputClick
            end
          end
        end
        object CurvyPanel30: TCurvyPanel
          Left = 16
          Top = 407
          Width = 1233
          Height = 320
          TabOrder = 1
          object CurvyPanel32: TCurvyPanel
            Left = 603
            Top = 3
            Width = 627
            Height = 314
            Color = clBtnFace
            TabOrder = 0
            object Label28: TLabel
              Left = 20
              Top = 119
              Width = 208
              Height = 15
              Caption = 'TRAY UNIT CENTER TO PICK UP POINT X'
            end
            object Label29: TLabel
              Left = 21
              Top = 148
              Width = 207
              Height = 15
              Caption = 'TRAY UNIT CENTER TO PICK UP POINT Y'
            end
            object Label31: TLabel
              Left = 21
              Top = 189
              Width = 147
              Height = 15
              Caption = 'TRAY CENTER TO 1ST UNIT X'
            end
            object Label32: TLabel
              Left = 21
              Top = 218
              Width = 146
              Height = 15
              Caption = 'TRAY CENTER TO 1ST UNIT Y'
            end
            object Shape27: TShape
              Left = 22
              Top = 175
              Width = 586
              Height = 3
            end
            object Shape28: TShape
              Left = 22
              Top = 247
              Width = 586
              Height = 3
            end
            object Label36: TLabel
              Left = 21
              Top = 259
              Width = 129
              Height = 15
              Caption = 'MAX TRAY STACK COUNT'
            end
            object Label37: TLabel
              Left = 21
              Top = 289
              Width = 135
              Height = 15
              Caption = 'MAX TRAY TOTAL WEIGHT'
            end
            object Shape5: TShape
              Left = 22
              Top = 104
              Width = 586
              Height = 3
            end
            object Label14: TLabel
              Left = 21
              Top = 17
              Width = 204
              Height = 15
              Caption = 'Gerber Center To Unit Pickup Center X'
            end
            object Label15: TLabel
              Left = 328
              Top = 17
              Width = 203
              Height = 15
              Caption = 'Gerber Center To Unit Pickup Center Y'
            end
            object Label16: TLabel
              Left = 21
              Top = 46
              Width = 164
              Height = 15
              Caption = 'PCB CENTER TO UNIT CENTER X'
            end
            object Label17: TLabel
              Left = 22
              Top = 75
              Width = 163
              Height = 15
              Caption = 'PCB CENTER TO UNIT CENTER Y'
            end
            object EditPP2: TEdit
              Left = 255
              Top = 143
              Width = 132
              Height = 26
              Alignment = taCenter
              Enabled = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'Calibri'
              Font.Style = []
              ImeName = 'Microsoft Office IME 2007'
              ParentFont = False
              TabOrder = 0
              Text = '0.0'
            end
            object EditPP1: TEdit
              Left = 255
              Top = 114
              Width = 132
              Height = 26
              Alignment = taCenter
              Enabled = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'Calibri'
              Font.Style = []
              ImeName = 'Microsoft Office IME 2007'
              ParentFont = False
              TabOrder = 1
              Text = '0.0'
            end
            object BtnTCUnitSave: TBitBtn
              AlignWithMargins = True
              Left = 408
              Top = 184
              Width = 200
              Height = 55
              Margins.Left = 5
              Margins.Top = 10
              Margins.Right = 5
              Margins.Bottom = 10
              Caption = 'TRAY CENTER TO 1ST UNIT VALUE OPERATION'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -12
              Font.Name = 'Calibri'
              Font.Style = []
              Glyph.Data = {
                36030000424D3603000000000000360000002800000010000000100000000100
                1800000000000003000012170000121700000000000000000000FFFFFFFFFFFF
                FFFFFFFFFFFFC0C0C0525252020202020202020202020202323232919191F0F0
                F0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0F0F055555505050505050505050505
                0505050505050505050505050505252525D1D1D1FFFFFFFFFFFFFFFFFFF0F0F0
                3838380909090909090909090909090909090909090909090909090909090909
                09191919D1D1D1FFFFFFFFFFFF7777770C0C0C0C0C0C0C0C0C2A2A2AA3A3A3E1
                E1E1F0F0F0B3B3B34949490C0C0C0C0C0C0C0C0C2B2B2BF0F0F0E2E2E20F0F0F
                0F0F0F0F0F0F3D3D3DF0F0F0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9696960F0F
                0F0F0F0F0F0F0F8787877B7B7B121212121212212121F1F1F1FFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFF5D5D5D1212123030307B7B7B505050151515
                1515157C7C7CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFF282828191919191919C6C6C6FFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF2A2A2A1C1C1C
                1C1C1CB8B8B8FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD5D5
                D5C7C7C78E8E8E8E8E8E5858581F1F1F1F1F1F828282FFFFFFFFFFFFFFFFFFFF
                FFFFB9B9B95858583C3C3C1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F848484222222
                222222303030E4E4E4FFFFFFFFFFFFFFFFFFD6D6D64C4C4C2222222222222222
                22222222222222222222E4E4E42525252525252525254F4F4FF2F2F2FFFFFFFF
                FFFFFFFFFFF2F2F24F4F4F252525252525252525252525252525FFFFFF878787
                282828282828282828363636878787CACACACACACAAFAFAF4343432828282828
                28282828282828282828FFFFFFFFFFFF7B7B7B2C2C2C2C2C2C2C2C2C2C2C2C2C
                2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2CFFFFFFFFFFFF
                FFFFFF8A8A8A2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F5656
                56A4A4A42F2F2F2F2F2FFFFFFFFFFFFFFFFFFFFFFFFFE6E6E67F7F7F4C4C4C32
                32323232323F3F3F727272B2B2B2FFFFFFFFFFFFCCCCCC3F3F3F}
              ParentFont = False
              Style = bsWin31
              TabOrder = 2
              WordWrap = True
              OnClick = BtnTCUnitSaveClick
            end
            object EditTC2: TEdit
              Left = 255
              Top = 213
              Width = 132
              Height = 26
              Alignment = taCenter
              Enabled = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'Calibri'
              Font.Style = []
              ImeName = 'Microsoft Office IME 2007'
              ParentFont = False
              TabOrder = 3
              Text = '0.0'
            end
            object EditTC1: TEdit
              Left = 255
              Top = 184
              Width = 132
              Height = 26
              Alignment = taCenter
              Enabled = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'Calibri'
              Font.Style = []
              ImeName = 'Microsoft Office IME 2007'
              ParentFont = False
              TabOrder = 4
              Text = '0.0'
            end
            object BtnUCDistanceSave: TBitBtn
              AlignWithMargins = True
              Left = 408
              Top = 114
              Width = 200
              Height = 55
              Margins.Left = 5
              Margins.Top = 10
              Margins.Right = 5
              Margins.Bottom = 10
              Caption = 'UNIT CENTER PICK UP DISTANCE OPERATION'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Calibri'
              Font.Style = []
              Glyph.Data = {
                36030000424D3603000000000000360000002800000010000000100000000100
                1800000000000003000012170000121700000000000000000000FFFFFFFFFFFF
                FFFFFFFFFFFFC0C0C0525252020202020202020202020202323232919191F0F0
                F0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0F0F055555505050505050505050505
                0505050505050505050505050505252525D1D1D1FFFFFFFFFFFFFFFFFFF0F0F0
                3838380909090909090909090909090909090909090909090909090909090909
                09191919D1D1D1FFFFFFFFFFFF7777770C0C0C0C0C0C0C0C0C2A2A2AA3A3A3E1
                E1E1F0F0F0B3B3B34949490C0C0C0C0C0C0C0C0C2B2B2BF0F0F0E2E2E20F0F0F
                0F0F0F0F0F0F3D3D3DF0F0F0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9696960F0F
                0F0F0F0F0F0F0F8787877B7B7B121212121212212121F1F1F1FFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFF5D5D5D1212123030307B7B7B505050151515
                1515157C7C7CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFF282828191919191919C6C6C6FFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF2A2A2A1C1C1C
                1C1C1CB8B8B8FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD5D5
                D5C7C7C78E8E8E8E8E8E5858581F1F1F1F1F1F828282FFFFFFFFFFFFFFFFFFFF
                FFFFB9B9B95858583C3C3C1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F848484222222
                222222303030E4E4E4FFFFFFFFFFFFFFFFFFD6D6D64C4C4C2222222222222222
                22222222222222222222E4E4E42525252525252525254F4F4FF2F2F2FFFFFFFF
                FFFFFFFFFFF2F2F24F4F4F252525252525252525252525252525FFFFFF878787
                282828282828282828363636878787CACACACACACAAFAFAF4343432828282828
                28282828282828282828FFFFFFFFFFFF7B7B7B2C2C2C2C2C2C2C2C2C2C2C2C2C
                2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2C2CFFFFFFFFFFFF
                FFFFFF8A8A8A2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F5656
                56A4A4A42F2F2F2F2F2FFFFFFFFFFFFFFFFFFFFFFFFFE6E6E67F7F7F4C4C4C32
                32323232323F3F3F727272B2B2B2FFFFFFFFFFFFCCCCCC3F3F3F}
              ParentFont = False
              Style = bsWin31
              TabOrder = 5
              WordWrap = True
              OnClick = BtnUCDistanceSaveClick
            end
            object EditMaxTrayTotalWeight_1: TEdit
              Left = 255
              Top = 284
              Width = 132
              Height = 26
              Alignment = taCenter
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'Calibri'
              Font.Style = []
              ImeName = 'Microsoft Office IME 2007'
              ParentFont = False
              TabOrder = 6
              Text = '0.0'
            end
            object EditMaxTrayStackCount_1: TEdit
              Left = 255
              Top = 254
              Width = 132
              Height = 26
              Alignment = taCenter
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'Calibri'
              Font.Style = []
              ImeName = 'Microsoft Office IME 2007'
              ParentFont = False
              TabOrder = 7
              Text = '0'
            end
            object btnTrayInfoSave_Jig: TBitBtn
              Tag = 1
              AlignWithMargins = True
              Left = 408
              Top = 254
              Width = 200
              Height = 55
              Margins.Left = 5
              Margins.Top = 10
              Margins.Right = 5
              Margins.Bottom = 10
              Caption = 'TRAY INFO DATA SAVE'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Calibri'
              Font.Style = []
              Glyph.Data = {
                F6060000424DF606000000000000360000002800000018000000180000000100
                180000000000C0060000C40E0000C40E00000000000000000000FFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB5B5B51D1D
                1D00000000000000000000000000000000000000000000000000000000000000
                00000000000000000000001D1D1DB5B5B5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFF1C1C1C0000000000000000000000000000000000000000000000000000
                000000000000000000000000000000000000000000001C1C1CFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000000
                0000000000000000000000FFFFFFFFFFFF000000000000000000000000000000
                000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000
                00000000000000000000000000000000000000FFFFFFFFFFFF00000000000000
                0000000000000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFF0000000000000000000000000000000000000000000000000000000000
                00000000000000000000000000000000000000000000000000FFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000000
                0000000000000000000000FFFFFFFFFFFF000000000000000000000000000000
                000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000
                00000000000000000000000000000000000000FFFFFFFFFFFF00000000000000
                0000000000000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFF000000000000000000000000000000000000000000000000FFFFFFFFFF
                FF000000000000000000000000000000000000000000000000FFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000000
                000000FFFFFFFFFFFF0000000000000000000000000000000000000000000000
                00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000000
                0000000000000000000000FFFFFFFFFFFF000000000000000000000000000000
                000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000
                00000000000000000000000000000000000000FFFFFFFFFFFF00000000000000
                0000000000000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFF0000000000000000000000000000000000000000000000000000000000
                00000000000000000000000000000000000000000000000000FFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1C1C1C0000
                00000000000000000000000000000000000000C4C4C4C4C4C400000000000000
                00000000000000000000000000001C1C1CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFB5B5B51D1D1D000000000000000000000000000000000000C4C4C4C4C4
                C40000000000000000000000000000000000001D1D1DB5B5B5FFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF757575
                000000000000000000000000757575FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFBFBFB747474141414141414747474FBFBFBFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
              ParentFont = False
              Style = bsWin31
              TabOrder = 8
              OnClick = btnTrayInfoSave_JigClick
            end
            object EditGP1: TEdit
              Left = 231
              Top = 10
              Width = 70
              Height = 26
              Alignment = taCenter
              Enabled = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'Calibri'
              Font.Style = []
              ImeName = 'Microsoft Office IME 2007'
              ParentFont = False
              TabOrder = 9
              Text = '0.0'
            end
            object EditGP2: TEdit
              Left = 538
              Top = 10
              Width = 70
              Height = 26
              Alignment = taCenter
              Enabled = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'Calibri'
              Font.Style = []
              ImeName = 'Microsoft Office IME 2007'
              ParentFont = False
              TabOrder = 10
              Text = '0.0'
            end
            object EditUC1: TEdit
              Left = 256
              Top = 41
              Width = 132
              Height = 26
              Alignment = taCenter
              Enabled = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'Calibri'
              Font.Style = []
              ImeName = 'Microsoft Office IME 2007'
              ParentFont = False
              TabOrder = 11
              Text = '0.0'
            end
            object EditUC2: TEdit
              Left = 256
              Top = 70
              Width = 132
              Height = 26
              Alignment = taCenter
              Enabled = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'Calibri'
              Font.Style = []
              ImeName = 'Microsoft Office IME 2007'
              ParentFont = False
              TabOrder = 12
              Text = '0.0'
            end
            object BtnUnitCenterInput: TBitBtn
              Left = 408
              Top = 41
              Width = 100
              Height = 60
              Caption = 'INPUT'
              Font.Charset = ANSI_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Calibri'
              Font.Style = [fsBold]
              Layout = blGlyphTop
              ParentFont = False
              TabOrder = 13
              OnClick = BtnUnitCenterInputClick
            end
            object BtnUnitCenterSave: TBitBtn
              Left = 508
              Top = 41
              Width = 100
              Height = 60
              Caption = 'SAVE'
              Enabled = False
              Font.Charset = ANSI_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Calibri'
              Font.Style = [fsBold]
              Layout = blGlyphTop
              ParentFont = False
              TabOrder = 14
              OnClick = BtnUnitCenterSaveClick
            end
          end
          object CurvyPanel33: TCurvyPanel
            Left = 375
            Top = 3
            Width = 222
            Height = 314
            Color = clBtnFace
            TabOrder = 1
            object SpeedButton14: TSpeedButton
              Tag = 1036
              Left = 53
              Top = 187
              Width = 120
              Height = 41
              Caption = 'MOVE TO VISION'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -15
              Font.Name = 'Calibri'
              Font.Style = []
              ParentFont = False
              OnClick = SpeedButton14Click
            end
            object Image2: TImage
              Left = 50
              Top = 29
              Width = 166
              Height = 76
              Picture.Data = {
                0954506E67496D61676589504E470D0A1A0A0000000D49484452000006150000
                02910802000000DC7EBF65000000017352474200AECE1CE90000000467414D41
                0000B18F0BFC6105000000097048597300000EC300000EC301C76FA8640000F5
                584944415478DAECDD5F8C235979F87D2FB30C3B3B3B03CD2A70819468ADB988
                F4CB05C28CA228B989F0B48490401163778222C802633701054894B67B05244A
                42DA9E28C90D8ABADC89729380DA1E8172B15AE4F628911082E0F44811E40DDA
                38B3E46281046A3799D9D9DD99DDE9791FFCD0676BAAEC7255B95C7FECEFE7C2
                E3F6D8EE2A77F9D4394F3DE7390FFCEFFFFE6F01008025F2A637BD29F893D7D6
                D69E7FFE79FF2738EFAC8D397F7CFDEB5FFF810F7CE0FFFDBFFF97F67E030000
                008BF200F1230040D67CF7BBDFFDCA57BEA2F79F9F24ED0D7CCDDA31B95F2C16
                E5CEDBDFFEF6F7BDEF7DA74F9FF67FE1D1D1D1AD5BB7CE9C3993F61E00000000
                B3113F020064C5F5EBD7FBFDBEDC6A90C8DC999922941D26594963496F79CB5B
                3EFEF18F939A04000080BC237E040048D3F7BFFFFDBFFFFBBFFFD18F7EA4D1A2
                8223E128ED4D9B9773BEDB5BDFFAD64F7EF293BFF88BBF98F646010000005110
                3F0200A4E07BDFFB5EAFD77BFAE9A70BE3B423CD364A7BA316CB39CDEDF1C71F
                7FCF7BDE93F6160100000041113F020024EA7BDFFBDEDEDEDE37BFF9CDA5C933
                8A666D6DAD38A671A59FF9999F595F5FFFD99FFDD9B4B70B0000009880F81100
                2090D3A74FDFBA754BEFDFBD7BF7C48913AE279C3A75EAA5975E723EF2E4934F
                3EFBECB3B55A4DEE5FBD7AF5339FF9CCEDDBB70BC733D4D2DEA1F4695D275381
                BB582C7EF8C31FFEA55FFAA5B4B70B00000070237E040098CB9D3B774E9E3CE9
                7AF0C9279FFCC4273EE1AD7B4DD8C8878922FDFAAFFFFAC58B17D3DE1C000000
                E035C48F000071FAF297BFFC277FF227CE45D3F2B5805A46E8D4B6B7BCE52DBF
                FBBBBF7BEEDCB9B43707000000AB8EF81100201E3FFEF18F7FE1177EE1D4A953
                E611624673321949A64CD2830F3E489924000000248FF81100201EFBFBFBF57A
                BD705CD66711BF22C83BEB1A67136F35136ADA5B996CA989B72932ABB6396349
                B255BFF66BBFF6D6B7BE35DD6D030000C08A207E040008C7B6ED471F7DD4F5C8
                E1E161BBDD96DB64B6C184844C6CC5FC681E74DE71BECADC71068626868D9C77
                CC8FD7AF5F2FA4175A2A1ED3BD938D3979F2E41FFDD11FBDEE75AF4B784B0000
                00B052881F0100A2B36DFBFAF5EBBDB18506534CE8C7194029954A2660944C00
                E5E8E8E8BA830695CC9D0436C0907DD7A8D9E1E1E18B2FBEF8E77FFEE7EF79CF
                7B92DC00000000AC14E2470080409E7BEEB937BFF9CDE6C7A3A3A3C160D0E974
                0E0F0F17173A31D1220D9738538A52CFB8914FA0E0485392CFC1155A5AF40678
                D3A9E4CE134F3CC1DA6D000000881DF123004068FD7E7F30A693B962644AFC38
                6769954AA5D4A34501D9B66D329234B2964C38C9C492CAE5B2A6656D6C6CA4FD
                610000006079103F0280D575EAD4A9975E7A49EF7BAB1A791D1D1D1D1E1E0E06
                835EAF176FE448C346725B2E97E58EDCE62560E44FE7F71D8EC535D3CDA788B8
                7E8CFA19CA731E7CF0C18F7EF4A3697F060000005806C48F000081D8B66D26AC
                C5F8B6A552495366C4CC0056AE69ED240DC06938694149491A423273FD363737
                D3DE75000000E41EF12300C06CFBFBFB9D4E27AE79583A25CDCCB42A168BCB91
                6D54180789FCF745AB26993249269634F1538AF6699B35E9B46E548110120000
                00E646FC080050387DFAF4AD5BB726FED76834D2E5D5E69FB0A6A122AD845D2E
                97CF9D3B97F67E2F903390E41354928FD714DE8E3D2949A7049A625254440200
                004064C48F0000AF397BF6EC8D1B37CC8FCF3EFBEC073FF8C1C813D64C068D46
                312A636127A9CDCCE8590E5A5BAAD7EB693829C62892667BE92D894800000088
                86F811006082071E78E089279EF8E217BF38672043138E1A8DC6DADA5AC0C8D1
                B2068C02EE9796DCD640528CA5A6347E247F8ECB972FA7FD49000000207F881F
                0100DCBEFFFDEF7FE4231FF9C637BE11FC25DE623DA552A952A96861ECA58C07
                198B0878693A92A9B71DD76A776691BBEDEDED143E29000000E416F12300C06B
                6CDBFE8BBFF88B39D38EB436B6387FFE7CDA3B947B4747478331532069CE37D4
                75D9E46FB4B7B797F6CE0100002037881F01007EEAA9A79E7AFCF1C75F7EF9E5
                682FD7C044A552A9D56A618B1C6126DBB64D21F358A248C562F1EAD5AB69EF16
                000000F281F81100E027BEFCE52F7FF8C31F8EFCF2B5B5B546A311A13C364231
                65B66399D4A6894857AE5C497BB70000009075C48F0060D53DF9E4939FF8C427
                22A7B4E8C26ACC564B9299D4164B8D6DF90B5EBB762DED7D02000040A6113F02
                80D5F5B5AF7DEDD2A54BB76FDF8E163CD24ACC954A657D7DDDF9F8B22EA09630
                D7C738F1531D0E87A63AD23C93DA98CE060000007FC48F0060753DF6D863721B
                2DEE502A951A8D862B72E442202919B66D773A1D2D8D34CFFBACADAD3DF3CC33
                69EF0D000000B288F81100E4DB238F3CF2C20B2F847AC90F7EF0836F7FFBDB5A
                432742F0686D6DAD56AB552A9573E7CEA5BDF72BCA1B989347AE5FBF2E7F50F9
                B3CE33A38D101200000026227E04002BE7E8E8A8DD6E474B57D152471B1B1BCE
                77D35806D946596066B41145020000408C881F01C0CAD9D9D969B7DB615FA569
                478215D6B26F341A753A9D79D66823840400000027E24700B0428E8E8E9ACD66
                A7D309FBC220D58E9029F2B73E3C3CD4BA48FAC8DADA5AD8E98A7412000000A0
                881F01C092B36D5B33868E8E8EEAF5BA892604A76947543BCA05EFAA6D5A1429
                C2DF5D91880400008002F123005811B66D379B4D5710615A428A79BC582C6AF0
                88C246B9A60BB4B98A22854A47A2B7000000B0E2881F01C0F29B183C9A69DA9C
                35EA64E794164592C320C2A27B054248000000AB8DF811002C213367AD300EF7
                54ABD5C16010EA1D2A954AA3D1F09FB3462029E3BC7F202D8AD46C3623AFCE46
                B70100006035113F02806516AAE69199D054ABD55AAD16B1A19C9A19D7B36D5B
                0E894EA7F3FC58D8F7A7E7000000B082881F01C0D28A50307B6D6DADD1686C6E
                6EFABC2771A5E5301C0EDBEDF6E1E1212124000000CC44FC0800968A73B5B566
                B3D9E97482BF766D6DCDB22C6FC1232C2B39483A63D7AF5FD74728AA0D000080
                89881F01C072DADADA0A153C2A168B96659D3F7F3EED0D47D246A351BBDD9E98
                A736339C442F0200006045103F02801C70D6C30EF29CDDDDDD66B319FCFD091E
                AD38572212594800000070217E0400CB667F7FBF5EAFFB3FC7192028954AAD56
                CB193CA2C8D16AD28A486197EA537427000000961BF12300582AFD7EBF5EAF07
                4F1E29168BDD6EF7DCB973696F3832C1B66D4D44A2A8360000009C881F01C0F2
                188D46F57AFDF0F030E0F34BA5926559AEE011C947ABC6FB17DFDFDF6FB7DBA6
                A876706B6B6BCF3CF34CDA3B04000080F8113F02807C732EB856AFD72756419E
                6866CD230249AB4C8B6A0F0683B0894884900000009612F12300C89F89E5B477
                767664C01FF01D2898BD52A68502CDE3139F200FCA11C55C3600000014881F01
                C072E8F7FBD56A35E093D7D6D62CCB5A5F5F4F7BAB91037268359B4DE6B20100
                00AC38E24700907BC3E15046F801CB1EC9A8BED56A6D6C6CA4BDD5C88DD16824
                07588475D908210100002C0DE24700906F41CA1EC930DE4C416A341ADBDBDBAE
                77A0CE119CBC8784732E9BF3700A829E060000C012207E0400F9B6BBBBDB6C36
                033EB931E653F2063026AECBD6E974822FF06790880400009077C48F0020C76C
                DBBE70E1C2B4DA34AE3C9172B96C5996B7F036105CE4B96C051291000000F28C
                F81100E4D5030F3CF0D18F7ED47FE69A512C16BBDDEEB973E75C8F938584B06C
                DB6EB7DB72E0B12E1B0000C0EA207E04003973F7EEDD13274E14C2CC5C73D6CC
                2660845830970D000060A5103F02805C9AB6E6DAC4DAC6DE9AD9401026DA3831
                EC280761BBDD662E1B0000C02A207E0400B9B4B5B5D5E974823CB35C2E77BB5D
                728E303F6F14C9B66D390EDBED768477A3070200009023C48F00207FF6F7F79B
                CD6690EA33D3CA1E0191B9A248F263AFD76BB7DBD3EAB8FB602E1B0000405E10
                3F02809CB16DBB5EAF079C34645996963D02168AB96C000000CB8DF81100E44C
                BFDFAF56AB419E59A954F6F6F6D2DE5E2C9B6925D86DDB6E369B01170474A137
                0200009071C48F00204F46A351BD5E0FB2E81533D790186799EDC873D90A4491
                000000328CF81100E4806DDB8F3EFAA8DCD9D9D90952AB786D6DADD56A31730D
                A9E8F7FB72940689722AE7A281744B000000B289F81100E446F0E4A34AA5D26A
                B534E4E4BF043B109CF310F23F9C742EDB603078FEF9E79DE1A1208AC5E2B56B
                D7D2DE57000000DC87F81100E4C6A54B9782149791E1FAC1C18173E61A912324
                4F8EBA76BBDDE97426068FFC834AACCB0600009035C48F0020BBCCB435BD5FAD
                5683241F351A8DEDEDEDB4B71DF889E170D86C36F5B80D9B884417050000203B
                881F01400ED8B6DDE97482543E2A97CB966599A81390BAD16824876EB475D998
                CB0600009011C48F00200764045EAD565D6B5A4DCCE668B55A9B9B9B696F2F70
                1FFFB96CFE98CB0600009005C48F0020077677779BCDE6B4FF3581A44AA56259
                16A58E904DD3D6650B32AF8DEE0A000040BA881F0140D68D46235DCA6AE6332D
                CBDAD8D8487B7B81A9CC5CB699F5B3BDFF4B22120000408A881F0140D6EDECEC
                04A97C44F21172E1E8E8A8D96CF67A3DE6B2010000E408F12300C834196CD7EB
                F599B587655C6D59D6FAFA7ADADB0B4C2647B233B8D9EFF79BCDA6ABA4574074
                5D0000009247FC0800B24B86DCBD5EAFDD6ECF1C6697CBE52B57AEA4BDBDC004
                AEC891311C0EE5D8764ECC0C520849B12E1B000040C2881F014076054F3E6AB5
                5A543E42EEB02E1B0000405E103F0280EC1A8D46172E5C9839B4AE542A7B7B7B
                696F2C10942B23697F7F3F4892DD4474630000009241FC0800B26B777757C6D5
                33E347AD566B7373B3307DA2109071DE450683CF652B1045020000583CE24700
                905DEF7AD7BB0E0F0FFD9F532E972DCB7AF4D147D3DE58602EB66DEB5CB608AF
                652E1B0000C0A2113F0280241C1D1D9D3C79F2D4A953376FDE74FDD7D9B367BD
                4DF1EB5EF7BA7EBF5FAFD783271F397F175948C8A9DDDDDD5EAF37336C3A115D
                1A000080C5217E0400297BE8A1875E7CF145E7231AFDD9D9D969B7DBFEAF2D16
                8BDD6EF7DCB973C48C905FAEA377381C369BCD68212412910000001684F81100
                A4E3D4A9532FBEF8E2BD7BF7CC2332843603696F3998892A958A655966EC4D14
                0939E273B8DAB6DDE97466C64F272284040000B008C48F002039A74E9D7AE9A5
                97663E4DC6D5CD667366219862B1D86AB5D6D7D7D3DE2D209C20814E794E672C
                C2BA6C84900000006247FC08001225A3622D69F4FC983E68EEEB50596E0F0F0F
                670E9B4BA5D2C1C10109475862FD7EBFD3E9CC4CC49B48BE2057AF5E4D7B0F00
                00009604F1230048C26834D220D1F5EBD79DD1227DA4300E21857DCF46A3B1BD
                BD9DF69E018B65DB76B3D9ECF57A115E4B22120000405C881F01C0BC6EDEBC79
                E6CC99A3A323130F7ADEC184879C11A208D1221726AF612999A96DCE396EDEB9
                6C6B6B6B01BF44F2CC72B9BCB7B797F69E010000E41BF1230008EDA9A79EFAF4
                A73F7DFBF6EDC278745A2A957434EB0A15CD1F24F2E1AA9C0D2CBD7EBFDF6EB7
                A3ADCB562E97AF5CB992F61E000000E418F123004BEBECD9B3376EDC303FDAB6
                FDE8A38FCE7CD5D1D15161527122934C34180CE43678FAC382B45AADCDCDCD89
                DB4F5009CB6A9EB96CC562F1DAB56B69EF010000405E113F02B0BA3454A44C41
                2265EE9BC851DA1B7B9FB5B535CBB298BC862513705DB676BBDDE974BCDFCA99
                515DCD1624110900002002E24700568B2E7FE68C0D996891FEA843D0AC058C5C
                CAE5B2655941D2A98025E08D2B39E7B2854D0624110900002002E24700969389
                1339573A2B8CF38C4CC0C8DCE68E77F21AD3D6B0F45C07F968346AB7DBACCB06
                0000900CE24700F2E7A5975E7AEAA9A7BEF9CD6F168BC552A924B7FAB83342E4
                4C2FCAE61CB4C864E8DBED76CF9F3F9FF6860029F399CB16045124000080E088
                1F0188D3830F3EF8EAABAFC6FB9E57AF5EFDCC673E73FBF66D33B9CCF9BFC562
                716DCC39196D69424513C92E1F1C1C30790D50FBFBFBED763B5A2E2121240000
                8080881F01C822DBB6BFF295AF3CFDF4D32699C8FB9CE50E12F92897CBDD6EF7
                75AF7B1D73D60035CFBA6C849000000082207E042084B367CFDEB87163D1BF45
                8682D7AF5F3F3C3CD4DB259B7D368D0C62F5CECC05A41A8D86ABF8110069373A
                9D4EBBDD8EF6728A6A030000F8237E0460811E7AE8A1975F7E79DAFF1E1D1DE9
                1D1321BAEE6026A32D1F132AD299775ABF496F0783812E29358D3CADD56AADAF
                AFA7BD134016F5FBFD66B3E96A3A022ED04622120000800FE247001265964573
                2A1CAF83B67C4946CEF0902B5AE48A22C99DC3C34319FAFAC78FCAE5B2655914
                3F02947716E770386CB7DB83C1A0103872649085040000300DF123000B2443BB
                694BA12DD3AC340D09AD79B8669969BE954FC5A27EBF5FAFD7FD3F934AA5B2B7
                B767DE90FA478097CE658BB62E9B7C9DCBE5F2E5CB97D3DE090000806C217E04
                6051FEE77FFEE76FFEE66F966C32DAB450913C3EFF9CB2ADAD2D19F1FA3FA7D1
                686C6F6FA7FD310039B0BBBB2B5FA8682D8F33500B00008002F12360D59C3C79
                F2CE9D3BD3FEF7CC9933376FDE8CE5173DF5D4538F3FFEB84FF1A3BC585B5B2B
                954A450779F0DCB9738BF85D972E5DF25F408AE2D94028CEB96C6131970D0000
                C089F811B05A4C84E8E1871FBE75EBD6BD7BF74E9E3C79EAD4A9B0612379C9FF
                37F66FFFF66FDFFAD6B74C19A325A3C5539269278F8E8EAAD5AAFF40B7542A35
                1A0D8A6703C1D9B6DD6EB76766F679696AA17CE9484402000028103F0256CDD9
                B3676FDCB811F0C95FFFFAD7DFFFFEF79F3A75CAFB5FC56231A7058C9E7BEEB9
                EB93A4DE18CA28B75AADCE2C9EDD6AB51694FD042CABA3A3A35EAFD76EB735CC
                1DAAA8B6CE4EBD7AF56ADA3B0100009032E247002690E1D62FFFF22FFFFBBFFF
                7BE178B1F9DCC58972D7B80D87C37ABDEE9FC655ABD55AAD1635B3017F134BCB
                CB57CCB5BE61F04052698CA2DA00006095113F02F053376EDCE876BB4F3FFDF4
                E158DA9B13427EDB31E728777F7F5F06B7FEA3598A6703C179A34891E7B215C6
                4997CC65030000AB8CF811B0D2FEF55FFFF50B5FF8824E43D3CC978CE71965BC
                C932E3D589E90FFE2FD461ADFFE76F59D6C6C646DA7B09E4987CD7E48B265FB7
                086D9D9643BA72E54ADA3B0100009002E247C06AF9C10F7EF0777FF7773FFAD1
                8FB4E84F960B18795B2719F8996D5EB21AD2B26BCD6673665A44B7DB75EE78D8
                2815B06AA68574FBFD7EBBDD8E9668592A95CAE5329980000060D5103F0296CD
                B3CF3EFBB6B7BD4D064B26AB48C83049EEEB6DDA1B38C1B48648F7E2D1471F4D
                7B0317CEB6ED7ABDEEBFF8DADADA5AB7DB3D7FFE7CDA1B0B2C03F9D2359BCD5E
                AF17E1B5C562B15C2E530E090000AC14E24740B6C8902642B8E4EAD5AB1FFFF8
                C7DFF6B6B7552A9552A9A40123A1D93A69EFD37D6AB59A6EE46A26CE4CCB180A
                B2F89A7C689665B1F81A10175D976D66DDB18998CB060000560DF123206667CE
                9CB979F36662BFEEC9279FFCC4273EA1F7D78E6533CFA85C2ED76A35B95DCDC8
                9193378A341A8DAAD5AAFFE26BF2D1B55A2DE247402CCCD730F25C36696CB5A8
                36894800006015103F0272E9A9A79EFAF4A73F7DFBF6EDC2B8E275F055A85321
                43AC4AA552ABD55661269A0F6FD8C83C12307E6459D68A7F86C022C817B0DD6E
                0F0683080D29EBB20100801541FC08C881871E7AE83BDFF94EAFD79BB93E57F2
                6686AE686482180E87D56AD5FF93ACD56AAD568BEC2D60116CDBEE8C31970D00
                006022E2474046C960460B1899EAD7195C2BAD582CEA26990DA34999696209A4
                E17078E1C205FF1736C6881F01B198F84D3473D94C643C787667698CB96C0000
                6059113F02B262341A99E5D2CC2AF5592B80ADF53EF49661528C64D45AAD567D
                9E209F79A3D1D8DCDC4C7B4B811CF399436A4853DC6C36FD17439C469BC7AB57
                AFA6BDA3000000F1237E04A4C6B66DB9D5089133CFC8BF088E5302658F4C4D6E
                4644B198B6FEDAFEFEBEFF2250F22768B55A1B1B1BFEEF03607EF2FD6AB7DBF3
                CC17A673050000960FF1232066B66D4FAB70AC637EB935D122E7DCB4B437FC35
                9A5E44C02849BBBBBBCD66D3E709F247B12C6B7D7D3DED2D05969C69A8078381
                7C2B8307F49DE40B2BB7CF3CF34CDA7B030000101BE2474020274E9CB87BF76E
                C1131EF289163969CCE870CCCC4DCB4ED8C84C4953729F3845C2A2C58FC84202
                162AD45C3657422821240000B064881F013FF5C8238FBCF0C20B71BD9B0CEC65
                2061E6A33927A9A5BDA3AF4D49731633D225A80946A44227CB089FE7C81FC8B2
                ACF3E7CFA7BDB1C06AD175D99C5FCFE0138709210100806542FC08888DC68C94
                4935CA48016C67CCA8744CEE1330CA889D9D1DFFF891FCB10E0E0ECE9D3B97F6
                9602AB687F7F5FBEA191E7B2896BD7AEA5BD1300000073217E04CC30B39E913E
                E7F0F070301898D5D3D2DEEA9F7026169989697A3D9CB051D66C6D6D753A1D9F
                27C89FAFDBED123F02D2321C0EDBED76E475D9A41DDEDBDB4B7B27000000A223
                7E0444341A8D4C0D6C6749A31437C955C3C8DC06A9D0E483223B0998997FE48C
                1FF1170152A173D922ACCBA6B1FB72B95C2A95CC2A8A000000F942FC08709B96
                70A435B09D558D525F3ACDD43092FB3A1F4D538DE60C182179972E5DEAF57A3E
                4F903FEBC1C1017F5920312650EB8AD8EEEEEE763A1DCD330D5E0B499FAC21A4
                CDCDCDB4770E00002034E247C0543266905B1D1B68B4C8CC504B77C39C13D322
                078CC861C914E6AF0139321C0E9BCDA69C14C2BE505BEF72B9BCBDBD9DF64E00
                00008443FC082BC7A79E91EB6987C7CCF4B4B4B6D9D4BDD68147611C4DA0FAF5
                3209123F72E51F1101045224E78876BBEDFFB59DC684FE49440200003942FC08
                2B2160CCC89434D2E969E636956D7696317256352264B094C83F0272E7E8E848
                CB2145484A652E1B0000C81DE247C8A23367CEDCBC79B31038EE33CDCC974BEF
                DF192AD26CA314538D9C0123BD3A4DBC604544C83F029005F3CC65D34424E6B2
                0100805C207E8495A3558D0AE3C24683C1C039432D95ED3101A372B9AC612379
                9024A3553373FD35394E0E0E0E8827021964DB76B3D9F496C00F525D9BB96C00
                00202F881F61B568552353063BAD5423678691C9392266B4CA66C68F5CF3D728
                7E04A4C8FB0594934BAFD7936F7184738AB97E40080900006419F1232C3F8D19
                5D3F269DFB08130DE6A41122936AA4D31682E792102C587ABBBBBBCD66D3E709
                72CC74BBDDF3E7CFA7BDA5007ECADB32EFEFEF773A9DC873D9CAE53221240000
                9059C48FB084B4AA91D2AA4683C120F95423190F14C6179635CF486FE7AC5F43
                206959C9B0B35EAFFB3C81F811900B91CB2115C673D9341169636323EDFD0000
                0070237E84A5A291232D69A493D4929F9EE6AC67248381B5B180411F57788868
                D1EAE8F7FBF57ADDE77095A3C8B2ACF5F5F5B4B714C00CD3CA2105A1171B5897
                0D00006410F123E49B16C3D68969CED5D322ACA63C0F8D1939EB19C97D423F08
                6E676747469B3EC72DF1232053FCC3FDB66DB7DB6DFF4515A7912FBB6621B12E
                1B0000C814E247C8AB575F7DF52FFFF22FE5B6308E1F99C851621BE02A69A4DD
                FD083123928C202E5EBC38180C7C9E20475AA3D170A52470F00099255FCF4EA7
                13ADA2B69E59E4B4227748440200001941FC0879F2FAD7BFFE539FFAD4952B57
                5259344D696E91DC562A15E9DFB39E3A62F1A637BD69E6735AAD56AD56236004
                E4C8EEEEAE2B8424A78F80A730D6650300009942FC08B9F1A52F7DE989279E48
                2572A4358CB49E9199A1C6301E310A123FAAD56AAD568B030FC8977EBFDF6EB7
                A355D436A71E424800002075C48F900F5FFEF2977FEFF77E2FF9E96986E61CCD
                B97A9A0F2622AD38E247C07298D8980F87C376BBED3F47751A33978D72480000
                205DC48F905D1A33923B89858DD68E3917500B355C270C84681E7BECB199C7B9
                1C90AD568B2993401ECDB3289BD045D998CB0600005244FC0899934AAA51E1B8
                771E216604CC2F48FE911C999665113F02B2CCE72A82FC577B2CDA3BB32E1B00
                004817F12364C28D1B37A44BFDC52F7EB1906CB691B9A21B6D7A1AD94688D1CC
                10921CA896659D3F7F5E7FE4F003B26CDA37747F7FBFD96C463BD399D3162124
                0000903CE24748C7B7BFFDED0F7DE843CE0E743261236F5523B99D7F10CE481E
                F30B1B3F029017AE73C4FEFE7EBBDDBE7EFD7AB477632E1B00004805F12324EA
                BFFFFBBFDFFDEE77A71236D2CBB6D1AA1A0109083285CDB2AC8D8D8DB4B714C0
                BC86C361B3D98CB6285B8175D90000401A881F21095FFDEA579F78E289E79F7F
                5EBABCCF8F25F37BCDB2355A33427E246C84CC8A103F22F10DC8AFD16854AFD7
                E7092131970D00002489F81116EBC9279FFCEC673F5B18E71925163632258DB4
                AA512C33D48004CC0C21351A0DC68AC0D2B06DBBDD6E773A9DC8EFA0E7BBBDBD
                BDB4770500002C3FE24758AC77BCE31D1A365A74F0C859D848B38D2616C38E31
                5F83D40FC46E66FCA856ABB55A2D0E3C205FF47C31F1ACA18BB2753A9DC86749
                3DF1C99D2B57AEA4BDA300006099113FC24F997EADB9F3E0830FBEFAEAAB11DE
                EACE9D3BFFF44FFF34188B5C1FD44527BE4D7CDCE4F097CB659FA5CDA775DC5D
                7B0DA46866FC480EF256AB454A1DB064E65994CD90B3E133CF3C93F6AE000080
                A545FC08119D3973E6E6CD9BAE077FFCE31F6F6F6F1F1E1E2E3AE7C814363293
                D4420DA78916219B66C68FE4686F341AEBEBEB696F298079B9CE44FD7EBFD96C
                CE73D1452FB4D0AF0300000B42FC68E5D8B63D71625790174ADFD4FC687ABD77
                EFDEFDDBBFFDDB7FFEE77FBE3EB6D0796A5AD54873F5F50E61202C19FF10927C
                071B8D062B2E014B69341A359BCDC16010F91DCC699A44240000103BE247F889
                3B77EE9C3C79D2FBF8891327EEDEBDEB0D391D1D1D69B4E8F0D842538D4C6D23
                4D388A16FF8A1D494C58044A6803CBC73B577ADA198410120000C82CE2470841
                FABB72AB61A35EAFB7D0B051C131494DC346046BB00A66C68F2A958A596B8920
                26B094B6B6B6E65994AD701C4522840400006244FC086ECF3DF7DC9BDFFC66EF
                E3B66D0F06835EAFA793D4E68F1C4D2B89ED4C35923B616B1B01B916A48476B7
                DBE54B012C13572C78FE45D94C1692DCB976ED5ADAFB0700009601F123CCA061
                A3C3C3C3EBC716F48B4C49232D899D91496A40F2FC4348F21DE976BB3E4B0D02
                580EFBFBFBED76DBE7B43BED328C93B418F21C12910000C0FC881FAD8AD3A74F
                DFBA756BE27F4D2C72243F6AB4C8048F16B1557A8154C346954A85496A402140
                FCA8D1686C6C6CA4BD9900166EFE45D90ACC6503000031217EB4D2264E55D3C8
                51AFD71B0C068BCB362A8CC346E572B952A9B08C1AE034730A5BAD566BB55A05
                C732880096866B2EDB68346AB7DB7252D61F83E41C791142020000F3237E84D7
                BAAAD249D5B091F44D638C1C393BBB725FC346C5633E03606A03633551020958
                29134F76CE076DDB6E369B26841499AE674A39240000100DF123FC246C74784C
                6B63C7FE2B7425359DA7A6C123FFBEB217B124AC144A2001709ABFA2B6D2D3F1
                D5AB57D3DE210000903FC48F5682ABB69192CEA8068C7ABD9EDC5950D848BBAA
                3A4F2D60496C4245C0CC14A4838383F3E7CFA7BD9900E612F67CB7BBBBDB6EB7
                E7395F6B1670AD565B5F5F4F7BEF010040CE103FCAAB8921A1803472D41B5B44
                D8A830EEA196C734E728F978104128E4DACCF851ABD59211200739B06A62A9A8
                2DE7656940E41C4D1A230000088EF8D16A190E87663DB545D4C6D6496A1A3392
                DBC8112E60C50529816459165F316005C9A9BCD96CCAA97C9E3791D3B4E6085F
                B97225ED1D020000F940FC6825D8B66DCA1B6979EC78DF5F27A9E93C35C19816
                989F7F0849BE749665310305584DAE45D9E644571000000441FC68797867B41D
                1D1D699E9159552DF65FAA95142A954AA6C2464C5EC3129899826459D6C6C646
                DA9B09201D72D2D78ADAE611E76AA7A1C80BE5F699679E497B9F000040A6113F
                5A5AA3D1683018F47ABD452CA9A661232D6F2422046B08F100FE66C68F6AB55A
                ABD5E27B04AC0ED7A9537EEC743A7356D45684900000C04CC48FF26A5AFD6C9D
                AA668A1CC51B39328BA96979EC087537171D36222C85A511A40452ABD5A2FC2D
                B0F49CA7366F08A9D7EB359BCD394FF71A3F2A1042020000D3113FCA316708C9
                4C551B8CC55B1B5B4B6C9AF2468C578164CC2C81D46834363737D3DE4C0029EB
                F7FBED767BCE8ADA05B2900000802FE2473933B1C8D1F3CF3F3F180C3A9DCEFC
                7D47AF62B15819933BCC53039214640ADBE5CB97D3DE4C00E91B8D46F57A3D96
                6E805E34BA76ED5ADAFB040000B285F8D1A24C9B5F16EDB5D3DE6D381C9ADAD8
                B14F552B97CB1A368A16390230A799F1A352A9D4ED769D7988FA55256E0BAC20
                E92A349BCD581665231109000078113F4A930CF064985770848702468EE441AD
                70147B91232D8CADCAE5324350204533E347C562B1D56AADAFAFA7BDA5003241
                1765EBF57A54D4060000B1237E94273A554DCB63872D72E4BFACAF7613356654
                A95422674E018817ABB001086B7777379645D90A449100008003F1A3F8BDF2CA
                2BAF7FFDEB637F5BCD39D2D96AF1BEF39C158E002C4E9014A483830362BE009C
                F6F7F7DBEDF6FC8B69B02E1B000030881FE5C06834EA743AD20B3C3C3C8C77AA
                5AA552D1A96AD32247945301D2F5D8638FC9ADFF17DFB2AC8D8D8D025F58000E
                C3E1B0DD6EC772CD49E7B65FB97225ED7D02000069227E945D3202D4A96A7A1B
                D7DB4A2FB0582CEA54352A1C011977F1E2C5998163A6B001309CE1E3D168D46C
                3663E94268B7617B7B3BEDFD030000A9217E9445F7EEDDFBCFFFFC4FE9F069DA
                512CEFA9F58FB4FF27A34D66BB0079F18E77BCC3BF1D28168B96659D3F7F9EB4
                2360654DFBFA6B456DE94ECCFF2B346D59486B93F6EE02008014103FCA9C975F
                7EF9739FFB5C2C8BA7148EC34672AB85B14BA5924FE468E6E093D12990BC77BD
                EB5D878787FECF69B55A9B9B9B7A9FEF2900276913DA63B1BC9B74246AB59ACE
                990500002B85F851B67CE73BDFF9FDDFFFFD6F7CE31BF3BC8973A9352D6F542E
                97FD234700326B6B6B6B66EE807CC7BBDD2E612300131D1D1DF57ABD66B319D7
                A5A94AA572F9F2E5B4770B0000248AF851563CFDF4D3EF7DEF7B7FF8C31F467E
                0767D8484B5D0AE9E19D3B776EE2F349520072617F7F7FE6A84FBEF29665ADAF
                AFA7BDB100B22BAE45D90AE33647A7C333970D0080D541FC287D5FFAD2973EF6
                B18F15EE0F0045A69123AD50407808580E172F5E9C590157C67257AE5C212E0C
                C0C77038ACD7EB719556D4A9F1CC6503006045103F4AD3534F3DF5F8E38FBFFC
                F2CBA15E352DCC248FD76A35E9CC158B45A6AA01CB24C81436F9E21F1C1CF0DD
                07E0E20A2BF7FBFD66B3195708495A9E4AA5C2BA6C0000AC02E24729F8DAD7BE
                76E9D2A5DBB76FC75586407A6F5AE1486E4D1F9134046069C878AF5EAFCF6C31
                5AAD56AD56E38B0FC05FBC2124E6B20100B022881F25EA1FFEE11F3EF5A94FC5
                12362A1C478E74259469458E0A049280A5E03385CDE424928204C0C5D90770DE
                8F37845418CF6593DE0855D800005862C48F9270EBD6ADF7BCE73DFFF55FFF15
                4B79237D130D1B49778DB122B00A4C156DFF4269AD566B737333ED8D059003F3
                87905CCD1173D90000586EC48F16E5C4891357AF5EBD73E7CE602CDE2C71E99F
                954A259FC8113947C092198D46172E5C98198396C6A1D56A115606104490E51D
                43915E8AB442972F5F4E7BCF000040FC881FC5E9E4C99377EEDC313FCA78AFD7
                EB1D8ECDDF39D3A96AE5B16C0E0E095A010B15A48AB6B02C4B9743325F49EF1D
                0050B14F642BB02E1B00004B8AF8D1428C46A3C160A0C123D77FF9CF3D9948CB
                634B572CB395291994020908B8F0B6B4159665F19504E0CF9CBB63CF422A8C67
                D94B5BC4745A00009609F1A398D9B6DDE97406838137721481468E6AB59ADCC9
                CB68905812B038972E5DEAF57AFECF595B5BB32C8B2AB600820BB8C86328CC65
                030060C9103F8A8D891C5DBF7E7DFE1E9899AA2677721A8E219004C46E7777B7
                DD6E07A982440A12805016918554605D3600009608F1A318D8B63D38164BE448
                B3BE67CE56CB458026171B09E4857CA1EAF57A9014A46EB72B6DC8B4A5BB01C0
                DB26ECEFEFB7DBED786B211598CB0600C0B2207E148E6DDBCEDAD5D2F73A3C3C
                D4B4A3C8912353114967AB351A0D16560330CDEEEE6EB3D99CF93452900004E4
                EC5AC49885E42CF828F76BB5DAF6F676DAFB0A0000A2237E148EB38F351A8D3A
                9D4EAFD78BD6CD72F6AB8AC562656C5A9DA38C2711B0BA139018DBB6EBF5FA60
                3098F94CB3101B0004B7A0896C85F15CB62B57AEA4BD7F00002022E24741C998
                6D6D6D4D8323C3E15097579B3FC7DBD43972CD56231003609A802948B55AADD5
                6A6539F40C202DFE0D42C0526B1148B7479A2642DB0000E411F1A370B4D451AF
                D70B72F1DF9F595BEDDCB97369EF16D2470E17829386A85AADCE5CE4716D6DAD
                D16850730440048BCB42D29C6BE6B20100903BC48FFC38AB1D69A9A376BB3D7F
                E448AB00089F3A4700308D34479D4E27487640B95CEE76BB44240144B0B82CA4
                C2B846DBDEDE5EDABB08000042207E3481AB4876613C61AD3736672F6A669D23
                0008E2E8E8E8C2850B3353900AC75590C86B0310C1E2B2900ACC650300206F88
                1FCD301A8D74B65A90719A8BAB42B6D6395A5F5F0FFE0E0CF900B89866616767
                A7DD6ECF7CBE343E070707643B0208C8D5F75868161273D90000C891558F1F79
                538D9CFF757878D8E974E69CB0B6B6B6562A951A8D86AB42B64190084004C117
                6293F687E11980C84C1692F3C2588C6AB5DAE5CB97D3DE4B000030C3AAC78FA6
                190E871A390AD54FF2F6AB2A958AF48A4AA592334294B58051D6B607404032A8
                ABD7EB339F562C16BBDDEEB973E7F8B203F0376D318780CB3E46A657DA42E568
                03008084113F72B36DBBD3E9F47ABDEBD7AF477E13CD39AA542A72EBB3BC1A63
                3900F3302948339302A439B22CCBD5E0B0EA1F80E00206AC23D3D54548960400
                20B3563A7EE49ABC263FCA304CAB1D457E4FE9FD68A9A346A331FF788C411D00
                7FFD7EBF5AADCE7C9A344D9665996BFBB42D00220858762D3269A9A407C5BA6C
                000064D3AAC48F4CA86862C123194A5DBF7E5DD38EE699D82FFD9E4AA5D26834
                28550B2031172F5E0C12F5A6903680F92D3A0B4994CBE52B57AEA4BDA30000C0
                6D55E2473E6CDBEEF57A9D4E67CE096BB55AAD52A9F8CC56038045180E87329C
                9BD982313704402C165D0BA9C0BA6C000064D2AAC78FFAFD7EA7D3393C3C8C9C
                76A4B9D6D2CB915BE68300488077F6D9D6D69634657ADFA71692FC57B7DB3D7F
                FEBCEB1D98CE062094DDDDDD76BBBD88B5D80CE6B201009035AB1B3F1A8D46BD
                B1C869475AEA48D38E966CE8C56012C81AFF6FA53468D56A35486BE62CA4CD37
                1D4010136BED2FBA1692622E1B0000D9B112F12357CD23E9FD0C0603E9F41C1E
                1E467ECFB5B5B546A32123B189C54458D50840324C2313BC2889B45DCC0A0130
                BF5059489A1A3973B1482FBD56B7B9B999F6EE0200B0EA56227EE464DB76B3D9
                1C0C063EF33BFC7B365A245BBA32AE5247848A0024C6DBE048E356AFD70316D2
                B62CEBFCF9F369EF0480FC71353EA1B290228790B4EB75F9F2E5B4F71E008095
                B6CCF1236FDA914E580B32BEF2D2EE8ED6395AE2096B44C180FC1A0E87D56A35
                C8C04CDAB16EB76BBEF572CB171F403461CB694B874AEF848D2231970D008074
                2D73FCC8498655BAC85AE477D0F469317394450806405A2E5DBA246D5D9067B6
                5A2DE6830008C8BF6F13360BC9DC9F1842F249502A954AD213DBD8D8886BBF5C
                D71A0100808F5CC68FCCC9DE79D69FD603D0B4235D642DF26FD45247AE096BA1
                10545A11FCA1118D1E39F31F3FD21256AB55D3DC05598B6DDAC614389E010416
                210BA9582C5EBF7E5DDBA85093DA6AB51A73D90000485E2EE347C18D46A34EA7
                D3EBF5222F315B192B97CB1307510CAE6070302015AE034F23E6130B697B8767
                D2B25996A591770E60001138C3CDED31EF7326C686E4C152A924B7878787A156
                C235F504F6F6F6D2DE7B000056CBD2C68FE65F644D27AC4D5B610D00B2495ABF
                66B31970BAAEF3323E212400730A3B914D9A20B9EDF57A117A6BA552E9EAD5AB
                69EF3100002B6439E347A3D148FA22FE3D18FF691DE572B9D168CC33610D4B8F
                C136324BDAC06AB51AE492BE34779665ADAFAFA7BDC9009644A81052A95492EE
                963444F29208CB9B68046A7B7B3BED9D060060252C43FCC855F968381C369BCD
                C869475A9A71F95658039071F14624F7F7F7A5250C3275B7582C76BBDD89E172
                82A40022081B429226483A725B5B5BD1D639615D36000092B10CF123C3B66DE9
                AF84AD766412916410A5D58E169776C4600C4032A4B5A9D7EB01D7629376AFD5
                6A3903F1345600029AD85CF80483BC09E0A698D1EEEEAEBC2A543924C55C3600
                0012B03CF1A3E170A8A5B2A3BD5C33A8BD933818440148CC9C0D8EEBE5A3D1A8
                5EAF074CC66C8CC5B2061C80D5E1D36284CA4292F647A7A1F5FB7D2D5E196A45
                B60273D9000058BC65881FE97A43D2DB8870C1AA30EE7048AF45FA1C0C9900E4
                91770936F3E3FEFEFEC4B5D8BCA4256CB55A1B1B1B69EF0D805CF2069242D5F2
                17DD6E572FE38D46234D278FB019ACCB0600C0E2643D7EE4AA6DE4FA511F91DE
                C96030087E91CA79454BFA19B55AAD542A450E1E71AD7E15F057467E054F0128
                168B96659D3F7F5E7F742ECBEDBA03000199896C33F3899C4D90B436D270C90B
                43A52029E6B20100B020598F1FF9DBDFDF97BE45B452D9D24DD13AD9D14A7E30
                8E02900BB66D57AB556D275DE337EF70AE5C2ECBF8CD15A677A1F503E0CFD94A
                389BA0995C4D9074F334BB3CC85C36E773A48F77EDDAB5B43F060000964D6AF1
                23CD243A73E6CCCD9B37CD83A74F9FBE75EB5661529E91F7E5BD5E2F78914557
                CF433A28B55ACD67C96A0648009646BFDF6F369B015BCB4AA522E337128E00C4
                65381CD6EBF5804D9074CF2E5FBE6C7E1C8D469A661EE1F7BADE0A0000CC29A3
                F94726903451C089F113AF564DAB76C43009D3706C20A79C87EEEEEEAE8CC102
                BED014B29DF66E00108AAB09F2CF27B22CCB598B4DE7B2F9CFC39DF686CC6503
                002046198D1FF978F6D9673FF8C10F069FB3E6EC5294CB65191799EA1E5E0C90
                002CA550856C35CEBEB9B999F65603581EA610D24CD2045996E54A12D73CCAE7
                C742FD5EE6B20100109744E34767CF9EBD71E386EBC153A74EBDF4D24B415E7E
                F3E6CD2F7CE10BBD5E2FC23A6BD27BD052D9FED3E200205F8247BD4355219938
                7E0BF5EB00C0699E42486A381C369BCD08552FA541934E2073D900009853CAF9
                47AEFA47D3BCF4D24B1FF9C847BEFBDDEF46881C15C6D9CB8D46C33510F21F05
                31468213C7039643A82A24BA16D2C4E529F94600F0E16D22F491D16854AD56C3
                D66273BE9BA652F67A3DFFA500262A97CB57AE5C49FBB3010020C7161B3F0A18
                1EF271FAF4E973E7CEDDB8712378BAB2B31BA1579C1A8DC6CCB42386430096CC
                C4666D7777B7DD6E4F6B51BD4B0DB45A2D6984D3DE150079E56A88F6F7F7751A
                5A90D74AFB337122AD59972DECC630970D0080792C307EF4C8238FBCF0C20BF3
                BCC3A953A77EEEE77EEEF6EDDB01873A2ED24B68341A954A85C01000183B3B3B
                FE95689D26CE220180C8421542EA76BB13CB56465E978DB96C00004496DDFAD9
                B66DBFF39DEF943B610B252A4D3BE2B23900B848EB5AAFD7CDB86BE6D40F338B
                A440AA2680B9B99A207FA552A9DBED4E0C61CBFBB4DBED80A1281769D6F6F6F6
                D2FE240000C8998CC68FBEFAD5AF7EEC631F2B440A1EC958A856AB351A0D6A76
                00C044A10AD90A69545BAD16ED278058380B21850A617B31970D0080C464317E
                F42FFFF22F8D4643BA02A18247DAFF28954A32C89998EA9C1D268CE5BD0300C9
                08554B5B34C668A900C4627F7F5F9AA0804F96C6677B7B5BEFBBCA69CB7DB32E
                5BC042DA4E19EC0603009059998B1FDDBC79F38FFFF88F5D2B6BF870F61598B3
                0600C1F5FB7D19BF051F6E99211CB16F00F3DBDDDD6D369B419E299D3DCBB25C
                0BE93A4D9BCB1630A294B5CE300000D994B9F8917426E4F41F360FB9582CD66A
                B5898B7430BC018069828FDFD4B4E59000202CE9A155ABD5E085902CCBF2BF46
                B8B3B3D3EBF522CC655B5B5B7BE69967D2FE3C0000C8BA0CC58F1E7AE8A1DFF9
                9DDF099E79644897A2D16878AF4A11390280992284906AB51AAD2B80F98D46A3
                7ABD1EB0165BA55291F6C77F394833972DEC961042020060A6ACC48FE44CBFB5
                B515E17C3FB13341E4080026F2368FF2888CDF7ABD5EF037716621D1DE0208C5
                D568F4FBFD6AB51AF0B5CE4248D38C46A3CE58846DA3A83600003E32113FBA7A
                F5EA9FFEE99F860D1EF9ACB3B60A18B3019893B38C51D810D2B472DAAC0F0020
                AC5085905AADD6C6C6466152216DF334F951434861E7B2C9FBCB2D894800004C
                947EFC687F7F5F3A0D61E7AC158B45E940F8545204000424632D196549531CB0
                1049613CCA6A341ACE896CC489004413AA1092F400BBDD6E90C552FAFDBEF630
                C37632CBE5F2952B57D2FE540000C89CE4E24767CF9EBD71E386F3917BF7EE59
                96D56EB7239CD75BAD96ABEBC0D00500E611AA10899A9985040041D8B65DAD56
                03B63FD20F940EA4D62EF06F6DA459937EA62BB932C8A26C3E0BB30000B0B242
                C48F1E7AE8A1975F7ED9FCF8F0C30FCB39DBF9C834F2CC5BB76EBDE10D6FB873
                E78E791F796D7B2CEC16EB9C35FFEA89094B7EA4C4D80CC03CA6B521C3E1B05E
                AF879AF1A12124B933AD51A2BD021044BFDF97F627E035C5698590BC0D8E6DDB
                3A972DECD5CAC2B8C8E6DEDE5EDA1F0C0000591125FFE8CC9933AFBCF2CAC993
                275DF9448633D5E891471EB979F3E6BD7BF7F4473DA9CBB9BCDD6E872D6DB8E2
                058F00200111562FCA60581F401EEDEFEFD7EBF520CF9C5608699A7EBF2FDDCE
                E053748D52A974F5EAD5B43F180000322174FCE8E1871FBE7BF7EEEDDBB783BF
                E4C1071FD4CC233DBB8F46A399553634B5D82418AF8D4D2C78E4AD9898567489
                6BEC00F2655AABA54543426521552A9546A3A1D38A690C014413AA967FB158B4
                2CEBFCF9F301DF3C48FF73DA2F8A6B5136D941EF8334980080BC08113F3A73E6
                CC4B2FBD74E2C48950C1A3C2381DE9FFFEEFFFEEDDBB2727C8E170D86EB7C39E
                BC4BA552ABD59AD64558CDB1CA6AEE35904DCBF77D8C30914D1A6A19CB51990E
                C03CB41092343E41A69B49B3D3ED764DF2E3CC06478B274498CBB6B6B6562E97
                6399CBE60D21D1480200F22244FC484E78A74E9D0A1B3C728A302DA230BEACDD
                6AB598190100B10818D309558B44C958AED168CC4C1405001FCEC6C7998A3EB1
                39AAD56A972F5F763EE2DFE0C8FFF67ABD4EA713B63B5A605D3600C0CA4B6EFD
                35E90DB4DB6DFFB3B5B773E05ADC67669F806580961B7F4D2C3DE7416EEEFB37
                6EFE4FF3BE6DC0DF5E8814F42F168BD2686F6C6CCCDC18BECE000C578310BC10
                9268B55ADE85D2FC5B1869DC3A9DCEB489723E0BB4C538970D0080DC49227E74
                EFDEBD6EB7DB6EB7434D859093B70C42A2AD9CCAB004C820BE98C988109DF179
                72841092B3F5E68F0E208250ABF4FA17429AD624CA23D2B8F57A3D132AF2091B
                39C9D32A958A2BE909008055105BFCE8D6AD5B0F3FFCF0030F3CE07AFC3FFEE3
                3FE4142B630F9FE091F784ED5C5603C06A22F430D19C81A1692FF7AE45208DB6
                36CE9A3A1AEA0240E1FE45D9F85302F031B189B06DBB5EAF07AC98690A214D4C
                E1F41161B900C55C3600C00A8A2D7EF4C0030FDCBB77CFF5E0D7BFFEF5DFFCCD
                DF0C5BA4D05B2D9BB107BC382AB022E69F9536F185CF7BC8E3A666AD794405AC
                65EBE2AA5E173C9805600579433FA1AAB0790B2105146D69970273D90000AB67
                81F3D7E49CFA810F7CE0873FFC61A857F92FB506B830FEC4EA8870B49B385161
                1C122A8C234185E37890DE3A1F8F9DB7A276906A4D00A0F6F7F79BCD66C01092
                B436DBDBDBFECF9998A064DB76BBDD76CE650B686D6DED99679E49FB43020020
                218B8A1FFDE33FFEE3C73EF6B1B0C1A372B96C5996CF526B8C3780FCE2FB1B4A
                84796A1A2D2A8C4345D7C7343C64A24585E3285292988F0C20A089EDDED6D656
                A7D3F179952983502C16A5B5F12E015908D6A24E8C5505298AC45C3600C08A98
                2B7E74F6ECD91B376E4C78D3071E78FFFBDF7F787838F38CEB3C2BBB663A7831
                F8448A38FC90226F7122132DD296D6448B0AC79944CE9CA32C98D9C203C044D2
                D655ABD5E085902CCB3A77EE9C796DA873F76834AAD7EB1166EC32970D00B00A
                E68A1F9D3E7DFAD6AD5BDEC7FFFAAFFFFAAFFEEAAF42CD86F099B5CEB81D2AAD
                23812310499A78BC69356B57B9228D19158E6B15652754344DB95C6EB55A665C
                070041680358AD56BD1DCB89C941954A656F6FAF10B8789CEB69B66D379BCDC1
                60C05C3600005CE29FBFF6ECB3CFFECAAFFC4AA8936E63CCB5BA2A83F674F1F9
                63C5F9177BF66FAC26FEAFCF1D1719BD141C51A1EBC7CC4CB4B43F9BE8747649
                B95CF67E02D44502E02354212469673637375D0F866A5B7677773B9D0EEBB201
                00E01473FCE8BBDFFDEEBBDFFD6EFFB3BBF36291DC6F341ADE733C0064DFC469
                65D37EF47F13DBB6AFDFCF542C5A3EE69A41DA1B0220D35CADE8CC424886742F
                2DCB9A580829B87EBF2FBFCE356F2E4839A452A974F5EAD5D43E3500001626E6
                F8D1638F3D16FCDA38C12300D9B7887418132D7216B7762D94B6DCCAE5B2B4FF
                66A9CD68A137002B455A867ABDDEEBF5823CD9673D5FFF16C6F9BFBA2E5BC0A0
                951373D900004B29CEF8D197BFFCE50F7FF8C3019F5C2C1665F06056E461F090
                297CFEC04411BE1A5AE55A3389BC01A365CD300A424677B55A8D75D900F870B5
                BAC3E150EB5B07796DA552B12C6BCEEEA5BCA4D3E9B4DBED08917DE6B2010096
                4CB8F89173C1B5471E7944CEC1E6C750C123967306907191A3A81A302A8CD388
                6490737878E89C9296F66E658B9C0B6A63665D3682D700FCF5FBFD7ABD2ECD69
                90A964D2DB94162642CCC8F512F9A5ED765BDA73D733676E03EBB201009649C4
                FCA33367CEDCBC79D3FC38180C2E5EBC18F0B55A3FD567523AE30700D9E75DB2
                C7192D3219464146387921FBA2B7CE3BE647D95FB36251A8BDAE542A8D468375
                D9004CE36A6F777676DAED76C0D776BB5DED73CED9BD1C8D46F24B9DB3E70236
                74CC6503002C8D28F12357F0E85BDFFA56F00A85338347C808A2788097738DB0
                89B5AEF536A701236F60C875BF306EC35D4FD607E56391C1D5603090C195F712
                7D61D6408B530300AF695D116721A4201940DD6ED71BA18E3C972DDABA6CB1AF
                770C0040F2E6AD7FF4677FF6679FFFFCE7033E991102803C923143E1B87A9186
                8A9C91A37C458B4CD0C71521D2C090B96FC24661C757C3E1B0D96C4E0C21CDDC
                B046A31161A6098015341A8DAAD56AC0388E342C972F5F8EEB57F7FB7D69E522
                849028870400C8BBB9E2473242B874E952C033A8772DD524335CE2FA5DB16F73
                5A693ECE348A643660A5129A967867F3B56B13B776E2C1EFBDAF3123132D1A0C
                06F9AD61E48C076978481FD15BD793E76F196CDB96C155C035925CBC73D9A6FD
                9900AC38530869E633632FBB19792E1BE5900000B9163D7E74E7CE9D0F7CE003
                32A60AF2649FCCA3951D0FACCE8EAFCE9E2EB70CFE1DFDC343D1B6DC55C6C804
                8C721136D21C22676CC86415153C33D1E6F96BCAA7642A5E4F34CF8A45A552A9
                D168C8F92283871C804CD9DDDD6D369B419E290DCBC1C1418CC1686906752E5B
                D8568E72480080FC8A1E3F927376C0B1810C606430602EFB302400908A89A125
                E77C3453F43AE37946261E64024605479291B9937A4BDBEFF7657015F032836B
                07BD73D9387700F0DADADA927626C8332DCB92BE68BC2DC9B475D9662A954A57
                AF5E4DF2830200607E11E347C3E1B05EAF0799B9167BCE708A18BD20088E9354
                B83E769FBF826DDBCF1FF3E619658D0915E98FCEDC22197E14C683902C1F6FAE
                591EA1D665ABD56A8D46E3D1471FE53B05C0C9B59481F448834470A4B5B42C2B
                F6A51EA5956B369B1A280FD5C491880400C89DA9F1A3B367CFDEB871C3F5E043
                0F3DF4F2CB2F3B97BD98A9D56A6D6E6EBA1E643080A5C7419E98201FB516333A
                3C96E5809172CD4133158B0AC7B124ADD0948B636C9EB96CD3E63EE765DF0124
                207841EB46A3B1BDBD1DF9174DAB1D293F4A1317612E5B8175D90000B912227E
                A4C123B9B3BFBF2FE7E920E7C84AA5B2B7B7677E0C58AC2419591B7E646D7B80
                3C72D55AD65091DC6AAA51615CC6286B612367596BD7DA67911741F39A59B168
                D126CEF2705EAB9F76DDDE35031A00BC5DA6808590A43DB12CEBFCF9F38BD824
                2D87E40A6305C948625D3600405E8498BFA6676B679AAE0F1DF32CE8249D22A2
                3C4066798B1969E428C22ACB0BA2030953D3DAD42D72E619856A61528F0A85DA
                8CE170A8E5902284F06A63E7CE9DA31106A05C170C2E5CB81064165BA55291DE
                E9829A11EFBA6C01B12E1B00201782C68F4CF2D1CECE8E9C1A83BC44EB14FA3C
                81CC23AC080EB945D04FD5B6EDC238AB48F38CCCDCB4B4B7EE352666A451F552
                A964AA17B9128B62394E3212519AB64991572C2A786A97F0B502E014303B5EAF
                6E4E5C113816D2CAE95CB608AF652E1B0020E302C58F1E78E0817BF7EE15C657
                8FE5DC9CFAE51DA48E915B32BCA516F2F5C9079CB23A6DA77C765F6BA60E0683
                CC16337206894CCC48FF6BE67CB40CC680E21579C5225D97CD5B53AF10E6B802
                B0AC2E5DBA1424F747DAE483838369E1FB589A8EFDFD7D69E5225CCC20840400
                C8B2D7E247130B6617C699472FBEF8A2D66A6D369B41AEA8C848A9DBEDBA56B8
                A02B0FACAC58C6F6A3D148938C345AA4B791C346416A52045F49C7143072D530
                D23B347D5EFD7E5FE7B2857DA17C9E954A45D765D347822FBD0760B9055F1DD8
                B22C6949626C2BBCD7396463DAED7684566EE25C365A36004016BC163F7AF8E1
                875F7CF145D77F9F3A75EAD6AD5BE64418F0AC3C71CD350098C9D905975B132A
                521A3C4A7B1BEFF3877FF887BFF11BBF311A8DA4A98C50C06895E92C0F4D1608
                1B072C97CB8D46C3555F8F14240001CB2C982B9D0B4DEF35ADDCCC8502BC4844
                020064D04FE3470F3FFCF0830F3EE8CD3FBA37A645469ACD6690AC60E9D6CB29
                992E3BB0E266CE4AF33EA8312361D64D33D94669EFCD4FC878C3390678F7BBDF
                BDB5B5F5C637BE31EDEDCA19D7ECBCDDDD5DD78A4501C757ACCB06C06B341A55
                ABD520571AA401D9DEDEF63E1E2190E4FF1269E5DAED76841399E65ABAD2F901
                0048D14FE347274E9CB87BF7AEEBFF74E69ADC919362C0E423E9F7B75A2D6F87
                9E8BC000BC9C177E0F8F9902D859081B694A91163092DBC16060DBF66FFFF66F
                9B6246FE96BE92512C22CFF2D0B96C72D2E1FC02C0E8F7FBD56A75E6D3A45597
                D623F642DA137BBCAEFAA1C1B3905C8172BAD3008074FD247E74EAD429391BDD
                BA75CBF57F9A0B20273919CB055C4BA256ABD1955F4DF469108A1C30D27B36D1
                2253033BDD9891B36891AB981161A0850A9EE2EA552E97E5BCE3BD444FA304AC
                08D7975DDA936AB51A70B197BDBDBDD83760E27F456EE574DD00D9544E430080
                D43DF0EAABAFBEF2CA2BB76FDF76FD87563ED26BEC72B6ABD7EB619744A5EF0E
                AC0E9F1212CEFF3275AF9DD3D352DC6C6DE29CD5AF35D5883246A9D8D9D9E974
                3A1162889A47502E977516247F3B60C5F5FBFD66B319E4FCD2ED76B5E9308F2C
                B40DF1CED80DC83B978DB60E0090BC076EDDBAF5CA2BAF78FF432B1F15C623AB
                7ABD1E24F968DA4C72C5796E59F1975D71330F0013361A0C06CEE96929D28091
                9995A60123FD2F0EE674455EF4BA305EBAA156ABC5BB0837809CBA74E9529064
                1F39051C1C1C24D956F4FB7D69E5343D2AF844B6C2C226DC010010DC0377EFDE
                BD79F3A6EB51AD7CA457E665C8E79CB3EDE43CED99952CD2DE2300A13947DAD3
                EEBB1E993938B76D5B5A0FCD33D28969E9868D741A9A8916AD1D634640D68C46
                23B32E9B0A3EC49A3697AD10E6D005B004C2AE1A9C64CBA0EBB205B934EB228D
                61AD566B341AD34ED3F1EE45F066739E27787F0BAD34006484B7657E60E2FAA0
                A6F29174D99BCD66A8E4231A7D202F427D5B83F40E4DB4280B258D744A5A617C
                79D9393D8D062AFB6470D5198B3C978D99D4C00A725DFF688FCD7C552A574075
                F34C2B172A11A936663638E156CEFFD7F95C764A656B91293EB1420E0C206BA6
                7D2B27C48FB4F251E1B87276901A84241F014B20DAA2C526B7C8CC504BB106B6
                C92AD25091661B9161945391E7B2516E1640214C216D67058624C7B1CEB96CA1
                C8D94DB679E25CB6056DFFC4B75DF4671524DCC09D5CDC01905FAE2FF284F891
                563ED22B219D4E474E6C334783B55AEDF2E5CB69EF1A8010E63CA94BBF5C0B60
                0F068374E7A699DC2253CC484348FABF745C72CDB5E87528954AA5D56A394348
                746481E5E6FD8EEFEEEE4A1B32F38572E2B02CEBFCF9F3C96FB377C66E40B2CD
                9A8894CD7503E69CD196F6E6234ED24B74F6CAF44F3FF136ED2D05F053DE58B0
                79D01D3FD2CA4785E3E4A37ABD2E8343FF774FF1A40B40C5D577F4CF33373123
                E7DCB454B28D4C8691DE3121A4AC75A011961C63AEA4211D5C6998D2F97890E9
                1E7284C8E06A6363C3F57806C75A001641BEECD56A55BBB2FE8D46B95CEE76BB
                A9B40CB29101AFD77A2D7A2E9B7378EFFF1CE78F66AD55D34930B71A4A30B713
                DF30C52C662C94F9D3EB8FD3EE03489D995BEDBCBFB7B757F0C68F4CE8579ED1
                EBF5E4A43BF3DD2726FDD23B0712B0B82F9A796719CF5F7730C5B013DED33507
                E7A2694C505A055A28444E499AE616AA5088CE65635D36604578BFE0FBFBFBCD
                667366A3216D85655929AE6EE69CB16B5AB98081F256AB95F0755CE91BC8AD49
                3D7606894C87C13C817810002C010D1CDD173F72261F495B1FA4EE60EAA7DB80
                98910B784DFB3A98AA465ACF48138E52D942133032F58CCE9D3BC7977745B872
                91E699CBE6BA440F60B9B94E135B5B5B41968291538CF469136B28BCE7B26973
                D96646919C73D9A6BDF99CDBA91D037D447B057A9B6226320020493F8D1FC9F9
                E0C68D1BFA9033F948C68D41D63DAD542A72AE652C072C015D40CDC48C529C9B
                264CF56B673DA30C3635F2A1BDE10D6F78E59557D2DE909510B9504821A54BF4
                00B2A0DFEF379BCD201742A44FEB9DF19AA4C8AB4FCA5952FAE48D4623C6B45C
                D32B30F944A6639062D14300402ADCF947CEE423B9D5E423FFB35762C947AE05
                599D33B1BDFF559874D58584052C8D083529FDD3EE644C6E4A1A99C24609EF94
                B306B6068FF40E5F5BB8C8312CE3401DCF847DADFF5C364E13C0129BBF9076C2
                EBB2050C78B994CB6569E2FCD765F3B9E39CB15E180789CCFAAAC9EC380020B3
                DCF1234D4CD5EBFC72A75EAF4FBBC66BD268658CD7ED7617577F64CE53358301
                AC14FFD2D7AE679A4EA1C9424FB1A491468B34E188EF2C82D8DFDFEF743A11E6
                B22DE2123D80EC1B8D46D56A35481CC4B9A670023DC969BF62381CEAD20161DF
                50CEA7D2C44943172438AEFD81C271629149405EE82E0300F26842FCA8709C7C
                24E78F2065269CA758F326C90FFFCC946C93556BC6A505C784172A1F6129053F
                9EF53B2EDF6BCDDDF02E68950C5300DBCC50D3C7F9562214DBB6E53CD5EBF542
                95D3563A97CD15AFE4D4002C372DA45D9855CE39E12A483E74E9006729D2E0CD
                9DE65A4E0C949B447EE9094813AA5D020A180100FCDD173FF256CE9E39F53A99
                F3ABFF3513FF422D66464CA552C9423F00884BA881AEE9236A9E51218DB205CE
                24230D184D9B9EA625939DB7096F2A72C43BB80A4E2FD17B0B9D10450296957C
                BB2F5CB830F3E2E8C45A6989B50CAE8B9D722BA76FB32E5B28E572595A39D78E
                0C874379434D40A6F4350020B8FBE2479A9820A710E952CB6DB55A9D9931EBAC
                9CBDE81212AEF79451A59CFCCCBC1BFFD76A22929C44A54360B2791921602939
                FB9D666E5A5A558D344254BC1FF120C4CEB9E8B5D3CC0BF57A6A90812295B680
                1511A4AE909CAAA459C8D4CAC2DEB96C011391A4EB5BABD5F4C966D23AD3D300
                00114C881F15C6272439AF0499222E27D7CDCDCD856EA237CA63DBB69C3E35DB
                36C21BCA49B452A9B0FE0E72CDA766BC7C414C0731958C740DD76AA848A7A705
                4CFD23D508F3885C28A430BE442FA733EF81CA650660295DBA74C97F0D4767FE
                5176DA015D3AA0D3E94478ADD67320CF0800308FD7E247AEC96BD205AFD7EB33
                27AF25BF10B28C3075E5E6794E81B28FB55AADD168CC5C8402C80BB3C2AE868D
                D25A3D4D9A05198A6BDA91ABFA181056D890A2E6A5CE5C367422395CE58CE62C
                370B60094CECD1CD5C882DC5FC23FF2EE83C73D9000098D36BF12357F291C668
                FC5FECAD9CBD68FD7E5F362CAE9C5B192748E7807C07E49799A1E69CA496E406
                B826A6690869DA778AF4222440075791D765AB8D71A002CB6D6767C7BF685A06
                E7AF39C5DB1F4E9E5E5ED25BE783BA0674DA5B872498558F0AA4C52D867E95B4
                DEA8735129E5FCCCF9FC978F73C2B2F3EFABE3B5C2F4E9CFF2E0CC33CB4FE347
                2FBFFCB2261F158EE347F57A7DE68B2DCBF2961D9D934F11A5E170285BE5333C
                D6E16BE1FE1C5DFFC93BD3E62CF86FD83CCF419625F9170C582F6CE2D346A391
                7EBDF556EF24F6296990C859D548BE471CF9C89439E7B279CBCD2A925581E530
                33FF4813124D2F37AD95857D5687D4A50334E938E10D9BC90C53CD9075DA6DE1
                FE281221A415E10A1B796349AEFF72BD70E27FC1C5F575335F463345C03023E8
                891F7E84F56D276E4C8A7FAF747F7B2AFBA57F503941B89255B58BABA5AE5D6F
                A22F0992C5FFD3F8D173CF3D5738AE9C2D773A9D8E9C56FD5F29CFEC76BB31AE
                6836EDDCAC8FCB60A05AAD4EDB241DC1EAAC19B310B886DCCC8C9E6981277995
                6559E66AB37733181E2046414245130FC2C2F121AD01A38467A899538E2969E4
                5AF51CC81ADBB6E54436ED9BE2DF9930EBB2D1FE034B29C8FCB5898B332660E6
                FC35E755A5C8E590E2E20A15E958B470FF18B5E0B8B2EBBA8315E4FCEB4FBB5F
                F0849326FE38F1BF5CEF0017679552E704025611593EDEE41B39AF6D6F6FFBBC
                64DA72344EF7C58F941C3D722A925FE6BF41AEB04BBCBC4BAD55ABD589175874
                5109D9189F83DED48599164ED355E40A146A4126C9F1AF01230D8326BF809A09
                1899BE20DF14E482AB5048A80B50F2649DE34CE629B07C82E41F493F5B7A9899
                BDA6381A8D7A63C917423239C885FB6743143C0944CE3BD39A5F7DBEB92DDC7F
                3DDCF5BFDC2EEED6F581C7F8F99BBFB5EBF0F00F23BA5EEB7D379F079DF77DE2
                50054F282AE1AF52EA5CF15FF3D5D63E7F8C692248859C265C53CAE4A4E6DFB3
                0DB23EA93B7E246F17E46A869E5617BDF29A92ED913DF71663D2CEBD7C0AC10F
                6EF94464BF26CE68987F21B9EC74291044F27FAF50A96D1A33D26C234DA34BEC
                ACA6A7103973E859C4DCE1F0464ECD33974DCE329AE8CBF10FE49DF39C1B307E
                944C4737C8061BBA4A80A97B98C066380796D366C1E833BD1D95151C906311FC
                D3D6A64D7BF4068626CE989BF8C8B467FA4FAF5B0E3AB9C97CC14D50C9BFC829
                32C81B0C9A193FDADFDF9F390BEDBEF891BED7CCAEB67E3FBBDD6E322BAFC96E
                7893A15C0BA819338302D3A251F27DB02CCBEC11C1A01591913FB46E8626CA19
                DA3B4C6C1B5C971D847F649662D8C8115DB833DA2C0F2DA3EB2CF29591760340
                6413FB964ED3F28F92671A1CE99F6B36FDCCF56DE6E42C98E22A77E82C92A25C
                C38C65AD3382DC99980C15E4F9FAA3398CCDD87B5A91A699659B82E44C659F2B
                8A64D20FF5A36344904D72D668369BAEFC2339B5F9D4ED099D7FA4AF0F127692
                B1E5C1C1C182CEA9CE3D9938736DCE8B42D30612954A656F6F6F117B04F8D0DA
                463A3D4D6E134E352A3866A8F9CF0305724DBE68D2EC4F9CC53CB327979D9124
                805804891FC957DEBF4EC482783BF49A73242DD8A2138E269644F156A5993835
                09C82CEFB13A3159C93FC01476B2DEB4CA4DE641B33C56DA1F4FF44F75EDFEB5
                74260692B8E496226FFD23FFFC232DFB1025FF68664E6FC1116A89F1989838BB
                472B79BB9E297B7EF9F2E520EF336DF3A685A534A92AF24EF10D81E15F0CDB2C
                A3A661233D14133B8598E65EE7A651360F2BE5E2C58B91D7659393AE732E9BC9
                1CE4BB03E44BBFDF975EB57F17D9D9CF4EEB6B2EBD7FE9092F74AA9A4E5437B7
                CEE969059657477C3218709C36EB2DD42C39D7739C6F32319C641E77262BE9C5
                63BD759664CA0BE705E94AA5C21A3B1931317EE4CC3FF20A977F2447AABED7A5
                4B976666C6CEACDD1D8B89511E3922BBDD6E843439D7B97FE2826EFE91292CB7
                647A87A3D1C859D528B16C2353D5C8193C22DD14AB696B6B4B4E7311BE7AF2AD
                91F1643273B7012CCECC5C7B2DB299569F502F021F1E8BFDFD4D4FC0D5372810
                300216C01B7B723E620246CEF8913390A483F9BC7C2BCDF5699DDCC0582345FD
                7EBFDD6E87AA9F1DB1FED1CCF851626B9A4EBC3A6459565CBF7A6767473E53D7
                AE6915A420A1049F04132C93897F68D71FDDFF609007E53036F5B013AB7959B8
                3FB9B45C2ED38E036A777777DA8A9CFE6656DFE3D40064DFC48B882EBA38EFFC
                DF6257A2E2C4BE84F38E4E66EF743AB10F175D5D02BDEFAAD892C12411CC14E1
                AFE65DED0E0B35710E9DF9134C7BB2892899990ADE25E4324B63D33AFAD0D686
                4E51C282E41FB93AAB51EA1F8D4623798D7F6EBFE6F02F7A49BF8993D7E23A97
                FB7C4031C6A7905F01077EFE4FD3B0911C607A1531E1C24626F0AF17010AC701
                62002AC839721A5D978DA56D811C719EB2C3CE5F4B8674C2DBEDF622CA639B2E
                81A9813DB1A4D122762AF83BC7BE0DF98D8CC4B5E5B90B12E5653B17FA09B81E
                99B8ACA199C1E09CF596F6B6FB31F3DA024E6DE30A5C2CC2D63F2A84CD3FD237
                F2A63979C51BC499C6B66DD97AD74934DE797313D7624B666A1E326BFE064B97
                51D34AD809878D9C29A3669504DA5F601A19AD75C622F459E55B26E78BF5F5F5
                B477024068DE5EB597B3BBBBB8C18CBEB3468E624F4FF6163A3425B1333EDACC
                ACE4031CCEDF38ED7EF2BF3D6BB2BC6DF3EF9A731F9DE5939C8948DA747867C0
                65E7E332ED8F494AD22C9869533A9C08274513A1FED1FEFEBE9C8C82E61F696E
                ADF6A4FD5FB3E8088B1E22DE1DD645944D673DC291E47D8977018EE42F3721B3
                82B468866DDBD2F3D314D324C346CEA534B59B484E04109C2E6C146D2E9B7CDD
                6A6354D406F22548FA618C974B7D5A06E9EE0EC662AC73A41D03733DC93B492D
                B220F92CFE43D358E21111422AC92458CDF35B928F07A5FE51CC3C9CC23EBE3A
                5C694ACE3A4AAE8C24331EC9D4C4376746A47F6D8D20EB62619A68F947A1E347
                BAB0BDFF8125BF75737373D13BEC4D2D8EAB70A9F3E0F34E804F66761E72CD59
                A7C024916AE76FA12BA438CFCA85E3757635841FE488957132C58F80899CA7D8
                B01D530D2171D6007244BEF2CD66D33F6423A757CBB2623F6F9A2E849C94B5CE
                51BC9123D331F0590A2A2F169DFC12240E15CBEF4D378728F2A62EE2F9F9DABB
                206F15F03D17F441399392A6AD0DE70C2AE998A570FFA2CF29FE059DE948CE69
                13848A62E13DD305597F6DE6E4EEFBE2477226D3F891FFA6382B04C5F8D775BD
                9577F65DA55269B55AF19EC8BDF12396D7C144DE5C24AD70A9F3D4922C6CA48D
                ACB38A012D2C30BF20E5FFA6916FA59C8F5D270E7A3F4066058C1F75BBDD457C
                8BA57190A62672FD352F1D83299D2162FE2B602A50E4DF9BA3D8C112CB5D9DA3
                993B12D74B56F320F7092439EFB8C249E9AEF2A67329CA630CC3E3E2CDB4F5E6
                1FCD8CC078B9E347DE92432EF2D7B52C2B818A0FDE99658B881FC980417E8BB3
                03112D7EC4386145E8D542CD334AAC5E9D29865D749876BC91640444265F9F4E
                A72327C108833AE75C36CE0840C6058917CB69B7DBEDFAAC5313CD7038947646
                7E752C592D7A55C9CC5673D64689EBB3CAE3F8397579F9D012DBCEBC7C20C948
                EBD37096522A38A248CE6249E6A2B8F34E921B69463A2C1B3DBF08F58FC2ADBF
                A6F1A36AB5EA7F3526B1F49C8995899C3B3CE759DC142C945D767E46017790E1
                C17273FE7DE57BA111FAC363C9C48CCC3ABBE6A222871C90009DFBAD7DA9B017
                75A9A007E44290FC2339ED1E1C1CC4F875963E676F6CFEF1982943AB533F9C25
                B1173D34CD72202054CD9DE5FE407C568B9F7F9B635F1E6EA13B1EF6772DD9E2
                773E9BE19DF5E6ACA3E45CDFAD701C454AB28892B34692B3BA2B63F0E092587F
                2D48FC28B1F240DED9778B582F3972FCC898B9823B8778C2FC8B5E3B4B17F9FF
                69B4B691068CE22D6CE9CFC48C88BB0369897D2E5B81D2DA4096E87A67FE19F7
                DEFC2317FF0E86ABECABB4273317380EC2E41C09E92DE883D9AF7094FCE83DD4
                BBC535D45F44791D181989FD2DEB9FC61B4E72565632B948A68ED2CC55DE62DC
                30332C1205DFC21DD3EA6DAF66EF2B42FDA310F5B35F78E185575F7DD51B4CF1
                5A441067DAD6BBA25F7386AE26060EBC51AA99E51257F3F8CBBE20F1A0894FF0
                362E3A494D634689AD716B123535CA2E8F64307274FAF4E95BB76EA5BD154012
                74410911E1B5F2159613E5220A050288459018B17C910F0E0E26A6BD87FA52C7
                3861CD5900D13C988580C5C4D7C61E33CA42A1E205FD8A996F987CD5ED8CD7F9
                4E5262796D59ABD6E49CEF66A248CE224A4ACB7A2470A15DA7E86A3328B73E09
                0141067DAB2048FD239710F947F269DEB8714386CDEF7CE73BFD5F10EF243227
                D7E51A6FC04C8E18D961ED91C7F57B2756598A6BB956A42BD441A2F5B04D0B98
                4C49ECE2FDB4EC25C71E901DBBBBBB32F08BBC2E9BFF451E00690952F1D3153F
                9AC627AF597E8BFC0AD38644E61C35992247B95EEB9D3C9DC54977DA54E4A8D3
                FCF3CE964C6677DC3BDFEDBAC7A2A7D06A469269152377B4963E9C14A4FE91EB
                430851FF48FFF12E46E6D5184BE0B39693AEECB0EBD250ABD5DADCDC8CEB57C8
                E725BFC2D57B90BDDBDEDE8EEBFD97FBA0CC3B9DA16626A9A945FF526D6A4D3D
                6C69F8D25DF6FBC4891377EFDE4D7103808C933363BBDD8E3C972D9919DF0066
                7255368C2B7E348DA61DF9FF8A999C6B12C99D392B8FA435892C19F32FDD157B
                C6CDB437CCDAC71B7BEAD99C4F8E2596B4D00F39AE45DF4265362D2EC43667CC
                518736FA5A532ED64491161D4BD2E6519B4A9FF5859C566784DEEFF75DF3A6E3
                CC3FD27F82CC5F4B2C7E247676765C7307742DD5424C0B967B6372C2B22C33E9
                00F9E5D334C87F15C6CDD9E058626B4F98529733A7EF02C80EEF5CB650BD4339
                55572A95159F840F648A6DDBF28DEE743A3ECF91A188F439A7C57FFDBB19F2CE
                5A867F9E8D341D06679DA3783F87AC0532666E64F63738F90A4A19F94C92DF8C
                640E0C9F77CEE01F2BC583C1E425E94C374D4432B1A40436A07C4C7E7BECEB66
                E65484F5D742D43F32F947172E5CF0DF8E783380FC798B1339A7B045E03A80B6
                B6B65C5D07FFBE02B2CCBF276772CB4D316C53F86DA15BE55A404D532E57B615
                03F24B5A8F5EAFE73AA706BF94AA276CBEFB4046CC1F3F325CDD8F202BBBCDE4
                AC7394D86C357F3EA93AB990E4525F8B7893DC7DE0F9B2221F6F6295B3CC3A6E
                CE45DC92290F624A82386B2419AB164B5A6CFD23FD27C80B928C1F4D5C0F2EF8
                7218FE2B6D4D4C3E92FEBD7CAC3196AB58B5C3349BE44032F1EF64E6E5BEEF7D
                EFFBFCE73F7FE2C489AF7EF5AB3FFCE10FB5157B68ECC68D1BB1FC96B367CFC6
                F5564066C9973753F583E44CAC757023BC56D76593A680930290BA2005F2E56C
                7E7070E08D1F4DEBDAE9E21B33AFDCFAFF4653D143AF39CD19390A3B5CF45FF4
                7D71BF3753329EEEB4E8FCA6148362897DDA8BAEB01E6309AABC1F8126966486
                60666DA24527259952217ABB9AD92111D65F0B5DFFE8E2C58BFEDD6257FA4FEC
                C111EF1B7AA7B015A29628728693E4A8F546A664EFBADDAE77D165E491FC9535
                4EA491A32427A97DF4A31FFDEC673FABB3E41E79E4916BD7AEBDFDED6F7FF1C5
                17D3FE4800C42048D99469A41323E7AFF5F5F5B477025875F3C48F26BE9B7439
                E4DDE6A976A491A34AA51264B65A5AB360161D4EF20960A53B905E74A463A1BB
                9962B5F2D897038BF66E19FF54C3FEBA583E87C4E2A466ED36F388AB46520273
                415C199DAB534F2078FE91F92842E71F3DF6D86333FF84C9E41F39633DD56AD5
                1BD5D21092EBAFEE3D08A62DE9279F8B37699995D7D2157C655CFF679A496A22
                9965D494B4479FFBDCE73EF2918F68E408C0120B323F7C1A571941FF9CD9A5EF
                DC000998D85598D81574725D56F4F9327AEB2D84A2E5117584E3AC2162FE372F
                0908A90CEF2397A7C9E0079B8A244B41E7C8C4DD49601F977B69424D47323123
                BDA3E3B564963032CB11B892C17D7A62B9EE9225917F34337EB4E8FC232FAD41
                28BBE1DD12D9798D64E96604DC9869978E5DB3DC73777CE457F050913FCD1B77
                4E524B60E3B59FF7C637BE518ED25FFDD55FBD75EB56521F1B8094CD53E5A452
                A9C829CC3FAF81D310B0207A9DC95BC4C0C5193F9A36A8D03894F42A238FD334
                72A4355F93297594582E462A2BB24788866473925102B59933185F48FE4358F4
                66875A612D965F9A854FC087E622796B2499592309941931D569E5D6B9BCC9F2
                49A2FE5176F28F9C7CAE11D5C6824F68F4594B35DA9C3824CCDB81D3B09199A7
                B6E8B0D19BDEF4A64F7DEA531FFAD0879C79980056935E9088363D563A2E72FE
                4AF27A0C00637777D77B6DD265665983D16834CF9C351DC0C8E8456E630C1B65
                7CF498BBED8FB1DED09C3386E65FBD3E95CF362F718D84F169183AA4D20FC439
                AF2D9962DB665E9B9AB91653BE44C83F0ABDFE5AEAF1A36919627286AE56AB13
                F744CB4968C6EFB4C96BD2C597FD92137CA7D399B883CE996B393D3E568A4E10
                33858DA2D5B20DEEB77EEBB7FEE00FFE808011002FADA222E79769EBB2F9CFAD
                D0451B38E9008BE6EA614EAC8DE0522E97BBDDEEC4AFA72EC838F322ED347AF5
                5BBEFBD27D2D1C5F905FC404AE20CF595C299F0549B2C07366657FFB2347BB92
                CCA2CAFEC798BC14838CDE1A4972AB0D750259991ACDD72892892AE43D2C1024
                FFC8B58FA1E347EF78C73B66A66F4C2BDCB06866B9B4898775C9C15977D0593E
                79DAAE49FFC0B2AC4C2DF1B382A61D48DE125709D736DADCDC94AF59DA1F0F80
                4C9B675D36E75CB66935FB72DD7D01B226487D07679D04AFADAD2DFFDA493E4C
                018E2075B213B67C13A0E2B23A7B1A4A8A1F4BEC61239F3CA91467382E7AB9BD
                F9CD9F16E77D8EDE6A13AD8948A63E493281249DD7E64A3ECD6321A468F58F66
                96F3BB2F7EB4BBBBDB6EB7FD5FE08A1F2569E6F95EE385CE2CB89975DDE5FCDD
                6AB57C3AEE48D8C4BF82A96DA401C1455707D00B839AD398F06C4D0039A53359
                22CF659333519032BD00E61724FA23DFCA6EB76B3AD9E65B29DF749DB51AE1F7
                EA3240A64E76D8CE4CA64218CB9A041476E1F945C41AB2FF29E57A3B63DFA39C
                06D1E6F945C97CFD9D237A330034556E17BDE3268A94EB357393A87F24A3F40B
                172EF85F9091CF517E6B5AD93AF3D42B9DB82FDE0AA62BDB71CFDA756F5D0DD7
                64902550DBC81454139FFCE4277FFEE77FFEE6CD9BA9EC3B809CDAD9D9993651
                DADFC4B96CA15687001084F475ABD5EACC9EA47C192F5FBEEC7A709E5EA8A61D
                E9FC88E091A364C687330787FE256C163ACC8EAB7ACE9CBF3DCB629C9C186448
                9F4C35E8D8DF39E11CA2057D08F3FC81622CC5953C5776880E0C13A89164DA6D
                D77A6D7991C4FA6B724E7DE73BDFE9FF67585CFC28601779CE6A854A8E3FFDF8
                F278282C2B57BD2A9DA4A6ADC3A27FB5A61A4903F1DEF7BEF72D6F790B612300
                910539F54E93EE151A6059397B98412EAEBA961B0EFEC269EF664620092CAFB6
                3A62896AA5CE67249F915DC86646D53C81C58C7CB039DAB078772DDA9FCCF9A3
                164BD244A404920C346EA0D1FF7C4D614B28FF68E6351939F95996E5539F7C11
                BC4570068381293611361E2C6771F9EC7C16D480FF5762DAFC4FEF9F69E28FDE
                3BE6095ADBC814DE4F2035510B10B88AA545F6E28B2F3EFCF0C30BDD6600D937
                1A8D3A63E691E0E7295D14625ABEF4B4F61380934F4FA35EAFCFBC06E9AA8CE9
                B310F04CE6F2B559AC7AFEBD0B3E729E39BB6A89C7AB9992F0E71CF6C0C8E661
                304FF2548C994AB14727B3F969C765717BE72CB03DB1588D89252D68D734DBC0
                1943F0F6C4B256232948FED1BCF5B3A5CB2BA7D599F1A38C9469B06D5B7A005A
                477966D0D1CC4BD2B378EA7FCE2516F6BB247F4713394E66929ACE68D5EA0372
                9BE4A57ED959320B8055A067A899250527D28599B4F81A01232046D299AE56AB
                33BF95966599E4A3790A1E99B423530B76A192993293FDA230A1B62AF876869A
                2696CDDD8F4B5A93B3326EDAF627B9FA61A6763C19662102938E64CA242D62AB
                74B52E57756DFFC16F8A12CA3F9217F85F969143444EAB992A2525BD0133D1E9
                FF67EF6D7A2459AEFAFF58D8F85AE65EDF94652123B1E86256C0AAEBF62BE8EA
                462021164CF54896D8D1AEE661E155F78CF8B101A1EE1AC9FBAE998D4102C9D5
                B3479A69F3065A034B24ABB85EB12CB5F05D201931FA1FF250F18F89CC8C8C8C
                A78CCCFA7E16A1EAEACCC888C8878AF3CD734E706FE56B19F1B172049FA37CA0
                8B8DEF6DE97014F5706A4A6CBA12B4A45700001003C4B201901EC3C49D66C68B
                C5A2B58677EFDEF18CD1463C6A724FA05B985365AB53531F621B69FD1A81834B
                C8E2D0AFF1F5CE7910C020C86DF9369BDAA45312DB9891225AF83D1F47B164E5
                70A49122FF91A55BAF7C2D9366982CDFBED27FABFA915C8EAD69C70CCFF420F0
                19379A8DA5CC6DC4B337BEC3FD23D40000A0139AFDD969AA440F2EFA99AFBEF9
                C02F1700F6A8D9155BDF920AE5F5ACA5B352157E3B4DF72FFF99ADE5DC575E9B
                1CD484F46D4896C03B8862D5354F76C0F5E9738BF5EB0BCF74DD79F62B543AFC
                A6CAD53FA526A0E6DB0EFEC4FB4149558EC9649E96C2FF88BABA5C2E5BD78EA1
                E9EC8B172F7A1C0B9FD8C24C4EE71E42F3304E6F9420B71107A6719C1A63D059
                11530600880A3D64381D925B2C1B2F158A5F2E003CA199F462B168CD0BB35EAF
                67B3194D57686307E7414EB2C9211519DA6F2257C332602F4225AC31EFD2D730
                0EE2F4A559DF7D1CAD726E408C15E51CD6D70B7B9B78764ACD912476A16D3247
                925CD73B6C681B0739F1633FB7283607FFA3CEF98FA8933CC735EF53BBA6E9E0
                E8FD8C8E0643CC2707A9A9B98D622FB22841901A00202BE827997E5EDD323BCE
                E7736DD907FC8401D08A769B5C5E5EB6E6C0A6C9C37ABD66F1A8AB0621936CD2
                079FF76491DECCF798B0C6F3E8667B3560D78224454EE909D28B96D1BB80924F
                5307341443C44629B37F04B1AE2473244945490412FAA5DB69E245C6CCD8FB1F
                C99FCBCEFE47A24EA6AA42434307EEC5380F3E63C614DC99DAA1E32F3996902E
                D6BBBBBBA899F08592E54AC6A9C199080090273E897839D89E662778C401E000
                CD6F5BFD89386911CD255ADFBE5691E930849D35124A527148D9DBF510A3249F
                744B8696784630C5DE31F668588E52EC2EA41CD85EF20D657501C4EBB550BC93
                E2E5489253B5DA9429E957444991FF48940E23F4FB6A9EDD6A4BB0E50064A04C
                A013C1B98D38BF406CD55FE6C3E6C54D4473A22B1F10E0060008053D4F384EDC
                6D778E658373250066B469A1CDE45694F35B9A4B38246794EBACF19F391B6363
                B515C7DA2F073CE389ECF585A1E8235935AF9756A5ACC139BC2E65F63499669B
                AB92716DDA824ECEC7929907441CCBD49E14F98F98F3F3F3D6E4829C02696F55
                9B7177BC36BD9439E714CDCC381FB65C34315EF3646E23F961C4E70200303EE8
                114A3FB20E0E0E4CAD2392F4FDC462110054B9BDBDA50971EB66F21DB57DCDEC
                FECCE251D4DC8E9958B659C5D625CB481DAAFB999CC4A130BEE10A9B71DCE0AD
                E690C628AB8EA714BC648E24991A2954E80CBB38D0AF83E19D9F4F4E671B52E4
                3F626CE2C3C79102096874BA7069E32F77C45E4C8DA77432B1119559B9BF0100
                4057DEBE7D4B3FB56EB16C1C6543343D09D3FB48039015EA95EFBC8C9A01364E
                E49D48D392A86FCE221130862B604EA234D9AF03127549A90C491355974F17F6
                A4A7F1D28A0D0235AE4D7589F01F84D90E352F52CAF8352D70DBC6FFC8453FB2
                715B9A4EA7EFDEBDC3AC74DF90AFB8599DBDBBBB73337E24368F2719A486DC46
                00803141CF52FAB5758E65A367E3D5D515D9AE96BFC5D092C01EE2799719E008
                0582FFCC615DA70165364919ABE25CBF9B30142FB352FE198E3A85CE854AFCD4
                4B5FB26D525F5E45E3405DBB8D170D274265D7E60479E6BC48C1A9D58F34FF23
                EDE8360B957EA41F7DF6D967BFF8C52F68B7E5726976DCA25FCDD56AB59F3E20
                7B3805975DDE6C36AC19C50E52133BAF3F2AE962A39B0DCA11006094D8BCB331
                A06544DAC35F28000C5846AE35D16420C9A5766883A6E99067D698506E38FEFB
                FA2F7E14AF6D61E9D7B326811FD3BEB94A69BD4E50CFC8EE886A63B26A58BCFE
                F207B676D91D2988D9CB2A92FADA4F9BB3059FC2B9F91FB9E43FB2CCEE795582
                79EA5851C31FDE2B840AEFAF7D00B154C41332763B32CB46C86C0D0018013EB1
                6CA26E4622202401504E12CECECE822F02CB292DA88C9AF0C886AC6C39CFB4CD
                F6F5679E83394D1B7268A15B3332F1C9F2AFA4C725E1D20C4B9A8386BACE23E9
                E3FC86405AC141542419D196602D141BFF230D97F5D778C669F3BA86BABD5AAD
                60BD8F092D8917AB45ECBC17D5DB886523568ED2DC4E000090159BCDE6D5AB57
                777777CE733E8E65C3F31300196B4FF3E6D605612C91098FA6D329DD6B0E99B6
                6B2B4CBF6F0EF5873D50EF413DBD6B2831DA9F550B336F153A15B05F392C36A7
                5525DD91A4451CC428E6971032374BA4777EE9FC8F845DE41B8DE66AB53A3D3D
                0DDED5FC19F77B5DEADDFD8ED8416A6A6EA3DA88501FE09D040018165ADAC2AE
                EFDB3923D2B367CFE43748A40DF6961869B369C64F936F7FF1C88DB1DA996189
                E4DE92FFE027482194F920E4DCBC043189A3C7ED0A0FB5E61D7F90116D322F92
                672A37F61F57A76D6171F03F72C99FCD2990AA8BBDD572737373717111A9C320
                31DBED965362B3B01AF56134DDC14BAA05578E000060A0D0EF2FFD723BC7B2F1
                8250EC1F81E72AD85B369B0D4D9A0346AEB18B34DD59FC67578797C4365EBCA3
                474AEF9220C55282C1B13FE8E80935C8431CB7D63677ED54D7C1B4CFBC9649B2
                EDA19C658E9561098983DA6AB36B3B9CDF9B9B9B4812525CFFA3FFF99FFFF9EA
                ABAFE4B772B90AF31090FDBF5AADAA693BF19E3331D501D722D1AAE7457E66D9
                88433A430576D6C2298D18F639C24502000055380BA18F072887D8181EB3F8BD
                06E3A07662435C5F5FD34D14EA282CCBB2E7516CBF6CEDB83E76A6FDC69E1158
                9E99C20747562E4EC1A3E7FA4D9D1330DF4DCE8975420D821B9DA49C18C9B387
                FE6450F322058968A3DAD6EB35CDDC6A27663EF3B4AA4B90CDFA6B9DF31F497E
                F6B39FFDEEEFFE6EEB9DC9821926A099607F22684B99523ED4DA842AEAA341D5
                8CE4BDD1B5C10000B057D4BA10779AF2FEA044CE12F0BC0523A3E992B699FE6A
                985716E7FCF4225ACC9A9B299B6796A2809A575F56746EC6ED20F285E79F2EBA
                F73C59991C112D0FD277F999064186EFF80C08D9C8EBF5BA695D3667AABF8611
                F31F893290EDF4F4B4D5859E7E505FBF7EEDDF3D109CA62B6FBBDDD26995716A
                F11AC069265933AA06A951F3E467983400005065B3D92C974B4E00EC3657A367
                2F4D14CC990AA12B81A1A379219D9D9D3947806A48F1C8DEF328A05F4FECBD40
                57F2F1DC19FAB1067DC5BA0582F5D8E5418F768FD8F8B8F1070E6AA3D91AAF3D
                E57638C3D2F6CEF3B444F98F548E8F8F5B43C7696EBA5AAD8E8E8E8274123860
                39DA6487B0B751D8F446D55B8BBD8D381F362B47EAACAEB6125C2D000050CB76
                BB7D55E2B354131C91C09E40D736DD2CAD2B085B421398798968F33C8A649EF5
                E26D148FC46998D2B817E5EFC41469D8F3E920488CD95B3387ABC239A7B5B37C
                CF1F38A28D71AB67BD5E6BA28A2749D75F630E0F0FE978AD4349BFACABD50A93
                D13CD96C3652338A11A7269199B0D9E1485B43BA49396270F100008001FA3927
                ABD82719303D9969D2A06644828A04C607CD79CECECE7C7CABD51424AAE7511A
                D121137A6F5E0C272CCF4E8D238DF780C85F988BD4C17C2AECB755D56C5066A1
                AAF7EEB38AC4BF17AAC746A74AC8825EAFD786E4445DB1C97FA4E195FF88F8CB
                BFFCCB7FFCC77F6C3D1993C984BAAAE905203D6A3ED4C7125E5FD0C795CE06F6
                36E25035ED8A979FA9015AB0A8FA276C18000030A3C6B2B9414F5D9A34903D6C
                983700302CB4C8B5C562E1738F48F866614F6A76D956272D9635244E96D46A50
                F56E5FF97436ABD89FBE1212E5133D97ACCB5D3B182A62D4F2C28B1A6DEA7968
                FB7BC7F240B16F84A15FC0A2921789CDF0AE413F8628360752E73F223EF9E493
                EF7DEF7B367D569BC2BFE578B1D9171CA7165B36E2C5D4646E2335484D22AF04
                B15388B46B03970A0000D8C3B139848F7B05AF41AE3A48E3210CC601CD7A178B
                85F6A59B3DC9219FFC2A2E48DB46601A75ED4B3ECE025197B1EBBD5A9FA33824
                2FF719CC11DC05B1576D8B2711DADF8339DF9BF91F481E8E8F280380EC53F2C9
                D5C982B4C426FF913609F4CD7F441C1C1C58FE48040FD803F6A88BA9854D6FA4
                21D5A269095E62030040626836403FED3E6F08E08804C6C766B3A159B24F8C27
                639FF3A889805E3F965585B52A53EE9E093918D2FDF634E0380419B450324D3C
                E1727CD7860FB165356DDFA10CBE9617C9DE17A91AC5E64C0FF98F4419C2F64F
                FFF44F36AF3A0DADA9BEDBC4DB4E6D1CAA1F5ABF143BD988F15F38B0154E6F44
                56C7EFFFFEEF7FFDEB5FFFAFFFFAAFBEC70F0000F691DBDB5B4F2F2451E62EA4
                1F6E9AA6682B63567F7754F0F30D7AC4707D5E5E5ED24DE159BFC36A6B72C7C1
                2D7F1EDCE40B38089D0CC5C469B9D354026213D62B6D646E569EA311701C46B0
                F69F9A1769B95C5A3A225543BB84D304AC87FC47C4AFFEEAAFFED99FFD190B66
                AD4D5CAD56A1BCADF69CDAEBA3AA1CD179E19502A33646AAA77FF8877FF8377F
                F3379F7EFA69DFC3030000FBCEE1E1A17F700DBF12A0C984614602C108E48059
                D0A4F9EE62B1F0BF1D5854ED2A1E0D0B87C43A63226A4F3DBD5DD2BBF944EAB5
                65F3F2E942BC860549EA64D82B993BD5884F56EB051CA4EF93C9842A219BDD7E
                2D94F57A7D7A7AEA79DC1EF21F31BFFCE52FFFDFFFFB7F777777AD63A77A5BB5
                2A2040C37270647A2387A4EE9D90B2D1F7BFFFFDBFF88BBFF8EE77BFFBB5AF7D
                ADEF41020000F07FB084245CA36C2432231292D381214217EAC9C989FFBB340E
                EA14DE375458FC572FDA4FB28DCBCBD9A3CA4695D8F3EBCA730406317AC175CC
                BE569A4B2C16DBEC4270164B9B7D2793C96AB5F2CC0EE4E07F1420FF11F31FFF
                F11F7FF0077FD0AA56F0AB9B972F5FFAF4737FB09F9AB3B7D1FB1DF1E2D4F866
                908E767FF4477F747979F9F5AF7FBDEFA102000050CFC1C181F0B678699AC209
                83211881CCA9CE9DAEAFAF69B2EB53A783E7D1E86D487FC2BEC0CF67D002F62B
                073338D921C2B62DDBD8A8E03567E595D6C94D29EAE2747D8D80336C5F73F35E
                BD7A65B94E28FD30BD7EFDDAE7B8BDF91F315A60B9E1F468516C7881A9D14936
                E2CCED9C73CB3E73BB0F74668F8F8F7FF4A31F7DFBDBDFEE79A40000005860B9
                D2452B6C4263290C9027B5D3A7878787B3B333CFEB9FAEFCABAB2B61D4613334
                4B7C1218B57A9A64BE2E52FE599033BC60F227942C1B7015B3B19EC7B1F62B67
                78CC279309D9F5BC0A8ACD2EF4DB747171C17F46CA7FA4551B20FF915A976557
                DDBCADF65C66D2BA9F32BD9128AFCEEF7FFFFB979797D08C0000608804F14212
                E52F3847F120021DE40F5D936767679E6FD7A4E791C82372CD2D2CC232194A0E
                EFF6E335326AAADD9CED6D9F6B26FFC3F9571224C62A1F2FB064D764D8FA1114
                293B4B25FD6C2D974B9BF348B3B2F57AFDE4C913B7C3F5EC7F24CA055FA83A9B
                B6CE66B3D56A45C351BB6A1850D14686D31B719C9A7F6ED426E8D4D0E5389D4E
                7FFBB77FFB8FFFF88F716A000060045C5E5EF2CF87FD2EB58E09F423CE8E48F8
                ED0639D0741DDACF4B9BA089D0D5D5159531124AE6139D14037F278E941D8F71
                2EB24D111D2978CA323B78582126B71436AD63921BF9C85EFE7BE51C2EDAE9AA
                600989D762B33916EB2A868C4506FACC7FC46C369BC5626139319DCFE7D4559B
                17987B353DD5D650939F696C39B1118B47918E3E51A0D9D2EFFCCEEFFCDAAFFD
                DA2F7EF18B4E957CEB5BDFA26BFDABAFBE72BB8E010000C483E60A777777FE0B
                99D36F046744A207FEFEFC4683FC91C9DD69CA747272A24EBEBBCEFB2DC5A31C
                1C13921D657C6D4BDF7DB7E0A9D86AE39E9FA304E4A38B6542AD9F5426A39438
                6CB6567BA5DF1D436897B6CBCDCD8D8C62EB44FFFE47DC08FB1552A5BE655E75
                D5612C32A1490CAA6E6018014E6F44D3FD78E98DD8DB8898CD66B551099E7D07
                0000901536AF8F6CE0BC3055C7E9DA05DAF0BB00A2A24DBA6882EBA39372A8E6
                743A15A9C2D6F2B7187B0C324A998669E83E4123C3D38D2B5BFF1AFF1A4673F1
                47C24696CAB6BF9C4B9BCC7F19C56646CD0ED469AEE5E07F1432FF11432D5E2C
                169639C38585C43544FCA7C89C189B35238E538BD454D68C08D68FE89B919D0B
                000000B5D00C80AC6BFF3713F4DB41BFE3F43BD2F4F301D908A4E7273FF9094D
                479D77A7AB7A5E223A8A47F9A76DDE370667377AF60BADEAB19B3DFACE380412
                06A9D97E9B7CC8BF856A3BED1DC6691AB65EAF35CF95D6095816FE47C476BB3D
                3B3BB38FB1A29F676AA5E685D4EAB933680C3DA2D1E395D4E8ACC4538E786244
                255D9AD3E91481660000B0876C361B5E26D6FFB78663D99E3C79325687623020
                BA4E44ABF0F5CC110461DB964974864DFD3ECBB7451A90C4B52538E8504CD978
                CDCE6D04726B4F8C16E6DFC75EC830813799EAF41BA4F90719B8BABA7AF1E245
                A74338ACBF1638FF915A6FAB2EA5329BCD6E6E6EA403FC1ECE3269AEA3A6378A
                1ACCF9E77FFEE77FF5577FF5C9279FF4DD690000003D433FB8AF4AFCED644E16
                63704402201EEAD4F1FCFCDCDE11BE0A2FB8C613F7BEBB65C2DEDA49A3048D95
                DE737B876D79D75EF86F935822B46F8CBFD7CC202E03B7EE240E8E0B9BDE2B87
                947341D428B9169BE5248DB65FAFD79DD6B877F33F8AA21F8972CD0BCB803D86
                E79DA7A7A74D1B0C4E54AA75A1AA2683A021BADF11F55A7FFAF4E98F7EF4A36F
                7FFBDB7D0F0C000080BC5063D93C275EF4534EE6B7F352B20078F2F0F0707676
                E67C0D1B7266E7602BE6D086A88DD99F0099F406B39BB00244DE03527BE2726E
                706DCBCD5FFA1F621003D2D4052AF93D9FCDF6722D364BE5C42DFF516BB66B47
                FDA86B22241E206EF1B0742237687C68A64EE3C36E47918E421320F6BEFEBDDF
                FBBDBFFDDBBFEDBBD3000000328563D9FCD765131FBF10B28CC007C007798179
                46AEF1AA8234FF7E2C69DD3EA5DB450E64BB207D827EE5D080DEDBE9DF9D4C16
                2B8CDD00FF75B8C621E7250BB51B62E239FB63B133EC72B9B44C58D9298A2D7A
                FEA3AF7FFDEBFFFDDFFF6D3F2EF42B4EB5777521A69F6DFEF11ECAA22D55DF22
                436BE95F34ADE120B52F4B623489AE339A03716E6CBA3ABFFBDDEFC2ED080000
                809980B16CF4D3C34140AA2352CE3FE5601CDCDEDED2CCD36D5FBA6839005384
                5E702D8DCC94D2D0CA2D35D25002F4F21102F269C93EB47F1C6290B95F032571
                262FE730492ADFBF7F6FBF6CEE7ABD360475A938F81F458C5F6B6A93E530F14F
                38CF3BB39D71B6364C5594582DE238B578B211E7C3E625D5F21C3400000039F3
                F6ED5B9A19F8E41E96D02F11FD9A770AC507C0191BA7FA2A3CA1978AA7082D1E
                0527375BB45FEDC639D353E276863DCAE0D2843B57E56993F79B817E7007CDE1
                7912A4B5C3EA884DCB65149BE58227D3E974BD5EDB2C909557FE23899B84244A
                35843A403FE75AE7AB7985CC9986B40F365E42B5C7B2DCA55A038D2F9D6CF639
                721B439BB162CD8803D6A01C0100007026602C9B285DA9E9D7DCB096C7FEACBE
                0A3C31CC001DD226A8B0F37B6DDAA34E0CD46E49DFEC64471CE281822C0F0F86
                42F0D36A9F23BCEBA1F30F3F0C4B56B9F3D528369B364819A849096172C97FB4
                DD6EB54352CBE8306E3FC9D312CD075E049D56B606A0F9C846EF4B225D672C1B
                71A81A61A33202000000ADD04F39BFE90AE2305BBB4406E4211090EBEB6BBA62
                DDA65B3483A2793695C2CEF9C8CD7BC23F254ACA7D531A4E43B1391DDA99A130
                17CA7F2DEA68647249F80B2E6E87CBA4FBA364B8632BA3D8E897CEC62585B65F
                AD564D516C720266EF7F2477E996FFC8A7CF0F0F0FF6699FAA4C15F25CD585C6
                54942795E3D4684CF9738C6B74B283C523C846000000621030968D7EB3383E08
                4EB220146ADAEC93931337AD93176F219A7266E7B98E75EC16E679D0DCDA96F3
                200469A4BF7F4AB2B45C9D6A48200C8D32742E78B3ED5DA5864B58CF442AEFEE
                EE2C5F964CA7D3D56A654E07E4E67FA4494E55C2E847C25B42E251E3E43EEC71
                D3E31C94CF01CD5744F9AA8AA0416457A3489A115F7CDC719A82433602000090
                80CD6643BFDDCE61411A2C21D14F58AB932FBC93802574A99C9D9D394F2F593C
                12D9A73DB2674CA657BC1E05D7357A11AD222D766EF85762979CD603E5738246
                76DFD93B43659E2F2CFDE2869E52A6CDF6664545AD93265DAF5FBF3654187DFD
                35FF0155532A78CAE1EC80C37212BB1C1B26A36183DDBEAC2348E586FEAAE98D
                6A95A36AD820000000E00FFDF0D164C53938A80A4D68AEAEAE9AC2D2A11C0133
                DA1542D3DFB3B333B7AA82A43D8A6A2DF8D364070ED7DC8D249AECD5D26C033A
                FB43F1C8F36C8FA74C934397B3CA16E4D3E6C435743D1CF1FEFD7B167D6C8EBE
                5AAD9E3D7B261A265739AEBF56153538A542A869280B493C94FC817525FEA6D3
                04B49A5C8A3D89D8B7E8B101FF2E68DD51EB64818C7D8EE070040000A04768C6
                6019756F03876057931B02D089CD66737676E6A6FE98D31EF5F53A3A20291723
                EB31AB8EE55EBDDBB1FE3A483EB62E7C7942357EAF16118BD4CD615D8DFE1E73
                5DA3D8E8376EBD5E37CDB56CFC8F34E12996FF51AB2F4CD869A83AA0AA96C4C8
                81E65294B304F5B3DC9D3F6BF2100F686C0F23AD176A7A23CCAD010000E400FD
                B8B3D774A83728F41B379FCFE9C70EBF74C086EAEBD3EBEB6BBA261DAAA2B916
                47538AB6C8B504565C561E163D068B65526D2F47716E5524B5AE53FD3EEA6156
                6E5F868E3838D734D590B2CBB53DAA6D49E6D7B9E5F7FE1DC9C421B1B59154DA
                E716A01FBBD56A55BBB86DD6F98FAA8A12A754E06968CC11FE08291B899D8A94
                D595C1B2114FA61DBC8D6A653B552C030000007CA0A906AFCB16B04E5E9D4D73
                B345141B30C09787CD5BD02668A27573732322A43D0A956E2346A299DCE6BDB1
                896164DAE808BD8F73EF0D88DAB6AEA3EDA992A44FA093AC66E796F88B2CE6E7
                5B9A75EE721BA8AE7E5B5F7EF9A5FD0A27328A4D6300F98F34B6DBEDFDFD7D0C
                47A4C121D31B35E505477A2300000039707C7C1C7CA50876BCA5298B9A5A1B79
                B5F799D613ED9336DB1CB966203799C0ADD939D0C956EC2B37D080E262324FC2
                359A36E70F064A326E458FA3ACEEEEEE96CBA565141BFDEA9D9E9E6ABFAD39E6
                3FB281DA4D9DA71940CA18B11CE0E9F274077D1EE29CF8577EE5577EF9CB5FF6
                DD0A0000004939383810A17D3738A488D7188DB40806181C4D2BA2DCDEDED2AC
                D7AD4E9A1CD36526C25DC0BD9B1369520E758DEEC97F1C469CB59A8F65A9D339
                4409098B6BC04D25CC3C8028DE359638D758530D91FC80DCAEB178DD0CD88650
                11736E3B7222249BED67B3D97ABDD666530F0F0F8BC52277FFA3263F9AB76FDF
                52E7792DB33C9F170199ECA0E9CBD1D151D7DD6BB39247F24EFAF4D34FA9FCEA
                ABAF7A1A2A00000099C2129208AD22F18F23A12645924B5B4048DA5BB4940D67
                6767CE916B5757571CDA3FEED9261828D9265C1FBD81160A0C144803CD97BEFC
                F24BCD81A809BA2C6F6E6E6872A5F91F55F523CDFFA8BAE669A2FC473650E3EE
                EFEFEF4A621FAB2FA6D3A90C558B340946A41B000080341C1E1EC6588D5494B3
                229AC1B8650304E3A0492EA4790ECD777D22D7680E569DFBC6CE1BDDBB49D963
                0302462AF53E8CE9B177FB0AB8E29E2CFBEEBDE340E57FC4D82BAF8DF54EC9EA
                A16A685B9A4AF80EA55FC3D68032A6EA82541BBF969DFF51154DEFA03FDF97D0
                588C262F12BF4D956E47A1726303000000BD134F45223B9FA632DAEB32B05754
                55A4CBCB4B4B777D0D1920D9295A61706B51F79555A775DF4C042C4BBB3D9433
                4E6E26AEA1B3969A5135324E28AB1239944259EDC7FCBDA155D5F6DB1F4EDD5E
                FBDCA9B55A63CCED6F6AB0FDBF9A5AD575339FBE379D1A9BC6B43632F88E86F6
                DB7753EBAF439B6DEAEF542DF1AAC4E677EDDDBB774F9E3C913FAC43CD7F548B
                5491080E6A4B79747FF85C4E14B495650424210000006321463A24867E4C67B3
                19AF4C0A15694F68F23CA2EF69A6EB261E0925722D0779C5B292DAFF8E3B2F6C
                A8A686ED4BD42C2DBDA4616253457EC90DA052DA5CF21B4D27D26AEBA412B6CA
                B23E59721C0E1A441DF6F1240AB8AF8FA069DF8C20BA70AD506BFED2C1EDC8E7
                E4DA5F33916E5E737FB5FF52C96A894D4BD8A3456E491FEEEFEFD51D87E17F64
                868524F645E2275AB63F6CF241AC66C58642040000601F88940E89A19F579AD3
                448DFE06F9E393339BE6667C0909E58D6EDF1D1A1589552D9E7237BD931731ED
                855E7CC43C8506596AAA905AB2FDA96EA01A99910613009015ADFE4789F21FB5
                3ADA9837F8F0E183D829E25248CAC42349F533E235D40829E7638E0B000060AF
                88E78824762A12817733FB834C9DFEEAD52B67F148947362427C7C713A7843E4
                9C9AC4BEDA5E1C5EFCDB50F597311C4E0D9FF16C6A908DDD703B4435544AFDCC
                3A915A761D2500C05869F23F927EC18EFE47B5724F9A682C6ABA148FDEBF7FCF
                0F3E552F8F87F42D929A1197F24B4C6701000080A81292D8A5146415494E68B4
                0FD5EFC180A89E359B09AB014EA4359BCD3279FBE88C43E884437C9C4F8551FB
                2565113A8FFC3AB9AA7D686F76B9AA268FB3214602B63A22C951A20F5224D2CC
                A5047613006088E4E27F148FED762B1F88F2B15875C814CDBECA9A42AF3E73D5
                520A46F2738F6A111227010000C899D85E4854332745426AED112355249AAD2E
                160B9FEC279C855DC477B2186B589CA57F56BCEE73C20E9EF34BE5A8C98051A7
                EB323E80C5947C862EEC8E6A345FAD8711042300800D83CF7FE42694D05EF2E9
                292A21BEF2832615898F1318899D5791C3C414FA0E00000010DB1149EC322223
                29D20868F2147B7878582C163E963F5D1E341BA6495D6B25C1E50F879CAF4043
                66EDA1D3777777C7C1079D76A70B8053A7B945B485EA45A48845A919C91C469A
                73160000D833E0F5D75AD96EB7AD6986387112531BDFAEF9794A300D05000000
                FC492021F1026D34DD79F2E449DFDD0581A92E2DDC152D6D76DF1D32D1755121
                9F84CAA11A93604C4479E25EBD7AA52D12D4B51EF658E437C464F9A82B10653E
                08B5AD52B53055331A7A842600A05F06EF7F04000000804173787898207482AC
                41B20F69DE431FD4FC47A2921AA9EFF100B66C361B9AA4DEDFDFFB54329FCFAF
                AEAE4436E291C3CAD383CBD11364A975B1138FDEBF7FFFEAD52B1F0D51329D4E
                E97A701613ED57D4761804FBED5902A38DDF976869B00100C087F1E73F020000
                0040FE247044124A9A649EFA40301A2EDBED76B158788A476469D33CD8336DB6
                FDD26C012B0F8E7FA6ED64CD60D83F882E8057AF5E194E9F9AF747467299AB6D
                F5478B3D0E6E39CBB9A75F5648261B55C335D4EEA42F7B3C34CA4EA5D8A52116
                4A3EE25E8E6BF8D07475B55E66B95D87AD9D6D7D62C0FF080000000059707070
                90C6D4994EA7AC1A403C1A1C2CF96DB7DBE572F9EAD52B871A54E3FC0725229C
                7019554B8AD7BCC1B58A4D1DB378C4E9B1393736BBE4885D30173BE618E421BE
                30D8944A33686E47D11236B16044C3125B3652970F123B8F27F59BA261F52100
                40B6B022DFFA56A6EA7FA4BD8A1B70FE23000000000C8B64121227CDA569D0E9
                E9A9FA3D3C9206C1E5E5A59B78A4C2322295CECE4779CA31FD36BEB6DA1879C7
                DFBF7FDF64A2B000349BCD6A17BAA17B9C55243293EEEEEE6A6B68F2426A8D4A
                131D430B3D175F93BA0C5B7D7225B580432D0F372D113BB548D389201801305C
                A4F7223D54E9A968DE18FE4700000000C88B341991C42E2912A1A9480C722465
                028FB91CF9DBDB5B9A9B7AD6C912C37C3E173D653EB2571606AD523963E835AF
                9447764EED7BF27949ED1D5DE5EDDBB7ECC4547B145E95AFDFC16FD2E3C44E44
                93498EA226C6A6635D5D5DB1B39EF8381E476E530DDB01000C05BA6DE573D57C
                FF22FF1100000000B2E3FAFA9A26314172E2B6227D0D7881362844F9503D17B7
                B7B734C1F5B74EA7D3E9CDCD0D0CDD5A3A0D4BE2F02EFE70777757157D581324
                C3A6D3FD4BD718C74256DD8864C6FDC46B969917CE63334FA6C73604E2056C09
                7D58AFD79699C2FA4D6AD39AF6C5A155093A15A3E6A62E07E94ED431C9E49A09
                D26BC3063667C47F78CD35C82F598FA62721FC8F000000003048B6DBEDAB9234
                163EAB48843A2BAAD5922030F5C5DBB76F178B85FFF54013E5F97C5E9BF9284D
                F895A1619E078AD1FE1E130055BFA4FB94C5A3AA907155E2766FD61A3CEC7443
                974AF558E9954735D51199793408CEF2BA5BE3D7EB350F45AB879126F6A1B429
                638C9BA8788A0DB4E528139C207EB658C6AF99FD8F90FF0800000000BD411391
                508B73B75294097739AC090A516E84128F84E27C24E267CE0E8B769450074DA9
                86F81C8B4FD9F3E7CFAB916B64CFBC78F1C2BEAAAA0A7C7979498693D6B6D96C
                4635C71EE7D6FAD93B807336054C8F5D6B5E72D2282D208EBE59AD56AA7EC4DF
                C7F340D9B732C6180A0F97ABAC5A8E32F609E2DB99EE6E1FFF23F950857E0400
                0000803E797878A0B948D4300D95A28C5B214B495DA00D3E477DC123BFD96CCE
                CECE4285117126970469B3DD7487946A4E8CEEAB1B84ED4BD190369B6ED5D56A
                65781F6E035D698BC542B39D8A0CF264B19A431DE7905ECF6618CEC86C079B91
                AA48477B91C548E3F058B2B74E226274DE55A3E9C8F84ACF8B4DD4A524336CCF
                4FD7DAD0600D9BFC47AD2F7BA01F010000002022BC5E7BD53B201E85B28493A7
                5D0A3C092B1EC9A43689E5805ABB3D37A928717B3A1D8E2DA26A784551A6E639
                3A3A92DF38ABBD0F0F0F74A5694D9ACFE7642C8936FD28D4D0A9961E7FC3CA51
                6B52DBAE471195A5E5D8C348946E0864FE69FA91EA7FA4D69083A59DDE956334
                3ACE1E9EC4A194C14F8D88EC7F2441FE230000000064818D5374588A72D56A5E
                D109FE47BDB0DD6EC9A40F15C05894196DAAEBB2DBEF9E95DCE33914C3EA0B37
                98CC12ED62A07B73B55A39E429D3D6F5632E2F2FB5D7EFF404A06B46151C6D86
                CE67780B253A8C6C390E580B358C93125682D4EC7245E961C449C16AF523FE2F
                B72413ED634CA5C82CF84B048A4A0BD82F949EA5E13E151FAF6B697E7661FD35
                000000000C068E65AB5DB73B1EAC22D1EC8A833B20242563BBDD6A76AC27AC05
                50D96A906B136EC306361BDBA3D5E056A14D9B6DBEEF85A6C1A41B90AE04EDB5
                7651FAC59C9E9EF29FFE71A6551724B93EA34815C2C65A1575F6EEEE2E54AA23
                7E7C51C98F32B2FD341F01553F7AFFFEBD96648AC7996A782C814690D2B6EFA5
                AA80ED41994929A2F91F690F5EF81F010000002023369B0D4F71D25BBC6C83B1
                0146A566A9AA5328F9B96AD022955295EAD051499FABF9687C2876318959C925
                017BD76FA75AC5299F16F2BEBCBCB4AAFDD16DB85EAF034698D285777272A2BA
                3815E56A7D8473FBAB3B3655C5CA1175909757F3773B3268DF551B8F6C428ED4
                33FB1F55C50501AD21A66DDF4B5501DB837210975051E659C3FA6B0000000018
                27362FB8E2412619E7D8A62997B3ED0A21C9000D0E9DDFD6449E9D90CBAE8552
                01C687D64773970DFF0D3E565C6135B72B59322F5FBE0C78A0DA2CDA74A7D381
                22754A7E16A5F9C7296CFD03368BBA7500546E6F6FE91653B76FF53F52D75F83
                D610B61499F91FA1CCBC14A1C3482793090BF4C87F040000008071D24B2C9B4A
                51BEDB67238D55244842CE6843777D7D4D27D77E771BDBDE3211729063B56EEC
                2FBE24D6B3D21CCE305CEC95A3E5E608AE1F89F2DAE3C031F98DA7F268D33BD9
                417FCF4A1970471F3AD978ABD5CAA01FA9EBAF09F81F65E63C02396FDFCAEA4D
                E779DE8B72FD354BFD08F98F0000000030487A8C6593D0AC4BC6B5D5BEEAAF4D
                D30B0C689E112A9A055E289986CD75D2D9A1592F95D58D3D75016D36EF534390
                CD8682B93BD5135D5D545E942157171717015B45F7293D4F346185EE6B4EA11D
                23793F5FC3EC76D4490DAF0E113F8288274F9EB4EE0EFFA3AC4A01FF23947E2A
                A1E77987FF1100000000F6053284B4AC28BD50947952A625E637FFD0920C748A
                4CE4B7A68F25E62D7F502252ADC29E15613B957E88D85892EE39EABFAEAEAE5E
                BC7811F670D5E41DE6B4EBEA80D80F0E1B6CFC9953653BC7ACB184CD499AECC3
                693BF91FF17FD9FF4860FDB52472400E55A1CCF62C07AFBC28FD8FAA31C255AA
                FE47D5FCD9C87F0400000080AC79FBF62DCD571C0C3039EB0AD8187647A23996
                5945021239FBA4F3B8582C2CADF1A274B810A5F96DAEBF287D2BE8A4A8335A7F
                1D64B862939BE4D16F83ABFA515126440FAE1FDDDEDED2C3441D9350F16B5A8F
                D86063F1C8B96676AC9BCFE74D9E8FA241B086FF5156A580FFD11E94514F8D67
                E5F03F02000000C07EC1B16C0E19970BEB18A84ED06CAC283D92D47092DA35DA
                00F3F0F040934E7B11F0EAEA8A465833F56B61D70C5EDCCAA1610EC241ED2EC9
                949A3407AA1EC5F9B8DA8E4D3573FCDA63FCFC4774A0C74AFC5AC0512D9A3DAA
                EC61E588DAE696C25FB3F1A8495725A26EFD3562BD5ED3B11E4B04F21F65E63C
                02396F1065D453E3597981FC4700000000D8373E7CF8C0ABCF768D65E3B997B4
                8502DADE45E9232309B8D0F8C8D86C3664B2DA8B47FC0A9426BB4D999224459D
                F351B6A82285A56011562DCAB336AEA71A5B319FCF5FBF7E1DAAB5C476BBA52B
                2AEAFA6B6CAADDDFDF535FDC62D664B45A539E231B6D1AFE47599502FE47287B
                2DE17F04000000803DC539968D3D86A48414D08A16BBE5B439CD766D5C9B166C
                628E3D19284DEE5764B457FD1D9A8691CE0B0DE37ABDA60F676767AD275A061F
                89D2B1C2D20B29A08C125691E911CD3A4D3C1AACB968EE667436DFBD7B276559
                ED6631DC3B4D97227DFEE28B2FB43847E9BFE6204C6B23C6971F8B4736B569C3
                C57AF4D5D5D5D1D191DBF84B7CD65FCBC1DC1D5929E07F84B2D7B2F0C87F547D
                B620FF110000000086C466B36147A4AE3B4A9587F392C4F058E1EC486489A916
                60AB4834261549EB1795676767F62B4F91FDFCEEDD3B1A8DCBCBCBD699AE34FE
                2D658BD6CD7A17837A6F408F1DA7FB510B8B605DE3D9B367DAC6CEF78B96814B
                94372C2FBE663FF24D5BB26DCF316B0ECF166E894F67D52D03FA1F0DB714D948
                2D02FE47287BBD1144F97E05FE4700000000D853B6DB2D4D836C92E3684C4A38
                6F915C1729B8C5CE47E1F5B6FD5D09868566EE9E9F9F9B27ACAA354E8346762C
                8FD8F1F171ABF3116D4F335D5EE82A92ECE22CE8A45782621C316A2FB4534F9F
                AB418E7413ADD7EB26172433557F25AA5FBB1A9B921F75EDB8148FB4E44A3675
                B20C4A669B1AB0E6A9291BF21FD5AEBF26F31F896C349731492D0147754C2708
                65B2B208B7FE1AF21F0100000060A838C7B271D013D94BF4996B601529B8A9CC
                116D36D991C6E782443DA259A67DCA7316834E4F4F45996CFBECECACF57490D5
                CD26B1C3890BAB8CA4578BFC0FDA4B9BCD8D61E79DC78F43BA6A5D90CCD4DE4D
                B5AFCD7D2E21B59154F2BBFDC78EF9AD384FB6DA4187474175171FFF23E12DBB
                883C348E4C9A1156C90A5815CA3D29F93687FF1100000000C0FF3A22712C9B83
                F9C72FE4799EC4EBBB9165A55950A1DAC9416D6A76A4F109465AA7AEAFAFE9D4
                58EEA8CA04B57E22B5BBF0D2E6A2CEF8AF9E3EC309B53CD7CE9744A86BA9533D
                DAC601AF679BAA6AB731EF58EC5608AABA20D1B521FDF8BAAE7228338E9D9C9C
                683517A5570EEBC86E3D123BCF29B3E75113AC5E35E5C9D6BAD0A96643FEA3EA
                FA6B45E8FC4722B2C621B21186D23778707D479943C9978D4DE03FF21F010000
                0060E46C361B37E34D94B20E995572AAB4DD6ED9C79B85A4E04DE5A0369A9F51
                D9C9061E16D4239BA5D3246CC65F5C5CF09F0F0F0F64EAB7EE45E78E46B23561
                76581D30149A99DD7773EADB16697B433DA2F407AC5A38F3F99CEED3B0916BA2
                B4945852716E3F67DDAEBA4DD9ECC8478F74EFF798FF487C2C7088087A87189A
                0F4EC0060FAEEF287B2FF93687FF1100000000C0FFCFE1E1E16349D71DD99093
                E28528AD4D32AEDEEF086EDEB38AC499B647991DC9667EA9A23A82096BFD8876
                69723E4A4302E9274375A953833BB5BF28E1C5CBAA41A9EA5BF1AE59906AE328
                5952A13BB1B5854DBD28EAC2D66CB08F597316973BE53F2A62AEBF2622E81D62
                683E38011B3CB8BEA3ECBD143BA57BB95CD28D6F7E58B5FA1F21FF1100000000
                46C2C1C181704D85C3BE00DA9C89B374E7901D6910D07089328570A7BCE6D5B7
                9D36816F6CF1D2007ABA89D54A0341549BACA41F830262D3C8647D297659A86B
                2F00CB682F158E4BAD158F386535FF69D93B751CD8F1CD413C6AED85B36684F5
                D7B2955D04FC8F50F67AF10BF81F010000000054610949D825C4D1E095986A1D
                82B6DB2D4DBCD8292946B36725BC0EBD961D49FB60FE5356D89423C6D234ADDD
                A5F658F459941353423A6DD977BC1A97F4F0F0B0582C5A55210E5E9B4EA7724B
                7F8D238D4A623E4A56AA532FF00834D939BCC83D9DFDEA8A6CD5CB922EC8A6FC
                FA4DCBAED93752D6DF4980EB1A8857C5F216AEDA786413B2FF5135FF91D86547
                8AA41F890C5C6644AFB24BC011C86130510EAE2CC2ADBF86FC4700000000181B
                0707076E666135AE84E1F9D366B361958488971D892C4C326E636744AA5AA15D
                BD1E385714C1FEF04CA7365037D7EBB576504BE7239AE0D258A5575B9A8ED88B
                2AA4569B8FF064DF92DA2DD942E6508B5AE98736A03B85B3D1AB79C418BA8C39
                219121F894F6E2EBC77C171BCE35D1D5CF4E940A8E1A271B957ED75FCB50FBE8
                F1D0618734DED94139CA527DA8C2FF0800000000A01E8384D46AEA7380495340
                999A1D89FD6E3AD5DF0AAB489C2089E814AD63C626C78AD959893523EA9DEC7B
                571D4D0ECE6C36A3496AB57736FA110D0BEDDB9A39DBDC8020E4A3DAA4275EDF
                59A0694A8424B7E11BA4D8C18D91976553DB64027BE11AEB2A4A09C6F006BE3A
                32C5C719E2DDE8A4F01AD65FABEA47C47ABDA65B9255E03C65143164BF9B808D
                1FF438A0ECE5B4F23DFE58AEBF86FC470000000000F51C1F1F8BD25872D8D726
                D30AAF32C6BE486C77856DBF2A24B1B55CECA2DBCC3405B5B9C10E1DDC4716CE
                FC7DAFA85364CDF2F0AAADA5B2BAC87A15D69E68346A5BA259EF9D640E9F7DA3
                D6DFB5250E2D77EE6C0C2149CA340609C98120E291C137AA168EB9AB7A354665
                7CF98FC490FD6E02367ED0E380B2AFD32AE07F04000000006003D95134676AD2
                770CA6AF6AF5998598CD6643C61887CC44EA058B47B3D94CAEDDE61C7D669F02
                490A4632422D545FC858ADCD334527AB3526A8281DC438575454ADC7997C5AE2
                D9C2201D512BE9AAE515BB9C1DADEFCC6DE09C5974F9898EE29166E0491BCCA6
                3B2CDCD82CB51616C3FA6BD5FC47525D4AA01F09573F0BE71D732803367ED0E3
                80D2702AA39ED9A27CDD423FAF36FA91D9FF08F98F000000003072DEBE7DDBC9
                5F405294EBB2A94BCB1B6C3FCE8EC4E66E8CEC4862E7FE20DD91A48352AB395A
                DBECDA2FA91732348FE69D863820370CE2D176BBADA6F5ADC2C96BDC82D7C2D2
                2A1F68BA43A8CABBAA30A1062ABD2E26CD1ED6679D6F2BBA6638453D5F366EBD
                E0BBAF763537C32E74B59F9E9EA61C3446F33F12C6F8356E6782F83594FEA580
                FFD158CA94A75204F53F827E040000008091B3D96C78E51107D391D7F9AE953C
                AA7CF8F0811D769AB223058485244E233DD9F19DEF7CC72D13364B45519B5D54
                7C31B4A1FBE28B2FF8D006A9824F47282DA36B3DFEC78DA4C2A4177792218D1F
                969058D6B4DC51CAACB3D94C94AFF7A535D53468D52FE94FBED76C7266AB96A1
                413C8AED85D429FF51A1F81F09B8B7E45DE204A174288B70EBAFBD7DFB76B158
                3C227E0D00000000A38763D91CC411F679514DC156F38F36E0B81B4E389DC0B6
                97EE48AC28314D09B3456990B360241D8EA236AF493C9223B9D96C4E4E4E5A07
                8A4E044D707D86344FA9256CABF2ECA34F77F803FB22A919B2B56ECA2D39CC93
                7D8EE47FDDC6A4B0C8995DDDC5209546427D288D2FFF114A559AECBD19283D4B
                91560714C87F0400000000E0C0C3C3034D7DDC1215B1016613CB26E1E4D33287
                4B9A3EB272A4CA49F25DA26C4F4A618BB9BABA7AF1E2853638EA00DA243FA24E
                D12990BE245D87A55F49A5F70664D84DFB8D0B651521A91C692A92944D5933E2
                CF722F9F1E51595DB3CC003D2B3C575BF3C4E07FD494FF683E9FF3D8F665E2A2
                CC507740398EB2F0F03FD2C0FA6B00000000D82F369B4DA7242692A2CC60DDBA
                2E5BD341D9C787859B343D2D76F99218360ECDAB9B478273F71AA4371A9F56FB
                9CC79FACDCD6E4479E4A4D6CA1A76BFDEAF6CE6DABDDB1FA65FE229754855421
                49359354C3C9B92F721C8AEE698FD28B47D51BCAC7FF485878B808A8183D9536
                6707254AED6E1581FC8FD8B11AFE4700000000D83B3C63D966B3993AC1B2CF66
                F2F0F090263B52BF48339E20BB94AC53F3F8D8A45410E5D49683D712F7C5E688
                E995979447D48E652F6969466FF05669DF843D045FC6FCD2DEF26EA5EBF3E5CB
                9761BBE98061FDB5AA7E2476DE49F6F16B022A467F5A400ECD4039ACB280FF11
                0000000080270F0F0FCBE592ECA8AE962D1B63D2C5C07E7533F5BFBCA4142F4C
                9E5E7A88049B37B3D98C73303D96EE4E341F6DF5D8227377B158B4567E737343
                9557736CFB0FA0C335F018D3072A076ABB10BC5F9174A5AE753675965FDA5B46
                AED1C5B95EAFA326C6B6C461FD35FBFC4702ABD1F7570A287728BB5F3002F98F
                0000000000FCF9F0E103CD846846E560C192B945D32C35B590C1E5BB298F75FA
                EC483128CA65E0185EA9AAD8A5EEE6BEB7FA6755CDDD2A54330D381DE2B1A4B6
                190115251095EA09CAED94F165BC5C2ECDCF07D96CBA3257AB952A95C65E64CD
                40D5FFC810BF46ACD7EBD96CC67716D4909C4B01C50D65F7B208BAFE1AFC8F00
                000000B0D71C1F1FDBE72452AD5C4E8774747424FFEB66316EB75B19D4C669AD
                FB1E9276582762C148629350BCBA0D759F553CC38E8575F2A36111504689A7BF
                E4A6ECA469215B5C966BAE15A50B8FBA44634A5AF31F89A0FE4701450DE71DF7
                B61450DC5076BFCB04FC8F000000000002727878F858D275C7A28C6553D76553
                51ED3A1B6989D36CCBEC488F752B94F708CF4439368DCAD96CE6904A5C549C92
                6CE6A374445E79AD935260D838BD26D28B0A938FF4E3D912CD788EDD5451DE77
                1CDF6AB38BBABC608F6E471287F5D764FE23D15DA1A8EE22200C45D302726806
                CA619545B8FC47F46C6955D5A11F0100000060FC1C1F1F3B2F4CD63AE5EA0A99
                A0D4129AF0919997835312BB17CD4A6CFC8C3A717979D93AA9E5B4E5BC2EFBA3
                453051A77FA5A7C7C6540F1DAA316A3D598D76EB0854A12B8D6C2D32935AB764
                2DF5CD9B37DAF7FDAA489DD65F1365FC5A58FF2301379938250616A5C3052382
                FA1F413F0200000000F83F9C1D91C886A45917C7B205341D594862BB8E8524F6
                4E4A3014AC197156239A80D2E7800299CAF9F979EBA476369BD1F08A06F12899
                5A517BA03447EFB78FE9E9B1BF74A973E49A4D582B6DBC5AADD420D61CE8B4FE
                5A51C6AF55F31F096B571701FFA354250616A54359C0FF080000000020120707
                076E862B599234F19ACFE76AEA68D13D8ACDC076BB95D16D52540A6866B34E24
                95232ADD22D43A61A31FD1A8B2F51B5B5350D584E012465385A1BE8F4D26D252
                53AB82348F4DF45725AD2350947E3DCF9E3DEB77045AF31F15C9FD8FA077442A
                05FC8F5076BF3D05F21F0100000000C4E3F8F898A519877DFD63D92C35265EBE
                4D26DE7EDCD1F5703CBF5423D40C8D0F1E9543159E9C9C981D3D8A32F911D9B7
                C2553FAA5516C2EA0EF6C74D708834424FD8A3B4D6966630456968999D8F644B
                E86659AFD7BD673BAA62C87F54EB7F143CFF11F48E785A400ECD4039ACB2C0FA
                6B00000000002A642F05F702383F3F272BCBC164D5D6658B9D0985EA17A5D12B
                A3DB2CF325B19311B5965D8DE89BC49630B59C66B4AD2F33A979F3F99CE36B52
                36AF2B69549BA1A38E5202CDA8530D6C9F2F97CBD6B7F4A2BC7DD6EB7502073D
                073AF91F1531D75F13D03B8296027A1CCAEE178C80FF1100000000400268AA44
                532E9B34281A1CCBA64A5A9A8A14495462A7A4C7D2798AD1F225D1549273604B
                226535B26C2DCD445BDF8852836952DB9A3CBB2F06211BF5D8C848878E512DD5
                49374BEBDB75465D732D37AA361ED98486FC47F4DFF97CFEB85BF03107BB1725
                F43894A1CA02F98F0000000000D2F0F0F0A02EE36D6FB51665D4156170050F45
                53B59BCD469590643EEC1E3523AD798BC5A2559EE361340C7BF5A40C42D3E9B1
                A936071DD018FAB459EE427707DD265513ABB64E9FC8B51841A0FDE63F4299D8
                9DA4F766A01C50C9F738D65F030000000048C7F5F535CDBD1E3F4E9D6B63A9F2
                C2615D835CEC5320699BF998A6E9571CDF6C36676767ADBE1E575757AC1F0591
                33DC64116D2F4F6DC5BC7BB68A52FAAA228D466D9D93C9E4FEFEBED5346256AB
                D5B367CF6A73E4E78021FF11F56EB15818F21FA966670ED62F4A9C14949E6511
                CEFFE8EDDBB7F4007944FC1A000000008099DBDB5B9A7BD5DA966613B71ACB66
                4F2F7669B2836E369B2FBEF8C2BC4D512E3DCECE11EA97E91516430B1FDBBC9F
                A2EA4DBD13BC79E9FBCB9639D957CBE5B275E3D657F4BDE396FF883D017BB775
                511A4A9C20940E178C80FF1100000000407AB458367B680247E659755AA62A35
                B9B9302480C6F3ECECECB12D7936CD68A94C2028A8B245E6928DB9B59AA919EF
                B839D334264D1BBF7FFFDE26D919AB2DA7A7A77DF7CF44A7F5D7E47FD926ECDD
                E24569287182503A9485B7FF919C9FC0FF0800000000A01B979797AD93B05AE6
                F339CDCCF25CB0A917342F892A4599ED9BC62D78F2ECA80ACBF8B01F25E7F1F4
                39119E2791ED2BBAA955E7A3A63AABEFE77B577E3DF31F15F03F1A4E891384B2
                6BC9B739D65F0300000000E80D432C9B99C964429333765EE8DDECEC97ED764B
                D350F374B628FDB688D1AB3C513BD85479EDF7015BA255A5FED98BCC64AED3C6
                B8A22DD7EBF5D1D151D8060447B3F18A320894D75F33E73F12706FC9BBC40942
                E9501641F31FB5AE5009FD0800000000408766513415738B65E3295A35F3EE5E
                294A0F0F0F64C79AB31A1575C98F9A88AD8664C558FB951E1E490E5E6BBDCCE8
                525CAD56F9DFB05DFD8F6AF367A3CCB014F03F42D9FD8211F03F0200000000C8
                81CBCB4B9A903958F28865B39986B2653B9BCD1C5CBD82D0AF4C637374C336F6
                82DA3EAB5193C984FA5E4D0954A51842E623A653FE234D3F125028322E05FC8F
                50762F8B70FE47C89F0D00000000E0C5F5F5354DCBE474CADE149F4EA734511B
                84391A83D6E44762374454F6A51FA998CF6CF5BFE66F1C241B1F952794426439
                08690E17043A045D5DAD1119A2D47C5FBF7E1DB5316E04C97F349BCD1E4B7AB7
                75511A4A01750F6577CD5160FD3500000000807C7878782093AC69E526830D5C
                94F1593463CB330A262A6EFA91A7A060B97BD8CDD293B2FD3D0E42EDA15BDBA3
                A97854DEDFDF9345D4DA0B32AB2E2E2EF873B6916B4CA7FC4742597F4D333B73
                B07E51E2A4A0F42C8B5225A7A79C8D7EA4F91F69CF3AACBF06000000001086F3
                F373B2CA1C6CE9F97C4EA629CDD832374AC362B9F81A4D679B148180CA45B64A
                90679B7D8424EDCB4843A4A93989CF029B553689CCA6D3E96AB5E280D3FCEF53
                B7F5D790FF28FF52C0FF086577CD51C0FF08000000002043686A45F33387A4DA
                D5583669A3D61AABF95BB0B5AD559B7D797969CEC550F82DBE164F5D8A2A73F4
                AB64C5387AB54EE7A338EC68D8855FCBD3DDDA9A874B7CEC7C943FCEEBAF41A1
                C8BC14F03F42D9B11465963767FF230DF81F010000000084E4F6F6D66621A72A
                34C3A3A91BDBA8C392871CD86EB7D5209ADA0199CD66A23499FA6E7223FD2A3E
                0EED8C2A1299F59ADC068AAEB157258F6D216FEBF5FAE8E8A8EFF636A23D319C
                F31F89FEE4891E0F3DA05240DD43D9FDCE1281FC8FE8394335C0FF0800000000
                20308787879612926654CB58B6DA8D47A32B99334631D3E99446439AB5BDA39D
                A90CD590F1117C90D50AF9B38D4D4597E27ABD36BC93CF8D4EEBAF8986FC4750
                46322C05543694DDCB22DCFA6BF03F020000000088C2C1C18170729C99CD6634
                81CBD9D9A113B59AD7EDED6D6BC66232DA6F6E6E2C1584AE42433CF5A7ABCC64
                DEC0BE9DC9F42C9B030D425C639B8A0C2AB38E5994CE3BCF9E3DEBBBBD1D185C
                FE23F1B12C22A09240654319AE9C4C26FCAC43FE2300000000807C393C3C7C2C
                E9BA23876E35ADCB36022FA4EBEBEBD6A0A1D96C461359112878CD59D1B0D483
                92093D41A499AE2257F0260517981C04448213829877A49B71BD5E73E6ECA1D0
                75FD35EA203BFAF56EE84225E924B4A144697FD960FD350000000080DC719690
                C4EE4D207D3024D21E16DC052AC9B86D75A49FCFE76CF106543A5AE9547FECC6
                E480832E93604CCC47B16903DB543606D56C367BF3E64DEC1E79E29FFF08EBAF
                0DA21450D65076178F8A9DAF6510FFA3D60507A01F010000000078717070E066
                54F3AAE193C964E8CA91C6F9F979EB44B6563FB2A75F7127E5D1B5636976668F
                FD726B404A05AA350917C19E3BC3D270AB361ED98406FF2335FF918042917129
                E07F84B263294A274A7BFDA835FF113D5B10BF06000000001097A74F9F7E59A2
                7E69632AD3CC8FE6736AFA95A118B14D50FB4F4E4E5AED768EE013F1175FEB2A
                5818B6F7D43E2C778FADB0241089A236C9665F7E21DF9AC8633A9DD2DD777A7A
                1ABB836181FFD1584B01750F6577CDB108E47FC4EBAFC1FF080000000020053F
                F9C94F6802275FF277A2F6ADA01492AA1FB2426B15FD797676A6794068D07C97
                BA4C36AD30EA4769C48B41D03A1469B4ADA835843A3A7FA62BD02609D77ABDCE
                F09E629AEEF74EEBAFB1BA44F7DA63896A76E660FDA2C44941E9538A9DFF51A8
                F5D7E07F0400000000908ECBCBCBD694BD1A3C0BE47CD2C3CAE35B8B8DFF1167
                10A72E8B3AFD2881126179089BCD9AB6B1EF455632596D63E4975D9B9ABE6B85
                924DD62C628A3278EDC58B17299BE78CAA25C1FF68ACA580FF11CAEE9AA32803
                577DFC8FE4E305F98F000000000052C38E482CA074B29F8B012E255EC5463F9A
                4EA764D0F29A50F63507147D3AEDD597BEE37FDCAC94A9645D984C26644DD924
                3F5AAD5674BBE5E9D667C0E07F645E7F4DC0BD6508D24FC0AA500EE8BC3B9745
                19BF06FF230000000080A14293309AC9B5BA3F5429CAC02E99D05792B989AB36
                6FBBDD9E9C9C9827A064CDCEE7F3E9742ABCF31F0D5422716876D49E66328CE6
                6668065BD3661CCDD1BA0A356D767373A3263FCAFC2E93C0FF28C35284D3E602
                56857240E7DDB901C2DBFF4802FF230000000080DE383F3F2743CEC61ED698CD
                66575757474747623836AD64B3D99C9D9DB5EA4734912503DE6170801B31C6D3
                A7CE50EDA9D6C36FE35BADA0E1468C765A7FADF838FF91C8C05D629465C081C5
                391A5099C3C92AC2F91FD1B3A575D901E8470000000000B1B8BDBDE5A4DA361B
                AB96F0743AA5A95EFEB16CD5E4D964BBB6BA7ECC4BCCFA5126749239D48D23E9
                5F41AAED459BB33FA8BF2C65933C3BABE4470699B8FA2FF81F65580AF81FED41
                99DBA911BB8C6FCEFE47DAE305FA110000000040CF3C3C3CD8A4F2AD5228B16C
                3CC91B842F928D033C59B3D4B5269920ACBA61D6749C8FD57547CBED1DC644FB
                97BF4CA3BD574F303801E143DB98529CFCA897467AE2BCFE9AC8CCFA1D5329E0
                7FB407659EA7A6089AFFA8F5F50FF4230000000080E85C5F5FD3F4CED2114985
                0C3F9AF00D25CAE6C3870FCB12F366348BA57EB5AA0CE965087B99066442553E
                6353AA55B17DF7EE1D87888AA1458976F23F1265FE6CF81FC52E05FC8FF6A0CC
                F0D4F03D1E30FF11FC8F0000000000B24095903A8911D3E9F4EAEA4A4DF4CB48
                A33713EB979A412599AF366F41D9DCB51F84AA4C50DD17128F33A319BAC96472
                7F7FDF6A02517FDFBD7BE72FCB56E337B55B72BBDD3EEE1C7F9842815B226BA8
                BDA3AB7777A7F5D7A4BAC4FA91C8D281620465C081C5391A5099C3C92AE07F04
                00000000304A8E8F8F6966E6E0854413449AF6D1E42FF32836B296ABCB8757E1
                BE388C03488CAA2B1934261FF929A074C58A0C273F325F5DD3E974BD5E6B7694
                F39D55BBE3C3C303B584ECBAEA2D2FADBEC964422D99CD66D213CA0687FC4774
                88C724F16B090E916719B0E37B3B86432CFB3D59C23BFF9106D65F0300000000
                C88EC3C34337E98463D9C8E0A4E95DED14B07769A9937EF458A2BDC5EDB1F155
                9A9A54DB66E7F6DBEFE8A0E6B8B52AF8B9F0AFD0A6061665C8885A2E978F6D19
                B8C88E32BC8737537BA3C9246564C8BD7FFFFECB12CB364F2693D96C46AD924D
                6AF26C12151B8FC5655E7FAD367E8DBD93D2C4AF8954EE18626739E7202284ED
                78B23144398E935578FB1FC9C7CBDBB76FE90182F8350000000080BC38383810
                5DA2B7246464D2FCAF93B74254342B77B3D92C160B9ACB9AF76287088765E97A
                A46B333C9B9D49AF83D3A95F0E8330994CC8886ACDC0C5824B70B195ACAFBB12
                B7916109894A73C334FF23D1963FBB75FD353140DF19B17B7EF66EBD0F770C51
                8EE064F16D0EFF23000000008091737878F858D275C7428965E36F7A773B926C
                369BB3B3B3D6D433D47E3668FB6DAD2A4F24D66BC62A0FF9633932B59BF1ABF8
                E572697E0F5FD44583BADD446A9EA35725FEA755F511A86D55D5FF48C6AF35E5
                3FE2F5D79A0417E1ADC288E456B480FF11CA0CCA1C4E56112EFF11F267030000
                0000648D9B235251BA2AF804E0442213FDA82A2EA4D16B0C4769FA97835CE2D3
                3B872D9B949AAE3D4D03EB47E6F7F02CA93C7BF62CD441E9B26F3D6827F8EE96
                E9BD35912B43FF23918115DDBB1B488655A11CD07977BEEF04D65F0300000000
                D81F9C63D99AD665EB914EFAD16389FF41930916FD2A2396EDC9AA9166A92B78
                53B9C2563B6A3299AC56AB5041A0AD319B74386A18DF146ADFF943D308D05E64
                E9D5DEDD86F5D7FACA7F24F65EF210F03FDACB3287935578F81F691E8E587F0D
                000000006000F8C4B271704A8FF16BEA04F4E1E181669F66FD880C639AC21AF2
                1F196485ACC49180E4D0AFA86D48D0415631D88E3267709F4EA7ABD54A7AF7F8
                60108FD8AE9B95D0074DD5A236B04F1067DAAE1D9CA676DEDEDEAA09C20BEBF5
                D706AA0465D8A4A88D1C447F516672B2F83687FF1100000000C0DE717070E066
                63D7264C51651DCF242FF690397D727262EE4511227ECD478FB0D9B75F41473D
                FAD0659D9414A59B0FD951ADFAD17ABD7688FDD4EE232ACFCECE6A8F252F7256
                91E89BC562A17A07501BC8903B3A3ADA6EB7EC38507B3BD44A4864E3516DEA37
                D2FFA829FF11FB1F090B5B5764E04F61D3A4EA9736BD4BDCC8DEAB4239A0F3EE
                5CF273CF2684B635FF11FC8F000000000086C4E1E1A19BAA52BB2E5B935A144F
                457A7878208BDA3CFB6CF53F52D1E6E831DA1C957EDB9FE6A00E47E92A90D96F
                C3FA917905C0E974FAEEDD3BED1630DF14B5FF3D3F3FAF35D8E6F3395DE11CB6
                C6DF50C3C82AD3FC8F540D8B6E9C26F781AACB8083FF113589C7247F7F0ACB26
                55BFB4E95DE246F65E15CA7D2805D65F0300000000D85BAA5E4896F639EB32FD
                C6B2D9F81F713BC97E164E599FBA124943E9AA808C831C7ADAD406B6A3EEEFEF
                C98832EB47B3D96CBD5EBBDD2652487AFBF6EDD9D9597503B6D0A472C4D4EA47
                EC7FA4D6CC2BC7557B475B5E5C5CC83FABFE47B401DD53226DFE239199BF4F6E
                EDC9A12A94033AEFCE65E1BDFE9AFA58A30748F5D58EFAD4857E040000000090
                1D865836B30DCF0B93F7B52E9BA7FF918D3C61D8C64DDD48AF89743D62FE2DCC
                A401B4D7FDFD7D532C9884AEBD376FDEF834AF29ED115DD8373737D5ED6BF5A3
                DADC46D7D7D7CBE552FB52735672F33F72D08F845191111958CEF99402FE477B
                59F67EB2F83687FF1100000000C0BE737C7CDC9458D78CB6F8B7244116A4E0F1
                6BCE045740F2117D3C6B4EA00D990FA1FE3760638A9DFF51AB7E349FCF57AB95
                CFBD50F50092D5CA96A83C5AF81F492E2F2FAB7E045725DC5443FEA35AFFA3F5
                7A2DF3678B2EA28F7963D1B7E59C55D969609355857240E7DDB92CBCFD8FD427
                1BF26703000000000C15B224C91454277396F6366B34CF9E3DE33F63A7CD96D8
                EB47643FB776449BA037FD3737D2372CDBA1483F086447D9E847AF5FBFAE7E6F
                B84DD47F6DB75B2D47B5D8F913715466156ACFF3E7CF6BFD8FAA07A5FA4F4E4E
                B42EA82E489A7E54F4E47F94BF6B466237900CAB4239A0F3EE5CD24F2A3FF7B0
                FE1A0000000000104F9F3E35AF27550BCD2C7F501235964DB37E6DF423B284A9
                55AA43842761D5931E6B5337AEEE685F955B179AF632D7968F745538F91F3950
                1BE2213D80A455C9481B4FF33F22938F76A9F53F6A3AC47ABD3E3D3DADFD6FEB
                FA6BD465BEDD46E39A11B5F27ECB11776D7C650E27AB28FD8F2CF523CDFF48FB
                05C7FA6B000000000063E0F2F292A6860E867A532C5B241E1E1E4E4E4ECCDB90
                E54C4DA232AAEEE0A3BFA42441AB621CA2D3F0D6FECBF30435EDCEFA91B91E32
                A25EBE7CE9D67132B7342548EC16742B2A616B92478BFC47AA21577B14E93B70
                7B7BFBFCF973B5E391FC8F3CFD2C1C76C9A4F27ECB11776D7C65BF274BEC74F3
                80F98FE07F040000000030069A164669458B65D3D0AC56CF30B70CD75F3390A7
                A28441706B2DDB5177256EF16B36D03D4257B89A39BB281DFD6AD3664B1EBBE4
                3F623491489437CE7ABD7EF2E489E67F440DE0EC48A2413F6275492653EBDDE4
                1E8DDF07BA863287935584CB7F04FF23000000008051717E7EDEFA8EB10A9BB8
                32FF6E55270A95202976FEEC1CC40EB50D9DDA9343E3FB25C67069EFE1D9887A
                8CE07FC4F7C866B3A12B5CBD7459D669CA7CC4D4E63F32EB47742B9121A7E53E
                A303D12EC9F21FE55C8AF13AE98CB86BE32B7B3F59F20983F5D7000000000040
                0DD7D7D7AD16722D1CCB46E66EBC5CDA41FC8F34E1A047D9257379C8ED88AD7B
                0D54E7E2665BE6CFAEE63FB29450ABEFE7E9B65AAFD7B5469DE4B1BBFFD176BB
                5D2E979A430135FBD9B367D53638E43F127DDBBD23F0FB40D750E670B20A27FF
                A35AD7631B3767E847000000000003C32649412D64B5D2F491B3F0C65894CDC6
                FF880D5A37FFA33D445573E2293B363567AE2B15D6F16B0EFE477CB350C99A8E
                3A0EF3F97CBD5E9B7737ACBF66D8EBFAFA9A0EA77E4337CEC5C505FC8F46A07F
                ED67D7C657F67BB244C7FC47F41CA06785217E0DFE470000000000A3C5675D36
                19CBC684D292AAD13DB50DA0296CC0FC47AD0A8BF6A54107C95C22E93414C96A
                6BDAACFABDFD966ECDA36FA2AEBF56AB1FD1DD44B599777CB4F03FAADE83D514
                48AC1F69FE478531FF91D87927E593FF48401FB110057A6F06CADC4E56ED8DC3
                0DB0F43FA2471F3D280CB235F26703000000008C196D5D367B3BFC0725DA3CD2
                4D4552F7AA266DA9E293FF2806AD83164ADDF0AF336CBF6A37F36C585885A86B
                4744E4FCD974A93F7FFE5C33D2E8623627CF164EF16BA2B4E5543F233ED68B17
                2F86EE7F24A08F405F1B4B99F26435DD38C2DAFF887E76E969A0FA1F693FFAD0
                8F000000000046CEEDED6DABC3452D6A2C5B282CFD8FE8B86CD06ADFC79654F2
                47B313FA6E4E9F23E0B04151FA1F9111A5AE8F5685331639E43F62FD48556C45
                9DFF9134EAD46F82E847ADFE47D5FC47047596BAFC58928348D1E3A107510AE8
                6BC329639F2CED66A9BD770A6BFF23CE8168F03FC2FA6B00000000007BC1F1F1
                B1B6A6B88DFAC0962719C0A11221D9C7AFF9F81F25D356F656C46925C39161E3
                CA267E8DAEBD376FDE381C82E3D7B49C4436F16B96F98F340DAB297E6DE8FE47
                1092302CA329639F2C61A14FB17E64E97F64D68FE07F0400000000B02F68B16C
                F6704E4D9A83B2EDAA19B19D82DA6CF423519AC155FF238D0C150A9FE6F974C7
                B0AF7DB551C733939325DFC39BF3824DA7D377EFDEB95DE4D5FCB26AFEECFFFC
                CFFFFCF6B7BFCD9FA579299CFC8F6AB5AA5AFF23A1ACBF56AB1FB1BA944FFEA3
                64BE1B032D312C032A733859FC84A167857FFE6CF81F0100000000EC11D7D7D7
                5A725F4B66B3D9D5D595399B6F13EA969BCD86669FE6E821B1D38F1E4B2C5BD8
                49A1A86EEC2FF70411713AED9E8F2813A319CED59A87EBCB2FBFB4D18FD6EBB5
                C1883250B5AF588D2A9480355539626AFD8F54FDA87ABBD1AD54CD844DCD3E3D
                3D85FFD1B84B0CCB80CAA827CBB2F2C2DAFFA8AA1F55F31F61FD350000000080
                FDC2795D36FF58B6ED765B4DBF52850F9449FEECB06422FA246B6756FDA5C670
                1E59F31538994CD6EBB52188C3005DE16767675AAC280B3486BD1EBBFB1F5585
                2A3A10359B76E994FF88D52529D7F66E6F87B2C645067E1F91CA11776D7C650E
                278B6F7C9BFC47BCF4AAD9FFE8F9F3E7885F0300000000D82F2E2F2F6BA79266
                6B9FFECBEBFBF2FC52BE99B4F74522EB5AF3B3A8A5563F72532252EEE5406279
                25F668A4EC8ECDB1B46DF8CFD6F7F093C964B55A9973576BA8F7C2C9C989E661
                471733478036ED6E99FF483D50F516966B2755F36A9BE3D7B2F53FCAD6EF035D
                43697FB27EF3377FF3DFFFFDDF7B6C4061ED7FC44FAAA65F737AF8500DF03F02
                00000000D8476422CCAE36BFCFBA6CB50B9C57F9418928CDA4BEC7E9FF48A08C
                843A440E728F65CDE9E5332A5BF3804C26135E01D0CDD5EEFAFA5A4B4B44C77D
                F7EE1DDD38D2A2D378ECE87F54F57212A5EAFAE2C50B518931298CF16B42597F
                4D8C48981019F87DA06B28733859C23AFF11FC8F000000000080096D5D364BD8
                C07EF6EC59A7E4D96297F4B7350713CD62C97A4F2C2E0C821CC6C4B30D0EBB07
                54D6A87C5562DE8C2EEF8B8B0BFEB3EB45FEF0F0B0582C3413CBBC0A5B6BFE23
                AD1955E72396A8D85FA9BA2E1BFC8FC6548EB86BE32BFB3D59F2A1C771BB6EFE
                47EA9307F98F0000000000F61DE774486A2C9B8A39AECD66023A2F994C2661B5
                92D8E24BD8FA73908AD2E3DF6B430D45098760982BA1CB6FB55A39A7FAAABA20
                0945C461A479293AFA1F3D3C3C9C9D9D697D9CCD66EBF59A1B5CBDC5E4A1EDF3
                1F89818B142203BF0F740D650E27ABD8AD3B89FC47000000000020000707076E
                467B755DB6566C160056F5A3AA1C609618EC050875CBE0624D4AF527D4B172AB
                27C611E9A28AA71F49C1B456246549886E99EA8EADF98F64CD9BCDE6ECEC4CB3
                DFA43F20FFA9F91F15835D7F6DB87E1FE81ACA4C4E967CC2F8E73F12F03F0200
                00000000123715494D166313E94306F062B13007CD918D4D1572BE189B36A417
                2C3A1D3494E0E5D9CE5E46295E77DC60FD884C29F32B74BAF6D6EB351D4BBD9E
                ED03D99AF27C71666E2921A916A68DFF516DDA2351DE2F6FDEBC917F56F31FC9
                F5D76AF5235697583F1219B84B8CC6EF035D4399C3C92AC2F91FC9B489864AA0
                1F0100000000EC0BCE8E486CA056C3D6AA2677930DAC42C6334D64A91439A5D0
                3663A96BF8C81FA104A08042D2B03429166BE8DA6B35812693C97ABDAE2E7FD6
                44F53AAF751412BBF4F3F3F95CFDD226FFD1DBB76FA9D9D51BA7BA5A1CFC8F72
                F0FB40D750F67EB2C42E68D779FD35EDC906FF230000000000F0113EB16C34F5
                6C35B96B1738D720939826B2724DA8F422857AC45E24924C7499AEE360D8A675
                F7345DA6A37028476BCEAFF57AEDB6C8A0A4295493DAC02B0CD2752EBF3C3B3B
                6B8A5FA35B861ABC5C2E6BC7873693916B8C21FF51EDFA6BAC1F3D62FDB58194
                23EEDAF8CA1C4E96C0FA6B0000000000201E9F7FFEB9F68DA56DAFE561515193
                6A93A96CB6DEA91E4E81249AFD8F3CE58C48E4A0FBE4D0069F76866A7F6D3DAC
                1FDD959877F7D78F4443226D66369B4DA7538ED3A43F178B851A5DC26A2CB596
                BE7CFFFE7DD3FD42B7DB8B172FB42F6F6F6F55B1A980FFD1B8CA11776D7C65EF
                278BEF7167FF230DF81F0100000000807A9E3E7D4A93CEAE967CB1F3ADF8CE77
                BE539B2FC6C6FFA8281777638B576B40EFE288D600CFF6D8D4165B67893D4491
                2A743B0A1B549C0AC4BCBB664A99931F1962360D129228FD8C66B35951AE0AA7
                DE149312512A3E4DED6C32F6C8C65B2C166A9765FEA3EAFA6BA254CAD8D72F2B
                BB77047E1FE81ACADE4F163F4C90FF08000000000044E7F2F2B23AE3B4B1DBE7
                F3394D4365F48D964FA1D5FF48EC26B26CD3DA37D8DCB68032847F6332219346
                5A36C3A7B5AA3947975F53389864369BAD562B8329D50A5FF99C4B9B8CB7B0E3
                AC661CD3F0F13F127D9BBBA19C3BC4C0F52FB75EA3CCADECFD64F16D1E70FD35
                E8470000000000A0119B7C07B54C26139A89D646009D9F9FB74E645981128AFF
                51EF4A87D600FBF6D86C6953799A11703B8A61AFDC9ACD6FE35BAF6AC305EC80
                8DDD65DF53BA352E2E2EE437D51CB74DFE47ADEBAFF56E6F8772EE108312C242
                F51A656E650E27AB288376DDF21F69CF96A69C6E2AD08F0000000000F69DA74F
                9FB67A0C5561C395A6A49AFF51EDD2E61A9CFF45D4E53FD2E6E57D8F4D2ECD48
                D63607392C78637CAA9A4C261CC6D5AAE65453531B3007B8110F0F0F362E00E6
                5EF3F26DEA6A6B5534FF2361CC9F5D94FE47D5F8B50C3D293A3529C3D626E835
                CADCCA7E4F96D845EC06F43F42FE230000000000D0CEE5E5A516836369C3ABB1
                6C8CB6BE782D64D0D25ECE3241FA1D7B3F4A6B9DB9E96EF1307790FF6B694DBD
                7CF95258684396503D32F552275F246AF36432E19BA2B52555FF2319BF569BFF
                88D5256E4F8F9E1422A8A51DBBB5BD8B02BD3703E5504E56B1CB9F4D37FE635B
                D237ACBF060000000000C260F3EEB116327DC946954E1336F54CA7535E7F2A86
                D2E15F6DB586A1AB334DCD4EDF9DD8E21A7F2653AA3585F67C3EA7EB368872A4
                C22A1235808CBA561589EE1DCEB14D8DB16C8983FF91CDFA6B22B22785086A69
                C76E6D8FE588BB36BE328793C511BBF03F0200000000003DE01FCBB6D96C168B
                857909369AF2D2C66439F72BC70C540C4AD985A8F577AADC726336EAE8F26B4D
                48A4A640F27141AADD77BBDD3E965E48CC63896C61513A1C31F4B9531A6F83FF
                51553F120DEBAF0DDDD216166A54D82366A5A005AC0A653EE7DDED8AF5597FAD
                9A5B0DF9B3010000000040376AD765B3815F6FD2A496EC5B730D34E59D97888F
                53206913EEEAF75506A401D92B2043E9512F5D68AD9C3778FEFCB959C414E532
                672F5EBC883D1A64A455F523835C255776B3597F4D04F23FCA4115CAE14083E8
                C20846637F4AFB93259C64C16217BF06FF230000000000D00F64A3D27C94DF43
                76D2023831364D64C9C4356C4675B27EE42C34D8EF98468E49D091DE89DDD4A6
                FABB1E976D2A32845A0D2ABA5CD7EB7528CF23CF3C4A96BB6BFE4742D18FAAF9
                8F8AD23B896E3416B0820B102295234CB2030DA20B23188DFD29ED4F96DB5DD9
                297E0DF98F0000000000402C8E8F8F5B3D38AA4CA75351BA429837239B96A6B3
                BDA827B50755BFD4E6FDB57BD9B43C46EF5ADBD9EF30A6ACDFA03751C90695B9
                0632BDDEBD7BD7297C2C38362294FAA5E67F5418E3D70AF81F655306ECC20846
                63AC65E253C3B739D65F03000000000059E01CCBD60A2F554E65F56D672F6AC8
                9868D595CC231C5BF68ADA65F927BF936FD531597C71F31B727338F27453AAE6
                3FBA2A110DF98FE4FA6B9D5C21121BC9C12BCCB00C35F861AB4299ED59B62C09
                BABB97CBA5FFFA6BC87F0400000000007CB9BEBEBEBBBBEBB41EB90D9CBD58D5
                8FAA1283FA4DAD26D2F4D906374523B1B695E670F90B766E27D7E69DBC67085B
                13AA48D4EA52D4891CFC8F446823397885199602FE477B50A63F353EEBAF217F
                36000000000088825B2C9B01B67B39D82D73F102D8E02C424552AFC8AC2283EA
                F9F3E7AD5BBE7BF7EEE8E8A8298ECCD35D283886FC47B5FA91CC7F2432D62F82
                54A85512BC91F9686401AB4239A0F35E5B165DF267B7E63FA267CB23E2D70000
                000000803FE7E7E7AD33547B8A32EE865716AFFD6F704DC1ADCE642D49D63C75
                9748DA4D8FC81EB17E24D3C01BB8B9B9B9B8B8E0CFB9A945D5F6E4E07FD4AFE7
                45D381C4C786BAC84C6409383EC9861A65FE27CBC7FF4803F98F000000000040
                48AA6B874B1C94089ACEF2126C22820B522FCA8866B8F6DE9EB09D8ABAA3A710
                56FD9728D3CADE9598EB994EA7ABD5EAC99327C1872E069DF21F151FAFBF2662
                4A2A512BB73990A833D44536524BC0F14936D428F33F597C85D3EF32D65F0300
                0000000039122A966D5E32994C7A147A1CFEEBB665BF846AA77F3DC9468C0F44
                176A93E2A9A2BA20650EFC8F2C0F2476AA740E2242D8F14936D428333F594259
                2B00FE4700000000002053642C9B8F1C30994C7809361F41215B05275EC382D4
                9C4F259EF51BB6E17F2D168BD610B6D96CF6E6CD1BF59BDC02D92486FC47D44D
                FA57A4FC479EBB8FD27AEF540AF81FED6519F56489F267D439FF11F267030000
                000080445C5F5FD39CD553FAA1E9AC1A5C1384AEA246860A94D624CB16FA77A4
                971AEC77E95A3959567265EBD62D6F6E6E4E4F4FABFFEA57480A9BFF48589BB2
                A222BBD8EF9B49995B8305FC8FF6B28C7AB204FC8F0000000000C080F08C65E3
                37A2EA0BCFE06A4ED80A33149B40136C5FDDDFDFDB64D19ECD66EBF59A8CAB6C
                3D8F189FFC473EE28BE86E063BEC32E252C0FF682FCBB027AB7A4FB1FF11AF15
                607E7420FF11000000000088422713FAE9D3A7ADFE1D4DFCA0A45591A9556DCC
                528ECF7F9311A91996D5461D84D823DCA98F5517A4EAEEF4CDBB77EFD42CDA79
                0A49D51CF6327E2D54FE231148F7119039E2A86901AB4239A0F35E7B4F15F03F
                0200000000009E24367D9D63D9A6D3294D6AA9141E4BB06913EB64BD3637663F
                F1E97E8CA163FB8A2ECEE572D9BAF17C3E5FAD56BD6846F6376CD5FFC810BF26
                76EA5282FCD9B9C91C22840B55D4F6E45015CA019DF7DAB2937E64F63F42FE23
                0000000000908EC3C3C3D628218DE9744A46FB6C36CB537309AE6884AD30AA56
                15B5A9A12AB7A947DA57368196EBF5BA360B525FB4E63F1276FE47F4AFF159CE
                5DD5ABDCDA93435528877EDE459938DFC7FF483E64A01F0100000000808F4CD0
                D87E495D63D968FA4BC62D5BBF8F4A4AE01EE5A4AE476FDDDEBEC2481D0F52AD
                5A498213E47688DABDD8C422E3CAC10529C3103687F5D7E07F94677B72A80AE5
                80CE7B6D49B07E1424FF113D401E11BF0600000000009271797949B6BABDF13F
                9BCDC8C4151EF16B7B42BFB29A4FAB3C5BEEDFF1C964727F7FDFFA6A5DEC0497
                67CF9E451BB01A3AA9546EEBAFEDA1FF516EA580FFD15E96514F16DFE69EFE47
                12F81F0100000000807EB05F976D3A9D92892B2AFA9141357016146A77CC5397
                71689BE5C64D9B251887208770A88477B159A2489417E4BB77EFB2754132F81F
                35ADBFB69FFE47B99502FE477B59C63E597C972D974BFFFC47F03F0200000000
                00BD717E7E4EA66CABA93F994C6852EB9942BB89809A48CE32D39E63A3881565
                9447EBEAD4CCCDCDCDC5C545DFDDFA5F5AF31F1516FE479C5F2CBDBE232073C4
                19EDD8270E659EE7BDB6F2C263FD35EDF182F5D70000000000409F1C1C1CB46A
                2E459902891890406368AA6639FB54B527A41981C9644247B1C912C24D5AAFD7
                474747C906C167FDB5AB126191FF4824177404940E0873FB5DC63E59229CFF11
                E2D70000000000409F1C1C1C080BAFA2D96C46F35A071D41DDA5AB701390B16A
                40B5436AA39D6538266C68D92FC4D69A2BA42FDCF21FF512BF06A503AA1CCAA8
                278B6F73E43F02000000000063E0F0F0F0B1C4BCD96432A179ED743A35CC5C63
                EB1129F50EFF63D92835B9293829C7A70A55489799B05E884D7C1CC526FD8334
                47A1EAF7B1F32539E43F9ACFE73C9E23339EF7B61450E58653C63E594519BF66
                93DC0DF98F0000000000405E7CF6D967BFF8C52FF8F3279F7CF25BBFF55B36FA
                5151C6E0B09744C0C61864086D666FBFA3DB11ED2B8C24FA84ED66FA6607A99F
                E50CBAC696CBA58D0BD2643259AFD74F9E3CD1BE4F99513B48FEA31EFD8F2024
                6130F7BC8C77B2D4675A28FF23E43F020000000000BDF1AFFFFAAF7FF7777FF7
                E31FFFB8754B9ADACA144891C408376C1A135B9D095E5BD406388F58A8569975
                432AEFEFEF5509C6C06C365BAFD75945B1556D3CB2099BF21F899D77525FF98F
                9CBD3084B7D5DD6367731B4C94233E598587FF91264FBF7DFBB6758501E84700
                0000000020229F7CF2C9F7BEF7BD565B9D0C759ADD7292E3B00D88AABC3854DE
                7517F3F6017B176FA0FA15BFB4A3D335C62E489ACED20447B1A5F43932737B7B
                4B369EDABB51FA1F096FABBBEB1107548EB86BE32BA39E2CBECDD3F81FF141A1
                1F010000000080B8681137B5146508DB6C36134ABEED64BA438F0247D84387AA
                CD504FBF62509036F01BFBD64CB192F57A7D7A7AAA7ED3A39C54B5F10CF98FB8
                F1745B3D96889D07560E76756CAB5B8CD74967C45D1B5F19FB6415E1F21F217F
                360000000000E89FAF7DED6BBFF11BBFD16AF0D3D49626B8B419CD5FE59BD52A
                55ED409BA69B8FA26EE320439877B1AFB075CB1C649A64F8EB419D76E7ABEB55
                89CDF6D3E974B55A55132125A036FFD110FD8F9CB5A14E1B27F3FB18D000A21C
                F7C99A4C26BCAC24D65F03000000000063E0B3CF3E3B3A3A6ACD582C43D884E2
                82C4EC95983220323F2F86E6B1D175576253155D9CABD58A2A94D6575F59B435
                FFA3A274DCE3FC4719AEBFE6EF91D169E33D5158DCC604E5284F9628E3D7B0FE
                1A0000000000180FE7E7E7AD86FA743A254397636D3C0FE7A06B384B219D76AC
                DD58FB32AA2893B9E29392A28CFB685D6F4842D6D7CB972FFB6EB5EE7F242CE2
                D7F6D0FF488C5A61711B1394E33B59F23986F5D70000000000C078B059D845EC
                5661E30CC7229BB444699AD17494EAF79A85EC596DD8DEB58E5BEB716B378821
                B115BB2836B2BB2CCF357BFAA80698F40CAA7E8844D5FF48C6AF55D75F93FFCD
                4A3F4A606907AC2AC3528C5A1D1B5919FB64F1A5BE5C2E6DF4A35AFF23F9C8C2
                FA6B0000000000200B68867A7676D6BAE215279A1195F8354F12084006952701
                3D0A6D836EBF4C1D527B65D69ED39B9B9B67CF9EF53550C22FFF91C85B7708DB
                3C315E0969C45D1B5F19F564F16D9E66FD3506FA11000000000048C1E5E5656B
                8206B2E7AFAEAEA6D3695735C1418008A25924163E7AD1597A14A73471A1D37F
                2DEB17A5F565E31C2777D124A4C46BB1556D3C6A4F53FE23F1F1FA6BBDDBD229
                2D6D91B75886AEED4919FB6415587F0D00000000008C8F6ADE962A3415A6392E
                99BB36A2406C5D439BFDA719A534C7321CA5B501FE2D341F5DFD537DC7AE7EE9
                D9367533AE9FAD2FCB7E4D26939B9B9BD3D3539F41B024D2FA6B62980E2C9D9A
                3DD03EEE79D7C657C63B594251C0B1FE1A00000000001815DBED564BCE52CB74
                3ABDBABAAA5D856DD054A58D2052516D252905AF8087E377E98FBB95C2E407F9
                2FBA2A54DB29541F8B5D22A4D617F8127694935E48AACA9338FF9150F2670F3D
                FF5158578E4E1B0FAB1C71D7C657C63E594538FF23ACBF06000000000032C2D2
                05892CDED96C66194F940F61551BCDF6C8AD2F9D5A65DE58CA465F963C7E8CDC
                4694AA8D1492586114762A526B6B3965BB7C876FD3BBA274ED49E385A4D2C9FF
                4858ACBF2686E3CCD2A9A903EA57D4714039E293C5F738F21F01000000008011
                F2F0F070727222FF6CB2D27915B6EA7FBB2A29B5DBB76A1941F408CF46C620C8
                817C2AA93DA1FC8195A3F725FFF22FFF62AEE7F0F0703299CC66B3E9742A6BE8
                7AA2AB702EEDE57249A57D8FD45C4869122119FC8F9AE2D764FE2351E70A21BC
                FD23449672867FBFB22D47DCB5F195B14F56E1E17FA43DB2B0FE1A0000000000
                C888CD66737676D6EA58349D4E69A6CB59B4836846CEBB84954B42A199253EC7
                8AD1487B0D4E94BA031B3F7455FCFCE73FB73FCAC1C101D5309FCF67B319C7B5
                797684DBC31292BDEF1BED4526D9C5C545D8319444CA7F1456FD1159CA19FEFD
                CAB61C71D7C657C63B592242FE23F81F0100000000808CB0C9B020766F4A9B44
                8178D2CC9E936C60A558737F7F6FE373D4C4C1C1C1743A9DCFE7540AEF8C48FC
                329F9AD4494222AE4A34C34C937E42792769361E0B58BCFE5A53FE231A1FBE95
                0667218F4FD542D7F6AD8C7DB20AACBF060000000000C6C7679F7DF66FFFF66F
                7FFFF77F6FB3D01559BC34D90D2B6764A23AD9342393A6466A09BB0BDDDFDF93
                CDF3D39FFED4BFC2C3C3435EB64F8448AA4D5DEEB41C1BD3F46E3F78505B70FF
                A3FC9520B7A60EA82FE310EC50A63F597C9BC3FF0800000000008C906F7CE31B
                BFFEEBBF6E63964F26135604D4B7B806F2115C62E0DCBBD8C3E2503FDB3C7725
                366E4707070754B686B6D166326D968DEB90A1E56A0B3B79214DA7D3D56AF5E4
                C993A88990AA361ED984EC7F549B3F9BB323B17E24DA5C215A37C8A71C535F82
                F71D653E65EC9355045D7F0DF98F00000000004046FCF0873FFCF18F7F6CB325
                CB01BC3056DFADFE5F6A158771EB56FE68E3C39E476CEA3449428787879CD288
                90AB9BFDE4273FA1F2FEFE9E2E86269725292189662F24CBF3C5571D4B48EAF6
                ADBB4FA753B2D0B445D9FCE524B506F81F593675407D09DE7794F994F14E96D8
                85DCD28DEFE37F241F2FF03F02000000000079F18D6F7CE39BDFFCA6CD9664C3
                D364970C72837EE4A3E944927E9CAB4D2945F91CAB69DFD63A0B254175ADE7D1
                F1F131AFAA46D4BE24273B87F3255159AB221D1C1C5C5D5D750D64AB6D799384
                D40ABBCECDE773EA82AAFBC8CF9E729261FDB56AFE2362BD5ECBF5D7466339E7
                E0F781AEA1ECF764F1FDC50B475AEA47C87F04000000000006C6E79F7F6EB359
                51260666D3D766637FF125B1A2E47638CD2609DEDA78909D737F7F4F764EADF4
                737E7E4EA7FBC9932736556DB75B76B4A93A311D1E1E1A64C7D6D153BF779690
                4499C0CBBE3B9D88EA7F1456FD11BDCA1CFEEDCFB61C71D7C657C63B592290FF
                91A4553FA263F12317FA11000000000048847D08DB6C36E305DAD519AD836E62
                DE25ACBE130AFBA36B5B7ACA52319A24BF210BE7E5CB97DAC6EC3444B64D27AF
                9C0F1F3E506DCF9F3FAF4A48E7E7E7BC229B4FE423BFD8E7CF649B71E85CA701
                61073A2D96CD1FC3FA6BB5FA91BAFE9AE822E874DA384399C3BFFDD99623EEDA
                F8CAD827ABC0FA6B000000000060C47CEB5BDFFA877FF887BFFEEBBFB631EF35
                EB37013DCA46F10EDDA9E6D68DBB2A6E6CE4908543C68926F7B078747171E1D6
                2F16536AEB64A71BFF71E30F0EE9B479775E49507544F28C5FD3FC8F8412BF56
                9B3F7BBD5EF7E57FD4AF90D4CB41D13594894F56A7F835CDFF487B1621FF1100
                00000000C8149AAA2E168BD6CDD8FC1611BC847AD489F60D1E6AB2705EBF7EAD
                FDEBFAFAFAC58B173E95DFDEDE56E5A7A74F9FD265C30E44FE67B9705D918D99
                4EA7BC98A0FAE65FB3DC6A3325D552F53F92F16BD5FC47F2BF0EFAD1805C30F2
                3928BA8632F1C92ABAC4AF61FD350000000000304868EE7B7878D86ADB7336E2
                DA8CC86601A8933CE4B9B1FDEEA154B001895F2CBE70E6232D6DF6F9F9F9CDCD
                8DC19EB1E1C3870F64F3686171BC161BF15812B6176E6E4D9C1189AE67C3FB7F
                AD5FB58A52B2FC47017D283C771FD041D13594294F16DFE6747787CA7F04FF23
                0000000000902F36B9B4D9F016768E24618515ED05B2DBBE615B62F8DE5FC6F2
                6C586DB5FC65D5F9E8E0E060BD5E1F1D1DF19F9DA2BAB48D1F1E1E168B45559C
                B2BF6C6CBAC91F38D5881623665F095FCC4D9299CD20546D3CB2092DF31F39DB
                B4A2E243D1B586F1F97DA06B2873385945B8FC47F03F02000000000059737878
                D8EACDC17988A97CF4F3366ADD26ACE2D34ABCC3051492DCF429155EC58CCC12
                6DD9B5F3F3F3D56AD5351350ADC2425F2E974B2D0EEEF8F898FD7D3C2F1B6DFB
                62172DE2262189329C6D5EA21972960A5A27FF23E191FFC8AC16094818232A45
                DE6AA0A17999B73C813225E07F040000000000F684F3F3F3D659AFD865416225
                C25FD1C88A6A17A2762AC1886987A0B3767F7FBF5C2E55FFA0838383D56A55BB
                36995B7AE9CD66737272A226D2E62CDAD3E954D33BFC0787AF43F64262F5D361
                54796D416A9E9A5ADB86AA8D27F367B7E63F12AEA28F18A0FF114A9FF39B5569
                685EE62D4F50161EFE47D5FCD9587F0D0000000000E48BCD0B4F51BA6CB016E0
                BFA2D680B057250C5BF6AB46F1069C364815779E3E7DBA5EAF7D962163A4FD43
                1FBEF8E20B4DA262379FE02350F82DCAA6329BCD647A2FCBFCD9B9E53F121092
                865F667E1271F919BA2F82FA1F413F02000000000059737D7D4D7356F3364599
                3826B816505B5BA743445567FAEA57C04E715564D868F9ADCFCFCF391D922A00
                F9C8499C459B0EA4A9545757575A7742F58E23E39AD221558F6238EE743A6521
                C92695B8C1FF2865FE2338808CA9CCFC24E2F2339445D0FC478BC5E211F16B00
                00000000204F3EFDF4D33FFDD33F6D9DF88AD25CA7B92F99D96C09CBEF132B38
                E6C3B50A379ACD13EAB8F1FAD5558AD23A2BCA77E364DB68C9B3AFAFAFB57445
                F634A540A2AB68B95CD6EA47C2298B76EB98B3F1C61D247C4E10D5332DA12B9C
                4AB3FF1175531DE45EF21FC101644C65E62711979F413B13C87F040000000000
                F6079B14DA0CAFC82EDAB480AE92C74071EB91B380E5D61829AFBC7EFDFAE0E0
                408A3B06FDC8D911E9F6F6968C283584EDF8F898ECA504D21B2163D93C8F3599
                4C66259392EA50908DB7582CD4A35F9588B6FC47628F2D6D94364A44EFCD7068
                5EE62D4F50F23376B95CDAE847B5FE47F2918BF5D7000000000040EE7CFEF9E7
                9616FE743AA51930952353826A8924F4F8B7A7EB5EFC6EFCCD9B37EAF7B7B7B7
                171717615BD8A41F71BAEBD883234AF9E6FEFEBED611A9EBE8D1F6D4ECF97CCE
                429296E356D38F6CF21FD1BFC4DE5BDA289B4A91B7B628E07FD4DC7D01FF2300
                00000000B03F7CFEF9E7F61B9325CC11495545A0D644AF7EE9A083782A3896BB
                DB6CD6BA4DD306C94428F540459CF8B526D8F851E3D78E8F8FE96AE144450E83
                D6B5E37C59BE7FFFFEBE2448CD931D74E51F1D1D89BA1C25ADF98FE07F84D25C
                8ABCB54501FFA3E6B270CD7F54F5F444FE6C0000000000903B6FDEBCF9933FF9
                13CB8DC990668F92346A88812072CFE8E11120C3E6FEFE5E55766AF5A3D6C835
                C306F42FB27CAAABBCB17E946CD93E69CEB18414EAB845E98E349D4EB92FAA8B
                53B1F33012CDFE47326B58EFB62ECA3C4B91B7B628E07FD45CD233816E7CACBF
                060000000000F685AE2E48340F8E24CDB8559BA14E944993B8199C1B485376B4
                88364F3E7CF8B0582C342FA7F3F373874BC573E80A25A88497660B7B22B4E6D1
                9F6C168AD290A64150CDC842F13F82B306CAA632F30B43C0FFA8B92C4AC1DA52
                3FC2FA6B000000000060F0BC7BF78E1D286C601724CE82F4E897212813912508
                A1FA127C4CA8C2FBFB7B6D65B4E3E3E3F57A6D88A4E8CA76BB3D393951931F1D
                1E1ECE66339B84EBE68E3B4B8A7C5C359C2D12DC4DBA23388D6E6DFE23CFF5D7
                508EBB14797BF108F81F3597F03F0200000000007B47A728B6A82E482949DF85
                AE47B4DC5EDB4CFD93CD9BE7CF9FABE2CEC1C101BF0CF7948D24FCE65C95A80E
                0F0F3978CDD0368701E904075A725224E6D13B1B572D4519E0C69E085A85EBF5
                5AC6AF89BD77D640595B667E6108F81F3597C5CEFFA8D5D511FE470000000000
                603CD847B11565CC0E21ADE2D6ED036EE683CD21D46D9AB637D4D3A9173E5DB6
                DC9753F63C7FFEFCA73FFDA9FAFDD3A74FD7EBB58F7E24BD96B6DB2D993D5A40
                1C273F72EB60C02B815D248A5D52242A652859028A66FF23D193E12DF6DE6124
                C332F39322E07FD4AC9D09EFF5D7E48314EBAF010000000080C1F0C31FFEF0C7
                3FFEB1E5C6B3D9CC591DB0A4B6F2041A53B2BE24A8445A3B6CDEA8FE41C4EDED
                EDC5C585F8387E8D3F6B116DD50DD47ADEBE7D7B7A7AAA1DFAF2F2D23E782D2A
                C52E23123746A6D64ED3B0F57A3D9FCFF958B54734BB75883699A9EB06ADDB5B
                D666598F73F38485CF8BE7879C6B73A8D6BF196EFBCABB2CB83413F03A0C7B68
                759BC275FDB52AF4207DFEFC39E2D70000000000C000F8D6B7BE757E7E6E2921
                D1A499AC629A0D3F96A8DFF7A817F472F426832A1F8A7261FBE572A9B9201D1E
                1EAED7EB274F9E18F66D4D8DB4D96CCECECED4E038AE998CA5D96C26FCF4A3DA
                B1AD355C6D6A93EB067E59C2EE48514F191D515B7FAD3A20D95E360080568A2E
                F9B35BF31FC1FF080000000000E4CBA79F7EFAD5575FC93FBFF18D6F7CF39BDF
                B4DC9713694B9BDC1E83C13C265B3A545F6CEA316FC32FC9C932D1D647134A22
                6D9B14DA55A7242AABCBAE899C9C8F6A51F3227DB9235253A725627716F8E8C5
                2EAA4E2DAB314162FF82833CBB2C3C22AD6CF675685EA493D8A9DADA8D430D35
                5FE703BD6082F49DD5F9BBBB3BF333A4D5FF08F9B30100000000C0C0E814C5C6
                5990447F32414ABD69D0DA967C49AEB920893251D16AB5325835555848DA6EB7
                64EDBC7CF952FB2F67CE9ECD66AA21D4AA70797AE5386C2FF7E2D448AC228968
                17B3148FB4CF4291969A0C5400B265B8176AA8963FEEA262CD9B61FD35000000
                000030787EFEF39F1F1C1CC83FBBBA20D19C98D3BB54AD6E4B933E9E2ED329B2
                2C0779C810A5E50F9DACBBBB3BB24FB42C486297EBFAE8E8C8BEB6CD66435555
                3D8F44E97C4497446BFB331970FEC02D91CBB4994DB8646DEB7D7CFCDB16A917
                96778ACFD1ED15CF4EEAA7FD8E9EA26AEDC69E3518EA0C7BA2D35CFC295D4445
                9DFF91E6D189F5D70000000000C0F0B829B1DC783E9FD3B438810634886A2D8F
                18C9AC351F623299709ED75AD1E7F0F0904FA5346F9A22DAB6DB2D278BD5721E
                31E7E7E7642389A05E3C094E960C1FE34036F645E2EC486E87CE59FD0100A407
                F98F0000000000C008E9E482445C5D5DB1BF0999DC63329B93F525F18196CBE5
                9B376F6A3778FAF429E7EB9994D037BC161BCB285255A955A044994D896C244E
                F733D0CB408692C9CE4A4569B89D0200F40ED65F030000000000E3A45316A4E9
                744AD3628744DA4DE49F60BBA919419AE750897DA8A0D8657BAD2642921C1C1C
                B08424BD72C42EB6AB1AFB2661F148AE3516AFB341F66DAD564D8CC242928C6B
                73764A0200EC2D66FFA30F1F3EDCDDDDC1FF0800000000000C8FAE2E48D52836
                FF8CC80E6887E894FF285B6224423204B2B9E1261EC520600E295542E27A543F
                ACA8ABB601007AA453EE27CB3AE17F04000000000046CBCF7EF6B37FFEE77F5E
                2E97968E2DBCE496502C6DD57B45DB1856772B314649F5AC212BE5EEEEEEFDFB
                F7B5698CEC39383898CFE774EAA7D3A9413C0A92C23CDE98D86C261407AEC71D
                6CECA9DFE0DA0660B8C4FB7942FE23000000000030726C66B48C8C6213234D13
                335CD9ABB6E51C6F787777C74BD71B02D30C1C1F1FCF4AA4B0D2693D6CFB25AE
                B242F6913F488F24A9284909552B01000322EC23A875FD35FAB55D2E97F03F02
                000000000003E6FCFCFCEEEECE66CB1F94883A6BB9EB4AD536F84FEEDDDA60EF
                B1D2A36A60E9EF23CA93C52A127DB054910E0E0E68DFD96CC679D3F9CB1ED7B3
                8BB78BB936C37F351F253EAE9A84DB79C9F380017A00802A916E2B1BFF23E847
                000000000060D8BC7DFB76B158B845B1859A8877ADC790F92848209508A43D39
                54D269179B0DC4C7697D6496E8AA9674787848DB4F261335BBB6D86FE71A190F
                A8C606CA61972353FD20767252D37FD5CAB50F4D7FAA5B1A766FDAACEB67F5E8
                5D4BFBC6D77EF62F5B07D3F0673E65D75363B896028EB35695E5A56868BCE5B5
                61BE432D3B4EB098DE7AEFD32E2CA0D7BE2FE18CFBEABF6CF21FB5FED4423F02
                0000000000B9737D7DBD5C2E6DB6E428362A9B5EA2465D33ABDF511A62DB640B
                B9916A2816FF4BD5444419F5C61292DC3E8701E9DD17C97094A63FA511AB8947
                F60D6BB59C01D8136C34AC5678DF57AF5E69BA4FD3C6F44B379FCFBFF39DEF6C
                B7DBEAA28DF7F7F75A326CE43F0200000000007BC1870F1F4E4E4E68566DB371
                752D3607F2D75C72C33062F6EE54D5CC3EDA1B7BB97DAB57573EE17B9967590A
                A5017572CA10CD1E22969FD303BD6C88647ED6D4E64D2693BBBBBBD60832867E
                E6CCEB573E3C3C3C7FFE5CFDD1C4FA6B0000000000605FA0D9F0D9D9997D141B
                4DAFF35F8B2AAA76D0BB3061D3AA5ADDA7695FE7943D0E0DB3FC97C3669DEA19
                D015D2B5D996039E4FBAA53C6F2890339611BE32FDFF72B9B4794D32994C56AB
                D5D1D191611BFAC55C2C16F03F0200000000007BCAE5E5E5AB57AF6CB6A4E935
                274292B3E73476F8A083E39C059418CD0BE535D02A57051FABE07B013730DA60
                287000EF72B9B4FC81BBB9B9B9B8B8306FE3E07F84FCD9000000FEBFF6EEA6B7
                91AC6AE078CD74C33C6E2719F1B64658FD0D2CBE81273B36484E6F6687448605
                12AB09B36445329F606236AC639648486021219623B31F297283184548DD01A5
                BBA71B987E79AE7C9EDCE74E955DBE75EBBE95FDFF2D22C7B1AB6E955FE27B7C
                CEB900B03D2E2F2F8F8F8FE503F1C6B8C06834529F9573E874E3BCCDF65D759C
                035B99975CB5E77066B26D72D495616CF1D125799F59F91CAEBFB2E86C765B57
                B8BD4B14CB764593C9C4A6724DFD6BBBB8B8A8492312E41F01000060D7D9AFC5
                562C3F2E2BC5AAF5B992CC6DFCE6C2E4303DF318F98A33B054DB69BABB0CE377
                A13B4CC54FB20BF7020C919E96FC35D57290E15E925E1ED384A757767D767636
                9BCD6C6E7C7171515FB92656C68F4AF947AF5FBF36C349F43F020000C0B6B1A9
                62934FE452C5361C0E8BDA25DE3B316D6B3A2487E632A187D4218D0EC7B2C589
                AFDD212D8F6F17F93FEE49DA8D15FEDEA3BC8493AA51DD8D495E1B376B5E503F
                A56DB6CDC07EFCE31F7FFCF1C736B724FF0800000028AEAFAF8F8E8E2CD7621B
                0C06EA13B3FA59D48690B42EA6542013193EDCB92D4B571DC32EBCE25A1E6FC2
                F6EDE1EE126EFC39B03F16F5BF49FD2FAB699B6D6E6A381C5E5C5CD4343032D9
                E41F95D0FF080000005BC8E66B524D1A21A98FE9F2B1789B6629363C1EEFF69D
                BA96995CCE77F4DB8E0A5E6CCD4966953A9BB1E5304EF9AF34994CA6D3A9CDE0
                4F4F4F1F3C7860B971F28F000000B0730E0E0E9E3C7952BDFE934F3E519F740B
                BB69404D23A496422CEF95439FE6082557F1E76F39CC183B74681E57158CD975
                DEFB1E6B5EE39934A24217E9CAB5C96462F3808EC7E3F3F37389FE94FA16ADE4
                907F44FF230000006C27F501FAE8E8C8A6E168B1FCA4AE3E378F46A322400829
                9C2D9828C69C6C87685AEC652FF6C1B8F8719636C7B5F2BE6DD6B34BB24C985F
                A91A0685DE72DA4859479F0C3647F7F39FFFBC5AB9563DC6C16070717171FFFE
                7DFBED937F04000000FCBFCBCBCBA3A3239B058F8BDBE4FFD16864797B7D2FCB
                F63111663539C45F028D61E56649EEF07B206D223B6EDBC95F84F5C2F2E1BD29
                B5AFD064920ED93137BBF2C5A87E4E966CB6A0FE797DF0C107366947DAA79F7E
                5A0A4ED1FF080000003B4D57B1D9188D46EA03F470382C7D3E8E1CFA491569F2
                153E08775F875D245F3FCE7901A6F843CD41F2986017D777F775EC39083A9E1C
                1E5C9BE09A048FA46DB6CDF719EA3FD7C5C5857DE448548BD1D6E51FE9B014F1
                230000006CB90F3FFCD0F22BDCE2B697B67C7CCF24E1A566EFA1D3409CF302BA
                1504899C6392DB8CBDD3BA7E329B86147D5502861E738461B4DC7E6E256FD5F1
                9C9D9DE9FAEBFAF7A8F3F3F3C3C3C3A67B74C83FFAFDEF7F7F7C7C4CFD1A0000
                00B6D6F5F5F5D1D1D1BAC58FABFCF6D20ED4B12587094FA7879AE7A8421F459B
                9A35EF9B0A11FEF05BE718B4ED54FDE03BF7FCECDC8023706EB8A64C2693B3B3
                339B2D9F9C9C7CF4D1477259270AD914B2D9E71F69E41F010000603B991FA0AF
                AFAFDF7BEF3DFBC646EA13F9783C2E1A869012CEA07298BCE550D4D6C587A0BE
                0770E44CAE4E8730029D135FBB88763EBBD29DCAA13B52B4885EAA352E75E5DA
                6432B1F9CE63381C5E5C5CD4640CD520FF0800000058CD5C38C6A62C4B4248FF
                5AAAB959AA56D9DD956A72DB66B2EABCC15D7E266CE5AB23CFC1276F1A957054
                C91F11BF9DD1247EA4FE5559AE1C7A7171717878D8A86DB666937F54DA32EBAF
                0100006057FCF297BFACA90828BEFA817E3018A80FD3A3D1A8F054C8B66E4731
                B71C624A1F7FFE16BFB992AFCC820C430F2DC79F6A81AD7C4E66265945A17794
                4907A51C761174CBEAE76C369B4C26EDDB666F0C2AB9E51F95424E55C48F0000
                00D061FA63F4F5F5F5F1F1B1F9BD6EFD4C60381C4A08A93E0B699DA0618EC8B3
                A370C7D232C7A7659550266188FAAA1C5F319AAC383CEEF91C603E2359392A87
                7651A9DAB1255C083232FB74C5524C679DC160F0873FFCA11AEBB1CF4572EB7F
                44FE110000007645D35EDAC3E1F0E4E4447D522F362DC716677DF74CE6D51D9A
                B6253940CBC7B44D0CA57DA2D9363D887EE39BD17AEB442881F47E2C6DA2547E
                07D0E8AF793EDB4BCF3AF573B264735FB36DB61B87FC23FA6703000060B74807
                D0E2361EB4715E311A8DD4A7EAE170687E68CE7336521279906D3A07056A8B9B
                55B8245CEBDFE4876633AA846B9955AFC9F38CB5393AB8D9F8AC8813269335D7
                A6D3A965E5DA783C3E3D3D756B9BAD917F040000006CA63E371F1D1DD9DF7E34
                1A9D9C9CC8F7C339A4FF20A16D7DB803F578DAD6D3E576069C138EBA751A338F
                90C6EFBEB4718F83C160B1589C9D9DD9B4CD565B3B3F3F3F3C3C945FDD9A6717
                76F947A58DD3FF08000000BBE8934F3E519F83ED6F3F1E8FD5676BF994EFB0BB
                DCA67F398CA78B8D8AEC07D6B469519CF41C2FAD94B6AF6374278611F958E819
                1FEDE8D4BF15B51D493EB2D960FBCA3541FE1100000060EBB7BFFDEDFBEFBF6F
                796335559042B67CA6551D9D9B65BB2E52B73AA7341A67D36C88986720555959
                C287B52BCFA8F887B00567A6D1D14967BDC562319FCF2D2BD7D6B5CD7640FF23
                000000A0813FFFF9CF3FF8C10F2C6FAC4348F27571B495D1BCA40C747AB92B6C
                018F4FA77C9E9941D7588C7F36A2350EF7B291EEAE1B20A5D0C5B21A7AB158CC
                962C13034F4F4F1F3C78E05CB36622FF0800000068E6BFFFFDEF871F7EF8EB5F
                FFDAE6C6EAE3FB78A91313AD38A3F238A76ABA9D36CB5775A59B729BD972AA4E
                D5F1AD3C4B99E4C8248C77243CEAF87B8CF91C68795C72613E9FDB478E84FAD7
                F3AB5FFDCAD7481CF28FE87F040000805DF73F4B9637364348C5AA76DA0E329C
                E4F8E27668B9AD596EB3CD98796741F795E7B3712B6BE8D21E4BF223F5D58CC9
                6D3B35713D5FEF3FD5BA51B966369BCD97ECBBE9C97DCFCFCFBFFFFDEF9BD7B7
                494422FF08000000B0B5BFBFFFF4E953B9AC3E10FFE217BFB0CC422A969FB3C7
                E3B1653BEDE4F3B4683A9D6A112D88D0C593D3F5E3CA796C1B47DB9555EDF21C
                55B443AE397C5DF22CAD8E66B359A3C8916CF6F4F4F4830F3EF0387887F5D7E8
                7F04000080DDF5CF7FFEF39BDFFCA65C7EE79D777ABD9EFD7D7508C9EC85D4B2
                51B1477E530F32991966320CFB91445EEE2ACE617ACC0E4BD2B33C93BAB69887
                1C4EE6294EA9989174B946128EA6D3A9DB09198D46E7E7E75EDA666BE41F0100
                0000CD3C7FFEFCDEBD7B72B969169214B2C91A3AF2915AFDD4138640324C4670
                1E40F2914793434024C9D9CE39AA122EBAB731EED689C722F31509A30DC37947
                F2ED82241C35AA56AB0EE0FCFCFCF0F0D0EF71B1FE1A000000D0D8E3C78FBFFD
                ED6FCBE54659487A4536B31752FC4639F6D6A54759B605295A2458058D316D9C
                E86632E38D20502CA9A32730E7C85A9C43EB0ABF4BB3A51DADEE73A44BD5CC18
                8D03F52FE6E38F3FF67E146EF947C48F000000B0EB1E3E7CF8BDEF7D4F2E37CD
                429210929985D44686E945F0A5EB0F6586E36FF47AC970FCE1CE83C78DF88DC3
                6EEBA360669ECE0D2D37ABFEBF9C9E9EDEBF7FDFFB80DDD65F3B3E3EA67E0D00
                0000BBEEADB7DE7AF3E68D5C7EE79D777EF2939FA40A21E526CFF95EB68BD35B
                962935DA7226655C4137985B79576ED55B79B66D8ABCF1A0AF9A36A3D5C1A3C5
                62315B72AE562B6DF6E2E2A2B4E69A2FF43F02000000DC992BB2356DA73D1C0E
                D587EFD16864B6D3B691C35439AB2D47CB7170C8AA8813536853B2E777601916
                637ADC639C9C9D363B6DDFBF3CE757BAE5C6BD3F4CDE5FADB2C1C562319D4EDB
                57ABC9D6D43F94D192048F4AEBA07941FF2300000060B37BF7EE3D7FFE7CE59F
                CC10D2CF7EF633FB14A462D92D5542486A02E0E5CBE7A642AC9615673099342E
                89399240E3CF53CBCC8E2E1E72CEDC2250362FDEE42FF098CC3E47BEAAD5649B
                EA9FC8783C5E9976E4319044FF23000000C0CAD7BEF6B52FBFFCB2F86AC0481C
                1C1C3C79F2A4588699D4E7E9462124F5D1FFE4E4447DFA2FBE5AC8E6B1814875
                533425E9EEA1C5CCA6F1185EE429D7F4182DD7B9F7754EBA726E331967D3B502
                24CAB3582CCCE5D5BC0C633C1EAB7F3A21BA1D55D1FF08000000B072E7CE9D7B
                F7EE95224755EA365FFFFAD71B6D59CF01526521459061CD5DB84645318FC2D7
                BD9C2BE0729ECF371D5E88D85C26E59921369EC943DF689049CA27E582DAEF74
                3A75EB73541DF66030182FA90BDEEBD4D6A1FF11000000604BE719D5FFE9D34F
                3F7DEFBDF79A6E5C87900AD78EDAC9A77311E6EAC98F31A1DCFAF8B4D957265D
                907258792D4E5FAA7C8E2EAB9770E888B0AC90A0138E24FFA8FD36A55A6D381C
                468B1C09FBFC235D34570D3955113F020000C096EBF7FB6FDEBC59D714E98F7F
                FCE30F7FF8C3A61392A68BB2C5593C3B89104B92E57344ED6FDCA1036F3FE60C
                0F36504DA8C781A5DDAFC786EEF18FB76950A97AECFA6B00E970241DB2BD448E
                64D58540CBAB6D44FE1100000060A5DFEF7FF1C51785916AF4E5975F7EEB5BDF
                5A9991A46EF39BDFFCE6E8E8A8E95E647AA07E9AB56C323F89B0B275E6C902ED
                4715A15A2766BD4C4797CAAAD9977DC9619ECF4CFB238DB3E5F6AF94C8E739C2
                BB5CA00D9A756A72613E9F4FA753B73E47D5B711F9762155E448B0FE1A000000
                E0EEEDB7DF7EFDFAF5CA3F49086963EBD02ADDD8427ECD61E1ED38DB8F2CEDE1
                045D6EDC72B3A9E6EA1D8DA9754888F49F4C329B3C0ECF2D70B9F24F123C523F
                F5AA6A52AAE6E5752DFF0EE257AB55917F04000000D8AAAEBC26D6F54552D7FF
                EE77BFFBE94F7FDAB461AA5E8F59CD19BC4C4252B19FD4F99DF1D25CC9E3D1B5
                6F60B44D27B63EE8D0DD238D99D3D795B3541F36D23FA54E6D714BFDEA651904
                E97324AA011ADD6028269BFCA3D2C0E87F040000809DA323447B7B7BCF9E3D2B
                FDB53E0BE94F7FFAD38F7EF4238719850E21150D3B6AC7E9589CD5BC31741B94
                7C3615EE78B74FFBF84E86757CDD7AE8433FF323BFB274D848824412DC97F646
                5E7A63EBBD4821F3E1E1A1CDEDA3C592C83F020000009A599985D4EBF55EBC78
                B1F2F652C8767676E6D008633018A80FE8A3D1487EF598ECE0B7BF49A0396D9C
                B1790984F93A0309A3031D5DE12BE793B0C5DABF6A1296313A8411F565B9A304
                8C66B3999754239354AB59468E22A3FF1100000060655D919AB6AEBAADDFEFAB
                EBD5676EF5315ACD379AEE57774E1D0C06DDAD658B332DCFADB14EFB496CB732
                B6920C2F424F748F7B4C25B797466EC7BE2E225C4A38F2DBDBA8B43BFD3E5F13
                8E498BFC2300000020ACFDFDFDEBEBEBBB77EFAA8FDD93C9643A9D3AA4AEE875
                D9E4D79C6331F127931D1A2A4AB6BB8F92DF2C98ED382796079236114FFF5C18
                A4CF91F765E9064B927694BC43763D87FC23FA1F01000000ABD534D87EF8F0A1
                4C392693C9D9D959CD46D6CD4C648E311A8D74D3D68D77C9796ED966CC391F57
                D3D176BD6A2C4EA25072ED071F21CAE93D2015BAAD58564F091D36926087EE84
                2D394781F6285F0CACEC909D21F28F000000009FD695B93D7FFEFCC58B173245
                994EA71B3F52AF24F30D892215CB198E97313BF7428A3CFDF3B8927747FB13DB
                E768583EA64DCF43CC5898AFB314675F991CBBF3F8FDDE3849C3F836D588BAC3
                91A41A49CC2868BDB054ABD5478E922CB256C361FD35FA1F010000002E9E3D7B
                F69FFFFC478790269389DBD7DAC3E1501675AEE988B4237D737CCD7E3DE68638
                B7EB4EB5D4D7D66BD3FE26E190D29E90CC8FA2E5AE75CC48E7724A57231D33F2
                DE15DBDCA92CACA9DEBDEFDFBF6F7FF71C6249E41F01000000F1F47ABDABABAB
                77DF7D57CD2266B3992CCAE6F69DB99A84482049A62579E60DD9D7AAE4105569
                34B0B4F21C55A0E3AA09EE6C65036C8F2B062679A5C7BFBBE5367592917ECFD4
                8D8D74F028E829D27D8E4A0D83CCD8500E71A275E87F0400000044757070F097
                BFFC45BEFAAE76D46E14462975442AC2F4D5CEAAC3B1DF0E2FB9C51182B610CE
                A735526EA73DA15D3E1531635BFAB2EC518247B3D94CC24611C6207D8EEA3B64
                E71C3912E41F01000000B1BD7CF9F2E6E6A6B89D414922925BC584EE8854BF34
                9BC7CE4111781C86C3A63AD1E227D0A89A3E4FF2391BF1136D6A2E647566DC8E
                2EC436A3E52895F66886D775CC28686F233D0C4911553F0783414DCE515738E4
                1FD1FF08000000684BDA69CB65A9659B4C26EAA7DBD6D4E4443A22A9894AFDBC
                A8A3D35A1BC90FAD69F820740F6F2F6550A173A0923F6AE8567079E578563EAF
                CCDE461230D2A56A4107A6DE8D2560246FCB35B195CE21FF0800000048E3F9F3
                E7575757C572BEA1A63A6A86737676369BCD9C27693A1149FA6A1761CAD93C6A
                1F4DC86D4E1B6EA8991CA9C3A26CD0DA9C28FBB4B8B4E97B1EF7E8F06EA06346
                122AD28D8DE4D7A02397B7F1E1527D9D5A7739ACBF46FF23000000C08FBDBDBD
                376FDEA80FDC373737DFF9CE77743B24E76FC8A5AFB62422C935BE1AF1FABD6F
                9E323CA20C8794F0B8DAF48DB6897CD907344354F0054DCEF2D893BBD18E426C
                B6BA0BB990A4B79174C5D6EFBA9D6E6FB411F947000000407AFBFBFB7FFDEB5F
                6522A4663ED3A5EACDEC2B4DA4AFB69AD8C835A1D7A8F21EE6E8CA02E7CEE30C
                977B957CC9ADCC97878FB3D457509DCE30F27B1EF42148B4C8AC530BBD6BDDD8
                48743D366483FE4700000040587B7B7BCF9E3DDB78B35EAF777575F5EEBBEF4A
                2D9BB4436AD3AA43A637C24B399B7354C563E99673CB1E8F819E38B29DD8874B
                1D4A1E110B61E3B3B12B47B772CC4906AFEBD41606091B05ED6D24FB556FA7BA
                31B65B6FA3EE2622917F04000000E4E2E0E0E0EF7FFFFBCB972F256F68B2D4B2
                04433A22C99C47AEC9A7C974F201643598B4475D1FF24B7EA26C8E0B995BF724
                B48C2DEA9BE9C646D17A1B49919AC48C149BE88F19245A1730EA5C20C921FF88
                FE470000004040B2349B4C9614E988D4327F47B7D6D6AB593B67E8ECF88CBD51
                DD59C245E5B752A32426CBC7C5FED4795F146F5D902EED332A9FA7900E7917C6
                FBD57C3E97C4CCD0CBA809C9E2546F9E12C0EA56B8C73BF28F00000080ECC8D2
                6CF2A5B7FAB02E1D91D4CF75B7B79C57EBEFCF75706AE3DDC395146DDF4A5E71
                82389D3E4581ECF239B15F97CDF22E5E86D1BE31BF193C2AF5362A0227514A3F
                23E91FB73BBD8D6C38ACBF46FF2300000020B857AF5EA98FD36A9A24CB42CF66
                33A9656BF9ADBB546108A992B3D9609EF373E70EDF695725CF613CF6E3B41C9E
                43979FF81DA922B44577B8AFC3BE726814A5A33CCE6DADAA37336FAF2BD4D485
                38456A3A5AE4DCDBA873F5684D917F04000000E4487A213D7AF448A6559288A4
                E651F25D6EFBDC1F494492E0945CE9963E9079EC23F216B29243942107C9CF43
                0E0BD2792FBE6BBF1D73F5B462F9FEA32EEBF422A95333D32403317B1B1D1E1E
                06DD57D7D1FF08000000C857BFDFFFFCF3CFAFAFAFCD2587A64B2D1391646BBA
                A24D5FEF6BA134CB9BD997CE395487B1CC79478FB74D31543E55841E971DECA8
                D22B5D5FAF1397F495E6026A52A716216C24EF7E928969996DB4F51946F5C83F
                02000000B2767070F0EF7FFFFBD192EE88A4A658D3E9B47D395BB1CC6C927424
                9947955A23B591678996DBF8036DA4698FE73C8FB12B2359175A8A1F67CCE7B4
                AF1B8F976CBEEA6579BF9268912E522B6E97542BECCA69DB9054235DA776FFFE
                FDA0BBDB320EF947F43F020000001AD8DBDB7BF6EC59FBEDBC7AF5EAE1C38766
                39DB743A9D4C26F5E11ECB99A17C1BAF6756D21A294216405AB9B5E071EEE8B4
                F1EE3994507554B45397FFDA6A355DAE74319A5C598A07E90A351D338A132DD2
                F4DB9A04CA1D7A1BA120FF08000000E8903B77EE7CF6D96766A359599DEDECEC
                CC57CD8E9E624908696577245FB6381891F3A1058D6165722C6E3592D1861761
                237E0F6D5D255A6114A399D7E862B4C2A84DF33598467489AE7D919AD8F152B5
                951CD65FA3FF110000009058BFDF5753B2BB77EF1646AFD9E974EA2B51A258CE
                BB744652A9C7ADF75297CCB5CC1CD9BEF3E31C91091A9C4ADE5EBA8B3676192B
                352A2ADDB2B4509A4E2CD2DB4C72564BBD8DD4AF6D2241A580C82EC795C83F02
                0000003A697F7FFFF3CF3F7FF9F2A5B4D6964424E16BCE26532FB3638839DB6C
                9913D17255AC9A4DB50C616C6B2821D5FA741B1FE8DC4E78564B95ADDB66D045
                E5CC0C47B9A01388743D9AD9B74857AB05CA78B2A4BB1AD1DB2810FA1F010000
                001DD6EBF56E6E6E9E3E7D5A184D91647536BF7339F932FF1B06F9538495D153
                053E765C3E27CD396B29CE21D4EF317498AC652BAE52A8C86C5454FAB5DAF43A
                1312D7D6756A3B9B1C1401F94700000040B7E944A4C2282A99CFE793C9C4FCA2
                D80BFD0DBF9AA7156BD6E44E7D3E3AC32DB2905B18A27303705E7C2D68642AE8
                E1AFAB412B2AF15FB30CCDBC1068602D0F4ABD178DC76369D946D8280287FC23
                FA1F01000000D9E9F7FB575757BA9C4D4DF966B3992E6AABBF6FD3B9ABB4D696
                4092242599EBB5258F44F83DD8CC471BB91D55F2B3977C005D3916336654CA33
                2AAD8366A61485A844F34BBFEDE825D5881C4543FE11000000B03D7ABDDE3FFE
                F18F478F1EE9988EF4D5569FF8E7F37988862C7A162797CD5852B16916EA9080
                136ECAED1088B1EFEC9330EA11BF862BDA06239CDED06D8C3CEED14C2F32CB4B
                656BE65268C5AA064621CE9E47FA7D4682472B7B1BADEB6CBDCB1DAFFD72587F
                8DFE4700000040D6742E5261B435994C26B2405BA0B9A2D9BC5676AA3B2595D6
                F64E7D7A8A228335D1532D2AEFB0718F91B5B4F21CD5BA71AE2C37AB1E4BB5A5
                7DE967A924AD1367C03C4C794B198FC7EA42D330109123BFC83F02000000B6D3
                C1C181FAD4AE3E93EB10924C232793C9C68AB6362466A45741D2CDB675695B7D
                EFEDD2A6DA4C771BE5B0ECA098C7BE32DE91AAF153B8F85775D9FBD2D37EE5AF
                EBB6B6720BE69FF465FDEA36E3449D8B1699A751C78C241E6D1906AA0918A93F
                A99F8493DAA0FF11000000B043D4246ABE24AD9182AEA3A46BD9745D9B282AF3
                73E7596ED3604486D1A2547DA3938F670BAC8B166DBCCBCAC6F366B8A79A4954
                7CB53991BE8BB99DD2DD3B4167299A35B0726165911A1222FF08000000D81597
                97977AB6A65B6B4B5FA4D0134E7396A80BDC7474A9F86AC7167DAF963920B9DD
                D7633A95CDE55DD6A64CAF260C544DA0AB3E6F6B2E14AB42427ABFEB6246EB36
                D5453A1B716564D93ECF0849ACCC3FAAC68FCC2C30FA1F010000009DB4BFBFFF
                F8F1E3172F5EBC7AF5AAB89D0CAB4FF6D3E934742E524929D14047948ADB40D2
                C6548E52694FE2338B3C544369F5D940D57B899A67D4CA3FE9284FE942F54FC5
                1605832C99B945BAA6D5D7BA696E1D8EF4BDBC5F88B00B9BBD7B1F8658977F54
                AC2F0C24FF08000000E8B6BDBDBD9B9B9BB7DE7A4B7ED59D53A43B52117D66AB
                63463AA8545ACDAD46351F6463DF19FB9F2BB76FB3DF4637B0BFE03672CBBDDB
                5F697F4EAA8FD4C673557D646B6EB6AEAF50CD9364DDB368DDCFFAB4A0EA2BC5
                1C929F9747779811E1523D9A9C13D28B3AEDF2F2F2F8F8B826FFA81AC9A2FF11
                000000B025FAFDFE175F7CA13EB77FF7BBDF55BFAA89C16C3653F35EE9919464
                02AC6349E64F3DFF342FACBC9965CA491BF55192365BCB8D4D0A98CD65CB63B4
                BC714D90A8B0C8F7B1BFDE1C52B193F1A075BE61A8C68924E64BA868FB5C5E5E
                9AF56BEAB13E393979F0E041CD5D881F01000000DBA6DFEFABE9F1D3A74F7577
                24B3A82D66695B0D1D3C2A56458E0AA38952F1D5F225CB45AFEC537236B28931
                D967EED48CD0FE586CD288D66DD663C8CCFE1036EEAB9AE953DF827AD70AC702
                A9468E74F0A874CB759138E7F4C0624D8962F54FA501976EE0908A683FC2A0DB
                B71F83F79114CB7F04EAFF82F92A1B8D46B2465EF521966BE6F3F96432A17E0D
                000000D836FD7E5F7D86BF73E78E39D39EDD5A373DCB5F69E41BE7991BAF6CB4
                479BDDD9DC7EE57DED8FA5FE9AFA53D474786D466E7FF2BBFB84EC968D496166
                6C515F58F99C59192D2A5685398A35E19EFA5F2D63524593C04AB13E02653948
                87ED34BDB0F2C10AB1AFD2D3C0F2E8EA113F02000000BA4D4ADBD485EBEBEBC5
                62F1AFDB1E49913B6D03C801D13A0442FC08000000D806BD5EEFE6E6E6EEDDBB
                F2B5B3344832C3494C290100CE881F01000000DBA3DFEF5F5D5DBD7CF9D22C5E
                905892F4DBA6C13000C001F123000000A0C3F6F7F79F3E7D5ABAB2D7EB3D592A
                6EFB98E8423669939470D536004017113F020000003AEFE0E040A245253A1DA9
                30D63E5B2C16F3F95C224A52DDA67F05006025E247000000C0F69340D2A3478F
                248424B124C93F9ADF2A6E575597A052EA2103003242FC08000000D821A58CA4
                EAEADD928EA40BDCCC75BE538F1D00900CF1230000006077F5FB7D351778F2E4
                89D96FFB5F06892E2952E326EBB8114B02805D43FC08000000D875FBFBFB8F1F
                3F7EF1E285FAA90BDCE44F72412ADA74FC48FE2417744489B812006C31E24700
                000000FE8FAE6E93CC23B9525F3673948ADB62379D9A648690F44FB3386EE595
                D871A52715800CC9FBF6C3870F0BE247000000004CBD5EEFC993277FFBDBDFE4
                D76AE4480795AA91201D21327F9AB56FD59E4A8496FCD2A7B19414A6AE1F0E87
                C9C756FA695E6F062E01A4557A9FFFE8A38F0AE24700000000804CBC7EFD3AF5
                1000146FBFFDB6BC18E582FA59103F02000000000040BDFF05304D277C043934
                5F0000000049454E44AE426082}
              Proportional = True
              Transparent = True
            end
            object Shape45: TShape
              Left = 9
              Top = 50
              Width = 43
              Height = 46
              Brush.Color = clLime
              Shape = stCircle
            end
            object Shape46: TShape
              Left = 26
              Top = 67
              Width = 10
              Height = 10
              Brush.Color = clLime
              Shape = stCircle
            end
            object Label13: TLabel
              Left = 10
              Top = 138
              Width = 59
              Height = 15
              Caption = 'Tolarence :'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlue
              Font.Height = -13
              Font.Name = 'Calibri'
              Font.Style = []
              ParentFont = False
            end
            object CurvyPanel50: TCurvyPanel
              Left = 4
              Top = 238
              Width = 214
              Height = 61
              TabOrder = 0
              object SpeedButton12: TSpeedButton
                Tag = 88
                Left = 7
                Top = 10
                Width = 95
                Height = 41
                Caption = 'ROBOT HOME'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -15
                Font.Name = 'Calibri'
                Font.Style = []
                ParentFont = False
                OnClick = SpeedButton14Click
              end
              object SpeedButton13: TSpeedButton
                Tag = 1047
                Left = 111
                Top = 10
                Width = 95
                Height = 41
                Caption = 'MOVE TO MAINT'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -13
                Font.Name = 'Calibri'
                Font.Style = []
                ParentFont = False
                OnClick = SpeedButton14Click
              end
            end
            object EditVisionThreshold: TEdit
              Left = 75
              Top = 135
              Width = 61
              Height = 24
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlue
              Font.Height = -13
              Font.Name = 'Tahoma'
              Font.Style = []
              ImeName = 'Microsoft IME 2010'
              ParentFont = False
              TabOrder = 1
              Text = '68'
            end
            object BitBtn5: TBitBtn
              AlignWithMargins = True
              Left = 140
              Top = 131
              Width = 77
              Height = 30
              Margins.Left = 5
              Margins.Top = 10
              Margins.Right = 5
              Margins.Bottom = 10
              Caption = 'Write'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -16
              Font.Name = 'Calibri'
              Font.Style = []
              Glyph.Data = {
                F6060000424DF606000000000000360000002800000018000000180000000100
                180000000000C0060000C40E0000C40E00000000000000000000FFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB5B5B51D1D
                1D00000000000000000000000000000000000000000000000000000000000000
                00000000000000000000001D1D1DB5B5B5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFF1C1C1C0000000000000000000000000000000000000000000000000000
                000000000000000000000000000000000000000000001C1C1CFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000000
                0000000000000000000000FFFFFFFFFFFF000000000000000000000000000000
                000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000
                00000000000000000000000000000000000000FFFFFFFFFFFF00000000000000
                0000000000000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFF0000000000000000000000000000000000000000000000000000000000
                00000000000000000000000000000000000000000000000000FFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000000
                0000000000000000000000FFFFFFFFFFFF000000000000000000000000000000
                000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000
                00000000000000000000000000000000000000FFFFFFFFFFFF00000000000000
                0000000000000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFF000000000000000000000000000000000000000000000000FFFFFFFFFF
                FF000000000000000000000000000000000000000000000000FFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000000
                000000FFFFFFFFFFFF0000000000000000000000000000000000000000000000
                00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000000
                0000000000000000000000FFFFFFFFFFFF000000000000000000000000000000
                000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000
                00000000000000000000000000000000000000FFFFFFFFFFFF00000000000000
                0000000000000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFF0000000000000000000000000000000000000000000000000000000000
                00000000000000000000000000000000000000000000000000FFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1C1C1C0000
                00000000000000000000000000000000000000C4C4C4C4C4C400000000000000
                00000000000000000000000000001C1C1CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFB5B5B51D1D1D000000000000000000000000000000000000C4C4C4C4C4
                C40000000000000000000000000000000000001D1D1DB5B5B5FFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF757575
                000000000000000000000000757575FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFBFBFB747474141414141414747474FBFBFBFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
              ParentFont = False
              Style = bsWin31
              TabOrder = 2
              OnClick = BitBtn5Click
            end
          end
          object CurvyPanel31: TCurvyPanel
            Left = 3
            Top = 3
            Width = 366
            Height = 314
            Color = clBtnFace
            TabOrder = 2
            object Shape29: TShape
              Left = 22
              Top = 26
              Width = 246
              Height = 150
              Brush.Color = 5395026
            end
            object Label24: TLabel
              Left = 128
              Top = 93
              Width = 34
              Height = 19
              Caption = 'TRAY'
              Color = clWhite
              Font.Charset = ANSI_CHARSET
              Font.Color = clWhite
              Font.Height = -16
              Font.Name = 'Calibri'
              Font.Style = [fsBold]
              ParentColor = False
              ParentFont = False
            end
            object Label25: TLabel
              Left = 22
              Top = 198
              Width = 113
              Height = 15
              Caption = 'Tray Pocket X Count :'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Calibri'
              Font.Style = []
              ParentFont = False
            end
            object Label26: TLabel
              Left = 22
              Top = 225
              Width = 112
              Height = 15
              Caption = 'Tray Pocket Y Count :'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Calibri'
              Font.Style = []
              ParentFont = False
            end
            object Label27: TLabel
              Left = 22
              Top = 252
              Width = 109
              Height = 15
              Caption = 'Tray Pocket X Pitch :'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Calibri'
              Font.Style = []
              ParentFont = False
            end
            object Label33: TLabel
              Left = 22
              Top = 279
              Width = 108
              Height = 15
              Caption = 'Tray Pocket Y Pitch :'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Calibri'
              Font.Style = []
              ParentFont = False
            end
            object Shape30: TShape
              Left = 70
              Top = 437
              Width = -1
              Height = 23
              Pen.Color = clWhite
            end
            object Shape31: TShape
              Left = 35
              Top = 331
              Width = 92
              Height = 256
              Brush.Color = clGreen
              Pen.Color = clLime
              Visible = False
            end
            object Shape32: TShape
              Left = 50
              Top = 331
              Width = 5
              Height = 20
              Brush.Color = clOlive
              Pen.Color = clYellow
              Visible = False
            end
            object Shape33: TShape
              Left = 58
              Top = 331
              Width = 5
              Height = 20
              Brush.Color = clOlive
              Pen.Color = clYellow
              Visible = False
            end
            object Shape34: TShape
              Left = 67
              Top = 331
              Width = 5
              Height = 20
              Brush.Color = clOlive
              Pen.Color = clYellow
              Visible = False
            end
            object Shape35: TShape
              Left = 74
              Top = 331
              Width = 5
              Height = 20
              Brush.Color = clOlive
              Pen.Color = clYellow
              Visible = False
            end
            object Shape36: TShape
              Left = 82
              Top = 331
              Width = 5
              Height = 20
              Brush.Color = clOlive
              Pen.Color = clYellow
              Visible = False
            end
            object Shape37: TShape
              Left = 90
              Top = 331
              Width = 5
              Height = 20
              Brush.Color = clOlive
              Pen.Color = clYellow
              Visible = False
            end
            object Shape38: TShape
              Left = 99
              Top = 331
              Width = 5
              Height = 20
              Brush.Color = clOlive
              Pen.Color = clYellow
              Visible = False
            end
            object Shape39: TShape
              Left = 106
              Top = 331
              Width = 5
              Height = 20
              Brush.Color = clOlive
              Pen.Color = clYellow
              Visible = False
            end
            object Label34: TLabel
              Left = 142
              Top = 448
              Width = 139
              Height = 15
              Caption = 'PCB Center to Chip Center'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Calibri'
              Font.Style = []
              ParentFont = False
              Visible = False
            end
            object Shape40: TShape
              Left = 81
              Top = 445
              Width = 1
              Height = 23
              Pen.Color = clWhite
            end
            object Shape41: TShape
              Left = 71
              Top = 456
              Width = 21
              Height = 1
              Pen.Color = clWhite
            end
            object Label35: TLabel
              Left = 67
              Top = 359
              Width = 26
              Height = 19
              Caption = 'PCB'
              Color = clWhite
              Font.Charset = ANSI_CHARSET
              Font.Color = clWhite
              Font.Height = -16
              Font.Name = 'Calibri'
              Font.Style = [fsBold]
              ParentColor = False
              ParentFont = False
            end
            object CurvyPanel35: TCurvyPanel
              Left = 46
              Top = 514
              Width = 70
              Height = 63
              Color = 3026478
              TabOrder = 18
              Visible = False
              object Shape42: TShape
                Left = 35
                Top = 20
                Width = 0
                Height = 22
                Pen.Color = clWhite
              end
              object Shape43: TShape
                Left = 25
                Top = 31
                Width = 20
                Height = 0
                Pen.Color = clWhite
              end
              object Shape44: TShape
                Left = 32
                Top = 30
                Width = 6
                Height = 6
                Shape = stCircle
              end
              object Label38: TLabel
                Left = 21
                Top = 40
                Width = 31
                Height = 19
                Caption = 'CHIP'
                Color = clWhite
                Font.Charset = ANSI_CHARSET
                Font.Color = clWhite
                Font.Height = -16
                Font.Name = 'Calibri'
                Font.Style = [fsBold]
                ParentColor = False
                ParentFont = False
              end
            end
            object CurvyPanel36: TCurvyPanel
              Left = 30
              Top = 33
              Width = 41
              Height = 41
              Color = clMedGray
              TabOrder = 0
            end
            object CurvyPanel37: TCurvyPanel
              Left = 30
              Top = 80
              Width = 41
              Height = 41
              Color = clMedGray
              TabOrder = 1
            end
            object CurvyPanel38: TCurvyPanel
              Left = 218
              Top = 33
              Width = 41
              Height = 41
              Color = clMedGray
              TabOrder = 2
            end
            object EditTrayXCnt: TEdit
              Left = 176
              Top = 194
              Width = 92
              Height = 24
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Tahoma'
              Font.Style = []
              ImeName = 'Microsoft IME 2010'
              ParentFont = False
              TabOrder = 3
              Text = '91'
            end
            object CurvyPanel39: TCurvyPanel
              Left = 77
              Top = 33
              Width = 41
              Height = 41
              Color = clMedGray
              TabOrder = 4
            end
            object CurvyPanel40: TCurvyPanel
              Left = 124
              Top = 33
              Width = 41
              Height = 41
              Color = clMedGray
              TabOrder = 5
            end
            object CurvyPanel41: TCurvyPanel
              Left = 30
              Top = 127
              Width = 41
              Height = 41
              Color = clMedGray
              TabOrder = 6
            end
            object CurvyPanel42: TCurvyPanel
              Left = 218
              Top = 127
              Width = 41
              Height = 41
              Color = clMedGray
              TabOrder = 7
            end
            object CurvyPanel43: TCurvyPanel
              Left = 171
              Top = 33
              Width = 41
              Height = 41
              Color = clMedGray
              TabOrder = 8
            end
            object CurvyPanel44: TCurvyPanel
              Left = 77
              Top = 127
              Width = 41
              Height = 41
              Color = clMedGray
              TabOrder = 9
            end
            object CurvyPanel45: TCurvyPanel
              Left = 171
              Top = 127
              Width = 41
              Height = 41
              Color = clMedGray
              TabOrder = 10
            end
            object CurvyPanel46: TCurvyPanel
              Left = 124
              Top = 127
              Width = 41
              Height = 41
              Color = clMedGray
              TabOrder = 11
            end
            object CurvyPanel47: TCurvyPanel
              Left = 218
              Top = 80
              Width = 41
              Height = 41
              Color = clMedGray
              TabOrder = 12
            end
            object CurvyPanel48: TCurvyPanel
              Left = 77
              Top = 80
              Width = 41
              Height = 41
              Color = clMedGray
              TabOrder = 13
            end
            object CurvyPanel49: TCurvyPanel
              Left = 171
              Top = 80
              Width = 41
              Height = 41
              Color = clMedGray
              TabOrder = 14
            end
            object EditTrayYCnt: TEdit
              Left = 176
              Top = 221
              Width = 92
              Height = 24
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Tahoma'
              Font.Style = []
              ImeName = 'Microsoft IME 2010'
              ParentFont = False
              TabOrder = 15
              Text = '91'
            end
            object EditTrayXPitch: TEdit
              Left = 176
              Top = 248
              Width = 92
              Height = 24
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Tahoma'
              Font.Style = []
              ImeName = 'Microsoft IME 2010'
              ParentFont = False
              TabOrder = 16
              Text = '91'
            end
            object EditTrayYPitch: TEdit
              Left = 176
              Top = 275
              Width = 92
              Height = 24
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Tahoma'
              Font.Style = []
              ImeName = 'Microsoft IME 2010'
              ParentFont = False
              TabOrder = 17
              Text = '91'
            end
            object Edit5: TEdit
              Left = 189
              Top = 477
              Width = 92
              Height = 24
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Tahoma'
              Font.Style = []
              ImeName = 'Microsoft IME 2010'
              ParentFont = False
              TabOrder = 19
              Text = '91'
              Visible = False
            end
            object Edit6: TEdit
              Left = 189
              Top = 507
              Width = 92
              Height = 24
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Tahoma'
              Font.Style = []
              ImeName = 'Microsoft IME 2010'
              ParentFont = False
              TabOrder = 20
              Text = '91'
              Visible = False
            end
            object Panel40: TPanel
              Left = 162
              Top = 477
              Width = 21
              Height = 24
              BevelOuter = bvLowered
              Caption = 'X :'
              Color = clWhite
              ParentBackground = False
              TabOrder = 21
              Visible = False
            end
            object Panel41: TPanel
              Left = 162
              Top = 507
              Width = 21
              Height = 24
              BevelOuter = bvLowered
              Caption = 'Y :'
              Color = clWhite
              ParentBackground = False
              TabOrder = 22
              Visible = False
            end
            object BitBtn3: TBitBtn
              AlignWithMargins = True
              Left = 274
              Top = 194
              Width = 74
              Height = 105
              Margins.Left = 5
              Margins.Top = 10
              Margins.Right = 5
              Margins.Bottom = 10
              Caption = 'Write'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -16
              Font.Name = 'Calibri'
              Font.Style = []
              Glyph.Data = {
                F6060000424DF606000000000000360000002800000018000000180000000100
                180000000000C0060000C40E0000C40E00000000000000000000FFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB5B5B51D1D
                1D00000000000000000000000000000000000000000000000000000000000000
                00000000000000000000001D1D1DB5B5B5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFF1C1C1C0000000000000000000000000000000000000000000000000000
                000000000000000000000000000000000000000000001C1C1CFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000000
                0000000000000000000000FFFFFFFFFFFF000000000000000000000000000000
                000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000
                00000000000000000000000000000000000000FFFFFFFFFFFF00000000000000
                0000000000000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFF0000000000000000000000000000000000000000000000000000000000
                00000000000000000000000000000000000000000000000000FFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000000
                0000000000000000000000FFFFFFFFFFFF000000000000000000000000000000
                000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000
                00000000000000000000000000000000000000FFFFFFFFFFFF00000000000000
                0000000000000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFF000000000000000000000000000000000000000000000000FFFFFFFFFF
                FF000000000000000000000000000000000000000000000000FFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000000
                000000FFFFFFFFFFFF0000000000000000000000000000000000000000000000
                00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000000
                0000000000000000000000FFFFFFFFFFFF000000000000000000000000000000
                000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000
                00000000000000000000000000000000000000FFFFFFFFFFFF00000000000000
                0000000000000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFF0000000000000000000000000000000000000000000000000000000000
                00000000000000000000000000000000000000000000000000FFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1C1C1C0000
                00000000000000000000000000000000000000C4C4C4C4C4C400000000000000
                00000000000000000000000000001C1C1CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFB5B5B51D1D1D000000000000000000000000000000000000C4C4C4C4C4
                C40000000000000000000000000000000000001D1D1DB5B5B5FFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF757575
                000000000000000000000000757575FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFBFBFB747474141414141414747474FBFBFBFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
                FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
              ParentFont = False
              Style = bsWin31
              TabOrder = 23
              OnClick = BitBtn1Click
            end
          end
        end
      end
    end
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 500
    OnTimer = Timer1Timer
    Left = 1143
    Top = 59
  end
end
