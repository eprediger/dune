#include "Map.h"

#include "Precipice.h"
#include "Summit.h"

Map* Map::map_instance = nullptr;

Map::Map(int width, int height) : matrix(width*height), rows(height), cols(width){
    //// TMP /////
    for (int i=0; i < width*height ; i++){
        matrix[i] = std::unique_ptr<Terrain>(new Sand());
    }

//    this->at(0, 8) = std::move(p);
//    matrix.at(8*cols + 0) = std::move(std::unique_ptr<Terrain>(new Precipice()));
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
//    this->at(1, 8) = Terrain(1);
//    this->at(2, 8) = Terrain(1);
//    this->at(3, 8) = Terrain(1);
//    this->at(9, 3) = Terrain(1);
//    this->at(8, 3) = Terrain(1);
//    this->at(7, 3) = Terrain(1);
//    this->at(6, 3) = Terrain(1);
//    this->at(5, 3) = Terrain(1);
//    this->at(4, 3) = Terrain(1);
//    this->at(3, 3) = Terrain(1);

}

Map *Map::getInstance() {
    if (!map_instance) {
        throw "Error";
    }

    return map_instance;
}

Map::Map() {}

Map::~Map() {
    delete map_instance;
}

void Map::create(int width, int height) {
    map_instance = new Map(width, height);
}

#include <iostream>
void Map::print() {
    std::vector<char> pmatrix(rows*cols);

    std::fill(pmatrix.begin(), pmatrix.end(), ' ');
    for (int i = 0; i< cols*rows; i++){
//        int mov = matrix[i].getMovility();
//        if (mov != 0) {
            pmatrix[i] = matrix[i]->getKey();
//            pmatrix[i] = 'O';
//        }
    }

    for (auto pos : unitys){
        pmatrix.at(pos->getPosition().getY()*cols + pos->getPosition().getX()) = 'A' + pos->getValue();
    }

    int col = 0;
    for (auto m : pmatrix){
        if (col == cols) {
            std::cout << std::endl;
            col = 0;
        }
        col++;
        std::cout << m << "\t";
    }
    std::cout << std::endl;

}

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

