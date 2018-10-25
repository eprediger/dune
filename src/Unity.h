#ifndef __UNITY_H__
#define __UNITY_H__

#include "Position.h"
#include "Positionable.h"
#include "Weapon.h"

#include "Sand.h"
#include "Precipice.h"
#include <stack>

#define INITIAL_LIFE 50

class Unity : public Positionable {
private:
    int life;
    std::stack<Position> pathToDestiny;
    Weapon weapon;
public:
    Unity();

//    void setDestiny(int x_dest, int y_dest);
    void setPath(std::stack<Position> path);

    int getLife();

    int move();

    virtual bool canMoveAboveTerrain(Terrain& terrain);

    Unity(int x, int y);

    void attack(Unity &defender);

    void getAttack(Unity &attacker);

    int getDammage();
};

#endif //__UNITY_H__
