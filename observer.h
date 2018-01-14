#ifndef _observer_h_
#define _observer_h_
#include "global.h"

class Thing;

class Observer {
public:
	virtual ~Observer() = 0; // Basic dtor

	// beNotified(Thing * who): act correspondingly by changing the display with new Thing
	virtual void beNotified(Thing * who) = 0;
};


#endif



