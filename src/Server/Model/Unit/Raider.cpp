#include <Model/GameConfiguration.h>
#include "Raider.h"
#include "Model/Weapons/Weapons.h"

Raider::Raider(int x, int y) :
        OffensiveUnit(x, y, GameConfiguration::getConfig().raiderHitPoints, GameConfiguration::getConfig().raiderRange, Weapons::smallCannon,
                      GameConfiguration::getConfig().raiderSpeed, GameConfiguration::getConfig().raiderCost)
{
        serialization["subClass"] = "Raider";
}

Raider::~Raider() {}

bool Raider::canMoveAboveTerrain(Terrain &terrain) {
	return terrain == Sand() || terrain == Dunes() || terrain == Rocks();
}

void Raider::reciveBonusDammage(const Weapon &weapon) {
	life -= weapon.getVehicleBonus();
}
