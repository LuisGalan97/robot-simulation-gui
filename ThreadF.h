//---------------------------------------------------------------------------

#ifndef ThreadFH
#define ThreadFH

#include "Field.h"
//---------------------------------------------------------------------------
class ThreadF : public TThread {
	private:
		Field* field;

	protected:
		void __fastcall Execute() override;

	public:
		__fastcall ThreadF(Field* field);
};
#endif
