#include "enemyElf.h"
#include "pc.h"
using namespace std;

/////*****Elf*****/////
Elf::Elf(int row, int col)
	:Enemy(row, col, 'E', 140, 30, 10, 0, "Elf") {
	setMoney(generateRandom(1, 2));
}

Elf::~Elf() {}

void Elf::attack(Figure * oppo) {
	oppo->beAttacked(this);
	if (oppo->getFigureType() != "Drow") {
		oppo->beAttacked(this);
	}
}//has two attacks against each race except drow

void Elf::beAttacked(Figure * who) {
	int damage = ((100 * who->getATK()) / (100 + this->getDEF())) + 1;
	int newHP = getHP() - damage;
	if (newHP <= 0) {
		newHP = 0;
	}
	setHP(newHP);
	who->action = "PC deals " + to_string(damage) + " damage to Elf(HP: " + to_string(newHP) + ")!";
}

void Elf::beChecked(PC * player) {
	this->attack(player);
}
/////*****Elf*****/////



