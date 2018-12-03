#include "Trike.h"

Trike::Trike(nlohmann::json& j) :
	OffensiveUnit(j){}

Trike::~Trike() {}

Unit::UnitType Trike::getUnitType(){
	return Unit::TRIKE;
}