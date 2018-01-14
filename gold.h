#ifndef GOLD_H
#define GOLD_H

#include "item.h"
class PC;
class Figure;

class Gold : public Item {
	int money;
	bool availability;
	//Figure * guardian;
public:
	int getMoney();
	virtual bool isAvailable();
	//Figure * getGuardian();
	//void setGuardian(Figure * ptr);

	Gold(int row, int col, char symbol, int money, bool availability);
	virtual ~Gold() = 0;
};


#endif


