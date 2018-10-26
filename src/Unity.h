#ifndef __UNITY_H__
#define __UNITY_H__

#include "Position.h"
#include "Positionable.h"
#include "Weapon.h"

#include "Sand.h"
#include "Precipice.h"
#include "Attackable.h"
#include "Attacker.h"
//#include "Map.h"
#include <stack>

#define INITIAL_LIFE 50

class Map;

class Unity : public Positionable, public Attackable, public Attacker {
private:
    int id;
    std::stack<Position> pathToDestiny;

public:
    Unity();

    Unity(int x, int y);

    void setPath(std::stack<Position> path);

    int move();

    virtual bool canMoveAboveTerrain(Terrain& terrain);

    bool automaticAttack(Map &map);

    static bool isDead(Unity* attackable);

    bool operator==(const Unity& other);
};

#endif //__UNITY_H__
