#ifndef __TERRAIN_H__
#define __TERRAIN_H__

#include <ostream>

#include "../Positionable.h"

class Terrain {
private:
    char key;

public:
    Terrain();

    Terrain(char key);

    bool operator==(const Terrain& terrain);

    char getKey();

};

#endif //__TERRAIN_H__
