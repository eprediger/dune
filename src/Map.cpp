#include "Map.h"

#include "Precipice.h"
#include "Summit.h"
#include "AStar.h"

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

Map::Map() {}

Map::~Map() {}

Terrain& Map::at(int x, int y){
    return *matrix.at(y*cols + x);
}

Terrain& Map::at(const Position& pos) {
    return *matrix.at(pos.getY()*cols + pos.getX());
}

int Map::getHeight() {
    return rows;
}

int Map::getWidth() {
    return cols;
}

bool Map::isValid(Position &pos) {
    return pos.getX() >= 0 && pos.getY() >= 0 && pos.getX() < cols && pos.getY() < rows;
}

void Map::put(Unity &unity) {
    unitys.push_back(&unity);

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

