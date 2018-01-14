#ifndef enemyDragon_h
#define enemyDragon_h
#include "enemy.h"
class PC;

class Dragon : public Enemy {
public:
	Dragon(int row, int col);
	~Dragon();
	void attack(Figure * oppo) override;
	void beAttacked(Figure * who) override;
	void beChecked(PC * player) override;
};


#endif


