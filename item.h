#ifndef ITEM_H
#define ITEM_H
#include "global.h"
#include "thing.h"

class Item : public Thing{
public:
	virtual void beConsumed(PC * user) = 0;

	Item(int row, int col, char symbol);
	~Item()=0;
};

#endif


