#ifndef _subject_h_
#define _subject_h_
#include "global.h"

class Observer;


// Abstract class Subject
class Subject {
protected:
	std::vector<Observer *> myObservers;
public:
	virtual ~Subject(); // Basic dtor

    // notifyObserver(): Notify the textDisplay to change correspondingly
	virtual void notifyObserver(Observer * o) = 0;
	void attachObserver(Observer * o);
	void DetachObserver(Observer * o);

};







#endif


