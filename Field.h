//---------------------------------------------------------------------------

#ifndef FieldH
#define FieldH

#include "Coord.h"
#include "Robot.h"
#include "math.h"
//---------------------------------------------------------------------------
class Field{
	private:
		int n;
		Robot** robot;
		std::atomic<bool> active;
		Coord baseX(Coord curPos, Coord tarPos, double m, int b);
		Coord baseY(Coord curPos, Coord tarPos, double m, int b);

	public:
		Field(int n, int size, int rmax, TForm* form);
		void initRobots(int size, int rmax, TForm* form);
		void genPosRobots();
		void showRobots();
		void moveRobots();
		void setActive(bool active);
		bool getActive();
};
#endif
