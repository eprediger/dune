#include "SpiceRefinery.h"

SpiceRefinery::SpiceRefinery(const int x, const int y) :
        Building(x, y,
                 GlobalConfig.spiceRefineryEnergy,
                 GlobalConfig.spiceRefineryCost,
                 GlobalConfig.spiceRefineryHitPoints,
                 SPICE_REFINERY),
	capacity(GlobalConfig.spiceRefinerySpiceCapacity) {}

SpiceRefinery::~SpiceRefinery() {}
