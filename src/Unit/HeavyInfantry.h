#ifndef __HEAVY_INFANTRY_H__
#define __HEAVY_INFANTRY_H__

#include "OffensiveUnit.h"
#include "../Weapons/RocketLauncher.h"

class HeavyInfantry : public OffensiveUnit {
public:
	HeavyInfantry(int x, int y);
	~HeavyInfantry();
	virtual bool canMoveAboveTerrain(Terrain &terrain);

	virtual void reciveBonusDammage(const Weapon &weapon) override;
	
};

#endif
