#include "SpiceRefinery.h"

SpiceRefinery::SpiceRefinery(const int x, const int y) :
	Building(x, y,
			 GlobalConfig.spiceRefineryEnergy,
			 GlobalConfig.spiceRefineryCost,
			 GlobalConfig.spiceRefineryHitPoints),
	capacity(GlobalConfig.spiceRefinerySpiceCapacity) {}

SpiceRefinery::~SpiceRefinery() {}
