#include "SpiceSilo.h"

SpiceSilo::SpiceSilo(const int x, const int y) :
	Building(x, y,
			 GlobalConfig.spiceSiloEnergy,
			 GlobalConfig.spiceSiloCost,
			 GlobalConfig.spiceSiloHitPoints),
	capacity(GlobalConfig.spiceSiloSpiceCapacity) {}

SpiceSilo::~SpiceSilo() {}
