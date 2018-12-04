#include "LightInfantry.h"
#include "Unit.h"

LightInfantry::LightInfantry(nlohmann::json& j) :
	OffensiveUnit(j) {}

LightInfantry::~LightInfantry() {}

Unit::UnitType LightInfantry::getUnitType() {
	return Unit::LIGHT_INFANTRY;
}
