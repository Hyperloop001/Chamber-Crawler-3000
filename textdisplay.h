#ifndef _textdisplay_h_
#define _textdisplay_h_
#include "global.h"
#include "thing.h"
#include "observer.h"
using namespace std;

class TextDisplay : public Observer {
	std::vector<std::vector<char>> theDisplay;

	const int width;
	const int height;
public:

	TextDisplay(); // Basic ctor
	~TextDisplay(); // Basic dtor

	// getTheDisplay() returns a reference to its own vector<vector<char>>
	std::vector<std::vector<char>> & getTheDisplay();
	// beNotified(Subject * who): act correspondingly by changing the display with new Thing
	void beNotified(Thing * who)override;

	int getWidth();
	int getHeight();

	friend class Floor;
	friend std::ostream & operator<<(std::ostream & out, TextDisplay & display);
};

#endif






