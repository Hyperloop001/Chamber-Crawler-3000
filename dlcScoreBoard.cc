#include "dlcScoreBoard.h"
using namespace std;



void ScoreBoard::addPlayer(std::string name, int score, string figure) {
	listOfString.push_back(name);
	listOfScore.push_back(score);
	listOfFigure.push_back(figure);
}

void ScoreBoard::sortPlayer() {
	int loop = listOfScore.size();
	for (int i = 0; i < loop; i++) {
		for (int j = i + 1; j < loop; j++) {
			if (listOfScore[i] < listOfScore[j]) {
				int temps = listOfScore[i];
				listOfScore[i] = listOfScore[j];
				listOfScore[j] = temps;
				string tempn = listOfString[i];
				listOfString[i] = listOfString[j];
				listOfString[j] = tempn;
				string tempf = listOfFigure[i];
				listOfFigure[i] = listOfFigure[j];
				listOfFigure[j] = tempf;
			}
		}
	}
}

ostream & operator<<(ostream & out, ScoreBoard & sb) {
	sb.sortPlayer();
	int loop = sb.listOfString.size();
	out << "List of heros" << endl;
	out << "Name" << "	" << "Score" << "	" << "Hero" << endl;
	for (int i = 0; i < loop; i++) {
		out << sb.listOfString[i] << "	";
		out << sb.listOfScore[i] << "	";
		out << sb.listOfFigure[i] << endl;
	}
	return out;
}
