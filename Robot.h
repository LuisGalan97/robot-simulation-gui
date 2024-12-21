//---------------------------------------------------------------------------

#ifndef RobotH
#define RobotH

#include "Seed.h"
#include "Coord.h"
#include "Utils.h"
#include "math.h"
//---------------------------------------------------------------------------
class Robot{
	private:
        Seed s;
		Coord coord;
		String id;
		int size;
        int rmax;
        TForm* form;
		TShape* shape;
		TLabel* label1;
		TLabel* label2;
		TLabel* label3;

	public:
		Robot(String id, int size, int rmax, TForm* form);
		Coord getPos();
		void genInitPos();
		Coord genTarPos();
		bool checkDist(Coord coord);
		void showRobot();
		void moveRobot(Coord coord);
		void setColor(int r, int g, int b);
};
#endif
