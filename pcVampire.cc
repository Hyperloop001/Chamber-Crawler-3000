#include "pcVampire.h"
using namespace std;

/////*****Vampire*****/////
Vampire::Vampire(int row, int col)
	:PC{ row, col, 50, 25, 25, 0, "Vampire", -1, false } {}

Vampire::~Vampire(){}

void Vampire::attack(Figure * oppo) { //gain 5 HP for each succesful attack EXCEPT DWARF
	int oppoFormerHP = oppo->getHP();
	oppo->beAttacked(this); // WILL CHANGE ACTION
	int oppoLaterHP = oppo->getHP();
	bool gainHP = true;
	if (oppo->getSymbol() == 'W') {
		gainHP = false;
	}
	if ((oppoFormerHP != oppoLaterHP) && (gainHP)) {
		setHP(getHP() + 5);
	}
	if ((oppoFormerHP != oppoLaterHP) && (!gainHP)) {
		int newHP = getHP() - 5;
		if (newHP <= 0) {
			newHP = 0;
		}
		setHP(newHP);
	}
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

void Vampire::beAttacked(Figure * who) {
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
/////*****Vampire*****/////


