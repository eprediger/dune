#include "Player.h"
#include <algorithm>

Player::Player(int id, ConstructionYard &construction_yard) :
    id(id),
    generatedEnergy(5000),  // Inicial es 0
    consumedEnergy(2500),   // Inicial es 0
    gold(10000),
    gold_limit(10000),
    construction_yard(&construction_yard) {}

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
}

//bool Player::hasBuilding(Building *building) {
//    return std::find(buildings.begin(), buildings.end(), building) != buildings.end();
//}

Building *Player::getClosestBuilding(Position pos, Building::BuildingType type) {
    for (auto b : buildings){
        if ( b->is(type) ){
            return b;
        }
    }
    return nullptr;
}

bool Player::lose() {
    return construction_yard == nullptr;
}

int& Player::getId(){
    return this->id;
}

ConstructionYard &Player::getConstructionYard() {
    return *construction_yard;
}

bool Player::hasBuilding(Building& building) {
    if (building == *construction_yard){
        return true;
    }
    for (auto b : buildings){
        if (*b == building){
            return true;
        }
    }
    return false;
}

void Player::cleanDeadBuildings() {
    if (Attackable::isDead(construction_yard)){
        construction_yard = nullptr;
    }
    auto result_itr(std::remove_if(buildings.begin(), buildings.end(), Attackable::isDead));
    if (result_itr != buildings.end()){
        buildings.erase(result_itr, buildings.end());
    }
}
