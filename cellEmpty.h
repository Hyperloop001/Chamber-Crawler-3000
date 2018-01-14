#ifndef cellEmpty_h
#define cellEmpty_h
#include "global.h"
#include "cell.h"

class Empty : public Cell {
public:
	Empty(int row, int col);
	~Empty();
};



#endif



