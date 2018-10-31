#ifndef __LIGHT_INFANTRY_H__
#define __LIGHT_INFANTRY_H__

#include "Unit.h"
#include "../Weapons/assault-rifle.h"

class LightInfantry : public Unit {
public:
	LightInfantry(int x, int y);
	
	~LightInfantry();
	
    virtual bool canMoveAboveTerrain(Terrain &terrain) override;
};

#endif
