//---------------------------------------------------------------------------

#pragma hdrstop

#include "ThreadF.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void __fastcall ThreadF::Execute(){
	field->moveRobots();
	field->setActive(false);
}

__fastcall ThreadF::ThreadF(Field* field): TThread(true), field(field){
	FreeOnTerminate = true;
}
