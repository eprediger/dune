#ifndef __TANK_H__
#define __TANK_H__

#include "OffensiveUnit.h"
#include "Model/Weapons/Cannon.h"

class Tank : public OffensiveUnit {
public:
	Tank(int x, int y);
	~Tank();
	virtual bool canMoveAboveTerrain(Terrain &terrain);

	virtual void reciveBonusDammage(const Weapon &weapon) override;	
};

#endif
