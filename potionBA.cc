#include "potionBA.h"
#include "pc.h"
using namespace std;

/////*****BoostATK*****/////
BoostATK::BoostATK(int row, int col)
	:Potion{ row, col, 'P', 5 } {}

BoostATK::~BoostATK() {}

void BoostATK::beConsumed(PC * user) {
	int x = 5;
	if (user->isMagnified()) {
		x = 7;
	}
	int value = user->getATK() + x;
	user->setATK(value);
	user->action = "PC use BoostATK.";
}
/////*****BoostATK*****/////


