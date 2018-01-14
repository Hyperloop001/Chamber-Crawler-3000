#ifndef potionWD_h
#define potionWD_h
#include "global.h"
#include "potion.h"
class PC;

class WoundDEF : public Potion {
public:
	WoundDEF(int row, int col);
	~WoundDEF();
	void beConsumed(PC * user) override;
};


#endif




