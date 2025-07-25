object frmRfid: TfrmRfid
  Left = 429
  Top = 182
  Width = 827
  Height = 601
  Caption = 'frmRfid'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 811
    Height = 563
    Align = alClient
    TabOrder = 0
    object Label1: TLabel
      Left = 105
      Top = 226
      Width = 67
      Height = 27
      AutoSize = False
      Caption = 'STEP :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 95
      Top = 341
      Width = 77
      Height = 27
      AutoSize = False
      Caption = 'LOT ID :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label3: TLabel
      Left = 67
      Top = 444
      Width = 104
      Height = 27
      AutoSize = False
      Caption = 'PART NO :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object lblMessage: TLabel
      Left = 161
      Top = 185
      Width = 530
      Height = 33
      Alignment = taCenter
      AutoSize = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label4: TLabel
      Left = 92
      Top = 282
      Width = 80
      Height = 27
      AutoSize = False
      Caption = 'MGZ ID :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label5: TLabel
      Left = 8
      Top = 392
      Width = 165
      Height = 27
      AutoSize = False
      Caption = 'FRAME COUNT :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ledReadOk: TAssLED
      Left = 105
      Top = 124
      Width = 249
      Height = 56
      Caption = 'READ OK'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      LED.Width = 230
      LED.Height = 55
      LED.OffColor = clWhite
      LED.Style = alsFlat
      LEDLayout = allCenter
      ParentFont = False
    end
    object ledWrithOk: TAssLED
      Left = 449
      Top = 124
      Width = 249
      Height = 56
      Caption = 'WRITE OK'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      LED.Width = 230
      LED.Height = 55
      LED.OffColor = clWhite
      LED.Style = alsFlat
      LEDLayout = allCenter
      ParentFont = False
    end
    object btnRfidRead: TAssBitBtn
      Left = 190
      Top = 494
      Width = 181
      Height = 53
      Hint = 'Rfid Read'
      Caption = 'RFID READ'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      OnClick = btnRfidReadClick
      Color = 13162455
      ColorFocused = 14739951
      Flat = False
      Skinner = BtnSkinnerXP
      ImageIndex = 19
    end
    object btnRfidWrite: TAssBitBtn
      Left = 378
      Top = 494
      Width = 181
      Height = 53
      Hint = 'Rfid Write'
      Caption = 'RFID WRITE'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      OnClick = btnRfidWriteClick
      Color = 13162455
      ColorFocused = 14739951
      Flat = False
      Skinner = BtnSkinnerXP
      ImageIndex = 18
    end
    object EditRfidStep: TAssInstEdit
      Left = 262
      Top = 220
      Width = 80
      Height = 40
      AutoSelect = False
      AutoSize = False
      CharCase = ecUpperCase
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Frame.FlatColor = clBlack
      Frame.Edges = [aeLeft, aeTop, aeRight, aeBottom]
      Frame.Style = afsSunkenHeavy
      ImeName = #54620#44397#50612' '#51077#47141' '#49884#49828#53596' (IME 2000)'
      ParentCtl3D = False
      ParentFont = False
      TabOrder = 2
    end
    object EditRfidLotId: TAssInstEdit
      Left = 262
      Top = 332
      Width = 177
      Height = 40
      AutoSelect = False
      AutoSize = False
      CharCase = ecUpperCase
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Frame.FlatColor = clBlack
      Frame.Edges = [aeLeft, aeTop, aeRight, aeBottom]
      Frame.Style = afsSunkenHeavy
      ImeName = #54620#44397#50612' '#51077#47141' '#49884#49828#53596' (IME 2000)'
      ParentCtl3D = False
      ParentFont = False
      TabOrder = 3
    end
    object EditRfidPartNo: TAssInstEdit
      Left = 261
      Top = 435
      Width = 494
      Height = 40
      AutoSelect = False
      AutoSize = False
      CharCase = ecUpperCase
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Frame.FlatColor = clBlack
      Frame.Edges = [aeLeft, aeTop, aeRight, aeBottom]
      Frame.Style = afsSunkenHeavy
      ImeName = #54620#44397#50612' '#51077#47141' '#49884#49828#53596' (IME 2000)'
      ParentCtl3D = False
      ParentFont = False
      TabOrder = 4
    end
    object btnStepNo: TAssLEDBtn
      Left = 183
      Top = 219
      Width = 76
      Height = 41
      Caption = 'OK'
      TabOrder = 5
      Flat = False
      Skinner = BtnSkinnerXP
      Channel = 'RFID_STEP_READ'
      LED.Width = 25
      LED.Height = 25
      Margin = 0
      Spacing = 0
    end
    object btnLotNo: TAssLEDBtn
      Left = 183
      Top = 331
      Width = 76
      Height = 41
      Caption = 'OK'
      TabOrder = 6
      Flat = False
      Skinner = BtnSkinnerXP
      Channel = 'RFID_LOT_NO_READ'
      LED.Width = 25
      LED.Height = 25
      Margin = 0
      Spacing = 0
    end
    object btnPratNo: TAssLEDBtn
      Left = 182
      Top = 434
      Width = 76
      Height = 41
      Caption = 'OK'
      TabOrder = 7
      Flat = False
      Skinner = BtnSkinnerXP
      Channel = 'RFID_PART_NO_READ'
      LED.Width = 25
      LED.Height = 25
      Margin = 0
      Spacing = 0
    end
    object btnMgzId: TAssLEDBtn
      Left = 183
      Top = 275
      Width = 76
      Height = 41
      Caption = 'OK'
      TabOrder = 8
      Flat = False
      Skinner = BtnSkinnerXP
      Channel = 'RFID_MGZID_READ'
      LED.Width = 25
      LED.Height = 25
      Margin = 0
      Spacing = 0
    end
    object EditRfidMgzId: TAssInstEdit
      Left = 262
      Top = 276
      Width = 175
      Height = 40
      AutoSelect = False
      AutoSize = False
      CharCase = ecUpperCase
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Frame.FlatColor = clBlack
      Frame.Edges = [aeLeft, aeTop, aeRight, aeBottom]
      Frame.Style = afsSunkenHeavy
      ImeName = #54620#44397#50612' '#51077#47141' '#49884#49828#53596' (IME 2000)'
      ParentCtl3D = False
      ParentFont = False
      TabOrder = 9
    end
    object btnFrameCount: TAssLEDBtn
      Left = 182
      Top = 382
      Width = 76
      Height = 41
      Caption = 'OK'
      TabOrder = 10
      Flat = False
      Skinner = BtnSkinnerXP
      Channel = 'RFID_FRAMECNT_READ'
      LED.Width = 25
      LED.Height = 25
      Margin = 0
      Spacing = 0
    end
    object EditRfidFrameCnt: TAssInstEdit
      Left = 262
      Top = 383
      Width = 81
      Height = 41
      AutoSelect = False
      AutoSize = False
      CharCase = ecUpperCase
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Frame.FlatColor = clBlack
      Frame.Edges = [aeLeft, aeTop, aeRight, aeBottom]
      Frame.Style = afsSunkenHeavy
      ImeName = #54620#44397#50612' '#51077#47141' '#49884#49828#53596' (IME 2000)'
      ParentCtl3D = False
      ParentFont = False
      TabOrder = 11
    end
    object RadioSelectRfidType: TRadioGroup
      Left = 39
      Top = 68
      Width = 735
      Height = 51
      Caption = 'RFID Read Select'
      Columns = 2
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ItemIndex = 0
      Items.Strings = (
        'Channel_1'
        'Channel_2')
      ParentFont = False
      TabOrder = 12
    end
    object btnConnect: TAssBitBtn
      Left = 406
      Top = 5
      Width = 181
      Height = 53
      Hint = 'Rfid Read'
      Caption = 'CONNECT'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 13
      OnClick = btnConnectClick
      Color = 13162455
      ColorFocused = 14739951
      Flat = False
      Skinner = BtnSkinnerXP
      ImageIndex = 19
    end
    object btnDisConnect: TAssBitBtn
      Left = 614
      Top = 5
      Width = 181
      Height = 53
      Hint = 'Rfid Read'
      Caption = 'DISCONNECT'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 14
      OnClick = btnDisConnectClick
      Color = 13162455
      ColorFocused = 14739951
      Flat = False
      Skinner = BtnSkinnerXP
      ImageIndex = 19
    end
  end
  object BtnSkinnerXP: TAssBtnSkinner
    BitmapDisabled.Data = {
      D6060000424DD606000000000000360400002800000020000000150000000100
      080000000000A0020000D30E0000D30E00000001000000000000743C00007E4D
      16000097E5002FB2F80030B2F80030B3F80035B4F80035B4F90035B5F8003AB7
      F9003BB7F8003BB7F9003BB8F9006F8483007186840047B5ED0049B5EF0041BA
      F90041BAFA0042BAF90048BDF90049BDF90049BDFA0049BEFA0050C0FA0050C1
      FA0051C0FA0058C3FA0058C4FA0059C4FA0061C7FA0061C7FB0060C8FB006ACA
      FB0069CAFC0072CFFB0071CEFC0072CEFC0079D2FC007AD1FC007AD2FC00854D
      2700835725008E6D4600906E48009270490093714A0098754D009B774F00A27D
      5500C17D4D00FF00FF00A0876600A0886700A28B6A00A48C6C00A8957A00A995
      7B00AA997D00EE826900A19E8D00ACA89D00B1ABA000B4AEA300BDB5A900B6B7
      B100B7B7B100BDBDB60081D5FD0082D5FD0089D8FD008FDBFD0095DDFE009ADF
      FE009BE0FD00BAC7C900BCC9CB00BFCBD000ADDCEE00E4AD8900E4AD8B00E5AF
      8B00E5AF8D00E5AE8E00E6AF8E00E6B19100E7B19100E8B39400E8B49400E8B4
      9500E9B89800EAB89800EAB89900EBBB9C00EBBC9D00ECBEA000EDBEA100C7C5
      BC00CBC1B200CAC7BF00DCCEBF00EDC1A500EDC2A400EEC3A500EFC5A900F0C6
      A800F0C7AD00F0C8AD00F2CBB100F2CCB100F3CEB500F3CEB400F4D0B700F5D1
      B800F5D3BA00F6D3BA00F6D4BC00C1CCD100C0CCD100C3CFD500C4D0D500C5D0
      D600C4D2D500C6D0D600C7D5D800CAD3D700C9D4D600CAD4D700CAD5D700CBD4
      D700CBD4D800CAD6D800CDD6D900CCD6D800CDD7DB00CED7DB00CFD7DA00CFD8
      DA00CFD8DC00D2CEC400DDCFC000DAD3CA00D0DADB00D0D9DC00D1DBDC00D1DA
      DD00D2DADC00D2DBDD00D3DBDD00D2DCDF00D3DCDE00D5DDDF00D4DDDE00D6DE
      DF00D6DFDF00D4DEE000D5DEE100D7DEE000D7DFE000D6DFE200CFF0FF00D7E0
      E000D2E8EF00D8E0E000D8E0E100D8E1E100D9E0E100D9E1E200D8E0E200D9E2
      E200DAE0E100DAE1E200DBE1E200DAE2E200DAE2E300DBE2E300DBE3E300DAE2
      E400DBE2E500DBE3E400DCE3E300DCE3E400DDE3E400DCE3E500DDE3E600DDE4
      E400DDE4E500DDE5E500DDE4E700DEE4E500DEE5E500DFE5E600DFE6E600DFE5
      E800DEE9EA00D3EDF800E8DFD500FFE7CE00E0E5E600E0E6E600E1E6E600E0E6
      E900E0E7EA00E1E8E900E1E8EA00E3E9EA00E2E8EB00E2EDEE00E4EAEA00E4EA
      EB00E5EBEB00E4EBEC00E5EBEC00E6EBEC00E6EAED00E5ECED00E7ECED00E7ED
      EE00E8EEEF00E9EFEF00E9EFF000EAEEF000EAF0F000EBF0F000EBF0F100EAF4
      F500ECF0F000ECF1F100EDF1F100EDF2F200EEF1F200EEF1F300EEF2F200EEF3
      F300EFF2F200EFF3F300EFF4F400F0F4F400F1F5F500F2F5F500F2F4F600F2F6
      F600F3F6F600F4F6F600F5F7F700F6F8F800F7F8F800F8FAFA00F9FAFA00FAFB
      FB00FBFCFC00FCFCFC00FCFDFD00FDFEFE00FEFEFE00FFFFFF00337C4C4B4B4B
      4B4B4B4B4B4B4B4B4B4B4B4B4B4B4B4B4B4B4B4B4B4B4B4B7A337A86C2E1E1E1
      E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1D3867A4BD3E1E1E1E1
      E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1D34B4BE1E1E1E1E1
      E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E14B4BE1E1E1E1E1
      E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E14B4BE1E1E1E1E1
      E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E14B4BE1E1E1E1E1
      E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E14B4BE1E1E1E1E1
      E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E14B4BE1E1E1E1E1
      E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E14B4BE1E1E1E1E1
      E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E14B4BE1E1E1E1E1
      E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E14B4BE1E1E1E1E1
      E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E14B4BE1E1E1E1E1
      E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E14B4BE1E1E1E1E1
      E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E14B4BE1E1E1E1E1
      E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E14B4BE1E1E1E1E1
      E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E14B4BE1E1E1E1E1
      E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E14B4BE1E1E1E1E1
      E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E14B4CC2E1E1E1E1
      E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1C24C7C86C2E1E1E1
      E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1E1D3867C337C4C4B4B4B
      4B4B4B4B4B4B4B4B4B4B4B4B4B4B4B4B4B4B4B4B4B4B4B4B7A33}
    BitmapDown.Data = {
      D6060000424DD606000000000000360400002800000020000000150000000100
      080000000000A0020000D30E0000D30E00000001000000010000743C00007E4D
      16000097E5002FB2F80030B2F80030B3F80035B4F80035B4F90035B5F8003AB7
      F9003BB7F8003BB7F9003BB8F9006F8483007186840047B5ED0049B5EF0041BA
      F90041BAFA0042BAF90048BDF90049BDF90049BDFA0049BEFA0050C0FA0050C1
      FA0051C0FA0058C3FA0058C4FA0059C4FA0061C7FA0061C7FB0060C8FB006ACA
      FB0069CAFC0072CFFB0071CEFC0072CEFC0079D2FC007AD1FC007AD2FC00854D
      2700835725008E6D4600906E48009270490093714A0098754D009B774F00A27D
      5500C17D4D00FF00FF00A0876600A0886700A28B6A00A48C6C00A8957A00A995
      7B00AA997D00EE826900A19E8D00ACA89D00B1ABA000B4AEA300BDB5A900B6B7
      B100B7B7B100BDBDB60081D5FD0082D5FD0089D8FD008FDBFD0095DDFE009ADF
      FE009BE0FD00BAC7C900BCC9CB00BFCBD000ADDCEE00E4AD8900E4AD8B00E5AF
      8B00E5AF8D00E5AE8E00E6AF8E00E6B19100E7B19100E8B39400E8B49400E8B4
      9500E9B89800EAB89800EAB89900EBBB9C00EBBC9D00ECBEA000EDBEA100C7C5
      BC00CBC1B200CAC7BF00DCCEBF00EDC1A500EDC2A400EEC3A500EFC5A900F0C6
      A800F0C7AD00F0C8AD00F2CBB100F2CCB100F3CEB500F3CEB400F4D0B700F5D1
      B800F5D3BA00F6D3BA00F6D4BC00C1CCD100C0CCD100C3CFD500C4D0D500C5D0
      D600C4D2D500C6D0D600C7D5D800CAD3D700C9D4D600CAD4D700CAD5D700CBD4
      D700CBD4D800CAD6D800CDD6D900CCD6D800CDD7DB00CED7DB00CFD7DA00CFD8
      DA00CFD8DC00D2CEC400DDCFC000DAD3CA00D0DADB00D0D9DC00D1DBDC00D1DA
      DD00D2DADC00D2DBDD00D3DBDD00D2DCDF00D3DCDE00D5DDDF00D4DDDE00D6DE
      DF00D6DFDF00D4DEE000D5DEE100D7DEE000D7DFE000D6DFE200CFF0FF00D7E0
      E000D2E8EF00D8E0E000D8E0E100D8E1E100D9E0E100D9E1E200D8E0E200D9E2
      E200DAE0E100DAE1E200DBE1E200DAE2E200DAE2E300DBE2E300DBE3E300DAE2
      E400DBE2E500DBE3E400DCE3E300DCE3E400DDE3E400DCE3E500DDE3E600DDE4
      E400DDE4E500DDE5E500DDE4E700DEE4E500DEE5E500DFE5E600DFE6E600DFE5
      E800DEE9EA00D3EDF800E8DFD500FFE7CE00E0E5E600E0E6E600E1E6E600E0E6
      E900E0E7EA00E1E8E900E1E8EA00E3E9EA00E2E8EB00E2EDEE00E4EAEA00E4EA
      EB00E5EBEB00E4EBEC00E5EBEC00E6EBEC00E6EAED00E5ECED00E7ECED00E7ED
      EE00E8EEEF00E9EFEF00E9EFF000EAEEF000EAF0F000EBF0F000EBF0F100EAF4
      F500ECF0F000ECF1F100EDF1F100EDF2F200EEF1F200EEF1F300EEF2F200EEF3
      F300EFF2F200EFF3F300EFF4F400F0F4F400F1F5F500F2F5F500F2F4F600F2F6
      F600F3F6F600F4F6F600F5F7F700F6F8F800F7F8F800F8FAFA00F9FAFA00FAFB
      FB00FBFCFC00FCFCFC00FCFDFD00FDFEFE00FEFEFE00FFFFFF00333A2A000000
      0000000000000000000000000000000000000000000000013733342F62E2E6E6
      E6E6E6E6E6E6E6E6E6E6E6E6E6E6E6E6E6E6E6E6E6E8EA8D30360161C0CDD0D0
      CDCDCDCDCDCDCDCDCDCDCDCDCDCDCDCDCDCDCDCDD0D1D5D88B01008999ABAEAD
      ADADADADADADADADADADADADADADADADADADADADADAFB5BFBF000080909AA1A1
      A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A5ADB000007E8E9AA1A1
      A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A1A3A9AD00007D909EA4A4
      A4A4A4A4A4A4A4A4A4A4A4A4A4A4A4A4A4A4A4A4A4A4A6ABAE00007D929EA6A6
      A6A6A6A6A6A6A6A6A6A6A6A6A6A6A6A6A6A6A6A6A6A6AAACAF00007F93A4A7A7
      A7A7A7A7A7A7A7A7A7A7A7A7A7A7A7A7A7A7A7A7A7A7ABAFB300007F93A4A7A7
      A7A7A7A7A7A7A7A7A7A7A7A7A7A7A7A7A7A7A7A7A7A7ABAFB300008194A6ABAB
      ABABABABABABABABABABABABABABABABABABABABABABACAFB500008296A7AEAE
      AEAEAEAEAEAEAEAEAEAEAEAEAEAEAEAEAEAEAEAEAEAEAFB5B700008598ADB0B0
      B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B0B4B9BB00008497AFB5B5
      B5B5B5B5B5B5B5B5B5B5B5B5B5B5B5B5B5B5B5B5B5B5B6BDBE00008497AFB5B5
      B5B5B5B5B5B5B5B5B5B5B5B5B5B5B5B5B5B5B5B5B5B5B6BDBE0000889DB5BDBD
      BDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBFC60000899DB9C0C7
      C7C7C7C7C7C7C7C7C7C7C7C7C7C7C7C7C7C7C7C7C7C7C7C7C800008291A8B5BA
      BABABABABABABABABABABABABABABABABABABABABAB7B5B5BA002A3E7B82878A
      8A8A8A8A8A8A8A8A8A8A8A8A8A8A8A8A8A8A8A8A8A8A878F402A382B3D4D7675
      7575757575757575757575757575757575757575757575422D3933382A000000
      0000000000000000000000000000000000000000000000013533}
    BitmapEnter.Data = {
      D6060000424DD606000000000000360400002800000020000000150000000100
      080000000000A0020000D30E0000D30E00000001000000000000743C00007E4D
      16000097E5002FB2F80030B2F80030B3F80035B4F80035B4F90035B5F8003AB7
      F9003BB7F8003BB7F9003BB8F9006F8483007186840047B5ED0049B5EF0041BA
      F90041BAFA0042BAF90048BDF90049BDF90049BDFA0049BEFA0050C0FA0050C1
      FA0051C0FA0058C3FA0058C4FA0059C4FA0061C7FA0061C7FB0060C8FB006ACA
      FB0069CAFC0072CFFB0071CEFC0072CEFC0079D2FC007AD1FC007AD2FC00854D
      2700835725008E6D4600906E48009270490093714A0098754D009B774F00A27D
      5500C17D4D00FF00FF00A0876600A0886700A28B6A00A48C6C00A8957A00A995
      7B00AA997D00EE826900A19E8D00ACA89D00B1ABA000B4AEA300BDB5A900B6B7
      B100B7B7B100BDBDB60081D5FD0082D5FD0089D8FD008FDBFD0095DDFE009ADF
      FE009BE0FD00BAC7C900BCC9CB00BFCBD000ADDCEE00E4AD8900E4AD8B00E5AF
      8B00E5AF8D00E5AE8E00E6AF8E00E6B19100E7B19100E8B39400E8B49400E8B4
      9500E9B89800EAB89800EAB89900EBBB9C00EBBC9D00ECBEA000EDBEA100C7C5
      BC00CBC1B200CAC7BF00DCCEBF00EDC1A500EDC2A400EEC3A500EFC5A900F0C6
      A800F0C7AD00F0C8AD00F2CBB100F2CCB100F3CEB500F3CEB400F4D0B700F5D1
      B800F5D3BA00F6D3BA00F6D4BC00C1CCD100C0CCD100C3CFD500C4D0D500C5D0
      D600C4D2D500C6D0D600C7D5D800CAD3D700C9D4D600CAD4D700CAD5D700CBD4
      D700CBD4D800CAD6D800CDD6D900CCD6D800CDD7DB00CED7DB00CFD7DA00CFD8
      DA00CFD8DC00D2CEC400DDCFC000DAD3CA00D0DADB00D0D9DC00D1DBDC00D1DA
      DD00D2DADC00D2DBDD00D3DBDD00D2DCDF00D3DCDE00D5DDDF00D4DDDE00D6DE
      DF00D6DFDF00D4DEE000D5DEE100D7DEE000D7DFE000D6DFE200CFF0FF00D7E0
      E000D2E8EF00D8E0E000D8E0E100D8E1E100D9E0E100D9E1E200D8E0E200D9E2
      E200DAE0E100DAE1E200DBE1E200DAE2E200DAE2E300DBE2E300DBE3E300DAE2
      E400DBE2E500DBE3E400DCE3E300DCE3E400DDE3E400DCE3E500DDE3E600DDE4
      E400DDE4E500DDE5E500DDE4E700DEE4E500DEE5E500DFE5E600DFE6E600DFE5
      E800DEE9EA00D3EDF800E8DFD500FFE7CE00E0E5E600E0E6E600E1E6E600E0E6
      E900E0E7EA00E1E8E900E1E8EA00E3E9EA00E2E8EB00E2EDEE00E4EAEA00E4EA
      EB00E5EBEB00E4EBEC00E5EBEC00E6EBEC00E6EAED00E5ECED00E7ECED00E7ED
      EE00E8EEEF00E9EFEF00E9EFF000EAEEF000EAF0F000EBF0F000EBF0F100EAF4
      F500ECF0F000ECF1F100EDF1F100EDF2F200EEF1F200EEF1F300EEF2F200EEF3
      F300EFF2F200EFF3F300EFF4F400F0F4F400F1F5F500F2F5F500F2F4F600F2F6
      F600F3F6F600F4F6F600F5F7F700F6F8F800F7F8F800F8FAFA00F9FAFA00FAFB
      FB00FBFCFC00FCFCFC00FCFDFD00FDFEFE00FEFEFE00FFFFFF00333A2A000000
      0000000000000000000000000000000000000000000000013733340E02020202
      0202020202020202020202020202020202020202020202020D37011007070305
      0504040505050505050505050505050505050505040407070F01000707D3D4D5
      D5D5D5D5D5D5D5D5D5D5D5D5D5D5D5D5D5D5D5D5D5D2D3070700000C0BDEDEDE
      DEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDA0A0900001213DFDFDF
      DFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDB111100001517E3E3E3
      E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3DF161400001819E4E4E4
      E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E21A1900001B1DE5E5E5
      E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E31C1D00001F20E9E9E9
      E9E9E9E9E9E9E9E9E9E9E9E9E9E9E9E9E9E9E9E9E9E9E51E1F00002221EBEBEB
      EBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBE8212200002424EDEDED
      EDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEB232500002828EEEEEE
      EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEED262700004526F1F1F1
      F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1EE264400004626F2F2F2
      F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2EF264600004726F5F5F5
      F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F4264700004826F8F8F8
      F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F7264800004928FBFAFA
      FAFAFAFAFAFAFAFAFAFAFAFAFAFAFAFAFAFAFAFAFAFAFB284A002A4E28474646
      4646464646464646464646464646464646464646464647284E2A393CA2A0A0A0
      A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0C33C3933392A000000
      0000000000000000000000000000000000000000000000013533}
    BitmapFocused.Data = {
      D6060000424DD606000000000000360400002800000020000000150000000100
      080000000000A0020000D30E0000D30E00000001000000000000743C00007E4D
      16000097E5002FB2F80030B2F80030B3F80035B4F80035B4F90035B5F8003AB7
      F9003BB7F8003BB7F9003BB8F9006F8483007186840047B5ED0049B5EF0041BA
      F90041BAFA0042BAF90048BDF90049BDF90049BDFA0049BEFA0050C0FA0050C1
      FA0051C0FA0058C3FA0058C4FA0059C4FA0061C7FA0061C7FB0060C8FB006ACA
      FB0069CAFC0072CFFB0071CEFC0072CEFC0079D2FC007AD1FC007AD2FC00854D
      2700835725008E6D4600906E48009270490093714A0098754D009B774F00A27D
      5500C17D4D00FF00FF00A0876600A0886700A28B6A00A48C6C00A8957A00A995
      7B00AA997D00EE826900A19E8D00ACA89D00B1ABA000B4AEA300BDB5A900B6B7
      B100B7B7B100BDBDB60081D5FD0082D5FD0089D8FD008FDBFD0095DDFE009ADF
      FE009BE0FD00BAC7C900BCC9CB00BFCBD000ADDCEE00E4AD8900E4AD8B00E5AF
      8B00E5AF8D00E5AE8E00E6AF8E00E6B19100E7B19100E8B39400E8B49400E8B4
      9500E9B89800EAB89800EAB89900EBBB9C00EBBC9D00ECBEA000EDBEA100C7C5
      BC00CBC1B200CAC7BF00DCCEBF00EDC1A500EDC2A400EEC3A500EFC5A900F0C6
      A800F0C7AD00F0C8AD00F2CBB100F2CCB100F3CEB500F3CEB400F4D0B700F5D1
      B800F5D3BA00F6D3BA00F6D4BC00C1CCD100C0CCD100C3CFD500C4D0D500C5D0
      D600C4D2D500C6D0D600C7D5D800CAD3D700C9D4D600CAD4D700CAD5D700CBD4
      D700CBD4D800CAD6D800CDD6D900CCD6D800CDD7DB00CED7DB00CFD7DA00CFD8
      DA00CFD8DC00D2CEC400DDCFC000DAD3CA00D0DADB00D0D9DC00D1DBDC00D1DA
      DD00D2DADC00D2DBDD00D3DBDD00D2DCDF00D3DCDE00D5DDDF00D4DDDE00D6DE
      DF00D6DFDF00D4DEE000D5DEE100D7DEE000D7DFE000D6DFE200CFF0FF00D7E0
      E000D2E8EF00D8E0E000D8E0E100D8E1E100D9E0E100D9E1E200D8E0E200D9E2
      E200DAE0E100DAE1E200DBE1E200DAE2E200DAE2E300DBE2E300DBE3E300DAE2
      E400DBE2E500DBE3E400DCE3E300DCE3E400DDE3E400DCE3E500DDE3E600DDE4
      E400DDE4E500DDE5E500DDE4E700DEE4E500DEE5E500DFE5E600DFE6E600DFE5
      E800DEE9EA00D3EDF800E8DFD500FFE7CE00E0E5E600E0E6E600E1E6E600E0E6
      E900E0E7EA00E1E8E900E1E8EA00E3E9EA00E2E8EB00E2EDEE00E4EAEA00E4EA
      EB00E5EBEB00E4EBEC00E5EBEC00E6EBEC00E6EAED00E5ECED00E7ECED00E7ED
      EE00E8EEEF00E9EFEF00E9EFF000EAEEF000EAF0F000EBF0F000EBF0F100EAF4
      F500ECF0F000ECF1F100EDF1F100EDF2F200EEF1F200EEF1F300EEF2F200EEF3
      F300EFF2F200EFF3F300EFF4F400F0F4F400F1F5F500F2F5F500F2F4F600F2F6
      F600F3F6F600F4F6F600F5F7F700F6F8F800F7F8F800F8FAFA00F9FAFA00FAFB
      FB00FBFCFC00FCFCFC00FCFDFD00FDFEFE00FEFEFE00FFFFFF00333A2A000000
      00000000000000000000000000000000000000000000000137333429323B3B3B
      3B3B3B3B3B3B3B3B3B3B3B3B3B3B3B3B3B3B3B3B3B3B3B3B2937015050504F4F
      4F4F4F4F4F4F4F4F4F4F4F4F4F4F4F4F4F4F4F4F4F4F50505001005050D3D4D5
      D5D5D5D5D5D5D5D5D5D5D5D5D5D5D5D5D5D5D5D5D5D2D3505000005050DEDEDE
      DEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDA505100005453DFDFDF
      DFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDB545200005655E3E3E3
      E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3DF565500005857E4E4E4
      E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E2595900005B5AE5E5E5
      E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E35C5A00005D5EE9E9E9
      E9E9E9E9E9E9E9E9E9E9E9E9E9E9E9E9E9E9E9E9E9E9E55D5D00005F5FEBEBEB
      EBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBE8605F00006566EDEDED
      EDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEB676700006869EEEEEE
      EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEED686800006B6AF1F1F1
      F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1EE6A6A00006C6CF2F2F2
      F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2EF6C6D00006F6EF5F5F5
      F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F46F6E00007071F8F8F8
      F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F7717100007474FBFAFA
      FAFAFAFAFAFAFAFAFAFAFAFAFAFAFAFAFAFAFAFAFAFAFB7474002A7474747474
      747474747474747474747474747474747474747474747474742A3929C5C5C5C5
      C5C5C5C5C5C5C5C5C5C5C5C5C5C5C5C5C5C5C5C5C5C5C5C5293933392A000000
      0000000000000000000000000000000000000000000000013533}
    BitmapNormal.Data = {
      D6060000424DD606000000000000360400002800000020000000150000000100
      080000000000A0020000D30E0000D30E00000001000000000000743C00007E4D
      16000097E5002FB2F80030B2F80030B3F80035B4F80035B4F90035B5F8003AB7
      F9003BB7F8003BB7F9003BB8F9006F8483007186840047B5ED0049B5EF0041BA
      F90041BAFA0042BAF90048BDF90049BDF90049BDFA0049BEFA0050C0FA0050C1
      FA0051C0FA0058C3FA0058C4FA0059C4FA0061C7FA0061C7FB0060C8FB006ACA
      FB0069CAFC0072CFFB0071CEFC0072CEFC0079D2FC007AD1FC007AD2FC00854D
      2700835725008E6D4600906E48009270490093714A0098754D009B774F00A27D
      5500C17D4D00FF00FF00A0876600A0886700A28B6A00A48C6C00A8957A00A995
      7B00AA997D00EE826900A19E8D00ACA89D00B1ABA000B4AEA300BDB5A900B6B7
      B100B7B7B100BDBDB60081D5FD0082D5FD0089D8FD008FDBFD0095DDFE009ADF
      FE009BE0FD00BAC7C900BCC9CB00BFCBD000ADDCEE00E4AD8900E4AD8B00E5AF
      8B00E5AF8D00E5AE8E00E6AF8E00E6B19100E7B19100E8B39400E8B49400E8B4
      9500E9B89800EAB89800EAB89900EBBB9C00EBBC9D00ECBEA000EDBEA100C7C5
      BC00CBC1B200CAC7BF00DCCEBF00EDC1A500EDC2A400EEC3A500EFC5A900F0C6
      A800F0C7AD00F0C8AD00F2CBB100F2CCB100F3CEB500F3CEB400F4D0B700F5D1
      B800F5D3BA00F6D3BA00F6D4BC00C1CCD100C0CCD100C3CFD500C4D0D500C5D0
      D600C4D2D500C6D0D600C7D5D800CAD3D700C9D4D600CAD4D700CAD5D700CBD4
      D700CBD4D800CAD6D800CDD6D900CCD6D800CDD7DB00CED7DB00CFD7DA00CFD8
      DA00CFD8DC00D2CEC400DDCFC000DAD3CA00D0DADB00D0D9DC00D1DBDC00D1DA
      DD00D2DADC00D2DBDD00D3DBDD00D2DCDF00D3DCDE00D5DDDF00D4DDDE00D6DE
      DF00D6DFDF00D4DEE000D5DEE100D7DEE000D7DFE000D6DFE200CFF0FF00D7E0
      E000D2E8EF00D8E0E000D8E0E100D8E1E100D9E0E100D9E1E200D8E0E200D9E2
      E200DAE0E100DAE1E200DBE1E200DAE2E200DAE2E300DBE2E300DBE3E300DAE2
      E400DBE2E500DBE3E400DCE3E300DCE3E400DDE3E400DCE3E500DDE3E600DDE4
      E400DDE4E500DDE5E500DDE4E700DEE4E500DEE5E500DFE5E600DFE6E600DFE5
      E800DEE9EA00D3EDF800E8DFD500FFE7CE00E0E5E600E0E6E600E1E6E600E0E6
      E900E0E7EA00E1E8E900E1E8EA00E3E9EA00E2E8EB00E2EDEE00E4EAEA00E4EA
      EB00E5EBEB00E4EBEC00E5EBEC00E6EBEC00E6EAED00E5ECED00E7ECED00E7ED
      EE00E8EEEF00E9EFEF00E9EFF000EAEEF000EAF0F000EBF0F000EBF0F100EAF4
      F500ECF0F000ECF1F100EDF1F100EDF2F200EEF1F200EEF1F300EEF2F200EEF3
      F300EFF2F200EFF3F300EFF4F400F0F4F400F1F5F500F2F5F500F2F4F600F2F6
      F600F3F6F600F4F6F600F5F7F700F6F8F800F7F8F800F8FAFA00F9FAFA00FAFB
      FB00FBFCFC00FCFCFC00FCFDFD00FDFEFE00FEFEFE00FFFFFF00333A2A000000
      0000000000000000000000000000000000000000000000013733342E3F7A7979
      7979797979797979797979797979797979797979797877412E3701639C9C9C9F
      9F9F9F9F9F9F9F9F9F9F9F9F9F9F9F9F9F9F9F9F9F9C9486430100D3D3D3D4D5
      D5D5D5D5D5D5D5D5D5D5D5D5D5D5D5D5D5D5D5D5D5D2D3B59C0000DFDEDEDEDE
      DEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDACCB10000E3E3DFDFDF
      DFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDFDBD1B20000E5E5E3E3E3
      E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3E3DFD3B70000E8E8E4E4E4
      E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E4E2D4B80000E9E9E5E5E5
      E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E5E3D7BC0000ECECE9E9E9
      E9E9E9E9E9E9E9E9E9E9E9E9E9E9E9E9E9E9E9E9E9E9E5D9C10000EDEDEBEBEB
      EBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBEBE8D9C10000EEEEEDEDED
      EDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEDEBDAC90000F1EFEEEEEE
      EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEDDCCA0000F2F2F1F1F1
      F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1EEDECC0000F3F3F2F2F2
      F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2EFE0CE0000F6F5F5F5F5
      F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F4E7D60000F8F8F8F8F8
      F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F8F7EFDD0000FBFBFBFAFA
      FAFAFAFAFAFAFAFAFAFAFAFAFAFAFAFAFAFAFAFAFAFAFBFBEF002A64FBFBFEFE
      FEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFEFBFB642A39318CFBFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBC4313933392A000000
      0000000000000000000000000000000000000000000000013533}
    FixedHeight = 4
    FixedWidth = 4
    TransparentColor = clFuchsia
    Left = 670
    Top = 280
  end
  object RfidRead: TAssComm
    Port = COM02
    EventChar = #3
    BinaryMode = True
    CheckParity = False
    DiscardNull = True
    CommEvents = [EVRXCHAR, EVRXFLAG, EVTXEMPTY]
    Timeout = 500
    Priority = tpNormal
    MonitorInterval = 500
    OnEventCharReceived = RfidReadEventCharReceived
    Left = 603
    Top = 275
  end
end
