#include "potionPH.h"
#include "pc.h"
using namespace std;

/////*****PoisonHealth*****/////
PoisonHealth::PoisonHealth(int row, int col)
	:Potion{ row, col, 'P',  -10 } {}

PoisonHealth::~PoisonHealth() {}

void PoisonHealth::beConsumed(PC * user) {
	int x = -10;
	if (user->isMagnified()) {
		x = -15;
	}
	int value = user->getHP() + x;
	if (value <= 0) {
		user->setHP(0);
	}
	else {
		user->setHP(value);
	}
	user->action = "PC use PoisonHealth.";
}
/////*****PoisonHealth*****/////



