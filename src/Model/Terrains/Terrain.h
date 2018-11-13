#ifndef __TERRAIN_H__
#define __TERRAIN_H__

#include <ostream>

#include "../Positionable.h"

class Terrain {
private:
	char key;
	bool occupied;

public:
	Terrain();

	explicit Terrain(char key);

	void occupy();
	void free();
	bool isOccupied();

	virtual int getFarm();

	bool operator==(const Terrain& terrain);

	char getKey();
};

#endif	// __TERRAIN_H__
