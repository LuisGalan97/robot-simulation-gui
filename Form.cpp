//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Form.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Field* field = nullptr;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	Form1->Position = poScreenCenter;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseWheel(TObject *Sender, TShiftState Shift, int WheelDelta,
          TPoint &MousePos, bool &Handled)
{
	if ((field != nullptr) && (!field->getActive())) {
		field->setActive(true);
		ThreadF* threadF = new ThreadF(field);
		threadF->Start();
	}
}
//---------------------------------------------------------------------------}


void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if (!Validations::checkInt(Edit1)) return;
	int n = Edit1->Text.ToInt();
	Form1->Width = 1200;
	Form1->Height = 700;
	Form1->Position = poScreenCenter;
	Form1->BorderIcons = Form1->BorderIcons << biMaximize;
	Form1->BorderStyle = bsSizeable;
	Label1->Visible = false;
	Label2->Visible = false;
	Label3->Visible = false;
	Edit1->Visible = false;
	Button1->Visible = false;
	field = new Field(n, 75, 200, this);
	ShowMessage("¡La simulacion ha iniciado!\nPara mover los robots debes usar la rueda del raton.");
}
//---------------------------------------------------------------------------

