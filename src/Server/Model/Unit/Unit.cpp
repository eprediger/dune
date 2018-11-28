#include "Unit.h"
#include "Model/AStar.h"
#include "Model/Weapons/AssaultRifle.h"
#include <iostream>
#include <stack>

int Unit::counter = 0;
Unit::Unit(const int x, const int y, const int hitPoints, const int speed, const int cost) :
    Attackable(hitPoints, x, y),
    id(counter),
    speed(speed),
    cost(cost),
    actual_speed(0),
    pathToDestiny(),
    foll_unit(nullptr),
    destiny(x, y),
    prev_foll_unit_pos(),
    next_pos(x, y),
    state((UnitState*) & Unit::training),
    serialization(),
    news(true) {
    counter += 1;
    serialization["class"] = "Unit";
    serialization["id"] = id;
}

Unit::~Unit() {}

const UnitStateAttacking Unit::attacking;
const UnitStateFollowing Unit::following;
const UnitStateMoving Unit::moving;
const UnitStateStopped Unit::stopped;
const UnitStateDefending Unit::defending;
const UnitStateLoading Unit::loading;
const UnitStateFarming Unit::farming;
const UnitStateBacking Unit::backing;
const UnitStateTraining Unit::training;

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
            moved = true;
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
//        state = (UnitState*)&Unit::moving;
    } else {
        next_pos = pos;
//        state = (UnitState*)&Unit::stopped;
    }
}

//bool Unit::isDead(const Attackable *unit) {
//    if (!unit) {
//        return true;
//    }
//    return unit->getLife() <= 0;
//}

void Unit::follow(Attackable* other, Map& map) {
    foll_unit = other;
    prev_foll_unit_pos = foll_unit->getClosestPosition(pos);
    bool occupied_pos = map.at(prev_foll_unit_pos).isOccupied();
    // Se libera la posicion objetivo para que el algoritmo pueda calcular el camino.
    // Luego se vuelve a ocupar
    if (occupied_pos)
        map.at(prev_foll_unit_pos).free();
    map.setDestiny(*this, foll_unit->getClosestPosition(pos).x, foll_unit->getClosestPosition(pos).y);
    if (occupied_pos)
        map.at(prev_foll_unit_pos).occupy();
    state = (UnitState*)&Unit::following;
}

void Unit::setPlayer(Player &player) {
    this->player = &player;
    this->player->subGold(this->cost);
    serialization["player_id"] = player.getId();
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
//    Unit* foll_unit = map.getClosestUnit(pos, 50 * 50, *player, false);
    Attackable* foll_unit = map.getClosestAttackable(pos, 50 * 50, *player);
    if (foll_unit != nullptr) {
        this->follow(foll_unit, map);
        state = (UnitState*) &Unit::following;
    } else {
        map.setDestiny(*this, pos.x, pos.y);
        state = (UnitState*) &Unit::moving;
    }
}

bool Unit::shotARocket() {
    return false;
}

Rocket* Unit::getRocket() {
    return nullptr;
}
void Unit::checkForDeadVictim() {
    if (foll_unit != nullptr)
        if (Unit::isDead(foll_unit)) {
            this->foll_unit = nullptr;
            this->state = (UnitState*)&Unit::stopped;
        }
}

bool Unit::isTraining() {
    return this->state->isTraining();
}

void Unit::finishTraining() {
    this->state = (UnitState*)&Unit::stopped;
}

nlohmann::json& Unit::getSerialization() {
    news = false;
    serialization["life"] = this->getLife();
    serialization["pos"]["x"] = pos.x;
    serialization["pos"]["y"] = pos.y;
    return serialization;
}

bool Unit::hasNews() {
    return (news || (this->getLife() != serialization["life"]));
}