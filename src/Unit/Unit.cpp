#include "Unit.h"
#include "../AStar.h"
#include "../Weapons/assault-rifle.h"
#include "../Config.h"

/*Unit::Unit(const int hitPoints) : Attackable(hitPoints), Positionable(0,0), Attacker(AssaultRifle(), ){
    id = Config::getNextId();
    state = STOPPED;

}

Unit::Unit(int x, int y) : Attackable(hitPoints), Positionable(x, y), Attacker(AssaultRifle()) {
    id = Config::getNextId();
}*/

Unit::Unit(const int x, const int y, const int hitPoints, const int speed) :
    Positionable(x, y),
    Attackable(hitPoints),
//    Attacker(weapon, range),
    id(Config::getNextId()),
    speed(speed),
    actual_speed(0),
    pathToDestiny(),
    prev_foll_unit_pos(),
    next_pos(x, y),
    state(STOPPED)
    {
    // this->id = Config::getNextId();

}

int Unit::move() {

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

//int Unit::makeAction(Map& map){
//    switch (state) {
//        case STOPPED:
//            return 0;
//        case MOVING:
//            this->move();
//            return 1;
//        case FOLLOWING:
//            if (prev_foll_unit_pos.sqrtDistance(pos) < this->range){
//                this->attack(*foll_unit);
//                if (Unit::isDead(foll_unit)){
//                    foll_unit = nullptr;
//                    pathToDestiny = std::stack<Position>();
//                    state = STOPPED;
//                }
//            } else if (foll_unit->getPosition() == prev_foll_unit_pos || actual_speed != speed){
//                this->move();
//            } else {
//                this->follow(foll_unit, map);
//                this->move();
//            }
//            return 0;
//    }
//}

/*bool Unit::canMoveAboveTerrain(Terrain &terrain) {
    return terrain == Sand() || terrain == Summit();
}*/

void Unit::setPath(std::stack<Position> path) {
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


//bool Unit::automaticAttack(Map &map) {
//    Unit* closes_unit = map.getClosestUnit(*this, this->range);
//    if (closes_unit == nullptr){
//        return false;
//    } else {
//        this->attack(*closes_unit);
//        return true;
//    }
//}

bool Unit::operator==(const Unit &other) {
    return this->id == other.id;
}

bool Unit::isDead(Unit* unit) {
    return unit->life <= 0;
}

void Unit::follow(Unit* other, Map& map) {
    foll_unit = other;
    prev_foll_unit_pos = foll_unit->getPosition();
    map.setDestiny(*this, foll_unit->getPosition().getX(), foll_unit->getPosition().getY());
    state = FOLLOWING;
}






