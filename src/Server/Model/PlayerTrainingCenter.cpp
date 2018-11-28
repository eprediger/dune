#include "PlayerTrainingCenter.h"
#include "Model/GlobalConfig.h"

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
    harvester(0, nullptr),
    lightInfantry(0, nullptr),
    heavyInfantry(0, nullptr),
    raider(0, nullptr),
    tank(0, nullptr),
    trike(0, nullptr),
    readyUnits(),
    serialization() {
    serialization["trainingHarvester"] = false;
    serialization["harvesterTime"] = 0;
    serialization["trainingLightInfantry"] = false;
    serialization["lightInfantryTime"] = 0;
    serialization["trainingHeavyInfantry"] = false;
    serialization["heavyInfantryTime"] = 0;
    serialization["trainingRaider"] = false;
    serialization["raiderTime"] = 0;
    serialization["trainingTank"] = false;
    serialization["tankTime"] = 0;
    serialization["trainingTrike"] = false;
    serialization["trikeTime"] = 0;
}

void PlayerTrainingCenter::trainHarvester(Harvester* harvester) {
    this->harvester.first = GlobalConfig.harvesterConstructionTime;
    this->harvester.second = harvester;

    serialization["trainingHarvester"] = true;
    serialization["harvesterTime"] = this->harvester.first;
}

void PlayerTrainingCenter::trainHeavyInfantry(HeavyInfantry* heavyInfantry) {
    this->heavyInfantry.first = GlobalConfig.heavyInfantryTrainingTime;
    this->heavyInfantry.second = heavyInfantry;
    serialization["trainingHeavyInfantry"] = true;
    serialization["heavyInfantryTime"] = this->heavyInfantry.first;
}

void PlayerTrainingCenter::trainLightInfantry(LightInfantry* lightInfantry) {
    this->lightInfantry.first = GlobalConfig.lightInfantryTrainingTime;
    this->lightInfantry.second = lightInfantry;
    serialization["trainingLightInfantry"] = true;
    serialization["lightInfantryTime"] = this->lightInfantry.first;
}

void PlayerTrainingCenter::trainRaider(Raider* raider) {
    this->raider.first = GlobalConfig.raiderConstructionTime;
    this->raider.second = raider;
    serialization["trainingRaider"] = true;
    serialization["raiderTime"] = this->raider.first;
}

void PlayerTrainingCenter::trainTank(Tank* tank) {
    this->tank.first = GlobalConfig.tankConstructionTime;
    this->tank.second = tank;
    serialization["trainingTank"] = true;
    serialization["tankTime"] = this->tank.first;
}

void PlayerTrainingCenter::trainTrike(Trike* trike) {
    this->trike.first = GlobalConfig.trikeConstructionTime;
    this->trike.second = trike;
    serialization["trainingTrike"] = true;
    serialization["trikeTime"] = this->trike.first;
}

void PlayerTrainingCenter::trainUnits(std::vector<Building*>& buildings) {
    std::vector<Building*>::iterator it = buildings.begin();
    while (it != buildings.end()) {
        if ((*it)->is(Building::BARRACKS)) {
            if (lightInfantry.second != nullptr) {
                lightInfantry.first -= 1;
                serialization["lightInfantryTime"] = lightInfantry.first;
            }
            if (heavyInfantry.second != nullptr) {
                heavyInfantry.first -= 1;
                serialization["heavyInfantryTime"] = heavyInfantry.first;
            }
        } else if ((*it)->is(Building::LIGHT_FACTORY)) {
            if (trike.second != nullptr)
                trike.first -= 1;
            serialization["trikeTime"] = trike.first;
            if (raider.second != nullptr)
                raider.first -= 1;
            serialization["raiderTime"] = raider.first;
        } else if ((*it)->is(Building::HEAVY_FACTORY)) {
            if (tank.second != nullptr) {
                tank.first -= 1;
                serialization["tankTime"] = tank.first;
            }
            if (harvester.second != nullptr) {
                harvester.first -= 1;
                serialization["harvesterTime"] = harvester.first;
            }
        }
        it++;
    }
}

nlohmann::json& PlayerTrainingCenter::getSerialization() {
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
        serialization["trainingLightInfantry"] = false;
    }

    if (heavyInfantry.second != nullptr && heavyInfantry.first <= 0) {
        setInitialPosition(heavyInfantry.second, map, buildings, constructionYard, Building::BARRACKS);
        readyUnits.emplace_back(heavyInfantry.second);
        heavyInfantry.second = nullptr;
        serialization["trainingHeavyInfantry"] = false;
    }

    if (harvester.second != nullptr && harvester.first <= 0) {
        setInitialPosition(harvester.second, map, buildings, constructionYard, Building::HEAVY_FACTORY);
        readyUnits.emplace_back(harvester.second);
        harvester.second = nullptr;
        serialization["trainingHarvester"] = false;
    }

    if (tank.second != nullptr && tank.first <= 0) {
        setInitialPosition(tank.second, map, buildings, constructionYard, Building::HEAVY_FACTORY);
        readyUnits.emplace_back(tank.second);
        tank.second = nullptr;
        serialization["trainingTank"] = false;
    }

    if (raider.second != nullptr && raider.first <= 0) {
        setInitialPosition(raider.second, map, buildings, constructionYard, Building::LIGHT_FACTORY);
        readyUnits.emplace_back(raider.second);
        raider.second = nullptr;
        serialization["trainingRaider"] = false;
    }

    if (trike.second != nullptr && trike.first <= 0) {
        setInitialPosition(trike.second, map, buildings, constructionYard, Building::LIGHT_FACTORY);
        readyUnits.emplace_back(trike.second);
        trike.second = nullptr;
        serialization["trainingTrike"] = false;
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
