#ifndef pcVampire_h
#define pcVampire_h
#include "global.h"
#include "pc.h"

class Vampire : public PC {
public:
	Vampire(int row, int col);
	~Vampire();
	void attack(Figure * oppo) override;
	void beAttacked(Figure * who) override;
};



#endif



