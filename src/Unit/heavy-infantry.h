#ifndef __HEAVY_INFANTRY_H__
#define __HEAVY_INFANTRY_H__

#include "Unit.h"
#include "../Weapons/rocket-launcher.h"

class HeavyInfantry : public Unit {
public:
	HeavyInfantry(int x, int y);
	~HeavyInfantry();
	virtual bool canMoveAboveTerrain(Terrain &terrain);
	
};

#endif
