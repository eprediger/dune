#ifndef __HARVESTER_H__
#define __HARVESTER_H__

#include "PassiveUnit.h"
#include "../Weapons/AssaultRifle.h"

class Harvester : public PassiveUnit {
public:
	Harvester(int x, int y);

	~Harvester();

	virtual bool canMoveAboveTerrain(Terrain &terrain);

private:
	const int spiceCapacity;
};

#endif
