#ifndef figure_h
#define figure_h
#include "global.h"
#include "thing.h"

class Figure : public Thing{
	int HP;
	int ATK;
	int DEF;
	int money;
	std::string figureType;
public:
	std::string action;

	int getHP();
	int getATK();
	int getDEF();
	int getMoney();
	std::string getFigureType();
	void setHP(int value);
	void setATK(int value);
	void setDEF(int value);
	void setMoney(int value);
	bool isDead();
	virtual void attack(Figure * oppo)=0;
	virtual void beAttacked(Figure * who)=0;
	virtual int returnScore();
	//void move(std::string direction);

	Figure(int row, int col, char symbol, 
		int HP, int ATK, int DEF, int money, std::string figureType);
	~Figure()=0;

	
};

#endif



