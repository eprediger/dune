#ifndef __TRIKE_H__
#define __TRIKE_H__

#include "OffensiveUnit.h"
#include "../Weapons/assault-rifle.h"

class Trike : public OffensiveUnit {
public:
	Trike(int x, int y);
	~Trike();
	virtual bool canMoveAboveTerrain(Terrain &terrain);
	
};

#endif
