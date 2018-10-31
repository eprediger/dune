#include "Model.h"
#include "light-infantry.h"

Model::Model(int width, int height) : map(width, height){
}

Unity &Model::createUnity(int x, int y) {
    unitys.push_back(std::unique_ptr<Unity>(new LightInfantry(x,y)));
    map.put(*unitys.back());
    return *unitys.back();
}

void Model::step() {
//    for (auto unit : unitys){
    for (auto itr = unitys.begin(); itr != unitys.end(); ++itr){
//        (*itr)->move();
        (*itr)->makeAction(map);
//        (*itr)->automaticAttack(map);
    }
//    map.cleanDeadUnitys();
}

Unity *Model::selectUnity(int x, int y) {
    Position aux_pos(x,y);
    return map.getClosestUnity(aux_pos, LIMIT_TO_SELECT);
}

Map &Model::getMap() {
    return map;
}
