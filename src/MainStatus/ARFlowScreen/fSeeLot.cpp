//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fSeeLot.h"
#include "MainFormScrn.h"
#include "FormSecsGemSetScrn.h"
#include "BaseComm.h"
#include "..\tccomm\ftccomm.h"
#include "fLotEventHistory.h"
#include "include.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CurvyControls"
#pragma resource "*.dfm"

#define		AUTO_MODE		0
#define		MANUAL_MODE		1

TfrmSeeLot *frmSeeLot;
//---------------------------------------------------------------------------
__fastcall TfrmSeeLot::TfrmSeeLot(TComponent* Owner)
	: TForm(Owner)
{
	_mergeLotID= "";
	_mode = AUTO_MODE;
}
//---------------------------------------------------------------------------
void __fastcall TfrmSeeLot::FormShow(TObject *Sender)
{
	_result = 0;  /// 0 -> form close only  1-> sorter lot end  2->  manual lot end
	_retryCnt = 0;
	this->pageChg();

	if(_mode == AUTO_MODE)
	{
		btnManualClose->Enabled = false;
	}
	else
	{
		btnManualClose->Enabled = true;
	}

	_bWriteCycle = false;
	CurvyMemo1->Lines->Clear();
	//Timer3->Enabled = true;
	//see lot
	sgEqScrap->Cells[0][0] = "No";
	sgEqScrap->Cells[1][0] = "CODE";
	sgEqScrap->Cells[2][0] = "ARRAY SN";
	for (int i=0; i< sgEqScrap->RowCount-1; i++)
	{
		sgEqScrap->Cells[0][i+1] = IntToStr(i+1);
		sgEqScrap->Cells[1][i+1] = "";
		sgEqScrap->Cells[2][i+1] = "";
	}

	tmSeeLot->Enabled = true;
}
//---------------------------------------------------------------------------
void		TfrmSeeLot::setMode(int nMode)
{
	_mode = nMode;
}
//---------------------------------------------------------------------------
void __fastcall TfrmSeeLot::eqInputCntChange(TObject *Sender)
{

   if (qty->Text != eqInputCnt->Text)
   {
		eqInputCnt->Font->Color = clRed;
		qty->Font->Color = clRed;
   }
   else
   {
		eqInputCnt->Font->Color = clWindowText;
		qty->Font->Color = clWindowText;
   }

   if (scrapCount->Text != eqScrapCnt->Text)
   {
		eqScrapCnt->Font->Color = clRed;
		scrapCount->Font->Color = clRed;

		btnLotEnd->Enabled = false;
   }
   else
   {
		eqScrapCnt->Font->Color = clWindowText;
		scrapCount->Font->Color = clWindowText;

		if(_mergeLotID == "")
			btnLotEnd->Enabled = false;
		else
			btnLotEnd->Enabled = true;
   }

}
//---------------------------------------------------------------------------
void __fastcall TfrmSeeLot::btnLotEndClick(TObject *Sender)
{
	FrmCdBox->setFlag(CD_YESNO);
	FrmCdBox->setTitle("Sorter Lot End");
	FrmCdBox->setText("Do you want sorter lot end ?");

	if (mrYes == FrmCdBox->ShowModal())
	{
		AnsiString mergeLotID;
		g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_LOT_END_INFO;
		if (g_MMIComm->Send() &&  g_MMIComm->Recv())
		{
			// case CMD_RD_LOT_END_LOT_INFO:
			// LOT_INFO_PART_CUR	= 5, // 현재 진행중인 LOT 정보를 넘겨줌
			LOT_INFO& info = g_MMIComm->m_mmiToSeq.buffer.lotInfoCopy;
			mergeLotID = info.mergeLotID;    //Lot end 는 merge LOT ID 로

			//nWriteCommunicationDM(7, lotEndFrmState);

			//int oncestep = int(nReadCommunicationDM(lotEndFrmOnceStep));
			//int frmstate = int(nReadCommunicationDM(lotEndFrmState));
			//MainForm->MachineHistoryData("lotEndFrmState: " + IntToStr(frmstate) );

			// 성공은 TC 통신내에서 처리
			// MachineHistoryData 로그
			MainForm->MachineHistoryData("lot ended ! merge lotid: "+ _mergeLotID + \
										", input cnt: " + eqInputCnt->Text + \
										", good cnt: " + eqGoodCnt->Text + \
										", reject cnt: " + eqRejectCnt->Text + \
										", out cnt: " + eqOutPutCnt->Text +
										", scrap cnt: " + eqScrapCnt->Text );
			FormSecsGemSet->TrackOut();

			// LOT END LOGGING
			// 초기화
			LOT_EVENT_DATA	data;
			::ZeroMemory(&data, sizeof(data));

			// 데이터 넣어줌
			data.lotID = _mergeLotID;
			data.inputCnt = eqInputCnt->Text.ToInt();
			data.scrapCnt = eqScrapCnt->Text.ToInt();
			data.goodCnt = eqGoodCnt->Text.ToInt();
			data.rejectCnt = eqRejectCnt->Text.ToInt();
			data.outputCnt = eqOutPutCnt->Text.ToInt();
			// frmLotDataHistory 로그
			frmLotDataHistory->Record_LotEnd(data);

			//nWriteCommunicationDM(0, lotEndFrmState);

			nWriteCommunicationDM(1, autoLotEndComp);
			MainForm->_bSeeLotShow = false;
			//RSM SOR SAVE INFO SAVE LOT END FLAG
			//nWriteCommunicationDM(0, lotEndCompFlag);

			this->Close();
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmSeeLot::btnEditClick(TObject *Sender)
{
	sgEqScrap->Options<<goEditing;
	sgEqScrap->Options>>goRowSelect;

	sgScrap->Options<<goEditing;
	sgScrap->Options>>goRowSelect;

	btnEdit->Enabled = false;
    btnSave->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmSeeLot::btnDeleteClick(TObject *Sender)
{
	int row = sgScrap->Row;
    if (row < 1)
    	return;

	if (row > scrapCount->Text.ToIntDef(0))
    	return;

    String scrapCode = sgScrap->Cells[1][row];
    String scrapArraySN = sgScrap->Cells[2][row];

	FrmCdBox->setFlag(CD_YESNO);
    FrmCdBox->setTitle("Delete Scrap Info");
    FrmCdBox->setText("Do you want to delete scrap information with scrap code = " + scrapCode + " , arraysn = "+ scrapArraySN + " ?");
    if (mrYes == FrmCdBox->ShowModal())
    {
        // FUNCTION=DELETE_SCRAP
        // EQPID=AROUT-X02 LOTID=X007B00508 SERIAL= ARRAYSN=2MX16D003303MZVLVXXXXA009JXXXXXX_8 AUTOLINE=NO
//        AnsiString params[] = { \
//			MainForm->_eqpID,
//			_mergeLotID,
//			NULL,
//			scrapArraySN,
//			"NO"
//			};
//
//		BOOL bRet = frmTCComm->ohtDeleteScrap(params);

		if(FormSecsGemSet->DeleteScrap(CMD_RD_SCRAP_INFO_CUR_COPY, scrapArraySN))
		{
			msg->Text = "Request server to delete scrap ...";
			MainForm->MachineHistoryData("trying to delete scrap info : code= " + scrapCode + " , array sn = "+ scrapArraySN);
		}
		else
		{
			msg->Text = "Fail to Delete Scrap (xgem off)";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmSeeLot::btnLotEndManualClick(TObject *Sender)
{
	FrmCdBox->setFlag(CD_YESNO);
	FrmCdBox->setTitle("Warning ! Lot End By Manually");
	FrmCdBox->setText("No data transfer to TC Server ! Do you want lot end by manually ? ");
	if (mrYes == FrmCdBox->ShowModal())
	{
		AnsiString mergeLotID;
		g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_LOT_END_INFO;
		bool bRet = g_MMIComm->Send() &&  g_MMIComm->Recv();

		if(bRet)
		{
			LOT_INFO& info = g_MMIComm->m_mmiToSeq.buffer.lotInfoCopy;
			mergeLotID = info.mergeLotID;    // Lot end 는 Merge LOT ID 로

			MainForm->SaveToCSVFile(String(mergeLotID));
			FormSecsGemSet->TrackOut();
			MainForm->MachineHistoryData("lot ended by manually : Merge lot id : "+ mergeLotID);

			// LOT END LOGGING
			LOT_EVENT_DATA	data;
			::ZeroMemory(&data, sizeof(data));

			data.lotID = _mergeLotID;
			data.inputCnt = eqInputCnt->Text.ToInt();
			data.scrapCnt = eqScrapCnt->Text.ToInt();
			data.goodCnt = eqGoodCnt->Text.ToInt();
			data.rejectCnt = eqRejectCnt->Text.ToInt();
			data.outputCnt = eqOutPutCnt->Text.ToInt();
			frmLotDataHistory->Record_LotEnd(data);

			//nWriteCommunicationDM(STATE_IDLE, reqWriteCoverGoodRfid);
			//nWriteCommunicationDM(STATE_IDLE, reqReadCoverGoodRfid);
			//_bWriteCycle = true;
			nWriteCommunicationDM(4, lotEndStep); 	//manual success
		}
		else
			nWriteCommunicationDM(5, lotEndStep); 	//manual success
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmSeeLot::tmSeeLotTimer(TObject *Sender)
{
	tmSeeLot->Enabled = false;

	sgScrap->Cells[0][0] = "No";
	sgScrap->Cells[1][0] = "CODE";
	sgScrap->Cells[2][0] = "ARRAY SN";
	for (int i=0; i< sgScrap->RowCount-1; i++)
    {
		sgScrap->Cells[0][i+1] = IntToStr(i+1);
        sgScrap->Cells[1][i+1] = "";
        sgScrap->Cells[2][i+1] = "";
    }
	ceMergeLotID->Text = "";
    lotState->Text = "";
	partNo->Text = "";
    qty->Text = "";
	//result->Text = "";
	scrapCount->Text = "0";
	msg->Text = "";

	ceEqpID->Text = "EQP ID : " + MainForm->_eqpID;
	eqInputCnt->Text = IntToStr( nReadCommunicationDM(lotInputCntCopy));
	eqGoodCnt->Text = IntToStr( nReadCommunicationDM(lotGoodCntCopy));
	eqRejectCnt->Text = IntToStr( nReadCommunicationDM(lotRejectCntCopy));
	eqOutPutCnt->Text =  IntToStr( nReadCommunicationDM(lotOutPutCntCopy));
	//	eqInputCnt->Text = IntToStr( nReadCommunicationDM(lotInputCnt ));
	//	eqGoodCnt->Text = IntToStr( nReadCommunicationDM(lotGoodCnt ));
	//	eqRejectCnt->Text = IntToStr( nReadCommunicationDM(lotRejectCnt ));
	//	eqOutPutCnt->Text =  IntToStr( nReadCommunicationDM(lotOutPutCnt ));

	// 수율이 94% 이하이면
	// LOT ID : ???  YIELD 94% H6 Hold Lot 메시지 출력
	// 작업 LOT에 QC 에러가 1나라도 있으면 에러 메시지 출력

	// g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_SCRAP_INFO_CUR;
	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_SCRAP_INFO_CUR_COPY;
	BOOL bRet = g_MMIComm->Send() &&  g_MMIComm->Recv();
	if (!bRet)
		return;

	// eqScrapCnt->Text = IntToStr( g_MMIComm->m_mmiToSeq.buffer.onlineEndHistory.scrapCnt );
	eqScrapCnt->Text = IntToStr( g_MMIComm->m_mmiToSeq.buffer.onlineEndHistoryCopy.scrapCnt );

	// _mergeLotID = g_MMIComm->m_mmiToSeq.buffer.onlineEndHistory.mergeLotID;
	_mergeLotID = g_MMIComm->m_mmiToSeq.buffer.onlineEndHistoryCopy.mergeLotID;
	ceMergeLotID->Text = "MERGE LOTID : " + _mergeLotID;

	/*
	int qcErrorCnt = 0;
	for (int i=0; i< g_MMIComm->m_mmiToSeq.buffer.onlineEndHistory.scrapCnt; i++)
    {
		if ( 0 == stricmp( g_MMIComm->m_mmiToSeq.buffer.onlineEndHistory.scrapCode[i], "1129"))	// QC Dimension 에러 코드
        	qcErrorCnt++;

		this->sgEqScrap->Cells[1][i+1] =  g_MMIComm->m_mmiToSeq.buffer.onlineEndHistory.scrapCode[i];
		this->sgEqScrap->Cells[2][i+1] =  g_MMIComm->m_mmiToSeq.buffer.onlineEndHistory.scrapArraySN[i];
	}
	*/
    // FUNCTION=SEE_LOT
    // LOTNO=X007B00508 EQPID=AROUT-X02 OPERID=AUTO
//	AnsiString params[] = {\
//		_mergeLotID,
//		MainForm->_eqpID,
//		"AUTO"
//	};

 	/// 전산쪽 정보를 왼쪽에 기입
    //////////////////////////////////////////////////////////////////


    // tc 통신 응답부분에서 form 에 접근해 기입
	//bRet = frmTCComm->ohtSeeLot(params);
	if(FormSecsGemSet->GemLotInfo(1, _mergeLotID))
	{
		msg->Text = "Request server to See Lot ...";
	}
	else
	{
		msg->Text = "Fail to See Lot (xgem off)";
	}

	// 전산쪽 스크랩 정보 기입
	// tc 통신응답부분에서 form 에 접근해 기입
	// 타이머 사용이유 -> tc 통신이 타이머 방식으로 연결되어 연속으로 처리하기 곤란해서 사용
	//tmScrapInfo->Enabled = true;	// GemLotInfo 결과 이후로 변경. RMS. TC->SECSGEM
}
//---------------------------------------------------------------------------
void __fastcall TfrmSeeLot::tmScrapInfoTimer(TObject *Sender)
{
	tmScrapInfo->Enabled = false;
	// FUNCTION=SCRAP_INFO
	// LOTID=X007B00508 EQPID=AROUT-X02 AUTOLINE=NO
//	AnsiString params[] = {\
//		MainForm->_eqpID,
//		_mergeLotID,
//		"NO"
//	};

	//BOOL bRet = frmTCComm->ohtScrapInfo(params);

	if(FormSecsGemSet->ScrapInfo(CMD_RD_SCRAP_INFO_CUR_COPY))
	{
		msg->Text = "Request server to Scrap Info ...";
	}
	else
	{
		msg->Text = "Fail to Scrap Info (xgem off)";
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmSeeLot::btnSeeLotClick(TObject *Sender)
{
	tmSeeLot->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmSeeLot::btnSaveClick(TObject *Sender)
{
	FrmCdBox->setFlag(CD_YESNO);
    FrmCdBox->setTitle("Online End History");
    FrmCdBox->setText("Do you want to save with online end history ?");
    if (mrYes != FrmCdBox->ShowModal())
    {
    	return;
    }

	sgEqScrap->Options>>goEditing;
	sgEqScrap->Options<<goRowSelect;

	sgScrap->Options>>goEditing;
	sgScrap->Options<<goRowSelect;

	btnEdit->Enabled = true;
	btnSave->Enabled = false;
	/*
	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_SCRAP_INFO_CUR;
	bool bRet = g_MMIComm->Send() &&  g_MMIComm->Recv();
    if (!bRet)	return;

	int scrapCnt = 0;
    for (int i=0; i< sgEqScrap->RowCount-1; i++)
    {
    	AnsiString scrapCode = sgEqScrap->Cells[1][i+1];
        AnsiString scrapArraySN = sgEqScrap->Cells[2][i+1];
        if ( scrapCode.Trim() != "" && scrapArraySN.Trim() != "")
        {
			strcpy(g_MMIComm->m_mmiToSeq.buffer.onlineEndHistory.scrapCode[scrapCnt],  scrapCode.c_str() );
			strcpy(g_MMIComm->m_mmiToSeq.buffer.onlineEndHistory.scrapArraySN[scrapCnt],  scrapArraySN.c_str() );
			scrapCnt++;
        }
    }

	g_MMIComm->m_mmiToSeq.nCmd = CMD_WR_SCRAP_INFO_CUR;
	strcpy( g_MMIComm->m_mmiToSeq.buffer.onlineEndHistory.lotID, _lotID.c_str() );
	g_MMIComm->m_mmiToSeq.buffer.onlineEndHistory.scrapCnt = scrapCnt;
	bRet = g_MMIComm->Send() &&  g_MMIComm->Recv();

	MainForm->MachineHistoryData("online end history saved to seq by manually" );

	for (int i=0; i< sgEqScrap->RowCount-1; i++)
    {
		sgEqScrap->Cells[0][i+1] = IntToStr(i+1);
        sgEqScrap->Cells[1][i+1] = "";
        sgEqScrap->Cells[2][i+1] = "";
    }

	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_SCRAP_INFO_CUR;
	bRet = g_MMIComm->Send() &&  g_MMIComm->Recv();
	if (!bRet)
    	return;

	eqScrapCnt->Text = IntToStr( g_MMIComm->m_mmiToSeq.buffer.onlineEndHistory.scrapCnt );
	for (int i=0; i< g_MMIComm->m_mmiToSeq.buffer.onlineEndHistory.scrapCnt; i++)
    {
		this->sgEqScrap->Cells[1][i+1] =  g_MMIComm->m_mmiToSeq.buffer.onlineEndHistory.scrapCode[i];
		this->sgEqScrap->Cells[2][i+1] =  g_MMIComm->m_mmiToSeq.buffer.onlineEndHistory.scrapArraySN[i];
	}
	*/
	// g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_SCRAP_INFO_CUR;
	g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_SCRAP_INFO_CUR_COPY;

	bool bRet = g_MMIComm->Send() &&  g_MMIComm->Recv();
    if (!bRet)
		return;

	// eqScrapCnt->Text = IntToStr( g_MMIComm->m_mmiToSeq.buffer.onlineEndHistory.scrapCnt );
	eqScrapCnt->Text = IntToStr( g_MMIComm->m_mmiToSeq.buffer.onlineEndHistoryCopy.scrapCnt );

	nWriteCommunicationDM(eqInputCnt->Text.ToInt(),lotInputCntCopy);
	nWriteCommunicationDM(eqGoodCnt->Text.ToInt(),lotGoodCntCopy);
	nWriteCommunicationDM(eqRejectCnt->Text.ToInt(),lotRejectCntCopy);
	nWriteCommunicationDM(eqOutPutCnt->Text.ToInt(),lotOutPutCntCopy);
	//nWriteCommunicationDM(eqInputCnt->Text.ToInt(),lotInputCnt);
	//nWriteCommunicationDM(eqGoodCnt->Text.ToInt(),lotGoodCnt);
	//nWriteCommunicationDM(eqRejectCnt->Text.ToInt(),lotRejectCnt);
	//nWriteCommunicationDM(eqOutPutCnt->Text.ToInt(),lotOutPutCnt);
}
//---------------------------------------------------------------------------

void __fastcall TfrmSeeLot::btnOnlineEndAllClick(TObject *Sender)
{
	//g_MMIComm->m_mmiToSeq.nCmd = CMD_RD_SCRAP_INFO_CUR;
	//BOOL bRet = g_MMIComm->Send() &&  g_MMIComm->Recv();
	//if (!bRet)
	//	return;

	//int scrapCnt = g_MMIComm->m_mmiToSeq.buffer.onlineEndHistory.scrapCnt;
	//if (scrapCnt <= 0 )
	//	return;
	int scrapCnt = 0;
	int scrapIndex[1000] = {0,};
	for(int i=0; i<sgEqScrap->RowCount-1; i++)
	{
		if(sgEqScrap->Cells[1][i+1] != "" && sgEqScrap->Cells[2][i+1] != "")
		{
			scrapIndex[scrapCnt] = i+1;
			scrapCnt++;
		}
	}

	if (scrapCnt <= 0 )
		return;

	FrmCdBox->setFlag(CD_YESNO);
	FrmCdBox->setTitle("Online End");
	FrmCdBox->setText("Do you want to online end with " + IntToStr(scrapCnt) + " scrap count ?");
	if (mrYes != FrmCdBox->ShowModal())
	{
		return;
	}


	// FUNCTION=ONLINE_END
	// EQPID=AROUT-X02 EQPMODEL=ROUTER_SORTER AUTOLINE=NO LOTID=X007B00508 OPERID=AUTO
	// SCRAP_CNT=8
	// SCRAP_INFO001=(SCRAP_CODE=3417 ARRAYSN=2MX16D003301MZVLVXXXXA039IXXXXXX_1 SERIAL=)
	// SCRAP_INFO002=(SCRAP_CODE=3417 ARRAYSN=2MX16D003301MZVLVXXXXA039IXXXXXX_2 SERIAL=)
	// SCRAP_INFO003=(SCRAP_CODE=3417 ARRAYSN=2MX16D003301MZVLVXXXXA039IXXXXXX_3 SERIAL=)
	// SCRAP_INFO004=(SCRAP_CODE=3417 ARRAYSN=2MX16D003301MZVLVXXXXA039IXXXXXX_4 SERIAL=)
	// SCRAP_INFO005=(SCRAP_CODE=3417 ARRAYSN=2MX16D003301MZVLVXXXXA039IXXXXXX_5 SERIAL=)
	// SCRAP_INFO006=(SCRAP_CODE=3417 ARRAYSN=2MX16D003301MZVLVXXXXA039IXXXXXX_6 SERIAL=)
	// SCRAP_INFO007=(SCRAP_CODE=3417 ARRAYSN=2MX16D003301MZVLVXXXXA039IXXXXXX_7 SERIAL=)
	// SCRAP_INFO008=(SCRAP_CODE=3417 ARRAYSN=2MX16D003301MZVLVXXXXA039IXXXXXX_8 SERIAL=)
//	AnsiString params[100];
//	params[0] = MainForm->_eqpID;
//	params[1] = IntToStr(scrapCnt);
//	params[2] = "ROUTER_SORTER";//eqp model
//	params[3] = "NO";	//autoline
//	params[4] = _mergeLotID;   //online end 는 mergelot id 로
//	params[5] = "AUTO";//operid
//
//	int paramIndex = 6;
//
//	for (int i=0; i<scrapCnt; i++)
//	{
//		AnsiString scrapCode = sgEqScrap->Cells[1][scrapIndex[i]];
//		AnsiString scrapArraySN = sgEqScrap->Cells[2][scrapIndex[i]];
//
//		 params[paramIndex++] =  \
//			AnsiString("SCRAP_CODE=") +  \
//			scrapCode +
//			AnsiString(" ARRAYSN=") + \
//			scrapArraySN + \
//			AnsiString(" SERIAL=");
//		MainForm->MachineHistoryData("online ended by manually : scrap code = " + scrapCode + " , arraysn = " + scrapArraySN);
//	}

	//frmTCComm->ohtOnlineEnd(params, FALSE);

	String sScrap4Add="";
	String scrapCode, scrapArraySN;
	for (int i=0; i<scrapCnt; i++)
	{
		if(i != 0)	sScrap4Add += ",";

		scrapCode = sgEqScrap->Cells[1][scrapIndex[i]];
		scrapArraySN = sgEqScrap->Cells[2][scrapIndex[i]];
		sScrap4Add += String().sprintf(L"%s:%s",scrapCode,scrapArraySN);

		//SERIAL 부분은 TC->SECSGEM 전환전에도 없던 부분이랑 추가 안함
		//RMS 적용 중 여러사정으로 무료로 진행하는 부분이라 UI 관련부분은 수정X
	}

	MainForm->_onlineEndIndex = 99;	//manual
	MainForm->MachineHistoryData("AddScrap Online End Function Check");
	if(FormSecsGemSet->AddScrap(CMD_RD_LOT_END_INFO/*확인필요*/, scrapCnt, sScrap4Add))
	{
		msg->Text = "Request server to add scrap ...";
	}
	else
	{
		msg->Text = "Fail to Add Scrap (xgem off)";
	}

	sgEqScrap->Cells[0][0] = "No";
	sgEqScrap->Cells[1][0] = "CODE";
	sgEqScrap->Cells[2][0] = "ARRAY SN";
	for (int i=0; i< sgEqScrap->RowCount-1; i++)
	{
		sgEqScrap->Cells[0][i+1] = IntToStr(i+1);
		sgEqScrap->Cells[1][i+1] = "";
		sgEqScrap->Cells[2][i+1] = "";
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmSeeLot::btnManualCloseClick(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmSeeLot::Timer3Timer(TObject *Sender)
{
	this->rfidState();

	if(_bWriteCycle)
	{
		bool bUseSkip = bReadUseSkip(usRfid);

		if(!bUseSkip )
		{
			_bWriteCycle = false;
			nWriteCommunicationDM(STATE_IDLE, reqWriteCoverGoodRfid);
			nWriteCommunicationDM(STATE_IDLE, reqReadCoverGoodRfid);
			MainForm->MachineHistoryData("RFID Cycle Skip!");
			//nWriteCommunicationDM(7, lotEndStep);
			this->Close();
		}
		else
		{
			bool bRet = rfidCycle();

			if(!bRet)
			{
				if(_retryCnt > 5)  //25초
				{
					_retryCnt = 0;
					_bWriteCycle = false;

					nWriteCommunicationDM(STATE_IDLE, reqWriteCoverGoodRfid);
					nWriteCommunicationDM(STATE_IDLE, reqReadCoverGoodRfid);
					CurvyMemo1->Lines->Add("Fail to write cycle!");
					MainForm->MachineHistoryData("Fail to write cycle!");
					this->pageChg(page_rfid);
				}
			}
			else
			{
				_bWriteCycle = false;
				nWriteCommunicationDM(STATE_IDLE, reqWriteCoverGoodRfid);
				nWriteCommunicationDM(STATE_IDLE, reqReadCoverGoodRfid);
				CurvyMemo1->Lines->Add("Success to write cycle!");
				MainForm->MachineHistoryData("Success to write cycle!");
				if( _mode == AUTO_MODE )
				{
					//nWriteCommunicationDM(7, lotEndStep);
					this->Close();
				}
			}
		}
	}
}
//---------------------------------------------------------------------------
void		TfrmSeeLot::pageChg(int nIndex)
{
	PageControl1->ActivePageIndex = nIndex;
	return;
}
//---------------------------------------------------------------------------
void		TfrmSeeLot::readRfidData(RFID_DATA rfid)
{
	rfidCarrierID->Text = String(rfid.carrierID);
	rfidLotID->Text = String(rfid.lotID);
	rfidPartNo->Text = String(rfid.partNo);
	rfidQty->Text = String(rfid.qty);
	rfidStep->Text = String(rfid.step);

	CurvyMemo1->Lines->Add("RFID read cover Carrier ID : "  + rfid.carrierID);
	CurvyMemo1->Lines->Add("RFID read cover Qty        : "  + rfid.qty);
	CurvyMemo1->Lines->Add("RFID read cover Lot ID     : "  + rfid.lotID);
	CurvyMemo1->Lines->Add("RFID read cover Step       : "  + rfid.step);
	CurvyMemo1->Lines->Add("RFID read cover Part No    : "  + rfid.partNo);

	return;
}
//---------------------------------------------------------------------------
void		TfrmSeeLot::writeRfidData(String strLotID, String strPartNo)
{
	rfidLotID->Text = strLotID;
	rfidPartNo->Text = strPartNo;

	CurvyMemo1->Lines->Add("RFID write cover Qty        : 0");
	CurvyMemo1->Lines->Add("RFID write cover Lot ID     : "  + strLotID);
	CurvyMemo1->Lines->Add("RFID write cover Step       : " );
	CurvyMemo1->Lines->Add("RFID write cover Part No    : "  + strPartNo);

	MainForm->MachineHistoryData("RFID write cover Qty        : 0");
	MainForm->MachineHistoryData("RFID write cover Lot ID     : "  + strLotID);
	MainForm->MachineHistoryData("RFID write cover Step       : " );
	MainForm->MachineHistoryData("RFID write cover Part No    : "  + strPartNo);
	return;
}
//---------------------------------------------------------------------------
bool 		TfrmSeeLot::rfidCycle()
{
	int nReadRfid  = nReadCommunicationDM(reqReadCoverGoodRfid);
	int nWriteRfid = nReadCommunicationDM(reqWriteCoverGoodRfid);

	if(nWriteRfid == STATE_IDLE)
	{
		CurvyMemo1->Lines->Add("rfid write start actving...");
		nWriteCommunicationDM(STATE_REQ, reqWriteCoverGoodRfid);
	}
	else if(nWriteRfid == STATE_COMP && nReadRfid == STATE_IDLE)
	{
		CurvyMemo1->Lines->Add("rfid read start actving...");
		nWriteCommunicationDM(STATE_REQ, reqReadCoverGoodRfid);
	}
	else if(nWriteRfid == STATE_ERR || nReadRfid == STATE_ERR)
	{
		_retryCnt++;
		CurvyMemo1->Lines->Add("rfid error detect start clear...");
		CurvyMemo1->Lines->Add("rfid write cycle retry count : "  + IntToStr(_retryCnt));
		nWriteCommunicationDM(STATE_IDLE, reqWriteCoverGoodRfid);
		nWriteCommunicationDM(STATE_IDLE, reqReadCoverGoodRfid);
	}

	if(nWriteRfid == STATE_COMP && nReadRfid == STATE_COMP)
		return true;
	else
		return false;
}
//---------------------------------------------------------------------------
void		TfrmSeeLot::rfidState()
{
	bool bUseSkip = bReadUseSkip(usRfid);
	int nReadRfid  = nReadCommunicationDM(reqReadCoverGoodRfid);
	int nWriteRfid = nReadCommunicationDM(reqWriteCoverGoodRfid);

	if(bUseSkip)
	{
		CurvyEditRfidControl->Text = "RFID USE";
		CurvyEditRfidControl->Color = clLime;
	}
	else
	{
		CurvyEditRfidControl->Text = "RFID SKIP";
		CurvyEditRfidControl->Color = clMedGray;
	}

	if(nWriteRfid==STATE_IDLE && nReadRfid==STATE_IDLE)
	{
		CurvyEditRfidState->Text = "RFID_READY";
		CurvyEditRfidState->Color = clMedGray;
	}
	else if(nWriteRfid==STATE_COMP && nReadRfid==STATE_COMP)
	{
		CurvyEditRfidState->Text = "RFID_COMP";
		CurvyEditRfidState->Color = clLime;
		MainForm->MachineHistoryData("RFID Read Write COMP!");
	}
	else if(nWriteRfid==STATE_ERR || nReadRfid==STATE_ERR)
	{
		CurvyEditRfidState->Text = "RFID_ERROR";
		CurvyEditRfidState->Color = clRed;
	}
	else if(nWriteRfid!=STATE_IDLE && nReadRfid==STATE_IDLE)
	{
		CurvyEditRfidState->Text = "RFID_WRITING";
		CurvyEditRfidState->Color = clYellow;
	}
	else if(nReadRfid!=STATE_IDLE)
	{
		CurvyEditRfidState->Text = "RFID_READING";
		CurvyEditRfidState->Color = clYellow;
	}
	else
	{
		CurvyEditRfidState->Text = "RFID_READY";
		CurvyEditRfidState->Color = clMedGray;
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmSeeLot::CurvyEditRfidControlDblClick(TObject *Sender)
{
	FrmCdBox->setFlag(CD_YESNO);
	FrmCdBox->setTitle("RFID USE/SKIP");
	FrmCdBox->setText("Do you want to change Rfid use/skip?");
	if (mrYes != FrmCdBox->ShowModal())
	{
		return;
	}

	int iRtn =UseSkipControl(usRfid);
	if(iRtn)
	{
		if(MainForm->b_TpConnect)
		{
			String strData = "", strIndex = "";

			{
				strIndex= "'Rfid'";
				if(iRtn==1)
					strData = "'TRUE'";
				else
					strData = "'FALSE'";

				g_pTpBase->logConfigure(L"USESKIP",L"CHANGE",L"'CHANGE_ITEM'",strIndex.c_str(),L"'VALUE'",strData.c_str());
			}
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmSeeLot::btnRfidWriteClick(TObject *Sender)
{
	FrmCdBox->setFlag(CD_YESNO);
	FrmCdBox->setTitle("RFID WRITE CYCLE");
	FrmCdBox->setText("Do you want to write rfid data?");
	if (mrYes != FrmCdBox->ShowModal())
	{
		return;
	}

	nWriteCommunicationDM(STATE_IDLE, reqWriteCoverGoodRfid);
	nWriteCommunicationDM(STATE_IDLE, reqReadCoverGoodRfid);

	_bWriteCycle = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmSeeLot::btnRfidReadClick(TObject *Sender)
{
	FrmCdBox->setFlag(CD_YESNO);
	FrmCdBox->setTitle("RFID READ");
	FrmCdBox->setText("Do you want to read rfid data?");
	if (mrYes != FrmCdBox->ShowModal())
	{
		return;
	}

}
//---------------------------------------------------------------------------

void __fastcall TfrmSeeLot::FormClose(TObject *Sender, TCloseAction &Action)
{
	Timer3->Enabled = false;
}
//---------------------------------------------------------------------------

void		TfrmSeeLot::setCycle(bool bSet)
{
	if(bSet)
	{
    	nWriteCommunicationDM(STATE_IDLE, reqWriteCoverGoodRfid);
		nWriteCommunicationDM(STATE_IDLE, reqReadCoverGoodRfid);
	}
	_bWriteCycle = bSet;
}
void __fastcall TfrmSeeLot::BitBtn1Click(TObject *Sender)
{
	int nTcRow = sgScrap->Row;
	int nEqRow = 0;
	for(int i=0; i<sgEqScrap->RowCount-1; i++)
	{
		if(sgEqScrap->Cells[1][i+1]==""&&sgEqScrap->Cells[2][i+1]=="")
		{
			nEqRow = i+1;
			break;
		}
	}

	FrmCdBox->setFlag(CD_YESNO);
	FrmCdBox->setTitle("Scrap Info Copy");
	FrmCdBox->setText("Do you want to Scrap Data Copy TC_Row["+IntToStr(nTcRow)+"]-> EQ_Row["+IntToStr(nEqRow)+"]?");
	if (mrYes != FrmCdBox->ShowModal())
	{
		return;
	}

	sgEqScrap->Cells[1][nEqRow] = sgScrap->Cells[1][nTcRow];
	sgEqScrap->Cells[2][nEqRow] = sgScrap->Cells[2][nTcRow];
}
//---------------------------------------------------------------------------

void __fastcall TfrmSeeLot::SpeedButton11Click(TObject *Sender)
{
	nWriteCommunicationDM(0, lotEndStep); 	//manual success
	this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmSeeLot::setMsg(String sText)
{
	if(this->Showing)
	{
		msg->Text = sText;
	}
}
//---------------------------------------------------------------------------





