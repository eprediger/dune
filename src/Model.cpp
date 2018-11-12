#include <algorithm>
#include "Model.h"
#include "View/View.h"
#include "Unit/Harvester.h"
#include "View/UnitViewFactory.h"
#include "Buildings/Barracks.h"
#include "Buildings/HeavyFactory.h"
#include "Buildings/ConstructionYard.h"
#include "Buildings/LightFactory.h"
#include "Buildings/SpiceRefinery.h"
#include "Buildings/SpiceSilo.h"
#include "Buildings/WindTrap.h"
#include "View/BuildingViewFactory.h"
#include "View/Area.h"

Model::Model(int width, int height, int n_player, View &view) : view(view), map(width, height) {
    // reemplazar luego por un vector de players
    for (int i=0; i< n_player; ++i){
        players.emplace(players.end(),i);
    }
}

Model::~Model() {
    for (auto unit : units){
        delete unit;
    }
    for (auto building : buildings){
        delete building;
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
//    for (auto unit : units){
    this->cleanDeadUnits();
	for (auto itr = units.begin(); itr != units.end(); ++itr) {
//        (*itr)->move();
		(*itr)->makeAction(map);
//        (*itr)->automaticAttack(map);
    }
}

Unit *Model::selectUnit(int x, int y) {
	Position aux_pos(x, y);
	return map.getClosestUnit(aux_pos, LIMIT_TO_SELECT);
}


std::vector<Unit*> Model::selectUnitsInArea(Area& area, Player& player){
    return std::move(map.getUnitsInArea(area,player));
} 

Map &Model::getMap() {
	return map;
}

void Model::cleanDeadUnits() {
    bool has_dead_unit = false;
    for (auto u : units){
        if (Unit::isDead(u)){
            has_dead_unit = true;
            map.cleanUnit(u);
        } else {
            u->checkForDeadVictim();
        }
    }
    if (has_dead_unit){
        std::vector<Unit*>::iterator it = units.begin();
        while (it!=units.end()){
            if (Unit::isDead((*it))){
                delete(*it);
                it = units.erase(it);
            }
            else it++;
        }
    }
}

Player &Model::getPlayer(int player) {
    return players.at(player);
}

void Model::createHarvester(int x, int y, int player) {
    Harvester* harvester = new Harvester(x,y);
    harvester->setPlayer(players.at(player)); //Quitar luego y hacer player.add(harvester)
    view.addUnitView(UnitViewFactory::createUnitView(*harvester,view.getWindow()));
    this->createUnit(harvester);
}

void Model::createHeavyInfantry(int x, int y, int player) {
    HeavyInfantry* heavyInfantry = new HeavyInfantry(x,y);
    heavyInfantry->setPlayer(players.at(player)); //Quitar luego y hacer player.add(heavyInfantry)
    view.addUnitView(UnitViewFactory::createUnitView(*heavyInfantry,view.getWindow()));
    this->createUnit(heavyInfantry);
}

void Model::createLightInfantry(int x, int y, int player) {
    LightInfantry* lightInfantry = new LightInfantry(x,y);
    lightInfantry->setPlayer(players.at(player)); //Quitar luego y hacer player.add(lightInfantry)
    view.addUnitView(UnitViewFactory::createUnitView(*lightInfantry,view.getWindow()));
    this->createUnit(lightInfantry);
}

void Model::createRaider(int x, int y, int player) {
    Raider* raider = new Raider(x,y);
    raider->setPlayer(players.at(player)); //Quitar luego y hacer player.add(raider)
    view.addUnitView(UnitViewFactory::createUnitView(*raider,view.getWindow()));
    this->createUnit(raider);
}

void Model::createTank(int x, int y, int player) {
    Tank* tank = new Tank(x,y);
    tank->setPlayer(players.at(player)); //Quitar luego y hacer player.add(tank)
    view.addUnitView(UnitViewFactory::createUnitView(*tank,view.getWindow()));
    this->createUnit(tank);
}

void Model::createTrike(int x, int y, int player) {
    Trike* trike = new Trike(x,y);
    trike->setPlayer(players.at(player)); //Quitar luego y hacer player.add(trike)
    view.addUnitView(UnitViewFactory::createUnitView(*trike,view.getWindow()));
    this->createUnit(trike);
}

// Se deben crear las vistas de cada edificio (o la fabrica de vistas para los edificios)
void Model::createBarracks(int x, int y, int player) {
    Barracks* building = new Barracks(x, y);
    players.at(player).addBuilding(building);
    view.addBuildingView(std::move(BuildingViewFactory::createBuildingView(*building, view.getWindow())));
    this->createBuilding(std::move(building));
}

void Model::createConstructionYard(int x, int y, int player) {
    ConstructionYard* building = new ConstructionYard(x, y);
    players.at(player).addBuilding(building);
    view.addBuildingView(std::move(BuildingViewFactory::createBuildingView(*building, view.getWindow())));
    this->createBuilding(std::move(building));
}

void Model::createHeavyFactory(int x, int y, int player) {
    HeavyFactory* building = new HeavyFactory(x, y);
    players.at(player).addBuilding(building);
    view.addBuildingView(std::move(BuildingViewFactory::createBuildingView(*building, view.getWindow())));
    this->createBuilding(std::move(building));
}

void Model::createLightFactory(int x, int y, int player) {
    LightFactory* building = new LightFactory(x, y);
    players.at(player).addBuilding(building);
    view.addBuildingView(std::move(BuildingViewFactory::createBuildingView(*building, view.getWindow())));
    this->createBuilding(std::move(building));
}

void Model::createSpiceRefinery(int x, int y, int player) {
    SpiceRefinery* building = new SpiceRefinery(x, y);
    players.at(player).addBuilding(building);
    view.addBuildingView(std::move(BuildingViewFactory::createBuildingView(*building, view.getWindow())));
    this->createBuilding(std::move(building));
}

void Model::createSpiceSilo(int x, int y, int player) {
    SpiceSilo* building = new SpiceSilo(x, y);
    players.at(player).addBuilding(building);
    view.addBuildingView(std::move(BuildingViewFactory::createBuildingView(*building, view.getWindow())));
    this->createBuilding(std::move(building));
}

void Model::createWindTrap(int x, int y, int player) {
    WindTrap* building = new WindTrap(x, y);
    players.at(player).addBuilding(building);
    view.addBuildingView(std::move(BuildingViewFactory::createBuildingView(*building, view.getWindow())));
    this->createBuilding(std::move(building));
}


Unit * Model::selectUnit(Position &pos, int player) {
//    map.getClosestUnit(pos, 50*50, players.at(player), true);
    return map.getClosestUnit(pos, 50*50);
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


