#include "LightInfantry.h"
#include "../Weapons/Weapons.h"

LightInfantry::LightInfantry(int x, int y) :
        OffensiveUnit(x, y, GlobalConfig.lightInfantryHitPoints, GlobalConfig.lightInfantryRange, Weapons::assaultRifle,
                      GlobalConfig.lightInfantrySpeed, 0) {}

LightInfantry::~LightInfantry() {}

bool LightInfantry::canMoveAboveTerrain(Terrain &terrain) {
    return terrain == Sand() || terrain == Dunes() || terrain == Rocks() || terrain == Summit();
}

void LightInfantry::reciveBonusDammage(const Weapon &weapon) {
	life -= weapon.getInfantryBonus();
}
