#ifndef _BASEPROCESS_H_
#define _BASEPROCESS_H_

#include <inifiles.hpp>
#include <DBTables.hpp>
#include <Dialogs.hpp>
#include <stdlib.h>
#include <assert.h>

// -------------- Reference header files -------------------------------------
#include "Communication.h"
#include "PkgDataDef.h"
#include "cdbox.h"         
#include "NvMem.h"
#include "UserDataDef.h"
#include "AxisDef.h"
#include "flogin.h"
#include "MainFormScrn.h"

// -------------- BIT STATUS -------------------------------------------------
#define BIT(data,BitNo) (((DWORD)data>>BitNo)&0x01 ? 1: 0)
// -------------- SELECT BIT REVERSE -----------------------------------------
#define BITCHANGE(data, BitNo)\
		BIT(data, BitNo) ? (data &(DWORD)(~(1<<BitNo))) : (data |(DWORD)(1<<BitNo))
#define BITONOFF(data, BitNo, ONOFF)\
		ONOFF ? (data |(DWORD)(1<<BitNo)) : (data &(DWORD)(~(1<<BitNo)))
// ---------------------------------------------------------------------------
#define _1ST_CORE_	0x01
#define _2ND_CORE_	0x02

// ---------------------------------------------------------------------------
#define  _STATUS_LED_BLACK_                    0
#define  _STATUS_LED_RED_                      1
#define  _STATUS_LED_GREEN_                    2
#define  _STATUS_LED_BLUE_                     3

#define  _TENKEY_PARENT_BUTTON_WIDTH_           200
#define  _TENKEY_PARENT_BUTTON_HEIGHT_          60

#define  _TENKEY_CHILD_BUTTON_WIDTH_            200
#define  _TENKEY_CHILD_BUTTON_HEIGHT_           30

#define _TENKEY_MOTION_RUNMODE_DM_     96

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
#define  _RequestPRS_DATA_                       11
#define  _RequestOffset_Front_LASER_             15
#define  _RequestOffset_Rear_LASER_              16

#define  _Request_IDLE_             0
#define  _Request_COMPLETE_         0
#define  _Request_WRITE_            1
#define  _Request_READ_             1
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
#define      _READ_RECIPE_GRID_CNT_                         110
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#define  _PASS_OPERATOR_                1
#define  _PASS_MAINTENANCE_             2
#define  _PASS_ENGINEER_                3
#define  _PASS_PASS_                    0

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#define _MAX_COL_COUNT_         20
#define _MAX_ROW_COUNT_         20

#define		_RevWeight_	    1
#define		_ZeroSet_		0

#define  _pkg_START_NO1_             75
#define  _pkg_START_NO2_             81
#define  _pkg_TRAY_NO1_              151
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------


static String g_szDMList[]  = { "NDm", "DDm", "Parameter" };
static String g_szAlarmDBList[] = { "Alarm", "Warning" };
static String szRegPath = "Software\\KOSES\\MMI\\" + Application->Title + "\\";
static String g_szLangTag[]  = { "_k", "", "_c" };

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
String DecToBin(int number)
{
    if ( number == 0 ) return "0";
    if ( number == 1 ) return "1";

    if ( number % 2 == 0 )
        return DecToBin(number / 2) + "0";
    else
        return DecToBin(number / 2) + "1";
}
// ---------------------------------------------------------------------------

