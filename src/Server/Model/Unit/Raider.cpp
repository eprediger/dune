#include "Raider.h"
#include "Model/Weapons/Weapons.h"
#include "Model/GlobalConfig.h"

Raider::Raider(int x, int y) :
        OffensiveUnit(x, y, GlobalConfig.raiderHitPoints, GlobalConfig.raiderRange, Weapons::smallCannon,
                      GlobalConfig.raiderSpeed, GlobalConfig.raiderCost)
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
