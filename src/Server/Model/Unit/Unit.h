#ifndef __UNIT_H__
#define __UNIT_H__

#include "Position.h"
#include <Model/Weapons/Weapon.h>
#include <Model/Weapons/Rocket.h>
#include <Model/Terrains/Sand.h>
#include <Model/Terrains/Precipice.h>
#include <Model/Terrains/Summit.h>
#include <Model/Terrains/Dunes.h>
#include <Model/Terrains/Rocks.h>
#include <Model/Attackable.h>
#include <Model/Player.h>
#include "States/UnitState.h"
#include "States/UnitStateAttacking.h"
#include "States/UnitStateFollowing.h"
#include "States/UnitStateMoving.h"
#include "States/UnitStateStopped.h"
#include "States/UnitStateDefending.h"
#include "States/UnitStateLoading.h"
#include "States/UnitStateFarming.h"
#include "States/UnitStateBacking.h"
#include "States/UnitStateTraining.h"
#include <stack>
#include <memory>
#include <iostream>
#include <nlohmann/json.hpp>

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
    static const UnitStateTraining training;

    enum UnitType {
            HARVESTER,
            LIGHT_INFANTRY,
            HEAVY_INFANTRY,
            RAIDER,
            TANK,
            TRIKE,
    };

    Unit(const int x, const int y, const int hitPoints, const int speed, const int cost);
    virtual ~Unit();

    bool operator==(const Unit& other);

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

    bool isAttacking();

    void setPlayer(Player &player);

    Player& getPlayer();

    virtual bool shotARocket();
    virtual Rocket* getRocket();

    void checkForDeadVictim();

    bool isTraining();

    void finishTraining();

    virtual nlohmann::json& getSerialization();

    virtual bool hasNews();

public:
    const int id;

protected:
    static int counter;
    const int speed;
    const int cost;
    int actual_speed;
    std::stack<Position> pathToDestiny;
    Attackable* foll_unit;
    Position destiny;
    Position prev_foll_unit_pos;
    Position next_pos;
    UnitState* state;
    Player* player;
    nlohmann::json serialization;
    bool news;
};

#endif //__UNIT_H__
