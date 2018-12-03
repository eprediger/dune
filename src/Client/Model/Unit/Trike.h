#ifndef __TRIKE_H__
#define __TRIKE_H__

#include "OffensiveUnit.h"

class Trike : public OffensiveUnit {
public:
	explicit Trike(nlohmann::json& j);

	virtual Unit::UnitType getUnitType();

	~Trike();
};

#endif
