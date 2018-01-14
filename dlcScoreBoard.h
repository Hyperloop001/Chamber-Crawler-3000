#ifndef dlcScoreBoard_h
#define dlcScoreBoard_h
#include <string>
#include <iostream>
#include <vector>

class ScoreBoard {
	std::vector<std::string> listOfString;
	std::vector<std::string> listOfFigure;
	std::vector<int> listOfScore;
public:
	void addPlayer(std::string name, int score, std::string figure);
	void sortPlayer();

	friend std::ostream & operator<<(std::ostream & out, ScoreBoard & sb);

};





#endif
