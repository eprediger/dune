#ifndef __TERRAIN_H__
#define __TERRAIN_H__

#include <ostream>

class Terrain {
protected:
	char key;
	bool occupied;
	bool builtOn;
	int speed_factor;
public:
	Terrain();

	explicit Terrain(char key);

	void occupy();
	void buildOn();
	void free();
	bool isOccupied();
	bool isBuiltOn();
	virtual int farm();
	virtual int getSpice();
	virtual bool hasFarm();
	int getSpeedFactor();

	bool operator==(const Terrain& terrain);

	virtual char getKey();
};

#endif	// __TERRAIN_H__
