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
    state = STOPPED;

}

Unity::Unity(int x, int y) :
        Attackable(INITIAL_LIFE),
        Positionable(x, y),
        Attacker(AssaultRifle()),
        velocity(UNITY_VEL),
        actual_vel(0) {
    id = Config::getNextId();
    state = STOPPED;
}

int Unity::move() {
    if (!pathToDestiny.empty()) {
        if (actual_vel++ == velocity) {
            pos = pathToDestiny.top();
            pathToDestiny.pop();
            actual_vel = 0;
        }
    } else {
        state = STOPPED;
        return 0;
    }

}

int Unity::makeAction(Map& map){
    switch (state) {
        case STOPPED:
            return 0;
        case MOVING:
            this->move();
            return 1;
        case FOLLOWING:
            if (prev_foll_unity_pos.sqrtDistance(pos) < ATTACK_RANGE){
                this->attack(*foll_unity);
                if (Unity::isDead(foll_unity)){
                    foll_unity = nullptr;
                    pathToDestiny = std::stack<Position>();
                    state = STOPPED;
                }
            } else if (foll_unity->getPosition() == prev_foll_unity_pos || actual_vel != velocity){
                this->move();
            } else {
                this->follow(foll_unity, map);
                this->move();
            }
            return 0;
    }
}

bool Unity::canMoveAboveTerrain(Terrain &terrain) {
    return terrain == Sand() || terrain == Summit();
}

void Unity::setPath(std::stack<Position> path) {
    pathToDestiny = path;
    state = MOVING;
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

void Unity::follow(Unity* other, Map& map) {
    foll_unity = other;
    prev_foll_unity_pos = foll_unity->getPosition();
    map.setDestiny(*this, foll_unity->getPosition().getX(), foll_unity->getPosition().getY());
    state = FOLLOWING;
}






