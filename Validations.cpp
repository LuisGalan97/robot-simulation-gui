//---------------------------------------------------------------------------

#pragma hdrstop

#include "Validations.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

bool Validations::checkInt(TEdit* edit){
	if(edit->Text.Trim().IsEmpty()){
		ShowMessage("El campo no debe estar vacío.");
		edit->SetFocus();
		return false;
	}
	int temp;
	if (!TryStrToInt(edit->Text, temp)){
		ShowMessage("El campo debe contener un número válido entre 1 y 50.");
		edit->SetFocus();
		return false;
	}
	if (edit->Text.ToInt() < 1 || edit->Text.ToInt() > 50){
		ShowMessage("El campo debe contener un número válido entre 1 y 50.");
		edit->SetFocus();
		return false;
	}
	return true;
}
