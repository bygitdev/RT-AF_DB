object FrmDailyReport: TFrmDailyReport
  Left = 0
  Top = 0
  BorderStyle = bsNone
  Caption = 'FrmDailyReport'
  ClientHeight = 695
  ClientWidth = 1094
  Color = clGrayText
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnResize = FormResize
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object GridPanel1: TGridPanel
    Left = 0
    Top = 0
    Width = 1094
    Height = 695
    Margins.Left = 8
    Margins.Top = 8
    Margins.Right = 8
    Margins.Bottom = 8
    Align = alClient
    BevelOuter = bvNone
    Caption = 'GridPanel1'
    ColumnCollection = <
      item
        Value = 50.000000000000000000
      end
      item
        Value = 50.000000000000000000
      end>
    ControlCollection = <
      item
        Column = 1
        Control = iPieChart1
        Row = 0
      end
      item
        Column = 0
        Control = Calendar
        Row = 0
      end
      item
        Column = 0
        Control = ValueListEditor1
        Row = 2
      end
      item
        Column = 1
        Control = GridPanel2
        Row = 2
      end
      item
        Column = 0
        Control = Panel1
        Row = 1
      end
      item
        Column = 1
        Control = Panel2
        Row = 1
      end>
    ParentBackground = False
    RowCollection = <
      item
        Value = 100.000000000000000000
      end
      item
        SizeStyle = ssAbsolute
        Value = 35.000000000000000000
      end
      item
        SizeStyle = ssAbsolute
        Value = 400.000000000000000000
      end
      item
        SizeStyle = ssAuto
      end>
    ShowCaption = False
    TabOrder = 0
    DesignSize = (
      1094
      695)
    object iPieChart1: TiPieChart
      AlignWithMargins = True
      Left = 573
      Top = 5
      Width = 495
      Height = 249
      Anchors = [akLeft, akTop, akRight, akBottom]
      LegendFont.Charset = DEFAULT_CHARSET
      LegendFont.Color = clWindowText
      LegendFont.Height = -19
      LegendFont.Name = 'Calibri'
      LegendFont.Style = [fsBold]
      TitleText = 'Pie Chart 1'
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -13
      TitleFont.Name = 'Calibri'
      TitleFont.Style = []
      TitleHorizontalAlignment = ithaCenterControl
      LegendShowPercent = True
      LegendPercentMargin = 20
      BorderStyle = ibsNone
      Items = (
        'ALARM'
        (
          255
          100.000000000000000000)
        'RUN'
        (
          65280
          100.000000000000000000)
        'STOP'
        (
          16711680
          100.000000000000000000)
        'RUNDOWN'
        (
          16776960
          100.000000000000000000))
    end
    object Calendar: TAdvSmoothCalendar
      AlignWithMargins = True
      Left = 8
      Top = 8
      Width = 531
      Height = 244
      Margins.Left = 8
      Margins.Top = 8
      Margins.Right = 8
      Margins.Bottom = 8
      Year = 2017
      Month = 6
      Fill.Color = 16765615
      Fill.ColorTo = 16765615
      Fill.ColorMirror = clNone
      Fill.ColorMirrorTo = clNone
      Fill.GradientType = gtVertical
      Fill.GradientMirrorType = gtSolid
      Fill.BorderColor = clNone
      Fill.Rounding = 0
      Fill.ShadowOffset = 0
      Fill.Glow = gmNone
      DateAppearance.DateFont.Charset = ANSI_CHARSET
      DateAppearance.DateFont.Color = clBlack
      DateAppearance.DateFont.Height = -16
      DateAppearance.DateFont.Name = 'Calibri'
      DateAppearance.DateFont.Style = [fsBold]
      DateAppearance.DateFill.Color = 15653832
      DateAppearance.DateFill.ColorTo = 16178633
      DateAppearance.DateFill.ColorMirror = 15586496
      DateAppearance.DateFill.ColorMirrorTo = 16245200
      DateAppearance.DateFill.GradientType = gtVertical
      DateAppearance.DateFill.GradientMirrorType = gtVertical
      DateAppearance.DateFill.BorderColor = clNone
      DateAppearance.DateFill.Rounding = 0
      DateAppearance.DateFill.ShadowOffset = 0
      DateAppearance.DateFill.Glow = gmNone
      DateAppearance.DayOfWeekFont.Charset = ANSI_CHARSET
      DateAppearance.DayOfWeekFont.Color = clBlack
      DateAppearance.DayOfWeekFont.Height = -15
      DateAppearance.DayOfWeekFont.Name = 'Calibri'
      DateAppearance.DayOfWeekFont.Style = []
      DateAppearance.DayOfWeekFill.Color = 16440004
      DateAppearance.DayOfWeekFill.ColorTo = 16640215
      DateAppearance.DayOfWeekFill.ColorMirror = clNone
      DateAppearance.DayOfWeekFill.ColorMirrorTo = clNone
      DateAppearance.DayOfWeekFill.GradientType = gtVertical
      DateAppearance.DayOfWeekFill.GradientMirrorType = gtSolid
      DateAppearance.DayOfWeekFill.BorderColor = clNone
      DateAppearance.DayOfWeekFill.Rounding = 0
      DateAppearance.DayOfWeekFill.ShadowOffset = 0
      DateAppearance.DayOfWeekFill.Glow = gmNone
      DateAppearance.SelectedDateFont.Charset = ANSI_CHARSET
      DateAppearance.SelectedDateFont.Color = clBlack
      DateAppearance.SelectedDateFont.Height = -19
      DateAppearance.SelectedDateFont.Name = 'Calibri'
      DateAppearance.SelectedDateFont.Style = [fsBold]
      DateAppearance.SelectedDateFill.Color = 11196927
      DateAppearance.SelectedDateFill.ColorTo = 7257087
      DateAppearance.SelectedDateFill.ColorMirror = 4370174
      DateAppearance.SelectedDateFill.ColorMirrorTo = 8053246
      DateAppearance.SelectedDateFill.GradientType = gtVertical
      DateAppearance.SelectedDateFill.GradientMirrorType = gtVertical
      DateAppearance.SelectedDateFill.BorderColor = 4370174
      DateAppearance.SelectedDateFill.Rounding = 0
      DateAppearance.SelectedDateFill.ShadowOffset = 0
      DateAppearance.SelectedDateFill.Glow = gmNone
      DateAppearance.CurrentDateFont.Charset = ANSI_CHARSET
      DateAppearance.CurrentDateFont.Color = clBlack
      DateAppearance.CurrentDateFont.Height = -21
      DateAppearance.CurrentDateFont.Name = 'Calibri'
      DateAppearance.CurrentDateFont.Style = [fsBold]
      DateAppearance.CurrentDateFill.Color = 7778289
      DateAppearance.CurrentDateFill.ColorTo = 4296947
      DateAppearance.CurrentDateFill.ColorMirror = 946929
      DateAppearance.CurrentDateFill.ColorMirrorTo = 5021693
      DateAppearance.CurrentDateFill.GradientType = gtVertical
      DateAppearance.CurrentDateFill.GradientMirrorType = gtVertical
      DateAppearance.CurrentDateFill.BorderColor = 4548219
      DateAppearance.CurrentDateFill.Rounding = 0
      DateAppearance.CurrentDateFill.ShadowOffset = 0
      DateAppearance.CurrentDateFill.Glow = gmNone
      DateAppearance.WeekendFill.Color = 15653832
      DateAppearance.WeekendFill.ColorTo = 16178633
      DateAppearance.WeekendFill.ColorMirror = 15586496
      DateAppearance.WeekendFill.ColorMirrorTo = 16245200
      DateAppearance.WeekendFill.GradientType = gtVertical
      DateAppearance.WeekendFill.GradientMirrorType = gtVertical
      DateAppearance.WeekendFill.BorderColor = clNone
      DateAppearance.WeekendFill.Rounding = 0
      DateAppearance.WeekendFill.ShadowOffset = 0
      DateAppearance.WeekendFill.Glow = gmNone
      DateAppearance.WeekendFont.Charset = ANSI_CHARSET
      DateAppearance.WeekendFont.Color = clBlack
      DateAppearance.WeekendFont.Height = -15
      DateAppearance.WeekendFont.Name = 'Calibri'
      DateAppearance.WeekendFont.Style = [fsBold]
      DateAppearance.HoverDateFont.Charset = ANSI_CHARSET
      DateAppearance.HoverDateFont.Color = clBlack
      DateAppearance.HoverDateFont.Height = -16
      DateAppearance.HoverDateFont.Name = 'Calibri'
      DateAppearance.HoverDateFont.Style = [fsBold]
      DateAppearance.HoverDateFill.Color = 15465983
      DateAppearance.HoverDateFill.ColorTo = 11332863
      DateAppearance.HoverDateFill.ColorMirror = 5888767
      DateAppearance.HoverDateFill.ColorMirrorTo = 10807807
      DateAppearance.HoverDateFill.GradientType = gtVertical
      DateAppearance.HoverDateFill.GradientMirrorType = gtVertical
      DateAppearance.HoverDateFill.BorderColor = 10079963
      DateAppearance.HoverDateFill.Rounding = 0
      DateAppearance.HoverDateFill.ShadowOffset = 0
      DateAppearance.HoverDateFill.Glow = gmNone
      DateAppearance.MonthDateFont.Charset = DEFAULT_CHARSET
      DateAppearance.MonthDateFont.Color = clBlack
      DateAppearance.MonthDateFont.Height = -11
      DateAppearance.MonthDateFont.Name = 'Tahoma'
      DateAppearance.MonthDateFont.Style = []
      DateAppearance.YearDateFont.Charset = DEFAULT_CHARSET
      DateAppearance.YearDateFont.Color = clBlack
      DateAppearance.YearDateFont.Height = -11
      DateAppearance.YearDateFont.Name = 'Tahoma'
      DateAppearance.YearDateFont.Style = []
      DateAppearance.WeekNumbers.Font.Charset = DEFAULT_CHARSET
      DateAppearance.WeekNumbers.Font.Color = clWindowText
      DateAppearance.WeekNumbers.Font.Height = -11
      DateAppearance.WeekNumbers.Font.Name = 'Tahoma'
      DateAppearance.WeekNumbers.Font.Style = []
      DateAppearance.WeekNumbers.Fill.Color = 16440004
      DateAppearance.WeekNumbers.Fill.ColorTo = 16640215
      DateAppearance.WeekNumbers.Fill.ColorMirror = clNone
      DateAppearance.WeekNumbers.Fill.ColorMirrorTo = clNone
      DateAppearance.WeekNumbers.Fill.GradientType = gtVertical
      DateAppearance.WeekNumbers.Fill.GradientMirrorType = gtSolid
      DateAppearance.WeekNumbers.Fill.BorderColor = clNone
      DateAppearance.WeekNumbers.Fill.Rounding = 0
      DateAppearance.WeekNumbers.Fill.ShadowOffset = 0
      DateAppearance.WeekNumbers.Fill.Glow = gmNone
      DateAppearance.DisabledDateFont.Charset = DEFAULT_CHARSET
      DateAppearance.DisabledDateFont.Color = clGray
      DateAppearance.DisabledDateFont.Height = -11
      DateAppearance.DisabledDateFont.Name = 'Tahoma'
      DateAppearance.DisabledDateFont.Style = []
      DateAppearance.DisabledDateFill.Color = 15921906
      DateAppearance.DisabledDateFill.ColorTo = 11974326
      DateAppearance.DisabledDateFill.ColorMirror = clNone
      DateAppearance.DisabledDateFill.ColorMirrorTo = clNone
      DateAppearance.DisabledDateFill.GradientType = gtVertical
      DateAppearance.DisabledDateFill.GradientMirrorType = gtVertical
      DateAppearance.DisabledDateFill.BorderColor = clNone
      DateAppearance.DisabledDateFill.Rounding = 0
      DateAppearance.DisabledDateFill.ShadowOffset = 0
      DateAppearance.DisabledDateFill.Glow = gmNone
      DateAppearance.ShowDaysBefore = True
      DateAppearance.ShowDaysAfter = True
      DateAppearance.DateBeforeFill.Color = clNone
      DateAppearance.DateBeforeFill.ColorMirror = clNone
      DateAppearance.DateBeforeFill.ColorMirrorTo = clNone
      DateAppearance.DateBeforeFill.GradientType = gtVertical
      DateAppearance.DateBeforeFill.GradientMirrorType = gtSolid
      DateAppearance.DateBeforeFill.BorderColor = clNone
      DateAppearance.DateBeforeFill.Rounding = 0
      DateAppearance.DateBeforeFill.ShadowOffset = 0
      DateAppearance.DateBeforeFill.Glow = gmNone
      DateAppearance.DateAfterFill.Color = clNone
      DateAppearance.DateAfterFill.ColorMirror = clNone
      DateAppearance.DateAfterFill.ColorMirrorTo = clNone
      DateAppearance.DateAfterFill.GradientType = gtVertical
      DateAppearance.DateAfterFill.GradientMirrorType = gtSolid
      DateAppearance.DateAfterFill.BorderColor = clNone
      DateAppearance.DateAfterFill.Rounding = 0
      DateAppearance.DateAfterFill.ShadowOffset = 0
      DateAppearance.DateAfterFill.Glow = gmNone
      DateAppearance.DateBeforeFont.Charset = DEFAULT_CHARSET
      DateAppearance.DateBeforeFont.Color = clSilver
      DateAppearance.DateBeforeFont.Height = -11
      DateAppearance.DateBeforeFont.Name = 'Tahoma'
      DateAppearance.DateBeforeFont.Style = []
      DateAppearance.DateAfterFont.Charset = DEFAULT_CHARSET
      DateAppearance.DateAfterFont.Color = clSilver
      DateAppearance.DateAfterFont.Height = -11
      DateAppearance.DateAfterFont.Name = 'Tahoma'
      DateAppearance.DateAfterFont.Style = []
      StatusAppearance.Fill.Color = clRed
      StatusAppearance.Fill.ColorMirror = clNone
      StatusAppearance.Fill.ColorMirrorTo = clNone
      StatusAppearance.Fill.GradientType = gtSolid
      StatusAppearance.Fill.GradientMirrorType = gtSolid
      StatusAppearance.Fill.BorderColor = clGray
      StatusAppearance.Fill.Rounding = 0
      StatusAppearance.Fill.ShadowOffset = 0
      StatusAppearance.Fill.Glow = gmNone
      StatusAppearance.Font.Charset = ANSI_CHARSET
      StatusAppearance.Font.Color = clWhite
      StatusAppearance.Font.Height = -15
      StatusAppearance.Font.Name = 'Calibri'
      StatusAppearance.Font.Style = []
      Header.Fill.Color = 14059353
      Header.Fill.ColorTo = 9648131
      Header.Fill.ColorMirror = clNone
      Header.Fill.ColorMirrorTo = clNone
      Header.Fill.GradientType = gtVertical
      Header.Fill.GradientMirrorType = gtSolid
      Header.Fill.BorderColor = 9841920
      Header.Fill.Rounding = 0
      Header.Fill.ShadowOffset = 0
      Header.Fill.Glow = gmNone
      Header.ArrowSize = 15
      Header.Height = 30
      Header.Font.Charset = ANSI_CHARSET
      Header.Font.Color = clWhite
      Header.Font.Height = -15
      Header.Font.Name = 'Calibri'
      Header.Font.Style = []
      Footer.Fill.Color = 14059353
      Footer.Fill.ColorTo = 9648131
      Footer.Fill.ColorMirror = clNone
      Footer.Fill.ColorMirrorTo = clNone
      Footer.Fill.GradientType = gtVertical
      Footer.Fill.GradientMirrorType = gtSolid
      Footer.Fill.BorderColor = 9841920
      Footer.Fill.Rounding = 0
      Footer.Fill.ShadowOffset = 0
      Footer.Fill.Glow = gmNone
      Footer.Font.Charset = ANSI_CHARSET
      Footer.Font.Color = clWhite
      Footer.Font.Height = -15
      Footer.Font.Name = 'Calibri'
      Footer.Font.Style = [fsBold]
      Version = '2.2.0.1'
      MultiSelect = True
      DisjunctDaySelect = True
      TabOrder = 1
      Align = alClient
      OnMouseUp = CalendarMouseUp
    end
    object ValueListEditor1: TValueListEditor
      AlignWithMargins = True
      Left = 8
      Top = 303
      Width = 531
      Height = 384
      Margins.Left = 8
      Margins.Top = 8
      Margins.Right = 8
      Margins.Bottom = 8
      Align = alClient
      DefaultColWidth = 180
      DefaultRowHeight = 24
      DisplayOptions = [doAutoColResize, doKeyColFixed]
      DoubleBuffered = False
      DrawingStyle = gdsGradient
      FixedCols = 1
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Calibri'
      Font.Style = []
      Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goThumbTracking]
      ParentDoubleBuffered = False
      ParentFont = False
      TabOrder = 2
      TitleCaptions.Strings = (
        'Item'
        'Value')
      ColWidths = (
        180
        345)
    end
    object GridPanel2: TGridPanel
      Left = 547
      Top = 295
      Width = 547
      Height = 400
      Align = alClient
      BevelOuter = bvNone
      Caption = 'GridPanel2'
      ColumnCollection = <
        item
          Value = 100.000000000000000000
        end>
      ControlCollection = <
        item
          Column = 0
          Control = Label3
          Row = 1
        end
        item
          Column = 0
          Control = ValueListEditor2
          Row = 2
        end
        item
          Column = 0
          Control = StringGridErrorList
          Row = 0
        end>
      RowCollection = <
        item
          Value = 100.000000000000000000
        end
        item
          SizeStyle = ssAbsolute
          Value = 30.000000000000000000
        end
        item
          SizeStyle = ssAbsolute
          Value = 150.000000000000000000
        end>
      ShowCaption = False
      TabOrder = 3
      object Label3: TLabel
        AlignWithMargins = True
        Left = 8
        Top = 226
        Width = 125
        Height = 24
        Margins.Left = 8
        Margins.Top = 8
        Margins.Right = 8
        Margins.Bottom = 0
        Align = alBottom
        Caption = ' PRODUCT LIST'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object ValueListEditor2: TValueListEditor
        AlignWithMargins = True
        Left = 8
        Top = 258
        Width = 531
        Height = 134
        Margins.Left = 8
        Margins.Top = 8
        Margins.Right = 8
        Margins.Bottom = 8
        Align = alClient
        DefaultColWidth = 180
        DefaultRowHeight = 24
        DoubleBuffered = False
        DrawingStyle = gdsGradient
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Calibri'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goThumbTracking]
        ParentDoubleBuffered = False
        ParentFont = False
        TabOrder = 0
        TitleCaptions.Strings = (
          'JOB NAME'
          'PRODUCT COUNT')
        ColWidths = (
          180
          345)
      end
      object StringGridErrorList: TStringGrid
        AlignWithMargins = True
        Left = 8
        Top = 8
        Width = 531
        Height = 204
        Margins.Left = 8
        Margins.Top = 8
        Margins.Right = 8
        Margins.Bottom = 8
        Align = alClient
        ColCount = 4
        DrawingStyle = gdsGradient
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Calibri'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine]
        ParentFont = False
        TabOrder = 1
      end
    end
    object Panel1: TPanel
      Left = 0
      Top = 260
      Width = 547
      Height = 35
      Align = alClient
      BevelOuter = bvNone
      TabOrder = 4
      DesignSize = (
        547
        35)
      object Label1: TLabel
        AlignWithMargins = True
        Left = 8
        Top = 11
        Width = 531
        Height = 24
        Margins.Left = 8
        Margins.Top = 8
        Margins.Right = 8
        Margins.Bottom = 0
        Align = alBottom
        Caption = ' RUN DATA REPORT'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentFont = False
        ExplicitWidth = 162
      end
      object BtnRunDataSaveCSV: TBitBtn
        Left = 330
        Top = 5
        Width = 209
        Height = 29
        Anchors = [akRight, akBottom]
        Caption = 'RUN DATA SAVE (.CSV)'
        Default = True
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'Calibri'
        Font.Style = []
        Glyph.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          1800000000000003000012170000121700000000000000000000FFFFFFFFFFFF
          D0D0D01212120202020202020202020202020202020202020202020202020202
          02121212D0D0D0FFFFFFFFFFFFD1D1D115151505050505050505050505050505
          0505050505050505050505050505050505050505151515D1D1D1F0F0F0191919
          090909181818D1D1D1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD1D1
          D1181818090909191919F0F0F01B1B1B1B1B1BD1D1D1FFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD1D1D11B1B1B1B1B1BFFFFFFF0F0F0
          F0F0F0FFFFFFFFFFFFFFFFFFFFFFFFA5A5A54C4C4CA5A5A5FFFFFFFFFFFFFFFF
          FFFFFFFFF0F0F0F0F0F0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFA7A7A712
          1212121212121212A7A7A7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFA8A8A8151515151515151515151515151515A8A8A8FFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFA9A9A919191919191919
          1919191919191919191919191919A9A9A9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFAAAAAA1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C
          1CAAAAAAFFFFFFFFFFFFFFFFFFFFFFFFABABAB1F1F1F1F1F1F1F1F1F1F1F1F1F
          1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1FABABABFFFFFFFFFFFFFFFFFF
          2222222222222222222222222222222222222222222222222222222222222222
          22222222222222FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF2F2F225252525
          2525252525252525252525F2F2F2FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFF282828282828282828282828282828FFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF2C2C2C2C
          2C2C2C2C2C2C2C2C2C2C2CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFF2F2F2F2F2F2F2F2F2F2F2F2F2F2F2FFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE6E6E632323232
          3232323232323232323232FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
        ParentFont = False
        TabOrder = 0
        OnClick = BtnRunDataSaveCSVClick
      end
    end
    object Panel2: TPanel
      Left = 547
      Top = 260
      Width = 547
      Height = 35
      Align = alClient
      BevelOuter = bvNone
      TabOrder = 5
      DesignSize = (
        547
        35)
      object Label2: TLabel
        AlignWithMargins = True
        Left = 8
        Top = 11
        Width = 531
        Height = 24
        Margins.Left = 8
        Margins.Top = 8
        Margins.Right = 8
        Margins.Bottom = 0
        Align = alBottom
        Caption = ' ERROR LIST'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = 'Calibri'
        Font.Style = [fsBold]
        ParentFont = False
        ExplicitWidth = 99
      end
      object BtnErrorListSaveCSV: TBitBtn
        Tag = 1
        Left = 330
        Top = 5
        Width = 209
        Height = 29
        Anchors = [akRight, akBottom]
        Caption = 'ERROR LIST SAVE (.CSV)'
        Default = True
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'Calibri'
        Font.Style = []
        Glyph.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          1800000000000003000012170000121700000000000000000000FFFFFFFFFFFF
          D0D0D01212120202020202020202020202020202020202020202020202020202
          02121212D0D0D0FFFFFFFFFFFFD1D1D115151505050505050505050505050505
          0505050505050505050505050505050505050505151515D1D1D1F0F0F0191919
          090909181818D1D1D1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD1D1
          D1181818090909191919F0F0F01B1B1B1B1B1BD1D1D1FFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD1D1D11B1B1B1B1B1BFFFFFFF0F0F0
          F0F0F0FFFFFFFFFFFFFFFFFFFFFFFFA5A5A54C4C4CA5A5A5FFFFFFFFFFFFFFFF
          FFFFFFFFF0F0F0F0F0F0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFA7A7A712
          1212121212121212A7A7A7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFA8A8A8151515151515151515151515151515A8A8A8FFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFA9A9A919191919191919
          1919191919191919191919191919A9A9A9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFAAAAAA1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C1C
          1CAAAAAAFFFFFFFFFFFFFFFFFFFFFFFFABABAB1F1F1F1F1F1F1F1F1F1F1F1F1F
          1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1FABABABFFFFFFFFFFFFFFFFFF
          2222222222222222222222222222222222222222222222222222222222222222
          22222222222222FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF2F2F225252525
          2525252525252525252525F2F2F2FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFF282828282828282828282828282828FFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF2C2C2C2C
          2C2C2C2C2C2C2C2C2C2C2CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFF2F2F2F2F2F2F2F2F2F2F2F2F2F2F2FFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE6E6E632323232
          3232323232323232323232FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
        ParentFont = False
        TabOrder = 0
        OnClick = BtnRunDataSaveCSVClick
      end
    end
  end
  object SaveDialog1: TSaveDialog
    Left = 840
    Top = 256
  end
end
