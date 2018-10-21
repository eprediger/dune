#ifndef __MAP_H__
#define __MAP_H__

#include <vector>
#include "Terrain.h"
#include "Positionable.h"
#include "Unity.h"
#include <memory>

class Map {
private:
    Map();
    Map(int width, int height);
    Map(Map const&);
    Map& operator=(Map const&);
    static Map* map_instance;

    std::vector<std::unique_ptr<Terrain>> matrix;
    int rows, cols;
//    std::vector<Positionable*> unitys;
    std::vector<Unity*> unitys;
public:
    static Map* getInstance();
    static void create(int width, int height);

    void print();

    int getWidth();
    int getHeight();
    bool isValid(Position& pos);
    bool canMove(Unity &unity, Position pos);
    void put(Unity &unity);
    bool moveUnitys();

    Terrain& at(int x, int y);
    Terrain& at(const Position& pos);

    ~Map();

};

#endif //__MAP_H__
