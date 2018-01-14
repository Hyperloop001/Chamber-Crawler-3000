#include "potionWD.h"
#include "pc.h"
using namespace std;

/////*****WoundDEF*****/////
WoundDEF::WoundDEF(int row, int col)
	:Potion{ row, col, 'P', -5 } {}

WoundDEF::~WoundDEF() {}

void WoundDEF::beConsumed(PC * user) {
	int x = -5;
	if (user->isMagnified()) {
		x = -7;
	}
	int value = user->getDEF() + x;
	if (value <= 0) {
		user->setDEF(0);
	}
	else {
		user->setDEF(value);
	}
	user->action = "PC use WoundDEF.";
}
/////*****WoundDEF*****/////



