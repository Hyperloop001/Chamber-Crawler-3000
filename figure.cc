#include "figure.h"
using namespace std;


Figure::Figure(int row, int col, char symbol,
	int HP, int ATK, int DEF, int money, string figureType)
	:Thing{ row, col, symbol},
	HP{ HP }, ATK{ ATK }, DEF{ DEF }, money{ money }, figureType{ figureType }, 
	action{ "Player character has been spawned" } {}

Figure::~Figure() {}

int Figure::getHP() {
	return this->HP;
}

int Figure::getATK() {
	return this->ATK;
}

int Figure::getDEF() {
	return this->DEF;
}

int Figure::getMoney() {
	return this->money;
}

string Figure::getFigureType() {
	return this->figureType;
}

bool Figure::isDead() {
	return (this->getHP() <= 0);
}

void Figure::setHP(int value) {
	this->HP = value;
}

void Figure::setATK(int value) {
	this->ATK = value;
}

void Figure::setDEF(int value) {
	this->DEF = value;
}

void Figure::setMoney(int value) {
	this->money = value;
}

int Figure::returnScore() {
	return money;
}




