#ifndef __UNIT_H__
#define __UNIT_H__

#include "Position.h"
#include "../Player.h"
#include <memory>
#include <iostream>
#include <nlohmann/json.hpp>

class Map;

class Unit{
public:
   
    Unit(nlohmann::json& j);
    virtual ~Unit();

    virtual void update(nlohmann::json& j);

    bool isDead();

    Position& getPosition();
    
    int getLife();

    int getInitialLife();

    void setPlayer(Player* player);
   
    Player& getPlayer();

    const int id;

protected:
    int player_id;
    Player* player;
    int life;
    int initial_life;
    Position pos;


};

#endif //__UNIT_H__
