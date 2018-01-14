#include "random.h"
#include <cstdlib>
#include <ctime>



int generateRandom(int a, int b) {
	//srand(time(NULL));
	int rv = rand() % b + a;
	return rv;
}


