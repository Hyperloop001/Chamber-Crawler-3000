#include "gold.h"

Gold::Gold(int row, int col, char symbol,int money, bool availability)
	:Item{ row, col, symbol}, money{ money }, availability{ availability } {}
Gold::~Gold() {}

int Gold::getMoney() {
	return money;
}

bool Gold::isAvailable() {
	return availability;
}

//Figure * Gold::getGuardian() {
//	return guardian;
//}

//void Gold::setGuardian(Figure * ptr) {
//	this->guardian = ptr;
//}



