#include "Player.h"
#include <algorithm>
#include "PlayerTrainingCenter.h"
Player::Player(int id, ConstructionYard &construction_yard) :
    id(id),
    generatedEnergy(5000),  // Inicial es 0
    consumedEnergy(2500),   // Inicial es 0 
    gold(10000),
    gold_limit(10000),
    trainingCenter(new PlayerTrainingCenter()),
    construction_yard(&construction_yard) {
    construction_yard.setPlayer(this);
}

bool Player::operator==(const Player &other) const {
    return this->id == other.id;
}

void Player::addGold(int gold_to_add) {
    gold += gold_to_add;
}

void Player::subGold(int gold_to_sub) {
    // if (gold_to_sub > gold ) throw error -> Ver que hacer
    gold -= gold_to_sub;
}

void Player::addBuilding(Building *building) {
    buildings.push_back(building);
    building->setPlayer(this); 
    if (building->is(Building::WIND_TRAP)) {
        this->generatedEnergy += building->energy;
    } else {
        this->consumedEnergy += building->energy;
    }
    this->gold -= building->cost;
}

//bool Player::hasBuilding(Building *building) {
//    return std::find(buildings.begin(), buildings.end(), building) != buildings.end();
//}

Building *Player::getClosestBuilding(Position pos, Building::BuildingType type) {
    for (auto& b : buildings) {
        if ( b->is(type) ) {
            return b;
        }
    }
    return nullptr;
}

void Player::trainUnits(){
    trainingCenter->trainUnits(buildings);
}

bool Player::lose() {
//    return this->lose;
    return this->construction_yard == nullptr;
}

int& Player::getId() {
    return this->id;
}

ConstructionYard &Player::getConstructionYard() {
    return *construction_yard;
}

bool Player::hasBuilding(Building& building) {
    if (building == *construction_yard){
        return true;
    }
    for (auto& b : buildings){
        if (*b == building){
            return true;
        }
    }
    return false;
}

bool Player::hasBuilding(Building::BuildingType buildingType) {
    bool buildingTypeFound = false;
    unsigned i = 0;
    while ((!buildingTypeFound) && (i < this->buildings.size())) {
        buildingTypeFound = this->buildings[i]->is(buildingType);
        i++;
    }
    return buildingTypeFound;
}

void Player::cleanDeadBuildings() {
    if (Attackable::isDead(this->construction_yard)){
        this->construction_yard = nullptr;
    }
    auto result_itr(std::remove_if(buildings.begin(), buildings.end(), Attackable::isDead));
    if (result_itr != buildings.end()){
        buildings.erase(result_itr, buildings.end());
    }
}

std::vector<Unit*>& Player::getTrainedUnits(Map& map){
        return this->trainingCenter->getReadyUnits(map,buildings,construction_yard);
}
