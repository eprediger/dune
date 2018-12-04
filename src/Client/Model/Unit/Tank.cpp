#include "Tank.h"

Tank::Tank(nlohmann::json& j) :
	OffensiveUnit(j) {}

Tank::~Tank() {}

Unit::UnitType Tank::getUnitType() {
	return Unit::TANK;
}
