#ifndef enemy_h
#define enemy_h
#include "global.h"
#include "figure.h"

class Enemy : public Figure{
public:
	virtual bool isFriendly();

	Enemy(int row, int col, char symbol, int HP, int ATK, int DEF, int money, std::string figureType);
	virtual ~Enemy()=0;
};

#endif


