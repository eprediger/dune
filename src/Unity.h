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
public:

    enum State {FOLLOWING, MOVING, ATTACKING, STOPPED};

    /*Unity();

    Unity(int x, int y);*/

    Unity(const int x, const int y, const int hitPoints,
          const int range, Weapon weapon, const int speed);

    void setPath(std::stack<Position> path);

    int move();

    int makeAction(Map& map);

    void follow(Unity* other, Map& map);

    virtual bool canMoveAboveTerrain(Terrain& terrain) = 0;

    bool automaticAttack(Map &map);

    static bool isDead(Unity* attackable);

    bool operator==(const Unity& other);

private:
    int id;
    const int speed;
    int actual_speed;
    std::stack<Position> pathToDestiny;
    Unity* foll_unity;
    Position prev_foll_unity_pos;
    Position next_pos;
    State state;
};

#endif //__UNITY_H__
