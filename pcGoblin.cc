#include "pcGoblin.h"
using namespace std;

/////*****Goblin*****/////
Goblin::Goblin(int row, int col)
	:PC{ row, col, 110, 15, 20, 0, "Goblin", 110, false } {}

Goblin::~Goblin() {}

void Goblin::attack(Figure * oppo) { //steals 5 gold for each killed enemy
	oppo->beAttacked(this); // WILL CHANGE ACTION
	bool kill = oppo->isDead();
	char c = oppo->getSymbol();
	if (kill) {
		if (c == 'W' || c == 'E' || c == 'O' || c == 'L') {
			int newMoney = this->getMoney() + oppo->getMoney() + 5;
			setMoney(newMoney);
			action = "PC killed " + oppo->getFigureType() + " and get " + to_string(oppo->getMoney()) + " and 5(additional) gold!";
		}
		else {
			int newMoney = this->getMoney() + 5;
			setMoney(newMoney);
			action = "PC killed " + oppo->getFigureType() + " and get 5(additional) gold!";
		}
	}
}

void Goblin::beAttacked(Figure * who) {
	int miss = generateRandom(1, 2); // 1 hurt, 2 safe
	int damage = 0;
	if (miss == 1) {
		damage = ((100 * who->getATK()) / (100 + this->getDEF())) + 1;
	}
	if (who->getSymbol() == 'O') { // damage 150% by Orc
		damage = damage + (damage / 2);
	}
	int newHP = getHP() - damage;
	if (newHP <= 0) {
		newHP = 0;
	}
	setHP(newHP);
	action += " PC was hurt by " + who->getFigureType() + " and loss " + to_string(damage) + " HP!";
}
/////*****Goblin*****/////


