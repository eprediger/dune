#include "Unity.h"
#include "AStar.h"
#include "assault-rifle.h"
#include "Config.h"

/*Unity::Unity(const int hitPoints) : Attackable(hitPoints), Positionable(0,0), Attacker(AssaultRifle(), ){
    id = Config::getNextId();
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
    pathToDestiny() {
    // this->id = Config::getNextId();
}

int Unity::move() {
    if (!pathToDestiny.empty()) {
        pos = pathToDestiny.top();
        pathToDestiny.pop();
        return 1;
    } else {
        return 0;
    }

}

/*bool Unity::canMoveAboveTerrain(Terrain &terrain) {
    return terrain == Sand() || terrain == Summit();
}*/

void Unity::setPath(std::stack<Position> path) {
    pathToDestiny = path;
}


bool Unity::automaticAttack(Map &map) {
    Unity* closes_unity = map.getClosestUnity(*this, 100);
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
