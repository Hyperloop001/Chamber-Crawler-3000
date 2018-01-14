#ifndef goldSmall_h
#define goldSmall_h
#include "global.h"
#include "gold.h"

class Small : public Gold {
public:
	void beConsumed(PC * user) override;

	Small(int row, int col);
	~Small();
};

#endif





