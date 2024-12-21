//---------------------------------------------------------------------------

#ifndef UtilsH
#define UtilsH

#include "Coord.h"
//---------------------------------------------------------------------------
class Utils {
	public:
		static TShape* confShape(TShape* shape, Coord coord, int size, TForm* form);
		static void updShape(TShape* shape, Coord coord, int size);
		static TLabel* confLabel1(TLabel* label, Coord coord, String id, TForm* form);
		static void updLabel1(TLabel* label, Coord coord);
		static TLabel* confLabel2(TLabel* label, Coord coord, TForm* form);
		static void updLabel2(TLabel* label, Coord coord);
		static TLabel* confLabel3(TLabel* label, Coord coord, TForm* form);
		static void updLabel3(TLabel* label, Coord coord);
};
#endif
