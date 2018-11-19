#ifndef __HEAVY_INFANTRY_H__
#define __HEAVY_INFANTRY_H__

#include "OffensiveUnit.h"
#include "../Weapons/RocketLauncher.h"
#include "../Weapons/Rocket.h"
class HeavyInfantry : public OffensiveUnit {
public:
	HeavyInfantry(int x, int y);
	~HeavyInfantry();
	virtual bool canMoveAboveTerrain(Terrain &terrain);

	virtual void shoot(Attackable& defender) override;
	virtual bool shotARocket() override;
	Rocket* viewRocket();
	virtual Rocket* getRocket() override;
	virtual void reciveBonusDammage(const Weapon &weapon) override;
private:
	bool shot;
	Rocket* rocket;
};

#endif	// __HEAVY_INFANTRY_H__
