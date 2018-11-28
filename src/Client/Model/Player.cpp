#include "Model/Player.h"
#include "PlayerTrainingCenter.h"
#include <algorithm>
#include <vector>
#include <string>

Player::Player(nlohmann::json& j) :
    id(j["id"]),
    house(j["house"].get<std::string>()),
    generatedEnergy(j["generated_energy"]),  // Inicial es 0
    consumedEnergy(j["consumed_energy"]),   // Inicial es 0
    gold(j["gold"]),
    trainingCenter(new PlayerTrainingCenter(j["trainingCenter"])),
    buildingCenter(new PlayerBuildingCenter(j["buildingCenter"])) {}

void Player::update(nlohmann::json& j) {
    generatedEnergy = j["generated_energy"];
    consumedEnergy = j["consumed_energy"];
    gold = j["gold"];
    trainingCenter->update(j["trainingCenter"]);
    buildingCenter->update(j["buildingCenter"]);
}

bool Player::operator==(const Player &other) const {
    return this->id == other.id;
}

int& Player::getId() {
    return this->id;
}

std::string& Player::getHouse() {
    return this->house;
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
    std::vector<Building*>::iterator it = buildings.begin();
    while (it != buildings.end()) {
        if ((*it)->isDead()) {
            it = buildings.erase(it);
        } else {
            it++;
        }
    }
}

void Player::addBuilding(Building *building) {
    buildings.push_back(building);
    building->setPlayer(this);
}