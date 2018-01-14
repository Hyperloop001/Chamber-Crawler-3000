#include "enemyDwarf.h"
#include "pc.h"
using namespace std;

/////*****Dwarf*****/////
Dwarf::Dwarf(int row, int col)
	: Enemy(row, col, 'W', 100, 20, 30, 0, "Dwarf") {
	setMoney(generateRandom(1, 2));
}

Dwarf::~Dwarf() {}

void Dwarf::attack(Figure * oppo) {
	oppo->beAttacked(this);
}

void Dwarf::beAttacked(Figure * who) {
	int damage = ((100 * who->getATK()) / (100 + this->getDEF())) + 1;
	int newHP = getHP() - damage;
	if (newHP <= 0) {
		newHP = 0;
	}
	setHP(newHP);
	who->action = "PC deals " + to_string(damage) + " damage to Dwarf(HP: " + to_string(newHP) + ")!";
}

void Dwarf::beChecked(PC * player) {
	this->attack(player);
}
/////*****Dwarf*****/////



