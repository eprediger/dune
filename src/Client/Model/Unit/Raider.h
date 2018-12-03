#ifndef __RAIDER_H__
#define __RAIDER_H__

#include "OffensiveUnit.h"

class Raider : public OffensiveUnit {
public:
	explicit Raider(nlohmann::json& j);
	virtual Unit::UnitType getUnitType();
	~Raider();
};

#endif	// __RAIDER_H__
