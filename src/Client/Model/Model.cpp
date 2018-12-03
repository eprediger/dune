#include "Model.h"
#include "Unit/Unit.h"
#include "Model/Map.h"
#include "Unit/Harvester.h"
#include "Model/Buildings/Barracks.h"
#include "Model/Buildings/HeavyFactory.h"
#include "Model/Buildings/ConstructionYard.h"
#include "Model/Buildings/LightFactory.h"
#include "Model/Buildings/SpiceRefinery.h"
#include "Model/Buildings/SpiceSilo.h"
#include "Model/Buildings/WindTrap.h"
#include "Unit/HeavyInfantry.h"
#include "Unit/LightInfantry.h"
#include "Unit/Raider.h"
#include "Unit/Tank.h"
#include "Unit/Trike.h"
#include "PlayerTrainingCenter.h"
#include <algorithm>
#include <vector>
#include <map>

Model::Model(nlohmann::json& file, CommunicationQueue &queue) :
    map(file),
    units(),
    buildings(),
    players(),
    rockets(),
    gameFinished(false),
    winner_player_id(-1),
    queue(queue) {}

Model::~Model() {
    for (auto& unit : units) {
        delete unit.second;
    }
    for (auto& building : buildings) {
        delete building.second;
    }
    for (auto& player : players) {
        delete player.second;
    }
    for (auto& rocket : rockets) {
        delete rocket.second;
    }
}

Unit &Model::createUnit(Unit *unit) {
    units.insert(std::make_pair(unit->id, unit));
    map.put(*unit);
    return *unit;
}

Building &Model::createBuilding(Building *building) {
    buildings.insert(std::make_pair(building->id, building));
    map.put(building);
    return *building;
}

void Model::addPlayer(nlohmann::json& j) {
    players.insert(std::make_pair(j["id"], new Player(j)));
}

void Model::updatePlayer(nlohmann::json& j) {
    players.at(j["id"])->update(j);
}

bool Model::playerExists(int id) {
    return (players.find(id) != players.end());
}

bool Model::unitExists(int id) {
    return (units.find(id) != units.end());
}

bool Model::buildingExists(int id) {
    return (buildings.find(id) != buildings.end());
}

bool Model::rocketExists(int id) {
    return (rockets.find(id) != rockets.end());
}
void Model::step() {
    this->cleanDeadUnits();
    this->cleanDeadBuildings();
    this->cleanRockets();
}

bool Model::isGameFinished() {
    return gameFinished;
}

int Model::getWinnerId(){
    return winner_player_id;
}

std::vector<Unit*> Model::selectUnitsInArea(Area& area, Player& player) {
    return std::move(map.getUnitsInArea(area, player));
}

std::vector<Building*> Model::selectBuildingsInArea(Area& area, Player& player) {
    return std::move(map.getBuildingsInArea(area, player));
}

Map &Model::getMap() {
    return map;
}

void Model::cleanDeadUnits() {
    bool has_dead_unit = false;
    for (auto& u : units) {
        if (u.second->isDead()) {
            has_dead_unit = true;
            map.cleanUnit(u.second);
        }
    }
    if (has_dead_unit) {
        std::map<int, Unit*>::iterator it = units.begin();
        while (it != units.end()) {
            if ((it->second)->isDead()) {
                delete(it->second);
                it = units.erase(it);
            } else {
                it++;
            }
        }
    }
}

void Model::cleanDeadBuildings() {
    bool has_dead_unit = false;
    for (auto& b : buildings) {
        if (b.second->isDead()) {
            has_dead_unit = true;
            map.cleanBuilding(b.second);
        }
    }
    if (has_dead_unit) {
        for (auto& player : players) {
            player.second->cleanDeadBuildings();
        }
        auto it = buildings.begin();
        while (it != buildings.end()) {
            if (it->second->isDead()) {
                delete(it->second);
                it = buildings.erase(it);
            } else {
                it++;
            }
        }
    }
}

void Model::cleanRockets() {
    if (!rockets.empty()) {
        std::map<int, Rocket*>::iterator it = rockets.begin();
        while (it != rockets.end()) {
            if ((it)->second->arrived) {
                delete(it->second);
                it = rockets.erase(it);
            } else {
                it++;
            }
        }
    }
}

