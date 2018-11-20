#include "AssaultRifle.h"
#include "../GlobalConfig.h"

AssaultRifle::AssaultRifle() :
	Weapon(GlobalConfig.assaultRifleDamage,
		   GlobalConfig.assaultRifleShootingRate,
		   GlobalConfig.assaultRifleBonus) {}

AssaultRifle::~AssaultRifle() {}

int AssaultRifle::getInfantryBonus() const {
	return bonus;
}

int AssaultRifle::getVehicleBonus() const {
    return 0;
}

int AssaultRifle::getBuildingBonus() const {
	return 0;
}

