#ifndef __UNITY_H__
#define __UNITY_H__

#include "Position.h"
#include "Positionable.h"
#include "Weapon.h"

#include "Sand.h"
#include "Precipice.h"
#include "Summit.h"
#include "Attackable.h"
#include "Attacker.h"
//#include "Map.h"
#include <stack>

class Map;

class Unity : public Positionable, public Attackable, public Attacker {
private:
    int id;
    const int speed;
    std::stack<Position> pathToDestiny;
public:
    /*Unity(const int hitPoints);

    Unity(int x, int y);*/

    Unity(const int x, const int y, const int hitPoints,
          const int range, Weapon weapon, const int speed);

    void setPath(std::stack<Position> path);

    int move();

    virtual bool canMoveAboveTerrain(Terrain& terrain) = 0;

    bool automaticAttack(Map &map);

    static bool isDead(Unity* attackable);

    bool operator==(const Unity& other);
};

#endif //__UNITY_H__
