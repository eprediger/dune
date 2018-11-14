#include "Harvester.h"

#include "../Map.h"


Harvester::Harvester(int x, int y) :
	Unit(x, y,
	  GlobalConfig.harvesterHitPoints,
	  GlobalConfig.harvesterSpeed),
    spiceCapacity(GlobalConfig.harvesterSpiceCapacity),
    spiceCollected(0) {}

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
	back_pos = this->pos;
}

UnitState *Harvester::makeFollow(Map &map) {
	if (this->move(map)){
		return state;
	} else {
		return (UnitState*)&Unit::farming;
	}
}

#include <iostream>
UnitState *Harvester::makeFarming(Map &map) {
//	map.at(pos).getFarm();
	if (!this->farm(map)) {
		map.setDestiny(*this, back_pos.x, back_pos.y);
		state = (UnitState*)&Unit::backing;
	}
	std::cout << "SpiceCollected: " << spiceCollected << std::endl;
	return state;
}

UnitState *Harvester::makeLoading(Map &map) {
	if (spiceCollected != 0) {
        spiceCollected -= 1;
        refinery->load(1);
        std::cout << "Loading! SpiceCollected restante: " << spiceCollected << std::endl;
        return state;
	} else {
		map.setDestiny(*this, farming_position.x, farming_position.y);
		return (UnitState*)&Unit::following;
	}
}

UnitState *Harvester::makeBacking(Map &map) {
    if (this->refinery == nullptr) {
        this->refinery = (SpiceRefinery*) player->getClosestBuilding(this->pos, Building::SPICE_REFINERY);
        if (this->refinery == nullptr){
            state = (UnitState*)&Unit::stopped;
        }
    } else if (this->move(map)) {
        return state;
    } else {
    	if (spiceCollected == 0){
			return (UnitState*)&Unit::stopped;
    	} else {
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
