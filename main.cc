#include"global.h"
#include "textdisplay.h"
#include "thing.h"
#include "figure.h" // Figures
#include "globalPC.h"
#include "globalEnemy.h"
#include "item.h" // Items
#include "globalGold.h"
#include "globalPotion.h"
#include "globalCell.h" // Cells
#include "floor.h"
#include <cstdlib>
#include <ctime>
///
#include "dlcScoreBoard.h"
using namespace std;

int main(int argc, char *argv[]) {
	srand(time(NULL));
	int clargc = argc - 1;

	bool scoreAvailable = false;
	bool floorAvailable = false;
	string cla;
	int floor_cmd_index = 0;
	for (int i = 1; i <= clargc; i++) {
		cla = argv[i];
		if (cla == "-SB") {
			scoreAvailable = true;
		}
		else {
			floor_cmd_index = i;
			floorAvailable = true;
		}
	}
	ScoreBoard sb;


	// Creat an vector of floors

	bool gameTerminate = false; // Check if game need to be terminate;
	for (;;) { // Big loop for set each game
		vector<Floor *> arrOfFloors;
		// Initialize character (Or terminate game when entering q)
		PC * player = nullptr;
		string pcType;
		while (true) {
			cout << "Please select a race: s(shade), d(drow), v(vampire), g(goblin), t(troll)." << endl;
				cin >> pcType;
				if (pcType == "s") {
					player = new Shade{ 0,0 };
				}
				else if (pcType == "d") {
					player = new Drow{ 0,0 };
				}
				else if (pcType == "v") {
					player = new Vampire{ 0,0 };
				}
				else if (pcType == "g") {
					player = new Goblin{ 0,0 };
				}
				else if (pcType == "t") {
					player = new Troll{ 0,0 };
				}
				else if (pcType == "q") {
					// Input have to terminate game
					gameTerminate = true;
				}
				else {
					// Invalid input
					if (cin.eof()) {
						gameTerminate = true;
						break;
					}
					cout << "Invalid input." << endl;
					continue;
				}
				break;
		}
		// Check if game have to terminate here
		if (gameTerminate) {
			delete player;
			cout << "Game terminate with q of EOF." << endl;
			if (scoreAvailable) {
				cout << "Please enter your name: " << endl;
				string name;
				cin >> name;
				sb.addPlayer(name, 0, "Not selected");
			}
			break;
		}
		int playerDefaultATK = 0;
		int playerDefaultDEF = 0;
		if (player != nullptr) {
			playerDefaultATK = player->getATK();
			playerDefaultDEF = player->getDEF();
		}

		// Initialize Floors 
		for (int i = 1; i <= 5; i++) {
			// Creat 5 floors
			arrOfFloors.push_back(new Floor{ player, i });
		}
		if (floorAvailable) {
			// There is a given file name
			string textFileName = argv[floor_cmd_index];
			ifstream iff{ textFileName };
			for (auto f : arrOfFloors) {
				// Initialize 5 floors
				f->initializeFloor(iff);
			}
		}
		else {
			// No specified flie name, creat default floor
			for (auto f : arrOfFloors) {
				// Initialize 5 floors
				f->initializeFloor();
			}
		}

		// Start Game
		bool stopCurrentGame = false;
		for (auto f : arrOfFloors) {
			// Iterate through each floor
			// Set player initial location
			player->setRow(f->getPlayerStartRow());
			player->setCol(f->getPlayerStartCol());
			cout << (*f); // Print floor;
			string cmd;
			bool currentFloorWon = false;
			// Taking command
			while (true) {
				cin >> cmd;
				// no,so,ea,we,ne,nw,se,sw
				if ((cmd == "no") || (cmd == "so") || (cmd == "ea") || (cmd == "we") ||
					(cmd == "ne") || (cmd == "nw") || (cmd == "se") || (cmd == "sw")) {
					f->movePlayer(cmd);
				}
				else if (cmd == "u") {
					// Use potion
					cin >> cmd;
					f->playerUsePotion(cmd);
				}
				else if (cmd == "a") {
					// Attack enemy
					cin >> cmd;
					f->playerAttack(cmd);
				}
				else if (cmd == "f") {
					// Set Movability
					f->changeEnemyMovability();
				}
				else if (cmd == "r") {
					// Restart game
					stopCurrentGame = true;
				}
				else if (cmd == "q") {
					// Terminate game
					gameTerminate = true;
				}
				else {
					cout << "Invalid command." << endl;
					cin.clear();
					continue;
				}
				f->randomMoveEnemy();
				cout << (*f);
				// Check if game have to terminate or restart here
				if (gameTerminate) {
					cout << "The score of player is: ";
					cout << player->returnScore() << endl;
					cout << "Current game terminated by user." << endl;
					if (scoreAvailable) {
						cout << "Please enter your name: " << endl;
						string name;
						cin >> name;
						sb.addPlayer(name, player->returnScore(), player->getFigureType());
					}
					break;
				}
				if (stopCurrentGame) {
					cout << "The score of player is: ";
					cout << player->returnScore() << endl;
					cout << "User restarts the game." << endl;
					if (scoreAvailable) {
						cout << "Please enter your name: " << endl;
						string name;
						cin >> name;
						sb.addPlayer(name, player->returnScore(), player->getFigureType());
					}
					break;
				}
				// Check if player won the game
					// Depend on input 
						// stopCurrentGame = true;
						// or
						// gameTerminate = true;
					// currentFloorWon = true;
				if ((f->isWon()) && (f->getFloorNumber() == 5)) {
					// Game succeed
					cout << "Congratulations!!! You won!!! Freedom is yours!!!" << endl;
					currentFloorWon = true;
					cout << "The final score of player is: ";
					cout << player->returnScore() << endl;
					if (scoreAvailable) {
						cout << "Please enter your name: " << endl;
						string name;
						cin >> name;
						sb.addPlayer(name, player->returnScore(), player->getFigureType());
					}
					cout << "To restart game please press r, to end game please press q." << endl;
					string endcmd;
					cin >> endcmd;
					if (endcmd == "r") {
						cout << "Game restarted by user." << endl;
						stopCurrentGame = true;
					}
					else if (endcmd == "q") {
						cout << "Game terminated by user." << endl;
						gameTerminate = true;
					}
					else {
						cout << "Input is invalid, game end automatically." << endl;
						gameTerminate = true;
					}
					break;
				}
				// Check if player succeed on current floor
					// currentFloorWon = true;
				if (f->isWon()) {
					currentFloorWon = true;
					break;
				}
				// Check if player is dead
					// Depend on input 
						// stopCurrentGame = true;
						// or
						// gameTerminate = true;
				if (player->isDead()) {
					cout << "The player is dead." << endl;
					cout << "The score of player is: ";
					cout << player->returnScore() << endl;
					if (scoreAvailable) {
						cout << "Please enter your name: " << endl;
						string name;
						cin >> name;
						sb.addPlayer(name, player->returnScore(), player->getFigureType());
					}
					cout << "To restart game please press r, to end game please press q." << endl;
					string endcmd;
					cin >> endcmd;
					if (endcmd == "r") {
						cout << "Game restarted by user." << endl;
						stopCurrentGame = true;
					}
					else if (endcmd == "q") {
						cout << "Game terminated by user." << endl;
						gameTerminate = true;
					}
					else {
						cout << "Input is invalid, game end automatically." << endl;
						gameTerminate = true;
					}
					break;
				}
			}
			if (gameTerminate || stopCurrentGame) {
				break;
			}
			if (currentFloorWon) {
				player->setATK(playerDefaultATK);
				player->setDEF(playerDefaultDEF);
				cout << "Player going to the next floor." << endl;
				continue;
			}
		}
		// Need to terminate game
		if (gameTerminate) {
			gameTerminate = false;
			for (auto f : arrOfFloors) {
				delete f;
			}
			delete player;
			break;
		}
		// Need to restart game
		if (stopCurrentGame) {
			stopCurrentGame = false;
			for (auto f : arrOfFloors) {
				delete f;
			}
			delete player;
			continue;
		}
	}
	// Show score
	if (scoreAvailable) {
		cout << sb;
	}
}


