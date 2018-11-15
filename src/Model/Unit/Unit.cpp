#include "Unit.h"
#include "../AStar.h"
#include "../Weapons/AssaultRifle.h"
#include "../Config.h"
#include <iostream>

Unit::Unit(const int x, const int y, const int hitPoints, const int speed, const int cost) :
    Attackable(hitPoints, x, y),
    id(Config::getNextId()),
    speed(speed),
    cost(cost),
    actual_speed(0),
    pathToDestiny(),
    foll_unit(nullptr),
    destiny(x, y),
    prev_foll_unit_pos(),
    next_pos(x, y),
    state((UnitState*) & Unit::stopped) {}

Unit::~Unit() {}

const UnitStateAttacking Unit::attacking;
const UnitStateFollowing Unit::following;
const UnitStateMoving Unit::moving;
const UnitStateStopped Unit::stopped;
const UnitStateDefending Unit::defending;
const UnitStateLoading Unit::loading;
const UnitStateFarming Unit::farming;
const UnitStateBacking Unit::backing;

bool Unit::move(Map &map) {
    bool moved = true;
    if (actual_speed++ == speed) {
        if (pos == next_pos && !pathToDestiny.empty()) {
            next_pos = pathToDestiny.top();
            if ( map.at(next_pos).isOccupied() ) {
                map.setDestiny(*this, destiny.x, destiny.y);
            } else {
                pathToDestiny.pop();
            }
        }

        if (!(pos == next_pos)) {
            pos.x += (next_pos.x < pos.x) ? -1 : ((next_pos.x > pos.x) ? +1 : 0);
            pos.y += (next_pos.y < pos.y) ? -1 : ((next_pos.y > pos.y) ? +1 : 0);
        } else {
            map.at(pos).occupy();
//            state = (UnitState*)&Unit::stopped;;
            moved = false;
        }
        actual_speed = 0;
    }
    return moved;
}

void Unit::setPath(std::stack<Position> path, Position destiny) {
    pathToDestiny = path;
    this->destiny = destiny;
    if (!path.empty()) {
        next_pos = pathToDestiny.top();
        pathToDestiny.pop();
        state = (UnitState*)&Unit::moving;
    } else {
        next_pos = pos;
        state = (UnitState*)&Unit::stopped;
    }
}

bool Unit::operator==(const Unit &other) {
    return this->id == other.id;
}


//bool Unit::isDead(const Attackable *unit) {
//    if (!unit) {
//        return true;
//    }
//    return unit->getLife() <= 0;
//}

void Unit::follow(Attackable* other, Map& map) {
    foll_unit = other;
    prev_foll_unit_pos = foll_unit->getPosition();
    bool occupied_pos = map.at(prev_foll_unit_pos).isOccupied();

    // Se libera la posicion objetivo para que el algoritmo pueda calcular el camino.
    // Luego se vuelve a ocupar
    if (occupied_pos) map.at(prev_foll_unit_pos).free();
    map.setDestiny(*this, foll_unit->getPosition().getX(), foll_unit->getPosition().getY());
    if (occupied_pos) map.at(prev_foll_unit_pos).occupy();
    state = (UnitState*)&Unit::following;
}

void Unit::setPlayer(Player &player) {
    this->player = &player;
    this->player->subGold(this->cost);
}

Player &Unit::getPlayer() {
    return *player;
}

void Unit::makeAction(Map &map) {
    state = state->makeAction(map, *this);
}

bool Unit::isAttacking() {
    return state->isAttacking();
}

UnitState *Unit::makeFollow(Map &map) {
    return state;
}

UnitState *Unit::makeAttack(Map &map) {
    return state;
}

UnitState *Unit::makeStopped(Map &map) {
    return state;
}

UnitState *Unit::makeDefending(Map &map) {
    return state;
}

UnitState *Unit::makeLoading(Map &map) {
    return state;
}

UnitState *Unit::makeFarming(Map &map) {
    return state;
}

UnitState *Unit::makeBacking(Map &map) {
    return state;
}

void Unit::actionOnPosition(Map &map, Position &pos) {
    Unit* foll_unit = map.getClosestUnit(pos, 50 * 50, *player, false);
    if (foll_unit != nullptr) {
        this->follow(foll_unit, map);
    } else {
        map.setDestiny(*this, pos.x, pos.y);
    }
}

void Unit::checkForDeadVictim() {
    if (foll_unit != nullptr)
        if (Unit::isDead(foll_unit))
            this->foll_unit = nullptr;
}
