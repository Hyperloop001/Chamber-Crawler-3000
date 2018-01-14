#ifndef goldDragon_h
#define goldDragon_h
#include "global.h"
#include "gold.h"
class Floor;

class DragonHoard : public Gold {
	Floor * locatedFloor;
public:
	void beConsumed(PC * user) override;

	DragonHoard(int row, int col, Floor * locatedFloor);
	~DragonHoard();
	bool isAvailable() override;

	void beChecked(PC * player) override;
};

#endif



