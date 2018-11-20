#ifndef __SPICE_REFINERY_H__
#define __SPICE_REFINERY_H__

#include "Building.h"

class SpiceRefinery : public Building {
public:
	SpiceRefinery(const int x, const int y, int blockWidth, int blockHeight);
	~SpiceRefinery();

	bool load(Player &player);

private:
	int capacity;
	int availableCapacity;
};

#endif
