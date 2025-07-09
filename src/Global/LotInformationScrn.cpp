//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "LotInformationScrn.h"
#include "langs.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvPicture"
#pragma link "CurvyControls"
#pragma link "Shader"
#pragma resource "*.dfm"
TFrmLotInformation *FrmLotInformation;

TIniFile *pLotsetIni;
//---------------------------------------------------------------------------
__fastcall TFrmLotInformation::TFrmLotInformation(TComponent* Owner)
	: TForm(Owner)
{
	g_langs.saveComponentNameListToTextFile( this );

	pLotsetIni = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\LotInfo.ini");
}
//---------------------------------------------------------------------------
void __fastcall TFrmLotInformation::FormClose(TObject *Sender, TCloseAction &Action)

{
	delete  pLotsetIni;
}
//---------------------------------------------------------------------------

void __fastcall TFrmLotInformation::BtnLotStartClick(TObject *Sender)
{
	if(CurvyEditLotnumber->Text == "")
    {
		MessageDlg("NOT input the LOT NUMBER!", mtError, TMsgDlgButtons() << mbOK, 0);
    }
    else
    {
        if(CurvyEditOPid->Text == "")
        {
			MessageDlg("NOT input the OPERATOR ID!", mtError, TMsgDlgButtons() << mbOK, 0);
        }
        else
        {
        	pLotsetIni->WriteString("LotInfo","LotCode",CurvyEditLotnumber->Text);
            pLotsetIni->WriteString("LotInfo","OPID",CurvyEditOPid->Text);
        }

    }
}
//---------------------------------------------------------------------------
String __fastcall TFrmLotInformation::LotInfoReturnQuery(int nType)
{
	if(nType == 1)
    {
 		return  pLotsetIni->ReadString("LotInfo","LotCode","LOTCODE");
    }
    else if(nType == 2)
    {
 		return  pLotsetIni->ReadString("LotInfo","OPID","OPID");
    }

}
//---------------------------------------------------------------------------


void __fastcall TFrmLotInformation::LMDCheckBoxCountStopChange(TObject *Sender)
{
	if(LMDCheckBoxCountStop->Checked == true)
    {
    	PanelCountStop->Enabled = true;
        PanelCountStop->Color = clSilver;

    }
    else
    {
		PanelCountStop->Enabled = false;
        PanelCountStop->Color = clWhite;

    }
}
//---------------------------------------------------------------------------



void __fastcall TFrmLotInformation::BtnCloseClick(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------






