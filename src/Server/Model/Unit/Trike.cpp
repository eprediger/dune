#include <Model/GameConfiguration.h>
#include "Trike.h"
#include "Model/Weapons/Weapons.h"

Trike::Trike(int x, int y) :
	OffensiveUnit(x, y,
	              GameConfiguration::getConfig().trikeHitPoints,
	              GameConfiguration::getConfig().trikeRange,
	              Weapons::assaultRifle,
	              GameConfiguration::getConfig().trikeSpeed,
	              GameConfiguration::getConfig().trikeCost)
{
	serialization["subClass"] = "Trike";
}

Trike::~Trike() {}

bool Trike::canMoveAboveTerrain(Terrain &terrain) {
	return terrain == Sand() || terrain == Dunes() || terrain == Rocks();
}

void Trike::reciveBonusDammage(const Weapon &weapon) {
	life -= weapon.getVehicleBonus();
}
