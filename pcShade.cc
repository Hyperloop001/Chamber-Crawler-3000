#include "pcShade.h"
using namespace std;

/////*****Shade*****/////
Shade::Shade(int row, int col)
	: PC{ row, col, 125, 25, 25, 0, "Shade", 125, false } {}

Shade::~Shade() {}

void Shade::attack(Figure * oppo) {
	oppo->beAttacked(this); // WILL CHANGE ACTION
	bool kill = oppo->isDead();
	char c = oppo->getSymbol();
	if (kill) {
		if (c == 'W' || c == 'E' || c == 'O' || c == 'L') {
			int newMoney = this->getMoney() + oppo->getMoney();
			setMoney(newMoney);
			action = "PC killed " + oppo->getFigureType() + " and get " + to_string(oppo->getMoney()) + " gold!";
		}
		else {
			action = "PC killed " + oppo->getFigureType() + "!";
		}
	}
}

void Shade::beAttacked(Figure * who) {
	int miss = generateRandom(1, 2); // 1 hurt, 2 safe
	int damage = 0;
	if (miss == 1) {
		damage = ((100 * who->getATK()) / (100 + this->getDEF())) + 1;
	}
	int newHP = getHP() - damage;
	if (newHP <= 0) {
		newHP = 0;
	}
	setHP(newHP);
	action += " PC was hurt by " + who->getFigureType() + " and loss " + to_string(damage) + " HP!";
}

int Shade::returnScore() {
	int m = this->getMoney();
	//cout << "1.5 magnified for Shade!" << endl;
	return m + (m / 2);
}


/////*****Shade*****/////


