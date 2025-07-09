//---------------------------------------------------------------------------

#ifndef FrmImageListScrnH
#define FrmImageListScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ImgList.hpp>
//---------------------------------------------------------------------------
class TFrmImageList : public TForm
{
__published:	// IDE-managed Components
    TImageList *ImageList1;
    TImageList *ImageList24Disable;
private:	// User declarations
public:		// User declarations
    __fastcall TFrmImageList(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmImageList *FrmImageList;
//---------------------------------------------------------------------------
#endif
