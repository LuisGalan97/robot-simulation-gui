//---------------------------------------------------------------------------

#pragma hdrstop

#include "Field.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Coord Field::baseX(Coord curPos, Coord tarPos, double m, int b){
	(curPos.x > tarPos.x) ? curPos.x-- : curPos.x++;
	curPos.y = m*curPos.x + b;
	return curPos;
}

Coord Field::baseY(Coord curPos, Coord tarPos, double m, int b){
	(curPos.y > tarPos.y) ? curPos.y-- : curPos.y++;
	curPos.x = (m < 10000) ? (curPos.y - b)/m : curPos.x;
	return curPos;
}

Field::Field(int n, int size, int rmax, TForm* form){
	this->n = n;
	robot = new Robot*[n];
	active = false;
	initRobots(size, rmax, form);
	genPosRobots();
	showRobots();
}

void Field::initRobots(int size, int rmax, TForm* form){
	for(int i = 0; i < n; i++){
		robot[i] = new Robot((String)(i + 1), size, rmax, form);
	}
}

void Field::genPosRobots(){
	for(int i = 0; i < n; i++){
		robot[i]->genInitPos();
		if(i > 0){
			for(int j = 0; j < i; j++){
				if(robot[j]->checkDist(robot[i]->getPos())){
					i--;
					break;
				}
			}
		}
	}
}

void Field::showRobots(){
	for(int i = 0; i < n; i++){
		robot[i]->showRobot();
	}
}

void Field::moveRobots(){
	for(int i = 0; i < n; i++){
		Coord curPos = robot[i]->getPos();
		Coord tarPos = robot[i]->genTarPos();
		double deltaY = (double)(tarPos.y - curPos.y);
		double deltaX = (double)(tarPos.x - curPos.x);
		double m = (tarPos.x != curPos.x) ? deltaY/deltaX : 10000;
		int b = curPos.y - m*curPos.x;
		while((curPos.x != tarPos.x) && (curPos.y != tarPos.y)){
			Coord newPos = (abs(m) <= 1) ? baseX(curPos , tarPos, m, b) : baseY(curPos, tarPos, m, b);
			for(int j = 0; j < n; j++){
				if (i != j){
					if(robot[j]->checkDist(newPos)){
						robot[i]->setColor(255,0,0);
						tarPos = curPos;
						break;
					}
				}
				if (j == n - 1){
					robot[i]->moveRobot(newPos);
					curPos = robot[i]->getPos();
				}
			}
		}
	}
}

void Field::setActive(bool active){
	this->active = active;
}

bool Field::getActive(){
	return active;
}
