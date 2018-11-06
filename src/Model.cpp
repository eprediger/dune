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
//    units.push_back(std::unique_ptr<Unit>(Unit(x,y)));
	units.push_back(std::unique_ptr<Unit>(unit));
	map.put(*units.back());
	return *units.back();
}

Building &Model::createBuilding(Building *building) {
	buildings.push_back(std::unique_ptr<Building>(building));
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
    if (std::find_if(units.begin(), units.end(), Unit::isDeadOnModel) != units.end()){
        units.erase(std::remove_if(units.begin(), units.end(), Unit::isDeadOnModel));
    }
}

Player &Model::getPlayer(int player) {
    return players.at(player);
}
