//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FrmStaubliControlScrn.h"
#include "fSetCommonStaubli.h"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include "BaseComm.h"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma resource "*.dfm"
TFrmStaubliControl *FrmStaubliControl;

//	#define _Modbus_coilsCnt_      8
//	#define _Modbus_discreteCnt_   10
//	#define _Modbus_HRCnt_         44
//	#define _Modbus_IRCnt_          8

	#define _Modbus_coilsCnt_      16
	#define _Modbus_discreteCnt_   16
	#define _Modbus_HRCnt_         46 // 45 -> 46 변경
	#define _Modbus_IRCnt_         14 // 13 -> 14로 변경


	String strModBusCoils[8] = {"POWER ON" , "START" , "STOP" , "PAUSE" , "HOME" , "MOVE" , "RESET" , "VAC" } ;
	String strModBusInput[10] = {"READY" , "POWER" , "BUSY" , "PAUSE" , "STOP" , "HOME" , "DRIVING" , "ERROR" , "VAC" , "AUTOMODE" } ;

    TColor PanelColor[3] = {clLime , clRed , clBlue} ;

//---------------------------------------------------------------------------
__fastcall TFrmStaubliControl::TFrmStaubliControl(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TFrmStaubliControl::Staubli_Initilize()
{
	StaubliGrid->Cells[0][0] = "ID";
	StaubliGrid->Cells[1][0] = "INDEX NAME";
    StaubliGrid->Cells[2][0] = "SET X";
    StaubliGrid->Cells[3][0] = "SET Y";
    StaubliGrid->Cells[4][0] = "SET Z";
    StaubliGrid->Cells[5][0] = "SET RZ";
    StaubliGrid->Cells[6][0] = "SET Z Offset";
    //StaubliGrid->Cells[7][0] = "SET SPEED";

    StaubliGrid->Cells[7][0] = "ACT X";
    StaubliGrid->Cells[8][0] = "ACT Y";
    StaubliGrid->Cells[9][0] = "ACT Z";
    StaubliGrid->Cells[10][0] = "ACT RZ";
    StaubliGrid->Cells[11][0] = "ACT Z Offset";
    //StaubliGrid->Cells[12][0] = "ACT SPEED";

	for( int i = 0; i < this->StaubliGrid->RowCount; i++ )
	{
		this->StaubliGrid->Cells[ 0 ][ i + 1 ] = IntToStr( i );
	}


    StaubliGridSpeed->Cells[0][0] = "ID";
    StaubliGridSpeed->Cells[1][0] = "INDEX NAME";
    StaubliGridSpeed->Cells[2][0] = "SET SPEED";
    StaubliGridSpeed->Cells[3][0] = "ACT SPEED";
	for( int i = 0; i < this->StaubliGridSpeed->RowCount; i++ )
	{
		this->StaubliGridSpeed->Cells[ 0 ][ i + 1 ] = IntToStr( i );
	}




	ModBusGrid->Cells[0][0] = "ID";
//	ModBusGrid->Cells[1][0] = "COILS";
//	ModBusGrid->Cells[2][0] = "VAL";
//	ModBusGrid->Cells[3][0] = "D_INPUT";
//	ModBusGrid->Cells[4][0] = "VAL";
	ModBusGrid->Cells[1][0] = "H_REG";
    ModBusGrid->Cells[2][0] = "VAL";
	ModBusGrid->Cells[3][0] = "I_REG";
	ModBusGrid->Cells[4][0] = "VAL";

	for( int i = 0; i < this->ModBusGrid->RowCount; i++ )
	{
		this->ModBusGrid->Cells[ 0 ][ i + 1 ] = IntToStr( i );
	}

	this->Staubli_DataRead();

	this->ModbusIndexNameRead();
	ModbusTimer->Enabled = true;

	this->StaubliSpeed_Initilize();
}


void TFrmStaubliControl::StaubliSpeed_Initilize()
{
    StaubliGridSpeed->Cells[0][0] = "ID";
    StaubliGridSpeed->Cells[1][0] = "INDEX NAME";
    StaubliGridSpeed->Cells[2][0] = "SET SPEED";
    StaubliGridSpeed->Cells[3][0] = "ACT SPEED";

    TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\PKGName.ini");

    /*
	robotPickZSpeed			= 30,
	robotPlaceZSpeed		= 31,
	robotPickSpeed			= 32,
	robotHomeSpeed			= 33,
	robotHomeFastSpeed		= 34,
	robotPadChangeSpeed		= 35,
	robotSlowSpeed			= 36,

	robotPlaceSpeed			= 36, // Normal speed

	robotRearGoodFromStg1	= 37,
	robotRearGoodFromStg2	= 38,
	robotRearGoodFromStg3	= 39,
	robotRearGoodFromStg4	= 40,
	robotRearGoodFromVi	= 41,
	robotRearGoodFromFlip	= 42,

	robotFrontGoodFromStg1	= 43,
	robotFrontGoodFromStg2	= 44,
	robotFrontGoodFromStg3	= 45,
	robotFrontGoodFromStg4	= 46,
	robotFrontGoodFromVi	= 47,
	robotFrontGoodFromFlip	= 48,

	robotFlipFromStg1		= 49,
	robotFlipFromStg2		= 50,
	robotFlipFromStg3		= 51,
	robotFlipFromStg4		= 52,

	staubliPickDelay		= 54,
	staubliPlaceDelay		= 55,
    ...

    = 59
    */
    for(int i=0; i<30;i++)
    {
        StaubliGridSpeed->Cells[0][i+1] = IntToStr(i);
        StaubliGridSpeed->Cells[1][i+1] = ini->ReadString("PKGNAME","NAME"+IntToStr(i+30),"Name"+IntToStr(i+30));
    }
	delete ini;

	this->StaubliSpeed_DataRead();

}
//---------------------------------------------------------------------------
void TFrmStaubliControl::Staubli_DataRead()
{
	int nGrpNo, nRcpNo;

    nGrpNo = nReadGroupNo();
    nRcpNo = nReadRecipeNo();

    String StrPath = ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(nGrpNo)+"\\RCP"+IntToStr(nRcpNo)+"\\StaubliData.ini";
    String StrCommonPath = ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP0\\RCP0\\StaubliData.ini";
    String StrNamePath = ExtractFilePath(Application->ExeName)+ "\\Ini\\StaubliIndexName.ini";


    if(FileExists(StrPath))
    {
        TIniFile *ini = new TIniFile(StrPath);
        TIniFile *iniCmn = new TIniFile(StrCommonPath);
		TIniFile *iniName = new TIniFile(StrNamePath);

		for( int nRow = 0; nRow < 30; nRow++ )
		{
			StaubliGrid->Cells[1][nRow+1] = ini->ReadString("INDEXNAME","INDEXNAME"+IntToStr(nRow),"INDEXNAME"+IntToStr(nRow));

            bool bCommon = iniName->ReadBool("INDEXNAME","COMMON"+IntToStr(nRow), true);

            if (bCommon == true)
			{
				StaubliGrid->Cells[2][nRow+1] = FloatToStrF(iniCmn->ReadString("XPOS","VALUE"+IntToStr(nRow),"0").ToDouble(),ffFixed,10,3);
                StaubliGrid->Cells[3][nRow+1] = FloatToStrF(iniCmn->ReadString("YPOS","VALUE"+IntToStr(nRow),"0").ToDouble(),ffFixed,10,3);
                StaubliGrid->Cells[4][nRow+1] = FloatToStrF(iniCmn->ReadString("ZPOS","VALUE"+IntToStr(nRow),"0").ToDouble(),ffFixed,10,3);
                StaubliGrid->Cells[5][nRow+1] = FloatToStrF(iniCmn->ReadString("RZPOS","VALUE"+IntToStr(nRow),"0").ToDouble(),ffFixed,10,3);
                StaubliGrid->Cells[6][nRow+1] = FloatToStrF(iniCmn->ReadString("ZOFFSET","VALUE"+IntToStr(nRow),"0").ToDouble(),ffFixed,10,3);
                //StaubliGrid->Cells[7][nRow+1] = FloatToStrF(ini->ReadString("SPEED","VALUE"+IntToStr(nRow),"0").ToDouble(),ffFixed,10,3);
			}
            else
            {
                StaubliGrid->Cells[2][nRow+1] = FloatToStrF(ini->ReadString("XPOS","VALUE"+IntToStr(nRow),"0").ToDouble(),ffFixed,10,3);
                StaubliGrid->Cells[3][nRow+1] = FloatToStrF(ini->ReadString("YPOS","VALUE"+IntToStr(nRow),"0").ToDouble(),ffFixed,10,3);
				StaubliGrid->Cells[4][nRow+1] = FloatToStrF(ini->ReadString("ZPOS","VALUE"+IntToStr(nRow),"0").ToDouble(),ffFixed,10,3);
                StaubliGrid->Cells[5][nRow+1] = FloatToStrF(ini->ReadString("RZPOS","VALUE"+IntToStr(nRow),"0").ToDouble(),ffFixed,10,3);
				StaubliGrid->Cells[6][nRow+1] = FloatToStrF(ini->ReadString("ZOFFSET","VALUE"+IntToStr(nRow),"0").ToDouble(),ffFixed,10,3);
                //StaubliGrid->Cells[7][nRow+1] = FloatToStrF(ini->ReadString("SPEED","VALUE"+IntToStr(nRow),"0").ToDouble(),ffFixed,10,3);
			}
		}

        delete ini;
        delete iniCmn;
        delete iniName;

    }

	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_STAUBLI_TABLE;

	if ( g_MMIComm->Send() &&  g_MMIComm->Recv() )
	{
		for( int nRow = 0; nRow < 30; nRow++ )
		{
			StaubliGrid->Cells[7][nRow+1] =  FloatToStrF(g_MMIComm->m_mmiToSeq.buffer.staubliTable.posX[nRow],ffFixed,10,3);
			StaubliGrid->Cells[8][nRow+1] =  FloatToStrF(g_MMIComm->m_mmiToSeq.buffer.staubliTable.posY[nRow],ffFixed,10,3);
			StaubliGrid->Cells[9][nRow+1] =  FloatToStrF(g_MMIComm->m_mmiToSeq.buffer.staubliTable.posZ[nRow],ffFixed,10,3);
			StaubliGrid->Cells[10][nRow+1] =  FloatToStrF(g_MMIComm->m_mmiToSeq.buffer.staubliTable.posRZ[nRow],ffFixed,10,3);
			StaubliGrid->Cells[11][nRow+1] =  FloatToStrF(g_MMIComm->m_mmiToSeq.buffer.staubliTable.posZOffset[nRow],ffFixed,10,3);
			//StaubliGrid->Cells[12][nRow+1] =  FloatToStrF(g_MMIComm->m_mmiToSeq.buffer.staubliTable.speed[nRow],ffFixed,10,3);
        }
	}
    else
    {

	}
}
//---------------------------------------------------------------------------

void TFrmStaubliControl::Staubli_DataSave()
{
	int nGrpNo, nRcpNo;

    nGrpNo = nReadGroupNo();
	nRcpNo = nReadRecipeNo();

    String StrPath = ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(nGrpNo)+"\\RCP"+IntToStr(nRcpNo)+"\\StaubliData.ini";
	String StrCommonPath = ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP0\\RCP0\\StaubliData.ini";
	String StrNamePath = ExtractFilePath(Application->ExeName)+ "\\Ini\\StaubliIndexName.ini";

	if(FileExists(StrPath))
    {
        TIniFile *ini = new TIniFile(StrPath);
        TIniFile *iniCmn = new TIniFile(StrCommonPath);
		TIniFile *iniName = new TIniFile(StrNamePath);

		this->StaubliLimit();

		for( int nRow = 0; nRow < 30; nRow++ )
		{
		   ini->WriteString("INDEXNAME","INDEXNAME"+IntToStr(nRow),StaubliGrid->Cells[1][nRow+1]);
		   ini->WriteString("XPOS","VALUE"+IntToStr(nRow),StaubliGrid->Cells[2][nRow+1]);
		   ini->WriteString("YPOS","VALUE"+IntToStr(nRow),StaubliGrid->Cells[3][nRow+1]);
		   ini->WriteString("ZPOS","VALUE"+IntToStr(nRow),StaubliGrid->Cells[4][nRow+1]);
		   ini->WriteString("RZPOS","VALUE"+IntToStr(nRow),StaubliGrid->Cells[5][nRow+1]);
		   ini->WriteString("ZOFFSET","VALUE"+IntToStr(nRow),StaubliGrid->Cells[6][nRow+1]);
           //ini->WriteString("SPEED","VALUE"+IntToStr(nRow),StaubliGrid->Cells[7][nRow+1]);

            bool bCommon = iniName->ReadBool("INDEXNAME","COMMON"+IntToStr(nRow), true);

            if (bCommon == true)    // ini 저장은 공통, 레시피 둘다 저장, 읽어서 seq 쓸때만 공통인지레시피인지 구분
            {
               iniCmn->WriteString("INDEXNAME","INDEXNAME"+IntToStr(nRow),StaubliGrid->Cells[1][nRow+1]);
               iniCmn->WriteString("XPOS","VALUE"+IntToStr(nRow),StaubliGrid->Cells[2][nRow+1]);
               iniCmn->WriteString("YPOS","VALUE"+IntToStr(nRow),StaubliGrid->Cells[3][nRow+1]);
               iniCmn->WriteString("ZPOS","VALUE"+IntToStr(nRow),StaubliGrid->Cells[4][nRow+1]);
               iniCmn->WriteString("RZPOS","VALUE"+IntToStr(nRow),StaubliGrid->Cells[5][nRow+1]);
               iniCmn->WriteString("ZOFFSET","VALUE"+IntToStr(nRow),StaubliGrid->Cells[6][nRow+1]);
               //iniCmn->WriteString("SPEED","VALUE"+IntToStr(nRow),StaubliGrid->Cells[7][nRow+1]);
            }

            iniName->WriteString("INDEXNAME","INDEXNAME"+IntToStr(nRow),StaubliGrid->Cells[1][nRow+1]);
        }
        delete ini;
    }

    g_MMIComm->m_mmiToSeq.nCmd  = CMD_RD_STAUBLI_TABLE;

    if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
    {
        for(int i=0; i<30; i++)
        {
			if(StaubliGrid->Cells[2][i+1] != "")
            {
                g_MMIComm->m_mmiToSeq.buffer.staubliTable.posX[i] = StaubliGrid->Cells[2][i+1].ToDouble();
            }
            else
            {
                g_MMIComm->m_mmiToSeq.buffer.staubliTable.posX[i] = 0.;

            }

            if(StaubliGrid->Cells[3][i+1] !="")
            {
                g_MMIComm->m_mmiToSeq.buffer.staubliTable.posY[i] = StaubliGrid->Cells[3][i+1].ToDouble();
            }
            else
            {
                g_MMIComm->m_mmiToSeq.buffer.staubliTable.posY [i] = 0.;

            }

            if(StaubliGrid->Cells[4][i+1] !="")
            {
                g_MMIComm->m_mmiToSeq.buffer.staubliTable.posZ[i] = StaubliGrid->Cells[4][i+1].ToDouble();
            }
            else
            {
                g_MMIComm->m_mmiToSeq.buffer.staubliTable.posZ[i] = 0.;

            }

            if(StaubliGrid->Cells[5][i+1] !="")
            {
                g_MMIComm->m_mmiToSeq.buffer.staubliTable.posRZ [i] = StaubliGrid->Cells[5][i+1].ToDouble();
            }
            else
            {
                g_MMIComm->m_mmiToSeq.buffer.staubliTable.posRZ[i] = 0.;

            }

            if(StaubliGrid->Cells[6][i+1] !="")
            {
                g_MMIComm->m_mmiToSeq.buffer.staubliTable.posZOffset [i] = StaubliGrid->Cells[6][i+1].ToDouble();
            }
            else
            {
                g_MMIComm->m_mmiToSeq.buffer.staubliTable.posZOffset[i] = 0.;

            }

//            if(StaubliGrid->Cells[7][i+1] !="")
//            {
//                g_MMIComm->m_mmiToSeq.buffer.staubliTable.speed [i] = StaubliGrid->Cells[7][i+1].ToDouble();
//            }
//            else
//            {
//                g_MMIComm->m_mmiToSeq.buffer.staubliTable.speed[i] = 0.;
//
//            }
        }

		g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_STAUBLI_TABLE;
        if(g_MMIComm->Send()  && g_MMIComm->Recv())
        {

        }
    }
    else
    {

    }
}
//---------------------------------------------------------------------------
void TFrmStaubliControl::_Staubli_ReverseSave()   // NDM 19  : 1 -> 0
{
	int nGrpNo, nRcpNo;

	nGrpNo = nReadGroupNo();
	nRcpNo = nReadRecipeNo();

	String StrPath = ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(nGrpNo)+"\\RCP"+IntToStr(nRcpNo)+"\\StaubliData.ini";

	if(FileExists(StrPath))
	{
		MainForm->MachineHistoryData("Staubli Data Save activating...");
		TIniFile *ini = new TIniFile(StrPath);

		g_MMIComm->m_mmiToSeq.nCmd  = CMD_RD_STAUBLI_TABLE;

		if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
		{
			for(int nRow=0; nRow<30; nRow++)
			{
				ini->WriteString("XPOS","VALUE"+IntToStr(nRow), FloatToStr(g_MMIComm->m_mmiToSeq.buffer.staubliTable.posX[nRow]));
				ini->WriteString("YPOS","VALUE"+IntToStr(nRow), FloatToStr(g_MMIComm->m_mmiToSeq.buffer.staubliTable.posY[nRow]));
				ini->WriteString("ZPOS","VALUE"+IntToStr(nRow), FloatToStr(g_MMIComm->m_mmiToSeq.buffer.staubliTable.posZ[nRow]));
				ini->WriteString("RZPOS","VALUE"+IntToStr(nRow),FloatToStr(g_MMIComm->m_mmiToSeq.buffer.staubliTable.posRZ[nRow]));
				ini->WriteString("ZOFFSET","VALUE"+IntToStr(nRow),FloatToStr(g_MMIComm->m_mmiToSeq.buffer.staubliTable.posZOffset[nRow]));
				//ini->WriteString("SPEED","VALUE"+IntToStr(nRow),FloatToStr(g_MMIComm->m_mmiToSeq.buffer.staubliTable.speed[nRow]));
			}
		}
		else
		{

		}
		delete ini;
	}
	else
	{
		MainForm->MachineHistoryData("Fail to Staubli Data Save : inifile exist error");
		return;
	}
	this->Staubli_DataRead();
	MainForm->MachineHistoryData("Staubli Data Save End...");
}
//---------------------------------------------------------------------------

void TFrmStaubliControl::StaubliSpeed_DataRead()
{
    g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_PKG;
    g_MMIComm->m_mmiToSeq.buffer.pkg.nStart = 30;
    g_MMIComm->m_mmiToSeq.buffer.pkg.nEnd = 30+29;
    if(true == g_MMIComm->Send() &&  true == g_MMIComm->Recv())
    {

		for( int nRow = 0; nRow < 30; nRow++ )
		{
			StaubliGridSpeed->Cells[2][nRow+1] =  FloatToStrF(g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[nRow+30],ffFixed,10,3);
			StaubliGridSpeed->Cells[3][nRow+1] =  FloatToStrF(g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[nRow+30],ffFixed,10,3);
        }

    }

}
//---------------------------------------------------------------------------

void TFrmStaubliControl::StaubliSpeed_DataSave()
{
    g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_PKG;
    g_MMIComm->m_mmiToSeq.buffer.pkg.nStart = 30;
    g_MMIComm->m_mmiToSeq.buffer.pkg.nEnd = 30+29;
    if(true == g_MMIComm->Send() &&  true == g_MMIComm->Recv())
    {
    	g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_PKG;
    	g_MMIComm->m_mmiToSeq.buffer.pkg.nStart = 30;
    	g_MMIComm->m_mmiToSeq.buffer.pkg.nEnd = 30+29;
		for( int nRow = 0; nRow < 30; nRow++ )
		{
        	g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[nRow+30] = StaubliGridSpeed->Cells[2][nRow+1].ToDouble() ;
        }
        if(true == g_MMIComm->Send() &&  true == g_MMIComm->Recv())
        {
        	//pkg 파라메터에 쓰기

            int nGrpNo, nRcpNo;
            nGrpNo = nReadGroupNo();
            nRcpNo = nReadRecipeNo();

            TIniFile *PkgParmini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\system\\GRP"+IntToStr(nGrpNo)+"\\RCP"+IntToStr(nRcpNo)+"\\PkgParam.ini");

            for(int i=0; i<30;i++)
            {
           	 	PkgParmini->WriteString("PKGPARM","VALUE"+IntToStr(30+i), StaubliGridSpeed->Cells[2][i+1]);
            }
            delete PkgParmini;
        }
    }
}


void __fastcall TFrmStaubliControl::BtnInputMotionDataClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

    BtnSaveMotionData->Enabled = true;
    BtnInputMotionData->Enabled = false;
    StaubliGrid->Options << goEditing;
    StaubliGrid->Options >> goRowSelect;

	StaubliGridSpeed->Options << goEditing;
    StaubliGridSpeed->Options >> goRowSelect;
}
//---------------------------------------------------------------------------

