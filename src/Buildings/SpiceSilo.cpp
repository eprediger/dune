#include "SpiceSilo.h"

SpiceSilo::SpiceSilo() :
	Building(GlobalConfig.spiceSiloEnergy,
			 GlobalConfig.spiceSiloCost,
			 GlobalConfig.spiceSiloHitPoints),
	capacity(GlobalConfig.spiceSiloSpiceCapacity) {}

SpiceSilo::~SpiceSilo() {}
