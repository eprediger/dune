#ifndef __LIGHT_INFANTRY_H__
#define __LIGHT_INFANTRY_H__

#include "OffensiveUnit.h"
#include "../Weapons/assault-rifle.h"

class LightInfantry : public OffensiveUnit {
public:
	LightInfantry(int x, int y);
	
	~LightInfantry();
	
    virtual bool canMoveAboveTerrain(Terrain &terrain) override;
};

#endif
