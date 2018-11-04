#include "Harvester.h"

Harvester::Harvester(int x, int y) :
	PassiveUnit(x, y,
	  GlobalConfig.harvesterHitPoints,
	  GlobalConfig.harvesterSpeed),
    spiceCapacity(GlobalConfig.harvesterSpiceCapacity) {}

Harvester::~Harvester() {}

bool Harvester::canMoveAboveTerrain(Terrain &terrain) {
	return terrain == Sand() || terrain == Dunes() || terrain == Rocks();
}