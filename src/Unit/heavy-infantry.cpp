#include "heavy-infantry.h"

HeavyInfantry::HeavyInfantry(int x, int y) :
	Unit(x, y,
		  GlobalConfig.heavyInfantryHitPoints,
		  GlobalConfig.heavyInfantryRange,
		  RocketLauncher(),
		  GlobalConfig.heavyInfantrySpeed) {}

HeavyInfantry::~HeavyInfantry() {}
