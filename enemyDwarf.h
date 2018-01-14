#ifndef enemyDwarf_h
#define enemyDwarf_h
#include "enemy.h"
class PC;

class Dwarf : public Enemy {
public:
	Dwarf(int row, int col);
	~Dwarf();
	void attack(Figure * oppo) override;
	void beAttacked(Figure * who) override;
	void beChecked(PC * player) override;
};


#endif



