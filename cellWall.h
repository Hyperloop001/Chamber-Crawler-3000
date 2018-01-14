#ifndef cellWall_h
#define cellWall_h
#include "global.h"
#include "cell.h"

class Wall : public Cell {
public:
	Wall(int row, int col, char symbol);
	~Wall();

};



#endif


