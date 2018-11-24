#ifndef __LIGHT_INFANTRY_H__
#define __LIGHT_INFANTRY_H__

#include "OffensiveUnit.h"
#include "Model/Weapons/AssaultRifle.h"

class LightInfantry : public OffensiveUnit {
public:
	LightInfantry(int x, int y);
	
	~LightInfantry();
	
    virtual bool canMoveAboveTerrain(Terrain &terrain) override;

	virtual void reciveBonusDammage(const Weapon &weapon) override;
};

#endif
