#include "thing.h"
#include "observer.h"
using namespace std;



Thing::Thing(int row, int col, char symbol)
	:row{ row }, col{ col }, symbol{ symbol }{}

Thing::~Thing() {}


int Thing::getRow() {
	return row;
}

int Thing::getCol() {
	return col;
}

char Thing::getSymbol() {
	return symbol;
}

void Thing::setRow(int r) {
	this->row = r;
}
void Thing::setCol(int c) {
	this->col = c;
}

void Thing::notifyObserver(Observer * o) {
	//cout << "Notify observer" << endl; /////////////
	for (vector<Observer *>::iterator it = myObservers.begin(); it != myObservers.end(); ++it) {
		if ((*it) == o) {
			(*it)->beNotified(this);
			break;
		}
	}
}

void Thing::beChecked(PC * player) {
	return;
}

/*
void Thing::beConsumed(PC * user) {}

bool Thing::isAvailable(){
	return false;
}

bool Thing::isFriendly() {
	return false;
}
*/





