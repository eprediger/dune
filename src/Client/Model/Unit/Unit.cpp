#include "Unit.h"
#include <iostream>
#include <stack>

Unit::Unit(nlohmann::json& j):
    id(j["id"])
    ,life(j["life"])
    ,initial_life(life)
    ,pos(j["pos"]["x"],j["pos"]["y"])
    ,player_id(j["player_id"])
    ,player(nullptr)
    {} 
 

Unit::~Unit() {}

void Unit::update(nlohmann::json& j){
    life = j["life"];
    pos.x = j["pos"]["x"];
    pos.y = j["pos"]["y"];
}

bool Unit::isDead(){
    return life <= 0;
}

void Unit::setPlayer(Player* player){
    this->player = player;
}

Player& Unit::getPlayer(){
    return *this->player;
}

Position& Unit::getPosition(){
    return pos;
}

int Unit::getLife(){
    return life;
}

int Unit::getInitialLife(){
    return initial_life;
}