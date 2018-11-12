#ifndef __SPICE_SILO_H__
#define __SPICE_SILO_H__

#include "Building.h"

class SpiceSilo : public Building {
public:
	SpiceSilo(const int x, const int y);
	~SpiceSilo();

private:
	int capacity;
};

#endif
