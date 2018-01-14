#include "potionWA.h"
#include "pc.h"
using namespace std;

/////*****WoundATK*****/////
WoundATK::WoundATK(int row, int col)
	:Potion{ row, col, 'P', -5 } {}

WoundATK::~WoundATK() {}

void WoundATK::beConsumed(PC * user) {
	int x = -5;
	if (user->isMagnified()) {
		x = -7;
	}
	int value = user->getATK() + x;
	if (value <= 0) {
		user->setATK(0);
	}
	else {
		user->setATK(value);
	}
	user->action = "PC use WoundATK.";
}
/////*****WoundATK*****/////