int __fastcall nReadCommunicationDM(int nDMno)
{
	int nRtnVal = 0;

	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_NDM;
    g_MMIComm->m_mmiToSeq.buffer.ndm.nStart = nDMno;
    g_MMIComm->m_mmiToSeq.buffer.ndm.nEnd = nDMno;

	if(true == g_MMIComm->Send())
	{
		if(true == g_MMIComm->Recv())
		{
			nRtnVal = g_MMIComm->m_mmiToSeq.buffer.ndm.nVal[nDMno];
		}
	}
	return nRtnVal;
}
//---------------------------------------------------------------------------
bool __fastcall nResponseWriteCommunicationDM(int nResponseVal,int nDivide)
{
//	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_NDM;
//    g_MMIComm->m_mmiToSeq.buffer.ndm.nStart = nDivide;
//    g_MMIComm->m_mmiToSeq.buffer.ndm.nEnd = nDivide;
//
//	if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
	{
		g_MMIComm->m_mmiToSeq.buffer.ndm.nStart = nDivide;
		g_MMIComm->m_mmiToSeq.buffer.ndm.nEnd  =nDivide;
		g_MMIComm->m_mmiToSeq.buffer.ndm.nVal[nDivide] = nResponseVal;

		g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_NDM;

		if(g_MMIComm->Send() && g_MMIComm->Recv())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall nWriteCommunicationDM(int nResponseVal,int nDivide)
{
//	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_NDM;
//    g_MMIComm->m_mmiToSeq.buffer.ndm.nStart = nDivide;
//    g_MMIComm->m_mmiToSeq.buffer.ndm.nEnd  = nDivide;
//
//	if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
	{
		g_MMIComm->m_mmiToSeq.buffer.ndm.nStart = nDivide;
		g_MMIComm->m_mmiToSeq.buffer.ndm.nEnd  =nDivide;
		g_MMIComm->m_mmiToSeq.buffer.ndm.nVal[nDivide] = nResponseVal;

		g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_NDM;
		if(g_MMIComm->Send() && g_MMIComm->Recv())
		{

		}
		else
		{
//			MessageDlg("Communication Failure", mtError, TMsgDlgButtons() << mbOK, 0);
		}
	}
}
//---------------------------------------------------------------------------
double __fastcall dReadPkgData(int nPkgno)
{
	double dRtnVal = 0;

	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_PKG;
    g_MMIComm->m_mmiToSeq.buffer.pkg.nStart = nPkgno;
    g_MMIComm->m_mmiToSeq.buffer.pkg.nEnd  = nPkgno;
	if(true == g_MMIComm->Send() && true == g_MMIComm->Recv())
	{
		dRtnVal = g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[nPkgno];
	}
	return dRtnVal;
}
//---------------------------------------------------------------------------
double __fastcall dReadCommunicationDM(int nDMno)
{
	double dRtnVal = 0;

	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_DDM;
    g_MMIComm->m_mmiToSeq.buffer.ddm.nStart = nDMno;
    g_MMIComm->m_mmiToSeq.buffer.ddm.nEnd  = nDMno;
	if(true == g_MMIComm->Send() && true == g_MMIComm->Recv())
	{
		dRtnVal = g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[nDMno];
	}
	return dRtnVal;
}
//---------------------------------------------------------------------------

bool __fastcall dWritePkgData(double dResponseVal,int nDivide)
{
	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_PKG;
    g_MMIComm->m_mmiToSeq.buffer.pkg.nStart = nDivide;
    g_MMIComm->m_mmiToSeq.buffer.pkg.nEnd  = nDivide;

	if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
	{
		g_MMIComm->m_mmiToSeq.buffer.pkg.nStart = nDivide;
		g_MMIComm->m_mmiToSeq.buffer.pkg.nEnd = nDivide;
		g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[nDivide] = dResponseVal;

		g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_PKG;

		if(g_MMIComm->Send() && g_MMIComm->Recv())
		{
        	return true;
		}
		else
		{
            return false;
			//MessageDlg("Communication Failure", mtError, TMsgDlgButtons() << mbOK, 0);
		}
	}
}
//---------------------------------------------------------------------------
bool __fastcall dWriteCommunicationDM(double dResponseVal,int nDivide)
{
	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_DDM;
    g_MMIComm->m_mmiToSeq.buffer.ddm.nStart = nDivide;
    g_MMIComm->m_mmiToSeq.buffer.ddm.nEnd  = nDivide;
	if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
	{
		g_MMIComm->m_mmiToSeq.buffer.ddm.nStart = nDivide;
		g_MMIComm->m_mmiToSeq.buffer.ddm.nEnd  =nDivide;
		g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[nDivide] = dResponseVal;

		g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_DDM;

		if(g_MMIComm->Send() && g_MMIComm->Recv())
		{
        	return true;
		}
		else
		{
        	return false;
//			MessageDlg("Communication Failure", mtError, TMsgDlgButtons() << mbOK, 0);
		}
	}

    return false;
}
//---------------------------------------------------------------------------
AnsiString  DoubleTimeToStringDisplay(double dbdata)
{
    AnsiString RetTime;
    int nAllTime, nTempHour, nTempHourMinute, nTempMinute, nTempSec;

    if(dbdata <= 0)
    {
        return "00:00:00";
    }
    nAllTime = (int)dbdata;
    nTempHour = nAllTime/3600;
    nTempHourMinute = nAllTime%3600;
    nTempMinute = nTempHourMinute/60;
    nTempSec = nTempHourMinute%60;

    if(nTempHour > 0)
    {
		//RetTime = IntToStr(nTempHour)+ ":"+ IntToStr(nTempMinute) +":"+IntToStr(nTempSec);
        RetTime.sprintf("%02d:%02d:%02d", nTempHour,  nTempMinute, nTempSec);
    }
    else
    {
    	//RetTime = IntToStr(nTempMinute) +":"+IntToStr(nTempSec);
        RetTime.sprintf("%02d:%02d", nTempMinute,  nTempSec);
    }
    return RetTime;
}

AnsiString  DoubleTimeToHoursStringDisplay(double dbdata)
{
    AnsiString RetTime, nTempHour, nTempHourMinute, nTempMinute;
    int nAllTime;

    if(dbdata <= 0)
    {
        return "0";
    }
    nAllTime = (int)dbdata;
    nTempHour = nAllTime/3600;
    nTempHourMinute = nAllTime%3600;
    nTempMinute = nTempHourMinute/60;

    RetTime.sprintf("%d", nTempHour*60 + nTempMinute );
    return RetTime;
}
//---------------------------------------------------------------------------

CHAR Str2WideString(String strStuck)
{
	CHAR cStuck[100] = {0, };

	WideCharToMultiByte(0, 0, strStuck.c_str(), -1, cStuck, strStuck.Length(),
		NULL, NULL);

	return cStuck[100];
}

// ---------------------------------------------------------------------------

String _AlarmNameReturn(int nalarmMode , int nalarmCode)
{
	TIniFile *Alarmini;
    if(nalarmCode < 1)
    {
        nalarmCode = 0;
    }


	if(nalarmMode == 1)
    {
    	Alarmini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Alarm.ini");
    }
    else if(nalarmMode == 2)
    {
		Alarmini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Alarm.ini");
    }
    else
    {
		Alarmini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Warning.ini");
    }

	String StrAlarm = Alarmini->ReadString("NAME","NAME"+IntToStr(nalarmCode),"NAME"+IntToStr(nalarmCode));

	delete  Alarmini;

	return StrAlarm;
}
//---------------------------------------------------------------------------

int __fastcall nReadGroupNo() // false 이면 0을 리턴하지 않음
{
	int nRtnVal = nReadCommunicationDM(groupNo);

	if (nRtnVal == 0)
		nRtnVal = 1;

	return nRtnVal;
}

// ---------------------------------------------------------------------------

int __fastcall nReadRecipeNo() // false 이면 0을 리턴하지 않음
{
	int nRtnVal = nReadCommunicationDM(jobNo);

	if (nRtnVal == 0)
		nRtnVal = 1;

	return nRtnVal;
}

// ---------------------------------------------------------------------------
bool _AlarmTypeRet(int nalarmCode)     //false error
{
	TIniFile *Alarmini;

	Alarmini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\Alarm.ini");

	bool bRet =  Alarmini->ReadBool("CHECK","CHECK"+IntToStr(nalarmCode),true);

	delete  Alarmini;

	return bRet;
}
//---------------------------------------------------------------------------
int _AlarmCoodeReturn(bool bType)
{
	int nRetCode = 0;
	if(bType == true)
	{
		g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_ERR_WR;
		if (g_MMIComm->Send() &&  g_MMIComm->Recv())
		{
			nRetCode =  g_MMIComm->m_mmiToSeq.buffer.errWr.err[ 0 ] ;
		}
	}
	else
	{
		g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_ERR_WR;
		if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
		{
			nRetCode =  g_MMIComm->m_mmiToSeq.buffer.errWr.wr[ 0 ] ;
		}
	}

	return nRetCode;
}
//---------------------------------------------------------------------------

int _Shortcut_Return_(int nScreenNo)
{
	TIniFile *pConfigIni = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\ShortCutSet.ini");
	if( pConfigIni == NULL)
	{
		delete pConfigIni;
		return 0;
	}

	int nRet =  pConfigIni->ReadInteger("ShortCut"+IntToStr(nScreenNo),"SetID",0);
	delete pConfigIni;

	return nRet;
}
//---------------------------------------------------------------------------

void __fastcall Status_Led(TPanel *ClonePanel, int clColor, bool bActive, String StrCaption)
{
	if (bActive == true)
    {
		if (clColor == _STATUS_LED_BLACK_) {
			ClonePanel->Color = clBlack;
            ClonePanel->Font->Color = clWhite;
		}
		else if (clColor == _STATUS_LED_RED_) {
			ClonePanel->Color = TColor(clRed * 0.8);
            ClonePanel->Font->Color = clWhite;
		}
		else if (clColor == _STATUS_LED_GREEN_) {
			ClonePanel->Color = clLime;
            ClonePanel->Font->Color = clBlack;
		}
		else if (clColor == _STATUS_LED_BLUE_) {
			ClonePanel->Color = clBlue;
            ClonePanel->Font->Color = clWhite;
		}
		else {
            if( clColor == clRed )
            {
                ClonePanel->Font->Color = clWhite;
            }
            else if( clColor == clLime )
            {
				ClonePanel->Font->Color = clBlack;
            }

            ClonePanel->Color = TColor(clColor);
		}
		ClonePanel->Caption = StrCaption;
	}
	else
    {
		ClonePanel->Color = clGray;
        ClonePanel->Font->Color = clWhite;
		ClonePanel->Caption = StrCaption;
	}
}

// ---------------------------------------------------------------------------
String Get_PKGName(int nIndex)
{
	TIniFile *PKGNameini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\PkgName.ini");

	String strTemp = PKGNameini->ReadString("PKGNAME","NAME"+IntToStr(nIndex),"");
	delete  PKGNameini;
	return strTemp;
}
// ---------------------------------------------------------------------------
String Get_DDMName(int nIndex)
{
	TIniFile *DDMNameini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\DParam.ini");

	String strTemp = DDMNameini->ReadString("DPARM","NAME"+IntToStr(nIndex),"");
	delete  DDMNameini;
	return strTemp;
}
// ---------------------------------------------------------------------------
String Get_NDMName(int nIndex)
{
	TIniFile *NDMNameini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\NParam.ini");

	String strTemp = NDMNameini->ReadString("NPARM","NAME"+IntToStr(nIndex),"");
	delete  NDMNameini;
	return strTemp;
}
// ---------------------------------------------------------------------------

String Get_GroupName()
{
	TIniFile *GroupNameini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\GroupName.ini");

	int nGroupNo = nReadGroupNo();

	if(nGroupNo == 0)
	{
		nGroupNo = 1;
	}

	String strTemp = GroupNameini->ReadString("GROUP","NAME"+IntToStr(nGroupNo),"");
	delete  GroupNameini;
	return strTemp;
}
// ---------------------------------------------------------------------------
String Get_RecipeName()
{
	TIniFile *RecipeNameini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\RecipeName.ini");

	int nGroupNo = nReadGroupNo();
	int nRecipeNo =  nReadRecipeNo();

	if(nGroupNo == 0)
	{
		nGroupNo = 1;
	}

	if(nRecipeNo == 0)
	{
		nRecipeNo = 1;
	}

	String strTemp = RecipeNameini->ReadString("GROUP_"+IntToStr(nGroupNo),"RECIPENAME"+IntToStr(nRecipeNo),"");
	delete  RecipeNameini;
	return strTemp;
}
// ---------------------------------------------------------------------------
String Get_ReadRecipeName(int ngroup , int nrecipe)
{
	TIniFile *RecipeNameini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\RecipeName.ini");

	if(ngroup == 0)
	{
		ngroup = 1;
	}

	if(nrecipe == 0)
	{
		nrecipe = 1;
	}

	String strTemp = RecipeNameini->ReadString("GROUP_"+IntToStr(ngroup),"RECIPENAME"+IntToStr(nrecipe),"");
	delete  RecipeNameini;

	return strTemp;
}
// ---------------------------------------------------------------------------
String GetStringRecipeName(int nGroupNo, int nRecipeNo)
{
	TIniFile *RecipeNameini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\RecipeName.ini");

	String strTemp = RecipeNameini->ReadString("GROUP_"+IntToStr(nGroupNo),"RECIPENAME"+IntToStr(nRecipeNo),"");
	delete  RecipeNameini;
	return strTemp;
}
// ---------------------------------------------------------------------------
bool GetRecipeIndexNO(int &groupNo, int &recipeNo, String sRecipeName)
{
	#define _MAX_GRP_NO_	100
	#define _MAX_RCP_NO_    500

	bool bRtn = false;
	String strTemp = "";
	TMemIniFile *RecipeNameini = new TMemIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\RecipeName.ini");
	for(int iGroup=1; iGroup<=_MAX_GRP_NO_; iGroup++)
	{
		for(int iRecipe=1; iRecipe<=_MAX_RCP_NO_; iRecipe++)
		{
			strTemp = RecipeNameini->ReadString("GROUP_"+IntToStr(iGroup),"RECIPENAME"+IntToStr(iRecipe),"");
			if(sRecipeName == strTemp.Trim())
			{
				groupNo = iGroup;
				recipeNo = iRecipe;
				bRtn = true;
				break;
			}
		}

		if(bRtn)	break;
	}

	delete  RecipeNameini;
	return bRtn;
}
//---------------------------------------------------------------------------
String __fastcall StringBlankMaker(String StrTempData, int nBlankCnt) {
	StrTempData = StrTempData.Trim();
	int nActualCnt = nBlankCnt - StrTempData.Length();

	if (nActualCnt < 0) {
		StrTempData = StrTempData.SubString(1, nBlankCnt);
	}
	else {
		for (int nCnt = 0; nCnt < nActualCnt; nCnt++) {
			StrTempData += " ";
		}
	}
	return StrTempData;
}

// ---------------------------------------------------------------------------
String __fastcall StringSpaceMaker(int nValue, int nCount) {
	String StrRet;
	return StrRet.sprintf(("%0" + IntToStr(nCount) + "d").c_str(), nValue);
}
// ---------------------------------------------------------------------------

int __fastcall MotorAxisHometenkeyNo(int nAxis) {
	TIniFile *pTempIni;
	int nRetNo;
	pTempIni = new TIniFile(ExtractFilePath(Application->ExeName) +
		"\\Ini\\MotorHomeTenkey.ini");
	if (FileExists(ExtractFilePath(Application->ExeName) +
		"\\Ini\\MotorHomeTenkey.ini")) {
		nRetNo = pTempIni->ReadInteger("MtrTenkey",
		"Axis" + IntToStr(nAxis), -1);
	}
	else {
		nRetNo = -1;
	}
	delete pTempIni;
	return nRetNo;
}

// ---------------------------------------------------------------------------

String RemoveChar(String sValue, String cChar)
{
	String Temp = sValue;

	for (int i = 1; i <= sValue.Length(); i++)
	{
		if (Temp.SubString(i,1) == cChar)
		{
			Temp.Delete(i,1);
		}
	}                  
    
	return Temp;   
}

//---------------------------------------------------------------------------    

void DeleteAllFile(String szDir )
{
	WIN32_FIND_DATA FindData;     //검색된 파일속성에 대한 정보를 담습니다 (생성일, 변경일 등등등)

	String sFileName = szDir + "*.*";
	HANDLE hFind = FindFirstFile(sFileName.w_str(), &FindData);
	if(hFind != INVALID_HANDLE_VALUE) //exist no File in Directory
	{
		do
		{
			if (FindData.dwFileAttributes & FILE_ATTRIBUTE_ARCHIVE)
		   {
				 DeleteFile(szDir +(LPCTSTR)FindData.cFileName);
			}

		} while(FindNextFile(hFind, &FindData));

		FindClose(hFind); //close handle
	}
}

//---------------------------------------------------------------------------
                           
void DeleteLogFile(String sDir, String sFilter, int nSetDate )
{
	TDateTime dt = Now() - nSetDate;
	int nDeleteDate = StrToIntDef(dt.FormatString("yyyymmdd"),0);

	WIN32_FIND_DATA FindData;     //검색된 파일속성에 대한 정보를 담습니다 (생성일, 변경일 등등등)
	String sFileName = sDir + sFilter;
	HANDLE hFind = FindFirstFile(sFileName.w_str(), &FindData);
	if(hFind != INVALID_HANDLE_VALUE) //exist File in Directory
	{
		do
		{
			if (FindData.dwFileAttributes & FILE_ATTRIBUTE_ARCHIVE)
		   {
				String sFile = (LPCTSTR)FindData.cFileName;

				int nFindFileDate = StrToIntDef( RemoveChar(sFile, "-").SubString(1, 8),0);

				if (nFindFileDate <= nDeleteDate)
				{
					DeleteFile(sDir +  sFile);
				}
			}

		} while(FindNextFile(hFind, &FindData));

		FindClose(hFind);
	}
}

//---------------------------------------------------------------------------

void DeleteLogDirectory(String sDir, String sFilter, int nSetDate )
{
	TDateTime dt = Now() - nSetDate;
	int nDeleteDate = StrToIntDef(dt.FormatString("yyyymmdd"),0);

	WIN32_FIND_DATA FindData;     //검색된 파일속성에 대한 정보를 담습니다 (생성일, 변경일 등등등)
	String sFileName = sDir + sFilter;

	HANDLE hFind = FindFirstFile(sFileName.w_str(), &FindData);
	if(hFind != INVALID_HANDLE_VALUE) //exist File in Directory
	{
		do
		{
			if (FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		   {
				String sFile = (LPCTSTR)FindData.cFileName;

				if (! (sFile == "." || sFile == "..") )
				{
					int nFindFileDate = StrToIntDef( RemoveChar(sFile, "-").SubString(1, 8),0);

					if (nFindFileDate <= nDeleteDate)
					{
						DeleteAllFile(sDir + sFile + "\\");
						RemoveDir(sDir + sFile);
					}
				}


			}
		} while(FindNextFile(hFind, &FindData));

		FindClose(hFind);
	}

}

//---------------------------------------------------------------------------

void DeleteRecipeDirectory(String sDir, String sFilter)
{
	WIN32_FIND_DATA FindData;     //검색된 파일속성에 대한 정보를 담습니다 (생성일, 변경일 등등등)
	String sFileName = sDir + sFilter;

	HANDLE hFind = FindFirstFile(sFileName.w_str(), &FindData);
	if(hFind != INVALID_HANDLE_VALUE) //exist File in Directory
	{
		do
		{
			if (FindData.dwFileAttributes & FILE_ATTRIBUTE_ARCHIVE)
		   {
				String sFile = (LPCTSTR)FindData.cFileName;

				if (! (sFile == "." || sFile == "..") )
				{
					DeleteFile(sDir + sFile);
				}
			}
		} while(FindNextFile(hFind, &FindData));
		RemoveDir(sDir);

		FindClose(hFind);
	}

}

//---------------------------------------------------------------------------

bool WriteCommDDM(int nNumberIndex , double dResponseVal)
{
    g_MMIComm->m_mmiToSeq.buffer.ddm.nStart = nNumberIndex;
    g_MMIComm->m_mmiToSeq.buffer.ddm.nEnd  =nNumberIndex;
    g_MMIComm->m_mmiToSeq.buffer.ddm.dVal[nNumberIndex] = dResponseVal;

    g_MMIComm->m_mmiToSeq. nCmd = CMD_WR_DDM;

    if(g_MMIComm->Send() && g_MMIComm->Recv())
    {
        return true;
    }
    else
    {
        return false;
    }
}
//---------------------------------------------------------------------------
bool WriteCommNDM(int nNumberIndex , int nResponseVal)
{
    g_MMIComm->m_mmiToSeq.buffer.ndm.nStart = nNumberIndex;
    g_MMIComm->m_mmiToSeq.buffer.ndm.nEnd  =nNumberIndex;
    g_MMIComm->m_mmiToSeq.buffer.ndm.nVal[nNumberIndex] = nResponseVal;

    g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_NDM;

    if(g_MMIComm->Send() && g_MMIComm->Recv())
    {
        return true;
    }
    else
    {
        return false;
    }
}
//---------------------------------------------------------------------------
bool WriteCommPKG(int nNumberIndex , double dResponseVal)
{
    g_MMIComm->m_mmiToSeq.buffer.pkg.nStart = nNumberIndex;
    g_MMIComm->m_mmiToSeq.buffer.pkg.nEnd  =nNumberIndex;
    g_MMIComm->m_mmiToSeq.buffer.pkg.dVal[nNumberIndex] = dResponseVal;

    g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_PKG;

    if(g_MMIComm->Send() && g_MMIComm->Recv())
    {
        return true;
    }
    else
    {
        return false;
    }
}
//---------------------------------------------------------------------------

int __fastcall UseSkipControl(int nNumber)  //해당 USESKIP 의 값을 반전
{
	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_USESKIP;
    g_MMIComm->m_mmiToSeq.buffer.useSkip.nStart = nNumber;
    g_MMIComm->m_mmiToSeq.buffer.useSkip.nEnd  = nNumber;

    if(g_MMIComm->Send() && g_MMIComm->Recv())
    {
		bool bValue = true;
		bool oldValue = g_MMIComm->m_mmiToSeq.buffer.useSkip.nVal[nNumber];
		if(oldValue == true)
        {
			bValue = false;
		}

        g_MMIComm->m_mmiToSeq.buffer.useSkip.nStart 	= nNumber;
        g_MMIComm->m_mmiToSeq.buffer.useSkip.nEnd 	= nNumber;
        g_MMIComm->m_mmiToSeq.buffer.useSkip.nVal[nNumber] = bValue;

        g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_USESKIP;
        if(g_MMIComm->Send() && g_MMIComm->Recv())
        {
    		if(oldValue==false)
				return 1;	// false -> true
			else
				return 2;	// true -> false
		}

		return 0;	//false
	}

	return 0;	//false
}

//---------------------------------------------------------------------------
bool __fastcall UseSkipControl(int nNumber, bool bUse)  //해당 USESKIP 의 값으로 변경
{
	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_USESKIP;
	g_MMIComm->m_mmiToSeq.buffer.useSkip.nStart = nNumber;
	g_MMIComm->m_mmiToSeq.buffer.useSkip.nEnd = nNumber;

	if(g_MMIComm->Send() && g_MMIComm->Recv())
	{
		if(g_MMIComm->m_mmiToSeq.buffer.useSkip.nVal[nNumber] == bUse)
			return false;

		g_MMIComm->m_mmiToSeq.buffer.useSkip.nStart = nNumber;
		g_MMIComm->m_mmiToSeq.buffer.useSkip.nEnd  = nNumber;
		g_MMIComm->m_mmiToSeq.buffer.useSkip.nVal[nNumber] = bUse;

		g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_USESKIP;
		if(g_MMIComm->Send() && g_MMIComm->Recv())
		{
			return true;	//변경이 될때만 true return
		}
		else
		{
			return false;
		}
	}
}

//---------------------------------------------------------------------------

bool __fastcall bReadUseSkip(int nNumber)  //해당 USESKIP 의 값을 return
{
	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_USESKIP;
	g_MMIComm->m_mmiToSeq.buffer.useSkip.nStart = nNumber;
	g_MMIComm->m_mmiToSeq.buffer.useSkip.nEnd  = nNumber;

	if(g_MMIComm->Send() && g_MMIComm->Recv())
	{
		return g_MMIComm->m_mmiToSeq.buffer.useSkip.nVal[nNumber];
	}
	return false;
}
//---------------------------------------------------------------------------

bool __fastcall CheckAccessLevel( int nLevel, String component_caption )
{
    if( nLevel == 3/*PW_SUPER*/ )
    {
        return true;
    }

    String szUserName = "";
    switch ( nLevel )
    {
        case 0://PW_OPERATOR:
            szUserName = "Operator";
            break;
        case 1://PW_MAINTENANCE:
            szUserName = "Maintenance";
            break;
        case 2://PW_ENGINEER:
            szUserName = "Engineer";
            break;
        case 3://PW_SUPER:
            szUserName = "Super"; 
            break;
    } 

	String path = ExtractFilePath( Application->ExeName ) + "ini\\AccessConfig.ini";
    TIniFile* pIni = new TIniFile( path );      
    bool bChecked = pIni->ReadBool( szUserName, component_caption, true  );
    delete pIni;

    return bChecked;
}

//---------------------------------------------------------------------------  

String GetLastFilePath()
{  
    // 가장 최근에 열었던 파일 열기.
    String path = ExtractFilePath( Application->ExeName ) + "INI\\Setup.ini";
	TIniFile* pIni = new TIniFile( path );

    // ini의 설정에 따라서 ex파일, xml파일을 DB/Glass/PKG 폴더에서 관리할 것인지
    // 아니면 실제 dxf파일을 열었던 경로에 저장할 것인지 설정 합니다.
    int nRecipeManageType = pIni->ReadInteger( "RECIPE MANAGE TYPE", "TYPE", 0 );

    String szLastFilePath = "";
    
    if( nRecipeManageType == 0 ) 
    {
        // recipe 폴더에 저장된 ex파일 열기.
        // DB/Glass/PKG 폴더 경로.
        szLastFilePath = Get_RecipeName();
        pIni->WriteInteger( "RECIPE MANAGE TYPE", "TYPE", 0 );
    }
    else
    {
        // 가장 최근에 열었던 파일 열기.
        // dxf파일을 열었던 폴더 경로.
        szLastFilePath = pIni->ReadString( "LAST OPEN FILE", "PATH", "" );
        pIni->WriteInteger( "RECIPE MANAGE TYPE", "TYPE", 1 );
    }

    delete pIni;
    
    return szLastFilePath;
}

//--------------------------------------------------------------------------- 

void SetLastFilePath( String szFilePath_No_Extension )
{
	String path = ExtractFilePath( Application->ExeName ) + "INI\\Setup.ini";
	TIniFile* pIni = new TIniFile( path );

    // 가장 최근에 열었던 파일 경로 저장.
    pIni->WriteString( "LAST OPEN FILE", "PATH", szFilePath_No_Extension );

    delete pIni;
}

//--------------------------------------------------------------------------- 

String getFileExtension (const TCHAR* lpszFileName)
{
    try
	{
        String szFullPath = String( lpszFileName );

		String szExtension = szFullPath.SubString( szFullPath.LastDelimiter( "." ) + 1, szFullPath.Length() );

        return szExtension;
    }
	catch( ... )
	{
		MessageBox( Application->Handle, lpszFileName, _T( "viewled getFileExtension func Exception" ), 0 );
	}

	return "";
}

//---------------------------------------------------------------------------

String CharReplaceAll(String str, const String sOldPettern, const String sNewPettern)
{
	for (int i = 1; i <= sOldPettern.Length(); i++)
	{
		String s = sOldPettern[i];
		str = StringReplace(str, sOldPettern[i], sNewPettern, Sysutils::TReplaceFlags() << Sysutils::rfReplaceAll);
	}

	return str;


}

int GetLangTag()
{
	String szPath = ExtractFilePath( Application->ExeName ) + "\\Ini\\Setup.ini";
	TIniFile *pIni = new TIniFile( szPath );

	int nLangIdx = pIni->ReadInteger( "LANGUAGE", "LANGUAGE", 0 );

	delete pIni;

	return nLangIdx;
}

float ChangeAngle(float orgAngle, float newAngle)
{
	float dAngle = orgAngle - newAngle;

	return ( dAngle >= 0 ? dAngle: dAngle + 360 );
}
//---------------------------------------------------------------------------
bool	CheckCanAccessLevel(_LEVEL_ reqLevel)
{
	if(frmLogin->getLevel() < reqLevel)
    {
        frmLogin->SetTryLevel(reqLevel);
        frmLogin->ShowModal();
        //FrmApha->AlphaShowModal(frmLogin);

        if(frmLogin->getLevel() >= reqLevel) return true;
        else   return false;
    }
    else return true;
}

bool	CheckCanAccessLevelOnce(_LEVEL_ reqLevel)	//확인 후 현재 레벨로 복귀
{
	_LEVEL_ _currentLevel = frmLogin->getLevel();
	if(_currentLevel < reqLevel)
	{
		frmLogin->SetTryLevel(reqLevel);
		frmLogin->ShowModal();

		if(frmLogin->getLevel() >= reqLevel) {
			frmLogin->changeLevel(_currentLevel);
			return true;
		}
		else {
			frmLogin->changeLevel(_currentLevel);
			return false;
		}
	}
	else return true;
}

bool	CheckCanAccessLevelMust(_LEVEL_ reqLevel)	// 무조건 확인 후 현재 레벨로 복귀
{
	_LEVEL_ _currentLevel = frmLogin->getLevel();
	frmLogin->SetTryLevel(reqLevel);

	bool bRtn = false;
	if(frmLogin->ShowModal() == mrOk) {
		if(frmLogin->getLevel() >= reqLevel) {
			bRtn = true;
		}
	}

	if(frmLogin->getKeepPwd() == true)
	{
		frmLogin->setKeepPwd(false);
		frmLogin->changeLevel(PW_SUPER);
		frmLogin->setKeepPwd(true);
	}
	else
		frmLogin->changeLevel(_currentLevel);

	return bRtn;
}
//---------------------------------------------------------------------------
enum RUNNINGSTATUS
{
//	STATUS_STOP             	= 0,
//	STATUS_RUN					= 1,
//	STATUS_ERROR				= 2,
//	STATUS_WARNING				= 3,
//	STATUS_EMG					= 4,

	STATUS_STOP             	= 0,
	STATUS_AUTO					= 1,
	STATUS_ERROR				= 2,
	STATUS_RUN					= 3,   	// cycle run
	STATUS_EMG					= 4,
	STATUS_RUNDOWN				= 5
};

bool   CheckCanDataAccess()
{
	RUNNINGSTATUS curStatus = nReadCommunicationDM( mcState );

	if(curStatus == STATUS_RUN || curStatus == STATUS_AUTO || curStatus == STATUS_RUNDOWN)
    {
    	FrmCdBox->setFlag(CD_OK);
        FrmCdBox->setTitle("Machine is running now.");
        FrmCdBox->setText("Can not this operating now.");
        FrmCdBox->ShowModal();
        return false;
    }
	else return true;
}
//---------------------------------------------------------------------------
bool ReadLotInfoData(COMCMD cmd, LOT_INFO &data)
{
	g_MMIComm->m_mmiToSeq.nCmd = cmd;
	if (g_MMIComm->Send() && g_MMIComm->Recv())
	{
		data = g_MMIComm->m_mmiToSeq.buffer.lotInfo;
		return true;
    }
	else return false;
}
//---------------------------------------------------------------------------

bool	 WriteLotInfoData(COMCMD cmd, LOT_INFO data)
{
	g_MMIComm->m_mmiToSeq.nCmd = cmd;
	if (g_MMIComm->Send() && g_MMIComm->Recv())
	{
		g_MMIComm->m_mmiToSeq.nCmd = cmd;
		g_MMIComm->m_mmiToSeq.buffer.lotInfo = data;
        if (g_MMIComm->Send() && g_MMIComm->Recv())
        {
            return true;
        }
    }
    else return false;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
String ReadStringFromRootInifile(String fileName, String section, String ident)
{
	String root = ExtractFilePath(Application->ExeName)+ "ini\\";
	TIniFile* ini = new TIniFile(root+fileName);
    String r = ini->ReadString(section, ident, "");
    delete ini;

    return r;
}
//---------------------------------------------------------------------------
double ReadFloatFromRootInifile(String fileName, String section, String ident)
{
	String root = ExtractFilePath(Application->ExeName)+ "ini\\";
	TIniFile* ini = new TIniFile(root+fileName);
    double r = ini->ReadFloat(section, ident, 0.0);
    delete ini;

    return r;
}
//---------------------------------------------------------------------------
int ReadIntegerFromRootInifile(String fileName, String section, String ident)
{
	String root = ExtractFilePath(Application->ExeName)+ "ini\\";
	TIniFile* ini = new TIniFile(root+fileName);
    int r = ini->ReadInteger(section, ident, 0);
    delete ini;

    return r;
}
//---------------------------------------------------------------------------
void WriteStringToRootInifile(String fileName, String section, String ident, String value)
{
	String root = ExtractFilePath(Application->ExeName)+ "ini\\";
	TIniFile* ini = new TIniFile(root+fileName);
    ini->WriteString(section, ident, value);
    delete ini;
}
//---------------------------------------------------------------------------
void WriteFloatToRootInifile(String fileName, String section, String ident, double value)
{
	String root = ExtractFilePath(Application->ExeName)+ "ini\\";
	TIniFile* ini = new TIniFile(root+fileName);
	ini->WriteFloat(section, ident, value);
    delete ini;
}
//---------------------------------------------------------------------------
void WriteIntegerToRootInifile(String fileName, String section, String ident, int value)
{
	String root = ExtractFilePath(Application->ExeName)+ "ini\\";
	TIniFile* ini = new TIniFile(root+fileName);
    ini->WriteInteger(section, ident, value);
    delete ini;
}

//---------------------------------------------------------------------------
String ReadStringFromRecipeInifile(String fileName, String section, String ident)
{

	int nGroupNo = nReadGroupNo();
	int nRecipeNo =  nReadRecipeNo();

	String recipe = "GRP" + IntToStr(nGroupNo) + "\\RCP" + IntToStr(nRecipeNo) + "\\";

	String root = ExtractFilePath(Application->ExeName)+ "ini\\system\\" + recipe;
	TIniFile* ini = new TIniFile(root+fileName);
    String r = ini->ReadString(section, ident, "");
    delete ini;

    return r;
}
//---------------------------------------------------------------------------
double ReadFloatFromRecipeInifile(String fileName, String section, String ident)
{
	int nGroupNo = nReadGroupNo();
	int nRecipeNo =  nReadRecipeNo();

	String recipe = "GRP" + IntToStr(nGroupNo) + "\\RCP" + IntToStr(nRecipeNo) + "\\";

	String root = ExtractFilePath(Application->ExeName)+ "ini\\system\\" + recipe;
	TIniFile* ini = new TIniFile(root+fileName);
    double r = ini->ReadFloat(section, ident, 0.0);
    delete ini;

    return r;
}
//---------------------------------------------------------------------------
double ReadPkgDataRecipeInifile(int nGroup, int  nRecipe , int TrgNo )
{
	String recipe = "GRP" + IntToStr(nGroup) + "\\RCP" + IntToStr(nRecipe) + "\\";

	String root = ExtractFilePath(Application->ExeName)+ "ini\\system\\" + recipe + "PkgParam.ini";

    TIniFile* ini = new TIniFile(root );

    String  r = ini->ReadString("PKGPARM", "VALUE"+ IntToStr(TrgNo), "0");
    delete ini;

	return StrToFloat(r);



}
//---------------------------------------------------------------------------
int ReadIntegerFromRecipeInifile(String fileName, String section, String ident)
{
	int nGroupNo = nReadGroupNo();
	int nRecipeNo =  nReadRecipeNo();

	String recipe = "GRP" + IntToStr(nGroupNo) + "\\RCP" + IntToStr(nRecipeNo) + "\\";

	String root = ExtractFilePath(Application->ExeName)+ "ini\\system\\" + recipe;
	TIniFile* ini = new TIniFile(root+fileName);
    int r = ini->ReadInteger(section, ident, 0);
    delete ini;

    return r;
}
//---------------------------------------------------------------------------
void WriteStringToRecipeInifile(String fileName, String section, String ident, String value)
{
	int nGroupNo = nReadGroupNo();
	int nRecipeNo =  nReadRecipeNo();

	String recipe = "GRP" + IntToStr(nGroupNo) + "\\RCP" + IntToStr(nRecipeNo) + "\\";

	String root = ExtractFilePath(Application->ExeName)+ "ini\\system\\" + recipe;
	TIniFile* ini = new TIniFile(root+fileName);
    ini->WriteString(section, ident, value);
    delete ini;
}
//---------------------------------------------------------------------------
void WriteFloatToRecipeInifile(String fileName, String section, String ident, double value)
{
	int nGroupNo = nReadGroupNo();
	int nRecipeNo =  nReadRecipeNo();

	String recipe = "GRP" + IntToStr(nGroupNo) + "\\RCP" + IntToStr(nRecipeNo) + "\\";

	String root = ExtractFilePath(Application->ExeName)+ "ini\\system\\" + recipe;
	TIniFile* ini = new TIniFile(root+fileName);
	ini->WriteFloat(section, ident, value);
    delete ini;
}
//---------------------------------------------------------------------------
void WriteIntegerToRecipeInifile(String fileName, String section, String ident, int value)
{
	int nGroupNo = nReadGroupNo();
	int nRecipeNo =  nReadRecipeNo();

	String recipe = "GRP" + IntToStr(nGroupNo) + "\\RCP" + IntToStr(nRecipeNo) + "\\";

	String root = ExtractFilePath(Application->ExeName)+ "ini\\system\\" + recipe;
	TIniFile* ini = new TIniFile(root+fileName);
	ini->WriteInteger(section, ident, value);
	delete ini;
}
//---------------------------------------------------------------------------
void WriteFloatPkgParamInifile(double value, int index)
{
	int nGroupNo = nReadGroupNo();
	int nRecipeNo =  nReadRecipeNo();

	String recipe = "GRP" + IntToStr(nGroupNo) + "\\RCP" + IntToStr(nRecipeNo) + "\\";
	String root = ExtractFilePath(Application->ExeName)+ "ini\\system\\" + recipe;

	TIniFile* ini = new TIniFile(root+"PkgParam.ini");
	ini->WriteFloat("PKGPARM", "VALUE"+IntToStr(index), value);
	delete ini;
}
//---------------------------------------------------------------------------
void	MainLog(String str)
{
	MainForm->MachineHistoryData(str);
}
//---------------------------------------------------------------------------
void 	LoadToCSVFile(TStringGrid *sGrid,String sCSVFile)
{
	if(!FileExists(sCSVFile))
		return;

	TStringList *sLst = new TStringList;
	TStringList *sCols = new TStringList;
	try
	{
		sLst->LoadFromFile(sCSVFile);
		sGrid->RowCount = sLst->Count;
		for(int i=0;i< sLst->Count ; i++)
		{
			sCols->CommaText = sLst->Strings[i];
			if( sCols->Count > sGrid->ColCount)
			{
				sGrid->ColCount = sCols->Count;
			}
			sGrid->Rows[i]->Assign(sCols);
		}
		sLst->SaveToFile(sCSVFile);
	}
	__finally
	{
		delete sLst;
		delete sCols;
	}
}
//---------------------------------------------------------------------------
void 	SaveToCSVFile(TStringGrid *sGrid,String sCSVFile)
{
	TStringList *sLst = new TStringList;
	try
	{
		for(int i=0;i< sGrid->RowCount ; i++)
		{
			sLst->Add( sGrid->Rows[i]->CommaText );
		}
		sLst->SaveToFile(sCSVFile);
	}
	__finally
	{
		delete sLst;
	}
}
//---------------------------------------------------------------------------
bool __fastcall bReadMsgNotice(MsgNotice *p)
{
	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_MSGNOTICE;
	if(g_MMIComm->Send() && g_MMIComm->Recv())
	{
		memcpy(p,&g_MMIComm->m_mmiToSeq.buffer.msg,sizeof(MsgNotice));
		return true;
	}
	return false;
}
//SEQ <-> MMI COMM CHECK
//---------------------------------------------------------------------------
bool __fastcall bReadIO(CommReadIO *p)
{
	Monitor m(&g_MMIComm->comm_cs);
	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_IO;
	if(g_MMIComm->Send() && g_MMIComm->Recv())
	{
		memcpy(p,&g_MMIComm->m_mmiToSeq.buffer.rdIO,sizeof(CommReadIO));
		return true;
	}
	return false;
}
//---------------------------------------------------------------------------
bool __fastcall bWriteIO(CommWriteIO *p)
{
	Monitor m(&g_MMIComm->comm_cs);
	g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_IO;
	memcpy(&g_MMIComm->m_mmiToSeq.buffer.wrIO,p,sizeof(CommWriteIO));
	if(g_MMIComm->Send() && g_MMIComm->Recv())
	{
		return true;
	}
	return false;
}
//---------------------------------------------------------------------------
bool __fastcall bWriteIO(int idx,bool set)
{

    CommWriteIO wrIO;
    wrIO.nIONo = idx;
    wrIO.bOn = set;
	return  bWriteIO(&wrIO);
}

//---------------------------------------------------------------------------
bool __fastcall bWriteIO(int ch,int idx,bool set)
{
	return  bWriteIO(ch*100+idx,set);
}

//---------------------------------------------------------------------------
#endif
