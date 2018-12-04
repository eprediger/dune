#include "Harvester.h"

Harvester::Harvester(nlohmann::json& j) :
	Unit(j) {}

Harvester::~Harvester() {}

Unit::UnitType Harvester::getUnitType() {
	return Unit::HARVESTER;
}
