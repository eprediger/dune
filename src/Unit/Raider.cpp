#include "Raider.h"

Raider::Raider(int x, int y) :
		OffensiveUnit(x, y,
		  GlobalConfig.raiderHitPoints,
		  GlobalConfig.raiderRange,
		  SmallCannon(),
		  GlobalConfig.raiderSpeed) {}

Raider::~Raider() {}

bool Raider::canMoveAboveTerrain(Terrain &terrain) {
	return terrain == Sand() || terrain == Dunes() || terrain == Rocks();
}