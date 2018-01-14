#include "potion.h"
#include "pc.h"

Potion::Potion(int row, int col, char symbol, int magnitude)
	:Item{ row, col, symbol}, magnitude{ magnitude } {}

Potion::~Potion() {}

int Potion::getMagnitude(){
	return magnitude;
}

void Potion::beChecked(PC * player) {
	player->action += " Player meet an unknown potion.";
}




