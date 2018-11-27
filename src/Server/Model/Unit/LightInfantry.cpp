#include "LightInfantry.h"
#include "Model/Weapons/Weapons.h"
#include "Model/GlobalConfig.h"

LightInfantry::LightInfantry(int x, int y) :
        OffensiveUnit(x, y, GlobalConfig.lightInfantryHitPoints, GlobalConfig.lightInfantryRange, Weapons::assaultRifle,
                      GlobalConfig.lightInfantrySpeed, GlobalConfig.lightInfantryCost) 
{
    serialization["subClass"] = "LightInfantry";
}

LightInfantry::~LightInfantry() {}

bool LightInfantry::canMoveAboveTerrain(Terrain &terrain) {
    return terrain == Sand() || terrain == Dunes() || terrain == Rocks() || terrain == Summit();
}

void LightInfantry::reciveBonusDammage(const Weapon &weapon) {
	life -= weapon.getInfantryBonus();
}
