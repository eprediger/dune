#include "tank.h"

Tank::Tank(int x, int y) :
		OffensiveUnit(x, y,
		  GlobalConfig.tankHitPoints,
		  GlobalConfig.tankRange,
		  Cannon(),
		  GlobalConfig.tankSpeed) {}

Tank::~Tank() {}

bool Tank::canMoveAboveTerrain(Terrain &terrain) {
	return terrain == Sand() || terrain == Dunes() || terrain == Rocks();
}