#include "Building.h"

Building::Building(const int x, const int y, const int hitPoints, const int energy, const int cost, BuildingType type) :
	Attackable(hitPoints),
	Positionable(x, y),
	energy(energy),
	cost(cost),
	key(type) {}

Building::~Building() {}

void Building::reciveBonusDammage(const Weapon &weapon) {
	life -= weapon.getBuildingBonus();
}

bool Building::is(Building::BuildingType type) {
    return this->key == type;
}
