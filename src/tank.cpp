#include "tank.h"

Tank::Tank(int x, int y) :
	Unity(x, y,
		  GlobalConfig.tankHitPoints,
		  GlobalConfig.tankRange,
		  Cannon(),
		  GlobalConfig.tankSpeed) {}

Tank::~Tank() {}
