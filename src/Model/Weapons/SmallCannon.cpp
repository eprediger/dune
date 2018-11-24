#include "SmallCannon.h"
#include "Model/GlobalConfig.h"

SmallCannon::SmallCannon() :
	Weapon(GlobalConfig.smallCannonDamage,
		   GlobalConfig.smallCannonShootingRate,
		   GlobalConfig.smallCannonBonus) {}

SmallCannon::~SmallCannon() {}

int SmallCannon::getInfantryBonus() const {
    return 0;
}

int SmallCannon::getVehicleBonus() const {
	return bonus;
}

int SmallCannon::getBuildingBonus() const {
	return bonus;
}
