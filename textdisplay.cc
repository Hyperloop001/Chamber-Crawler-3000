#include "textdisplay.h"


TextDisplay::TextDisplay()
	:width{ 79 }, height{ 25 } {}

TextDisplay::~TextDisplay() {}

vector<vector<char>> & TextDisplay::getTheDisplay() {
	return theDisplay;
}

void TextDisplay::beNotified(Thing * who) {
	int row = who->getRow();
	int col = who->getCol();
	theDisplay[row][col] = who->getSymbol();
	//cout << "td notified" << endl;///////////////
}

int TextDisplay::getWidth() {
	return this->width;
}
int TextDisplay::getHeight() {
	return this->height;
}



ostream & operator<<(ostream & out, TextDisplay & display) {
	for (vector<vector<char>>::iterator it1 = display.theDisplay.begin();
		it1 != display.theDisplay.end(); ++it1) {
		for (vector<char>::iterator it2 = (*it1).begin(); it2 != (*it1).end(); ++it2) {
			out << (*it2);
		}
		out << endl;
	}
	return out;
}


