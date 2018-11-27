#ifndef __HEAVY_INFANTRY_H__
#define __HEAVY_INFANTRY_H__

#include "OffensiveUnit.h"

class HeavyInfantry : public OffensiveUnit {
public:
	HeavyInfantry(nlohmann::json& j);
	~HeavyInfantry();
};

#endif	// __HEAVY_INFANTRY_H__
