#include "OffensiveUnit.h"
#include "../Weapons/Weapon.h"


OffensiveUnit::OffensiveUnit(const int x, const int y, const int hitPoints, const int range,
           Weapon weapon, const int speed) :
        Unit(x, y, hitPoints, speed),
        Attacker(weapon, range),
        attacking(false) {}

int OffensiveUnit::makeAction(Map& map){
    switch (state) {
        case STOPPED:
            return 0;
        case MOVING:
            this->move();
            return 1;
        case FOLLOWING:
            if (prev_foll_unit_pos.sqrtDistance(pos) < this->range){
                if (!attacking){
                    attacking = true;
                    victim_pos = prev_foll_unit_pos;
                }
                this->attack(*foll_unit);
                if (Unit::isDead(foll_unit)){
                    foll_unit = nullptr;
                    pathToDestiny = std::stack<Position>();
                    state = STOPPED;
                }
            } else if (foll_unit->getPosition() == prev_foll_unit_pos || actual_speed != speed){
                this->move();
            } else {
                this->follow(foll_unit, map);
                this->move();
            }
            return 0;
    }
}


bool OffensiveUnit::automaticAttack(Map &map) {
    Unit* closest_unit = map.getClosestUnit(*this, this->range);
    if (closest_unit == nullptr){
        return false;
    } else {
        if (!attacking){
            attacking = true;
            victim_pos = closest_unit->getPosition();
        }
        this->attack(*closest_unit);
        return true;
    }
}

Position& OffensiveUnit::getVictimPosition(){
    return this->victim_pos;
}

//void OffensiveUnit::follow(Unit* other, Map& map) {
//    foll_unit = other;
//    prev_foll_unit_pos = foll_unit->getPosition();
//    map.setDestiny(*this, foll_unit->getPosition().getX(), foll_unit->getPosition().getY());
//    state = FOLLOWING;
//}
