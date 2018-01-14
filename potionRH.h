#ifndef potionRH_h
#define potionRH_h
#include "global.h"
#include "potion.h"
class PC;

class RestoreHealth : public Potion {
public:
	RestoreHealth(int row, int col);
	~RestoreHealth();
	void beConsumed(PC * user) override;
};


#endif


