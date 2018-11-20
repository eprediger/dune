#include "Harvester.h"

#include "../Map.h"

// #define TIME_FACTOR 2

Harvester::Harvester(int x, int y) :
	Unit(x, y,
	     GlobalConfig.harvesterHitPoints,
	     GlobalConfig.harvesterSpeed,
	     GlobalConfig.harvesterCost),
	spiceCapacity(GlobalConfig.harvesterSpiceCapacity),
	spiceCollected(0),
	refinery(nullptr),
	farm_speed(GlobalConfig.harvesterFarmSpeed),
	actual_farm_speed(0),
	load_speed(GlobalConfig.harvesterLoadSpeed),
	actual_load_speed(0) {}

Harvester::~Harvester() {}

bool Harvester::canMoveAboveTerrain(Terrain &terrain) {
	return terrain == Sand() || terrain == Dunes() || terrain == Rocks();
}

void Harvester::reciveBonusDammage(const Weapon &weapon) {
	life -= weapon.getVehicleBonus();
}

void Harvester::actionOnPosition(Map &map, Position &pos) {
	map.setDestiny(*this, pos.x, pos.y);
//    map.getClosestRefinery(pos);
	state = (UnitState*)&Unit::following;
	farming_position = pos;
}

UnitState *Harvester::makeFollow(Map &map) {
	if (this->move(map)) {
		return (UnitState *) &Unit::following;
	} else {
		std::cout << "Following => Farming" << std::endl;
		return (UnitState*)&Unit::farming;
	}
}

#include <iostream>
UnitState *Harvester::makeFarming(Map &map) {
	if (actual_farm_speed++ < farm_speed*TIME_FACTOR){
		return (UnitState *) &Unit::farming;
	} else {
        actual_farm_speed = 0;
	}

	// Revisa si esta llena. Si no lo esta, intenta cosechar
	if (!this->isFull()) {
		// Intenta cosechar, si puede hacerlo, mantiene el estado
		if (this->farm(map)) {
			std::cout << "SpiceCollected: " << spiceCollected << std::endl;
			return (UnitState *) &Unit::farming;
		}

		// Si no puede cosechar, busca un nuevo lugar
		Position new_pos = map.getClosestSpeciaPosition(this->pos, 5);
		if (!(new_pos == this->pos)){
			farming_position = new_pos;
			map.setDestiny(*this, new_pos.x, new_pos.y);
			std::cout << "Farming => Following " << std::endl;
			return (UnitState *) &Unit::following;
		}
	}

	// Si esta llena o si no encontro una nueva posicion, busca volver a la refineria
	if (this->refinery == nullptr) {
		this->refinery = (SpiceRefinery *) player->getClosestBuilding(this->pos, Building::SPICE_REFINERY);
		if (this->refinery == nullptr) {
			// Si no encontro ninguna refineria, se queda en el lugar
			std::cout << "Backing => Stopped: " << std::endl;
			return (UnitState *) &Unit::stopped;
		}
	}

	map.free(*refinery);
	map.setDestiny(*this, refinery->getPosition().x, refinery->getPosition().y);
	map.occupy(*refinery);


	std::cout << "Farming => Backing" << std::endl;
	return (UnitState *) &Unit::backing;
}

UnitState *Harvester::makeLoading(Map &map) {
	if (actual_load_speed++ < load_speed*TIME_FACTOR){
		return (UnitState *) &Unit::loading;
    } else {
        actual_load_speed = 0;
    }

	if (spiceCollected != 0) {
		if (refinery->load(*player)){
			spiceCollected -= 1;
			std::cout << "Loading! SpiceCollected restante: " << spiceCollected << std::endl;
			return (UnitState *) &Unit::loading;
		} else{
			return (UnitState *) &Unit::stopped;
		}
	} else {
		map.setDestiny(*this, farming_position.x, farming_position.y);
		std::cout << "Loading => Following " << std::endl;
		return (UnitState*)&Unit::following;
	}
}

UnitState* Harvester::makeBacking(Map &map) {
	if (this->move(map)) {
		return (UnitState *) &Unit::backing;
	} else {
		if (spiceCollected == 0) {
			std::cout << "Backing => Stopped 2" << std::endl;
			return (UnitState*)&Unit::stopped;
		} else {
			std::cout << "Backing => Loading: " << std::endl;
			return (UnitState*)&Unit::loading;
		}
	}
}

bool Harvester::farm(Map &map) {
	int farm = map.at(farming_position).getFarm();
	if (farm != 0) {
		spiceCollected += farm;
		return true;
	} else {
		return false;
	}
}

bool Harvester::isFull() {
	return spiceCollected >= spiceCapacity;
}
