#include "Map.h"


Map* Map::map_instance = nullptr;

Map::Map(int width, int height) : matrix(width,std::vector<Terrain>(height)){
    //// TMP /////

    matrix.at(8).at(0) = Terrain(1);
    matrix.at(8).at(1) = Terrain(1);
    matrix.at(8).at(2) = Terrain(1);
    matrix.at(8).at(3) = Terrain(1);
    matrix.at(3).at(9) = Terrain(1);
    matrix.at(3).at(8) = Terrain(1);
    matrix.at(3).at(7) = Terrain(1);
    matrix.at(3).at(6) = Terrain(1);
    matrix.at(3).at(5) = Terrain(1);
    matrix.at(3).at(4) = Terrain(1);
    matrix.at(3).at(3) = Terrain(1);

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
    std::vector<std::vector<int>> pmatrix(getWidth(), std::vector<int>(getHeight()));
    int n_row = 0,n_col = 0;
    for (auto row : matrix){
        n_col = 0;
        for(auto col : row){
            pmatrix[n_row][n_col] = col.getMovility();
            n_col++;
        }
        n_row++;
    }

    for (auto pos : positionables){
        pmatrix[pos->getPosition().getY()][pos->getPosition().getX()] = pos->getValue();
    }

    for (int i = 0; i< pmatrix.size() ; i++){
        for (int j = 0; j< pmatrix[i].size() ; j++){
            std::cout << pmatrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }


}

Terrain& Map::at(int x, int y){
    return matrix.at(y).at(x);
}

int Map::getHeight() {
    return matrix.size();
}

int Map::getWidth() {
    return matrix.at(0).size();
}

bool Map::isValid(Position &pos) {
    return pos.getX() >= 0 && pos.getY() >= 0 && pos.getX() < matrix.at(0).size() && pos.getY() < matrix.size();
}

void Map::put(Positionable& positionable) {
    positionables.push_back(&positionable);
}


