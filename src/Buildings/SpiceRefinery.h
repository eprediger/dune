#ifndef __SPICE_REFINERY_H__
#define __SPICE_REFINERY_H__

#include "Building.h"

class SpiceRefinery : public Building {
public:
	SpiceRefinery(const int x, const int y);
	~SpiceRefinery();

private:
	int capacity;	
};

#endif
