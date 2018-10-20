#ifndef __TERRAIN_H__
#define __TERRAIN_H__

#include <ostream>

#include "Positionable.h"

class Terrain {
private:
    int movility;
public:
    Terrain();

    Terrain(int movility);

    int getMovility();
    void setMovility(int movility);

    friend std::ostream& operator<<(std::ostream& os, const Terrain& terrain);

};

#endif //__TERRAIN_H__
