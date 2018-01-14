#include "enemy.h"
using namespace std;

bool Enemy::isFriendly() {
	return false;
}

Enemy::Enemy(int row, int col, char symbol, int HP, int ATK, int DEF, int money, std::string figureType)
	:Figure{ row, col, symbol, HP, ATK, DEF, money, figureType } {}

Enemy::~Enemy(){}




