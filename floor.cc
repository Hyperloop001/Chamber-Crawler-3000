#include "floor.h"
#include "textdisplay.h"
#include "thing.h"
#include "figure.h" // Figures
#include "globalPC.h"
#include "globalEnemy.h"
#include "item.h" // Items
#include "globalGold.h"
#include "globalPotion.h"
#include "globalCell.h" // Cells
#include <stdlib.h>
#include <time.h>
#include "random.h"

using namespace std;

Floor::Floor(PC * player, int floorNumber)
	:td{ new TextDisplay() }, player{ player }, width{ 79 }, height{ 25 }, 
	floorNumber{ floorNumber }, playerStartRoom{ 0 }, playerStartRow{ 0 }, 
	playerStartCol{ 0 }, enemyMovability{ true }, win{ false } {}

Floor::~Floor() { // Have to delete player by user
	player->DetachObserver(td);
	delete td;
	for (vector<vector<Thing *>>::iterator it1 = gridOfThing.begin(); it1 != gridOfThing.end(); ++it1) {
		for (vector<Thing *>::iterator it2 = (*it1).begin(); it2 != (*it1).end(); ++it2) {
			delete (*it2);
		}
	}
}

void Floor::initializeFloor(std::ifstream & textFile) {
	//cout << "File initialize" << endl; ////////////////////////////////////////////
	for (int i = 0; i < this->height; i++) {
		vector<Thing *> lineOfThing;
		vector<char> lineOfChar;
		string newLine;
		getline(textFile, newLine);
		for (int j = 0; j < this->width; j++) {
			char c = newLine[j];
			if (c == '@') { // Add PC to the floor
				FloorTile * ptr = new FloorTile{ i, j, 0 };
				ptr->attachObserver(td);
				lineOfThing.push_back(ptr);
				lineOfChar.push_back(c);
				player->setRow(i);
				player->setCol(j);
				this->playerStartRow = i;
				this->playerStartCol = j;
			}
			else if (c == '-') {
				Wall * ptr = new Wall{ i, j, '-' };
				ptr->attachObserver(td);
				lineOfThing.push_back(ptr);
				lineOfChar.push_back(c);
			}
			else if (c == '|') {
				Wall * ptr = new Wall{ i, j, '|' };
				ptr->attachObserver(td);
				lineOfThing.push_back(ptr);
				lineOfChar.push_back(c);
			}
			else if (c == ' ') {
				Empty * ptr = new Empty{ i, j };
				ptr->attachObserver(td);
				lineOfThing.push_back(ptr);
				lineOfChar.push_back(c);
			}
			else if (c == '.') {
				FloorTile * ptr = new FloorTile{ i, j, 0 };
				ptr->attachObserver(td);
				lineOfThing.push_back(ptr);
				lineOfChar.push_back(c);
			}
			else if (c == '#') {
				Passage * ptr = new Passage{ i, j };
				ptr->attachObserver(td);
				lineOfThing.push_back(ptr);
				lineOfChar.push_back(c);
			}
			else if (c == '+') {
				DoorWay * ptr = new DoorWay{ i, j};
				ptr->attachObserver(td);
				lineOfThing.push_back(ptr);
				lineOfChar.push_back(c);
			}
			else if (c == '0') {
				RestoreHealth * ptr = new RestoreHealth{ i, j};
				ptr->attachObserver(td);
				lineOfThing.push_back(ptr);
				lineOfChar.push_back('P');
				listOfPotion.push_back(ptr);
			}
			else if (c == '1') {
				BoostATK * ptr = new BoostATK{ i, j};
				ptr->attachObserver(td);
				lineOfThing.push_back(ptr);
				lineOfChar.push_back('P');
				listOfPotion.push_back(ptr);
			}
			else if (c == '2') {
				BoostDEF * ptr = new BoostDEF{ i, j};
				ptr->attachObserver(td);
				lineOfThing.push_back(ptr);
				lineOfChar.push_back('P');
				listOfPotion.push_back(ptr);
			}
			else if (c == '3') {
				PoisonHealth * ptr = new PoisonHealth{ i, j};
				ptr->attachObserver(td);
				lineOfThing.push_back(ptr);
				lineOfChar.push_back('P');
				listOfPotion.push_back(ptr);
			}
			else if (c == '4') {
				WoundATK * ptr = new WoundATK{ i, j};
				ptr->attachObserver(td);
				lineOfThing.push_back(ptr);
				lineOfChar.push_back('P');
				listOfPotion.push_back(ptr);
			}
			else if (c == '5') {
				WoundDEF * ptr = new WoundDEF{ i, j};
				ptr->attachObserver(td);
				lineOfThing.push_back(ptr);
				lineOfChar.push_back('P');
				listOfPotion.push_back(ptr);
			}
			else if (c == '6') {
				Normal * ptr = new Normal{ i, j};
				ptr->attachObserver(td);
				lineOfThing.push_back(ptr);
				lineOfChar.push_back('G');
				listOfGold.push_back(ptr);
			}
			else if (c == '7') {
				Small * ptr = new Small{ i, j};
				ptr->attachObserver(td);
				lineOfThing.push_back(ptr);
				lineOfChar.push_back('G');
				listOfGold.push_back(ptr);
			}
			else if (c == '8') {
				MerchantHoard * ptr = new MerchantHoard{ i, j};
				ptr->attachObserver(td);
				lineOfThing.push_back(ptr);
				lineOfChar.push_back('G');
				listOfGold.push_back(ptr);
			}
			else if (c == '9') {
				DragonHoard * ptr = new DragonHoard{ i, j, this};
				ptr->attachObserver(td);
				lineOfThing.push_back(ptr);
				lineOfChar.push_back('G');
				listOfGold.push_back(ptr);
				//listOfDragonHoard.push_back(ptr);
			}
			else if (c == 'H') {
				Human * ptr = new Human{ i, j};
				ptr->attachObserver(td);
				lineOfThing.push_back(ptr);
				lineOfChar.push_back(c);
				listOfEnemy.push_back(ptr);
			}
			else if (c == 'W') {
				Dwarf * ptr = new Dwarf{ i, j};
				ptr->attachObserver(td);
				lineOfThing.push_back(ptr);
				lineOfChar.push_back(c);
				listOfEnemy.push_back(ptr);
			}
			else if (c == 'E') {
				Elf * ptr = new Elf{ i, j};
				ptr->attachObserver(td);
				lineOfThing.push_back(ptr);
				lineOfChar.push_back(c);
				listOfEnemy.push_back(ptr);
			}
			else if (c == 'O') {
				Orcs * ptr = new Orcs{ i, j};
				ptr->attachObserver(td);
				lineOfThing.push_back(ptr);
				lineOfChar.push_back(c);
				listOfEnemy.push_back(ptr);
			}
			else if (c == 'M') {
				Merchant * ptr = new Merchant{ i, j};
				ptr->attachObserver(td);
				lineOfThing.push_back(ptr);
				lineOfChar.push_back(c);
				listOfEnemy.push_back(ptr);
			}
			else if (c == 'D') {
				Dragon * ptr = new Dragon{ i, j};
				ptr->attachObserver(td);
				lineOfThing.push_back(ptr);
				lineOfChar.push_back(c);
				listOfEnemy.push_back(ptr);
			}
			else if (c == 'L') {
				Halfling * ptr = new Halfling{ i, j};
				ptr->attachObserver(td);
				lineOfThing.push_back(ptr);
				lineOfChar.push_back(c);
				listOfEnemy.push_back(ptr);
			}
			else if (c == '\\') {
				StairWay * ptr = new StairWay{ i, j};
				ptr->attachObserver(td);
				lineOfThing.push_back(ptr);
				lineOfChar.push_back(c);
			}
			else {
				continue;
			}
		}
		gridOfThing.push_back(lineOfThing);
		td->theDisplay.push_back(lineOfChar);
	}
	player->attachObserver(td);
	player->notifyObserver(td);
}

