#ifndef __RAIDER_H__
#define __RAIDER_H__

#include "OffensiveUnit.h"
#include "Model/Weapons/SmallCannon.h"

class Raider : public OffensiveUnit {
public:
	Raider(int x, int y);
	~Raider();
	virtual bool canMoveAboveTerrain(Terrain &terrain);

	virtual void reciveBonusDammage(const Weapon &weapon) override;	
};

#endif	// __RAIDER_H__
