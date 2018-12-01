#include <Model/GameConfiguration.h>
#include "SpiceSilo.h"

SpiceSilo::SpiceSilo(const int x, const int y, int blockWidth, int blockHeight) :
        Building(x, y, blockWidth, blockHeight,
                 GameConfiguration::getConfig().spiceSiloEnergy,
                 GameConfiguration::getConfig().spiceSiloCost,
                 GameConfiguration::getConfig().spiceSiloHitPoints,
                 GameConfiguration::getConfig().spiceSiloWidth,
                 GameConfiguration::getConfig().spiceSiloHeight,
                 SPICE_SILO),
	capacity(GameConfiguration::getConfig().spiceSiloSpiceCapacity) {}

SpiceSilo::~SpiceSilo() {}


int SpiceSilo::getCapacity() {
    return this->capacity;
}