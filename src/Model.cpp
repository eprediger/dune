#include "Model.h"

Model::Model(int width, int height) : map(width, height){
}

//Unit &Model::createUnit(int x, int y) {
Unit &Model::createUnit(Unit *unit) {

//    units.push_back(std::unique_ptr<Unit>(Unit(x,y)));
    units.push_back(std::unique_ptr<Unit>(unit));
    map.put(*units.back());
    return *units.back();
}


void Model::step() {
//    for (auto unit : units){
    for (auto itr = units.begin(); itr != units.end(); ++itr){
//        (*itr)->move();
        (*itr)->makeAction(map);
//        (*itr)->automaticAttack(map);
    }
//    map.cleanDeadUnits();
}

Unit *Model::selectUnit(int x, int y) {
    Position aux_pos(x,y);
    return map.getClosestUnit(aux_pos, LIMIT_TO_SELECT);
}

Map &Model::getMap() {
    return map;
}
