#include <Model/GameConfiguration.h>
#include "SpiceRefinery.h"

#include <Model/Player.h>

SpiceRefinery::SpiceRefinery(const int x, const int y, int blockWidth, int blockHeight) :
	Building(x, y, blockWidth, blockHeight,
	         GameConfiguration::getConfig().spiceRefineryEnergy,
	         GameConfiguration::getConfig().spiceRefineryCost,
	         GameConfiguration::getConfig().spiceRefineryHitPoints,
	         GameConfiguration::getConfig().spiceRefineryWidth,
	         GameConfiguration::getConfig().spiceRefineryHeight,
	         SPICE_REFINERY),
	capacity(GameConfiguration::getConfig().spiceRefinerySpiceCapacity),
	availableCapacity(0) {}

SpiceRefinery::~SpiceRefinery() {}

bool SpiceRefinery::load(Player &player) {
	if (availableCapacity < capacity) {
		++availableCapacity;
		player.addGold(1);
		return true;
	} else {
		return false;
	}
}
