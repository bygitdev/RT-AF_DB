//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "JobRunningScrn.h"
#include "UnitSetupScrn.h"
#include "BaseComm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma resource "*.dfm"

#define     _MAX_PARENT_TENKEYCOUNT_          14
#define     _MAX_CHILD_TENKEYCOUNT_           27

#define     _PARENT_TENKEY_LINE_             20
#define     _CHILD_TENKEY_LINE_              50

TFrmJobRunning *FrmJobRunning;
//---------------------------------------------------------------------------
__fastcall TFrmJobRunning::TFrmJobRunning(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TFrmJobRunning::FormCreate(TObject *Sender)
{
	TIniFile *TenkeyIni = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\TenkeyNameInfo.ini");
	for(int i = 1; i < _MAX_PARENT_TENKEYCOUNT_; i++)
	{
		String strSection;
		strSection.sprintf( L"ChildTenkeyName%d", i );

		for (int j=1; j< _MAX_CHILD_TENKEYCOUNT_; ++j)
		{
			String strKeyNumber;
			String strKeyName;
			strKeyNumber.sprintf( L"ChildTenkeyNumber%d", j );
			strKeyName.sprintf( L"ChildButtonName%d", j );

			INT nNumber = TenkeyIni->ReadInteger(strSection, strKeyNumber, 0);
			String strName = TenkeyIni->ReadString (strSection, strKeyName, "");

			if (strName != "")
			{
				if (nNumber > 0 && nNumber < 200)
				{
					_strTenkeyName[ nNumber ] =  strName;
				}
			}
		}

	}
	delete TenkeyIni;
}
//---------------------------------------------------------------------------

void __fastcall TFrmJobRunning::FormInitiaize()
{
	ParentTenkeyLoad();
	BtnTenkeyLoad(1);
	nTenkeyPartNo = 1;
}
//---------------------------------------------------------------------------

void __fastcall TFrmJobRunning::BtnTenkeyLoad(int SelectNo)
{
    int nLineChk = _CHILD_TENKEY_LINE_;
    TenkeyEffectProcess(SelectNo);
    TIniFile *TenkeyIni = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\TenkeyNameInfo.ini");
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\TenkeyNameInfo.ini"))
    {
        for(int i = 1; i <= _MAX_CHILD_TENKEYCOUNT_; i++)
        {
            TBitBtn *CloneTenkeyButton = (TBitBtn *)FindComponent("TenkeyBtn"+IntToStr(i));
            CloneTenkeyButton->Tag = i;
            String StrTemp = TenkeyIni->ReadString("ChildTenkeyName"+IntToStr(SelectNo),"ChildButtonName"+IntToStr(i),"Tenkey"+IntToStr(i));

            int nCmdTenekyNumber = TenkeyIni->ReadInteger("ChildTenkeyName"+IntToStr(SelectNo),"ChildTenkeyNumber"+IntToStr(i),0);
            if(StrTemp.Length() < nLineChk)
            {
                CloneTenkeyButton->Caption = IntToStr(nCmdTenekyNumber)+" : "+StrTemp;
            }
            else
            {
				CloneTenkeyButton->Caption = IntToStr(nCmdTenekyNumber)+" : "+ StrTemp.SubString(0,nLineChk) +"\n"+ StrTemp.SubString((nLineChk+1),StrTemp.Length());
            }
        }
    }
    delete TenkeyIni;
}
//---------------------------------------------------------------------------

void __fastcall TFrmJobRunning::TenkeyEffectProcess(int selectBtn)
{
    for(int i = 1; i <= _MAX_PARENT_TENKEYCOUNT_; i++)
    {
		TBitBtn *SubCloneBtn = (TBitBtn *)FindComponent("BtnTenkeyLoad"+IntToStr(i));
		SubCloneBtn->Enabled  = true;
    }

	TBitBtn *SubCloneBtn = (TBitBtn *)FindComponent("BtnTenkeyLoad"+IntToStr(selectBtn));
	SubCloneBtn->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TFrmJobRunning::ParentTenkeyLoad()
{
	int nLineChk = _PARENT_TENKEY_LINE_;

    TIniFile *TenkeyIni = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\TenkeyNameInfo.ini");
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\TenkeyNameInfo.ini"))
    {
		for(int i = 1; i <= _MAX_PARENT_TENKEYCOUNT_; i++)
        {
			TBitBtn *CloneParentTenkeyButton = (TBitBtn *)FindComponent("BtnTenkeyLoad"+IntToStr(i));
            String StrTemp = TenkeyIni->ReadString("ParentTenkeyName","Part"+IntToStr(i),"PART"+IntToStr(i));
            if(StrTemp.Length() < nLineChk)
            {
                CloneParentTenkeyButton->Caption = StrTemp;
            }
            else
            {
                CloneParentTenkeyButton->Caption = StrTemp.SubString(0,nLineChk) +"\n"+ StrTemp.SubString((nLineChk+1),StrTemp.Length());
            }
        }
    }
    delete TenkeyIni;
}
//---------------------------------------------------------------------------

void __fastcall TFrmJobRunning::BtnTenkeyLoad1Click(TObject *Sender)
{
	PanelSelectTenkeyNo->Caption = "";
	PanelSelectTenkeyName->Caption = "";
	int nTemp = dynamic_cast<TBitBtn *>(Sender)->Tag;
    nTenkeyPartNo = nTemp;
	BtnTenkeyLoad(nTemp);
}
//---------------------------------------------------------------------------

void __fastcall TFrmJobRunning::TenkeyBtn1Click(TObject *Sender)
{
	int nTemp = dynamic_cast<TBitBtn *>(Sender)->Tag;

    TIniFile *TenkeyIni = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\TenkeyNameInfo.ini");
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\TenkeyNameInfo.ini"))
    {
        int nCmdTenekyNumber = TenkeyIni->ReadInteger("ChildTenkeyName"+IntToStr(nTenkeyPartNo),"ChildTenkeyNumber"+IntToStr(nTemp),0);

		TBitBtn *CloneTenkeyButton = (TBitBtn *)FindComponent("TenkeyBtn"+IntToStr(nTemp));
        PanelSelectTenkeyNo->Caption = IntToStr(nCmdTenekyNumber);
        PanelSelectTenkeyName->Caption = CloneTenkeyButton->Caption;
    }
	delete TenkeyIni;
}
//---------------------------------------------------------------------------

void __fastcall TFrmJobRunning::BtnHomeClick(TObject *Sender)
{
//    if(FrmMain->bRunDataAccessChk == true)
//    {
        if(PanelSelectTenkeyNo->Caption != "")
        {
            FrmCdBox->setFlag(CD_YESNO);
			FrmCdBox->setTitle("Manual Operate");
			FrmCdBox->setText("Execute Running?");
			if (mrYes == FrmCdBox->ShowModal())
			{
				int nTemp = dynamic_cast<TBitBtn *>(Sender)->Tag;

                int nData = StrToInt( PanelSelectTenkeyNo->Caption.ToDouble()+nTemp );
                WriteCommNDM(screenTenkey, nData);

			}
        }
        else
        {
            FrmCdBox->setFlag(CD_OK);
			FrmCdBox->setTitle("Manual Operate");
			FrmCdBox->setText("Select tenkey-no.");
			FrmCdBox->ShowModal();
		}
//	}
//	else
//	{
//		FrmCdBox->setFlag(CD_OK);
//		FrmCdBox->setTitle("MACHINE RUNNING");
//		FrmCdBox->setText("Now machine is run!");
//		FrmCdBox->ShowModal();
//	}
}
//---------------------------------------------------------------------------

String	TFrmJobRunning::getTenKeyName(int nTenkeyNo)
{
	return _strTenkeyName[nTenkeyNo];
}
//---------------------------------------------------------------------------
void __fastcall TFrmJobRunning::FormDestroy(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

