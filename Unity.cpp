#include "Unity.h"
#include "AStar.h"
#include "Summit.h"

Unity::Unity() : Positionable(0,0,9){}

void Unity::setDestiny(int x_dest, int y_dest) {
    AStar algorithm;
    this->pathToDestiny = algorithm.makePath(this->pos, Position(x_dest, y_dest), *this);
    this->pathToDestiny.pop();
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

Unity::Unity(int x, int y) : Positionable(x, y, 9) {

}

//bool Unity::canMoveAboveTerrain(Sand &terrain) {
//    return true;
//}
//
//bool Unity::canMoveAboveTerrain(Precipice &terrain) {
//    return false;
//}

bool Unity::canMoveAboveTerrain(Terrain &terrain) {
    return terrain == Sand() || terrain == Summit();
}

void move();
