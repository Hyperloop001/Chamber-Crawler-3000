#ifndef pcGoblin_h
#define pcGoblin_h
#include "global.h"
#include "pc.h"

class Goblin : public PC {
public:
	Goblin(int row, int col);
	~Goblin();
	void attack(Figure * oppo) override;
	void beAttacked(Figure * who) override;
};


#endif


