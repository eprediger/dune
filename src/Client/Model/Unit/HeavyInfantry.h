#ifndef __HEAVY_INFANTRY_H__
#define __HEAVY_INFANTRY_H__

#include "OffensiveUnit.h"

class HeavyInfantry : public OffensiveUnit {
public:
	explicit HeavyInfantry(nlohmann::json& j);
	virtual Unit::UnitType getUnitType();
	~HeavyInfantry();
};

#endif	// __HEAVY_INFANTRY_H__
