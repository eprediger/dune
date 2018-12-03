#include "HeavyInfantry.h"
#include "Unit.h"

HeavyInfantry::HeavyInfantry(nlohmann::json& j) 
		:OffensiveUnit(j){}

HeavyInfantry::~HeavyInfantry() {}


Unit::UnitType HeavyInfantry::getUnitType(){
	return Unit::HEAVY_INFANTRY;
}
