#include "enemyHalfling.h"
#include "pc.h"
using namespace std;

/////*****Halfling*****/////
Halfling::Halfling(int row, int col)
	:Enemy(row, col, 'L', 100, 15, 20, 0, "Halfling") {
	setMoney(generateRandom(1, 2));
}

Halfling::~Halfling() {}

void Halfling::attack(Figure * oppo) {
	oppo->beAttacked(this);
}

void Halfling::beAttacked(Figure * who) {
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
	who->action = "PC deals " + to_string(damage) + " damage to Halfling(HP: " + to_string(newHP) + ")!";
}//has 50% chance to cause the player to miss

void Halfling::beChecked(PC * player) {
	this->attack(player);
}
 /////*****Halfling*****/////


