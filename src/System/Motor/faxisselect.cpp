//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "faxisselect.h"
#include "FrmMotorControlScrn.h"
#include <inifiles.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmSelectAxis *frmSelectAxis;
//---------------------------------------------------------------------------
__fastcall TfrmSelectAxis::TfrmSelectAxis(TComponent* Owner, TForm* target)
	: TForm(Owner)
{
	_target = target;
}
//---------------------------------------------------------------------------
void __fastcall TfrmSelectAxis::CategoryBtnClick(TObject *Sender)
{
	TBitBtn* btn = dynamic_cast<TBitBtn*>(Sender);
	if(NULL != btn) this->set_axis(btn->Tag);
}
//---------------------------------------------------------------------------
void __fastcall TfrmSelectAxis::AxisBtnClick(TObject *Sender)
{
	TBitBtn* btn = dynamic_cast<TBitBtn*>(Sender);
	if(NULL != btn)
	{
		((TFrmMotorControl*)_target)->Motorscreen_Initialize(btn->Tag);
		this->Close();
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmSelectAxis::ButtonAllClick(TObject *Sender)
{
	this->set_axis(0);
}
//---------------------------------------------------------------------------
void __fastcall TfrmSelectAxis::FormCreate(TObject *Sender)
{
	TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\MotorScrnSetup.ini");
	int categoryCnt = ini->ReadInteger("MOTER_SELECT_SCREEN","CATEGORY_CNT",0);

	for(int i=1; i <categoryCnt + 1; i++)
	{
		TBitBtn* btn = new TBitBtn(this);
		btn->Parent = GridPanelCategory;
		btn->Align = alClient;
		btn->Margins->SetBounds(5,5,5,5);
		btn->AlignWithMargins = true;
		btn->Font->Name = "Calibri";
		btn->Font->Size = 10;
		btn->Style<<fsBold;
		btn->Caption = ini->ReadString("CATEGORY"+IntToStr(i),"NAME","NO NAME");
		btn->Tag = i;
		btn->OnClick = CategoryBtnClick;

		_category.push_back(btn);
	}

	this->set_axis(0);

	delete ini;
}
//---------------------------------------------------------------------------
void	TfrmSelectAxis::set_axis(int index)
{
	for(int i=0; i < _axis.size(); i++)
	{
		_axis.at(i)->FreeOnRelease();
		delete _axis.at(i);
	}

	_axis.clear();

	TIniFile *nameIni = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\MotorName.ini");
	TIniFile *ini = new TIniFile(ExtractFilePath(Application->ExeName)+ "\\Ini\\MotorScrnSetup.ini");

	if(index == 0)
	{
		int	axisCnt = ini->ReadInteger("MOTER_SELECT_SCREEN","TOTAL_AXIS_COUNT",0);
		for(int i=0; i <axisCnt; i++)
		{
			TBitBtn* btn = new TBitBtn(this);
			btn->Parent = GridPanelAxis;
			btn->Align = alClient;
			btn->Margins->SetBounds(5,5,5,5);
			btn->AlignWithMargins = true;
			btn->Font->Name = "Calibri";
			btn->Font->Size = 10;
			btn->Style<<fsBold;
			btn->Tag = i;
			btn->Caption = IntToStr(btn->Tag+1)+ " : " + nameIni->ReadString("AXISNAME","AXIS"+IntToStr(btn->Tag),"AXISNAME"+IntToStr(btn->Tag));
			btn->OnClick = AxisBtnClick;

			_axis.push_back(btn);
		}
	}
	else
	{
		int axisCnt = ini->ReadInteger("CATEGORY"+IntToStr(index),"COUNT",0);
		for(int i=0; i <axisCnt; i++)
		{
			TBitBtn* btn = new TBitBtn(this);
			btn->Parent = GridPanelAxis;
			btn->Align = alClient;
			btn->Margins->SetBounds(5,5,5,5);
			btn->AlignWithMargins = true;
			btn->Font->Name = "Calibri";
			btn->Font->Size = 10;
			btn->Style<<fsBold;
			btn->Tag = ini->ReadInteger("CATEGORY"+IntToStr(index),"AXIS_NUMBER_"+IntToStr(i),0);
			btn->Caption = IntToStr(btn->Tag+1)+ " : " + nameIni->ReadString("AXISNAME","AXIS"+IntToStr(btn->Tag),"AXISNAME"+IntToStr(btn->Tag));
			btn->OnClick = AxisBtnClick;

			_axis.push_back(btn);
		}
	}

	delete ini;
	delete nameIni;

}
//---------------------------------------------------------------------------
void __fastcall TfrmSelectAxis::FormDestroy(TObject *Sender)
{
	for(int i=0; i < _axis.size(); i++)
	{
		_axis.at(i)->FreeOnRelease();
		delete _axis.at(i);
	}

	_axis.clear();

	for(int i=0; i < _category.size(); i++)
	{
		_category.at(i)->FreeOnRelease();
		delete _category.at(i);
	}

	_category.clear();
}
//---------------------------------------------------------------------------
