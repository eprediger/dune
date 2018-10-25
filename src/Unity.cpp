#include "Unity.h"
#include "AStar.h"
#include "Summit.h"
#include "AssaultRifle.h"

Unity::Unity() : life(INITIAL_LIFE), Positionable(0,0), weapon(AssaultRifle()){
}

Unity::Unity(int x, int y) : life(INITIAL_LIFE), Positionable(x, y), weapon(AssaultRifle()) {
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

int Unity::getLife() {
    return life;
}

void Unity::attack(Unity &defender) {
    defender.getAttack(*this);
}

void Unity::getAttack(Unity &attacker) {
    life -= attacker.getDammage();
}

int Unity::getDammage() {
    return weapon.getDammage();
}


