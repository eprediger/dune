#include "HeavyInfantry.h"
#include "../Weapons/Weapons.h"
#include "../GlobalConfig.h"

HeavyInfantry::HeavyInfantry(int x, int y) :
		OffensiveUnit(x, y, GlobalConfig.heavyInfantryHitPoints, GlobalConfig.heavyInfantryRange,
					  Weapons::rocketLauncher, GlobalConfig.heavyInfantrySpeed, GlobalConfig.heavyInfantryCost) {}

HeavyInfantry::~HeavyInfantry() {}

bool HeavyInfantry::canMoveAboveTerrain(Terrain &terrain) {
	return terrain == Sand() || terrain == Dunes() || terrain == Rocks() || terrain == Summit();
}

void HeavyInfantry::reciveBonusDammage(const Weapon &weapon) {
	life -= weapon.getInfantryBonus();
}
