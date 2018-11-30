#include "Rocket.h"
#include "Position.h"
#include "Model/Map.h"
#include "Weapons.h"
#include <Area.h>
#include <cstdlib>
#include <vector>
#include <Model/Unit/Unit.h>

int Rocket::counter = 0;

Rocket::Rocket(Position source, Position dest) :
    id(counter),
    pos(source),
    dest(dest),
    serialization() {
    counter += 1;
    serialization["class"] = "Rocket";
    serialization["id"] = id;
    serialization["pos"]["x"] = pos.x;
    serialization["pos"]["y"] = pos.y;
    serialization["arrived"] = false;
}

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

nlohmann::json& Rocket::getSerialization() {
    serialization["pos"]["x"] = pos.x;
    serialization["pos"]["y"] = pos.y;
    serialization["arrived"] = this->arrived();
    return serialization;
}

