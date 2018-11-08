#include "Tank.h"
#include "../Weapons/Weapons.h"

Tank::Tank(int x, int y) :
		OffensiveUnit(x, y,
		  GlobalConfig.tankHitPoints,
		  GlobalConfig.tankRange,
		  Weapons::cannon,
		  GlobalConfig.tankSpeed) {}

Tank::~Tank() {}

bool Tank::canMoveAboveTerrain(Terrain &terrain) {
	return terrain == Sand() || terrain == Dunes() || terrain == Rocks();
}

void Tank::reciveBonusDammage(const Weapon &weapon) {
	life -= weapon.getVehicleBonus();
}
