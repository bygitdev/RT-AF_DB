//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FrmADCOptionScrn.h"
//---------------------------------------------------------------------------
#include "BaseComm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma resource "*.dfm"
TFrmADCOption *FrmADCOption;


#define   _MAX_OPTION_COUNT_          18
//---------------------------------------------------------------------------
__fastcall TFrmADCOption::TFrmADCOption(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFrmADCOption::FormShow(TObject *Sender)
{
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\ADCOption.ini"))
	{
        TIniFile *ADCIni = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\ADCOption.ini");

        for( int i = 0; i < _MAX_OPTION_COUNT_; i++ )
        {
			nADCSeqNumber[i] =  ADCIni->ReadInteger("ADCINDEX","ENUM"+IntToStr(i), i);
            nADCName[i] =  ADCIni->ReadString("ADCNAME","NAME"+IntToStr(i), "ADC Option");
		}
        this->ReadADCOption();
    }
    else
    {

    }
}
//---------------------------------------------------------------------------
void TFrmADCOption::ReadADCOption()
{
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\ADCOption.ini"))
	{
        TIniFile *ADCIni = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\ADCOption.ini");

        for( int i = 0; i < _MAX_OPTION_COUNT_; i++ )
        {
			TPanel* CloneADCPanel = (TPanel*)FindComponent("PanelADC" + IntToStr(i+1));

            bool bReadval = bool(nReadCommunicationDM( nADCSeqNumber[i]));

        	CloneADCPanel->Color =  bReadval ? clLime : clGray;
            CloneADCPanel->Caption =   "";
            CloneADCPanel->Caption =   bReadval ? nADCName[i] + " ON" : nADCName[i] + " OFF";
		}
    }
}
//---------------------------------------------------------------------------
bool TFrmADCOption::WriteADCOption(int nIdx)
{
	if(FileExists(ExtractFilePath(Application->ExeName)+ "\\Ini\\ADCOption.ini"))
	{
        TIniFile *ADCIni = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\ADCOption.ini");

        bool bReadval = bool(nReadCommunicationDM( nADCSeqNumber[nIdx-1] ));

        bReadval =  bReadval ? 0 : 1;

        nWriteCommunicationDM( bReadval , nADCSeqNumber[nIdx-1] );
    }
}
//---------------------------------------------------------------------------

void __fastcall TFrmADCOption::PanelADC1DblClick(TObject *Sender)
{
	int nSelect = dynamic_cast<TPanel *>(Sender)->Tag;
	WriteADCOption(nSelect);
    ReadADCOption();
}
//---------------------------------------------------------------------------
void __fastcall TFrmADCOption::BitBtn1Click(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------
