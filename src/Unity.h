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
#define UNITY_VEL 5
#define ATTACK_RANGE 1500

class Map;

class Unity : public Positionable, public Attackable, public Attacker {
public:

    enum State {FOLLOWING, MOVING, ATTACKING, STOPPED};

    Unity();

    Unity(int x, int y);

    void setPath(std::stack<Position> path);

    int move();

    int makeAction(Map& map);

    void follow(Unity* other, Map& map);

    virtual bool canMoveAboveTerrain(Terrain& terrain);

    bool automaticAttack(Map &map);

    static bool isDead(Unity* attackable);

    bool operator==(const Unity& other);

private:
    int id;
    int velocity;
    int actual_vel;
    std::stack<Position> pathToDestiny;
    Unity* foll_unity;
    Position prev_foll_unity_pos;

    Position next_pos;
    State state;
};

#endif //__UNITY_H__