void Floor::initializeFloor() {
	ifstream if_Default{ "emptyFloor.txt" };
	for (int i = 0; i < this->height; i++) {
		vector<Thing *> lineOfThing;
		vector<char> lineOfChar;
		string newLine;
		getline(if_Default, newLine);
		for (int j = 0; j < this->width; j++) {
			char c = newLine[j];
			if (c == '-') {
				Wall * ptr = new Wall{ i, j, '-' };
				ptr->attachObserver(td);
				lineOfThing.push_back(ptr);
				lineOfChar.push_back(c);
			}
			else if (c == '|') {
				Wall * ptr = new Wall{ i, j, '|' };
				ptr->attachObserver(td);
				lineOfThing.push_back(ptr);
				lineOfChar.push_back(c);
			}
			else if (c == ' ') {
				Empty * ptr = new Empty{ i, j};
				ptr->attachObserver(td);
				lineOfThing.push_back(ptr);
				lineOfChar.push_back(c);
			}
			else if (c == '#') {
				Passage * ptr = new Passage{ i, j};
				ptr->attachObserver(td);
				lineOfThing.push_back(ptr);
				lineOfChar.push_back(c);
			}
			else if (c == '+') {
				DoorWay * ptr = new DoorWay{ i, j};
				ptr->attachObserver(td);
				lineOfThing.push_back(ptr);
				lineOfChar.push_back(c);
			}
			else if (c == '1') {
				FloorTile * ptr = new FloorTile{ i, j, 1 };
				ptr->attachObserver(td);
				lineOfThing.push_back(ptr);
				lineOfChar.push_back('.');
				listOfRoom1.push_back(ptr); // Add this FloorTile to listOfRoom1
			}
			else if (c == '2') {
				FloorTile * ptr = new FloorTile{ i, j, 2 };
				ptr->attachObserver(td);
				lineOfThing.push_back(ptr);
				lineOfChar.push_back('.');
				listOfRoom2.push_back(ptr); // Add this FloorTile to listOfRoom2
			}
			else if (c == '3') {
				FloorTile * ptr = new FloorTile{ i, j, 3 };
				ptr->attachObserver(td);
				lineOfThing.push_back(ptr);
				lineOfChar.push_back('.');
				listOfRoom3.push_back(ptr); // Add this FloorTile to listOfRoom3
			}
			else if (c == '4') {
				FloorTile * ptr = new FloorTile{ i, j, 4 };
				ptr->attachObserver(td);
				lineOfThing.push_back(ptr);
				lineOfChar.push_back('.');
				listOfRoom4.push_back(ptr); // Add this FloorTile to listOfRoom4
			}
			else if (c == '5') {
				FloorTile * ptr = new FloorTile{ i, j, 5 };
				ptr->attachObserver(td);
				lineOfThing.push_back(ptr);
				lineOfChar.push_back('.');
				listOfRoom5.push_back(ptr); // Add this FloorTile to listOfRoom5
			}
			else {
				continue;
			}
		}
		gridOfThing.push_back(lineOfThing);
		td->theDisplay.push_back(lineOfChar);
	} // Finish of generating empty floor
	generatePlayer();
	generateStairway();
	generatePotion();
	generateGold();
	generateEnemy();
}

void Floor::generatePlayer() {
	this->playerStartRoom = generateRandom(1, 5);
	int r = 0;
	int c = 0;
	if (playerStartRoom == 1) {
		int numOfChoice = listOfRoom1.size();
		int finalChoice = generateRandom(0, numOfChoice - 1);
		r = (listOfRoom1[finalChoice])->getRow();
		c = (listOfRoom1[finalChoice])->getCol();
		listOfRoom1.erase(listOfRoom1.begin() + finalChoice);
	}
	else if (playerStartRoom == 2) {
		int numOfChoice = listOfRoom2.size();
		int finalChoice = generateRandom(0, numOfChoice - 1);
		r = (listOfRoom2[finalChoice])->getRow();
		c = (listOfRoom2[finalChoice])->getCol();
		listOfRoom2.erase(listOfRoom2.begin() + finalChoice);
	}
	else if (playerStartRoom == 3) {
		int numOfChoice = listOfRoom3.size();
		int finalChoice = generateRandom(0, numOfChoice - 1);
		r = (listOfRoom3[finalChoice])->getRow();
		c = (listOfRoom3[finalChoice])->getCol();
		listOfRoom3.erase(listOfRoom3.begin() + finalChoice);
	}
	else if (playerStartRoom == 4) {
		int numOfChoice = listOfRoom4.size();
		int finalChoice = generateRandom(0, numOfChoice - 1);
		r = (listOfRoom4[finalChoice])->getRow();
		c = (listOfRoom4[finalChoice])->getCol();
		listOfRoom4.erase(listOfRoom4.begin() + finalChoice);
	}
	else {
		int numOfChoice = listOfRoom5.size();
		int finalChoice = generateRandom(0, numOfChoice - 1);
		r = (listOfRoom5[finalChoice])->getRow();
		c = (listOfRoom5[finalChoice])->getCol();
		listOfRoom5.erase(listOfRoom5.begin() + finalChoice);
	}
	this->player->setRow(r);
	this->player->setCol(c);
	playerStartRow = r;////////////
	playerStartCol = c;////////////
	this->player->attachObserver(this->td);
	this->player->notifyObserver(this->td);
}

