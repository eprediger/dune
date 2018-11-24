#include "Trike.h"
#include "Model/Weapons/Weapons.h"

Trike::Trike(int x, int y) :
	OffensiveUnit(x, y,
	              GlobalConfig.trikeHitPoints,
	              GlobalConfig.trikeRange,
	              Weapons::assaultRifle,
	              GlobalConfig.trikeSpeed,
	              GlobalConfig.trikeCost) {}

Trike::~Trike() {}

bool Trike::canMoveAboveTerrain(Terrain &terrain) {
	return terrain == Sand() || terrain == Dunes() || terrain == Rocks();
}

void Trike::reciveBonusDammage(const Weapon &weapon) {
	life -= weapon.getVehicleBonus();
}
