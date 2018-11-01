#ifndef __HARVESTER_H__
#define __HARVESTER_H__

#include "Unit.h"
#include "../Weapons/assault-rifle.h"

class Harvester : public Unit {
public:
	Harvester(int x, int y);

	~Harvester();
	virtual bool canMoveAboveTerrain(Terrain &terrain);
};

#endif
