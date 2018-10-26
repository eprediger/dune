#include "Unity.h"
#include "AStar.h"
#include "Summit.h"
#include "AssaultRifle.h"
#include "Config.h"

Unity::Unity() : Attackable(INITIAL_LIFE), Positionable(0,0), Attacker(AssaultRifle()){
    id = Config::getNextId();
}

Unity::Unity(int x, int y) : Attackable(INITIAL_LIFE), Positionable(x, y), Attacker(AssaultRifle()) {
    id = Config::getNextId();
}

int Unity::move() {
    if (!pathToDestiny.empty()) {
        pos = pathToDestiny.top();
        pathToDestiny.pop();
        return 1;
    } else {
        return 0;
    }

}

bool Unity::canMoveAboveTerrain(Terrain &terrain) {
    return terrain == Sand() || terrain == Summit();
}

void Unity::setPath(std::stack<Position> path) {
    pathToDestiny = path;
}



//void Unity::attack(Unity &defender) {
//    defender.reciveAttack(*this);
//}

//void Unity::reciveAttack(Unity &attacker) {
//    life -= attacker.getDammage();
//    if (life <= 0) {
//        // this->kill;
//    }
//}
//
//int Unity::getDammage() {
//    return weapon.getDammage();
//}

bool Unity::automaticAttack(Map &map) {
    Unity* closes_unity = map.getClosestUnity(*this, 100);
    if (closes_unity == nullptr){
        return false;
    } else {
        this->attack(*closes_unity);
        return true;
    }
}

bool Unity::operator==(const Unity &other) {
    return this->id == other.id;
}

bool Unity::isDead(Unity* unity) {
    return unity->life <= 0;
}






