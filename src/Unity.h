#ifndef __UNITY_H__
#define __UNITY_H__

#include "Position.h"
#include "Positionable.h"
#include "Weapon.h"

#include "Sand.h"
#include "Precipice.h"
//#include "Map.h"
#include <stack>

#define INITIAL_LIFE 50

class Map;

class Unity : public Positionable {
private:
    int id;
    int life;
    std::stack<Position> pathToDestiny;
    Weapon weapon;
//    Map & map;
public:
    Unity();

    Unity(int x, int y);

    void setPath(std::stack<Position> path);

    int getLife();

    int move();

    virtual bool canMoveAboveTerrain(Terrain& terrain);

    void attack(Unity &defender);

    void reciveAttack(Unity &attacker);

    int getDammage();

    bool automaticAttack(Map &map);

    static bool isDead(Unity* unity);

    bool operator==(const Unity& other);
};

#endif //__UNITY_H__
