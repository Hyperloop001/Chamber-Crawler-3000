#ifndef cellFloorTile_h
#define cellFloorTile_h
#include "global.h"
#include "cell.h"

class FloorTile : public Cell {
	int roomNumber;
public:
	FloorTile(int row, int col, int roomNumber);
	~FloorTile();
	int getRoomNumber();
};



#endif


