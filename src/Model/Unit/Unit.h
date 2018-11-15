#ifndef __UNIT_H__
#define __UNIT_H__

#include "../../Position.h"
#include "../Weapons/Weapon.h"

#include "../Terrains/Sand.h"
#include "../Terrains/Precipice.h"
#include "../Terrains/Summit.h"
#include "../Terrains/Dunes.h"
#include "../Terrains/Rocks.h"
#include "../Attackable.h"
#include "../Player.h"
#include "States/UnitState.h"
#include "States/UnitStateAttacking.h"
#include "States/UnitStateFollowing.h"
#include "States/UnitStateMoving.h"
#include "States/UnitStateStopped.h"
#include "States/UnitStateDefending.h"
#include "States/UnitStateLoading.h"
#include "States/UnitStateFarming.h"
#include "States/UnitStateBacking.h"
//#include "Map.h"
#include <stack>
#include <memory>
#include <iostream>

class Map;

class Unit : public Attackable {
public:
    static const UnitStateAttacking attacking;
    static const UnitStateFollowing following;
    static const UnitStateMoving moving;
    static const UnitStateStopped stopped;
    static const UnitStateDefending defending;
    static const UnitStateLoading loading;
    static const UnitStateFarming farming;
    static const UnitStateBacking backing;

    Unit(const int x, const int y, const int hitPoints, const int speed);
    virtual ~Unit();

    void setPath(std::stack<Position> path, Position destiny);

    bool move(Map &map);

    virtual void makeAction(Map &map);

    virtual UnitState * makeFollow(Map &map);
    virtual UnitState * makeAttack(Map &map);
    virtual UnitState * makeStopped(Map &map);
    virtual UnitState * makeDefending(Map &map);
    virtual UnitState * makeLoading(Map &map);
    virtual UnitState * makeFarming(Map &map);
    virtual UnitState * makeBacking(Map &map);

    virtual void actionOnPosition(Map& map, Position& pos);

    void follow(Attackable* other, Map& map);

    virtual bool canMoveAboveTerrain(Terrain& terrain) = 0;

//    bool automaticAttack(Map &map);

//    static bool isDead(const Attackable *unit);

    bool isAttacking();

    Position getNextPosition();

    bool operator==(const Unit& other);

    void setPlayer(Player &player);

    Player& getPlayer();

    void checkForDeadVictim();

protected:
    int id;
    const int speed;
    int cost;
    int actual_speed;
    std::stack<Position> pathToDestiny;
    Attackable* foll_unit;
    Position destiny;
    Position prev_foll_unit_pos;
    Position next_pos;
    UnitState* state;
    Player* player;
};
 
#endif //__UNIT_H__
