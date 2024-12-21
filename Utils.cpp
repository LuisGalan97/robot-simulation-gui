//---------------------------------------------------------------------------

#pragma hdrstop

#include "Utils.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TShape* Utils::confShape(TShape* shape, Coord coord, int size, TForm* form){
	shape = new TShape(form);
	shape->Parent = form;
	shape->Shape = stCircle;
	shape->Height = size;
	shape->Width = size;
	shape->Left = coord.x - size/2;
	shape->Top = coord.y - size/2;
	shape->Brush->Color = (TColor)RGB(0, 255, 0);
	return shape;
}

void Utils::updShape(TShape* shape, Coord coord, int size){
	shape->Left = coord.x - size/2;
	shape->Top = coord.y - size/2;
	shape->Brush->Color = (TColor)RGB(0, 255, 0);
}

TLabel* Utils::confLabel1(TLabel* label, Coord coord, String id, TForm* form){
	label = new TLabel(form);
	label->Parent = form;
	label->Left = coord.x - 17;
	label->Top = coord.y - 20;
	label->Caption = "Robot " + id;
	return label;
}

void Utils::updLabel1(TLabel* label, Coord coord){
	label->Left = coord.x - 17;
	label->Top = coord.y - 20;
}

TLabel* Utils::confLabel2(TLabel* label, Coord coord, TForm* form){
	label = new TLabel(form);
	label->Parent = form;
	label->Left = coord.x - 17;
	label->Top = coord.y - 7;
	label->Caption = "x = " + (String)(coord.x);
	return label;
}

void Utils::updLabel2(TLabel* label, Coord coord){
	label->Left = coord.x - 17;
	label->Top = coord.y - 7;
	label->Caption = "x = " + (String)(coord.x);
}

TLabel* Utils::confLabel3(TLabel* label, Coord coord, TForm* form){
	label = new TLabel(form);
	label->Parent = form;
	label->Left = coord.x - 17;
	label->Top = coord.y + 5;
	label->Caption = "y = " + (String)(coord.y);
	return label;
}

void Utils::updLabel3(TLabel* label, Coord coord){
	label->Left = coord.x - 17;
	label->Top = coord.y + 5;
	label->Caption = "y = " + (String)(coord.y);
}