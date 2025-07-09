object frmLogin: TfrmLogin
  Left = 425
  Top = 330
  BorderStyle = bsNone
  Caption = 'Password'
  ClientHeight = 347
  ClientWidth = 357
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Arial'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poOwnerFormCenter
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 15
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 357
    Height = 347
    Align = alClient
    TabOrder = 0
    ExplicitHeight = 198
    object Label3: TLabel
      Left = 56
      Top = 80
      Width = 27
      Height = 15
      Caption = 'Level'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Calibri'
      Font.Style = []
      ParentFont = False
    end
    object Label1: TLabel
      Left = 56
      Top = 111
      Width = 54
      Height = 15
      Caption = 'Password'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Calibri'
      Font.Style = []
      ParentFont = False
    end
    object Shape1: TShape
      Left = 1
      Top = 1
      Width = 355
      Height = 61
      Align = alTop
      Brush.Color = 9729387
      Pen.Color = 9729387
      Pen.Style = psClear
      ExplicitWidth = 347
    end
    object Label2: TLabel
      Left = 17
      Top = 11
      Width = 36
      Height = 18
      Caption = 'Log In'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWhite
      Font.Height = -15
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label4: TLabel
      Left = 17
      Top = 35
      Width = 287
      Height = 14
      Caption = 'Priviledge controlled by operator / maint / engineer .'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWhite
      Font.Height = -12
      Font.Name = 'Calibri'
      Font.Style = []
      ParentFont = False
    end
    object Splitter1: TSplitter
      Left = 1
      Top = 62
      Width = 355
      Height = 1
      Cursor = crVSplit
      Align = alTop
      Color = clSilver
      ParentColor = False
      ExplicitTop = 82
      ExplicitWidth = 516
    end
    object SpeedButton1: TSpeedButton
      Left = 320
      Top = 11
      Width = 23
      Height = 22
      Glyph.Data = {
        76060000424D7606000000000000360400002800000018000000180000000100
        0800000000004002000000000000000000000001000000000000000000000101
        0100020202000303030004040400050505000606060007070700080808000909
        09000A0A0A000B0B0B000C0C0C000D0D0D000E0E0E000F0F0F00101010001111
        1100121212001313130014141400151515001616160017171700181818001919
        19001A1A1A001B1B1B001C1C1C001D1D1D001E1E1E001F1F1F00202020002121
        2100222222002323230024242400252525002626260027272700282828002929
        29002A2A2A002B2B2B002C2C2C002D2D2D002E2E2E002F2F2F00303030003131
        3100323232003333330034343400353535003636360037373700383838003939
        39003A3A3A003B3B3B003C3C3C003D3D3D003E3E3E003F3F3F00404040004141
        4100424242004343430044444400454545004646460047474700484848004949
        49004A4A4A004B4B4B004C4C4C004D4D4D004E4E4E004F4F4F00505050005151
        5100525252005353530054545400555555005656560057575700585858005959
        59005A5A5A005B5B5B005C5C5C005D5D5D005E5E5E005F5F5F00606060006161
        6100626262006363630064646400656565006666660067676700686868006969
        69006A6A6A006B6B6B006C6C6C006D6D6D006E6E6E006F6F6F00707070007171
        7100727272007373730074747400757575007676760077777700787878007979
        79007A7A7A007B7B7B007C7C7C007D7D7D007E7E7E007F7F7F00808080008181
        8100828282008383830084848400858585008686860087878700888888008989
        89008A8A8A008B8B8B008C8C8C008D8D8D008E8E8E008F8F8F00909090009191
        9100929292009393930094949400959595009696960097979700989898009999
        99009A9A9A009B9B9B009C9C9C009D9D9D009E9E9E009F9F9F00A0A0A000A1A1
        A100A2A2A200A3A3A300A4A4A400A5A5A500A6A6A600A7A7A700A8A8A800A9A9
        A900AAAAAA00ABABAB00ACACAC00ADADAD00AEAEAE00AFAFAF00B0B0B000B1B1
        B100B2B2B200B3B3B300B4B4B400B5B5B500B6B6B600B7B7B700B8B8B800B9B9
        B900BABABA00BBBBBB00BCBCBC00BDBDBD00BEBEBE00BFBFBF00C0C0C000C1C1
        C100C2C2C200C3C3C300C4C4C400C5C5C500C6C6C600C7C7C700C8C8C800C9C9
        C900CACACA00CBCBCB00CCCCCC00CDCDCD00CECECE00CFCFCF00D0D0D000D1D1
        D100D2D2D200D3D3D300D4D4D400D5D5D500D6D6D600D7D7D700D8D8D800D9D9
        D900DADADA00DBDBDB00DCDCDC00DDDDDD00DEDEDE00DFDFDF00E0E0E000E1E1
        E100E2E2E200E3E3E300E4E4E400E5E5E500E6E6E600E7E7E700E8E8E800E9E9
        E900EAEAEA00EBEBEB00ECECEC00EDEDED00EEEEEE00EFEFEF00F0F0F000F1F1
        F100F2F2F200F3F3F300F4F4F400F5F5F500F6F6F600F7F7F700F8F8F800F9F9
        F900FAFAFA00FBFBFB00FCFCFC00FDFDFD00FEFEFE00FFFFFF00C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C00000C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C000000000C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0000000000000C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0000000C0C0000000C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0000000C0C0C0C0
        000000C0C0C0C0C0C0C0C0C0C0C0C0C0000000C0C0C0C0C0C0000000C0C0C0C0
        C0C0C0C0C0C0C0C0C000C0C0C0C0C0C0C0C000C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0}
      OnClick = SpeedButton1Click
    end
    object Shape2: TShape
      Left = 7
      Top = 208
      Width = 344
      Height = 132
      Brush.Color = clSilver
    end
    object Label5: TLabel
      Left = 44
      Top = 226
      Width = 98
      Height = 15
      Caption = 'Current Password'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Calibri'
      Font.Style = []
      ParentFont = False
    end
    object Label6: TLabel
      Left = 62
      Top = 254
      Width = 80
      Height = 15
      Caption = 'New Password'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Calibri'
      Font.Style = []
      ParentFont = False
    end
    object cbLevel: TComboBox
      Left = 146
      Top = 77
      Width = 197
      Height = 22
      Style = csDropDownList
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Calibri'
      Font.Style = []
      ImeName = 'Microsoft IME 2010'
      ItemIndex = 0
      ParentFont = False
      TabOrder = 0
      Text = 'Operator'
      OnChange = cbLevelChange
      Items.Strings = (
        'Operator'
        'Maintenance'
        'Engineer'
        'Super')
    end
    object mePassword: TMaskEdit
      Left = 146
      Top = 108
      Width = 197
      Height = 22
      Color = 16317692
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Calibri'
      Font.Style = []
      ImeName = 'Microsoft IME 2003'
      ParentFont = False
      PasswordChar = '*'
      TabOrder = 1
      Text = ''
      OnKeyPress = mePasswordKeyPress
    end
    object Button1: TButton
      Left = 233
      Top = 140
      Width = 110
      Height = 36
      Caption = ' &Log In'
      ElevationRequired = True
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Calibri'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnClick = Button1Click
    end
    object btnChangePassword: TBitBtn
      Left = 117
      Top = 140
      Width = 110
      Height = 36
      Caption = 'Change Password'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Calibri'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      OnClick = btnChangePasswordClick
    end
    object meCurrentPassword: TMaskEdit
      Left = 146
      Top = 224
      Width = 197
      Height = 22
      Color = 16317692
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Calibri'
      Font.Style = []
      ImeName = 'Microsoft IME 2003'
      ParentFont = False
      PasswordChar = '*'
      TabOrder = 4
      Text = ''
      OnKeyPress = mePasswordKeyPress
    end
    object meNewPassword: TMaskEdit
      Left = 146
      Top = 252
      Width = 197
      Height = 22
      Color = 16317692
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Calibri'
      Font.Style = []
      ImeName = 'Microsoft IME 2003'
      ParentFont = False
      PasswordChar = '*'
      TabOrder = 5
      Text = ''
      OnKeyPress = mePasswordKeyPress
    end
    object btnOk: TBitBtn
      Left = 117
      Top = 289
      Width = 110
      Height = 36
      Caption = 'Ok'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Calibri'
      Font.Style = []
      ParentFont = False
      TabOrder = 6
      OnClick = btnOkClick
    end
    object btnCancel: TBitBtn
      Left = 233
      Top = 289
      Width = 110
      Height = 36
      Caption = 'Cencel'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Calibri'
      Font.Style = []
      ParentFont = False
      TabOrder = 7
      OnClick = btnCancelClick
    end
  end
end
