#ifndef __TERRAIN_H__
#define __TERRAIN_H__

#include <ostream>

#include "Positionable.h"

class Terrain {
private:
    char key;
    int movility;
public:
    Terrain();

    Terrain(char key);

    Terrain(int movility);

    int getMovility();
    void setMovility(int movility);

    bool operator==(const Terrain& terrain);
    friend std::ostream& operator<<(std::ostream& os, const Terrain& terrain);

    char getKey();

};

#endif //__TERRAIN_H__
