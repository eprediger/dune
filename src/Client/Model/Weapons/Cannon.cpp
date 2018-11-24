#include "Cannon.h"
#include "Model/GlobalConfig.h"

Cannon::Cannon() :
	Weapon(GlobalConfig.cannonDamage,
		   GlobalConfig.cannonShootingRate,
		   GlobalConfig.cannonBonus) {}

Cannon::~Cannon() {}

int Cannon::getInfantryBonus() const {
    return 0;
}

int Cannon::getVehicleBonus() const {
	return 0;
}

int Cannon::getBuildingBonus() const {
	return 0;
}
