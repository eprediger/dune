#include "WindTrap.h"

WindTrap::WindTrap(const int x, const int y, int blockWidth, int blockHeight) :
	Building(x, y, blockWidth, blockHeight,
	         GlobalConfig.windTrapEnergy,
	         GlobalConfig.windTrapCost,
	         GlobalConfig.windTrapHitPoints,
	         GlobalConfig.windTrapWidth,
	         GlobalConfig.windTrapHeight,
	         WIND_TRAP) {}

WindTrap::~WindTrap() {}
