#include "Player.h"
#include "PlayerTrainingCenter.h"
#include <algorithm>
#include <vector>
#include <string>
#include <nlohmann/json.hpp>

Player::Player(int id, ConstructionYard &construction_yard) :
    id(id),
    serialization(),
    news(true),
    generatedEnergy(0),
    consumedEnergy(0),
    gold(10000),
    gold_limit(10000),
    trainingCenter(),
    buildingCenter(),
    construction_yard(&construction_yard) {
    construction_yard.setPlayer(this);
    if ((id % 3) == 0) {
        house = "Ordos";
    }
    if ((id % 3) == 1) {
        house = "Atreides";
    }
    if ((id % 3) == 2) {
        house = "Harkonnen";
    }
    serialization["class"] = "Player";
    serialization["id"] = id;
    serialization["house"] = house;
    serialization["generated_energy"] = generatedEnergy;
    serialization["consumed_energy"] = consumedEnergy;
    serialization["gold"] = gold;
    serialization["gold_limit"] = gold_limit;
    serialization["trainingCenter"] = trainingCenter.getSerialization();
    serialization["buildingCenter"] = buildingCenter.getSerialization();
}

bool Player::operator==(const Player &other) const {
    return this->id == other.id;
}

void Player::addGold(int gold_to_add) {
    gold += gold_to_add;
    this->news = true;
    serialization["gold"] = gold;
}

void Player::subGold(int gold_to_sub) {
    // if (gold_to_sub > gold ) throw error -> Ver que hacer
    gold -= gold_to_sub;
    this->news = true;
    serialization["gold"] = gold;
}

void Player::addBuilding(Building *building) {
    buildings.push_back(building);
    building->setPlayer(this);
    if (building->is(Building::WIND_TRAP)) {
        this->generatedEnergy += building->energy;
        serialization["generated_energy"] = generatedEnergy;
    } else {
        this->consumedEnergy += building->energy;
        serialization["consumed_energy"] = consumedEnergy;
    }
    this->gold_limit += building->getCapacity();
    serialization["gold_limit"] = this->gold_limit;
    this->subGold(building->cost);
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

void Player::trainUnits() {
    trainingCenter.trainUnits(buildings);
}

void Player::constructBuildings() {
    buildingCenter.construct();
}

bool Player::lose() {
//    return this->lose;
    return this->construction_yard == nullptr;
}

int Player::getId() const {
    return this->id;
}

std::string& Player::getHouse() {
    return this->house;
}
ConstructionYard &Player::getConstructionYard() {
    return *construction_yard;
}

bool Player::hasBuilding(Building& building) {
    if (construction_yard != nullptr) {
        if (building == *construction_yard) {
            return true;
        }
    }
    for (auto& b : buildings) {
        if (*b == building) {
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
    if (Attackable::isDead(this->construction_yard)) {
        this->construction_yard = nullptr;
    }
    std::vector<Building*>::iterator it = buildings.begin();
    while (it != buildings.end()) {
        if (Attackable::isDead(*it)) {
            if ((*it)->is(Building::WIND_TRAP)) {
                this->generatedEnergy -= (*it)->energy;
                serialization["generated_energy"] = generatedEnergy;
            } else {
                this->consumedEnergy -= (*it)->energy;
                serialization["consumed_energy"] = consumedEnergy;
            }
            this->gold_limit -= (*it)->getCapacity();
            serialization["gold_limit"] = this->gold_limit;
            news = true;
            it = buildings.erase(it);
        } else {
            it++;
        }
    }
}

std::vector<Unit*>& Player::getTrainedUnits(Map& map) {
    return this->trainingCenter.getReadyUnits(map, buildings, construction_yard);
}

void Player::sellBuilding(Building* building) {
    std::vector<Building*>::iterator it = buildings.begin();
    while (it != buildings.end()) {
        if ((*it) == building) {
            gold += building->cost * float(building->getLife()) / float(building->getInitialLife()) * 0.9;
            serialization["gold"] = gold;
            building->demolish();
            news = true;
            break;
        } else {
            it++;
        }
    }
}

nlohmann::json& Player::getSerialization() {
    news = false;
    serialization["trainingCenter"] = trainingCenter.getSerialization();
    serialization["buildingCenter"] = buildingCenter.getSerialization();
    return serialization;
}

bool Player::hasNews() {
    return ( news || buildingCenter.news || trainingCenter.news);
}
