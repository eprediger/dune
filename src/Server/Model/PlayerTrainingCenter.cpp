#include "PlayerTrainingCenter.h"
#include <Model/GameConfiguration.h>

#include "Unit/HeavyInfantry.h"
#include "Unit/LightInfantry.h"
#include "Unit/Raider.h"
#include "Unit/Trike.h"
#include "Unit/Tank.h"
#include "Unit/Harvester.h"
#include "Unit/Unit.h"
#include "Model/Buildings/Building.h"
#include <vector>

PlayerTrainingCenter::PlayerTrainingCenter():
    news(true),
    harvester(0, nullptr),
    lightInfantry(0, nullptr),
    heavyInfantry(0, nullptr),
    raider(0, nullptr),
    tank(0, nullptr),
    trike(0, nullptr),
    readyUnits(),
    serialization() {
    serialization["units"].push_back(Unit::LIGHT_INFANTRY);
    serialization["time"].push_back(0);
    serialization["units"].push_back(Unit::HEAVY_INFANTRY);
    serialization["time"].push_back(0);
    serialization["units"].push_back(Unit::HARVESTER);
    serialization["time"].push_back(0);
    serialization["units"].push_back(Unit::TRIKE);
    serialization["time"].push_back(0);
    serialization["units"].push_back(Unit::TANK);
    serialization["time"].push_back(0);
    serialization["units"].push_back(Unit::RAIDER);
    serialization["time"].push_back(0);
}

void PlayerTrainingCenter::trainHarvester(Harvester* harvester) {
    int training_time = (int)(GameConfiguration::getConfig().harvesterConstructionTime
                              * harvester->getPlayer().getEnergyFactor());
    this->harvester.first = training_time;
    this->harvester.second = harvester;

    serialization["units"].push_back(Unit::HARVESTER);
    serialization["time"].push_back(this->harvester.first);
    news = true;
}

void PlayerTrainingCenter::trainHeavyInfantry(HeavyInfantry* heavyInfantry) {
    int training_time = (int)(GameConfiguration::getConfig().heavyInfantryTrainingTime
                              * heavyInfantry->getPlayer().getEnergyFactor());
    this->heavyInfantry.first = training_time;
    this->heavyInfantry.second = heavyInfantry;
    serialization["units"].push_back(Unit::HEAVY_INFANTRY);
    serialization["time"].push_back(this->heavyInfantry.first);
    news = true;
}

void PlayerTrainingCenter::trainLightInfantry(LightInfantry* lightInfantry) {
    int training_time = (int)(GameConfiguration::getConfig().lightInfantryTrainingTime
                              * lightInfantry->getPlayer().getEnergyFactor());
    this->lightInfantry.first = training_time;
    this->lightInfantry.second = lightInfantry;
    serialization["units"].push_back(Unit::LIGHT_INFANTRY);
    serialization["time"].push_back(this->lightInfantry.first);
    news = true;
}

void PlayerTrainingCenter::trainRaider(Raider* raider) {
    int training_time = (int)(GameConfiguration::getConfig().raiderConstructionTime
                              * raider->getPlayer().getEnergyFactor());
    this->raider.first = training_time;
    this->raider.second = raider;
    serialization["units"].push_back(Unit::RAIDER);
    serialization["time"].push_back(this->raider.first);
    news = true;
}

void PlayerTrainingCenter::trainTank(Tank* tank) {
    int training_time = (int)(GameConfiguration::getConfig().tankConstructionTime
                              * tank->getPlayer().getEnergyFactor());
    this->tank.first = training_time;
    this->tank.second = tank;
    serialization["units"].push_back(Unit::TANK);
    serialization["time"].push_back(this->tank.first);
    news = true;
}

void PlayerTrainingCenter::trainTrike(Trike* trike) {
    int training_time = (int)(GameConfiguration::getConfig().trikeConstructionTime
                              * trike->getPlayer().getEnergyFactor());
    this->trike.first = training_time;
    this->trike.second = trike;
    serialization["units"].push_back(Unit::TRIKE);
    serialization["time"].push_back(this->trike.first);
    news = true;
}

