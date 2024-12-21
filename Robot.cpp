//---------------------------------------------------------------------------

#pragma hdrstop

#include "Robot.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Robot::Robot(String id, int size, int rmax, TForm* form){
	this->id = id;
	this->size = size;
	this->rmax = rmax;
	this->form = form;
	coord.x = 0;
	coord.y = 0;
}

Coord Robot::getPos(){
	return coord;
}

void Robot::genInitPos(){
	coord.x = size/2 + s.random(form->Width - (size + 16));
	coord.y = size/2 + s.random(form->Height - (size + 39));
}

Coord Robot::genTarPos(){
	int angle, r;
	Coord coord;
	angle = s.random(361);
	r = s.random(rmax + 1);
	coord.x = this->coord.x + r*(cos(angle));
	coord.y = this->coord.y + r*(sin(angle));
	if (coord.x < size/2){
		coord.x = size/2;
	} else if (coord.x > form->Width - (size/2 + 16)){
		coord.x = form->Width - (size/2 + 16);
	}
	if (coord.y < (size/2 + 5)){
		coord.y = size/2 + 5;
	} else if (coord.y > form->Height - (size/2 + 39)) {
		coord.y = form->Height - (size/2 + 39);
	}
	return coord;
}

bool Robot::checkDist(Coord coord){
	double dist = pow((pow(coord.x - this->coord.x, 2) + pow(coord.y - this->coord.y, 2)),0.5);
	return dist <= size;
}

void Robot::showRobot(){
	shape = Utils::confShape(shape, coord, size, form);
	label1 = Utils::confLabel1(label1, coord, id, form);
	label2 = Utils::confLabel2(label2, coord, form);
	label3 = Utils::confLabel3(label3, coord, form);
}

void Robot::moveRobot(Coord coord){
	this->coord = coord;
	Utils::updShape(shape, coord, size);
	Utils::updLabel1(label1, coord);
	Utils::updLabel2(label2, coord);
	Utils::updLabel3(label3, coord);
	shape->Update();
}

void Robot::setColor(int R, int G, int B){
	shape->Brush->Color = (TColor)RGB(R, G, B);
}
