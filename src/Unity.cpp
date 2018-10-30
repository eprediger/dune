#include "Unity.h"
#include "AStar.h"
#include "Summit.h"
#include "AssaultRifle.h"
#include "Config.h"

Unity::Unity() :
        Attackable(INITIAL_LIFE),
        Positionable(0,0),
        Attacker(AssaultRifle()),
        velocity(UNITY_VEL),
        actual_vel(0){
    id = Config::getNextId();

}

Unity::Unity(int x, int y) :
        Attackable(INITIAL_LIFE),
        Positionable(x, y),
        Attacker(AssaultRifle()),
        velocity(UNITY_VEL),
        actual_vel(0) {
    id = Config::getNextId();
}

int Unity::move() {
    if (!pathToDestiny.empty()) {
        if (actual_vel++ == velocity) {
            pos = pathToDestiny.top();
            pathToDestiny.pop();
            actual_vel = 0;
        }
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


bool Unity::automaticAttack(Map &map) {
    Unity* closes_unity = map.getClosestUnity(*this, ATTACK_RANGE);
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






