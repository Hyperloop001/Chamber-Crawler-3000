#include "cellFloorTile.h"
using namespace std;

/////*****FloorTile*****/////
FloorTile::FloorTile(int row, int col, int roomNumber)
	:Cell{ row, col, '.'}, roomNumber{ roomNumber } {}

FloorTile::~FloorTile() {}


int FloorTile::getRoomNumber() {
	return roomNumber;
}
/////*****FloorTile*****/////



