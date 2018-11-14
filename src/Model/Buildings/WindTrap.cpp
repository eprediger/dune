#include "WindTrap.h"

WindTrap::WindTrap(const int x, const int y) :
        Building(x, y,
                 GlobalConfig.windTrapEnergy,
                 GlobalConfig.windTrapCost,
                 GlobalConfig.windTrapHitPoints,
                 WIND_TRAP) {}

WindTrap::~WindTrap() {}
