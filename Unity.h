#ifndef __UNITY_H__
#define __UNITY_H__

#include "Position.h"
#include "Positionable.h"

#include "Sand.h"
#include "Precipice.h"
#include <stack>

class Unity : public Positionable {
private:
    std::stack<Position> pathToDestiny;
public:
    Unity();

    void setDestiny(int x_dest, int y_dest);

    int move();

    bool canMoveAboveTerrain(Terrain& terrain);
//    bool canMoveAboveTerrain(Sand& terrain);
//    bool canMoveAboveTerrain(Precipice& terrain);

    Unity(int x, int y);
};

#endif //__UNITY_H__
