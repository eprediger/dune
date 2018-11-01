#ifndef __HEAVY_INFANTRY_H__
#define __HEAVY_INFANTRY_H__

#include "OffensiveUnit.h"
#include "../Weapons/rocket-launcher.h"

class HeavyInfantry : public OffensiveUnit {
public:
	HeavyInfantry(int x, int y);
	~HeavyInfantry();
	virtual bool canMoveAboveTerrain(Terrain &terrain);
	
};

#endif
