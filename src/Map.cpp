#include "Map.h"

#include "Precipice.h"
#include "Summit.h"
#include "AStar.h"

#include <algorithm>

Map::Map(int width, int height) : matrix(width*height), rows(height), cols(width){
    //// TMP /////
    for (int i=0; i < width*height ; i++){
        matrix[i] = std::unique_ptr<Terrain>(new Sand());
    }

    matrix.at(8*cols + 0) = std::unique_ptr<Terrain>(new Precipice());
    matrix.at(8*cols + 1) = std::unique_ptr<Terrain>(new Precipice());
    matrix.at(8*cols + 2) = std::unique_ptr<Terrain>(new Precipice());
    matrix.at(8*cols + 3) = std::unique_ptr<Terrain>(new Precipice());
    matrix.at(3*cols + 9) = std::unique_ptr<Terrain>(new Precipice());
    matrix.at(3*cols + 8) = std::unique_ptr<Terrain>(new Precipice());
    matrix.at(3*cols + 7) = std::unique_ptr<Terrain>(new Precipice());
    matrix.at(3*cols + 6) = std::unique_ptr<Terrain>(new Precipice());
    matrix.at(3*cols + 5) = std::unique_ptr<Terrain>(new Precipice());
    matrix.at(3*cols + 4) = std::unique_ptr<Terrain>(new Summit());
    matrix.at(3*cols + 3) = std::unique_ptr<Terrain>(new Precipice());

}

Map::Map() :matrix(640*480), rows(640), cols(480)  {}

Map::~Map() {}

Terrain& Map::at(int x, int y){
    return *matrix.at(y*cols + x);
}

Terrain& Map::at(const Position& pos) {
    return *matrix.at(pos.getY()*cols + pos.getX());
}

bool Map::isValid(Position &pos) {
    return pos.getX() >= 0 && pos.getY() >= 0 && pos.getX() < cols && pos.getY() < rows;
}

void Map::put(Unity &unity) {
    unitys.push_back(&unity);
}
void Map::put(Building &building) {
    buildings.push_back(&building);
}

bool Map::canMove(Unity& unity, Position pos) {
    return unity.canMoveAboveTerrain(this->at(pos));
}

bool Map::moveUnitys() {
    bool result = false;
    for (auto u : unitys){
        if (u->move()){
            result = true;
        }
    }
    return result;
}

void Map::setDestiny(Unity &unity, int x_dest, int y_dest) {
    AStar algorithm(*this);
    unity.setPath(algorithm.makePath(unity, Position(x_dest, y_dest)));
}

Unity* Map::getClosestUnity(Unity &unity, int limitRadius) {
    Unity* closest_unity = nullptr;
    int closest_unity_distance = limitRadius;
    for (auto unit : unitys){
        int distance = unit->getPosition().sqrtDistance(unity.getPosition());
        if (distance < limitRadius
                && distance < closest_unity_distance
                && !(*unit == unity)){
            closest_unity = unit;
            closest_unity_distance = distance;
        }
    }

    return closest_unity;
}

void Map::cleanDeadUnitys() {
    if (std::find_if(unitys.begin(), unitys.end(), Unity::isDead) != unitys.end()){
        unitys.erase(std::remove_if(unitys.begin(), unitys.end(), Unity::isDead));
    }
}

