#include <Model/GameConfiguration.h>
#include "Tank.h"
#include "Model/Weapons/Weapons.h"

Tank::Tank(int x, int y) :
        OffensiveUnit(x, y, GameConfiguration::getConfig().tankHitPoints, GameConfiguration::getConfig().tankRange, Weapons::cannon, GameConfiguration::getConfig().tankSpeed,
                      GameConfiguration::getConfig().tankCost)
{
        serialization["subClass"] = "Tank";
}

Tank::~Tank()
{
}

bool Tank::canMoveAboveTerrain(Terrain &terrain) {
	return terrain == Sand() || terrain == Dunes() || terrain == Rocks();
}

void Tank::reciveBonusDammage(const Weapon &weapon) {
	life -= weapon.getVehicleBonus();
}
