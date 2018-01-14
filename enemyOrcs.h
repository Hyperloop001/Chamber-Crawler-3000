#ifndef enemyOrcs_h
#define enemyOrcs_h
#include "enemy.h"

class Orcs : public Enemy {
public:
	Orcs(int row, int col);
	~Orcs();
	void attack(Figure * oppo) override;
	void beAttacked(Figure * who) override;
	void beChecked(PC * player) override;
};


#endif


