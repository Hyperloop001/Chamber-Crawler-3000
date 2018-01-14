#ifndef enemyHalfling_h
#define enemyHalfling_h
#include "enemy.h"

class Halfling : public Enemy {
public:
	Halfling(int row, int col);
	~Halfling();
	void attack(Figure * oppo) override;
	void beAttacked(Figure * who) override;
	void beChecked(PC * player) override;
};

#endif



