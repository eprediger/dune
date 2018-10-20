#ifndef __MAP_H__
#define __MAP_H__

#include <vector>
#include "Terrain.h"
#include "Positionable.h"
#include "Unity.h"

class Map {
private:
    Map();
    Map(int width, int height);
    Map(Map const&);
    Map& operator=(Map const&);
    static Map* map_instance;

    std::vector<std::vector<Terrain>> matrix;
    std::vector<Positionable*> positionables;
public:
    static Map* getInstance();
    static void create(int width, int height);

    void print();

    int getWidth();
    int getHeight();
    bool isValid(Position& pos);

    void put(Positionable &positionable);

    Terrain& at(int x, int y);

    ~Map();

};

#endif //__MAP_H__
