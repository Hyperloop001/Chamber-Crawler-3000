#ifndef pcTroll_h
#define pcTroll_h
#include "global.h"
#include "pc.h"

class Troll : public PC {
public:
	Troll(int row, int col);
	~Troll();
	void attack(Figure * oppo) override;
	void beAttacked(Figure * who) override;
};



#endif