void Floor::generateStairway() {
	int stairRoom = 0;
	for (;;) {
		stairRoom = generateRandom(1, 5);
		if (stairRoom != this->playerStartRoom) break;
	}
	int r = 0;
	int c = 0;
	if (stairRoom == 1) {
		int numOfChoice = listOfRoom1.size();
		int finalChoice = generateRandom(0, numOfChoice - 1);
		r = (listOfRoom1[finalChoice])->getRow();
		c = (listOfRoom1[finalChoice])->getCol();
		listOfRoom1.erase(listOfRoom1.begin() + finalChoice);
	}
	else if (stairRoom == 2) {
		int numOfChoice = listOfRoom2.size();
		int finalChoice = generateRandom(0, numOfChoice - 1);
		r = (listOfRoom2[finalChoice])->getRow();
		c = (listOfRoom2[finalChoice])->getCol();
		listOfRoom2.erase(listOfRoom2.begin() + finalChoice);
	}
	else if (stairRoom == 3) {
		int numOfChoice = listOfRoom3.size();
		int finalChoice = generateRandom(0, numOfChoice - 1);
		r = (listOfRoom3[finalChoice])->getRow();
		c = (listOfRoom3[finalChoice])->getCol();
		listOfRoom3.erase(listOfRoom3.begin() + finalChoice);
	}
	else if (stairRoom == 4) {
		int numOfChoice = listOfRoom4.size();
		int finalChoice = generateRandom(0, numOfChoice - 1);
		r = (listOfRoom4[finalChoice])->getRow();
		c = (listOfRoom4[finalChoice])->getCol();
		listOfRoom4.erase(listOfRoom4.begin() + finalChoice);
	}
	else {
		int numOfChoice = listOfRoom5.size();
		int finalChoice = generateRandom(0, numOfChoice - 1);
		r = (listOfRoom5[finalChoice])->getRow();
		c = (listOfRoom5[finalChoice])->getCol();
		listOfRoom5.erase(listOfRoom5.begin() + finalChoice);
	}
	delete gridOfThing[r][c];
	StairWay * ptr = new StairWay{ r, c};
	gridOfThing[r][c] = ptr;
	ptr->attachObserver(this->td);
	ptr->notifyObserver(this->td);
}

void Floor::generatePotion() {
	for (int i = 0; i < 10; i++) {
		int potionRoom = generateRandom(1, 5);
		int r = 0;
		int c = 0;
		int potionType = generateRandom(1, 6);
		if (potionRoom == 1) {
			int numOfChoice = listOfRoom1.size();
			int finalChoice = generateRandom(0, numOfChoice - 1);
			r = (listOfRoom1[finalChoice])->getRow();
			c = (listOfRoom1[finalChoice])->getCol();
			listOfRoom1.erase(listOfRoom1.begin() + finalChoice);
		}
		else if (potionRoom == 2) {
			int numOfChoice = listOfRoom2.size();
			int finalChoice = generateRandom(0, numOfChoice - 1);
			r = (listOfRoom2[finalChoice])->getRow();
			c = (listOfRoom2[finalChoice])->getCol();
			listOfRoom2.erase(listOfRoom2.begin() + finalChoice);
		}
		else if (potionRoom == 3) {
			int numOfChoice = listOfRoom3.size();
			int finalChoice = generateRandom(0, numOfChoice - 1);
			r = (listOfRoom3[finalChoice])->getRow();
			c = (listOfRoom3[finalChoice])->getCol();
			listOfRoom3.erase(listOfRoom3.begin() + finalChoice);
		}
		else if (potionRoom == 4) {
			int numOfChoice = listOfRoom4.size();
			int finalChoice = generateRandom(0, numOfChoice - 1);
			r = (listOfRoom4[finalChoice])->getRow();
			c = (listOfRoom4[finalChoice])->getCol();
			listOfRoom4.erase(listOfRoom4.begin() + finalChoice);
		}
		else {
			int numOfChoice = listOfRoom5.size();
			int finalChoice = generateRandom(0, numOfChoice - 1);
			r = (listOfRoom5[finalChoice])->getRow();
			c = (listOfRoom5[finalChoice])->getCol();
			listOfRoom5.erase(listOfRoom5.begin() + finalChoice);
		}
		delete gridOfThing[r][c];
		Potion * ptr = nullptr;
		if (potionType == 1) {
			ptr = new RestoreHealth{ r, c};
		}
		else if (potionType == 2) {
			ptr = new BoostATK{ r, c};
		}
		else if (potionType == 3) {
			ptr = new BoostDEF{ r, c};
		}
		else if (potionType == 4) {
			ptr = new PoisonHealth{ r, c};
		}
		else if (potionType == 5) {
			ptr = new WoundATK{ r, c};
		}
		else {
			ptr = new WoundDEF{ r, c};
		}
		gridOfThing[r][c] = ptr;
		ptr->attachObserver(this->td);
		ptr->notifyObserver(this->td);
		listOfPotion.push_back(ptr);
	}
}