Player &Model::getPlayer(int player) {
    return *players.at(player);
}

void Model::updateUnit(nlohmann::json& j) {
    units.at(j["id"])->update(j);
}

void Model::updateBuilding(nlohmann::json& j) {
    buildings.at(j["id"])->update(j);
}

Harvester& Model::createHarvester(nlohmann::json& j) {
    Harvester* harvester = new Harvester(j);
    harvester->setPlayer(players.at(j["player_id"]));
    createUnit(harvester);
    return *harvester;
}

HeavyInfantry& Model::createHeavyInfantry(nlohmann::json& j) {
    HeavyInfantry* heavyInfantry = new HeavyInfantry(j);
    heavyInfantry->setPlayer(players.at(j["player_id"]));
    createUnit(heavyInfantry);
    return *heavyInfantry;
}

LightInfantry& Model::createLightInfantry(nlohmann::json& j) {
    LightInfantry* lightInfantry = new LightInfantry(j);
    lightInfantry->setPlayer(players.at(j["player_id"]));
    createUnit(lightInfantry);
    return *lightInfantry;
}

Raider& Model::createRaider(nlohmann::json& j) {
    Raider* raider = new Raider(j);
    raider->setPlayer(players.at(j["player_id"]));
    createUnit(raider);
    return (*raider);
}

Tank& Model::createTank(nlohmann::json& j) {
    Tank* tank = new Tank(j);
    tank->setPlayer(players.at(j["player_id"]));
    createUnit(tank);
    return *tank;
}

Trike& Model::createTrike(nlohmann::json& j) {
    Trike* trike = new Trike(j);
    trike->setPlayer(players.at(j["player_id"]));
    createUnit(trike);
    return *trike;
}

Barracks& Model::createBarracks(nlohmann::json& j) {
    Barracks* building = new Barracks(j);
    players.at(j["player_id"])->addBuilding(building);
    return (Barracks&)this->createBuilding(std::move(building));
}

ConstructionYard& Model::createConstructionYard(nlohmann::json& j) {
    ConstructionYard* building = new ConstructionYard(j);
    players.at(j["player_id"])->addBuilding(building);
    return (ConstructionYard&)this->createBuilding(std::move(building));
}

HeavyFactory& Model::createHeavyFactory(nlohmann::json& j) {
    HeavyFactory* building = new HeavyFactory(j);
    players.at(j["player_id"])->addBuilding(building);
    return (HeavyFactory&)this->createBuilding(std::move(building));
}

LightFactory& Model::createLightFactory(nlohmann::json& j) {
    LightFactory* building = new LightFactory(j);
    players.at(j["player_id"])->addBuilding(building);
    return (LightFactory&)this->createBuilding(std::move(building));
}

SpiceRefinery& Model::createSpiceRefinery(nlohmann::json& j) {
    SpiceRefinery* building = new SpiceRefinery(j);
    players.at(j["player_id"])->addBuilding(building);
    return (SpiceRefinery&)this->createBuilding(std::move(building));
}

SpiceSilo& Model::createSpiceSilo(nlohmann::json& j) {
    SpiceSilo* building = new SpiceSilo(j);
    players.at(j["player_id"])->addBuilding(building);
    return (SpiceSilo&)this->createBuilding(std::move(building));
}

WindTrap& Model::createWindTrap(nlohmann::json& j) {
    WindTrap* building = new WindTrap(j);
    players.at(j["player_id"])->addBuilding(building);
    return (WindTrap&)this->createBuilding(std::move(building));
}

Rocket& Model::createRocket(nlohmann::json& j) {
    Rocket* rocket = new Rocket(j);
    rockets.insert(std::make_pair(rocket->id, rocket));
    return *rocket;
}

void Model::updateRocket(nlohmann::json& j) {
    rockets.at(j["id"])->update(j);
}

bool Model::canWeBuild(Position& pos, int width, int height, int cost, Player& player) {
    if ( cost > player.gold ) {
        return false;
    }
    return this->map.canWeBuild(pos, width, height, player);
}

int Model::numberOfPlayers() {
    return players.size();
}

void Model::finishGame(int player_id) {
    gameFinished = true;
    winner_player_id = player_id;    
}

