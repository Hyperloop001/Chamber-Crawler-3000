#include "subject.h"
#include "observer.h"
#include "global.h"
using namespace std;


Subject::~Subject() {}


void Subject::attachObserver(Observer * o) {
	myObservers.push_back(o);
}


void Subject::DetachObserver(Observer * o) {
	int i = 0;
	for (vector<Observer *>::iterator it = myObservers.begin(); it != myObservers.end(); ++it, ++i) {
		if ((*it) == o) {
			myObservers.erase(myObservers.begin() + i);
			break;
		}
	}
}