void Floor::generateGold() {
	for (int i = 0; i < 10; i++) {
		int goldRoom = generateRandom(1, 5);
		int r = 0;
		int c = 0;
		int goldType = generateRandom(1, 8);
		if (goldRoom == 1) {
			int numOfChoice = listOfRoom1.size();
			int finalChoice = generateRandom(0, numOfChoice - 1);
			r = (listOfRoom1[finalChoice])->getRow();
			c = (listOfRoom1[finalChoice])->getCol();
			listOfRoom1.erase(listOfRoom1.begin() + finalChoice);
		}
		else if (goldRoom == 2) {
			int numOfChoice = listOfRoom2.size();
			int finalChoice = generateRandom(0, numOfChoice - 1);
			r = (listOfRoom2[finalChoice])->getRow();
			c = (listOfRoom2[finalChoice])->getCol();
			listOfRoom2.erase(listOfRoom2.begin() + finalChoice);
		}
		else if (goldRoom == 3) {
			int numOfChoice = listOfRoom3.size();
			int finalChoice = generateRandom(0, numOfChoice - 1);
			r = (listOfRoom3[finalChoice])->getRow();
			c = (listOfRoom3[finalChoice])->getCol();
			listOfRoom3.erase(listOfRoom3.begin() + finalChoice);
		}
		else if (goldRoom == 4) {
			int numOfChoice = listOfRoom4.size();
			int finalChoice = generateRandom(0, numOfChoice - 1);
			r = (listOfRoom4[finalChoice])->getRow();
			c = (listOfRoom4[finalChoice])->getCol();
			listOfRoom4.erase(listOfRoom4.begin() + finalChoice);
		}
		else {
			int numOfChoice = listOfRoom5.size();
			int finalChoice = generateRandom(0, numOfChoice - 1);
			r = (listOfRoom5[finalChoice])->getRow();
			c = (listOfRoom5[finalChoice])->getCol();
			listOfRoom5.erase(listOfRoom5.begin() + finalChoice);
		}
		delete gridOfThing[r][c];
		Gold * ptr = nullptr;
		if (goldType == 1) {
			ptr = new DragonHoard{ r, c, this };
		}
		else if (goldType <= 3) {
			ptr = new Small{ r, c};
		}
		else {
			ptr = new Normal{ r, c};
		}
		gridOfThing[r][c] = ptr;
		ptr->attachObserver(this->td);
		ptr->notifyObserver(this->td);
		listOfGold.push_back(ptr);
		if (goldType == 1) { // Set dragon
			int dr = 0;
			int dc = 0;
			for (;;) {
				int position = generateRandom(1, 8);
				if (position == 1) {
					if (gridOfThing[r - 1][c - 1]->getSymbol() == '.') {
						dr = r - 1;
						dc = c - 1;
						if ((dr != playerStartRow) && (dc != playerStartCol)) break;
					}
				}
				else if (position == 2) {
					if (gridOfThing[r - 1][c]->getSymbol() == '.') {
						dr = r - 1;
						dc = c;
						if ((dr != playerStartRow) && (dc != playerStartCol)) break;
					}
				}
				else if (position == 3) {
					if (gridOfThing[r - 1][c + 1]->getSymbol() == '.') {
						dr = r - 1;
						dc = c + 1;
						if ((dr != playerStartRow) && (dc != playerStartCol)) break;
					}
				}
				else if (position == 4) {
					if (gridOfThing[r][c - 1]->getSymbol() == '.') {
						dr = r;
						dc = c - 1;
						if ((dr != playerStartRow) && (dc != playerStartCol)) break;
					}
				}
				else if (position == 5) {
					if (gridOfThing[r][c + 1]->getSymbol() == '.') {
						dr = r;
						dc = c + 1;
						if ((dr != playerStartRow) && (dc != playerStartCol)) break;
					}
				}
				else if (position == 6) {
					if (gridOfThing[r + 1][c - 1]->getSymbol() == '.') {
						dr = r + 1;
						dc = c - 1;
						if ((dr != playerStartRow) && (dc != playerStartCol)) break;
					}
				}
				else if (position == 7) {
					if (gridOfThing[r + 1][c]->getSymbol() == '.') {
						dr = r + 1;
						dc = c;
						if ((dr != playerStartRow) && (dc != playerStartCol)) break;
					}
				}
				else {
					if (gridOfThing[r + 1][c + 1]->getSymbol() == '.') {
						dr = r + 1;
						dc = c + 1;
						if ((dr != playerStartRow) && (dc != playerStartCol)) break;
					}
				}
			} // Get dragon place
			Thing * dptr1 = gridOfThing[dr][dc];
			if (goldRoom == 1) { // Get rid off the annoying ptr to the available '.'
				int i = 0;
				for (vector<FloorTile *>::iterator it = listOfRoom1.begin(); it != listOfRoom1.end(); ++it, ++i) {
					if ((*it) == dptr1) {
						listOfRoom1.erase(listOfRoom1.begin() + i);
						break;
					}
				}
			}
			else if (goldRoom == 2) {
				int i = 0;
				for (vector<FloorTile *>::iterator it = listOfRoom2.begin(); it != listOfRoom2.end(); ++it, ++i) {
					if ((*it) == dptr1) {
						listOfRoom2.erase(listOfRoom2.begin() + i);
						break;
					}
				}
			}
			else if (goldRoom == 3) {
				int i = 0;
				for (vector<FloorTile *>::iterator it = listOfRoom3.begin(); it != listOfRoom3.end(); ++it, ++i) {
					if ((*it) == dptr1) {
						listOfRoom3.erase(listOfRoom3.begin() + i);
						break;
					}
				}
			}
			else if (goldRoom == 4) {
				int i = 0;
				for (vector<FloorTile *>::iterator it = listOfRoom4.begin(); it != listOfRoom4.end(); ++it, ++i) {
					if ((*it) == dptr1) {
						listOfRoom4.erase(listOfRoom4.begin() + i);
						break;
					}
				}
			}
			else {
				int i = 0;
				for (vector<FloorTile *>::iterator it = listOfRoom5.begin(); it != listOfRoom5.end(); ++it, ++i) {
					if ((*it) == dptr1) {
						listOfRoom5.erase(listOfRoom5.begin() + i);
						break;
					}
				}
			}
			delete gridOfThing[dr][dc];
			Dragon * dptr2 = new Dragon{ dr,dc};
			gridOfThing[dr][dc] = dptr2;
			dptr2->attachObserver(this->td);
			dptr2->notifyObserver(this->td);
			listOfEnemy.push_back(dptr2);
			//ptr->setGuardian(dptr2);
		}
	}
}

