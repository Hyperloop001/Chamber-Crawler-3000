#ifndef pcShade_h
#define pcShade_h
#include "global.h"
#include "pc.h"

class Shade : public PC {
public:
	Shade(int row, int col);
	~Shade();
	void attack(Figure * oppo) override;
	void beAttacked(Figure * who) override;
	int returnScore() override;
};


#endif



