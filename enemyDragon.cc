#include "enemyDragon.h"
#include "pc.h"
using namespace std;

/////*****Dragon*****/////
Dragon::Dragon(int row, int col)
	:Enemy(row, col, 'D', 150, 20, 20, 0, "Dragon") {}

Dragon::~Dragon() {}

void Dragon::attack(Figure * oppo) {
	oppo->beAttacked(this);
}

void Dragon::beAttacked(Figure * who) {
	int damage = ((100 * who->getATK()) / (100 + this->getDEF())) + 1;
	int newHP = getHP() - damage;
	if (newHP <= 0) {
		newHP = 0;
	}
	setHP(newHP);
	who->action = "PC deals " + to_string(damage) + " damage to Dragon(HP: " + to_string(newHP) + ")!";
}

void Dragon::beChecked(PC * player) {
	this->attack(player);
}
/////*****Dragon*****/////