void Floor::generateEnemy() {
	for (int i = 0; i < 20; i++) {
		int enemyRoom = generateRandom(1, 5);
		int r = 0;
		int c = 0;
		int enemyType = generateRandom(1, 18);
		if (enemyRoom == 1) {
			int numOfChoice = listOfRoom1.size();
			int finalChoice = generateRandom(0, numOfChoice - 1);
			r = (listOfRoom1[finalChoice])->getRow();
			c = (listOfRoom1[finalChoice])->getCol();
			listOfRoom1.erase(listOfRoom1.begin() + finalChoice);
		}
		else if (enemyRoom == 2) {
			int numOfChoice = listOfRoom2.size();
			int finalChoice = generateRandom(0, numOfChoice - 1);
			r = (listOfRoom2[finalChoice])->getRow();
			c = (listOfRoom2[finalChoice])->getCol();
			listOfRoom2.erase(listOfRoom2.begin() + finalChoice);
		}
		else if (enemyRoom == 3) {
			int numOfChoice = listOfRoom3.size();
			int finalChoice = generateRandom(0, numOfChoice - 1);
			r = (listOfRoom3[finalChoice])->getRow();
			c = (listOfRoom3[finalChoice])->getCol();
			listOfRoom3.erase(listOfRoom3.begin() + finalChoice);
		}
		else if (enemyRoom == 4) {
			int numOfChoice = listOfRoom4.size();
			int finalChoice = generateRandom(0, numOfChoice - 1);
			r = (listOfRoom4[finalChoice])->getRow();
			c = (listOfRoom4[finalChoice])->getCol();
			listOfRoom4.erase(listOfRoom4.begin() + finalChoice);
		}
		else {
			int numOfChoice = listOfRoom5.size();
			int finalChoice = generateRandom(0, numOfChoice - 1);
			r = (listOfRoom5[finalChoice])->getRow();
			c = (listOfRoom5[finalChoice])->getCol();
			listOfRoom5.erase(listOfRoom5.begin() + finalChoice);
		}
		delete gridOfThing[r][c];
		Enemy * ptr = nullptr;
		if ((1 <= enemyType) && (enemyType <= 4)) {
			ptr = new Human{ r, c};
		}
		else if ((5 <= enemyType) && (enemyType <= 7)) {
			ptr = new Dwarf{ r, c};
		}
		else if ((8 <= enemyType) && (enemyType <= 12)) {
			ptr = new Halfling{ r, c};
		}
		else if ((13 <= enemyType) && (enemyType <= 14)) {
			ptr = new Elf{ r, c};
		}
		else if ((15 <= enemyType) && (enemyType <= 16)) {
			ptr = new Orcs{ r, c};
		}
		else {
			ptr = new Merchant{ r, c};
		}
		gridOfThing[r][c] = ptr;
		ptr->attachObserver(this->td);
		ptr->notifyObserver(this->td);
		listOfEnemy.push_back(ptr);
	}
}

void Floor::movePlayer(std::string direction) {
	int currentR = this->player->getRow();
	int currentC = this->player->getCol();
	int nextR = 0;
	int nextC = 0;
	// Get next position
	if (direction == "no") {
		nextR = currentR - 1;
		nextC = currentC;
	}
	else if (direction == "so") {
		nextR = currentR + 1;
		nextC = currentC;
	}
	else if (direction == "we") {
		nextR = currentR;
		nextC = currentC - 1;
	}
	else if (direction == "ea") {
		nextR = currentR;
		nextC = currentC + 1;
	}
	else if (direction == "ne") {
		nextR = currentR - 1;
		nextC = currentC + 1;
	}
	else if (direction == "se") {
		nextR = currentR + 1;
		nextC = currentC + 1;
	}
	else if (direction == "sw") {
		nextR = currentR + 1;
		nextC = currentC - 1;
	}
	else if (direction == "nw") {
		nextR = currentR - 1;
		nextC = currentC - 1;
	}
	else {
		cout << "Invalid direction" << endl;
	}
	// Check next position
	Thing * nextptr = gridOfThing[nextR][nextC];
	char c = nextptr->getSymbol();
	if (c == 'G' || c == '.' || c == '+' || c == '#' || c == '\\') {
		gridOfThing[currentR][currentC]->notifyObserver(this->td); // Remove @ and show cell
		this->player->setRow(nextR);
		this->player->setCol(nextC);
		this->player->notifyObserver(this->td); // Refresh @ location on td
		this->player->action = "PC moves " + direction + ".";
		if (c == '\\') {
			this->win = true;
			this->player->action = "PC succeed on this floor.";
			return;
		}
		if (c == 'G') {
			Gold * temp = nullptr;
			int count = 0;
			for (vector<Gold *>::iterator it = listOfGold.begin(); it != listOfGold.end(); ++it, ++count) {
				if (((*it)->getRow() == nextR) && ((*it)->getCol() == nextC)){
					temp = (*it);
					if (temp->isAvailable()) {
						this->player->consumeGold(temp);
						listOfGold.erase(listOfGold.begin() + count);
						// Change grid
						delete gridOfThing[nextR][nextC];
						FloorTile * fptr = new FloorTile{ nextR , nextC, 0 };
						gridOfThing[nextR][nextC] = fptr;
						fptr->attachObserver(this->td);
						break;
					}
					else {
						temp->beChecked(this->player);
						break;
					}
				}
			}
		}
		checkAroundPlayer();
	}
}

void Floor::checkAroundPlayer() {
	int r = this->player->getRow();
	int c = this->player->getCol();
	gridOfThing[r - 1][c - 1]->beChecked(this->player);
	gridOfThing[r - 1][c]->beChecked(this->player);
	gridOfThing[r - 1][c + 1]->beChecked(this->player);
	gridOfThing[r][c - 1]->beChecked(this->player);
	gridOfThing[r][c + 1]->beChecked(this->player);
	gridOfThing[r + 1][c - 1]->beChecked(this->player);
	gridOfThing[r + 1][c]->beChecked(this->player);
	gridOfThing[r + 1][c + 1]->beChecked(this->player);
}

