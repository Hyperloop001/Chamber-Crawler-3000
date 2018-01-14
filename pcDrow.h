#ifndef pcDrow_h
#define pcDrow_h
#include "global.h"
#include "pc.h"

class Drow : public PC {
public:
	Drow(int row, int col);
	~Drow();
	void attack(Figure * oppo) override;
	void beAttacked(Figure * who) override;
};



#endif



