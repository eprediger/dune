#include "Raider.h"

Raider::Raider(nlohmann::json& j) :
	OffensiveUnit(j) {}

Raider::~Raider() {}

Unit::UnitType Raider::getUnitType() {
	return Unit::RAIDER;
}
