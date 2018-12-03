#include "Harvester.h"
#include <Model/GameConfiguration.h>
#include <Model/Map.h>

Harvester::Harvester(int x, int y) :
	Unit(x, y,
	     GameConfiguration::getConfig().harvesterHitPoints,
	     GameConfiguration::getConfig().harvesterSpeed,
	     GameConfiguration::getConfig().harvesterCost),
	spiceCapacity(GameConfiguration::getConfig().harvesterSpiceCapacity),
	spiceCollected(0),
	refinery(nullptr),
	farm_speed(GameConfiguration::getConfig().harvesterFarmSpeed),
	actual_farm_speed(0),
	load_speed(GameConfiguration::getConfig().harvesterLoadSpeed),
	actual_load_speed(0) {
	serialization["subClass"] = "Harvester";
}

Harvester::~Harvester() {}

bool Harvester::canMoveAboveTerrain(Terrain &terrain) {
	return terrain == Sand() || terrain == Dunes() || terrain == Rocks();
}

void Harvester::reciveBonusDammage(const Weapon &weapon) {
	life -= weapon.getVehicleBonus();
}

void Harvester::actionOnPosition(Map &map, Position &pos) {
	map.setDestiny(*this, pos.x, pos.y);
	state = (UnitState*)&Unit::following;
	farming_position = pos;
}

UnitState *Harvester::makeFollow(Map &map) {
	if (this->move(map)) {
		return (UnitState *) &Unit::following;
	} else {
		return (UnitState*)&Unit::farming;
	}
}

#include <iostream>
UnitState *Harvester::makeFarming(Map &map) {
	if (actual_farm_speed++ < farm_speed) {
		return (UnitState *) &Unit::farming;
	} else {
		actual_farm_speed = 0;
	}

	// Revisa si esta llena. Si no lo esta, intenta cosechar
	if (!this->isFull()) {
		// Intenta cosechar, si puede hacerlo, mantiene el estado
		if (this->farm(map)) {
			return (UnitState *) &Unit::farming;
		}

		// Si no puede cosechar, busca un nuevo lugar
		Position new_pos = map.getClosestSpeciaPosition(this->pos, 5);
		if (!(new_pos == this->pos)) {
			farming_position = new_pos;
			map.setDestiny(*this, new_pos.x, new_pos.y);
			return (UnitState *) &Unit::following;
		}
	}

	// Si esta llena o si no encontro una
	// nueva posicion, busca volver a la refineria
	if (this->refinery == nullptr) {
		this->refinery = (SpiceRefinery*) player->getClosestBuilding(this->pos, Building::SPICE_REFINERY);
		if (this->refinery == nullptr) {
			// Si no encontro ninguna refineria, se queda en el lugar
			return (UnitState *) &Unit::stopped;
		}
	}

	map.free(*refinery);
	map.setDestiny(*this, refinery->getPosition().x, refinery->getPosition().y);
	map.occupy(refinery);

	return (UnitState *) &Unit::backing;
}

UnitState *Harvester::makeLoading(Map &map) {
	if (actual_load_speed++ < load_speed) {
		return (UnitState *) &Unit::loading;
	} else {
		actual_load_speed = 0;
	}

	if (spiceCollected != 0) {
		if (refinery->load(*player)) {
			spiceCollected -= 1;
			return (UnitState *) &Unit::loading;
		} else {
			return (UnitState *) &Unit::stopped;
		}
	} else {
		map.setDestiny(*this, farming_position.x, farming_position.y);
		return (UnitState*)&Unit::following;
	}
}

UnitState* Harvester::makeBacking(Map &map) {
	if (this->move(map)) {
		return (UnitState *) &Unit::backing;
	} else {
		if (spiceCollected == 0) {
			return (UnitState*)&Unit::stopped;
		} else {
			return (UnitState*)&Unit::loading;
		}
	}
}

bool Harvester::farm(Map &map) {
	int farm = map.at(farming_position).farm();
	if (farm != 0) {
		spiceCollected += farm;
		map.updateSpice(farming_position.x, farming_position.y);
		return true;
	} else {
		return false;
	}
}

bool Harvester::isFull() {
	return spiceCollected >= spiceCapacity;
}
