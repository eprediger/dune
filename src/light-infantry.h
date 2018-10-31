#ifndef __LIGHT_INFANTRY_H__
#define __LIGHT_INFANTRY_H__

#include "Unity.h"
#include "assault-rifle.h"

class LightInfantry : public Unity {
public:
	LightInfantry(int x, int y);
	
	~LightInfantry();
	
    virtual bool canMoveAboveTerrain(Terrain &terrain) override;
};

#endif
