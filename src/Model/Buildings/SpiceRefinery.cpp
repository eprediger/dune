#include "SpiceRefinery.h"

SpiceRefinery::SpiceRefinery(const int x, const int y) :
        Building(x, y,
                 GlobalConfig.spiceRefineryEnergy,
                 GlobalConfig.spiceRefineryCost,
                 GlobalConfig.spiceRefineryHitPoints,
                 SPICE_REFINERY),
		capacity(GlobalConfig.spiceRefinerySpiceCapacity) ,
		availableCapacity(0) {}

SpiceRefinery::~SpiceRefinery() {}

void SpiceRefinery::load(int charge) {
	availableCapacity-= charge;
}
