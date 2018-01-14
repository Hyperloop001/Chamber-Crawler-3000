#ifndef _thing_h_
#define _thing_h_
#include "subject.h"
class Observer;
class PC;

// Abstract class Thing: The common name of all elements in the game
class Thing : public Subject {
protected:
	int row;
	int col;
	char symbol;
public:
	Thing(int row, int col, char symbol); // Basic ctor
	virtual ~Thing() = 0; // Basic dtor

	// getRow() returns the row
	int getRow();
	// getCol() returns the column
	int getCol();
	// getSymbol() returns the represented symbol
	char getSymbol();

	void setRow(int r);
	void setCol(int c);

	virtual void beChecked(PC * player);
	//Virtual
	//virtual void beConsumed(PC * user);
	//virtual bool isAvailable();
	//virtual bool isFriendly();

	void notifyObserver(Observer * o) override;
};


#endif




