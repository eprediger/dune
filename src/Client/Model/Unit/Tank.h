#ifndef __TANK_H__
#define __TANK_H__

#include "OffensiveUnit.h"

class Tank : public OffensiveUnit {
public:
	explicit Tank(nlohmann::json& j);
	virtual Unit::UnitType getUnitType();

	~Tank();
};

#endif
