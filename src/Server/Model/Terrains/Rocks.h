#ifndef __ROCKS_H__
#define __ROCKS_H__

#include "Terrain.h"

#define ROCKS_KEY 'R'

class Building;

class Rocks : public Terrain {
private:
	Building* building;

public:
	Rocks();

	virtual void buildOn(Building* building) override;

	virtual Building* getBuilding() override;

	virtual void free() override;
};

#endif //__ROCKS_H__
