#ifndef __SPICE_REFINERY_H__
#define __SPICE_REFINERY_H__

#include "Building.h"

class SpiceRefinery : public Building {
public:
	explicit SpiceRefinery(nlohmann::json& j);
	~SpiceRefinery();
};

#endif
