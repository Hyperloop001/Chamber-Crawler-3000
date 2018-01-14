#include "goldNormal.h"
#include "pc.h"
using namespace std;

/////*****Normal*****/////
void Normal::beConsumed(PC * user) {
	user->addMoney(this->getMoney());
}

Normal::Normal(int row, int col)
	:Gold{ row, col, 'G', 2, true } {}

Normal::~Normal() {}
/////*****Normal*****/////



