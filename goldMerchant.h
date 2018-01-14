#ifndef goldMerchant_h
#define goldMerchant_h
#include "global.h"
#include "gold.h"

class MerchantHoard : public Gold {
public:
	void beConsumed(PC * user) override;

	MerchantHoard(int row, int col);
	~MerchantHoard();
};

#endif