void __fastcall TFrmStaubliControl::BtnSaveMotionDataClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

    BtnInputMotionData->Enabled = true;
    BtnSaveMotionData->Enabled = false;
    StaubliGrid->Options >> goEditing;
    StaubliGrid->Options << goRowSelect;
	Staubli_DataSave();
    Staubli_DataRead();

    StaubliGridSpeed->Options >> goEditing;
	StaubliGridSpeed->Options << goRowSelect;
	StaubliSpeed_DataSave();
    StaubliSpeed_DataRead();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void TFrmStaubliControl::ModbusDataRead()
{
	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_MODBUS;

	if ( g_MMIComm->Send() &&  g_MMIComm->Recv() )
	{
//        for( int nRow = 0; nRow <= _Modbus_coilsCnt_; nRow++ )
//        {
//        	ModBusGrid->Cells[2][nRow+1] =  FloatToStr(g_MMIComm->m_mmiToSeq.buffer.modbus.coils[nRow]);
//        }
//
//        for( int nRow = 0; nRow <= _Modbus_discreteCnt_; nRow++ )
//        {
//        	ModBusGrid->Cells[4][nRow+1] =  FloatToStr(g_MMIComm->m_mmiToSeq.buffer.modbus.discreteInput[nRow]);
//        }

        for( int nRow = 0; nRow < _Modbus_HRCnt_; nRow++ )
        {
        	ModBusGrid->Cells[2][nRow+1] =  FloatToStrF(g_MMIComm->m_mmiToSeq.buffer.modbus.holdingRegister[nRow], ffFixed, 10, 3 );
        }

        for( int nRow = 0; nRow < _Modbus_IRCnt_; nRow++ )
        {
        	ModBusGrid->Cells[4][nRow+1] =  FloatToStrF(g_MMIComm->m_mmiToSeq.buffer.modbus.inputRegister[nRow], ffFixed, 10, 3 );
        }
	}
    else
    {

    }
}
//---------------------------------------------------------------------------
void TFrmStaubliControl::ModbusIndexNameRead()
{
    String StrPath = ExtractFilePath(Application->ExeName)+ "\\Ini\\ModbusData.ini";

    if(FileExists(StrPath))
    {
        TIniFile *ini = new TIniFile(StrPath);
        for( int nRow = 0; nRow < _Modbus_HRCnt_; nRow++ )
        {
//            ModBusGrid->Cells[1][nRow+1] = ini->ReadString("COILS","INDEXNAME"+IntToStr(nRow),"COILS"+IntToStr(nRow));
//            ModBusGrid->Cells[3][nRow+1] = ini->ReadString("DISCRETEINPUT","INDEXNAME"+IntToStr(nRow),"DISCRETE INPUT"+IntToStr(nRow));
            ModBusGrid->Cells[1][nRow+1] = ini->ReadString("HOLDINGREGISTER","INDEXNAME"+IntToStr(nRow),"HOLDING REGISTER"+IntToStr(nRow));
		}

        for( int nRow = 0; nRow <_Modbus_IRCnt_; nRow++ )
        {
            ModBusGrid->Cells[3][nRow+1] = ini->ReadString("INPUTREGISTER","INDEXNAME"+IntToStr(nRow),"INPUT REGISTER"+IntToStr(nRow));
        }
        delete ini;

    }
}
//---------------------------------------------------------------------------
void TFrmStaubliControl::ModbusIndexNameSave()
{
    String StrPath = ExtractFilePath(Application->ExeName)+ "\\Ini\\ModbusData.ini";

    if(FileExists(StrPath))
    {
        TIniFile *ini = new TIniFile(StrPath);
        for( int nRow = 0; nRow <_Modbus_HRCnt_; nRow++ )
        {
//            ini->WriteString("COILS","INDEXNAME"+IntToStr(nRow), (ModBusGrid->Cells[1][nRow+1]));
//            ini->WriteString("DISCRETEINPUT","INDEXNAME"+IntToStr(nRow),(ModBusGrid->Cells[3][nRow+1]));
            ini->WriteString("HOLDINGREGISTER","INDEXNAME"+IntToStr(nRow),(ModBusGrid->Cells[1][nRow+1]));
		}

        for( int nRow = 0; nRow <_Modbus_IRCnt_; nRow++ )
        {
            ini->WriteString("INPUTREGISTER","INDEXNAME"+IntToStr(nRow),(ModBusGrid->Cells[3][nRow+1]));
        }
        delete ini;

    }
}
//---------------------------------------------------------------------------
void TFrmStaubliControl::ModbusDataSave()
{
	g_MMIComm->m_mmiToSeq.nCmd  = CMD_RD_MODBUS;

    if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
    {

//            if(ModBusGrid->Cells[2][i+1] != "")
//            {
//                g_MMIComm->m_mmiToSeq.buffer.modbus.coils[i] = ModBusGrid->Cells[2][i+1].ToInt();
//            }
//            else
//            {
//                g_MMIComm->m_mmiToSeq.buffer.modbus.coils[i] = 0.;
//
//            }
//
//            if(ModBusGrid->Cells[4][i+1] !="")
//            {
//                g_MMIComm->m_mmiToSeq.buffer.modbus.discreteInput[i] = ModBusGrid->Cells[4][i+1].ToInt();
//            }
//            else
//            {
//                g_MMIComm->m_mmiToSeq.buffer.modbus.discreteInput [i] = 0.;
//
//            }
            for(int i=0; i<_Modbus_HRCnt_; i++)
            {
                if(ModBusGrid->Cells[2][i+1] !="")
                {
                    g_MMIComm->m_mmiToSeq.buffer.modbus.holdingRegister[i] = ModBusGrid->Cells[2][i+1].ToDouble();
                }
                else
                {
                    g_MMIComm->m_mmiToSeq.buffer.modbus.holdingRegister[i] = 0.;

                }
            }

            for(int i=0; i<_Modbus_IRCnt_; i++)
            {
                if(ModBusGrid->Cells[4][i+1] !="")
                {
                    g_MMIComm->m_mmiToSeq.buffer.modbus.inputRegister [i] = ModBusGrid->Cells[4][i+1].ToDouble();
                }
                else
                {
                    g_MMIComm->m_mmiToSeq.buffer.modbus.inputRegister[i] = 0.;

                }
            }

        g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_MODBUS;
        if(g_MMIComm->Send()  && g_MMIComm->Recv())
		{

        }
    }
    else
    {

    }
}
//---------------------------------------------------------------------------

