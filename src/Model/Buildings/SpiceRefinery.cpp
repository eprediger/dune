#include "SpiceRefinery.h"

#include "../Player.h"

SpiceRefinery::SpiceRefinery(const int x, const int y) :
        Building(x, y,
                 GlobalConfig.spiceRefineryEnergy,
                 GlobalConfig.spiceRefineryCost,
                 GlobalConfig.spiceRefineryHitPoints,
                 GlobalConfig.spiceRefinerySpicWidth,
                 GlobalConfig.spiceRefinerySpicHeight,
                 SPICE_REFINERY),
		capacity(GlobalConfig.spiceRefinerySpiceCapacity) ,
		availableCapacity(0) {}

SpiceRefinery::~SpiceRefinery() {}

bool SpiceRefinery::load(Player &player) {
	if (availableCapacity < capacity){
		++availableCapacity;
		player.addGold(1);
	};
}
