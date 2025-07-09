//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fsystemteach.h"
#include "..\common\basecomm.h"
#include "..\mainformscrn.h"
#include "FrmFrontGoodTrayScrn.h"
#include "FrmRearGoodTrayScrn.h"
#include "FrmRejectTrayTeachingScrn.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmSystemTeach *frmSystemTeach;
//---------------------------------------------------------------------------
__fastcall TfrmSystemTeach::TfrmSystemTeach(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmSystemTeach::FormShow(TObject *Sender)
{
	Timer1->Enabled = true;
    this->loadDdm();

    // tray teach data read;
    TraySelectRead(0);  // rear good
    TraySelectRead(1);  // front good
	TraySelectRead(2);  // reject

}
//---------------------------------------------------------------------------
void __fastcall TfrmSystemTeach::BitBtn5Click(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;
    if(!CheckCanAccessLevel(PW_ENGINEER)) return;

    FrmCdBox->setFlag(CD_YESNO);
    FrmCdBox->setTitle("Data Write");
    FrmCdBox->setText("Do you want to write the system teach data ?");
    FrmCdBox->BringToFront();
    if (mrYes != FrmCdBox->ShowModal())
    	return;

    if ( this->saveDdm() == false ||
    	this->saveMotorSeq() == false ||
        this->saveMotorDB() == false
        )
	{
        FrmCdBox->setFlag(CD_OK);
        FrmCdBox->setTitle("WRITE FAILED");
        FrmCdBox->setText("can not write to data.");
        FrmCdBox->BringToFront();
        FrmCdBox->ShowModal();
    }
    else
    {
	    ShowMessage("Success to write data !");
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmSystemTeach::BtnTeachBtn5Click(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	FrmRearGoodTray->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfrmSystemTeach::BitBtn1Click(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	FrmFrontGoodTray->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfrmSystemTeach::BitBtn2Click(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	FrmRejectTrayTeaching->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfrmSystemTeach::BitBtn3Click(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	FrmCdBox->setFlag(CD_YESNO);
    FrmCdBox->setTitle("Overwrite calc save");
    FrmCdBox->setText("Do you want to save the calcuration data?");
    FrmCdBox->BringToFront();
    if (mrYes != FrmCdBox->ShowModal())
    	return;	//

	TraySelectSave(0);  //REAR GOOD TRAY
    TraySelectSave(1);  //FRONT GOOD TRAY
    TraySelectSave(2);  //REJECT TRAY
}
//---------------------------------------------------------------------------
#define  _DDM_COUNT_BUNCH_          10

#define  _DDM_START_NO_             200

void TfrmSystemTeach::TraySelectRead(int nSelect)
{

    int nStartNo  =  _DDM_START_NO_ + (nSelect *10);
	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_DDM;
	if(true == g_MMIComm->Send() && true == g_MMIComm->Recv())
	{
        for(int i=0; i<_DDM_COUNT_BUNCH_; i++)
        {
        	TEdit* CloneEdit = (TEdit*)FindComponent("TrayEdit" + IntToStr(nStartNo + i));
			CloneEdit->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[nStartNo + i] , ffFixed,10,3);
		}
	}

}
//---------------------------------------------------------------------------

void TfrmSystemTeach::TraySelectSave(int nSelect)
{
	int nStartNo  =  _DDM_START_NO_ + (nSelect *10);
	g_MMIComm->m_mmiToSeq.buffer.ddm.nStart =nStartNo;
    g_MMIComm->m_mmiToSeq.buffer.ddm.nEnd  =nStartNo + 9;

	for(int i=0; i<_DDM_COUNT_BUNCH_; i++)
	{
		TEdit* CloneEdit = (TEdit*)FindComponent("TrayEdit" + IntToStr(nStartNo+i));
		if(CloneEdit->Text == "")
		{
			CloneEdit->Text = "0";
		}

		g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[nStartNo + i] = StrToFloat(CloneEdit->Text.ToDouble());
		//WriteFloatPkgParamInifile(StrToFloat(CloneEdit->Text.Trim()), nStartNo + i);
	}

	g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_DDM;

    if(g_MMIComm->Send() && g_MMIComm->Recv())
	{
	/*
    	for(int i=0; i<_DDM_COUNT_BUNCH_; i++)
		{
			TEdit* CloneEdit = (TEdit*)FindComponent("TrayEdit" + IntToStr(i));
			if(CloneEdit->Text == "")
			{
				CloneEdit->Text = "0";
			}
			WriteFloatPkgParamInifile(StrToFloat(CloneEdit->Text.Trim()), nStartNo + i);
	*/
    }
    else
    {
        MessageDlg("Communication Failure", mtError, TMsgDlgButtons() << mbOK, 0);
    }
}

void TfrmSystemTeach::loadMotorSeq()
{
	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_MT_TABLE;
	g_MMIComm->m_mmiToSeq.buffer.motTable.nMtNo = 0;

	if ( g_MMIComm->Send() &&  g_MMIComm->Recv() )
	{
        edt70->Text =  FloatToStr(g_MMIComm->m_mmiToSeq.buffer.motTable.dPos[4]/1000);
        edt80->Text =  FloatToStr(g_MMIComm->m_mmiToSeq.buffer.motTable.dPos[5]/1000);
	}

	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_MT_TABLE;
	g_MMIComm->m_mmiToSeq.buffer.motTable.nMtNo = 1;

	if ( g_MMIComm->Send() &&  g_MMIComm->Recv() )
	{
        edt72->Text =  FloatToStr(g_MMIComm->m_mmiToSeq.buffer.motTable.dPos[4]/1000);
        edt82->Text =  FloatToStr(g_MMIComm->m_mmiToSeq.buffer.motTable.dPos[5]/1000);
	}

	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_MT_TABLE;
	g_MMIComm->m_mmiToSeq.buffer.motTable.nMtNo = 2;

	if ( g_MMIComm->Send() &&  g_MMIComm->Recv() )
	{
        edt74->Text =  FloatToStr(g_MMIComm->m_mmiToSeq.buffer.motTable.dPos[4]/1000);
        edt84->Text =  FloatToStr(g_MMIComm->m_mmiToSeq.buffer.motTable.dPos[5]/1000);
	}

	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_MT_TABLE;
	g_MMIComm->m_mmiToSeq.buffer.motTable.nMtNo = 3;

	if ( g_MMIComm->Send() &&  g_MMIComm->Recv() )
	{
        edt76->Text =  FloatToStr(g_MMIComm->m_mmiToSeq.buffer.motTable.dPos[4]/1000);
        edt86->Text =  FloatToStr(g_MMIComm->m_mmiToSeq.buffer.motTable.dPos[5]/1000);
	}

	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_MT_TABLE;
	g_MMIComm->m_mmiToSeq.buffer.motTable.nMtNo = 25;

	if ( g_MMIComm->Send() &&  g_MMIComm->Recv() )
	{
        edt71->Text =  FloatToStr(g_MMIComm->m_mmiToSeq.buffer.motTable.dPos[9]/1000);
        edt73->Text =  FloatToStr(g_MMIComm->m_mmiToSeq.buffer.motTable.dPos[10]/1000);
        edt75->Text =  FloatToStr(g_MMIComm->m_mmiToSeq.buffer.motTable.dPos[11]/1000);
        edt77->Text =  FloatToStr(g_MMIComm->m_mmiToSeq.buffer.motTable.dPos[12]/1000);


        edt81->Text =  FloatToStr(g_MMIComm->m_mmiToSeq.buffer.motTable.dPos[1]/1000);
        edt83->Text =  FloatToStr(g_MMIComm->m_mmiToSeq.buffer.motTable.dPos[2]/1000);
        edt85->Text =  FloatToStr(g_MMIComm->m_mmiToSeq.buffer.motTable.dPos[3]/1000);
        edt87->Text =  FloatToStr(g_MMIComm->m_mmiToSeq.buffer.motTable.dPos[4]/1000);
	}
}

bool TfrmSystemTeach::saveMotorSeq()
{
    g_MMIComm->m_mmiToSeq.nCmd  = CMD_RD_MT_TABLE;
    g_MMIComm->m_mmiToSeq.buffer.motTable.nMtNo = 0;

    if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
    {

        g_MMIComm->m_mmiToSeq.buffer.motTable.dPos [4] = edt70->Text.ToDouble()*1000;
        g_MMIComm->m_mmiToSeq.buffer.motTable.dPos [5] = edt80->Text.ToDouble()*1000;

        g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_MT_TABLE;
        g_MMIComm->Send()  && g_MMIComm->Recv();
    }

    g_MMIComm->m_mmiToSeq.nCmd  = CMD_RD_MT_TABLE;
    g_MMIComm->m_mmiToSeq.buffer.motTable.nMtNo = 1;

    if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
    {

        g_MMIComm->m_mmiToSeq.buffer.motTable.dPos [4] = edt72->Text.ToDouble()*1000;
        g_MMIComm->m_mmiToSeq.buffer.motTable.dPos [5] = edt82->Text.ToDouble()*1000;

        g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_MT_TABLE;
        g_MMIComm->Send()  && g_MMIComm->Recv();
    }

    g_MMIComm->m_mmiToSeq.nCmd  = CMD_RD_MT_TABLE;
    g_MMIComm->m_mmiToSeq.buffer.motTable.nMtNo = 2;

    if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
    {

        g_MMIComm->m_mmiToSeq.buffer.motTable.dPos [4] = edt74->Text.ToDouble()*1000;
        g_MMIComm->m_mmiToSeq.buffer.motTable.dPos [5] = edt84->Text.ToDouble()*1000;

        g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_MT_TABLE;
        g_MMIComm->Send()  && g_MMIComm->Recv();
    }

    g_MMIComm->m_mmiToSeq.nCmd  = CMD_RD_MT_TABLE;
    g_MMIComm->m_mmiToSeq.buffer.motTable.nMtNo = 3;

    if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
    {

        g_MMIComm->m_mmiToSeq.buffer.motTable.dPos [4] = edt76->Text.ToDouble()*1000;
        g_MMIComm->m_mmiToSeq.buffer.motTable.dPos [5] = edt86->Text.ToDouble()*1000;

        g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_MT_TABLE;
        g_MMIComm->Send()  && g_MMIComm->Recv();
    }

    g_MMIComm->m_mmiToSeq.nCmd  = CMD_RD_MT_TABLE;
    g_MMIComm->m_mmiToSeq.buffer.motTable.nMtNo = 25;

    if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
    {

        g_MMIComm->m_mmiToSeq.buffer.motTable.dPos [1] = edt81->Text.ToDouble()*1000;
        g_MMIComm->m_mmiToSeq.buffer.motTable.dPos [2] = edt83->Text.ToDouble()*1000;
        g_MMIComm->m_mmiToSeq.buffer.motTable.dPos [3] = edt85->Text.ToDouble()*1000;
        g_MMIComm->m_mmiToSeq.buffer.motTable.dPos [4] = edt87->Text.ToDouble()*1000;

        g_MMIComm->m_mmiToSeq.buffer.motTable.dPos [9] = edt71->Text.ToDouble()*1000;
        g_MMIComm->m_mmiToSeq.buffer.motTable.dPos [10] = edt73->Text.ToDouble()*1000;
        g_MMIComm->m_mmiToSeq.buffer.motTable.dPos [11] = edt75->Text.ToDouble()*1000;
        g_MMIComm->m_mmiToSeq.buffer.motTable.dPos [12] = edt77->Text.ToDouble()*1000;

        g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_MT_TABLE;
        g_MMIComm->Send()  && g_MMIComm->Recv();
    }

}

bool    TfrmSystemTeach::saveMotorDB()
{
	int nGrpNo, nRcpNo;

	nGrpNo = nReadGroupNo();
	nRcpNo = nReadRecipeNo();

    TIniFile *cmnIni[5];
    TIniFile *ini[5];
    int axis_no[5] = {0,1,2,3,25};

    String sCmnPath = ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP0\\RCP0\\";
    String sPath = ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(nGrpNo)+"\\RCP"+IntToStr(nRcpNo)+"\\Motor0.ini";

    for (int i= 0; i <5; i++)
    {
    	cmnIni[i] = new TIniFile(sCmnPath + "Motor" + IntToStr(axis_no[i])+".ini" );
        ini[i] = new TIniFile(sCmnPath + "Motor" + IntToStr(axis_no[i])+".ini" );
    }

    if ( NULL != ini[0] )
    {
        ini[0]->WriteString("INDEXPOS","POSITION4",edt70->Text);
        ini[0]->WriteString("INDEXPOS","POSITION5",edt80->Text);

        delete ini[0];
    }

    if (NULL != cmnIni[0] )
    {
        cmnIni[0]->WriteString("INDEXPOS","POSITION4", edt70->Text);
        cmnIni[0]->WriteString("INDEXPOS","POSITION5", edt80->Text);

        delete cmnIni[0];
    }

    if (NULL != ini[1] )
    {
        ini[1]->WriteString("INDEXPOS","POSITION4",edt72->Text);
        ini[1]->WriteString("INDEXPOS","POSITION5",edt82->Text);

        delete ini[1];
    }

	if (NULL != cmnIni[1] )
    {
        cmnIni[1]->WriteString("INDEXPOS","POSITION4", edt72->Text);
        cmnIni[1]->WriteString("INDEXPOS","POSITION5", edt82->Text);

        delete cmnIni[1];
    }

    if (NULL != ini[2] )
    {
        ini[2]->WriteString("INDEXPOS","POSITION4",edt74->Text);
        ini[2]->WriteString("INDEXPOS","POSITION5",edt84->Text);

        delete ini[2];
    }

	if (NULL != cmnIni[2] )
    {
        cmnIni[2]->WriteString("INDEXPOS","POSITION4", edt74->Text);
        cmnIni[2]->WriteString("INDEXPOS","POSITION5", edt84->Text);

        delete cmnIni[2];
    }


    if (NULL != ini[3] )
    {
        ini[3]->WriteString("INDEXPOS","POSITION4",edt76->Text);
        ini[3]->WriteString("INDEXPOS","POSITION5",edt86->Text);

        delete ini[3];
    }

    if (NULL != cmnIni[3] )
    {
	    cmnIni[3]->WriteString("INDEXPOS","POSITION4", edt76->Text);
    	cmnIni[3]->WriteString("INDEXPOS","POSITION5", edt86->Text);

        delete cmnIni[3];
    }

    if (NULL != ini[4] )
    {
        ini[4]->WriteString("INDEXPOS","POSITION1",edt81->Text);
        ini[4]->WriteString("INDEXPOS","POSITION2",edt83->Text);
        ini[4]->WriteString("INDEXPOS","POSITION3",edt85->Text);
        ini[4]->WriteString("INDEXPOS","POSITION4",edt87->Text);
        ini[4]->WriteString("INDEXPOS","POSITION3",edt71->Text);
        ini[4]->WriteString("INDEXPOS","POSITION4",edt73->Text);
        ini[4]->WriteString("INDEXPOS","POSITION3",edt75->Text);
        ini[4]->WriteString("INDEXPOS","POSITION4",edt77->Text);

        delete ini[4];
    }

    if (NULL != cmnIni[4] )
    {
        cmnIni[4]->WriteString("INDEXPOS","POSITION1",edt81->Text);
        cmnIni[4]->WriteString("INDEXPOS","POSITION2",edt83->Text);
        cmnIni[4]->WriteString("INDEXPOS","POSITION3",edt85->Text);
        cmnIni[4]->WriteString("INDEXPOS","POSITION4",edt87->Text);
        cmnIni[4]->WriteString("INDEXPOS","POSITION9",edt71->Text);
        cmnIni[4]->WriteString("INDEXPOS","POSITION10",edt73->Text);
        cmnIni[4]->WriteString("INDEXPOS","POSITION11",edt75->Text);
        cmnIni[4]->WriteString("INDEXPOS","POSITION12",edt77->Text);

        delete cmnIni[4];
    }

	return true;
}

void TfrmSystemTeach::loadDdm()
{
	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_DDM;
    g_MMIComm->m_mmiToSeq.buffer.ddm.nStart = 0;
    g_MMIComm->m_mmiToSeq.buffer.ddm.nEnd = 999;
	if(true == g_MMIComm->Send())
	{
		if(true == g_MMIComm->Recv())
		{

        	edt50->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 50 ] , ffFixed, 10, 3);
            edt51->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 51 ] , ffFixed, 10, 3);
            edt52->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 52 ] , ffFixed, 10, 3);
            edt53->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 53 ] , ffFixed, 10, 3);
            edt54->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 54 ] , ffFixed, 10, 3);
            edt55->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 55 ] , ffFixed, 10, 3);
            edt56->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 56 ] , ffFixed, 10, 3);
        	edt57->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 57 ] , ffFixed, 10, 3);

        	edt60->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 60 ] , ffFixed, 10, 3);
            edt61->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 61 ] , ffFixed, 10, 3);
            edt62->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 62 ] , ffFixed, 10, 3);
            edt63->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 63 ] , ffFixed, 10, 3);
            edt64->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 64 ] , ffFixed, 10, 3);
            edt65->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 65 ] , ffFixed, 10, 3);
            edt66->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 66 ] , ffFixed, 10, 3);
        	edt67->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 67 ] , ffFixed, 10, 3);
            edt68->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 68 ] , ffFixed, 10, 3);
        	edt69->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 69 ] , ffFixed, 10, 3);

         	edt70->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 70 ] , ffFixed, 10, 3);
            edt71->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 71 ] , ffFixed, 10, 3);
            edt72->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 72 ] , ffFixed, 10, 3);
            edt73->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 73 ] , ffFixed, 10, 3);
            edt74->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 74 ] , ffFixed, 10, 3);
            edt75->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 75 ] , ffFixed, 10, 3);
            edt76->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 76 ] , ffFixed, 10, 3);
        	edt77->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 77 ] , ffFixed, 10, 3);

        	edt80->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 80 ] , ffFixed, 10, 3);
            edt81->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 81 ] , ffFixed, 10, 3);
            edt82->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 82 ] , ffFixed, 10, 3);
            edt83->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 83 ] , ffFixed, 10, 3);
            edt84->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 84 ] , ffFixed, 10, 3);
            edt85->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 85 ] , ffFixed, 10, 3);
            edt86->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 86 ] , ffFixed, 10, 3);
        	edt87->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 87 ] , ffFixed, 10, 3);
            edt88->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 88 ] , ffFixed, 10, 3);
        	edt89->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 89 ] , ffFixed, 10, 3);

        	edt90->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 220 ] , ffFixed, 10, 3);   //90
            edt91->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 221 ] , ffFixed, 10, 3);   //91
            edt92->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 210 ] , ffFixed, 10, 3);   //92
            edt93->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 211 ] , ffFixed, 10, 3);   //93
            edt94->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 200 ] , ffFixed, 10, 3);   //94
            edt95->Text = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 201 ] , ffFixed, 10, 3);   //95
		}
	}
}

