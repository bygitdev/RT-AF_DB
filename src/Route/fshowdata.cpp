//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fshowdata.h"
#include "BaseComm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrmShowData *FrmShowData;
#define	COLUNM_COUNT	15
#define PKG_ROW_COUNT	1000
#define MAX_PATH_CNT	100
#define PKG_COUNT  26

String pkg_names[PKG_COUNT] = {
	"COUNT X",
	"COUNT Y",
	"PITCH X",
	"PITCH Y",
	"PATH COUNT",
	"PRS MARK1 X",
	"PRS MARK1 Y",
	"PRS MARK2 X",
	"PRS MARK2 Y",
	"PRS MARK3 X",

	"PRS MARK3 Y",
	"PRS MARK4 X",
	"PRS MARK4 Y",
	"PRS UNIT1 X",
	"PRS UNIT1 Y",
	"PRS UNIT2 X",
	"PRS UNIT2 Y",
	"QC COUNT",
	"QC POINT1 X",
	"QC POINT1 y",

	"QC POINT2 X",
	"QC POINT2 Y",
	"QC POINT3 X",
	"QC POINT3 Y",
	"QC POINT4 X",
	"QC POINT4 Y"
};

String ini_value[PKG_COUNT] = {
	"COUNT_X",
	"COUNT_Y",
	"PITCH_X",
	"PITCH_Y",
	"PATH_COUNT",
	"PRS_MARK1_X",
	"PRS_MARK1_Y",
	"PRS_MARK2_X",
	"PRS_MARK2_Y",
	"PRS_MARK3_X",
	"PRS_MARK3_Y",

	"PRS_MARK4_X",
	"PRS_MARK4_Y",
	"PRS_UNIT1_X",
	"PRS_UNIT1_Y",
	"PRS_UNIT2_X",
	"PRS_UNIT2_Y",
	"QC COUNT",
	"QC_POINT1_X",
	"QC_POINT1_y",

	"QC_POINT2_X",
	"QC_POINT2_Y",
	"QC_POINT3_X",
	"QC_POINT3_Y",
	"QC_POINT4_X",
	"QC_POINT4_Y"
};

String PATH_PRM[COLUNM_COUNT] = {	"_TYPE", "_START_X", "_START_Y", "_END_X", "_END_Y",
								"_MID1_X" , "_MID1_Y", "_MID2_X" ,	"_MID2_Y", "_MID3_X",
								"_MID3_Y", "_MID4_X" , "_MID4_Y",  "_ARC_X", "_ARC_Y"};



