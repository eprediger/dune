#include "Model.h"
#include "Unit/Unit.h"
#include "Map.h"
#include "Unit/Harvester.h"
#include "Buildings/Barracks.h"
#include "Buildings/HeavyFactory.h"
#include "Buildings/ConstructionYard.h"
#include "Buildings/LightFactory.h"
#include "Buildings/SpiceRefinery.h"
#include "Buildings/SpiceSilo.h"
#include "Buildings/WindTrap.h"
#include "Unit/HeavyInfantry.h"
#include "Unit/LightInfantry.h"
#include "Unit/Raider.h"
#include "Unit/Tank.h"
#include "Unit/Trike.h"
#include <AcceptedPlayer.h>
#include "PlayerTrainingCenter.h"
#include <algorithm>
#include <vector>
#include <map>
#include <string>

Model::Model(const char *file) :
    map(file),
    units(),
    buildings(),
    players(),
    rockets(),
    gameFinished(false) {}

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

int Model::addPlayer(const std::string& house, const std::string& playerName) {
    std::vector<Position>& initial_pos = map.getInitialPositions();
    int i = this->players.size();
    ConstructionYard* cYard = new ConstructionYard(initial_pos[i].x, initial_pos[i].y, map.getBlockWidth(), map.getBlockHeight());
    Player* player = new Player(i, *cYard, house, playerName);
    players.insert(std::make_pair(player->getId(), player));
    this->createBuilding(std::move(cYard));
    return i;
}

void Model::step() {
    this->cleanDeadUnits();
    this->cleanDeadBuildings();
    this->cleanRockets();
    for (auto itr = units.begin(); itr != units.end(); ++itr) {
        if (itr->second->shotARocket()) {
            rockets.emplace_back(itr->second->getRocket());
        }
        (itr)->second->makeAction(map);
    }
    for (auto itr = players.begin(); itr != players.end(); itr++) {
        (itr)->second->trainUnits();
        (itr)->second->constructBuildings();
        std::vector<Unit*>& new_units = (itr)->second->getTrainedUnits(map);
        for (auto unit = new_units.begin(); unit != new_units.end(); unit++) {
            createUnit(*unit);
        }
        new_units.clear();
    }

    for (auto itr = rockets.begin(); itr != rockets.end(); itr++) {
        (*itr)->move();
        if ((*itr)->arrived()) {
            (*itr)->explode(map);
        }
    }

    int players_alive = 0;
    for (auto itr = players.begin(); itr != players.end(); ++itr) {
        if ( !(itr)->second->lose() ) {
            players_alive++;
        }
    }
    if (players_alive <= 1) {
        gameFinished = true;
    }
}

bool Model::isGameFinished() {
    return gameFinished;
}

