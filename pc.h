#ifndef pc_h
#define pc_h
#include "global.h"
#include "figure.h"
class Potion;
class Gold;

class PC : public Figure{
	int maxHP;
	bool magnified;
public:
	PC(int row, int col, int HP, int ATK, int DEF, int money, std::string figureType,
		int maxHP, bool magnified);
	virtual ~PC() = 0;

	int getMaxHP();
	bool isMagnified();
	void addMoney(int value); 
	void consumeGold(Gold * target);
	void consumePotion(Potion * target);
	
};

#endif



