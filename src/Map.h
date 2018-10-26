#ifndef __MAP_H__
#define __MAP_H__

#include <vector>
#include "Terrain.h"
#include "Positionable.h"
//#include "Unity.h"
#include <memory>

class Unity;

class Map {
private:
    std::vector<std::unique_ptr<Terrain>> matrix;
    int rows, cols;
//    std::vector<Positionable*> unitys;
    std::vector<Unity*> unitys;
public:
    Map();
    Map(int width, int height);

    bool isValid(Position& pos);
    bool canMove(Unity& unity, Position pos);
    void put(Unity& unity);
    bool moveUnitys();

    Unity * getClosestUnity(Unity &unity, int limitRadius);

    void setDestiny(Unity& unity, int x_dest, int y_dest);

    void cleanDeadUnitys();

    Terrain& at(int x, int y);
    Terrain& at(const Position& pos);

    ~Map();

};

#endif //__MAP_H__
