#ifndef __RAIDER_H__
#define __RAIDER_H__

#include "OffensiveUnit.h"
#include "../Weapons/SmallCannon.h"

class Raider : public OffensiveUnit {
public:
	Raider(int x, int y);
	~Raider();
	virtual bool canMoveAboveTerrain(Terrain &terrain);
	
};

#endif