void __fastcall TFrmStaubliControl::BtnModbusInputClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

    BtnModbusSave->Enabled = true;
    BtnModbusInput->Enabled = false;
    ModBusGrid->Options << goEditing;
    ModBusGrid->Options >> goRowSelect;
    ModbusTimer->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TFrmStaubliControl::BtnModbusSaveClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;

    BtnModbusInput->Enabled = true;
    BtnModbusSave->Enabled = false;
    ModBusGrid->Options >> goEditing;
    ModBusGrid->Options << goRowSelect;
    this->ModbusDataSave();
	this->ModbusIndexNameSave();
    ModbusTimer->Enabled = true;
	this->ModbusIndexNameRead();
}
//---------------------------------------------------------------------------

void __fastcall TFrmStaubliControl::ModbusTimerTimer(TObject *Sender)
{
	this->ModbusDataRead();


	bool bReadval = bool(nReadCommunicationDM(modbusIsOpen));

    PanelModBusOpen->Color =  bReadval ?  clLime: clGray;
    PanelModBusOpen->Caption =   "";
    PanelModBusOpen->Caption =   bReadval ? "MODBUS OPENING" : "MODBUS CLOSE";


    g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_MODBUS;

    if ( g_MMIComm->Send() &&  g_MMIComm->Recv() )
    {
        for( int nRow = 0; nRow <_Modbus_coilsCnt_; nRow++ )
        {
			TPanel* CloneFlowPanel = (TPanel*)FindComponent("ModbusCoil" + IntToStr(nRow+1));

            if(CloneFlowPanel != NULL)
            {
                bool bReadval =  bool(g_MMIComm->m_mmiToSeq.buffer.modbus.coils[nRow]);
                CloneFlowPanel->Color =  bReadval ? clLime: clGray;
                CloneFlowPanel->Caption =   "";
                CloneFlowPanel->Caption =   bReadval ? strModBusCoils[nRow] + " ON" : strModBusCoils[nRow] + " OFF";
           }
        }

        for( int nRow = 0; nRow <_Modbus_discreteCnt_; nRow++ )
        {
            TPanel* CloneFlowPanel = (TPanel*)FindComponent("ModbusInput" + IntToStr(nRow+1));

            if(CloneFlowPanel != NULL)
            {
                bool bReadval =  bool(g_MMIComm->m_mmiToSeq.buffer.modbus.discreteInput[nRow]);
                CloneFlowPanel->Color =  bReadval ? clLime: clGray;
                CloneFlowPanel->Caption =   "";
                CloneFlowPanel->Caption =   bReadval ? strModBusInput[nRow] + " ON" : strModBusInput[nRow] + " OFF";
           }
        }
        int nCode[4] ={1,2,4,8};
        int nErrorCode =0;
        for( int nRow = 10; nRow < 14; nRow++ )
        {
        	nErrorCode =+ (g_MMIComm->m_mmiToSeq.buffer.modbus.discreteInput[nRow])* nCode[nRow-10];
        }
        LabelModBusErrCode->Caption = "ERROR CODE : " + IntToStr(nErrorCode);
    }
}
//---------------------------------------------------------------------------


