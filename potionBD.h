#ifndef potionBD_h
#define potionBD_h
#include "global.h"
#include "potion.h"
class PC;

class BoostDEF : public Potion {
public:
	BoostDEF(int row, int col);
	~BoostDEF();
	void beConsumed(PC * user) override;
};


#endif


