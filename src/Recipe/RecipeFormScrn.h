//---------------------------------------------------------------------------

#ifndef RecipeFormScrnH
#define RecipeFormScrnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------

#define RECIPE_SUB_FORM		1

class TRecipeForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TComboBox *ComboBoxAccessLevel;
	TPanel *Panel2;
	TBitBtn *BitBtn6;
	TBitBtn *RecipeFrmSub1;
	TPanel *RecipeBasePanel;
	TBitBtn *BitBtn2;
	void __fastcall RecipeFrmSub1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
    TForm* _pCurrentForm;

public:		// User declarations
	void	ScreenChange(String menu);

	__fastcall TRecipeForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TRecipeForm *RecipeForm;
//---------------------------------------------------------------------------
#endif