int Model::getWinnerId() {
    if (!gameFinished) {
        return -1;
    }
    for (auto itr = players.begin(); itr != players.end() ; ++itr) {
        if ( !(itr)->second->lose() ) {
            return itr->second->getId();
        }
    }
    return -1;
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
        if (Unit::isDead(u.second)) {
            has_dead_unit = true;
            map.cleanUnit(u.second);
        } else {
            u.second->checkForDeadVictim();
        }
    }
    if (has_dead_unit) {
        std::map<int, Unit*>::iterator it = units.begin();
        while (it != units.end()) {
            if (Unit::isDead((it->second))) {
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
        if (Attackable::isDead(b.second)) {
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
            if (Attackable::isDead((it->second))) {
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
        std::vector<Rocket*>::iterator it = rockets.begin();
        while (it != rockets.end()) {
            if ((*it)->arrived()) {
                delete(*it);
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

Harvester& Model::createHarvester(int x, int y, int player) {
    Harvester* harvester = new Harvester(x, y);
    harvester->setPlayer(*players.at(player));
    players.at(player)->trainingCenter.trainHarvester(harvester);
    return *harvester;
}

HeavyInfantry& Model::createHeavyInfantry(int x, int y, int player) {
    HeavyInfantry* heavyInfantry = new HeavyInfantry(x, y);
    heavyInfantry->setPlayer(*players.at(player));
    players.at(player)->trainingCenter.trainHeavyInfantry(heavyInfantry);
    return *heavyInfantry;
}

LightInfantry& Model::createLightInfantry(int x, int y, int player) {
    LightInfantry* lightInfantry = new LightInfantry(x, y);
    lightInfantry->setPlayer(*players.at(player));
    players.at(player)->trainingCenter.trainLightInfantry(lightInfantry);
    return *lightInfantry;
}

Raider& Model::createRaider(int x, int y, int player) {
    Raider* raider = new Raider(x, y);
    raider->setPlayer(*players.at(player));

    players.at(player)->trainingCenter.trainRaider(raider);
    return (*raider);
}

Tank& Model::createTank(int x, int y, int player) {
    Tank* tank = new Tank(x, y);
    tank->setPlayer(*players.at(player));

    players.at(player)->trainingCenter.trainTank(tank);
    return *tank;
}

Trike& Model::createTrike(int x, int y, int player) {
    Trike* trike = new Trike(x, y);
    trike->setPlayer(*players.at(player));
    players.at(player)->trainingCenter.trainTrike(trike);
    return *trike;
}

// Se deben crear las vistas de cada edificio (o la fabrica de vistas para los edificios)
Barracks& Model::createBarracks(int x, int y, int player) {
    Position pos1(x, y);
    Position pos = map.getCornerPosition(pos1);
    Barracks* building = new Barracks(pos.x, pos.y, map.getBlockWidth(), map.getBlockHeight());
    players.at(player)->addBuilding(building);
    return (Barracks&)this->createBuilding(std::move(building));
}

ConstructionYard& Model::createConstructionYard(int x, int y, int player) {
    Position pos1(x, y);
    Position pos = map.getCornerPosition(pos1);
    ConstructionYard* building = new ConstructionYard(pos.x, pos.y, map.getBlockWidth(), map.getBlockHeight());
    players.at(player)->addBuilding(building);
    return (ConstructionYard&)this->createBuilding(std::move(building));
}

HeavyFactory& Model::createHeavyFactory(int x, int y, int player) {
    Position pos1(x, y);
    Position pos = map.getCornerPosition(pos1);
    HeavyFactory* building = new HeavyFactory(pos.x, pos.y, map.getBlockWidth(), map.getBlockHeight());
    players.at(player)->addBuilding(building);
    return (HeavyFactory&)this->createBuilding(std::move(building));
}

LightFactory& Model::createLightFactory(int x, int y, int player) {
    Position pos1(x, y);
    Position pos = map.getCornerPosition(pos1);
    LightFactory* building = new LightFactory(pos.x, pos.y, map.getBlockWidth(), map.getBlockHeight());
    players.at(player)->addBuilding(building);
    return (LightFactory&)this->createBuilding(std::move(building));
}

SpiceRefinery& Model::createSpiceRefinery(int x, int y, int player) {
    Position pos1(x, y);
    Position pos = map.getCornerPosition(pos1);
    SpiceRefinery* building = new SpiceRefinery(pos.x, pos.y, map.getBlockWidth(), map.getBlockHeight());
    players.at(player)->addBuilding(building);
    return (SpiceRefinery&)this->createBuilding(std::move(building));
}

SpiceSilo& Model::createSpiceSilo(int x, int y, int player) {
    Position pos1(x, y);
    Position pos = map.getCornerPosition(pos1);
    SpiceSilo* building = new SpiceSilo(pos.x, pos.y, map.getBlockWidth(), map.getBlockHeight());
    players.at(player)->addBuilding(building);
    return (SpiceSilo&)this->createBuilding(std::move(building));
}

WindTrap& Model::createWindTrap(int x, int y, int player) {
    Position pos1(x, y);
    Position pos = map.getCornerPosition(pos1);
    WindTrap* building = new WindTrap(pos.x, pos.y, map.getBlockWidth(), map.getBlockHeight());
    players.at(player)->addBuilding(building);
    return (WindTrap&)this->createBuilding(std::move(building));
}

void Model::actionOnPosition(Position &pos, Unit &unit) {
    unit.actionOnPosition(map, pos);
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

/// TEMPORAL
Building & Model::getBuildingById(int id) {
    return *buildings.at(id);
}

Unit& Model::getUnitById(int id) {
    return *units.at(id);
}

void Model::serialize(std::vector<AcceptedPlayer*>& connectedPlayers) {
    bool news = false;
    nlohmann::json step;
    step["class"] = "Step";

    for (auto itr = units.begin(); itr != units.end(); ++itr) {
        if (itr->second->hasNews()) {
            news = true;
            for (auto player : connectedPlayers) {
                player->queue.enqueue((itr)->second->getSerialization());
            }
        }
    }

    if (map.hasNews()) {
        news = true;
        for (auto player : connectedPlayers) {
            player->queue.enqueue(map.getSpiceUpdate());
        }
    }

    for (auto itr = rockets.begin(); itr != rockets.end(); itr++) {
        news = true;
        for (auto player : connectedPlayers) {
            player->queue.enqueue((*itr)->getSerialization());
        }
    }

    for (auto itr = buildings.begin(); itr != buildings.end(); ++itr) {
        if (itr->second->hasNews()) {
            news = true;
            for (auto player : connectedPlayers) {
                player->queue.enqueue((itr->second->getSerialization()));
            }
        }
    }

    for (auto player : connectedPlayers) {
        if (players.at(player->getId())->hasNews()) {
            player->queue.enqueue(players.at(player->getId())->getSerialization());
            if (!news) {
                player->queue.enqueue(step);
            }
        }
    }

    if (news) {
        for (auto player : connectedPlayers) {
            player->queue.enqueue(step);
        }
    }

    if (gameFinished) {
        nlohmann::json finishGameJson;
        finishGameJson["class"] = "finishGame";
        finishGameJson["winner_id"] = this->getWinnerId();
        for (auto player : connectedPlayers) {
            player->queue.enqueue(finishGameJson);
        }
    }
}
