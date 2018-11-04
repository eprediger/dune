#include "HeavyInfantry.h"

HeavyInfantry::HeavyInfantry(int x, int y) :
	OffensiveUnit(x, y,
		  GlobalConfig.heavyInfantryHitPoints,
		  GlobalConfig.heavyInfantryRange,
		  RocketLauncher(),
		  GlobalConfig.heavyInfantrySpeed) {}

HeavyInfantry::~HeavyInfantry() {}

bool HeavyInfantry::canMoveAboveTerrain(Terrain &terrain) {
	return terrain == Sand() || terrain == Dunes() || terrain == Rocks() || terrain == Summit();
}