bool TfrmSystemTeach::saveDdm()
{
	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_DDM;
    g_MMIComm->m_mmiToSeq.buffer.ddm.nStart = 0;
    g_MMIComm->m_mmiToSeq.buffer.ddm.nEnd = 999;
	if(true == g_MMIComm->Send())
	{
		if(true == g_MMIComm->Recv())
		{


       		g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 50 ] =  edt50->Text.ToDouble();// = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 50 ] , ffFixed, 10, 3);
            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 51 ] =  edt51->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 51 ] , ffFixed, 10, 3);
            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 52 ] =  edt52->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 52 ] , ffFixed, 10, 3);
            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 53 ] =  edt53->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 53 ] , ffFixed, 10, 3);
            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 54 ] =  edt54->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 54 ] , ffFixed, 10, 3);
            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 55 ] =  edt55->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 55 ] , ffFixed, 10, 3);
            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 56 ] =  edt56->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 56 ] , ffFixed, 10, 3);
            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 57 ] =  edt57->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 57 ] , ffFixed, 10, 3);

            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 60 ] =  edt60->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 60 ] , ffFixed, 10, 3);
            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 61 ] =  edt61->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 61 ] , ffFixed, 10, 3);
            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 62 ] =  edt62->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 62 ] , ffFixed, 10, 3);
            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 63 ] =  edt63->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 63 ] , ffFixed, 10, 3);
            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 64 ] =  edt64->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 64 ] , ffFixed, 10, 3);
            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 65 ] =  edt65->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 65 ] , ffFixed, 10, 3);
            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 66 ] =  edt66->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 66 ] , ffFixed, 10, 3);
            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 67 ] =  edt67->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 67 ] , ffFixed, 10, 3);
            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 68 ] =  edt68->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 68 ] , ffFixed, 10, 3);
            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 69 ] =  edt69->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 69 ] , ffFixed, 10, 3);

            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 70 ] =  edt70->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 70 ] , ffFixed, 10, 3);
            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 71 ] =  edt71->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 71 ] , ffFixed, 10, 3);
            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 72 ] =  edt72->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 72 ] , ffFixed, 10, 3);
            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 73 ] =  edt73->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 73 ] , ffFixed, 10, 3);
            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 74 ] =  edt74->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 74 ] , ffFixed, 10, 3);
            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 75 ] =  edt75->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 75 ] , ffFixed, 10, 3);
            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 76 ] =  edt76->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 76 ] , ffFixed, 10, 3);
            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 77 ] =  edt77->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 77 ] , ffFixed, 10, 3);

            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 80 ] =  edt80->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 80 ] , ffFixed, 10, 3);
            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 81 ] =  edt81->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 81 ] , ffFixed, 10, 3);
            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 82 ] =  edt82->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 82 ] , ffFixed, 10, 3);
            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 83 ] =  edt83->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 83 ] , ffFixed, 10, 3);
            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 84 ] =  edt84->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 84 ] , ffFixed, 10, 3);
            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 85 ] =  edt85->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 85 ] , ffFixed, 10, 3);
            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 86 ] =  edt86->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 86 ] , ffFixed, 10, 3);
            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 87 ] =  edt87->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 87 ] , ffFixed, 10, 3);
            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 88 ] =  edt88->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 88 ] , ffFixed, 10, 3);
            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 89 ] =  edt89->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 89 ] , ffFixed, 10, 3);

            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 220 ] =  edt90->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 90 ] , ffFixed, 10, 3);
            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 221 ] =  edt91->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 91 ] , ffFixed, 10, 3);
            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 210 ] =  edt92->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 92 ] , ffFixed, 10, 3);
            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 211 ] =  edt93->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 93 ] , ffFixed, 10, 3);
            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 200 ] =  edt94->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 94 ] , ffFixed, 10, 3);
            g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 201 ] =  edt95->Text.ToDouble(); // = FloatToStrF( g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[ 95 ] , ffFixed, 10, 3);

			g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_DDM;
            g_MMIComm->m_mmiToSeq.buffer.ddm.nStart = 0;
            g_MMIComm->m_mmiToSeq.buffer.ddm.nEnd = 999;
            if(true == g_MMIComm->Send())
            {
                if(true == g_MMIComm->Recv())
                {
                    return true;
                }
                else
                {
                	return false;
                }
            }
            else
            {
            	return false;
            }
		}
	}
}




