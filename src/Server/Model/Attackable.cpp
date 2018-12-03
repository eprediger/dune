#include "Attackable.h"
#include "Config.h"
#include <iostream>

Attackable::Attackable(const int life, const int x, const int y) :
    id(Config::getNextId()),
    initial_life(life),
    life(life),
    pos(x, y) {
    this->pos.normalizeToBlock();
}

int Attackable::getLife() {
    return life;
}

int Attackable::getInitialLife() {
    return initial_life;
}

void Attackable::reciveAttack(const Weapon &weapon) {
    life -= weapon.getDammage();
    this->reciveBonusDammage(weapon);
}

Position &Attackable::getPosition() {
    return pos;
}

bool Attackable::isDead(const Attackable *unit) {
    if (!unit) {
        return true;
    }
    return (unit->life <= 0);
}

bool Attackable::operator==(const Attackable &other) {
    return this->id == other.id;
}

void Attackable::setPosition(Position pos) {
    this->pos = pos;
}

Position& Attackable::getClosestPosition(Position& position) {
    return this->pos;
}

int Attackable::getId() {
    return id;
}
