#include "pcTroll.h"
using namespace std;

/////*****Troll*****/////
Troll::Troll(int row, int col)
	:PC{ row, col, 120, 25, 15, 0, "Troll", 120, false } {}

Troll::~Troll() {}

void Troll::attack(Figure * oppo) { //regain 5 HP each turn, maximize at 120
	oppo->beAttacked(this); // WILL CHANGE ACTION
	int newHP = getHP() + 5;
	if (newHP >= getMaxHP()) {
		newHP = getMaxHP();
	}
	setHP(newHP);
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

void Troll::beAttacked(Figure * who) {
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
/////*****Troll*****/////


