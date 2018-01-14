#include "goldMerchant.h"
#include "pc.h"
using namespace std;

/////*****MerchantHoard*****/////
void MerchantHoard::beConsumed(PC * user) {
	user->addMoney(this->getMoney());
}

MerchantHoard::MerchantHoard(int row, int col)
	: Gold{ row, col, 'G', 4, true } {}

MerchantHoard::~MerchantHoard() {}
/////*****MerchantHoard*****/////



