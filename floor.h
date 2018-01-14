#ifndef _floor_h_
#define _floor_h_
#include "global.h"
class TextDisplay;
class Thing;
class PC;
class Enemy;
class FloorTile;
class Gold;
class Potion;
class Enemy;

class Floor {
	std::vector<std::vector<Thing *>> gridOfThing; // The base of game pad
	//std::vector<std::vector<bool>> gridOfOccupancy; // The corresponding cell availability
	//std::vector<Enemy *> listOfEnemy; // List of enemy, used for tracking and moving enemy
	std::vector<FloorTile *> listOfRoom1; // List of coordinates of room 1
	std::vector<FloorTile *> listOfRoom2; // List of coordinates of room 2
	std::vector<FloorTile *> listOfRoom3; // List of coordinates of room 3
	std::vector<FloorTile *> listOfRoom4; // List of coordinates of room 4
	std::vector<FloorTile *> listOfRoom5; // List of coordinates of room 5
	std::vector<Gold *> listOfGold;
	std::vector<Potion *> listOfPotion;
	std::vector<Enemy *> listOfEnemy;
	TextDisplay * td; // Pointer to the display pad

	PC * player;
	const int width;
	const int height;

	int floorNumber;
	int playerStartRoom;
	int playerStartRow;
	int playerStartCol;
	bool enemyMovability;
	bool win;

	
public:
	Floor(PC * player, int floorNumber); // Basic ctor
	~Floor(); // Basic dtor

	/////*****initializing game pad*****/////
	void initializeFloor(std::ifstream & textFile); // initialize a floor from textFile
	void initializeFloor(); // initialize an cell floor along with same size text display
	void generatePlayer(); // generate the Player
	void generateStairway(); // generate the Stairway
	void generatePotion(); // generate the Potion
	void generateGold(); // generate the Gold
	void generateEnemy(); // generate the Enemy
	/////*****initializing game pad*****/////

	/////*****player action on game pad*****/////
	// Movement section:
	void movePlayer(std::string direction); // move Player around the pad (Will check if Player is movable)
	void checkAroundPlayer(); // Check around the Player and decide next action
	void playerAttack(std::string direction);
	void playerUsePotion(std::string direction);

	void randomMoveEnemy(); // randomly move the Enemy around the pad (Will check if Enemy is movable)
	bool enemyMovable(Enemy * e); // Check around the Enemy and decide whether enemy is movable
	/////*****player action on game pad*****/////

	/////*****Accessor*****/////
	std::vector<std::vector<Thing *>> & getGridOfThing();
	int getFloorNumber();
	int getWidth();
	int getHeight();
	void changeEnemyMovability();
	bool isWon(); // Return win value
	int getPlayerStartRow();
	int getPlayerStartCol();
	/////*****Accessor*****/////

	friend std::ostream & operator<<(std::ostream & out, Floor & f);
};



#endif



