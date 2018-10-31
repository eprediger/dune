#include "Building.h"

Building::Building(const int hitPoints, const int energy, const int cost) :
	Attackable(hitPoints),
	Positionable(0,0),
	energy(energy),
	cost(cost) {}

Building::~Building() {}
