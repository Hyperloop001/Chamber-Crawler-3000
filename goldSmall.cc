#include "goldSmall.h"
#include "pc.h"
using namespace std;

/////*****Small*****/////
void Small::beConsumed(PC * user) {
	user->addMoney(this->getMoney());
}

Small::Small(int row, int col)
	:Gold{ row, col, 'G', 1, true } {}

Small::~Small() {}
/////*****Small*****/////



