#ifndef potion_h
#define potion_h
#include "global.h"
#include "item.h"
class PC;

class Potion : public Item {
	int magnitude;
public:
	Potion(int row, int col, char symbol, int magnitude);
	virtual ~Potion();

	int getMagnitude();

	void beChecked(PC * player) override;

};

#endif



