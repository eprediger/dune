#include "Building.h"

Building::Building(const int x, const int y, const int hitPoints, const int energy, const int cost) :
	Attackable(hitPoints),
	Positionable(x, y),
	energy(energy),
	cost(cost) {}

Building::~Building() {}

void Building::reciveBonusDammage(const Weapon &weapon) {
	life -= weapon.getBuildingBonus();
}