void PlayerTrainingCenter::trainUnits(std::vector<Building*>& buildings) {
    std::vector<Building*>::iterator it = buildings.begin();
    if (!news) {
        serialization["units"].clear();
        serialization["time"].clear();
    }
    while (it != buildings.end()) {
        if ((*it)->is(Building::BARRACKS)) {
            if (lightInfantry.second != nullptr) {
                lightInfantry.first -= 1;
                serialization["units"].push_back(Unit::LIGHT_INFANTRY);
                serialization["time"].push_back(this->lightInfantry.first);
                news = true;
            }
            if (heavyInfantry.second != nullptr) {
                heavyInfantry.first -= 1;
                serialization["units"].push_back(Unit::HEAVY_INFANTRY);
                serialization["time"].push_back(this->heavyInfantry.first);
                news = true;
            }
        } else if ((*it)->is(Building::LIGHT_FACTORY)) {
            if (trike.second != nullptr) {
                trike.first -= 1;
                serialization["units"].push_back(Unit::TRIKE);
                serialization["time"].push_back(this->trike.first);
                news = true;
            }
            if (raider.second != nullptr) {
                raider.first -= 1;
                serialization["units"].push_back(Unit::RAIDER);
                serialization["time"].push_back(this->raider.first);
                news = true;
            }
        } else if ((*it)->is(Building::HEAVY_FACTORY)) {
            if (tank.second != nullptr) {
                tank.first -= 1;
                serialization["units"].push_back(Unit::TANK);
                serialization["time"].push_back(this->tank.first);
                news = true;
            }
            if (harvester.second != nullptr) {
                harvester.first -= 1;
                serialization["units"].push_back(Unit::HARVESTER);
                serialization["time"].push_back(this->harvester.first);
                news = true;
            }
        }
        it++;
    }
}

nlohmann::json& PlayerTrainingCenter::getSerialization() {
    news = false;
    return this->serialization;
}

void setInitialPosition(Unit* unit, Map& map, std::vector<Building*>& buildings,
                        ConstructionYard* constructionYard, Building::BuildingType building_type) {
    std::vector<Building*>::iterator it = buildings.begin();
    while (it != buildings.end()) {
        if ((*it)->is(building_type)) {
            unit->setPosition(map.getClosestFreePosition(*it));
            it = buildings.begin();
            break;
        }
        it++;
    }
    if (it == buildings.end()) {
        unit->setPosition(map.getClosestFreePosition(constructionYard));
    }
    unit->finishTraining();
    map.at(unit->getPosition()).occupy();
}

std::vector<Unit*>& PlayerTrainingCenter::getReadyUnits(Map& map, std::vector<Building*>& buildings, ConstructionYard* constructionYard) {
    if (lightInfantry.second != nullptr && lightInfantry.first <= 0) {
        setInitialPosition(lightInfantry.second, map, buildings, constructionYard, Building::BARRACKS);
        readyUnits.emplace_back(lightInfantry.second);
        lightInfantry.second = nullptr;
    }

    if (heavyInfantry.second != nullptr && heavyInfantry.first <= 0) {
        setInitialPosition(heavyInfantry.second, map, buildings, constructionYard, Building::BARRACKS);
        readyUnits.emplace_back(heavyInfantry.second);
        heavyInfantry.second = nullptr;
    }

    if (harvester.second != nullptr && harvester.first <= 0) {
        setInitialPosition(harvester.second, map, buildings, constructionYard, Building::HEAVY_FACTORY);
        readyUnits.emplace_back(harvester.second);
        harvester.second = nullptr;
    }

    if (tank.second != nullptr && tank.first <= 0) {
        setInitialPosition(tank.second, map, buildings, constructionYard, Building::HEAVY_FACTORY);
        readyUnits.emplace_back(tank.second);
        tank.second = nullptr;
    }

    if (raider.second != nullptr && raider.first <= 0) {
        setInitialPosition(raider.second, map, buildings, constructionYard, Building::LIGHT_FACTORY);
        readyUnits.emplace_back(raider.second);
        raider.second = nullptr;
    }

    if (trike.second != nullptr && trike.first <= 0) {
        setInitialPosition(trike.second, map, buildings, constructionYard, Building::LIGHT_FACTORY);
        readyUnits.emplace_back(trike.second);
        trike.second = nullptr;
    }
    return readyUnits;
}

bool PlayerTrainingCenter::isTrainingLightInfantry() {
    return ((lightInfantry.first > 0) && (lightInfantry.second != nullptr));
}

bool PlayerTrainingCenter::isTrainingHeavyInfantry() {
    return ((heavyInfantry.first > 0) && (heavyInfantry.second != nullptr));
}

bool PlayerTrainingCenter::isTrainingHarvester() {
    return ((harvester.first > 0) && (harvester.second != nullptr));
}

bool PlayerTrainingCenter::isTrainingTank() {
    return ((tank.first > 0) && (tank.second != nullptr));
}

bool PlayerTrainingCenter::isTrainingRaider() {
    return ((raider.first > 0) && (raider.second != nullptr));
}

bool PlayerTrainingCenter::isTrainingTrike() {
    return ((trike.first > 0) && (trike.second != nullptr));
}
