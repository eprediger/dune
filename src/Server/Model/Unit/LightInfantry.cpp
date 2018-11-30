#include <Model/GameConfiguration.h>
#include "LightInfantry.h"
#include "Model/Weapons/Weapons.h"

LightInfantry::LightInfantry(int x, int y) :
        OffensiveUnit(x, y, GameConfiguration::getConfig().lightInfantryHitPoints, GameConfiguration::getConfig().lightInfantryRange, Weapons::assaultRifle,
                      GameConfiguration::getConfig().lightInfantrySpeed, GameConfiguration::getConfig().lightInfantryCost)
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
