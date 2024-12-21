//---------------------------------------------------------------------------

#pragma hdrstop

#include "Semilla.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Semilla::Semilla() {
	std::random_device rd;
	auto seed = rd() ^ static_cast<unsigned int>(time(nullptr));
	generator.seed(seed);
}

int Semilla::random(int max) {
	std::uniform_int_distribution<> dis(0, max - 1);
	return dis(generator);
}
