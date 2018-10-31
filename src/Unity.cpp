#include "Unity.h"
#include "AStar.h"
#include "assault-rifle.h"
#include "Config.h"

/*Unity::Unity(const int hitPoints) : Attackable(hitPoints), Positionable(0,0), Attacker(AssaultRifle(), ){
    id = Config::getNextId();
    state = STOPPED;

}

Unity::Unity(int x, int y) : Attackable(hitPoints), Positionable(x, y), Attacker(AssaultRifle()) {
    id = Config::getNextId();
}*/

Unity::Unity(const int x, const int y, const int hitPoints, const int range,
             Weapon weapon, const int speed) :
    Positionable(x, y),
    Attackable(hitPoints),
    Attacker(weapon, range),
    id(Config::getNextId()),
    speed(speed),
    actual_speed(0),
    pathToDestiny(),
    prev_foll_unity_pos(),
    next_pos(x, y),
    state(STOPPED){
    // this->id = Config::getNextId();

}

int Unity::move() {

    if (actual_speed++ == speed) {
        if (pos == next_pos && !pathToDestiny.empty()) {
            next_pos = pathToDestiny.top();
            pathToDestiny.pop();
        }

        if (!(pos == next_pos)) {
            pos.x += (next_pos.x < pos.x) ? -1 : ((next_pos.x > pos.x)? +1 : 0);
            pos.y += (next_pos.y < pos.y) ? -1 : ((next_pos.y > pos.y)? +1 : 0);
        } else {
            state = STOPPED;
        }
        actual_speed = 0;
    }
    return 0;
}

int Unity::makeAction(Map& map){
    switch (state) {
        case STOPPED:
            return 0;
        case MOVING:
            this->move();
            return 1;
        case FOLLOWING:
            if (prev_foll_unity_pos.sqrtDistance(pos) < this->range){
                this->attack(*foll_unity);
                if (Unity::isDead(foll_unity)){
                    foll_unity = nullptr;
                    pathToDestiny = std::stack<Position>();
                    state = STOPPED;
                }
            } else if (foll_unity->getPosition() == prev_foll_unity_pos || actual_speed != speed){
                this->move();
            } else {
                this->follow(foll_unity, map);
                this->move();
            }
            return 0;
    }
}

/*bool Unity::canMoveAboveTerrain(Terrain &terrain) {
    return terrain == Sand() || terrain == Summit();
}*/

void Unity::setPath(std::stack<Position> path) {
    pathToDestiny = path;
    if (!path.empty()){
        next_pos = pathToDestiny.top();
        pathToDestiny.pop();
        state = MOVING;
    } else {
        next_pos = pos;
        state = STOPPED;
    }
}


bool Unity::automaticAttack(Map &map) {
    Unity* closes_unity = map.getClosestUnity(*this, this->range);
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