/*
void Floor::checkAroundPlayer() {
	int currentR = this->player->getRow();
	int currentC = this->player->getCol();
	char c;
	// Check current position(Position 5)
	c = gridOfThing[currentR][currentC]->getSymbol();
	if (c == 'G') {
		Gold * temp = nullptr;
		int count = 0;
		for (vector<Gold *>::iterator it = listOfGold.begin(); it != listOfGold.end(); ++it, ++count) {
			if (((*it)->getRow() == currentR) && ((*it)->getCol() == currentC)) {
				temp = (*it);
				if (temp->isAvailable()) {
					this->player->consumeGold(temp);
					listOfGold.erase(listOfGold.begin() + count);
					// Change grid
					delete gridOfThing[currentR][currentC];
					FloorTile * fptr = new FloorTile{ currentR , currentC, 0 };
					gridOfThing[currentR][currentC] = fptr;
					fptr->attachObserver(this->td);
					break;
				}
				else {
					Dragon * ptr = new Dragon{ -1,-1};
					this->player->beAttacked(ptr);
					delete ptr;
					break;
				}
			}
		}
	}
	if (c == '\\') { // To next floor
		this->win = true;
		this->player->action = "PC succeed on this floor.";
		return;
	}
	// Check position 1
	c = gridOfThing[currentR - 1][currentC - 1]->getSymbol();
	if (c == 'G') {
		Gold * temp = nullptr;
		for (vector<Gold *>::iterator it = listOfGold.begin(); it != listOfGold.end(); ++it) {
			if (((*it)->getRow() == currentR - 1) && ((*it)->getCol() == currentC - 1)) {
				temp = (*it);
				if (!temp->isAvailable()) {
					Dragon * ptr = new Dragon{ -1,-1};
					this->player->beAttacked(ptr);
					delete ptr;
				}
				break;
			}
		}
	}
	if (c == 'P') {
		this->player->action += " and meet unknown potion";
	}
	if (c == 'H' || c == 'W' || c == 'E' || c == 'O' || c == 'M' || c == 'D' || c == 'L') {
		Enemy * temp = nullptr;
		for (vector<Enemy *>::iterator it = listOfEnemy.begin(); it != listOfEnemy.end(); ++it) {
			if (((*it)->getRow() == currentR - 1) && ((*it)->getCol() == currentC - 1)) {
				temp = (*it);
				if (!temp->isFriendly()) {
					this->player->beAttacked(temp);
				}
				break;
			}
		}
	}
	// Check position 2
	c = gridOfThing[currentR - 1][currentC]->getSymbol();
	if (c == 'G') {
		Gold * temp = nullptr;
		for (vector<Gold *>::iterator it = listOfGold.begin(); it != listOfGold.end(); ++it) {
			if (((*it)->getRow() == currentR - 1) && ((*it)->getCol() == currentC)) {
				temp = (*it);
				if (!temp->isAvailable()) {
					Dragon * ptr = new Dragon{ -1,-1};
					this->player->beAttacked(ptr);
					delete ptr;
				}
				break;
			}
		}
	}
	if (c == 'P') {
		this->player->action += " and meet unknown potion";
	}
	if (c == 'H' || c == 'W' || c == 'E' || c == 'O' || c == 'M' || c == 'D' || c == 'L') {
		Enemy * temp = nullptr;
		for (vector<Enemy *>::iterator it = listOfEnemy.begin(); it != listOfEnemy.end(); ++it) {
			if (((*it)->getRow() == currentR - 1) && ((*it)->getCol() == currentC)) {
				temp = (*it);
				if (!temp->isFriendly()) {
					this->player->beAttacked(temp);
				}
				break;
			}
		}
	}
	// Check position 3
	c = gridOfThing[currentR - 1][currentC + 1]->getSymbol();
	if (c == 'G') {
		Gold * temp = nullptr;
		for (vector<Gold *>::iterator it = listOfGold.begin(); it != listOfGold.end(); ++it) {
			if (((*it)->getRow() == currentR - 1) && ((*it)->getCol() == currentC + 1)) {
				temp = (*it);
				if (!temp->isAvailable()) {
					Dragon * ptr = new Dragon{ -1,-1};
					this->player->beAttacked(ptr);
					delete ptr;
				}
				break;
			}
		}
	}
	if (c == 'P') {
		this->player->action += " and meet unknown potion";
	}
	if (c == 'H' || c == 'W' || c == 'E' || c == 'O' || c == 'M' || c == 'D' || c == 'L') {
		Enemy * temp = nullptr;
		for (vector<Enemy *>::iterator it = listOfEnemy.begin(); it != listOfEnemy.end(); ++it) {
			if (((*it)->getRow() == currentR - 1) && ((*it)->getCol() == currentC + 1)) {
				temp = (*it);
				if (!temp->isFriendly()) {
					this->player->beAttacked(temp);
				}
				break;
			}
		}
	}
	// Check position 4
	c = gridOfThing[currentR][currentC - 1]->getSymbol();
	if (c == 'G') {
		Gold * temp = nullptr;
		for (vector<Gold *>::iterator it = listOfGold.begin(); it != listOfGold.end(); ++it) {
			if (((*it)->getRow() == currentR) && ((*it)->getCol() == currentC - 1)) {
				temp = (*it);
				if (!temp->isAvailable()) {
					Dragon * ptr = new Dragon{ -1,-1};
					this->player->beAttacked(ptr);
					delete ptr;
				}
				break;
			}
		}
	}
	if (c == 'P') {
		this->player->action += " and meet unknown potion";
	}
	if (c == 'H' || c == 'W' || c == 'E' || c == 'O' || c == 'M' || c == 'D' || c == 'L') {
		Enemy * temp = nullptr;
		for (vector<Enemy *>::iterator it = listOfEnemy.begin(); it != listOfEnemy.end(); ++it) {
			if (((*it)->getRow() == currentR) && ((*it)->getCol() == currentC - 1)) {
				temp = (*it);
				if (!temp->isFriendly()) {
					this->player->beAttacked(temp);
				}
				break;
			}
		}
	}
	// Check position 6
	c = gridOfThing[currentR][currentC + 1]->getSymbol();
	if (c == 'G') {
		Gold * temp = nullptr;
		for (vector<Gold *>::iterator it = listOfGold.begin(); it != listOfGold.end(); ++it) {
			if (((*it)->getRow() == currentR) && ((*it)->getCol() == currentC + 1)) {
				temp = (*it);
				if (!temp->isAvailable()) {
					Dragon * ptr = new Dragon{ -1,-1};
					this->player->beAttacked(ptr);
					delete ptr;
				}
				break;
			}
		}
	}
	if (c == 'P') {
		this->player->action += " and meet unknown potion";
	}
	if (c == 'H' || c == 'W' || c == 'E' || c == 'O' || c == 'M' || c == 'D' || c == 'L') {
		Enemy * temp = nullptr;
		for (vector<Enemy *>::iterator it = listOfEnemy.begin(); it != listOfEnemy.end(); ++it) {
			if (((*it)->getRow() == currentR) && ((*it)->getCol() == currentC + 1)) {
				temp = (*it);
				if (!temp->isFriendly()) {
					this->player->beAttacked(temp);
				}
				break;
			}
		}
	}
	// Check position 7
	c = gridOfThing[currentR + 1][currentC - 1]->getSymbol();
	if (c == 'G') {
		Gold * temp = nullptr;
		for (vector<Gold *>::iterator it = listOfGold.begin(); it != listOfGold.end(); ++it) {
			if (((*it)->getRow() == currentR + 1) && ((*it)->getCol() == currentC - 1)) {
				temp = (*it);
				if (!temp->isAvailable()) {
					Dragon * ptr = new Dragon{ -1,-1};
					this->player->beAttacked(ptr);
					delete ptr;
				}
				break;
			}
		}
	}
	if (c == 'P') {
		this->player->action += " and meet unknown potion";
	}
	if (c == 'H' || c == 'W' || c == 'E' || c == 'O' || c == 'M' || c == 'D' || c == 'L') {
		Enemy * temp = nullptr;
		for (vector<Enemy *>::iterator it = listOfEnemy.begin(); it != listOfEnemy.end(); ++it) {
			if (((*it)->getRow() == currentR + 1) && ((*it)->getCol() == currentC - 1)) {
				temp = (*it);
				if (!temp->isFriendly()) {
					this->player->beAttacked(temp);
				}
				break;
			}
		}
	}
	// Check position 8
	c = gridOfThing[currentR + 1][currentC]->getSymbol();
	if (c == 'G') {
		Gold * temp = nullptr;
		for (vector<Gold *>::iterator it = listOfGold.begin(); it != listOfGold.end(); ++it) {
			if (((*it)->getRow() == currentR + 1) && ((*it)->getCol() == currentC)) {
				temp = (*it);
				if (!temp->isAvailable()) {
					Dragon * ptr = new Dragon{ -1,-1};
					this->player->beAttacked(ptr);
					delete ptr;
				}
				break;
			}
		}
	}
	if (c == 'P') {
		this->player->action += " and meet unknown potion";
	}
	if (c == 'H' || c == 'W' || c == 'E' || c == 'O' || c == 'M' || c == 'D' || c == 'L') {
		Enemy * temp = nullptr;
		for (vector<Enemy *>::iterator it = listOfEnemy.begin(); it != listOfEnemy.end(); ++it) {
			if (((*it)->getRow() == currentR + 1) && ((*it)->getCol() == currentC)) {
				temp = (*it);
				if (!temp->isFriendly()) {
					this->player->beAttacked(temp);
				}
				break;
			}
		}
	}
	// Check position 9
	c = gridOfThing[currentR + 1][currentC + 1]->getSymbol();
	if (c == 'G') {
		Gold * temp = nullptr;
		for (vector<Gold *>::iterator it = listOfGold.begin(); it != listOfGold.end(); ++it) {
			if (((*it)->getRow() == currentR + 1) && ((*it)->getCol() == currentC + 1)) {
				temp = (*it);
				if (!temp->isAvailable()) {
					Dragon * ptr = new Dragon{ -1,-1};
					this->player->beAttacked(ptr);
					delete ptr;
				}
				break;
			}
		}
	}
	if (c == 'P') {
		this->player->action += " and meet unknown potion";
	}
	if (c == 'H' || c == 'W' || c == 'E' || c == 'O' || c == 'M' || c == 'D' || c == 'L') {
		Enemy * temp = nullptr;
		for (vector<Enemy *>::iterator it = listOfEnemy.begin(); it != listOfEnemy.end(); ++it) {
			if (((*it)->getRow() == currentR + 1) && ((*it)->getCol() == currentC + 1)) {
				temp = (*it);
				if (!temp->isFriendly()) {
					this->player->beAttacked(temp);
				}
				break;
			}
		}
	}
}
*/

