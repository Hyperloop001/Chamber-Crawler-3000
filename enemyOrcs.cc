#include "enemyOrcs.h"
#include "pc.h"
using namespace std;

/////*****Orcs*****/////
Orcs::Orcs(int row, int col)
	:Enemy(row, col, 'O', 180, 30, 25, 0, "Orcs") {
	setMoney(generateRandom(1, 2));
}

Orcs::~Orcs() {}

void Orcs::attack(Figure * oppo) {
	oppo->beAttacked(this);
}//does 50% more damage to goblin

void Orcs::beAttacked(Figure * who) {
	int damage = ((100 * who->getATK()) / (100 + this->getDEF())) + 1;
	int newHP = getHP() - damage;
	if (newHP <= 0) {
		newHP = 0;
	}
	setHP(newHP);
	who->action = "PC deals " + to_string(damage) + " damage to Orcs(HP: " + to_string(newHP) + ")!";
}

void Orcs::beChecked(PC * player) {
	this->attack(player);
}
/////*****Orcs*****/////


