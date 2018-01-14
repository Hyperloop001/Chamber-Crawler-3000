#include "enemyMerchant.h"
#include "pc.h"
using namespace std;

/////*****Merchant*****/////
bool Merchant::merchantFriend = true;

Merchant::Merchant(int row, int col)
	:Enemy(row, col, 'M', 30, 70, 5, 0, "Merchant") {}

Merchant::~Merchant() {}

bool Merchant::isFriendly() {
	return Merchant::merchantFriend;
}

void Merchant::attack(Figure * oppo) {
	oppo->beAttacked(this);
}

void Merchant::beAttacked(Figure * who) {
	Merchant::merchantFriend = false;
	int damage = ((100 * who->getATK()) / (100 + this->getDEF())) + 1;
	int newHP = getHP() - damage;
	if (newHP <= 0) {
		newHP = 0;
	}
	setHP(newHP);
	who->action = "PC deals " + to_string(damage) + " damage to Merchant(HP: " + to_string(newHP) + ")!";
}

void Merchant::beChecked(PC * player) {
	if (!merchantFriend) {
		this->attack(player);
	}
}
/////*****Merchant*****/////


