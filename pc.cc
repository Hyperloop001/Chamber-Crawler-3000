#include "pc.h"
#include "potion.h"
#include "gold.h"
using namespace std;


PC::PC(int row, int col, int HP, int ATK, int DEF, int money, std::string figureType,
	int maxHP, bool magnified)
	:Figure{ row, col, '@', HP, ATK, DEF, money, figureType}, 
	maxHP{ maxHP }, magnified{ magnified } {}

PC::~PC(){}

void PC::addMoney(int value){
	setMoney(getMoney() + value);
	action += " PC add " + to_string(value) + " gold!";
}

void PC::consumePotion(Potion * target){
	target->beConsumed(this);
}

void PC::consumeGold(Gold * target) {
		target->beConsumed(this);
}

int PC::getMaxHP() {
	return maxHP;
}
bool PC::isMagnified() {
	return magnified;
}


