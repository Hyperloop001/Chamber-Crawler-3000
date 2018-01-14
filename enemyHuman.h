#ifndef enemyHuman_h
#define enemyHuman_h
#include "enemy.h"

class Human : public Enemy {
public:
	Human(int row, int col);
	~Human();
	void attack(Figure * oppo) override;
	void beAttacked(Figure * who) override;
	void beChecked(PC * player) override;
};


#endif





