#include "Rocket.h"
#include "../../Position.h"
#include "../Map.h"
#include "../../View/Area.h"
#include "Weapons.h"
#include <cstdlib>
#include <vector>

Rocket::Rocket(Position source, Position dest) :
    pos(source),
    dest(dest) {}

void Rocket::move() {
    if (pos.x != dest.x)
        pos.x += 3 * float(dest.x - pos.x) / (abs(dest.x - pos.x) + abs(dest.y - pos.y));
    if (pos.y != dest.y)
        pos.y += 3 * float(dest.y - pos.y) / (abs(dest.x - pos.x) + abs(dest.y - pos.y));
}

bool Rocket::arrived() {
    if (abs(pos.x - dest.x) <= 3 && abs(pos.y - dest.y) <= 3) {
        return true;
    }
    return (false);
}

void Rocket::explode(Map& map) {
    Area area(pos.getX() - 4, pos.getY() - 4, 8, 8);
    std::vector<Unit*> damagedUnits = map.getUnitsInArea(area);
    std::vector<Building*>damagedBuildings = map.getBuildingsInArea(area);
    for (auto itr = damagedUnits.begin(); itr != damagedUnits.end(); itr++) {
        (*itr)->reciveAttack(Weapons::rocketLauncher);
    }
    for (auto itr = damagedBuildings.begin() ; itr != damagedBuildings.end(); itr++) {
        (*itr)->reciveAttack(Weapons::rocketLauncher);
    }
}

Position& Rocket::getPosition() {
    return pos;
}
