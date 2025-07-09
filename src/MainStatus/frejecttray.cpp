//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "frejecttray.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmRejectTray *frmRejectTray;

#include "BaseComm.h"
//---------------------------------------------------------------------------
__fastcall TfrmRejectTray::TfrmRejectTray(TComponent* Owner)
	: TForm(Owner)
{
	_page = 0;
}
//---------------------------------------------------------------------------
void	TfrmRejectTray::SetDisplayIndex(bool enable)
{
    PanelIndex->Visible = enable;
}
//---------------------------------------------------------------------------
void	TfrmRejectTray::SetTrayCount(int col, int row)
{
	if(!_panels.empty())
	{
		for(int i=0; i < _panels.size(); i++)
		{
			_panels.at(i)->FreeOnRelease();
			delete _panels.at(i);
		}
	}

	_panels.clear();

	GridPanel1->ColumnCollection->Clear();
	GridPanel1->RowCollection->Clear();

	for(int r=0; r<row ; r++)
	{
		GridPanel1->RowCollection->Add();
	}
	for(int c=0; c<col ; c++)
	{
		GridPanel1->ColumnCollection->Add();
	}

	for(int r=0; r < row; r++)
	{
		for(int c=0; c <col; c++)
		{
			TPanel* p = new TPanel(this);
			p->Parent = GridPanel1;
			p->Align = alClient;

			p->AlignWithMargins = true;
			p->Margins->Top = 2;
			p->Margins->Bottom = 2;
			p->Margins->Left = 2;
			p->Margins->Right = 2;

			p->Color = clGray;
			p->BevelKind = bkFlat;
			p->BevelOuter = bvNone;
			p->BevelInner = bvNone;

			p->Font->Name = "Calibri";
			p->Font->Size = 20;
			p->Font->Style << fsBold;


			_panels.push_back(p);

			p->Show();
		}
	}
}
//---------------------------------------------------------------------------
void	TfrmRejectTray::SetUnitStatus(int id, String caption)
{
	if(id < _panels.size())
	{
		TPanel* p = _panels[id];
		p->Caption = caption;

		TColor brush = clGray;
		TColor font = clBlack;
		
		if(caption == "1")
		{
			brush = clLime;
		}
		if(caption == "R")
		{
			brush = clRed;
		}

		p->Color = brush;
		p->Font->Color = font;		
	}
}
//---------------------------------------------------------------------------
String 	TfrmRejectTray::read_status(int page, int unitId)
{
	return "1";
}
//---------------------------------------------------------------------------
void	TfrmRejectTray::regen()
{
   int		row = dReadPkgData(trayYCnt);
   int		col = dReadPkgData(trayXCnt);

   this->SetTrayCount(col, row);

   for(int r = 0 ; r < row; r++)
   {
		for(int c=0; c < col; c++)
		{
			int id = r*col + c;
			
			this->SetUnitStatus(id, this->read_status(_page,id));
		}                                                        	
   }
}
//---------------------------------------------------------------------------

void __fastcall TfrmRejectTray::BitBtnPrevClick(TObject *Sender)
{
	if(_page > 0) _page--;
	
	if(_page == 0) BitBtnPrev->Enabled = false;
	else BitBtnPrev->Enabled = true;	

	if(_page == 40) BitBtnNext->Enabled = false;
	else BitBtnNext->Enabled = true;

	PanelPage->Caption = IntToStr(_page);
}
//---------------------------------------------------------------------------

void __fastcall TfrmRejectTray::BitBtnNextClick(TObject *Sender)
{
	if(_page < 40) _page++;

	if(_page == 0) BitBtnPrev->Enabled = false;
	else BitBtnPrev->Enabled = true;	
	
	if(_page == 40) BitBtnNext->Enabled = false;
	else BitBtnNext->Enabled = true;	

	PanelPage->Caption = IntToStr(_page);	
}
//---------------------------------------------------------------------------

void __fastcall TfrmRejectTray::FormDestroy(TObject *Sender)
{
	if(!_panels.empty())
	{
		for(int i=0; i < _panels.size(); i++)
		{
			_panels.at(i)->FreeOnRelease();
			delete _panels.at(i);
		}
	}
	_panels.clear();
}
//---------------------------------------------------------------------------

