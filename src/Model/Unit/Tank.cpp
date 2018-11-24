#include "Tank.h"
#include "Model/Weapons/Weapons.h"
#include "Model/GlobalConfig.h"

Tank::Tank(int x, int y) :
        OffensiveUnit(x, y, GlobalConfig.tankHitPoints, GlobalConfig.tankRange, Weapons::cannon, GlobalConfig.tankSpeed,
                      GlobalConfig.tankCost) {}

Tank::~Tank() {}

bool Tank::canMoveAboveTerrain(Terrain &terrain) {
	return terrain == Sand() || terrain == Dunes() || terrain == Rocks();
}

void Tank::reciveBonusDammage(const Weapon &weapon) {
	life -= weapon.getVehicleBonus();
}
