#include "enemyHuman.h"
#include "pc.h"
using namespace std;

/////*****Human*****/////
Human::Human(int row, int col)
	: Enemy(row, col, 'H', 140, 20, 20, 0, "Human") {}

Human::~Human() {}

void Human::attack(Figure * oppo) {
	oppo->beAttacked(this);
}

void Human::beAttacked(Figure * who) {
	int damage = ((100 * who->getATK()) / (100 + this->getDEF())) + 1;
	int newHP = getHP() - damage;
	if (newHP <= 0) {
		newHP = 0;
	}
	setHP(newHP);
	who->action = "PC deals " + to_string(damage) + " damage to Human(HP: " + to_string(newHP) + ")!";
}

void Human::beChecked(PC * player) {
	this->attack(player);
}
/////*****Human*****/////