void __fastcall TfrmSystemTeach::BitBtn4Click(TObject *Sender)
{
	this->loadMotorSeq();
}
//---------------------------------------------------------------------------

void __fastcall TfrmSystemTeach::Timer1Timer(TObject *Sender)
{
	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_MODBUS;

	if ( g_MMIComm->Send() &&  g_MMIComm->Recv() )
	{
		EditCurXPos->Text =  FloatToStrF(g_MMIComm->m_mmiToSeq.buffer.modbus.inputRegister[0], ffFixed, 10, 3 );
		EditCurYPos->Text =  FloatToStrF(g_MMIComm->m_mmiToSeq.buffer.modbus.inputRegister[1], ffFixed, 10, 3 );
	}
    else
    {

	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmSystemTeach::btnIndexWrite1Click(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

	FrmCdBox->setFlag(CD_YESNO);
	FrmCdBox->setTitle("Overwrite Robot Position");
    FrmCdBox->setText("Do you want to overwrite current position?");
    FrmCdBox->BringToFront();
    if (mrYes != FrmCdBox->ShowModal())
		return;	//

	int nTag = dynamic_cast<TBitBtn*>(Sender)->Tag;

	TEdit* editX = (TEdit*)FindComponent("TrayEdit"+IntToStr(nTag));
	TEdit* editY = (TEdit*)FindComponent("TrayEdit"+IntToStr(nTag+1));

	if(editX != NULL)
	{
		editX->Text = EditCurXPos->Text;
	}
	if(editY != NULL)
	{
		editY->Text = EditCurYPos->Text;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmSystemTeach::FormClose(TObject *Sender, TCloseAction &Action)

{
	Timer1->Enabled = false;
}
//---------------------------------------------------------------------------

