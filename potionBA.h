#ifndef potionBA_h
#define potionBA_h
#include "global.h"
#include "potion.h"
class PC;

class BoostATK : public Potion {
public:
	BoostATK(int row, int col);
	~BoostATK();
	void beConsumed(PC * user) override;
};


#endif


