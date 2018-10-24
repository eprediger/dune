#include "Unity.h"
#include "AStar.h"
#include "Summit.h"

Unity::Unity() : Positionable(0,0){}

Unity::Unity(int x, int y) : Positionable(x, y) {}

//void Unity::setDestiny(int x_dest, int y_dest) {
//    AStar algorithm(<#initializer#>);
//    this->pathToDestiny = algorithm.makePath(*this, Position(x_dest, y_dest));
//    this->pathToDestiny.pop();
//}

int Unity::move() {
    if (!pathToDestiny.empty()) {
        pos = pathToDestiny.top();
        pathToDestiny.pop();
        return 1;
    } else {
        return 0;
    }

}

bool Unity::canMoveAboveTerrain(Terrain &terrain) {
    return terrain == Sand() || terrain == Summit();
}

void Unity::setPath(std::stack<Position> path) {
    pathToDestiny = path;
}


