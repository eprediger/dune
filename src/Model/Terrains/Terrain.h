#ifndef __TERRAIN_H__
#define __TERRAIN_H__

#include <ostream>

class Terrain {
private:
	char key;
	bool occupied;
	bool builtOn;
public:
	Terrain();

	explicit Terrain(char key);

	void occupy();
	void buildOn();
	void free();
	bool isOccupied();
	bool isBuiltOn();
	virtual int getFarm();
	virtual bool hasFarm();

	bool operator==(const Terrain& terrain);

	char getKey();
};

#endif	// __TERRAIN_H__
