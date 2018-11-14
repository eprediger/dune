#include "SpiceSilo.h"

SpiceSilo::SpiceSilo(const int x, const int y) :
        Building(x, y,
                 GlobalConfig.spiceSiloEnergy,
                 GlobalConfig.spiceSiloCost,
                 GlobalConfig.spiceSiloHitPoints,
                 GlobalConfig.spiceSiloSpicWidth,
                 GlobalConfig.spiceSiloSpicHeight,
                 SPICE_SILO),
	capacity(GlobalConfig.spiceSiloSpiceCapacity) {}

SpiceSilo::~SpiceSilo() {}
