#ifndef _cell_h_
#define _cell_h_
#include "global.h"
#include "thing.h"

// Abstract class Cell, common name for all structure of the floor
class Cell : public Thing {
public:
	Cell(int row, int col, char symbol); // Basic ctor
	virtual ~Cell() = 0; // Basic dtor
						 
    // disappear() that notify the textDisplay to change into a floor tile
	//virtual void disappear();

};


#endif



