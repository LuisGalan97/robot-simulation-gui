//---------------------------------------------------------------------------

#ifndef SeedH
#define SeedH

#include <random>
//---------------------------------------------------------------------------
class Seed{
	private:
		std::mt19937 generator;

	public:
        Seed();
    	int random(int max);
};
#endif
