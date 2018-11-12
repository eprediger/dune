#include "Player.h"
#include <algorithm>

Player::Player(int id) :
    id(id),
    energy(5000), //Reemplazar luego por valores iniciales
    gold(10000),
    gold_limit(10000){

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

void Player::addEnergy(int energy_to_add) {
    energy += energy_to_add;
}

void Player::subEnergy(int energy_to_sub) {
    energy -= energy_to_sub;
}


void Player::addBuilding(Building *building) {
    buildings.push_back(building);
}

bool Player::hasBuilding(Building *building) {
    return std::find(buildings.begin(), buildings.end(), building) != buildings.end();
}

void Player::cleanBuilding(Building *building) {
    buildings.erase(std::find(buildings.begin(), buildings.end(), building));
}


