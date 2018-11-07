#include <algorithm>
#include "Model.h"

Model::Model(int width, int height, int n_player) : map(width, height){
    // reemplazar luego por un vector de players
    for (int i=0; i< n_player; ++i){
        players.emplace(players.end(),i);
    }
}

//Unit &Model::createUnit(int x, int y) {
Unit &Model::createUnit(Unit *unit, int player) {
    unit->setPlayer(players.at(player));
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
	for (auto itr = units.begin(); itr != units.end(); ++itr) {
//        (*itr)->move();
		(*itr)->makeAction(map);
//        (*itr)->automaticAttack(map);
    }
    this->cleanDeadUnits();
}

Unit *Model::selectUnit(int x, int y) {
	Position aux_pos(x, y);
	return map.getClosestUnit(aux_pos, LIMIT_TO_SELECT);
}

Map &Model::getMap() {
	return map;
}

void Model::cleanDeadUnits() {
    map.cleanDeadUnits();
    bool has_dead_unit = false;
    for (auto u : units){
        if (Unit::isDead(u)){
            has_dead_unit = true;
            delete u;
        }
    }
    if (has_dead_unit){
        units.erase(std::remove_if(units.begin(), units.end(), Unit::isDead));
    }
}

Player &Model::getPlayer(int player) {
    return players.at(player);
}

Model::~Model() {
    for (auto unit : units){
        delete unit;
    }
    for (auto building : buildings){
        delete building;
    }
}
