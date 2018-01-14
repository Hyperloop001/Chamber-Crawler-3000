#ifndef potionWA_h
#define potionWA_h
#include "global.h"
#include "potion.h"
class PC;

class WoundATK : public Potion {
public:
	WoundATK(int row, int col);
	~WoundATK();
	void beConsumed(PC * user) override;
};


#endif



