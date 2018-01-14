#ifndef potionPH_h
#define potionPH_h
#include "global.h"
#include "potion.h"
class PC;

class PoisonHealth : public Potion {
public:
	PoisonHealth(int row, int col);
	~PoisonHealth();
	void beConsumed(PC * user) override;
};


#endif


