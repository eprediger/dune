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
#include <algorithm>
#include <vector>
#include "PlayerTrainingCenter.h"

Model::Model(const char* file, int n_player) :
    map(file),
    units(),
    buildings(),
    players(),
    rockets(),
    gameFinished(false) {
    std::vector<Position>& initial_pos = map.getInitialPositions();
    for (int i = 0; i < n_player; ++i) {
        ConstructionYard* new_building = new ConstructionYard(initial_pos[i].x, initial_pos[i].y,
                map.getBlockWidth(), map.getBlockHeight());
        players.push_back(new Player(i, *new_building));
        this->createBuilding(std::move(new_building));
    }
}

Model::~Model() {
    for (auto& unit : units) {
        delete unit;
    }
    for (auto& building : buildings) {
        delete building;
    }
    for (auto& player : players) {
        delete player;
    }
}

//Unit &Model::createUnit(int x, int y) {
Unit &Model::createUnit(Unit *unit) {
    units.push_back(std::move(unit));
    map.put(*units.back());
    return *units.back();
}

Building &Model::createBuilding(Building *building) {
    buildings.push_back(std::move(building));
    map.put(*buildings.back());
    return *buildings.back();
}

void Model::step() {
    this->cleanDeadUnits();
    this->cleanDeadBuildings();
    this->cleanRockets();
    for (auto itr = units.begin(); itr != units.end(); ++itr) {
        if ((*itr)->shotARocket()) {
            rockets.emplace_back((*itr)->getRocket());
        }
        (*itr)->makeAction(map);
    }
    for (auto itr = players.begin(); itr != players.end(); itr++) {
        (*itr)->trainUnits();
        (*itr)->constructBuildings();
        std::vector<Unit*>& new_units = (*itr)->getTrainedUnits(map);
        for (auto unit = new_units.begin(); unit != new_units.end(); unit++) {
            units.push_back(*unit);
//            (*unit)->setPlayer(**itr);
            map.put(**unit);
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
        if ( !(*itr)->lose() ) {
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

Player *Model::getWinner() {
    if (!gameFinished) {
        return nullptr;
    }
    for (auto itr = players.begin(); itr != players.end() ; ++itr) {
        if ( !(*itr)->lose() ) {
            return *itr;
        }
    }
    return nullptr;
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
        if (Unit::isDead(u)) {
            has_dead_unit = true;
            map.cleanUnit(u);
        } else {
            u->checkForDeadVictim();
        }
    }
    if (has_dead_unit) {
        std::vector<Unit*>::iterator it = units.begin();
        while (it != units.end()) {
            if (Unit::isDead((*it))) {
                delete(*it);
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
        if (Attackable::isDead(b)) {
            has_dead_unit = true;
            map.cleanBuilding(b);
        }
    }
    if (has_dead_unit) {
        for (auto& player : players) {
            player->cleanDeadBuildings();
        }
        auto it = buildings.begin();
        while (it != buildings.end()) {
            if (Attackable::isDead((*it))) {
                delete(*it);
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
    players.at(player)->trainingCenter->trainHarvester(harvester);
    return *harvester;
}

HeavyInfantry& Model::createHeavyInfantry(int x, int y, int player) {
    HeavyInfantry* heavyInfantry = new HeavyInfantry(x, y);
    heavyInfantry->setPlayer(*players.at(player));
    players.at(player)->trainingCenter->trainHeavyInfantry(heavyInfantry);
    return *heavyInfantry;
}

LightInfantry& Model::createLightInfantry(int x, int y, int player) {
    LightInfantry* lightInfantry = new LightInfantry(x, y);
    lightInfantry->setPlayer(*players.at(player));
    players.at(player)->trainingCenter->trainLightInfantry(lightInfantry);
    return *lightInfantry;
}

Raider& Model::createRaider(int x, int y, int player) {
    Raider* raider = new Raider(x, y);
    raider->setPlayer(*players.at(player));

    players.at(player)->trainingCenter->trainRaider(raider);
    return (*raider);
}

Tank& Model::createTank(int x, int y, int player) {
    Tank* tank = new Tank(x, y);
    tank->setPlayer(*players.at(player));

    players.at(player)->trainingCenter->trainTank(tank);
    return *tank;
}

Trike& Model::createTrike(int x, int y, int player) {
    Trike* trike = new Trike(x, y);
    trike->setPlayer(*players.at(player));
    players.at(player)->trainingCenter->trainTrike(trike);
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
//    Unit* foll_unit = map.getClosestUnit(pos, 50*50, unit.getPlayer(), false);
//    if (foll_unit != nullptr){
//        unit.follow(foll_unit, map);
//    } else {
//        map.setDestiny(unit, pos.x, pos.y);
//    }

    // Hacer lo mismo con los edificios
}

bool Model::canWeBuild(Position& pos, int width, int height, int cost, Player& player) {
    if ( cost > player.gold ) {
        return false;
    }
    return this->map.canWeBuild(pos, width, height);
}

int Model::numberOfPlayers() {
    return players.size();
}


/// TEMPORAL
Building & Model::getBuildingById(int id) {
    for (auto& building : buildings){
        if(building->getId() == id ){
            return *building;
        }
    }
}
