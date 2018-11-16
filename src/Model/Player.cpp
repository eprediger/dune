#include "Player.h"
#include <algorithm>
#include "PlayerTrainingCenter.h"
Player::Player(int id) :
    id(id),
    generatedEnergy(5000),  // Inicial es 0
    consumedEnergy(2500),   // Inicial es 0 
    gold(10000),
    gold_limit(10000),
    trainingCenter(new PlayerTrainingCenter()) {}

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

/*void Player::addEnergy(int energy_to_add) {
    energy += energy_to_add;
}

void Player::subEnergy(int energy_to_sub) {
    energy -= energy_to_sub;
}*/

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

bool Player::hasBuilding(Building *building) {
    return std::find(buildings.begin(), buildings.end(), building) != buildings.end();
}

void Player::cleanBuilding(Building *building) {
    buildings.erase(std::find(buildings.begin(), buildings.end(), building));
}

Building *Player::getClosestBuilding(Position pos, Building::BuildingType type) {
    for (auto b : buildings) {
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
    return construction_yard == nullptr;
}

int& Player::getId() {
    return this->id;
}

std::vector<Unit*>& Player::getTrainedUnits(Map& map){ 
        return this->trainingCenter->getReadyUnits(map,buildings,construction_yard);
}