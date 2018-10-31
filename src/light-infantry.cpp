#include "light-infantry.h"

LightInfantry::LightInfantry(int x, int y) :
	Unity(x, y,
		  GlobalConfig.lightInfantryHitPoints,
		  GlobalConfig.lightInfantryRange,
		  AssaultRifle(),
		  GlobalConfig.lightInfantrySpeed) {}

LightInfantry::~LightInfantry() {}

bool LightInfantry::canMoveAboveTerrain(Terrain &terrain) {
    return terrain == Sand() || terrain == Summit();
}
