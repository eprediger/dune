#include "SpiceRefinery.h"

SpiceRefinery::SpiceRefinery() :
	Building(GlobalConfig.spiceRefineryEnergy,
			 GlobalConfig.spiceRefineryCost,
			 GlobalConfig.spiceRefineryHitPoints),
	capacity(GlobalConfig.spiceRefinerySpiceCapacity) {}

SpiceRefinery::~SpiceRefinery() {}
