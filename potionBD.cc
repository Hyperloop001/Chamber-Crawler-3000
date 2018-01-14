#include "potionBD.h"
#include "pc.h"
using namespace std;

/////*****BoostDEF*****/////
BoostDEF::BoostDEF(int row, int col)
	:Potion{ row, col, 'P', 5 } {}

BoostDEF::~BoostDEF() {}

void BoostDEF::beConsumed(PC * user) {
	int x = 5;
	if (user->isMagnified()) {
		x = 7;
	}
	int value = user->getDEF() + x;
	user->setDEF(value);
	user->action = "PC use BoostDEF.";
}
/////*****BoostDEF*****/////



