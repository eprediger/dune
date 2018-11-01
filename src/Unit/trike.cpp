#include "trike.h"

Trike::Trike(int x, int y) :
		OffensiveUnit(x, y,
		  GlobalConfig.trikeHitPoints,
		  GlobalConfig.trikeRange,
		  AssaultRifle(),
		  GlobalConfig.trikeSpeed) {}

Trike::~Trike() {}

bool Trike::canMoveAboveTerrain(Terrain &terrain) {
	return terrain == Sand() || terrain == Dunes() || terrain == Rocks();
}