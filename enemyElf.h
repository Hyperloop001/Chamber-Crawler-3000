#ifndef enemyElf_h
#define enemyElf_h
#include "enemy.h"

class Elf : public Enemy {
public:
	Elf(int row, int col);
	~Elf();
	void attack(Figure * oppo) override;
	void beAttacked(Figure * who) override;
	void beChecked(PC * player) override;
};


#endif



