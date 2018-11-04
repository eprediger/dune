#ifndef __TANK_H__
#define __TANK_H__

#include "OffensiveUnit.h"
#include "../Weapons/Cannon.h"

class Tank : public OffensiveUnit {
public:
	Tank(int x, int y);
	~Tank();
	virtual bool canMoveAboveTerrain(Terrain &terrain);
	
};

#endif