void __fastcall TFrmStaubliControl::ModbusCoil1DblClick(TObject *Sender)
{
	int nTagVal = dynamic_cast<TPanel *>(Sender)->Tag;

    TPanel* CloneFlowPanel = (TPanel*)FindComponent("ModbusCoil" + IntToStr(nTagVal+1));

    if(CloneFlowPanel != NULL)
    {
        g_MMIComm->m_mmiToSeq.nCmd  = CMD_RD_MODBUS;

        if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
        {
            if(CloneFlowPanel->Color != clLime)
            {
            	g_MMIComm->m_mmiToSeq.buffer.modbus.coils[nTagVal] = 1;
            }
            else
			{
                g_MMIComm->m_mmiToSeq.buffer.modbus.coils[nTagVal] =  0;
            }
		}

        g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_MODBUS;
        if(g_MMIComm->Send()  && g_MMIComm->Recv())
        {

        }
    }
}
//---------------------------------------------------------------------------


void __fastcall TFrmStaubliControl::StaubliGridDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State)
{
	if(ARow > 0  &&  ACol > 6 )
	{
    	StaubliGrid->Canvas->Brush->Color = clSilver;
        StaubliGrid->Canvas->Pen->Color = clBlack;
		StaubliGrid->Canvas->FillRect( Rect );
		StaubliGrid->Canvas->Font->Color = clBlack;
		StaubliGrid->Canvas->FillRect(StaubliGrid->CellRect(ACol,ARow));
		StaubliGrid->Canvas->TextRect( Rect, Rect.Left+5, Rect.Top+5, StaubliGrid->Cells[ACol][ARow] );
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmStaubliControl::ModBusGridDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State)
{
	if(ARow > _Modbus_IRCnt_  &&  ACol > 2 )
	{
    	ModBusGrid->Canvas->Brush->Color = clGray;
        ModBusGrid->Canvas->Pen->Color = clGray;
		ModBusGrid->Canvas->FillRect( Rect );
		ModBusGrid->Canvas->Font->Color = clBlack;
		ModBusGrid->Canvas->FillRect(ModBusGrid->CellRect(ACol,ARow));
		ModBusGrid->Canvas->TextRect( Rect, Rect.Left+5, Rect.Top+5, ModBusGrid->Cells[ACol][ARow] );
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmStaubliControl::BtnModBusOpenClick(TObject *Sender)
{
	if(!CheckCanDataAccess()) return;
	int nFlow = dynamic_cast<TSpeedButton *>(Sender)->Tag;
	bool bReadval = bool(nReadCommunicationDM( nFlow ));

	bReadval =  bReadval ? 0 : 1;
	nWriteCommunicationDM (bReadval , nFlow);
}
//---------------------------------------------------------------------------

void __fastcall TFrmStaubliControl::StaubliGridSpeedDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State)
{
	if(ARow > 0  &&  ACol > 2 )
	{
    	StaubliGridSpeed->Canvas->Brush->Color = clSilver;
        StaubliGridSpeed->Canvas->Pen->Color = clBlack;
		StaubliGridSpeed->Canvas->FillRect( Rect );
		StaubliGridSpeed->Canvas->Font->Color = clBlack;
		StaubliGridSpeed->Canvas->FillRect(StaubliGridSpeed->CellRect(ACol,ARow));
		StaubliGridSpeed->Canvas->TextRect( Rect, Rect.Left+5, Rect.Top+5, StaubliGridSpeed->Cells[ACol][ARow] );
	}
}
//---------------------------------------------------------------------------


void __fastcall TFrmStaubliControl::SpeedButton1Click(TObject *Sender)
{
    if(CheckCanAccessLevel(PW_ENGINEER))
    {
        frmSetCommonStaubli->ShowModal();
        this->Staubli_DataRead();
	}
}
//---------------------------------------------------------------------------


void __fastcall TFrmStaubliControl::StaubliGridSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect)
{
	selectCol = ACol-1;
	selectRow = ARow-1;
}
//---------------------------------------------------------------------------
void	TFrmStaubliControl::StaubliLimit()
{
	int i = Stage1LimitZ;

	for(int j = 2; j <= 17; j++)
	{
		if(i == GoodRearLTopLimitZ)
		{
			j = 9;
		}

		float MaxValue = dReadCommunicationDM(i);
		float SelectValue = StrToFloat(StaubliGrid->Cells[4][j]);

		if(MaxValue > SelectValue)
		{
			FrmCdBox->setFlag(CD_YESNO);
			FrmCdBox->setTitle("STAUBLI DATA SAVE FAIL!");
			FrmCdBox->setText("STAUBLI 데이터 수정을 실패하였습니다. 지정된 DEFAULT 값 이내에 데이터를 기입하거나 DDM 600~612번을 확인하세요.");

			if(mrYes == FrmCdBox->ShowModal())
			{

			}

			this->Staubli_Initilize();

			return;
		}
		else
		{
			i = i+1;
		}
	}
}
//---------------------------------------------------------------------------
