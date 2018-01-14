#ifndef enemyMerchant_h
#define enemyMerchant_h
#include "enemy.h"

class Merchant : public Enemy {
	static bool merchantFriend;
public:
	Merchant(int row, int col);
	~Merchant();
	void attack(Figure * oppo) override;
	void beAttacked(Figure * who) override;
	bool isFriendly() override;
	void beChecked(PC * player) override;
};


#endif