void Floor::playerAttack(string direction) {
	int currentR = this->player->getRow();
	int currentC = this->player->getCol();
	int nextR = 0;
	int nextC = 0;
	// Get attack position
	if (direction == "no") {
		nextR = currentR - 1;
		nextC = currentC;
	}
	else if (direction == "so") {
		nextR = currentR + 1;
		nextC = currentC;
	}
	else if (direction == "we") {
		nextR = currentR;
		nextC = currentC - 1;
	}
	else if (direction == "ea") {
		nextR = currentR;
		nextC = currentC + 1;
	}
	else if (direction == "ne") {
		nextR = currentR - 1;
		nextC = currentC + 1;
	}
	else if (direction == "se") {
		nextR = currentR + 1;
		nextC = currentC + 1;
	}
	else if (direction == "sw") {
		nextR = currentR + 1;
		nextC = currentC - 1;
	}
	else if (direction == "nw") {
		nextR = currentR - 1;
		nextC = currentC - 1;
	}
	else {
		cout << "Invalid direction" << endl;
	}
	// Check attack enemy
	char c = gridOfThing[nextR][nextC]->getSymbol();
	if (c == 'H' || c == 'W' || c == 'E' || c == 'O' || c == 'M' || c == 'D' || c == 'L') {
		Enemy * temp = nullptr;
		int i = 0;
		for (vector<Enemy *>::iterator it = listOfEnemy.begin(); it != listOfEnemy.end(); ++it, ++i) {
			if (((*it)->getRow() == nextR) && ((*it)->getCol() == nextC)) {
				temp = (*it);
				this->player->attack(temp);
				if (temp->isDead()) {
					if (c == 'H' || c == 'M') {
						delete gridOfThing[nextR][nextC];
						MerchantHoard * mptr = new MerchantHoard{ nextR, nextC};
						gridOfThing[nextR][nextC] = mptr;
						mptr->attachObserver(this->td);
						mptr->notifyObserver(this->td);
						listOfGold.push_back(mptr);
					}
					else {
						delete gridOfThing[nextR][nextC];
						FloorTile * fptr = new FloorTile{ nextR, nextC, 0 };
						gridOfThing[nextR][nextC] = fptr;
						fptr->attachObserver(this->td);
						fptr->notifyObserver(this->td);
					}
					listOfEnemy.erase(listOfEnemy.begin() + i);
					if (c == 'D') {
						if (gridOfThing[currentR][currentC]->getSymbol() == 'G') {
							Gold * temp = nullptr;
							int count = 0;
							for (vector<Gold *>::iterator it = listOfGold.begin(); it != listOfGold.end(); ++it, ++count) {
								if (((*it)->getRow() == currentR) && ((*it)->getCol() == currentC)) {
									temp = (*it);
									if (temp->isAvailable()) {
										this->player->consumeGold(temp);
										listOfGold.erase(listOfGold.begin() + count);
										// Change grid
										delete gridOfThing[currentR][currentC];
										FloorTile * fptr = new FloorTile{ currentR , currentC, 0 };
										gridOfThing[currentR][currentC] = fptr;
										fptr->attachObserver(this->td);
									}
									break;
								}
							}
						}
					}
					break;
				}
				else {
					temp->attack(player);
					break;
				}
			}
		}
	}
}

