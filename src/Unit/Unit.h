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
#include "../Player.h"
#include "States/UnitState.h"
#include "States/UnitStateAttacking.h"
#include "States/UnitStateFollowing.h"
#include "States/UnitStateMoving.h"
#include "States/UnitStateStopped.h"
#include "States/UnitStateDefending.h"
//#include "Map.h"
#include <stack>
#include <memory>

class Map;

class Unit : public Positionable, public Attackable {
public:

    static const UnitStateAttacking attacking;
    static const UnitStateFollowing following;
    static const UnitStateMoving moving;
    static const UnitStateStopped stopped;
    static const UnitStateDefending defending;

    Unit(const int x, const int y, const int hitPoints, const int speed);

    void setPath(std::stack<Position> path, Position destiny);

    bool move(Map &map);

    virtual void makeAction(Map &map);

    virtual UnitState * makeFollow(Map &map) = 0;
    virtual UnitState * makeAttack(Map &map) = 0;
    virtual UnitState * makeStopped(Map &map) = 0;
    virtual UnitState * makeDefending(Map &map) = 0;

    void follow(Unit* other, Map& map);

    virtual bool canMoveAboveTerrain(Terrain& terrain) = 0;

//    bool automaticAttack(Map &map);

    static bool isDead(const Unit *unit);

    bool isAttacking();

    Position getNextPosition();

    bool operator==(const Unit& other);

    void setPlayer(Player &player);

    Player& getPlayer();

protected:
    int id;
    const int speed;
    int actual_speed;
    std::stack<Position> pathToDestiny;
    Unit* foll_unit;
    Position destiny;
    Position prev_foll_unit_pos;
    Position next_pos;
    UnitState* state;
    Player* player;
};
 
#endif //__UNITY_H__
