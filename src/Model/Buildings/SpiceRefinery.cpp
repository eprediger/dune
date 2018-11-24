#include "SpiceRefinery.h"

#include "Model/Player.h"

SpiceRefinery::SpiceRefinery(const int x, const int y, int blockWidth, int blockHeight) :
        Building(x, y, blockWidth, blockHeight,
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
		return true;
	} else {
		return false; 
	}
}
