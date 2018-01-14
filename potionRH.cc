#include "potionRH.h"
#include "pc.h"
using namespace std;

/////*****RestoreHealth*****/////
RestoreHealth::RestoreHealth(int row, int col)
	:Potion{ row, col, 'P',  10 } {}

RestoreHealth::~RestoreHealth() {}

void RestoreHealth::beConsumed(PC * user) {
	int x = 10;
	if (user->isMagnified()) {
		x = 15;
	}
	int value = user->getHP() + x;
	if (value >= user->getMaxHP() && user->getMaxHP() >= 0) {
		user->setHP(user->getMaxHP());
	}
	else {
		user->setHP(value);
	}
	user->action = "PC use RestoreHealth.";
}
/////*****RestoreHealth*****/////