//---------------------------------------------------------------------------
__fastcall TFrmShowData::TFrmShowData(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TFrmShowData::FormDestroy(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
void	TFrmShowData::print_statusbar(String text)
{
	StatusBar1->Panels->Items[0]->Text = text;
	StatusBar1->Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TFrmShowData::FormCreate(TObject *Sender)
{

	TStringGrid* sg[5] = { StringGrid_path, StringGrid_offset1, StringGrid_offset2, StringGrid_offset3, StringGrid_offset4 };

	String Collabel[COLUNM_COUNT] = {	"TYPE", "START X", "START Y", "END X", "END Y",
								"MID1 X" , "MID1 Y", "MID2 X" ,	"MID2 Y", "MID3 X",
								"MID3 Y", "MID4 X" , "MID4 Y",  "ARC X", "ARC Y"};

	for(int s=0; s < 5; s++)
	{
		sg[s]->ColCount = COLUNM_COUNT + 1;
		sg[s]->Cells[0][0] = "No.";

		for(int i=1; i < COLUNM_COUNT+1; i++)
		{
			sg[s]->Cells[i][0] = Collabel[i-1];
		}
	}

}
//---------------------------------------------------------------------------
void __fastcall TFrmShowData::FormShow(TObject *Sender)
{
	this->read_pkg_data_ini();
	this->read_origin_path_data_ini();
	this->read_offset_data_ini();
}
//---------------------------------------------------------------------------

void	TFrmShowData::read_pkg_data_ini()
{
	this->print_statusbar("Read package data from DB");

	int group = nReadGroupNo();
	int recipe = nReadRecipeNo();

	TIniFile* orgData = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\ini\\system\\GRP"+IntToStr(group)+"\\RCP"+IntToStr(recipe)+"\\exportData.ini");


	for(int i=0; i < PKG_COUNT; i++)
	{
		ValueListEditorPkg->Values[pkg_names[i]] = FloatToStr(orgData->ReadFloat("PATH_ARRAY_INFO",ini_value[i],0));
		//orgData->WriteString("PATH_ARRAY_INFO",ini_value[i],"0"); // 처음 파일 만들때 사용
	}

	delete orgData;

	this->print_statusbar("");
}
//---------------------------------------------------------------------------
void	TFrmShowData::read_origin_path_data_ini()
{
	this->print_statusbar("Read path data from DB");

	int group = nReadGroupNo();
	int recipe = nReadRecipeNo();

	int xCnt = ValueListEditorPkg->Values["COUNT X"].ToInt();
	int yCnt = ValueListEditorPkg->Values["COUNT Y"].ToInt();
	int pCnt = ValueListEditorPkg->Values["PATH COUNT"].ToInt();

	double xPitch = ValueListEditorPkg->Values["PITCH X"].ToDouble();
	double yPitch = ValueListEditorPkg->Values["PITCH Y"].ToDouble();

	int tPathCnt = xCnt * yCnt * pCnt;

	StringGrid_path->RowCount = tPathCnt+1;

	TIniFile* orgData = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\ini\\system\\GRP"+IntToStr(group)+"\\RCP"+IntToStr(recipe)+"\\exportData.ini");

	for(int y=0; y < yCnt; y++)
	{
		for(int x=0; x < xCnt; x++)
		{
			for(int p=0; p < pCnt; p++)
			{
				int i = p + (x*pCnt) + y*(xCnt*pCnt);

				StringGrid_path->Cells[0][i+1] = IntToStr(i+1);

				for(int c=1; c < COLUNM_COUNT+1; c++)
				{
					double value = orgData->ReadFloat("PATH_DATA","PATH_"+IntToStr(p)+PATH_PRM[c-1],0);

					if(c%2 == 0) value = value + xPitch*x;
					else if(c != 1) value = value + y*yPitch;

					if(c==1) StringGrid_path->Cells[c][i+1] = IntToStr((int)value);
					StringGrid_path->Cells[c][i+1] = FloatToStr(value);
				}
			}
		}
	}
	delete orgData;
	this->print_statusbar("");

}
//---------------------------------------------------------------------------
void	TFrmShowData::read_offset_data_ini()
{
	this->print_statusbar("Read offset data from DB");

	int group = nReadGroupNo();
	int recipe = nReadRecipeNo();

	TStringGrid* sg[4] = { StringGrid_offset1, StringGrid_offset2, StringGrid_offset3, StringGrid_offset4 };

	for(int i=0; i < 4; i++)
	{
		TIniFile* offset  = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\ini\\system\\GRP"+IntToStr(group)+"\\RCP"+IntToStr(recipe)+"\\offsetData"+IntToStr(i)+".ini");

		for(int r = 0; r < MAX_PATH_CNT; r++)
		{
			sg[i]->Cells[0][r+1] = IntToStr(r+1);
			for(int c=1; c < COLUNM_COUNT+1; c++)
			{
				sg[i]->Cells[c][r+1] = offset->ReadString("PATH_"+IntToStr(r),"VALUE"+IntToStr(c-1),"0");
            }
		}
		delete offset;
	}
	this->print_statusbar("");
}
//---------------------------------------------------------------------------
void	TFrmShowData::save_offset_data_ini()
{
	this->print_statusbar("Save offset data to DB");

	int group = nReadGroupNo();
	int recipe = nReadRecipeNo();

	TStringGrid* sg[4] = { StringGrid_offset1, StringGrid_offset2, StringGrid_offset3, StringGrid_offset4 };

	for(int i=0; i < 4; i++)
	{
		TIniFile* offset  = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\ini\\system\\GRP"+IntToStr(group)+"\\RCP"+IntToStr(recipe)+"\\offsetData"+IntToStr(i)+".ini");


		for(int r = 0; r < MAX_PATH_CNT; r++)
		{
			sg[i]->Cells[0][r+1] = IntToStr(r+1);
			for(int c=1; c < COLUNM_COUNT+1; c++)
			{
				offset->WriteString("PATH_"+IntToStr(r),"VALUE"+IntToStr(c-1),sg[i]->Cells[c][r+1]);
			}
		}
		delete offset;
	}
	this->print_statusbar("");
}
//---------------------------------------------------------------------------
void	TFrmShowData::write_pkg_data_seq()
{
	this->print_statusbar("Save package data to DB");
	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_GERBER_PARA;
	if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
	{
		g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[unitXCnt] = ValueListEditorPkg->Values["COUNT X"].ToDouble();
		g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[unitYCnt] = ValueListEditorPkg->Values["COUNT Y"].ToDouble();
		g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[unitXPitch] = ValueListEditorPkg->Values["PITCH X"].ToDouble();
		g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[unitYPitch] = ValueListEditorPkg->Values["PITCH Y"].ToDouble();
		g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[unitPathCnt] = ValueListEditorPkg->Values["PATH COUNT"].ToDouble();
		g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[unitQcCnt] = ValueListEditorPkg->Values["QC COUNT"].ToDouble();

		g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[prsBlockPos] = ValueListEditorPkg->Values["PRS MARK1 X"].ToDouble();
		g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[prsBlockPos+1] = ValueListEditorPkg->Values["PRS MARK1 Y"].ToDouble();
		g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[prsBlockPos+2] = ValueListEditorPkg->Values["PRS MARK2 X"].ToDouble();
		g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[prsBlockPos+3] = ValueListEditorPkg->Values["PRS MARK2 Y"].ToDouble();
		g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[prsBlockPos+4] = ValueListEditorPkg->Values["PRS MARK3 X"].ToDouble();
		g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[prsBlockPos+5] = ValueListEditorPkg->Values["PRS MARK3 Y"].ToDouble();
		g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[prsBlockPos+6] = ValueListEditorPkg->Values["PRS MARK4 X"].ToDouble();
		g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[prsBlockPos+7] = ValueListEditorPkg->Values["PRS MARK4 Y"].ToDouble();

		g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[prsUnitPos] = ValueListEditorPkg->Values["PRS UNIT1 X"].ToDouble();
		g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[prsUnitPos+1] = ValueListEditorPkg->Values["PRS UNIT1 Y"].ToDouble();
		g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[prsUnitPos+2] = ValueListEditorPkg->Values["PRS UNIT2 X"].ToDouble();
		g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[prsUnitPos+3] = ValueListEditorPkg->Values["PRS UNIT2 Y"].ToDouble();

		g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[qcPos] = ValueListEditorPkg->Values["QC POINT1 X"].ToDouble();
		g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[qcPos+1] = ValueListEditorPkg->Values["QC POINT1 Y"].ToDouble();
		g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[qcPos+2] = ValueListEditorPkg->Values["QC POINT2 X"].ToDouble();
		g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[qcPos+3] = ValueListEditorPkg->Values["QC POINT2 Y"].ToDouble();
		g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[qcPos+4] = ValueListEditorPkg->Values["QC POINT3 X"].ToDouble();
		g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[qcPos+5] = ValueListEditorPkg->Values["QC POINT3 Y"].ToDouble();
		g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[qcPos+6] = ValueListEditorPkg->Values["QC POINT4 X"].ToDouble();
		g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[qcPos+7] = ValueListEditorPkg->Values["QC POINT4 Y"].ToDouble();

		g_MMIComm->m_mmiToSeq.buffer.gerberPara.nStart = unitXCnt;
		g_MMIComm->m_mmiToSeq.buffer.gerberPara.nEnd  = qcPos+7;
		g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_GERBER_PARA;

		if(!g_MMIComm->Send() || !g_MMIComm->Recv())
		{
			MessageDlg("Communication Failure", mtError, TMsgDlgButtons() << mbOK, 0);
		}
	}
	this->print_statusbar("");
}
//---------------------------------------------------------------------------
void	TFrmShowData::write_offset_data_seq()
{
	this->print_statusbar("Save offset data to SEQ");
	TStringGrid* sg[4] = { StringGrid_offset1, StringGrid_offset2, StringGrid_offset3, StringGrid_offset4 };

	for(int i=0; i < 4; i++)
	{

		g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_GERBER_DATA;

		if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
		{
			for(int r=0; r < MAX_PATH_CNT; r++)
			{
				if(r < sg[i]->RowCount-1)
				{
					GERBER gerberData =
					{
						sg[i]->Cells[1][r+1].ToDouble(),
						sg[i]->Cells[2][r+1].ToDouble(),
						sg[i]->Cells[3][r+1].ToDouble(),
						sg[i]->Cells[4][r+1].ToDouble(),
						sg[i]->Cells[5][r+1].ToDouble(),
						sg[i]->Cells[6][r+1].ToDouble(),
						sg[i]->Cells[7][r+1].ToDouble(),
						sg[i]->Cells[8][r+1].ToDouble(),
						sg[i]->Cells[9][r+1].ToDouble(),
						sg[i]->Cells[10][r+1].ToDouble(),
						sg[i]->Cells[11][r+1].ToDouble(),
						sg[i]->Cells[12][r+1].ToDouble(),
						sg[i]->Cells[13][r+1].ToDouble(),
						sg[i]->Cells[14][r+1].ToDouble(),
						sg[i]->Cells[15][r+1].ToDouble(),
						0,
						0,
						0,
						0,
						0
					};

					g_MMIComm->m_mmiToSeq.buffer.gerberData.data[(i+1)*100 + r] = gerberData;
				}
				else
				{
					GERBER gerberData = {0,};
					g_MMIComm->m_mmiToSeq.buffer.gerberData.data[(i+1)*100 + r] = gerberData;
				}
			}

			g_MMIComm->m_mmiToSeq.buffer.gerberData.nStart = (i+1)*100;
			g_MMIComm->m_mmiToSeq.buffer.gerberData.nEnd  = (i+1)*100 + MAX_PATH_CNT-1;
			g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_GERBER_DATA;

			if(!g_MMIComm->Send() || !g_MMIComm->Recv())
			{
				MessageDlg("Communication Failure", mtError, TMsgDlgButtons() << mbOK, 0);
			}
		}
	}
	this->print_statusbar("");
}
//---------------------------------------------------------------------------
void	TFrmShowData::write_origin_path_data_seq()
{
	this->print_statusbar("Write path data to seq");
	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_GERBER_DATA;

	if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
	{
		for(int r=0; r < MAX_PATH_CNT; r++)
		{
			if(r < StringGrid_path->RowCount-1)
			{
				GERBER gerberData =
				{
					StringGrid_path->Cells[1][r+1].ToDouble(),
					StringGrid_path->Cells[2][r+1].ToDouble(),
					StringGrid_path->Cells[3][r+1].ToDouble(),
					StringGrid_path->Cells[4][r+1].ToDouble(),
					StringGrid_path->Cells[5][r+1].ToDouble(),
					StringGrid_path->Cells[6][r+1].ToDouble(),
					StringGrid_path->Cells[7][r+1].ToDouble(),
					StringGrid_path->Cells[8][r+1].ToDouble(),
					StringGrid_path->Cells[9][r+1].ToDouble(),
					StringGrid_path->Cells[10][r+1].ToDouble(),
					StringGrid_path->Cells[11][r+1].ToDouble(),
					StringGrid_path->Cells[12][r+1].ToDouble(),
					StringGrid_path->Cells[13][r+1].ToDouble(),
					StringGrid_path->Cells[14][r+1].ToDouble(),
					StringGrid_path->Cells[15][r+1].ToDouble(),
					0,
					0,
					0,
					0,
					0
				};

				g_MMIComm->m_mmiToSeq.buffer.gerberData.data[r] = gerberData;
			}
			else
			{
				GERBER gerberData = {0,};
				g_MMIComm->m_mmiToSeq.buffer.gerberData.data[r] = gerberData;
			}
		}

		g_MMIComm->m_mmiToSeq.buffer.gerberData.nStart = 0;
		g_MMIComm->m_mmiToSeq.buffer.gerberData.nEnd  = MAX_PATH_CNT - 1;
		g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_GERBER_DATA;

		if(!g_MMIComm->Send() || !g_MMIComm->Recv())
		{
			MessageDlg("Communication Failure", mtError, TMsgDlgButtons() << mbOK, 0);
		}
	}
	this->print_statusbar("");
}
//---------------------------------------------------------------------------
void	TFrmShowData::save_exportData_ini()
{
	this->print_statusbar("Save export data to DB");

	int group = nReadGroupNo();
	int recipe = nReadRecipeNo();

	TIniFile* orgData = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\ini\\system\\GRP"+IntToStr(group)+"\\RCP"+IntToStr(recipe)+"\\exportData.ini");

	for(int i=0; i < PKG_COUNT; i++)
	{
		orgData->WriteString("PATH_ARRAY_INFO",ini_value[i],ValueListEditorPkg->Values[pkg_names[i]]);
	}

	int pathCnt = ValueListEditorPkg->Values["PATH COUNT"].ToInt();

	for(int i=0; i < pathCnt; i++)
	{
		for(int c=1; c < COLUNM_COUNT+1; c++)
		{
			orgData->WriteString("PATH_DATA","PATH_"+IntToStr(i)+PATH_PRM[c-1],StringGrid_path->Cells[c][i+1]);
		}
	}

	delete orgData;
	this->print_statusbar("");
}
//---------------------------------------------------------------------------
void __fastcall TFrmShowData::StringGridSelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect)
{

	if(ARow > 0)
	{
		EditIndex->Text = ARow;

		if(ACol > 1)
		{
			String lb[7] = { "START", "END", "MID1", "MID2", "MID3", "MID4", "ARC" };
			PanelPos->Tag = (ACol-2)/2;
			PanelPos->Caption = lb[PanelPos->Tag];
		}
	}
}
//---------------------------------------------------------------------------


void __fastcall TFrmShowData::ButtonInputClick(TObject *Sender)
{
	if(!frmMain->CanDataAccess())
	{
		FrmCdBox->setFlag(CD_OK);
		FrmCdBox->setTitle("Machine Run");
		FrmCdBox->setText("Machine Run");
		FrmCdBox->BringToFront();
		FrmCdBox->ShowModal();
		return;
	}

	TStringGrid* sg[5] = { StringGrid_path, StringGrid_offset1, StringGrid_offset2, StringGrid_offset3, StringGrid_offset4 };

	for(int s=0; s < 5; s++)
	{
		sg[s]->Options<<goEditing;
	}

	ValueListEditorPkg->Options<<goEditing;

	ButtonSave->Enabled = true;
	ButtonInput->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TFrmShowData::ButtonSaveClick(TObject *Sender)
{
	if(!frmMain->CanDataAccess())
	{
		FrmCdBox->setFlag(CD_OK);
		FrmCdBox->setTitle("Machine Run");
		FrmCdBox->setText("Machine Run");
		FrmCdBox->BringToFront();
		FrmCdBox->ShowModal();
		return;
	}

	TStringGrid* sg[5] = { StringGrid_path, StringGrid_offset1, StringGrid_offset2, StringGrid_offset3, StringGrid_offset4 };

	ButtonSave->Enabled = false;


	for(int s=0; s < 5; s++)
	{
		sg[s]->Options>>goEditing;
	}
	ValueListEditorPkg->Options>>goEditing;


	this->write_offset_data_seq();
	this->write_origin_path_data_seq();
	this->write_pkg_data_seq();
	this->save_offset_data_ini();
	this->save_exportData_ini();	// for test

	this->read_origin_path_data_ini();
	this->read_offset_data_ini();
	this->read_pkg_data_ini();

	ButtonInput->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TFrmShowData::PanelIndexClick(TObject *Sender)
{
	//
	TPanel* panel = dynamic_cast<TPanel*>(Sender);
	if(NULL != panel)
	{
		int id = panel->Caption.ToInt() - 1;
		this->select_index_for_move(id);
	}
}
//---------------------------------------------------------------------------
void	TFrmShowData::select_index_for_move(int index)
{

	TPanel* panel[4] = { PanelIndex1, PanelIndex2, PanelIndex3, PanelIndex4 };

	for(int i=0; i < 4; i++)
	{
		panel[i]->BevelOuter = bvRaised;
		panel[i]->Color = clSilver;
	}

	panel[index]->BevelOuter = bvLowered;
	panel[index]->Color = clBtnFace;

	GridPanelStageIndex->Tag = index;
}
//---------------------------------------------------------------------------
void __fastcall TFrmShowData::ButtonIndexMoveClick(TObject *Sender)
{
	if(!frmMain->CanDataAccess())
	{
		FrmCdBox->setFlag(CD_OK);
		FrmCdBox->setTitle("Machine Run");
		FrmCdBox->setText("Machine Run");
		FrmCdBox->BringToFront();
		FrmCdBox->ShowModal();
		return;
	}


	TBitBtn* btn = dynamic_cast<TBitBtn*>(Sender);
	if(NULL != btn)
	{
		#define	NDM_STAGE_NUMBER		210
		#define	NDM_PATH_NUMBER			211
		#define	NDM_POSITION_NUMBER		212
		#define	TENKEY_NUMBER_ROUTER 	97
		#define	TENKEY_NUMBER_VISION  	1097

		int	tenkey = TENKEY_NUMBER_VISION;

		if(btn->Caption == "ROUTER") tenkey =  TENKEY_NUMBER_ROUTER;
		else if(btn->Caption == "VISION") tenkey =  TENKEY_NUMBER_VISION;

		int	stageIndex = GridPanelStageIndex->Tag;
		int pathNumner = EditIndex->Text.ToInt() - 1;
		int	position   = PanelPos->Tag;

		FrmCdBox->setFlag(CD_YESNO);
		FrmCdBox->setTitle( btn->Caption +  " MOVE" );
		FrmCdBox->setText( "STAGE INDEX = " + IntToStr(stageIndex + 1) +
										", PATH NUMBER = " + IntToStr(pathNumner + 1) +
										", POSITION = " + PanelPos->Caption);
		if( mrYes == FrmCdBox->ShowModal())
		{
			nWriteCommunicationDM(stageIndex, NDM_STAGE_NUMBER);
			nWriteCommunicationDM(pathNumner, NDM_PATH_NUMBER);
			nWriteCommunicationDM(position, NDM_POSITION_NUMBER);
			nWriteCommunicationDM(tenkey, screenTenkey);
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmShowData::PageControl1Change(TObject *Sender)
{
	int index = PageControl1->ActivePageIndex -1;
	if( index >= 0) this->select_index_for_move(index);
}
//---------------------------------------------------------------------------
void	TFrmShowData::read_from_seq()
{
	this->print_statusbar("Read package data from SEQ");

	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_GERBER_PARA;
	if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
	{
		ValueListEditorPkg->Values["COUNT X"] 	  = IntToStr((int)g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[unitXCnt]);
		ValueListEditorPkg->Values["COUNT Y"] 	  = IntToStr((int)g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[unitYCnt]);
		ValueListEditorPkg->Values["PITCH X"] 	  = FloatToStr(g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[unitXPitch] );
		ValueListEditorPkg->Values["PITCH Y"] 	  = FloatToStr(g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[unitYPitch] );
		ValueListEditorPkg->Values["PATH COUNT"]  = IntToStr((int)g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[unitPathCnt]);
		ValueListEditorPkg->Values["QC COUNT"] 	  = IntToStr((int)g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[unitQcCnt]);

		ValueListEditorPkg->Values["PRS MARK1 X"] = FloatToStr(g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[prsBlockPos]  );
		ValueListEditorPkg->Values["PRS MARK1 Y"] = FloatToStr(g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[prsBlockPos+1]);
		ValueListEditorPkg->Values["PRS MARK2 X"] = FloatToStr(g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[prsBlockPos+2]);
		ValueListEditorPkg->Values["PRS MARK2 Y"] = FloatToStr(g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[prsBlockPos+3]);
		ValueListEditorPkg->Values["PRS MARK3 X"] = FloatToStr(g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[prsBlockPos+4]);
		ValueListEditorPkg->Values["PRS MARK3 Y"] = FloatToStr(g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[prsBlockPos+5]);
		ValueListEditorPkg->Values["PRS MARK4 X"] = FloatToStr(g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[prsBlockPos+6]);
		ValueListEditorPkg->Values["PRS MARK4 Y"] = FloatToStr(g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[prsBlockPos+7]);

		ValueListEditorPkg->Values["PRS UNIT1 X"] = FloatToStr(g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[prsUnitPos]   );
		ValueListEditorPkg->Values["PRS UNIT1 Y"] = FloatToStr(g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[prsUnitPos+1] );
		ValueListEditorPkg->Values["PRS UNIT2 X"] = FloatToStr(g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[prsUnitPos+2] );
		ValueListEditorPkg->Values["PRS UNIT2 Y"] = FloatToStr(g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[prsUnitPos+3] );

		ValueListEditorPkg->Values["QC POINT1 X"] = FloatToStr(g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[qcPos] 	   );
		ValueListEditorPkg->Values["QC POINT1 Y"] = FloatToStr(g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[qcPos+1] 	   );
		ValueListEditorPkg->Values["QC POINT2 X"] = FloatToStr(g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[qcPos+2] 	   );
		ValueListEditorPkg->Values["QC POINT2 Y"] = FloatToStr(g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[qcPos+3] 	   );
		ValueListEditorPkg->Values["QC POINT3 X"] = FloatToStr(g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[qcPos+4] 	   );
		ValueListEditorPkg->Values["QC POINT3 Y"] = FloatToStr(g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[qcPos+5] 	   );
		ValueListEditorPkg->Values["QC POINT4 X"] = FloatToStr(g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[qcPos+6] 	   );
		ValueListEditorPkg->Values["QC POINT4 Y"] = FloatToStr(g_MMIComm->m_mmiToSeq.buffer.gerberPara.dVal[qcPos+7] 	   );
	}

	this->print_statusbar("Read path data from SEQ");

	int pathCnt = ValueListEditorPkg->Values["PATH COUNT"].ToInt();
	int yCnt = ValueListEditorPkg->Values["COUNT Y"].ToInt();
	int xCnt = ValueListEditorPkg->Values["COUNT X"].ToInt();

	int tPathCnt = xCnt * yCnt * pathCnt;
	StringGrid_path->RowCount = tPathCnt+1;

	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_GERBER_DATA;
	if ( g_MMIComm->Send() &&  g_MMIComm->Recv())
	{
		for(int r=0; r < tPathCnt; r++)
		{
			GERBER gerberData = g_MMIComm->m_mmiToSeq.buffer.gerberData.data[r];

			StringGrid_path->Cells[1][r+1] = IntToStr((int)gerberData.dLineType);
			StringGrid_path->Cells[2][r+1] = FloatToStr(gerberData.dX_Start);
			StringGrid_path->Cells[3][r+1] = FloatToStr(gerberData.dY_Start);
			StringGrid_path->Cells[4][r+1] = FloatToStr(gerberData.dX_End);
			StringGrid_path->Cells[5][r+1] = FloatToStr(gerberData.dY_End);
			StringGrid_path->Cells[6][r+1] = FloatToStr(gerberData.dX_Mid_01);
			StringGrid_path->Cells[7][r+1] = FloatToStr(gerberData.dY_Mid_01);
			StringGrid_path->Cells[8][r+1] = FloatToStr(gerberData.dX_Mid_02);
			StringGrid_path->Cells[9][r+1] = FloatToStr(gerberData.dY_Mid_02);
			StringGrid_path->Cells[10][r+1]= FloatToStr(gerberData.dX_Mid_03);
			StringGrid_path->Cells[11][r+1]= FloatToStr(gerberData.dY_Mid_03);
			StringGrid_path->Cells[12][r+1]= FloatToStr(gerberData.dX_Mid_04);
			StringGrid_path->Cells[13][r+1]= FloatToStr(gerberData.dY_Mid_04);
			StringGrid_path->Cells[14][r+1]= FloatToStr(gerberData.dX_Arc);
			StringGrid_path->Cells[15][r+1]= FloatToStr(gerberData.dY_Arc);

			StringGrid_path->Cells[16][r+1]= FloatToStr(gerberData.dSpare16);
			StringGrid_path->Cells[17][r+1]= FloatToStr(gerberData.dSpare17);
			StringGrid_path->Cells[18][r+1]= FloatToStr(gerberData.dSpare18);
			StringGrid_path->Cells[19][r+1]= FloatToStr(gerberData.dSpare19);
			StringGrid_path->Cells[20][r+1]= FloatToStr(gerberData.dSpare20);

		}
	}

	this->print_statusbar("Read offset data from SEQ");

	TStringGrid* sg[4] = { StringGrid_offset1, StringGrid_offset2, StringGrid_offset3, StringGrid_offset4 };

	for(int i=0; i < 4; i++)
	{
		for(int r=0; r < MAX_PATH_CNT; r++)
		{
			GERBER gerberData = g_MMIComm->m_mmiToSeq.buffer.gerberData.data[(i+1)*100 + r];

			sg[i]->Cells[1][r+1] = IntToStr((int)gerberData.dLineType);
			sg[i]->Cells[2][r+1] = FloatToStr(gerberData.dX_Start	);
			sg[i]->Cells[3][r+1] = FloatToStr(gerberData.dY_Start	);
			sg[i]->Cells[4][r+1] = FloatToStr(gerberData.dX_End		);
			sg[i]->Cells[5][r+1] = FloatToStr(gerberData.dY_End		);
			sg[i]->Cells[6][r+1] = FloatToStr(gerberData.dX_Mid_01	);
			sg[i]->Cells[7][r+1] = FloatToStr(gerberData.dY_Mid_01	);
			sg[i]->Cells[8][r+1] = FloatToStr(gerberData.dX_Mid_02	);
			sg[i]->Cells[9][r+1] = FloatToStr(gerberData.dY_Mid_02	);
			sg[i]->Cells[10][r+1]= FloatToStr(gerberData.dX_Mid_03	);
			sg[i]->Cells[11][r+1]= FloatToStr(gerberData.dY_Mid_03	);
			sg[i]->Cells[12][r+1]= FloatToStr(gerberData.dX_Mid_04	);
			sg[i]->Cells[13][r+1]= FloatToStr(gerberData.dY_Mid_04	);
			sg[i]->Cells[14][r+1]= FloatToStr(gerberData.dX_Arc		);
			sg[i]->Cells[15][r+1]= FloatToStr(gerberData.dY_Arc		);
		}
	}

	this->print_statusbar("");
}
//---------------------------------------------------------------------------

void __fastcall TFrmShowData::ButtonReloadClick(TObject *Sender)
{
	TBitBtn* btn = dynamic_cast<TBitBtn*>(Sender);
	if(NULL != btn)
	{
		if(btn->Caption == "READ SEQ")
		{
			this->read_from_seq();
			btn->Caption = "READ DB";
		}
		else
		{
			this->read_pkg_data_ini();
			this->read_origin_path_data_ini();
			this->read_offset_data_ini();
			btn->Caption = "READ SEQ";
        }

    }
}
//---------------------------------------------------------------------------

