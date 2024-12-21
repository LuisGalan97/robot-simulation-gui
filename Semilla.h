//---------------------------------------------------------------------------

#ifndef SemillaH
#define SemillaH

#include <random>
//---------------------------------------------------------------------------
class Semilla{
	private:
		std::mt19937 generator;

	public:
        Semilla();
    	int random(int max);
};
#endif
