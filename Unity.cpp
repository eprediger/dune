#include "Unity.h"
#include "AStar.h"

Unity::Unity() : Positionable(0,0,9){}

void Unity::setDestiny(int x_dest, int y_dest) {
    AStar algorithm;
    this->pathToDestiny = algorithm.makePath(this->pos, Position(x_dest, y_dest));
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

void move();
