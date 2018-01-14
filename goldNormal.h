#ifndef goldNormal_h
#define goldNormal_h
#include "global.h"
#include "gold.h"

class Normal : public Gold {
public:
	void beConsumed(PC * user) override;

	Normal(int row, int col);
	~Normal();
};

#endif



