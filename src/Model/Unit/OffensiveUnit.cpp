#include "OffensiveUnit.h"
#include "../Weapons/Weapon.h"


OffensiveUnit::OffensiveUnit(const int x, const int y, const int hitPoints, const int range, const Weapon &weapon,
                             const int speed, const int cost) :
        Unit(x, y, hitPoints, speed, cost),
        Attacker(weapon, range)
//        ,attacking(false)
        {}


UnitState * OffensiveUnit::makeFollow(Map &map) {
    UnitState* new_state = state;
    if (Unit::isDead(foll_unit)){
        foll_unit = nullptr;
        pathToDestiny = std::stack<Position>();
        new_state = (UnitState*)&Unit::stopped;
    } else if (foll_unit->getPosition().sqrtDistance(pos) < this->range){
        victim_pos = prev_foll_unit_pos;
        new_state = (UnitState*)&Unit::attacking;
        this->attack(*foll_unit);
        this->victim_pos = (*foll_unit).getPosition();
    } else if (foll_unit->getPosition() == prev_foll_unit_pos || actual_speed != speed){
        this->move(map);
    } else {
        this->follow(foll_unit, map);
        this->move(map);
    }
    return new_state;
}

UnitState *OffensiveUnit::makeAttack(Map &map) {
    UnitState* new_state = state;
    if (Unit::isDead(foll_unit)){
        foll_unit = nullptr;
        pathToDestiny = std::stack<Position>();
        new_state = (UnitState*)&Unit::stopped;
    } else if (foll_unit->getPosition().sqrtDistance(pos) < this->range){
        this->attack(*foll_unit);
        this->victim_pos = (*foll_unit).getPosition();
    } else {
        new_state = (UnitState*)&Unit::following;
    }
    return new_state;
}

UnitState *OffensiveUnit::makeStopped(Map &map) {
    if (this->automaticAttack(map)){
        return (UnitState * )&Unit::defending;
    } else {
        return state;
    }
}

UnitState *OffensiveUnit::makeDefending(Map &map) {
    UnitState* new_state = state;
    if (Unit::isDead(foll_unit) || foll_unit->getPosition().sqrtDistance(pos) >= this->range){
        foll_unit = nullptr;
        new_state = (UnitState*)&Unit::stopped;
    } else {
        this->attack(*foll_unit);
        victim_pos = (*foll_unit).getPosition();
    }
    return new_state;
}


bool OffensiveUnit::automaticAttack(Map &map) {
    Unit* closest_unit = map.getClosestUnit(this->pos, this->range, *this->player, false);
    if (closest_unit == nullptr){
        return false;
    } else {
        foll_unit = closest_unit;
        prev_foll_unit_pos = closest_unit->getPosition();
        victim_pos = closest_unit->getPosition();
        this->attack(*closest_unit);
        return true;
    }
}

Position& OffensiveUnit::getVictimPosition(){
    return this->victim_pos;
//    return this->next_pos;
}




//void OffensiveUnit::follow(Unit* other, Map& map) {
//    foll_unit = other;
//    prev_foll_unit_pos = foll_unit->getPosition();
//    map.setDestiny(*this, foll_unit->getPosition().getX(), foll_unit->getPosition().getY());
//    state = FOLLOWING;
//}
