#include "WindTrap.h"

WindTrap::WindTrap() :
	Building(GlobalConfig.windTrapEnergy,
			 GlobalConfig.windTrapCost,
			 GlobalConfig.windTrapHitPoints) {}

WindTrap::~WindTrap() {}
