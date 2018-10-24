#include "Infantry.h"

#include "Summit.h"

Infantry::Infantry() {}

Infantry::Infantry(int x, int y) : Unity(x, y) {}

bool Infantry::canMoveAboveTerrain(Terrain &terrain) {
    return terrain == Sand() || terrain == Summit() || terrain == Precipice();
}