void Floor::playerUsePotion(string direction) {
	int currentR = this->player->getRow();
	int currentC = this->player->getCol();
	int nextR = 0;
	int nextC = 0;
	// Get attack position
	if (direction == "no") {
		nextR = currentR - 1;
		nextC = currentC;
	}
	else if (direction == "so") {
		nextR = currentR + 1;
		nextC = currentC;
	}
	else if (direction == "we") {
		nextR = currentR;
		nextC = currentC - 1;
	}
	else if (direction == "ea") {
		nextR = currentR;
		nextC = currentC + 1;
	}
	else if (direction == "ne") {
		nextR = currentR - 1;
		nextC = currentC + 1;
	}
	else if (direction == "se") {
		nextR = currentR + 1;
		nextC = currentC + 1;
	}
	else if (direction == "sw") {
		nextR = currentR + 1;
		nextC = currentC - 1;
	}
	else if (direction == "nw") {
		nextR = currentR - 1;
		nextC = currentC - 1;
	}
	else {
		cout << "Invalid direction" << endl;
	}
	// Check attack enemy
	char c = gridOfThing[nextR][nextC]->getSymbol();
	if (c == 'P') {
		Potion * temp = nullptr;
		int i = 0;
		for (vector<Potion *>::iterator it = listOfPotion.begin(); it != listOfPotion.end(); ++it, ++i) {
			if (((*it)->getRow() == nextR) && ((*it)->getCol() == nextC)) {
				temp = (*it);
				this->player->consumePotion(temp);
				delete gridOfThing[nextR][nextC];
				FloorTile * fptr = new FloorTile{ nextR, nextC, 0 };
				gridOfThing[nextR][nextC] = fptr;
				fptr->attachObserver(this->td);
				fptr->notifyObserver(this->td);
				listOfPotion.erase(listOfPotion.begin() + i);
				break;
			}
		}
	}
}

void Floor::randomMoveEnemy() {
	if (this->enemyMovability == false) {
		return;
	}
	vector<Enemy *> tempListOfEnemy; // Used to collect ptr of enemy for random movement
	for (int i = 0; i < this->height; i++) { // Loop through each row
		for (int j = 0; j < this->width; j++) { // Loop through each col
			char c = gridOfThing[i][j]->getSymbol();
			// Check if it is an enemy except dragon
			if (c == 'H' || c == 'W' || c == 'E' || c == 'O' || c == 'M' || c == 'L') {
				// Get enemy location
				int er = gridOfThing[i][j]->getRow();
				int ec = gridOfThing[i][j]->getCol();
				// Find its pointer
				for (auto p : listOfEnemy) {
					// Match row and col to get ptr
					if (er == p->getRow() && ec == p->getCol()) {
						// Enemy find, check if it is movable
						if (enemyMovable(p)) {
							// Add movable enemy to the temp list
							tempListOfEnemy.push_back(p);
						}
						break;
					}
				}
			}
		}
	}
	// Movable enemy collected, start random movement
	srand((unsigned int)time(NULL));
	for (auto e : tempListOfEnemy) {
		for (; ;) {
			int dir = generateRandom(1, 8);
			int currR = e->getRow();
			int currC = e->getCol();
			int nextR = 0;
			int nextC = 0;
			if (dir == 1) {
				nextR = currR - 1;
				nextC = currC;
			}
			else if (dir == 2) {
				nextR = currR + 1;
				nextC = currC;
			}
			else if (dir == 3) {
				nextR = currR;
				nextC = currC - 1;
			}
			else if (dir == 4) {
				nextR = currR;
				nextC = currC + 1;
			}
			else if (dir == 5) {
				nextR = currR - 1;
				nextC = currC + 1;
			}
			else if (dir == 6) {
				nextR = currR + 1;
				nextC = currC + 1;
			}
			else if (dir == 7) {
				nextR = currR + 1;
				nextC = currC - 1;
			}
			else {
				nextR = currR - 1;
				nextC = currC - 1;
			}
			char c = gridOfThing[nextR][nextC]->getSymbol();
			if (c == '.') {
				// Set Enemy location
				e->setRow(nextR);
				e->setCol(nextC);
				e->notifyObserver(this->td);
				// Set FloorTile location
				gridOfThing[nextR][nextC]->setRow(currR);
				gridOfThing[nextR][nextC]->setCol(currC);
				gridOfThing[nextR][nextC]->notifyObserver(this->td);
				// Switch gridOfThing ptr
				Thing * temp = gridOfThing[nextR][nextC];
				gridOfThing[nextR][nextC] = gridOfThing[currR][currC];
				gridOfThing[currR][currC] = temp;
				break;
			}
		}
	}
}

bool Floor::enemyMovable(Enemy * e) {
	// Collect Enemy location
	int er = e->getRow();
	int ec = e->getCol();
	// Find range
	int rowUpperBound = er - 1;
	int rowLowerBound = er + 1;
	int colLeftBound = ec - 1;
	int colRightBound = ec + 1;
	// Collect player location
	int pr = this->player->getRow();
	int pc = this->player->getCol();
	// Check if player is within attack range
	if ((rowUpperBound <= pr && pr <= rowLowerBound) && (colLeftBound <= pc && pc <= colRightBound)) {
		// Player is around the enemy
		return false;
	}
	// Player is not around enemy, enemy is movable
	return true;
}

vector<vector<Thing *>> & Floor::getGridOfThing() {
	return gridOfThing;
}

int Floor::getFloorNumber() {
	return this->floorNumber;
}

int Floor::getWidth() {
	return this->width;
}

int Floor::getHeight() {
	return this->height;
}

void Floor::changeEnemyMovability() {
	if (this->enemyMovability) {
		this->enemyMovability = false;
	}
	else {
		this->enemyMovability = true;
	}
}

bool Floor::isWon() {
	return this->win;
}

int Floor::getPlayerStartRow() {
	return playerStartRow;
}

int Floor::getPlayerStartCol() {
	return playerStartCol;
}

ostream & operator<<(ostream & out, Floor & f) {
	out << *(f.td);
	out << "Floor: " << f.getFloorNumber() << endl;
	out << "Race: " << f.player->getFigureType() << " Gold: " << f.player->getMoney() << endl;
	out << "HP: " << f.player->getHP() << endl;
	out << "ATK: " << f.player->getATK() << endl;
	out << "DEF: " << f.player->getDEF() << endl;
	out << "Action: " << f.player->action << endl;
	return out;
}



