#include "OffensiveUnit.h"
#include "../Weapons/Weapon.h"


OffensiveUnit::OffensiveUnit(const int x, const int y, const int hitPoints, const int range,
                             const Weapon &weapon, const int speed) :
        Unit(x, y, hitPoints, speed),
        Attacker(weapon, range)
//        ,attacking(false)
        {}


UnitState * OffensiveUnit::makeFollow(Map &map) {
    UnitState* new_state = state;
    if (Unit::isDead(foll_unit)){
        foll_unit = nullptr;
        pathToDestiny = std::stack<Position>();
        new_state = (UnitState*)&Unit::stopped;
    } else if (prev_foll_unit_pos.sqrtDistance(pos) < this->range){
//        if (!attacking){
//            attacking = true;
//            victim_pos = prev_foll_unit_pos;
//        }
        new_state = (UnitState*)&Unit::attacking;
        this->attack(*foll_unit);

    } else if (foll_unit->getPosition() == prev_foll_unit_pos || actual_speed != speed){
        this->move(map);
    } else {
        this->follow(foll_unit, map);
        this->move(map);
    }
    return new_state;
}



bool OffensiveUnit::automaticAttack(Map &map) {
    Unit* closest_unit = map.getClosestUnit(*this, this->range);
    if (closest_unit == nullptr){
        return false;
    } else {
//        if (!attacking){
//            attacking = true;
//            victim_pos = closest_unit->getPosition();
//        }
        this->attack(*closest_unit);
        return true;
    }
}

Position& OffensiveUnit::getVictimPosition(){
//    return this->victim_pos;
    return this->next_pos;
}

UnitState *OffensiveUnit::makeAttack(Map &map) {
    UnitState* new_state = state;
    if (Unit::isDead(foll_unit)){
        foll_unit = nullptr;
        pathToDestiny = std::stack<Position>();
        new_state = (UnitState*)&Unit::stopped;
    } else if (prev_foll_unit_pos.sqrtDistance(pos) < this->range){
        this->attack(*foll_unit);
    } else {
        new_state = (UnitState*)&Unit::following;
    }
    return new_state;
}

//void OffensiveUnit::follow(Unit* other, Map& map) {
//    foll_unit = other;
//    prev_foll_unit_pos = foll_unit->getPosition();
//    map.setDestiny(*this, foll_unit->getPosition().getX(), foll_unit->getPosition().getY());
//    state = FOLLOWING;
//}
