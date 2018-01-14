#include "goldDragon.h"
#include "floor.h"
#include "pc.h"
#include "enemyDragon.h"
//#include "enemyDragon.h"
using namespace std;

/////*****DragonHoard*****/////
void DragonHoard::beConsumed(PC * user) {
	user->addMoney(this->getMoney());
}

DragonHoard::DragonHoard(int row, int col, Floor * locatedFloor)
	: Gold{ row, col, 'G', 6, false }, locatedFloor {locatedFloor} {}

DragonHoard::~DragonHoard() {}

bool DragonHoard::isAvailable() {
	int row = getRow();
	int col = getCol();
	vector<vector<Thing *>> & v = locatedFloor->getGridOfThing();
	if (v[row - 1][col - 1]->getSymbol() == 'D') {
		return false;
	}
	if (v[row - 1][col]->getSymbol() == 'D') {
		return false;
	}
	if (v[row - 1][col + 1]->getSymbol() == 'D') {
		return false;
	}
	if (v[row][col - 1]->getSymbol() == 'D') {
		return false;
	}
	if (v[row][col + 1]->getSymbol() == 'D') {
		return false;
	}
	if (v[row + 1][col - 1]->getSymbol() == 'D') {
		return false;
	}
	if (v[row + 1][col]->getSymbol() == 'D') {
		return false;
	}
	if (v[row + 1][col + 1]->getSymbol() == 'D') {
		return false;
	}
	//this->setGuardian(nullptr);
	return true;
}

void DragonHoard::beChecked(PC * player) {
	if (!isAvailable()) {
		Dragon * d = new Dragon{ 0,0 };
		player->beAttacked(d);
		delete d;
	}
}
/////*****DragonHoard*****/////



