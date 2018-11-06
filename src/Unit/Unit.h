#ifndef __UNITY_H__
#define __UNITY_H__

#include "../Position.h"
#include "../Positionable.h"
#include "../Weapons/Weapon.h"

#include "../Terrains/Sand.h"
#include "../Terrains/Precipice.h"
#include "../Terrains/Summit.h"
#include "../Terrains/Dunes.h"
#include "../Terrains/Rocks.h"
#include "../Attackable.h"
//#include "Map.h"
#include <stack>
#include <memory>

class Map;

class Unit : public Positionable, public Attackable {
public:

    enum State {FOLLOWING, MOVING, ATTACKING, STOPPED};

    /*Unit();

    Unit(int x, int y);*/

    Unit(const int x, const int y, const int hitPoints, const int speed);

    void setPath(std::stack<Position> path);

    int move();

    virtual int makeAction(Map& map) = 0;

    void follow(Unit* other, Map& map);

    virtual bool canMoveAboveTerrain(Terrain& terrain) = 0;

//    bool automaticAttack(Map &map);

    static bool isDead(const Unit *unit);

    static bool isDeadOnModel(const std::unique_ptr<Unit> &unit);

    Position getNextPosition();

    bool operator==(const Unit& other);

protected:
    int id;
    const int speed;
    int actual_speed;
    std::stack<Position> pathToDestiny;
    Unit* foll_unit;
    Position prev_foll_unit_pos;
    Position next_pos;
    State state;
};
 
#endif //__UNITY_H__
